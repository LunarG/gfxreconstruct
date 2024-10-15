
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

#ifndef GFXRECON_DECODE_PRELOAD_ALLOCATOR_H
#define GFXRECON_DECODE_PRELOAD_ALLOCATOR_H

#include "util/defines.h"
#include "format/format_util.h"

#include "util/logging.h"

#include <memory>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class PreloadAllocator
{
  public:
    PreloadAllocator();
    ~PreloadAllocator();

    void Initialize();

    template <typename T>
    void Add(T* data)
    {
        if (IsCopyMemorySafe(sizeof(T)))
        {
            Save(data);
        }
        else
        {
            PrintPreloadMemoryError();
        }
    }

    template <typename T>
    T* Allocate(size_t count, bool initialize = true)
    {
        T* result = reinterpret_cast<T*>(Allocate(sizeof(T) * count, alignof(T)));
        if ((result != nullptr) && initialize)
        {
            for (size_t i = 0; i < count; ++i)
            {
                T* obj = new (result + i) T();
                if (!std::is_trivially_destructible<T>())
                {
                    destructors_.push_back({ obj, [](const void* x) { static_cast<const T*>(x)->~T(); } });
                }
            }
        }

        return result;
    }

    void Reset();
    void Clear();

  private:
    inline bool IsCopyMemorySafe(size_t data_size)
    {
        if (preload_memory_offset_record_ + data_size > preload_memory_capacity_)
            return false;
        return true;
    }

    inline void PrintPreloadMemoryError()
    {
        GFXRECON_LOG_FATAL("Preload memory is not enough! Run again without preload.");
        exit(-1);
    }

    template <typename T>
    inline void Save(T* data)
    {
        memcpy(preload_memory_ + preload_memory_offset_record_, reinterpret_cast<char*>(data), sizeof(T));
        preload_memory_offset_record_ += sizeof(T);
    }

    void  AllocateMemory(size_t size);
    void* Allocate(size_t object_bytes, size_t alignment_bytes);
    void* AllocateToBlock(size_t object_bytes, size_t alignment_bytes);

  private:
    struct Destructor
    {
        void* obj;
        void (*destroy)(const void*);
    };
    std::vector<Destructor> destructors_;

    char*  preload_memory_;
    size_t preload_memory_offset_record_;
    size_t preload_memory_offset_replay_;
    size_t preload_memory_capacity_;
    size_t preload_memory_free_bytes_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_PRELOAD_DECODE_DECODE_ALLOCATOR_H
