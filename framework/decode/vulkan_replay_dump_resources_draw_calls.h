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

#ifndef GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_DRAW_CALLS_H
#define GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_DRAW_CALLS_H

#include "decode/common_object_info_table.h"
#include "decode/vulkan_replay_dump_resources_common.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_replay_options.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "util/compressor.h"
#include "util/defines.h"
#include "vulkan/vulkan_core.h"

#include <cstdint>
#include <memory>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// This class handles the context related to dumping the draw call render targets
class DrawCallsDumpingContext
{
  public:
    // Forward declaration
    struct DrawCallParams;

    enum DrawCallType
    {
        kDraw,
        kDrawIndirect,
        kDrawIndirectCount,
        kDrawIndirectCountKHR,
        kDrawIndirectCountAMD,
        kDrawIndexed,
        kDrawIndexedIndirect,
        kDrawIndexedIndirectCount,
        kDrawIndexedIndirectCountKHR,
        kDrawIndexedIndirectCountAMD
    };

    DrawCallsDumpingContext(const CommandIndices*          dc_indices,
                            const RenderPassIndices*       rp_indices,
                            const CommandImageSubresource& dc_subresources,
                            CommonObjectInfoTable&         object_info_table,
                            const VulkanReplayOptions&     options,
                            VulkanDumpResourcesDelegate&   delegate,
                            const util::Compressor*        compressor);

    ~DrawCallsDumpingContext();

    bool IsRecording() const { return current_cb_index_ < command_buffers_.size(); }

    bool MustDumpDrawCall(uint64_t index) const;

    bool ShouldHandleRenderPass(uint64_t index) const;

    bool ShouldHandleExecuteCommands(uint64_t index) const;

    void BindDescriptorSets(VkPipelineBindPoint                                pipeline_bind_point,
                            uint32_t                                           first_set,
                            const std::vector<const VulkanDescriptorSetInfo*>& descriptor_sets_infos,
                            uint32_t                                           dynamicOffsetCount,
                            const uint32_t*                                    pDynamicOffsets);

    void BindPipeline(VkPipelineBindPoint bind_point, const VulkanPipelineInfo* pipeline);

    VkResult CloneCommandBuffer(VulkanCommandBufferInfo*             orig_cmd_buf_info,
                                const graphics::VulkanDeviceTable*   dev_table,
                                const graphics::VulkanInstanceTable* inst_table,
                                const VkCommandBufferBeginInfo*      begin_info);

    VkResult CloneRenderPass(const VkRenderPassCreateInfo* original_render_pass_ci);

    VkResult CloneRenderPass2(const VulkanRenderPassInfo*    render_pass_info,
                              const VkRenderPassCreateInfo2* original_render_pass_ci);

    VkResult BeginRenderPass(const VulkanRenderPassInfo*  render_pass_info,
                             const VulkanFramebufferInfo* framebuffer_info,
                             const VkRenderPassBeginInfo* renderpass_begin_info,
                             VkSubpassContents            contents);

    void NextSubpass(VkSubpassContents contents);

    void EndRenderPass();

    void BeginRendering(const std::vector<VulkanImageInfo*>& color_attachments,
                        const std::vector<VkImageLayout>&    color_attachment_layouts,
                        VulkanImageInfo*                     depth_attachment,
                        VkImageLayout                        depth_attachment_layout,
                        const VkRect2D&                      render_area);

    void EndRendering();

    void BindVertexBuffers(uint64_t                                    index,
                           uint32_t                                    firstBinding,
                           const std::vector<const VulkanBufferInfo*>& buffer_infos,
                           const VkDeviceSize*                         pOffsets);

    void BindVertexBuffers2(uint64_t                                    index,
                            uint32_t                                    first_binding,
                            const std::vector<const VulkanBufferInfo*>& buffer_infos,
                            const VkDeviceSize*                         pOffsets,
                            const VkDeviceSize*                         pSizes,
                            const VkDeviceSize*                         pStrides);

    void SetVertexInput(uint32_t                                     vertexBindingDescriptionCount,
                        const VkVertexInputBindingDescription2EXT*   pVertexBindingDescriptions,
                        uint32_t                                     vertexAttributeDescriptionCount,
                        const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions);

    void BindIndexBuffer(uint64_t                index,
                         const VulkanBufferInfo* buffer_info,
                         VkDeviceSize            offset,
                         VkIndexType             index_type,
                         VkDeviceSize            size = 0);

