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

#ifndef GFXRECON_DECODE_DX12_REPLAY_CONSUMER_BASE_H
#define GFXRECON_DECODE_DX12_REPLAY_CONSUMER_BASE_H

#include "generated/generated_dx12_consumer.h"
#include "decode/dx12_object_mapping_util.h"
#include "decode/window.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class Dx12ReplayConsumerBase : public Dx12Consumer
{
  public:
    Dx12ReplayConsumerBase(WindowFactory* window_factory);
    virtual ~Dx12ReplayConsumerBase();

  protected:
    template <typename T>
    T* MapObject(const format::HandleId id)
    {
        return object_mapping::MapObject<T>(id, object_info_table_);
    }

    template <typename T>
    std::vector<T*> MapObjects(const format::HandleId* p_ids, const size_t ids_len)
    {
        return object_mapping::MapObjectArray<T>(p_ids, ids_len, object_info_table_);
    }

    template <typename T>
    void AddObject(const format::HandleId* p_id, T** pp_object)
    {
        object_mapping::AddObject<T>(p_id, pp_object, &object_info_table_);
    }

    void RemoveObject(format::HandleId id);

    void CheckReplayResult(const char* call_name, HRESULT capture_result, HRESULT replay_result);

    void* PreProcessExternalObject(uint64_t object_id, format::ApiCallId call_id, const char* call_name);

    void PostProcessExternalObject(
        HRESULT replay_result, void* object, uint64_t* object_id, format::ApiCallId call_id, const char* call_name);

    HRESULT OverrideCreateSwapChain(IDXGIFactory*                                       replay_object,
                                    HRESULT                                             original_result,
                                    IUnknown*                                           device,
                                    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC>* desc,
                                    HandlePointerDecoder<IDXGISwapChain*>*              swapchain);

    HRESULT OverrideCreateSwapChain(IDXGIFactory2*                          replay_object,
                                    HRESULT                                 original_result,
                                    IUnknown*                               device,
                                    DXGI_SWAP_CHAIN_DESC1*                  desc,
                                    HandlePointerDecoder<IDXGISwapChain1*>* swapchain);

    HRESULT
    OverrideCreateSwapChainForHwnd(IDXGIFactory2*                                                 replay_object,
                                   HRESULT                                                        original_result,
                                   IUnknown*                                                      device,
                                   uint64_t                                                       hwnd,
                                   StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>*           desc,
                                   StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC>* full_screen_desc,
                                   IDXGIOutput*                                                   restrict_to_output,
                                   HandlePointerDecoder<IDXGISwapChain1*>*                        swapchain);

    HRESULT
    OverrideCreateSwapChainForCoreWindow(IDXGIFactory2*                                       replay_object,
                                         HRESULT                                              original_result,
                                         IUnknown*                                            device,
                                         IUnknown*                                            window,
                                         StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* desc,
                                         IDXGIOutput*                                         restrict_to_output,
                                         HandlePointerDecoder<IDXGISwapChain1*>*              swapchain);

    HRESULT OverrideCreateSwapChainForComposition(IDXGIFactory2*                                       replay_object,
                                                  HRESULT                                              original_result,
                                                  IUnknown*                                            device,
                                                  StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* desc,
                                                  IDXGIOutput*                            restrict_to_output,
                                                  HandlePointerDecoder<IDXGISwapChain1*>* swapchain);

    // TODO(GH-71): Implement function
    HRESULT
    OverrideWriteToSubresource(ID3D12Resource*                          replay_object,
                               HRESULT                                  original_result,
                               UINT                                     DstSubresource,
                               StructPointerDecoder<Decoded_D3D12_BOX>* pDstBox,
                               uint64_t                                 pSrcData,
                               UINT                                     SrcRowPitch,
                               UINT                                     SrcDepthPitch)
    {
        return 0;
    }
    // TODO(GH-71): Implement function
    HRESULT
    OverrideReadFromSubresource(ID3D12Resource*                          replay_object,
                                HRESULT                                  original_result,
                                uint64_t                                 pDstData,
                                UINT                                     DstRowPitch,
                                UINT                                     DstDepthPitch,
                                UINT                                     SrcSubresource,
                                StructPointerDecoder<Decoded_D3D12_BOX>* pSrcBox)
    {
        return 0;
    }

    void DestroyWindowHandles();


    const Dx12ObjectInfoTable& GetObjectInfoTable() const { return object_info_table_; }

    Dx12ObjectInfoTable& GetObjectInfoTable() { return object_info_table_; }

  private:
    HRESULT
    CreateSwapChainForHwnd(IDXGIFactory2*                          replay_object,
                           HRESULT                                 original_result,
                           IUnknown*                               device,
                           uint64_t                                hwnd,
                           const DXGI_SWAP_CHAIN_DESC1*            desc,
                           const DXGI_SWAP_CHAIN_FULLSCREEN_DESC*  full_screen_desc,
                           IDXGIOutput*                            restrict_to_output,
                           HandlePointerDecoder<IDXGISwapChain1*>* swapchain);
    
    void InsertWindowHandleToMap(uint64_t& hwnd, Window* window);

    std::unordered_map<format::HandleId, IUnknown*> objects_;
    std::unordered_map<uint64_t, Window*>           swapchain_windows_;
    WindowFactory*                                  window_factory_ = nullptr;
    Dx12ObjectInfoTable object_info_table_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_REPLAY_CONSUMER_BASE_H
