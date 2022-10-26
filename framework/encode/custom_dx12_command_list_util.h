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

#ifndef GFXRECON_ENCODE_CUSTOM_DX12_COMMAND_LIST_UTIL_H
#define GFXRECON_ENCODE_CUSTOM_DX12_COMMAND_LIST_UTIL_H

#include <dxgi.h>
#include <dxgi1_2.h>
#include <dxgi1_3.h>
#include <dxgi1_4.h>
#include <dxgi1_5.h>
#include <dxgi1_6.h>
#include <dxgicommon.h>
#include <dxgiformat.h>
#include <dxgitype.h>
#include <d3d12.h>
#include <d3dcommon.h>
#include <d3d12sdklayers.h>
#include <Unknwnbase.h>
#include <guiddef.h>
#include <windef.h>
#include <minwinbase.h>

#include "generated/generated_dx12_wrappers.h"

#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void Track_ID3D12GraphicsCommandList_ResourceBarrier(ID3D12CommandList_Wrapper*    wrapper,
                                                     UINT                          NumBarriers,
                                                     const D3D12_RESOURCE_BARRIER* pBarriers);

void Track_ID3D12GraphicsCommandList4_BeginRenderPass(ID3D12CommandList_Wrapper*                  wrapper,
                                                      UINT                                        NumRenderTargets,
                                                      const D3D12_RENDER_PASS_RENDER_TARGET_DESC* pRenderTargets,
                                                      const D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* pDepthStencil,
                                                      D3D12_RENDER_PASS_FLAGS                     Flags);

void Track_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure(
    ID3D12CommandList_Wrapper*                                         wrapper,
    const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC*          pDesc,
    UINT                                                               NumPostbuildInfoDescs,
    const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* pPostbuildInfoDescs);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_CUSTOM_DX12_COMMAND_LIST_UTIL_H
