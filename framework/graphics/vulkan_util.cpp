/*
** Copyright (c) 2021 LunarG, Inc.
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

#include "graphics/vulkan_util.h"
#include "graphics/vulkan_struct_get_pnext.h"

#include "Vulkan-Utility-Libraries/vk_format_utils.h"

#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

util::platform::LibraryHandle InitializeLoader(const char* loader_path)
{
    if (loader_path != nullptr && loader_path[0] != '\0')
    {
        return util::platform::OpenLibrary(loader_path);
    }
    else
    {
        return util::platform::OpenLibrary(kLoaderLibNames);
    }
}

void ReleaseLoader(util::platform::LibraryHandle loader_handle)
{
    if (loader_handle != nullptr)
    {
        util::platform::CloseLibrary(loader_handle);
    }
}

bool ImageHasUsage(VkImageUsageFlags usage_flags, VkImageUsageFlagBits bit)
{
    return (usage_flags & bit) == bit;
}

VkDeviceSize AlignBufferOffset(VkDeviceSize offset, VkDeviceSize alignment)
{
    // Vulkan only specifies alignments for buffer-image copies. Use modulo math so
    // non-power-of-two alignments (e.g. 3-byte RGB formats) are handled correctly.
    GFXRECON_ASSERT(alignment > 0);

    if (alignment <= 1)
    {
        return offset;
    }

    const VkDeviceSize remainder = offset % alignment;
    if (remainder == 0)
    {
        return offset;
    }

    return offset + (alignment - remainder);
}

VkDeviceSize GetBufferImageCopyOffsetAlignment(VkFormat format, VkImageAspectFlags aspect_mask)
{
    if (format == VK_FORMAT_UNDEFINED)
    {
        // Defensive fallback for external-format images where no concrete VkFormat is available.
        return 1;
    }

    if (vkuFormatIsDepthOrStencil(format))
    {
        // Vulkan requires 4-byte bufferOffset alignment for depth/stencil image copies.
        return 4;
    }

    if (vkuFormatIsMultiplane(format))
    {
        // For multiplane formats, alignment comes from the selected plane's compatible format.
        VkImageAspectFlagBits plane_aspect = VK_IMAGE_ASPECT_PLANE_0_BIT;
        if ((aspect_mask & VK_IMAGE_ASPECT_PLANE_1_BIT) != 0)
        {
            plane_aspect = VK_IMAGE_ASPECT_PLANE_1_BIT;
        }
        else if ((aspect_mask & VK_IMAGE_ASPECT_PLANE_2_BIT) != 0)
        {
            plane_aspect = VK_IMAGE_ASPECT_PLANE_2_BIT;
        }

        const VkFormat compatible_format = vkuFindMultiplaneCompatibleFormat(format, plane_aspect);
        GFXRECON_ASSERT(compatible_format != VK_FORMAT_UNDEFINED);
        if (compatible_format != VK_FORMAT_UNDEFINED)
        {
            const VKU_FORMAT_INFO format_info = vkuGetFormatInfo(compatible_format);
            GFXRECON_ASSERT(format_info.texel_block_size > 0);
            return format_info.texel_block_size;
        }

        return 1;
    }

    const VKU_FORMAT_INFO format_info = vkuGetFormatInfo(format);
    GFXRECON_ASSERT(format_info.texel_block_size > 0);
    return format_info.texel_block_size;
}

uint32_t GetFormatElementSizeWithAspect(VkFormat format, VkImageAspectFlagBits aspectMask)
{
    // Depth/Stencil aspect have separate helper functions
    if (aspectMask & VK_IMAGE_ASPECT_STENCIL_BIT)
    {
        return vkuFormatStencilSize(format) / 8;
    }
    else if (aspectMask & VK_IMAGE_ASPECT_DEPTH_BIT)
    {
        return vkuFormatDepthSize(format) / 8;
    }
    else if (vkuFormatIsMultiplane(format))
    {
        // Element of entire multiplane format is not useful,
        // Want to get just a single plane as the lookup format
        format = vkuFindMultiplaneCompatibleFormat(format, aspectMask);
    }

    return vkuFormatTexelBlockSize(format);
}

uint32_t FindTransferQueueFamilyIndex(const VulkanQueueFamilyFlags& families)
{
    uint32_t index = VK_QUEUE_FAMILY_IGNORED;

    for (uint32_t i = 0; i < static_cast<uint32_t>(families.queue_family_index_enabled.size()); ++i)
    {
        if (families.queue_family_index_enabled[i])
        {
            const auto& flags_entry = families.queue_family_properties_flags.find(i);
            if ((flags_entry != families.queue_family_properties_flags.end()))
            {
                if ((flags_entry->second & VK_QUEUE_TRANSFER_BIT) == VK_QUEUE_TRANSFER_BIT)
                {
                    return i;
                }
                else if ((flags_entry->second & (VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT)))
                {
                    index = i;
                }
            }
        }
    }

    return index;
}

uint32_t FindComputeQueueFamilyIndex(const VulkanQueueFamilyFlags& families)
{
    for (uint32_t i = 0; i < static_cast<uint32_t>(families.queue_family_index_enabled.size()); ++i)
    {
        if (families.queue_family_index_enabled[i])
        {
            const auto& flags_entry = families.queue_family_properties_flags.find(i);
            if ((flags_entry != families.queue_family_properties_flags.end()))
            {
                if ((flags_entry->second & VK_QUEUE_COMPUTE_BIT) == VK_QUEUE_COMPUTE_BIT)
                {
                    return i;
                }
            }
        }
    }

    return VK_QUEUE_FAMILY_IGNORED;
}

uint32_t FindGraphicsOrComputeQueueFamilyIndex(const VulkanQueueFamilyFlags& families)
{
    for (uint32_t i = 0; i < static_cast<uint32_t>(families.queue_family_index_enabled.size()); ++i)
    {
        if (families.queue_family_index_enabled[i])
        {
            const auto& flags_entry = families.queue_family_properties_flags.find(i);
            if (flags_entry != families.queue_family_properties_flags.end() &&
                (flags_entry->second & (VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT)))
            {
                return i;
            }
        }
    }

    return VK_QUEUE_FAMILY_IGNORED;
}

std::vector<VkPipelineBindPoint> ShaderStageFlagsToPipelineBindPoints(VkShaderStageFlags flags)
{
    std::vector<VkPipelineBindPoint> bind_points;

    constexpr VkShaderStageFlags graphics_flags =
        VK_SHADER_STAGE_ALL_GRAPHICS | VK_SHADER_STAGE_TASK_BIT_EXT | VK_SHADER_STAGE_MESH_BIT_EXT;
    constexpr VkShaderStageFlags compute_flags = VK_SHADER_STAGE_COMPUTE_BIT;
    constexpr VkShaderStageFlags rt_flags      = VK_SHADER_STAGE_RAYGEN_BIT_KHR | VK_SHADER_STAGE_ANY_HIT_BIT_KHR |
                                            VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR | VK_SHADER_STAGE_MISS_BIT_KHR |
                                            VK_SHADER_STAGE_INTERSECTION_BIT_KHR | VK_SHADER_STAGE_CALLABLE_BIT_KHR;

    if (flags & graphics_flags)
    {
        bind_points.push_back(VK_PIPELINE_BIND_POINT_GRAPHICS);
    }

    if (flags & compute_flags)
    {
        bind_points.push_back(VK_PIPELINE_BIND_POINT_COMPUTE);
    }

    if (flags & rt_flags)
    {
        bind_points.push_back(VK_PIPELINE_BIND_POINT_RAY_TRACING_KHR);
    }
    return bind_points;
}

static bool IsRasterizerDiscardStaticallyEnabled(const VkGraphicsPipelineCreateInfo& create_info)
{
    if (create_info.pDynamicState != nullptr)
    {
        for (uint32_t i = 0; i < create_info.pDynamicState->dynamicStateCount; ++i)
        {
            // If VK_DYNAMIC_STATE_RASTERIZER_DISCARD_ENABLE is used, rasterizerDiscardEnable is ignored.
            // The value is set later by vkCmdSetRasterizerDiscardEnable, so it isn't statically enabled.
            if (create_info.pDynamicState->pDynamicStates[i] == VK_DYNAMIC_STATE_RASTERIZER_DISCARD_ENABLE)
            {
                return false;
            }
        }
    }

    return (create_info.pRasterizationState != nullptr) &&
           (create_info.pRasterizationState->rasterizerDiscardEnable == VK_TRUE);
}

bool ArePipelineRenderingFormatsIgnored(const VkGraphicsPipelineCreateInfo& create_info)
{
    if (vulkan_struct_get_pnext<VkPipelineRenderingCreateInfo>(&create_info) == nullptr)
    {
        return false;
    }

    // The rendering formats are ignored when a render pass is used.
    if (create_info.renderPass != VK_NULL_HANDLE)
    {
        return true;
    }

    bool has_pre_rasterization_state = false;

    // Only fragment output needs the rendering formats.
    // The others, vertex input, pre-rasterization, and fragment shader, ignore the rendering formats.
    if (const auto* library_info = vulkan_struct_get_pnext<VkGraphicsPipelineLibraryCreateInfoEXT>(&create_info))
    {
        if ((library_info->flags & VK_GRAPHICS_PIPELINE_LIBRARY_FRAGMENT_OUTPUT_INTERFACE_BIT_EXT) == 0)
        {
            return true;
        }

        has_pre_rasterization_state =
            (library_info->flags & VK_GRAPHICS_PIPELINE_LIBRARY_PRE_RASTERIZATION_SHADERS_BIT_EXT) != 0;
    }
    else
    {
        VkPipelineCreateFlags2 create_flags = create_info.flags;
        if (const auto* create_flags2_info = vulkan_struct_get_pnext<VkPipelineCreateFlags2CreateInfo>(&create_info))
        {
            create_flags = create_flags2_info->flags;
        }

        // If it doesn't have VkGraphicsPipelineLibraryCreateInfoEXT,
        // and it has VK_PIPELINE_CREATE_LIBRARY_BIT_KHR
        // or it has VkPipelineLibraryCreateInfoKHR with libraryCount > 0,
        // then the rendering formats are ignored.
        const auto* linked_libraries = vulkan_struct_get_pnext<VkPipelineLibraryCreateInfoKHR>(&create_info);
        if (((create_flags & VK_PIPELINE_CREATE_LIBRARY_BIT_KHR) != 0) ||
            ((linked_libraries != nullptr) && (linked_libraries->libraryCount > 0)))
        {
            return true;
        }

        // Otherwise, if it's also without VkGraphicsPipelineLibraryCreateInfoEXT, it's a complete graphics pipeline.
        // A complete graphics pipeline always includes pre-rasterization state.
        has_pre_rasterization_state = true;
    }

    // pRasterizationState belongs to pre-rasterization state, so it's only read when that state is present.
    // The fragment output state isn't required, and the rendering formats are ignored, only if pre-rasterization
    // state is present and rasterizerDiscardEnable is VK_TRUE. Otherwise, the rendering formats are used.
    return has_pre_rasterization_state && IsRasterizerDiscardStaticallyEnabled(create_info);
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
