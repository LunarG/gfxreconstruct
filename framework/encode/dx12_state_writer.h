/*
** Copyright (c) 2021 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_DX12_STATE_WRITER_H
#define GFXRECON_ENCODE_DX12_STATE_WRITER_H

#include "encode/dx12_state_table.h"
#include "encode/parameter_encoder.h"
#include "format/format.h"
#include "util/compressor.h"
#include "util/defines.h"
#include "util/file_output_stream.h"
#include "util/memory_output_stream.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class Dx12StateWriter
{
  public:
    Dx12StateWriter(util::FileOutputStream* output_stream, util::Compressor* compressor, format::ThreadId thread_id);

    ~Dx12StateWriter();

    void WriteState(const Dx12StateTable& state_table, uint64_t frame_number);

  private:
    // TODO: This is the same function as VulkanStateWriter. Move to a utility class or common base class to reduce code
    // duplication.
    template <typename Wrapper>
    void StandardCreateWrite(const Dx12StateTable& state_table)
    {
        std::set<util::MemoryOutputStream*> processed;
        state_table.VisitWrappers([&](const Wrapper* wrapper) {
            assert(wrapper != nullptr);
            assert(wrapper->GetObjectInfo() != nullptr);
            assert(wrapper->GetObjectInfo()->create_parameters != nullptr);

            // Filter duplicate entries for calls that create multiple objects, where objects created by the same call
            // all reference the same parameter buffer.
            auto wrapper_info = wrapper->GetObjectInfo();
            if (processed.find(wrapper_info->create_parameters.get()) == processed.end())
            {
                if (wrapper_info->object_id == format::kNullHandleId)
                {
                    WriteFunctionCall(wrapper_info->create_call_id, wrapper_info->create_parameters.get());
                }
                else
                {
                    WriteMethodCall(
                        wrapper_info->create_call_id, wrapper_info->object_id, wrapper_info->create_parameters.get());
                }
                WriteAddRefAndReleaseCommands(wrapper);
                processed.insert(wrapper_info->create_parameters.get());
            }
        });
    }

    // TODO: These are similar to the functions used by CaptureManager to write call data. They could be refactored for
    // code reuse.
    void WriteFunctionCall(format::ApiCallId call_id, util::MemoryOutputStream* parameter_buffer);

    void
    WriteMethodCall(format::ApiCallId call_id, format::HandleId object_id, util::MemoryOutputStream* parameter_buffer);

    void WriteHeapState(const Dx12StateTable& state_table);

    // Returns true if memory information was successfully retrieved and written and false otherwise.
    bool WriteCreateHeapAllocationCmd(const void* address);

    void WriteAddRefAndReleaseCommands(const IUnknown_Wrapper* wrapper);

    void WriteAddRefCommand(format::HandleId handle_id, unsigned long result_ref_count);

    void WriteReleaseCommand(format::HandleId handle_id, unsigned long result_ref_count);

    // TODO (GH #83): Add D3D12 trimming support, add custom functions for writing tracked state.

  private:
    util::FileOutputStream*  output_stream_;
    util::Compressor*        compressor_;
    std::vector<uint8_t>     compressed_parameter_buffer_;
    format::ThreadId         thread_id_;
    util::MemoryOutputStream parameter_stream_;
    ParameterEncoder         encoder_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_DX12_STATE_WRITER_H
