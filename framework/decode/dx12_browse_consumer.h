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

#include "generated/generated_dx12_decoder.h"
#include "graphics/dx12_dump_resources.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct TrackDumpCommandList
{
    uint64_t begin_renderpass_code_index{ 0 };
    uint64_t set_render_targets_code_index{ 0 };
    uint64_t drawcall_code_index{ 0 };
    uint64_t execute_code_index{ 0 };

    // vertex
    std::vector<D3D12_GPU_VIRTUAL_ADDRESS> captured_vertex_buffer_view_gvas;

    void Clear()
    {
        begin_renderpass_code_index = 0;
        drawcall_code_index         = 0;
        execute_code_index          = 0;
        captured_vertex_buffer_view_gvas.clear();
    }
};

class Dx12BrowseConsumer : public Dx12Consumer
{
  public:
    Dx12BrowseConsumer() {}

    void SetDumpTarget(DumpResourcesType dump_resources_type, uint64_t dump_resources_argument)
    {
        dump_resources_type_     = dump_resources_type;
        dump_resources_argument_ = dump_resources_argument;
    }
    TrackDumpCommandList* GetTrackDumpTarget()
    {
        auto it = track_commandlist_infos_.find(target_command_list_);
        if (it != track_commandlist_infos_.end())
        {
            return &(it->second);
        }
        return nullptr;
    }

    virtual void Process_ID3D12GraphicsCommandList_Reset(const ApiCallInfo& call_info,
                                                         format::HandleId   object_id,
                                                         HRESULT            return_value,
                                                         format::HandleId   pAllocator,
                                                         format::HandleId   pInitialState)
    {
        if (!IsFindDumpTarget())
        {
            auto it = track_commandlist_infos_.find(object_id);
            if (it != track_commandlist_infos_.end())
            {
                it->second.Clear();
            }
            else
            {
                TrackDumpCommandList info = {};
                track_commandlist_infos_.insert({ object_id, std::move(info) });
            }
        }
    }

    virtual void Process_ID3D12GraphicsCommandList4_BeginRenderPass(
        const ApiCallInfo&                                                  call_info,
        format::HandleId                                                    object_id,
        UINT                                                                NumRenderTargets,
        StructPointerDecoder<Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC>* pRenderTargets,
        StructPointerDecoder<Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC>* pDepthStencil,
        D3D12_RENDER_PASS_FLAGS                                             Flags)
    {
        if (!IsFindDumpTarget())
        {
            auto it = track_commandlist_infos_.find(object_id);
            if (it != track_commandlist_infos_.end())
            {
                it->second.begin_renderpass_code_index = call_info.index;
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
        if (!IsFindDumpTarget())
        {
            auto it = track_commandlist_infos_.find(object_id);
            if (it != track_commandlist_infos_.end())
            {
                it->second.set_render_targets_code_index = call_info.index;
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
        if (!IsFindDumpTarget())
        {
            auto it = track_commandlist_infos_.find(object_id);
            if (it != track_commandlist_infos_.end())
            {
                it->second.captured_vertex_buffer_view_gvas.resize(NumViews);
                auto views = pViews->GetMetaStructPointer();
                for (uint32_t i = 0; i < NumViews; ++i)
                {
                    it->second.captured_vertex_buffer_view_gvas[i] = views[i].decoded_value->BufferLocation;
                }
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
        if (!IsFindDumpTarget())
        {
            auto it = track_commandlist_infos_.find(object_id);
            if (it != track_commandlist_infos_.end())
            {
                if (dump_resources_type_ == DumpResourcesType::kDrawCall)
                {
                    if (track_drawcall_index_ == dump_resources_argument_)
                    {
                        it->second.drawcall_code_index = call_info.index;
                        target_command_list_           = object_id;
                    }
                }
            }
        }
        ++track_drawcall_index_;
    }

    virtual void
    Process_ID3D12CommandQueue_ExecuteCommandLists(const ApiCallInfo&                        call_info,
                                                   format::HandleId                          object_id,
                                                   UINT                                      NumCommandLists,
                                                   HandlePointerDecoder<ID3D12CommandList*>* ppCommandLists)
    {
        if (IsFindDumpTarget())
        {
            auto command_lists = ppCommandLists->GetPointer();
            for (uint32_t i = 0; i < NumCommandLists; ++i)
            {
                if (command_lists[i] == target_command_list_)
                {
                    auto it = track_commandlist_infos_.find(target_command_list_);
                    if (it != track_commandlist_infos_.end())
                    {
                        it->second.execute_code_index = call_info.index;
                        is_complete                   = true;
                        break;
                    }
                }
            }
        }
    }

    virtual bool IsComplete(uint64_t block_index) override { return (block_index > kMaxDX12BlockLimit) || is_complete; }

  private:
    bool IsFindDumpTarget()
    {
        return (dump_resources_type_ == DumpResourcesType::kDrawCall &&
                track_drawcall_index_ > dump_resources_argument_);
    }

    static int const  kMaxDX12BlockLimit = 1000;
    DumpResourcesType dump_resources_type_{ DumpResourcesType::kNone };
    uint64_t          dump_resources_argument_{ 0 };
    uint64_t          track_drawcall_index_{ 0 };
    format::HandleId  target_command_list_{ 0 };
    bool              is_complete{ false };
    // Key is commandlist_id. We need to know the commandlist of the info because in a commandlist block
    // between reset and close, it might have the other commandlist's commands.
    std::map<format::HandleId, TrackDumpCommandList> track_commandlist_infos_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_BROWSE_CONSUMER_H
