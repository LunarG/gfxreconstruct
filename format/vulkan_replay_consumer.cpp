/*
** Copyright (c) 2018 LunarG, Inc.
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

#include "util/platform.h"
#include "format/vulkan_replay_consumer.h"

#include "generated/generated_decoded_struct_types.inc"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

VulkanReplayConsumer::VulkanReplayConsumer()
{
}

VulkanReplayConsumer::~VulkanReplayConsumer()
{
}

const VkAllocationCallbacks* VulkanReplayConsumer::GetAllocationCallbacks(const StructPointerDecoder<Decoded_VkAllocationCallbacks>& original_callbacks)
{
    // Replay does not currently attempt emulate the captured application's use of VkAllocationCallbacks.
    BRIMSTONE_UNREFERENCED_PARAMETER(original_callbacks);
    return nullptr;
}

#include "generated/generated_api_call_replay_consumer_definitions.inc"

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)
