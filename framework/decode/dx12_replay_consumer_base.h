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

class DX12ReplayConsumerBase : public DX12Consumer
{
  public:
    DX12ReplayConsumerBase() {}
    virtual ~DX12ReplayConsumerBase() {}

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

    void AddObject(format::HandleId id, void* object)
    {
        objects_.insert(std::make_pair(id, reinterpret_cast<IUnknown*>(object)));
    }

    void RemoveObject(format::HandleId id) { objects_.erase(id); }

    template <typename T>
    T MapHandle(format::HandleId id)
    {
        auto entry = handles_.find(id);
        if (entry != handles_.end())
        {
            return static_cast<T>(entry->second);
        }

        return nullptr;
    }

    void AddHandle(format::HandleId id, HANDLE handle_) { handles_.insert(std::make_pair(id, handle_)); }

    void RemoveHandle(format::HandleId id) { handles_.erase(id); }

    void CheckReplayResult(const char* call_name, HRESULT capture_result, HRESULT replay_result)
    {
        if (capture_result != replay_result)
        {
            GFXRECON_LOG_ERROR("%s returned %d, which does not match the value returned at capture",
                               call_name,
                               replay_result,
                               capture_result);
        }
    }

  private:
    std::unordered_map<format::HandleId, IUnknown*> objects_;
    std::unordered_map<format::HandleId, HANDLE>    handles_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_REPLAY_CONSUMER_BASE_H
