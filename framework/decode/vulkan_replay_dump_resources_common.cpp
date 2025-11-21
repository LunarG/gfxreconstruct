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

#include "decode/vulkan_device_address_tracker.h"
#include "decode/vulkan_replay_dump_resources_common.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_object_info_table.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "util/logging.h"
#include "graphics/vulkan_resources_util.h"
#include "util/platform.h"
#include "util/to_string.h"
#include "vulkan/vulkan_core.h"
#include "Vulkan-Utility-Libraries/vk_format_utils.h"

#include <algorithm>
#include <cstddef>
#include <sstream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

ImageDumpResult CanDumpImage(const graphics::VulkanInstanceTable* instance_table,
                             VkPhysicalDevice                     phys_dev,
                             const VulkanImageInfo*               image_info)
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
        if ((image_info->tiling == VK_IMAGE_TILING_OPTIMAL &&
             (format_properties.optimalTilingFeatures & VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT) !=
                 VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT) ||
            (image_info->tiling == VK_IMAGE_TILING_LINEAR &&
             (format_properties.linearTilingFeatures & VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT) !=
                 VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT))
        {
            GFXRECON_LOG_WARNING("Multisampled image with format %s does not support "
                                 "\"VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT\" will not be dumped.",
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

uint32_t GetMemoryTypeIndex(const VkPhysicalDeviceMemoryProperties& memory_properties,
                            uint32_t                                type_bits,
                            VkMemoryPropertyFlags                   property_flags)
{
    uint32_t memory_type_index = std::numeric_limits<uint32_t>::max();

    for (uint32_t i = 0; i < memory_properties.memoryTypeCount; ++i)
    {
        if ((type_bits & (1 << i)) &&
            ((memory_properties.memoryTypes[i].propertyFlags & property_flags) == property_flags))
        {
            memory_type_index = i;
            break;
        }
    }

    return memory_type_index;
}

VkResult CloneImage(CommonObjectInfoTable&                  object_info_table,
                    const graphics::VulkanDeviceTable*      device_table,
                    const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props,
                    const VulkanImageInfo*                  image_info,
                    VkImage*                                new_image,
                    VkDeviceMemory*                         new_image_memory)
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

    assert(device_table);
    assert(new_image);
    VkResult res = device_table->CreateImage(device, &ci, nullptr, new_image);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("CreateImage failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    VkMemoryRequirements mem_reqs       = {};
    VkMemoryAllocateInfo mem_alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO, nullptr };

    device_table->GetImageMemoryRequirements(device, *new_image, &mem_reqs);
    mem_alloc_info.allocationSize = mem_reqs.size;

    assert(replay_device_phys_mem_props);
    uint32_t index =
        GetMemoryTypeIndex(*replay_device_phys_mem_props, mem_reqs.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    if (index == std::numeric_limits<uint32_t>::max())
    {
        GFXRECON_LOG_ERROR("%s failed to find an appropriate memory type", __func__)
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    mem_alloc_info.memoryTypeIndex = index;

    assert(new_image_memory);
    res = device_table->AllocateMemory(device, &mem_alloc_info, nullptr, new_image_memory);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("AllocateMemory failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    res = device_table->BindImageMemory(device, *new_image, *new_image_memory, 0);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("BindImageMemory failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    return VK_SUCCESS;
}

VkResult CloneBuffer(CommonObjectInfoTable&                  object_info_table,
                     const graphics::VulkanDeviceTable*      device_table,
                     const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props,
                     const VulkanBufferInfo*                 buffer_info,
                     VkBuffer*                               new_buffer,
                     VkDeviceMemory*                         new_buffer_memory,
                     VkDeviceSize                            override_size)
{
    assert(device_table);
    assert(new_buffer);
    assert(buffer_info);
    assert(buffer_info->size || override_size);

    VkBufferCreateInfo ci;
    ci.sType                 = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    ci.pNext                 = nullptr;
    ci.flags                 = VkBufferCreateFlags(0);
    ci.size                  = override_size ? override_size : buffer_info->size;
    ci.usage                 = VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
    ci.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    ci.queueFamilyIndexCount = 0;
    ci.pQueueFamilyIndices   = nullptr;

    const VulkanDeviceInfo* device_info = object_info_table.GetVkDeviceInfo(buffer_info->parent_id);
    VkDevice                device      = device_info->handle;

    VkResult res = device_table->CreateBuffer(device, &ci, nullptr, new_buffer);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("CreateBuffer failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    VkMemoryRequirements mem_reqs       = {};
    VkMemoryAllocateInfo mem_alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO, nullptr };

    device_table->GetBufferMemoryRequirements(device, *new_buffer, &mem_reqs);
    mem_alloc_info.allocationSize = mem_reqs.size;

    assert(replay_device_phys_mem_props);
    uint32_t index =
        GetMemoryTypeIndex(*replay_device_phys_mem_props, mem_reqs.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    if (index == std::numeric_limits<uint32_t>::max())
    {
        GFXRECON_LOG_ERROR("%s failed to find an appropriate memory type", __func__)
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    mem_alloc_info.memoryTypeIndex = index;

    assert(new_buffer_memory);
    res = device_table->AllocateMemory(device, &mem_alloc_info, nullptr, new_buffer_memory);

    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("AllocateMemory failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    res = device_table->BindBufferMemory(device, *new_buffer, *new_buffer_memory, 0);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("BindBufferMemory failed with %s", util::ToString<VkResult>(res).c_str());
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

VkResult DumpImage(DumpedImage&                         dumped_image,
                   VkImageLayout                        layout,
                   float                                scale,
                   bool                                 dump_image_raw,
                   const VkImageSubresourceRange&       subresource_range,
                   std::vector<DumpedRawData>&          data,
                   const VulkanDeviceInfo*              device_info,
                   const graphics::VulkanDeviceTable*   device_table,
                   const graphics::VulkanInstanceTable* instance_table,
                   CommonObjectInfoTable&               object_info_table)
{
    GFXRECON_ASSERT(device_info != nullptr);
    GFXRECON_ASSERT(device_table != nullptr);
    GFXRECON_ASSERT(instance_table != nullptr);

    const VulkanImageInfo* image_info = dumped_image.image_info;
    GFXRECON_ASSERT(image_info != nullptr);

    const VulkanPhysicalDeviceInfo* phys_dev_info = object_info_table.GetVkPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    graphics::VulkanResourcesUtil resource_util(device_info->handle,
                                                device_info->parent,
                                                *device_table,
                                                *instance_table,
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
    const bool scaling_supported = resource_util.IsScalingSupported(
        image_info->format, image_info->tiling, dst_format, image_info->type, image_info->extent, scale);

    dumped_image.scaling_failed = (scale != 1.0f && !scaling_supported);
    dumped_image.dumped_format  = dst_format;

    const VkImageSubresourceRange modified_subresource_range =
        FilterImageSubresourceRange(subresource_range, image_info);

    std::vector<VkImageAspectFlagBits> aspects;
    graphics::AspectFlagsToFlagBits(modified_subresource_range.aspectMask, aspects);

    const uint32_t total_subresources = static_cast<uint32_t>(aspects.size()) *
                                        (modified_subresource_range.layerCount * modified_subresource_range.levelCount);

    data.resize(total_subresources);

    // data will hold dumped data for all aspects and sub resources, total_subresources in total.
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
        image_resource.queue_family_index   = image_info->queue_family_index;
        image_resource.external_format      = image_info->external_format;
        image_resource.size                 = image_info->size;
        image_resource.level_sizes          = &subresource_sizes;
        image_resource.aspect               = aspect;
        image_resource.scale                = scale;
        image_resource.dst_format           = dst_format;
        image_resource.all_layers_per_level = false;

        const VkExtent3D scaled_extent =
            (scale != 1.0f && scaling_supported) ? ScaleExtent(image_info->extent, scale) : image_info->extent;

        image_resource.resource_size =
            resource_util.GetImageResourceSizesOptimal(dst_format,
                                                       image_info->type,
                                                       scaling_supported ? scaled_extent : image_info->extent,
                                                       image_info->level_count,
                                                       image_info->layer_count,
                                                       image_info->tiling,
                                                       aspect,
                                                       &subresource_offsets,
                                                       &subresource_sizes,
                                                       false);

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

        DumpedRawData raw_data;
        VkResult      result = resource_util.ReadImageResource(image_resource, raw_data);

        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_WARNING("Reading from image resource %" PRIu64 " failed (%s)",
                                 image_info->capture_id,
                                 util::ToString<VkResult>(result).c_str())
            return result;
        }

        for (uint32_t mip = modified_subresource_range.baseMipLevel;
             mip < modified_subresource_range.baseMipLevel + modified_subresource_range.levelCount;
             ++mip)
        {
            for (uint32_t layer = modified_subresource_range.baseArrayLayer;
                 layer < modified_subresource_range.baseArrayLayer + modified_subresource_range.layerCount;
                 ++layer)
            {
                const VkExtent3D subresource_extent        = ScaleToMipLevel(image_info->extent, mip);
                const VkExtent3D subresource_scaled_extent = ScaleToMipLevel(scaled_extent, mip);

                dumped_image.dumped_subresources.emplace_back(
                    aspect, subresource_extent, subresource_scaled_extent, mip, layer);

                const uint32_t sub_res_idx = mip * image_info->layer_count + layer;
                const void*    offsetted_data =
                    reinterpret_cast<const void*>(raw_data.data() + subresource_offsets[sub_res_idx]);

                data[data_index].resize(subresource_sizes[sub_res_idx]);
                util::platform::MemoryCopy(data[data_index].data(),
                                           subresource_sizes[sub_res_idx],
                                           offsetted_data,
                                           subresource_sizes[sub_res_idx]);
                ++data_index;
            }
        }
    }

    GFXRECON_ASSERT(data_index == total_subresources);

    return VK_SUCCESS;
}

VkResult DumpBuffer(const DumpedBuffer&                  dumped_buffer,
                    DumpedRawData&                       data,
                    const VulkanDeviceInfo*              device_info,
                    const graphics::VulkanDeviceTable*   device_table,
                    const graphics::VulkanInstanceTable* instance_table,
                    CommonObjectInfoTable&               object_info_table)
{
    GFXRECON_ASSERT(device_info != nullptr);
    GFXRECON_ASSERT(device_table != nullptr);
    GFXRECON_ASSERT(instance_table != nullptr);

    const VulkanPhysicalDeviceInfo* phys_dev_info = object_info_table.GetVkPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    graphics::VulkanResourcesUtil resource_util(device_info->handle,
                                                device_info->parent,
                                                *device_table,
                                                *instance_table,
                                                *phys_dev_info->replay_device_info->memory_properties);

    const VulkanBufferInfo* buffer_info = dumped_buffer.buffer_info;
    GFXRECON_ASSERT(buffer_info != nullptr);

    GFXRECON_ASSERT(dumped_buffer.size);
    GFXRECON_ASSERT(dumped_buffer.size != VK_WHOLE_SIZE);
    GFXRECON_ASSERT(dumped_buffer.offset != VK_WHOLE_SIZE);

    const uint32_t transfer_queue_index = FindTransferQueueFamilyIndex(device_info->enabled_queue_family_flags);
    if (transfer_queue_index == VK_QUEUE_FAMILY_IGNORED)
    {
        GFXRECON_LOG_ERROR("Failed to find a transfer queue")
        return VK_ERROR_UNKNOWN;
    }

    VkResult res = resource_util.ReadFromBufferResource(
        buffer_info->handle, dumped_buffer.size, dumped_buffer.offset, transfer_queue_index, data);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_WARNING("Failed reading from buffer %" PRIu64, buffer_info->parent_id);
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

VkResult CreateVkBuffer(VkDeviceSize                            size,
                        const graphics::VulkanDeviceTable&      device_table,
                        VkDevice                                parent_device,
                        const VkBaseInStructure*                buffer_create_info_pNext,
                        const VkBaseInStructure*                allocate_memory_info_pNext,
                        const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props,
                        VkBufferUsageFlags                      usage_flags,
                        VkBuffer*                               new_buffer,
                        VkDeviceMemory*                         new_memory)
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

    VkResult res = device_table.CreateBuffer(parent_device, &bci, nullptr, new_buffer);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s(): CreateBuffer failed with: %s", __func__, util::ToString<VkResult>(res).c_str());
        return res;
    }

    VkMemoryRequirements mem_reqs       = {};
    VkMemoryAllocateInfo mem_alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO, allocate_memory_info_pNext };

    device_table.GetBufferMemoryRequirements(parent_device, *new_buffer, &mem_reqs);
    mem_alloc_info.allocationSize = mem_reqs.size;

    uint32_t mem_index =
        GetMemoryTypeIndex(*replay_device_phys_mem_props, mem_reqs.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
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

    res = device_table.AllocateMemory(parent_device, &mem_alloc_info, nullptr, new_memory);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s(): AllocateMemory failed with %s", __func__, util::ToString<VkResult>(res).c_str());
        return res;
    }

    res = device_table.BindBufferMemory(parent_device, *new_buffer, *new_memory, 0);
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

std::vector<VkPipelineBindPoint> ShaderStageFlagsToPipelineBindPoints(VkShaderStageFlags flags)
{
    std::vector<VkPipelineBindPoint> bind_points;

    constexpr VkShaderStageFlags gr_flags =
        VK_SHADER_STAGE_ALL_GRAPHICS | VK_SHADER_STAGE_TASK_BIT_EXT | VK_SHADER_STAGE_MESH_BIT_EXT;
    constexpr VkShaderStageFlags com_flags = VK_SHADER_STAGE_COMPUTE_BIT;
    constexpr VkShaderStageFlags rt_flags  = VK_SHADER_STAGE_RAYGEN_BIT_KHR | VK_SHADER_STAGE_ANY_HIT_BIT_KHR |
                                            VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR | VK_SHADER_STAGE_MISS_BIT_KHR |
                                            VK_SHADER_STAGE_INTERSECTION_BIT_KHR | VK_SHADER_STAGE_CALLABLE_BIT_KHR;

    if (flags & gr_flags)
    {
        bind_points.push_back(VK_PIPELINE_BIND_POINT_GRAPHICS);
    }

    if (flags & com_flags)
    {
        bind_points.push_back(VK_PIPELINE_BIND_POINT_COMPUTE);
    }

    if (flags & rt_flags)
    {
        bind_points.push_back(VK_PIPELINE_BIND_POINT_RAY_TRACING_KHR);
    }

    return bind_points;
}

uint32_t FindTransferQueueFamilyIndex(const VulkanDeviceInfo::EnabledQueueFamilyFlags& families)
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
                    // Apparently some implementations (i.e. Adreno) don't have a transfer queue. According to spec,
                    // graphics and compute queues also support transfer operations.
                    index = i;
                }
            }
        }
    }

    return index;
}

bool CullDescriptor(CommandImageSubresourceIterator cmd_subresources_entry,
                    uint32_t                        desc_set,
                    uint32_t                        binding,
                    uint32_t                        array_index,
                    VkImageSubresourceRange*        subresource_range)
{
    const DescriptorLocation desc_loc                = DescriptorLocation{ desc_set, binding, array_index };
    const auto               image_subresource_entry = cmd_subresources_entry->second.find(desc_loc);
    if (image_subresource_entry == cmd_subresources_entry->second.end())
    {
        return true;
    }

    if (subresource_range != nullptr)
    {
        *subresource_range = image_subresource_entry->second;
    }

    return false;
}

uint32_t FindComputeQueueFamilyIndex(const VulkanDeviceInfo::EnabledQueueFamilyFlags& families)
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

VkResult
SerializeAccelerationStructures(const std::vector<AccelerationStructureDumpResourcesContext*>& acceleration_structures,
                                const VulkanDeviceInfo*                                        device_info,
                                const graphics::VulkanDeviceTable&                             device_table,
                                const VulkanObjectInfoTable&                                   object_info_table_)
{
    const uint32_t query_count = static_cast<uint32_t>(acceleration_structures.size());
    if (!query_count)
    {
        return VK_SUCCESS;
    }

    const VulkanPhysicalDeviceInfo* phys_dev_info = object_info_table_.GetVkPhysicalDeviceInfo(device_info->parent_id);
    GFXRECON_ASSERT(phys_dev_info != nullptr);

    const VkPhysicalDeviceMemoryProperties& mem_props = phys_dev_info->replay_device_info->memory_properties.value();

    const VkQueryPoolCreateInfo qci = {
        VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO, nullptr,
        VK_QUERY_POOL_CREATE_RESET_BIT_KHR,       VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SERIALIZATION_SIZE_KHR,
        static_cast<uint32_t>(query_count),       VkQueryPipelineStatisticFlags(0)
    };

    const VkDevice device = device_info->handle;
    VkQueryPool    query_pool;
    VkResult       res = device_table.CreateQueryPool(device, &qci, nullptr, &query_pool);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s: CreateQueryPool failed (%s)", __func__, util::ToString(res).c_str())
        return res;
    }

    const uint32_t compute_queue_family_index = FindComputeQueueFamilyIndex(device_info->enabled_queue_family_flags);
    if (compute_queue_family_index == VK_QUEUE_FAMILY_IGNORED)
    {
        GFXRECON_LOG_ERROR("%s: Failed to find a compute queue family index", __func__)
        return VK_ERROR_UNKNOWN;
    }

    const VkCommandPoolCreateInfo cpci = { VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO,
                                           nullptr,
                                           VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT,
                                           compute_queue_family_index };
    VkCommandPool                 cmd_pool;
    res = device_table.CreateCommandPool(device, &cpci, nullptr, &cmd_pool);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("(%s) CreateCommandPool failed (%s)", __func__, util::ToString(res).c_str());
        return res;
    }

    const VkCommandBufferAllocateInfo cbai = {
        VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO, nullptr, cmd_pool, VK_COMMAND_BUFFER_LEVEL_PRIMARY, 1
    };
    VkCommandBuffer cmd_buffer;
    res = device_table.AllocateCommandBuffers(device, &cbai, &cmd_buffer);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("(%s) AllocateCommandBuffers failed (%s)", __func__, util::ToString(res).c_str());
        return res;
    }

    res = device_table.ResetCommandBuffer(cmd_buffer, 0);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s: ResetCommandBuffer failed (%s)", __func__, util::ToString(res).c_str())
        return res;
    }

    const VkCommandBufferBeginInfo cbbi = {
        VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO, nullptr, VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT, nullptr
    };
    res = device_table.BeginCommandBuffer(cmd_buffer, &cbbi);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s: BeginCommandBuffer failed (%s)", __func__, util::ToString(res).c_str())
        return res;
    }

    const VkMemoryBarrier mem_barrier = { VK_STRUCTURE_TYPE_MEMORY_BARRIER,
                                          nullptr,
                                          VK_ACCESS_ACCELERATION_STRUCTURE_WRITE_BIT_KHR | VK_ACCESS_TRANSFER_WRITE_BIT,
                                          VK_ACCESS_ACCELERATION_STRUCTURE_READ_BIT_KHR | VK_ACCESS_TRANSFER_READ_BIT };

    device_table.CmdPipelineBarrier(
        cmd_buffer,
        VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR | VK_PIPELINE_STAGE_TRANSFER_BIT,
        VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR | VK_PIPELINE_STAGE_TRANSFER_BIT,
        VkDependencyFlagBits(0),
        1,
        &mem_barrier,
        0,
        nullptr,
        0,
        nullptr);

    for (uint32_t i = 0; i < query_count; ++i)
    {
        const VkBufferMemoryBarrier as_buf_mem_barrier = {
            VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
            nullptr,
            VK_ACCESS_ACCELERATION_STRUCTURE_WRITE_BIT_KHR | VK_ACCESS_TRANSFER_WRITE_BIT,
            VK_ACCESS_ACCELERATION_STRUCTURE_READ_BIT_KHR | VK_ACCESS_TRANSFER_READ_BIT,
            VK_QUEUE_FAMILY_IGNORED,
            VK_QUEUE_FAMILY_IGNORED,
            acceleration_structures[i]->as_info->buffer,
            0,
            VK_WHOLE_SIZE
        };
        device_table.CmdPipelineBarrier(
            cmd_buffer,
            VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR | VK_PIPELINE_STAGE_TRANSFER_BIT,
            VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR | VK_PIPELINE_STAGE_TRANSFER_BIT,
            VkDependencyFlagBits(0),
            0,
            nullptr,
            1,
            &as_buf_mem_barrier,
            0,
            nullptr);

        GFXRECON_ASSERT(acceleration_structures[i]->as_info != nullptr);
        device_table.CmdWriteAccelerationStructuresPropertiesKHR(
            cmd_buffer,
            1,
            &acceleration_structures[i]->as_info->handle,
            VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SERIALIZATION_SIZE_KHR,
            query_pool,
            static_cast<uint32_t>(i));
    }

    device_table.EndCommandBuffer(cmd_buffer);

    VkQueue compute_queue = VK_NULL_HANDLE;
    device_table.GetDeviceQueue(device, compute_queue_family_index, 0, &compute_queue);
    if (compute_queue == VK_NULL_HANDLE)
    {
        GFXRECON_LOG_ERROR("%s: GetDeviceQueue failed to get family index %u", __func__, compute_queue_family_index)
        return VK_ERROR_UNKNOWN;
    }

    const VkFenceCreateInfo fci = { VK_STRUCTURE_TYPE_FENCE_CREATE_INFO, nullptr, 0 };
    VkFence                 fence;
    res = device_table.CreateFence(device, &fci, nullptr, &fence);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s: CreateFence failed (%s)", __func__, util::ToString(res).c_str())
        return res;
    }

    res = device_table.ResetFences(device, 1, &fence);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s: ResetFences failed (%s)", __func__, util::ToString(res).c_str())
        return res;
    }

    const VkSubmitInfo si = { VK_STRUCTURE_TYPE_SUBMIT_INFO, nullptr, 0, nullptr, nullptr, 1, &cmd_buffer, 0, nullptr };
    res                   = device_table.QueueSubmit(compute_queue, 1, &si, fence);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s: QueueSubmit failed (%s)", __func__, util::ToString(res).c_str())
        return res;
    }

    // Wait a sensible amount of time (10 seconds) in case we did something that can cause the GPU to hang or crash.
    res = device_table.WaitForFences(device, 1, &fence, VK_TRUE, 10000000000);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s: WaitForFences failed (%s)", __func__, util::ToString(res).c_str())
        return res;
    }

    // Read query results
    std::vector<VkDeviceSize> query_results(query_count);
    res = device_table.GetQueryPoolResults(device,
                                           query_pool,
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

    res = device_table.ResetCommandBuffer(cmd_buffer, 0);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s: ResetCommandBuffer (2) failed (%s)", __func__, util::ToString(res).c_str())
        return res;
    }

    res = device_table.BeginCommandBuffer(cmd_buffer, &cbbi);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s: BeginCommandBuffer (2) failed (%s)", __func__, util::ToString(res).c_str())
        return res;
    }

    for (uint32_t i = 0; i < query_count; ++i)
    {
        const VkDeviceSize serialized_size               = query_results[i];
        acceleration_structures[i]->serialized_data.size = serialized_size;

        if (!serialized_size)
        {
            continue;
        }

        res = CreateVkBuffer(serialized_size,
                             device_table,
                             device,
                             nullptr,
                             nullptr,
                             &mem_props,
                             VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT |
                                 VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT,
                             &acceleration_structures[i]->serialized_data.buffer,
                             &acceleration_structures[i]->serialized_data.memory);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("%s: CreateBuffer failed (%s)", __func__, util::ToString(res).c_str())
            return res;
        }

        const VkBufferDeviceAddressInfo bdai = { VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO,
                                                 nullptr,
                                                 acceleration_structures[i]->serialized_data.buffer };

        VkDeviceOrHostAddressKHR device_address;
        device_address.deviceAddress = device_table.GetBufferDeviceAddressKHR(device, &bdai);

        GFXRECON_ASSERT(acceleration_structures[i]->as_info != VK_NULL_HANDLE);
        const VkCopyAccelerationStructureToMemoryInfoKHR castmi = {
            VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR,
            nullptr,
            acceleration_structures[i]->as_info->handle,
            device_address,
            VK_COPY_ACCELERATION_STRUCTURE_MODE_SERIALIZE_KHR
        };
        device_table.CmdCopyAccelerationStructureToMemoryKHR(cmd_buffer, &castmi);

        const VkBufferMemoryBarrier buf_barrier = { VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
                                                    nullptr,
                                                    VK_ACCESS_TRANSFER_WRITE_BIT,
                                                    VK_ACCESS_TRANSFER_READ_BIT,
                                                    VK_QUEUE_FAMILY_IGNORED,
                                                    VK_QUEUE_FAMILY_IGNORED,
                                                    acceleration_structures[i]->serialized_data.buffer,
                                                    0,
                                                    serialized_size };

        device_table.CmdPipelineBarrier(cmd_buffer,
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

    device_table.EndCommandBuffer(cmd_buffer);

    res = device_table.ResetFences(device, 1, &fence);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s: ResetFences failed (%s)", __func__, util::ToString(res).c_str())
        return res;
    }

    res = device_table.QueueSubmit(compute_queue, 1, &si, fence);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s: QueueSubmit (2) failed (%s)", __func__, util::ToString(res).c_str())
        return res;
    }

    // Wait a sensible amount of time (10 seconds) in case we did something that can cause the GPU to hang or crash.
    res = device_table.WaitForFences(device, 1, &fence, VK_TRUE, 10000000000);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s: WaitForFences (2) failed (%s)", __func__, util::ToString(res).c_str())
        return res;
    }

    return VK_SUCCESS;
}

