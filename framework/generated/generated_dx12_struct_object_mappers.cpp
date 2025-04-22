/*
** Copyright (c) 2021-2023 LunarG, Inc.
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

/*
** This file is generated from dx12_struct_object_mappers_body_generator.py.
**
*/

#include "generated/generated_dx12_struct_object_mappers.h"

#include "decode/custom_dx12_struct_decoders.h"
#include "decode/custom_dx12_struct_object_mappers.h"
#include "decode/handle_pointer_decoder.h"
#include "decode/dx12_object_mapping_util.h"
#include "generated/generated_dx12_struct_decoders.h"

#include <algorithm>
#include <cassert>

#include <dxgiformat.h>
#include <d3d12.h>
#include <d3dcommon.h>
#include <d3d12sdklayers.h>
#include <d3d11.h>
#include <d3d11_1.h>
#include <d3d11_2.h>
#include <d3d11_3.h>
#include <d3d11_4.h>
#include <d3d11on12.h>
#include <dxgi.h>
#include <dxgi1_2.h>
#include <dxgi1_3.h>
#include <dxgi1_4.h>
#include <dxgi1_5.h>
#include <dxgi1_6.h>
#include <dxgicommon.h>
#include <dxgitype.h>
#include <Unknwnbase.h>
#include <guiddef.h>
#include <windef.h>
#include <minwinbase.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void MapStructObjects(Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_GRAPHICS_PIPELINE_STATE_DESC* value = wrapper->decoded_value;

        value->pRootSignature = object_mapping::MapObject<ID3D12RootSignature>(wrapper->pRootSignature, object_info_table);
    }
}

void MapStructObjects(Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_COMPUTE_PIPELINE_STATE_DESC* value = wrapper->decoded_value;

        value->pRootSignature = object_mapping::MapObject<ID3D12RootSignature>(wrapper->pRootSignature, object_info_table);
    }
}

void MapStructObjects(Decoded_D3D12_RESOURCE_TRANSITION_BARRIER* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_RESOURCE_TRANSITION_BARRIER* value = wrapper->decoded_value;

        value->pResource = object_mapping::MapObject<ID3D12Resource>(wrapper->pResource, object_info_table);
    }
}

void MapStructObjects(Decoded_D3D12_RESOURCE_ALIASING_BARRIER* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_RESOURCE_ALIASING_BARRIER* value = wrapper->decoded_value;

        value->pResourceBefore = object_mapping::MapObject<ID3D12Resource>(wrapper->pResourceBefore, object_info_table);

        value->pResourceAfter = object_mapping::MapObject<ID3D12Resource>(wrapper->pResourceAfter, object_info_table);
    }
}

void MapStructObjects(Decoded_D3D12_RESOURCE_UAV_BARRIER* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_RESOURCE_UAV_BARRIER* value = wrapper->decoded_value;

        value->pResource = object_mapping::MapObject<ID3D12Resource>(wrapper->pResource, object_info_table);
    }
}

