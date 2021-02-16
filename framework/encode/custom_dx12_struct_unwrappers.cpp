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

/*
** This file is generated from dx12_struct_unwrappers_body_generator.py.
**
*/

#include "encode/custom_dx12_struct_unwrappers.h"

#include "encode/dx12_object_wrapper_util.h"
#include "generated/generated_dx12_struct_unwrappers.h"
#include "generated/generated_dx12_wrappers.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

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
    if (value != nullptr)
    {
        value->pResource = encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(value->pResource);
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
