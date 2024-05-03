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

#ifndef GFXRECON_DECODE_DX12_BROWSE_CONSUMER_H
#define GFXRECON_DECODE_DX12_BROWSE_CONSUMER_H

#include <memory>

#include "generated/generated_dx12_decoder.h"
#include "graphics/dx12_dump_resources.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// If TEST_AVAILABLE_ARGS is enabled, it finds the available args that follow the original args, if the original args
// are unavailable.
// 0: disable
// 1: enable. The target could be Draw or Dispatch.
// 2: enable, and the target is Draw, not Dispatch.
// ExecuteIndirect isn't available to check if it's Draw, so it doesn't work for 2.
const int TEST_AVAILABLE_ARGS = 0;

struct ExecuteIndirectInfo
{
    format::HandleId argument_id{ format::kNullHandleId };
    uint64_t         argument_offset{ 0 };
    format::HandleId count_id{ format::kNullHandleId };
    uint64_t         count_offset{ 0 };
};

struct TrackDumpDrawcall
{
    DumpResourcesTarget dump_resources_target{};
    format::HandleId    command_list_id{ format::kNullHandleId };
    uint64_t            begin_block_index{ 0 };
    uint64_t            close_block_index{ 0 };
    uint64_t            begin_renderpass_block_index{ 0 };
    uint64_t            end_renderpass_block_index{ 0 };
    uint64_t            set_render_targets_block_index{ 0 };
    format::HandleId    root_signature_handle_id{ format::kNullHandleId };
    bool is_draw{ false }; // true: DrawInstanced, DrawIndexedInstanced, false: Dispatch, ExecuteIndirect, ExecuteBundle

    // vertex
    std::vector<D3D12_VERTEX_BUFFER_VIEW> captured_vertex_buffer_views;

    // index
    D3D12_INDEX_BUFFER_VIEW captured_index_buffer_view{};

    // descriptor
    std::vector<format::HandleId>               descriptor_heap_ids;
    std::map<UINT, D3D12_GPU_DESCRIPTOR_HANDLE> captured_descriptor_gpu_handles;

    // ExecuteIndirect
    ExecuteIndirectInfo execute_indirect_info{};

    // Bundle
    format::HandleId bundle_commandlist_id{ format::kNullHandleId };
    // It couldn't use the structure that is the same to the parent structure, so use std::shared_ptr.
    std::shared_ptr<TrackDumpDrawcall> bundle_target_drawcall;

    uint64_t drawcall_block_index{ 0 }; // It could also be ExecuteIndirect or ExecuteBundle block index.
    uint64_t execute_block_index{ 0 };

    void Clear()
    {
        captured_vertex_buffer_views.clear();
        descriptor_heap_ids.clear();
        captured_descriptor_gpu_handles.clear();
        bundle_commandlist_id  = format::kNullHandleId;
        bundle_target_drawcall = nullptr;
    }
};

struct TrackDumpCommandList
{
    uint64_t         begin_block_index{ 0 };
    uint64_t         current_begin_renderpass_block_index{ 0 };
    uint64_t         current_set_render_targets_block_index{ 0 };
    format::HandleId current_root_signature_handle_id{ format::kNullHandleId };

    // vertex
    std::vector<D3D12_VERTEX_BUFFER_VIEW> current_captured_vertex_buffer_views;

    // index
    D3D12_INDEX_BUFFER_VIEW current_captured_index_buffer_view{};

    // descriptor
    std::vector<format::HandleId>               current_descriptor_heap_ids;
    std::map<UINT, D3D12_GPU_DESCRIPTOR_HANDLE> current_captured_descriptor_gpu_handles;

    // render target
    // Track render target info in replay, not here.
    // Because the useful info is replay cpuDescriptor. It's only available in replay.

    std::vector<std::shared_ptr<TrackDumpDrawcall>> track_dump_drawcalls;

    void Clear()
    {
        begin_block_index                      = 0;
        current_begin_renderpass_block_index   = 0;
        current_set_render_targets_block_index = 0;
        current_captured_vertex_buffer_views.clear();
        current_captured_index_buffer_view = {};
        current_descriptor_heap_ids.clear();
        current_captured_descriptor_gpu_handles.clear();
        track_dump_drawcalls.clear();
    }
};

