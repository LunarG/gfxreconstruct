/*
** Copyright (c) 2022 Advanced Micro Devices, Inc.
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

#include "custom_common_to_string.h"

#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// clang-format off

template <>
std::string ToString<SECURITY_ATTRIBUTES>(const SECURITY_ATTRIBUTES& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::ostringstream& strStrm)
        {
            FieldToString(strStrm, true, "nLength", toStringFlags, tabCount, tabSize, ToString(obj.nLength, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "lpSecurityDescriptor", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.lpSecurityDescriptor)));
            FieldToString(strStrm, false, "bInheritHandle", toStringFlags, tabCount, tabSize, ToString(obj.bInheritHandle, toStringFlags, tabCount, tabSize));
        }
    );
}

// clang-format on

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
