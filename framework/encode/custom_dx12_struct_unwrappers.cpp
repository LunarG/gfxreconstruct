/*
** Copyright (c) 2021 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to
** deal in the Software without restriction, including without limitation the
** rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
** sell copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
** IN THE SOFTWARE.
*/

#include "encode/custom_dx12_struct_unwrappers.h"

#include "encode/dx12_object_wrapper_util.h"
#include "format/dx12_subobject_types.h"
#include "generated/generated_dx12_struct_unwrappers.h"
#include "generated/generated_dx12_wrappers.h"
#include "util/defines.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

DxDescriptorInfo* GetDescriptorInfo(size_t descriptor_ptr)
{
    DxDescriptorInfo* descriptor_info = nullptr;

    // The descriptor increment isn't required to be a multiple of sizeof(void*), so copy the address of the current
    // item instead of dereferencing a potentially unaligned address for assignment.
    util::platform::MemoryCopy(
        &descriptor_info, sizeof(descriptor_info), reinterpret_cast<void*>(descriptor_ptr), sizeof(descriptor_info));

    return descriptor_info;
}

void UnwrapStructObjects(D3D12_CPU_DESCRIPTOR_HANDLE* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value->ptr != 0)
    {
        DxDescriptorInfo* descriptor_info = GetDescriptorInfo(value->ptr);
        value->ptr                        = descriptor_info->cpu_address;
    }
}

void UnwrapStructObjects(D3D12_RESOURCE_BARRIER* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        switch (value->Type)
        {
            case D3D12_RESOURCE_BARRIER_TYPE_TRANSITION:
                UnwrapStructObjects(&value->Transition, unwrap_memory);
                break;
            case D3D12_RESOURCE_BARRIER_TYPE_ALIASING:
                UnwrapStructObjects(&value->Aliasing, unwrap_memory);
                break;
            case D3D12_RESOURCE_BARRIER_TYPE_UAV:
                UnwrapStructObjects(&value->UAV, unwrap_memory);
                break;
            default:
                break;
        }
    }
}

void UnwrapStructObjects(D3D12_TEXTURE_COPY_LOCATION* value, HandleUnwrapMemory* unwrap_memory)
{
    GFXRECON_UNREFERENCED_PARAMETER(unwrap_memory);

    if (value != nullptr)
    {
        value->pResource = encode::GetWrappedObject<ID3D12Resource>(value->pResource);
    }
}

void UnwrapStructObjects(D3D12_RENDER_PASS_ENDING_ACCESS* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        switch (value->Type)
        {
            case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_RESOLVE:
                UnwrapStructObjects(&value->Resolve, unwrap_memory);
            default:
                break;
        }
    }
}

