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

inline pid_t get_current_process_id()
{
    return GetCurrentProcessId();
}

inline uint64_t get_current_thread_id()
{
    return GetCurrentThreadId();
}

inline void trigger_debug_break()
{
    __debugbreak();
}

inline bool get_environment_variable(const char* name, std::string& value)
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

inline int32_t file_open(FILE** stream, const char* filename, const char* mode)
{
    return static_cast<int32_t>(fopen_s(stream, filename, mode));
}

inline size_t file_write_nolock(const void* buffer, size_t element_size, size_t element_count, FILE* stream)
{
    return _fwrite_nolock(buffer, element_size, element_count, stream);
}

inline size_t file_read_nolock(void* buffer, size_t element_size, size_t element_count, FILE* stream)
{
    return _fread_nolock(buffer, element_size, element_count, stream);
}

inline int file_vprintf(FILE *stream, const char *format, va_list vlist)
{
    return vfprintf_s(stream, format, vlist);
}

#else  // !defined(WIN32)

inline pid_t get_current_process_id()
{
    return getpid();
}

inline uint64_t get_current_thread_id()
{
    return static_cast<uint64_t>(syscall(SYS_gettid));
}

inline void trigger_debug_break()
{
    raise(SIGTRAP);
}

inline bool get_environment_variable(const char* name, std::string& value)
{
    value = getenv(name);
    return (value.size() > 0);
}

inline int32_t file_open(FILE** stream, const char* filename, const char* mode)
{
    (*stream) = fopen(filename, mode);
    return errno;
}

inline size_t file_write_nolock(const void* buffer, size_t element_size, size_t element_count, FILE* stream)
{
    return fwrite_unlocked(buffer, element_size, element_count, stream);
}

inline size_t file_read_nolock(void* buffer, size_t element_size, size_t element_count, FILE* stream)
{
    return fread_unlocked(buffer, element_size, element_count, stream);
}

inline int file_vprintf(FILE *stream, const char *format, va_list vlist)
{
    return vfprintf(stream, format, vlist);
}

#endif // WIN32

inline int32_t file_puts(const char *char_string, FILE *stream)
{
    return fputs(char_string, stream);
}

inline int32_t file_flush(FILE *stream)
{
    return fflush(stream);
}

inline size_t file_write(const void* buffer, size_t element_size, size_t element_count, FILE* stream)
{
    return fwrite(buffer, element_size, element_count, stream);
}

inline size_t file_read(void* buffer, size_t element_size, size_t element_count, FILE* stream)
{
    return fread(buffer, element_size, element_count, stream);
}

inline int32_t file_close(FILE* stream)
{
    return fclose(stream);
}

BRIMSTONE_END_NAMESPACE(platform)
BRIMSTONE_END_NAMESPACE(util)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_UTIL_PLATFORM_H
