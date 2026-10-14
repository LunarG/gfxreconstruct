//
// Copyright (c) 2020 Samsung
// Copyright (c) 2023 Google
// Copyright (c) 2023 LunarG, Inc
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// String and value helpers for the generated source.
// This file holds part of VulkanCppConsumerBase.  See vulkan_cpp_consumer_base.h.

#include "decode/vulkan_cpp_consumer_base.h"
#include "decode/vulkan_cpp_template_strings.h"

#include PROJECT_VERSION_HEADER_FILE
#include "util/file_path.h"
#include "util/platform.h"
#include <util/hash.h>
#include "decode/vulkan_cpp_structs.h"
#include <generated/generated_vulkan_cpp_structs.h>
#include "generated/generated_vulkan_cpp_consumer_extension.h"
#include "generated/generated_vulkan_enum_to_string.h"

#include <algorithm>
#include <cmath>
#include <iomanip>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
std::string VulkanCppConsumerBase::ToEscape(const char* value)
{
    return (value != nullptr) ? std::string("\"") + value + "\"" : "NULL";
}

std::string VulkanCppConsumerBase::ToEscape(const std::string& value)
{
    return std::string("\"") + value + "\"";
}

std::string VulkanCppConsumerBase::EscapeStringArray(const char* const* stringArray, const uint32_t stringArrayLength)
{
    if (stringArrayLength == 0)
    {
        return std::string("{\"\"}");
    }

    std::string escaped_strings = "{";
    for (uint32_t idx = 0; idx < stringArrayLength; ++idx)
    {
        escaped_strings += ToEscape(*(stringArray + idx)) + std::string(",");
    }

    // Replace the comma after the last item to a curly bracket.
    escaped_strings.back() = '}';
    return escaped_strings;
}

std::string VulkanCppConsumerBase::EscapeStringArray(const std::vector<std::string>& strings)
{
    if (strings.size() == 0)
    {
        return std::string("{\"\"}");
    }

    std::string escaped_strings = "{";
    for (uint32_t idx = 0; idx < strings.size(); ++idx)
    {
        escaped_strings += ToEscape(strings[idx]) + std::string(",");
    }

    // Replace the comma after the last item to a curly bracket.
    escaped_strings.back() = '}';
    return escaped_strings;
}

