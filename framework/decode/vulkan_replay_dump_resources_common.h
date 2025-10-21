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
#include "decode/vulkan_replay_options.h"
#include "util/logging.h"
#include "vulkan/vulkan_core.h"
#include "util/defines.h"
#include <cstdint>
#include <utility>
#include <list>
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

using DumpedRawData = std::vector<uint8_t>;

enum class DumpResourcesCommandType
{
    kNone,
    kGraphics,
    kCompute,
    kRayTracing
};

enum class DumpResourceType
{
    kNone,
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
    DumpedFile(VkDeviceSize s) : size(s) {}

    std::string  filename;
    VkDeviceSize size{ 0 };
    VkDeviceSize compressed_size{ 0 };
};

struct DumpedBuffer : DumpedFile
{
    DumpedBuffer() = default;

    DumpedBuffer(const VulkanBufferInfo* bi, VkDeviceSize o, VkDeviceSize s) : DumpedFile(s), buffer_info(bi), offset(o)
    {}

    const VulkanBufferInfo* buffer_info{ nullptr };
    VkDeviceSize            offset{ VK_WHOLE_SIZE };

    void CopyDumpedInfo(const DumpedBuffer& other)
    {
        buffer_info     = other.buffer_info;
        offset          = other.offset;
        filename        = other.filename;
        size            = other.size;
        compressed_size = other.compressed_size;
    }
};

struct DumpedImage
{
    DumpedImage() = default;

    DumpedImage(const VulkanImageInfo* i_f) : image_info(i_f), scaling_failed(false), dumped_raw(false) {}

    const VulkanImageInfo* image_info{ nullptr };

    // Scaling is done with vkCmdBlitImage. It is possible that an implementation does not supporting blit for some
    // specific formats. In these cases, since we can't scale the images with BlitImage, we dump them in their original
    // dimensions and mark them with an entry in the output json.
    bool     scaling_failed{ false };
    bool     dumped_raw{ false };
    VkFormat dumped_format{ VK_FORMAT_UNDEFINED };

    struct DumpedImageSubresource : DumpedFile
    {
        DumpedImageSubresource() = default;

        DumpedImageSubresource(
            VkImageAspectFlagBits a, const VkExtent3D& e, const VkExtent3D& se, uint32_t le, uint32_t la) :
            aspect(a),
            extent(e), scaled_extent(se), level(le), layer(la)
        {}

        VkImageAspectFlagBits aspect{ VkImageAspectFlagBits(0) };
        VkExtent3D            extent{ 0, 0, 0 };
        VkExtent3D            scaled_extent{ 0, 0, 0 };
        uint32_t              level{ 0 };
        uint32_t              layer{ 0 };
    };

    std::vector<DumpedImageSubresource> dumped_subresources;

    void CopyDumpedInfo(const DumpedImage& other)
    {
        scaling_failed      = other.scaling_failed;
        dumped_raw          = other.dumped_raw;
        dumped_format       = other.dumped_format;
        dumped_subresources = other.dumped_subresources;
    }
};

struct DumpedResourceBase
{
    DumpedResourceBase() = default;

    DumpedResourceBase(DumpResourceType t, uint64_t bcb, uint64_t cmd, uint64_t qs) :
        type(t), bcb_index(bcb), cmd_index(cmd), qs_index(qs)
    {}

    DumpedResourceBase(DumpResourceType t, uint64_t bcb, uint64_t cmd, uint64_t qs, uint64_t rp, uint64_t sp) :
        type(t), bcb_index(bcb), cmd_index(cmd), qs_index(qs), render_pass(rp), subpass(sp)
    {}

    DumpResourceType type{ DumpResourceType::kNone };

    // BeginCommandBuffer index
    uint64_t bcb_index{ 0 };

    // The command's index (vkCmdDraw, vkCmdDispatch, etc)
    uint64_t cmd_index{ 0 };

    // The QueueSubmit index
    uint64_t qs_index{ 0 };

    // The render pass index in which this resource is dumped
    uint64_t render_pass{ 0 };

    // The sub pass index in which this resource is dumped
    uint64_t subpass{ 0 };
};

