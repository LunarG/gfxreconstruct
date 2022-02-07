/*
** Copyright (c) 2022 LunarG, Inc.
** Copyright (c) 2022 Advanced Micro Devices, Inc. All rights reserved.
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

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

namespace /* anonymous */
{

template <typename T>
T* GetExtraInfo(const DxObjectInfo* info)
{
    if ((info != nullptr) && (info->extra_info != nullptr) && (info->extra_info->extra_info_type == T::kType))
    {
        return static_cast<T*>(info->extra_info.get());
    }

    GFXRECON_LOG_FATAL("%s object does not have an associated info structure", T::kObjectType);

    return nullptr;
}

} // namespace

void Dx12ResourceValueMapper::PostProcessCommandListReset(DxObjectInfo* command_list_object_info)
{
    // Clear tracked info.
    auto command_list_extra_info = GetExtraInfo<D3D12CommandListInfo>(command_list_object_info);
    command_list_extra_info->resource_value_info_map.clear();
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
                                              sizeof(D3D12_VERTEX_BUFFER_VIEW::BufferLocation) });
                byte_offset += sizeof(D3D12_VERTEX_BUFFER_VIEW);
                break;
            case D3D12_INDIRECT_ARGUMENT_TYPE_INDEX_BUFFER_VIEW:
                resource_value_infos.insert({ byte_offset + offsetof(D3D12_INDEX_BUFFER_VIEW, BufferLocation),
                                              ResourceValueType::kGpuVirtualAddress,
                                              sizeof(D3D12_INDEX_BUFFER_VIEW::BufferLocation) });
                byte_offset += sizeof(D3D12_INDEX_BUFFER_VIEW);
                break;
            case D3D12_INDIRECT_ARGUMENT_TYPE_CONSTANT:
                byte_offset += arg_desc.Constant.Num32BitValuesToSet * 4;
                break;
            case D3D12_INDIRECT_ARGUMENT_TYPE_CONSTANT_BUFFER_VIEW:
            case D3D12_INDIRECT_ARGUMENT_TYPE_SHADER_RESOURCE_VIEW:
            case D3D12_INDIRECT_ARGUMENT_TYPE_UNORDERED_ACCESS_VIEW:
                resource_value_infos.insert(
                    { byte_offset, ResourceValueType::kGpuVirtualAddress, sizeof(D3D12_GPU_VIRTUAL_ADDRESS) });
                byte_offset += sizeof(D3D12_GPU_VIRTUAL_ADDRESS);
                break;
            case D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH_RAYS:
                // TODO (GH# 416): Implement support for D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH_RAYS. Also validate that
                // byte_offset is updated correctly.
                GFXRECON_LOG_ERROR("Application is using unsupported indirect argument type: "
                                   "D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH_RAYS");
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

    auto& resource_value_infos = command_list_extra_info->resource_value_info_map[argument_buffer_object_info];

    // TODO (GH# 417): Support pCountBuffer argument.
    if ((count_buffer_object_info != nullptr) && (count_buffer_object_info->object != nullptr))
    {
        GFXRECON_LOG_WARNING_ONCE("The pCountBuffer argument for ExecuteIndirect is not currently supported. The "
                                  "contents of pArgumentBuffer may become corrupted.");
    }

    // Add resource value offsets to resource_value_infos based on the command signature's arguments.
    uint64_t command_byte_offset = argument_buffer_offset;
    for (UINT i = 0; i < max_command_count; ++i)
    {
        for (const auto& resource_value_info : command_signature_extra_info->resource_value_infos)
        {
            resource_value_infos.insert({ resource_value_info.offset + command_byte_offset, resource_value_info.type });
        }
        command_byte_offset += command_signature_extra_info->byte_stride;
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
