/*
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

#ifndef GFXRECON_DECODE_VULKAN_JSON_UTIL_H
#define GFXRECON_DECODE_VULKAN_JSON_UTIL_H

#include "util/defines.h"
#include "nlohmann/json.hpp"
#include "vulkan/vulkan.h"

#include <sstream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

enum class JsonFormat
{
    JSON,
    JSONL
};

struct JsonOptions
{
    JsonFormat  format        = JsonFormat::JSON;
    bool        dump_binaries = false;
    bool        expand_flags  = false;
    std::string root_dir;
    std::string data_sub_dir;
};

template<typename T>
std::string to_hex(T value)
{
    std::stringstream stream;
    stream << "0x" << std::setfill('0') << std::setw(sizeof(T)*2) << std::hex << value;
    return stream.str();
}

inline std::string uuid_to_string(uint32_t size, const uint8_t* uuid)
{
    std::stringstream stream;
    stream << std::setfill('0') << std::setw(2) << std::hex;
    for (size_t i = 0; i < size; ++i)
    {
        stream << (uint32_t)uuid[i];
    }
    return stream.str();
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_JSON_UTIL_H

