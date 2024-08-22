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

#include PROJECT_VERSION_HEADER_FILE
#include "decode/dx12_dump_resources.h"
// TODO: It should change the file name of "vulkan"
#include "generated/generated_vulkan_struct_to_json.h"
#include "decode/dx12_object_mapping_util.h"
#include "util/platform.h"
#include "util/logging.h"
#include "util/image_writer.h"
#include "util/json_util.h"
#include "graphics/dx12_util.h"
#include "graphics/dx12_resource_data_util.h"

extern "C"
{
    extern const UINT D3D12SDKVersion;
}

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// TEST_READABLE is only for test because data type could be various.
// But here uses fixed type.
// According to the resource's desc.Dimension, float is for buffer, image is for the others.
constexpr bool TEST_READABLE   = false;
constexpr bool TEST_SHADER_RES = true;

static const char* Dx12ResourceTypeToString(Dx12DumpResourceType type)
{
    switch (type)
    {
        case Dx12DumpResourceType::kRtv:
            return "rtv";
        case Dx12DumpResourceType::kDsv:
            return "dsv";
        case Dx12DumpResourceType::kSrv:
            return "srv";
        case Dx12DumpResourceType::kUav:
            return "uav";
        case Dx12DumpResourceType::kUavCounter:
            return "uavCounter";
        case Dx12DumpResourceType::kVertex:
            return "vertex";
        case Dx12DumpResourceType::kIndex:
            return "index";
        case Dx12DumpResourceType::kCbv:
            return "cbv";
        case Dx12DumpResourceType::kExecuteIndirectArg:
            return "eiArgs";
        case Dx12DumpResourceType::kExecuteIndirectCount:
            return "eiCount";
        case Dx12DumpResourceType::kUnknown:
        default:
            return "";
    }
}

static const char* Dx12DumpResourcePosToString(Dx12DumpResourcePos pos)
{
    switch (pos)
    {
        case Dx12DumpResourcePos::kBeforeDrawCall:
            return "before";
        case Dx12DumpResourcePos::kDrawCall:
            return "drawcall";
        case Dx12DumpResourcePos::kAfterDrawCall:
            return "after";
        case Dx12DumpResourcePos::kUnknown:
        default:
            return "";
    }
}

const static uint32_t kBeforeDrawCallArrayIndex = 0;
const static uint32_t kDrawCallArrayIndex       = 1;
const static uint32_t kAfterDrawCallArrayIndex  = 2;

uint32_t Dx12DumpResourcePosToArrayIndex(Dx12DumpResourcePos pos)
{
    switch (pos)
    {
        case Dx12DumpResourcePos::kBeforeDrawCall:
            return kBeforeDrawCallArrayIndex;
        case Dx12DumpResourcePos::kDrawCall:
            return kDrawCallArrayIndex;
        case Dx12DumpResourcePos::kAfterDrawCall:
            return kAfterDrawCallArrayIndex;
        case Dx12DumpResourcePos::kUnknown:
        default:
            GFXRECON_ASSERT(false && "Invalid use of Dx12DumpResourcePosToArrayIndex.");
            return 0;
    }
}

Dx12DumpResources::Dx12DumpResources(std::function<DxObjectInfo*(format::HandleId id)> get_object_info_func,
                                     const graphics::Dx12GpuVaMap&                     gpu_va_map,
                                     DxReplayOptions&                                  options) :
    get_object_info_func_(get_object_info_func),
    gpu_va_map_(gpu_va_map), options_(options), user_delegate_(nullptr), active_delegate_(nullptr)
{}

void Dx12DumpResources::StartDump(ID3D12Device* device, const std::string& capture_file_name)
{
    // prepare for copy resources
    auto hr = device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT,
                                             IID_PPV_ARGS(&track_dump_resources_.copy_cmd_allocator));

    const UINT64 initial_fence_value = 1;
    device->CreateFence(initial_fence_value, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&track_dump_resources_.fence));
    track_dump_resources_.fence_event        = CreateEventA(nullptr, TRUE, FALSE, nullptr);
    track_dump_resources_.fence_signal_value = initial_fence_value;

    if (user_delegate_ != nullptr)
    {
        active_delegate_ = user_delegate_;
    }
    else
    {
        // Use a default delegate if none was provided.
        default_delegate_ = std::make_unique<DefaultDx12DumpResourcesDelegate>();
        active_delegate_  = default_delegate_.get();
    }

    active_delegate_->BeginDumpResources(capture_file_name, track_dump_resources_);
}

void Dx12DumpResources::FinishDump(DxObjectInfo* queue_object_info)
{
    auto queue_extra_info = GetExtraInfo<D3D12CommandQueueInfo>(queue_object_info);
    if (queue_extra_info->pending_events.empty())
    {
        CloseDump();
        track_dump_resources_.Clear();
    }
    else
    {
        auto queue_sync_event = QueueSyncEventInfo{ false, false, nullptr, 0, [&]() {
                                                       CloseDump();
                                                       track_dump_resources_.Clear();
                                                   } };

        queue_extra_info->pending_events.push_back(queue_sync_event);
    }
}

void Dx12DumpResources::CloseDump()
{
    active_delegate_->EndDumpResources();
    active_delegate_ = nullptr;

    // Free the default delegate if it was used.
    default_delegate_ = nullptr;
}

bool Dx12DumpResources::ExecuteCommandLists(DxObjectInfo*                             replay_object_info,
                                            UINT                                      num_command_lists,
                                            HandlePointerDecoder<ID3D12CommandList*>* command_lists,
                                            const uint64_t                            block_index,
                                            const bool                                needs_mapping,
                                            const std::string&                        filename)
{
    bool is_complete = false;
    if (track_dump_resources_.target.execute_block_index == block_index)
    {
        if (needs_mapping)
        {
            GFXRECON_LOG_ERROR("Cannot dump resources on a command queue that requires additional processing for "
                               "DXR or EI so no resources will be dumped. Optimizing the capture file may allow "
                               "dump resources to succeed.");
        }
        else
        {
            auto replay_object = static_cast<ID3D12CommandQueue*>(replay_object_info->object);

            auto                            captured_command_lists = command_lists->GetHandlePointer();
            auto                            command_list_ids       = command_lists->GetPointer();
            std::vector<format::HandleId>   front_command_list_ids;
            std::vector<ID3D12CommandList*> modified_command_lists;
            auto device = graphics::dx12::GetDeviceComPtrFromChild<ID3D12Device>(replay_object);

            for (uint32_t i = 0; i < num_command_lists; ++i)
            {
                front_command_list_ids.emplace_back(command_list_ids[i]);
                if (i == track_dump_resources_.target.dump_resources_target.command_index)
                {
                    is_complete = true;
                    modified_command_lists.emplace_back(track_dump_resources_.split_command_sets[0].list);

                    auto modified_num_command_lists = modified_command_lists.size();
                    replay_object->ExecuteCommandLists(modified_num_command_lists, modified_command_lists.data());
                    modified_command_lists.clear();

                    StartDump(device, filename);

                    // Before and after copy resources do the same processes, so they do some duplicated
                    // processes, for exmaples: finding resource by GPU VA, getting the resource infomation, and
                    // write resource id, offset, size. But those duplicated processes shouldn't hurt the
                    // performance.
                    CopyDrawcallResources(
                        replay_object_info, front_command_list_ids, Dx12DumpResourcePos::kBeforeDrawCall);

                    ID3D12CommandList* ppCommandLists[] = { track_dump_resources_.split_command_sets[1].list };
                    replay_object->ExecuteCommandLists(1, ppCommandLists);

                    CopyDrawcallResources(
                        replay_object_info, front_command_list_ids, Dx12DumpResourcePos::kAfterDrawCall);

                    FinishDump(replay_object_info);

                    modified_command_lists.emplace_back(track_dump_resources_.split_command_sets[2].list);
                }
                else
                {
                    modified_command_lists.emplace_back(captured_command_lists[i]);
                }
            }
            if (is_complete && !modified_command_lists.empty())
            {
                auto modified_num_command_lists = modified_command_lists.size();
                replay_object->ExecuteCommandLists(modified_num_command_lists, modified_command_lists.data());
            }
        }
    }
    return is_complete;
}

void Dx12DumpResources::ExecuteBundle(DxObjectInfo* replay_object_info,
                                      DxObjectInfo* command_list_object_info,
                                      uint64_t      block_index)
{
    auto command_list      = static_cast<ID3D12GraphicsCommandList*>(command_list_object_info->object);
    auto dump_command_sets = GetCommandListsForDumpResources(
        replay_object_info, block_index, format::ApiCall_ID3D12GraphicsCommandList_ExecuteBundle);

    // size = 1: this replay_object is the target command list, but this ExecuteBundle isn't the target drawcall.
    // size = 0: this replay_object isn't the target command list.
    // size = 3: this replay_object is the target command list, also this ExecuteBundle is the target drawcall.
    if (dump_command_sets.size() == 1)
    {
        dump_command_sets[0].list->ExecuteBundle(command_list);
    }
    else
    {
        uint32_t i = 0;
        for (auto& command_set : dump_command_sets)
        {
            command_set.list->ExecuteBundle(track_dump_resources_.split_bundle_command_sets[i].list);
            ++i;
        }
    }
}

