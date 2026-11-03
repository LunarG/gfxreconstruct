/*
** Copyright (c) 2026 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to
** deal in the Software without restriction, including without limitation the
** rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
** sell copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
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

// A string literal as a non-type template argument. C++20 admits a class object as a template argument when the
// class is structural, [temp.param]/7: every base and non-static data member public, non-mutable, and itself of a
// structural type. The characters are copied into a public array, which is structural, so Field<"pNext", ...> names
// a distinct type for each spelling and two equal spellings name the same type.

#ifndef GFXRECON_UTIL_FIXED_STRING_H
#define GFXRECON_UTIL_FIXED_STRING_H

#include "util/defines.h"

#include <cstddef>
#include <string_view>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

template <size_t N>
struct FixedString
{
    char data[N];

    constexpr FixedString(const char (&s)[N])
    {
        for (size_t i = 0; i < N; ++i)
        {
            data[i] = s[i];
        }
    }

    // The characters without the terminator.
    constexpr std::string_view view() const { return std::string_view(data, N - 1); }
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_FIXED_STRING_H
