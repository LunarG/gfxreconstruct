/*
** Copyright (c) 2022 Valve Corporation
** Copyright (c) 2022 LunarG, Inc.
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
/// @file Helper functions for working with strings.
/// @see platform.h for wrappers of C-string functions.

#ifndef GFXRECON_UTIL_STRINGS_H
#define GFXRECON_UTIL_STRINGS_H

#include "util/defines.h"

#include <string>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(strings)

/// @return A string with a tab added at the start of each new line.
/// A string is considered to start at a new line, even an empty string.
std::string TabRight(const std::string& str);

/// @return A vector of strings based on chopping compound everywhere that the
/// separator character is found, adding the pieces to the returned vector from
/// left to right in the original order and discarding the found instances of
/// the separator.
std::vector<std::string> SplitString(const std::string_view compound, const char separator);

/// Removes all whitespace anywhere in the given string, not just trimming it
/// from front and back of the string.
/// @note This will turn a space separated list of numbers into one long number.
void RemoveWhitespace(std::string& str);

/// Create a string from a char array limiting the search for a null terminator
/// to the given capacity as a protection against ill-formed input.
std::string_view ViewOfCharArray(const char* array, const size_t capacity);

/// Convert a std::wstring_view to an UTF-8 encoded std::string
std::string convert_wstring_to_utf8(const std::wstring_view& wstr);

bool StringToU32(const std::string& value_string, uint32_t& value);

GFXRECON_END_NAMESPACE(strings)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_STRINGS_H
