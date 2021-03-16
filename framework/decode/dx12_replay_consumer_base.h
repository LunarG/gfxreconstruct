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
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class Dx12ReplayConsumerBase : public Dx12Consumer
{
  public:
    Dx12ReplayConsumerBase() {}
    virtual ~Dx12ReplayConsumerBase() {}

  protected:
    template <typename T>
    T* MapObject(const format::HandleId id)
    {
        auto entry = objects_.find(id);
        if (entry != objects_.end())
        {
            return reinterpret_cast<T*>(entry->second);
        }

        return nullptr;
    }

    template <typename T>
    std::vector<T*> MapObjects(const format::HandleId* p_ids, const size_t ids_len)
    {
        std::vector<T*> objects(ids_len);
        if (p_ids != nullptr)
        {
            for (uint32_t i = 0; i < ids_len; ++i)
            {
                objects[i] = MapObject<T>(p_ids[i]);
            }
        }
        return objects;
    }

    template <typename T>
    void AddObject(const format::HandleId* p_id, T** pp_object)
    {
        if ((p_id != nullptr) && (*p_id != format::kNullHandleId) && (pp_object != nullptr) && (*pp_object != nullptr))
        {
            objects_.insert(std::make_pair(*p_id, reinterpret_cast<IUnknown*>(*pp_object)));
        }
    }

    void RemoveObject(format::HandleId id);

    void CheckReplayResult(const char* call_name, HRESULT capture_result, HRESULT replay_result);

    void* PreProcessExternalObject(uint64_t object_id, format::ApiCallId call_id, const char* call_name);

    void PostProcessExternalObject(
        HRESULT replay_result, void* object, uint64_t* object_id, format::ApiCallId call_id, const char* call_name);

    // TODO(GH-63): Implement function
    HRESULT
    OverrideCreateSwapChainForHwnd(IDXGIFactory2*                                                 replay_object,
                                   HRESULT                                                        original_result,
                                   IUnknown*                                                      pDevice,
                                   uint64_t                                                       hWnd,
                                   StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>*           pDesc,
                                   StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC>* pFullscreenDesc,
                                   IDXGIOutput*                                                   pRestrictToOutput,
                                   HandlePointerDecoder<IDXGISwapChain1*>*                        ppSwapChain);

    // TODO(GH-71): Implement function
    HRESULT
    OverrideWriteToSubresource(ID3D12Resource*                          replay_object,
                               HRESULT                                  original_result,
                               UINT                                     DstSubresource,
                               StructPointerDecoder<Decoded_D3D12_BOX>* pDstBox,
                               uint64_t                                 pSrcData,
                               UINT                                     SrcRowPitch,
                               UINT                                     SrcDepthPitch);

    // TODO(GH-71): Implement function
    HRESULT
    OverrideReadFromSubresource(ID3D12Resource*                          replay_object,
                                HRESULT                                  original_result,
                                uint64_t                                 pDstData,
                                UINT                                     DstRowPitch,
                                UINT                                     DstDepthPitch,
                                UINT                                     SrcSubresource,
                                StructPointerDecoder<Decoded_D3D12_BOX>* pSrcBox);

  private:
    std::unordered_map<format::HandleId, IUnknown*> objects_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_REPLAY_CONSUMER_BASE_H
