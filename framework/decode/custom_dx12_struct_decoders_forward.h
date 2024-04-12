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

#ifndef GFXRECON_DECODE_CUSTOM_DX12_STRUCT_DECODERS_FORWARD_H
#define GFXRECON_DECODE_CUSTOM_DX12_STRUCT_DECODERS_FORWARD_H

#if defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)

#include "generated/generated_dx12_struct_decoders_forward.h"
#include "util/defines.h"

#ifndef WIN32
#include <cstddef>
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Descriptor handles.
struct Decoded_D3D12_CPU_DESCRIPTOR_HANDLE;

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_CPU_DESCRIPTOR_HANDLE* wrapper);

// Unions.
struct Decoded_D3D12_CLEAR_VALUE;
struct Decoded_D3D12_RESOURCE_BARRIER;
struct Decoded_D3D12_TEXTURE_COPY_LOCATION;
struct Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC;
struct Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC;
struct Decoded_D3D12_RENDER_TARGET_VIEW_DESC;
struct Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC;
struct Decoded_D3D12_ROOT_PARAMETER;
struct Decoded_D3D12_ROOT_PARAMETER1;
struct Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC;
struct Decoded_D3D12_INDIRECT_ARGUMENT_DESC;
struct Decoded_D3D12_RAYTRACING_GEOMETRY_DESC;
struct Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS;
struct Decoded_D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA;
struct Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS;
struct Decoded_D3D12_RENDER_PASS_ENDING_ACCESS;

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_CLEAR_VALUE* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RESOURCE_BARRIER* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEXTURE_COPY_LOCATION* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RENDER_TARGET_VIEW_DESC* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_ROOT_PARAMETER* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_ROOT_PARAMETER1* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_INDIRECT_ARGUMENT_DESC* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RAYTRACING_GEOMETRY_DESC* wrapper);
size_t DecodeStruct(const uint8_t*                                                buffer,
                    size_t                                                        buffer_size,
                    Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* wrapper);
size_t
       DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RENDER_PASS_ENDING_ACCESS* wrapper);

// Platform types.
struct Decoded_LARGE_INTEGER;

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_LARGE_INTEGER* wrapper);

// Types requiring special processing.
struct Decoded_D3D12_PIPELINE_STATE_STREAM_DESC;
struct Decoded_D3D12_STATE_OBJECT_DESC;
struct Decoded_D3D12_STATE_SUBOBJECT;
struct Decoded_D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION;
struct Decoded_D3D12_BARRIER_GROUP;
struct Decoded_D3D12_SAMPLER_DESC2;

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_PIPELINE_STATE_STREAM_DESC* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_STATE_OBJECT_DESC* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_STATE_SUBOBJECT* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_BARRIER_GROUP* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_SAMPLER_DESC2* wrapper);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)

#endif // GFXRECON_DECODE_CUSTOM_DX12_STRUCT_DECODERS_FORWARD_H