void UnwrapStructObjects(D3D12_PIPELINE_STATE_STREAM_DESC* value, HandleUnwrapMemory* unwrap_memory)
{
    if ((value != nullptr) && (value->SizeInBytes > 0) && (value->pPipelineStateSubobjectStream != nullptr))
    {
        // Allocate memory for and copy the subobject stream prior to modifying its contents.
        auto start = reinterpret_cast<uint8_t*>(unwrap_memory->GetFilledBuffer(
            reinterpret_cast<uint8_t*>(value->pPipelineStateSubobjectStream), value->SizeInBytes));

        value->pPipelineStateSubobjectStream = start;

        size_t offset = 0;
        while (offset < value->SizeInBytes)
        {
            auto current = start + offset;
            auto type    = *reinterpret_cast<D3D12_PIPELINE_STATE_SUBOBJECT_TYPE*>(current);

            if (type == D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_ROOT_SIGNATURE)
            {
                // The only subobject in the stream that contains a handle to be unwrapped is the root signature
                // subobject, so we can unwrap it and then break from the loop.  There will only be one root signature
                // per-stream, so there is no need to continue processing the stream after it has been unwrapped.
                auto subobject   = reinterpret_cast<format::Dx12SignatureSubobject*>(current);
                subobject->value = encode::GetWrappedObject<ID3D12RootSignature>(subobject->value);
                offset += sizeof(*subobject);
                break;
            }

            // Only the root signature subobject requires object unwrapping.  The rest of the subobjects only require
            // an offset increment.
            switch (type)
            {
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_VS:
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_PS:
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DS:
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_HS:
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_GS:
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_CS:
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_AS:
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_MS:
                    offset += sizeof(format::Dx12ShaderBytecodeSubobject);
                    break;
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_STREAM_OUTPUT:
                    offset += sizeof(format::Dx12StreamOutputSubobject);
                    break;
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_BLEND:
                    offset += sizeof(format::Dx12BlendSubobject);
                    break;
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_SAMPLE_MASK:
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_NODE_MASK:
                    offset += sizeof(format::Dx12UIntSubobject);
                    break;
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_RASTERIZER:
                    offset += sizeof(format::Dx12RasterizerSubobject);
                    break;
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL:
                    offset += sizeof(format::Dx12DepthStencilSubobject);
                    break;
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_INPUT_LAYOUT:
                    offset += sizeof(format::Dx12InputLayoutSubobject);
                    break;
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_IB_STRIP_CUT_VALUE:
                    offset += sizeof(format::Dx12StripCutSubobject);
                    break;
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_PRIMITIVE_TOPOLOGY:
                    offset += sizeof(format::Dx12PrimitiveTopologySubobject);
                    break;
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_RENDER_TARGET_FORMATS:
                    offset += sizeof(format::Dx12RenderTargetFormatsSubobject);
                    break;
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL_FORMAT:
                    offset += sizeof(format::Dx12FormatSubobject);
                    break;
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_SAMPLE_DESC:
                    offset += sizeof(format::Dx12SampleDescSubobject);
                    break;
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_CACHED_PSO:
                    offset += sizeof(format::Dx12CachedPsoSubobject);
                    break;
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_FLAGS:
                    offset += sizeof(format::Dx12TypeFlagsSubobject);
                    break;
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL1:
                    offset += sizeof(format::Dx12DepthStencil1Subobject);
                    break;
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_VIEW_INSTANCING:
                    offset += sizeof(format::Dx12ViewInstancingSubobject);
                    break;
                default:
                    // Type is unrecognized.  Write an invalid enum value so the decoder know the data is incomplete,
                    // and log a warning.
                    offset = value->SizeInBytes;

                    GFXRECON_LOG_WARNING(
                        "A pipeline state subobject with unrecognized D3D12_PIPELINE_STATE_SUBOBJECT_TYPE = %d was "
                        "omitted from handle unwrapping, which may cause capture to fail.",
                        type);

                    break;
            }
        }
    }
}

void UnwrapStructObjects(D3D12_STATE_OBJECT_DESC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        auto unwrapped_structs = MakeUnwrapStructs(value->pSubobjects, value->NumSubobjects, unwrap_memory);

        for (UINT i = 0; i < value->NumSubobjects; ++i)
        {
            UnwrapStructObjects(&unwrapped_structs[i], unwrap_memory, value->pSubobjects, unwrapped_structs, i);
        }

        value->pSubobjects = unwrapped_structs;
    }
}

void UnwrapStructObjects(D3D12_STATE_SUBOBJECT*       value,
                         HandleUnwrapMemory*          unwrap_memory,
                         const D3D12_STATE_SUBOBJECT* wrapped_subobjects,
                         const D3D12_STATE_SUBOBJECT* unwrapped_subobjects,
                         UINT                         num_subobjects)
{
    if ((value != nullptr) && (value->pDesc != nullptr))
    {
        switch (value->Type)
        {
            case D3D12_STATE_SUBOBJECT_TYPE_STATE_OBJECT_CONFIG:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_GLOBAL_ROOT_SIGNATURE:
                value->pDesc = UnwrapStructPtrObjects(
                    reinterpret_cast<const D3D12_GLOBAL_ROOT_SIGNATURE*>(value->pDesc), unwrap_memory);
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_LOCAL_ROOT_SIGNATURE:
                value->pDesc = UnwrapStructPtrObjects(reinterpret_cast<const D3D12_LOCAL_ROOT_SIGNATURE*>(value->pDesc),
                                                      unwrap_memory);
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_NODE_MASK:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_DXIL_LIBRARY:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_EXISTING_COLLECTION:
                value->pDesc = UnwrapStructPtrObjects(
                    reinterpret_cast<const D3D12_EXISTING_COLLECTION_DESC*>(value->pDesc), unwrap_memory);
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_SUBOBJECT_TO_EXPORTS_ASSOCIATION:
            {
                auto unwrapped_struct = MakeUnwrapStructs(
                    reinterpret_cast<const D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION*>(value->pDesc), 1, unwrap_memory);
                UnwrapStructObjects(
                    unwrapped_struct, unwrap_memory, wrapped_subobjects, unwrapped_subobjects, num_subobjects);
                value->pDesc = unwrapped_struct;
                break;
            }
            case D3D12_STATE_SUBOBJECT_TYPE_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_SHADER_CONFIG:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_PIPELINE_CONFIG:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_HIT_GROUP:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_PIPELINE_CONFIG1:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_WORK_GRAPH:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_STREAM_OUTPUT:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_BLEND:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_SAMPLE_MASK:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_RASTERIZER:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_INPUT_LAYOUT:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_IB_STRIP_CUT_VALUE:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_PRIMITIVE_TOPOLOGY:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_RENDER_TARGET_FORMATS:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL_FORMAT:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_SAMPLE_DESC:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_FLAGS:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL1:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_VIEW_INSTANCING:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_GENERIC_PROGRAM:
            {
                auto unwrapped_struct = MakeUnwrapStructs(
                    reinterpret_cast<const D3D12_GENERIC_PROGRAM_DESC*>(value->pDesc), 1, unwrap_memory);
                UnwrapStructObjects(
                    unwrapped_struct, unwrap_memory, wrapped_subobjects, unwrapped_subobjects, num_subobjects);
                value->pDesc = unwrapped_struct;
                break;
            }
            case D3D12_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL2:
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_MAX_VALID:
                break;
            default:
                break;
        }
    }
}

