/*
** Copyright (c) 2019-2024 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_OPENXR_STATE_TABLE_BASE_H
#define GFXRECON_ENCODE_OPENXR_STATE_TABLE_BASE_H

#if ENABLE_OPENXR_SUPPORT

#include "encode/openxr_handle_wrappers.h"
#include "format/format.h"
#include "util/defines.h"

#include "openxr/openxr.h"

#include <cassert>
#include <functional>
#include <map>
#include <mutex>
#include <shared_mutex>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class OpenXrStateTableBase
{
  public:
    OpenXrStateTableBase() {}

    ~OpenXrStateTableBase() {}

  protected:
    template <typename T>
    bool InsertEntry(format::HandleId id, T* wrapper, std::map<format::HandleId, T*>& map)
    {
        const auto& inserted = map.insert(std::make_pair(id, wrapper));
        return inserted.second;
    }

    template <typename Wrapper>
    bool RemoveEntry(const Wrapper* wrapper, std::map<format::HandleId, Wrapper*>& map)
    {
        assert(wrapper != nullptr);
        return (map.erase(wrapper->handle_id) != 0);
    }

    template <typename T>
    T* GetWrapper(format::HandleId id, std::map<format::HandleId, T*>& map)
    {
        auto entry = map.find(id);
        return (entry != map.end()) ? entry->second : nullptr;
    }

    template <typename T>
    const T* GetWrapper(format::HandleId id, const std::map<format::HandleId, T*>& map) const
    {
        auto entry = map.find(id);
        return (entry != map.end()) ? entry->second : nullptr;
    }

    template <typename Wrapper>
    bool InsertEntry(typename Wrapper::HandleType                                handle,
                     Wrapper*                                                    wrapper,
                     std::unordered_map<typename Wrapper::HandleType, Wrapper*>& map)
    {
        const std::unique_lock<std::shared_mutex> lock(mutex_);
        const auto&                               inserted = map.insert(std::make_pair(handle, wrapper));
        return inserted.second;
    }

    template <typename Wrapper>
    bool RemoveEntry(const typename Wrapper::HandleType                          handle,
                     std::unordered_map<typename Wrapper::HandleType, Wrapper*>& map)
    {
        const std::unique_lock<std::shared_mutex> lock(mutex_);
        return (map.erase(handle) != 0);
    }

    template <typename Wrapper>
    Wrapper* GetWrapper(typename Wrapper::HandleType                                      handle,
                        const std::unordered_map<typename Wrapper::HandleType, Wrapper*>& map)
    {
        const std::shared_lock<std::shared_mutex> lock(mutex_);
        auto                                      entry = map.find(handle);
        return (entry != map.end()) ? entry->second : nullptr;
    }

    template <typename Wrapper>
    const Wrapper* GetWrapper(typename Wrapper::HandleType                                      handle,
                              const std::unordered_map<typename Wrapper::HandleType, Wrapper*>& map) const
    {
        const std::shared_lock<std::shared_mutex> lock(mutex_);
        auto                                      entry = map.find(handle);
        return (entry != map.end()) ? entry->second : nullptr;
    }

  private:
    mutable std::shared_mutex mutex_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_ENCODE_OPENXR_STATE_TABLE_BASE_H
