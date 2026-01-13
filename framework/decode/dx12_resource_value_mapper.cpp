/*
** Copyright (c) 2022-2024 LunarG, Inc.
** Copyright (c) 2022-2025 Advanced Micro Devices, Inc. All rights reserved.
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

#include "decode/dx12_resource_value_mapper.h"

#include "decode/custom_dx12_struct_decoders.h"
#include "decode/dx12_experimental_resource_value_tracker.h"
#include "decode/dx12_object_mapping_util.h"

#if defined(GFXRECON_DXC_SUPPORT)
#include <d3d12shader.h>
#include <dxcapi.h>
#endif

#include <codecvt>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

namespace /* anonymous */
{

template <typename T>
T* GetExtraInfo(HandlePointerDecoder<void*>* handle_ptr_decoder)
{
    GFXRECON_ASSERT(handle_ptr_decoder != nullptr);

    auto object_info = static_cast<DxObjectInfo*>(handle_ptr_decoder->GetConsumerData(0));

    if ((object_info != nullptr) && (object_info->extra_info != nullptr) &&
        (object_info->extra_info->extra_info_type == T::kType))
    {
        return static_cast<T*>(object_info->extra_info.get());
    }

    GFXRECON_LOG_FATAL("%s object does not have an associated info structure", T::kObjectType);

    return nullptr;
}

D3D12ResourceInfo* GetResourceExtraInfo(DxObjectInfo* resource_object_info)
{
    GFXRECON_ASSERT(resource_object_info != nullptr);
    if (resource_object_info->extra_info == nullptr)
    {
        resource_object_info->extra_info = std::make_unique<D3D12ResourceInfo>();
    }
    return GetExtraInfo<D3D12ResourceInfo>(resource_object_info);
}

template <typename T>
void GetRootSignatureResourceValueInfos(const T* root_signature_desc, std::set<ResourceValueInfo>& value_infos)
{
    value_infos.clear();
    UINT byte_offset = 0;
    for (UINT i = 0; i < root_signature_desc->NumParameters; ++i)
    {
        auto& param_desc = root_signature_desc->pParameters[i];
        switch (param_desc.ParameterType)
        {
            case D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS:
                byte_offset = util::platform::AlignValue<sizeof(UINT32)>(byte_offset) +
                              param_desc.Constants.Num32BitValues * sizeof(UINT32);
                break;
            case D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE:
            {
                auto aligned_offset = util::platform::AlignValue<sizeof(D3D12_GPU_DESCRIPTOR_HANDLE::ptr)>(byte_offset);
                value_infos.insert({ aligned_offset,
                                     ResourceValueType::kGpuDescriptorHandle,
                                     sizeof(D3D12_GPU_DESCRIPTOR_HANDLE::ptr),
                                     nullptr,
                                     { nullptr, nullptr, 0 },
                                     0 });
                byte_offset = aligned_offset + sizeof(D3D12_GPU_DESCRIPTOR_HANDLE::ptr);
            }
            break;
            case D3D12_ROOT_PARAMETER_TYPE_CBV:
            case D3D12_ROOT_PARAMETER_TYPE_SRV:
            case D3D12_ROOT_PARAMETER_TYPE_UAV:
            {
                auto aligned_offset = util::platform::AlignValue<sizeof(D3D12_GPU_VIRTUAL_ADDRESS)>(byte_offset);
                value_infos.insert({ aligned_offset,
                                     ResourceValueType::kGpuVirtualAddress,
                                     sizeof(D3D12_GPU_VIRTUAL_ADDRESS),
                                     nullptr,
                                     { nullptr, nullptr, 0 },
                                     0 });
                byte_offset = aligned_offset + sizeof(D3D12_GPU_VIRTUAL_ADDRESS);
            }
            break;
            default:
                GFXRECON_LOG_ERROR("Ignoring unrecognized root signature parameter type (%d)",
                                   param_desc.ParameterType);
                break;
        }
    }
}

// This is a helper for CopyResourceValues. It copies ResourceValueInfos (with updated offset) from dst to src.
void CopyResourceValuesFromDstToSrc(std::set<ResourceValueInfo>&          src,
                                    const std::set<ResourceValueInfo>&    dst,
                                    std::set<ResourceValueInfo>::iterator dst_begin,
                                    std::set<ResourceValueInfo>::iterator dst_end,
                                    const ResourceCopyInfo&               copy_info)
{
    for (auto dst_iter = dst_begin; dst_iter != dst_end; ++dst_iter)
    {
        auto src_offset = ((*dst_iter).offset - copy_info.dst_offset) + copy_info.src_offset;
        src.insert({ static_cast<uint64_t>(src_offset),
                     (*dst_iter).type,
                     static_cast<uint64_t>((*dst_iter).size),
                     (*dst_iter).state_object,
                     (*dst_iter).arg_buffer_extra_info,
                     (*dst_iter).max_command_count });
    }
}

// This is a helper for CopyMappedResourceValues. It copies mapped gpu address entries (with updated offset) from src to
// dst.
template <typename T>
void CopyMappedResourceValuesFromSrcToDst(std::map<uint64_t, T>&                   dst,
                                          const std::map<uint64_t, T>&             src,
                                          typename std::map<uint64_t, T>::iterator src_begin,
                                          typename std::map<uint64_t, T>::iterator src_end,
                                          const ResourceCopyInfo&                  copy_info)
{
    for (auto src_iter = src_begin; src_iter != src_end; ++src_iter)
    {
        auto dst_offset = (src_iter->first - copy_info.src_offset) + copy_info.dst_offset;
        dst[dst_offset] = src_iter->second;
    }
}

std::string DemangleDxilExportName(const std::string& mangled_name)
{
    size_t demangled_name_start = mangled_name.find_first_of("?");
    size_t demangled_name_end   = mangled_name.find_first_of("@");

    std::string demangled_name = "";
    if (demangled_name_start != std::string::npos && demangled_name_end != std::string::npos)
    {
        // The char after '?' is the first char of the unmangled name so increment start pos.
        ++demangled_name_start;
        demangled_name = mangled_name.substr(demangled_name_start, demangled_name_end - demangled_name_start);
    }

    if (!demangled_name.empty())
    {
        GFXRECON_LOG_DEBUG("Found demangled DXIL export name '%s'.", demangled_name.c_str());
    }
    else
    {
        GFXRECON_LOG_WARNING("Failed to demangle DXIL export name '%s'.", mangled_name.c_str());
    }
    return demangled_name;
}

} // namespace

Dx12ResourceValueMapper::Dx12ResourceValueMapper(std::function<DxObjectInfo*(format::HandleId id)> get_object_info_func,
                                                 const graphics::Dx12ShaderIdMap&                  shader_id_map,
                                                 const graphics::Dx12GpuVaMap&                     gpu_va_map,
                                                 const decode::Dx12DescriptorMap&                  descriptor_map) :
    get_object_info_func_(get_object_info_func),
    shader_id_map_(shader_id_map), gpu_va_map_(gpu_va_map), descriptor_map_(descriptor_map), do_value_mapping_(true)
{}

void Dx12ResourceValueMapper::EnableResourceValueTracker(std::function<uint64_t(void)> get_current_block_index_func,
                                                         bool                          experimental_tracker)
{
    if (experimental_tracker)
    {
        resource_value_tracker_ =
            std::make_unique<Dx12ExperimentalResourceValueTracker>(get_object_info_func_, get_current_block_index_func);
    }
    else
    {
        resource_value_tracker_ =
            std::make_unique<Dx12ResourceValueTracker>(get_object_info_func_, get_current_block_index_func);
    }
}

void Dx12ResourceValueMapper::GetTrackedResourceValues(Dx12FillCommandResourceValueMap& values)
{
    if (resource_value_tracker_ != nullptr)
    {
        resource_value_tracker_->GetTrackedResourceValues(values);
    }
}

void Dx12ResourceValueMapper::GetUnassociatedResourceValues(Dx12UnassociatedResourceValueMap& unassociated_values)
{
    if (resource_value_tracker_ != nullptr)
    {
        resource_value_tracker_->GetUnassociatedResourceValues(unassociated_values);
    }
}

void Dx12ResourceValueMapper::SetUnassociatedResourceValues(Dx12FillCommandResourceValueMap&&  tracked_values,
                                                            Dx12UnassociatedResourceValueMap&& unassociated_values)
{
    GFXRECON_ASSERT(resource_value_tracker_ != nullptr);

    // Don't do value mapping on the second pass of optimization processing. tracked_values should contain the resource
    // values found and mapped by the first pass.
    do_value_mapping_ = false;
    resource_value_tracker_->SetUnassociatedResourceValues(std::move(tracked_values), std::move(unassociated_values));
}

void Dx12ResourceValueMapper::PostProcessCommandListReset(DxObjectInfo* command_list_object_info)
{
    // Clear tracked info.
    auto command_list_extra_info = GetExtraInfo<D3D12CommandListInfo>(command_list_object_info);
    command_list_extra_info->resource_copies.clear();
    command_list_extra_info->resource_value_info_map.clear();
    command_list_extra_info->active_state_object = nullptr;

    if (resource_value_tracker_ != nullptr)
    {
        resource_value_tracker_->PostProcessCommandListReset(command_list_object_info);
    }
}

void Dx12ResourceValueMapper::PostProcessCopyResource(DxObjectInfo* command_list_object_info,
                                                      DxObjectInfo* dst_resource_object_info,
                                                      DxObjectInfo* src_resource_object_info)
{
    // Track copies in order to correctly map resource values.
    auto command_list_extra_info = GetExtraInfo<D3D12CommandListInfo>(command_list_object_info);
    command_list_extra_info->resource_copies.push_back({ dst_resource_object_info, 0, src_resource_object_info, 0, 0 });
}

void Dx12ResourceValueMapper::PostProcessCopyBufferRegion(DxObjectInfo* command_list_object_info,
                                                          DxObjectInfo* dst_buffer_object_info,
                                                          UINT64        dst_offset,
                                                          DxObjectInfo* src_buffer_object_info,
                                                          UINT64        src_offset,
                                                          UINT64        num_bytes)
{
    // Track copies in order to correctly map resource values.
    auto command_list_extra_info = GetExtraInfo<D3D12CommandListInfo>(command_list_object_info);
    command_list_extra_info->resource_copies.push_back(
        { dst_buffer_object_info, dst_offset, src_buffer_object_info, src_offset, num_bytes });
}

