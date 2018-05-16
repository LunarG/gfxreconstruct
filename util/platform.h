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

#include <cinttypes>
#include <cstdio>
#include <thread>

#if defined(WIN32)
#include <windows.h>
#else  // WIN32
#include <errno.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#endif // WIN32

#include "util/defines.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(util)
BRIMSTONE_BEGIN_NAMESPACE(platform)

#if defined(WIN32)

typedef DWORD pid_t;

pid_t get_current_process_id()
{
    return GetCurrentProcessId();
}

uint64_t get_current_thread_id()
{
    return GetCurrentThreadId();
}

errno_t file_open(FILE** stream, const char* filename, const char* mode)
{
    return fopen_s(stream, filename, mode);
}

size_t file_write_nolock(const void* buffer, size_t element_size, size_t element_count, FILE* stream)
{
    return _fwrite_nolock(buffer, element_size, element_count, stream);
}

size_t file_read_nolock(void* buffer, size_t element_size, size_t element_count, FILE* stream)
{
    return _fread_nolock(buffer, element_size, element_count, stream);
}

#else  // WIN32

pid_t get_current_process_id()
{
    return getpid();
}

uint64_t get_current_thread_id()
{
    uint64_t tid = 0;
    pthread_threadid_np(NULL, &tid);
    return tid;
}

errno_t file_open(FILE** stream, const char* filename, const char* mode)
{
    (*stream) = fopen(filename, mode);
    return errno;
}

size_t file_write_nolock(const void* buffer, size_t element_size, size_t element_count, FILE* stream)
{
    return fwrite_unlocked(buffer, element_size, element_count, stream);
}

size_t file_read_nolock(void* buffer, size_t element_size, size_t element_count, FILE* stream)
{
    return fread_unlocked(buffer, element_size, element_count, stream);
}

#endif // WIN32

size_t file_write(const void* buffer, size_t element_size, size_t element_count, FILE* stream)
{
    return fwrite(buffer, element_size, element_count, stream);
}

size_t file_read(void* buffer, size_t element_size, size_t element_count, FILE* stream)
{
    return fread(buffer, element_size, element_count, stream);
}

int file_close(FILE* stream)
{
    return fclose(stream);
}

BRIMSTONE_END_NAMESPACE(platform)
BRIMSTONE_END_NAMESPACE(util)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_UTIL_PLATFORM_H
