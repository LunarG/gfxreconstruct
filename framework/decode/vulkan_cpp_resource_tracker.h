/*
** Copyright (c) 2022 Samsung
**
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef GFXRECONSTRUCT_VULKAN_CPP_RESOURCE_TRACKER_H
#define GFXRECONSTRUCT_VULKAN_CPP_RESOURCE_TRACKER_H

#include "format/platform_types.h"
#include "format/format.h"
#include "pointer_decoder.h"
#include "util/xxhash32.h"

#include <cstdint>
#include <map>
#include <unordered_set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct FrameId
{
    // TODO(tkeri: uint64_t to include xxhash64?)
    uint32_t frameNumber;
    uint32_t frameSplit;

    bool operator==(const FrameId& frameId) const
    {
        return (frameNumber == frameId.frameNumber && frameSplit == frameId.frameSplit);
    }
};

struct FrameIdHasher
{
    uint32_t operator()(const FrameId& frameId) const
    {
        return XXHash32::hash(&frameId.frameSplit, 1, 0) ^ XXHash32::hash(&frameId.frameNumber, 1, 0);
    }
};

class VulkanCppResourceTracker
{
  public:
    VulkanCppResourceTracker() {}

    void AddHandleUsage(uint32_t frameNumber, uint32_t frameSplitNumber, format::HandleId ptr);

    void AddHandleUsage(uint32_t frameNumber, uint32_t frameSplitNumber, const format::HandleId* ptrs, uint32_t count);

    template <typename T>
    void AddHandleUsage(uint32_t                frameNumber,
                        uint32_t                frameSplitNumber,
                        const format::HandleId* ptrs,
                        PointerDecoder<T>*      count)
    {
        if (ptrs != nullptr && count != nullptr)
        {
            AddHandleUsage(frameNumber, frameSplitNumber, ptrs, *count->GetPointer());
        }
    }

    void CalculateGlobalVariables();

    bool IsGlobalVariable(format::HandleId handleId) { return true; } // return m_globalVariableMap[handleId]; }

  private:
    // HandleId -> (FrameNumber, FrameSplit)
    std::map<format::HandleId, std::unordered_set<FrameId, FrameIdHasher>> m_handleIdUsageMap;
    std::map<format::HandleId, bool>                                       m_globalVariableMap;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECONSTRUCT_VULKAN_CPP_RESOURCE_TRACKER_H