class Dx12BrowseConsumer : public Dx12Consumer
{
  public:
    Dx12BrowseConsumer() {}

    void SetDumpTarget(const DumpResourcesTarget& dump_resources_target)
    {
        dump_resources_target_ = dump_resources_target;
    }

    TrackDumpDrawcall* GetTrackDumpTarget()
    {
        if (track_submit_index_ <= dump_resources_target_.submit_index)
        {
            GFXRECON_LOG_FATAL("The target submit index(%d) of dump resources is out of range(%d).",
                               dump_resources_target_.submit_index,
                               track_submit_index_);
            if (TEST_AVAILABLE_ARGS > 0)
            {
                GFXRECON_LOG_FATAL("Although TEST_AVAILABLE_ARGS is enabled, it cann't find the available args that "
                                   "follow the original args.");
            }
            GFXRECON_ASSERT(track_submit_index_ > dump_resources_target_.submit_index);
        }

        auto it = track_commandlist_infos_.find(target_command_list_);
        if (it != track_commandlist_infos_.end())
        {
            auto drawcall_size = it->second.track_dump_drawcalls.size();
            GFXRECON_ASSERT(drawcall_size > target_drawcall_index_);

            if (is_modified_args)
            {
                GFXRECON_LOG_INFO("TEST_AVAILABLE_ARGS is enabled, it finds the available args(%d,%d,%d) that follow "
                                  "the original args.",
                                  dump_resources_target_.submit_index,
                                  dump_resources_target_.command_index,
                                  dump_resources_target_.drawcall_index);
            }
            auto& target                  = it->second.track_dump_drawcalls[target_drawcall_index_];
            target->dump_resources_target = dump_resources_target_;
            return target.get();
        }
        return nullptr;
    }

    virtual void Process_ID3D12Device_CreateCommandList(const ApiCallInfo&           call_info,
                                                        format::HandleId             object_id,
                                                        HRESULT                      return_value,
                                                        UINT                         nodeMask,
                                                        D3D12_COMMAND_LIST_TYPE      type,
                                                        format::HandleId             pCommandAllocator,
                                                        format::HandleId             pInitialState,
                                                        Decoded_GUID                 riid,
                                                        HandlePointerDecoder<void*>* ppCommandList)
    {
        InitializeTracking(call_info, *ppCommandList->GetPointer());
    }

    virtual void Process_ID3D12GraphicsCommandList_Reset(const ApiCallInfo& call_info,
                                                         format::HandleId   object_id,
                                                         HRESULT            return_value,
                                                         format::HandleId   pAllocator,
                                                         format::HandleId   pInitialState)
    {
        InitializeTracking(call_info, object_id);
    }

    virtual void Process_ID3D12GraphicsCommandList4_BeginRenderPass(
        const ApiCallInfo&                                                  call_info,
        format::HandleId                                                    object_id,
        UINT                                                                NumRenderTargets,
        StructPointerDecoder<Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC>* pRenderTargets,
        StructPointerDecoder<Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC>* pDepthStencil,
        D3D12_RENDER_PASS_FLAGS                                             Flags)
    {
        if (target_command_list_ == format::kNullHandleId)
        {
            auto it = track_commandlist_infos_.find(object_id);
            if (it != track_commandlist_infos_.end())
            {
                it->second.current_begin_renderpass_block_index   = call_info.index;
                it->second.current_set_render_targets_block_index = 0;
            }
        }
    }

    virtual void Process_ID3D12GraphicsCommandList4_EndRenderPass(const ApiCallInfo& call_info,
                                                                  format::HandleId   object_id)
    {
        if (target_command_list_ == format::kNullHandleId)
        {
            auto it = track_commandlist_infos_.find(object_id);
            if (it != track_commandlist_infos_.end())
            {
                for (auto& drawcall : it->second.track_dump_drawcalls)
                {
                    if (drawcall->begin_renderpass_block_index != 0 && drawcall->end_renderpass_block_index == 0)
                    {
                        drawcall->end_renderpass_block_index = call_info.index;
                    }
                }
            }
        }
    }

