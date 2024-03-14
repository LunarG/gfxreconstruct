/*
** Copyright (c) 2019-2024 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_OPENXR_STATE_WRITER_H
#define GFXRECON_ENCODE_OPENXR_STATE_WRITER_H

#if ENABLE_OPENXR_SUPPORT

#include "encode/parameter_encoder.h"
#include "encode/openxr_handle_wrappers.h"
#include "generated/generated_openxr_state_table.h"
#include "format/format.h"
#include "format/platform_types.h"
#include "generated/generated_openxr_dispatch_table.h"
#include "util/compressor.h"
#include "util/defines.h"
#include "util/file_output_stream.h"
#include "util/memory_output_stream.h"

#include "openxr/openxr.h"

#include <set>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class OpenXrStateWriter
{
  public:
    OpenXrStateWriter(util::FileOutputStream* output_stream, util::Compressor* compressor, format::ThreadId thread_id);

    ~OpenXrStateWriter();

    // Returns number of blocks written to the output_stream.
    uint64_t WriteState(const OpenXrStateTable& state_table, uint64_t frame_number);

  private:
    void WriteFunctionCall(format::ApiCallId call_id, util::MemoryOutputStream* parameter_buffer);

    void WriteSessionState(const OpenXrStateTable& state_table);
    void WriteActionSetState(const OpenXrStateTable& state_table);
    void WritePassthroughFBState(const OpenXrStateTable& state_table);

    template <typename Wrapper>
    void StandardCreateWrite(const OpenXrStateTable& state_table)
    {
        std::set<util::MemoryOutputStream*> processed;
        state_table.VisitWrappers([&](const Wrapper* wrapper) {
            // Filter duplicate entries for calls that create multiple objects, where objects created by the same call
            // all reference the same parameter buffer.
            if (processed.find(wrapper->create_parameters.get()) == processed.end())
            {
                WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());
                processed.insert(wrapper->create_parameters.get());
            }
        });
    }

  private:
    util::FileOutputStream*  output_stream_;
    util::Compressor*        compressor_;
    std::vector<uint8_t>     compressed_parameter_buffer_;
    format::ThreadId         thread_id_;
    util::MemoryOutputStream parameter_stream_;
    ParameterEncoder         encoder_;
    uint64_t                 blocks_written_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_ENCODE_OPENXR_STATE_WRITER_H
