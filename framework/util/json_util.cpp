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
#include "util/to_string.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

void FieldToJson(nlohmann::ordered_json&  jdata,
                 const float              data[4],
                 const util::JsonOptions& options)
{
    FieldToJson(jdata, data, 4, options);
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

void HandleToJson(nlohmann::ordered_json& jdata,
                  const format::HandleId* data,
                  size_t                  num_elements,
                  const JsonOptions&      options)
{
    if (data)
    {
        for (size_t i = 0; i < num_elements; ++i)
        {
            HandleToJson(jdata[i], data[i], options);
        }
    }
    else
    {
        jdata = nullptr;
    }
}

// The following look trivial but there is some work in a header-only
// library hidden in the assignments so we can give the inlining of that code a
// natural place to stop right here.

void Bool32ToJson(nlohmann::ordered_json& jdata, const uint32_t data, const util::JsonOptions& options)
{
    jdata = static_cast<bool>(data);
}

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

void FieldToJson(nlohmann::ordered_json& jdata, float data, const JsonOptions& options)
{
    if (std::isnan(data))
    {
        GFXRECON_LOG_WARNING_ONCE("Converting a NAN to zero.");
        data = 0.0f;
    }
    else if (std::isinf(data))
    {
        GFXRECON_LOG_WARNING_ONCE("Converting an infinity to max or min.");
        if (data < 0)
        {
            data = std::numeric_limits<float>::min();
        }
        else
        {
            data = std::numeric_limits<float>::max();
        }
    }
    // Normal and denormal/subnormal numbers pass through unchanged and unremarked.

    jdata = data;
}

void FieldToJson(nlohmann::ordered_json& jdata, double data, const util::JsonOptions& options)
{
    jdata = data;
}

void FieldToJson(nlohmann::ordered_json& jdata, const std::string_view data, const util::JsonOptions& options)
{
    jdata = data;
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)