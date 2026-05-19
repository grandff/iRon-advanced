#pragma once

#include "Overlay.h"
#include "iracing.h"
#include <cmath>
#include <string>

class OverlayDeltaBar : public Overlay
{
public:
    OverlayDeltaBar()
        : Overlay("OverlayDeltaBar")
    {
    }

protected:
    virtual float2 getDefaultSize() override
    {
        return float2{ 400, 50 };
    }

    virtual void onConfigChanged() override
    {
        m_text.reset(m_dwriteFactory.Get());

        const std::string font = g_cfg.getString(m_name, "font", "Microsoft YaHei UI");
        const float fontSize = g_cfg.getFloat(m_name, "font_size", 24.0f);
        const int fontWeight = g_cfg.getInt(m_name, "font_weight", 800); // Bold

        HRCHECK(m_dwriteFactory->CreateTextFormat(toWide(font).c_str(), NULL, (DWRITE_FONT_WEIGHT)fontWeight, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, fontSize, L"en-us", &m_textFormat));
        m_textFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
        m_textFormat->SetWordWrapping(DWRITE_WORD_WRAPPING_NO_WRAP);
        m_textFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
    }

    virtual void onUpdate() override
    {
        bool useOptimal = g_cfg.getBool(m_name, "use_optimal_delta", true);
        float maxScale = g_cfg.getFloat(m_name, "max_scale_seconds", 2.0f); // 바의 최대 범위 (초)

        float delta = 0.0f;
        bool isOk = false;

        if (m_uiEditEnabled) {
            delta = -0.45f; // 테스트용 가짜 데이터
            isOk = true;
        } else {
            if (useOptimal) {
                isOk = ir_LapDeltaToSessionOptimalLap_OK.getBool();
                delta = ir_LapDeltaToSessionOptimalLap.getFloat();
            } else {
                isOk = ir_LapDeltaToSessionBestLap_OK.getBool();
                delta = ir_LapDeltaToSessionBestLap.getFloat();
            }
        }

        if (!isOk) return;

        // 배경 렌더링
        D2D1_RECT_F bgRect = D2D1::RectF(0, 0, (float)m_width, (float)m_height);
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> bgBrush;
        m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(0.1f, 0.1f, 0.1f, 0.8f), &bgBrush);
        m_renderTarget->FillRectangle(&bgRect, bgBrush.Get());

        // 중앙선
        float midX = m_width / 2.0f;
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> lineBrush;
        m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 1.0f, 0.5f), &lineBrush);
        m_renderTarget->DrawLine(D2D1::Point2F(midX, 0), D2D1::Point2F(midX, (float)m_height), lineBrush.Get(), 2.0f);

        // 델타 바 계산
        float clampedDelta = std::max(-maxScale, std::min(delta, maxScale));
        float barWidth = (fabsf(clampedDelta) / maxScale) * (m_width / 2.0f);
        
        D2D1_RECT_F barRect;
        D2D1_COLOR_F barColor;

        if (delta <= 0) {
            // 더 빠름 (초록색, 왼쪽으로 채워짐)
            barRect = D2D1::RectF(midX - barWidth, 0, midX, (float)m_height);
            barColor = D2D1::ColorF(0.1f, 0.8f, 0.1f, 0.9f);
        } else {
            // 더 느림 (빨간색, 오른쪽으로 채워짐)
            barRect = D2D1::RectF(midX, 0, midX + barWidth, (float)m_height);
            barColor = D2D1::ColorF(0.9f, 0.1f, 0.1f, 0.9f);
        }

        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> barBrush;
        m_renderTarget->CreateSolidColorBrush(barColor, &barBrush);
        m_renderTarget->FillRectangle(&barRect, barBrush.Get());

        // 델타 수치 텍스트 렌더링
        wchar_t buf[64];
        swprintf(buf, _countof(buf), L"%+.2f", delta);
        
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> textBrush;
        m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 1.0f, 1.0f), &textBrush);
        m_text.render(m_renderTarget.Get(), buf, m_textFormat.Get(), 0, (float)m_width, (float)m_height / 2.0f, textBrush.Get(), DWRITE_TEXT_ALIGNMENT_CENTER);
    }

private:
    Microsoft::WRL::ComPtr<IDWriteTextFormat> m_textFormat;
    TextCache m_text;
};
