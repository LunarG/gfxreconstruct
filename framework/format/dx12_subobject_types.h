/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
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

#ifndef GFXRECON_FORMAT_DX12_SUBOBJECT_TYPES_H
#define GFXRECON_FORMAT_DX12_SUBOBJECT_TYPES_H

#include "util/defines.h"

#ifdef WIN32
#include <d3d12.h>
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(format)

const EnumEncodeType kInvalidSubobjectType = 0xffffffff;

template <typename T>
struct alignas(void*) Dx12SubobjectType
{
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE type;
    T                                   value;
};

using Dx12UIntSubobject                = Dx12SubobjectType<UINT>;
using Dx12SignatureSubobject           = Dx12SubobjectType<ID3D12RootSignature*>;
using Dx12ShaderBytecodeSubobject      = Dx12SubobjectType<D3D12_SHADER_BYTECODE>;
using Dx12StreamOutputSubobject        = Dx12SubobjectType<D3D12_STREAM_OUTPUT_DESC>;
using Dx12BlendSubobject               = Dx12SubobjectType<D3D12_BLEND_DESC>;
using Dx12RasterizerSubobject          = Dx12SubobjectType<D3D12_RASTERIZER_DESC>;
using Dx12DepthStencilSubobject        = Dx12SubobjectType<D3D12_DEPTH_STENCIL_DESC>;
using Dx12InputLayoutSubobject         = Dx12SubobjectType<D3D12_INPUT_LAYOUT_DESC>;
using Dx12StripCutSubobject            = Dx12SubobjectType<D3D12_INDEX_BUFFER_STRIP_CUT_VALUE>;
using Dx12PrimitiveTopologySubobject   = Dx12SubobjectType<D3D12_PRIMITIVE_TOPOLOGY_TYPE>;
using Dx12RenderTargetFormatsSubobject = Dx12SubobjectType<D3D12_RT_FORMAT_ARRAY>;
using Dx12FormatSubobject              = Dx12SubobjectType<DXGI_FORMAT>;
using Dx12SampleDescSubobject          = Dx12SubobjectType<DXGI_SAMPLE_DESC>;
using Dx12CachedPsoSubobject           = Dx12SubobjectType<D3D12_CACHED_PIPELINE_STATE>;
using Dx12TypeFlagsSubobject           = Dx12SubobjectType<D3D12_PIPELINE_STATE_FLAGS>;
using Dx12DepthStencil1Subobject       = Dx12SubobjectType<D3D12_DEPTH_STENCIL_DESC1>;
using Dx12ViewInstancingSubobject      = Dx12SubobjectType<D3D12_VIEW_INSTANCING_DESC>;

GFXRECON_END_NAMESPACE(format)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_FORMAT_DX12_SUBOBJECT_TYPES_H