    virtual void Process_ID3D12GraphicsCommandList_OMSetRenderTargets(
        const ApiCallInfo&                                         call_info,
        format::HandleId                                           object_id,
        UINT                                                       NumRenderTargetDescriptors,
        StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pRenderTargetDescriptors,
        BOOL                                                       RTsSingleHandleToDescriptorRange,
        StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pDepthStencilDescriptor)
    {
        if (target_command_list_ == format::kNullHandleId)
        {
            auto it = track_commandlist_infos_.find(object_id);
            if (it != track_commandlist_infos_.end())
            {
                it->second.current_set_render_targets_block_index = call_info.index;
                it->second.current_begin_renderpass_block_index   = 0;
            }
        }
    }

    virtual void Process_ID3D12GraphicsCommandList_SetComputeRootSignature(const ApiCallInfo& call_info,
                                                                           format::HandleId   object_id,
                                                                           format::HandleId   pRootSignature)
    {
        if (target_command_list_ == format::kNullHandleId)
        {
            auto it = track_commandlist_infos_.find(object_id);
            if (it != track_commandlist_infos_.end())
            {
                it->second.current_root_signature_handle_id = pRootSignature;
            }
        }
    }

    virtual void Process_ID3D12GraphicsCommandList_SetGraphicsRootSignature(const ApiCallInfo& call_info,
                                                                            format::HandleId   object_id,
                                                                            format::HandleId   pRootSignature)
    {
        if (target_command_list_ == format::kNullHandleId)
        {
            auto it = track_commandlist_infos_.find(object_id);
            if (it != track_commandlist_infos_.end())
            {
                it->second.current_root_signature_handle_id = pRootSignature;
            }
        }
    }

    virtual void
    Process_ID3D12GraphicsCommandList_IASetVertexBuffers(const ApiCallInfo& call_info,
                                                         format::HandleId   object_id,
                                                         UINT               StartSlot,
                                                         UINT               NumViews,
                                                         StructPointerDecoder<Decoded_D3D12_VERTEX_BUFFER_VIEW>* pViews)
    {
        if (target_command_list_ == format::kNullHandleId)
        {
            auto it = track_commandlist_infos_.find(object_id);
            if (it != track_commandlist_infos_.end())
            {
                it->second.current_captured_vertex_buffer_views.resize(NumViews);
                auto views = pViews->GetMetaStructPointer();
                for (uint32_t i = 0; i < NumViews; ++i)
                {
                    it->second.current_captured_vertex_buffer_views[i] = *(views[i].decoded_value);
                }
            }
        }
    }

    virtual void
    Process_ID3D12GraphicsCommandList_IASetIndexBuffer(const ApiCallInfo&                                     call_info,
                                                       format::HandleId                                       object_id,
                                                       StructPointerDecoder<Decoded_D3D12_INDEX_BUFFER_VIEW>* pView)
    {
        if (target_command_list_ == format::kNullHandleId)
        {
            auto it = track_commandlist_infos_.find(object_id);
            if (it != track_commandlist_infos_.end())
            {
                auto view = pView->GetMetaStructPointer();
                if (view != nullptr)
                {
                    it->second.current_captured_index_buffer_view = *(view->decoded_value);
                }
                else
                {
                    it->second.current_captured_index_buffer_view = D3D12_INDEX_BUFFER_VIEW();
                }
            }
        }
    }

    virtual void
    Process_ID3D12GraphicsCommandList_SetDescriptorHeaps(const ApiCallInfo& call_info,
                                                         format::HandleId   object_id,
                                                         UINT               NumDescriptorHeaps,
                                                         HandlePointerDecoder<ID3D12DescriptorHeap*>* ppDescriptorHeaps)
    {
        if (target_command_list_ == format::kNullHandleId)
        {
            auto it = track_commandlist_infos_.find(object_id);
            if (it != track_commandlist_infos_.end())
            {
                it->second.current_descriptor_heap_ids.resize(NumDescriptorHeaps);
                auto heap_ids = ppDescriptorHeaps->GetPointer();
                for (uint32_t i = 0; i < NumDescriptorHeaps; ++i)
                {
                    it->second.current_descriptor_heap_ids[i] = heap_ids[i];
                }
                it->second.current_captured_descriptor_gpu_handles.clear();
            }
        }
    }