bool Dx12DumpResources::CreateRootSignature(DxObjectInfo*                device_object_info,
                                            HRESULT&                     replay_result,
                                            UINT                         node_mask,
                                            PointerDecoder<uint8_t>*     blob_with_root_signature_decoder,
                                            SIZE_T                       blob_length_in_bytes,
                                            Decoded_GUID                 riid,
                                            HandlePointerDecoder<void*>* root_signature_decoder)
{
    bool is_complete = false;
    auto handld_id   = *root_signature_decoder->GetPointer();
    if (track_dump_resources_.target.root_signature_handle_id == handld_id)
    {
        auto device = static_cast<ID3D12Device*>(device_object_info->object);

        // DATA_STATIC causes error for ResourceBarrier. Change it to NONE.
        graphics::dx12::ID3D12VersionedRootSignatureDeserializerComPtr root_sig_deserializer{ nullptr };
        HRESULT result = D3D12CreateVersionedRootSignatureDeserializer(
            blob_with_root_signature_decoder->GetPointer(), blob_length_in_bytes, IID_PPV_ARGS(&root_sig_deserializer));
        auto versioned_root_sig = root_sig_deserializer->GetUnconvertedRootSignatureDesc();

        D3D12_VERSIONED_ROOT_SIGNATURE_DESC modified_root_sig = *versioned_root_sig;
        if (modified_root_sig.Version == D3D_ROOT_SIGNATURE_VERSION_1_1 ||
            modified_root_sig.Version == D3D_ROOT_SIGNATURE_VERSION_1_2)
        {
            bool                                              is_modified = false;
            std::vector<D3D12_ROOT_PARAMETER1>                params;
            std::vector<std::vector<D3D12_DESCRIPTOR_RANGE1>> ranges;
            uint32_t                                          param_size = 0;
            if (modified_root_sig.Version == D3D_ROOT_SIGNATURE_VERSION_1_1)
            {
                param_size = modified_root_sig.Desc_1_1.NumParameters;
                params.resize(param_size);
                std::memcpy(
                    params.data(), modified_root_sig.Desc_1_1.pParameters, param_size * sizeof(D3D12_ROOT_PARAMETER1));
            }
            else if (modified_root_sig.Version == D3D_ROOT_SIGNATURE_VERSION_1_2)
            {
                param_size = modified_root_sig.Desc_1_2.NumParameters;
                params.resize(param_size);
                std::memcpy(
                    params.data(), modified_root_sig.Desc_1_2.pParameters, param_size * sizeof(D3D12_ROOT_PARAMETER1));
            }
            ranges.resize(param_size);

            for (uint32_t i = 0; i < param_size; ++i)
            {
                switch (params[i].ParameterType)
                {
                    case D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE:
                    {
                        auto range_size = params[i].DescriptorTable.NumDescriptorRanges;
                        ranges[i].resize(range_size);
                        std::memcpy(ranges[i].data(),
                                    params[i].DescriptorTable.pDescriptorRanges,
                                    range_size * sizeof(D3D12_DESCRIPTOR_RANGE1));
                        for (uint32_t j = 0; j < range_size; ++j)
                        {
                            if (ranges[i][j].Flags == D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC)
                            {
                                ranges[i][j].Flags = D3D12_DESCRIPTOR_RANGE_FLAG_NONE;
                                is_modified        = true;
                            }
                        }
                        params[i].DescriptorTable.pDescriptorRanges = ranges[i].data();
                        break;
                    }
                    default:
                        break;
                }
            }
            if (is_modified)
            {
                if (modified_root_sig.Version == D3D_ROOT_SIGNATURE_VERSION_1_1)
                {
                    modified_root_sig.Desc_1_1.pParameters = params.data();
                }
                else if (modified_root_sig.Version == D3D_ROOT_SIGNATURE_VERSION_1_2)
                {
                    modified_root_sig.Desc_1_2.pParameters = params.data();
                }

                ID3D10Blob* p_modified_blob       = nullptr;
                ID3D10Blob* p_modified_error_blob = nullptr;
                replay_result =
                    D3D12SerializeVersionedRootSignature(&modified_root_sig, &p_modified_blob, &p_modified_error_blob);

                GFXRECON_ASSERT(SUCCEEDED(replay_result));

                auto modified_size   = p_modified_blob->GetBufferSize();
                auto modified_buffer = p_modified_blob->GetBufferPointer();

                // TODO: This new signautre use NONE, instead of DATA_STATIC.
                //       DATA_STATIC is optimization, so new signature might impact the performance.
                //       It could create two root signatures. Keep original one and create new one.
                //       The only target command llist use the new one. The others use the original one.
                //       But if it has two root signatures, it also needs to have two PipeStates.
                //       The target command list needs to use the new PipeStates for Create and Reset.
                replay_result = device->CreateRootSignature(node_mask,
                                                            modified_buffer,
                                                            modified_size,
                                                            *riid.decoded_value,
                                                            root_signature_decoder->GetHandlePointer());
                GFXRECON_ASSERT(SUCCEEDED(replay_result));
                is_complete = true;
            }
        }
    }
    return is_complete;
}

void Dx12DumpResources::OMSetRenderTargets(
    const ApiCallInfo&                                         call_info,
    DxObjectInfo*                                              object_info,
    UINT                                                       NumRenderTargetDescriptors,
    StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pRenderTargetDescriptors,
    BOOL                                                       RTsSingleHandleToDescriptorRange,
    StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pDepthStencilDescriptor)
{
    if (call_info.index == track_dump_resources_.target.set_render_targets_block_index)
    {
        auto descriptor_increment = 0;
        if (RTsSingleHandleToDescriptorRange)
        {
            // Determine descriptor increment for contiguous render target descriptors.
            auto cmd_list = reinterpret_cast<ID3D12GraphicsCommandList*>(object_info->object);
            auto device   = graphics::dx12::GetDeviceComPtrFromChild<ID3D12Device>(cmd_list);
            if (device != nullptr)
            {
                descriptor_increment = device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
            }
            else
            {
                GFXRECON_LOG_ERROR("Failed to get Device for GetDescriptorHandleIncrementSize in OMSetRenderTargets.");
            }
        }

        auto rt_handles = pRenderTargetDescriptors->GetMetaStructPointer();
        track_dump_resources_.render_target_heap_ids.resize(NumRenderTargetDescriptors);
        track_dump_resources_.replay_render_target_handles.resize(NumRenderTargetDescriptors);
        for (uint32_t i = 0; i < NumRenderTargetDescriptors; ++i)
        {
            if (RTsSingleHandleToDescriptorRange)
            {
                // All render target descriptors are contiguous in the same descriptor heap.
                track_dump_resources_.render_target_heap_ids[i] = rt_handles[0].heap_id;
                track_dump_resources_.replay_render_target_handles[i] =
                    D3D12_CPU_DESCRIPTOR_HANDLE{ (*rt_handles[0].decoded_value).ptr + descriptor_increment * i };
            }
            else
            {
                track_dump_resources_.render_target_heap_ids[i]       = rt_handles[i].heap_id;
                track_dump_resources_.replay_render_target_handles[i] = *rt_handles[i].decoded_value;
            }
        }
        auto ds_handle = pDepthStencilDescriptor->GetMetaStructPointer();
        if (ds_handle)
        {
            track_dump_resources_.depth_stencil_heap_id       = ds_handle->heap_id;
            track_dump_resources_.replay_depth_stencil_handle = *ds_handle->decoded_value;
        }
    }
}

