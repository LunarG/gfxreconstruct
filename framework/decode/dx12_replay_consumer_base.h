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
    T* MapObject(format::HandleId id)
    {
        auto entry = objects_.find(id);
        if (entry != objects_.end())
        {
            return reinterpret_cast<T*>(entry->second);
        }

        return nullptr;
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

    template <typename T>
    T MapWin32Handle(uint64_t handle)
    {
        auto entry = win32_handles_.find(handle);
        if (entry != win32_handles_.end())
        {
            return static_cast<T>(entry->second);
        }

        return nullptr;
    }

    template <typename T>
    void AddWin32Handle(const uint64_t* p_handle, T** pp_handle)
    {
        if ((p_handle != nullptr) && (*p_handle != format::kNullHandleId) && (pp_handle != nullptr) &&
            (*pp_handle != nullptr))
        {
            win32_handles_.insert(std::make_pair(*p_handle, *pp_handle));
        }
    }

    void RemoveWin32Handle(uint64_t handle);

    void CheckReplayResult(const char* call_name, HRESULT capture_result, HRESULT replay_result);

    HRESULT
    OverrideCreateSwapChainForHwnd(IDXGIFactory2*                                                 replay_object,
                                   HRESULT                                                        returnValue,
                                   IUnknown*                                                      pDevice,
                                   uint64_t                                                       hWnd,
                                   StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>*           pDesc,
                                   StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC>* pFullscreenDesc,
                                   IDXGIOutput*                                                   pRestrictToOutput,
                                   HandlePointerDecoder<IDXGISwapChain1*>*                        ppSwapChain);

  private:
    std::unordered_map<format::HandleId, IUnknown*> objects_;
    std::unordered_map<uint64_t, void*>             win32_handles_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_REPLAY_CONSUMER_BASE_H