void MapStructObjects(Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV* value = wrapper->decoded_value;

        object_mapping::MapGpuVirtualAddress(value->Location, gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_CONSTANT_BUFFER_VIEW_DESC* value = wrapper->decoded_value;

        object_mapping::MapGpuVirtualAddress(value->BufferLocation, gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_STREAM_OUTPUT_BUFFER_VIEW* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_STREAM_OUTPUT_BUFFER_VIEW* value = wrapper->decoded_value;

        object_mapping::MapGpuVirtualAddress(value->BufferLocation, gpu_va_map);

        object_mapping::MapGpuVirtualAddress(value->BufferFilledSizeLocation, gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_VERTEX_BUFFER_VIEW* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_VERTEX_BUFFER_VIEW* value = wrapper->decoded_value;

        object_mapping::MapGpuVirtualAddress(value->BufferLocation, gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_INDEX_BUFFER_VIEW* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_INDEX_BUFFER_VIEW* value = wrapper->decoded_value;

        object_mapping::MapGpuVirtualAddress(value->BufferLocation, gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_WRITEBUFFERIMMEDIATE_PARAMETER* value = wrapper->decoded_value;

        object_mapping::MapGpuVirtualAddress(value->Dest, gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_GLOBAL_ROOT_SIGNATURE* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_GLOBAL_ROOT_SIGNATURE* value = wrapper->decoded_value;

        value->pGlobalRootSignature = object_mapping::MapObject<ID3D12RootSignature>(wrapper->pGlobalRootSignature, object_info_table);
    }
}

void MapStructObjects(Decoded_D3D12_LOCAL_ROOT_SIGNATURE* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_LOCAL_ROOT_SIGNATURE* value = wrapper->decoded_value;

        value->pLocalRootSignature = object_mapping::MapObject<ID3D12RootSignature>(wrapper->pLocalRootSignature, object_info_table);
    }
}

void MapStructObjects(Decoded_D3D12_EXISTING_COLLECTION_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_EXISTING_COLLECTION_DESC* value = wrapper->decoded_value;

        value->pExistingCollection = object_mapping::MapObject<ID3D12StateObject>(wrapper->pExistingCollection, object_info_table);
    }
}

void MapStructObjects(Decoded_D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE* value = wrapper->decoded_value;

        object_mapping::MapGpuVirtualAddress(value->StartAddress, gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_GPU_VIRTUAL_ADDRESS_RANGE* value = wrapper->decoded_value;

        object_mapping::MapGpuVirtualAddress(value->StartAddress, gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE* value = wrapper->decoded_value;

        object_mapping::MapGpuVirtualAddress(value->StartAddress, gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC* value = wrapper->decoded_value;

        object_mapping::MapGpuVirtualAddress(value->Transform3x4, gpu_va_map);

        object_mapping::MapGpuVirtualAddress(value->IndexBuffer, gpu_va_map);

        MapStructObjects(wrapper->VertexBuffer, object_info_table, gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_RAYTRACING_GEOMETRY_AABBS_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if (wrapper != nullptr)
    {
        MapStructObjects(wrapper->AABBs, object_info_table, gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* value = wrapper->decoded_value;

        object_mapping::MapGpuVirtualAddress(value->DestBuffer, gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_RAYTRACING_INSTANCE_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_RAYTRACING_INSTANCE_DESC* value = wrapper->decoded_value;

        object_mapping::MapGpuVirtualAddress(value->AccelerationStructure, gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC* value = wrapper->decoded_value;

        object_mapping::MapGpuVirtualAddress(value->DestAccelerationStructureData, gpu_va_map);

        MapStructObjects(wrapper->Inputs, object_info_table, gpu_va_map);

        object_mapping::MapGpuVirtualAddress(value->SourceAccelerationStructureData, gpu_va_map);

        object_mapping::MapGpuVirtualAddress(value->ScratchAccelerationStructureData, gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_AUTO_BREADCRUMB_NODE* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_AUTO_BREADCRUMB_NODE* value = wrapper->decoded_value;

        value->pCommandList = object_mapping::MapObject<ID3D12GraphicsCommandList>(wrapper->pCommandList, object_info_table);

        value->pCommandQueue = object_mapping::MapObject<ID3D12CommandQueue>(wrapper->pCommandQueue, object_info_table);

        MapStructArrayObjects<Decoded_D3D12_AUTO_BREADCRUMB_NODE>(wrapper->pNext->GetMetaStructPointer(), 1, object_info_table, gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_AUTO_BREADCRUMB_NODE1* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_AUTO_BREADCRUMB_NODE1* value = wrapper->decoded_value;

        value->pCommandList = object_mapping::MapObject<ID3D12GraphicsCommandList>(wrapper->pCommandList, object_info_table);

        value->pCommandQueue = object_mapping::MapObject<ID3D12CommandQueue>(wrapper->pCommandQueue, object_info_table);

        MapStructArrayObjects<Decoded_D3D12_AUTO_BREADCRUMB_NODE1>(wrapper->pNext->GetMetaStructPointer(), 1, object_info_table, gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_DRED_ALLOCATION_NODE1* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_DRED_ALLOCATION_NODE1* value = wrapper->decoded_value;

        value->pObject = object_mapping::MapObject<IUnknown>(wrapper->pObject, object_info_table);

        MapStructArrayObjects<Decoded_D3D12_DRED_ALLOCATION_NODE1>(wrapper->pNext->GetMetaStructPointer(), 1, object_info_table, gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_DRED_PAGE_FAULT_OUTPUT* value = wrapper->decoded_value;

        object_mapping::MapGpuVirtualAddress(value->PageFaultVA, gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_DRED_PAGE_FAULT_OUTPUT1* value = wrapper->decoded_value;

        object_mapping::MapGpuVirtualAddress(value->PageFaultVA, gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT2* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_DRED_PAGE_FAULT_OUTPUT2* value = wrapper->decoded_value;

        object_mapping::MapGpuVirtualAddress(value->PageFaultVA, gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA1* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if (wrapper != nullptr)
    {
        MapStructObjects(wrapper->PageFaultOutput, object_info_table, gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA2* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if (wrapper != nullptr)
    {
        MapStructObjects(wrapper->PageFaultOutput, object_info_table, gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA3* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if (wrapper != nullptr)
    {
        MapStructObjects(wrapper->PageFaultOutput, object_info_table, gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS* value = wrapper->decoded_value;

        value->pSrcResource = object_mapping::MapObject<ID3D12Resource>(wrapper->pSrcResource, object_info_table);

        value->pDstResource = object_mapping::MapObject<ID3D12Resource>(wrapper->pDstResource, object_info_table);
    }
}

void MapStructObjects(Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if (wrapper != nullptr)
    {
        MapStructObjects(wrapper->cpuDescriptor, object_info_table, gpu_va_map);

        MapStructObjects(wrapper->EndingAccess, object_info_table, gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if (wrapper != nullptr)
    {
        MapStructObjects(wrapper->cpuDescriptor, object_info_table, gpu_va_map);

        MapStructObjects(wrapper->DepthEndingAccess, object_info_table, gpu_va_map);

        MapStructObjects(wrapper->StencilEndingAccess, object_info_table, gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_DISPATCH_RAYS_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if (wrapper != nullptr)
    {
        MapStructObjects(wrapper->RayGenerationShaderRecord, object_info_table, gpu_va_map);

        MapStructObjects(wrapper->MissShaderTable, object_info_table, gpu_va_map);

        MapStructObjects(wrapper->HitGroupTable, object_info_table, gpu_va_map);

        MapStructObjects(wrapper->CallableShaderTable, object_info_table, gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_SET_WORK_GRAPH_DESC* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if (wrapper != nullptr)
    {
        MapStructObjects(wrapper->BackingMemory, object_info_table, gpu_va_map);

        MapStructObjects(wrapper->NodeLocalRootArgumentsTable, object_info_table, gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_NODE_GPU_INPUT* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if (wrapper != nullptr)
    {
        MapStructObjects(wrapper->Records, object_info_table, gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_MULTI_NODE_GPU_INPUT* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if (wrapper != nullptr)
    {
        MapStructObjects(wrapper->NodeInputs, object_info_table, gpu_va_map);
    }
}

void MapStructObjects(Decoded_D3D12_TEXTURE_BARRIER* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_TEXTURE_BARRIER* value = wrapper->decoded_value;

        value->pResource = object_mapping::MapObject<ID3D12Resource>(wrapper->pResource, object_info_table);
    }
}

void MapStructObjects(Decoded_D3D12_BUFFER_BARRIER* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D12_BUFFER_BARRIER* value = wrapper->decoded_value;

        value->pResource = object_mapping::MapObject<ID3D12Resource>(wrapper->pResource, object_info_table);
    }
}

void MapStructObjects(Decoded_D3D11_VIDEO_DECODER_EXTENSION* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D11_VIDEO_DECODER_EXTENSION* value = wrapper->decoded_value;

        value->ppResourceList = object_mapping::MapObjectArray<ID3D11Resource>(&wrapper->ppResourceList, object_info_table);
    }
}

void MapStructObjects(Decoded_D3D11_VIDEO_PROCESSOR_STREAM* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D11_VIDEO_PROCESSOR_STREAM* value = wrapper->decoded_value;

        value->ppPastSurfaces = object_mapping::MapObjectArray<ID3D11VideoProcessorInputView>(&wrapper->ppPastSurfaces, object_info_table);

        value->pInputSurface = object_mapping::MapObject<ID3D11VideoProcessorInputView>(wrapper->pInputSurface, object_info_table);

        value->ppFutureSurfaces = object_mapping::MapObjectArray<ID3D11VideoProcessorInputView>(&wrapper->ppFutureSurfaces, object_info_table);

        value->ppPastSurfacesRight = object_mapping::MapObjectArray<ID3D11VideoProcessorInputView>(&wrapper->ppPastSurfacesRight, object_info_table);

        value->pInputSurfaceRight = object_mapping::MapObject<ID3D11VideoProcessorInputView>(wrapper->pInputSurfaceRight, object_info_table);

        value->ppFutureSurfacesRight = object_mapping::MapObjectArray<ID3D11VideoProcessorInputView>(&wrapper->ppFutureSurfacesRight, object_info_table);
    }
}

void MapStructObjects(Decoded_D3D11_VIDEO_DECODER_BEGIN_FRAME_CRYPTO_SESSION* wrapper, const Dx12ObjectInfoTable& object_info_table, const graphics::Dx12GpuVaMap& gpu_va_map)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        D3D11_VIDEO_DECODER_BEGIN_FRAME_CRYPTO_SESSION* value = wrapper->decoded_value;

        value->pCryptoSession = object_mapping::MapObject<ID3D11CryptoSession>(wrapper->pCryptoSession, object_info_table);
    }
}
void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC>* capture_value, const D3D12_GRAPHICS_PIPELINE_STATE_DESC* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pRootSignature && new_value->pRootSignature)
    {
        object_mapping::AddObject(&decoded_struct->pRootSignature, const_cast<ID3D12RootSignature**>(&new_value->pRootSignature), &object_info_table);
    }
}

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC>* capture_value, const D3D12_COMPUTE_PIPELINE_STATE_DESC* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pRootSignature && new_value->pRootSignature)
    {
        object_mapping::AddObject(&decoded_struct->pRootSignature, const_cast<ID3D12RootSignature**>(&new_value->pRootSignature), &object_info_table);
    }
}

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_RESOURCE_TRANSITION_BARRIER>* capture_value, const D3D12_RESOURCE_TRANSITION_BARRIER* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pResource && new_value->pResource)
    {
        object_mapping::AddObject(&decoded_struct->pResource, const_cast<ID3D12Resource**>(&new_value->pResource), &object_info_table);
    }
}

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_RESOURCE_ALIASING_BARRIER>* capture_value, const D3D12_RESOURCE_ALIASING_BARRIER* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pResourceBefore && new_value->pResourceBefore)
    {
        object_mapping::AddObject(&decoded_struct->pResourceBefore, const_cast<ID3D12Resource**>(&new_value->pResourceBefore), &object_info_table);
    }
    if(decoded_struct->pResourceAfter && new_value->pResourceAfter)
    {
        object_mapping::AddObject(&decoded_struct->pResourceAfter, const_cast<ID3D12Resource**>(&new_value->pResourceAfter), &object_info_table);
    }
}

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_RESOURCE_UAV_BARRIER>* capture_value, const D3D12_RESOURCE_UAV_BARRIER* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pResource && new_value->pResource)
    {
        object_mapping::AddObject(&decoded_struct->pResource, const_cast<ID3D12Resource**>(&new_value->pResource), &object_info_table);
    }
}

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_GLOBAL_ROOT_SIGNATURE>* capture_value, const D3D12_GLOBAL_ROOT_SIGNATURE* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pGlobalRootSignature && new_value->pGlobalRootSignature)
    {
        object_mapping::AddObject(&decoded_struct->pGlobalRootSignature, const_cast<ID3D12RootSignature**>(&new_value->pGlobalRootSignature), &object_info_table);
    }
}

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_LOCAL_ROOT_SIGNATURE>* capture_value, const D3D12_LOCAL_ROOT_SIGNATURE* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pLocalRootSignature && new_value->pLocalRootSignature)
    {
        object_mapping::AddObject(&decoded_struct->pLocalRootSignature, const_cast<ID3D12RootSignature**>(&new_value->pLocalRootSignature), &object_info_table);
    }
}

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_EXISTING_COLLECTION_DESC>* capture_value, const D3D12_EXISTING_COLLECTION_DESC* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pExistingCollection && new_value->pExistingCollection)
    {
        object_mapping::AddObject(&decoded_struct->pExistingCollection, const_cast<ID3D12StateObject**>(&new_value->pExistingCollection), &object_info_table);
    }
}

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_AUTO_BREADCRUMB_NODE>* capture_value, const D3D12_AUTO_BREADCRUMB_NODE* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pCommandList && new_value->pCommandList)
    {
        object_mapping::AddObject(&decoded_struct->pCommandList, const_cast<ID3D12GraphicsCommandList**>(&new_value->pCommandList), &object_info_table);
    }
    if(decoded_struct->pCommandQueue && new_value->pCommandQueue)
    {
        object_mapping::AddObject(&decoded_struct->pCommandQueue, const_cast<ID3D12CommandQueue**>(&new_value->pCommandQueue), &object_info_table);
    }
}

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_AUTO_BREADCRUMB_NODE1>* capture_value, const D3D12_AUTO_BREADCRUMB_NODE1* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pCommandList && new_value->pCommandList)
    {
        object_mapping::AddObject(&decoded_struct->pCommandList, const_cast<ID3D12GraphicsCommandList**>(&new_value->pCommandList), &object_info_table);
    }
    if(decoded_struct->pCommandQueue && new_value->pCommandQueue)
    {
        object_mapping::AddObject(&decoded_struct->pCommandQueue, const_cast<ID3D12CommandQueue**>(&new_value->pCommandQueue), &object_info_table);
    }
}

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA>* capture_value, const D3D12_DEVICE_REMOVED_EXTENDED_DATA* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pHeadAutoBreadcrumbNode && new_value->pHeadAutoBreadcrumbNode)
    {
        AddStructObjects(decoded_struct->pHeadAutoBreadcrumbNode, new_value->pHeadAutoBreadcrumbNode, object_info_table);
    }
}

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_DRED_ALLOCATION_NODE1>* capture_value, const D3D12_DRED_ALLOCATION_NODE1* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pObject && new_value->pObject)
    {
        object_mapping::AddObject(&decoded_struct->pObject, const_cast<IUnknown**>(&new_value->pObject), &object_info_table);
    }
}

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT>* capture_value, const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pHeadAutoBreadcrumbNode && new_value->pHeadAutoBreadcrumbNode)
    {
        AddStructObjects(decoded_struct->pHeadAutoBreadcrumbNode, new_value->pHeadAutoBreadcrumbNode, object_info_table);
    }
}

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1>* capture_value, const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pHeadAutoBreadcrumbNode && new_value->pHeadAutoBreadcrumbNode)
    {
        AddStructObjects(decoded_struct->pHeadAutoBreadcrumbNode, new_value->pHeadAutoBreadcrumbNode, object_info_table);
    }
}

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1>* capture_value, const D3D12_DRED_PAGE_FAULT_OUTPUT1* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pHeadExistingAllocationNode && new_value->pHeadExistingAllocationNode)
    {
        AddStructObjects(decoded_struct->pHeadExistingAllocationNode, new_value->pHeadExistingAllocationNode, object_info_table);
    }
    if(decoded_struct->pHeadRecentFreedAllocationNode && new_value->pHeadRecentFreedAllocationNode)
    {
        AddStructObjects(decoded_struct->pHeadRecentFreedAllocationNode, new_value->pHeadRecentFreedAllocationNode, object_info_table);
    }
}

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT2>* capture_value, const D3D12_DRED_PAGE_FAULT_OUTPUT2* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pHeadExistingAllocationNode && new_value->pHeadExistingAllocationNode)
    {
        AddStructObjects(decoded_struct->pHeadExistingAllocationNode, new_value->pHeadExistingAllocationNode, object_info_table);
    }
    if(decoded_struct->pHeadRecentFreedAllocationNode && new_value->pHeadRecentFreedAllocationNode)
    {
        AddStructObjects(decoded_struct->pHeadRecentFreedAllocationNode, new_value->pHeadRecentFreedAllocationNode, object_info_table);
    }
}

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS>* capture_value, const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pSrcResource && new_value->pSrcResource)
    {
        object_mapping::AddObject(&decoded_struct->pSrcResource, const_cast<ID3D12Resource**>(&new_value->pSrcResource), &object_info_table);
    }
    if(decoded_struct->pDstResource && new_value->pDstResource)
    {
        object_mapping::AddObject(&decoded_struct->pDstResource, const_cast<ID3D12Resource**>(&new_value->pDstResource), &object_info_table);
    }
}

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_TEXTURE_BARRIER>* capture_value, const D3D12_TEXTURE_BARRIER* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pResource && new_value->pResource)
    {
        object_mapping::AddObject(&decoded_struct->pResource, const_cast<ID3D12Resource**>(&new_value->pResource), &object_info_table);
    }
}

