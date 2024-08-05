/*
** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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

#include "decode/info_decoder.h"
#include "decoder_util.h"
#include <decode/info_consumer.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

bool InfoDecoder::IsComplete(uint64_t block_index)
{
    return decode::IsComplete<InfoConsumer*>(consumers_, block_index);
}

void InfoDecoder::DispatchExeFileInfo(format::ThreadId thread_id, format::ExeFileInfoBlock& info)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->Process_ExeFileInfo(info.info_record);
    }
}

void InfoDecoder::DispatchDriverInfo(format::ThreadId thread_id, format::DriverInfoBlock& info)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->Process_DriverInfo(info.driver_record);
    }
}

void InfoDecoder::DispatchSetEnvironmentVariablesCommand(format::SetEnvironmentVariablesCommand& header,
                                                         const char*                             env_string)
{
    for (auto consumer : consumers_)
    {
        consumer->Process_SetEnvironmentVariablesCommand(header, env_string);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