void Dx12ResourceValueMapper::PreProcessExecuteCommandLists(
    DxObjectInfo*                             command_queue_object_info,
    UINT                                      num_command_lists,
    HandlePointerDecoder<ID3D12CommandList*>* command_lists_decoder,
    bool&                                     needs_mapping)
{
    needs_mapping = false;
    if (do_value_mapping_)
    {
        auto command_queue            = static_cast<ID3D12CommandQueue*>(command_queue_object_info->object);
        auto command_queue_extra_info = GetExtraInfo<D3D12CommandQueueInfo>(command_queue_object_info);

        GFXRECON_ASSERT(command_queue_extra_info != nullptr);

        if (command_queue_extra_info->resource_value_map_fence == nullptr)
        {
            InitializeRequiredObjects(command_queue, command_queue_extra_info);
        }

        // Determine if there are values that need to be mapped in resources referenced by the command list.
        for (UINT i = 0; (i < num_command_lists) && !needs_mapping; ++i)
        {
            auto command_list_extra_info =
                GetExtraInfo<D3D12CommandListInfo>(get_object_info_func_(command_lists_decoder->GetPointer()[i]));
            GFXRECON_ASSERT(command_list_extra_info != nullptr);

            for (auto& resource_value_info_pair : command_list_extra_info->resource_value_info_map)
            {
                if (!resource_value_info_pair.second.empty())
                {
                    needs_mapping = true;
                    break;
                }
            }
        }

        if (needs_mapping)
        {
            // Signal the resource_value_map_fence to indicate it is safe to begin mapping, then wait for the
            // resource_value_map_fence to ensure mapping has completed. No other objects should be signaling or waiting
            // on this fence, so no events need to be added to the command queue's pending events list.
            command_queue->Signal(command_queue_extra_info->resource_value_map_fence,
                                  command_queue_extra_info->resource_value_map_fence_value);
            command_queue->Wait(command_queue_extra_info->resource_value_map_fence,
                                command_queue_extra_info->resource_value_map_fence_value + 1);
        }
    }
}

void Dx12ResourceValueMapper::PostProcessExecuteCommandLists(
    DxObjectInfo*                             command_queue_object_info,
    UINT                                      num_command_lists,
    HandlePointerDecoder<ID3D12CommandList*>* command_lists_decoder,
    bool                                      needs_mapping)
{
    if (resource_value_tracker_ != nullptr)
    {
        resource_value_tracker_->PostProcessExecuteCommandLists(
            command_queue_object_info, num_command_lists, command_lists_decoder);
    }

    if (needs_mapping)
    {
        auto command_queue            = static_cast<ID3D12CommandQueue*>(command_queue_object_info->object);
        auto command_queue_extra_info = GetExtraInfo<D3D12CommandQueueInfo>(command_queue_object_info);

        GFXRECON_ASSERT(command_queue_extra_info != nullptr);

        auto& pending_events = command_queue_extra_info->pending_events;

        // Signal the fence again to indicate the command list has completed and the resources with mapped values can be
        // restored to the unmapped values.
        command_queue->Signal(command_queue_extra_info->resource_value_map_fence,
                              command_queue_extra_info->resource_value_map_fence_value + 2);
        command_queue->Wait(command_queue_extra_info->resource_value_map_fence,
                            command_queue_extra_info->resource_value_map_fence_value + 3);

        ProcessResourceMappingsArgs process_args{ command_queue_extra_info->resource_value_map_fence,
                                                  command_queue_extra_info->resource_value_map_fence_value,
                                                  command_queue_extra_info->resource_value_map_event };

        for (UINT i = 0; i < num_command_lists; ++i)
        {
            auto command_list_extra_info =
                GetExtraInfo<D3D12CommandListInfo>(get_object_info_func_(command_lists_decoder->GetPointer()[i]));
            GFXRECON_ASSERT(command_list_extra_info != nullptr);

            process_args.resource_copies.insert(process_args.resource_copies.end(),
                                                command_list_extra_info->resource_copies.begin(),
                                                command_list_extra_info->resource_copies.end());

            for (const auto& resource_value_info_pair : command_list_extra_info->resource_value_info_map)
            {
                if (!resource_value_info_pair.second.empty())
                {
                    process_args.resource_value_info_map[resource_value_info_pair.first].insert(
                        resource_value_info_pair.second.begin(), resource_value_info_pair.second.end());
                }
            }
        }

        // Run (or queue) resource value mapping process.
        if (pending_events.empty())
        {
            ProcessResourceMappings(std::move(process_args));
        }
        else
        {
            command_queue_extra_info->pending_events.push_back(
                CreateProcessProcessResourceMappingsSyncEvent(std::move(process_args)));
        }

        command_queue_extra_info->resource_value_map_fence_value += 4;
    }
}

void Dx12ResourceValueMapper::PostProcessCreateCommandSignature(HandlePointerDecoder<void*>* command_signature_decoder,
                                                                const D3D12_COMMAND_SIGNATURE_DESC* desc)
{
    auto command_signature_object_info = static_cast<DxObjectInfo*>(command_signature_decoder->GetConsumerData(0));
    auto command_signature_extra_info  = GetExtraInfo<D3D12CommandSignatureInfo>(command_signature_object_info);

    GFXRECON_ASSERT(command_signature_extra_info != nullptr);

    // Determine offsets in the command signature that will contain GPU VAs
    command_signature_extra_info->byte_stride = desc->ByteStride;
    auto& resource_value_infos                = command_signature_extra_info->resource_value_infos;
    resource_value_infos.clear();
    UINT byte_offset = 0;
    for (UINT i = 0; i < desc->NumArgumentDescs; ++i)
    {
        const auto& arg_desc = desc->pArgumentDescs[i];
        switch (arg_desc.Type)
        {
            case D3D12_INDIRECT_ARGUMENT_TYPE_DRAW:
                byte_offset += sizeof(D3D12_DRAW_ARGUMENTS);
                break;
            case D3D12_INDIRECT_ARGUMENT_TYPE_DRAW_INDEXED:
                byte_offset += sizeof(D3D12_DRAW_INDEXED_ARGUMENTS);
                break;
            case D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH:
                byte_offset += sizeof(D3D12_DISPATCH_ARGUMENTS);
                break;
            case D3D12_INDIRECT_ARGUMENT_TYPE_VERTEX_BUFFER_VIEW:
                resource_value_infos.insert({ byte_offset + offsetof(D3D12_VERTEX_BUFFER_VIEW, BufferLocation),
                                              ResourceValueType::kGpuVirtualAddress,
                                              sizeof(D3D12_VERTEX_BUFFER_VIEW::BufferLocation),
                                              nullptr,
                                              { nullptr, nullptr, 0 },
                                              0 });
                byte_offset += sizeof(D3D12_VERTEX_BUFFER_VIEW);
                break;
            case D3D12_INDIRECT_ARGUMENT_TYPE_INDEX_BUFFER_VIEW:
                resource_value_infos.insert({ byte_offset + offsetof(D3D12_INDEX_BUFFER_VIEW, BufferLocation),
                                              ResourceValueType::kGpuVirtualAddress,
                                              sizeof(D3D12_INDEX_BUFFER_VIEW::BufferLocation),
                                              nullptr,
                                              { nullptr, nullptr, 0 },
                                              0 });
                byte_offset += sizeof(D3D12_INDEX_BUFFER_VIEW);
                break;
            case D3D12_INDIRECT_ARGUMENT_TYPE_CONSTANT:
                byte_offset += arg_desc.Constant.Num32BitValuesToSet * 4;
                break;
            case D3D12_INDIRECT_ARGUMENT_TYPE_CONSTANT_BUFFER_VIEW:
            case D3D12_INDIRECT_ARGUMENT_TYPE_SHADER_RESOURCE_VIEW:
            case D3D12_INDIRECT_ARGUMENT_TYPE_UNORDERED_ACCESS_VIEW:
                resource_value_infos.insert({ static_cast<uint64_t>(byte_offset),
                                              ResourceValueType::kGpuVirtualAddress,
                                              sizeof(D3D12_GPU_VIRTUAL_ADDRESS),
                                              nullptr,
                                              { nullptr, nullptr, 0 },
                                              0 });
                byte_offset += sizeof(D3D12_GPU_VIRTUAL_ADDRESS);
                break;
            case D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH_RAYS:
                resource_value_infos.insert({ static_cast<uint64_t>(byte_offset),
                                              ResourceValueType::kIndirectArgumentDispatchRays,
                                              sizeof(D3D12_DISPATCH_RAYS_DESC),
                                              nullptr,
                                              { nullptr, nullptr, 0 },
                                              0 });
                byte_offset += sizeof(D3D12_DISPATCH_RAYS_DESC);
                break;
            case D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH_MESH:
                byte_offset += sizeof(D3D12_DISPATCH_MESH_ARGUMENTS);
                break;
            default:
                GFXRECON_LOG_ERROR("Ignoring unknown command signature argument type %d.", arg_desc.Type);
                break;
        }
    }
}

void Dx12ResourceValueMapper::PostProcessExecuteIndirect(DxObjectInfo* command_list_object_info,
                                                         DxObjectInfo* command_signature_object_info,
                                                         UINT          max_command_count,
                                                         DxObjectInfo* argument_buffer_object_info,
                                                         UINT64        argument_buffer_offset,
                                                         DxObjectInfo* count_buffer_object_info,
                                                         UINT64        count_buffer_offset)
{
    auto command_list_extra_info = GetExtraInfo<D3D12CommandListInfo>(command_list_object_info);
    GFXRECON_ASSERT(command_list_extra_info != nullptr);

    auto command_signature_extra_info = GetExtraInfo<D3D12CommandSignatureInfo>(command_signature_object_info);
    GFXRECON_ASSERT(command_signature_extra_info != nullptr);

    D3D12StateObjectInfo* state_object_extra_info = nullptr;
    if (command_list_extra_info->active_state_object != nullptr)
    {
        state_object_extra_info = GetExtraInfo<D3D12StateObjectInfo>(command_list_extra_info->active_state_object);
    }

    if (max_command_count > 0)
    {
        if ((count_buffer_object_info != nullptr) && (count_buffer_object_info->object != nullptr))
        {
            auto& resource_value_infos = command_list_extra_info->resource_value_info_map[count_buffer_object_info];
            resource_value_infos.insert(
                { count_buffer_offset,
                  ResourceValueType::kExecuteIndirectCountBuffer,
                  sizeof(uint32_t),
                  state_object_extra_info,
                  { command_signature_extra_info, argument_buffer_object_info, argument_buffer_offset },
                  max_command_count });
        }
        else
        {
            // Add resource value offsets to resource_value_infos based on the command signature's arguments.
            GetExecuteIndirectResourceValues(
                command_list_extra_info->resource_value_info_map[argument_buffer_object_info],
                command_signature_extra_info->resource_value_infos,
                max_command_count,
                argument_buffer_offset,
                command_signature_extra_info->byte_stride,
                state_object_extra_info);
        }
        SourceCopyResources(command_list_extra_info->resource_copies, command_list_extra_info->resource_value_info_map);
    }
}