std::string VulkanCppConsumerBase::BuildValue(const VkClearColorValue color)
{
    float values[4];
    // normalize the float values, to avoid inf/nan outputs
    for (size_t idx = 0; idx < 4; idx++)
    {
        values[idx] = std::isfinite(color.float32[idx]) ? color.float32[idx] : 0;
    }

    std::stringstream output;
    output << "{{" << values[0] << ", " << values[1] << ", " << values[2] << ", " << values[3] << ""
           << "}}";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkClearValue clearValue)
{
    std::stringstream output;
    output << "{ (VkClearColorValue)" << BuildValue(clearValue.color) << " }";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkClearValue* values, uint32_t count)
{
    std::stringstream output;
    output << "{";
    for (uint32_t idx = 0; idx < count; idx++)
    {
        output << VulkanCppConsumerBase::BuildValue(values[idx]) << ", ";
    }
    output << "}";

    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkComponentMapping components)
{
    std::stringstream output;
    output << "(VkComponentMapping){ " << util::ToString<VkComponentSwizzle>(components.r) << ", "
           << util::ToString<VkComponentSwizzle>(components.g) << ", "
           << util::ToString<VkComponentSwizzle>(components.b) << ", "
           << util::ToString<VkComponentSwizzle>(components.a) << " }";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkOffset2D offSet2D)
{
    std::stringstream output;
    output << "(VkOffset2D){ " << offSet2D.x << ", " << offSet2D.y << " }";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkOffset3D offSet3D)
{
    std::stringstream output;
    output << "(VkOffset3D){ " << offSet3D.x << ", " << offSet3D.y << ", " << offSet3D.z << " }";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkOffset3D* values, uint32_t count)
{
    std::stringstream output;
    output << "{";
    for (uint32_t idx = 0; idx < count; idx++)
    {
        output << VulkanCppConsumerBase::BuildValue(values[idx]) << ", ";
    }
    output << "}";

    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkExtent2D extent2D)
{
    std::stringstream output;
    output << "(VkExtent2D){ " << extent2D.width << ", " << extent2D.height << " }";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkExtent3D extent3D)
{
    std::stringstream output;
    output << "(VkExtent3D){ " << extent3D.width << ", " << extent3D.height << ", " << extent3D.depth << " }";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkRect2D rect2D)
{
    std::stringstream output;
    output << "(VkRect2D){ " << BuildValue(rect2D.offset) << ", " << BuildValue(rect2D.extent) << " }";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkRect2D* rect2D)
{
    std::stringstream output;
    output << "(VkRect2D){ " << BuildValue(rect2D->offset) << ", " << BuildValue(rect2D->extent) << " }";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkRect2D* values, uint32_t count)
{
    std::stringstream output;
    output << "{";
    for (uint32_t idx = 0; idx < count; idx++)
    {
        output << VulkanCppConsumerBase::BuildValue(values[idx]) << ", ";
    }
    output << "}";

    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkImageSubresourceRange subresourceRange)
{
    std::stringstream output;
    output << "(VkImageSubresourceRange){ " << util::ToString<VkImageAspectFlags>(subresourceRange.aspectMask) << ", "
           << subresourceRange.baseMipLevel << ", " << subresourceRange.levelCount << ", "
           << subresourceRange.baseArrayLayer << ", " << subresourceRange.layerCount << " }";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkImageSubresourceLayers subresourceLayer)
{
    std::stringstream output;
    output << "(VkImageSubresourceLayers){ " << util::ToString<VkImageAspectFlags>(subresourceLayer.aspectMask) << ", "
           << subresourceLayer.mipLevel << ", " << subresourceLayer.baseArrayLayer << ", "
           << subresourceLayer.layerCount << " }";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkStencilOpState stencilOpState)
{
    std::stringstream output;
    output << "(VkStencilOpState){ " << util::ToString<VkStencilOp>(stencilOpState.failOp) << ", "
           << util::ToString<VkStencilOp>(stencilOpState.passOp) << ", "
           << util::ToString<VkStencilOp>(stencilOpState.depthFailOp) << ", "
           << util::ToString<VkCompareOp>(stencilOpState.compareOp) << ", " << stencilOpState.compareMask << ", "
           << stencilOpState.writeMask << ", " << stencilOpState.reference << " }";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkQueueGlobalPriorityKHR value)
{
    std::stringstream output;
    output << "(VkQueueGlobalPriorityKHR){ " << util::ToString<VkQueueGlobalPriorityKHR>(value) << " }";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkQueueGlobalPriorityKHR* values, uint32_t count)
{
    std::stringstream output;
    output << "{";
    for (uint32_t idx = 0; idx < count; idx++)
    {
        output << VulkanCppConsumerBase::BuildValue(values[idx]) << ", ";
    }
    output << "}";

    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkFragmentShadingRateCombinerOpKHR value)
{
    std::stringstream output;
    output << "(VkFragmentShadingRateCombinerOpKHR){ " << util::ToString<VkFragmentShadingRateCombinerOpKHR>(value)
           << " }";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkFragmentShadingRateCombinerOpKHR* values, uint32_t count)
{
    std::stringstream output;
    output << "{";
    for (uint32_t idx = 0; idx < count; idx++)
    {
        output << VulkanCppConsumerBase::BuildValue(values[idx]) << ", ";
    }
    output << "}";

    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkPipelineExecutableStatisticValueKHR& value)
{
    std::stringstream output;
    output << "(VkPipelineExecutableStatisticValueKHR){ " << util::ToString<uint64_t>(value.u64) << " }";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const StdVideoAV1FrameRestorationType value)
{
    std::stringstream output;
    output << "(StdVideoAV1FrameRestorationType){ " << util::ToString<StdVideoAV1FrameRestorationType>(value) << "}";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const StdVideoAV1FrameRestorationType* values, uint32_t count)
{
    std::stringstream output;
    output << "{";
    for (uint32_t idx = 0; idx < count; idx++)
    {
        output << VulkanCppConsumerBase::BuildValue(values[idx]) << ", ";
    }
    output << "}";

    return output.str();
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
