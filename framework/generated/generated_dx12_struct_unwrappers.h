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
** This file is generated from dx12_struct_unwrappers_body_generator.py.
**
*/

#ifndef  GFXRECON_GENERATED_DX12_STRUCT_UNWRAPPERS_H
#define  GFXRECON_GENERATED_DX12_STRUCT_UNWRAPPERS_H

#include "encode/handle_unwrap_memory.h"
#include "util/defines.h"

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
GFXRECON_BEGIN_NAMESPACE(encode)

void UnwrapStructObjects(D3D12_GRAPHICS_PIPELINE_STATE_DESC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructObjects(D3D12_COMPUTE_PIPELINE_STATE_DESC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructObjects(D3D12_RESOURCE_TRANSITION_BARRIER* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructObjects(D3D12_RESOURCE_ALIASING_BARRIER* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructObjects(D3D12_RESOURCE_UAV_BARRIER* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructObjects(D3D12_GLOBAL_ROOT_SIGNATURE* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructObjects(D3D12_LOCAL_ROOT_SIGNATURE* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructObjects(D3D12_EXISTING_COLLECTION_DESC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructObjects(D3D12_AUTO_BREADCRUMB_NODE* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructObjects(D3D12_AUTO_BREADCRUMB_NODE1* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructObjects(D3D12_DRED_ALLOCATION_NODE1* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructObjects(D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructObjects(D3D12_RENDER_PASS_RENDER_TARGET_DESC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructObjects(D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructObjects(D3D12_TEXTURE_BARRIER* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructObjects(D3D12_BUFFER_BARRIER* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructObjects(D3D11_VIDEO_DECODER_EXTENSION* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructObjects(D3D11_VIDEO_PROCESSOR_STREAM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructObjects(D3D11_VIDEO_DECODER_BEGIN_FRAME_CRYPTO_SESSION* value, HandleUnwrapMemory* unwrap_memory);

template <typename T>
T* MakeUnwrapStructs(const T* values, size_t len, HandleUnwrapMemory* unwrap_memory)
{
    assert((values != nullptr) && (len > 0) && (unwrap_memory != nullptr));

    const uint8_t* bytes     = reinterpret_cast<const uint8_t*>(values);
    size_t         num_bytes = len * sizeof(T);

    return reinterpret_cast<T*>(unwrap_memory->GetFilledBuffer(bytes, num_bytes));
}

template <typename T>
const T* UnwrapStructPtrObjects(const T* value, HandleUnwrapMemory* unwrap_memory)
{
    T* unwrapped_struct = nullptr;

    if (value != nullptr)
    {
        unwrapped_struct = MakeUnwrapStructs(value, 1, unwrap_memory);
        UnwrapStructObjects(unwrapped_struct, unwrap_memory);
    }

    return unwrapped_struct;
}

template <typename T>
const T* UnwrapStructArrayObjects(const T* values, size_t len, HandleUnwrapMemory* unwrap_memory)
{
    if ((values != nullptr) && (len > 0))
    {
        auto unwrapped_structs = MakeUnwrapStructs(values, len, unwrap_memory);

        for (size_t i = 0; i < len; ++i)
        {
            UnwrapStructObjects(&unwrapped_structs[i], unwrap_memory);
        }

        return unwrapped_structs;
    }

    // Leave the original memory in place when the pointer is not null, but size is zero.
    return values;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