void Dx12ResourceValueMapper::PostProcessBuildRaytracingAccelerationStructure(
    DxObjectInfo*                                                                     command_list4_object_info,
    StructPointerDecoder<Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC>* desc)
{
    auto* build_desc = desc->GetPointer();
    if ((build_desc->Inputs.Type == D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL) &&
        (build_desc->Inputs.NumDescs > 0))
    {
        GFXRECON_ASSERT(build_desc->Inputs.InstanceDescs != 0);

        format::HandleId resource_id = format::kNullHandleId;
        bool             found       = false;

        auto min_end_gpu_va = build_desc->Inputs.InstanceDescs;
        if (build_desc->Inputs.DescsLayout == D3D12_ELEMENTS_LAYOUT_ARRAY)
        {
            min_end_gpu_va += build_desc->Inputs.NumDescs * sizeof(D3D12_RAYTRACING_INSTANCE_DESC);
        }
        else
        {
            min_end_gpu_va += build_desc->Inputs.NumDescs * sizeof(D3D12_GPU_VIRTUAL_ADDRESS);
        }

        reverse_gpu_va_map_.Map(build_desc->Inputs.InstanceDescs, &resource_id, &found, min_end_gpu_va);

        if (resource_id != format::kNullHandleId)
        {
            auto resource_object_info = get_object_info_func_(resource_id);
            GFXRECON_ASSERT(resource_object_info != nullptr);
            GFXRECON_ASSERT(resource_object_info->object != nullptr);

            auto  resource                = static_cast<ID3D12Resource*>(resource_object_info->object);
            auto  command_list_extra_info = GetExtraInfo<D3D12CommandListInfo>(command_list4_object_info);
            auto& resource_value_infos    = command_list_extra_info->resource_value_info_map[resource_object_info];

            GFXRECON_ASSERT(build_desc->Inputs.InstanceDescs >= resource->GetGPUVirtualAddress());
            auto offset_to_instance_descs_start = build_desc->Inputs.InstanceDescs - resource->GetGPUVirtualAddress();

            // Add the D3D12_RAYTRACING_INSTANCE_DESC::AccelerationStructure(s) referenced by
            // D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC::Inputs to the command list's resource GPU VAs.
            if (build_desc->Inputs.DescsLayout == D3D12_ELEMENTS_LAYOUT_ARRAY)
            {
                constexpr auto accel_struct_gpu_va_stride = sizeof(D3D12_RAYTRACING_INSTANCE_DESC);
                GFXRECON_ASSERT((accel_struct_gpu_va_stride % D3D12_RAYTRACING_INSTANCE_DESCS_BYTE_ALIGNMENT) == 0);
                constexpr auto accel_struct_gpu_va_offset =
                    offsetof(D3D12_RAYTRACING_INSTANCE_DESC, AccelerationStructure);
                for (UINT i = 0; i < build_desc->Inputs.NumDescs; ++i)
                {
                    resource_value_infos.insert(
                        { offset_to_instance_descs_start + accel_struct_gpu_va_stride * i + accel_struct_gpu_va_offset,
                          ResourceValueType::kGpuVirtualAddress,
                          sizeof(D3D12_GPU_VIRTUAL_ADDRESS),
                          nullptr,
                          { nullptr, nullptr, 0 },
                          0 });
                }
            }
            else if (build_desc->Inputs.DescsLayout == D3D12_ELEMENTS_LAYOUT_ARRAY_OF_POINTERS)
            {
                constexpr auto instance_desc_pointer_stride = sizeof(D3D12_GPU_VIRTUAL_ADDRESS);
                for (UINT i = 0; i < build_desc->Inputs.NumDescs; ++i)
                {
                    resource_value_infos.insert({ offset_to_instance_descs_start + instance_desc_pointer_stride * i,
                                                  ResourceValueType::kRaytracingInstanceDescPointer,
                                                  sizeof(D3D12_GPU_VIRTUAL_ADDRESS),
                                                  nullptr,
                                                  { nullptr, nullptr, 0 },
                                                  0 });
                }
            }
            else
            {
                GFXRECON_LOG_ERROR("Unknown BuildRaytracingAccelerationStructure DescsLayout: %d",
                                   static_cast<int>(build_desc->Inputs.DescsLayout));
            }
            SourceCopyResources(command_list_extra_info->resource_copies,
                                command_list_extra_info->resource_value_info_map);
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to find the resource containing the D3D12_GPU_VIRTUAL_ADDRESS (%" PRIu64
                               ") of InstanceDescs in call to BuildRaytracingAccelerationStructure. GPU addresses "
                               "pointed to by InstanceDescs may be incorrect.",
                               build_desc->Inputs.InstanceDescs);
        }
    }
}