    // When this is called for a command buffer that corresponds to a before command, dc_params should be null
    void FinalizeCommandBuffer(DrawCallParams* dc_params = nullptr);

    uint32_t GetDrawCallActiveCommandBuffers(CommandBufferIterator& first, CommandBufferIterator& last) const;

    VkResult
    DumpDrawCalls(VkQueue queue, uint64_t qs_index, uint64_t bcb_index, const VkSubmitInfo& submit_info, VkFence fence);

    VkResult DumpRenderTargetAttachments(
        uint64_t cmd_buf_index, uint64_t rp, uint64_t sp, uint64_t qs_index, uint64_t bcb_index);

    VkResult DumpDescriptors(uint64_t qs_index, uint64_t bcb_index, uint64_t dc_index, uint64_t rp);

    VkResult DumpVertexIndexBuffers(uint64_t qs_index, uint64_t bcb_index, uint64_t dc_index);

    DrawCallParams* InsertNewDrawParameters(
        uint64_t index, uint32_t vertex_count, uint32_t instance_count, uint32_t first_vertex, uint32_t first_instance);

    DrawCallParams* InsertNewDrawIndexedParameters(uint64_t index,
                                                   uint32_t index_count,
                                                   uint32_t instance_count,
                                                   uint32_t first_index,
                                                   int32_t  vertexOffset,
                                                   uint32_t first_instance);

    DrawCallParams* InsertNewDrawIndirectParameters(
        uint64_t index, const VulkanBufferInfo* buffer_info, VkDeviceSize offset, uint32_t draw_count, uint32_t stride);

    DrawCallParams* InsertNewDrawIndexedIndirectParameters(
        uint64_t index, const VulkanBufferInfo* buffer_info, VkDeviceSize offset, uint32_t draw_count, uint32_t stride);

    DrawCallParams* InsertNewIndirectCountParameters(uint64_t                index,
                                                     const VulkanBufferInfo* buffer_info,
                                                     VkDeviceSize            offset,
                                                     const VulkanBufferInfo* count_buffer_info,
                                                     VkDeviceSize            count_buffer_offset,
                                                     uint32_t                max_draw_count,
                                                     uint32_t                stride,
                                                     DrawCallType            drawcall_type);

    DrawCallParams* InsertNewDrawIndexedIndirectCountParameters(uint64_t                index,
                                                                const VulkanBufferInfo* buffer_info,
                                                                VkDeviceSize            offset,
                                                                const VulkanBufferInfo* count_buffer_info,
                                                                VkDeviceSize            count_buffer_offset,
                                                                uint32_t                max_draw_count,
                                                                uint32_t                stride,
                                                                DrawCallType            drawcall_type);

    void Release();

    const std::vector<VkCommandBuffer>& GetCommandBuffers() const { return command_buffers_; }

    void AssignSecondary(uint64_t execute_commands_index, DrawCallsDumpingContext* secondary_context);

    uint32_t RecaclulateCommandBuffers();

    void UpdateSecondaries();

    void MergeRenderPasses(const DrawCallsDumpingContext& secondary_context);

  private:
    void SetRenderTargets(const std::vector<VulkanImageInfo*>& color_att_imgs,
                          VulkanImageInfo*                     depth_att_img,
                          bool                                 new_renderpass);

    void SetRenderArea(const VkRect2D& new_render_area);

    using RenderPassSubpassPair = std::pair<uint64_t, uint64_t>;
    RenderPassSubpassPair GetRenderPassIndex(uint64_t dc_index) const;
    size_t                CmdBufToDCVectorIndex(size_t cmd_buf_index) const;

    void DestroyMutableResourceBackups();

    void ReleaseIndirectParams();

    void ResetFetchedIndirectParams();

    VkResult BackUpMutableResources(VkQueue queue);

    VkResult RevertMutableResources(VkQueue queue);

    VkResult FetchDrawIndirectParams(uint64_t dc_index);

    VkResult RevertRenderTargetImageLayouts(VkQueue queue, uint64_t dc_index);

