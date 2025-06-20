/*
** Copyright (c) 2021-2025 LunarG, Inc.
** Copyright (c) 2022-2023 Valve Corporation
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
/// @file Facilities for the conversion of types to strings, oriented  towards
/// JSON Lines output.

#ifndef GFXRECON_TO_STRING_H
#define GFXRECON_TO_STRING_H

#include "format/format.h"
#include "util/defines.h"

#include <iomanip>
#include <sstream>
#include <string>
#include <utility>
#include <cmath>
#include <functional>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

enum ToStringFlagBits
{
    kToString_Unformatted = 0,
    kToString_Formatted   = 1,
    kToString_Default     = kToString_Unformatted,
};

constexpr uint32_t kToStringDefaultTabCount = 0;
constexpr uint32_t kToStringDefaultTabSize  = 4;

typedef uint32_t ToStringFlags;

/// Convert a value to a string in hexadecimal form.
template <typename T>
std::string to_hex_variable_width(T value)
{
    std::ostringstream stream;
    stream << "0x" << std::hex << value;
    return stream.str();
}

/// Convert a value to a string in hexadecimal form, filling with leading zeros
/// to make a fixed-width for a given parameter type.
template <typename T>
std::string to_hex_fixed_width(T value)
{
    std::ostringstream stream;
    stream << "0x" << std::setfill('0') << std::setw(sizeof(T) * 2) << std::hex << value;
    return stream.str();
}

/// Convert a value to a string in binary form, filling with leading zeros to
/// make a fixed-width. Follows C++ 14's format for literal binary constants.
std::string to_binary_fixed_width(const uint8_t value);
std::string to_binary_fixed_width(const uint16_t value);
std::string to_binary_fixed_width(const uint32_t value);
std::string to_binary_fixed_width(const uint64_t value);

std::string uuid_to_string(uint32_t size, const uint8_t* uuid);

/// @brief Convert an annotation to its string representation.
std::string AnnotationTypeToString(const format::AnnotationType& type);

/// @deprecated Use the nlohmann JSON library instead.
/// @brief  A template ToString to take care of simple POD cases like the many
/// types of integers.
/// It contains the three parameters that are unused for unstructured types like
/// scalars and strings so that calling code doesn't have to care whether it is
/// dealing with a simple type or a multi-line struct or array which tabs itself
/// out.
template <typename T>
inline std::string ToString(const T&      obj,
                            ToStringFlags toStringFlags = kToString_Default,
                            uint32_t      tabCount      = kToStringDefaultTabCount,
                            uint32_t      tabSize       = kToStringDefaultTabSize)
{
    GFXRECON_UNREFERENCED_PARAMETER(toStringFlags);
    GFXRECON_UNREFERENCED_PARAMETER(tabCount);
    GFXRECON_UNREFERENCED_PARAMETER(tabSize);
    return std::to_string(obj);
}

/// @deprecated Use the nlohmann JSON library instead.
/// @brief A template that exists only to allow the ToStrings for 32 bit sets of
/// flags to be template specializations.
/// It is never called and its return value of "0" is a meaningless placeholder
/// to allow compilation to succeed.
/// @note There seems to be no reason for those ToStrings to be template
/// function specializations since a caller has to explicitly spell out a type
/// to call one of them and there is no function resolution based on argument
/// types going on.
/// @todo This may not be necessary: try deleting it.
template <typename T>
inline std::string ToString(uint32_t      apiFlags,
                            ToStringFlags toStringFlags = kToString_Default,
                            uint32_t      tabCount      = kToStringDefaultTabCount,
                            uint32_t      tabSize       = kToStringDefaultTabSize)
{
    GFXRECON_UNREFERENCED_PARAMETER(toStringFlags);
    GFXRECON_UNREFERENCED_PARAMETER(tabCount);
    GFXRECON_UNREFERENCED_PARAMETER(tabSize);
    return std::to_string(apiFlags);
}

template <typename HandleIdType>
inline std::string HandleIdToString(HandleIdType handleId)
{
    std::ostringstream strStrm;
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

template <>
inline std::string HandleIdToString(format::HandleId handleId)
{
    return std::to_string(handleId);
}

#if defined(WIN32)
inline std::string WCharArrayToString(const wchar_t* pStr)
{
    int required_size = 0;
    if (pStr != nullptr)
    {
        required_size = WideCharToMultiByte(CP_UTF8, 0, pStr, -1, nullptr, 0, nullptr, nullptr);

        // Don't include null-terminator in output.
        --required_size;
    }

    if (required_size > 0)
    {
        std::string result_str;
        result_str.resize(required_size);
        required_size = WideCharToMultiByte(
            CP_UTF8, 0, pStr, -1, result_str.data(), static_cast<int>(result_str.size()), nullptr, nullptr);
        return result_str;
    }
    else
    {
        return "";
    }
}
#endif

template <typename BitmaskType, typename FlagsType, typename ToString>
inline std::string BitmaskToString(FlagsType flags, ToString&& to_string)
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
            str.append(to_string(static_cast<BitmaskType>(FlagsType(1) << index)));
        }
        ++index;
        flags >>= 1;
    }
    if (str.empty())
    {
        str.append(to_string(static_cast<BitmaskType>(0)));
    }
    return str;
}

template <typename BitmaskType, typename FlagsType>
inline std::string BitmaskToString(FlagsType flags)
{
    auto to_string = [](const BitmaskType& bit) { return ToString(bit); };
    return BitmaskToString<BitmaskType>(flags, to_string);
}

template <typename PtrType>
inline std::string PtrToString(PtrType* ptr)
{
    return to_hex_variable_width(reinterpret_cast<uintptr_t>(ptr));
}

template <typename PtrType>
inline std::string PtrToString(PtrType ptr)
{
    return to_hex_variable_width(ptr);
}

/// @deprecated Use the nlohmann JSON library instead.
inline std::string GetNewlineString(ToStringFlags toStringFlags)
{
    return (toStringFlags & kToString_Formatted) ? std::string("\n") : std::string();
}

/// @deprecated Use the nlohmann JSON library instead.
inline std::string GetWhitespaceString(ToStringFlags toStringFlags, uint32_t count = 1)
{
    return (toStringFlags & kToString_Formatted) ? std::string((size_t)count, ' ') : std::string();
}

/// @deprecated Use the nlohmann JSON library instead.
inline std::string
GetTabString(ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize = kToStringDefaultTabSize)
{
    return GetWhitespaceString(toStringFlags, tabCount * tabSize);
}

/// @brief Make a copy of the input string with double quotes at start and end.
inline std::string Quote(const std::string& str)
{
    std::string quoted{ '"' };
    quoted += str;
    quoted += '"';
    return quoted;
}

/// @deprecated Use the nlohmann JSON library instead.
/// @brief Create the opening and closing braces of a JSON object: calling a function
/// to fill out the internal fields of the object.
/// By convention the functions which convert structs will be called ToString and
/// will call FieldToString() to format each field and another ToString,
/// ArrayToString(), etc. to form the nested structure or the immediate value of
/// the field.
template <typename ToStringFunctionType>
inline std::string
ObjectToString(ToStringFlags toStringFlags, uint32_t& tabCount, uint32_t tabSize, ToStringFunctionType toStringFunction)
{
    std::ostringstream strStrm;
    const auto         nl = GetNewlineString(toStringFlags);
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

/// @deprecated Use the nlohmann JSON library instead.
/// Part of a system for formatting fields of structs and arguments of functions
/// as JSON text strings.
/// @deprecated Use the nlohmann JSON library instead.
void FieldToString(std::ostringstream& strStrm,
                   bool                firstField,
                   const char*         fieldName,
                   ToStringFlags       toStringFlags,
                   uint32_t            tabCount,
                   uint32_t            tabSize,
                   const std::string&  fieldString);

/// @deprecated Use the nlohmann JSON library instead.
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

    std::ostringstream strStrm;
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

/// @deprecated Use the nlohmann JSON library instead.
template <typename T>
inline std::string ArrayToString(size_t        count,
                                 const T*      pObjs,
                                 ToStringFlags toStringFlags = kToString_Default,
                                 uint32_t      tabCount      = kToStringDefaultTabCount,
                                 uint32_t      tabSize       = kToStringDefaultTabSize)
{
    return ArrayToString(
        count,
        pObjs,
        toStringFlags,
        tabCount,
        tabSize,
        [&]() { return pObjs != nullptr; },
        [&](size_t i) { return ToString(pObjs[i], toStringFlags, tabCount + 1, tabSize); });
}

/// @deprecated Use the nlohmann JSON library instead.
template <typename EnumType>
inline std::string EnumArrayToString(size_t              count,
                                     const EnumType*     pObjs,
                                     util::ToStringFlags toStringFlags = util::kToString_Default,
                                     uint32_t            tabCount      = kToStringDefaultTabCount,
                                     uint32_t            tabSize       = kToStringDefaultTabSize)
{
    using namespace util;
    return ArrayToString(
        count,
        pObjs,
        toStringFlags,
        tabCount,
        tabSize,
        [&]() { return pObjs != nullptr; },
        [&](size_t i) { return Quote(ToString(pObjs[i])); });
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_TO_STRING_H