void Dx12ResourceValueMapper::PostProcessCreateRootSignature(PointerDecoder<uint8_t>* blob_with_root_signature_decoder,
                                                             SIZE_T                   blob_length_in_bytes,
                                                             HandlePointerDecoder<void*>* root_signature_decoder)
{
    // Store root signature GPU VAs and descriptor handles with the root signature's extra info.
    auto root_sig_id              = *root_signature_decoder->GetPointer();
    auto root_sig_extra_info      = GetExtraInfo<D3D12RootSignatureInfo>(root_signature_decoder);
    auto blob_with_root_signature = blob_with_root_signature_decoder->GetPointer();

    GFXRECON_ASSERT(root_sig_id != format::kNullHandleId);
    GFXRECON_ASSERT(root_sig_extra_info != nullptr);
    GFXRECON_ASSERT(blob_with_root_signature != nullptr);
    GFXRECON_ASSERT(blob_length_in_bytes != 0);

    graphics::dx12::ID3D12VersionedRootSignatureDeserializerComPtr root_sig_deserializer{ nullptr };
    HRESULT result = D3D12CreateVersionedRootSignatureDeserializer(
        blob_with_root_signature, blob_length_in_bytes, IID_PPV_ARGS(&root_sig_deserializer));
    if (SUCCEEDED(result))
    {
        auto versioned_root_sig = root_sig_deserializer->GetUnconvertedRootSignatureDesc();

        switch (versioned_root_sig->Version)
        {
            case D3D_ROOT_SIGNATURE_VERSION_1_0:
                GetRootSignatureResourceValueInfos(&versioned_root_sig->Desc_1_0,
                                                   root_sig_extra_info->resource_value_infos);
                break;
            case D3D_ROOT_SIGNATURE_VERSION_1_1:
                GetRootSignatureResourceValueInfos(&versioned_root_sig->Desc_1_1,
                                                   root_sig_extra_info->resource_value_infos);
                break;
            case D3D_ROOT_SIGNATURE_VERSION_1_2:
                GetRootSignatureResourceValueInfos(&versioned_root_sig->Desc_1_2,
                                                   root_sig_extra_info->resource_value_infos);
                break;
            default:
                GFXRECON_LOG_ERROR("Ignoring unrecognized root signature version (%d) for root signature (id=%" PRIu64
                                   ").",
                                   versioned_root_sig->Version,
                                   root_sig_id);
                break;
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to deserialize root signature (id=%" PRIu64 ").", root_sig_id);
    }
}

void Dx12ResourceValueMapper::PostProcessCreateStateObject(
    HandlePointerDecoder<void*>*                           state_object_decoder,
    StructPointerDecoder<Decoded_D3D12_STATE_OBJECT_DESC>* desc_decoder,
    const D3D12StateObjectInfo*                            grow_from_state_object)
{
    auto                                           state_object_id = *state_object_decoder->GetPointer();
    std::set<std::wstring>                         export_names;
    std::vector<format::HandleId>                  local_root_signature_ids;
    format::HandleId                               explicit_default_local_root_signature_id = format::kNullHandleId;
    std::map<std::wstring, format::HandleId>       explicit_local_root_signature_associations;
    std::map<std::wstring, std::set<std::wstring>> hit_group_imports;
    std::map<std::wstring, format::HandleId>       lrs_associations_map;
    std::map<graphics::Dx12ShaderIdentifier, std::set<ResourceValueInfo>> existing_shader_id_lrs_map;

    auto state_object_extra_info = GetExtraInfo<D3D12StateObjectInfo>(state_object_decoder);
    if (grow_from_state_object != nullptr)
    {
        lrs_associations_map = grow_from_state_object->export_name_lrs_map;
    }

    GetStateObjectLrsAssociationInfo(state_object_id,
                                     desc_decoder,
                                     export_names,
                                     local_root_signature_ids,
                                     explicit_default_local_root_signature_id,
                                     explicit_local_root_signature_associations,
                                     hit_group_imports,
                                     lrs_associations_map,
                                     existing_shader_id_lrs_map);

    if (!export_names.empty())
    {
        // Determine if there is a default LRS for this state object.
        std::set<format::HandleId> associated_local_root_sig_ids;
        if (explicit_default_local_root_signature_id != format::kNullHandleId)
        {
            associated_local_root_sig_ids.insert(explicit_default_local_root_signature_id);
        }
        for (auto association_pair : explicit_local_root_signature_associations)
        {
            associated_local_root_sig_ids.insert(association_pair.second);
        }
        format::HandleId implicit_default_local_root_sig_id = format::kNullHandleId;
        for (auto local_root_sig_id : local_root_signature_ids)
        {
            if (associated_local_root_sig_ids.find(local_root_sig_id) == associated_local_root_sig_ids.end())
            {
                if (implicit_default_local_root_sig_id != format::kNullHandleId)
                {
                    GFXRECON_LOG_WARNING("CreateStateObject: Found multiple unassociated local root signatures in "
                                         "state object (id=%" PRIu64
                                         "). Shader ID to LRS associations may be incorrect.",
                                         state_object_id);
                }
                implicit_default_local_root_sig_id = local_root_sig_id;
            }
        }

        // Resolve associations between shader exports and LRSs.
        for (auto& export_name : export_names)
        {
            // Initialize to implicit default root signature.
            format::HandleId export_local_root_sig_id = implicit_default_local_root_sig_id;

            // Check for explicit default LRS assocation.
            if (explicit_default_local_root_signature_id != format::kNullHandleId)
            {
                export_local_root_sig_id = explicit_default_local_root_signature_id;
            }

            // Check for explicit shader ID to LRS association from existing a state object dependency (from an existing
            // collection or input to AddToStateObject).
            if (lrs_associations_map.find(export_name) != lrs_associations_map.end())
            {
                export_local_root_sig_id = lrs_associations_map[export_name];
            }

            // Promote explicit LRS associations of hit group imports to the LRS association of the hit group export.
            auto hit_group_import_iter = hit_group_imports.find(export_name);
            if (hit_group_import_iter != hit_group_imports.end())
            {
                auto explicit_import_lrs = format::kNullHandleId;
                for (const auto& hit_group_import : hit_group_import_iter->second)
                {
                    auto explicit_association_pair = explicit_local_root_signature_associations.find(hit_group_import);
                    if (explicit_association_pair != explicit_local_root_signature_associations.end())
                    {
                        GFXRECON_ASSERT((explicit_import_lrs == format::kNullHandleId) ||
                                        (explicit_import_lrs == explicit_association_pair->second));
                        explicit_import_lrs      = explicit_association_pair->second;
                        export_local_root_sig_id = explicit_import_lrs;
                    }
                }
            }

            // Apply explicit shader ID to LRS association.
            auto explicit_association_pair = explicit_local_root_signature_associations.find(export_name);
            if (explicit_association_pair != explicit_local_root_signature_associations.end())
            {
                export_local_root_sig_id = explicit_association_pair->second;
            }

            // Save the result.
            lrs_associations_map[export_name] = export_local_root_sig_id;
        }

        // Store the shader ID LRS map with the state object extra info, to be referenced if this state object is used
        // as a dependency in the creation of another SO.
        state_object_extra_info->export_name_lrs_map = lrs_associations_map;
        state_object_extra_info->shader_id_lrs_map.insert(existing_shader_id_lrs_map.begin(),
                                                          existing_shader_id_lrs_map.end());

        // Populate the state object's shader_id_lrs_map for shaders that were exported.
        graphics::dx12::ID3D12StateObjectPropertiesComPtr props;
        auto    state_object = static_cast<ID3D12StateObject*>(*state_object_decoder->GetHandlePointer());
        HRESULT hr           = state_object->QueryInterface(IID_PPV_ARGS(&props));
        GFXRECON_ASSERT(SUCCEEDED(hr));
        for (auto& root_sig_pair : lrs_associations_map)
        {
            auto export_local_root_sig_id = root_sig_pair.second;
            if (export_local_root_sig_id != format::kNullHandleId)
            {
                const auto& export_name        = root_sig_pair.first;
                auto new_shader_identifier_ptr = static_cast<uint8_t*>(props->GetShaderIdentifier(export_name.c_str()));
                if (new_shader_identifier_ptr != nullptr)
                {
                    auto replay_shader_id = graphics::PackDx12ShaderIdentifier(new_shader_identifier_ptr);

                    auto local_root_sig_object_info = get_object_info_func_(export_local_root_sig_id);
                    GFXRECON_ASSERT(local_root_sig_object_info != nullptr);

                    auto local_root_sig_extra_info = GetExtraInfo<D3D12RootSignatureInfo>(local_root_sig_object_info);
                    GFXRECON_ASSERT(local_root_sig_extra_info != nullptr);

                    auto lrs_map = state_object_extra_info->shader_id_lrs_map.find(replay_shader_id);
                    if (lrs_map == state_object_extra_info->shader_id_lrs_map.end())
                    {
                        state_object_extra_info->shader_id_lrs_map[replay_shader_id] =
                            local_root_sig_extra_info->resource_value_infos;
                    }
                    else
                    {
                        if (!((lrs_map->second.size() == local_root_sig_extra_info->resource_value_infos.size()) &&
                              (std::equal(lrs_map->second.begin(),
                                          lrs_map->second.end(),
                                          local_root_sig_extra_info->resource_value_infos.begin()))))
                        {
                            // Given a ShaderID to the StateObject, if it already assocated LRS but different from
                            // defined in the current StateObject, GFXR could not determind which LRS is right to the
                            // ShaderID.
                            GFXRECON_LOG_ERROR_ONCE(
                                "CreateStateObject: Duplicate shader identifier found for export '%ls' in "
                                "state object (id=%" PRIu64 "). Shader ID to LRS associations may be incorrect.",
                                export_name.c_str(),
                                state_object_id);
                        }
                    }
                }
            }
        }
    }
}

void Dx12ResourceValueMapper::PostProcessDispatchRays(
    DxObjectInfo* command_list4_object_info, StructPointerDecoder<Decoded_D3D12_DISPATCH_RAYS_DESC>* desc_decoder)
{
    const auto* desc = desc_decoder->GetPointer();

    // Skip empty dispatch.
    if ((desc->Width == 0) || (desc->Height == 0) || (desc->Depth == 0))
    {
        return;
    }

    auto command_list_extra_info = GetExtraInfo<D3D12CommandListInfo>(command_list4_object_info);
    GFXRECON_ASSERT(command_list_extra_info != nullptr);

    // Ray gen only has 1 record, so stride == size
    D3D12StateObjectInfo* state_object_extra_info = nullptr;
    if (command_list_extra_info->active_state_object != nullptr)
    {
        state_object_extra_info = GetExtraInfo<D3D12StateObjectInfo>(command_list_extra_info->active_state_object);
    }
    GetDispatchRaysResourceValues(command_list_extra_info->resource_value_info_map, state_object_extra_info, *desc);
    SourceCopyResources(command_list_extra_info->resource_copies, command_list_extra_info->resource_value_info_map);
}

void Dx12ResourceValueMapper::PostProcessSetPipelineState1(DxObjectInfo* command_list4_object_info,
                                                           DxObjectInfo* state_object_object_info)
{
    auto command_list_extra_info                 = GetExtraInfo<D3D12CommandListInfo>(command_list4_object_info);
    command_list_extra_info->active_state_object = state_object_object_info;
}

void Dx12ResourceValueMapper::PostProcessFillMemoryCommand(uint64_t       resource_id,
                                                           uint64_t       offset,
                                                           uint64_t       size,
                                                           const uint8_t* data)
{
    if (resource_value_tracker_ != nullptr)
    {
        resource_value_tracker_->PostProcessFillMemoryCommand(resource_id, offset, size, data);
    }
}

void Dx12ResourceValueMapper::PostProcessInitSubresourceCommand(
    ID3D12Resource* resource, const format::InitSubresourceCommandHeader& command_header, const uint8_t* data)
{
    if (resource_value_tracker_ != nullptr)
    {
        resource_value_tracker_->PostProcessInitSubresourceCommand(resource, command_header, data);
    }
}

void Dx12ResourceValueMapper::PostProcessCopyTextureRegion(
    DxObjectInfo*                                              command_list_object_info,
    StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* dst_decoder,
    UINT                                                       dst_x,
    UINT                                                       dst_y,
    UINT                                                       dst_z,
    StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* src_decoder,
    StructPointerDecoder<Decoded_D3D12_BOX>*                   src_box_decoder)
{
    if (resource_value_tracker_ != nullptr)
    {
        resource_value_tracker_->PostProcessCopyTextureRegion(
            command_list_object_info, dst_decoder, dst_x, dst_y, dst_z, src_decoder, src_box_decoder);
    }
}

void Dx12ResourceValueMapper::PostProcessIASetIndexBuffer(
    DxObjectInfo* command_list_object_info, StructPointerDecoder<Decoded_D3D12_INDEX_BUFFER_VIEW>* views_decoder)
{
    if (resource_value_tracker_ != nullptr)
    {
        resource_value_tracker_->PostProcessIASetIndexBuffer(
            command_list_object_info, views_decoder, reverse_gpu_va_map_);
    }
}

void Dx12ResourceValueMapper::PostProcessIASetVertexBuffers(
    DxObjectInfo*                                           command_list_object_info,
    UINT                                                    start_slot,
    UINT                                                    num_views,
    StructPointerDecoder<Decoded_D3D12_VERTEX_BUFFER_VIEW>* views_decoder)
{
    if (resource_value_tracker_ != nullptr)
    {
        resource_value_tracker_->PostProcessIASetVertexBuffers(
            command_list_object_info, start_slot, num_views, views_decoder, reverse_gpu_va_map_);
    }
}

void Dx12ResourceValueMapper::AddResourceGpuVa(format::HandleId          resource_id,
                                               D3D12_GPU_VIRTUAL_ADDRESS replay_address,
                                               UINT64                    width,
                                               D3D12_GPU_VIRTUAL_ADDRESS capture_address)
{
    reverse_gpu_va_map_.Add(resource_id, replay_address, width, capture_address);

    if (resource_value_tracker_ != nullptr)
    {
        resource_value_tracker_->AddResourceGpuVa(resource_id, replay_address, width, capture_address);
    }
}

void Dx12ResourceValueMapper::RemoveResourceGpuVa(format::HandleId resource_id,
                                                  uint64_t         replay_address,
                                                  uint64_t         capture_address)
{
    reverse_gpu_va_map_.Remove(resource_id, replay_address);

    if (resource_value_tracker_ != nullptr)
    {
        resource_value_tracker_->RemoveResourceGpuVa(resource_id, capture_address);
    }
}

void Dx12ResourceValueMapper::AddGpuDescriptorHeap(const D3D12_GPU_DESCRIPTOR_HANDLE&     capture_gpu_start,
                                                   const D3D12_GPU_DESCRIPTOR_HANDLE&     replay_gpu_start,
                                                   D3D12_DESCRIPTOR_HEAP_TYPE             heap_info_descriptor_type,
                                                   uint32_t                               heap_info_descriptor_count,
                                                   std::shared_ptr<DescriptorIncrements>& heap_info_capture_increments,
                                                   std::shared_ptr<DescriptorIncrements>& heap_info_replay_increments)
{
    if (resource_value_tracker_ != nullptr)
    {
        resource_value_tracker_->AddGpuDescriptorHeap(capture_gpu_start,
                                                      replay_gpu_start,
                                                      heap_info_descriptor_type,
                                                      heap_info_descriptor_count,
                                                      heap_info_capture_increments,
                                                      heap_info_replay_increments);
    }
}

void Dx12ResourceValueMapper::RemoveGpuDescriptorHeap(uint64_t capture_gpu_start)
{
    if (resource_value_tracker_ != nullptr)
    {
        resource_value_tracker_->RemoveGpuDescriptorHeap(capture_gpu_start);
    }
}

void Dx12ResourceValueMapper::SourceCopyResources(std::vector<ResourceCopyInfo>& copy_infos,
                                                  ResourceValueInfoMap&          resource_value_info_map)
{
    const auto copies_size = copy_infos.size();
    for (size_t i = 0; i < copies_size; ++i)
    {
        auto& copy_info = copy_infos[copies_size - i - 1];
        CopyResourceValues(copy_info, resource_value_info_map);
    }
}

void Dx12ResourceValueMapper::CopyResourceValues(const ResourceCopyInfo& copy_info,
                                                 ResourceValueInfoMap&   resource_value_info_map)
{
    // Copy required resource values from dst to src.
    auto dst_iter = resource_value_info_map.find(copy_info.dst_resource_object_info);
    if (dst_iter != resource_value_info_map.end())
    {
        if (dst_iter->second.empty())
        {
            return;
        }

        auto& dst_values = dst_iter->second;
        auto& src_values = resource_value_info_map[copy_info.src_resource_object_info];

        // If num_bytes != 0, process CopyBufferRegion (partial copy) else process CopyResource (full copy).
        if (copy_info.num_bytes != 0)
        {
            auto dst_values_begin = dst_values.lower_bound(
                { copy_info.dst_offset, ResourceValueType::kUnknown, 0, nullptr, { nullptr, nullptr, 0 }, 0 });
            auto dst_values_end = dst_values.upper_bound({ copy_info.dst_offset + copy_info.num_bytes,
                                                           ResourceValueType::kUnknown,
                                                           0,
                                                           nullptr,
                                                           { nullptr, nullptr, 0 },
                                                           0 });
            CopyResourceValuesFromDstToSrc(src_values, dst_values, dst_values_begin, dst_values_end, copy_info);
            dst_values.erase(dst_values_begin, dst_values_end);
        }
        else
        {
            CopyResourceValuesFromDstToSrc(src_values, dst_values, dst_values.begin(), dst_values.end(), copy_info);
            dst_values.clear();
        }

        // If all values were removed from dst, remove it from the map.
        if (dst_values.empty())
        {
            resource_value_info_map.erase(dst_iter);
        }
    }
}

void Dx12ResourceValueMapper::CopyMappedResourceValues(const ResourceCopyInfo& copy_info)
{
    auto dst_extra_info = GetResourceExtraInfo(copy_info.dst_resource_object_info);
    auto src_extra_info = GetResourceExtraInfo(copy_info.src_resource_object_info);

    auto& dst_mapped_gpu_addresses = dst_extra_info->mapped_gpu_addresses;
    auto& src_mapped_gpu_addresses = src_extra_info->mapped_gpu_addresses;
    auto& dst_mapped_shader_ids    = dst_extra_info->mapped_shader_ids;
    auto& src_mapped_shader_ids    = src_extra_info->mapped_shader_ids;

    // If num_bytes != 0, process CopyBufferRegion (partial copy) else process CopyResource (full copy).
    if (copy_info.num_bytes != 0)
    {
        auto dst_min_offset = copy_info.dst_offset;
        auto dst_max_offset = dst_min_offset + copy_info.num_bytes;
        auto src_min_offset = copy_info.src_offset;
        auto src_max_offset = src_min_offset + copy_info.num_bytes;

        { // Remove current set of mapped values in destination copy range.
            auto dst_mapped_gpu_addresses_begin = dst_mapped_gpu_addresses.lower_bound(dst_min_offset);
            auto dst_mapped_gpu_addresses_end   = dst_mapped_gpu_addresses.upper_bound(dst_max_offset);
            dst_mapped_gpu_addresses.erase(dst_mapped_gpu_addresses_begin, dst_mapped_gpu_addresses_end);
        }

        { // Copy mapped values from source to destination.
            auto src_mapped_gpu_addresses_begin = src_mapped_gpu_addresses.lower_bound(src_min_offset);
            auto src_mapped_gpu_addresses_end   = src_mapped_gpu_addresses.upper_bound(src_max_offset);
            CopyMappedResourceValuesFromSrcToDst(dst_mapped_gpu_addresses,
                                                 src_mapped_gpu_addresses,
                                                 src_mapped_gpu_addresses_begin,
                                                 src_mapped_gpu_addresses_end,
                                                 copy_info);
        }

        { // Remove current set of mapped shader IDs in destination copy range.
            auto dst_mapped_shader_ids_begin = dst_mapped_shader_ids.lower_bound(dst_min_offset);
            auto dst_mapped_shader_ids_end   = dst_mapped_shader_ids.upper_bound(dst_max_offset);
            dst_mapped_shader_ids.erase(dst_mapped_shader_ids_begin, dst_mapped_shader_ids_end);
        }

        { // Copy mapped shader IDs from source to destination.
            auto src_mapped_shader_ids_begin = src_mapped_shader_ids.lower_bound(src_min_offset);
            auto src_mapped_shader_ids_end   = src_mapped_shader_ids.upper_bound(src_max_offset);
            CopyMappedResourceValuesFromSrcToDst(dst_mapped_shader_ids,
                                                 src_mapped_shader_ids,
                                                 src_mapped_shader_ids_begin,
                                                 src_mapped_shader_ids_end,
                                                 copy_info);
        }
    }
    else
    {
        // Clear destination values and copy from source.
        dst_mapped_gpu_addresses.clear();
        CopyMappedResourceValuesFromSrcToDst(dst_mapped_gpu_addresses,
                                             src_mapped_gpu_addresses,
                                             src_mapped_gpu_addresses.begin(),
                                             src_mapped_gpu_addresses.end(),
                                             copy_info);

        // Clear destination shader IDs and copy from source.
        dst_mapped_shader_ids.clear();
        CopyMappedResourceValuesFromSrcToDst(dst_mapped_shader_ids,
                                             src_mapped_shader_ids,
                                             src_mapped_shader_ids.begin(),
                                             src_mapped_shader_ids.end(),
                                             copy_info);
    }
}

void Dx12ResourceValueMapper::ProcessResourceMappings(ProcessResourceMappingsArgs args)
{
    GFXRECON_ASSERT(args.fence != nullptr);

    // Wait for the command queue before mapping.
    UINT64 completed_value = args.fence->GetCompletedValue();
    if (completed_value == UINT64_MAX)
    {
        GFXRECON_LOG_FATAL(
            "Invalid fence value (UINT64_MAX). Device may have been removed. GFXR is unable to continue.");
        return;
    }
    if (completed_value < args.fence_value)
    {
        ResetEvent(args.fence_event);
        args.fence->SetEventOnCompletion(args.fence_value, args.fence_event);
        WaitForSingleObject(args.fence_event, INFINITE);
    }

    auto resource_value_info_map = std::move(args.resource_value_info_map);
    args.resource_value_info_map.clear();
    std::map<DxObjectInfo*, MappedResourceRevertInfo> resource_data_to_revert;
    while (!resource_value_info_map.empty())
    {
        // Process resource copies so values are mapped in the source resource.
        SourceCopyResources(args.resource_copies, resource_value_info_map);

        // Apply the resource value mappings to the resources on the GPU.
        ResourceValueInfoMap indirect_values_map;
        MapResources(resource_value_info_map, resource_data_to_revert, indirect_values_map);

        // If indirect_values_map is not empty, another pass of mapping is required.
        resource_value_info_map = std::move(indirect_values_map);
    }

    // Track mapped values that were copied to other resources.
    const auto copies_size = args.resource_copies.size();
    for (size_t i = 0; i < copies_size; ++i)
    {
        auto& copy_info = args.resource_copies[i];
        CopyMappedResourceValues(copy_info);
    }

    // Signal to the command queue that the mapping is completed.
    args.fence->Signal(args.fence_value + 1);

    // Wait for the command queue before performing resource mapping.
    if (args.fence->GetCompletedValue() < args.fence_value + 2)
    {
        ResetEvent(args.fence_event);
        args.fence->SetEventOnCompletion(args.fence_value + 2, args.fence_event);
        WaitForSingleObject(args.fence_event, INFINITE);
    }

    // Revert the resource values to their unmapped values.
    for (auto& resource_data_pair : resource_data_to_revert)
    {
        GFXRECON_ASSERT(!resource_data_pair.second.data.empty());
        HRESULT hr =
            resource_data_util_->WriteToResource(static_cast<ID3D12Resource*>(resource_data_pair.first->object),
                                                 true,
                                                 resource_data_pair.second.states,
                                                 resource_data_pair.second.states,
                                                 resource_data_pair.second.data,
                                                 { 0 },
                                                 { resource_data_pair.second.data.size() });
        if (SUCCEEDED(hr))
        {
            // The mapped values were reverted in the resource data, so revert the set of mapped values here.
            auto extra_info                  = GetResourceExtraInfo(resource_data_pair.first);
            extra_info->mapped_gpu_addresses = std::move(resource_data_pair.second.mapped_gpu_addresses);
            extra_info->mapped_shader_ids    = std::move(resource_data_pair.second.mapped_shader_ids);
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to revert data for mapped resource %" PRIu64,
                               resource_data_pair.first->capture_id);
        }
    }

    // Signal to the command queue that the mapping is completed.
    args.fence->Signal(args.fence_value + 3);
}