    virtual void
    Process_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable(const ApiCallInfo& call_info,
                                                                    format::HandleId   object_id,
                                                                    UINT               RootParameterIndex,
                                                                    Decoded_D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor)
    {
        if (target_command_list_ == format::kNullHandleId)
        {
            auto it = track_commandlist_infos_.find(object_id);
            if (it != track_commandlist_infos_.end())
            {
                it->second.current_captured_descriptor_gpu_handles[RootParameterIndex] =
                    (*BaseDescriptor.decoded_value);
            }
        }
    }

    virtual void
    Process_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable(const ApiCallInfo& call_info,
                                                                     format::HandleId   object_id,
                                                                     UINT               RootParameterIndex,
                                                                     Decoded_D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor)
    {
        if (target_command_list_ == format::kNullHandleId)
        {
            auto it = track_commandlist_infos_.find(object_id);
            if (it != track_commandlist_infos_.end())
            {
                it->second.current_captured_descriptor_gpu_handles[RootParameterIndex] =
                    (*BaseDescriptor.decoded_value);
            }
        }
    }

    virtual void Process_ID3D12GraphicsCommandList_DrawInstanced(const ApiCallInfo& call_info,
                                                                 format::HandleId   object_id,
                                                                 UINT               VertexCountPerInstance,
                                                                 UINT               InstanceCount,
                                                                 UINT               StartVertexLocation,
                                                                 UINT               StartInstanceLocation)
    {
        TrackTargetDrawcall(call_info, object_id, true);
    }

    virtual void Process_ID3D12GraphicsCommandList_DrawIndexedInstanced(const ApiCallInfo& call_info,
                                                                        format::HandleId   object_id,
                                                                        UINT               IndexCountPerInstance,
                                                                        UINT               InstanceCount,
                                                                        UINT               StartIndexLocation,
                                                                        INT                BaseVertexLocation,
                                                                        UINT               StartInstanceLocation)
    {
        TrackTargetDrawcall(call_info, object_id, true);
    }

    virtual void Process_ID3D12GraphicsCommandList_Dispatch(const ApiCallInfo& call_info,
                                                            format::HandleId   object_id,
                                                            UINT               ThreadGroupCountX,
                                                            UINT               ThreadGroupCountY,
                                                            UINT               ThreadGroupCountZ)
    {
        TrackTargetDrawcall(call_info, object_id, false);
    }

    virtual void Process_ID3D12GraphicsCommandList_ExecuteIndirect(const ApiCallInfo& call_info,
                                                                   format::HandleId   object_id,
                                                                   format::HandleId   pCommandSignature,
                                                                   UINT               MaxCommandCount,
                                                                   format::HandleId   pArgumentBuffer,
                                                                   UINT64             ArgumentBufferOffset,
                                                                   format::HandleId   pCountBuffer,
                                                                   UINT64             CountBufferOffset)
    {
        TrackTargetDrawcall(
            call_info, object_id, false, pArgumentBuffer, ArgumentBufferOffset, pCountBuffer, CountBufferOffset);
    }

    virtual void Process_ID3D12GraphicsCommandList_ExecuteBundle(const ApiCallInfo& call_info,
                                                                 format::HandleId   object_id,
                                                                 format::HandleId   pCommandList)
    {
        TrackTargetDrawcall(
            call_info, object_id, false, format::kNullHandleId, 0, format::kNullHandleId, 0, pCommandList);
    }

    virtual void Process_ID3D12GraphicsCommandList_Close(const ApiCallInfo& call_info,
                                                         format::HandleId   object_id,
                                                         HRESULT            return_value)
    {
        if (target_command_list_ == format::kNullHandleId)
        {
            auto it = track_commandlist_infos_.find(object_id);
            if (it != track_commandlist_infos_.end())
            {
                for (auto& drawcall : it->second.track_dump_drawcalls)
                {
                    drawcall->close_block_index = call_info.index;
                }
            }
        }
    }

