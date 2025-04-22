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
#include "util/to_string.h"
#include "vulkan/vulkan_core.h"
#include "Vulkan-Utility-Libraries/vk_format_utils.h"

#include <algorithm>
#include <sstream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

static util::imagewriter::DataFormats VkFormatToImageWriterDataFormat(VkFormat format)
{
    switch (format)
    {
        case VK_FORMAT_R8G8B8_SRGB:
        case VK_FORMAT_R8G8B8_UNORM:
            return util::imagewriter::DataFormats::kFormat_RGB;

        case VK_FORMAT_R8G8B8A8_SRGB:
        case VK_FORMAT_R8G8B8A8_UNORM:
            return util::imagewriter::DataFormats::kFormat_RGBA;

        case VK_FORMAT_B8G8R8_SRGB:
        case VK_FORMAT_B8G8R8_UNORM:
            return util::imagewriter::DataFormats::kFormat_BGR;

        case VK_FORMAT_B8G8R8A8_SRGB:
        case VK_FORMAT_B8G8R8A8_UNORM:
            return util::imagewriter::DataFormats::kFormat_BGRA;

        case VK_FORMAT_D32_SFLOAT:
        case VK_FORMAT_D32_SFLOAT_S8_UINT:
            return util::imagewriter::DataFormats::kFormat_D32_FLOAT;

        case VK_FORMAT_D24_UNORM_S8_UINT:
        case VK_FORMAT_X8_D24_UNORM_PACK32:
            return util::imagewriter::DataFormats::kFormat_D24_UNORM;

        case VK_FORMAT_D16_UNORM:
            return util::imagewriter::DataFormats::kFormat_D16_UNORM;

        default:
            GFXRECON_LOG_ERROR("%s isn't supported in VkFormatToImageWriterDataFormat",
                               util::ToString<VkFormat>(format).c_str());
            return util::imagewriter::DataFormats::kFormat_UNSPECIFIED;
    }
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
        dst_format = vkuFormatHasAlpha(format) ? VK_FORMAT_B8G8R8A8_SRGB : VK_FORMAT_B8G8R8_SRGB;
    }
    else if (vkuFormatIsDepthOrStencil(format))
    {
        // Converting depth format with vkCmdBlit is not allowed.
        // We will do the conversion on the cpu.
        dst_format = format;
    }
    else
    {
        dst_format = vkuFormatHasAlpha(format) ? VK_FORMAT_B8G8R8A8_UNORM : VK_FORMAT_B8G8R8_UNORM;
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
            const uint8_t  restart_index = 0xff;
            const uint8_t* indices       = static_cast<const uint8_t*>(index_data.data());
            uint32_t       i             = 0;
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

                if (indices[first_index + i] > max)
                {
                    max = indices[first_index + i];
                }

                if (indices[first_index + i] < min)
                {
                    min = indices[first_index + i];
                }
            }

            return MinMaxVertexIndex{ static_cast<uint32_t>(min) + vertex_offset,
                                      static_cast<uint32_t>(max) + vertex_offset };
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

                if (indices[first_index + i] > max)
                {
                    max = indices[first_index + i];
                }

                if (indices[first_index + i] < min)
                {
                    min = indices[first_index + i];
                }
            }

            return MinMaxVertexIndex{ static_cast<uint32_t>(min) + vertex_offset,
                                      static_cast<uint32_t>(max) + vertex_offset };
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

                if (indices[first_index + i] > max)
                {
                    max = indices[first_index + i];
                }

                if (indices[first_index + i] < min)
                {
                    min = indices[first_index + i];
                }
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