    VulkanCommandBufferInfo*     original_command_buffer_info_;
    std::vector<VkCommandBuffer> command_buffers_;
    size_t                       current_cb_index_;
    CommandIndices               dc_indices_;
    RenderPassIndices            RP_indices_;
    CommandImageSubresource      dc_subresources_;
    const VulkanRenderPassInfo*  active_renderpass_;
    const VulkanFramebufferInfo* active_framebuffer_;
    const VulkanPipelineInfo*    bound_gr_pipeline_;
    uint32_t                     current_renderpass_;
    uint32_t                     current_subpass_;
    VulkanDumpResourcesDelegate& delegate_;
    const VulkanReplayOptions&   options_;
    const util::Compressor*      compressor_;
    bool                         secondary_with_dynamic_rendering_;

    // Execute commands block index : DrawCallContexts
    std::unordered_map<uint64_t, std::vector<DrawCallsDumpingContext*>> secondaries_;

    enum RenderPassType
    {
        kNone,
        kRenderPass,
        kDynamicRendering
    };

    RenderPassType current_render_pass_type_;

    std::vector<std::vector<VkRenderPass>> render_pass_clones_;

    struct RenderPassAttachmentLayouts
    {
        bool                       is_dynamic{ false };
        std::vector<VkImageLayout> color_attachment_layouts;
        VkImageLayout              depth_attachment_layout{ VK_IMAGE_LAYOUT_GENERAL };
    };

    std::unordered_map<uint32_t, RenderPassAttachmentLayouts> rendering_attachment_layouts_;

  public:
    struct RenderTargets
    {
        RenderTargets() : depth_att_img(nullptr) {}

        std::vector<VulkanImageInfo*> color_att_imgs;
        VulkanImageInfo*              depth_att_img;
    };

  private:
    // render_targets is basically a 2d array (vector of vectors). It is indexed like render_targets[rp][sp]
    // where rp specifies the render pass and sp the subpass.
    std::vector<std::vector<RenderTargets>> render_targets_;

    // Render area is constant between subpasses so this array will be single dimension array
    std::vector<VkRect2D> render_area_;

    // One entry per descriptor set
    BoundDescriptorSets bound_descriptor_sets_gr_;

  public:
    struct VertexInputState
    {
        // One entry per binding
        VulkanPipelineInfo::VertexInputBindingMap vertex_input_binding_map;

        // One entry per location
        VulkanPipelineInfo::VertexInputAttributeMap vertex_input_attribute_map;

        // Check if one of the vertex attributes references a specific vertex biding
        bool IsVertexBindingReferenced(uint32_t binding_index) const
        {
            for (const auto& attrib_desc : vertex_input_attribute_map)
            {
                if (attrib_desc.second.binding == binding_index)
                {
                    return true;
                }
            }

            return false;
        }
    };

  private:
    // Keep track of CmdSetVertexInputEXT
    VertexInputState dynamic_vertex_input_state_;

  public:
    // Keep track of bound vertex buffers
    struct BoundVertexBuffersInfo
    {
        struct BufferPerBinding
        {
            BufferPerBinding() : buffer_info(nullptr), offset(0), size(0), stride(0) {}

            BufferPerBinding(const VulkanBufferInfo* buffer_info,
                             VkDeviceSize            offset,
                             VkDeviceSize            size   = 0,
                             VkDeviceSize            stride = 0) :
                buffer_info(buffer_info),
                offset(offset), size(size), stride(stride)
            {}

            const VulkanBufferInfo* buffer_info;
            VkDeviceSize            offset;

            // These are provided only by CmdBindVertexBuffers2
            VkDeviceSize size;
            VkDeviceSize stride;
        };

        // One entry for each vertex buffer bound at each binding
        std::unordered_map<uint32_t, BufferPerBinding> bound_vertex_buffer_per_binding;
    };

  private:
    BoundVertexBuffersInfo bound_vertex_buffers_;

  public:
    // Keep track of bound index buffer
    struct BoundIndexBuffer
    {
        BoundIndexBuffer() : buffer_info(nullptr), offset(0), index_type(VK_INDEX_TYPE_MAX_ENUM), size(0) {}

        BoundIndexBuffer(const VulkanBufferInfo* buffer_info,
                         VkDeviceSize            offset,
                         VkIndexType             index_type,
                         VkDeviceSize            size) :
            buffer_info(buffer_info),
            offset(offset), index_type(index_type), size(size)
        {}

        const VulkanBufferInfo* buffer_info;
        VkDeviceSize            offset;
        VkIndexType             index_type;

        // This is provided only by vkCmdBindIndexBuffer2KHR
        VkDeviceSize size;
    };

  private:
    BoundIndexBuffer bound_index_buffer_;

