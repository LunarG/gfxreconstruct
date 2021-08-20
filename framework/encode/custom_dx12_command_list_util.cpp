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

#include "encode/custom_dx12_command_list_util.h"
#include "encode/dx12_object_wrapper_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

template <typename T>
void TrackObjectForCommandList(ID3D12GraphicsCommandListInfo* info,
                               D3D12GraphicsCommandObjectType type,
                               const T*                       object)
{
    if (object)
    {
        info->command_objects[type].insert(GetWrappedId(object));
    }
}

void Track_ID3D12GraphicsCommandList_ResourceBarrier(ID3D12GraphicsCommandList_Wrapper* wrapper,
                                                     UINT                               NumBarriers,
                                                     const D3D12_RESOURCE_BARRIER*      pBarriers)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if (pBarriers != nullptr)
    {
        for (UINT i = 0; i < NumBarriers; ++i)
        {
            switch (pBarriers[i].Type)
            {
                case D3D12_RESOURCE_BARRIER_TYPE_TRANSITION:
                {
                    TrackObjectForCommandList(info.get(),
                                              D3D12GraphicsCommandObjectType::ID3D12ResourceObject,
                                              pBarriers[i].Transition.pResource);
                    break;
                }
                case D3D12_RESOURCE_BARRIER_TYPE_ALIASING:
                {
                    TrackObjectForCommandList(info.get(),
                                              D3D12GraphicsCommandObjectType::ID3D12ResourceObject,
                                              pBarriers[i].Aliasing.pResourceBefore);
                    TrackObjectForCommandList(info.get(),
                                              D3D12GraphicsCommandObjectType::ID3D12ResourceObject,
                                              pBarriers[i].Aliasing.pResourceAfter);
                    break;
                }
                case D3D12_RESOURCE_BARRIER_TYPE_UAV:
                {
                    TrackObjectForCommandList(
                        info.get(), D3D12GraphicsCommandObjectType::ID3D12ResourceObject, pBarriers[i].UAV.pResource);
                    break;
                }
                default:
                    break;
            }
        }
    }
}

void Track_ID3D12GraphicsCommandList4_BeginRenderPass(ID3D12GraphicsCommandList_Wrapper*          wrapper,
                                                      UINT                                        NumRenderTargets,
                                                      const D3D12_RENDER_PASS_RENDER_TARGET_DESC* pRenderTargets,
                                                      const D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* pDepthStencil,
                                                      D3D12_RENDER_PASS_FLAGS                     Flags)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if (pRenderTargets != nullptr)
    {
        for (UINT i = 0; i < NumRenderTargets; ++i)
        {
            if (pRenderTargets[i].EndingAccess.Type == D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_RESOLVE)
            {
                TrackObjectForCommandList(info.get(),
                                          D3D12GraphicsCommandObjectType::ID3D12ResourceObject,
                                          pRenderTargets[i].EndingAccess.Resolve.pSrcResource);
                TrackObjectForCommandList(info.get(),
                                          D3D12GraphicsCommandObjectType::ID3D12ResourceObject,
                                          pRenderTargets[i].EndingAccess.Resolve.pDstResource);
            }
        }
    }
    if (pDepthStencil != nullptr)
    {
        if (pDepthStencil->DepthEndingAccess.Type == D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_RESOLVE)
        {
            TrackObjectForCommandList(info.get(),
                                      D3D12GraphicsCommandObjectType::ID3D12ResourceObject,
                                      pDepthStencil->DepthEndingAccess.Resolve.pSrcResource);
            TrackObjectForCommandList(info.get(),
                                      D3D12GraphicsCommandObjectType::ID3D12ResourceObject,
                                      pDepthStencil->DepthEndingAccess.Resolve.pDstResource);
        }

        if (pDepthStencil->StencilEndingAccess.Type == D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_RESOLVE)
        {
            TrackObjectForCommandList(info.get(),
                                      D3D12GraphicsCommandObjectType::ID3D12ResourceObject,
                                      pDepthStencil->StencilEndingAccess.Resolve.pSrcResource);
            TrackObjectForCommandList(info.get(),
                                      D3D12GraphicsCommandObjectType::ID3D12ResourceObject,
                                      pDepthStencil->StencilEndingAccess.Resolve.pDstResource);
        }
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
