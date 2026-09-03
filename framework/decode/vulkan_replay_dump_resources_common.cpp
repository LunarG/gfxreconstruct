/*
** Copyright (c) 2024 LunarG, Inc.
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

#include "decode/common_object_info_table.h"
#include "decode/vulkan_device_address_tracker.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_replay_dump_resources_common.h"
#include "decode/vulkan_replay_options.h"
#include "decode/vulkan_temporary_objects.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "graphics/vulkan_resources_util.h"
#include "graphics/vulkan_submit_info_util.h"
#include "graphics/vulkan_util.h"
#include "util/logging.h"
#include "util/platform.h"
#include "Vulkan-Utility-Libraries/vk_format_utils.h"

#include <algorithm>
#include <cstddef>
#include <span>
#include <sstream>
#include <tuple>
#include <utility>
#include <vulkan/vulkan_core.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

ImageDumpResult CanDumpImage(const graphics::VulkanInstanceTable*             instance_table,
                             VkPhysicalDevice                                 phys_dev,
                             const VulkanImageInfo*                           image_info,
                             const graphics::VulkanDevicePropertyFeatureInfo& physical_device_features_info)
{
    GFXRECON_ASSERT(instance_table != nullptr);
    GFXRECON_ASSERT(phys_dev != VK_NULL_HANDLE);
    GFXRECON_ASSERT(image_info != nullptr);

    VkFormatProperties format_properties{};
    instance_table->GetPhysicalDeviceFormatProperties(phys_dev, image_info->format, &format_properties);

    // A format might not be supported on the replay implementation. Check before attempting to dump
    if ((image_info->tiling == VK_IMAGE_TILING_OPTIMAL &&
         format_properties.optimalTilingFeatures == VkFormatFeatureFlags(0)) ||
        (image_info->tiling == VK_IMAGE_TILING_LINEAR &&
         format_properties.linearTilingFeatures == VkFormatFeatureFlags(0)))
    {
        GFXRECON_LOG_WARNING("Format %s is not supported by the implementation",
                             util::ToString<VkFormat>(image_info->format).c_str());
        return ImageDumpResult::kFormatNotSupported;
    }

    // Check for multisampled images that cannot be resolved
    if (image_info->sample_count != VK_SAMPLE_COUNT_1_BIT)
    {
        if (graphics::VulkanResourcesUtil::SelectResolveMethod(
                *instance_table, phys_dev, image_info->format, image_info->tiling, physical_device_features_info) ==
            graphics::VulkanResourcesUtil::MultisampleResolveMethod::kUnsupported)
        {
            GFXRECON_LOG_WARNING("Multisampled image with format %s cannot be resolved and will not be dumped.",
                                 util::ToString<VkFormat>(image_info->format).c_str());
            return ImageDumpResult::kCanNotResolve;
        }
    }

    return ImageDumpResult::kCanDump;
}

const char* ImageFileExtension(DumpedImageFormat image_format)
{
    switch (image_format)
    {
        case kFormatBMP:
            return ".bmp";

        case KFormatPNG:
            return ".png";

        case KFormatRaw:
        default:
            return ".bin";
    }
}

static VkFormat ChooseDestinationImageFormat(VkFormat format)
{
    VkFormat dst_format;

    if (vkuFormatIsSRGB(format))
    {
        dst_format = VK_FORMAT_B8G8R8A8_SRGB;
    }
    else if (vkuFormatIsDepthOrStencil(format))
    {
        // Converting depth format with vkCmdBlit is not allowed.
        // We will do the conversion on the cpu.
        dst_format = format;
    }
    else
    {
        dst_format = VK_FORMAT_B8G8R8A8_UNORM;
    }

    return dst_format;
}

VkResult CreateVkImage(const CommonObjectInfoTable&               object_info_table,
                       const graphics::VulkanInjectedDeviceCalls& device_table,
                       const VkPhysicalDeviceMemoryProperties*    replay_device_phys_mem_props,
                       const VulkanImageInfo*                     image_info,
                       VkImage*                                   new_image,
                       VkDeviceMemory*                            new_image_memory)
{
    VkImageCreateInfo ci;
    ci.sType                 = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
    ci.pNext                 = nullptr;
    ci.flags                 = VkImageCreateFlags(0);
    ci.imageType             = image_info->type;
    ci.format                = image_info->format;
    ci.extent                = image_info->extent;
    ci.mipLevels             = image_info->level_count;
    ci.arrayLayers           = image_info->layer_count;
    ci.samples               = image_info->sample_count;
    ci.tiling                = image_info->tiling;
    ci.usage                 = VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
    ci.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    ci.queueFamilyIndexCount = 0;
    ci.pQueueFamilyIndices   = nullptr;
    ci.initialLayout         = VK_IMAGE_LAYOUT_UNDEFINED;

    const VulkanDeviceInfo* device_info = object_info_table.GetVkDeviceInfo(image_info->parent_id);
    VkDevice                device      = device_info->handle;

    assert(new_image);
    auto     injected = device_table.Open();
    VkResult res      = injected->CreateImage(device, &ci, nullptr, new_image);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("CreateImage failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    VkMemoryRequirements mem_reqs       = {};
    VkMemoryAllocateInfo mem_alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO, nullptr };

    injected->GetImageMemoryRequirements(device, *new_image, &mem_reqs);
    mem_alloc_info.allocationSize = mem_reqs.size;

    assert(replay_device_phys_mem_props);
    uint32_t index = graphics::GetMemoryTypeIndex(
        *replay_device_phys_mem_props, mem_reqs.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    if (index == std::numeric_limits<uint32_t>::max())
    {
        GFXRECON_LOG_ERROR("%s failed to find an appropriate memory type", __func__)
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    mem_alloc_info.memoryTypeIndex = index;

    assert(new_image_memory);
    res = injected->AllocateMemory(device, &mem_alloc_info, nullptr, new_image_memory);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("AllocateMemory failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    res = injected->BindImageMemory(device, *new_image, *new_image_memory, 0);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("BindImageMemory failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    return VK_SUCCESS;
}

uint32_t VkIndexTypeToBytes(VkIndexType type)
{
    switch (type)
    {
        case VK_INDEX_TYPE_UINT8_EXT:
            return 1;

        case VK_INDEX_TYPE_UINT16:
            return 2;

        case VK_INDEX_TYPE_UINT32:
            return 4;

        case VK_INDEX_TYPE_NONE_KHR:
        default:
            GFXRECON_LOG_ERROR("%s() Unrecognized/unhandled index type (%u)", __func__, static_cast<uint32_t>(type));
            assert(0);
            return 0;
    }
}

MinMaxVertexIndex FindMinMaxVertexIndices(const std::vector<uint8_t>& index_data,
                                          uint32_t                    index_count,
                                          uint32_t                    first_index,
                                          int32_t                     vertex_offset,
                                          VkIndexType                 type)
{
    switch (type)
    {
        case VK_INDEX_TYPE_UINT8_EXT:
        {
            const uint8_t restart_index = 0xff;
            const auto*   indices       = static_cast<const uint8_t*>(index_data.data());
            uint32_t      i             = 0;
            while (indices[first_index + i] == restart_index && i < index_count)
            {
                ++i;
            }

            if (i == index_count)
            {
                return MinMaxVertexIndex({ 0, 0 });
            }

            uint8_t min = indices[first_index + i];
            uint8_t max = indices[first_index + i];

            for (; i < index_count; ++i)
            {
                if (indices[first_index + i] == restart_index)
                {
                    continue;
                }
                min = std::min(min, indices[first_index + i]);
                max = std::max(max, indices[first_index + i]);
            }

            return MinMaxVertexIndex{ static_cast<uint32_t>(min) + vertex_offset,
                                      static_cast<uint32_t>(max) + vertex_offset };
        }
        break;

        case VK_INDEX_TYPE_UINT16:
        {
            const uint16_t restart_index = 0xffff;
            const auto*    indices       = reinterpret_cast<const uint16_t*>(index_data.data());
            uint32_t       i             = 0;
            while (indices[first_index + i] == restart_index && i < index_count)
            {
                ++i;
            }

            if (i == index_count)
            {
                return MinMaxVertexIndex{ 0, 0 };
            }

            uint16_t min = indices[first_index + i];
            uint16_t max = indices[first_index + i];

            for (; i < index_count; ++i)
            {
                if (indices[first_index + i] == restart_index)
                {
                    continue;
                }
                min = std::min(min, indices[first_index + i]);
                max = std::max(max, indices[first_index + i]);
            }

            return MinMaxVertexIndex{ static_cast<uint32_t>(min) + vertex_offset,
                                      static_cast<uint32_t>(max) + vertex_offset };
        }
        break;

        case VK_INDEX_TYPE_UINT32:
        {
            const uint32_t restart_index = 0xffffffff;
            const auto*    indices       = reinterpret_cast<const uint32_t*>(index_data.data());
            uint32_t       i             = 0;
            while (indices[first_index + i] == restart_index && i < index_count)
            {
                ++i;
            }

            if (i == index_count)
            {
                return MinMaxVertexIndex{ 0, 0 };
            }

            uint32_t min = indices[first_index + i];
            uint32_t max = indices[first_index + i];

            for (; i < index_count; ++i)
            {
                if (indices[first_index + i] == restart_index)
                {
                    continue;
                }
                min = std::min(min, indices[first_index + i]);
                max = std::max(max, indices[first_index + i]);
            }
            return MinMaxVertexIndex{ min + vertex_offset, max + vertex_offset };
        }
        break;

        case VK_INDEX_TYPE_NONE_KHR:
        default:
            GFXRECON_LOG_ERROR("%s() Unrecognized/unhandled index type (%u)", __func__, static_cast<uint32_t>(type));
            assert(0);

            return MinMaxVertexIndex{ 0, 0 };
            break;
    }
}

VkResult DumpImage(DumpedImage&                               dumped_image,
                   VkImageLayout                              layout,
                   float                                      scale,
                   bool                                       dump_image_raw,
                   const ImageSubresourceRanges&              subresource_range,
                   DumpedImageHostData&                       data,
                   const VulkanDeviceInfo*                    device_info,
                   const graphics::VulkanInjectedDeviceCalls& device_table,
                   const graphics::VulkanInstanceTable*       instance_table,
                   const CommonObjectInfoTable&               object_info_table)
{
    GFXRECON_ASSERT(device_info != nullptr);
    GFXRECON_ASSERT(device_table.IsValid());
    GFXRECON_ASSERT(instance_table != nullptr);

    const VulkanImageInfo* image_info = dumped_image.image_info;
    GFXRECON_ASSERT(image_info != nullptr);

    const VulkanPhysicalDeviceInfo* phys_dev_info = object_info_table.GetVkPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    graphics::VulkanResourcesUtil resource_util(device_info->handle,
                                                device_info->parent,
                                                device_table,
                                                *instance_table,
                                                device_info->property_feature_info,
                                                device_info->version_extension_info,
                                                *phys_dev_info->replay_device_info->memory_properties);

    // Choose the format in which the image will be dumped from the gpu into the host memory
    VkFormat dst_format;
    {
        // When dumping images raw, the data will be fetched in the same format, otherwise they will be transformed into
        // a VK_FORMAT_B8G8R8A8_* format, more suitable for dumping in an image file.
        const VkFormat target_format =
            dump_image_raw ? image_info->format : ChooseDestinationImageFormat(image_info->format);

        if (target_format != image_info->format)
        {
            // Check if we can convert the image into the desired format
            const bool is_blit_supported =
                resource_util.IsBlitSupported(image_info->format, image_info->tiling, target_format);

            // If we cannot convert then we will dump the image verbatim into a binary finaly
            dst_format = is_blit_supported ? target_format : image_info->format;
        }
        else
        {
            dst_format = image_info->format;
        }
    }

    // Scale can be greater than one so we need to check if we can scale that much
    const std::array<float, 2> scale_xy = { scale, scale };

    const bool scaling_supported = resource_util.IsScalingSupported(
        image_info->format, image_info->tiling, dst_format, image_info->type, image_info->extent, scale_xy);

    dumped_image.scaling_failed = (scale != 1.0f && !scaling_supported);
    dumped_image.dumped_format  = dst_format;

    ImageSubresourceRanges modified_subresource_range;
    ValidateImageSubresourceRange(subresource_range, modified_subresource_range, image_info);

    std::vector<VkImageAspectFlagBits> aspects;
    graphics::AspectFlagsToFlagBits(modified_subresource_range.aspect_mask, aspects);

    const VkExtent3D scaled_extent = (scale != 1.0f && scaling_supported)
                                         ? graphics::ScaleExtent3DNoDepth(image_info->extent, scale)
                                         : image_info->extent;

    const bool is_3d = image_info->type == VK_IMAGE_TYPE_3D;
    uint32_t   total_dumped_subresources;
    if (is_3d)
    {
        total_dumped_subresources = 0;
        for (uint32_t m = modified_subresource_range.base_mip_level;
             m < modified_subresource_range.base_mip_level + modified_subresource_range.level_count;
             ++m)
        {
            total_dumped_subresources += graphics::ScaleToMipLevel(modified_subresource_range.z_count, m);
        }
        total_dumped_subresources *= static_cast<uint32_t>(aspects.size());
    }
    else
    {
        total_dumped_subresources = static_cast<uint32_t>(aspects.size()) * modified_subresource_range.level_count *
                                    modified_subresource_range.layer_count;
    }

    data.resize(total_dumped_subresources);

    // data will hold dumped data for all aspects and sub resources, total_dumped_subresources in total.
    // VulkanResourcesUtil::ReadImageResource dumps all subresources for a specific aspect.
    // For that reason keep a different counter for the data vector
    size_t data_index = 0;
    for (const auto aspect : aspects)
    {
        std::vector<uint64_t> subresource_offsets;
        std::vector<uint64_t> subresource_sizes;

        graphics::VulkanResourcesUtil::ImageResource image_resource = {};
        image_resource.image                                        = image_info->handle;
        image_resource.format                                       = image_info->format;
        image_resource.type                                         = image_info->type;
        image_resource.extent                                       = image_info->extent;
        image_resource.level_count                                  = image_info->level_count;
        image_resource.layer_count                                  = image_info->layer_count;
        image_resource.tiling                                       = image_info->tiling;
        image_resource.sample_count                                 = image_info->sample_count;
        image_resource.layout = (layout == VK_IMAGE_LAYOUT_MAX_ENUM) ? image_info->intermediate_layout : layout;
        image_resource.queue_family_index = image_info->queue_family_index;
        image_resource.external_format    = image_info->external_format;
        image_resource.size               = image_info->size;
        image_resource.level_sizes        = &subresource_sizes;
        image_resource.aspect             = aspect;
        image_resource.scale              = scale_xy;
        image_resource.dst_format         = dst_format;
        image_resource.dump_resources     = true;

        image_resource.resource_size = resource_util.GetImageSubresourceSizesDumpResources(dst_format,
                                                                                           image_info->type,
                                                                                           scaled_extent,
                                                                                           image_info->level_count,
                                                                                           image_info->layer_count,
                                                                                           aspect,
                                                                                           subresource_offsets,
                                                                                           subresource_sizes);

        if (!image_resource.resource_size)
        {
            GFXRECON_LOG_WARNING("Unsupported format. Image cannot be dumped");
            // This should not prohibit us from dumping other images though. Treat it as a no error
            return VK_SUCCESS;
        }

        if (subresource_offsets.empty() || subresource_sizes.empty())
        {
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        DumpedHostData raw_data;
        VkResult       result = resource_util.ReadImageResource(image_resource, raw_data);

        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_WARNING("Reading from image resource %" PRIu64 " failed (%s)",
                                 image_info->capture_id,
                                 util::ToString<VkResult>(result).c_str())
            return result;
        }

        // absolute base index of base_mip_level in the full-image subresource layout
        uint32_t mip_base = 0;
        if (is_3d)
        {
            for (uint32_t m = 0; m < modified_subresource_range.base_mip_level; ++m)
            {
                mip_base += graphics::ScaleToMipLevel(image_info->extent.depth, m);
            }
        }

        for (uint32_t mip = modified_subresource_range.base_mip_level;
             mip < modified_subresource_range.base_mip_level + modified_subresource_range.level_count;
             ++mip)
        {
            const VkExtent3D subresource_extent        = graphics::ScaleToMipLevel(image_info->extent, mip);
            const VkExtent3D subresource_scaled_extent = graphics::ScaleToMipLevel(scaled_extent, mip);

            const uint32_t start =
                is_3d ? modified_subresource_range.base_z >> mip : modified_subresource_range.base_array_layer;
            const uint32_t end =
                is_3d ? graphics::ScaleToMipLevel(
                            modified_subresource_range.base_z + modified_subresource_range.z_count, mip)
                      : (modified_subresource_range.base_array_layer + modified_subresource_range.layer_count);
            for (uint32_t z = start; z < end; ++z)
            {
                dumped_image.dumped_subresources.emplace_back(
                    aspect, subresource_extent, subresource_scaled_extent, mip, is_3d ? 0 : z, is_3d ? z : 0);

                const uint32_t sub_res_idx = is_3d ? (mip_base + z) : (mip * image_info->layer_count + z);
                const void*    offsetted_data =
                    reinterpret_cast<const void*>(raw_data.data() + subresource_offsets[sub_res_idx]);

                data[data_index].resize(subresource_sizes[sub_res_idx]);
                util::platform::MemoryCopy(data[data_index].data(),
                                           subresource_sizes[sub_res_idx],
                                           offsetted_data,
                                           subresource_sizes[sub_res_idx]);
                ++data_index;
            }

            if (is_3d)
            {
                mip_base += graphics::ScaleToMipLevel(image_info->extent.depth, mip);
            }
        }
    }
    GFXRECON_ASSERT(data_index == total_dumped_subresources);

    return VK_SUCCESS;
}

VkResult DumpBuffer(const DumpedBuffer&                        dumped_buffer,
                    DumpedHostData&                            data,
                    const VulkanDeviceInfo*                    device_info,
                    const graphics::VulkanInjectedDeviceCalls& device_table,
                    const graphics::VulkanInstanceTable*       instance_table,
                    const CommonObjectInfoTable&               object_info_table)
{
    GFXRECON_ASSERT(device_info != nullptr);
    GFXRECON_ASSERT(device_table.IsValid());
    GFXRECON_ASSERT(instance_table != nullptr);

    const VulkanPhysicalDeviceInfo* phys_dev_info = object_info_table.GetVkPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    graphics::VulkanResourcesUtil resource_util(device_info->handle,
                                                device_info->parent,
                                                device_table,
                                                *instance_table,
                                                device_info->property_feature_info,
                                                device_info->version_extension_info,
                                                *phys_dev_info->replay_device_info->memory_properties);

    GFXRECON_ASSERT(dumped_buffer.size);
    GFXRECON_ASSERT(dumped_buffer.size != VK_WHOLE_SIZE);
    GFXRECON_ASSERT(dumped_buffer.offset != VK_WHOLE_SIZE);

    const uint32_t transfer_queue_index = FindTransferQueueFamilyIndex(device_info->enabled_queue_family_flags);
    if (transfer_queue_index == VK_QUEUE_FAMILY_IGNORED)
    {
        GFXRECON_LOG_ERROR("Failed to find a transfer queue")
        return VK_ERROR_UNKNOWN;
    }

    GFXRECON_ASSERT(dumped_buffer.buffer_info.handle != VK_NULL_HANDLE);
    VkResult res = resource_util.ReadFromBufferResource(
        dumped_buffer.buffer_info.handle, dumped_buffer.size, dumped_buffer.offset, transfer_queue_index, data);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_WARNING("Failed reading from buffer (%s)", util::ToString<VkResult>(res).c_str());
        return res;
    }

    return VK_SUCCESS;
}

std::string ShaderStageToStr(VkShaderStageFlagBits shader_stage)
{
    const std::string shader_stage_name_whole = util::ToString<VkShaderStageFlagBits>(shader_stage);
    std::string       shader_stage_name;
    if (!shader_stage_name_whole.compare(shader_stage_name_whole.size() - 4, 4, "_BIT"))
    {
        shader_stage_name = shader_stage_name_whole.substr(16, shader_stage_name_whole.size() - 20);
    }
    else if (!shader_stage_name_whole.compare(shader_stage_name_whole.size() - 8, 8, "_BIT_KHR"))
    {
        shader_stage_name = shader_stage_name_whole.substr(16, shader_stage_name_whole.size() - 24);
    }

    std::transform(shader_stage_name.begin(), shader_stage_name.end(), shader_stage_name.begin(), [](unsigned char c) {
        return std::tolower(c);
    });

    return shader_stage_name;
}

std::string ImageAspectToStr(VkImageAspectFlagBits aspect)
{
    std::string aspect_str_whole(util::ToString<VkImageAspectFlagBits>(aspect));
    std::string aspect_str(aspect_str_whole.begin() + 16, aspect_str_whole.end() - 4);

    std::transform(
        aspect_str.begin(), aspect_str.end(), aspect_str.begin(), [](unsigned char c) { return std::tolower(c); });

    return aspect_str;
}

std::string FormatToStr(VkFormat format)
{
    std::string whole_format_name = util::ToString<VkFormat>(format);
    std::string format_name(whole_format_name.begin() + 10, whole_format_name.end());

    std::transform(
        format_name.begin(), format_name.end(), format_name.begin(), [](unsigned char c) { return std::tolower(c); });

    return format_name;
}

std::string IndexTypeToStr(VkIndexType type)
{
    std::string index_type_name_whole = util::ToString<VkIndexType>(type);
    std::string index_type_name(index_type_name_whole.begin() + 13, index_type_name_whole.end());

    std::transform(index_type_name.begin(), index_type_name.end(), index_type_name.begin(), [](unsigned char c) {
        return std::tolower(c);
    });

    return index_type_name;
}

VkResult CreateVkBuffer(VkDeviceSize                               size,
                        const graphics::VulkanInjectedDeviceCalls& device_table,
                        VkDevice                                   parent_device,
                        const VkBaseInStructure*                   buffer_create_info_pNext,
                        const VkBaseInStructure*                   allocate_memory_info_pNext,
                        const VkPhysicalDeviceMemoryProperties*    replay_device_phys_mem_props,
                        VkBufferUsageFlags                         usage_flags,
                        VkBuffer*                                  new_buffer,
                        VkDeviceMemory*                            new_memory)
{
    assert(size);
    assert(new_buffer != nullptr);
    assert(new_memory != nullptr);
    assert(parent_device != VK_NULL_HANDLE);
    assert(replay_device_phys_mem_props);

    VkBufferCreateInfo bci;
    bci.sType                 = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    bci.pNext                 = buffer_create_info_pNext;
    bci.flags                 = 0;
    bci.size                  = size;
    bci.usage                 = usage_flags;
    bci.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    bci.queueFamilyIndexCount = 0;
    bci.pQueueFamilyIndices   = nullptr;

    auto     injected = device_table.Open();
    VkResult res      = injected->CreateBuffer(parent_device, &bci, nullptr, new_buffer);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s(): CreateBuffer failed with: %s", __func__, util::ToString<VkResult>(res).c_str());
        return res;
    }

    VkMemoryRequirements mem_reqs       = {};
    VkMemoryAllocateInfo mem_alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO, allocate_memory_info_pNext };

    injected->GetBufferMemoryRequirements(parent_device, *new_buffer, &mem_reqs);
    mem_alloc_info.allocationSize = mem_reqs.size;

    uint32_t mem_index = graphics::GetMemoryTypeIndex(
        *replay_device_phys_mem_props, mem_reqs.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    if (mem_index == std::numeric_limits<uint32_t>::max())
    {
        GFXRECON_LOG_ERROR("%s()%u failed to find an appropriate memory type", __func__, __LINE__);
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    mem_alloc_info.memoryTypeIndex = mem_index;

    // If VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT is requested then we need to pass that information vkAllocateMemory
    VkMemoryAllocateFlagsInfoKHR alloc_flags_info{};
    if ((usage_flags & VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT) == VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT)
    {
        alloc_flags_info.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO_KHR;
        alloc_flags_info.flags = VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT_KHR;
        mem_alloc_info.pNext   = &alloc_flags_info;
    }

    res = injected->AllocateMemory(parent_device, &mem_alloc_info, nullptr, new_memory);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s(): AllocateMemory failed with %s", __func__, util::ToString<VkResult>(res).c_str());
        return res;
    }

    res = injected->BindBufferMemory(parent_device, *new_buffer, *new_memory, 0);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s(): BindBufferMemory failed with %s", __func__, util::ToString<VkResult>(res).c_str());
        return res;
    }

    return VK_SUCCESS;
}

std::string ShaderStageFlagsToString(VkShaderStageFlags flags)
{
    if (flags == static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_ALL))
    {
        return util::ToString<VkShaderStageFlagBits>(VK_SHADER_STAGE_ALL);
    }

    if (flags == static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_ALL_GRAPHICS))
    {
        return util::ToString<VkShaderStageFlagBits>(VK_SHADER_STAGE_ALL_GRAPHICS);
    }

    std::stringstream flags_string_stream;
    bool              first_stage = true;

    if ((flags & static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_VERTEX_BIT)) ==
        static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_VERTEX_BIT))
    {
        if (!first_stage)
        {
            flags_string_stream << " | ";
        }

        flags_string_stream << util::ToString<VkShaderStageFlagBits>(VK_SHADER_STAGE_VERTEX_BIT);
        first_stage = false;
    }

    if ((flags & static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT)) ==
        static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT))
    {
        if (!first_stage)
        {
            flags_string_stream << " | ";
        }

        flags_string_stream << util::ToString<VkShaderStageFlagBits>(VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT);
        first_stage = false;
    }

    if ((flags & static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT)) ==
        static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT))
    {
        if (!first_stage)
        {
            flags_string_stream << " | ";
        }

        flags_string_stream << util::ToString<VkShaderStageFlagBits>(VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT);
        first_stage = false;
    }

    if ((flags & static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_GEOMETRY_BIT)) ==
        static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_GEOMETRY_BIT))
    {
        if (!first_stage)
        {
            flags_string_stream << " | ";
        }

        flags_string_stream << util::ToString<VkShaderStageFlagBits>(VK_SHADER_STAGE_GEOMETRY_BIT);
        first_stage = false;
    }

    if ((flags & static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_FRAGMENT_BIT)) ==
        static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_FRAGMENT_BIT))
    {
        if (!first_stage)
        {
            flags_string_stream << " | ";
        }

        flags_string_stream << util::ToString<VkShaderStageFlagBits>(VK_SHADER_STAGE_FRAGMENT_BIT);
        first_stage = false;
    }

    if ((flags & static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_COMPUTE_BIT)) ==
        static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_COMPUTE_BIT))
    {
        if (!first_stage)
        {
            flags_string_stream << " | ";
        }

        flags_string_stream << util::ToString<VkShaderStageFlagBits>(VK_SHADER_STAGE_COMPUTE_BIT);
        first_stage = false;
    }

    if ((flags & static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_RAYGEN_BIT_KHR)) ==
        static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_RAYGEN_BIT_KHR))
    {
        if (!first_stage)
        {
            flags_string_stream << " | ";
        }

        flags_string_stream << util::ToString<VkShaderStageFlagBits>(VK_SHADER_STAGE_RAYGEN_BIT_KHR);
        first_stage = false;
    }

    if ((flags & static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_ANY_HIT_BIT_KHR)) ==
        static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_ANY_HIT_BIT_KHR))
    {
        if (!first_stage)
        {
            flags_string_stream << " | ";
        }

        flags_string_stream << util::ToString<VkShaderStageFlagBits>(VK_SHADER_STAGE_ANY_HIT_BIT_KHR);
        first_stage = false;
    }

    if ((flags & static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR)) ==
        static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR))
    {
        if (!first_stage)
        {
            flags_string_stream << " | ";
        }

        flags_string_stream << util::ToString<VkShaderStageFlagBits>(VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR);
        first_stage = false;
    }

    if ((flags & static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_MISS_BIT_KHR)) ==
        static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_MISS_BIT_KHR))
    {
        if (!first_stage)
        {
            flags_string_stream << " | ";
        }

        flags_string_stream << util::ToString<VkShaderStageFlagBits>(VK_SHADER_STAGE_MISS_BIT_KHR);
        first_stage = false;
    }

    if ((flags & static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_INTERSECTION_BIT_KHR)) ==
        static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_INTERSECTION_BIT_KHR))
    {
        if (!first_stage)
        {
            flags_string_stream << " | ";
        }

        flags_string_stream << util::ToString<VkShaderStageFlagBits>(VK_SHADER_STAGE_INTERSECTION_BIT_KHR);
        first_stage = false;
    }

    if ((flags & static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_CALLABLE_BIT_KHR)) ==
        static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_CALLABLE_BIT_KHR))
    {
        if (!first_stage)
        {
            flags_string_stream << " | ";
        }

        flags_string_stream << util::ToString<VkShaderStageFlagBits>(VK_SHADER_STAGE_CALLABLE_BIT_KHR);
        first_stage = false;
    }

    if ((flags & static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_TASK_BIT_EXT)) ==
        static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_TASK_BIT_EXT))
    {
        if (!first_stage)
        {
            flags_string_stream << " | ";
        }

        flags_string_stream << util::ToString<VkShaderStageFlagBits>(VK_SHADER_STAGE_TASK_BIT_EXT);
        first_stage = false;
    }

    if ((flags & static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_MESH_BIT_EXT)) ==
        static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_MESH_BIT_EXT))
    {
        if (!first_stage)
        {
            flags_string_stream << " | ";
        }

        flags_string_stream << util::ToString<VkShaderStageFlagBits>(VK_SHADER_STAGE_MESH_BIT_EXT);
        first_stage = false;
    }

    if ((flags & static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_SUBPASS_SHADING_BIT_HUAWEI)) ==
        static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_SUBPASS_SHADING_BIT_HUAWEI))
    {
        if (!first_stage)
        {
            flags_string_stream << " | ";
        }

        flags_string_stream << util::ToString<VkShaderStageFlagBits>(VK_SHADER_STAGE_SUBPASS_SHADING_BIT_HUAWEI);
        first_stage = false;
    }

    if ((flags & static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_CLUSTER_CULLING_BIT_HUAWEI)) ==
        static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_CLUSTER_CULLING_BIT_HUAWEI))
    {
        if (!first_stage)
        {
            flags_string_stream << " | ";
        }

        flags_string_stream << util::ToString<VkShaderStageFlagBits>(VK_SHADER_STAGE_CLUSTER_CULLING_BIT_HUAWEI);
        first_stage = false;
    }

    if ((flags & static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_RAYGEN_BIT_NV)) ==
        static_cast<VkShaderStageFlags>(VK_SHADER_STAGE_RAYGEN_BIT_NV))
    {
        if (!first_stage)
        {
            flags_string_stream << " | ";
        }

        flags_string_stream << util::ToString<VkShaderStageFlagBits>(VK_SHADER_STAGE_RAYGEN_BIT_NV);
        first_stage = false;
    }

    return flags_string_stream.str();
}

void ShaderStageFlagsToStageNames(VkShaderStageFlags flags, std::vector<std::string>& stage_names)
{
    stage_names.clear();

    if ((flags & VK_SHADER_STAGE_VERTEX_BIT) == VK_SHADER_STAGE_VERTEX_BIT)
    {
        stage_names.push_back("vertex");
    }

    if ((flags & VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT) == VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT)
    {
        stage_names.push_back("tessellation_control");
    }

    if ((flags & VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT) == VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT)
    {
        stage_names.push_back("tessellation_evaluation");
    }

    if ((flags & VK_SHADER_STAGE_GEOMETRY_BIT) == VK_SHADER_STAGE_GEOMETRY_BIT)
    {
        stage_names.push_back("geometry");
    }

    if ((flags & VK_SHADER_STAGE_FRAGMENT_BIT) == VK_SHADER_STAGE_FRAGMENT_BIT)
    {
        stage_names.push_back("fragment");
    }

    if ((flags & VK_SHADER_STAGE_COMPUTE_BIT) == VK_SHADER_STAGE_COMPUTE_BIT)
    {
        stage_names.push_back("compute");
    }

    if ((flags & VK_SHADER_STAGE_RAYGEN_BIT_KHR) == VK_SHADER_STAGE_RAYGEN_BIT_KHR)
    {
        stage_names.push_back("raygen");
    }

    if ((flags & VK_SHADER_STAGE_ANY_HIT_BIT_KHR) == VK_SHADER_STAGE_ANY_HIT_BIT_KHR)
    {
        stage_names.push_back("any_hit");
    }

    if ((flags & VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR) == VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR)
    {
        stage_names.push_back("closest_hit");
    }

    if ((flags & VK_SHADER_STAGE_MISS_BIT_KHR) == VK_SHADER_STAGE_MISS_BIT_KHR)
    {
        stage_names.push_back("miss");
    }

    if ((flags & VK_SHADER_STAGE_INTERSECTION_BIT_KHR) == VK_SHADER_STAGE_INTERSECTION_BIT_KHR)
    {
        stage_names.push_back("intersection");
    }

    if ((flags & VK_SHADER_STAGE_CALLABLE_BIT_KHR) == VK_SHADER_STAGE_CALLABLE_BIT_KHR)
    {
        stage_names.push_back("callable");
    }

    if ((flags & VK_SHADER_STAGE_TASK_BIT_EXT) == VK_SHADER_STAGE_TASK_BIT_EXT)
    {
        stage_names.push_back("task");
    }

    if ((flags & VK_SHADER_STAGE_MESH_BIT_EXT) == VK_SHADER_STAGE_MESH_BIT_EXT)
    {
        stage_names.push_back("mesh");
    }
}

bool ValidateImageSubresourceRange(const ImageSubresourceRanges& requested_subresource_range,
                                   ImageSubresourceRanges&       modified_subresource_range,
                                   const VulkanImageInfo*        image_info)
{
    GFXRECON_ASSERT(image_info != nullptr);

    bool valid = true;

    // Validate aspect
    if ((requested_subresource_range.aspect_mask != VK_IMAGE_ASPECT_NONE) &&
        (!(graphics::GetFormatAspects(image_info->format) & requested_subresource_range.aspect_mask)))
    {
        GFXRECON_LOG_WARNING("Requested aspect 0x%x for image %" PRIu64 " is not valid for the image's format (%s)",
                             requested_subresource_range.aspect_mask,
                             image_info->capture_id,
                             util::ToString(image_info->format).c_str());

        valid                                  = false;
        modified_subresource_range.aspect_mask = graphics::GetFormatAspects(image_info->format);
    }
    else
    {
        if (requested_subresource_range.aspect_mask == VK_IMAGE_ASPECT_NONE)
        {
            modified_subresource_range.aspect_mask = graphics::GetFormatAspects(image_info->format);
        }
        else
        {
            modified_subresource_range.aspect_mask = requested_subresource_range.aspect_mask;
        }
    }

    // Validate baseMipLevel
    if (requested_subresource_range.base_mip_level >= image_info->level_count)
    {
        GFXRECON_LOG_WARNING("Requested baseMipLevel %u for image %" PRIu64 " is not valid (mipLevels: %u)",
                             requested_subresource_range.base_mip_level,
                             image_info->capture_id,
                             image_info->level_count);

        valid                                     = false;
        modified_subresource_range.base_mip_level = 0;
    }
    else
    {
        modified_subresource_range.base_mip_level = requested_subresource_range.base_mip_level;
    }

    // Validate levelCount
    if ((requested_subresource_range.level_count != VK_REMAINING_MIP_LEVELS) &&
        ((requested_subresource_range.level_count + modified_subresource_range.base_mip_level) >
         image_info->level_count))
    {
        GFXRECON_LOG_WARNING("Requested levelCount %u for image %" PRIu64 " is not valid (mipLevels: %u)",
                             requested_subresource_range.level_count,
                             image_info->capture_id,
                             image_info->level_count);

        valid                                  = false;
        modified_subresource_range.level_count = image_info->level_count - modified_subresource_range.base_mip_level;
    }
    else
    {
        if (requested_subresource_range.level_count == VK_REMAINING_MIP_LEVELS)
        {
            GFXRECON_ASSERT(image_info->level_count > modified_subresource_range.base_mip_level);
            modified_subresource_range.level_count =
                image_info->level_count - modified_subresource_range.base_mip_level;
        }
        else
        {
            modified_subresource_range.level_count = requested_subresource_range.level_count;
        }
    }

    // Handle baseArrayLayer
    if (requested_subresource_range.base_array_layer >= image_info->layer_count)
    {
        GFXRECON_LOG_WARNING("Requested baseArrayLayer %u for image %" PRIu64 " is not valid (arrayLayers: %u)",
                             requested_subresource_range.base_array_layer,
                             image_info->capture_id,
                             image_info->layer_count);

        valid                                       = false;
        modified_subresource_range.base_array_layer = 0;
    }
    else
    {
        modified_subresource_range.base_array_layer = requested_subresource_range.base_array_layer;
    }

    // Validate layerCount
    if ((requested_subresource_range.layer_count != VK_REMAINING_ARRAY_LAYERS) &&
        ((requested_subresource_range.layer_count + modified_subresource_range.base_array_layer) >
         image_info->layer_count))
    {
        GFXRECON_LOG_WARNING("Requested layerCount %u for image %" PRIu64 " is not valid (arrayLayers: %u)",
                             requested_subresource_range.layer_count,
                             image_info->capture_id,
                             image_info->layer_count);

        valid                                  = false;
        modified_subresource_range.layer_count = image_info->layer_count - modified_subresource_range.base_array_layer;
    }
    else
    {
        if (requested_subresource_range.layer_count == VK_REMAINING_ARRAY_LAYERS)
        {
            GFXRECON_ASSERT(image_info->layer_count > modified_subresource_range.base_array_layer);
            modified_subresource_range.layer_count =
                image_info->layer_count - modified_subresource_range.base_array_layer;
        }
        else
        {
            modified_subresource_range.layer_count = requested_subresource_range.layer_count;
        }
    }

    // Validate BaseZIndex
    if (requested_subresource_range.base_z >= image_info->extent.depth)
    {
        GFXRECON_LOG_WARNING("Requested BaseZIndex %u for image %" PRIu64 " is not valid (extent.depth: %u)",
                             requested_subresource_range.base_z,
                             image_info->capture_id,
                             image_info->extent.depth);

        valid                             = false;
        modified_subresource_range.base_z = 0;
    }
    else
    {
        modified_subresource_range.base_z = requested_subresource_range.base_z;
    }

    // Validate ZCount
    if ((requested_subresource_range.z_count != REMAINING_Z_INDICES) &&
        (requested_subresource_range.z_count + modified_subresource_range.base_z > image_info->extent.depth))
    {
        GFXRECON_LOG_WARNING("Requested z_count %u for image %" PRIu64 " is not valid (extent.depth: %u)",
                             requested_subresource_range.z_count,
                             image_info->capture_id,
                             image_info->extent.depth);

        valid                              = false;
        modified_subresource_range.z_count = image_info->extent.depth - modified_subresource_range.base_z;
    }
    else
    {
        if (requested_subresource_range.z_count == REMAINING_Z_INDICES)
        {
            GFXRECON_ASSERT(image_info->extent.depth > modified_subresource_range.base_z);
            modified_subresource_range.z_count = image_info->extent.depth - modified_subresource_range.base_z;
        }
        else
        {
            modified_subresource_range.z_count = requested_subresource_range.z_count;
        }
    }

    return valid;
}

void CullDescriptors(const CommonObjectInfoTable&             object_info_table_,
                     const BoundDescriptorSets&               referenced_descriptors,
                     const DescriptorImageSubresourcesVector* requested_descriptors,
                     decode::Index                            call_index,
                     bool                                     dump_all_image_subresources,
                     DescriptorImageSubresourcesVector&       descriptors_to_dump)
{
    descriptors_to_dump.clear();
    if (referenced_descriptors.empty() || (requested_descriptors != nullptr && requested_descriptors->empty()))
    {
        return;
    }

    if (requested_descriptors != nullptr)
    {
        descriptors_to_dump.reserve(referenced_descriptors.size());

        // Only dump the requested descriptors. Verify if they are valid based on the call's referenced descriptors
        for (const auto& [requested_descriptor_tuple, requested_img_subres_range] : *requested_descriptors)
        {
            // Validate requested descriptors
            const auto referenced_descriptor_entry = referenced_descriptors.find(requested_descriptor_tuple.set);
            if (referenced_descriptor_entry != referenced_descriptors.end())
            {
                const VulkanDescriptorSetInfo::VulkanDescriptorBindingsInfo& referenced_desc_set_map =
                    referenced_descriptor_entry->second;

                const auto referenced_desc_set_entry = referenced_desc_set_map.find(requested_descriptor_tuple.binding);
                if (referenced_desc_set_entry != referenced_desc_set_map.end())
                {
                    ImageSubresourceRanges modified_img_subres_range = requested_img_subres_range;
                    const auto&            referenced_desc_binding   = referenced_desc_set_entry->second;
                    bool                   valid_array_index         = false;
                    switch (referenced_desc_binding.desc_type)
                    {
                        case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                        case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                        case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                        case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                        {
                            const auto desc_array_entry =
                                referenced_desc_binding.image_info.find(requested_descriptor_tuple.array_index);
                            valid_array_index = desc_array_entry != referenced_desc_binding.image_info.end();

                            // If descriptor tuple is valid, validate the requested image sub resources
                            if (valid_array_index)
                            {
                                const auto&            img_desc_info = desc_array_entry->second;
                                const VulkanImageInfo* image_info =
                                    object_info_table_.GetVkImageInfo(img_desc_info.image_view_info->image_id);
                                if (image_info == nullptr)
                                {
                                    continue;
                                }

                                // Validate aspect
                                if (!ValidateImageSubresourceRange(
                                        requested_img_subres_range, modified_img_subres_range, image_info))
                                {
                                    GFXRECON_LOG_WARNING("Requested image subresources for image descriptor at set: %u "
                                                         "binding: %u array index: %u are not valid.",
                                                         requested_descriptor_tuple.set,
                                                         requested_descriptor_tuple.binding,
                                                         requested_descriptor_tuple.array_index);
                                }
                            }
                        }
                        break;

                        case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                        case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                            valid_array_index = referenced_desc_binding.texel_buffer_view_info.contains(
                                requested_descriptor_tuple.array_index);
                            break;

                        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                            valid_array_index =
                                referenced_desc_binding.buffer_info.contains(requested_descriptor_tuple.array_index);
                            break;

                        case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                            // Inline uniform blocks do not have arrays
                            valid_array_index = true;
                            break;

                        case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                            valid_array_index = referenced_desc_binding.acceleration_structs_khr_info.contains(
                                requested_descriptor_tuple.array_index);
                            break;

                        case VK_DESCRIPTOR_TYPE_SAMPLER:
                            // Nothing to dump for this descriptor type but don't generate a warning
                            valid_array_index = true;
                            break;

                        default:
                            GFXRECON_LOG_WARNING("%s:%u Descriptor type %u was not handled",
                                                 __FILE__,
                                                 __LINE__,
                                                 static_cast<uint32_t>(referenced_desc_binding.desc_type));
                    }

                    if (valid_array_index)
                    {
                        descriptors_to_dump.emplace_back(requested_descriptor_tuple, modified_img_subres_range);
                    }
                    else
                    {
                        GFXRECON_LOG_WARNING(
                            "Requested array index %u in descriptor set %u at binding %u is not valid for "
                            "draw call %" PRIu64,
                            requested_descriptor_tuple.array_index,
                            requested_descriptor_tuple.set,
                            requested_descriptor_tuple.binding,
                            call_index);
                    }
                }
                else
                {
                    GFXRECON_LOG_WARNING(
                        "Requested binding %u in descriptor set %u is not valid for draw call %" PRIu64,
                        requested_descriptor_tuple.binding,
                        requested_descriptor_tuple.set,
                        call_index);
                }
            }
            else
            {
                GFXRECON_LOG_WARNING("Requested descriptor set %u is not valid for draw call %" PRIu64,
                                     requested_descriptor_tuple.set,
                                     call_index);
            }
        }
    }
    else
    {
        for (const auto& [desc_set_index, desc_set] : referenced_descriptors)
        {
            for (const auto& [desc_binding_index, desc_binding] : desc_set)
            {
                switch (desc_binding.desc_type)
                {
                    case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                    case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                    case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                    case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                    {
                        for (const auto& [ai, img_desc_info] : desc_binding.image_info)
                        {
                            if (img_desc_info.image_view_info != nullptr)
                            {
                                const VulkanImageInfo* image_info =
                                    object_info_table_.GetVkImageInfo(img_desc_info.image_view_info->image_id);
                                if (image_info == nullptr)
                                {
                                    continue;
                                }

                                const ImageSubresourceRanges img_subres_range = {
                                    graphics::GetFormatAspects(image_info->format),
                                    0,
                                    dump_all_image_subresources ? VK_REMAINING_MIP_LEVELS : 1,
                                    0,
                                    dump_all_image_subresources ? VK_REMAINING_ARRAY_LAYERS : 1,
                                    0,
                                    dump_all_image_subresources ? REMAINING_Z_INDICES : 1
                                };
                                const DescriptorLocation desc_tuple = { desc_set_index, desc_binding_index, ai };

                                descriptors_to_dump.emplace_back(desc_tuple, img_subres_range);
                            }
                        }
                    }
                    break;

                    case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                    case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                    {
                        for (const auto& [ai, img_desc] : desc_binding.texel_buffer_view_info)
                        {
                            const DescriptorLocation desc_tuple = { desc_set_index, desc_binding_index, ai };
                            descriptors_to_dump.emplace_back(desc_tuple, ImageSubresourceRanges());
                        }
                    }
                    break;

                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                    {
                        for (const auto& [ai, img_desc] : desc_binding.buffer_info)
                        {
                            const DescriptorLocation desc_tuple = { desc_set_index, desc_binding_index, ai };
                            descriptors_to_dump.emplace_back(desc_tuple, ImageSubresourceRanges());
                        }
                    }
                    break;

                    case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                    {
                        // Inline uniform blocks do not have arrays
                        const DescriptorLocation desc_tuple = { desc_set_index, desc_binding_index, 0 };
                        descriptors_to_dump.emplace_back(desc_tuple, ImageSubresourceRanges());
                    }
                    break;

                    case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                    {
                        for (const auto& [ai, img_desc] : desc_binding.acceleration_structs_khr_info)
                        {
                            const DescriptorLocation desc_tuple = { desc_set_index, desc_binding_index, ai };
                            descriptors_to_dump.emplace_back(desc_tuple, ImageSubresourceRanges());
                        }
                    }
                    break;

                    case VK_DESCRIPTOR_TYPE_SAMPLER:
                        // Nothing to dump for this descriptor type
                        break;

                    default:
                        GFXRECON_LOG_WARNING("%s:%u Descriptor type %u was not handled",
                                             __FILE__,
                                             __LINE__,
                                             static_cast<uint32_t>(desc_binding.desc_type));
                }
            }
        }
    }
}

static VkResult SerializeAccelerationStructure(AccelerationStructureDumpResourcesContext* acceleration_structure,
                                               const VulkanDeviceInfo*                    device_info,
                                               const graphics::VulkanInjectedDeviceCalls& device_table,
                                               const CommonObjectInfoTable&               object_info_table_)
{
    constexpr uint32_t query_count = 1;

    const VulkanPhysicalDeviceInfo* phys_dev_info = object_info_table_.GetVkPhysicalDeviceInfo(device_info->parent_id);
    GFXRECON_ASSERT(phys_dev_info != nullptr);

    const VkPhysicalDeviceMemoryProperties& mem_props = phys_dev_info->replay_device_info->memory_properties.value();
    const VkDevice                          device    = device_info->handle;

    auto injected = device_table.Open();

    TemporaryCommandBuffer temp_command_buffer(*device_info, device_table);
    VkResult               res = temp_command_buffer.CreateAndBegin(graphics::FindComputeQueueFamilyIndex);
    if (res != VK_SUCCESS)
    {
        return res;
    }

    // Create a query pool
    TemporaryQueryPool query(device, device_table);
    res = query.Create(query_count);
    if (res != VK_SUCCESS)
    {
        return res;
    }

    injected->CmdResetQueryPool(temp_command_buffer.command_buffer, query.query_pool, 0, 1);

    // Flush any pending writes to the acceleration structure
    const VkMemoryBarrier mem_barrier = { VK_STRUCTURE_TYPE_MEMORY_BARRIER,
                                          nullptr,
                                          VK_ACCESS_ACCELERATION_STRUCTURE_WRITE_BIT_KHR | VK_ACCESS_TRANSFER_WRITE_BIT,
                                          VK_ACCESS_ACCELERATION_STRUCTURE_READ_BIT_KHR | VK_ACCESS_TRANSFER_READ_BIT };

    injected->CmdPipelineBarrier(
        temp_command_buffer.command_buffer,
        VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR | VK_PIPELINE_STAGE_TRANSFER_BIT,
        VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR | VK_PIPELINE_STAGE_TRANSFER_BIT,
        VkDependencyFlagBits(0),
        1,
        &mem_barrier,
        0,
        nullptr,
        0,
        nullptr);

    // Do vkCmdWriteAccelerationStructuresPropertiesKHR to request
    // VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SERIALIZATION_SIZE_KHR
    for (uint32_t i = 0; i < query_count; ++i)
    {
        injected->CmdWriteAccelerationStructuresPropertiesKHR(
            temp_command_buffer.command_buffer,
            1,
            &acceleration_structure->as_info->handle,
            VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SERIALIZATION_SIZE_KHR,
            query.query_pool,
            static_cast<uint32_t>(i));
    }

    res = temp_command_buffer.SubmitAndReset();
    if (res != VK_SUCCESS)
    {
        return res;
    }

    // Read query results
    std::vector<VkDeviceSize> query_results(query_count);
    res = injected->GetQueryPoolResults(device,
                                        query.query_pool,
                                        0,
                                        query_count,
                                        query_results.size() * sizeof(VkDeviceSize),
                                        query_results.data(),
                                        sizeof(VkDeviceSize),
                                        VK_QUERY_RESULT_64_BIT | VK_QUERY_RESULT_WAIT_BIT);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s: GetQueryPoolResults failed (%s)", __func__, util::ToString(res).c_str())
        return res;
    }

    // Do CmdCopyAccelerationStructureToMemoryKHR to copy the serialized AS into a buffer
    for (uint32_t i = 0; i < query_count; ++i)
    {
        const VkDeviceSize serialized_size           = query_results[i];
        acceleration_structure->serialized_data.size = serialized_size;

        if (!serialized_size)
        {
            continue;
        }

        acceleration_structure->ReleaseSerializedResources();
        res = CreateVkBuffer(serialized_size,
                             device_table,
                             device,
                             nullptr,
                             nullptr,
                             &mem_props,
                             VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT |
                                 VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT,
                             &acceleration_structure->serialized_data.buffer,
                             &acceleration_structure->serialized_data.memory);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("%s: CreateBuffer failed (%s)", __func__, util::ToString(res).c_str())
            return res;
        }

        const VkBufferDeviceAddressInfo bdai = { VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO,
                                                 nullptr,
                                                 acceleration_structure->serialized_data.buffer };

        const PFN_vkGetBufferDeviceAddress get_buffer_device_address =
            device_info->version_extension_info.SelectApiCallFlavor(VK_API_VERSION_1_2,
                                                                    injected->GetBufferDeviceAddress,
                                                                    VK_KHR_BUFFER_DEVICE_ADDRESS_EXTENSION_NAME,
                                                                    injected->GetBufferDeviceAddressKHR);
        if (get_buffer_device_address == nullptr)
        {
            GFXRECON_LOG_ERROR("%s: Neither vkGetBufferDeviceAddress nor vkGetBufferDeviceAddressKHR is available",
                               __func__)
            return VK_ERROR_UNKNOWN;
        }

        VkDeviceOrHostAddressKHR device_address;
        device_address.deviceAddress = get_buffer_device_address(device, &bdai);

        GFXRECON_ASSERT(acceleration_structure->as_info->handle != VK_NULL_HANDLE);
        const VkCopyAccelerationStructureToMemoryInfoKHR castmi = {
            VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR,
            nullptr,
            acceleration_structure->as_info->handle,
            device_address,
            VK_COPY_ACCELERATION_STRUCTURE_MODE_SERIALIZE_KHR
        };
        injected->CmdCopyAccelerationStructureToMemoryKHR(temp_command_buffer.command_buffer, &castmi);

        const VkBufferMemoryBarrier buf_barrier = { VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
                                                    nullptr,
                                                    VK_ACCESS_TRANSFER_WRITE_BIT,
                                                    VK_ACCESS_TRANSFER_READ_BIT,
                                                    VK_QUEUE_FAMILY_IGNORED,
                                                    VK_QUEUE_FAMILY_IGNORED,
                                                    acceleration_structure->serialized_data.buffer,
                                                    0,
                                                    serialized_size };

        injected->CmdPipelineBarrier(temp_command_buffer.command_buffer,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT |
                                         VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     VkDependencyFlagBits(0),
                                     0,
                                     nullptr,
                                     1,
                                     &buf_barrier,
                                     0,
                                     nullptr);
    }

    res = temp_command_buffer.SubmitAndDestroy();

    return res;
}

static VkResult DumpBLAS(DumpedAccelerationStructure&                      dumped_as,
                         AccelerationStructureDumpedHostData&              dumped_as_host_data,
                         AccelerationStructureDumpResourcesContext*        as_context,
                         const DumpResourcesAccelerationStructuresContext& acceleration_structures_context,
                         const VulkanDeviceInfo*                           device_info,
                         const graphics::VulkanInjectedDeviceCalls&        device_table,
                         const CommonObjectInfoTable&                      object_info_table,
                         const graphics::VulkanInstanceTable&              instance_table,
                         const VulkanPerDeviceAddressTrackers&             address_trackers)
{
    for (const auto& build_data : as_context->as_build_objects)
    {
        if (auto* triangles = std::get_if<AccelerationStructureDumpResourcesContext::Triangles>(&build_data))
        {
            auto& blas_triangles_variant = dumped_as.input_buffers.emplace_back(
                std::in_place_type<DumpedAccelerationStructure::DumpedBuildInputTriangleBuffer>, *triangles);
            auto& blas_triangles =
                std::get<DumpedAccelerationStructure::DumpedBuildInputTriangleBuffer>(blas_triangles_variant);
            auto& new_dumped_triangles_host_data_variant = dumped_as_host_data.build_data.emplace_back(
                std::in_place_type<AccelerationStructureDumpedHostData::TrianglesBuffers>);
            auto& new_dumped_triangles_host_data =
                std::get<AccelerationStructureDumpedHostData::TrianglesBuffers>(new_dumped_triangles_host_data_variant);

            VkResult res = DumpBuffer(blas_triangles.vertex_buffer,
                                      new_dumped_triangles_host_data.vertex_buffer,
                                      device_info,
                                      device_table,
                                      &instance_table,
                                      object_info_table);
            if (res != VK_SUCCESS)
            {
                GFXRECON_LOG_WARNING("Error dumping input vertex buffer for BLAS %" PRIu64 " (%s)",
                                     as_context->as_info->capture_id,
                                     util::ToString(res).c_str());
                return res;
            }

            if (triangles->index_type != VK_INDEX_TYPE_NONE_KHR)
            {
                res = DumpBuffer(blas_triangles.index_buffer,
                                 new_dumped_triangles_host_data.index_buffer,
                                 device_info,
                                 device_table,
                                 &instance_table,
                                 object_info_table);
                if (res != VK_SUCCESS)
                {
                    GFXRECON_LOG_WARNING("Error dumping input index buffer for BLAS %" PRIu64 " (%s)",
                                         as_context->as_info->capture_id,
                                         util::ToString(res).c_str());
                    return res;
                }
            }

            if (triangles->transform_buffer != VK_NULL_HANDLE)
            {
                res = DumpBuffer(blas_triangles.transform_buffer,
                                 new_dumped_triangles_host_data.transform_buffer,
                                 device_info,
                                 device_table,
                                 &instance_table,
                                 object_info_table);
                if (res != VK_SUCCESS)
                {
                    GFXRECON_LOG_WARNING("Error dumping transform buffer for BLAS %" PRIu64 " (%s)",
                                         as_context->as_info->capture_id,
                                         util::ToString(res).c_str());
                    return res;
                }
            }
        }
        else if (auto* aabbs = std::get_if<AccelerationStructureDumpResourcesContext::AABBS>(&build_data))
        {
            GFXRECON_ASSERT(aabbs->buffer != VK_NULL_HANDLE);
            auto& new_aabb_buffer_variant = dumped_as.input_buffers.emplace_back(
                std::in_place_type<DumpedAccelerationStructure::DumpedBuildInputAABBBuffer>, *aabbs);
            auto& new_aabb_buffer =
                std::get<DumpedAccelerationStructure::DumpedBuildInputAABBBuffer>(new_aabb_buffer_variant);

            auto& new_dumped_aabb_host_data_variant = dumped_as_host_data.build_data.emplace_back(
                std::in_place_type<AccelerationStructureDumpedHostData::AABBBuffer>);
            auto& new_dumped_aabb_host_data =
                std::get<AccelerationStructureDumpedHostData::AABBBuffer>(new_dumped_aabb_host_data_variant);

            VkResult res = DumpBuffer(new_aabb_buffer.aabb_buffer,
                                      new_dumped_aabb_host_data.aabb_buffer,
                                      device_info,
                                      device_table,
                                      &instance_table,
                                      object_info_table);
            if (res != VK_SUCCESS)
            {
                GFXRECON_LOG_WARNING("Error dumping input AABB buffer for BLAS %" PRIu64 " (%s)",
                                     as_context->as_info->capture_id,
                                     util::ToString(res).c_str());
                return res;
            }
        }
        else
        {
            GFXRECON_LOG_WARNING("Unexpected build data")
        }
    }

    VkResult res = SerializeAccelerationStructure(as_context, device_info, device_table, object_info_table);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_WARNING("Error serializing acceleration structures for TLAS %" PRIu64 " (%s)",
                             dumped_as.as_info->capture_id,
                             util::ToString(res).c_str());
        return res;
    }

    // Fetch serialized data for BLAS
    if (as_context->serialized_data.buffer != VK_NULL_HANDLE)
    {
        dumped_as.serialized_buffer.size               = as_context->serialized_data.size;
        dumped_as.serialized_buffer.buffer_info.handle = as_context->serialized_data.buffer;

        res = DumpBuffer(dumped_as.serialized_buffer,
                         dumped_as_host_data.serialized_data,
                         device_info,
                         device_table,
                         &instance_table,
                         object_info_table);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_WARNING("Error dumping fetching serialized data for TLAS %" PRIu64 " (%s)",
                                 dumped_as.as_info->capture_id,
                                 util::ToString(res).c_str());
            return res;
        }
    }

    return VK_SUCCESS;
}

static VkResult DumpTLAS(DumpedAccelerationStructure&                      dumped_as,
                         AccelerationStructureDumpedHostData&              dumped_as_host_data,
                         AccelerationStructureDumpResourcesContext*        as_context,
                         const DumpResourcesAccelerationStructuresContext& acceleration_structures_context,
                         const VulkanDeviceInfo*                           device_info,
                         const graphics::VulkanInjectedDeviceCalls&        device_table,
                         const CommonObjectInfoTable&                      object_info_table,
                         const graphics::VulkanInstanceTable&              instance_table,
                         const VulkanPerDeviceAddressTrackers&             address_trackers,
                         bool                                              use_capture_addresses)
{
    const VulkanAccelerationStructureKHRInfo* as_info = dumped_as.as_info;
    GFXRECON_ASSERT(as_info != nullptr);
    GFXRECON_ASSERT(as_info->type == VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR);

    std::unordered_set<AccelerationStructureDumpResourcesContext*> referenced_BLASes;
    const auto address_tracker_entry = address_trackers.find(device_info);
    if (address_tracker_entry == address_trackers.end())
    {
        GFXRECON_LOG_WARNING("Could not detect address tracker for device %" PRIu64, device_info->capture_id);
        return VK_SUCCESS;
    }
    const VulkanDeviceAddressTracker& device_address_tracker = address_tracker_entry->second;

    for (const auto& tlas_build_object : as_context->as_build_objects)
    {
        GFXRECON_ASSERT(
            (std::get_if<AccelerationStructureDumpResourcesContext::Triangles>(&tlas_build_object) == nullptr) &&
            (std::get_if<AccelerationStructureDumpResourcesContext::AABBS>(&tlas_build_object) == nullptr));

        const auto* instance_build_data =
            std::get_if<AccelerationStructureDumpResourcesContext::Instances>(&tlas_build_object);
        GFXRECON_ASSERT(instance_build_data != nullptr);

        auto& new_build_input_buffer = dumped_as.input_buffers.emplace_back(
            std::in_place_type<DumpedAccelerationStructure::DumpedBuildInputInstanceBuffer>, *instance_build_data);
        auto& new_instance_buffer =
            std::get<DumpedAccelerationStructure::DumpedBuildInputInstanceBuffer>(new_build_input_buffer);
        auto& new_build_host_data_variant = dumped_as_host_data.build_data.emplace_back(
            std::in_place_type<AccelerationStructureDumpedHostData::InstanceBuffer>);
        auto& new_instance_buffer_host_data =
            std::get<AccelerationStructureDumpedHostData::InstanceBuffer>(new_build_host_data_variant);
        // Fetch instance buffer
        VkResult res = DumpBuffer(new_instance_buffer.instance_buffer,
                                  new_instance_buffer_host_data.instance_buffer,
                                  device_info,
                                  device_table,
                                  &instance_table,
                                  object_info_table);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_WARNING("Error dumping input instance buffer for TLAS %" PRIu64 " (%s)",
                                 as_info->capture_id,
                                 util::ToString(res).c_str());
            return res;
        }

        // Parse instance buffer and extract referenced BLASes
        const auto* instances = reinterpret_cast<const VkAccelerationStructureInstanceKHR*>(
            new_instance_buffer_host_data.instance_buffer.data());
        for (uint32_t i = 0; i < instance_build_data->instance_count; ++i)
        {
            // Get all BLASes associated with the referenced device address
            const auto blases_infos =
                use_capture_addresses ? device_address_tracker.GetAccelerationStructuresByCaptureDeviceAddress(
                                            static_cast<VkDeviceAddress>(instances[i].accelerationStructureReference))
                                      : device_address_tracker.GetAccelerationStructuresByReplayDeviceAddress(
                                            static_cast<VkDeviceAddress>(instances[i].accelerationStructureReference));
            if (blases_infos.empty())
            {
                continue;
            }

            for (auto blas_it = blases_infos.begin(); blas_it != blases_infos.end(); ++blas_it)
            {
                if (*blas_it == nullptr)
                {
                    continue;
                }

                const auto blas_context_entry = acceleration_structures_context.find(*blas_it);
                // It is valid for a TLAS to reference BLASes which have not yet been built
                // (vkCmdBuildAccelerationStructuresIndirectKHR has not been called for the
                // VkAccelerationStructureKHR). This works as that BLAS can alias the memory of another BLAS which
                // has been properly built.
                if (blas_context_entry != acceleration_structures_context.end())
                {
                    referenced_BLASes.insert(blas_context_entry->second.get());
                    break;
                }
            }
        }
    }

    // Dump all discovered BLASes
    for (const auto& blas : referenced_BLASes)
    {
        GFXRECON_ASSERT(blas->as_info != nullptr);
        auto& new_dumped_blass = dumped_as.BLASes.emplace_back(blas->as_info, dumped_as.dump_build_input_buffers);
        auto& new_dumped_blass_host_data =
            dumped_as_host_data.blass_dumped_data.emplace_back(AccelerationStructureDumpedHostData());
        VkResult res = DumpBLAS(new_dumped_blass,
                                new_dumped_blass_host_data,
                                blas,
                                acceleration_structures_context,
                                device_info,
                                device_table,
                                object_info_table,
                                instance_table,
                                address_trackers);
        if (res != VK_SUCCESS)
        {
            return res;
        }
    }

    VkResult res = SerializeAccelerationStructure(as_context, device_info, device_table, object_info_table);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_WARNING("Error serializing acceleration structures for TLAS %" PRIu64 " (%s)",
                             as_info->capture_id,
                             util::ToString(res).c_str());
        return res;
    }

    // Fetch serialized data for TLAS
    if (as_context->serialized_data.buffer != VK_NULL_HANDLE)
    {
        dumped_as.serialized_buffer.size               = as_context->serialized_data.size;
        dumped_as.serialized_buffer.buffer_info.handle = as_context->serialized_data.buffer;

        res = DumpBuffer(dumped_as.serialized_buffer,
                         dumped_as_host_data.serialized_data,
                         device_info,
                         device_table,
                         &instance_table,
                         object_info_table);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_WARNING("Error dumping fetching serialized data for TLAS %" PRIu64 " (%s)",
                                 as_info->capture_id,
                                 util::ToString(res).c_str());
            return res;
        }
    }

    return VK_SUCCESS;
}

VkResult DumpAccelerationStructure(DumpedAccelerationStructure&                      dumped_as,
                                   AccelerationStructureDumpedHostData&              dumped_as_host_data,
                                   AccelerationStructureDumpResourcesContext*        as_context,
                                   const DumpResourcesAccelerationStructuresContext& acceleration_structures_context,
                                   const VulkanDeviceInfo*                           device_info,
                                   const graphics::VulkanInjectedDeviceCalls&        device_table,
                                   const CommonObjectInfoTable&                      object_info_table,
                                   const graphics::VulkanInstanceTable&              instance_table,
                                   const VulkanPerDeviceAddressTrackers&             address_trackers,
                                   bool                                              use_capture_addresses)
{
    const VulkanAccelerationStructureKHRInfo* as_info = dumped_as.as_info;
    GFXRECON_ASSERT(as_info != nullptr);

    VkResult res;
    if (as_info->type == VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR)
    {
        res = DumpTLAS(dumped_as,
                       dumped_as_host_data,
                       as_context,
                       acceleration_structures_context,
                       device_info,
                       device_table,
                       object_info_table,
                       instance_table,
                       address_trackers,
                       use_capture_addresses);
    }
    else
    {
        res = DumpBLAS(dumped_as,
                       dumped_as_host_data,
                       as_context,
                       acceleration_structures_context,
                       device_info,
                       device_table,
                       object_info_table,
                       instance_table,
                       address_trackers);
    }

    return res;
}

void CopyBufferAndBarrier(VkCommandBuffer                            command_buffer,
                          const graphics::VulkanInjectedDeviceCalls& device_table,
                          VkBuffer                                   src,
                          VkBuffer                                   dst,
                          const std::vector<VkBufferCopy>&           regions,
                          VkAccessFlags                              src_access_mask,
                          VkAccessFlags                              dst_access_mask,
                          VkPipelineStageFlags                       src_stage_mask,
                          VkPipelineStageFlags                       dst_stage_mask)
{
    GFXRECON_ASSERT(device_table.IsValid());

    auto injected = device_table.Open();
    injected->CmdCopyBuffer(
        command_buffer, src, dst, GFXRECON_NARROWING_CAST(uint32_t, regions.size()), regions.data());

    const VkBufferMemoryBarrier buffer_barrier = { VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
                                                   nullptr,
                                                   src_access_mask,
                                                   dst_access_mask,
                                                   VK_QUEUE_FAMILY_IGNORED,
                                                   VK_QUEUE_FAMILY_IGNORED,
                                                   dst,
                                                   0,
                                                   VK_WHOLE_SIZE };
    injected->CmdPipelineBarrier(command_buffer,
                                 src_stage_mask,
                                 dst_stage_mask,
                                 VkDependencyFlags(0),
                                 0,
                                 nullptr,
                                 1,
                                 &buffer_barrier,
                                 0,
                                 nullptr);
}

VkResult SubmitInfo2OnQueue(const graphics::VulkanInjectedDeviceCalls&        device_table,
                            const graphics::VulkanDeviceVersionExtensionInfo& device_version_extension_info,
                            VkQueue                                           queue,
                            const VkSubmitInfo2&                              submit_info_2,
                            VkFence                                           fence)
{
    auto injected = device_table.Open();

    // Check if the implementation supports either vkQueueSubmit2 (Vulkan 1.3) or vkQueueSubmit2KHR
    // (VK_KHR_synchronization2). In either case submit directly without converting
    const PFN_vkQueueSubmit2 queue_submit2 = device_version_extension_info.SelectApiCallFlavor(
        VK_API_VERSION_1_3, injected->QueueSubmit2, VK_KHR_SYNCHRONIZATION_2_EXTENSION_NAME, injected->QueueSubmit2KHR);
    if (queue_submit2 != nullptr)
    {
        return queue_submit2(queue, 1, &submit_info_2, fence);
    }

    // Otherwise fall back to vkQueueSubmit. SubmitInfoTranslator narrows the VkSubmitInfo2 back into a VkSubmitInfo,
    // reconstructing the timeline/device-group/protected pNext structures. The per-semaphore stage masks it drops are
    // only meaningful for queue-side synchronization, which is irrelevant here because the dump-resources submits are
    // serialized with host fence waits.
    graphics::SubmitInfoTranslator translator(std::span<const VkSubmitInfo2>(&submit_info_2, 1));
    return injected->QueueSubmit(queue, 1, translator.GetSubmitInfos().data(), fence);
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