  public:
    static const char* DrawCallTypeToStr(DrawCallType type)
    {
        switch (type)
        {
            case kDraw:
                return "vkCmdDraw";
            case kDrawIndirect:
                return "vkCmdDrawIndirect";
            case kDrawIndirectCount:
                return "vkCmdDrawIndirectCount";
            case kDrawIndirectCountKHR:
                return "vkCmdDrawIndirectCountKHR";
            case kDrawIndirectCountAMD:
                return "vkCmdDrawIndirectCountAMD";
            case kDrawIndexed:
                return "vkCmdDrawIndexed";
            case kDrawIndexedIndirect:
                return "vkCmdDrawIndexedIndirect";
            case kDrawIndexedIndirectCount:
                return "vkCmdDrawIndexedIndirectCount";
            case kDrawIndexedIndirectCountKHR:
                return "vkCmdDrawIndexedIndirectCountKHR";
            case kDrawIndexedIndirectCountAMD:
                return "vkCmdDrawIndexedIndirectCountAMD";
            default:
                assert(0);
                return "Unrecognized draw call type";
        }
    }

    static bool IsDrawCallIndexed(DrawCallType dc_type)
    {
        switch (dc_type)
        {
            case kDraw:
            case kDrawIndirect:
            case kDrawIndirectCount:
            case kDrawIndirectCountKHR:
            case kDrawIndirectCountAMD:
                return false;

            case kDrawIndexed:
            case kDrawIndexedIndirect:
            case kDrawIndexedIndirectCount:
            case kDrawIndexedIndirectCountKHR:
            case kDrawIndexedIndirectCountAMD:
                return true;

            default:
                GFXRECON_LOG_ERROR("%s() Unrecognized draw call type (%u)", __func__, static_cast<uint32_t>(dc_type))
                assert(0);
                return false;
        }
    }

    static bool IsDrawCallIndirect(DrawCallType dc_type)
    {
        switch (dc_type)
        {
            case kDraw:
            case kDrawIndexed:
                return false;

            case kDrawIndirect:
            case kDrawIndirectCount:
            case kDrawIndirectCountKHR:
            case kDrawIndirectCountAMD:
            case kDrawIndexedIndirect:
            case kDrawIndexedIndirectCount:
            case kDrawIndexedIndirectCountKHR:
            case kDrawIndexedIndirectCountAMD:
                return true;

            default:
                GFXRECON_LOG_ERROR("%s() Unrecognized draw call type (%u)", __func__, static_cast<uint32_t>(dc_type))
                assert(0);
                return false;
        }
    }

    static bool IsDrawCallIndirectCount(DrawCallType dc_type)
    {
        switch (dc_type)
        {
            case kDraw:
            case kDrawIndexed:
            case kDrawIndirect:
            case kDrawIndexedIndirect:
                return false;

            case kDrawIndirectCount:
            case kDrawIndirectCountKHR:
            case kDrawIndexedIndirectCount:
            case kDrawIndexedIndirectCountKHR:
                return true;

            default:
                GFXRECON_LOG_ERROR("%s() Unrecognized draw call type (%u)", __func__, static_cast<uint32_t>(dc_type))
                assert(0);
                return false;
        }
    }

    struct DrawCallParams
    {
        static constexpr uint64_t INVALID_BLOCK_INDEX = std::numeric_limits<uint64_t>::max();

        union DrawCallParamsUnion
        {
            VkDrawIndirectCommand draw;

            VkDrawIndexedIndirectCommand draw_indexed;

            struct DrawIndirectParams
            {
                const VulkanBufferInfo* params_buffer_info;
                VkDeviceSize            params_buffer_offset;
                uint32_t                draw_count;
                uint32_t                stride;

                VkBuffer       new_params_buffer;
                VkDeviceMemory new_params_memory;
                VkDeviceSize   new_params_buffer_size;

                // Pointers that will point to host allocated memory and filled with the draw params
                // read back after executing on the gpu. Because of the union a data structure
                // with a non default destructor (vector/unique_ptr) cannot be used and we will
                // handle the memory managment ourselves.
                // One of these pointer will be used, depending on whether the draw call is indexed
                // or not.
                VkDrawIndirectCommand*        draw_params;
                VkDrawIndexedIndirectCommand* draw_indexed_params;
            };

            DrawIndirectParams draw_indirect;

