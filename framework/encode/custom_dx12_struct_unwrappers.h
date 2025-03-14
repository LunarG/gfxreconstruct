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

#ifndef GFXRECON_ENCODE_CUSTOM_DX12_STRUCT_UNWRAPPERS_H
#define GFXRECON_ENCODE_CUSTOM_DX12_STRUCT_UNWRAPPERS_H

#include "encode/handle_unwrap_memory.h"
#include "encode/dx12_object_wrapper_info.h"
#include "util/defines.h"

#include <d3d12.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

DxDescriptorInfo* GetDescriptorInfo(size_t descriptor_ptr);

// Structs with descriptor handles.
void UnwrapStructObjects(D3D12_CPU_DESCRIPTOR_HANDLE* value, HandleUnwrapMemory* unwrap_memory);

// Structs with anonymous union members.
void UnwrapStructObjects(D3D12_RESOURCE_BARRIER* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructObjects(D3D12_TEXTURE_COPY_LOCATION* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructObjects(D3D12_RENDER_PASS_ENDING_ACCESS* value, HandleUnwrapMemory* unwrap_memory);

// Structs that require special handling.
void UnwrapStructObjects(D3D12_PIPELINE_STATE_STREAM_DESC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructObjects(D3D12_STATE_OBJECT_DESC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructObjects(D3D12_STATE_SUBOBJECT*       value,
                         HandleUnwrapMemory*          unwrap_memory,
                         const D3D12_STATE_SUBOBJECT* wrapped_subobjects,
                         const D3D12_STATE_SUBOBJECT* unwrapped_subobjects,
                         UINT                         num_subojects);

void UnwrapStructObjects(D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION* value,
                         HandleUnwrapMemory*                     unwrap_memory,
                         const D3D12_STATE_SUBOBJECT*            wrapped_subobjects,
                         const D3D12_STATE_SUBOBJECT*            unwrapped_subobjects,
                         UINT                                    num_subojects);

void UnwrapStructObjects(D3D12_GENERIC_PROGRAM_DESC*  value,
                         HandleUnwrapMemory*          unwrap_memory,
                         const D3D12_STATE_SUBOBJECT* wrapped_subobjects,
                         const D3D12_STATE_SUBOBJECT* unwrapped_subobjects,
                         UINT                         num_subojects);

void UnwrapStructObjects(D3D12_BARRIER_GROUP* value, HandleUnwrapMemory* unwrap_memory);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_CUSTOM_DX12_STRUCT_UNWRAPPERS_H
