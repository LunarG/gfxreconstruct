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

#include "decode/vulkan_replay_dump_resources_common.h"
#include "util/logging.h"
#include "util/image_writer.h"
#include "util/buffer_writer.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "graphics/vulkan_resources_util.h"
#include "vulkan/vulkan_core.h"
#include "Vulkan-Utility-Libraries/vk_format_utils.h"

#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

PipelineBindPoints VkPipelineBindPointToPipelineBindPoint(VkPipelineBindPoint bind_point)
{
    switch (bind_point)
    {
        case VK_PIPELINE_BIND_POINT_GRAPHICS:
            return kBindPoint_graphics;

        case VK_PIPELINE_BIND_POINT_COMPUTE:
            return kBindPoint_compute;

        case VK_PIPELINE_BIND_POINT_RAY_TRACING_KHR:
            return kBindPoint_ray_tracing;

        default:
            GFXRECON_LOG_ERROR("Unrecognized pipeline bind point (%d)", bind_point);
            assert(0);
            return kBindPoint_count;
    }
}

bool IsFormatAstcCompressed(VkFormat format)
{
    return vkuFormatIsCompressed_ASTC_HDR(format) || vkuFormatIsCompressed_ASTC_LDR(format);
}

util::imagewriter::DataFormats VkFormatToImageWriterDataFormat(VkFormat format)
{
    if (IsFormatAstcCompressed(format))
    {
        return util::imagewriter::DataFormats::kFormat_ASTC;
    }

    switch (format)
    {
        case VK_FORMAT_R8_UNORM:
            return util::imagewriter::DataFormats::kFormat_R8;

        case VK_FORMAT_R8G8B8_UNORM:
            return util::imagewriter::DataFormats::kFormat_RGB;

        case VK_FORMAT_R8G8B8A8_SRGB:
        case VK_FORMAT_R8G8B8A8_UNORM:
            return util::imagewriter::DataFormats::kFormat_RGBA;

        case VK_FORMAT_B8G8R8_UNORM:
            return util::imagewriter::DataFormats::kFormat_BGR;

        case VK_FORMAT_R16G16B16A16_SFLOAT:
            return util::imagewriter::DataFormats::kFormat_R16G16B16A16_SFLOAT;

        case VK_FORMAT_B10G11R11_UFLOAT_PACK32:
            return util::imagewriter::DataFormats::kFormat_B10G11R11_UFLOAT;

        case VK_FORMAT_B8G8R8A8_SRGB:
        case VK_FORMAT_B8G8R8A8_UNORM:
            return util::imagewriter::DataFormats::kFormat_BGRA;

        case VK_FORMAT_A2B10G10R10_UNORM_PACK32:
            return util::imagewriter::DataFormats::kFormat_A2B10G10R10;

        case VK_FORMAT_D32_SFLOAT:
        case VK_FORMAT_D32_SFLOAT_S8_UINT:
            return util::imagewriter::DataFormats::kFormat_D32_FLOAT;

        case VK_FORMAT_X8_D24_UNORM_PACK32:
            return util::imagewriter::DataFormats::kFormat_D24_UNORM;

        case VK_FORMAT_D16_UNORM:
            return util::imagewriter::DataFormats::kFormat_D16_UNORM;

        default:
            return util::imagewriter::DataFormats::kFormat_UNSPECIFIED;
    }
}