            struct DrawIndirectCountParams
            {
                const VulkanBufferInfo* params_buffer_info;
                VkDeviceSize            params_buffer_offset;
                const VulkanBufferInfo* count_buffer_info;
                VkDeviceSize            count_buffer_offset;
                uint32_t                max_draw_count;
                uint32_t                stride;

                VkBuffer       new_params_buffer;
                VkDeviceMemory new_params_memory;
                VkDeviceSize   new_params_buffer_size;

                VkBuffer       new_count_buffer;
                VkDeviceMemory new_count_memory;

                // Pointers that will point to host allocated memory and filled with the draw params
                // read back after executing on the gpu. Because of the union a data structure
                // with a non default destructor (vector/unique_ptr) cannot be used and we will
                // handle the memory managment ourselves.
                // One of these pointer will be used, depending on whether the draw call is indexed
                // or not.
                VkDrawIndirectCommand*        draw_params;
                VkDrawIndexedIndirectCommand* draw_indexed_params;

                uint32_t actual_draw_count;
            };

            DrawIndirectCountParams draw_indirect_count;

            // Constructor for vkCmdDraw
            DrawCallParamsUnion(uint32_t vertex_count,
                                uint32_t instance_count,
                                uint32_t first_vertex,
                                uint32_t first_instance) :
                draw{ vertex_count, instance_count, first_vertex, first_instance }
            {}

            // Constructor for vkCmdDrawIndexed*
            DrawCallParamsUnion(uint32_t index_count,
                                uint32_t instance_count,
                                uint32_t first_index,
                                int32_t  vertex_offset,
                                uint32_t first_instance) :
                draw_indexed{ index_count, instance_count, first_index, vertex_offset, first_instance }
            {}

            // Constructor for vkCmdDrawIndirect*
            DrawCallParamsUnion(const VulkanBufferInfo* params_buffer_info,
                                VkDeviceSize            offset,
                                uint32_t                draw_count,
                                uint32_t                stride) :
                draw_indirect{ params_buffer_info, offset, draw_count, stride, VK_NULL_HANDLE,
                               VK_NULL_HANDLE,     0,      nullptr,    nullptr }
            {}

            // Constructor for vkCmdDraw*IndirectCount*
            DrawCallParamsUnion(const VulkanBufferInfo* params_buffer_info,
                                VkDeviceSize            params_buffer_offset,
                                const VulkanBufferInfo* count_buffer_info,
                                VkDeviceSize            count_buffer_offset,
                                uint32_t                max_draw_count,
                                uint32_t                stride) :
                draw_indirect_count{ params_buffer_info,
                                     params_buffer_offset,
                                     count_buffer_info,
                                     count_buffer_offset,
                                     max_draw_count,
                                     stride,
                                     VK_NULL_HANDLE,
                                     VK_NULL_HANDLE,
                                     0,
                                     VK_NULL_HANDLE,
                                     VK_NULL_HANDLE,
                                     nullptr,
                                     nullptr,
                                     std::numeric_limits<uint32_t>::max() }
            {}
        } dc_params_union;

        // Constructor for vkCmdDraw
        DrawCallParams(DrawCallType type,
                       uint32_t     vertex_count,
                       uint32_t     instance_count,
                       uint32_t     first_vertex,
                       uint32_t     first_instance) :
            dc_params_union(vertex_count, instance_count, first_vertex, first_instance),
            type(type), updated_referenced_descriptors(false), updated_bound_vertex_buffers(false),
            updated_bound_index_buffer(false)
        {
            assert(type == DrawCallType::kDraw);
        }

        // Constructor for vkCmdDrawIndexed*
        DrawCallParams(DrawCallType type,
                       uint32_t     index_count,
                       uint32_t     instance_count,
                       uint32_t     first_index,
                       int32_t      vertex_offset,
                       uint32_t     first_instance) :
            dc_params_union(index_count, instance_count, first_index, vertex_offset, first_instance),
            type(type), updated_referenced_descriptors(false), updated_bound_vertex_buffers(false),
            updated_bound_index_buffer(false)
        {
            assert(type == DrawCallType::kDrawIndexed);
        }