struct DumpedVertexIndexBuffer : DumpedResourceBase
{
    // Due to multiple member variable it's easy to forget seting some of them.
    // Deleting the default construct should help to ensure that variable are set
    DumpedVertexIndexBuffer() = delete;

    // For vertex buffers
    DumpedVertexIndexBuffer(DumpResourceType        t,
                            uint64_t                bcb,
                            uint64_t                cmd,
                            uint64_t                qs,
                            uint32_t                b,
                            const VulkanBufferInfo* bi,
                            VkDeviceSize            s,
                            VkDeviceSize            o) :
        DumpedResourceBase(t, bcb, cmd, qs),
        buffer(bi, o, s), binding(b)
    {}

    // For index buffers
    DumpedVertexIndexBuffer(DumpResourceType        t,
                            uint64_t                bcb,
                            uint64_t                cmd,
                            uint64_t                qs,
                            VkIndexType             it,
                            const VulkanBufferInfo* bi,
                            VkDeviceSize            s,
                            VkDeviceSize            o) :
        DumpedResourceBase(t, bcb, cmd, qs),
        buffer(bi, o, s), index_type(it)
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

    // Buffer descriptors for graphics
    DumpedDescriptor(DumpResourceType         t,
                     uint64_t                 bcb,
                     uint64_t                 cmd,
                     uint64_t                 qs,
                     uint64_t                 rp,
                     uint64_t                 sp,
                     VkShaderStageFlags       ss,
                     VkDescriptorType         dt,
                     uint32_t                 s,
                     uint32_t                 b,
                     uint32_t                 ai,
                     const VulkanBufferInfo*  buffer_info,
                     VkDeviceSize             offset,
                     VkDeviceSize             size,
                     DumpResourcesCommandType rt) :
        DumpedResourceBase(t, bcb, cmd, qs, rp, sp),
        stages(ss), desc_type(dt), set(s), binding(b), array_index(ai), resource_type(rt),
        dumped_resource(std::in_place_type<DumpedBuffer>, buffer_info, offset, size)
    {}

    // Inline uniform buffers for graphics
    DumpedDescriptor(DumpResourceType         t,
                     uint64_t                 bcb,
                     uint64_t                 cmd,
                     uint64_t                 qs,
                     uint64_t                 rp,
                     uint64_t                 sp,
                     VkShaderStageFlags       ss,
                     VkDescriptorType         dt,
                     uint32_t                 s,
                     uint32_t                 b,
                     DumpResourcesCommandType rt) :
        DumpedResourceBase(t, bcb, cmd, qs, rp, sp),
        stages(ss), desc_type(dt), set(s), binding(b), array_index(0), resource_type(rt),
        dumped_resource(std::in_place_type<DumpedBuffer>, nullptr, 0, 0)
    {}

    // Graphics image descriptors
    DumpedDescriptor(DumpResourceType         t,
                     uint64_t                 bcb,
                     uint64_t                 cmd,
                     uint64_t                 qs,
                     uint64_t                 rp,
                     uint64_t                 sp,
                     VkShaderStageFlags       ss,
                     VkDescriptorType         dt,
                     uint32_t                 s,
                     uint32_t                 b,
                     uint32_t                 ai,
                     const VulkanImageInfo*   img_info,
                     DumpResourcesCommandType rt) :
        DumpedResourceBase(t, bcb, cmd, qs, rp, sp),
        stages(ss), desc_type(dt), set(s), binding(b), array_index(ai), resource_type(rt),
        dumped_resource(std::in_place_type<DumpedImage>, img_info)
    {}

    // Dispatch ray tracing image descriptors
    DumpedDescriptor(DumpResourceType         t,
                     uint64_t                 bcb,
                     uint64_t                 cmd,
                     uint64_t                 qs,
                     VkShaderStageFlags       ss,
                     VkDescriptorType         dt,
                     uint32_t                 s,
                     uint32_t                 b,
                     uint32_t                 ai,
                     const VulkanImageInfo*   img_info,
                     DumpResourcesCommandType rt) :
        DumpedResourceBase(t, bcb, cmd, qs),
        stages(ss), desc_type(dt), set(s), binding(b), array_index(ai), resource_type(rt),
        dumped_resource(std::in_place_type<DumpedImage>, img_info)
    {}

