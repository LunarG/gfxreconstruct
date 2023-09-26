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

#ifndef GFXRECON_UTIL_OPTIONS_H
#define GFXRECON_UTIL_OPTIONS_H

#include "util/defines.h"

#include <string>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

struct UintRange
{
    uint32_t first{ 0 };
    uint32_t last{ 0 };
};

std::vector<UintRange> GetUintRanges(const char* args, const char* option_name);

enum class ScreenshotFormat : uint32_t
{
    kBmp = 0,
    kPng = 1,
};

enum class SwapchainOption : uint32_t
{
    kVirtual   = 0,
    kCaptured  = 1,
    kOffscreen = 2,
};

//----------------------------------------------------------------------------
/// Read a boolean value out of a string
/// \param  value_string Input string
/// \param  default_value Default value in case it couldn't be read
/// \return True or false interpretation of input string
//----------------------------------------------------------------------------
bool ParseBoolString(const std::string& value_string, bool default_value);

uint32_t ParseUintString(const std::string& value_string, uint32_t default_value);

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_OPTIONS_H