void Dx12DumpResources::BeginRenderPass(
    DxObjectInfo*                                                       replay_object_info,
    UINT                                                                NumRenderTargets,
    StructPointerDecoder<Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC>* pRenderTargets,
    StructPointerDecoder<Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC>* pDepthStencil,
    D3D12_RENDER_PASS_FLAGS                                             Flags,
    uint64_t                                                            block_index)
{
    auto dump_command_sets = GetCommandListsForDumpResources(
        replay_object_info, block_index, format::ApiCall_ID3D12GraphicsCommandList4_BeginRenderPass);
    if (!dump_command_sets.empty())
    {
        if (dump_command_sets.size() == 3)
        {
            auto captured_rt_descs = pRenderTargets->GetMetaStructPointer();
            track_dump_resources_.render_target_heap_ids.resize(NumRenderTargets);
            track_dump_resources_.replay_render_target_handles.resize(NumRenderTargets);
            for (uint32_t i = 0; i < NumRenderTargets; ++i)
            {
                track_dump_resources_.render_target_heap_ids[i] = captured_rt_descs[i].cpuDescriptor->heap_id;
                track_dump_resources_.replay_render_target_handles[i] =
                    *captured_rt_descs[i].cpuDescriptor->decoded_value;
            }

            auto captured_ds_desc = pDepthStencil->GetMetaStructPointer();
            if (!pDepthStencil->IsNull())
            {
                track_dump_resources_.depth_stencil_heap_id       = captured_ds_desc->cpuDescriptor->heap_id;
                track_dump_resources_.replay_depth_stencil_handle = *captured_ds_desc->cpuDescriptor->decoded_value;
            }

            // before
            ID3D12GraphicsCommandList4* command_list4_before;
            dump_command_sets[kBeforeDrawCallArrayIndex].list->QueryInterface(IID_PPV_ARGS(&command_list4_before));

            std::vector<D3D12_RENDER_PASS_RENDER_TARGET_DESC> before_rt_descs;
            for (uint32_t i = 0; i < NumRenderTargets; ++i)
            {
                D3D12_RENDER_PASS_RENDER_TARGET_DESC desc = *captured_rt_descs[i].decoded_value;
                desc.EndingAccess.Type                    = D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE;
                before_rt_descs.emplace_back(std::move(desc));
            }

            D3D12_RENDER_PASS_DEPTH_STENCIL_DESC  before_ds_desc   = {};
            D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* p_before_ds_desc = nullptr;
            if (!pDepthStencil->IsNull())
            {
                before_ds_desc                          = *captured_ds_desc->decoded_value;
                before_ds_desc.DepthEndingAccess.Type   = D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE;
                before_ds_desc.StencilEndingAccess.Type = D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE;
                p_before_ds_desc                        = &before_ds_desc;
            }
            command_list4_before->BeginRenderPass(NumRenderTargets, before_rt_descs.data(), p_before_ds_desc, Flags);

            // drawcall
            ID3D12GraphicsCommandList4* command_list4_draw_call;
            dump_command_sets[kDrawCallArrayIndex].list->QueryInterface(IID_PPV_ARGS(&command_list4_draw_call));

            std::vector<D3D12_RENDER_PASS_RENDER_TARGET_DESC> draw_call_rt_descs;
            for (uint32_t i = 0; i < NumRenderTargets; ++i)
            {
                D3D12_RENDER_PASS_RENDER_TARGET_DESC desc = *captured_rt_descs[i].decoded_value;
                desc.BeginningAccess.Type                 = D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE;
                desc.EndingAccess.Type                    = D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE;
                draw_call_rt_descs.emplace_back(std::move(desc));
            }

            D3D12_RENDER_PASS_DEPTH_STENCIL_DESC  draw_call_ds_desc   = {};
            D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* p_draw_call_ds_desc = nullptr;
            if (!pDepthStencil->IsNull())
            {
                draw_call_ds_desc                             = *captured_ds_desc->decoded_value;
                draw_call_ds_desc.DepthBeginningAccess.Type   = D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE;
                draw_call_ds_desc.StencilBeginningAccess.Type = D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE;
                draw_call_ds_desc.DepthEndingAccess.Type      = D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE;
                draw_call_ds_desc.StencilEndingAccess.Type    = D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE;
                p_draw_call_ds_desc                           = &draw_call_ds_desc;
            }
            command_list4_draw_call->BeginRenderPass(
                NumRenderTargets, draw_call_rt_descs.data(), p_draw_call_ds_desc, Flags);

            // after
            ID3D12GraphicsCommandList4* command_list4_after;
            dump_command_sets[kAfterDrawCallArrayIndex].list->QueryInterface(IID_PPV_ARGS(&command_list4_after));

            std::vector<D3D12_RENDER_PASS_RENDER_TARGET_DESC> after_rt_descs;
            for (uint32_t i = 0; i < NumRenderTargets; ++i)
            {
                D3D12_RENDER_PASS_RENDER_TARGET_DESC desc = *captured_rt_descs[i].decoded_value;
                desc.BeginningAccess.Type                 = D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE;
                after_rt_descs.emplace_back(std::move(desc));
            }

            D3D12_RENDER_PASS_DEPTH_STENCIL_DESC  after_ds_desc   = {};
            D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* p_after_ds_desc = nullptr;
            if (!pDepthStencil->IsNull())
            {
                after_ds_desc                             = *captured_ds_desc->decoded_value;
                after_ds_desc.DepthBeginningAccess.Type   = D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE;
                after_ds_desc.StencilBeginningAccess.Type = D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE;
                p_after_ds_desc                           = &after_ds_desc;
            }
            command_list4_after->BeginRenderPass(NumRenderTargets, after_rt_descs.data(), p_after_ds_desc, Flags);
        }
        else if (dump_command_sets.size() == 1)
        {
            ID3D12GraphicsCommandList4* command_list4;
            dump_command_sets[0].list->QueryInterface(IID_PPV_ARGS(&command_list4));
            command_list4->BeginRenderPass(
                NumRenderTargets, pRenderTargets->GetPointer(), pDepthStencil->GetPointer(), Flags);
        }
    }
}

bool MatchDescriptorCPUGPUHandle(size_t                                      replay_cpu_addr_begin,
                                 size_t                                      replay_target_cpu_addr,
                                 uint64_t                                    capture_gpu_addr_begin,
                                 std::map<UINT, D3D12_GPU_DESCRIPTOR_HANDLE> captured_gpu_addrs)
{
    for (auto gpu_addr : captured_gpu_addrs)
    {
        if ((gpu_addr.second.ptr >= capture_gpu_addr_begin) &&
            ((replay_target_cpu_addr - replay_cpu_addr_begin) == (gpu_addr.second.ptr - capture_gpu_addr_begin)))
        {
            return true;
        }
    }
    return false;
}