bool Dx12ResourceValueMapper::IsNonEmptyShaderRecord(const std::vector<uint8_t>& data, uint64_t offset, uint64_t size)
{
    bool is_empty = false;
    if (size > D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES)
    {
        for (size_t index = 0; index < size - D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES; ++index)
        {
            if (data[static_cast<size_t>(offset) + D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES + index] != 0x0)
            {
                is_empty = true;
                break;
            }
        }
    }
    return is_empty;
}

bool Dx12ResourceValueMapper::MapValue(const ResourceValueInfo& value_info,
                                       std::vector<uint8_t>&    result_data,
                                       format::HandleId         resource_id,
                                       D3D12ResourceInfo*       resource_info,
                                       ResourceValueInfoMap&    indirect_values_map,
                                       uint64_t                 base_offset)
{
    uint64_t final_offset = value_info.offset + base_offset;

    if ((value_info.type == ResourceValueType::kGpuVirtualAddress) ||
        (value_info.type == ResourceValueType::kGpuDescriptorHandle))
    {
        D3D12_GPU_VIRTUAL_ADDRESS* address =
            reinterpret_cast<D3D12_GPU_VIRTUAL_ADDRESS*>(result_data.data() + final_offset);
        auto current_address = *address;

        if (current_address == 0)
        {
            return false;
        }

        auto mapped_value_iter = resource_info->mapped_gpu_addresses.find(final_offset);

        if (resource_value_tracker_ != nullptr)
        {
            resource_value_tracker_->AddTrackedResourceValue(
                resource_id, value_info.type, final_offset, result_data.data() + final_offset, gpu_va_map_);
        }

        // If the current value at the given offset matches the result of a previous mapping, don't attempt to map
        // again.
        if (mapped_value_iter != resource_info->mapped_gpu_addresses.end())
        {
            if (current_address == mapped_value_iter->second)
            {
                return false;
            }
        }

        if (value_info.type == ResourceValueType::kGpuVirtualAddress)
        {
            object_mapping::MapGpuVirtualAddress(*address, gpu_va_map_);

            if ((*address) == current_address)
            {
                GFXRECON_LOG_DEBUG_ONCE("Mapping a GPU virtual address resulted in no change.");
            }
            else
            {
                // Track the mapped value.
                resource_info->mapped_gpu_addresses[final_offset] = *address;
            }
        }
        else if (value_info.type == ResourceValueType::kGpuDescriptorHandle)
        {
            D3D12_GPU_DESCRIPTOR_HANDLE descriptor_handle;
            descriptor_handle.ptr = *address;
            object_mapping::MapGpuDescriptorHandle(descriptor_handle, descriptor_map_);
            *address = descriptor_handle.ptr;

            if ((*address) == current_address)
            {
                GFXRECON_LOG_DEBUG_ONCE("Mapping a GPU descriptor handle resulted in no change.");
            }
            else
            {
                // Track the mapped value.
                resource_info->mapped_gpu_addresses[final_offset] = *address;
            }
        }
        return true;
    }
    else if (value_info.type == ResourceValueType::kShaderIdentifier)
    {
        // Map a shader record. Shader records contain a shader identifier followed by the local root signature
        // parameters needed by the shader.

        GFXRECON_ASSERT(value_info.state_object != nullptr);

        constexpr graphics::Dx12ShaderIdentifier zero_id = { 0 };

        uint8_t*                       shader_id_ptr = result_data.data() + final_offset;
        graphics::Dx12ShaderIdentifier current_id    = graphics::PackDx12ShaderIdentifier(shader_id_ptr);

        // Don't attempt to map shader records with shader ID == 0.
        if (current_id == zero_id)
        {
            return false;
        }

        auto mapped_shader_id_iter = resource_info->mapped_shader_ids.find(final_offset);

        if (resource_value_tracker_ != nullptr)
        {
            resource_value_tracker_->AddTrackedResourceValue(
                resource_id, ResourceValueType::kShaderIdentifier, final_offset, shader_id_ptr, gpu_va_map_);
        }

        // Map the shader ID if it wasn't previously mapped.
        if ((mapped_shader_id_iter == resource_info->mapped_shader_ids.end()) ||
            (current_id != mapped_shader_id_iter->second))
        {
            if (!shader_id_map_.Map(shader_id_ptr))
            {
                // If the shader ID was not found in the shader ID map, don't treat the data as a shader record.
                // It is possible for a shader to specify a multiplier (e.g.,
                // MultiplierForGeometryContributionToHitGroupIndex) for the shader record stride so not all data in the
                // range of the shader table is necessarily a shader record.
                return false;
            }
        }

        auto replay_shader_id = graphics::PackDx12ShaderIdentifier(shader_id_ptr);

        // Track mapped shader IDs within a resource.
        resource_info->mapped_shader_ids[final_offset] = replay_shader_id;

        // Map values in the shader record's local root signature.
        auto shader_id_lrs_iter = value_info.state_object->shader_id_lrs_map.find(replay_shader_id);
        if (shader_id_lrs_iter != value_info.state_object->shader_id_lrs_map.end())
        {
            for (const auto& shader_record_value_info : shader_id_lrs_iter->second)
            {
                if ((shader_record_value_info.offset + D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES) < value_info.size)
                {
                    MapValue(shader_record_value_info,
                             result_data,
                             resource_id,
                             resource_info,
                             indirect_values_map,
                             final_offset + D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES);
                }
            }
        }
        else
        {
            // Error if a local root signature could be present in the shader record (based on record size) but the LRS
            // association was not found by PostProcessCreateStateObject.
            if ((value_info.size > D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES) &&
                IsNonEmptyShaderRecord(result_data, final_offset, value_info.size))
            {
                GFXRECON_LOG_WARNING_ONCE("Did not find an associated local root signature for one or more shader IDs "
                                          "used in a shader record. If the shader record contains GPU virtual "
                                          "addresses or descriptor handles, replay may fail.");

                if (resource_value_tracker_ != nullptr)
                {
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, final_offset);

                    resource_value_tracker_->AddShaderRecordData(
                        resource_id,
                        final_offset + D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES,
                        value_info.size - D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES,
                        &result_data[static_cast<size_t>(final_offset) + D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES],
                        gpu_va_map_,
                        descriptor_map_);
                }
            }
        }
        return true;
    }
    else if (value_info.type == ResourceValueType::kIndirectArgumentDispatchRays)
    {
        GFXRECON_ASSERT(value_info.size == sizeof(D3D12_DISPATCH_RAYS_DESC));

        uint8_t* desc_data_ptr = result_data.data() + final_offset;

        // First map the StartAddress GPU VAs from D3D12_DISPATCH_RAYS_DESC in resource data.
        ResourceValueInfo rvi{ 0, ResourceValueType::kUnknown, 0, nullptr, { nullptr, nullptr, 0 }, 0 };
        rvi.size         = sizeof(D3D12_GPU_VIRTUAL_ADDRESS);
        rvi.type         = ResourceValueType::kGpuVirtualAddress;
        rvi.state_object = value_info.state_object;

        // Map ray gen shader record StartAddress.
        rvi.offset = value_info.offset + offsetof(D3D12_DISPATCH_RAYS_DESC, RayGenerationShaderRecord) +
                     offsetof(D3D12_GPU_VIRTUAL_ADDRESS_RANGE, StartAddress);
        MapValue(rvi, result_data, resource_id, resource_info, indirect_values_map, base_offset);

        // Map miss shader table StartAddress.
        rvi.offset = value_info.offset + offsetof(D3D12_DISPATCH_RAYS_DESC, MissShaderTable) +
                     offsetof(D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE, StartAddress);
        MapValue(rvi, result_data, resource_id, resource_info, indirect_values_map, base_offset);

        // Map hit group table StartAddress.
        rvi.offset = value_info.offset + offsetof(D3D12_DISPATCH_RAYS_DESC, HitGroupTable) +
                     offsetof(D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE, StartAddress);
        MapValue(rvi, result_data, resource_id, resource_info, indirect_values_map, base_offset);

        // Map callable shader table StartAddress.
        rvi.offset = value_info.offset + offsetof(D3D12_DISPATCH_RAYS_DESC, CallableShaderTable) +
                     offsetof(D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE, StartAddress);
        MapValue(rvi, result_data, resource_id, resource_info, indirect_values_map, base_offset);

        // After mapping the start GPU VAs in the D3D12_DISPATCH_RAYS_DESC, add the resource values the shader records
        // will reference to indirect_values_map. These will be mapped in a follow-up mapping pass.
        D3D12_DISPATCH_RAYS_DESC desc;
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, value_info.size);
        util::platform::MemoryCopy(&desc, sizeof(desc), desc_data_ptr, static_cast<size_t>(value_info.size));
        GetDispatchRaysResourceValues(indirect_values_map, value_info.state_object, desc);
        return true;
    }
    else if (value_info.type == ResourceValueType::kExecuteIndirectCountBuffer)
    {
        // Read command counts while CountBuffer contents is still visible in temp_resource_data
        uint32_t command_count = 0;
        util::platform::MemoryCopy(&command_count,
                                   sizeof(command_count),
                                   temp_resource_data.data() + value_info.offset,
                                   sizeof(command_count));

        // Insert new ArgumentBuffer RV infos, which will queue them for translation.
        if (command_count != 0)
        {
            if (value_info.max_command_count > 0)
            {
                command_count = std::min(value_info.max_command_count, command_count);
            }
            GetExecuteIndirectResourceValues(
                indirect_values_map[value_info.arg_buffer_extra_info.argument_buffer],
                value_info.arg_buffer_extra_info.command_signature_info->resource_value_infos,
                command_count,
                value_info.arg_buffer_extra_info.argument_buffer_offset,
                value_info.arg_buffer_extra_info.command_signature_info->byte_stride,
                value_info.state_object);
        }
        return false;
    }
    else if (value_info.type == ResourceValueType::kRaytracingInstanceDescPointer)
    {
        GFXRECON_ASSERT(value_info.size == sizeof(D3D12_GPU_VIRTUAL_ADDRESS));

        // Map the GPU_VA in the array of instance desc pointers.
        ResourceValueInfo rvi = value_info;
        rvi.type              = ResourceValueType::kGpuVirtualAddress;
        MapValue(rvi, result_data, resource_id, resource_info, indirect_values_map);

        // Read instance desc GPU_VA from the array of pointers.
        D3D12_GPU_VIRTUAL_ADDRESS instance_desc_gpu_va = 0;
        util::platform::MemoryCopy(&instance_desc_gpu_va,
                                   sizeof(instance_desc_gpu_va),
                                   result_data.data() + value_info.offset,
                                   sizeof(instance_desc_gpu_va));

        GFXRECON_ASSERT(value_info.offset == final_offset);

        // Insert new RV infos for instance desc's AccelerationStructure, which will queue it for mapping.
        if (instance_desc_gpu_va != 0)
        {
            // The spec requires that instance descs are aligned to D3D12_RAYTRACING_INSTANCE_DESCS_BYTE_ALIGNMENT. If
            // the instance descs are not aligned behavior may be undefined.
            GFXRECON_ASSERT((instance_desc_gpu_va % D3D12_RAYTRACING_INSTANCE_DESCS_BYTE_ALIGNMENT) == 0);

            // Find the resource that contains the address referenced by instance_desc_gpu_va.
            format::HandleId instance_desc_resource_id = format::kNullHandleId;
            bool             found                     = false;
            reverse_gpu_va_map_.Map(instance_desc_gpu_va,
                                    &instance_desc_resource_id,
                                    &found,
                                    instance_desc_gpu_va + sizeof(D3D12_RAYTRACING_INSTANCE_DESC));

            if (instance_desc_resource_id != format::kNullHandleId)
            {
                GFXRECON_ASSERT(found);

                auto resource_object_info = get_object_info_func_(instance_desc_resource_id);
                GFXRECON_ASSERT(resource_object_info != nullptr);
                GFXRECON_ASSERT(resource_object_info->object != nullptr);

                auto instance_desc_resource = static_cast<ID3D12Resource*>(resource_object_info->object);
                GFXRECON_ASSERT(instance_desc_gpu_va >= instance_desc_resource->GetGPUVirtualAddress());
                auto offset_to_instance_desc_start =
                    instance_desc_gpu_va - instance_desc_resource->GetGPUVirtualAddress();

                constexpr auto accel_struct_gpu_va_offset =
                    offsetof(D3D12_RAYTRACING_INSTANCE_DESC, AccelerationStructure);

                auto& resource_value_infos = indirect_values_map[resource_object_info];
                resource_value_infos.insert({ offset_to_instance_desc_start + accel_struct_gpu_va_offset,
                                              ResourceValueType::kGpuVirtualAddress,
                                              sizeof(D3D12_GPU_VIRTUAL_ADDRESS),
                                              nullptr,
                                              { nullptr, nullptr, 0 },
                                              0 });
            }
            else
            {
                GFXRECON_LOG_ERROR("Failed to find the resource containing the D3D12_GPU_VIRTUAL_ADDRESS (%" PRIu64
                                   ") of InstanceDescs in call to BuildRaytracingAccelerationStructure. GPU addresses "
                                   "pointed to by InstanceDescs may be incorrect.",
                                   instance_desc_gpu_va);
            }
        }
        return true;
    }
    else
    {
        GFXRECON_ASSERT(false && "Unrecognized resource value type.");
    }
    return false;
}

