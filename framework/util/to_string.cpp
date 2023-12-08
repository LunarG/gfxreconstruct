/*
** Copyright (c) 2023 LunarG, Inc.
** Copyright (c) 2023 Valve Corporation.
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
#include "util/to_string.h"
#include "util/logging.h"
#include "to_string.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

/// Convert a value to a string in binary form, filling with leading zeros to
/// make a fixed-width for a given parameter type.
/// Concrete versions follow for uint8_t, uint16_t, uint32_t, and uint64_t and
/// only those are exposed outside this compilation unit.
template <typename T>
std::string to_binary_fixed_width(const T value)
{
    const auto  num_bits = sizeof(T) * 8U;
    const T     one{ 1u };
    std::string ret{ "0b" };
    for (auto i = num_bits; i > 0; --i)
    {
        ret += ((value >> (i - 1)) & one) ? '1' : '0';
    }
    return ret;
}

std::string to_binary_fixed_width(const uint8_t value)
{
    return to_binary_fixed_width<uint8_t>(value);
}

std::string to_binary_fixed_width(const uint16_t value)
{
    return to_binary_fixed_width<uint16_t>(value);
}

std::string to_binary_fixed_width(const uint32_t value)
{
    return to_binary_fixed_width<uint32_t>(value);
}

std::string to_binary_fixed_width(const uint64_t value)
{
    return to_binary_fixed_width<uint64_t>(value);
}

std::string uuid_to_string(uint32_t size, const uint8_t* uuid)
{
    std::ostringstream stream;
    stream << std::setfill('0') << std::setw(2) << std::hex;
    for (size_t i = 0; i < size; ++i)
    {
        stream << (uint32_t)uuid[i];
    }
    return stream.str();
}

std::string AnnotationTypeToString(const format::AnnotationType& type)
{
    std::string str;
    switch (type)
    {
        case format::AnnotationType::kUnknown:
            str.assign("kUnknown");
            break;
        case format::AnnotationType::kText:
            str.assign("kText");
            break;
        case format::AnnotationType::kJson:
            str.assign("kJson");
            break;
        case format::AnnotationType::kXml:
            str.assign("kXml");
            break;
        default:
            str.assign("OUT_OF_RANGE_ERROR");
            GFXRECON_LOG_WARNING("format::AnnotationType with out of range value: %lu",
                                 static_cast<long unsigned>(type));
            break;
    }
    return str;
}

void FieldToString(std::ostringstream& strStrm,
                   bool                firstField,
                   const char*         fieldName,
                   ToStringFlags       toStringFlags,
                   uint32_t            tabCount,
                   uint32_t            tabSize,
                   const std::string&  fieldString)
{
    if (!firstField)
    {
        strStrm << ',' << GetNewlineString(toStringFlags);
    }
    strStrm << GetTabString(toStringFlags, tabCount, tabSize);
    strStrm << "\"" << fieldName << "\":";
    strStrm << GetWhitespaceString(toStringFlags);
    strStrm << fieldString;
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
