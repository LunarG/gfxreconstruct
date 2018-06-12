/*
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

#ifndef BRIMSTONE_UTIL_PLATFORM_H
#define BRIMSTONE_UTIL_PLATFORM_H

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <thread>


#if defined(WIN32)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#else  // WIN32
#include <errno.h>
#include <pthread.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <signal.h>
#endif // WIN32

#include "util/defines.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(util)
BRIMSTONE_BEGIN_NAMESPACE(platform)

#if defined(WIN32)

typedef DWORD pid_t;

inline pid_t GetCurrentProcessId()
{
    return GetCurrentProcessId();
}

inline uint64_t GetCurrentThreadId()
{
    return GetCurrentThreadId();
}

inline void TriggerDebugBreak()
{
    __debugbreak();
}

inline bool GetEnvironmentVariable(const char* name, std::string& value)
{
    try
    {
        // value_size DOES include the null terminator, so for any set variable
        // will always be at least 1. If it's 0, the variable wasn't set.
        DWORD value_size = GetEnvironmentVariableA(name, nullptr, 0);
        if (value_size == 0) {
            return false;
        }

        // Allocate the space necessary for the registry entry
        value.resize(value_size);
        GetEnvironmentVariableA(name, value_size.data(), value_size.size());
        return true;
    }
    catch (...)
    {
        // Something bad happened during alloc or function call.
        return false;
    }
}

inline int32_t MemoryCopy(void* destination, size_t destination_size, const void* source, size_t source_size)
{
    return memcpy_s(destination, destination_size, source, source_size);
}

inline int32_t MemoryCompare(const void* memory_1, const void* memory_2, size_t compare_size)
{
    return memcmp(memory_1, memory_2, compare_size);
}

inline int32_t StringCopy(char* destination, size_t destination_size, const char* source, size_t source_size)
{
    return strncpy_s(destination, destination_size, source, copy_size);
}

inline int32_t StringCompare(const char* string_1, const char* string_2, size_t compare_size)
{
    return strncmp(string_1, string_2, compare_size);
}

inline int32_t FileOpen(FILE** stream, const char* filename, const char* mode)
{
    return static_cast<int32_t>(fopen_s(stream, filename, mode));
}

inline size_t FileWriteNolock(const void* buffer, size_t element_size, size_t element_count, FILE* stream)
{
    return _fwrite_nolock(buffer, element_size, element_count, stream);
}

inline size_t FileReadNolock(void* buffer, size_t element_size, size_t element_count, FILE* stream)
{
    return _fread_nolock(buffer, element_size, element_count, stream);
}

inline int32_t FileVprintf(FILE *stream, const char *format, va_list vlist)
{
    return vfprintf_s(stream, format, vlist);
}

#else  // !defined(WIN32)

// Error value indicating string was truncated
#define STRUNCATE   80

inline pid_t GetCurrentProcessId()
{
    return getpid();
}

inline uint64_t GetCurrentThreadId()
{
    return static_cast<uint64_t>(syscall(SYS_gettid));
}

inline void TriggerDebugBreak()
{
    raise(SIGTRAP);
}

inline bool GetEnvironmentVariable(const char* name, std::string& value)
{
    value = getenv(name);
    return (value.size() > 0);
}

inline int32_t MemoryCopy(void* destination, size_t destination_size, const void* source, size_t source_size)
{
    if (source_size > destination_size)
    {
        std::memcpy(destination, source, destination_size);
        return STRUNCATE;
    }
    else
    {
        std::memcpy(destination, source, source_size);
        return 0;
    }
}

inline int32_t MemoryCompare(const void* memory_1, const void* memory_2, size_t compare_size)
{
    return memcmp(memory_1, memory_2, compare_size);
}

inline int32_t StringCopy(char* destination, size_t destination_size, const char* source, size_t source_size)
{
    if (source_size > destination_size)
    {
        strncpy(destination, source, destination_size);
        return STRUNCATE;
    }
    else
    {
        strncpy(destination, source, source_size);
        return 0;
    }
}

inline int32_t StringCompare(const char* string_1, const char* string_2, size_t compare_size)
{
    return strncmp(string_1, string_2, compare_size);
}

inline int32_t FileOpen(FILE** stream, const char* filename, const char* mode)
{
    (*stream) = fopen(filename, mode);
    return errno;
}

inline size_t FileWriteNolock(const void* buffer, size_t element_size, size_t element_count, FILE* stream)
{
    return fwrite_unlocked(buffer, element_size, element_count, stream);
}

inline size_t FileReadNolock(void* buffer, size_t element_size, size_t element_count, FILE* stream)
{
    return fread_unlocked(buffer, element_size, element_count, stream);
}

inline int32_t FileVprintf(FILE *stream, const char *format, va_list vlist)
{
    return vfprintf(stream, format, vlist);
}

#endif // WIN32

inline int32_t FilePuts(const char *char_string, FILE *stream)
{
    return fputs(char_string, stream);
}

inline int32_t FileFlush(FILE *stream)
{
    return fflush(stream);
}

inline size_t FileWrite(const void* buffer, size_t element_size, size_t element_count, FILE* stream)
{
    return fwrite(buffer, element_size, element_count, stream);
}

inline size_t FileRead(void* buffer, size_t element_size, size_t element_count, FILE* stream)
{
    return fread(buffer, element_size, element_count, stream);
}

inline int32_t FileClose(FILE* stream)
{
    return fclose(stream);
}

BRIMSTONE_END_NAMESPACE(platform)
BRIMSTONE_END_NAMESPACE(util)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_UTIL_PLATFORM_H