VkResult DumpImageToFile(const VulkanImageInfo*               image_info,
                         const VulkanDeviceInfo*              device_info,
                         const graphics::VulkanDeviceTable*   device_table,
                         const graphics::VulkanInstanceTable* instance_table,
                         CommonObjectInfoTable&               object_info_table,
                         const std::vector<std::string>&      filenames,
                         float                                scale,
                         std::vector<bool>&                   scaling_supported,
                         util::ScreenshotFormat               image_file_format,
                         bool                                 dump_all_subresources,
                         bool                                 dump_image_raw,
                         bool                                 dump_separate_alpha,
                         VkImageLayout                        layout)
{
    assert(image_info != nullptr);
    assert(device_info != nullptr);
    assert(device_table != nullptr);
    assert(instance_table != nullptr);

    std::vector<VkImageAspectFlagBits> aspects;
    GetFormatAspects(image_info->format, aspects);

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

    const VkFormat dst_format = dump_image_raw ? image_info->format : ChooseDestinationImageFormat(image_info->format);

    uint32_t f = 0;
    for (size_t i = 0; i < aspects.size(); ++i)
    {
        const VkImageAspectFlagBits aspect = aspects[i];

        std::vector<uint8_t>  data;
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

        scaling_supported[i] = resource_util.IsScalingSupported(image_resource.format,
                                                                image_resource.tiling,
                                                                dst_format,
                                                                image_resource.type,
                                                                image_resource.extent,
                                                                scale);
        bool blit_supported  = resource_util.IsBlitSupported(image_resource.format, image_resource.tiling, dst_format);
        bool use_blit        = (image_resource.format != dst_format && blit_supported) ||
                        (image_resource.scale != 1.0f && scaling_supported[i]);

        VkExtent3D scaled_extent = {
            static_cast<uint32_t>(std::max(static_cast<float>(image_resource.extent.width) * scale, 1.0f)),
            static_cast<uint32_t>(std::max(static_cast<float>(image_resource.extent.height) * scale, 1.0f)),
            static_cast<uint32_t>(std::max(static_cast<float>(image_resource.extent.depth) * scale, 1.0f))
        };

        image_resource.resource_size =
            resource_util.GetImageResourceSizesOptimal(image_resource.image,
                                                       use_blit ? dst_format : image_resource.format,
                                                       image_resource.type,
                                                       use_blit ? scaled_extent : image_resource.extent,
                                                       image_resource.level_count,
                                                       image_resource.layer_count,
                                                       image_resource.tiling,
                                                       aspect,
                                                       &subresource_offsets,
                                                       &subresource_sizes,
                                                       image_resource.all_layers_per_level);
        VkResult result = resource_util.ReadImageResource(image_resource, data);

        GFXRECON_ASSERT(!subresource_offsets.empty());
        GFXRECON_ASSERT(!subresource_sizes.empty());

        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Reading from image resource %" PRIu64 " failed (%s)",
                               image_info->capture_id,
                               util::ToString<VkResult>(result).c_str())
            return result;
        }

        const DumpedImageFormat output_image_format = GetDumpedImageFormat(device_info,
                                                                           device_table,
                                                                           instance_table,
                                                                           object_info_table,
                                                                           image_info->format,
                                                                           image_info->tiling,
                                                                           image_info->type,
                                                                           image_file_format,
                                                                           dump_image_raw);

        for (uint32_t mip = 0; mip < image_info->level_count; ++mip)
        {
            for (uint32_t layer = 0; layer < image_info->layer_count; ++layer)
            {
                const std::string& filename = filenames[f++];

                // We don't support stencil output yet
                if (aspects[i] == VK_IMAGE_ASPECT_STENCIL_BIT)
                    continue;

                const uint32_t sub_res_idx    = mip * image_info->layer_count + layer;
                const void*    offsetted_data = reinterpret_cast<const void*>(
                    reinterpret_cast<const uint8_t*>(data.data()) + subresource_offsets[sub_res_idx]);

                if (output_image_format != KFormatRaw)
                {
                    const util::imagewriter::DataFormats image_writer_format =
                        VkFormatToImageWriterDataFormat(dst_format);
                    assert(image_writer_format != util::imagewriter::DataFormats::kFormat_UNSPECIFIED);

                    if (scale != 1.0f && scaling_supported[i])
                    {
                        scaled_extent.width  = std::max(image_info->extent.width * scale, 1.0f);
                        scaled_extent.height = std::max(image_info->extent.height * scale, 1.0f);
                        scaled_extent.depth  = image_info->extent.depth;
                    }
                    else
                    {
                        scaled_extent = image_info->extent;
                    }

                    scaled_extent.width  = std::max(1u, scaled_extent.width >> mip);
                    scaled_extent.height = std::max(1u, scaled_extent.height >> mip);
                    scaled_extent.depth  = std::max(1u, scaled_extent.depth >> mip);

                    const uint32_t texel_size = vkuFormatElementSizeWithAspect(dst_format, aspect);
                    const uint32_t stride     = texel_size * scaled_extent.width;

                    if (output_image_format == kFormatBMP)
                    {
                        if (dump_separate_alpha)
                        {
                            util::imagewriter::WriteBmpImageSeparateAlpha(filename,
                                                                          scaled_extent.width,
                                                                          scaled_extent.height,
                                                                          offsetted_data,
                                                                          stride,
                                                                          image_writer_format);
                        }
                        else
                        {
                            util::imagewriter::WriteBmpImage(filename,
                                                             scaled_extent.width,
                                                             scaled_extent.height,
                                                             offsetted_data,
                                                             stride,
                                                             image_writer_format,
                                                             vkuFormatHasAlpha(image_info->format));
                        }
                    }
                    else if (output_image_format == KFormatPNG)
                    {
                        if (dump_separate_alpha)
                        {
                            util::imagewriter::WritePngImageSeparateAlpha(filename,
                                                                          scaled_extent.width,
                                                                          scaled_extent.height,
                                                                          offsetted_data,
                                                                          stride,
                                                                          image_writer_format);
                        }
                        else
                        {
                            util::imagewriter::WritePngImage(filename,
                                                             scaled_extent.width,
                                                             scaled_extent.height,
                                                             offsetted_data,
                                                             stride,
                                                             image_writer_format,
                                                             vkuFormatHasAlpha(image_info->format));
                        }
                    }
                }
                else
                {
                    if (!dump_image_raw)
                    {
                        GFXRECON_LOG_WARNING(
                            "%s format is not handled. Images with that format will be dump as a plain binary file.",
                            util::ToString<VkFormat>(image_info->format).c_str());
                    }

                    util::bufferwriter::WriteBuffer(filename, offsetted_data, subresource_sizes[sub_res_idx]);
                }

                if (!dump_all_subresources)
                {
                    break;
                }
            }

            if (!dump_all_subresources)
            {
                break;
            }
        }
    }

    assert(f == total_files);
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
                        const graphics::VulkanDeviceTable*      device_table,
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