const char* ImageFileExtension(VkFormat format, util::ScreenshotFormat image_file_format)
{
    const util::imagewriter::DataFormats output_image_format = VkFormatToImageWriterDataFormat(format);

    if (output_image_format != util::imagewriter::DataFormats::kFormat_UNSPECIFIED)
    {
        if (output_image_format == util::imagewriter::DataFormats::kFormat_ASTC)
        {
            return ".astc";
        }
        else
        {
            switch (image_file_format)
            {
                case util::ScreenshotFormat::kBmp:
                    return ".bmp";

                case util::ScreenshotFormat::kPng:
                    return ".png";

                default:
                    assert(0);
                    return ".bmp";
            }
        }
    }
    else
    {
        return ".bin";
    }
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
                    const encode::VulkanDeviceTable*        device_table,
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
    ci.usage                 = image_info->usage | VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
    ci.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    ci.queueFamilyIndexCount = image_info->queue_family_index;
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
                     const encode::VulkanDeviceTable*        device_table,
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
    ci.usage                 = buffer_info->usage | VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
    ci.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    ci.queueFamilyIndexCount = buffer_info->queue_family_index;
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

uint32_t FindGreatestVertexIndex(const std::vector<uint8_t>& index_data,
                                 uint32_t                    index_count,
                                 uint32_t                    first_index,
                                 VkIndexType                 type)
{
    switch (type)
    {
        case VK_INDEX_TYPE_UINT8_EXT:
        {
            const uint8_t  restart_index = 0xff;
            const uint8_t* indices       = static_cast<const uint8_t*>(index_data.data());
            uint32_t       i             = 0;
            while (indices[first_index + i] == restart_index && i < index_count)
            {
                ++i;
            }

            if (i == index_count)
            {
                return 0;
            }

            uint8_t max = indices[first_index + i];

            for (; i < index_count; ++i)
            {
                if (indices[first_index + i] == restart_index)
                {
                    continue;
                }

                if (indices[first_index + i] > max)
                {
                    max = indices[first_index + i];
                }
            }

            return max;
        }
        break;

        case VK_INDEX_TYPE_UINT16:
        {
            const uint16_t  restart_index = 0xffff;
            const uint16_t* indices       = reinterpret_cast<const uint16_t*>(index_data.data());
            uint32_t        i             = 0;
            while (indices[first_index + i] == restart_index && i < index_count)
            {
                ++i;
            }

            if (i == index_count)
            {
                return 0;
            }

            uint16_t max = indices[first_index + i];

            for (; i < index_count; ++i)
            {
                if (indices[first_index + i] == restart_index)
                {
                    continue;
                }

                if (indices[first_index + i] > max)
                {
                    max = indices[first_index + i];
                }
            }

            return max;
        }
        break;

        case VK_INDEX_TYPE_UINT32:
        {
            const uint32_t  restart_index = 0xffffffff;
            const uint32_t* indices       = reinterpret_cast<const uint32_t*>(index_data.data());
            uint32_t        i             = 0;
            while (indices[first_index + i] == restart_index && i < index_count)
            {
                ++i;
            }

            if (i == index_count)
            {
                return 0;
            }

            uint32_t max = indices[first_index + i];

            for (; i < index_count; ++i)
            {
                if (indices[first_index + i] == restart_index)
                {
                    continue;
                }

                if (indices[first_index + i] > max)
                {
                    max = indices[first_index + i];
                }
            }

            return max;
        }
        break;

        case VK_INDEX_TYPE_NONE_KHR:
        default:
            GFXRECON_LOG_ERROR("%s() Unrecognized/unhandled index type (%u)", __func__, static_cast<uint32_t>(type));
            assert(0);
            return 0;
            break;
    }
}

VkResult DumpImageToFile(const VulkanImageInfo*             image_info,
                         const VulkanDeviceInfo*            device_info,
                         const encode::VulkanDeviceTable*   device_table,
                         const encode::VulkanInstanceTable* instance_table,
                         CommonObjectInfoTable&             object_info_table,
                         const std::vector<std::string>&    filenames,
                         float                              scale,
                         std::vector<bool>&                 scaling_supported,
                         util::ScreenshotFormat             image_file_format,
                         bool                               dump_all_subresources,
                         VkImageLayout                      layout,
                         const VkExtent3D*                  extent_p)
{
    assert(image_info != nullptr);
    assert(device_info != nullptr);
    assert(device_table != nullptr);
    assert(instance_table != nullptr);

    std::vector<VkImageAspectFlagBits> aspects;
    graphics::GetFormatAspects(image_info->format, &aspects);

    const uint32_t total_files =
        dump_all_subresources ? (aspects.size() * image_info->layer_count * image_info->level_count) : aspects.size();
    assert(total_files == filenames.size());
    assert(scaling_supported.size() == total_files);

    const VulkanPhysicalDeviceInfo* phys_dev_info = object_info_table.GetVkPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    graphics::VulkanResourcesUtil resource_util(device_info->handle,
                                                device_info->parent,
                                                *device_table,
                                                *instance_table,
                                                *phys_dev_info->replay_device_info->memory_properties);

    const VkExtent3D extent{ (extent_p != nullptr) ? extent_p->width : image_info->extent.width,
                             (extent_p != nullptr) ? extent_p->height : image_info->extent.height,
                             (extent_p != nullptr) ? extent_p->depth : image_info->extent.depth };

    uint32_t f = 0;
    for (size_t i = 0; i < aspects.size(); ++i)
    {
        const VkImageAspectFlagBits aspect = aspects[i];

        std::vector<uint8_t>  data;
        std::vector<uint64_t> subresource_offsets;
        std::vector<uint64_t> subresource_sizes;
        bool                  scaled;

        VkResult res = resource_util.ReadFromImageResourceStaging(
            image_info->handle,
            image_info->format,
            image_info->type,
            extent,
            image_info->level_count,
            image_info->layer_count,
            image_info->tiling,
            image_info->sample_count,
            (layout == VK_IMAGE_LAYOUT_MAX_ENUM) ? image_info->intermediate_layout : layout,
            image_info->queue_family_index,
            aspect,
            data,
            subresource_offsets,
            subresource_sizes,
            scaled,
            false,
            scale);

        assert(!subresource_offsets.empty());
        assert(!subresource_sizes.empty());

        scaling_supported[i] = scaled;

        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Reading from image resource %" PRIu64 " failed (%s)",
                               image_info->capture_id,
                               util::ToString<VkResult>(res).c_str())
            return res;
        }

        const util::imagewriter::DataFormats output_image_format = VkFormatToImageWriterDataFormat(image_info->format);

        if ((image_info->level_count == 1 && image_info->layer_count == 1) || !dump_all_subresources)
        {
            std::string filename = filenames[f++];

            if (aspects[i] == VK_IMAGE_ASPECT_STENCIL_BIT)
                continue;

            if (output_image_format != util::imagewriter::DataFormats::kFormat_UNSPECIFIED)
            {
                VkExtent3D scaled_extent;
                if (scale != 1.0f && scaled)
                {
                    scaled_extent.width  = std::max(image_info->extent.width * scale, 1.0f);
                    scaled_extent.height = std::max(image_info->extent.height * scale, 1.0f);
                    scaled_extent.depth  = image_info->extent.depth;
                }
                else
                {
                    scaled_extent = image_info->extent;
                }

                const uint32_t texel_size = vkuFormatElementSizeWithAspect(image_info->format, aspects[i]);
                const uint32_t stride     = texel_size * scaled_extent.width;

                filename += ImageFileExtension(image_info->format, image_file_format);
                if (output_image_format == util::imagewriter::DataFormats::kFormat_ASTC)
                {
                    VKU_FORMAT_INFO format_info = vkuGetFormatInfo(image_info->format);

                    util::imagewriter::WriteAstcImage(filename,
                                                      scaled_extent.width,
                                                      scaled_extent.width,
                                                      1,
                                                      format_info.block_extent.width,
                                                      format_info.block_extent.height,
                                                      format_info.block_extent.depth,
                                                      data.data(),
                                                      subresource_sizes[0]);
                }
                else if (image_file_format == util::ScreenshotFormat::kBmp)
                {
                    util::imagewriter::WriteBmpImage(filename,
                                                     scaled_extent.width,
                                                     scaled_extent.height,
                                                     subresource_sizes[0],
                                                     data.data(),
                                                     stride,
                                                     output_image_format);
                }
                else if (image_file_format == util::ScreenshotFormat::kPng)
                {
                    util::imagewriter::WritePngImage(filename,
                                                     scaled_extent.width,
                                                     scaled_extent.height,
                                                     subresource_sizes[0],
                                                     data.data(),
                                                     stride,
                                                     output_image_format);
                }
            }
            else
            {
                GFXRECON_LOG_WARNING(
                    "%s format is not handled. Images with that format will be dump as a plain binary file.",
                    util::ToString<VkFormat>(image_info->format).c_str());

                filename = filename + std::string(".bin");
                util::bufferwriter::WriteBuffer(filename, data.data(), data.size());
            }
        }
        else
        {
            for (uint32_t mip = 0; mip < image_info->level_count; ++mip)
            {
                for (uint32_t layer = 0; layer < image_info->layer_count; ++layer)
                {
                    std::string filename = filenames[f++];

                    if (aspects[i] == VK_IMAGE_ASPECT_STENCIL_BIT)
                        continue;

                    const uint32_t sub_res_idx = mip * image_info->layer_count + layer;
                    const void*    data_offset = reinterpret_cast<const void*>(
                        reinterpret_cast<const uint8_t*>(data.data()) + subresource_offsets[sub_res_idx]);

                    if (output_image_format != util::imagewriter::DataFormats::kFormat_UNSPECIFIED)
                    {
                        VkExtent3D scaled_extent;
                        if (scale != 1.0f && scaled)
                        {
                            scaled_extent.width  = extent.width * scale;
                            scaled_extent.height = extent.height * scale;
                            scaled_extent.depth  = extent.depth;
                        }
                        else
                        {
                            scaled_extent = extent;
                        }

                        scaled_extent.width  = std::max(1u, scaled_extent.width >> mip);
                        scaled_extent.height = std::max(1u, scaled_extent.height >> mip);
                        scaled_extent.depth  = std::max(1u, scaled_extent.depth >> mip);

                        const uint32_t texel_size = vkuFormatElementSizeWithAspect(image_info->format, aspect);
                        const uint32_t stride     = texel_size * scaled_extent.width;

                        filename += ImageFileExtension(image_info->format, image_file_format);
                        if (output_image_format == util::imagewriter::DataFormats::kFormat_ASTC)
                        {
                            VKU_FORMAT_INFO format_info = vkuGetFormatInfo(image_info->format);

                            util::imagewriter::WriteAstcImage(filename,
                                                              scaled_extent.width,
                                                              scaled_extent.width,
                                                              1,
                                                              format_info.block_extent.width,
                                                              format_info.block_extent.height,
                                                              format_info.block_extent.depth,
                                                              data.data(),
                                                              subresource_sizes[sub_res_idx]);
                        }
                        else if (image_file_format == util::ScreenshotFormat::kBmp)
                        {
                            util::imagewriter::WriteBmpImage(filename,
                                                             scaled_extent.width,
                                                             scaled_extent.height,
                                                             subresource_sizes[sub_res_idx],
                                                             data_offset,
                                                             stride,
                                                             output_image_format);
                        }
                        else if (image_file_format == util::ScreenshotFormat::kPng)
                        {
                            util::imagewriter::WritePngImage(filename,
                                                             scaled_extent.width,
                                                             scaled_extent.height,
                                                             subresource_sizes[sub_res_idx],
                                                             data_offset,
                                                             stride,
                                                             output_image_format);
                        }
                    }
                    else
                    {
                        GFXRECON_LOG_WARNING(
                            "%s format is not handled. Images with that format will be dump as a plain binary file.",
                            util::ToString<VkFormat>(image_info->format).c_str());

                        util::bufferwriter::WriteBuffer(filename, data_offset, subresource_sizes[sub_res_idx]);
                    }
                }
            }
        }
    }

    assert(f == total_files);

    return VK_SUCCESS;
}

