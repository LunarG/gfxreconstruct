/*
** Copyright (c) 2021 Samsung
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

#include "vulkan_cpp_resource_tracker.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanCppResourceTracker::AddHandleUsage(const uint32_t   frameNumber,
                                              uint32_t         m_frameSplitNumber,
                                              format::HandleId ptr)
{
    m_handleIdUsageMap[ptr].insert(FrameId{ frameNumber, m_frameSplitNumber });
}

void VulkanCppResourceTracker::AddHandleUsage(uint32_t                frameNumber,
                                              uint32_t                frameSplitNumber,
                                              const format::HandleId* ptrs,
                                              uint32_t                count)
{
    for (uint32_t idx = 0; idx < count; idx++)
    {
        m_handleIdUsageMap[ptrs[idx]].insert(FrameId{ frameNumber, frameSplitNumber });
    }
}

void VulkanCppResourceTracker::CalculateGlobalVariables()
{
    for (const auto& handleIdUsage : m_handleIdUsageMap)
    {
        // If the resource is used in more than a single frame then it's global
        uint32_t size     = handleIdUsage.second.size();
        bool     isGlobal = size > 1;

        m_globalVariableMap[handleIdUsage.first] = isGlobal;
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)