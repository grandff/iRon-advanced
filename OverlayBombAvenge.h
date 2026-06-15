#pragma once

#include "Overlay.h"
#include "iracing.h"
#include <string>
#include <cmath>

class OverlayBombAvenge : public Overlay
{
public:
    OverlayBombAvenge()
        : Overlay("OverlayBombAvenge")
    {
    }

protected:
    virtual float2 getDefaultSize() override
    {
        return float2{ 250, 90 };
    }

    virtual void onConfigChanged() override
    {
        m_text.reset(m_dwriteFactory.Get());

        const std::string font = g_cfg.getString(m_name, "font", "Microsoft YaHei UI");
        const float fontSize = g_cfg.getFloat(m_name, "font_size", 14.0f);
        const int fontWeight = g_cfg.getInt(m_name, "font_weight", 600);

        HRCHECK(m_dwriteFactory->CreateTextFormat(toWide(font).c_str(), NULL, (DWRITE_FONT_WEIGHT)fontWeight, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, fontSize, L"en-us", &m_textFormat));
        HRCHECK(m_dwriteFactory->CreateTextFormat(toWide(font).c_str(), NULL, DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, fontSize + 2.0f, L"en-us", &m_textFormatBold));
        HRCHECK(m_dwriteFactory->CreateTextFormat(toWide(font).c_str(), NULL, DWRITE_FONT_WEIGHT_NORMAL, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, fontSize - 2.0f, L"en-us", &m_textFormatSmall));
    }

    virtual void onUpdate() override
    {
        const float w = (float)m_width;
        const float h = (float)m_height;

        bool active = g_lastCollision.valid || m_uiEditEnabled;

        if (!active) {
            return;
        }

        // Under UI layout edit mode, draw a semi-transparent black backing so the user can easily see/drag the container
        if (m_uiEditEnabled) {
            Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> bgBrush;
            m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(0.0f, 0.0f, 0.0f, 0.3f), &bgBrush);
            D2D1_RECT_F bgRect = D2D1::RectF(0, 0, w, h);
            m_renderTarget->FillRectangle(&bgRect, bgBrush.Get());
        }

        // Background Glassmorphism (dark red tint)
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> bgBrush;
        m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(0.04f, 0.01f, 0.01f, 0.75f), &bgBrush);
        D2D1_ROUNDED_RECT roundedRect = D2D1::RoundedRect(D2D1::RectF(0, 0, w, h), 8.0f, 8.0f);
        m_renderTarget->FillRoundedRectangle(&roundedRect, bgBrush.Get());

        // Thin Border (red glow/tint)
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> borderBrush;
        m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(0.9f, 0.15f, 0.15f, 0.35f), &borderBrush);
        m_renderTarget->DrawRoundedRectangle(&roundedRect, borderBrush.Get(), 1.5f);

        // Core Text Info
        const float gap = 8.0f;
        wchar_t s[256];

        // Draw Title "BOMB AVENGE"
        m_brush->SetColor(float4(0.95f, 0.2f, 0.2f, 0.95f)); // Bright red title
        m_text.render(m_renderTarget.Get(), L"BOMB AVENGE", m_textFormatBold.Get(), gap, w - gap, gap, m_brush.Get(), DWRITE_TEXT_ALIGNMENT_LEADING);

        // Target info
        std::wstring driverName;
        std::wstring posStr;
        std::wstring distStr;

        if (g_lastCollision.valid) {
            driverName = toWide(g_lastCollision.driverName);
            int carIdx = g_lastCollision.carIdx;
            int pos = ir_getPosition(carIdx);
            
            if (pos > 0) {
                posStr = L"P" + std::to_wstring(pos);
            } else {
                posStr = L"P--";
            }

            // Real-time distance update
            float currentDistMeters = 0.0f;
            if (ir_session.driverCarIdx >= 0 && ir_session.trackLength > 0 && carIdx >= 0) {
                float myDistPct = ir_CarIdxLapDistPct.getFloat(ir_session.driverCarIdx);
                float otherDistPct = ir_CarIdxLapDistPct.getFloat(carIdx);
                float deltaPct = otherDistPct - myDistPct;
                if (deltaPct > 0.5f) deltaPct -= 1.0f;
                if (deltaPct < -0.5f) deltaPct += 1.0f;
                currentDistMeters = deltaPct * ir_session.trackLength;
            }

            wchar_t distBuf[64];
            if (currentDistMeters >= 0) {
                swprintf(distBuf, _countof(distBuf), L"%.1fm Ahead", currentDistMeters);
            } else {
                swprintf(distBuf, _countof(distBuf), L"%.1fm Behind", -currentDistMeters);
            }
            distStr = distBuf;
        } else {
            // Mock data for edit mode
            driverName = L"John Doe";
            posStr = L"P12";
            distStr = L"25.4m Behind";
        }

        // Draw Driver Name
        m_brush->SetColor(float4(1.0f, 1.0f, 1.0f, 0.95f));
        m_text.render(m_renderTarget.Get(), driverName.c_str(), m_textFormat.Get(), gap, w - gap, gap + 22.0f, m_brush.Get(), DWRITE_TEXT_ALIGNMENT_LEADING);

        // Draw Position and Distance
        swprintf(s, _countof(s), L"Pos: %s  |  Gap: %s", posStr.c_str(), distStr.c_str());
        m_brush->SetColor(float4(0.8f, 0.8f, 0.8f, 0.85f));
        m_text.render(m_renderTarget.Get(), s, m_textFormatSmall.Get(), gap, w - gap, gap + 44.0f, m_brush.Get(), DWRITE_TEXT_ALIGNMENT_LEADING);
    }

private:
    Microsoft::WRL::ComPtr<IDWriteTextFormat> m_textFormat;
    Microsoft::WRL::ComPtr<IDWriteTextFormat> m_textFormatBold;
    Microsoft::WRL::ComPtr<IDWriteTextFormat> m_textFormatSmall;
    TextCache m_text;
};
