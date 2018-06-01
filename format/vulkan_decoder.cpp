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

#include "format/pointer_decoder.h"
#include "format/vulkan_decoder.h"
#include "format/value_decoder.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

void VulkanDecoder::DecodeFunctionCall(ApiCallId call_id, const uint8_t* buffer, size_t buffer_size)
{
    switch (call_id)
    {
    case ApiCallId_vkCreateInstance:
        Decode_vkCreateInstance(buffer, buffer_size);
        break;
    default:
        break;
    }
}

void VulkanDecoder::Decode_vkCreateInstance(const uint8_t* buffer, size_t buffer_size)
{
}

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)
