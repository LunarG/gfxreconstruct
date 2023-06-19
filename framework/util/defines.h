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

#include <cassert>
#include <cstdint>
#include <limits>

#ifndef GFXRECON_UTIL_DEFINES_H
#define GFXRECON_UTIL_DEFINES_H

#if defined(_WIN64) || defined(__LP64__)
#define GFXRECON_ARCH64
#endif

#define GFXRECON_BEGIN_NAMESPACE(x) \
    namespace x                     \
    {
#define GFXRECON_END_NAMESPACE(x) }

#define GFXRECON_UNREFERENCED_PARAMETER(x) ((void)x)

// Use two macros for the x is a macro case, to ensure macro expansion is applied to x prior to string conversion.
#define GFXRECON_STR_EXPAND(x) #x
#define GFXRECON_STR(x) GFXRECON_STR_EXPAND(x)

#define GFXRECON_MAKE_FOURCC(c0, c1, c2, c3)                                                            \
    (static_cast<uint32_t>(c0) | (static_cast<uint32_t>(c1) << 8) | (static_cast<uint32_t>(c2) << 16) | \
     (static_cast<uint32_t>(c3) << 24))

// Determine if a type conversion would result in a loss of data.  Intended to check uint64_t to size_t conversions.
#define GFXRECON_CHECK_CONVERSION_DATA_LOSS(DstType, Value) assert(std::numeric_limits<DstType>::max() >= Value);

// Safely release a dynamic allocation.
#define GFXRECON_SAFE_DELETE(p)    \
    {                     \
        if (p != nullptr) \
        {                 \
            delete p;     \
            p = nullptr;  \
        }                 \
    }

// Usefull to avoid sign extension when converting a 32bit pointer to uint64_t
template <typename T>
static constexpr uint64_t GFXRECON_PTR_TO_UINT64(T ptr)
{
    return static_cast<uint64_t>(reinterpret_cast<uintptr_t>(ptr));
}

#endif // GFXRECON_UTIL_DEFINES_H
