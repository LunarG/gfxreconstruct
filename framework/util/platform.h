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

#ifndef GFXRECON_UTIL_PLATFORM_H
#define GFXRECON_UTIL_PLATFORM_H

#include "util/defines.h"

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <thread>

#if defined(WIN32)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#else // WIN32
#include <errno.h>
#include <pthread.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <signal.h>
#endif // WIN32

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(platform)

enum FileSeekOrigin
{
    FileSeekCurrent = SEEK_CUR,
    FileSeekEnd     = SEEK_END,
    FileSeekSet     = SEEK_SET
};

#if defined(WIN32)

typedef DWORD pid_t;

inline pid_t GetCurrentProcessId()
{
    return ::GetCurrentProcessId();
}

inline uint64_t GetCurrentThreadId()
{
    return ::GetCurrentThreadId();
}

inline void TriggerDebugBreak()
{
    __debugbreak();
}

inline std::string GetEnv(const char* name)
{
    try
    {
        // value_size DOES include the null terminator, so for any set variable
        // will always be at least 1. If it's 0, the variable wasn't set.
        DWORD value_size = GetEnvironmentVariableA(name, nullptr, 0);
        if (value_size != 0)
        {
            // Max environment variable size (including null terminator).
            const size_t kMaxEnvSize = 8196;
            char         return_value[kMaxEnvSize];
            GetEnvironmentVariableA(name, return_value, value_size);
            return std::string(return_value);
        }
    }
    catch (...)
    {
        // Something bad happened during alloc or function call.
    }
    return std::string("");
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
    return strncpy_s(destination, destination_size, source, source_size);
}

inline int32_t StringCopy(wchar_t* destination, size_t destination_size, const wchar_t* source, size_t source_size)
{
    return wcsncpy_s(destination, destination_size, source, source_size);
}

inline int32_t FileOpen(FILE** stream, const char* filename, const char* mode)
{
    return static_cast<int32_t>(fopen_s(stream, filename, mode));
}

inline int64_t FileTell(FILE* stream)
{
    return _ftelli64(stream);
}

inline bool FileSeek(FILE* stream, int64_t offset, FileSeekOrigin origin)
{
    int32_t result = _fseeki64(stream, offset, origin);
    return (result == 0) ? true : false;
}

inline size_t FileWriteNoLock(const void* buffer, size_t element_size, size_t element_count, FILE* stream)
{
    return _fwrite_nolock(buffer, element_size, element_count, stream);
}

inline size_t FileReadNoLock(void* buffer, size_t element_size, size_t element_count, FILE* stream)
{
    return _fread_nolock(buffer, element_size, element_count, stream);
}

inline int32_t FileVprintf(FILE* stream, const char* format, va_list vlist)
{
    return vfprintf_s(stream, format, vlist);
}

inline int32_t LocalTime(tm* local_time, const time_t* timer)
{
    return static_cast<int32_t>(localtime_s(local_time, timer));
}

inline int32_t GMTime(tm* gm_time, const time_t* timer)
{
    return static_cast<int32_t>(gmtime_s(gm_time, timer));
}

#else // !defined(WIN32)

// Error value indicating string was truncated
#define STRUNCATE 80

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

inline std::string GetEnv(const char* name)
{
    const char* ret_value = getenv(name);
    if (nullptr != ret_value)
    {
        return std::string(ret_value);
    }
    return std::string("");
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

inline int32_t StringCopy(wchar_t* destination, size_t destination_size, const wchar_t* source, size_t source_size)
{
    if (source_size > destination_size)
    {
        wcsncpy(destination, source, destination_size);
        return STRUNCATE;
    }
    else
    {
        wcsncpy(destination, source, source_size);
        return 0;
    }
}

inline int32_t FileOpen(FILE** stream, const char* filename, const char* mode)
{
    (*stream) = fopen(filename, mode);
    return errno;
}

inline int64_t FileTell(FILE* stream)
{
    return ftello(stream);
}

inline bool FileSeek(FILE* stream, int64_t offset, FileSeekOrigin origin)
{
    int32_t result = fseeko(stream, offset, origin);
    return (result == 0) ? true : false;
}

inline size_t FileWriteNoLock(const void* buffer, size_t element_size, size_t element_count, FILE* stream)
{
#if defined(__ANDROID__) && (__ANDROID_API__ < 28)
    return fwrite(buffer, element_size, element_count, stream);
#else
    return fwrite_unlocked(buffer, element_size, element_count, stream);
#endif
}

inline size_t FileReadNoLock(void* buffer, size_t element_size, size_t element_count, FILE* stream)
{
#if defined(__ANDROID__) && (__ANDROID_API__ < 28)
    return fread(buffer, element_size, element_count, stream);
#else
    return fread_unlocked(buffer, element_size, element_count, stream);
#endif
}

inline int32_t FileVprintf(FILE* stream, const char* format, va_list vlist)
{
    return vfprintf(stream, format, vlist);
}

inline int32_t LocalTime(tm* local_time, const time_t* timer)
{
    tm* result = localtime(timer);
    if (result != nullptr)
    {
        memcpy(local_time, result, sizeof(tm));
        return 0;
    }
    else
    {
        return errno;
    }
}

inline int32_t GMTime(tm* gm_time, const time_t* timer)
{
    tm* result = gmtime(timer);
    if (result != nullptr)
    {
        memcpy(gm_time, result, sizeof(tm));
        return 0;
    }
    else
    {
        return errno;
    }
}

#endif // WIN32

inline size_t StringLength(const char* s)
{
    return strlen(s);
}

inline size_t StringLength(const wchar_t* s)
{
    return wcslen(s);
}

inline int32_t StringCompare(const char* string_1, const char* string_2, size_t compare_size)
{
    return strncmp(string_1, string_2, compare_size);
}

inline int32_t StringCompare(const wchar_t* string_1, const wchar_t* string_2, size_t compare_size)
{
    return wcsncmp(string_1, string_2, compare_size);
}

inline int32_t FilePuts(const char* char_string, FILE* stream)
{
    return fputs(char_string, stream);
}

inline int32_t FileFlush(FILE* stream)
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

GFXRECON_END_NAMESPACE(platform)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_PLATFORM_H