    virtual void
    Process_ID3D12CommandQueue_ExecuteCommandLists(const ApiCallInfo&                        call_info,
                                                   format::HandleId                          object_id,
                                                   UINT                                      NumCommandLists,
                                                   HandlePointerDecoder<ID3D12CommandList*>* ppCommandLists)
    {
        if (target_command_list_ == format::kNullHandleId)
        {
            if (track_submit_index_ == dump_resources_target_.submit_index)
            {
                if (NumCommandLists <= dump_resources_target_.command_index)
                {
                    if (TEST_AVAILABLE_ARGS > 0)
                    {
                        ++track_submit_index_;
                        ++dump_resources_target_.submit_index;
                        dump_resources_target_.command_index  = 0;
                        dump_resources_target_.drawcall_index = 0;
                        is_modified_args                      = true;
                        return;
                    }
                    else
                    {
                        GFXRECON_LOG_FATAL("The target command index(%d) of dump resources is out of range(%d).",
                                           dump_resources_target_.command_index,
                                           NumCommandLists);
                        GFXRECON_ASSERT(NumCommandLists > dump_resources_target_.command_index);
                    }
                }

                auto command_lists = ppCommandLists->GetPointer();
                for (uint32_t cmd_index = dump_resources_target_.command_index; cmd_index < NumCommandLists;
                     ++cmd_index)
                {
                    auto cmd_list = command_lists[cmd_index];
                    auto it       = track_commandlist_infos_.find(cmd_list);
                    GFXRECON_ASSERT(it != track_commandlist_infos_.end());

                    uint32_t all_drawcall_count = 0; // Include normal drawcall and bundle drawcall.
                    uint32_t drawcall_index     = 0;
                    for (auto& drawcall : it->second.track_dump_drawcalls)
                    {
                        if (drawcall->bundle_commandlist_id != format::kNullHandleId)
                        {
                            auto bundle_it = track_commandlist_infos_.find(drawcall->bundle_commandlist_id);
                            if (bundle_it != track_commandlist_infos_.end())
                            {
                                for (auto& bundle_drawcall : bundle_it->second.track_dump_drawcalls)
                                {
                                    ++all_drawcall_count;
                                    if (all_drawcall_count > dump_resources_target_.drawcall_index)
                                    {
                                        if (TEST_AVAILABLE_ARGS == 2 && !bundle_drawcall->is_draw)
                                        {
                                            // Find a draw drawcall in the following drawcall.
                                            is_modified_args = true;
                                            ++dump_resources_target_.drawcall_index;
                                        }
                                        else
                                        {
                                            drawcall->bundle_target_drawcall = bundle_drawcall;

                                            drawcall->execute_block_index = call_info.index;
                                            target_command_list_          = cmd_list;
                                            target_drawcall_index_        = drawcall_index;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        else
                        {
                            ++all_drawcall_count;
                            if (all_drawcall_count > dump_resources_target_.drawcall_index)
                            {
                                if (TEST_AVAILABLE_ARGS == 2 && !drawcall->is_draw)
                                {
                                    // Find a draw drawcall in the following drawcall.
                                    is_modified_args = true;
                                    ++dump_resources_target_.drawcall_index;
                                }
                                else
                                {
                                    drawcall->execute_block_index = call_info.index;
                                    target_command_list_          = cmd_list;
                                    target_drawcall_index_        = drawcall_index;
                                    break;
                                }
                            }
                        }
                        ++drawcall_index;
                    }

                    // It didn't find the target drawcall.
                    if (target_command_list_ == format::kNullHandleId)
                    {
                        if (TEST_AVAILABLE_ARGS > 0)
                        {
                            // Find a drawcall in the following command list.
                            is_modified_args = true;
                            ++dump_resources_target_.command_index;
                            dump_resources_target_.drawcall_index = 0;
                        }
                        else
                        {
                            GFXRECON_LOG_FATAL("The target drawcall index(%d) of dump resources is out of range(%d).",
                                               dump_resources_target_.drawcall_index,
                                               all_drawcall_count);
                            GFXRECON_ASSERT(all_drawcall_count > dump_resources_target_.drawcall_index);
                            break;
                        }
                    }
                }

                // It didn't find the target drawcall.
                if (TEST_AVAILABLE_ARGS > 0 && target_command_list_ == format::kNullHandleId)
                {
                    // Find a drawcall in the following submit.
                    is_modified_args = true;
                    ++dump_resources_target_.submit_index;
                    dump_resources_target_.command_index  = 0;
                    dump_resources_target_.drawcall_index = 0;
                }
            }
            ++track_submit_index_;
        }
    }

    virtual bool IsComplete(uint64_t block_index) override { return (target_command_list_ != format::kNullHandleId); }

  private:
    bool                is_modified_args{ false };
    DumpResourcesTarget dump_resources_target_{};
    uint32_t            track_submit_index_{ 0 };
    format::HandleId    target_command_list_{ 0 };
    uint32_t            target_drawcall_index_{ 0 };

    // Key is commandlist_id. We need to know the commandlist of the info because in a commandlist block
    // between reset and close, it might have the other commandlist's commands.
    std::map<format::HandleId, TrackDumpCommandList> track_commandlist_infos_;

    void InitializeTracking(const ApiCallInfo& call_info, format::HandleId object_id)
    {
        if (target_command_list_ == format::kNullHandleId)
        {
            auto it = track_commandlist_infos_.find(object_id);
            if (it != track_commandlist_infos_.end())
            {
                it->second.Clear();
                it->second.begin_block_index = call_info.index;
            }
            else
            {
                TrackDumpCommandList info = {};
                info.begin_block_index    = call_info.index;
                track_commandlist_infos_.insert({ object_id, std::move(info) });
            }
        }
    }

    void TrackTargetDrawcall(const ApiCallInfo& call_info,
                             format::HandleId   object_id,
                             bool               is_draw,
                             format::HandleId   exe_indirect_argument_id     = format::kNullHandleId,
                             uint64_t           exe_indirect_argument_offset = 0,
                             format::HandleId   exe_indirect_count_id        = format::kNullHandleId,
                             uint64_t           exe_indirect_count_offset    = 0,
                             format::HandleId   bundle_commandlist_id        = format::kNullHandleId)
    {
        if (target_command_list_ == format::kNullHandleId)
        {
            auto it = track_commandlist_infos_.find(object_id);
            if (it != track_commandlist_infos_.end())
            {
                TrackDumpDrawcall track_drawcall                 = {};
                track_drawcall.command_list_id                   = object_id;
                track_drawcall.drawcall_block_index              = call_info.index;
                track_drawcall.is_draw                           = is_draw;
                track_drawcall.begin_block_index                 = it->second.begin_block_index;
                track_drawcall.begin_renderpass_block_index      = it->second.current_begin_renderpass_block_index;
                track_drawcall.set_render_targets_block_index    = it->second.current_set_render_targets_block_index;
                track_drawcall.root_signature_handle_id          = it->second.current_root_signature_handle_id;
                track_drawcall.captured_vertex_buffer_views      = it->second.current_captured_vertex_buffer_views;
                track_drawcall.captured_index_buffer_view        = it->second.current_captured_index_buffer_view;
                track_drawcall.descriptor_heap_ids               = it->second.current_descriptor_heap_ids;
                track_drawcall.captured_descriptor_gpu_handles   = it->second.current_captured_descriptor_gpu_handles;
                track_drawcall.execute_indirect_info.argument_id = exe_indirect_argument_id;
                track_drawcall.execute_indirect_info.argument_offset = exe_indirect_argument_offset;
                track_drawcall.execute_indirect_info.count_id        = exe_indirect_count_id;
                track_drawcall.execute_indirect_info.count_offset    = exe_indirect_count_offset;
                track_drawcall.bundle_commandlist_id                 = bundle_commandlist_id;

                it->second.track_dump_drawcalls.emplace_back(
                    std::make_shared<TrackDumpDrawcall>(std::move(track_drawcall)));
            }
        }
    }
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_BROWSE_CONSUMER_H
