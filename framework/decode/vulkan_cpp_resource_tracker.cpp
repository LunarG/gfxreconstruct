//
// Copyright (c) 2021 Samsung
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

#include "vulkan_cpp_resource_tracker.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanCppResourceTracker::AddHandleUsage(const uint32_t   frame_number,
                                              uint32_t         frame_split_number,
                                              format::HandleId ptr)
{
    handle_id_usage_map_[ptr].insert(FrameId{ frame_number, frame_split_number });
}

void VulkanCppResourceTracker::AddHandleUsage(uint32_t                frame_number,
                                              uint32_t                frame_split_number,
                                              const format::HandleId* ptrs,
                                              uint32_t                count)
{
    for (uint32_t idx = 0; idx < count; idx++)
    {
        handle_id_usage_map_[ptrs[idx]].insert(FrameId{ frame_number, frame_split_number });
    }
}

void VulkanCppResourceTracker::CalculateGlobalVariables()
{
    for (const auto& handle_id_usage : handle_id_usage_map_)
    {
        // If the resource is used in more than a single frame then it's global
        uint32_t size      = handle_id_usage.second.size();
        bool     is_global = size > 1;

        global_variable_map_[handle_id_usage.first] = is_global;
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)