void AccelerationStructureDumpResourcesContext::ReleaseResources()
{
    if (as_info == nullptr)
    {
        return;
    }

    const VulkanDeviceInfo* device_info = object_info_table.GetVkDeviceInfo(as_info->parent_id);
    GFXRECON_ASSERT(device_info != nullptr);

    const VkDevice device = device_info->handle;

    as_info = nullptr;

    if (serialized_data.buffer != VK_NULL_HANDLE)
    {
        device_table.DestroyBuffer(device, serialized_data.buffer, nullptr);
        serialized_data.buffer = VK_NULL_HANDLE;
    }

    if (serialized_data.memory != VK_NULL_HANDLE)
    {
        device_table.FreeMemory(device, serialized_data.memory, nullptr);
        serialized_data.memory = VK_NULL_HANDLE;
    }

    serialized_data.size = 0;

    for (auto& as_data : as_build_data)
    {
        if (auto* triangles = std::get_if<AccelerationStructureDumpResourcesContext::Triangles>(&as_data))
        {
            triangles->vertex_format      = VK_FORMAT_UNDEFINED;
            triangles->vertex_buffer_size = 0;

            if (triangles->vertex_buffer != VK_NULL_HANDLE)
            {
                device_table.DestroyBuffer(device, triangles->vertex_buffer, nullptr);
                triangles->vertex_buffer = VK_NULL_HANDLE;
            }

            if (triangles->vertex_buffer_memory != VK_NULL_HANDLE)
            {
                device_table.FreeMemory(device, triangles->vertex_buffer_memory, nullptr);
                triangles->vertex_buffer_memory = VK_NULL_HANDLE;
            }

            triangles->index_type        = VK_INDEX_TYPE_NONE_KHR;
            triangles->index_buffer_size = 0;

            if (triangles->index_buffer != VK_NULL_HANDLE)
            {
                device_table.DestroyBuffer(device, triangles->index_buffer, nullptr);
                triangles->index_buffer = VK_NULL_HANDLE;
            }

            if (triangles->index_buffer_memory != VK_NULL_HANDLE)
            {
                device_table.FreeMemory(device, triangles->index_buffer_memory, nullptr);
                triangles->index_buffer_memory = VK_NULL_HANDLE;
            }

            if (triangles->transform_buffer != VK_NULL_HANDLE)
            {
                device_table.DestroyBuffer(device, triangles->transform_buffer, nullptr);
                triangles->transform_buffer = VK_NULL_HANDLE;
            }

            if (triangles->transform_buffer_memory != VK_NULL_HANDLE)
            {
                device_table.FreeMemory(device, triangles->transform_buffer_memory, nullptr);
                triangles->transform_buffer_memory = VK_NULL_HANDLE;
            }
        }
        else if (auto* instance = std::get_if<AccelerationStructureDumpResourcesContext::Instances>(&as_data))
        {
            instance->instance_count       = 0;
            instance->instance_buffer_size = 0;

            if (instance->instance_buffer != VK_NULL_HANDLE)
            {
                device_table.DestroyBuffer(device, instance->instance_buffer, nullptr);
                instance->instance_buffer = VK_NULL_HANDLE;
            }

            if (instance->instance_buffer_memory != VK_NULL_HANDLE)
            {
                device_table.FreeMemory(device, instance->instance_buffer_memory, nullptr);
                instance->instance_buffer_memory = VK_NULL_HANDLE;
            }

            if (instance->compute_ppl != VK_NULL_HANDLE)
            {
                device_table.DestroyPipeline(device, instance->compute_ppl, nullptr);
                instance->compute_ppl = VK_NULL_HANDLE;
            }

            if (instance->compute_ppl_layout != VK_NULL_HANDLE)
            {
                device_table.DestroyPipelineLayout(device, instance->compute_ppl_layout, nullptr);
                instance->compute_ppl_layout = VK_NULL_HANDLE;
            }
        }
        else if (auto* aabb = std::get_if<AccelerationStructureDumpResourcesContext::AABBS>(&as_data))
        {
            aabb->buffer_size = 0;

            if (aabb->buffer != VK_NULL_HANDLE)
            {
                device_table.DestroyBuffer(device, aabb->buffer, nullptr);
                aabb->buffer = VK_NULL_HANDLE;
            }

            if (aabb->buffer_memory != VK_NULL_HANDLE)
            {
                device_table.FreeMemory(device, aabb->buffer_memory, nullptr);
                aabb->buffer_memory = VK_NULL_HANDLE;
            }
        }
        else
        {
            GFXRECON_LOG_ERROR("Unexpected as data entry");
            GFXRECON_ASSERT(0);
        }
    }

    as_build_data.clear();
}