void Dx12DumpResources::CopyDrawcallResources(DxObjectInfo*                        queue_object_info,
                                              const std::vector<format::HandleId>& front_command_list_ids,
                                              Dx12DumpResourcePos                  pos)
{
    // If Bundle have the bindings, using the bindings, or using the command's bindings.
    auto bundle_target_drawcall = track_dump_resources_.target.bundle_target_drawcall.get();

    // pair first: path name, second: resource index. If index is kNoneIndex, it means not a array.
    std::vector<std::pair<std::string, int32_t>> json_path;
    uint32_t                                     resource_index = 0;
    const std::vector<uint32_t>                  sub_indices_emptry{ 0 };

    // vertex
    const std::vector<D3D12_VERTEX_BUFFER_VIEW>* vertex_buffer_views = nullptr;
    if (bundle_target_drawcall && !bundle_target_drawcall->captured_vertex_buffer_views.empty())
    {
        vertex_buffer_views = &bundle_target_drawcall->captured_vertex_buffer_views;
    }
    else
    {
        vertex_buffer_views = &track_dump_resources_.target.captured_vertex_buffer_views;
    }
    if (vertex_buffer_views)
    {
        resource_index = 0;
        for (const auto& view : *vertex_buffer_views)
        {
            json_path.clear();
            json_path.emplace_back("vertex", resource_index);
            CopyDrawcallResourceByGPUVA(queue_object_info,
                                        front_command_list_ids,
                                        view.BufferLocation,
                                        view.SizeInBytes,
                                        json_path,
                                        Dx12DumpResourceType::kVertex,
                                        pos,
                                        format::kNullHandleId,
                                        0);
            ++resource_index;
        }
    }

    // index
    const D3D12_INDEX_BUFFER_VIEW* index_buffer_view = nullptr;
    if (bundle_target_drawcall && bundle_target_drawcall->captured_index_buffer_view.BufferLocation != kNullGpuAddress)
    {
        index_buffer_view = &bundle_target_drawcall->captured_index_buffer_view;
    }
    else
    {
        index_buffer_view = &track_dump_resources_.target.captured_index_buffer_view;
    }
    if (index_buffer_view)
    {
        json_path.clear();
        json_path.emplace_back("index", format::kNoneIndex);
        CopyDrawcallResourceByGPUVA(queue_object_info,
                                    front_command_list_ids,
                                    index_buffer_view->BufferLocation,
                                    index_buffer_view->SizeInBytes,
                                    json_path,
                                    Dx12DumpResourceType::kIndex,
                                    pos,
                                    format::kNullHandleId,
                                    0);
    }

    // descriptor
    std::vector<std::pair<std::string, int32_t>>       json_path_sub;
    const std::vector<format::HandleId>*               descriptor_heap_ids    = nullptr;
    const std::map<UINT, D3D12_GPU_DESCRIPTOR_HANDLE>* descriptor_gpu_handles = nullptr;
    if (bundle_target_drawcall && !bundle_target_drawcall->descriptor_heap_ids.empty())
    {
        descriptor_heap_ids = &bundle_target_drawcall->descriptor_heap_ids;
    }
    else
    {
        descriptor_heap_ids = &track_dump_resources_.target.descriptor_heap_ids;
    }
    if (bundle_target_drawcall && !bundle_target_drawcall->captured_descriptor_gpu_handles.empty())
    {
        descriptor_gpu_handles = &bundle_target_drawcall->captured_descriptor_gpu_handles;
    }
    else
    {
        descriptor_gpu_handles = &track_dump_resources_.target.captured_descriptor_gpu_handles;
    }
    if (descriptor_heap_ids && descriptor_gpu_handles)
    {
        json_path.clear();
        json_path.emplace_back("descriptor_heap", format::kNoneIndex);

        auto heap_size = descriptor_heap_ids->size();
        for (uint32_t heap_index = 0; heap_index < heap_size; ++heap_index)
        {
            auto descriptor_heap_id = (*descriptor_heap_ids)[heap_index];

            json_path.emplace_back("heap_id_" + util::HandleIdToString(descriptor_heap_id), format::kNoneIndex);

            auto heap_object_info = get_object_info_func_(descriptor_heap_id);
            auto heap_extra_info  = GetExtraInfo<D3D12DescriptorHeapInfo>(heap_object_info);

            // constant buffer
            resource_index = 0;
            for (const auto& info_pair : heap_extra_info->constant_buffer_infos)
            {
                auto        descriptor_heap_index = info_pair.first;
                const auto& info                  = info_pair.second;
                if (MatchDescriptorCPUGPUHandle(heap_extra_info->replay_cpu_addr_begin,
                                                info.replay_handle.ptr,
                                                heap_extra_info->capture_gpu_addr_begin,
                                                *descriptor_gpu_handles))
                {
                    json_path_sub = json_path;
                    json_path_sub.emplace_back("constant_buffer_views", resource_index);
                    CopyDrawcallResourceByGPUVA(queue_object_info,
                                                front_command_list_ids,
                                                info.captured_view.BufferLocation,
                                                info.captured_view.SizeInBytes,
                                                json_path_sub,
                                                Dx12DumpResourceType::kCbv,
                                                pos,
                                                descriptor_heap_id,
                                                descriptor_heap_index);
                    ++resource_index;
                }
            }

            if (TEST_SHADER_RES)
            {
                // shader resource
                resource_index = 0;
                for (const auto& info_pair : heap_extra_info->shader_resource_infos)
                {
                    auto        descriptor_heap_index = info_pair.first;
                    const auto& info                  = info_pair.second;
                    if (MatchDescriptorCPUGPUHandle(heap_extra_info->replay_cpu_addr_begin,
                                                    info.replay_handle.ptr,
                                                    heap_extra_info->capture_gpu_addr_begin,
                                                    *descriptor_gpu_handles))
                    {
                        uint64_t offset = 0;
                        uint64_t size   = 0;
                        switch (info.view.ViewDimension)
                        {
                            case D3D12_SRV_DIMENSION_BUFFER:
                            {
                                auto size = info.view.Buffer.StructureByteStride;
                                if (size == 0)
                                {
                                    size = graphics::dx12::GetSubresourcePixelByteSize(info.view.Format);
                                }
                                offset = info.view.Buffer.FirstElement * size;
                                size   = info.view.Buffer.NumElements * size;
                                break;
                            }
                            default:
                                break;
                        }
                        json_path_sub = json_path;
                        json_path_sub.emplace_back("shader_resource_views", resource_index);
                        CopyDrawcallResourceBySubresource(queue_object_info,
                                                          front_command_list_ids,
                                                          info.resource_id,
                                                          offset,
                                                          size,
                                                          info.subresource_indices,
                                                          json_path_sub,
                                                          Dx12DumpResourceType::kSrv,
                                                          pos,
                                                          descriptor_heap_id,
                                                          descriptor_heap_index);
                        ++resource_index;
                    }
                }

                // unordered access
                resource_index = 0;
                for (const auto& info_pair : heap_extra_info->unordered_access_infos)
                {
                    auto        descriptor_heap_index = info_pair.first;
                    const auto& info                  = info_pair.second;
                    if (MatchDescriptorCPUGPUHandle(heap_extra_info->replay_cpu_addr_begin,
                                                    info.replay_handle.ptr,
                                                    heap_extra_info->capture_gpu_addr_begin,
                                                    *descriptor_gpu_handles))
                    {
                        uint64_t offset = 0;
                        uint64_t size   = 0;
                        switch (info.view.ViewDimension)
                        {
                            case D3D12_UAV_DIMENSION_BUFFER:
                            {
                                auto size = info.view.Buffer.StructureByteStride;
                                if (size == 0)
                                {
                                    size = graphics::dx12::GetSubresourcePixelByteSize(info.view.Format);
                                }
                                offset = info.view.Buffer.FirstElement * size;
                                size   = info.view.Buffer.NumElements * size;
                                break;
                            }
                            default:
                                break;
                        }
                        json_path_sub = json_path;
                        json_path_sub.emplace_back("unordered_access_views", resource_index);
                        json_path_sub.emplace_back("resource", format::kNoneIndex);
                        CopyDrawcallResourceBySubresource(queue_object_info,
                                                          front_command_list_ids,
                                                          info.resource_id,
                                                          offset,
                                                          size,
                                                          info.subresource_indices,
                                                          json_path_sub,
                                                          Dx12DumpResourceType::kUav,
                                                          pos,
                                                          descriptor_heap_id,
                                                          descriptor_heap_index);

                        if (info.counter_resource_id != format::kNullHandleId)
                        {
                            json_path_sub = json_path;
                            json_path_sub.emplace_back("unordered_access_views", resource_index);
                            json_path_sub.emplace_back("counter_resource", format::kNoneIndex);
                            CopyDrawcallResourceBySubresource(queue_object_info,
                                                              front_command_list_ids,
                                                              info.counter_resource_id,
                                                              info.view.Buffer.CounterOffsetInBytes,
                                                              0,
                                                              sub_indices_emptry,
                                                              json_path_sub,
                                                              Dx12DumpResourceType::kUavCounter,
                                                              pos,
                                                              descriptor_heap_id,
                                                              descriptor_heap_index);
                        }
                        ++resource_index;
                    }
                }
            }
        }
    }

    // render target
    // render target isn't available in Bundle.
    resource_index = 0;
    auto rt_size   = track_dump_resources_.replay_render_target_handles.size();
    for (uint32_t i = 0; i < rt_size; ++i)
    {
        auto descriptor_heap_id = track_dump_resources_.render_target_heap_ids[i];
        auto heap_object_info   = get_object_info_func_(descriptor_heap_id);
        auto heap_extra_info    = GetExtraInfo<D3D12DescriptorHeapInfo>(heap_object_info);

        for (const auto& info_pair : heap_extra_info->render_target_infos)
        {
            auto        descriptor_heap_index = info_pair.first;
            const auto& info                  = info_pair.second;
            if (info.replay_handle.ptr == track_dump_resources_.replay_render_target_handles[i].ptr)
            {
                uint64_t offset = 0;
                uint64_t size   = 0;
                switch (info.view.ViewDimension)
                {
                    case D3D12_RTV_DIMENSION_BUFFER:
                    {
                        auto size = graphics::dx12::GetSubresourcePixelByteSize(info.view.Format);
                        offset    = info.view.Buffer.FirstElement * size;
                        size      = info.view.Buffer.NumElements * size;
                        break;
                    }
                    default:
                        break;
                }
                json_path.clear();
                json_path.emplace_back("render_target_views", resource_index);
                CopyDrawcallResourceBySubresource(queue_object_info,
                                                  front_command_list_ids,
                                                  info.resource_id,
                                                  0,
                                                  0,
                                                  info.subresource_indices,
                                                  json_path,
                                                  Dx12DumpResourceType::kRtv,
                                                  pos,
                                                  descriptor_heap_id,
                                                  descriptor_heap_index);
                ++resource_index;
                break;
            }
        }
    }

    // depth stencil
    // depth stencil isn't available in Bundle.
    if (track_dump_resources_.replay_depth_stencil_handle.ptr != kNullCpuAddress)
    {
        auto descriptor_heap_id = track_dump_resources_.depth_stencil_heap_id;
        auto heap_object_info   = get_object_info_func_(descriptor_heap_id);
        auto heap_extra_info    = GetExtraInfo<D3D12DescriptorHeapInfo>(heap_object_info);

        for (const auto& info_pair : heap_extra_info->depth_stencil_infos)
        {
            auto        descriptor_heap_index = info_pair.first;
            const auto& info                  = info_pair.second;
            if (info.replay_handle.ptr == track_dump_resources_.replay_depth_stencil_handle.ptr)
            {
                json_path.clear();
                json_path.emplace_back("depth_stencil_views", format::kNoneIndex);
                CopyDrawcallResourceBySubresource(queue_object_info,
                                                  front_command_list_ids,
                                                  info.resource_id,
                                                  0,
                                                  0,
                                                  info.subresource_indices,
                                                  json_path,
                                                  Dx12DumpResourceType::kDsv,
                                                  pos,
                                                  descriptor_heap_id,
                                                  descriptor_heap_index);
                break;
            }
        }
    }

    // ExecuteIndirect
    const ExecuteIndirectInfo* exe_indirect_info = nullptr;
    if (bundle_target_drawcall && bundle_target_drawcall->execute_indirect_info.argument_id != format::kNullHandleId)
    {
        exe_indirect_info = &bundle_target_drawcall->execute_indirect_info;
    }
    else
    {
        exe_indirect_info = &track_dump_resources_.target.execute_indirect_info;
    }
    if (exe_indirect_info)
    {
        json_path.clear();
        json_path.emplace_back("execute_indirect_arguments", format::kNoneIndex);
        CopyDrawcallResourceBySubresource(queue_object_info,
                                          front_command_list_ids,
                                          exe_indirect_info->argument_id,
                                          exe_indirect_info->argument_offset,
                                          0,
                                          sub_indices_emptry,
                                          json_path,
                                          Dx12DumpResourceType::kExecuteIndirectArg,
                                          pos,
                                          format::kNullHandleId,
                                          0);
        json_path.clear();
        json_path.emplace_back("execute_indirect_counts", format::kNoneIndex);
        CopyDrawcallResourceBySubresource(queue_object_info,
                                          front_command_list_ids,
                                          exe_indirect_info->count_id,
                                          exe_indirect_info->count_offset,
                                          0,
                                          sub_indices_emptry,
                                          json_path,
                                          Dx12DumpResourceType::kExecuteIndirectCount,
                                          pos,
                                          format::kNullHandleId,
                                          0);
    }
}