void GetFormatAspects(VkFormat format, std::vector<VkImageAspectFlagBits>& aspects)
{
    aspects.clear();
    graphics::GetFormatAspects(format, &aspects);

    for (auto it = aspects.begin(); it < aspects.end();)
    {
        if (*it == VK_IMAGE_ASPECT_STENCIL_BIT)
        {
            it = aspects.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

DumpedImageFormat GetDumpedImageFormat(const VulkanDeviceInfo*              device_info,
                                       const graphics::VulkanDeviceTable*   device_table,
                                       const graphics::VulkanInstanceTable* instance_table,
                                       VulkanObjectInfoTable&               object_info_table,
                                       VkFormat                             src_format,
                                       VkImageTiling                        src_image_tiling,
                                       VkImageType                          type,
                                       util::ScreenshotFormat               image_file_format,
                                       bool                                 dump_raw)
{
    const VulkanPhysicalDeviceInfo* phys_dev_info = object_info_table.GetVkPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    // If there's a request for images to be dumped as raw bin files
    if (dump_raw)
    {
        return KFormatRaw;
    }

    graphics::VulkanResourcesUtil resource_util(device_info->handle,
                                                device_info->parent,
                                                *device_table,
                                                *instance_table,
                                                *phys_dev_info->replay_device_info->memory_properties);

    // Image cannot be converted into a format compatible for dumping in an image file
    const VkFormat dst_format        = ChooseDestinationImageFormat(src_format);
    bool           is_blit_supported = resource_util.IsBlitSupported(src_format, src_image_tiling, dst_format);
    if (!vkuFormatIsDepthOrStencil(src_format) && src_format != dst_format && !is_blit_supported)
    {
        return KFormatRaw;
    }

    // Choose the requested preference for image file extension
    switch (image_file_format)
    {
        case util::ScreenshotFormat::kBmp:
            return kFormatBMP;

        case util::ScreenshotFormat::kPng:
            return KFormatPNG;

        default:
            assert(0);
            return KFormatRaw;
    }

    return KFormatRaw;
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

    if ((flags & VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR) == VK_SHADER_STAGE_RAYGEN_BIT_KHR)
    {
        stage_names.push_back("raygen");
    }

    if ((flags & VK_SHADER_STAGE_MISS_BIT_KHR) == VK_SHADER_STAGE_ANY_HIT_BIT_KHR)
    {
        stage_names.push_back("any_hit");
    }

    if ((flags & VK_SHADER_STAGE_INTERSECTION_BIT_KHR) == VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR)
    {
        stage_names.push_back("closest_hit");
    }

    if ((flags & VK_SHADER_STAGE_CALLABLE_BIT_KHR) == VK_SHADER_STAGE_MISS_BIT_KHR)
    {
        stage_names.push_back("miss");
    }

    if ((flags & VK_SHADER_STAGE_TASK_BIT_EXT) == VK_SHADER_STAGE_INTERSECTION_BIT_KHR)
    {
        stage_names.push_back("intersection");
    }

    if ((flags & VK_SHADER_STAGE_MESH_BIT_EXT) == VK_SHADER_STAGE_CALLABLE_BIT_KHR)
    {
        stage_names.push_back("callable");
    }

    if ((flags & VK_SHADER_STAGE_ALL_GRAPHICS) == VK_SHADER_STAGE_TASK_BIT_EXT)
    {
        stage_names.push_back("task");
    }

    if ((flags & VK_SHADER_STAGE_ALL) == VK_SHADER_STAGE_MESH_BIT_EXT)
    {
        stage_names.push_back("mesh");
    }
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
