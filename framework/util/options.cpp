/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
** Copyright (c) 2019-2021 Advanced Micro Devices, Inc. All rights reserved.
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

#include "options.h"
#include "util/platform.h"
#include "util/logging.h"

#include <sstream>
#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

std::vector<FrameRange> GetFrameRanges(const std::string& args)
{
    std::vector<FrameRange> ranges;

    std::istringstream value_input;
    value_input.str(args);

    for (std::string range; std::getline(value_input, range, ',');)
    {
        if (range.empty() || (std::count(range.begin(), range.end(), '-') > 1))
        {
            GFXRECON_LOG_WARNING("Ignoring invalid screenshot frame range \"%s\"", range.c_str());
            continue;
        }

        // Remove whitespace.
        range.erase(std::remove_if(range.begin(), range.end(), ::isspace), range.end());

        // Split string on '-' delimiter.
        bool                     invalid = false;
        std::vector<std::string> values;
        std::istringstream       range_input;
        range_input.str(range);

        for (std::string value; std::getline(range_input, value, '-');)
        {
            if (value.empty())
            {
                break;
            }

            // Check that the value string only contains numbers.
            size_t count = std::count_if(value.begin(), value.end(), ::isdigit);
            if (count == value.length())
            {
                values.push_back(value);
            }
            else
            {
                GFXRECON_LOG_WARNING(
                    "Ignoring invalid screenshot frame range \"%s\", which contains non-numeric values", range.c_str());
                invalid = true;
                break;
            }
        }

        if (!invalid)
        {
            FrameRange screenshot_range;

            if (values.size() == 1)
            {
                if (std::count(range.begin(), range.end(), '-') == 0)
                {
                    screenshot_range.first = std::stoi(values[0]);
                    screenshot_range.last  = screenshot_range.first;
                }
                else
                {
                    GFXRECON_LOG_WARNING("Ignoring invalid screenshot frame range \"%s\"", range.c_str());
                    continue;
                }
            }
            else if (values.size() == 2)
            {
                screenshot_range.first = std::stoi(values[0]);
                screenshot_range.last  = std::stoi(values[1]);
                if (screenshot_range.first > screenshot_range.last)
                {
                    GFXRECON_LOG_WARNING("Ignoring invalid screenshot frame range \"%s\", where first frame is "
                                         "greater than last frame",
                                         range.c_str());
                    continue;
                }
            }
            else
            {
                GFXRECON_LOG_WARNING("Ignoring invalid screenshot frame range \"%s\"", range.c_str());
                continue;
            }

            // Check for invalid start frame of 0.
            if (screenshot_range.first == 0)
            {
                GFXRECON_LOG_WARNING("Ignoring invalid screenshot frame range \"%s\", with first frame equal to zero",
                                     range.c_str());
                continue;
            }

            uint32_t next_allowed = 0;

            // Check that first frame is outside the bounds of the previous range.
            if (!ranges.empty())
            {
                // The number of the frame after the last frame of the last range.
                next_allowed = ranges.back().last + 1;
            }

            if (screenshot_range.first >= next_allowed)
            {
                ranges.emplace_back(std::move(screenshot_range));
            }
            else
            {
                const auto& back = ranges.back();
                GFXRECON_LOG_WARNING("Ignoring invalid screenshot frame range \"%s\", "
                                     "where start frame precedes the end of the previous range \"%u-%u\"",
                                     range.c_str(),
                                     back.first,
                                     back.last);
            }
        }
    }

    return ranges;
}

bool ParseBoolString(const std::string& value_string, bool default_value)
{
    bool result = default_value;

    // Checking for "false" or zero, or "true" or a non-zero number.
    if ((gfxrecon::util::platform::StringCompareNoCase("true", value_string.c_str()) == 0) ||
        (atoi(value_string.c_str()) != 0))
    {
        result = true;
    }
    else if ((gfxrecon::util::platform::StringCompareNoCase("false", value_string.c_str()) == 0) ||
             (value_string == "0"))
    {
        result = false;
    }
    else
    {
        if (!value_string.empty())
        {
            GFXRECON_LOG_WARNING("Settings Loader: Ignoring unrecognized Boolean option value \"%s\"",
                                 value_string.c_str());
        }
    }

    return result;
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
