#pragma once

#include "Overlay.h"
#include "iracing.h"
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

class OverlayH2H : public Overlay
{
public:
    OverlayH2H()
        : Overlay("OverlayH2H")
    {
    }

protected:
    virtual float2 getDefaultSize() override
    {
        return float2{ 350, 180 };
    }

    virtual void onConfigChanged() override
    {
        m_text.reset(m_dwriteFactory.Get());

        const std::string font = g_cfg.getString(m_name, "font", "Microsoft YaHei UI");
        const float fontSize = g_cfg.getFloat(m_name, "font_size", 14.0f);
        const float sectorFontSize = fontSize - 2.0f;
        const int fontWeight = g_cfg.getInt(m_name, "font_weight", 600);

        HRCHECK(m_dwriteFactory->CreateTextFormat(toWide(font).c_str(), NULL, (DWRITE_FONT_WEIGHT)fontWeight, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, fontSize, L"en-us", &m_textFormat));
        HRCHECK(m_dwriteFactory->CreateTextFormat(toWide(font).c_str(), NULL, DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, fontSize, L"en-us", &m_textFormatBold));
        HRCHECK(m_dwriteFactory->CreateTextFormat(toWide(font).c_str(), NULL, (DWRITE_FONT_WEIGHT)DWRITE_FONT_WEIGHT_NORMAL, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, sectorFontSize, L"en-us", &m_sectorFormat));
    }

    struct SectorTracker {
        int lastLap = -1;
        float lapStartTime = 0.0f;
        float s1EndTime = 0.0f;
        float s2EndTime = 0.0f;
        
        float lastS1 = 0.0f;
        float lastS2 = 0.0f;
        float lastS3 = 0.0f;
        
        bool s1Done = false;
        bool s2Done = false;
    };

    SectorTracker m_trackers[IR_MAX_CARS];

    void updateSectorTimes()
    {
        double curTime = ir_SessionTime.getDouble();
        for (int i = 0; i < IR_MAX_CARS; ++i) {
            const Car& car = ir_session.cars[i];
            if (car.userName.empty() || car.isSpectator || car.isPaceCar) {
                m_trackers[i] = SectorTracker();
                continue;
            }
            
            int lap = ir_CarIdxLap.getInt(i);
            float pct = ir_CarIdxLapDistPct.getFloat(i);
            
            SectorTracker& trk = m_trackers[i];
            
            if (lap < 0 || pct < 0.0f || pct > 1.0f) {
                continue;
            }
            
            if (trk.lastLap == -1 || lap != trk.lastLap) {
                if (trk.lastLap != -1 && lap == trk.lastLap + 1 && trk.s1Done && trk.s2Done) {
                    float s3Duration = (float)(curTime - trk.s2EndTime);
                    if (s3Duration > 0.0f && s3Duration < 300.0f) {
                        trk.lastS3 = s3Duration;
                    }
                }
                trk.lastLap = lap;
                trk.lapStartTime = (float)curTime;
                trk.s1Done = false;
                trk.s2Done = false;
            }
            
            if (!trk.s1Done && pct >= 0.333f && pct < 0.5f) {
                float s1Duration = (float)(curTime - trk.lapStartTime);
                if (s1Duration > 0.0f && s1Duration < 300.0f) {
                    trk.lastS1 = s1Duration;
                    trk.s1EndTime = (float)curTime;
                    trk.s1Done = true;
                }
            }
            
            if (trk.s1Done && !trk.s2Done && pct >= 0.667f && pct < 0.8f) {
                float s2Duration = (float)(curTime - trk.s1EndTime);
                if (s2Duration > 0.0f && s2Duration < 300.0f) {
                    trk.lastS2 = s2Duration;
                    trk.s2EndTime = (float)curTime;
                    trk.s2Done = true;
                }
            }
        }
    }

    std::wstring formatSector(float sec)
    {
        if (sec <= 0.0f || sec > 300.0f) return L"-.-";
        wchar_t buf[32];
        swprintf(buf, _countof(buf), L"%.3f", sec);
        return buf;
    }

    std::wstring formatLap(float sec)
    {
        if (sec <= 0.0f) return L"-.-";
        return toWide(formatLaptime(sec));
    }

    virtual void onUpdate() override
    {
        const float w = (float)m_width;
        const float h = (float)m_height;

        // Background Glassmorphism
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> bgBrush;
        m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(0.02f, 0.02f, 0.02f, 0.70f), &bgBrush);
        D2D1_ROUNDED_RECT roundedRect = D2D1::RoundedRect(D2D1::RectF(0, 0, w, h), 8.0f, 8.0f);
        m_renderTarget->FillRoundedRectangle(&roundedRect, bgBrush.Get());

