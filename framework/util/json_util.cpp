/*
** Copyright (c) 2022-2023 LunarG, Inc.
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

#include "util/json_util.h"
#include "json_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

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

void HandleToJson(nlohmann::ordered_json& jdata, const format::HandleId handle, const JsonOptions& options)
{
    if (options.hex_handles)
    {
        // A JSON string
        jdata = util::to_hex_variable_width(handle);
    }
    else
    {
        // A JSON number
        jdata = handle;
    }
}

// The following look trivial but there is a lot of work in a header-only
// library hidden in the assignments so we can give the inlining of that code a
// natural place to stop right here.

void FieldToJson(nlohmann::ordered_json& jdata, short data, const JsonOptions& options)
{
    jdata = data;
}

void FieldToJson(nlohmann::ordered_json& jdata, int data, const JsonOptions& options)
{
    jdata = data;
}

void FieldToJson(nlohmann::ordered_json& jdata, long data, const JsonOptions& options)
{
    jdata = data;
}

void FieldToJson(nlohmann::ordered_json& jdata, long long data, const JsonOptions& options)
{
    jdata = data;
}

void FieldToJson(nlohmann::ordered_json& jdata, unsigned short data, const JsonOptions& options)
{
    jdata = data;
}

void FieldToJson(nlohmann::ordered_json& jdata, unsigned int data, const JsonOptions& options)
{
    jdata = data;
}

void FieldToJson(nlohmann::ordered_json& jdata, unsigned long data, const JsonOptions& options)
{
    jdata = data;
}

void FieldToJson(nlohmann::ordered_json& jdata, unsigned long long data, const JsonOptions& options)
{
    jdata = data;
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)