/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
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

#ifndef GFXRECON_UTIL_PLATFORM_H
#define GFXRECON_UTIL_PLATFORM_H

#include "util/defines.h"

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <string>
#include <thread>
#include <vector>

// NOTE: this works around potential issues on msvc / VS 2019 with wrongly defined __cplusplus constant
#if defined(_MSVC_LANG)
#define CPP_STD _MSVC_LANG
#else
#define CPP_STD __cplusplus
#endif

#if CPP_STD < 202002L
#warning "Unsupported compiler: this project requires support for C++20."
#endif

#if defined(WIN32)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <direct.h>
#else // WIN32
#include <dlfcn.h>
#include <errno.h>
#include <pthread.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/mman.h>
#endif // WIN32

#if defined(__ANDROID__)
#include <sys/system_properties.h>
#endif

#ifdef __linux__
#include <sched.h>
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(platform)

enum FileSeekOrigin
{
    FileSeekCurrent = SEEK_CUR,
    FileSeekEnd     = SEEK_END,
    FileSeekSet     = SEEK_SET
};

#if defined(__ANDROID__)
const int32_t kMaxPropertyLength = 255;
#endif

#if defined(WIN32)

typedef DWORD   pid_t;
typedef HMODULE LibraryHandle;

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

inline LibraryHandle OpenLibrary(const char* name)
{
    return LoadLibraryA(name);
}

inline void CloseLibrary(LibraryHandle handle)
{
    FreeLibrary(handle);
}

