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
/// the JSON-generating components such as the Consumers that gfxrecon-convert
/// is based on.

#ifndef GFXRECON_UTIL_JSON_UTIL_H
#define GFXRECON_UTIL_JSON_UTIL_H

#include "util/defines.h"
#include "util/to_string.h"
#include "util/logging.h"
#include "format/format.h"

#ifndef WIN32
#include "format/platform_types.h"
#endif

#include "nlohmann/json.hpp"

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

inline std::string get_json_format(JsonFormat format)
{
    switch (format)
    {
        case gfxrecon::util::JsonFormat::JSONL:
            return "jsonl";
        case gfxrecon::util::JsonFormat::JSON:
            return "json";
        default:
            break;
    }
    GFXRECON_LOG_WARNING("Unrecognized format %d. Defaulting to JSON format.", static_cast<int>(format));
    return "json";
}

inline JsonFormat get_json_format(std::string format)
{
    if (format == "json")
    {
        return gfxrecon::util::JsonFormat::JSON;
    }
    else if (format == "jsonl")
    {
        return gfxrecon::util::JsonFormat::JSONL;
    }
    GFXRECON_LOG_WARNING("Unrecognized format %s. Defaulting to JSON format.", format.c_str());
    return gfxrecon::util::JsonFormat::JSON;
}

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

void FieldToJson(nlohmann::ordered_json& jdata, const short& data, const JsonOptions& options = JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const int& data, const JsonOptions& options = JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const long& data, const JsonOptions& options = JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const long long& data, const JsonOptions& options = JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const unsigned short& data, const JsonOptions& options = JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const unsigned int& data, const JsonOptions& options = JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const unsigned long& data, const JsonOptions& options = JsonOptions());
void FieldToJson(nlohmann::ordered_json&   jdata,
                 const unsigned long long& data,
                 const JsonOptions&        options = JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const std::nullptr_t data, const JsonOptions& options = JsonOptions());
/// Convert floats to JSON, logging information loss when floats with no JSON
/// number type representation are adjusted. The JSON library turns these numbers
/// into JSON nulls otherwise.
void FieldToJson(nlohmann::ordered_json& jdata, float data, const util::JsonOptions& options = util::JsonOptions());
/// @note This is unused dead code currently (try placing a breakpoint on it).
void FieldToJson(nlohmann::ordered_json& jdata, double data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json&  jdata,
                 const std::string_view   data,
                 const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json&  jdata,
                 const std::wstring_view  data,
                 const util::JsonOptions& options = util::JsonOptions());

/// @brief Convert the integer representation of a handle in capture files into
/// either a JSON number or a JSON string with the number represented in
/// hexadecimal.
void HandleToJson(nlohmann::ordered_json& jdata, const format::HandleId handle, const JsonOptions& options);

/// @brief  Convert a bool represented as a 32 bit unsigned number like a
/// VkBool32 to true or false. It should be fine for the signed Windows type
/// BOOL too.
void Bool32ToJson(nlohmann::ordered_json&  jdata,
                  const uint32_t&          data,
                  const util::JsonOptions& options = util::JsonOptions());

/// @brief Convert an integer type to JSON but encoded in hex as a JSON string
/// rather than as a JSON number type. Useful for pointers and memory offsets.
/// @todo Consider replacing FieldToJsonAsHex here and array forms with an
/// AsHex bit/bool in the JsonOptions struct. Same for Bool32ToJson where the
/// scalar uint32_t overload of FieldToJson would check the bit and the array
/// array forms would go away. An IsHandle bit could also replace HandleToJson
/// for format::HandleId but this is starting to get smelly (function effects
/// depending on switching on a parameter value) and should only be done if it
/// simplifies codegen, removing special cases for the classes of types.
template <typename T>
void FieldToJsonAsHex(nlohmann::ordered_json&  jdata,
                      const T                  data,
                      const util::JsonOptions& options = util::JsonOptions())
{
    jdata = to_hex_variable_width(data);
}

/// @brief Convert an integer type to JSON but encoded in binary as a JSON string
/// rather than as a JSON number type. Useful for bitmasks.
template <typename T>
void FieldToJsonAsFixedWidthBinary(nlohmann::ordered_json&  jdata,
                                   const T                  data,
                                   const util::JsonOptions& options = util::JsonOptions())
{
    jdata = to_binary_fixed_width(data);
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

void FieldToJson(nlohmann::ordered_json&  jdata,
                 const float              data[4],
                 const util::JsonOptions& options = util::JsonOptions());

void FieldToJson(nlohmann::ordered_json&  jdata,
                 const uint32_t           data[4],
                 const util::JsonOptions& options = util::JsonOptions());

void FieldToJson(nlohmann::ordered_json&  jdata,
                 const uint64_t           data[4],
                 const util::JsonOptions& options = util::JsonOptions());

void FieldToJson(nlohmann::ordered_json& jdata, const LARGE_INTEGER& value, const JsonOptions& options = JsonOptions());

void FieldToJson(nlohmann::ordered_json& jdata, const LUID& value, const JsonOptions& options = JsonOptions());

void HandleToJson(nlohmann::ordered_json&  jdata,
                  const format::HandleId*  data,
                  size_t                   num_elements,
                  const util::JsonOptions& options = util::JsonOptions());

#if defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)
/// @brief Turn a D3D12 or DXGI HRESULT into a string with the same character
/// sequence as the identifier of the C macro defining it in a header like
/// winerror.h.
/// @param hresult A D3D12 or DXGI result code.
std::string HresultToString(const HRESULT hresult);
void        HresultToJson(nlohmann::ordered_json& jdata, const HRESULT hresult, const util::JsonOptions& options);

void FieldToJson(nlohmann::ordered_json&                                  jdata,
                 const format::InitDx12AccelerationStructureGeometryDesc& data,
                 const util::JsonOptions&                                 options);
void FieldToJson(nlohmann::ordered_json& jdata, const format::DxgiAdapterDesc& data, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const format::Dx12RuntimeInfo& data, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const util::filepath::FileInfo& data, const util::JsonOptions& options);
#endif

/// @brief Represent a binary blob in the JSON tree either as the filename of a file containing the data that is also
/// written, or as placeholder text with the binary file not written, depending on the JsonOptions in effect.
/// @return true if a binary file was written to storage, false if not.
bool RepresentBinaryFile(const util::JsonOptions& json_options,
                         nlohmann::ordered_json&  jdata,
                         std::string_view         filename_base,
                         const uint64_t           instance_counter,
                         const uint64_t           data_size,
                         const uint8_t* const     data);

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_JSON_UTIL_H