void AddStructObjects(const StructPointerDecoder<Decoded_D3D12_BUFFER_BARRIER>* capture_value, const D3D12_BUFFER_BARRIER* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pResource && new_value->pResource)
    {
        object_mapping::AddObject(&decoded_struct->pResource, const_cast<ID3D12Resource**>(&new_value->pResource), &object_info_table);
    }
}

void AddStructObjects(const StructPointerDecoder<Decoded_D3D11_VIDEO_PROCESSOR_STREAM>* capture_value, const D3D11_VIDEO_PROCESSOR_STREAM* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pInputSurface && new_value->pInputSurface)
    {
        object_mapping::AddObject(&decoded_struct->pInputSurface, const_cast<ID3D11VideoProcessorInputView**>(&new_value->pInputSurface), &object_info_table);
    }
    if(decoded_struct->pInputSurfaceRight && new_value->pInputSurfaceRight)
    {
        object_mapping::AddObject(&decoded_struct->pInputSurfaceRight, const_cast<ID3D11VideoProcessorInputView**>(&new_value->pInputSurfaceRight), &object_info_table);
    }
}

void AddStructObjects(const StructPointerDecoder<Decoded_D3D11_VIDEO_DECODER_BEGIN_FRAME_CRYPTO_SESSION>* capture_value, const D3D11_VIDEO_DECODER_BEGIN_FRAME_CRYPTO_SESSION* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pCryptoSession && new_value->pCryptoSession)
    {
        object_mapping::AddObject(&decoded_struct->pCryptoSession, const_cast<ID3D11CryptoSession**>(&new_value->pCryptoSession), &object_info_table);
    }
}


GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
