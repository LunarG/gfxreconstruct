/*
** Copyright (c) 2026 LunarG, Inc.
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

// Allocator impostor: counts every heap block handed out to code linked into the capture
// layer library, so the layer can report its own heap use (see util/heap_accounting.h).
//
// The layer is linked with -Wl,--wrap=<name> for each function defined here. The static
// linker then redirects every reference to <name> in the layer's own objects (gfxrecon,
// LZ4/ZSTD, and the statically linked C++ runtime, whose operator new ends in malloc) to
// __wrap_<name>, and resolves __real_<name> to the libc implementation. The application,
// the Vulkan loader, the driver and libc's own internal calls are not affected, and no
// symbol is interposed at run time.
//
// The wrappers have hidden visibility so that they are never exported, whatever the
// platform's export rules: the Android layer exports gfxrecon's own functions for tombstone
// symbolization, and an exported wrapper could be preempted by a same-named definition in
// another library. Only the definitions are hidden: the __real_ declarations must keep
// default visibility to resolve against libc.
//
// Block sizes come from malloc_usable_size, so no header is added to blocks and a pointer
// that was allocated outside the layer can still be freed safely.

#include "util/heap_accounting.h"

#include <cstddef>
#include <cstdlib>
#include <malloc.h>

#define GFXRECON_IMPOSTOR_API __attribute__((visibility("hidden")))

using gfxrecon::util::heap_accounting::RecordAlloc;
using gfxrecon::util::heap_accounting::RecordFree;

extern "C"
{
    void* __real_malloc(size_t size);
    void  __real_free(void* ptr);
    void* __real_calloc(size_t count, size_t size);
    void* __real_realloc(void* ptr, size_t size);
    int   __real_posix_memalign(void** result, size_t alignment, size_t size);
    void* __real_memalign(size_t alignment, size_t size);

    GFXRECON_IMPOSTOR_API void* __wrap_malloc(size_t size)
    {
        void* ptr = __real_malloc(size);
        if (ptr != nullptr)
        {
            RecordAlloc(malloc_usable_size(ptr));
        }
        return ptr;
    }

    GFXRECON_IMPOSTOR_API void __wrap_free(void* ptr)
    {
        if (ptr != nullptr)
        {
            RecordFree(malloc_usable_size(ptr));
        }
        __real_free(ptr);
    }

    GFXRECON_IMPOSTOR_API void* __wrap_calloc(size_t count, size_t size)
    {
        void* ptr = __real_calloc(count, size);
        if (ptr != nullptr)
        {
            RecordAlloc(malloc_usable_size(ptr));
        }
        return ptr;
    }

    GFXRECON_IMPOSTOR_API void* __wrap_realloc(void* ptr, size_t size)
    {
        const size_t old_size = (ptr != nullptr) ? malloc_usable_size(ptr) : 0;
        void*        result   = __real_realloc(ptr, size);

        if (result != nullptr)
        {
            if (ptr != nullptr)
            {
                RecordFree(old_size);
            }
            RecordAlloc(malloc_usable_size(result));
        }
        else if ((size == 0) && (ptr != nullptr))
        {
            // A zero-size request releases the block and returns null.
            RecordFree(old_size);
        }
        // Otherwise the reallocation failed and the original block is untouched.

        return result;
    }

    GFXRECON_IMPOSTOR_API int __wrap_posix_memalign(void** result, size_t alignment, size_t size)
    {
        int rc = __real_posix_memalign(result, alignment, size);
        if (rc == 0)
        {
            RecordAlloc(malloc_usable_size(*result));
        }
        return rc;
    }

    GFXRECON_IMPOSTOR_API void* __wrap_memalign(size_t alignment, size_t size)
    {
        void* ptr = __real_memalign(alignment, size);
        if (ptr != nullptr)
        {
            RecordAlloc(malloc_usable_size(ptr));
        }
        return ptr;
    }

#if !defined(__ANDROID__)
    // Bionic only gained aligned_alloc at API level 28, above the layer's minimum, so it is
    // neither referenced by the Android build nor wrapped there.
    void* __real_aligned_alloc(size_t alignment, size_t size);

    GFXRECON_IMPOSTOR_API void* __wrap_aligned_alloc(size_t alignment, size_t size)
    {
        void* ptr = __real_aligned_alloc(alignment, size);
        if (ptr != nullptr)
        {
            RecordAlloc(malloc_usable_size(ptr));
        }
        return ptr;
    }
#endif
}
