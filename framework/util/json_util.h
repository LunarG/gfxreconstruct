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

/// @file API-agnostic options and helpers for outputting JSON used by all
/// the JSON-generating components such as the Consumers in.

#ifndef GFXRECON_UTIL_JSON_UTIL_H
#define GFXRECON_UTIL_JSON_UTIL_H

#include "util/defines.h"
#include "format/format.h"
#include "nlohmann/json.hpp"

#include <sstream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

static constexpr int kJsonIndentWidth = 2;

/// This selects between outputting an array of objects (JSON) or individual
/// top-level objects separated by newlines (JSONL). A top-level component
/// like Convert's main() needs to look at this but the FieldToJson functions
/// ignore it. They build a nlohmann tree in memory.
enum class JsonFormat : uint8_t
{
    JSON,
    JSONL
};

/// Parameters potentially required in converting our datastructures to JSON.
struct JsonOptions
{
    // Fields ordered large to small for alignment/packing.
    std::string root_dir;
    std::string data_sub_dir;
    JsonFormat  format        = JsonFormat::JSON;
    bool        dump_binaries = false;
    bool        expand_flags  = false;
    bool        hex_handles   = false;
};

void FieldToJson(nlohmann::ordered_json& jdata, short data, const JsonOptions& options = JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, int data, const JsonOptions& options = JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, long data, const JsonOptions& options = JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, long long data, const JsonOptions& options = JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, unsigned short data, const JsonOptions& options = JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, unsigned int data, const JsonOptions& options = JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, unsigned long data, const JsonOptions& options = JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, unsigned long long data, const JsonOptions& options = JsonOptions());
/// Convert floats to JSON, logging information loss when floats with no JSON
/// number type representation are adjusted. The JSON library turns these numbers
/// into JSON nulls otherwise.
void FieldToJson(nlohmann::ordered_json& jdata, float data, const util::JsonOptions& options = util::JsonOptions());
/// @note This is unused dead code currently (try placing a breakpoint on it).
void FieldToJson(nlohmann::ordered_json& jdata, double data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json&  jdata,
                 const std::string&       data,
                 const util::JsonOptions& options = util::JsonOptions());

/// @brief Convert the integer representation of a handle in capture files into
/// either a JSON number or a JSON string with the number represented in
/// hexadecimal.
void HandleToJson(nlohmann::ordered_json& jdata, const format::HandleId handle, const JsonOptions& options);

/// @brief  Convert a bool represented as a 32 bit unsigned number like a
/// VkBool32 to true or false.
void Bool32ToJson(nlohmann::ordered_json&  jdata,
                  const uint32_t           data,
                  const util::JsonOptions& options = util::JsonOptions());

template <typename T>
void FieldToJsonAsHex(nlohmann::ordered_json&  jdata,
                      const T                  data,
                      const util::JsonOptions& options = util::JsonOptions())
{
    jdata = to_hex_variable_width(data);
}

template <typename T>
void FieldToJson(nlohmann::ordered_json&  jdata,
                 const T*                 data,
                 size_t                   num_elements,
                 const util::JsonOptions& options = util::JsonOptions())
{
    if (data)
    {
        for (size_t i = 0; i < num_elements; ++i)
        {
            FieldToJson(jdata[i], data[i], options);
        }
    }
    else
    {
        jdata = nullptr;
    }
}

void HandleToJson(nlohmann::ordered_json&  jdata,
                  const format::HandleId*  data,
                  size_t                   num_elements,
                  const util::JsonOptions& options = util::JsonOptions());

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_JSON_UTIL_H