    // Dispatch ray tracing buffer descriptors
    DumpedDescriptor(DumpResourceType         t,
                     uint64_t                 bcb,
                     uint64_t                 cmd,
                     uint64_t                 qs,
                     VkShaderStageFlags       ss,
                     VkDescriptorType         dt,
                     uint32_t                 s,
                     uint32_t                 b,
                     uint32_t                 ai,
                     const VulkanBufferInfo*  buffer_info,
                     VkDeviceSize             offset,
                     VkDeviceSize             size,
                     DumpResourcesCommandType rt) :
        DumpedResourceBase(t, bcb, cmd, qs),
        stages(ss), desc_type(dt), set(s), binding(b), array_index(ai), resource_type(rt),
        dumped_resource(std::in_place_type<DumpedBuffer>, buffer_info, offset, size)
    {}

    // Dispatch ray tracing inline uniform buffers
    DumpedDescriptor(DumpResourceType         t,
                     uint64_t                 bcb,
                     uint64_t                 cmd,
                     uint64_t                 qs,
                     VkShaderStageFlags       ss,
                     VkDescriptorType         dt,
                     uint32_t                 s,
                     uint32_t                 b,
                     DumpResourcesCommandType rt) :
        DumpedResourceBase(t, bcb, cmd, qs),
        stages(ss), desc_type(dt), set(s), binding(b), array_index(0), resource_type(rt),
        dumped_resource(std::in_place_type<DumpedBuffer>, nullptr, 0, 0)
    {}

    // The dumped resource
    std::variant<DumpedImage, DumpedBuffer> dumped_resource;

    bool has_before{ false };

    // The dumped resource before the execution of the command.
    // Used only when --dump-resources-before-draw is used.
    std::variant<DumpedImage, DumpedBuffer> dumped_resource_before;

    VkShaderStageFlags stages{ VkShaderStageFlagBits(0) };

    VkDescriptorType desc_type{ VK_DESCRIPTOR_TYPE_MAX_ENUM };
    uint32_t         set{ 0 };
    uint32_t         binding{ 0 };
    uint32_t         array_index{ 0 };

    DumpResourcesCommandType resource_type{ DumpResourcesCommandType::kNone };
};

struct DumpedRenderTarget : DumpedResourceBase
{
    // Due to multiple member variable it's easy to forget seting some of them.
    // Deleting the default construct should help to ensure that variable are set
    DumpedRenderTarget() = delete;

    DumpedRenderTarget(DumpResourceType       t,
                       uint64_t               bcb,
                       uint64_t               cmd,
                       uint64_t               qs,
                       uint64_t               rp,
                       uint64_t               sp,
                       uint32_t               l,
                       bool                   before,
                       const VulkanImageInfo* img_info) :
        DumpedResourceBase(t, bcb, cmd, qs, rp, sp),
        location(l), dumped_image(img_info)
    {
        if (before)
        {
            dumped_image_before = DumpedImage(img_info);
        }
    }

    // The dumped image resource
    DumpedImage dumped_image;

    // The dumped image resource before the execution of the command.
    // Used only when --dump-resources-before-draw is used.
    DumpedImage dumped_image_before;

    // The render target location
    uint32_t location{ 0 };
};

struct DumpedResourcesInfo
{
    DumpedResourcesInfo() = default;

    uint64_t bcb_index{ 0 };
    uint64_t cmd_index{ 0 };
    uint64_t qs_index{ 0 };

    std::vector<DumpedVertexIndexBuffer> dumped_vertex_index_buffers;
    std::vector<DumpedRenderTarget>      dumped_render_targets;

    // We need to keep references to inserted elements. Use a list instead of a vector
    std::list<DumpedDescriptor> dumped_descriptors;
};

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

bool IsImageDumpable(const graphics::VulkanInstanceTable* instance_table,
                     const VulkanObjectInfoTable&         object_info_table,
                     const VulkanImageInfo*               image_info);