void Dx12ResourceValueMapper::MapResources(const ResourceValueInfoMap&                        resource_value_info_map,
                                           std::map<DxObjectInfo*, MappedResourceRevertInfo>& resource_data_to_revert,
                                           ResourceValueInfoMap&                              indirect_values_map)
{
    for (const auto& resource_value_infos : resource_value_info_map)
    {
        const auto& value_infos = resource_value_infos.second;

        if (value_infos.empty())
        {
            GFXRECON_LOG_WARNING_ONCE("Did not find resource value info for the given object.");
        }

        auto resource_object_info = resource_value_infos.first;
        auto resource             = static_cast<ID3D12Resource*>(resource_object_info->object);

        D3D12_HEAP_PROPERTIES heap_properties;
        D3D12_HEAP_FLAGS      heap_flags;
        HRESULT               result = resource->GetHeapProperties(&heap_properties, &heap_flags);
        temp_resource_states.clear();
        if (heap_properties.Type == D3D12_HEAP_TYPE_UPLOAD)
        {
            // If the resource is on an upload heap, it cannot be transitioned away from
            // D3D12_RESOURCE_STATE_GENERIC_READ.
            temp_resource_states.push_back({ D3D12_RESOURCE_STATE_GENERIC_READ, D3D12_RESOURCE_BARRIER_FLAG_NONE });
        }
        else if (heap_properties.Type == D3D12_HEAP_TYPE_READBACK)
        {
            // If the resource is on an readback heap, it cannot be transitioned away from
            // D3D12_RESOURCE_STATE_COPY_DEST.
            temp_resource_states.push_back({ D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_BARRIER_FLAG_NONE });
        }
        else
        {
            // TODO: Track resource state transitions for resources on other heap types.
            temp_resource_states.push_back({ D3D12_RESOURCE_STATE_GENERIC_READ, D3D12_RESOURCE_BARRIER_FLAG_NONE });
        }

        temp_resource_data.clear();
        temp_resource_sizes.clear();
        temp_resource_offsets.clear();
        HRESULT hr = resource_data_util_->ReadFromResource(resource,
                                                           true,
                                                           temp_resource_states,
                                                           temp_resource_states,
                                                           temp_resource_data,
                                                           temp_resource_offsets,
                                                           temp_resource_sizes);

        if (SUCCEEDED(hr))
        {
            auto resource_extra_info = GetResourceExtraInfo(resource_object_info);

            MappedResourceRevertInfo revert_info;
            revert_info.data                 = temp_resource_data;
            revert_info.states               = temp_resource_states;
            revert_info.mapped_gpu_addresses = resource_extra_info->mapped_gpu_addresses;
            revert_info.mapped_shader_ids    = resource_extra_info->mapped_shader_ids;

            bool write_back = false;
            for (const auto& value_info : value_infos)
            {
                if (performed_rv_mapping_ == false)
                {
                    if ((value_info.type == ResourceValueType::kGpuVirtualAddress) ||
                        (value_info.type == ResourceValueType::kGpuDescriptorHandle) ||
                        (value_info.type == ResourceValueType::kShaderIdentifier) ||
                        (value_info.type == ResourceValueType::kIndirectArgumentDispatchRays))
                    {
                        // condition for DXR/EI optimization really being done in gfxrecon-optimize
                        performed_rv_mapping_ = true;
                    }
                }

                if (MapValue(value_info,
                             temp_resource_data,
                             resource_object_info->capture_id,
                             resource_extra_info,
                             indirect_values_map) == true)
                {
                    write_back = true;
                }
            }

            if (write_back == true)
            {
                resource_data_to_revert[resource_value_infos.first] = std::move(revert_info);
                hr                                                  = resource_data_util_->WriteToResource(resource,
                                                          true,
                                                          temp_resource_states,
                                                          temp_resource_states,
                                                          temp_resource_data,
                                                          temp_resource_offsets,
                                                          temp_resource_sizes);
            }

            if (FAILED(hr))
            {
                GFXRECON_LOG_ERROR("Failed to write data for mapping values in resource (id=%" PRIu64 ")",
                                   resource_object_info->capture_id);
            }
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to read data for mapping values in resource (id=%" PRIu64 ")",
                               resource_object_info->capture_id);
        }
    }
}

