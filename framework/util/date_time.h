/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef GFXRECON_UTIL_DATE_TIME_H
#define GFXRECON_UTIL_DATE_TIME_H

#include "util/defines.h"
#include "util/logging.h"
#include "util/platform.h"

#include <ctime>
#include <string>

#if defined(WIN32)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#endif // WIN32

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(datetime)

#if defined(WIN32)

// Retrieve a timestamp, relative to an undefined reference point, suitable for computing time intervals.
inline uint64_t GetTimestamp()
{
    LARGE_INTEGER StartingTime;
    LARGE_INTEGER Frequency;

    // Get time and convert ticks to microseconds
    QueryPerformanceFrequency(&Frequency);
    QueryPerformanceCounter(&StartingTime);
    StartingTime.QuadPart *= 1000000;
    StartingTime.QuadPart /= Frequency.QuadPart;

    // Convert to nanoseconds
    return (static_cast<int64_t>(StartingTime.QuadPart) * 1000);
}

#else // !defined(WIN32)

// Retrieve a timestamp, relative to an undefined reference point, suitable for computing time intervals.
inline int64_t GetTimestamp()
{
#if defined(CLOCK_MONOTONIC_RAW)
    const clockid_t clock_id = CLOCK_MONOTONIC_RAW;
#elif defined(CLOCK_MONOTONIC)
    const clockid_t clock_id = CLOCK_MONOTONIC;
#else
    const clockid_t clock_id = CLOCK_REALTIME;
#endif

    timespec time;
    clock_gettime(clock_id, &time);
    int64_t timestamp = (1000000000 * static_cast<int64_t>(time.tv_sec)) + static_cast<int64_t>(time.tv_nsec);
    return timestamp;
}

#endif // WIN32

inline int64_t DiffTimestamps(int64_t start, int64_t end)
{
    return end - start;
}

inline double ConvertTimestampToMilliseconds(int64_t timestamp)
{
    // Timestamp is in nano-seconds, so convert to milliseconds
    return static_cast<double>(timestamp) / 1000000.0;
}

inline double ConvertTimestampToSeconds(int64_t timestamp)
{
    // Timestamp is in nano-seconds, so convert to seconds
    return static_cast<double>(timestamp) / 1000000000.0;
}

inline std::string GetDateTimeString(bool use_gmt)
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

GFXRECON_END_NAMESPACE(datetime)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_DATE_TIME_H