        // Thin Border
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> borderBrush;
        m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 1.0f, 0.15f), &borderBrush);
        m_renderTarget->DrawRoundedRectangle(&roundedRect, borderBrush.Get(), 1.5f);

        // Highlight band for Self driver (Middle row)
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> selfHighlightBrush;
        float4 selfHighlightCol = g_cfg.getFloat4("General", "self_highlight_col", float4(0.94f, 0.67f, 0.13f, 0.12f));
        m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(selfHighlightCol.x, selfHighlightCol.y, selfHighlightCol.z, selfHighlightCol.w), &selfHighlightBrush);
        D2D1_RECT_F selfRect = D2D1::RectF(4, 60, w - 4, 112);
        m_renderTarget->FillRectangle(&selfRect, selfHighlightBrush.Get());

        // Gather real telemetry
        updateSectorTimes();

        struct DriverPosInfo {
            int pos;
            int carIdx;
        };
        std::vector<DriverPosInfo> drivers;
        
        int myCarIdx = ir_session.driverCarIdx;

        if (myCarIdx >= 0) {
            for (int i = 0; i < IR_MAX_CARS; ++i) {
                const Car& car = ir_session.cars[i];
                if (car.userName.empty() || car.isSpectator || car.isPaceCar) continue;
                int pos = ir_getPosition(i);
                if (pos > 0) {
                    drivers.push_back({ pos, i });
                }
            }
            std::sort(drivers.begin(), drivers.end(), [](const DriverPosInfo& a, const DriverPosInfo& b) {
                return a.pos < b.pos;
            });
        }

        int myIdx = -1;
        if (myCarIdx >= 0) {
            for (int i = 0; i < (int)drivers.size(); ++i) {
                if (drivers[i].carIdx == myCarIdx) {
                    myIdx = i;
                    break;
                }
            }
        }

        // Define the 3 rows to render
        bool hasAhead = false;
        bool hasBehind = false;
        
        int aheadCarIdx = -1;
        int behindCarIdx = -1;
        
        int aheadPos = 0;
        int behindPos = 0;
        int myPos = (myCarIdx >= 0) ? ir_getPosition(myCarIdx) : 0;

        if (m_uiEditEnabled) {
            // Fake data for UI edit mode
            myPos = 4;
            aheadPos = 3;
            behindPos = 5;
            hasAhead = true;
            hasBehind = true;
        } else {
            if (myCarIdx >= 0 && myIdx != -1) {
                if (myIdx > 0) {
                    aheadCarIdx = drivers[myIdx - 1].carIdx;
                    aheadPos = drivers[myIdx - 1].pos;
                    hasAhead = true;
                }
                if (myIdx + 1 < (int)drivers.size()) {
                    behindCarIdx = drivers[myIdx + 1].carIdx;
                    behindPos = drivers[myIdx + 1].pos;
                    hasBehind = true;
                }
            }
        }

        // Row offsets
        float yAhead = 22.0f;
        float ySelf = 76.0f;
        float yBehind = 130.0f;

        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> textBrush;
        m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 1.0f, 0.95f), &textBrush);
        
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> grayBrush;
        m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(0.7f, 0.7f, 0.7f, 0.8f), &grayBrush);

        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> greenBrush;
        m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(0.3f, 0.9f, 0.3f, 0.95f), &greenBrush);

        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> redBrush;
        m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(0.9f, 0.3f, 0.3f, 0.95f), &redBrush);

        wchar_t s[256];

        // 1. Render Ahead Driver
        if (hasAhead) {
            std::wstring name = L"";
            float laptime = 0.0f;
            float s1 = 0.0f, s2 = 0.0f, s3 = 0.0f;
            float delta = 0.0f;

            if (m_uiEditEnabled) {
                name = L"Jason Bryfogle";
                laptime = 104.205f;
                s1 = 31.420f; s2 = 41.250f; s3 = 31.535f;
                delta = -1.5f;
            } else if (aheadCarIdx >= 0) {
                name = toWide(ir_session.cars[aheadCarIdx].userName);
                laptime = ir_CarIdxLastLapTime.getFloat(aheadCarIdx);
                s1 = m_trackers[aheadCarIdx].lastS1;
                s2 = m_trackers[aheadCarIdx].lastS2;
                s3 = m_trackers[aheadCarIdx].lastS3;

                // Calculate time gap (always negative/ahead)
                const float L = ir_estimateLaptime();
                const float C = ir_CarIdxEstTime.getFloat(aheadCarIdx);
                const float S = ir_CarIdxEstTime.getFloat(myCarIdx);
                const bool wrap = fabsf(ir_CarIdxLapDistPct.getFloat(aheadCarIdx) - ir_CarIdxLapDistPct.getFloat(myCarIdx)) > 0.5f;
                if (wrap) {
                    delta = S > C ? (C - S) + L : (C - S) - L;
                } else {
                    delta = C - S;
                }
                if (delta > 0) delta = -delta; // force negative representation for ahead
            }

            // Line 1: Pos, Name, Gap, Laptime
            swprintf(s, _countof(s), L"P%d", aheadPos);
            m_text.render(m_renderTarget.Get(), s, m_textFormat.Get(), 10, 45, yAhead, textBrush.Get(), DWRITE_TEXT_ALIGNMENT_LEADING);
            m_text.render(m_renderTarget.Get(), name.c_str(), m_textFormat.Get(), 50, 190, yAhead, textBrush.Get(), DWRITE_TEXT_ALIGNMENT_LEADING);
            
            swprintf(s, _countof(s), L"-%.1fs", fabsf(delta));
            m_text.render(m_renderTarget.Get(), s, m_textFormat.Get(), 195, 260, yAhead, greenBrush.Get(), DWRITE_TEXT_ALIGNMENT_LEADING);
            
            m_text.render(m_renderTarget.Get(), formatLap(laptime).c_str(), m_textFormat.Get(), 265, w - 10, yAhead, textBrush.Get(), DWRITE_TEXT_ALIGNMENT_TRAILING);

            // Line 2: Sectors
            swprintf(s, _countof(s), L"S1: %s", formatSector(s1).c_str());
            m_text.render(m_renderTarget.Get(), s, m_sectorFormat.Get(), 50, 140, yAhead + 22.0f, grayBrush.Get(), DWRITE_TEXT_ALIGNMENT_LEADING);
            swprintf(s, _countof(s), L"S2: %s", formatSector(s2).c_str());
            m_text.render(m_renderTarget.Get(), s, m_sectorFormat.Get(), 145, 235, yAhead + 22.0f, grayBrush.Get(), DWRITE_TEXT_ALIGNMENT_LEADING);
            swprintf(s, _countof(s), L"S3: %s", formatSector(s3).c_str());
            m_text.render(m_renderTarget.Get(), s, m_sectorFormat.Get(), 240, w - 10, yAhead + 22.0f, grayBrush.Get(), DWRITE_TEXT_ALIGNMENT_LEADING);
        } else {
            m_text.render(m_renderTarget.Get(), L"No driver ahead", m_sectorFormat.Get(), 10, w - 10, yAhead + 10.0f, grayBrush.Get(), DWRITE_TEXT_ALIGNMENT_CENTER);
        }

        // 2. Render Self Driver
        {
            std::wstring name = L"";
            float laptime = 0.0f;
            float s1 = 0.0f, s2 = 0.0f, s3 = 0.0f;

            if (m_uiEditEnabled) {
                name = L"Jeongmin Kim";
                laptime = 104.520f;
                s1 = 31.502f; s2 = 41.380f; s3 = 31.638f;
            } else if (myCarIdx >= 0) {
                name = toWide(ir_session.cars[myCarIdx].userName);
                laptime = ir_CarIdxLastLapTime.getFloat(myCarIdx);
                s1 = m_trackers[myCarIdx].lastS1;
                s2 = m_trackers[myCarIdx].lastS2;
                s3 = m_trackers[myCarIdx].lastS3;
            }

            // Highlight color for self text
            Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> selfTextBrush;
            float4 selfTextCol = g_cfg.getFloat4("General", "self_col", float4(0.94f, 0.67f, 0.13f, 1.0f));
            m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(selfTextCol.x, selfTextCol.y, selfTextCol.z, selfTextCol.w), &selfTextBrush);

            // Line 1: Pos, Name, Gap, Laptime
            swprintf(s, _countof(s), L"P%d", myPos);
            m_text.render(m_renderTarget.Get(), s, m_textFormatBold.Get(), 10, 45, ySelf, selfTextBrush.Get(), DWRITE_TEXT_ALIGNMENT_LEADING);
            m_text.render(m_renderTarget.Get(), name.c_str(), m_textFormatBold.Get(), 50, 260, ySelf, selfTextBrush.Get(), DWRITE_TEXT_ALIGNMENT_LEADING);
            m_text.render(m_renderTarget.Get(), formatLap(laptime).c_str(), m_textFormatBold.Get(), 265, w - 10, ySelf, selfTextBrush.Get(), DWRITE_TEXT_ALIGNMENT_TRAILING);

            // Line 2: Sectors
            swprintf(s, _countof(s), L"S1: %s", formatSector(s1).c_str());
            m_text.render(m_renderTarget.Get(), s, m_sectorFormat.Get(), 50, 140, ySelf + 22.0f, grayBrush.Get(), DWRITE_TEXT_ALIGNMENT_LEADING);
            swprintf(s, _countof(s), L"S2: %s", formatSector(s2).c_str());
            m_text.render(m_renderTarget.Get(), s, m_sectorFormat.Get(), 145, 235, ySelf + 22.0f, grayBrush.Get(), DWRITE_TEXT_ALIGNMENT_LEADING);
            swprintf(s, _countof(s), L"S3: %s", formatSector(s3).c_str());
            m_text.render(m_renderTarget.Get(), s, m_sectorFormat.Get(), 240, w - 10, ySelf + 22.0f, grayBrush.Get(), DWRITE_TEXT_ALIGNMENT_LEADING);
        }

        // 3. Render Behind Driver
        if (hasBehind) {
            std::wstring name = L"";
            float laptime = 0.0f;
            float s1 = 0.0f, s2 = 0.0f, s3 = 0.0f;
            float delta = 0.0f;

            if (m_uiEditEnabled) {
                name = L"Susan Flint";
                laptime = 105.110f;
                s1 = 31.642f; s2 = 41.520f; s3 = 31.948f;
                delta = 2.3f;
            } else if (behindCarIdx >= 0) {
                name = toWide(ir_session.cars[behindCarIdx].userName);
                laptime = ir_CarIdxLastLapTime.getFloat(behindCarIdx);
                s1 = m_trackers[behindCarIdx].lastS1;
                s2 = m_trackers[behindCarIdx].lastS2;
                s3 = m_trackers[behindCarIdx].lastS3;

                // Calculate time gap (always positive/behind)
                const float L = ir_estimateLaptime();
                const float C = ir_CarIdxEstTime.getFloat(behindCarIdx);
                const float S = ir_CarIdxEstTime.getFloat(myCarIdx);
                const bool wrap = fabsf(ir_CarIdxLapDistPct.getFloat(behindCarIdx) - ir_CarIdxLapDistPct.getFloat(myCarIdx)) > 0.5f;
                if (wrap) {
                    delta = S > C ? (C - S) + L : (C - S) - L;
                } else {
                    delta = C - S;
                }
                if (delta < 0) delta = -delta; // force positive representation for behind
            }

            // Line 1: Pos, Name, Gap, Laptime
            swprintf(s, _countof(s), L"P%d", behindPos);
            m_text.render(m_renderTarget.Get(), s, m_textFormat.Get(), 10, 45, yBehind, textBrush.Get(), DWRITE_TEXT_ALIGNMENT_LEADING);
            m_text.render(m_renderTarget.Get(), name.c_str(), m_textFormat.Get(), 50, 190, yBehind, textBrush.Get(), DWRITE_TEXT_ALIGNMENT_LEADING);
            
            swprintf(s, _countof(s), L"+%.1fs", fabsf(delta));
            m_text.render(m_renderTarget.Get(), s, m_textFormat.Get(), 195, 260, yBehind, redBrush.Get(), DWRITE_TEXT_ALIGNMENT_LEADING);
            
            m_text.render(m_renderTarget.Get(), formatLap(laptime).c_str(), m_textFormat.Get(), 265, w - 10, yBehind, textBrush.Get(), DWRITE_TEXT_ALIGNMENT_TRAILING);

            // Line 2: Sectors
            swprintf(s, _countof(s), L"S1: %s", formatSector(s1).c_str());
            m_text.render(m_renderTarget.Get(), s, m_sectorFormat.Get(), 50, 140, yBehind + 22.0f, grayBrush.Get(), DWRITE_TEXT_ALIGNMENT_LEADING);
            swprintf(s, _countof(s), L"S2: %s", formatSector(s2).c_str());
            m_text.render(m_renderTarget.Get(), s, m_sectorFormat.Get(), 145, 235, yBehind + 22.0f, grayBrush.Get(), DWRITE_TEXT_ALIGNMENT_LEADING);
            swprintf(s, _countof(s), L"S3: %s", formatSector(s3).c_str());
            m_text.render(m_renderTarget.Get(), s, m_sectorFormat.Get(), 240, w - 10, yBehind + 22.0f, grayBrush.Get(), DWRITE_TEXT_ALIGNMENT_LEADING);
        } else {
            m_text.render(m_renderTarget.Get(), L"No driver behind", m_sectorFormat.Get(), 10, w - 10, yBehind + 10.0f, grayBrush.Get(), DWRITE_TEXT_ALIGNMENT_CENTER);
        }
    }

private:
    Microsoft::WRL::ComPtr<IDWriteTextFormat> m_textFormat;
    Microsoft::WRL::ComPtr<IDWriteTextFormat> m_textFormatBold;
    Microsoft::WRL::ComPtr<IDWriteTextFormat> m_sectorFormat;
    TextCache m_text;
};
