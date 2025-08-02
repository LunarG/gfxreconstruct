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
#include "decode/vulkan_object_info.h"
#include "vulkan/vulkan_core.h"
#include "util/compressor.h"
#include "util/defines.h"
#include "util/options.h"
#include <cstdint>
#include <variant>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

using CommandBufferIterator = std::vector<VkCommandBuffer>::const_iterator;

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

enum DumpedImageFormat
{
    kFormatBMP,
    KFormatPNG,
    KFormatRaw
};

struct MinMaxVertexIndex
{
    uint32_t min = 0;
    uint32_t max = 0;
};

using BoundDescriptorSets = std::unordered_map<uint32_t, VulkanDescriptorSetInfo::VulkanDescriptorBindingsInfo>;

enum class DumpResourcesCommandType
{
    kUnknown,
    kGraphics,
    kCompute,
    kRayTracing
};

enum class DumpResourceType
{
    kUnknown,
    kRtv,
    kDsv,
    kVertex,
    kIndex,
    kImageDescriptor,
    kBufferDescriptor,
    kInlineUniformBufferDescriptor,
    kDispatchTraceRaysImage,
    kDispatchTraceRaysBuffer,
    kDispatchTraceRaysImageDescriptor,
    kDispatchTraceRaysBufferDescriptor,
    kDispatchTraceRaysInlineUniformBufferDescriptor,
};

struct DumpedFile
{
    DumpedFile() = default;
    DumpedFile(std::string f) : filename(f) {}

    std::string filename;
    std::string filename_before;
    size_t      size{ 0 };
    size_t      compressed_size{ 0 };
};

struct DumpedBuffer : DumpedFile
{
    DumpedBuffer() = default;

    const VulkanBufferInfo* buffer_info{ nullptr };
    VkDeviceSize            offset{ VK_WHOLE_SIZE };

    std::vector<uint8_t> inline_uniform_data;
};

struct DumpedImage
{
    DumpedImage() = default;

    const VulkanImageInfo* image_info{ nullptr };

    bool scaling_failed{ false };
    bool dumped_raw{ false };

    struct DumpedImageSubresource : DumpedFile
    {
        DumpedImageSubresource() = default;

        VkImageAspectFlagBits aspect{ VkImageAspectFlagBits(0) };
        VkExtent3D            scaled_extent{ 0, 0, 0 };
        VkExtent3D            extent{ 0, 0, 0 };
        uint32_t              level{ 0 };
        uint32_t              layer{ 0 };
    };

    std::vector<DumpedImageSubresource> dumped_subresources;
};

struct DumpedResourceBase
{
    DumpedResourceBase() = default;

    DumpedResourceBase(DumpResourceType t, uint64_t bcb, uint64_t cmd, uint64_t qs, bool bc) :
        type(t), bcb_index(bcb), cmd_index(cmd), qs_index(qs), before_command(bc)
    {}

    DumpedResourceBase(DumpResourceType t, uint64_t bcb, uint64_t cmd, uint64_t qs, uint64_t rp, uint64_t sp, bool bc) :
        type(t), bcb_index(bcb), cmd_index(cmd), qs_index(qs), render_pass(rp), subpass(sp), before_command(bc)
    {}

    DumpResourceType type{ DumpResourceType::kUnknown };
    uint64_t         bcb_index{ 0 };
    uint64_t         cmd_index{ 0 };
    uint64_t         qs_index{ 0 };

    // For storage descriptors and render targets when dumping before commands
    bool before_command{ false };

    uint64_t render_pass{ 0 };
    uint32_t subpass{ 0 };
};

struct DumpedVertexIndexBuffer : DumpedResourceBase
{
    // Due to multiple member variable it's easy to forget seting some of them.
    // Deleting the default construct should help to ensure that variable are set
    DumpedVertexIndexBuffer() = delete;

    // For vertex buffers
    DumpedVertexIndexBuffer(DumpResourceType t, uint64_t bcb, uint64_t cmd, uint64_t qs, bool bc, uint32_t b) :
        DumpedResourceBase(t, bcb, cmd, qs, bc), binding(b)
    {}

    // For index buffers
    DumpedVertexIndexBuffer(DumpResourceType t, uint64_t bcb, uint64_t cmd, uint64_t qs, bool bc, VkIndexType it) :
        DumpedResourceBase(t, bcb, cmd, qs, bc), index_type(it)
    {}

