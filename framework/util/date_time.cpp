/*
** Copyright (c) 2018, 2022 Valve Corporation
** Copyright (c) 2018, 2023 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

#include "util/date_time.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(datetime)

std::string GetDateTimeString(bool use_gmt)
{
    tm          now;
    time_t      timer  = time(nullptr);
    int32_t     result = 0;
    std::string datetime;

    if (use_gmt)
    {
        result = platform::GMTime(&now, &timer);
    }
    else
    {
        result = platform::LocalTime(&now, &timer);
    }

    if (result == 0)
    {
        char time_char_buffer[17] = { 0 };
        strftime(time_char_buffer, 17, "%Y%m%dT%H%M%S", &now);

        if (use_gmt)
        {
            time_char_buffer[15] = 'Z';
            time_char_buffer[16] = '\0';
        }
        else
        {
            time_char_buffer[15] = '\0';
        }

        datetime = time_char_buffer;
    }
    else
    {
        GFXRECON_LOG_ERROR("GetDateTimeString failed to retrieve localtime/gmtime");
    }

    return datetime;
}

std::string UtcString(const time_t seconds_since_epoch)
{
    struct tm  now_gm;
    const auto gmt_result = platform::GMTime(&now_gm, &seconds_since_epoch);

    std::string now_str;
    if (gmt_result == 0)
    {
        now_str += std::to_string(1900 + now_gm.tm_year);
        now_str += '-';
        const auto month_base_one = 1 + now_gm.tm_mon;
        if (month_base_one < 10)
        {
            now_str += '0';
        }
        now_str += std::to_string(month_base_one);
        now_str += '-';
        if (now_gm.tm_mday < 10)
        {
            now_str += '0';
        }
        now_str += std::to_string(now_gm.tm_mday);
        now_str += 'T';
        if (now_gm.tm_hour < 10)
        {
            now_str += '0';
        }
        now_str += std::to_string(now_gm.tm_hour);
        now_str += ':';
        if (now_gm.tm_min < 10)
        {
            now_str += '0';
        }
        now_str += std::to_string(now_gm.tm_min);
        now_str += ':';
        if (now_gm.tm_sec < 10)
        {
            now_str += '0';
        }
        now_str += std::to_string(now_gm.tm_sec);
        now_str += 'Z';
    }
    else
    {
        GFXRECON_LOG_ERROR(
            ("platform::GMTime(" + std::to_string(seconds_since_epoch) + ") -> " + std::to_string(gmt_result) + ')')
                .c_str());
    }

    return now_str;
}

std::string UtcNowString()
{
    const time_t now_time_t = time(nullptr);
    std::string  now_str    = UtcString(now_time_t);
    return now_str;
}

GFXRECON_END_NAMESPACE(datetime)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