void UnwrapStructObjects(D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION* value,
                         HandleUnwrapMemory*                     unwrap_memory,
                         const D3D12_STATE_SUBOBJECT*            wrapped_subobjects,
                         const D3D12_STATE_SUBOBJECT*            unwrapped_subobjects,
                         UINT                                    num_subobjects)
{
    if (value != nullptr)
    {
        // This may be a pointer to an existing subobject structure.
        for (UINT i = 0; i < num_subobjects; ++i)
        {
            if (value->pSubobjectToAssociate == &wrapped_subobjects[i])
            {
                value->pSubobjectToAssociate = &unwrapped_subobjects[i];
                return;
            }
        }

        // The subobject was not found in the list of existing subobjects, so fall back on standard unwrapping.
        auto unwrapped_struct = MakeUnwrapStructs(value->pSubobjectToAssociate, 1, unwrap_memory);
        UnwrapStructObjects(unwrapped_struct, unwrap_memory, wrapped_subobjects, unwrapped_subobjects, num_subobjects);
    }
}

void UnwrapStructObjects(D3D12_GENERIC_PROGRAM_DESC*  value,
                         HandleUnwrapMemory*          unwrap_memory,
                         const D3D12_STATE_SUBOBJECT* wrapped_subobjects,
                         const D3D12_STATE_SUBOBJECT* unwrapped_subobjects,
                         UINT                         num_subobjects)
{
    if (value != nullptr)
    {
        auto unwrapped_structs =
            const_cast<D3D12_STATE_SUBOBJECT**>(MakeUnwrapStructs(value->ppSubobjects, num_subobjects, unwrap_memory));

        for (UINT i = 0; i < num_subobjects; ++i)
        {
            UnwrapStructObjects(
                unwrapped_structs[i], unwrap_memory, &wrapped_subobjects[i], &unwrapped_subobjects[i], 1);
        }
    }
}

void UnwrapStructObjects(D3D12_BARRIER_GROUP* value, HandleUnwrapMemory* unwrap_memory)
{
    GFXRECON_UNREFERENCED_PARAMETER(unwrap_memory);

    if (value != nullptr)
    {
        for (UINT i = 0; i < value->NumBarriers; ++i)
        {
            switch (value->Type)
            {
                case D3D12_BARRIER_TYPE_TEXTURE:
                    UnwrapStructObjects(const_cast<D3D12_TEXTURE_BARRIER*>(&value->pTextureBarriers[i]), unwrap_memory);
                    break;
                case D3D12_BARRIER_TYPE_BUFFER:
                    UnwrapStructObjects(const_cast<D3D12_BUFFER_BARRIER*>(&value->pBufferBarriers[i]), unwrap_memory);
                    break;
                case D3D12_BARRIER_TYPE_GLOBAL:
                default:
                    break;
            }
        }
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
