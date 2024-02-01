/*
** Copyright (c) 2023 LunarG, Inc.
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

#ifndef GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_BASE_H
#define GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_BASE_H

#include "decode/api_decoder.h"
#include "decode/vulkan_replay_options.h"
#include "decode/vulkan_object_info_table.h"
#include "decode/struct_pointer_decoder.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "decode/vulkan_replay_dump_resources_json.h"
#include "format/format.h"
#include "util/defines.h"
#include "vulkan/vulkan.h"
#include <vector>
#include <unordered_map>
#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanReplayDumpResourcesBase
{
  public:
    VulkanReplayDumpResourcesBase() = delete;

    VulkanReplayDumpResourcesBase(const VulkanReplayOptions& options, const VulkanObjectInfoTable& object_info_table);

    VkResult CloneCommandBuffer(uint64_t                     bcb_index,
                                const CommandBufferInfo*     original_command_buffer_info,
                                const encode::VulkanDeviceTable*   device_table,
                                const encode::VulkanInstanceTable* inst_table);

    void FinalizeDrawCallCommandBuffer(VkCommandBuffer original_command_buffer);

    void FinalizeDispatchRaysCommandBuffer(VkCommandBuffer original_command_buffer);

    void OverrideCmdDraw(const ApiCallInfo& call_info,
                         PFN_vkCmdDraw      func,
                         VkCommandBuffer    original_command_buffer,
                         uint32_t           vertexCount,
                         uint32_t           instanceCount,
                         uint32_t           firstVertex,
                         uint32_t           firstInstance);

    void OverrideCmdDrawIndexed(const ApiCallInfo&   call_info,
                                PFN_vkCmdDrawIndexed func,
                                VkCommandBuffer      original_command_buffer,
                                uint32_t             indexCount,
                                uint32_t             instanceCount,
                                uint32_t             firstIndex,
                                int32_t              vertexOffset,
                                uint32_t             firstInstance);

    void OverrideCmdDrawIndirect(const ApiCallInfo&    call_info,
                                 PFN_vkCmdDrawIndirect func,
                                 VkCommandBuffer       original_command_buffer,
                                 VkBuffer              buffer,
                                 VkDeviceSize          offset,
                                 uint32_t              drawCount,
                                 uint32_t              stride);

    void OverrideCmdDrawIndexedIndirect(const ApiCallInfo&           call_info,
                                        PFN_vkCmdDrawIndexedIndirect func,
                                        VkCommandBuffer              original_command_buffer,
                                        VkBuffer                     buffer,
                                        VkDeviceSize                 offset,
                                        uint32_t                     drawCount,
                                        uint32_t                     stride);

    void OverrideCmdDrawIndirectCount(const ApiCallInfo&         call_info,
                                      PFN_vkCmdDrawIndirectCount func,
                                      VkCommandBuffer            original_command_buffer,
                                      VkBuffer                   buffer,
                                      VkDeviceSize               offset,
                                      VkBuffer                   countBuffer,
                                      VkDeviceSize               countBufferOffset,
                                      uint32_t                   maxDrawCount,
                                      uint32_t                   stride);

    void OverrideCmdDrawIndexedIndirectCount(const ApiCallInfo&                call_info,
                                             PFN_vkCmdDrawIndexedIndirectCount func,
                                             VkCommandBuffer                   original_command_buffer,
                                             VkBuffer                          buffer,
                                             VkDeviceSize                      offset,
                                             VkBuffer                          countBuffer,
                                             VkDeviceSize                      countBufferOffset,
                                             uint32_t                          maxDrawCount,
                                             uint32_t                          stride);

    void OverrideCmdDrawIndirectCountKHR(const ApiCallInfo&            call_info,
                                         PFN_vkCmdDrawIndirectCountKHR func,
                                         VkCommandBuffer               original_command_buffer,
                                         VkBuffer                      buffer,
                                         VkDeviceSize                  offset,
                                         VkBuffer                      countBuffer,
                                         VkDeviceSize                  countBufferOffset,
                                         uint32_t                      maxDrawCount,
                                         uint32_t                      stride);

    void OverrideCmdDrawIndexedIndirectCountKHR(const ApiCallInfo&                   call_info,
                                                PFN_vkCmdDrawIndexedIndirectCountKHR func,
                                                VkCommandBuffer                      original_command_buffer,
                                                VkBuffer                             buffer,
                                                VkDeviceSize                         offset,
                                                VkBuffer                             countBuffer,
                                                VkDeviceSize                         countBufferOffset,
                                                uint32_t                             maxDrawCount,
                                                uint32_t                             stride);

    void OverrideCmdBeginRenderPass(const ApiCallInfo&                                   call_info,
                                    PFN_vkCmdBeginRenderPass                             func,
                                    VkCommandBuffer                                      original_command_buffer,
                                    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
                                    VkSubpassContents                                    contents);

    void OverrideCmdBeginRenderPass2(const ApiCallInfo&                                   call_info,
                                     PFN_vkCmdBeginRenderPass2                            func,
                                     VkCommandBuffer                                      original_command_buffer,
                                     StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
                                     StructPointerDecoder<Decoded_VkSubpassBeginInfo>*    pSubpassBeginInfo);

    void OverrideCmdEndRenderPass(const ApiCallInfo&     call_info,
                                  PFN_vkCmdEndRenderPass func,
                                  VkCommandBuffer        original_command_buffer);

    void OverrideCmdEndRenderPass2(const ApiCallInfo&                              call_info,
                                   PFN_vkCmdEndRenderPass2                         func,
                                   VkCommandBuffer                                 original_command_buffer,
                                   StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo);

    void OverrideCmdNextSubpass(const ApiCallInfo&   call_info,
                                PFN_vkCmdNextSubpass func,
                                VkCommandBuffer      original_command_buffer,
                                VkSubpassContents    contents);

    void OverrideCmdNextSubpass2(const ApiCallInfo&                                call_info,
                                 PFN_vkCmdNextSubpass2                             func,
                                 VkCommandBuffer                                   original_command_buffer,
                                 StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
                                 StructPointerDecoder<Decoded_VkSubpassEndInfo>*   pSubpassEndInfo);

    void OverrideCmdBindPipeline(const ApiCallInfo&    call_info,
                                 PFN_vkCmdBindPipeline func,
                                 VkCommandBuffer       original_command_buffer,
                                 VkPipelineBindPoint   pipelineBindPoint,
                                 const PipelineInfo*   pipeline);

    void OverrideCmdDispatch(const ApiCallInfo& call_info,
                             PFN_vkCmdDispatch  func,
                             VkCommandBuffer    original_command_buffer,
                             uint32_t           groupCountX,
                             uint32_t           groupCountY,
                             uint32_t           groupCountZ);

    void OverrideCmdDispatchIndirect(const ApiCallInfo&        call_info,
                                     PFN_vkCmdDispatchIndirect func,
                                     VkCommandBuffer           original_command_buffer,
                                     VkBuffer                  buffer,
                                     VkDeviceSize              offset);

    void
    OverrideCmdTraceRaysKHR(const ApiCallInfo&                                             call_info,
                            PFN_vkCmdTraceRaysKHR                                          func,
                            VkCommandBuffer                                                original_command_buffer,
                            StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
                            StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
                            StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
                            StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
                            uint32_t                                                       width,
                            uint32_t                                                       height,
                            uint32_t                                                       depth);

    void OverrideCmdBindDescriptorSets(const ApiCallInfo&          call_info,
                                       PFN_vkCmdBindDescriptorSets func,
                                       VkCommandBuffer             original_command_buffer,
                                       VkPipelineBindPoint         pipeline_bind_point,
                                       VkPipelineLayout            layout,
                                       uint32_t                    first_set,
                                       uint32_t                    descriptor_sets_count,
                                       const format::HandleId*     descriptor_sets_ids,
                                       uint32_t                    dynamicOffsetCount,
                                       const uint32_t*             pDynamicOffsets);

    VkResult QueueSubmit(const std::vector<VkSubmitInfo>& modified_submit_infos,
                         const encode::VulkanDeviceTable& device_table,
                         VkQueue                    queue,
                         VkFence                    fence,
                         uint64_t                   index);

    bool ShouldDumpQueueSubmitIndex(uint64_t index) const;

    bool ShouldDumpDrawCall(VkCommandBuffer original_command_buffer, uint64_t dc_index) const;

    bool ShouldDumpDispatch(VkCommandBuffer original_command_buffer, uint64_t index) const;

    bool ShouldDumpTraceRays(VkCommandBuffer original_command_buffer, uint64_t index) const;

    bool DumpingBeginCommandBufferIndex(uint64_t index) const;

    bool IsRecording(VkCommandBuffer original_command_buffer) const;

    using cmd_buf_it = std::vector<VkCommandBuffer>::const_iterator;

    bool
    GetDrawCallActiveCommandBuffers(VkCommandBuffer original_command_buffer, cmd_buf_it& first, cmd_buf_it& last) const;

    VkCommandBuffer GetDispatchRaysCommandBuffer(VkCommandBuffer original_command_buffer) const;

  private:
    struct descriptor_set_bindings
    {
        // storage images
        std::unordered_map<uint32_t, const ImageInfo*> image_infos;

        // storage and texel buffers
        std::unordered_map<uint32_t, const BufferInfo*> buffer_infos;
    };

    using descriptor_set_t = std::unordered_map<uint32_t, descriptor_set_bindings>;

    enum PipelineBindPoints
    {
        kBindPoint_graphics = 0,
        kBindPoint_compute,
        kBindPoint_ray_tracing,

        kBindPoint_count
    };

    static PipelineBindPoints VkPipelineBindPointToPipelineBindPoint(VkPipelineBindPoint bind_point)
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

    // This class handles the context related to dumping the draw call render targets
    struct DrawCallsDumpingContext
    {
        DrawCallsDumpingContext(const std::vector<uint64_t>&              dc_indices,
                                const std::vector<std::vector<uint64_t>>& rp_indices,
                                const VulkanObjectInfoTable&              object_info_table,
                                bool                                      dump_resources_before,
                                const std::string&                        dump_resource_path,
                                util::ScreenshotFormat                    image_file_format,
                                float                                     dump_resource_scale,
                                VulkanReplayDumpResourcesJson*            dump_json);

        ~DrawCallsDumpingContext();

        const CommandBufferInfo*           original_command_buffer_info;
        std::vector<VkCommandBuffer>       command_buffers;
        size_t                             current_cb_index;
        std::vector<uint64_t>              dc_indices;
        std::vector<std::vector<uint64_t>> RP_indices;
        const RenderPassInfo*              active_renderpass;
        const FramebufferInfo*             active_framebuffer;
        const PipelineInfo*                bound_pipelines[kBindPoint_count];
        uint32_t                           current_renderpass;
        uint32_t                           current_subpass;
        uint32_t                           n_subpasses;
        bool                               dump_resources_before;
        const std::string&                 dump_resource_path;
        util::ScreenshotFormat             image_file_format;
        float                              dump_resources_scale;
        VulkanReplayDumpResourcesJson*     p_dump_json;

        std::vector<std::vector<VkRenderPass>> render_pass_clones;
        bool                                   inside_renderpass;

        struct RenderTargets
        {
            RenderTargets() : depth_att_img(nullptr) {}

            std::vector<const ImageInfo*> color_att_imgs;
            const ImageInfo*              depth_att_img;
        };

        // render_targets_ is basically a 2d array (vector of vectors). It is indexed like render_targets_[rp][sp]
        // where rp specifies the render pass and sp the subpass.
        std::vector<std::vector<RenderTargets>> render_targets_;

        // Render area is constant between subpasses so this array will be single dimension array
        std::vector<VkRect2D> render_area_;

        using RenderPassSubpassPair = std::pair<uint64_t, uint64_t>;
        RenderPassSubpassPair GetRenderPassIndex(uint64_t dc_index) const;
        size_t                CmdBufToDCVectorIndex(size_t cmd_buf_index) const;

        bool IsRecording() const { return current_cb_index < command_buffers.size(); }

        bool ShouldDumpDrawCall(uint64_t index) const;

        bool ShouldHandleRenderPass(uint64_t index) const;

        void BindDescriptorSets(VkPipelineBindPoint                          pipeline_bind_point,
                                VkPipelineLayout                             layout,
                                uint32_t                                     first_set,
                                const std::vector<const DescriptorSetInfo*>& descriptor_sets_infos,
                                uint32_t                                     dynamicOffsetCount,
                                const uint32_t*                              pDynamicOffsets);

        void BindPipeline(VkPipelineBindPoint bind_point, const PipelineInfo* pipeline);

        VkResult CloneCommandBuffer(const CommandBufferInfo*     orig_cmd_buf_info,
                                    const encode::VulkanDeviceTable*   dev_table,
                                    const encode::VulkanInstanceTable* inst_table);

        VkResult CloneRenderPass(const RenderPassInfo* original_render_pass);

        VkResult BeginRenderPass(const RenderPassInfo*  render_pass_info,
                                 uint32_t               clear_value_count,
                                 const VkClearValue*    p_clear_values,
                                 const FramebufferInfo* framebuffer_info,
                                 const VkRect2D&        render_area,
                                 VkSubpassContents      contents);

        void NextSubpass(VkSubpassContents contents);

        void EndRenderPass();

        void FinalizeCommandBuffer();

        void SetRenderTargets(const std::vector<const ImageInfo*>& color_att_imgs,
                              const ImageInfo*                     depth_att_img,
                              bool                                 new_renderpass);

        void SetRenderArea(const VkRect2D& render_area);

        uint32_t GetDrawCallActiveCommandBuffers(cmd_buf_it& first, cmd_buf_it& last) const;

        VkResult DumpDrawCallsAttachments(
            VkQueue queue, uint64_t qs_index, uint64_t bcb_index, const VkSubmitInfo& submit_info, VkFence fence);

        VkResult DumpRenderTargetAttachments(uint64_t dc_index) const;

        descriptor_set_t bound_descriptor_sets[kBindPoint_count];

        std::string
        GenerateImageFilename(VkFormat format, uint64_t cmd_buf_index, uint64_t dc_index, int attachment_index) const;

        struct
        {
            std::vector<const ImageInfo*> original_images;
            std::vector<VkImage>          images;
            std::vector<VkDeviceMemory>   image_memories;

            std::vector<const BufferInfo*> original_buffers;
            std::vector<VkBuffer>          buffers;
            std::vector<VkDeviceMemory>    buffer_memories;
        } mutable_resource_backups;

        void DestroyMutableResourceBackups();

        VkResult BackUpMutableResources(VkQueue queue);

        VkResult RevertMutableResources(VkQueue queue);

        VkCommandBuffer aux_command_buffer;
        VkFence         aux_fence;
        bool            must_backup_resources;

        const encode::VulkanDeviceTable*              device_table;
        const encode::VulkanInstanceTable*            instance_table;
        const VulkanObjectInfoTable&            object_info_table;
        const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props;
    };

    // This class handles the context related to dumping Dispatch and TraceRays resouces
    struct DispatchTraceRaysDumpingContext
    {
        DispatchTraceRaysDumpingContext(const std::vector<uint64_t>&   dispatch_indices,
                                        const std::vector<uint64_t>&   trace_rays_indices,
                                        const VulkanObjectInfoTable&   object_info_table,
                                        bool                           dump_resources_before,
                                        const std::string&             dump_resource_path,
                                        util::ScreenshotFormat         image_file_format,
                                        float                          dump_resources_scale,
                                        VulkanReplayDumpResourcesJson* p_dump_json);

        ~DispatchTraceRaysDumpingContext();

        VkResult CloneCommandBuffer(const CommandBufferInfo*     orig_cmd_buf_info,
                                    const encode::VulkanDeviceTable*   dev_table,
                                    const encode::VulkanInstanceTable* inst_table);

        VkCommandBuffer GetDispatchRaysCommandBuffer() const { return DR_command_buffer; }

        void BindPipeline(VkPipelineBindPoint bind_point, const PipelineInfo* pipeline);

        bool IsRecording() const;

        bool ShouldDumpDispatch(uint64_t index) const;

        bool ShouldDumpTraceRays(uint64_t index) const;

        std::string GenerateImageFilename(VkFormat format,
                                          bool     is_dispatch,
                                          uint64_t index,
                                          uint32_t desc_set,
                                          uint32_t desc_binding,
                                          bool     before_cmd) const;

        std::string GenerateBufferFilename(
            bool is_dispatch, uint64_t index, uint32_t desc_set, uint32_t desc_binding, bool before_cmd) const;

        void BindDescriptorSets(VkPipelineBindPoint                          pipeline_bind_point,
                                VkPipelineLayout                             layout,
                                uint32_t                                     first_set,
                                const std::vector<const DescriptorSetInfo*>& descriptor_sets_infos,
                                uint32_t                                     dynamicOffsetCount,
                                const uint32_t*                              pDynamicOffsets);

        void CloneDispatchRaysResources(uint64_t index, bool cloning_before_cmd, bool is_dispatch);

        VkResult DumpDispatchRaysMutableResources(
            VkQueue queue, uint64_t qs_index, uint64_t bcb_index, const VkSubmitInfo& submit_info, VkFence fence);

        VkResult DumpMutableResources(uint64_t index, bool is_dispatch);

        void CopyImageResource(const ImageInfo* src_image_info, VkImage dst_image);

        void CopyBufferResource(const BufferInfo* src_buffer_info, VkBuffer dst_buffer);

        void DestroyMutableResourcesClones();

        void FinalizeCommandBuffer();

        const CommandBufferInfo* original_command_buffer_info;
        VkCommandBuffer                DR_command_buffer;
        std::vector<uint64_t>          dispatch_indices;
        std::vector<uint64_t>          trace_rays_indices;
        const PipelineInfo*            bound_pipelines[kBindPoint_count];
        bool                           dump_resources_before;
        const std::string&             dump_resource_path;
        util::ScreenshotFormat         image_file_format;
        float                          dump_resources_scale;
        VulkanReplayDumpResourcesJson* p_dump_json;

        descriptor_set_t bound_descriptor_sets[kBindPoint_count];

        // For each Dispatch/TraceRays that we dump we create a clone of all mutable resources used in the
        // shaders/pipeline and the content of the original resources are copied into the clones
        struct DumpableResourceBackup
        {
            DumpableResourceBackup() = default;

            std::vector<const ImageInfo*>              original_images;
            std::vector<VkImage>                       images;
            std::vector<VkDeviceMemory>                image_memories;
            std::vector<std::pair<uint32_t, uint32_t>> image_desc_set_binding_pair;

            std::vector<const BufferInfo*>             original_buffers;
            std::vector<VkBuffer>                      buffers;
            std::vector<VkDeviceMemory>                buffer_memories;
            std::vector<std::pair<uint32_t, uint32_t>> buffer_desc_set_binding_pair;
        };

        // This map should hold copies of all mutable resources per Dispach/TraceRays index
        std::unordered_map<uint64_t, DumpableResourceBackup> mutable_resources_clones;
        std::unordered_map<uint64_t, DumpableResourceBackup> mutable_resources_clones_before;

        const encode::VulkanDeviceTable*              device_table;
        const encode::VulkanInstanceTable*            instance_table;
        const VulkanObjectInfoTable&            object_info_table;
        const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props;
        size_t                                  current_dispatch_index;
        size_t                                  current_trace_rays_index;
    };

    std::vector<uint64_t> QueueSubmit_indices_;

    // One per BeginCommandBuffer index
    std::unordered_map<uint64_t, DrawCallsDumpingContext>         draw_call_contexts;
    std::unordered_map<uint64_t, DispatchTraceRaysDumpingContext> dispatch_ray_contexts;

    // Mapping between the original VkCommandBuffer handle and BeginCommandBuffer index
    std::unordered_map<VkCommandBuffer, uint64_t> cmd_buf_begin_map_;

    bool recording_;
    bool dump_resources_before_;

    const VulkanObjectInfoTable& object_info_table_;

  private:
    VulkanReplayDumpResourcesJson dump_json_;

    bool UpdateRecordingStatus();

    VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext*
    FindDispatchRaysCommandBufferContext(uint64_t bcb_id);

    const VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext*
    FindDispatchRaysCommandBufferContext(uint64_t bcb_id) const;

    VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext*
    FindDispatchRaysCommandBufferContext(VkCommandBuffer original_command_buffer);

    const VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext*
    FindDispatchRaysCommandBufferContext(VkCommandBuffer original_command_buffer) const;

    VulkanReplayDumpResourcesBase::DrawCallsDumpingContext*
    FindDrawCallCommandBufferContext(VkCommandBuffer original_command_buffer);

    const VulkanReplayDumpResourcesBase::DrawCallsDumpingContext*
    FindDrawCallCommandBufferContext(VkCommandBuffer original_command_buffer) const;

    VulkanReplayDumpResourcesBase::DrawCallsDumpingContext* FindDrawCallCommandBufferContext(uint64_t bcb_id);

    const VulkanReplayDumpResourcesBase::DrawCallsDumpingContext*
    FindDrawCallCommandBufferContext(uint64_t bcb_id) const;
};

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif /* GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_BASE_H */
