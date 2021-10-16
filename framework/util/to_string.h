/*
** Copyright (c) 2021 LunarG, Inc.
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

#ifndef GFXRECON_TO_STRING_H
#define GFXRECON_TO_STRING_H

#include "util/defines.h"

#include <codecvt>
#include <locale>
#include <sstream>
#include <string>
#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

enum ToStringFlagBits
{
    kToString_Unformatted = 0,
    kToString_Formatted   = 1,
    kToString_Default     = kToString_Formatted,
};

typedef uint32_t ToStringFlags;

template <typename T>
inline std::string
ToString(const T& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = 0, uint32_t tabSize = 4)
{
    GFXRECON_UNREFERENCED_PARAMETER(toStringFlags);
    GFXRECON_UNREFERENCED_PARAMETER(tabCount);
    GFXRECON_UNREFERENCED_PARAMETER(tabSize);
    return std::to_string(obj);
}

template <typename T>
inline std::string ToString(uint32_t      apiFlags,
                            ToStringFlags toStringFlags = kToString_Default,
                            uint32_t      tabCount      = 0,
                            uint32_t      tabSize       = 4)
{
    GFXRECON_UNREFERENCED_PARAMETER(apiFlags);
    GFXRECON_UNREFERENCED_PARAMETER(toStringFlags);
    GFXRECON_UNREFERENCED_PARAMETER(tabCount);
    GFXRECON_UNREFERENCED_PARAMETER(tabSize);
    return "0";
}

template <typename HandleIdType>
inline std::string HandleIdToString(HandleIdType handleId)
{
    std::stringstream strStrm;
    if (handleId)
    {
        strStrm << "\"0x" << reinterpret_cast<const void*>(handleId) << "\"";
    }
    else
    {
        strStrm << "\"NULL\"";
    }
    return strStrm.str();
}

inline std::string WCharArrayToString(const wchar_t* pStr)
{
    return pStr ? std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t>().to_bytes(pStr) : std::string();
}

template <typename BitmaskType, typename FlagsType>
inline std::string BitmaskToString(FlagsType flags)
{
    std::string str;
    FlagsType   index = 0;
    while (flags)
    {
        if (flags & 1)
        {
            if (!str.empty())
            {
                str.append("|");
            }
            str.append(ToString(static_cast<BitmaskType>(1 << index)));
        }
        ++index;
        flags >>= 1;
    }
    if (str.empty())
    {
        str.append(ToString(static_cast<BitmaskType>(0)));
    }
    return str;
}

template <typename PtrType>
inline std::string PtrToString(PtrType ptr)
{
    std::stringstream strStrm;
    strStrm << "0x" << reinterpret_cast<const void*>(ptr);
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
    strStrm << '{';
    strStrm << GetNewlineString(toStringFlags);
    ++tabCount;
    toStringFunction(strStrm);
    --tabCount;
    strStrm << GetNewlineString(toStringFlags);
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
inline std::string ArrayToString(uint32_t                  count,
                                 const ObjectType*         pObjs,
                                 ToStringFlags             toStringFlags,
                                 uint32_t                  tabCount,
                                 uint32_t                  tabSize,
                                 ValidateArrayFunctionType validateArrayFunction,
                                 ToStringFunctionType      toStringFunction)
{
    std::stringstream strStrm;
    strStrm << '[';
    if (count && validateArrayFunction())
    {
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
    }
    strStrm << ']';
    return strStrm.str();
}

template <typename T>
inline std::string ArrayToString(uint32_t      count,
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

inline std::string CStrArrayToString(uint32_t           count,
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
        [&](uint32_t i) { return ppStrs[i] ? ('"' + std::string(ppStrs[i]) + '"') : "null"; });
}

template <typename EnumType>
inline std::string EnumArrayToString(uint32_t            count,
                                     const EnumType*     pObjs,
                                     util::ToStringFlags toStringFlags = util::kToString_Default,
                                     uint32_t            tabCount      = 0,
                                     uint32_t            tabSize       = 4)
{
    using namespace util;
    return ArrayToString(
        count,
        pObjs,
        toStringFlags,
        tabCount,
        tabSize,
        [&]() { return pObjs != nullptr; },
        [&](uint32_t i) { return '"' + ToString(pObjs[i], toStringFlags, tabCount + 1, tabSize) + '"'; });
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_TO_STRING_H
