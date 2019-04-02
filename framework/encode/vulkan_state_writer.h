/*
** Copyright (c) 2019 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_VULKAN_STATE_WRITER_H
#define GFXRECON_ENCODE_VULKAN_STATE_WRITER_H

#include "encode/parameter_encoder.h"
#include "encode/vulkan_handle_wrappers.h"
#include "encode/vulkan_state_table.h"
#include "format/format.h"
#include "util/compressor.h"
#include "util/defines.h"
#include "util/file_output_stream.h"
#include "util/memory_output_stream.h"

#include "vulkan/vulkan.h"

#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class VulkanStateWriter
{
  public:
    VulkanStateWriter(util::FileOutputStream* output_stream, util::Compressor* compressor, format::ThreadId thread_id);

    ~VulkanStateWriter();

    // Returns number of bytes written to the output_stream.
    void WriteState(const VulkanStateTable& state_table);

  private:
    void WriteBufferState(const VulkanStateTable& state_table);

    void WriteImageState(const VulkanStateTable& state_table);

    void WriteFramebufferState(const VulkanStateTable& state_table);

    void WritePipelineLayoutState(const VulkanStateTable& state_table);

    void WritePipelineState(const VulkanStateTable& state_table);

    void DestroyTemporaryDeviceObject(format::ApiCallId         call_id,
                                      format::HandleId          handle,
                                      util::MemoryOutputStream* create_parameters);

    void WriteFunctionCall(format::ApiCallId call_id, util::MemoryOutputStream* parameter_buffer);

    template <typename Wrapper>
    void StandardCreateWrite(const VulkanStateTable& state_table)
    {
        state_table.VisitWrappers([=](const Wrapper* wrapper) {
            WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());
        });
    }

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

#endif // GFXRECON_ENCODE_VULKAN_STATE_WRITER_H