void Dx12DumpResources::CopyDrawcallResourceByGPUVA(DxObjectInfo*                        queue_object_info,
                                                    const std::vector<format::HandleId>& front_command_list_ids,
                                                    D3D12_GPU_VIRTUAL_ADDRESS            captured_source_gpu_va,
                                                    uint64_t                             source_size,
                                                    const std::vector<std::pair<std::string, int32_t>>& json_path,
                                                    Dx12DumpResourceType                                resource_type,
                                                    Dx12DumpResourcePos                                 pos,
                                                    format::HandleId descriptor_heap_id,
                                                    uint32_t         descriptor_heap_index)
{
    if (captured_source_gpu_va == 0)
    {
        return;
    }
    auto source_resource_id          = object_mapping::FindResourceIDbyGpuVA(captured_source_gpu_va, gpu_va_map_);
    auto source_resource_object_info = get_object_info_func_(source_resource_id);
    auto source_resource_extra_info  = GetExtraInfo<D3D12ResourceInfo>(source_resource_object_info);

    CopyDrawcallResourceBySubresource(queue_object_info,
                                      front_command_list_ids,
                                      source_resource_id,
                                      (captured_source_gpu_va - source_resource_extra_info->capture_address_),
                                      source_size,
                                      { 0 },
                                      json_path,
                                      resource_type,
                                      pos,
                                      descriptor_heap_id,
                                      descriptor_heap_index);
}

void Dx12DumpResources::CopyDrawcallResourceBySubresource(DxObjectInfo*                        queue_object_info,
                                                          const std::vector<format::HandleId>& front_command_list_ids,
                                                          format::HandleId                     source_resource_id,
                                                          uint64_t                             source_offset,
                                                          uint64_t                             source_size,
                                                          const std::vector<uint32_t>&         subresource_indices,
                                                          const std::vector<std::pair<std::string, int32_t>>& json_path,
                                                          Dx12DumpResourceType resource_type,
                                                          Dx12DumpResourcePos  pos,
                                                          format::HandleId     descriptor_heap_id,
                                                          uint32_t             descriptor_heap_index)
{
    CopyResourceDataPtr copy_resource_data(new CopyResourceData());
    copy_resource_data->subresource_indices   = subresource_indices;
    copy_resource_data->json_path             = json_path;
    copy_resource_data->resource_type         = resource_type;
    copy_resource_data->dump_position         = pos;
    copy_resource_data->descriptor_heap_id    = descriptor_heap_id;
    copy_resource_data->descriptor_heap_index = descriptor_heap_index;

    CopyDrawcallResource(
        queue_object_info, front_command_list_ids, source_resource_id, source_offset, source_size, copy_resource_data);
}

// If source_size = 0, the meaning is the whole after offset.
void Dx12DumpResources::CopyDrawcallResource(DxObjectInfo*                        queue_object_info,
                                             const std::vector<format::HandleId>& front_command_list_ids,
                                             format::HandleId                     source_resource_id,
                                             uint64_t                             source_offset,
                                             uint64_t                             source_size,
                                             CopyResourceDataPtr                  copy_resource_data)
{
    if (source_resource_id == 0)
    {
        return;
    }
    copy_resource_data->source_resource_id = source_resource_id;

    auto source_resource_object_info = get_object_info_func_(copy_resource_data->source_resource_id);
    auto source_resource             = reinterpret_cast<ID3D12Resource*>(source_resource_object_info->object);
    copy_resource_data->desc         = source_resource->GetDesc();

    size_t subresource_count;
    copy_resource_data->subresource_footprint_offsets.clear();
    copy_resource_data->subresource_footprint_sizes.clear();
    copy_resource_data->footprints.clear();
    copy_resource_data->total_size = 0;
    graphics::Dx12ResourceDataUtil::GetResourceCopyInfo(source_resource,
                                                        subresource_count,
                                                        copy_resource_data->subresource_footprint_offsets,
                                                        copy_resource_data->subresource_footprint_sizes,
                                                        copy_resource_data->footprints,
                                                        copy_resource_data->total_size);

    copy_resource_data->datas.resize(subresource_count);

    copy_resource_data->is_cpu_accessible = graphics::Dx12ResourceDataUtil::IsResourceCpuAccessible(
        source_resource, graphics::Dx12ResourceDataUtil::kCopyTypeRead);

    if (!copy_resource_data->is_cpu_accessible)
    {
        auto device = graphics::dx12::GetDeviceComPtrFromChild<ID3D12Device>(source_resource);
        if (device != nullptr)
        {
            // Get or create staging buffer.
            if (!track_dump_resources_.copy_staging_buffer ||
                (track_dump_resources_.copy_staging_buffer_size < copy_resource_data->total_size))
            {
                // TODO: If we could know the max required resource size for the all dump resources, we wouldn't need to
                //       free and re-create buffer. But it's tough to know it. dx12_brower_consumer might help it.
                //       It needs a map to match GPU virutal address with resources. Use a GPU virtal address
                //       to find its resource, and then know the size.
                track_dump_resources_.copy_staging_buffer = nullptr;
                track_dump_resources_.copy_staging_buffer = graphics::Dx12ResourceDataUtil::CreateStagingBuffer(
                    device, graphics::Dx12ResourceDataUtil::CopyType::kCopyTypeRead, copy_resource_data->total_size);
                track_dump_resources_.copy_staging_buffer_size = copy_resource_data->total_size;

                GFXRECON_ASSERT(track_dump_resources_.copy_staging_buffer);
            }
            copy_resource_data->read_resource                   = track_dump_resources_.copy_staging_buffer;
            copy_resource_data->read_resource_is_staging_buffer = true;

            if (track_dump_resources_.copy_cmd_allocator)
            {
                device->CreateCommandList(0,
                                          D3D12_COMMAND_LIST_TYPE_DIRECT,
                                          track_dump_resources_.copy_cmd_allocator,
                                          nullptr,
                                          IID_PPV_ARGS(&copy_resource_data->cmd_list));
            }

            if (copy_resource_data->cmd_list == nullptr)
            {
                GFXRECON_LOG_ERROR("Failed to create command list for dump resources.");
            }
        }
    }

    // Determine whether to read the full subresource or just part of it.
    copy_resource_data->subresource_offsets.resize(subresource_count, 0);
    copy_resource_data->subresource_sizes = copy_resource_data->subresource_footprint_sizes;
    if (copy_resource_data->desc.Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
    {
        // Buffer has its offset and size.
        if (source_size == 0)
        {
            source_size = copy_resource_data->total_size - source_offset;
        }
        copy_resource_data->subresource_offsets[0] = source_offset;
        copy_resource_data->subresource_sizes[0]   = source_size;
    }

    CopyResourceAsync(queue_object_info, front_command_list_ids, copy_resource_data);
}

bool Dx12DumpResources::CopyResourceAsyncQueue(const std::vector<format::HandleId>& front_command_list_ids,
                                               CopyResourceDataPtr                  copy_resource_data,
                                               ID3D12CommandQueue*                  draw_call_queue,
                                               ID3D12Fence*                         fence,
                                               UINT64                               fence_signal_value,
                                               UINT64                               fence_wait_value)
{

    auto source_resource_object_info = get_object_info_func_(copy_resource_data->source_resource_id);
    auto source_resource             = reinterpret_cast<ID3D12Resource*>(source_resource_object_info->object);
    auto source_resource_extra_info  = GetExtraInfo<D3D12ResourceInfo>(source_resource_object_info);

    graphics::dx12::ID3D12CommandQueueComPtr queue = nullptr;
    if (source_resource_extra_info->swap_chain_id != format::kNullHandleId)
    {
        auto swapchain_extra_info =
            GetExtraInfo<DxgiSwapchainInfo>(get_object_info_func_(source_resource_extra_info->swap_chain_id));
        if (draw_call_queue != swapchain_extra_info->command_queue)
        {
            // Can only read swapchain buffers from the swapchain's queue.
            GFXRECON_LOG_ERROR("TODO: Is the swapchain queue always the same as the draw call queue?");
        }
    }

    HRESULT hr = S_OK;
    if (copy_resource_data->is_cpu_accessible)
    {
        // If the source_resource is CPU accessible, it can be read from directly.
        copy_resource_data->read_resource                   = source_resource;
        copy_resource_data->read_resource_is_staging_buffer = false;
    }
    else
    {
        // If the source_resource is not CPU accessible, build and execute a command list to copy data from the
        // source_resource to a staging_buffer.

        // Determine subresource states in order to transition to D3D12_RESOURCE_STATE_COPY_SOURCE.
        std::vector<graphics::dx12::ResourceStateInfo> res_infos = source_resource_extra_info->resource_state_infos;
        auto                                           size      = front_command_list_ids.size();
        for (uint32_t i = 0; i < size; ++i)
        {
            auto cmd_list_extra_info =
                GetExtraInfo<D3D12CommandListInfo>(get_object_info_func_(front_command_list_ids[i]));
            auto pending_states_iter =
                cmd_list_extra_info->pending_resource_states.find(source_resource_object_info->capture_id);
            if (pending_states_iter != cmd_list_extra_info->pending_resource_states.end())
            {
                for (const auto& state : pending_states_iter->second)
                {
                    bool is_update = true;
                    if (i == (size - 1))
                    {
                        if (state.block_index > track_dump_resources_.target.drawcall_block_index)
                        {
                            is_update = false;
                        }
                    }
                    if (is_update)
                    {
                        if (state.transition.Subresource == D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES)
                        {
                            for (auto& info : res_infos)
                            {
                                info.states        = state.transition.StateAfter;
                                info.barrier_flags = state.barrier_flags;
                            }
                        }
                        else
                        {
                            res_infos[state.transition.Subresource].states        = state.transition.StateAfter;
                            res_infos[state.transition.Subresource].barrier_flags = state.barrier_flags;
                        }
                    }
                }
            }
        }

        // Build command list for copying to staging buffer.
        hr = graphics::Dx12ResourceDataUtil::RecordCommandsToCopyResource(copy_resource_data->cmd_list,
                                                                          source_resource,
                                                                          graphics::Dx12ResourceDataUtil::kCopyTypeRead,
                                                                          copy_resource_data->total_size,
                                                                          copy_resource_data->footprints,
                                                                          res_infos,
                                                                          res_infos,
                                                                          copy_resource_data->read_resource);

        if (SUCCEEDED(hr))
        {
            // Execute the command list.
            hr                             = copy_resource_data->cmd_list->Close();
            ID3D12CommandList* cmd_lists[] = { copy_resource_data->cmd_list };
            draw_call_queue->ExecuteCommandLists(1, cmd_lists);
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to record commands to copy resource data for resource %" PRIu64,
                               copy_resource_data->source_resource_id);
        }
    }

    // Signal the fence to indicate that data has been copied to the staging resource.
    hr = draw_call_queue->Signal(fence, fence_signal_value);
    GFXRECON_ASSERT(SUCCEEDED(hr));

    // Wait for the next fence value indicating that staging data has been read and is safe to continue.
    hr = draw_call_queue->Wait(fence, fence_wait_value);
    GFXRECON_ASSERT(SUCCEEDED(hr));

    return true;
}

