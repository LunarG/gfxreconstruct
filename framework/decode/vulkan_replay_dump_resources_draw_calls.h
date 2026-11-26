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

#include "decode/api_decoder.h"
#include "decode/common_object_info_table.h"
#include "decode/vulkan_replay_device_context.h"
#include "decode/vulkan_replay_dump_resources_as.h"
#include "decode/vulkan_replay_dump_resources_common.h"
#include "decode/vulkan_replay_dump_resources_windows.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_replay_options.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "graphics/vulkan_injected_calls.h"
#include "util/compressor.h"
#include "util/defines.h"
#include "util/logging.h"

#include <cstddef>
#include <cstdint>
#include <limits>
#include <memory>
#include <map>
#include <unordered_map>
#include <utility>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// This class handles the context related to dumping the draw call render targets.
//
// It owns the draw call slots of the DumpingContextWindows of its (BeginCommandBuffer, QueueSubmit) pair. It tracks
// the graphics state while the command buffer is recorded, snapshots what a target draw call references, records the
// draw call into the clone taking work and closes the window there. Once the windows have executed a window it dumps
// the draw call's render targets, descriptors and vertex/index buffers.
class DrawCallsDumpingContext : public DumpingContextBase
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

    DrawCallsDumpingContext(std::shared_ptr<DumpingContextWindows>            windows,
                            decode::Index                                     bcb_index,
                            decode::Index                                     qs_index,
                            const CommandImageSubresource&                    dc_subresources,
                            CommonObjectInfoTable&                            object_info_table,
                            const VulkanReplayOptions&                        options,
                            VulkanDumpResourcesDelegate&                      delegate,
                            const util::Compressor*                           compressor,
                            const DumpResourcesAccelerationStructuresContext& acceleration_structures_context,
                            const VulkanPerDeviceContexts&                    device_contexts);

    ~DrawCallsDumpingContext();

    // This context does not record draw calls: VulkanReplayDumpResourcesBase records every one of them into the
    // clone taking work. It only brackets the ones it dumps. Before*() is called right before the draw call is
    // recorded and AfterDraw() right after; both do nothing for a draw call that is not dumped.
    //
    // Before*(): with --dump-resources-before closes the window that ends right before the draw call, then stores
    //            its parameters and snapshots the bound state.
    // AfterDraw(): closes the window that ends with the draw call.
    void BeforeDraw(
        uint64_t index, uint32_t vertex_count, uint32_t instance_count, uint32_t first_vertex, uint32_t first_instance);

    void BeforeDrawIndexed(uint64_t index,
                           uint32_t index_count,
                           uint32_t instance_count,
                           uint32_t first_index,
                           int32_t  vertex_offset,
                           uint32_t first_instance);

    void BeforeDrawIndirect(
        uint64_t index, const VulkanBufferInfo* buffer_info, VkDeviceSize offset, uint32_t draw_count, uint32_t stride);

    void BeforeDrawIndexedIndirect(
        uint64_t index, const VulkanBufferInfo* buffer_info, VkDeviceSize offset, uint32_t draw_count, uint32_t stride);

    void BeforeDrawIndirectCount(uint64_t                              index,
                                 const VulkanBufferInfo*               buffer_info,
                                 VkDeviceSize                          offset,
                                 const VulkanBufferInfo*               count_buffer_info,
                                 VkDeviceSize                          count_buffer_offset,
                                 uint32_t                              max_draw_count,
                                 uint32_t                              stride,
                                 DrawCallsDumpingContext::DrawCallType drawcall_type);

    void BeforeDrawIndexedIndirectCount(uint64_t                              index,
                                        const VulkanBufferInfo*               buffer_info,
                                        VkDeviceSize                          offset,
                                        const VulkanBufferInfo*               count_buffer_info,
                                        VkDeviceSize                          count_buffer_offset,
                                        uint32_t                              max_draw_count,
                                        uint32_t                              stride,
                                        DrawCallsDumpingContext::DrawCallType drawcall_type);

    void AfterDraw(uint64_t index);

    bool MustDumpDrawCall(uint64_t index) const;

    void BindDescriptorSets(VkPipelineBindPoint                                pipeline_bind_point,
                            uint32_t                                           first_set,
                            const std::vector<const VulkanDescriptorSetInfo*>& descriptor_sets_infos,
                            uint32_t                                           dynamicOffsetCount,
                            const uint32_t*                                    pDynamicOffsets);

    void PushDescriptorSet(VkShaderStageFlags                                        stage_flags,
                           uint32_t                                                  set,
                           uint32_t                                                  descriptor_write_count,
                           const StructPointerDecoder<Decoded_VkWriteDescriptorSet>* p_descriptor_writes);

    void BindPipeline(VkPipelineBindPoint bind_point, const VulkanPipelineInfo* pipeline);

    // Also allocates the auxiliary command buffer and fence
    VkResult BeginCommandBuffer(const VulkanCommandBufferInfo*             orig_cmd_buf_info,
                                const graphics::VulkanInjectedDeviceCalls& dev_table,
                                const graphics::VulkanInstanceTable*       inst_table) override;

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

    // DumpingContextBase
    VkResult DumpSlot(const WindowSlot& slot,
                      size_t            window_index,
                      VkQueue           queue,
                      Index             submit_info_index,
                      Index             submit_info_cmd_buf_index) override;

    void ResetDumpedResources() override;

    void PrepareSecondary(DumpingContextBase& secondary_owner) override;

    void ExecuteSecondarySlot(DumpingContextBase& secondary_owner,
                              const WindowSlot&   secondary_slot,
                              Index               execute_cmd_index,
                              Index               command_buffer_execute_index) override;

    VkResult DumpRenderTargetAttachments(const WindowSlot&         slot,
                                         uint64_t                  cmd_buf_index,
                                         DrawCallParams&           dc_params,
                                         const DumpedResourceBase& dumped_resource_base);

    VkResult
    DumpDescriptors(const WindowSlot& slot, DrawCallParams& dc_params, const DumpedResourceBase& dumped_resource_base);

    VkResult DumpVertexIndexBuffers(uint64_t                  cmd_buf_index,
                                    DrawCallParams&           dc_params,
                                    const DumpedResourceBase& dumped_resource_base);

    void Release();

  private:
    using RenderPassContext = DumpingContextWindows::RenderPassContext;

    // Closes the window of a draw call slot: the clone taking work is ended and the next one takes over. Called
    // after each dumped draw call and, with --dump-resources-before, before it as well. dc_params is the finalized
    // draw call; it is null for a before command.
    void FinalizeWindow(DrawCallParams* dc_params = nullptr);

    // With --dump-resources-before, closes the window that ends right before a dumped draw call, so that the render
    // targets can be dumped before the draw call
    void FinalizeBeforeWindow();

    // The draw call contexts of the secondaries this context's command buffer executes
    std::vector<std::shared_ptr<DrawCallsDumpingContext>> GetSecondaryContexts() const;

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

    void DestroyMutableResourceBackups();

    void ReleaseIndirectParams();

    void ResetFetchedIndirectParams();

    VkResult BackUpMutableResources(VkQueue queue);

    VkResult RevertMutableResources(VkQueue queue);

    VkResult FetchDrawIndirectParams(DrawCallParams& dc_params);

    VkResult RevertRenderTargetImageLayouts(VkQueue queue, const WindowSlot& slot);

    CommandImageSubresource      dc_subresources_;
    const VulkanPipelineInfo*    bound_gr_pipeline_;

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
        DrawCallParams(DrawCallType                    type,
                       DumpResourcesCommandBufferLevel lvl,
                       Index                           dc_index,
                       uint32_t                        vertex_count,
                       uint32_t                        instance_count,
                       uint32_t                        first_vertex,
                       uint32_t                        first_instance) :
            dc_params_union(vertex_count, instance_count, first_vertex, first_instance),
            type(type), draw_call_index(dc_index), command_buffer_level(lvl), updated_referenced_descriptors(false),
            updated_bound_vertex_buffers(false), updated_bound_index_buffer(false)
        {
            assert(type == DrawCallType::kDraw);
        }

        // Constructor for vkCmdDrawIndexed*
        DrawCallParams(DrawCallType                    type,
                       DumpResourcesCommandBufferLevel lvl,
                       Index                           dc_index,
                       uint32_t                        index_count,
                       uint32_t                        instance_count,
                       uint32_t                        first_index,
                       int32_t                         vertex_offset,
                       uint32_t                        first_instance) :
            dc_params_union(index_count, instance_count, first_index, vertex_offset, first_instance),
            type(type), draw_call_index(dc_index), command_buffer_level(lvl), updated_referenced_descriptors(false),
            updated_bound_vertex_buffers(false), updated_bound_index_buffer(false)
        {
            assert(type == DrawCallType::kDrawIndexed);
        }

        // Constructor for vkCmdDraw*Indirect
        DrawCallParams(DrawCallType                    type,
                       DumpResourcesCommandBufferLevel lvl,
                       Index                           dc_index,
                       const VulkanBufferInfo*         params_buffer_info,
                       VkDeviceSize                    offset,
                       uint32_t                        draw_count,
                       uint32_t                        stride) :
            dc_params_union(params_buffer_info, offset, draw_count, stride),
            type(type), draw_call_index(dc_index), command_buffer_level(lvl), updated_referenced_descriptors(false),
            updated_bound_vertex_buffers(false), updated_bound_index_buffer(false)
        {
            assert(type == DrawCallType::kDrawIndirect || type == DrawCallType::kDrawIndexedIndirect);
        }

        // Constructor for vkCmdDraw*IndirectCount*
        DrawCallParams(DrawCallType                    type,
                       DumpResourcesCommandBufferLevel lvl,
                       Index                           dc_index,
                       const VulkanBufferInfo*         buffer_info,
                       VkDeviceSize                    offset,
                       const VulkanBufferInfo*         count_buffer_info,
                       VkDeviceSize                    count_buffer_offset,
                       uint32_t                        max_draw_count,
                       uint32_t                        stride) :
            dc_params_union(buffer_info, offset, count_buffer_info, count_buffer_offset, max_draw_count, stride),
            type(type), draw_call_index(dc_index), command_buffer_level(lvl), updated_referenced_descriptors(false),
            updated_bound_vertex_buffers(false), updated_bound_index_buffer(false)
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

        Index draw_call_index{ UNDEFINED_INDEX };

        // Relevant only for secondary command buffers
        DumpResourcesCommandBufferLevel command_buffer_level;

        // Store the vkCmdExecuteCommands block index and the secondary's command buffer index inside pCommandBuffers.
        // This is a map in order to support the case where the same secondary is executed multiple times either from
        // the same vkCmdExecuteCommands or when vkCmdExecuteCommands is recorded multiple times in the primary command
        // buffer. The index of the primary's window that runs the draw call is used as the map's key.
        std::map<Index, SecondaryIdentifiers> secondary_identifiers;

        DumpedResourcesInfo dumped_resources;
    };

  private:
    // One entry for each draw call. It is important that this is an ordered map
    using DrawCallParameters = std::map<uint64_t, std::shared_ptr<DrawCallParams>>;
    DrawCallParameters draw_call_params_;

    DrawCallParameters& GetDrawCallParameters() { return draw_call_params_; }

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
    // multiple times.
    // They are copies, not references into DumpedResourcesInfo::dumped_descriptors: that list is cleared for each
    // slot of its draw call (see DumpSlot), while these live until the whole submission has been dumped.
    struct RenderPassDumpedDescriptors
    {
        std::map<DescriptorLocation, DumpedImage>                 image_descriptors;
        std::map<DescriptorLocation, DumpedBuffer>                buffer_descriptors;
        std::map<DescriptorLocation, DumpedAccelerationStructure> acceleration_structures;
    };

    // Keyed by the render pass context a draw call was recorded in (nullptr for uncorrelated draw calls)
    std::unordered_map<const RenderPassContext*, RenderPassDumpedDescriptors> render_pass_dumped_descriptors_;

    // Used to put the render targets back into their layouts after a window was dumped
    VkCommandBuffer aux_command_buffer_;
    VkFence         aux_fence_;

    void SecondaryUpdateContextFromPrimary(const VulkanPipelineInfo*     gr_pipeline,
                                           const BoundVertexBuffersInfo& vertex_buffers,
                                           const BoundIndexBuffer&       index_buffer,
                                           const VertexInputState&       dynamic_vertex_input_state_,
                                           const BoundDescriptorSets&    descriptor_sets);

    // Records, into the clone taking work, the transition of the render targets that are going to be dumped into
    // VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL. RevertRenderTargetImageLayouts undoes it once the window was dumped.
    void TransitionRenderTargetLayouts(const RenderPassContext& renderpass_context);

    void SnapshotState(DrawCallParams& dc_params);

    VkResult CopyDrawIndirectParameters(DrawCallParams& dc_params);
};

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif /* GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_DRAW_CALLS_H */
