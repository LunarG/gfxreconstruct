/*
** Copyright (c) 2021 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_CUSTOM_DX12_STRUCT_ENCODERS_H
#define GFXRECON_ENCODE_CUSTOM_DX12_STRUCT_ENCODERS_H

#include "encode/parameter_encoder.h"
#include "util/defines.h"

#ifdef WIN32
#include <d3d12.h>
#include <dxgi1_5.h>
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

// Descriptor handles.
void EncodeStruct(ParameterEncoder* encoder, const D3D12_CPU_DESCRIPTOR_HANDLE& result);

// Unions.
void EncodeStruct(ParameterEncoder* encoder, const D3D12_CLEAR_VALUE& value);
void EncodeStruct(ParameterEncoder* encoder, const D3D12_RESOURCE_BARRIER& value);
void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEXTURE_COPY_LOCATION& value);
void EncodeStruct(ParameterEncoder* encoder, const D3D12_SHADER_RESOURCE_VIEW_DESC& value);
void EncodeStruct(ParameterEncoder* encoder, const D3D12_UNORDERED_ACCESS_VIEW_DESC& value);
void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_TARGET_VIEW_DESC& value);
void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEPTH_STENCIL_VIEW_DESC& value);
void EncodeStruct(ParameterEncoder* encoder, const D3D12_ROOT_PARAMETER& value);
void EncodeStruct(ParameterEncoder* encoder, const D3D12_ROOT_PARAMETER1& value);
void EncodeStruct(ParameterEncoder* encoder, const D3D12_VERSIONED_ROOT_SIGNATURE_DESC& value);
void EncodeStruct(ParameterEncoder* encoder, const D3D12_INDIRECT_ARGUMENT_DESC& value);
void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_GEOMETRY_DESC& value);
void EncodeStruct(ParameterEncoder* encoder, const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS& value);
void EncodeStruct(ParameterEncoder* encoder, const D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA& value);
void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_PASS_BEGINNING_ACCESS& value);
void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_PASS_ENDING_ACCESS& value);

// Platform types.
void EncodeStruct(ParameterEncoder* encoder, const LARGE_INTEGER& value);

// Types requiring special processing.
void EncodeStruct(ParameterEncoder* encoder, const D3D12_PIPELINE_STATE_STREAM_DESC& value);
void EncodeStruct(ParameterEncoder* encoder, const D3D12_STATE_OBJECT_DESC& value);
void EncodeStruct(ParameterEncoder* encoder, const D3D12_STATE_SUBOBJECT& value);
void EncodeStruct(ParameterEncoder* encoder, const D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION& value);
void EncodeD3D12FeatureStruct(ParameterEncoder* encoder, void* feature_data, D3D12_FEATURE feature);
void EncodeDXGIFeatureStruct(ParameterEncoder* encoder, void* feature_data, DXGI_FEATURE feature);
void EncodeStruct(ParameterEncoder* encoder, const D3D12_BARRIER_GROUP& value);
void EncodeStruct(ParameterEncoder* encoder, const D3D12_SAMPLER_DESC2& value);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_CUSTOM_DX12_STRUCT_ENCODERS_H