// Wait for the queued work to complete and then read the copied resource.
void Dx12DumpResources::CopyResourceAsyncRead(graphics::dx12::ID3D12FenceComPtr fence,
                                              UINT64                            fence_wait_value,
                                              UINT64                            fence_signal_value,
                                              HANDLE                            fence_event,
                                              CopyResourceDataPtr               copy_resource_data)
{
    auto        resource            = copy_resource_data->read_resource;
    const auto& subresource_indices = copy_resource_data->subresource_indices;
    const auto& subresource_sizes   = copy_resource_data->subresource_footprint_sizes;

    // Wait for the command queue before reading data.
    UINT64 completed_value = fence->GetCompletedValue();
    if (completed_value == UINT64_MAX)
    {
        GFXRECON_LOG_FATAL(
            "Invalid fence value (UINT64_MAX). Device may have been removed. GFXR is unable to continue.");
        return;
    }
    if (completed_value < fence_wait_value)
    {
        ResetEvent(fence_event);
        fence->SetEventOnCompletion(fence_wait_value, fence_event);
        WaitForSingleObject(fence_event, INFINITE);
    }

    auto& subresource_datas = copy_resource_data->datas;
    if (copy_resource_data->read_resource_is_staging_buffer)
    {
        // Read staging buffer data.
        const auto&          subresource_offsets = copy_resource_data->subresource_footprint_offsets;
        std::vector<uint8_t> full_resource_data;
        full_resource_data.resize(copy_resource_data->total_size);
        graphics::Dx12ResourceDataUtil::MapSubresourceAndReadData(
            resource, 0, full_resource_data.size(), full_resource_data.data());
        for (auto i : subresource_indices)
        {
            subresource_datas[i].resize(subresource_sizes[i]);
            util::platform::MemoryCopy(subresource_datas[i].data(),
                                       subresource_sizes[i],
                                       full_resource_data.data() + subresource_offsets[i],
                                       subresource_sizes[i]);
        }
    }
    else
    {
        // Read directly from resource.
        for (auto i : subresource_indices)
        {
            subresource_datas[i].resize(subresource_sizes[i]);
            graphics::Dx12ResourceDataUtil::MapSubresourceAndReadData(
                resource, i, subresource_sizes[i], subresource_datas[i].data());
        }
    }

    // After copying task is done, write the data to disk, and free it to reduce memory use.
    active_delegate_->DumpResource(copy_resource_data);
    copy_resource_data->Clear();

    // Signal command queue to continue execution.
    fence->Signal(fence_signal_value);
}

void Dx12DumpResources::CopyResourceAsync(DxObjectInfo*                        queue_object_info,
                                          const std::vector<format::HandleId>& front_command_list_ids,
                                          CopyResourceDataPtr                  copy_resource_data)
{
    auto fence               = track_dump_resources_.fence;
    auto fence_current_value = track_dump_resources_.fence_signal_value;
    auto fence_event         = track_dump_resources_.fence_event;
    auto queue_extra_info    = GetExtraInfo<D3D12CommandQueueInfo>(queue_object_info);
    auto queue               = static_cast<ID3D12CommandQueue*>(queue_object_info->object);

    bool queued_success = CopyResourceAsyncQueue(
        front_command_list_ids, copy_resource_data, queue, fence, fence_current_value + 1, fence_current_value + 2);

    if (queued_success)
    {
        if (queue_extra_info->pending_events.empty())
        {
            CopyResourceAsyncRead(
                fence, fence_current_value + 1, fence_current_value + 2, fence_event, copy_resource_data);
        }
        else
        {
            // Add CopyResourceAsyncRead to queue's pending_events to be processed later.
            queue_extra_info->pending_events.push_back(CreateCopyResourceAsyncReadQueueSyncEvent(
                fence, fence_current_value + 1, fence_current_value + 2, fence_event, copy_resource_data));
        }
    }

    track_dump_resources_.fence_signal_value += 2;
}

QueueSyncEventInfo Dx12DumpResources::CreateCopyResourceAsyncReadQueueSyncEvent(graphics::dx12::ID3D12FenceComPtr fence,
                                                                                UINT64              fence_wait_value,
                                                                                UINT64              fence_signal_value,
                                                                                HANDLE              fence_event,
                                                                                CopyResourceDataPtr copy_resource_data)
{
    return QueueSyncEventInfo{ false, false, nullptr, 0, [=]() {
                                  CopyResourceAsyncRead(
                                      fence, fence_wait_value, fence_signal_value, fence_event, copy_resource_data);
                              } };
}