void Dx12ResourceValueMapper::InitializeRequiredObjects(ID3D12CommandQueue*    command_queue,
                                                        D3D12CommandQueueInfo* command_queue_extra_info)
{
    graphics::dx12::ID3D12DeviceComPtr device = nullptr;
    HRESULT                            result = command_queue->GetDevice(IID_PPV_ARGS(&device));
    GFXRECON_ASSERT(SUCCEEDED(result));

    // Create the fence for synchronizing resource mapping.
    auto fence_result = device->CreateFence(command_queue_extra_info->resource_value_map_fence_value,
                                            D3D12_FENCE_FLAG_NONE,
                                            IID_PPV_ARGS(&command_queue_extra_info->resource_value_map_fence));
    ++command_queue_extra_info->resource_value_map_fence_value;
    if (SUCCEEDED(fence_result))
    {
        command_queue_extra_info->resource_value_map_event = CreateEventA(nullptr, TRUE, FALSE, nullptr);
        command_queue_extra_info->resource_value_map_fence_info.object =
            command_queue_extra_info->resource_value_map_fence;
        command_queue_extra_info->resource_value_map_fence_info.extra_info = std::make_unique<D3D12FenceInfo>();
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to create ID3D12Fence object for synchronizing the mapping for resource values with "
                           "command list execution.");
    }

    if (resource_data_util_ == nullptr)
    {
        resource_data_util_ = std::make_unique<graphics::Dx12ResourceDataUtil>(device, 0);
    }
}

void Dx12ResourceValueMapper::GetShaderTableResourceValues(ResourceValueInfoMap&     resource_value_info_map,
                                                           D3D12StateObjectInfo*     state_object_extra_info,
                                                           D3D12_GPU_VIRTUAL_ADDRESS start_address,
                                                           UINT64                    size,
                                                           UINT64                    stride)
{
    if (start_address == 0)
    {
        return;
    }
    format::HandleId resource_id = format::kNullHandleId;
    bool             found       = false;
    reverse_gpu_va_map_.Map(start_address, &resource_id, &found, start_address + size);
    if (resource_id == format::kNullHandleId)
    {
        return;
    }

    // Verify alignments.
    GFXRECON_ASSERT((start_address % D3D12_RAYTRACING_SHADER_TABLE_BYTE_ALIGNMENT) == 0);
    GFXRECON_ASSERT((stride % D3D12_RAYTRACING_SHADER_RECORD_BYTE_ALIGNMENT) == 0);

    auto resource_object_info = get_object_info_func_(resource_id);
    GFXRECON_ASSERT((resource_object_info != nullptr) && (resource_object_info->object != nullptr));
    auto resource = static_cast<ID3D12Resource*>(resource_object_info->object);

    auto& resource_value_infos = resource_value_info_map[resource_object_info];

    UINT64 shader_record_count = 1;
    UINT64 shader_record_size  = size;
    if (stride != 0)
    {
        GFXRECON_ASSERT((size % stride) == 0);
        shader_record_count = (size / stride);
        shader_record_size  = stride;
    }
    auto byte_offset = start_address - resource->GetGPUVirtualAddress();
    GFXRECON_ASSERT((byte_offset % D3D12_RAYTRACING_SHADER_TABLE_BYTE_ALIGNMENT) == 0);
    for (UINT64 i = 0; i < shader_record_count; ++i)
    {
        resource_value_infos.insert({ byte_offset,
                                      ResourceValueType::kShaderIdentifier,
                                      shader_record_size,
                                      state_object_extra_info,
                                      { nullptr, nullptr, 0 },
                                      0 });
        byte_offset += shader_record_size;
    }
}

void Dx12ResourceValueMapper::GetDispatchRaysResourceValues(ResourceValueInfoMap&           resource_value_info_map,
                                                            D3D12StateObjectInfo*           state_object_extra_info,
                                                            const D3D12_DISPATCH_RAYS_DESC& desc)
{
    if (state_object_extra_info == nullptr)
    {
        GFXRECON_LOG_ERROR("No ID3D12StateObject was set on the command list before DispatchRays was called. Unable to "
                           "map the values in the shader table. Replay may fail.");
        return;
    }

    // Ray gen only has 1 record, so stride == size
    GetShaderTableResourceValues(resource_value_info_map,
                                 state_object_extra_info,
                                 desc.RayGenerationShaderRecord.StartAddress,
                                 desc.RayGenerationShaderRecord.SizeInBytes,
                                 desc.RayGenerationShaderRecord.SizeInBytes);
    GetShaderTableResourceValues(resource_value_info_map,
                                 state_object_extra_info,
                                 desc.MissShaderTable.StartAddress,
                                 desc.MissShaderTable.SizeInBytes,
                                 desc.MissShaderTable.StrideInBytes);
    GetShaderTableResourceValues(resource_value_info_map,
                                 state_object_extra_info,
                                 desc.HitGroupTable.StartAddress,
                                 desc.HitGroupTable.SizeInBytes,
                                 desc.HitGroupTable.StrideInBytes);
    GetShaderTableResourceValues(resource_value_info_map,
                                 state_object_extra_info,
                                 desc.CallableShaderTable.StartAddress,
                                 desc.CallableShaderTable.SizeInBytes,
                                 desc.CallableShaderTable.StrideInBytes);
}

void Dx12ResourceValueMapper::GetExecuteIndirectResourceValues(
    std::set<ResourceValueInfo>& dst_resource_value_info_map,
    std::set<ResourceValueInfo>& command_signature_resource_value_info_map,
    uint32_t                     command_count,
    uint64_t                     command_offset,
    uint8_t                      stride,
    D3D12StateObjectInfo*        state_object)
{
    for (uint32_t i = 0; i < command_count; ++i)
    {
        for (const auto& resource_value_info : command_signature_resource_value_info_map)
        {
            dst_resource_value_info_map.insert({ resource_value_info.offset + command_offset,
                                                 resource_value_info.type,
                                                 resource_value_info.size,
                                                 state_object,
                                                 resource_value_info.arg_buffer_extra_info,
                                                 0 });
        }
        command_offset += stride;
    }
}

