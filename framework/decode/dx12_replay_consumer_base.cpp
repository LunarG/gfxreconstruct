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

#include "decode/dx12_replay_consumer_base.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void Dx12ReplayConsumerBase::RemoveObject(format::HandleId id)
{
    object_mapping::RemoveObject(id, &object_info_table_);
}

void Dx12ReplayConsumerBase::CheckReplayResult(const char* call_name, HRESULT capture_result, HRESULT replay_result)
{
    if (capture_result != replay_result)
    {
        GFXRECON_LOG_ERROR("%s returned %d, which does not match the value returned at capture",
                           call_name,
                           replay_result,
                           capture_result);
    }
}

void* Dx12ReplayConsumerBase::PreProcessExternalObject(uint64_t          object_id,
                                                       format::ApiCallId call_id,
                                                       const char*       call_name)
{
    void* object = nullptr;
    switch (call_id)
    {
        case format::ApiCallId::ApiCall_IDXGIFactory2_CreateSwapChainForHwnd:
            break;

        default:
            GFXRECON_LOG_WARNING("Skipping object handle mapping for unsupported external object type processed by %s",
                                 call_name);
            break;
    }
    return object;
}

void Dx12ReplayConsumerBase::PostProcessExternalObject(
    HRESULT replay_result, void* object, uint64_t* object_id, format::ApiCallId call_id, const char* call_name)
{
    GFXRECON_UNREFERENCED_PARAMETER(replay_result);
    GFXRECON_UNREFERENCED_PARAMETER(object_id);
    GFXRECON_UNREFERENCED_PARAMETER(object);

    switch (call_id)
    {
        case format::ApiCallId::ApiCall_IDXGISurface1_GetDC:
        case format::ApiCallId::ApiCall_IDXGIFactory_GetWindowAssociation:
        case format::ApiCallId::ApiCall_IDXGISwapChain1_GetHwnd:
            break;

        default:
            GFXRECON_LOG_WARNING("Skipping object handle mapping for unsupported external object type processed by %s",
                                 call_name);
            break;
    }
}

HRESULT Dx12ReplayConsumerBase::OverrideCreateSwapChainForHwnd(
    IDXGIFactory2*                                                 replay_object,
    HRESULT                                                        original_result,
    IUnknown*                                                      pDevice,
    uint64_t                                                       hWnd,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>*           pDesc,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC>* pFullscreenDesc,
    IDXGIOutput*                                                   pRestrictToOutput,
    HandlePointerDecoder<IDXGISwapChain1*>*                        ppSwapChain)
{
    return replay_object->CreateSwapChainForHwnd(pDevice,
                                                 reinterpret_cast<HWND>(hWnd),
                                                 pDesc->GetPointer(),
                                                 pFullscreenDesc->GetPointer(),
                                                 pRestrictToOutput,
                                                 ppSwapChain->GetHandlePointer());
}

HRESULT
Dx12ReplayConsumerBase::OverrideWriteToSubresource(ID3D12Resource*                          replay_object,
                                                   HRESULT                                  original_result,
                                                   UINT                                     DstSubresource,
                                                   StructPointerDecoder<Decoded_D3D12_BOX>* pDstBox,
                                                   uint64_t                                 pSrcData,
                                                   UINT                                     SrcRowPitch,
                                                   UINT                                     SrcDepthPitch)
{
    return E_NOTIMPL;
}

HRESULT
Dx12ReplayConsumerBase::OverrideReadFromSubresource(ID3D12Resource*                          replay_object,
                                                    HRESULT                                  original_result,
                                                    uint64_t                                 pDstData,
                                                    UINT                                     DstRowPitch,
                                                    UINT                                     DstDepthPitch,
                                                    UINT                                     SrcSubresource,
                                                    StructPointerDecoder<Decoded_D3D12_BOX>* pSrcBox)
{
    return E_NOTIMPL;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
