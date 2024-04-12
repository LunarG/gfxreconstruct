/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2024 LunarG, Inc.
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

#if ENABLE_OPENXR_SUPPORT

#include "decode/openxr_decoder_base.h"

#include "decode/descriptor_update_template_decoder.h"
#include "decode/pointer_decoder.h"
#include "decode/value_decoder.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void OpenXrDecoderBase::WaitIdle()
{
    for (auto consumer : consumers_)
    {
        consumer->WaitDevicesIdle();
    }
}

void OpenXrDecoderBase::DispatchStateBeginMarker(uint64_t frame_number)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessStateBeginMarker(frame_number);
    }
}

void OpenXrDecoderBase::DispatchStateEndMarker(uint64_t frame_number)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessStateEndMarker(frame_number);
    }
}

void OpenXrDecoderBase::DispatchFrameEndMarker(uint64_t frame_number)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessFrameEndMarker(frame_number);
    }
}

void OpenXrDecoderBase::DispatchDisplayMessageCommand(format::ThreadId thread_id, const std::string& message)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->ProcessDisplayMessageCommand(message);
    }
}

void OpenXrDecoderBase::DecodeFunctionCall(format::ApiCallId  call_id,
                                           const ApiCallInfo& call_info,
                                           const uint8_t*     parameter_buffer,
                                           size_t             buffer_size)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_id);
    GFXRECON_UNREFERENCED_PARAMETER(call_info);
    GFXRECON_UNREFERENCED_PARAMETER(parameter_buffer);
    GFXRECON_UNREFERENCED_PARAMETER(buffer_size);
}

void OpenXrDecoderBase::SetCurrentBlockIndex(uint64_t block_index)
{
    for (auto consumer : consumers_)
    {
        consumer->SetCurrentBlockIndex(block_index);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
