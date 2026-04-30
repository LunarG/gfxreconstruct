/*
** Copyright (c) 2020-2026 LunarG, Inc.
** Copyright (c) 2022-2024 Advanced Micro Devices, Inc. All rights reserved.
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

#include "convert_vulkan_feature.h"

#include "util/feature_module_registry.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(convert)

// Register this class as a feature in a module registry
GFXR_UTIL_REGISTER_FEATURE_CREATOR(ConvertFeature, ConvertVulkanFeature)

std::string ConvertVulkanFeature::GetVersionString() const
{
    return std::to_string(VK_API_VERSION_MAJOR(VK_HEADER_VERSION_COMPLETE)) + "." +
           std::to_string(VK_API_VERSION_MINOR(VK_HEADER_VERSION_COMPLETE)) + "." +
           std::to_string(VK_API_VERSION_PATCH(VK_HEADER_VERSION_COMPLETE));
}

void ConvertVulkanFeature::RegisterDecodeComponents(gfxrecon::decode::FileProcessor& file_processor)
{
    vulkan_decoder_.AddConsumer(&vulkan_json_consumer_);
    file_processor.AddDecoder(&vulkan_decoder_);
}

void ConvertVulkanFeature::RegisterJsonWriter(gfxrecon::decode::JsonWriter* json_writer)
{
    vulkan_json_consumer_.Initialize(json_writer, GetVersionString());
}

void ConvertVulkanFeature::UnregisterJsonWriter()
{
    vulkan_json_consumer_.Destroy();
}

GFXRECON_END_NAMESPACE(convert)
GFXRECON_END_NAMESPACE(gfxrecon)