std::vector<CommandSet> Dx12DumpResources::GetCommandListsForDumpResources(DxObjectInfo*     command_list_object_info,
                                                                           uint64_t          block_index,
                                                                           format::ApiCallId api_call_id)
{
    std::vector<CommandSet> cmd_sets;
    auto                    cmd_list_extra_info = GetExtraInfo<D3D12CommandListInfo>(command_list_object_info);
    auto                    cmd_list = static_cast<ID3D12GraphicsCommandList*>(command_list_object_info->object);
    auto                    device   = graphics::dx12::GetDeviceComPtrFromChild<ID3D12Device>(cmd_list);

    std::array<CommandSet, 3>* command_sets  = nullptr;
    TrackDumpDrawcall*         drawcall_info = nullptr;
    bool                       is_bundle     = false;
    if ((command_list_object_info->capture_id == track_dump_resources_.target.bundle_commandlist_id) &&
        (track_dump_resources_.target.bundle_target_drawcall != nullptr) &&
        (track_dump_resources_.target.bundle_target_drawcall->begin_block_index <= block_index) &&
        (track_dump_resources_.target.bundle_target_drawcall->close_block_index >= block_index))
    {
        is_bundle     = true;
        command_sets  = &track_dump_resources_.split_bundle_command_sets;
        drawcall_info = track_dump_resources_.target.bundle_target_drawcall.get();
    }
    else if ((command_list_object_info->capture_id == track_dump_resources_.target.command_list_id) &&
             (track_dump_resources_.target.begin_block_index <= block_index) &&
             (track_dump_resources_.target.close_block_index >= block_index))
    {
        command_sets  = &track_dump_resources_.split_command_sets;
        drawcall_info = &track_dump_resources_.target;
    }
    else
    {
        return cmd_sets;
    }

    for (auto& command_set : *command_sets)
    {
        if (command_set.allocator == nullptr)
        {
            device->CreateCommandAllocator(cmd_list_extra_info->create_list_type, IID_PPV_ARGS(&command_set.allocator));
        }
        if (command_set.list == nullptr)
        {
            device->CreateCommandList(0,
                                      cmd_list_extra_info->create_list_type,
                                      command_set.allocator,
                                      nullptr,
                                      IID_PPV_ARGS(&command_set.list));
        }
    }

    Dx12DumpResourcePos split_type = Dx12DumpResourcePos::kBeforeDrawCall;

    if (block_index == drawcall_info->drawcall_block_index)
    {
        split_type = Dx12DumpResourcePos::kDrawCall;
    }
    else if (block_index >= drawcall_info->drawcall_block_index)
    {
        split_type = Dx12DumpResourcePos::kAfterDrawCall;
    }

    auto split_type_array_index = Dx12DumpResourcePosToArrayIndex(split_type);

    // Here is to split command lists.
    switch (api_call_id)
    {
        case format::ApiCall_ID3D12GraphicsCommandList_Reset:
        {
            for (auto& command_set : *command_sets)
            {
                command_set.list->Close();
                command_set.allocator->Reset();
                cmd_sets.emplace_back(command_set);
            }
            break;
        }
        // It has to ensure that the splited command list has a pair of BeginQuery and EndQuery.
        case format::ApiCall_ID3D12GraphicsCommandList_BeginQuery:
        case format::ApiCall_ID3D12GraphicsCommandList_EndQuery:
        case format::ApiCall_ID3D12GraphicsCommandList_Close:
        {
            cmd_sets.insert(cmd_sets.end(), command_sets->begin(), command_sets->end());
            break;
        }
        // binding and Set. These commands are the three command lists need.
        case format::ApiCall_ID3D12GraphicsCommandList_IASetIndexBuffer:
        case format::ApiCall_ID3D12GraphicsCommandList_IASetPrimitiveTopology:
        case format::ApiCall_ID3D12GraphicsCommandList_IASetVertexBuffers:
        case format::ApiCall_ID3D12GraphicsCommandList_OMSetBlendFactor:
        case format::ApiCall_ID3D12GraphicsCommandList1_OMSetDepthBounds:
        case format::ApiCall_ID3D12GraphicsCommandList_OMSetRenderTargets:
        case format::ApiCall_ID3D12GraphicsCommandList_OMSetStencilRef:
        case format::ApiCall_ID3D12GraphicsCommandList_RSSetScissorRects:
        case format::ApiCall_ID3D12GraphicsCommandList5_RSSetShadingRate:
        case format::ApiCall_ID3D12GraphicsCommandList5_RSSetShadingRateImage:
        case format::ApiCall_ID3D12GraphicsCommandList_RSSetViewports:
        case format::ApiCall_ID3D12GraphicsCommandList_SetComputeRoot32BitConstant:
        case format::ApiCall_ID3D12GraphicsCommandList_SetComputeRoot32BitConstants:
        case format::ApiCall_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView:
        case format::ApiCall_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable:
        case format::ApiCall_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView:
        case format::ApiCall_ID3D12GraphicsCommandList_SetComputeRootSignature:
        case format::ApiCall_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView:
        case format::ApiCall_ID3D12GraphicsCommandList_SetDescriptorHeaps:
        case format::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstant:
        case format::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstants:
        case format::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView:
        case format::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable:
        case format::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView:
        case format::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootSignature:
        case format::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView:
        case format::ApiCall_ID3D12GraphicsCommandList_SetPipelineState:
        case format::ApiCall_ID3D12GraphicsCommandList4_SetPipelineState1:
        case format::ApiCall_ID3D12GraphicsCommandList_SetPredication:
        case format::ApiCall_ID3D12GraphicsCommandList3_SetProtectedResourceSession:
        case format::ApiCall_ID3D12GraphicsCommandList1_SetSamplePositions:
        case format::ApiCall_ID3D12GraphicsCommandList1_SetViewInstanceMask:
        case format::ApiCall_ID3D12GraphicsCommandList_SOSetTargets:
        case format::ApiCall_ID3D12GraphicsCommandList2_WriteBufferImmediate:
        {
            switch (split_type)
            {
                case Dx12DumpResourcePos::kBeforeDrawCall:
                    cmd_sets.insert(cmd_sets.end(), command_sets->begin(), command_sets->end());
                    break;
                // But if the command is after DrawCall, it's just added at the third CommandList.
                case Dx12DumpResourcePos::kAfterDrawCall:
                    cmd_sets.emplace_back((*command_sets)[kAfterDrawCallArrayIndex]);
                    break;
                default:
                    break;
            }
            break;
        }
        case format::ApiCall_ID3D12GraphicsCommandList4_BeginRenderPass:
        {
            if (block_index == drawcall_info->begin_renderpass_block_index)
            {
                cmd_sets.insert(cmd_sets.end(), command_sets->begin(), command_sets->end());
            }
            else
            {
                cmd_sets.emplace_back((*command_sets)[split_type_array_index]);
            }
            break;
        }
        case format::ApiCall_ID3D12GraphicsCommandList4_EndRenderPass:
        {
            if (block_index == drawcall_info->end_renderpass_block_index)
            {
                cmd_sets.insert(cmd_sets.end(), command_sets->begin(), command_sets->end());
            }
            else
            {
                cmd_sets.emplace_back((*command_sets)[split_type_array_index]);
            }
            break;
        }
        case format::ApiCall_ID3D12GraphicsCommandList_ExecuteBundle:
        {
            if (block_index == drawcall_info->drawcall_block_index)
            {
                cmd_sets.insert(cmd_sets.end(), command_sets->begin(), command_sets->end());
            }
            else
            {
                cmd_sets.emplace_back((*command_sets)[split_type_array_index]);
            }
            break;
        }
        default:
        {
            // command type could be changed data, drawcalls.
            cmd_sets.emplace_back((*command_sets)[split_type_array_index]);
            break;
        }
    }
    return cmd_sets;
}

void DefaultDx12DumpResourcesDelegate::BeginDumpResources(const std::string&        capture_file_name,
                                                          const TrackDumpResources& track_dump_resources)
{
    // prepare for output data
    json_options_.format = kDefaultDumpResourcesFileFormat;

    json_filename_    = capture_file_name;
    auto ext_pos      = json_filename_.find_last_of(".");
    auto path_sep_pos = json_filename_.find_last_of(util::filepath::kPathSepStr);
    if (ext_pos != std::string::npos && (path_sep_pos == std::string::npos || ext_pos > path_sep_pos))
    {
        json_filename_ = json_filename_.substr(0, ext_pos);
    }
    json_filename_ += "_dr." + util::get_json_format(json_options_.format);
    json_options_.data_sub_dir = util::filepath::GetFilenameStem(json_filename_);
    json_options_.root_dir     = util::filepath::GetBasedir(json_filename_);

    util::platform::FileOpen(&json_file_handle_, json_filename_.c_str(), "w");

    header_["D3D12SDKVersion"] = std::to_string(D3D12SDKVersion);
    header_["gfxreconversion"] = GFXRECON_PROJECT_VERSION_STRING;
    header_["captureFile"]     = capture_file_name;

    auto& dr_options       = header_["dumpResourcesOptions"];
    dr_options["submit"]   = std::to_string(track_dump_resources.target.dump_resources_target.submit_index);
    dr_options["command"]  = std::to_string(track_dump_resources.target.dump_resources_target.command_index);
    dr_options["drawcall"] = std::to_string(track_dump_resources.target.dump_resources_target.drawcall_index);

    StartFile();

    // Emit the header object as the first line of the file:
    WriteBlockStart();
    json_data_["header"] = header_;
    WriteBlockEnd();

    WriteBlockStart();

    util::FieldToJson(drawcall_["block_index"], track_dump_resources.target.drawcall_block_index, json_options_);
    util::FieldToJson(drawcall_["execute_block_index"], track_dump_resources.target.execute_block_index, json_options_);
}

void DefaultDx12DumpResourcesDelegate::DumpResource(CopyResourceDataPtr resource_data)
{
    WriteResource(resource_data);
}

