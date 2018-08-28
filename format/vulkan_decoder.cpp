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
#include "format/vulkan_consumer.h"
#include "format/vulkan_decoder.h"
#include "format/value_decoder.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

void VulkanDecoder::DecodeFunctionCall(ApiCallId             call_id,
                                       const ApiCallOptions& call_options,
                                       const uint8_t*        parameter_buffer,
                                       size_t                buffer_size)
{
    // Unused items
    (void)call_options;

    switch (call_id)
    {
#include "generated/generated_api_call_decode_cases.inc"
        default:
            break;
    }
}

void VulkanDecoder::DispatchDisplayMessageCommand(const std::string& message)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessDisplayMessageCommand(message);
    }
}

void VulkanDecoder::DispatchFillMemoryCommand(uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessFillMemoryCommand(memory_id, offset, size, data);
    }
}

void VulkanDecoder::DispatchResizeWindowCommand(HandleId surface_id, uint32_t width, uint32_t height)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessResizeWindowCommand(surface_id, width, height);
    }
}


BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)

#include "generated/generated_decoded_struct_types.inc"
#include "generated/generated_struct_decoders.inc"
#include "generated/generated_decode_pnext_struct.inc"
#include "generated/generated_api_call_decoders.inc"
