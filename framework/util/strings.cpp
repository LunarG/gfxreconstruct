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

#include "util/strings.h"
#include <algorithm>
#include <sstream>
#include <locale>
#include <codecvt>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(strings)

/// @note A deliberately simple, slow implementation for low-frequency use.
///       Feel free to tune it if it shows up in a profile.
std::string TabRight(const std::string& str)
{
    auto   tabbed = "\t" + str;
    size_t match  = 0;
    while ((match = tabbed.find('\n', match + 1)) != std::string::npos)
    {
        tabbed.replace(match, 1, "\n\t");
    }
    return tabbed;
}

std::vector<std::string> SplitString(const std::string_view compound, const char separator)
{
    std::vector<std::string> values;

    if (!compound.empty())
    {
        // Avoid most of the work if the string doesn't need splitting:
        if (std::count(compound.begin(), compound.end(), separator) < 1)
        {
            values.emplace_back(compound);
            return values;
        }
        else
        {
            // Split string on separator.
            std::istringstream range_input;
            range_input.str(std::string{ compound });

            for (std::string token; std::getline(range_input, token, separator);)
            {
                if (!token.empty())
                {
                    values.push_back(token);
                }
            }
        }
    }
    return values;
}

void RemoveWhitespace(std::string& str)
{
    const auto new_end{ std::remove_if(str.begin(), str.end(), [](const unsigned char c) { return std::isspace(c); }) };
    str.erase(new_end, str.end());
}

std::string_view ViewOfCharArray(const char* array, const size_t capacity)
{
    const char* zero_end = std::find(array, array + capacity, 0);
    return std::string_view(array, zero_end - array);
}

std::string convert_wstring_to_utf8(const std::wstring& wstr)
{
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> conv;

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
    return conv.to_bytes(wstr);
}

GFXRECON_END_NAMESPACE(strings)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