VkResult DumpImage(DumpedImage&                         dumped_image,
                   VkImageLayout                        layout,
                   float                                scale,
                   bool                                 dump_image_raw,
                   const VkImageSubresourceRange&       subresource_range,
                   std::vector<DumpedRawData>&          data,
                   const VulkanDeviceInfo*              device_info,
                   const graphics::VulkanDeviceTable*   device_table,
                   const graphics::VulkanInstanceTable* instance_table,
                   CommonObjectInfoTable&               object_info_table);

VkResult DumpBuffer(const DumpedBuffer&                  buffer,
                    DumpedRawData&                       data,
                    const VulkanDeviceInfo*              device_info,
                    const graphics::VulkanDeviceTable*   device_table,
                    const graphics::VulkanInstanceTable* instance_table,
                    CommonObjectInfoTable&               object_info_table);

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

std::string ShaderStageFlagsToString(VkShaderStageFlags flags);

void ShaderStageFlagsToStageNames(VkShaderStageFlags flags, std::vector<std::string>& stage_names);

std::vector<VkPipelineBindPoint> ShaderStageFlagsToPipelineBindPoints(VkShaderStageFlags flags);

uint32_t FindTransferQueueFamilyIndex(const VulkanDeviceInfo::EnabledQueueFamilyFlags& families);

static constexpr VkExtent3D ScaleToMipLevel(const VkExtent3D& extent, uint32_t level)
{
    const VkExtent3D mip_extent = VkExtent3D{ std::max(1u, extent.width >> level),
                                              std::max(1u, extent.height >> level),
                                              std::max(1u, extent.depth >> level) };

    return mip_extent;
}

static constexpr VkExtent3D ScaleExtent(const VkExtent3D& extent, float scale)
{
    const VkExtent3D scaled_extent =
        VkExtent3D{ static_cast<uint32_t>(std::max(1.0f, static_cast<float>(extent.width) * scale)),
                    static_cast<uint32_t>(std::max(1.0f, static_cast<float>(extent.height) * scale)),
                    static_cast<uint32_t>(std::max(1.0f, static_cast<float>(extent.depth) * scale)) };

    return scaled_extent;
}

static constexpr VkImageSubresourceRange FilterImageSubresourceRange(const VkImageSubresourceRange& subresource_range,
                                                                     const VulkanImageInfo*         image_info)
{
    GFXRECON_ASSERT(image_info != nullptr);

    VkImageSubresourceRange modified_subresource_range;
    modified_subresource_range.aspectMask = subresource_range.aspectMask;

    // Handle base mip level and count
    if (subresource_range.baseMipLevel > image_info->level_count)
    {
        modified_subresource_range.baseMipLevel = 0;
    }
    else
    {
        modified_subresource_range.baseMipLevel = subresource_range.baseMipLevel;
    }

    if (subresource_range.levelCount == VK_REMAINING_MIP_LEVELS)
    {
        modified_subresource_range.levelCount = image_info->level_count - modified_subresource_range.baseMipLevel;
    }
    else
    {
        modified_subresource_range.levelCount = std::min(image_info->level_count, subresource_range.levelCount);
    }

    // Handle base array layer and count
    if (subresource_range.baseArrayLayer > image_info->layer_count)
    {
        modified_subresource_range.baseArrayLayer = 0;
    }
    else
    {
        modified_subresource_range.baseArrayLayer = subresource_range.baseArrayLayer;
    }

    if (subresource_range.layerCount == VK_REMAINING_ARRAY_LAYERS)
    {
        modified_subresource_range.layerCount = image_info->layer_count - modified_subresource_range.baseArrayLayer;
    }
    else
    {
        modified_subresource_range.layerCount = std::min(image_info->layer_count, subresource_range.layerCount);
    }

    return modified_subresource_range;
}

bool CullDescriptor(CommandImageSubresourceIterator cmd_subresources_entry,
                    uint32_t                        desc_set,
                    uint32_t                        binding,
                    uint32_t                        array_index,
                    VkImageSubresourceRange*        subresource_range = nullptr);

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
