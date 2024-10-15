
/*
** Copyright (c) 2020 LunarG, Inc.
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

#include "decode/preload_allocator.h"
#include <memory>
#if defined(WIN32)
#include <windows.h>
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

static size_t GetAvailableMemorySize()
{
    size_t available_memory_size = 0;
#if defined(ANDROID) || defined(__linux__)
    std::string   token;
    std::ifstream file("/proc/meminfo");
    while (file >> token)
    {
        if (token == "MemFree:")
        {
            size_t memory_size;
            if (file >> memory_size)
            {
                available_memory_size += memory_size;
            }
        }
        else if (token == "Buffers:")
        {
            size_t buffers_size;
            if (file >> buffers_size)
            {
                available_memory_size += buffers_size;
            }
        }
        else if (token == "Cached:")
        {
            size_t cached_size;
            if (file >> cached_size)
            {
                available_memory_size += cached_size;
            }
        }
        // ignore rest of the line
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    available_memory_size *= 1024; // To bytes
#elif defined(_WIN32)
    MEMORYSTATUSEX memory_status;
    memory_status.dwLength = sizeof(memory_status);
    GlobalMemoryStatusEx(&memory_status);
    available_memory_size = static_cast<size_t>(memory_status.ullAvailPhys);
#else
    GFXRECON_LOG_ERROR("Unsupported platform! Failed to get available memory for preload");

#endif
    return available_memory_size;
}

PreloadAllocator::PreloadAllocator() :
    preload_memory_(nullptr), preload_memory_offset_record_(0), preload_memory_offset_replay_(0),
    preload_memory_capacity_(0), preload_memory_free_bytes_(0)
{
    Initialize();
}

PreloadAllocator::~PreloadAllocator()
{
    if (preload_memory_ != nullptr)
    {
        delete[] preload_memory_;
        preload_memory_ = nullptr;
    }
}

void PreloadAllocator::AllocateMemory(size_t size)
{
    try
    {
        preload_memory_            = new char[size];
        preload_memory_capacity_   = size;
        preload_memory_free_bytes_ = size;
    }
    catch (const std::exception& e)
    {
        GFXRECON_LOG_ERROR("Failed to allocate memory for preload");
    }
}

void PreloadAllocator::Initialize()
{
    Reset();
    size_t system_available_memory_size = GetAvailableMemorySize();
    AllocateMemory(system_available_memory_size / 2);
}

void PreloadAllocator::Reset()
{
    // Call destructors of allocated objects
    for (auto destructor : destructors_)
    {
        destructor.destroy(destructor.obj);
    }
    destructors_.clear();

    if (preload_memory_ != nullptr)
    {
        delete[] preload_memory_;
        preload_memory_ = nullptr;
    }

    preload_memory_offset_record_ = 0;
    preload_memory_offset_replay_ = 0;
    preload_memory_capacity_      = 0;
    preload_memory_free_bytes_    = 0;
}

void PreloadAllocator::Clear()
{
    Reset();
}

void* PreloadAllocator::Allocate(size_t object_bytes, size_t alignment_bytes)
{
    void* result = nullptr;

    // Don't allocate 0 bytes
    assert(object_bytes + alignment_bytes > 0);
    if (object_bytes + alignment_bytes == 0)
    {
        return nullptr;
    }

    // Find the start position
    if (object_bytes < preload_memory_free_bytes_)
    {
        result = AllocateToBlock(object_bytes, alignment_bytes);
    }
    else
    {
        PrintPreloadMemoryError();
    }

    return result;
}

void* PreloadAllocator::AllocateToBlock(size_t object_bytes, size_t alignment_bytes)
{
    void* block_ptr = reinterpret_cast<void*>(preload_memory_ + preload_memory_offset_record_);
    void* result    = std::align(alignment_bytes, object_bytes, block_ptr, preload_memory_free_bytes_);
    if (result != nullptr)
    {
        preload_memory_free_bytes_ -= object_bytes;
        preload_memory_offset_record_ = preload_memory_capacity_ - preload_memory_free_bytes_;
    }
    return result;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