bool CheckDescriptorCompatibility(VkDescriptorType desc_type_a, VkDescriptorType desc_type_b)
{
    switch (desc_type_a)
    {
        case VK_DESCRIPTOR_TYPE_SAMPLER:
        case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
        case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
        case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
        case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
        case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
        case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
        case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
        case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV:
        case VK_DESCRIPTOR_TYPE_SAMPLE_WEIGHT_IMAGE_QCOM:
        case VK_DESCRIPTOR_TYPE_BLOCK_MATCH_IMAGE_QCOM:
        case VK_DESCRIPTOR_TYPE_MUTABLE_EXT:
        case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
            return desc_type_a == desc_type_b;

        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
            return desc_type_b == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER ||
                   desc_type_b == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC ||
                   desc_type_b == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER ||
                   desc_type_b == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC;

        default:
            assert(0);
            GFXRECON_LOG_ERROR(
                "%s() Unrecognized/unhandled index type (%u)", __func__, static_cast<uint32_t>(desc_type_a));
            return false;
    }
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
                        const encode::VulkanDeviceTable*        device_table,
                        VkDevice                                parent_device,
                        VkBaseInStructure*                      pNext,
                        const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props,
                        VkBuffer*                               new_buffer,
                        VkDeviceMemory*                         new_memory)
{
    assert(size);
    assert(device_table != nullptr);
    assert(new_buffer != nullptr);
    assert(new_memory != nullptr);
    assert(parent_device != VK_NULL_HANDLE);
    assert(replay_device_phys_mem_props);

    VkBufferCreateInfo bci;
    bci.sType                 = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    bci.pNext                 = pNext;
    bci.flags                 = 0;
    bci.size                  = size;
    bci.usage                 = VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
    bci.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    bci.queueFamilyIndexCount = 0;
    bci.pQueueFamilyIndices   = nullptr;

    VkResult res = device_table->CreateBuffer(parent_device, &bci, nullptr, new_buffer);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s(): CreateBuffer failed with: %s", __func__, util::ToString<VkResult>(res).c_str());
        return res;
    }

    VkMemoryRequirements mem_reqs       = {};
    VkMemoryAllocateInfo mem_alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO, nullptr };

    device_table->GetBufferMemoryRequirements(parent_device, *new_buffer, &mem_reqs);
    mem_alloc_info.allocationSize = mem_reqs.size;

    uint32_t mem_index =
        GetMemoryTypeIndex(*replay_device_phys_mem_props, mem_reqs.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    if (mem_index == std::numeric_limits<uint32_t>::max())
    {
        GFXRECON_LOG_ERROR("%s()%u failed to find an appropriate memory type", __func__, __LINE__);
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    mem_alloc_info.memoryTypeIndex = mem_index;

    res = device_table->AllocateMemory(parent_device, &mem_alloc_info, nullptr, new_memory);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s(): AllocateMemory failed with %s", __func__, util::ToString<VkResult>(res).c_str());
        return res;
    }

    res = device_table->BindBufferMemory(parent_device, *new_buffer, *new_memory, 0);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s(): BindBufferMemory failed with %s", __func__, util::ToString<VkResult>(res).c_str());
        return res;
    }

    return VK_SUCCESS;
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
