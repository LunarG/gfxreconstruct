/*
** Copyright (c) 2024-2025 LunarG, Inc.
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

#include "decode/vulkan_device_address_tracker.h"
#include "decode/common_object_info_table.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_object_info_table.h"
#include "decode/vulkan_replay_options.h"
#include "format/format.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "util/logging.h"
#include "util/defines.h"
#include "util/options.h"

#include <bit>
#include <cstdint>
#include <memory>
#include <utility>
#include <list>
#include <variant>
#include <vector>
#include <vulkan/vulkan_core.h>

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

enum class DumpResourcesPipelineStage
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
    kAccelerationStructure
};

using DumpedHostData      = std::vector<uint8_t>;
using DumpedImageHostData = std::vector<DumpedHostData>;

struct AccelerationStructureDumpedHostData
{
    struct TrianglesBuffers
    {
        DumpedHostData vertex_buffer;
        DumpedHostData index_buffer;
        DumpedHostData transform_buffer;
    };

    struct AABBBuffer
    {
        DumpedHostData aabb_buffer;
    };

    struct InstanceBuffer
    {
        DumpedHostData instance_buffer;
    };

    std::vector<std::variant<std::monostate, TrianglesBuffers, AABBBuffer, InstanceBuffer>> build_data;

    DumpedHostData serialized_data;

    // Used only by TLASes
    std::vector<AccelerationStructureDumpedHostData> blass_dumped_data;
};

enum ImageDumpResult
{
    kCanDump,
    kCanNotResolve,
    kFormatNotSupported
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

    DumpedBuffer(VkBuffer buffer, format::HandleId id, VkDeviceSize o, VkDeviceSize s) : DumpedFile(s), offset(o)
    {
        buffer_info.handle     = buffer;
        buffer_info.capture_id = id;
    }

    DumpedBuffer(VkBuffer buffer, VkDeviceSize s) : DumpedFile(s), offset(0)
    {
        buffer_info.handle     = buffer;
        buffer_info.capture_id = format::kNullHandleId;
    }

    DumpedBuffer(VkDeviceSize s) : DumpedFile(s), offset(0)
    {
        buffer_info.handle     = VK_NULL_HANDLE;
        buffer_info.capture_id = format::kNullHandleId;
    }

    struct
    {
        VkBuffer         handle{ VK_NULL_HANDLE };
        format::HandleId capture_id{ format::kNullHandleId };
    } buffer_info;

    VkDeviceSize offset{ 0 };

    void CopyDumpedInfo(const DumpedBuffer& other)
    {
        buffer_info.handle     = other.buffer_info.handle;
        buffer_info.capture_id = other.buffer_info.capture_id;
        offset                 = other.offset;
        filename               = other.filename;
        size                   = other.size;
        compressed_size        = other.compressed_size;
    }
};

struct DumpedImage
{
    DumpedImage() = default;

    DumpedImage(const VulkanImageInfo* i_f, ImageDumpResult cd) :
        image_info(i_f), scaling_failed(false), dumped_raw(false), can_dump(cd)
    {}

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

    ImageDumpResult can_dump;
};

struct DumpedAccelerationStructure
{
    static constexpr uint32_t instance_buffer_stride{ static_cast<uint32_t>(
        sizeof(VkAccelerationStructureInstanceKHR)) };

    DumpedAccelerationStructure() = delete;

    DumpedAccelerationStructure(const VulkanAccelerationStructureKHRInfo* as_info, bool dump_input_buffers) :
        as_info(as_info), dump_build_input_buffers(dump_input_buffers)
    {}

    void CopyDumpedInfo(const DumpedAccelerationStructure& other)
    {
        input_buffers            = other.input_buffers;
        serialized_buffer        = other.serialized_buffer;
        dump_build_input_buffers = other.dump_build_input_buffers;
        as_info                  = other.as_info;
        BLASes                   = other.BLASes;
    }

    struct DumpedBuildInputTriangleBuffer
    {
        DumpedBuildInputTriangleBuffer() = delete;

        DumpedBuildInputTriangleBuffer(VkFormat                                        vf,
                                       uint32_t                                        mv,
                                       VkBuffer                                        vb,
                                       VkDeviceSize                                    vbs,
                                       VkDeviceSize                                    strd,
                                       VkIndexType                                     it,
                                       VkBuffer                                        ib,
                                       VkDeviceSize                                    ibs,
                                       VkBuffer                                        tb,
                                       VkDeviceSize                                    tbs,
                                       const VkAccelerationStructureBuildRangeInfoKHR& r) :
            vertex_format(vf),
            max_vertex(mv), vertex_buffer_stride(strd), vertex_buffer(vb, vbs), index_type(it), index_buffer(ib, ibs),
            transform_buffer(tb, tbs), range(r)
        {}

        VkFormat     vertex_format{ VK_FORMAT_UNDEFINED };
        uint32_t     max_vertex{ 0 };
        VkDeviceSize vertex_buffer_stride{ 0 };
        DumpedBuffer vertex_buffer;

        VkIndexType  index_type{ VK_INDEX_TYPE_NONE_KHR };
        DumpedBuffer index_buffer;

        DumpedBuffer transform_buffer;

        VkAccelerationStructureBuildRangeInfoKHR range;
    };

    struct DumpedBuildInputAABBBuffer
    {
        DumpedBuildInputAABBBuffer() = delete;

        DumpedBuildInputAABBBuffer(VkBuffer b, VkDeviceSize bs, const VkAccelerationStructureBuildRangeInfoKHR& r) :
            aabb_buffer(b, bs), range(r)
        {}

        DumpedBuffer aabb_buffer;

        VkAccelerationStructureBuildRangeInfoKHR range;
    };

    struct DumpedBuildInputInstanceBuffer
    {
        DumpedBuildInputInstanceBuffer(VkBuffer buffer, VkDeviceSize s) : instance_buffer(buffer, s) {}

        DumpedBuffer instance_buffer;
    };

    std::vector<std::variant<std::monostate,
                             DumpedBuildInputTriangleBuffer,
                             DumpedBuildInputAABBBuffer,
                             DumpedBuildInputInstanceBuffer>>
        input_buffers;

    const VulkanAccelerationStructureKHRInfo* as_info;
    bool                                      dump_build_input_buffers;
    DumpedBuffer                              serialized_buffer;

    // Used by TLASes
    std::vector<DumpedAccelerationStructure> BLASes;
};

struct DumpedResourceBase
{
    DumpedResourceBase() = default;

    DumpedResourceBase(DumpResourceType t, DumpResourcesPipelineStage ps, uint64_t bcb, uint64_t cmd, uint64_t qs) :
        type(t), ppl_stage(ps), bcb_index(bcb), cmd_index(cmd), qs_index(qs)
    {}

    DumpedResourceBase(DumpResourceType           t,
                       DumpResourcesPipelineStage ps,
                       uint64_t                   bcb,
                       uint64_t                   cmd,
                       uint64_t                   qs,
                       uint64_t                   rp,
                       uint64_t                   sp) :
        type(t),
        ppl_stage(ps), bcb_index(bcb), cmd_index(cmd), qs_index(qs), render_pass(rp), subpass(sp)
    {}

    DumpedResourceBase(DumpResourceType t, DumpResourcesPipelineStage ps, uint64_t cmd, uint64_t qs) :
        type(t), ppl_stage(ps), bcb_index(0), cmd_index(cmd), qs_index(qs), render_pass(0), subpass(0)
    {}

    DumpResourceType type{ DumpResourceType::kNone };

    DumpResourcesPipelineStage ppl_stage{ DumpResourcesPipelineStage::kNone };

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
    DumpedVertexIndexBuffer(DumpResourceType t,
                            uint64_t         bcb,
                            uint64_t         cmd,
                            uint64_t         qs,
                            uint32_t         b,
                            VkBuffer         buffer,
                            format::HandleId id,
                            VkDeviceSize     s,
                            VkDeviceSize     o) :
        DumpedResourceBase(t, DumpResourcesPipelineStage::kGraphics, bcb, cmd, qs),
        buffer(buffer, id, o, s), binding(b)
    {}

    // For index buffers
    DumpedVertexIndexBuffer(DumpResourceType t,
                            uint64_t         bcb,
                            uint64_t         cmd,
                            uint64_t         qs,
                            VkIndexType      it,
                            VkBuffer         buffer,
                            format::HandleId id,
                            VkDeviceSize     s,
                            VkDeviceSize     o) :
        DumpedResourceBase(t, DumpResourcesPipelineStage::kGraphics, bcb, cmd, qs),
        buffer(buffer, id, o, s), index_type(it)
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
    DumpedDescriptor(DumpResourceType           t,
                     uint64_t                   bcb,
                     uint64_t                   cmd,
                     uint64_t                   qs,
                     uint64_t                   rp,
                     uint64_t                   sp,
                     VkShaderStageFlags         ss,
                     VkDescriptorType           dt,
                     uint32_t                   s,
                     uint32_t                   b,
                     uint32_t                   ai,
                     VkBuffer                   buffer,
                     format::HandleId           id,
                     VkDeviceSize               offset,
                     VkDeviceSize               size,
                     DumpResourcesPipelineStage ps) :
        DumpedResourceBase(t, ps, bcb, cmd, qs, rp, sp),
        stages(ss), desc_type(dt), set(s), binding(b), array_index(ai),
        dumped_resource(std::in_place_type<DumpedBuffer>, buffer, id, offset, size)
    {}

    // Inline uniform buffers for graphics
    DumpedDescriptor(DumpResourceType           t,
                     uint64_t                   bcb,
                     uint64_t                   cmd,
                     uint64_t                   qs,
                     uint64_t                   rp,
                     uint64_t                   sp,
                     VkShaderStageFlags         ss,
                     VkDescriptorType           dt,
                     uint32_t                   s,
                     uint32_t                   b,
                     DumpResourcesPipelineStage ps) :
        DumpedResourceBase(t, ps, bcb, cmd, qs, rp, sp),
        stages(ss), desc_type(dt), set(s), binding(b), array_index(0),
        dumped_resource(std::in_place_type<DumpedBuffer>, 0)
    {}

    // Graphics image descriptors
    DumpedDescriptor(DumpResourceType           t,
                     uint64_t                   bcb,
                     uint64_t                   cmd,
                     uint64_t                   qs,
                     uint64_t                   rp,
                     uint64_t                   sp,
                     VkShaderStageFlags         ss,
                     VkDescriptorType           dt,
                     uint32_t                   s,
                     uint32_t                   b,
                     uint32_t                   ai,
                     const VulkanImageInfo*     img_info,
                     ImageDumpResult            cd,
                     DumpResourcesPipelineStage ps) :
        DumpedResourceBase(t, ps, bcb, cmd, qs, rp, sp),
        stages(ss), desc_type(dt), set(s), binding(b), array_index(ai),
        dumped_resource(std::in_place_type<DumpedImage>, img_info, cd)
    {}

    // Dispatch ray tracing image descriptors
    DumpedDescriptor(DumpResourceType           t,
                     uint64_t                   bcb,
                     uint64_t                   cmd,
                     uint64_t                   qs,
                     VkShaderStageFlags         ss,
                     VkDescriptorType           dt,
                     uint32_t                   s,
                     uint32_t                   b,
                     uint32_t                   ai,
                     const VulkanImageInfo*     img_info,
                     ImageDumpResult            cd,
                     DumpResourcesPipelineStage ps) :
        DumpedResourceBase(t, ps, bcb, cmd, qs),
        stages(ss), desc_type(dt), set(s), binding(b), array_index(ai),
        dumped_resource(std::in_place_type<DumpedImage>, img_info, cd)
    {}

    // Dispatch ray tracing buffer descriptors
    DumpedDescriptor(DumpResourceType           t,
                     uint64_t                   bcb,
                     uint64_t                   cmd,
                     uint64_t                   qs,
                     VkShaderStageFlags         ss,
                     VkDescriptorType           dt,
                     uint32_t                   s,
                     uint32_t                   b,
                     uint32_t                   ai,
                     VkBuffer                   buffer,
                     format::HandleId           id,
                     VkDeviceSize               offset,
                     VkDeviceSize               size,
                     DumpResourcesPipelineStage ps) :
        DumpedResourceBase(t, ps, bcb, cmd, qs),
        stages(ss), desc_type(dt), set(s), binding(b), array_index(ai),
        dumped_resource(std::in_place_type<DumpedBuffer>, buffer, id, offset, size)
    {}

    // Dispatch ray tracing inline uniform buffers
    DumpedDescriptor(DumpResourceType           t,
                     uint64_t                   bcb,
                     uint64_t                   cmd,
                     uint64_t                   qs,
                     VkShaderStageFlags         ss,
                     VkDescriptorType           dt,
                     uint32_t                   s,
                     uint32_t                   b,
                     DumpResourcesPipelineStage ps) :
        DumpedResourceBase(t, ps, bcb, cmd, qs),
        stages(ss), desc_type(dt), set(s), binding(b), array_index(0),
        dumped_resource(std::in_place_type<DumpedBuffer>, 0)
    {}

    // Acceleration structure for TraceRays
    DumpedDescriptor(DumpResourceType                          t,
                     uint64_t                                  bcb,
                     uint64_t                                  cmd,
                     uint64_t                                  qs,
                     VkShaderStageFlags                        ss,
                     VkDescriptorType                          dt,
                     uint32_t                                  s,
                     uint32_t                                  b,
                     uint32_t                                  ai,
                     const VulkanAccelerationStructureKHRInfo* as_info,
                     bool                                      dbib,
                     DumpResourcesPipelineStage                ps) :
        DumpedResourceBase(t, ps, bcb, cmd, qs),
        stages(ss), desc_type(dt), set(s), binding(b), array_index(ai),
        dumped_resource(std::in_place_type<DumpedAccelerationStructure>, as_info, dbib)
    {}

    // The dumped resource
    std::variant<std::monostate, DumpedImage, DumpedBuffer, DumpedAccelerationStructure> dumped_resource;

    bool has_before{ false };

    // The dumped resource before the execution of the command.
    // Used only when --dump-resources-before-draw is used.
    std::variant<std::monostate, DumpedImage, DumpedBuffer> dumped_resource_before;

    VkShaderStageFlags stages{ VkShaderStageFlagBits(0) };

    VkDescriptorType desc_type{ VK_DESCRIPTOR_TYPE_MAX_ENUM };
    uint32_t         set{ 0 };
    uint32_t         binding{ 0 };
    uint32_t         array_index{ 0 };
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
                       const VulkanImageInfo* img_info,
                       ImageDumpResult        cd) :
        DumpedResourceBase(t, DumpResourcesPipelineStage::kGraphics, bcb, cmd, qs, rp, sp),
        location(l), dumped_image(img_info, cd)
    {
        if (before)
        {
            dumped_image_before = DumpedImage(img_info, cd);
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

struct AccelerationStructureDumpResourcesContext
{
    AccelerationStructureDumpResourcesContext() = delete;

    AccelerationStructureDumpResourcesContext(const VulkanAccelerationStructureKHRInfo* ai,
                                              const graphics::VulkanDeviceTable&        dt,
                                              const CommonObjectInfoTable&              oit,
                                              const VulkanPerDeviceAddressTrackers&     at) :
        as_info(ai),
        device_table(dt), object_info_table(oit), address_trackers(at)
    {}

    ~AccelerationStructureDumpResourcesContext() { ReleaseResources(); }

    struct Triangles
    {
        VkFormat       vertex_format{ VK_FORMAT_UNDEFINED };
        uint32_t       max_vertex{ 0 };
        VkDeviceSize   vertex_buffer_size{ 0 };
        VkDeviceSize   vertex_buffer_stride{ 0 };
        VkBuffer       vertex_buffer{ VK_NULL_HANDLE };
        VkDeviceMemory vertex_buffer_memory{ VK_NULL_HANDLE };

        VkIndexType    index_type{ VK_INDEX_TYPE_NONE_KHR };
        VkDeviceSize   index_buffer_size{ 0 };
        VkBuffer       index_buffer{ VK_NULL_HANDLE };
        VkDeviceMemory index_buffer_memory{ VK_NULL_HANDLE };

        VkDeviceSize   transform_buffer_size{ 0 };
        VkBuffer       transform_buffer{ VK_NULL_HANDLE };
        VkDeviceMemory transform_buffer_memory{ VK_NULL_HANDLE };

        VkAccelerationStructureBuildRangeInfoKHR range;
    };

    struct AABBS
    {
        VkDeviceSize   buffer_size{ 0 };
        VkBuffer       buffer{ VK_NULL_HANDLE };
        VkDeviceMemory buffer_memory{ VK_NULL_HANDLE };

        VkAccelerationStructureBuildRangeInfoKHR range;
    };

    struct Instances
    {
        bool array_of_pointers{ false };

        uint32_t       instance_count{ 0 };
        uint32_t       instance_buffer_size{ 0 };
        VkBuffer       instance_buffer{ VK_NULL_HANDLE };
        VkDeviceMemory instance_buffer_memory{ VK_NULL_HANDLE };

        // Used to fetch the instance buffers in case
        // VkAccelerationStructureGeometryInstancesDataKHR.arrayOfPointers is true
        VkPipeline       compute_ppl{ VK_NULL_HANDLE };
        VkPipelineLayout compute_ppl_layout{ VK_NULL_HANDLE };
    };

    std::vector<std::variant<std::monostate, Triangles, AABBS, Instances>> as_build_objects;

    struct
    {
        VkDeviceSize   size{ 0 };
        VkBuffer       buffer{ VK_NULL_HANDLE };
        VkDeviceMemory memory{ VK_NULL_HANDLE };
    } serialized_data;

    // Clones buffers used as inputs in vkCmdBuildAccelerationStructuresKHR command.
    VkResult CloneBuildAccelerationStructuresInputBuffers(
        VkCommandBuffer                                            original_command_buffer,
        const Decoded_VkAccelerationStructureBuildGeometryInfoKHR* p_infos_meta,
        const VkAccelerationStructureBuildRangeInfoKHR*            range_infos,
        bool                                                       dump_as_build_input_buffers);

    // Clones input buffers from src_context
    VkResult CloneBuildAccelerationStructuresInputBuffers(VkCommandBuffer original_command_buffer,
                                                          const AccelerationStructureDumpResourcesContext& src_context,
                                                          bool dump_as_build_input_buffers);

    void ReleaseResources();

    const graphics::VulkanDeviceTable&        device_table;
    const CommonObjectInfoTable&              object_info_table;
    const VulkanAccelerationStructureKHRInfo* as_info;
    const VulkanPerDeviceAddressTrackers&     address_trackers;
};

using DumpResourcesAccelerationStructuresContext =
    std::unordered_map<const VulkanAccelerationStructureKHRInfo*,
                       std::shared_ptr<AccelerationStructureDumpResourcesContext>>;

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

VkResult CloneImage(const CommonObjectInfoTable&            object_info_table,
                    const graphics::VulkanDeviceTable*      device_table,
                    const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props,
                    const VulkanImageInfo*                  image_info,
                    VkImage*                                new_image,
                    VkDeviceMemory*                         new_image_memory);

VkResult CloneBuffer(const CommonObjectInfoTable&            object_info_table,
                     const graphics::VulkanDeviceTable*      device_table,
                     const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props,
                     const VulkanBufferInfo*                 buffer_info,
                     VkBuffer*                               new_buffer,
                     VkDeviceMemory*                         new_buffer_memory,
                     VkDeviceSize                            override_size = 0);

void FreeAccelerationStructureContextResources(const graphics::VulkanDeviceTable&         device_table,
                                               VkDevice                                   device,
                                               AccelerationStructureDumpResourcesContext& as_context);

uint32_t VkIndexTypeToBytes(VkIndexType type);

MinMaxVertexIndex FindMinMaxVertexIndices(const std::vector<uint8_t>& index_data,
                                          uint32_t                    index_count,
                                          uint32_t                    first_index,
                                          int32_t                     vertex_offset,
                                          VkIndexType                 type);

ImageDumpResult CanDumpImage(const graphics::VulkanInstanceTable* instance_table,
                             VkPhysicalDevice                     phys_dev,
                             const VulkanImageInfo*               image_info);

// Fetch image from the GPU into host memory
VkResult DumpImage(DumpedImage&                         dumped_image,
                   VkImageLayout                        layout,
                   float                                scale,
                   bool                                 dump_image_raw,
                   const VkImageSubresourceRange&       subresource_range,
                   DumpedImageHostData&                 data,
                   const VulkanDeviceInfo*              device_info,
                   const graphics::VulkanDeviceTable*   device_table,
                   const graphics::VulkanInstanceTable* instance_table,
                   const CommonObjectInfoTable&         object_info_table);

// Fetch a buffer from the GPU into host memory
VkResult DumpBuffer(const DumpedBuffer&                  buffer,
                    DumpedHostData&                      data,
                    const VulkanDeviceInfo*              device_info,
                    const graphics::VulkanDeviceTable*   device_table,
                    const graphics::VulkanInstanceTable* instance_table,
                    const CommonObjectInfoTable&         object_info_table);

// Fetch an acceleration structure from the GPU into host memory
VkResult DumpAccelerationStructure(DumpedAccelerationStructure&                      dumped_as,
                                   AccelerationStructureDumpedHostData&              dumped_as_data,
                                   AccelerationStructureDumpResourcesContext*        as_context,
                                   const DumpResourcesAccelerationStructuresContext& acceleration_structures_context,
                                   const VulkanDeviceInfo*                           device_info,
                                   const graphics::VulkanDeviceTable&                device_table,
                                   const CommonObjectInfoTable&                      object_info_table,
                                   const graphics::VulkanInstanceTable&              instance_table,
                                   const VulkanPerDeviceAddressTrackers&             address_trackers);

std::string ShaderStageToStr(VkShaderStageFlagBits shader_stage);

std::string ImageAspectToStr(VkImageAspectFlagBits aspect);

std::string FormatToStr(VkFormat format);

std::string IndexTypeToStr(VkIndexType type);

VkResult CreateVkBuffer(VkDeviceSize                            size,
                        const graphics::VulkanDeviceTable&      device_table,
                        VkDevice                                parent_device,
                        const VkBaseInStructure*                pNext,
                        const VkBaseInStructure*                allocate_memory_info_pNext,
                        const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props,
                        VkBufferUsageFlags                      usage_flags,
                        VkBuffer*                               new_buffer,
                        VkDeviceMemory*                         new_memory);

std::string ShaderStageFlagsToString(VkShaderStageFlags flags);

void ShaderStageFlagsToStageNames(VkShaderStageFlags flags, std::vector<std::string>& stage_names);

std::vector<VkPipelineBindPoint> ShaderStageFlagsToPipelineBindPoints(VkShaderStageFlags flags);

uint32_t FindTransferQueueFamilyIndex(const VulkanDeviceInfo::EnabledQueueFamilyFlags& families);

uint32_t FindComputeQueueFamilyIndex(const VulkanDeviceInfo::EnabledQueueFamilyFlags& families);

using FindQueueFamilyIndex_fp = uint32_t(const VulkanDeviceInfo::EnabledQueueFamilyFlags&);

struct TemporaryCommandBuffer
{
    TemporaryCommandBuffer() = default;
    TemporaryCommandBuffer(const TemporaryCommandBuffer& other)
    {
        device_info    = other.device_info;
        device_table   = other.device_table;
        command_pool   = other.command_pool;
        command_buffer = other.command_buffer;
        queue          = other.queue;
    }

    const VulkanDeviceInfo*            device_info{ nullptr };
    const graphics::VulkanDeviceTable* device_table{ nullptr };

    VkCommandPool   command_pool   = VK_NULL_HANDLE;
    VkCommandBuffer command_buffer = VK_NULL_HANDLE;
    VkQueue         queue          = VK_NULL_HANDLE;
};

VkResult CreateAndBeginCommandBuffer(FindQueueFamilyIndex_fp*           queue_finder_fp,
                                     const VulkanDeviceInfo*            device_info,
                                     const graphics::VulkanDeviceTable& device_table,
                                     TemporaryCommandBuffer&            cmd_buf_objects);

VkResult SubmitAndDestroyCommandBuffer(const TemporaryCommandBuffer& cmd_buf_objects);

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
