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

#ifndef GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_COMMON_H
#define GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_COMMON_H

#include "decode/common_object_info_table.h"
#include "vulkan/vulkan_core.h"
#include "util/defines.h"
#include "util/image_writer.h"
#include "util/options.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

using CommandBufferIterator = std::vector<VkCommandBuffer>::const_iterator;

enum PipelineBindPoints
{
    kBindPoint_graphics = 0,
    kBindPoint_compute,
    kBindPoint_ray_tracing,

    kBindPoint_count
};

template <typename T>
static bool IsInsideRange(const std::vector<T>& vec, T value)
{
    if (!vec.size())
    {
        return false;
    }
    else
    {
        return (value >= *(vec.begin()) && value <= *(vec.end() - 1));
    }
}

PipelineBindPoints VkPipelineBindPointToPipelineBindPoint(VkPipelineBindPoint bind_point);

bool IsFormatAstcCompressed(VkFormat format);

util::imagewriter::DataFormats VkFormatToImageWriterDataFormat(VkFormat format);

const char* ImageFileExtension(VkFormat format, util::ScreenshotFormat image_file_format);

uint32_t GetMemoryTypeIndex(const VkPhysicalDeviceMemoryProperties& memory_properties,
                            uint32_t                                type_bits,
                            VkMemoryPropertyFlags                   property_flags);

VkResult CloneImage(CommonObjectInfoTable&                  object_info_table,
                    const encode::VulkanDeviceTable*        device_table,
                    const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props,
                    const VulkanImageInfo*                  image_info,
                    VkImage*                                new_image,
                    VkDeviceMemory*                         new_image_memory);

VkResult CloneBuffer(CommonObjectInfoTable&                  object_info_table,
                     const encode::VulkanDeviceTable*        device_table,
                     const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props,
                     const VulkanBufferInfo*                 buffer_info,
                     VkBuffer*                               new_buffer,
                     VkDeviceMemory*                         new_buffer_memory,
                     VkDeviceSize                            override_size = 0);

uint32_t VkIndexTypeToBytes(VkIndexType type);

uint32_t FindGreatestVertexIndex(const std::vector<uint8_t>& index_data,
                                 uint32_t                    index_count,
                                 uint32_t                    first_index,
                                 VkIndexType                 type);

VkResult DumpImageToFile(const VulkanImageInfo*             image_info,
                         const VulkanDeviceInfo*            device_info,
                         const encode::VulkanDeviceTable*   device_table,
                         const encode::VulkanInstanceTable* instance_table,
                         CommonObjectInfoTable&             object_info_table,
                         const std::vector<std::string>&    filenames,
                         float                              scale,
                         std::vector<bool>&                 scaling_supported,
                         util::ScreenshotFormat             image_file_format,
                         bool                               dump_all_subresources = false,
                         VkImageLayout                      layout                = VK_IMAGE_LAYOUT_MAX_ENUM,
                         const VkExtent3D*                  extent_p              = nullptr);

bool CheckDescriptorCompatibility(VkDescriptorType desc_type_a, VkDescriptorType desc_type_b);

std::string ShaderStageToStr(VkShaderStageFlagBits shader_stage);

std::string ImageAspectToStr(VkImageAspectFlagBits aspect);

std::string FormatToStr(VkFormat format);

std::string IndexTypeToStr(VkIndexType type);

VkResult CreateVkBuffer(VkDeviceSize                            size,
                        const encode::VulkanDeviceTable*        device_table,
                        VkDevice                                parent_device,
                        VkBaseInStructure*                      pNext,
                        const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props,
                        VkBuffer*                               new_buffer,
                        VkDeviceMemory*                         new_memory);

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif /* GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_COMMON_H */