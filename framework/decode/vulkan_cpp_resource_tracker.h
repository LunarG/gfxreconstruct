//
// Copyright (c) 2022 Samsung
// Copyright (c) 2023 Google
// Copyright (c) 2023 LunarG, Inc
//
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GFXRECONSTRUCT_VULKAN_CPP_RESOURCE_TRACKER_H
#define GFXRECONSTRUCT_VULKAN_CPP_RESOURCE_TRACKER_H

#include "format/platform_types.h"
#include "format/format.h"
#include "pointer_decoder.h"

#include <cstdint>
#include <map>
#include <unordered_set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct FrameId
{
    uint32_t frame_number;
    uint32_t frame_split;

    bool operator==(const FrameId& frameId) const
    {
        return (frame_number == frameId.frame_number && frame_split == frameId.frame_split);
    }
};

struct FrameIdHasher
{
    uint64_t operator()(const FrameId& frameId) const
    {
        // With a 32-bit frame and split number, we can easily just output a 64-bit "hash" which is just both
        // numbers bit-shifted giving a unique value instead of doing an actual 32-bit hash on each number.
        return (static_cast<uint64_t>(frameId.frame_split) << 32) |
               (static_cast<uint64_t>(frameId.frame_number) & 0x00000000FFFFFFFF);
    }
};

class VulkanCppResourceTracker
{
  public:
    VulkanCppResourceTracker() {}

    void AddHandleUsage(uint32_t frame_number, uint32_t frame_split_number, format::HandleId ptr);

    void
    AddHandleUsage(uint32_t frame_number, uint32_t frame_split_number, const format::HandleId* ptrs, uint32_t count);

    template <typename T>
    void AddHandleUsage(uint32_t                frame_number,
                        uint32_t                frame_split_number,
                        const format::HandleId* ptrs,
                        PointerDecoder<T>*      count)
    {
        if (ptrs != nullptr && count != nullptr)
        {
            AddHandleUsage(frame_number, frame_split_number, ptrs, *count->GetPointer());
        }
    }

  private:
    // HandleId -> (frame_number, frame_split)
    std::map<format::HandleId, std::unordered_set<FrameId, FrameIdHasher>> handle_id_usage_map_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECONSTRUCT_VULKAN_CPP_RESOURCE_TRACKER_H