void Dx12ResourceValueMapper::GetStateObjectLrsAssociationInfo(
    format::HandleId                                                       state_object_id,
    StructPointerDecoder<Decoded_D3D12_STATE_OBJECT_DESC>*                 desc_decoder,
    std::set<std::wstring>&                                                export_names,
    std::vector<format::HandleId>&                                         local_root_signature_ids,
    format::HandleId&                                                      explicit_default_local_root_signature_id,
    std::map<std::wstring, format::HandleId>&                              explicit_local_root_signature_associations,
    std::map<std::wstring, std::set<std::wstring>>&                        hit_group_imports,
    std::map<std::wstring, format::HandleId>&                              lrs_associations_map,
    std::map<graphics::Dx12ShaderIdentifier, std::set<ResourceValueInfo>>& existing_shader_id_lrs_map)
{
    const auto* desc               = desc_decoder->GetPointer();
    const auto* subobject_decoders = desc_decoder->GetMetaStructPointer()->pSubobjects;

    for (UINT i = 0; i < desc->NumSubobjects; ++i)
    {
        const auto  subobject_type    = desc->pSubobjects[i].Type;
        const auto& subobject_decoder = subobject_decoders->GetMetaStructPointer()[i];

        if (subobject_type == D3D12_STATE_SUBOBJECT_TYPE_HIT_GROUP)
        {
            GFXRECON_ASSERT(subobject_decoder.hit_group_desc != nullptr);
            auto hit_group_desc_decoder = subobject_decoder.hit_group_desc;
            auto export_name            = hit_group_desc_decoder->GetMetaStructPointer()->HitGroupExport.GetPointer();

            if (hit_group_desc_decoder->GetMetaStructPointer()->ClosestHitShaderImport.GetPointer() != nullptr)
            {
                auto import_name = hit_group_desc_decoder->GetMetaStructPointer()->ClosestHitShaderImport.GetPointer();
                hit_group_imports[export_name].insert(import_name);
            }
            if (hit_group_desc_decoder->GetMetaStructPointer()->IntersectionShaderImport.GetPointer() != nullptr)
            {
                auto import_name =
                    hit_group_desc_decoder->GetMetaStructPointer()->IntersectionShaderImport.GetPointer();
                hit_group_imports[export_name].insert(import_name);
            }
            if (hit_group_desc_decoder->GetMetaStructPointer()->AnyHitShaderImport.GetPointer() != nullptr)
            {
                auto import_name = hit_group_desc_decoder->GetMetaStructPointer()->AnyHitShaderImport.GetPointer();
                hit_group_imports[export_name].insert(import_name);
            }

            export_names.insert(export_name);
        }
        else if (subobject_type == D3D12_STATE_SUBOBJECT_TYPE_STATE_OBJECT_CONFIG)
        {
            // TODO: handle external dependencies for resolving exports and LRS associations.
            if ((subobject_decoder.state_object_config->GetPointer()->Flags &
                 D3D12_STATE_OBJECT_FLAG_ALLOW_LOCAL_DEPENDENCIES_ON_EXTERNAL_DEFINITIONS) != 0)
            {
                GFXRECON_LOG_WARNING_ONCE("State object created with flag "
                                          "D3D12_STATE_OBJECT_FLAG_ALLOW_LOCAL_DEPENDENCIES_ON_EXTERNAL_DEFINITIONS. "
                                          "Dependencies between state objects may not be fully supported.");
            }
            if ((subobject_decoder.state_object_config->GetPointer()->Flags &
                 D3D12_STATE_OBJECT_FLAG_ALLOW_EXTERNAL_DEPENDENCIES_ON_LOCAL_DEFINITIONS) != 0)
            {
                GFXRECON_LOG_WARNING_ONCE("State object created with flag "
                                          "D3D12_STATE_OBJECT_FLAG_ALLOW_EXTERNAL_DEPENDENCIES_ON_LOCAL_DEFINITIONS. "
                                          "Dependencies between state objects may not be fully supported.");
            }
        }
        else if (subobject_type == D3D12_STATE_SUBOBJECT_TYPE_DXIL_LIBRARY)
        {
            // TODO: DXIL libraries can also contain local root signature definitions as well as subobject associations.
            // That information should be parsed here as well to ensure correct LRS handling.
            GFXRECON_LOG_DEBUG_ONCE("A state object is being created with a DXIL library subobject. Some usages of "
                                    "DXIL library subobjects may not be fully supported by GFXR replay.");

            GFXRECON_ASSERT(subobject_decoder.dxil_library_desc != nullptr);
            auto dxil_lib_desc_decoder = subobject_decoder.dxil_library_desc;
            auto num_exports           = dxil_lib_desc_decoder->GetPointer()->NumExports;
            if (num_exports == 0)
            {
#if defined(GFXRECON_DXC_SUPPORT)
                // If D3D12_DXIL_LIBRARY_DESC::NumExports == 0, everything in the DXIL library is exported. Use
                // reflection to get the list of exported shader names.
                HRESULT                         hr;
                graphics::dx12::IDxcUtilsComPtr dxc_utils = nullptr;
                hr                                        = DxcCreateInstance(CLSID_DxcUtils, IID_PPV_ARGS(&dxc_utils));
                if (SUCCEEDED(hr))
                {
                    graphics::dx12::IDxcContainerReflectionComPtr dxc_container_reflection = nullptr;
                    DxcCreateInstance(CLSID_DxcContainerReflection, IID_PPV_ARGS(&dxc_container_reflection));
                    if (SUCCEEDED(hr))
                    {
                        // Create a DXC blob from the DXIL library's bytes.
                        graphics::dx12::IDxcBlobEncodingComPtr dxc_blob_encoding;
                        hr = dxc_utils->CreateBlobFromPinned(
                            dxil_lib_desc_decoder->GetPointer()->DXILLibrary.pShaderBytecode,
                            dxil_lib_desc_decoder->GetPointer()->DXILLibrary.BytecodeLength,
                            DXC_CP_ACP,
                            &dxc_blob_encoding);
                        if (SUCCEEDED(hr))
                        {
                            // Load the DXIL library blob into the container reflection object.
                            hr = dxc_container_reflection->Load(dxc_blob_encoding);
                            if (SUCCEEDED(hr))
                            {
                                // Get the DXIL library reflection object.
                                UINT32 dxil_part;
                                hr = dxc_container_reflection->FindFirstPartKind(DXC_PART_DXIL, &dxil_part);
                                if (SUCCEEDED(hr))
                                {
                                    graphics::dx12::ID3D12LibraryReflectionComPtr library_reflection;
                                    hr = dxc_container_reflection->GetPartReflection(dxil_part,
                                                                                     IID_PPV_ARGS(&library_reflection));
                                    if (SUCCEEDED(hr))
                                    {
                                        // Parse all exported function/shader names from the DXIL library.
                                        D3D12_LIBRARY_DESC library_desc;
                                        hr = library_reflection->GetDesc(&library_desc);
                                        if (SUCCEEDED(hr))
                                        {
                                            for (UINT i = 0; i < library_desc.FunctionCount; i++)
                                            {
                                                // The pointer returned by GetFunctionByIndex is owned by the
                                                // ID3D12LibraryReflection object and does not need to be memory managed
                                                // in this scope.
                                                ID3D12FunctionReflection* function_reflection =
                                                    library_reflection->GetFunctionByIndex(i);

                                                D3D12_FUNCTION_DESC function_desc;
                                                hr = function_reflection->GetDesc(&function_desc);
                                                if (SUCCEEDED(hr))
                                                {
                                                    // Export names are mangled so parse the unmangled name.
                                                    auto function_name = DemangleDxilExportName(function_desc.Name);
                                                    if (!function_name.empty())
                                                    {
                                                        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>>
                                                            converter;
                                                        export_names.insert(converter.from_bytes(function_name));
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (FAILED(hr))
                {
                    GFXRECON_LOG_WARNING("Failed to parse shader exports from the DXIL subobject. Shader ID to LRS "
                                         "associations may be incorrect.");
                }
#else  // GFXRECON_DXC_SUPPORT
                GFXRECON_LOG_WARNING_ONCE(
                    "GFXReconstruct was built without DirectX Shader Compiler support and cannot parse the exports "
                    "from DXIL_LIBRARY subobjects. This may lead to incorrect DXR behavior. To fix this, be sure that "
                    "the DXC depedency is successfully found during CMake project configuration.");
#endif // GFXRECON_DXC_SUPPORT
            }
            else
            {
                // Get the shader names specified explicitly in the D3D12_DXIL_LIBRARY_DESC.
                for (UINT j = 0; j < num_exports; ++j)
                {
                    export_names.insert(dxil_lib_desc_decoder->GetMetaStructPointer()
                                            ->pExports->GetMetaStructPointer()[j]
                                            .Name.GetPointer());
                }
            }
        }
        else if (subobject_type == D3D12_STATE_SUBOBJECT_TYPE_EXISTING_COLLECTION)
        {
            GFXRECON_ASSERT(subobject_decoder.existing_collection_desc != nullptr);
            auto existing_collection_desc_decoder = subobject_decoder.existing_collection_desc;
            auto existing_collection_object_info =
                get_object_info_func_(existing_collection_desc_decoder->GetMetaStructPointer()->pExistingCollection);
            GFXRECON_ASSERT(existing_collection_object_info != nullptr);
            auto existing_collection_extra_info = GetExtraInfo<D3D12StateObjectInfo>(existing_collection_object_info);
            existing_shader_id_lrs_map.insert(existing_collection_extra_info->shader_id_lrs_map.begin(),
                                              existing_collection_extra_info->shader_id_lrs_map.end());

            // Include LRS associations from the existing collection.
            for (auto& assocation : existing_collection_extra_info->export_name_lrs_map)
            {
                lrs_associations_map.insert(assocation);
            }

            auto num_exports = existing_collection_desc_decoder->GetPointer()->NumExports;
            if (num_exports == 0)
            {
                // Include all exports from the existing collection.
                for (auto& assocation : existing_collection_extra_info->export_name_lrs_map)
                {
                    export_names.insert(assocation.first);
                }
            }
            else
            {
                // Include the specified exports from the existing collection. Rename the export if ExportToRename !=
                // nullptr.
                for (UINT j = 0; j < num_exports; ++j)
                {
                    export_names.insert(existing_collection_desc_decoder->GetPointer()->pExports[j].Name);

                    if (existing_collection_desc_decoder->GetPointer()->pExports[j].ExportToRename != nullptr)
                    {
                        auto existing_association_iter = lrs_associations_map.find(
                            existing_collection_desc_decoder->GetPointer()->pExports[j].ExportToRename);
                        if (existing_association_iter != lrs_associations_map.end())
                        {
                            lrs_associations_map[existing_collection_desc_decoder->GetPointer()->pExports[j].Name] =
                                existing_association_iter->second;
                            lrs_associations_map.erase(existing_association_iter);
                        }
                    }
                }
            }
        }
        else if (subobject_type == D3D12_STATE_SUBOBJECT_TYPE_LOCAL_ROOT_SIGNATURE)
        {
            GFXRECON_ASSERT(subobject_decoder.local_root_signature != nullptr);
            auto local_root_signature_handle_id =
                subobject_decoder.local_root_signature->GetMetaStructPointer()->pLocalRootSignature;
            if (local_root_signature_handle_id != format::kNullHandleId)
            {
                local_root_signature_ids.push_back(local_root_signature_handle_id);
            }
            else
            {
                GFXRECON_LOG_ERROR("State object (id=%" PRIu64
                                   ") includes a local root signature subobject with a null handle ID.",
                                   state_object_id);
            }
        }
        else if (subobject_type == D3D12_STATE_SUBOBJECT_TYPE_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION)
        {
            GFXRECON_LOG_WARNING("CreateStateObject: DXIL subobject export associations are not currently "
                                 "supported. Shader ID to LRS associations may be incorrect.");
        }
        else if (subobject_type == D3D12_STATE_SUBOBJECT_TYPE_SUBOBJECT_TO_EXPORTS_ASSOCIATION)
        {
            auto& subobjects_exports_association_desc_decoder = subobject_decoder.subobject_to_exports_association;
            auto  local_root_signature_decoder = subobjects_exports_association_desc_decoder->GetMetaStructPointer()
                                                    ->pSubobjectToAssociate->GetMetaStructPointer()
                                                    ->local_root_signature;
            if ((local_root_signature_decoder != nullptr) && !(local_root_signature_decoder->IsNull()))
            {
                auto local_root_signature_id =
                    local_root_signature_decoder->GetMetaStructPointer()->pLocalRootSignature;
                auto num_exports = subobjects_exports_association_desc_decoder->GetPointer()->NumExports;
                if (num_exports == 0)
                {
                    if (explicit_default_local_root_signature_id != format::kNullHandleId)
                    {
                        GFXRECON_LOG_WARNING(
                            "Found multiple explicit default local root signatures in state object (id=%" PRIu64
                            "). Shader ID to LRS associations may be incorrect.",
                            state_object_id);
                    }
                    explicit_default_local_root_signature_id = local_root_signature_id;
                }
                else
                {
                    for (UINT j = 0; j < num_exports; ++j)
                    {
                        auto export_name = subobjects_exports_association_desc_decoder->GetMetaStructPointer()
                                               ->pExports.GetPointer()[j];
                        export_names.insert(export_name);
                        explicit_local_root_signature_associations[export_name] = local_root_signature_id;
                    }
                }
            }
        }
    }
}

QueueSyncEventInfo
Dx12ResourceValueMapper::CreateProcessProcessResourceMappingsSyncEvent(ProcessResourceMappingsArgs args)
{
    return QueueSyncEventInfo{ false, false, nullptr, 0, [this, captured_args = std::move(args)]() {
                                  ProcessResourceMappings(captured_args);
                              } };
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