VkResult DumpTopLevelAccelerationStructure(DumpedTopLevelAccelerationStructure&        dumped_tlas,
                                           TLASDumpedHostData&                         dumped_tlas_data,
                                           DumpResourcesAccelerationStructuresContext& acceleration_structures_context,
                                           const VulkanDeviceInfo*                     device_info,
                                           const graphics::VulkanDeviceTable&          device_table,
                                           const VulkanObjectInfoTable&                object_info_table,
                                           const graphics::VulkanInstanceTable&        instance_table,
                                           const VulkanPerDeviceAddressTrackers&       address_trackers)
{
    const VulkanPhysicalDeviceInfo* phys_dev_info = object_info_table.GetVkPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    const auto address_tracker_entry = address_trackers.find(device_info);
    if (address_tracker_entry == address_trackers.end())
    {
        GFXRECON_LOG_WARNING("Could not detect address tracker for device %" PRIu64, device_info->capture_id);
        return VK_SUCCESS;
    }

    const VulkanDeviceAddressTracker& device_address_tracker = address_tracker_entry->second;

    graphics::VulkanResourcesUtil resource_util(device_info->handle,
                                                device_info->parent,
                                                device_table,
                                                instance_table,
                                                *phys_dev_info->replay_device_info->memory_properties);

    const uint32_t transfer_queue_index = FindTransferQueueFamilyIndex(device_info->enabled_queue_family_flags);
    if (transfer_queue_index == VK_QUEUE_FAMILY_IGNORED)
    {
        GFXRECON_LOG_ERROR("Failed to find a transfer queue")
        return VK_ERROR_UNKNOWN;
    }

    const VulkanAccelerationStructureKHRInfo* tlas_info = dumped_tlas.as_info;
    GFXRECON_ASSERT(tlas_info != nullptr);

    auto tlas_context_entry = acceleration_structures_context.find(tlas_info);
    GFXRECON_ASSERT(tlas_context_entry != acceleration_structures_context.end());
    AccelerationStructureDumpResourcesContext* tlas_context = tlas_context_entry->second.get();

    std::vector<AccelerationStructureDumpResourcesContext*> referenced_ases;
    for (const auto& tlas_build_data : tlas_context->as_build_data)
    {
        GFXRECON_ASSERT(
            (std::get_if<AccelerationStructureDumpResourcesContext::Triangles>(&tlas_build_data) == nullptr) &&
            (std::get_if<AccelerationStructureDumpResourcesContext::AABBS>(&tlas_build_data) == nullptr));

        const auto* instance_build_data =
            std::get_if<AccelerationStructureDumpResourcesContext::Instances>(&tlas_build_data);
        GFXRECON_ASSERT(instance_build_data != nullptr);

        dumped_tlas.instance_data.emplace_back(
            DumpedBuffer(static_cast<VkDeviceSize>(instance_build_data->instance_buffer_size)));

        auto& new_dumped_instance_data = dumped_tlas_data.instance_data.emplace_back(TLASDumpedHostData::Instances());

        // Fetch instance data
        VkResult res =
            resource_util.ReadFromBufferResource(instance_build_data->instance_buffer,
                                                 static_cast<uint64_t>(instance_build_data->instance_buffer_size),
                                                 0,
                                                 transfer_queue_index,
                                                 new_dumped_instance_data.instance_buffer);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_WARNING("Error dumping input instance buffer for TLAS %" PRIu64 " (%s)",
                                 tlas_info->capture_id,
                                 util::ToString(res).c_str());
            return res;
        }

        // Parse instance buffer and extract referenced BLASes
        const VkAccelerationStructureInstanceKHR* instances =
            reinterpret_cast<const VkAccelerationStructureInstanceKHR*>(
                new_dumped_instance_data.instance_buffer.data());
        for (uint32_t i = 0; i < instance_build_data->instance_count; ++i)
        {
            const auto blases_infos = device_address_tracker.GetAccelerationStructuresByCaptureDeviceAddress(
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
                // (vkCmdBuildAccelerationStructuresIndirectKHR has not been called for the VkAccelerationStructureKHR).
                // This works as that BLAS can alias the memory of another BLAS which has been properly built.
                if (blas_context_entry != acceleration_structures_context.end())
                {
                    referenced_ases.push_back(blas_context_entry->second.get());
                    break;
                }
            }
        }
    }

    for (const auto blas : referenced_ases)
    {
        GFXRECON_ASSERT(blas->as_info != nullptr);
        auto& new_dumped_blass      = dumped_tlas.blass.emplace_back(blas->as_info);
        auto& new_dumped_blass_data = dumped_tlas_data.blass_dumped_data.emplace_back(BLASDumpedHostData());
        for (const auto& build_data : blas->as_build_data)
        {
            if (auto* triangles = std::get_if<AccelerationStructureDumpResourcesContext::Triangles>(&build_data))
            {
                new_dumped_blass.input_data.emplace_back(
                    std::in_place_type<DumpedBottomLevelAccelerationStructure::DumpedBuildInputDataTriangles>,
                    triangles->vertex_format,
                    triangles->max_vertex,
                    triangles->vertex_buffer_size,
                    triangles->vertex_buffer_stride,
                    triangles->index_type,
                    triangles->index_buffer_size,
                    triangles->transform_buffer_size,
                    triangles->range);

                auto& new_dumped_triangles_data_variant =
                    new_dumped_blass_data.build_data.emplace_back(std::in_place_type<BLASDumpedHostData::Triangles>);
                auto& new_dumped_triangles_data =
                    std::get<BLASDumpedHostData::Triangles>(new_dumped_triangles_data_variant);

                GFXRECON_ASSERT(triangles->vertex_buffer != VK_NULL_HANDLE);
                VkResult res =
                    resource_util.ReadFromBufferResource(triangles->vertex_buffer,
                                                         static_cast<uint64_t>(triangles->vertex_buffer_size),
                                                         0,
                                                         transfer_queue_index,
                                                         new_dumped_triangles_data.vertex_buffer);
                if (res != VK_SUCCESS)
                {
                    GFXRECON_LOG_WARNING("Error dumping input vertex buffer for BLAS %" PRIu64 " (%s)",
                                         blas->as_info->capture_id,
                                         util::ToString(res).c_str());
                    return res;
                }

                if (triangles->index_type != VK_INDEX_TYPE_NONE_KHR)
                {
                    GFXRECON_ASSERT(triangles->index_buffer != VK_NULL_HANDLE);
                    res = resource_util.ReadFromBufferResource(triangles->index_buffer,
                                                               static_cast<uint64_t>(triangles->index_buffer_size),
                                                               0,
                                                               transfer_queue_index,
                                                               new_dumped_triangles_data.index_buffer);
                    if (res != VK_SUCCESS)
                    {
                        GFXRECON_LOG_WARNING("Error dumping input index buffer for BLAS %" PRIu64 " (%s)",
                                             blas->as_info->capture_id,
                                             util::ToString(res).c_str());
                        return res;
                    }
                }

                if (triangles->transform_buffer != VK_NULL_HANDLE)
                {
                    res = resource_util.ReadFromBufferResource(triangles->transform_buffer,
                                                               static_cast<uint64_t>(sizeof(VkTransformMatrixKHR)),
                                                               0,
                                                               transfer_queue_index,
                                                               new_dumped_triangles_data.transform_buffer);
                    if (res != VK_SUCCESS)
                    {
                        GFXRECON_LOG_WARNING("Error dumping transform buffer for BLAS %" PRIu64 " (%s)",
                                             blas->as_info->capture_id,
                                             util::ToString(res).c_str());
                        return res;
                    }
                }
            }
            else if (auto* aabbs = std::get_if<AccelerationStructureDumpResourcesContext::AABBS>(&build_data))
            {
                GFXRECON_ASSERT(aabbs->buffer != VK_NULL_HANDLE);
                new_dumped_blass.input_data.emplace_back(
                    std::in_place_type<DumpedBottomLevelAccelerationStructure::DumpedBuildInputDataAABB>,
                    aabbs->buffer_size,
                    aabbs->range);

                auto& new_dumped_aabb_data_variant =
                    new_dumped_blass_data.build_data.emplace_back(std::in_place_type<BLASDumpedHostData::AABBS>);
                auto& new_dumped_aabb_data = std::get<BLASDumpedHostData::AABBS>(new_dumped_aabb_data_variant);

                VkResult res = resource_util.ReadFromBufferResource(aabbs->buffer,
                                                                    static_cast<uint64_t>(aabbs->buffer_size),
                                                                    0,
                                                                    transfer_queue_index,
                                                                    new_dumped_aabb_data.aabb_buffer);
                if (res != VK_SUCCESS)
                {
                    GFXRECON_LOG_WARNING("Error dumping input AABB buffer for BLAS %" PRIu64 " (%s)",
                                         blas->as_info->capture_id,
                                         util::ToString(res).c_str());
                    return res;
                }
            }
            else
            {
                GFXRECON_LOG_WARNING("Unexpected build data")
            }
        }
    }

    // Serialize TLAS + BLASes
    referenced_ases.push_back(tlas_context);
    VkResult res = SerializeAccelerationStructures(referenced_ases, device_info, device_table, object_info_table);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_WARNING("Error serializing acceleration structures for TLAS %" PRIu64 " (%s)",
                             tlas_info->capture_id,
                             util::ToString(res).c_str());
        return res;
    }

    // Fetch serialized data for TLAS
    if (tlas_context->serialized_data.buffer != VK_NULL_HANDLE)
    {
        dumped_tlas.serialized_data.size = tlas_context->serialized_data.size;
        res                              = resource_util.ReadFromBufferResource(tlas_context->serialized_data.buffer,
                                                   static_cast<uint64_t>(tlas_context->serialized_data.size),
                                                   0,
                                                   transfer_queue_index,
                                                   dumped_tlas_data.serialized_data);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_WARNING("Error dumping fetching serialized data for TLAS %" PRIu64 " (%s)",
                                 tlas_info->capture_id,
                                 util::ToString(res).c_str());
            return res;
        }
    }

    // Fetch serialized data for referenced BLASes. Last one is the TLAS hence the -1 in the loop
    for (size_t i = 0; i < referenced_ases.size() - 1; ++i)
    {
        dumped_tlas.blass[i].serialized_data.size = referenced_ases[i]->serialized_data.size;

        if (referenced_ases[i]->serialized_data.buffer != VK_NULL_HANDLE)
        {
            res = resource_util.ReadFromBufferResource(referenced_ases[i]->serialized_data.buffer,
                                                       static_cast<uint64_t>(referenced_ases[i]->serialized_data.size),
                                                       0,
                                                       transfer_queue_index,
                                                       dumped_tlas_data.blass_dumped_data[i].serialized_data);
            if (res != VK_SUCCESS)
            {
                GFXRECON_LOG_WARNING("Error dumping fetching serialized data from BLAS %" PRIu64 " (%s)",
                                     referenced_ases[i]->as_info->capture_id,
                                     util::ToString(res).c_str());
                return res;
            }
        }
    }

    return VK_SUCCESS;
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
