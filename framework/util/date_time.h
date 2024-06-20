/*
** Copyright (c) 2018, 2022 Valve Corporation
** Copyright (c) 2018, 2022 LunarG, Inc.
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
/// @file Helpers for working with dates and times.

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

///@ Retrieve a timestamp, relative to an undefined reference point, suitable for computing time intervals.
inline int64_t GetTimestamp()
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

///@ Retrieve a timestamp, relative to an undefined reference point, suitable for computing time intervals.
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

inline double GetElapsedSeconds(int64_t start_timestamp, int64_t end_timestamp)
{
    return ConvertTimestampToSeconds(DiffTimestamps(start_timestamp, end_timestamp));
}

/// @brief Generate a compact representation of the current time.
/// @param use_gmt Use a location-independent time zone if true, else the local
/// one.
std::string GetDateTimeString(bool use_gmt);

/// @brief A moment in time to a rfc3339 UTC time as a string, to second
/// resolution.
/// rfc3339 looks like `1970-00-01T00:00:00Z`.
std::string UtcString(const time_t seconds_since_epoch);

/// @brief The current moment in UTC to the second as a string formatted to
/// rfc3339.
std::string UtcNowString();

#if defined(WIN32)

// Time in seconds since boot
inline double GetBootTime()
{
    return ConvertTimestampToSeconds(GetTimestamp());
}

// Time in seconds consumed by this process
inline double GetProcessTime()
{
    ULONG64 CycleTime;

    // Get time and convert ticks to seconds
    QueryProcessCycleTime(GetCurrentProcess(), &CycleTime);
    return (static_cast<double>(CycleTime) / CLOCKS_PER_SEC);
}

#else // !defined(WIN32)

// Time in seconds since boot
inline double GetBootTime()
{
#if defined(CLOCK_BOOTTIME)

    timespec time;
    clock_gettime(CLOCK_BOOTTIME, &time);
    int64_t timestamp = (1000000000 * static_cast<int64_t>(time.tv_sec)) + static_cast<int64_t>(time.tv_nsec);
    return ConvertTimestampToSeconds(timestamp);

#else
    return 0.0;
#endif
}

// Time in seconds consumed by this process
inline double GetProcessTime()
{
#if defined(CLOCK_PROCESS_CPUTIME_ID)

    timespec time;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time);
    int64_t timestamp = (1000000000 * static_cast<int64_t>(time.tv_sec)) + static_cast<int64_t>(time.tv_nsec);
    return ConvertTimestampToSeconds(timestamp);

#else
    return 0.0;
#endif
}

#endif // WIN32

GFXRECON_END_NAMESPACE(datetime)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_DATE_TIME_H