    DumpedBuffer buffer;

    // For vertex buffer attributes
    uint32_t binding{ 0 };

    // For index buffer
    VkIndexType index_type{ VK_INDEX_TYPE_NONE_KHR };
};

struct DumpedDescriptor : DumpedResourceBase
{
    // Due to multiple member variable it's easy to forget seting some of them.
    // Deleting the default construct should help to ensure that variable are set
    DumpedDescriptor() = delete;

    DumpedDescriptor(DumpResourceType         t,
                     uint64_t                 bcb,
                     uint64_t                 cmd,
                     uint64_t                 qs,
                     bool                     bc,
                     VkShaderStageFlags       ss,
                     VkDescriptorType         dt,
                     uint32_t                 s,
                     uint32_t                 b,
                     uint32_t                 ai,
                     DumpResourcesCommandType rt) :
        DumpedResourceBase(t, bcb, cmd, qs, bc),
        stages(ss), desc_type(dt), set(s), binding(b), array_index(ai), resource_type(rt)
    {}

    DumpedDescriptor(DumpResourceType         t,
                     uint64_t                 bcb,
                     uint64_t                 cmd,
                     uint64_t                 qs,
                     bool                     bc,
                     uint32_t                 rp,
                     uint32_t                 sp,
                     VkShaderStageFlags       ss,
                     VkDescriptorType         dt,
                     uint32_t                 s,
                     uint32_t                 b,
                     uint32_t                 ai,
                     DumpResourcesCommandType rt) :
        DumpedResourceBase(t, bcb, cmd, qs, rp, sp, bc),
        stages(ss), desc_type(dt), set(s), binding(b), array_index(ai), resource_type(rt)
    {}

    std::variant<DumpedImage, DumpedBuffer> dumped_resource;

    VkShaderStageFlags stages{ VkShaderStageFlagBits(0) };

    VkDescriptorType desc_type{ VK_DESCRIPTOR_TYPE_MAX_ENUM };
    uint32_t         set{ 0 };
    uint32_t         binding{ 0 };
    uint32_t         array_index{ 0 };

    DumpResourcesCommandType resource_type{ DumpResourcesCommandType::kUnknown };
};

struct DumpedRenderTarget : DumpedResourceBase
{
    // Due to multiple member variable it's easy to forget seting some of them.
    // Deleting the default construct should help to ensure that variable are set
    DumpedRenderTarget() = delete;

    DumpedRenderTarget(
        DumpResourceType t, uint64_t bcb, uint64_t cmd, uint64_t qs, uint64_t rp, uint64_t sp, uint32_t l, bool bc) :
        DumpedResourceBase(t, bcb, cmd, qs, rp, sp, bc),
        location(l)
    {}

    DumpedImage image;

    uint32_t location{ 0 };
};

struct DumpedResourcesInfo
{
    DumpedResourcesInfo() = default;

    uint64_t bcb_index{ 0 };
    uint64_t cmd_index{ 0 };
    uint64_t qs_index{ 0 };

    std::vector<DumpedVertexIndexBuffer> dumped_vertex_index_buffers;
    std::vector<DumpedDescriptor>        dumped_descriptors;
    std::vector<DumpedRenderTarget>      dumped_render_targets;
};

DumpedImageFormat GetDumpedImageFormat(const VulkanDeviceInfo*              device_info,
                                       const graphics::VulkanDeviceTable*   device_table,
                                       const graphics::VulkanInstanceTable* instance_table,
                                       VulkanObjectInfoTable&               object_info_table,
                                       VkFormat                             src_format,
                                       VkImageTiling                        src_image_tiling,
                                       VkImageType                          type,
                                       util::ScreenshotFormat               image_file_format,
                                       bool                                 dump_raw = false);

const char* ImageFileExtension(DumpedImageFormat image_format);

uint32_t GetMemoryTypeIndex(const VkPhysicalDeviceMemoryProperties& memory_properties,
                            uint32_t                                type_bits,
                            VkMemoryPropertyFlags                   property_flags);

