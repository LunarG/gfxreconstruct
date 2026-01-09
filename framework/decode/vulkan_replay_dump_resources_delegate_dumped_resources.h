/*
** Copyright (c) 2025 LunarG, Inc.
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

#ifndef GFXRECON_VULKAN_REPLAY_DUMP_RESOURCES_DELEGATE_DUMPED_RESOURCES_COMMON_H
#define GFXRECON_VULKAN_REPLAY_DUMP_RESOURCES_DELEGATE_DUMPED_RESOURCES_COMMON_H

#include "decode/vulkan_object_info.h"
#include "decode/vulkan_replay_dump_resources_as.h"
#include "util/defines.h"
#include "format/format.h"

#include <list>
#include <stdint.h>
#include <string>
#include <variant>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

enum class DumpResourcesPipelineStage
{
    kNone,
    kGraphics,
    kCompute,
    kRayTracing,
    kTransfer
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
    kAccelerationStructure,
    // Transfer related types
    kInitBufferMetaCommand,
    kInitImageMetaCommand,
    kCopyBuffer,
    kCopyBufferToImage,
    kCopyImage,
    kCopyImageToBuffer,
    kBlitImage,
    kBuildAccelerationStructure,
    kCopyAccelerationStructure,
};

using DumpedHostData                  = std::vector<uint8_t>;
using DumpedImageHostData             = std::vector<DumpedHostData>;
using DumpedCopyBufferRegionsHostData = std::vector<DumpedHostData>;
using DumpedCopyImageRegionsHostData  = std::vector<DumpedImageHostData>;

struct AccelerationStructureDumpedHostData
{
    void clear()
    {
        build_data.clear();
        serialized_data.clear();
        blass_dumped_data.clear();
    }

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

    DumpedBuffer(VkBuffer buffer, format::HandleId id, VkDeviceSize o, VkDeviceSize s) :
        DumpedFile(s), buffer_info(buffer, id), offset(o)
    {}

    DumpedBuffer(VkBuffer buffer, VkDeviceSize s) : DumpedFile(s), buffer_info(buffer, format::kNullHandleId), offset(0)
    {}

    DumpedBuffer(VkDeviceSize s) : DumpedFile(s), buffer_info(VK_NULL_HANDLE, format::kNullHandleId), offset(0) {}

    struct BufferInfo
    {
        BufferInfo() = default;
        BufferInfo(VkBuffer b, format::HandleId id) : handle(b), capture_id(id) {}

        VkBuffer         handle{ VK_NULL_HANDLE };
        format::HandleId capture_id{ format::kNullHandleId };
    };

    BufferInfo buffer_info;

    VkDeviceSize offset{ 0 };

    DumpedBuffer& operator=(const DumpedBuffer& other)
    {
        if (this == &other)
        {
            return *this;
        }

        buffer_info.handle     = other.buffer_info.handle;
        buffer_info.capture_id = other.buffer_info.capture_id;
        offset                 = other.offset;
        filename               = other.filename;
        size                   = other.size;
        compressed_size        = other.compressed_size;

        return *this;
    }
};

struct DumpedImage
{
    DumpedImage() = default;

    DumpedImage(const VulkanImageInfo* inf, ImageDumpResult cd) :
        image_info(inf), scaling_failed(false), dumped_raw(false), dumped_format(VK_FORMAT_UNDEFINED), can_dump(cd)
    {}

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

    DumpedImage& operator=(const DumpedImage& other)
    {
        if (this == &other)
        {
            return *this;
        }

        image_info          = other.image_info;
        scaling_failed      = other.scaling_failed;
        dumped_raw          = other.dumped_raw;
        dumped_format       = other.dumped_format;
        can_dump            = other.can_dump;
        dumped_subresources = other.dumped_subresources;

        return *this;
    }

    const VulkanImageInfo* image_info;
    bool                   scaling_failed;
    bool                   dumped_raw;
    VkFormat               dumped_format;

    // Scaling is done with vkCmdBlitImage. It is possible that an implementation does not supporting blit for some
    // specific formats. In these cases, since we can't scale the images with BlitImage, we dump them in their original
    // dimensions and mark them with an entry in the output json.
    ImageDumpResult can_dump;

    std::vector<DumpedImageSubresource> dumped_subresources;
};

struct DumpedAccelerationStructure
{
    static constexpr uint32_t instance_buffer_stride{ static_cast<uint32_t>(
        sizeof(VkAccelerationStructureInstanceKHR)) };

    DumpedAccelerationStructure() = delete;

    DumpedAccelerationStructure(const VulkanAccelerationStructureKHRInfo* as_info, bool dump_input_buffers) :
        as_info(as_info), dump_build_input_buffers(dump_input_buffers)
    {}

    DumpedAccelerationStructure& operator=(const DumpedAccelerationStructure& other)
    {
        if (this == &other)
        {
            return *this;
        }
        input_buffers            = other.input_buffers;
        serialized_buffer        = other.serialized_buffer;
        dump_build_input_buffers = other.dump_build_input_buffers;
        as_info                  = other.as_info;
        BLASes                   = other.BLASes;

        return *this;
    }

    struct DumpedBuildInputTriangleBuffer
    {
        DumpedBuildInputTriangleBuffer() = delete;

        DumpedBuildInputTriangleBuffer(const AccelerationStructureDumpResourcesContext::Triangles& triangles) :
            vertex_format(triangles.vertex_format), max_vertex(triangles.max_vertex),
            vertex_buffer_stride(triangles.vertex_buffer_stride),
            vertex_buffer(triangles.vertex_buffer, triangles.vertex_buffer_size), index_type(triangles.index_type),
            index_buffer(triangles.index_buffer, triangles.index_buffer_size),
            transform_buffer(triangles.transform_buffer, triangles.transform_buffer_size), range(triangles.range)
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

        DumpedBuildInputAABBBuffer(const AccelerationStructureDumpResourcesContext::AABBS& aabbs) :
            aabb_buffer(aabbs.buffer, aabbs.buffer_size), range(aabbs.range){};

        DumpedBuffer aabb_buffer;

        VkAccelerationStructureBuildRangeInfoKHR range;
    };

    struct DumpedBuildInputInstanceBuffer
    {
        DumpedBuildInputInstanceBuffer() = delete;
        DumpedBuildInputInstanceBuffer(const AccelerationStructureDumpResourcesContext::Instances& instance) :
            instance_buffer(instance.instance_buffer, static_cast<VkDeviceSize>(instance.instance_buffer_size))
        {}

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

struct TransferedImageInfo
{
    TransferedImageInfo() = delete;

    TransferedImageInfo(format::HandleId i, VkFormat f, VkExtent3D e, VkImageLayout l) :
        id(i), format(f), extent(e), layout(l)
    {}

    TransferedImageInfo(const TransferedImageInfo& other) :
        id(other.id), format(other.format), extent(other.extent), layout(other.layout)
    {}

    format::HandleId id;
    VkFormat         format;
    VkExtent3D       extent;
    VkImageLayout    layout;
};

struct DumpedInitBufferMetaCommand
{
    DumpedInitBufferMetaCommand() = delete;

    DumpedInitBufferMetaCommand(format::HandleId b, VkDeviceSize s) : buffer(b), dumped_buffer(s) {}

    format::HandleId buffer;
    DumpedBuffer     dumped_buffer;
};

struct DumpedInitImageMetaCommand
{
    DumpedInitImageMetaCommand() = delete;

    DumpedInitImageMetaCommand(const TransferedImageInfo& transf_img_inf, const VulkanImageInfo* img_inf) :
        image(transf_img_inf), dumped_image(img_inf, ImageDumpResult::kCanDump)
    {}

    TransferedImageInfo image;
    DumpedImage         dumped_image;
};

struct DumpedCopyBuffer
{
    DumpedCopyBuffer() = delete;

    DumpedCopyBuffer(format::HandleId s, format::HandleId d) : src_buffer(s), dst_buffer(d) {}

    struct CopyRegion
    {
        CopyRegion() = delete;
        CopyRegion(const VkBufferCopy& r, VkBuffer b, VkDeviceSize sz) : region(r), dumped_buffer(b, sz) {}

        VkBufferCopy region;
        DumpedBuffer dumped_buffer;
    };

    std::vector<CopyRegion> regions;

    format::HandleId src_buffer;
    format::HandleId dst_buffer;
};

struct DumpedCopyBufferToImage
{
    DumpedCopyBufferToImage() = delete;

    DumpedCopyBufferToImage(format::HandleId s, const TransferedImageInfo& transf_img_info) :
        src_buffer(s), dst_image(transf_img_info)
    {}

    struct CopyRegion
    {
        CopyRegion() = delete;
        CopyRegion(const VkBufferImageCopy& r, const VulkanImageInfo* img_inf, ImageDumpResult cd) :
            region(r), dumped_image(img_inf, cd)
        {}

        VkBufferImageCopy region;
        DumpedImage       dumped_image;
    };

    std::vector<CopyRegion> regions;

    format::HandleId    src_buffer;
    TransferedImageInfo dst_image;
};

struct DumpedCopyImage
{
    DumpedCopyImage() = delete;

    DumpedCopyImage(const TransferedImageInfo& src_img, const TransferedImageInfo& dst_img) :
        src_image(src_img), dst_image(dst_img)
    {}

    struct CopyRegion
    {
        CopyRegion() = delete;
        CopyRegion(const VkImageCopy& r, const VulkanImageInfo* img_inf, ImageDumpResult cd) :
            dumped_image(img_inf, cd), region(r)
        {}

        DumpedImage dumped_image;
        VkImageCopy region;
    };

    std::vector<CopyRegion> regions;

    TransferedImageInfo src_image;
    TransferedImageInfo dst_image;
};

struct DumpedCopyImageToBuffer
{
    DumpedCopyImageToBuffer() = delete;

    DumpedCopyImageToBuffer(const TransferedImageInfo& si, format::HandleId d) : src_image(si), dst_buffer(d) {}

    struct CopyRegion
    {
        CopyRegion() = delete;
        CopyRegion(const VkBufferImageCopy& r, VkBuffer b, VkDeviceSize sz) : region(r), dumped_buffer(b, sz) {}

        VkBufferImageCopy region;
        DumpedBuffer      dumped_buffer;
    };

    std::vector<CopyRegion> regions;

    TransferedImageInfo src_image;
    format::HandleId    dst_buffer;
};

struct DumpedBlitImage
{
    DumpedBlitImage() = delete;

    DumpedBlitImage(const TransferedImageInfo& si, const TransferedImageInfo& di, VkFilter f) :
        src_image(si), dst_image(di), filter(f)
    {}

    struct CopyRegion
    {
        CopyRegion() = delete;
        CopyRegion(const VkImageBlit& r, const VulkanImageInfo* img_inf, ImageDumpResult cd) :
            dumped_image(img_inf, cd), region(r)
        {}

        DumpedImage dumped_image;
        VkImageBlit region;
    };

    std::vector<CopyRegion> regions;

    TransferedImageInfo src_image;
    TransferedImageInfo dst_image;

    VkFilter filter;
};

struct AccelerationStructureTransfer
{
    AccelerationStructureTransfer() = delete;

    AccelerationStructureTransfer(format::HandleId                          s,
                                  format::HandleId                          d,
                                  uint32_t                                  m,
                                  const VulkanAccelerationStructureKHRInfo* as_info,
                                  bool                                      dump_input_buffers) :
        dumped_as(as_info, dump_input_buffers),
        src_as(s), dst_as(d), mode(m)
    {}

    format::HandleId src_as;
    format::HandleId dst_as;
    uint32_t         mode;

    DumpedAccelerationStructure dumped_as;
};

struct DumpedBuildAccelerationStructure
{
    std::vector<AccelerationStructureTransfer> dumped_build_infos;
};

struct DumpedCopyAccelerationStructure
{
    DumpedCopyAccelerationStructure() = delete;

    DumpedCopyAccelerationStructure(format::HandleId                          s,
                                    format::HandleId                          d,
                                    VkCopyAccelerationStructureModeKHR        m,
                                    const VulkanAccelerationStructureKHRInfo* as_info,
                                    bool                                      dump_input_buffers) :
        dumped_copy_info(s, d, m, as_info, dump_input_buffers)
    {}

    AccelerationStructureTransfer dumped_copy_info;
};

struct DumpedTransferCommand : DumpedResourceBase
{
    DumpedTransferCommand() = delete;

    // InitBufferMetaCommand
    DumpedTransferCommand(DumpResourceType t, uint64_t cmd, uint64_t qs, format::HandleId b, VkDeviceSize s) :
        DumpedResourceBase(t, DumpResourcesPipelineStage::kTransfer, cmd, qs),
        dumped_resource(std::in_place_type<DumpedInitBufferMetaCommand>, b, s), has_before(false)
    {
        GFXRECON_ASSERT(t == DumpResourceType::kInitBufferMetaCommand);
    }

    // InitImageMetaCommand
    DumpedTransferCommand(DumpResourceType           t,
                          uint64_t                   cmd,
                          uint64_t                   qs,
                          const TransferedImageInfo& transf_img_info,
                          const VulkanImageInfo*     img_info) :
        DumpedResourceBase(t, DumpResourcesPipelineStage::kTransfer, cmd, qs),
        dumped_resource(std::in_place_type<DumpedInitImageMetaCommand>, transf_img_info, img_info), has_before(false)
    {
        GFXRECON_ASSERT(t == DumpResourceType::kInitImageMetaCommand);
    }

    // CopyBuffer
    DumpedTransferCommand(
        DumpResourceType t, uint64_t cmd, uint64_t qs, format::HandleId s, format::HandleId d, bool hb) :
        DumpedResourceBase(t, DumpResourcesPipelineStage::kTransfer, cmd, qs),
        dumped_resource(std::in_place_type<DumpedCopyBuffer>, s, d), has_before(hb)
    {
        GFXRECON_ASSERT(t == DumpResourceType::kCopyBuffer);

        if (hb)
        {
            dumped_resource_before = DumpedCopyBuffer(s, d);
        }
    }

    // CopyBufferToImage
    DumpedTransferCommand(DumpResourceType           t,
                          uint64_t                   cmd,
                          uint64_t                   qs,
                          format::HandleId           s,
                          const TransferedImageInfo& transf_img_info,
                          bool                       hb) :
        DumpedResourceBase(t, DumpResourcesPipelineStage::kTransfer, cmd, qs),
        dumped_resource(std::in_place_type<DumpedCopyBufferToImage>, s, transf_img_info), has_before(hb)
    {
        GFXRECON_ASSERT(t == DumpResourceType::kCopyBufferToImage);

        if (hb)
        {
            dumped_resource_before = DumpedCopyBufferToImage(s, transf_img_info);
        }
    }

    // CopyImage
    DumpedTransferCommand(DumpResourceType           t,
                          uint64_t                   cmd,
                          uint64_t                   qs,
                          const TransferedImageInfo& si,
                          const TransferedImageInfo& di,
                          bool                       hb) :
        DumpedResourceBase(t, DumpResourcesPipelineStage::kTransfer, cmd, qs),
        dumped_resource(std::in_place_type<DumpedCopyImage>, si, di), has_before(hb)
    {
        GFXRECON_ASSERT(t == DumpResourceType::kCopyImage);

        if (hb)
        {
            dumped_resource_before = DumpedCopyImage(si, di);
        }
    }

    // CopyImageToBuffer
    DumpedTransferCommand(
        DumpResourceType t, uint64_t cmd, uint64_t qs, const TransferedImageInfo& si, format::HandleId d, bool hb) :
        DumpedResourceBase(t, DumpResourcesPipelineStage::kTransfer, cmd, qs),
        dumped_resource(std::in_place_type<DumpedCopyImageToBuffer>, si, d), has_before(hb)
    {
        GFXRECON_ASSERT(t == DumpResourceType::kCopyImageToBuffer);

        if (hb)
        {
            dumped_resource_before = DumpedCopyImageToBuffer(si, d);
        }
    }

    // BlitImage
    DumpedTransferCommand(DumpResourceType           t,
                          uint64_t                   cmd,
                          uint64_t                   qs,
                          const TransferedImageInfo& si,
                          const TransferedImageInfo& di,
                          VkFilter                   f,
                          bool                       hb) :
        DumpedResourceBase(t, DumpResourcesPipelineStage::kTransfer, cmd, qs),
        dumped_resource(std::in_place_type<DumpedBlitImage>, si, di, f), has_before(hb)
    {
        GFXRECON_ASSERT(t == DumpResourceType::kBlitImage);

        if (hb)
        {
            dumped_resource_before = DumpedBlitImage(si, di, f);
        }
    }

    // Build AS
    DumpedTransferCommand(DumpResourceType t, uint64_t cmd, uint64_t qs, bool hb) :
        DumpedResourceBase(t, DumpResourcesPipelineStage::kTransfer, cmd, qs),
        dumped_resource(std::in_place_type<DumpedBuildAccelerationStructure>), has_before(hb)
    {
        GFXRECON_ASSERT(t == DumpResourceType::kBuildAccelerationStructure);

        if (hb)
        {
            dumped_resource_before = DumpedBuildAccelerationStructure();
        }
    }

    // Copy AS
    DumpedTransferCommand(DumpResourceType                          t,
                          uint64_t                                  cmd,
                          uint64_t                                  qs,
                          format::HandleId                          s,
                          format::HandleId                          d,
                          VkCopyAccelerationStructureModeKHR        m,
                          const VulkanAccelerationStructureKHRInfo* as_info,
                          bool                                      dump_input_buffers,
                          bool                                      hb) :
        DumpedResourceBase(t, DumpResourcesPipelineStage::kTransfer, cmd, qs),
        dumped_resource(std::in_place_type<DumpedCopyAccelerationStructure>, s, d, m, as_info, dump_input_buffers),
        has_before(hb)
    {
        GFXRECON_ASSERT(t == DumpResourceType::kCopyAccelerationStructure);

        if (hb)
        {
            dumped_resource_before = DumpedCopyAccelerationStructure(s, d, m, as_info, dump_input_buffers);
        }
    }

    // The dumped resource
    std::variant<std::monostate,
                 DumpedInitBufferMetaCommand,
                 DumpedInitImageMetaCommand,
                 DumpedCopyBuffer,
                 DumpedCopyBufferToImage,
                 DumpedCopyImage,
                 DumpedCopyImageToBuffer,
                 DumpedBlitImage,
                 DumpedBuildAccelerationStructure,
                 DumpedCopyAccelerationStructure>
        dumped_resource;

    bool has_before{ false };

    // The dumped resource before the execution of the command.
    // Used only when --dump-resources-before-draw is used.
    std::variant<std::monostate,
                 DumpedInitBufferMetaCommand,
                 DumpedInitImageMetaCommand,
                 DumpedCopyBuffer,
                 DumpedCopyBufferToImage,
                 DumpedCopyImage,
                 DumpedCopyImageToBuffer,
                 DumpedBlitImage,
                 DumpedBuildAccelerationStructure,
                 DumpedCopyAccelerationStructure>
        dumped_resource_before;
};

struct DumpedResourcesInfo
{
    DumpedResourcesInfo() = default;

    uint64_t bcb_index{ 0 };
    uint64_t cmd_index{ 0 };
    uint64_t qs_index{ 0 };

    std::vector<DumpedVertexIndexBuffer>   dumped_vertex_index_buffers;
    std::vector<DumpedRenderTarget>        dumped_render_targets;
    std::unique_ptr<DumpedTransferCommand> dumped_transfer_command;

    // We need to keep references to inserted elements. Use a list instead of a vector
    std::list<DumpedDescriptor> dumped_descriptors;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_VULKAN_REPLAY_DUMP_RESOURCES_DELEGATE_DUMPED_RESOURCES_COMMON_H