inline void* GetProcAddress(LibraryHandle handle, const char* name)
{
    return ::GetProcAddress(handle, name);
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

inline bool SetEnv(const char* name, const char* value)
{
    return SetEnvironmentVariableA(name, value);
}

inline int32_t MemoryCopy(void* destination, size_t destination_size, const void* source, size_t source_size)
{
    return memcpy_s(destination, destination_size, source, source_size);
}

inline int32_t MemoryCompare(const void* memory_1, const void* memory_2, size_t compare_size)
{
    return memcmp(memory_1, memory_2, compare_size);
}

inline int32_t StringCompareNoCase(const char* string_1, const char* string_2)
{
    return _stricmp(string_1, string_2);
}

inline int32_t StringCompareNoCase(const wchar_t* string_1, const wchar_t* string_2)
{
    return _wcsicmp(string_1, string_2);
}

inline int32_t StringCompareNoCase(const char* string_1, const char* string_2, size_t compare_size)
{
    return _strnicmp(string_1, string_2, compare_size);
}

inline int32_t StringCompareNoCase(const wchar_t* string_1, const wchar_t* string_2, size_t compare_size)
{
    return _wcsnicmp(string_1, string_2, compare_size);
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
    return (result == 0);
}

inline bool FileWriteNoLock(const void* buffer, size_t bytes, FILE* stream)
{
    return _fwrite_nolock(buffer, bytes, 1, stream) == 1;
}

inline bool FileReadNoLock(void* buffer, size_t bytes, FILE* stream)
{
    return _fread_nolock(buffer, bytes, 1, stream) == 1;
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

inline int32_t MakeDirectory(const char* filename)
{
    return _mkdir(filename);
}

inline size_t GetSystemPageSize()
{
    SYSTEM_INFO sSysInfo;
    GetSystemInfo(&sSysInfo);
    return sSysInfo.dwPageSize;
}

inline void* AllocateRawMemory(size_t aligned_size, bool use_write_watch = false, void* address = nullptr)
{
    assert(aligned_size > 0);

    if (aligned_size > 0)
    {
        DWORD flags = MEM_RESERVE | MEM_COMMIT;

        if (use_write_watch)
        {
            flags |= MEM_WRITE_WATCH;
        }

        return VirtualAlloc(address, aligned_size, flags, PAGE_READWRITE);
    }

    return nullptr;
}

inline void FreeRawMemory(void* memory, size_t aligned_size)
{
    assert(memory != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(aligned_size);
    VirtualFree(memory, 0, MEM_RELEASE);
}

inline int GetSystemLastErrorCode()
{
    return GetLastError();
}

inline std::string GetCpuAffinity()
{
    DWORD_PTR process_mask;
    DWORD_PTR system_mask;
    if (!GetProcessAffinityMask(GetCurrentProcess(), &process_mask, &system_mask))
    {
        return "";
    }

    DWORD_PTR mask = (process_mask & system_mask);

    std::string affinity;
    while (mask)
    {
        affinity += (mask & 1) ? "1" : "0";
        mask >>= 1;
    }

    while (affinity.back() == '0')
    {
        affinity.pop_back();
    }

    return affinity;
}

inline bool SetCpuAffinity(const std::string& affinity)
{
    DWORD_PTR mask = 0;
    for (unsigned i = 0; i < affinity.size(); i++)
    {
        if (affinity[i] == '1')
        {
            mask |= 1;
        }
        else if (affinity[i] != '0')
        {
            return false;
        }

        mask <<= 1;
    }

    return (SetProcessAffinityMask(GetCurrentProcess(), mask) != 0);
}

#else // !defined(WIN32)

// Error value indicating string was truncated
#define STRUNCATE 80

typedef void* LibraryHandle;

inline pid_t GetCurrentProcessId()
{
    return getpid();
}

inline uint64_t GetCurrentThreadId()
{
#ifdef __APPLE__
    uint64_t thread_id;
    pthread_threadid_np(pthread_self(), &thread_id);
    return thread_id;
#else
    return static_cast<uint64_t>(syscall(SYS_gettid));
#endif
}

#if !defined(__APPLE__)
inline int SendSignalToThread(uint64_t tid, int signal)
{
    return static_cast<int>(syscall(SYS_tgkill, getpid(), tid, signal));
}
#endif

inline void TriggerDebugBreak()
{
    raise(SIGTRAP);
}

inline LibraryHandle OpenLibrary(const char* name)
{
    return dlopen(name, RTLD_NOW | RTLD_LOCAL);
}

inline void CloseLibrary(LibraryHandle handle)
{
    dlclose(handle);
}

inline void* GetProcAddress(LibraryHandle handle, const char* name)
{
    return dlsym(handle, name);
}

inline std::string GetEnv(const char* name)
{
    std::string      env_value;

#if defined(__ANDROID__)
    const prop_info* pi = __system_property_find(name);

    if (pi)
    {
        __system_property_read_callback(
            pi,
            [](void* cookie, const char* name, const char* value, uint32_t serial) {
                std::string* prop = reinterpret_cast<std::string*>(cookie);
                *prop             = value;
            },
            &env_value);
    }
#else
    const char* ret_value = getenv(name);
    if (nullptr != ret_value)
    {
        env_value = ret_value;
    }
#endif

    return env_value;
}

inline bool SetEnv(const char* name, const char* value)
{
    return setenv(name, value, 1) == 0;
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

inline int32_t StringCompareNoCase(const char* string_1, const char* string_2)
{
    return strcasecmp(string_1, string_2);
}

inline int32_t StringCompareNoCase(const wchar_t* string_1, const wchar_t* string_2)
{
    return wcscasecmp(string_1, string_2);
}

inline int32_t StringCompareNoCase(const char* string_1, const char* string_2, size_t compare_size)
{
    return strncasecmp(string_1, string_2, compare_size);
}

inline int32_t StringCompareNoCase(const wchar_t* string_1, const wchar_t* string_2, size_t compare_size)
{
    return wcsncasecmp(string_1, string_2, compare_size);
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
    if (stream == nullptr)
    {
        return EINVAL;
    }

    FILE* result = fopen(filename, mode);
    if (result != nullptr)
    {
        (*stream) = result;
        return 0;
    }
    else
    {
        return errno;
    }
}

inline int64_t FileTell(FILE* stream)
{
    return ftello(stream);
}

inline bool FileSeek(FILE* stream, int64_t offset, FileSeekOrigin origin)
{
    int32_t result = fseeko(stream, offset, origin);
    return (result == 0);
}

inline bool FileWriteNoLock(const void* buffer, size_t bytes, FILE* stream)
{
    size_t write_count = 0;
    int    err         = 0;
    do
    {
#if defined(__APPLE__) || (defined(__ANDROID__) && (__ANDROID_API__ < 28))
        write_count = fwrite(buffer, bytes, 1, stream);
#else
        write_count = fwrite_unlocked(buffer, bytes, 1, stream);
#endif
        err         = ferror(stream);
    } while (write_count < 1 && (err == EWOULDBLOCK || err == EINTR || err == EAGAIN));
    return (write_count == 1 || bytes == 0);
}

inline bool FileReadNoLock(void* buffer, size_t bytes, FILE* stream)
{
    size_t read_count = 0;
    int    err        = 0;
    do
    {
#if defined(__APPLE__) || (defined(__ANDROID__) && (__ANDROID_API__ < 28))
        read_count = fread(buffer, bytes, 1, stream);
#else
        read_count  = fread_unlocked(buffer, bytes, 1, stream);
#endif
        err        = ferror(stream);
    } while (!feof(stream) && read_count < 1 && (err == EWOULDBLOCK || err == EINTR || err == EAGAIN));
    return (read_count == 1 || bytes == 0);
}

inline int32_t FileVprintf(FILE* stream, const char* format, va_list vlist)
{
    return vfprintf(stream, format, vlist);
}

inline int32_t LocalTime(tm* local_time, const time_t* timer)
{
#if defined(__ANDROID__) || defined(__USE_POSIX)
    tm* result = localtime_r(timer, local_time);
    return (result != nullptr) ? 0 : errno;
#else
    if (local_time == nullptr)
    {
        return EINVAL;
    }

    tm* result = localtime(timer);
    if (result != nullptr)
    {
        (*local_time) = (*result);
        return 0;
    }
    else
    {
        return errno;
    }
#endif
}

inline int32_t GMTime(tm* gm_time, const time_t* timer)
{
#if defined(__ANDROID__) || defined(__USE_POSIX)
    tm* result = gmtime_r(timer, gm_time);
    return (result != nullptr) ? 0 : errno;
#else
    if (gm_time == nullptr)
    {
        return EINVAL;
    }

    tm* result = gmtime(timer);
    if (result != nullptr)
    {
        (*gm_time) = (*result);
        return 0;
    }
    else
    {
        return errno;
    }
#endif
}

inline int32_t MakeDirectory(const char* filename)
{
    return mkdir(filename, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
}

inline size_t GetSystemPageSize()
{
    return getpagesize();
}

// Memory allocation without extra space for private info like with new or malloc
inline void* AllocateRawMemory(size_t aligned_size, bool use_write_watch = false, void* address = nullptr)
{
    assert(aligned_size > 0);

    if (aligned_size > 0)
    {
        const int flags  = address ? (MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED) : (MAP_PRIVATE | MAP_ANONYMOUS);
        void*     memory = mmap(address, aligned_size, PROT_READ | PROT_WRITE, flags, -1, 0);

        if (memory == MAP_FAILED)
        {
            return nullptr;
        }

        return memory;
    }

    return nullptr;
}

inline void FreeRawMemory(void* memory, size_t aligned_size)
{
    assert(memory != nullptr);

    munmap(memory, aligned_size);
}

inline int GetSystemLastErrorCode()
{
    return errno;
}

inline std::string GetCpuAffinity()
{
    std::string affinity;

#ifdef __linux__
    cpu_set_t   mask;
    if (sched_getaffinity(0, sizeof(mask), &mask))
    {
        return affinity;
    }

    for (unsigned i = 0; i < sizeof(mask) / CPU_ALLOC_SIZE(1); i++)
    {
        affinity += CPU_ISSET(i, &mask) ? "1" : "0";
    }

    while (affinity.back() == '0')
    {
        affinity.pop_back();
    }
#endif // __linux__

    return affinity;
}

inline bool SetCpuAffinity(const std::string& affinity)
{
#ifdef __linux__
    cpu_set_t mask;
    CPU_ZERO(&mask);
    for (unsigned i = 0; i < affinity.size(); i++)
    {
        if (affinity[i] == '1')
        {
            CPU_SET(i, &mask);
        }
        else if (affinity[i] != '0')
        {
            return false;
        }
    }

    return (sched_setaffinity(0, sizeof(mask), &mask) == 0);
#else // !__linux__
    return false;
#endif
}

#endif // WIN32

inline size_t GetAlignedSize(size_t size, size_t align_to)
{
    size_t extra = size & (align_to - 1); // size % system_page_size_
    if (extra != 0)
    {
        // Adjust the size to be a multiple of the system page size.
        size = size - extra + align_to;
    }

    return size;
}

inline bool IsAddressAligned(const void* address, size_t alignment)
{
    uintptr_t uint_addr = reinterpret_cast<uintptr_t>(address);
    return (uint_addr % alignment) == 0;
}

inline LibraryHandle OpenLibrary(const std::vector<std::string>& name_list)
{
    for (const auto& name : name_list)
    {
        const auto handle = OpenLibrary(name.c_str());
        if (handle != nullptr)
        {
            return handle;
        }
    }
    return nullptr;
}

inline size_t StringLength(const char* s)
{
    return strlen(s);
}

inline size_t StringLength(const wchar_t* s)
{
    return wcslen(s);
}

inline int32_t StringCompare(const char* string_1, const char* string_2)
{
    return strcmp(string_1, string_2);
}

inline int32_t StringCompare(const wchar_t* string_1, const wchar_t* string_2)
{
    return wcscmp(string_1, string_2);
}

inline int32_t StringCompare(const char* string_1, const char* string_2, size_t compare_size)
{
    return strncmp(string_1, string_2, compare_size);
}

inline int32_t StringCompare(const wchar_t* string_1, const wchar_t* string_2, size_t compare_size)
{
    return wcsncmp(string_1, string_2, compare_size);
}

inline bool StringContains(const char* text, const char* substring)
{
    return strstr(text, substring) != nullptr;
}

inline int32_t FileFlush(FILE* stream)
{
    return fflush(stream);
}

inline bool FileWrite(const void* buffer, size_t bytes, FILE* stream)
{
    size_t write_count = 0;
    int    err         = 0;
    do
    {
        write_count = fwrite(buffer, bytes, 1, stream);
        err         = ferror(stream);
    } while (write_count < 1 && (err == EWOULDBLOCK || err == EINTR || err == EAGAIN));
    return (write_count == 1 || bytes == 0);
}

inline bool FilePuts(const char* char_string, FILE* stream)
{
    return FileWrite(char_string, strlen(char_string), stream);
}

inline size_t FileReadBytes(void* buffer, size_t bytes, FILE* stream)
{
    size_t read_count    = 0;
    char*  dest_buffer   = static_cast<char*>(buffer);
    size_t bytes_to_read = bytes;
    while (read_count < bytes) // Early out for zero byte reads
    {
        size_t bytes_read = fread(dest_buffer, 1, bytes_to_read, stream);
        read_count += bytes_read;
        if (bytes_read < bytes_to_read)
        {
            dest_buffer += bytes_read;
            bytes_to_read -= bytes_read;

            if (feof(stream))
            {
                break;
            }
            else if (ferror(stream))
            {
                int err = errno;
                if ((err == EWOULDBLOCK) || (err == EINTR) || (err == EAGAIN))
                {
                    clearerr(stream);
                }
                else
                {
                    break;
                }
            }
        }
    }
    return read_count;
}

inline bool FileRead(void* buffer, size_t bytes, FILE* stream)
{
    return FileReadBytes(buffer, bytes, stream) == bytes;
}

inline int32_t SetFileBufferSize(FILE* stream, size_t buffer_size)
{
    return setvbuf(stream, nullptr, (buffer_size == 0) ? _IONBF : _IOFBF, buffer_size);
}

inline int32_t FileClose(FILE* stream)
{
    return fclose(stream);
}

// Align an address/offset value to a given number of bytes. Requires static alignment value.
template <uint64_t Alignment, typename T>
inline T AlignValue(T original)
{
    // Validate inputs.
    static_assert(std::is_unsigned<T>::value, "Value to align must be unsigned.");
    static_assert(std::numeric_limits<T>::max() > Alignment, "Alignment value is too large.");
    static_assert((Alignment > 0) && (((Alignment - 1) & Alignment) == 0), "Alignment must be a power of two.");

    T alignment_t = static_cast<T>(Alignment);
    return (original + (alignment_t - 1)) & ~(alignment_t - 1);
}

inline uint64_t SizeTtoUint64(size_t value)
{
#if defined(_WIN64)
    return value;
#else
    return static_cast<uint64_t>(value);
#endif
}

/// @brief Get the start address of the memory page containing the given pointer.
/// @param ptr Pointer to the memory location.
/// @return The start address of the memory page containing the pointer.
inline uintptr_t GetPageStartAddress(const void* ptr)
{
    static size_t page_size = GetSystemPageSize();
    return (reinterpret_cast<uintptr_t>(ptr) / page_size) * page_size;
}

#if defined(WIN32)

/// @brief Heuristically determine whether a pointer likely refers to readable
///        memory in the current process on Windows.
/// @param ptr Pointer to the memory location to check.
/// @return `true` if the pointer is valid, `false` otherwise.
/// @note This is a best-effort probe only; it cannot guarantee safety.
///       Even if this returns true, dereferencing the pointer can still fault.
/// @note This implementation is adapted from the LLVM compiler-rt project:
///       `llvm-project/compiler-rt/lib/sanitizer_common/sanitizer_win.cpp`
/// @copyright License notice for the original source: https://llvm.org/LICENSE.txt
///            Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
inline bool PointerIsValid(const void* ptr)
{
    if (ptr == nullptr)
    {
        return false;
    }

    uintptr_t page = GetPageStartAddress(ptr);

    MEMORY_BASIC_INFORMATION info;
    if (VirtualQuery(reinterpret_cast<LPCVOID>(page), &info, sizeof(info)) != sizeof(info))
    {
        return false;
    }

    if (info.Protect == 0 || info.Protect == PAGE_NOACCESS || info.Protect == PAGE_EXECUTE)
    {
        // The page is not accessible.
        return false;
    }

    if (info.RegionSize == 0)
    {
        return false;
    }

    return true;
}

#else  // (WIN32)

/// @brief This implementation probes whether the page containing ptr is currently mapped in this process,
///        to guess whether the pointer might be valid.
/// @param ptr Pointer to the memory location to check.
/// @return `true` if the pointer is valid, `false` otherwise.
/// @note This is not a safety/readability guarantee. A mapped page may still be unreadable (e.g., `PROT_NONE`),
///       so dereferencing ptr can still fault even if this returns `true`.
inline bool PointerIsValid(const void* ptr)
{
    if (ptr == nullptr)
    {
        return false;
    }

    uintptr_t     page_start = GetPageStartAddress(ptr);
    static size_t page_size  = GetSystemPageSize();
    // Returns -1 with errno=ENOMEM if the indicated memory (or part of it) was not mapped.
    return msync(reinterpret_cast<void*>(page_start), page_size, MS_ASYNC) == 0;
}
#endif // !WIN32

GFXRECON_END_NAMESPACE(platform)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_PLATFORM_H
