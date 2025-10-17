/*
** Copyright (c) 2023 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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

#include "encode/d3d12_capture_manager.h"
#include "encode/dx12_rv_annotation_util.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void RvAnnotationUtil::AddRvAnnotation(D3D12_GPU_VIRTUAL_ADDRESS* result)
{
    if (result != nullptr)
    {
        auto manager = D3D12CaptureManager::Get();
        if (manager->IsAnnotated() == true)
        {
            uint64_t mask = manager->GetGPUVAMask();
            *result       = *result | (mask << (64 - kMaskSizeOfBits));
        }
    }
}

void RvAnnotationUtil::AddRvAnnotation(D3D12_GPU_DESCRIPTOR_HANDLE* result)
{
    if (result != nullptr)
    {
        auto manager = D3D12CaptureManager::Get();
        if (manager->IsAnnotated() == true)
        {
            if ((result->ptr & (~0x0ui64 << (64 - RvAnnotationUtil::kMaskSizeOfBits))) != 0x0)
            {
                GFXRECON_LOG_ERROR_ONCE("Insufficient bits available in GPU Descriptor Handle for RV annotation");
            }
            else
            {
                uint64_t mask = manager->GetDescriptorMask();
                result->ptr   = result->ptr | (mask << (64 - RvAnnotationUtil::kMaskSizeOfBits));
            }
        }
    }
}

void RvAnnotationUtil::AddRvAnnotation(void** result)
{
    if (result != nullptr)
    {
        static std::map<void*, graphics::Dx12ShaderIdentifier> annotated_shader_ids_;
        auto                                                   manager = D3D12CaptureManager::Get();
        if (*result != nullptr && (manager->IsAnnotated() == true))
        {
            if (((uint64_t*)*result)[3] != 0x0)
            {
                GFXRECON_LOG_ERROR("Insufficient bytes available in ShaderID for RV annotation");
            }
            else
            {
                constexpr graphics::Dx12ShaderIdentifier zero_id = { 0 };
                auto shader_id = graphics::PackDx12ShaderIdentifier((uint8_t*)*result);
                if (shader_id != zero_id)
                {
                    if (!annotated_shader_ids_.contains(*result))
                    {
                        uint64_t shader_id_mask = manager->GetShaderIDMask();
                        memcpy(shader_id.data() + D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES - sizeof(shader_id_mask),
                               &shader_id_mask,
                               sizeof(shader_id_mask));
                        annotated_shader_ids_[*result] = shader_id;
                    }
                    *result = annotated_shader_ids_[*result].data();
                }
            }
        }
    }
}

void RvAnnotationUtil::RemoveRvAnnotation(D3D12_GPU_VIRTUAL_ADDRESS& value)
{
    auto manager = D3D12CaptureManager::Get();
    if ((value != 0x0) && (manager->IsAnnotated() == true))
    {
        value = value & (~0x0ui64 >> RvAnnotationUtil::kMaskSizeOfBits);
    }
}

void RvAnnotationUtil::RemoveRvAnnotation(D3D12_GPU_DESCRIPTOR_HANDLE& value)
{
    auto manager = D3D12CaptureManager::Get();
    if ((value.ptr != 0x0) && (manager->IsAnnotated() == true))
    {
        value.ptr = value.ptr & (~0x0ui64 >> RvAnnotationUtil::kMaskSizeOfBits);
    }
}

void RvAnnotationUtil::RemoveStructRvAnnotation(D3D12_GPU_VIRTUAL_ADDRESS& param)
{
    RemoveRvAnnotation(param);
}

void RvAnnotationUtil::RemoveStructRvAnnotation(D3D12_INDEX_BUFFER_VIEW& param)
{
    RemoveRvAnnotation(param.BufferLocation);
}

void RvAnnotationUtil::RemoveStructRvAnnotation(D3D12_VERTEX_BUFFER_VIEW& param)
{
    RemoveRvAnnotation(param.BufferLocation);
}

void RvAnnotationUtil::RemoveStructRvAnnotation(D3D12_STREAM_OUTPUT_BUFFER_VIEW& param)
{
    RemoveRvAnnotation(param.BufferLocation);
}

void RvAnnotationUtil::RemoveStructRvAnnotation(D3D12_CONSTANT_BUFFER_VIEW_DESC& param)
{
    RemoveRvAnnotation(param.BufferLocation);
}

void RvAnnotationUtil::RemoveStructRvAnnotation(D3D12_SHADER_RESOURCE_VIEW_DESC& param)
{
    if (param.ViewDimension == D3D12_SRV_DIMENSION::D3D12_SRV_DIMENSION_RAYTRACING_ACCELERATION_STRUCTURE)
    {
        RemoveRvAnnotation(param.RaytracingAccelerationStructure.Location);
    }
}

void RvAnnotationUtil::RemoveStructRvAnnotation(D3D12_WRITEBUFFERIMMEDIATE_PARAMETER& param)
{
    RemoveRvAnnotation(param.Dest);
}

void RvAnnotationUtil::RemoveStructRvAnnotation(D3D12_DISPATCH_RAYS_DESC& param)
{
    RemoveRvAnnotation(param.RayGenerationShaderRecord.StartAddress);
    RemoveRvAnnotation(param.MissShaderTable.StartAddress);
    RemoveRvAnnotation(param.HitGroupTable.StartAddress);
    RemoveRvAnnotation(param.CallableShaderTable.StartAddress);
}

void RvAnnotationUtil::RemoveStructRvAnnotation(D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC& param)
{
    RemoveRvAnnotation(param.DestBuffer);
}

void RvAnnotationUtil::RemoveStructRvAnnotation(D3D12_RAYTRACING_GEOMETRY_DESC& param)
{
    if (param.Type == D3D12_RAYTRACING_GEOMETRY_TYPE::D3D12_RAYTRACING_GEOMETRY_TYPE_TRIANGLES)
    {
        RemoveRvAnnotation(param.Triangles.Transform3x4);
        RemoveRvAnnotation(param.Triangles.IndexBuffer);
        RemoveRvAnnotation(param.Triangles.VertexBuffer.StartAddress);
    }
    else if (param.Type == D3D12_RAYTRACING_GEOMETRY_TYPE::D3D12_RAYTRACING_GEOMETRY_TYPE_PROCEDURAL_PRIMITIVE_AABBS)
    {
        RemoveRvAnnotation(param.AABBs.AABBs.StartAddress);
    }
}

void RvAnnotationUtil::RemoveStructRvAnnotation(D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS& param,
                                                std::unique_ptr<D3D12_RAYTRACING_GEOMETRY_DESC[]>&    geometry_descs)
{
    if (param.Type ==
        D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE::D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL)
    {
        RemoveRvAnnotation(param.InstanceDescs);
    }
    else
    {
        if (param.DescsLayout == D3D12_ELEMENTS_LAYOUT::D3D12_ELEMENTS_LAYOUT_ARRAY)
        {
            geometry_descs       = RemoveStructArrayRvAnnotations(param.pGeometryDescs, param.NumDescs);
            param.pGeometryDescs = geometry_descs.get();
        }
        else if (param.DescsLayout == D3D12_ELEMENTS_LAYOUT::D3D12_ELEMENTS_LAYOUT_ARRAY_OF_POINTERS)
        {
            geometry_descs = std::make_unique<D3D12_RAYTRACING_GEOMETRY_DESC[]>(param.NumDescs);
            for (UINT i = 0; i < param.NumDescs; ++i)
            {
                geometry_descs[i] = *param.ppGeometryDescs[i];
                RemoveStructRvAnnotation(geometry_descs[i]);
            }

            // Switch to D3D12_ELEMENTS_LAYOUT_ARRAY instead of allocating an extra array of
            // D3D12_RAYTRACING_GEOMETRY_DESC*. pGeometryDescs is a union with ppGeometryDescs, so don't set
            // ppGeometryDescs = nullptr;
            param.DescsLayout    = D3D12_ELEMENTS_LAYOUT::D3D12_ELEMENTS_LAYOUT_ARRAY;
            param.pGeometryDescs = geometry_descs.get();
        }
    }
}

void RvAnnotationUtil::RemoveStructRvAnnotation(D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC& param,
                                                std::unique_ptr<D3D12_RAYTRACING_GEOMETRY_DESC[]>&  geometry_desc)
{
    RemoveRvAnnotation(param.DestAccelerationStructureData);
    RemoveRvAnnotation(param.ScratchAccelerationStructureData);
    RemoveRvAnnotation(param.SourceAccelerationStructureData);
    RemoveStructRvAnnotation(param.Inputs, geometry_desc);
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