VkResult CloneImage(CommonObjectInfoTable&                  object_info_table,
                    const graphics::VulkanDeviceTable*      device_table,
                    const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props,
                    const VulkanImageInfo*                  image_info,
                    VkImage*                                new_image,
                    VkDeviceMemory*                         new_image_memory);

VkResult CloneBuffer(CommonObjectInfoTable&                  object_info_table,
                     const graphics::VulkanDeviceTable*      device_table,
                     const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props,
                     const VulkanBufferInfo*                 buffer_info,
                     VkBuffer*                               new_buffer,
                     VkDeviceMemory*                         new_buffer_memory,
                     VkDeviceSize                            override_size = 0);

uint32_t VkIndexTypeToBytes(VkIndexType type);

MinMaxVertexIndex FindMinMaxVertexIndices(const std::vector<uint8_t>& index_data,
                                          uint32_t                    index_count,
                                          uint32_t                    first_index,
                                          int32_t                     vertex_offset,
                                          VkIndexType                 type);

VkResult DumpImageToFile(DumpedImage&                         dumped_resource,
                         const VulkanDeviceInfo*              device_info,
                         const graphics::VulkanDeviceTable*   device_table,
                         const graphics::VulkanInstanceTable* instance_table,
                         CommonObjectInfoTable&               object_info_table,
                         float                                scale,
                         util::ScreenshotFormat               image_file_format,
                         bool                                 before_command        = false,
                         const util::Compressor*              compressor            = nullptr,
                         bool                                 dump_all_subresources = false,
                         bool                                 dump_image_raw        = false,
                         bool                                 dump_separate_alpha   = false,
                         VkImageLayout                        layout                = VK_IMAGE_LAYOUT_MAX_ENUM);

VkResult DumpBufferToFile(DumpedBuffer&                        buffer,
                          const VulkanDeviceInfo*              device_info,
                          const graphics::VulkanDeviceTable*   device_table,
                          const graphics::VulkanInstanceTable* instance_table,
                          CommonObjectInfoTable&               object_info_table,
                          bool                                 before_command = false,
                          const util::Compressor*              compressor     = nullptr);

std::string ShaderStageToStr(VkShaderStageFlagBits shader_stage);

std::string ImageAspectToStr(VkImageAspectFlagBits aspect);

std::string FormatToStr(VkFormat format);

std::string IndexTypeToStr(VkIndexType type);

VkResult CreateVkBuffer(VkDeviceSize                            size,
                        const graphics::VulkanDeviceTable*      device_table,
                        VkDevice                                parent_device,
                        VkBaseInStructure*                      pNext,
                        const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props,
                        VkBuffer*                               new_buffer,
                        VkDeviceMemory*                         new_memory);

void GetFormatAspects(VkFormat format, std::vector<VkImageAspectFlagBits>& aspects);

std::string ShaderStageFlagsToString(VkShaderStageFlags flags);

void ShaderStageFlagsToStageNames(VkShaderStageFlags flags, std::vector<std::string>& stage_names);

std::vector<VkPipelineBindPoint> ShaderStageFlagsToPipelineBindPoints(VkShaderStageFlags flags);

uint32_t FindQueueFamilyIndex(const VulkanDeviceInfo::EnabledQueueFamilyFlags& families, VkQueueFlags flags);

static constexpr VkExtent3D ScaleToMipLevel(const VkExtent3D& extent, uint32_t level)
{
    const VkExtent3D mip_extent = VkExtent3D{ std::max(1u, extent.width >> level),
                                              std::max(1u, extent.height >> level),
                                              std::max(1u, extent.depth >> level) };

    return mip_extent;
}

static constexpr VkExtent3D ScaleExtent(const VkExtent3D& extent, float scale)
{
    const VkExtent3D scaled_extent = VkExtent3D{ std::max(1u, static_cast<uint32_t>(extent.width * scale)),
                                                 std::max(1u, static_cast<uint32_t>(extent.height * scale)),
                                                 std::max(1u, static_cast<uint32_t>(extent.depth * scale)) };

    return scaled_extent;
}

class VulkanDumpResourcesDelegate;
class DefaultVulkanDumpResourcesDelegate;

enum class DumpResourcesCommandBufferLevel
{
    kUnknown = 0,
    kPrimary,
    kSecondary
};

#define DEPTH_ATTACHMENT ~0

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif /* GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_COMMON_H */