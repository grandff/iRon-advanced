#pragma once

#include "Overlay.h"
#include "iracing.h"
#include <string>

class OverlayTireDash : public Overlay
{
public:

    OverlayTireDash()
        : Overlay("OverlayTireDash")
    {
    }

protected:

    virtual float2 getDefaultSize() override
    {
        return float2{ 400, 320 };
    }

    virtual void onConfigChanged() override
    {
        m_text.reset(m_dwriteFactory.Get());

        const std::string font = g_cfg.getString(m_name, "font", "Microsoft YaHei UI");
        
        const float titleFontSize = g_cfg.getFloat(m_name, "title_font_size", 20.0f);
        const float valFontSize = g_cfg.getFloat(m_name, "value_font_size", 16.0f);
        const int fontWeight = g_cfg.getInt(m_name, "font_weight", 700);

        HRCHECK(m_dwriteFactory->CreateTextFormat(toWide(font).c_str(), NULL, (DWRITE_FONT_WEIGHT)fontWeight, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, titleFontSize, L"en-us", &m_titleFormat));
        m_titleFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
        m_titleFormat->SetWordWrapping(DWRITE_WORD_WRAPPING_NO_WRAP);
        m_titleFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);

        HRCHECK(m_dwriteFactory->CreateTextFormat(toWide(font).c_str(), NULL, (DWRITE_FONT_WEIGHT)DWRITE_FONT_WEIGHT_NORMAL, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, valFontSize, L"en-us", &m_valFormat));
        m_valFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
        m_valFormat->SetWordWrapping(DWRITE_WORD_WRAPPING_NO_WRAP);
        m_valFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
    }

    void drawTire(float x, float y, float w, float h, const wchar_t* label, 
                  float tempL, float tempM, float tempR, 
                  float wearL, float wearM, float wearR,
                  bool isImperial)
    {
        // Tire background
        D2D1_ROUNDED_RECT rr = D2D1::RoundedRect(D2D1::RectF(x, y, x + w, y + h), 8.0f, 8.0f);
        
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> bgBrush;
        m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(0.08f, 0.08f, 0.08f, 0.85f), &bgBrush);
        m_renderTarget->FillRoundedRectangle(&rr, bgBrush.Get());

        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> borderBrush;
        m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 1.0f, 0.1f), &borderBrush);
        m_renderTarget->DrawRoundedRectangle(&rr, borderBrush.Get(), 1.0f);

        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> textWhite;
        m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 1.0f, 0.95f), &textWhite);

        // Title
        m_text.render(m_renderTarget.Get(), label, m_titleFormat.Get(), x, x + w, y + 15.0f, textWhite.Get(), DWRITE_TEXT_ALIGNMENT_CENTER);

        // Temp values formatting
        wchar_t bufTemp[64];
        if (isImperial) {
            // Convert C to F
            float fL = tempL * 1.8f + 32.0f;
            float fM = tempM * 1.8f + 32.0f;
            float fR = tempR * 1.8f + 32.0f;
            swprintf(bufTemp, _countof(bufTemp), L"%.0f\x00B0 | %.0f\x00B0 | %.0f\x00B0", fL, fM, fR);
        } else {
            swprintf(bufTemp, _countof(bufTemp), L"%.0f\x00B0 | %.0f\x00B0 | %.0f\x00B0", tempL, tempM, tempR);
        }

        // Color coding for temp (Blue = Cold, Red = Hot, Green = Optimal)
        float4 tempCol = float4(0.15f, 0.75f, 0.15f, 0.35f); // Green
        float t = tempM;
        if (t < 65.0f) {
            tempCol = float4(0.1f, 0.45f, 0.95f, 0.35f); // Blue
        } else if (t > 110.0f) {
            tempCol = float4(0.9f, 0.15f, 0.15f, 0.4f); // Red
        }

        // Draw Temp badge
        D2D1_ROUNDED_RECT tempBadge = D2D1::RoundedRect(D2D1::RectF(x + 12, y + h * 0.35f, x + w - 12, y + h * 0.58f), 4.0f, 4.0f);
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> tempBgBrush;
        m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(tempCol.x, tempCol.y, tempCol.z, tempCol.w), &tempBgBrush);
        m_renderTarget->FillRoundedRectangle(&tempBadge, tempBgBrush.Get());

        m_text.render(m_renderTarget.Get(), bufTemp, m_valFormat.Get(), x, x + w, y + h * 0.43f, textWhite.Get(), DWRITE_TEXT_ALIGNMENT_CENTER);

        // Wear values formatting
        wchar_t bufWear[64];
        float wL = wearL * 100.0f;
        float wM = wearM * 100.0f;
        float wR = wearR * 100.0f;
        swprintf(bufWear, _countof(bufWear), L"%.0f%% | %.0f%% | %.0f%%", wL, wM, wR);

        // Color coding for wear (Green = Good, Yellow = Medium, Red = Bad)
        float4 wearCol = float4(0.15f, 0.75f, 0.15f, 0.35f); // Green
        float minWear = std::min(std::min(wL, wM), wR);
        if (minWear <= 40.0f) {
            wearCol = float4(0.9f, 0.15f, 0.15f, 0.4f); // Red
        } else if (minWear <= 80.0f) {
            wearCol = float4(0.95f, 0.75f, 0.0f, 0.35f); // Yellow
        }

        // Draw Wear badge
        D2D1_ROUNDED_RECT wearBadge = D2D1::RoundedRect(D2D1::RectF(x + 12, y + h * 0.65f, x + w - 12, y + h * 0.88f), 4.0f, 4.0f);
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> wearBgBrush;
        m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(wearCol.x, wearCol.y, wearCol.z, wearCol.w), &wearBgBrush);
        m_renderTarget->FillRoundedRectangle(&wearBadge, wearBgBrush.Get());

        m_text.render(m_renderTarget.Get(), bufWear, m_valFormat.Get(), x, x + w, y + h * 0.73f, textWhite.Get(), DWRITE_TEXT_ALIGNMENT_CENTER);
    }

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> GetColorBrush(float r, float g, float b)
    {
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
        m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(r, g, b, 1.0f), &brush);
        return brush;
    }

    virtual void onUpdate() override
    {
        

        bool isImperial = ir_DisplayUnits.getInt() == 0;

        float gapX = 20.0f;
        float gapY = 20.0f;
        float w = (m_width - gapX * 3) / 2.0f;
        float h = (m_height - gapY * 3) / 2.0f;

        float xLeft = gapX;
        float xRight = gapX * 2 + w;
        float yFront = gapY;
        float yRear = gapY * 2 + h;

        if (m_uiEditEnabled) {
            // Fake data for UI edit
            drawTire(xLeft, yFront, w, h, L"LF", 80, 85, 82, 0.95f, 0.96f, 0.94f, isImperial);
            drawTire(xRight, yFront, w, h, L"RF", 85, 90, 88, 0.90f, 0.92f, 0.88f, isImperial);
            drawTire(xLeft, yRear, w, h, L"LR", 90, 95, 92, 0.80f, 0.82f, 0.81f, isImperial);
            drawTire(xRight, yRear, w, h, L"RR", 95, 105, 102, 0.70f, 0.75f, 0.68f, isImperial);
        } else {
            // LF
            drawTire(xLeft, yFront, w, h, L"LF", 
                ir_LFtempCL.getFloat(), ir_LFtempCM.getFloat(), ir_LFtempCR.getFloat(),
                ir_LFwearL.getFloat(), ir_LFwearM.getFloat(), ir_LFwearR.getFloat(), isImperial);
            // RF
            drawTire(xRight, yFront, w, h, L"RF", 
                ir_RFtempCL.getFloat(), ir_RFtempCM.getFloat(), ir_RFtempCR.getFloat(),
                ir_RFwearL.getFloat(), ir_RFwearM.getFloat(), ir_RFwearR.getFloat(), isImperial);
            // LR
            drawTire(xLeft, yRear, w, h, L"LR", 
                ir_LRtempCL.getFloat(), ir_LRtempCM.getFloat(), ir_LRtempCR.getFloat(),
                ir_LRwearL.getFloat(), ir_LRwearM.getFloat(), ir_LRwearR.getFloat(), isImperial);
            // RR
            drawTire(xRight, yRear, w, h, L"RR", 
                ir_RRtempCL.getFloat(), ir_RRtempCM.getFloat(), ir_RRtempCR.getFloat(),
                ir_RRwearL.getFloat(), ir_RRwearM.getFloat(), ir_RRwearR.getFloat(), isImperial);
        }
        
}

private:
    Microsoft::WRL::ComPtr<IDWriteTextFormat> m_titleFormat;
    Microsoft::WRL::ComPtr<IDWriteTextFormat> m_valFormat;
    TextCache m_text;
};