        // Constructor for vkCmdDraw*Indirect
        DrawCallParams(DrawCallType            type,
                       const VulkanBufferInfo* params_buffer_info,
                       VkDeviceSize            offset,
                       uint32_t                draw_count,
                       uint32_t                stride) :
            dc_params_union(params_buffer_info, offset, draw_count, stride),
            type(type), updated_referenced_descriptors(false), updated_bound_vertex_buffers(false),
            updated_bound_index_buffer(false)
        {
            assert(type == DrawCallType::kDrawIndirect || type == DrawCallType::kDrawIndexedIndirect);
        }

        // Constructor for vkCmdDraw*IndirectCount*
        DrawCallParams(DrawCallType            type,
                       const VulkanBufferInfo* buffer_info,
                       VkDeviceSize            offset,
                       const VulkanBufferInfo* count_buffer_info,
                       VkDeviceSize            count_buffer_offset,
                       uint32_t                max_draw_count,
                       uint32_t                stride) :
            dc_params_union(buffer_info, offset, count_buffer_info, count_buffer_offset, max_draw_count, stride),
            type(type), updated_referenced_descriptors(false), updated_bound_vertex_buffers(false),
            updated_bound_index_buffer(false)
        {
            GFXRECON_ASSERT(
                type == DrawCallType::kDrawIndirectCount || type == DrawCallType::kDrawIndexedIndirectCount ||
                type == DrawCallType::kDrawIndirectCountKHR || type == DrawCallType::kDrawIndexedIndirectCountKHR ||
                type == DrawCallType::kDrawIndirectCountAMD || type == DrawCallType::kDrawIndexedIndirectCountAMD);
        }

        DrawCallType type;

        // Store the vertex input state taken either from the current pipeline or from
        // CmdSetVertexInputEXT/CmdBindVertexBuffers2
        VertexInputState vertex_input_state;

        BoundVertexBuffersInfo referenced_vertex_buffers;

        BoundIndexBuffer referenced_index_buffer;

        // Keep copies of the descriptor bindings referenced by each draw call
        BoundDescriptorSets referenced_descriptors;

        // Need to keep track if a draw call context from a secondary command buffer has been updated with
        // information that might be available only from the primary command buffer
        bool updated_bound_vertex_buffers;
        bool updated_bound_index_buffer;
        bool updated_referenced_descriptors;

        DumpedResourcesInfo dumped_resources;
    };

  private:
    // One entry for each draw call
    using DrawCallParameters = std::unordered_map<uint64_t, std::unique_ptr<DrawCallParams>>;
    DrawCallParameters draw_call_params_;

    DrawCallParameters&   GetDrawCallParameters() { return draw_call_params_; }
    CommandIndices&       GetDrawCallIndices() { return dc_indices_; }
    const CommandIndices& GetDrawCallIndices() const { return dc_indices_; }

    struct
    {
        std::vector<const VulkanImageInfo*> original_images;
        std::vector<VkImage>                images;
        std::vector<VkDeviceMemory>         image_memories;

        std::vector<const VulkanBufferInfo*> original_buffers;
        std::vector<VkBuffer>                buffers;
        std::vector<VkDeviceMemory>          buffer_memories;
    } mutable_resource_backups_;

    // Gather here all descriptors referenced by draw calls that have been dumped
    // in order to avoid dumping descriptors referenced from multiple shader stages,
    // multiple times
    struct RenderPassDumpedDescriptors
    {
        std::unordered_map<const VulkanImageInfo*, const DumpedImage&>   image_descriptors;
        std::unordered_map<const VulkanBufferInfo*, const DumpedBuffer&> buffer_descriptors;
    };

    std::vector<RenderPassDumpedDescriptors> render_pass_dumped_descriptors_;

    VkCommandBuffer                 aux_command_buffer_;
    VkFence                         aux_fence_;
    DumpResourcesCommandBufferLevel command_buffer_level_;

    const graphics::VulkanDeviceTable*      device_table_;
    const graphics::VulkanInstanceTable*    instance_table_;
    CommonObjectInfoTable&                  object_info_table_;
    const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props_;

    void SecondaryUpdateContextFromPrimary(const VulkanPipelineInfo*     gr_pipeline,
                                           const BoundVertexBuffersInfo& vertex_buffers,
                                           const BoundIndexBuffer&       index_buffer,
                                           const VertexInputState&       dynamic_vertex_input_state_,
                                           const BoundDescriptorSets&    descriptor_sets);

    void SnapshotState(DrawCallParams& dc_params);

    VkResult CopyDrawIndirectParameters(DrawCallParams& dc_params);
};

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif /* GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_DRAW_CALLS_H */
