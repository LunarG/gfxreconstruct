/*
** Copyright (c) 2026 LunarG, Inc.
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

#include "decode/vulkan_consumer_stage_base.h"

#include "generated/generated_vulkan_decoder.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanConsumerStageBase::Emit(format::ApiCallId        call_id,
                                   const ApiCallInfo&       call_info,
                                   std::span<const uint8_t> bytes)
{
    // The local decoder hands the call to the next consumers only, so the call never comes back into this stage.
    VulkanDecoder decoder;
    for (auto* consumer : next_consumers_)
    {
        decoder.AddConsumer(consumer);
    }

    // Emit opens no DecoderAllocGuard, because the app call's allocator scope is still open
    // and a nested Begin asserts.
    decoder.DecodeFunctionCall(call_id, call_info, bytes);

    // The local decoder gave the next consumers the bytes of the invented call. Give them back the bytes
    // of the app call, because the stage may forward that call next.
    Broadcast(&VulkanConsumer::SetCurrentCallBytes, current_call_bytes_);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
