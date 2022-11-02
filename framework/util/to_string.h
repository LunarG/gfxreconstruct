/*
** Copyright (c) 2021-2022 LunarG, Inc.
** Copyright (c) 2022 Valve Corporation
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
/// @file Facilities for the conversion of types to strings.

#ifndef GFXRECON_TO_STRING_H
#define GFXRECON_TO_STRING_H

#include "util/defines.h"
#include "util/logging.h"

#include <sstream>
#include <string>
#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

enum ToStringFlagBits
{
    kToString_Unformatted = 0,
    kToString_Formatted   = 1,
    kToString_Default     = kToString_Unformatted,
};

typedef uint32_t ToStringFlags;

/// @brief  Template ToString to handle easy cases with primitive types like
/// bool, char, and the many ints and floats.
/// @note The hundreds of manual and generated ToString() functions are only
/// template specializations to logically tie them to this template which can be
/// used to avoid having one concrete function per primitive type, a decision
/// with its own trade-offs such as not being able to breakpoint only on a
/// particular primitive type, and requiring the function to be inline in a
/// header.
/// @deprecated This function can be removed once all the ToString functions
/// in the system are no longer template specializations.
template <typename T>
inline std::string
ToString(const T& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = 0, uint32_t tabSize = 4)
{
    GFXRECON_UNREFERENCED_PARAMETER(toStringFlags);
    GFXRECON_UNREFERENCED_PARAMETER(tabCount);
    GFXRECON_UNREFERENCED_PARAMETER(tabSize);
    GFXRECON_LOG_ERROR("ToString() base template called for type: %s with value: %s. This should never be called.",
                       typeid(obj).name(),
                       std::to_string(obj).c_str());
    return std::to_string(obj);
}

/// @deprecated This seems to be outputting a string containing a zero for any
/// uint32_t passed-in.
/// Hopefully the name resolution rules / priorities around function templates
/// meant this was never actually called.
template <typename T>
inline std::string ToString(uint32_t      apiFlags,
                            ToStringFlags toStringFlags = kToString_Default,
                            uint32_t      tabCount      = 0,
                            uint32_t      tabSize       = 4)
{
    GFXRECON_LOG_ERROR(
        "ToString(uint32_t apiFlags) template called for type: %s with value: %s. This should never be called.",
        typeid(T).name(),
        std::to_string(apiFlags).c_str());
    GFXRECON_UNREFERENCED_PARAMETER(apiFlags);
    GFXRECON_UNREFERENCED_PARAMETER(toStringFlags);
    GFXRECON_UNREFERENCED_PARAMETER(tabCount);
    GFXRECON_UNREFERENCED_PARAMETER(tabSize);
    return "0";
}

inline std::string
ToString(const char& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = 0, uint32_t tabSize = 4)
{
    GFXRECON_UNREFERENCED_PARAMETER(toStringFlags);
    GFXRECON_UNREFERENCED_PARAMETER(tabCount);
    GFXRECON_UNREFERENCED_PARAMETER(tabSize);
    return std::to_string(obj);
}

inline std::string
ToString(const bool& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = 0, uint32_t tabSize = 4)
{
    GFXRECON_UNREFERENCED_PARAMETER(toStringFlags);
    GFXRECON_UNREFERENCED_PARAMETER(tabCount);
    GFXRECON_UNREFERENCED_PARAMETER(tabSize);
    return std::to_string(obj);
}

inline std::string ToString(const int8_t& obj,
                            ToStringFlags toStringFlags = kToString_Default,
                            uint32_t      tabCount      = 0,
                            uint32_t      tabSize       = 4)
{
    GFXRECON_UNREFERENCED_PARAMETER(toStringFlags);
    GFXRECON_UNREFERENCED_PARAMETER(tabCount);
    GFXRECON_UNREFERENCED_PARAMETER(tabSize);
    return std::to_string(obj);
}

inline std::string ToString(const int16_t& obj,
                            ToStringFlags  toStringFlags = kToString_Default,
                            uint32_t       tabCount      = 0,
                            uint32_t       tabSize       = 4)
{
    GFXRECON_UNREFERENCED_PARAMETER(toStringFlags);
    GFXRECON_UNREFERENCED_PARAMETER(tabCount);
    GFXRECON_UNREFERENCED_PARAMETER(tabSize);
    return std::to_string(obj);
}

inline std::string ToString(const int32_t& obj,
                            ToStringFlags  toStringFlags = kToString_Default,
                            uint32_t       tabCount      = 0,
                            uint32_t       tabSize       = 4)
{
    GFXRECON_UNREFERENCED_PARAMETER(toStringFlags);
    GFXRECON_UNREFERENCED_PARAMETER(tabCount);
    GFXRECON_UNREFERENCED_PARAMETER(tabSize);
    return std::to_string(obj);
}

inline std::string ToString(const int64_t& obj,
                            ToStringFlags  toStringFlags = kToString_Default,
                            uint32_t       tabCount      = 0,
                            uint32_t       tabSize       = 4)
{
    GFXRECON_UNREFERENCED_PARAMETER(toStringFlags);
    GFXRECON_UNREFERENCED_PARAMETER(tabCount);
    GFXRECON_UNREFERENCED_PARAMETER(tabSize);
    return std::to_string(obj);
}

inline std::string ToString(const uint8_t& obj,
                            ToStringFlags  toStringFlags = kToString_Default,
                            uint32_t       tabCount      = 0,
                            uint32_t       tabSize       = 4)
{
    GFXRECON_UNREFERENCED_PARAMETER(toStringFlags);
    GFXRECON_UNREFERENCED_PARAMETER(tabCount);
    GFXRECON_UNREFERENCED_PARAMETER(tabSize);
    return std::to_string(obj);
}

inline std::string ToString(const uint16_t& obj,
                            ToStringFlags   toStringFlags = kToString_Default,
                            uint32_t        tabCount      = 0,
                            uint32_t        tabSize       = 4)
{
    GFXRECON_UNREFERENCED_PARAMETER(toStringFlags);
    GFXRECON_UNREFERENCED_PARAMETER(tabCount);
    GFXRECON_UNREFERENCED_PARAMETER(tabSize);
    return std::to_string(obj);
}

inline std::string ToString(const uint32_t& obj,
                            ToStringFlags   toStringFlags = kToString_Default,
                            uint32_t        tabCount      = 0,
                            uint32_t        tabSize       = 4)
{
    GFXRECON_UNREFERENCED_PARAMETER(toStringFlags);
    GFXRECON_UNREFERENCED_PARAMETER(tabCount);
    GFXRECON_UNREFERENCED_PARAMETER(tabSize);
    return std::to_string(obj);
}

inline std::string ToString(const uint64_t& obj,
                            ToStringFlags   toStringFlags = kToString_Default,
                            uint32_t        tabCount      = 0,
                            uint32_t        tabSize       = 4)
{
    GFXRECON_UNREFERENCED_PARAMETER(toStringFlags);
    GFXRECON_UNREFERENCED_PARAMETER(tabCount);
    GFXRECON_UNREFERENCED_PARAMETER(tabSize);
    return std::to_string(obj);
}

inline std::string
ToString(const float& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = 0, uint32_t tabSize = 4)
{
    GFXRECON_UNREFERENCED_PARAMETER(toStringFlags);
    GFXRECON_UNREFERENCED_PARAMETER(tabCount);
    GFXRECON_UNREFERENCED_PARAMETER(tabSize);
    return std::to_string(obj);
}

inline std::string ToString(const double& obj,
                            ToStringFlags toStringFlags = kToString_Default,
                            uint32_t      tabCount      = 0,
                            uint32_t      tabSize       = 4)
{
    GFXRECON_UNREFERENCED_PARAMETER(toStringFlags);
    GFXRECON_UNREFERENCED_PARAMETER(tabCount);
    GFXRECON_UNREFERENCED_PARAMETER(tabSize);
    return std::to_string(obj);
}

template <typename PtrType>
inline std::string PtrToString(PtrType* ptr)
{
    std::stringstream strStrm;
    strStrm << "0x" << std::hex << reinterpret_cast<uintptr_t>(ptr);
    return strStrm.str();
}

template <typename PtrType>
inline std::string PtrToString(PtrType ptr)
{
    std::stringstream strStrm;
    strStrm << "0x" << std::hex << ptr;
    return strStrm.str();
}

inline std::string GetNewlineString(ToStringFlags toStringFlags)
{
    return (toStringFlags & kToString_Formatted) ? std::string("\n") : std::string();
}

inline std::string GetWhitespaceString(ToStringFlags toStringFlags, uint32_t count = 1)
{
    return (toStringFlags & kToString_Formatted) ? std::string((size_t)count, ' ') : std::string();
}

inline std::string GetTabString(ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize = 4)
{
    return GetWhitespaceString(toStringFlags, tabCount * tabSize);
}

template <typename ToStringFunctionType>
inline std::string
ObjectToString(ToStringFlags toStringFlags, uint32_t& tabCount, uint32_t tabSize, ToStringFunctionType toStringFunction)
{
    std::stringstream strStrm;
    const auto        nl = GetNewlineString(toStringFlags);
    strStrm << '{';
    strStrm << nl;
    ++tabCount;
    toStringFunction(strStrm);
    --tabCount;
    strStrm << nl;
    strStrm << GetTabString(toStringFlags, tabCount, tabSize);
    strStrm << '}';
    return strStrm.str();
}

inline void FieldToString(std::stringstream& strStrm,
                          bool               firstField,
                          const std::string& fieldName,
                          ToStringFlags      toStringFlags,
                          uint32_t           tabCount,
                          uint32_t           tabSize,
                          const std::string& fieldString)
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

template <typename ObjectType, typename ValidateArrayFunctionType, typename ToStringFunctionType>
inline std::string ArrayToString(size_t                    count,
                                 const ObjectType*         pObjs,
                                 ToStringFlags             toStringFlags,
                                 uint32_t                  tabCount,
                                 uint32_t                  tabSize,
                                 ValidateArrayFunctionType validateArrayFunction,
                                 ToStringFunctionType      toStringFunction)
{
    if (!(count && validateArrayFunction()))
    {
        return "null";
    }

    std::stringstream strStrm;
    strStrm << '[';
    strStrm << GetNewlineString(toStringFlags);
    for (uint32_t i = 0; i < count; ++i)
    {
        if (i)
        {
            strStrm << ',' << GetNewlineString(toStringFlags);
        }
        strStrm << GetTabString(toStringFlags, tabCount + 1, tabSize) << toStringFunction(i);
    }
    strStrm << GetNewlineString(toStringFlags) << GetTabString(toStringFlags, tabCount, tabSize);
    strStrm << ']';
    return strStrm.str();
}

template <typename T>
inline std::string ArrayToString(size_t        count,
                                 const T*      pObjs,
                                 ToStringFlags toStringFlags = kToString_Default,
                                 uint32_t      tabCount      = 0,
                                 uint32_t      tabSize       = 4)
{
    return ArrayToString(
        count,
        pObjs,
        toStringFlags,
        tabCount,
        tabSize,
        [&]() { return pObjs != nullptr; },
        [&](uint32_t i) { return ToString(pObjs[i], toStringFlags, tabCount + 1, tabSize); });
}

template <typename T>
inline std::string Array2DToString(size_t          m,
                                   size_t          n,
                                   const T* const* pObjs,
                                   ToStringFlags   toStringFlags = kToString_Default,
                                   uint32_t        tabCount      = 0,
                                   uint32_t        tabSize       = 4)
{
    std::stringstream strStrm;
    for (size_t i = 0; i < m; ++i)
    {
        strStrm << ArrayToString(n, pObjs[i], toStringFlags, tabCount, tabSize);
    }
    return strStrm.str();
}

/// Replace special characters with their escaped versions.
/// @note forward slash / solidus is not escaped as that is optional and leads
/// to ugliness such as dates with escaped solidus separators.
/// @note Slashes for explicit unicode code points will be erroneously escaped
/// but Vulkan-derived C-strings should not have those embedded.
inline void JSONEscape(const char c, std::string& out)
{
    char out_c = c;
    switch (c)
    {
        case '\"':
        case '\\':
            out.push_back('\\');
            break;
        case '\b':
            out.push_back('\\');
            out_c = 'b';
            break;
        case '\f':
            out.push_back('\\');
            out_c = 'f';
            break;
        case '\n':
            out.push_back('\\');
            out_c = 'n';
            break;
        case '\r':
            out.push_back('\\');
            out_c = 'r';
            break;
        case '\t':
            out.push_back('\\');
            out_c = 't';
            break;
    }
    out.push_back(out_c);
}

/// Replace special characters in strings with their escaped versions.
/// <https://www.json.org/json-en.html>
inline void JSONEscape(const char* cstr, std::string& escaped)
{
    if (cstr)
    {
        while (char c = *cstr++)
        {
            JSONEscape(c, escaped);
        }
    }
}

inline std::string JSONEscape(const std::string& str)
{
    std::string escaped;
    for (const auto c : str)
    {
        JSONEscape(c, escaped);
    }
    return escaped;
}

/// @brief  A single point for the conversion of C-style strings to the JSON
/// string type or null.
inline std::string CStrToString(const char* const cstr)
{
    std::string str;
    if (cstr != nullptr)
    {
        str.push_back('"');
        JSONEscape(cstr, str);
        str.push_back('"');
    }
    else
    {
        str.assign("null");
    }
    return str;
}

/// @brief  Convert an array of c-style string pointers into a JSON array of
/// JSON strings or nulls.
inline std::string CStrArrayToString(size_t             count,
                                     const char* const* ppStrs,
                                     ToStringFlags      toStringFlags = kToString_Default,
                                     uint32_t           tabCount      = 0,
                                     uint32_t           tabSize       = 4)
{
    return ArrayToString(
        count,
        ppStrs,
        toStringFlags,
        tabCount,
        tabSize,
        [&]() { return ppStrs != nullptr; },
        [&](uint32_t i) { return CStrToString(ppStrs[i]); });
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_TO_STRING_H
