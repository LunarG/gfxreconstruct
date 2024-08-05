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

#ifndef GFXRECON_ENCODE_CUSTOM_DX12_API_CALL_ENCODERS_H
#define GFXRECON_ENCODE_CUSTOM_DX12_API_CALL_ENCODERS_H

#include "encode/parameter_encoder.h"
#include "format/format.h"
#include "generated/generated_dx12_wrappers.h"
#include "util/defines.h"

#include <d3d12.h>
#include <dxgi1_5.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void Encode_ID3D12Device_CheckFeatureSupport(ID3D12Device_Wrapper* wrapper,
                                             HRESULT               result,
                                             D3D12_FEATURE         Feature,
                                             void*                 pFeatureSupportData,
                                             UINT                  FeatureSupportDataSize);

void Encode_IDXGIFactory5_CheckFeatureSupport(IDXGIFactory5_Wrapper* wrapper,
                                              HRESULT                result,
                                              DXGI_FEATURE           Feature,
                                              void*                  pFeatureSupportData,
                                              UINT                   FeatureSupportDataSize);

void Encode_ID3D12Resource_WriteToSubresource(ID3D12Resource_Wrapper* wrapper,
                                              HRESULT                 return_value,
                                              UINT                    DstSubresource,
                                              const D3D12_BOX*        pDstBox,
                                              const void*             pSrcData,
                                              UINT                    SrcRowPitch,
                                              UINT                    SrcDepthPitch);

void Encode_ID3D12CommandQueue_ExecuteCommandLists(ID3D12CommandQueue_Wrapper* wrapper,
                                                   UINT                        NumCommandLists,
                                                   ID3D12CommandList* const*   ppCommandLists);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_CUSTOM_DX12_API_CALL_ENCODERS_H