void DefaultDx12DumpResourcesDelegate::EndDumpResources()
{
    json_data_[NameDrawCall()] = drawcall_;
    WriteBlockEnd();
    EndFile();
}

void DefaultDx12DumpResourcesDelegate::WriteResource(const CopyResourceDataPtr resource_data)
{
    if (resource_data->source_resource_id == format::kNullHandleId)
    {
        return;
    }

    auto* jdata_sub = &drawcall_;
    for (const auto& path : resource_data->json_path)
    {
        if (path.second == format::kNoneIndex)
        {
            jdata_sub = &(*jdata_sub)[path.first];
        }
        else
        {
            jdata_sub = &(*jdata_sub)[path.first][path.second];
        }
    }
    std::string prefix_file_name =
        json_options_.data_sub_dir + "_" + Dx12ResourceTypeToString(resource_data->resource_type);
    WriteResource(*jdata_sub, prefix_file_name, resource_data);

    if (TEST_READABLE)
    {
        TestWriteReadableResource(prefix_file_name, resource_data);
    }
}

void DefaultDx12DumpResourcesDelegate::WriteResource(nlohmann::ordered_json&   jdata,
                                                     const std::string&        prefix_file_name,
                                                     const CopyResourceDataPtr resource_data)
{
    if (resource_data->source_resource_id == format::kNullHandleId)
    {
        return;
    }

    std::string file_name = prefix_file_name + "_res_id_" + std::to_string(resource_data->source_resource_id);

    util::FieldToJson(jdata["res_id"], resource_data->source_resource_id, json_options_);

    std::string suffix    = Dx12DumpResourcePosToString(resource_data->dump_position);
    std::string json_path = suffix + "_file";
    for (const auto sub_index : resource_data->subresource_indices)
    {
        auto offset = resource_data->subresource_offsets[sub_index];
        auto size   = resource_data->subresource_sizes[sub_index];

        auto& jdata_sub = jdata["sub"][sub_index];
        util::FieldToJson(jdata_sub["index"], sub_index, json_options_);
        util::FieldToJson(jdata_sub["offset"], offset, json_options_);
        util::FieldToJson(jdata_sub["size"], size, json_options_);

        // Write data.
        GFXRECON_ASSERT(!resource_data->datas[sub_index].empty());

        std::string file_name_sub = file_name + "_sub_" + std::to_string(sub_index) + "_" + suffix + ".bin";
        util::FieldToJson(jdata_sub[json_path], file_name_sub.c_str(), json_options_);

        std::string file_path = gfxrecon::util::filepath::Join(json_options_.root_dir, file_name_sub);
        WriteBinaryFile(file_path, resource_data->datas[sub_index], offset, size);
    }
}

void DefaultDx12DumpResourcesDelegate::TestWriteReadableResource(const std::string&        prefix_file_name,
                                                                 const CopyResourceDataPtr resource_data)
{
    if (resource_data->source_resource_id == format::kNullHandleId)
    {
        return;
    }

    if (resource_data->desc.Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
    {
        TestWriteFloatResource(prefix_file_name, resource_data);
    }
    else
    {
        TestWriteImageResource(prefix_file_name, resource_data);
    }
}

void DefaultDx12DumpResourcesDelegate::TestWriteFloatResource(const std::string&        prefix_file_name,
                                                              const CopyResourceDataPtr resource_data)
{
    std::string file_name = prefix_file_name + "_res_id_" + std::to_string(resource_data->source_resource_id);

    for (const auto sub_index : resource_data->subresource_indices)
    {
        auto offset    = resource_data->subresource_offsets[sub_index];
        auto data_size = resource_data->subresource_sizes[sub_index];

        // Write data.
        GFXRECON_ASSERT(!resource_data->datas[sub_index].empty());

        auto        data_begin_sub = reinterpret_cast<const float*>(resource_data->datas[sub_index].data() + offset);
        uint32_t    size           = data_size / (sizeof(float));
        std::string data           = "";
        for (uint32_t i = 0; i < size; ++i)
        {
            data += std::to_string(data_begin_sub[i]);
            data += "\n";
        }

        const char* suffix        = Dx12DumpResourcePosToString(resource_data->dump_position);
        std::string file_name_sub = file_name + "_sub_" + std::to_string(sub_index) + "_" + suffix + ".txt";
        std::string file_path     = gfxrecon::util::filepath::Join(json_options_.root_dir, file_name_sub);
        FILE*       file_handle;
        util::platform::FileOpen(&file_handle, file_path.c_str(), "w");
        util::platform::FilePuts(data.c_str(), file_handle);
        util::platform::FileClose(file_handle);
    }
}

void DefaultDx12DumpResourcesDelegate::TestWriteImageResource(const std::string&        prefix_file_name,
                                                              const CopyResourceDataPtr resource_data)
{
    std::string file_name = prefix_file_name + "_res_id_" + std::to_string(resource_data->source_resource_id);

    for (const auto sub_index : resource_data->subresource_indices)
    {
        auto offset = resource_data->subresource_offsets[sub_index];
        auto size   = resource_data->subresource_sizes[sub_index];

        std::string file_name_sub = file_name + "_sub_" + std::to_string(sub_index);

        // WriteBmpImage expects 4 bytes per pixel.
        uint64_t row_pitch_aligned_size = ((size + (resource_data->footprints[sub_index].Footprint.RowPitch - 1)) /
                                           resource_data->footprints[sub_index].Footprint.RowPitch) *
                                          resource_data->footprints[sub_index].Footprint.RowPitch;
        double bytes_per_pixel = static_cast<double>(row_pitch_aligned_size) /
                                 (static_cast<double>(resource_data->footprints[sub_index].Footprint.RowPitch / 4) *
                                  resource_data->footprints[sub_index].Footprint.Height);
        if (bytes_per_pixel != 4.0)
        {
            GFXRECON_LOG_WARNING("Dump images could not be created for before and after resource of "
                                 "'%s_before\\after.bmp'. Only formats "
                                 "with 4 bytes per pixel are supported. Current format %" PRIu32
                                 " is %.2f bytes per pixel.",
                                 file_name_sub.c_str(),
                                 resource_data->footprints[sub_index].Footprint.Format,
                                 bytes_per_pixel);
            continue;
        }

        // Write data.
        GFXRECON_ASSERT(!resource_data->datas[sub_index].empty());

        std::string suffix = Dx12DumpResourcePosToString(resource_data->dump_position);
        file_name_sub += "_" + suffix + ".bmp ";
        std::string file_path = gfxrecon::util::filepath::Join(json_options_.root_dir, file_name_sub);
        if (!util::imagewriter::WriteBmpImage(file_path,
                                              resource_data->footprints[sub_index].Footprint.Width,
                                              resource_data->footprints[sub_index].Footprint.Height,
                                              size,
                                              resource_data->datas[sub_index].data() + offset,
                                              resource_data->footprints[sub_index].Footprint.RowPitch))
        {
            GFXRECON_LOG_ERROR("Dump image could not be created: failed to write BMP file %s", file_name_sub.c_str());
        }
    }
}

void DefaultDx12DumpResourcesDelegate::StartFile()
{
    num_objects_ = 0;
    if (json_options_.format == util::JsonFormat::JSON)
    {
        util::platform::FilePuts("[\n", json_file_handle_);
    }
}

void DefaultDx12DumpResourcesDelegate::EndFile()
{
    if (json_file_handle_ != nullptr)
    {
        if (json_options_.format == util::JsonFormat::JSON)
        {
            util::platform::FilePuts("\n]\n", json_file_handle_);
        }
        else
        {
            util::platform::FilePuts("\n", json_file_handle_);
        }
        util::platform::FileClose(json_file_handle_);
        json_file_handle_ = nullptr;
    }
}

void DefaultDx12DumpResourcesDelegate::WriteBlockStart()
{
    json_data_.clear(); // < Dominates profiling (1/2).
    num_objects_++;
}

void DefaultDx12DumpResourcesDelegate::WriteBlockEnd()
{
    if (num_objects_ > 1)
    {
        util::platform::FilePuts(json_options_.format == util::JsonFormat::JSONL ? "\n" : ",\n", json_file_handle_);
    }
    // Dominates profiling (2/2):
    const std::string block =
        json_data_.dump(json_options_.format == util::JsonFormat::JSONL ? -1 : util::kJsonIndentWidth);
    util::platform::FileWriteNoLock(block.data(), block.length() * sizeof(std::string::value_type), json_file_handle_);
    util::platform::FileFlush(json_file_handle_); /// @todo Implement a FileFlushNoLock() for all platforms.
}

bool DefaultDx12DumpResourcesDelegate::WriteBinaryFile(const std::string&          filename,
                                                       const std::vector<uint8_t>& data,
                                                       uint64_t                    offset,
                                                       uint64_t                    size)
{
    FILE* file_output = nullptr;
    if (util::platform::FileOpen(&file_output, filename.c_str(), "wb") == 0)
    {
        bool success = util::platform::FileWrite(data.data() + offset, size, file_output);
        util::platform::FileClose(file_output);
        return success;
    }
    return false;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
