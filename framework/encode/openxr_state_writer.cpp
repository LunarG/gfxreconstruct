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

#if ENABLE_OPENXR_SUPPORT

#include "encode/openxr_state_writer.h"

#include "encode/struct_pointer_encoder.h"
#include "encode/openxr_state_info.h"
#include "format/format_util.h"
#include "util/logging.h"

#include <algorithm>
#include <cassert>
#include <limits>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

OpenXrStateWriter::OpenXrStateWriter(util::FileOutputStream* output_stream,
                                     util::Compressor*       compressor,
                                     format::ThreadId        thread_id) :
    output_stream_(output_stream),
    compressor_(compressor), thread_id_(thread_id), encoder_(&parameter_stream_)
{
    assert(output_stream != nullptr);
}

OpenXrStateWriter::~OpenXrStateWriter() {}

uint64_t OpenXrStateWriter::WriteState(const OpenXrStateTable& state_table, uint64_t frame_number)
{
    // clang-format off
    blocks_written_ = 0;

    format::Marker marker;
    marker.header.size = sizeof(marker.marker_type) + sizeof(marker.frame_number);
    marker.header.type = format::kStateMarkerBlock;
    marker.marker_type = format::kBeginMarker;
    marker.frame_number = frame_number;
    output_stream_->Write(&marker, sizeof(marker));

    // Instance creation.
    StandardCreateWrite<openxr_wrappers::InstanceWrapper>(state_table);
    StandardCreateWrite<openxr_wrappers::SessionWrapper>(state_table);
    StandardCreateWrite<openxr_wrappers::ActionSetWrapper>(state_table);
    StandardCreateWrite<openxr_wrappers::PassthroughFBWrapper>(state_table);

    // Utility object creation.
    StandardCreateWrite<openxr_wrappers::DebugUtilsMessengerEXTWrapper>(state_table);

    marker.marker_type = format::kEndMarker;
    output_stream_->Write(&marker, sizeof(marker));

    return blocks_written_;
    // clang-format on
}

void OpenXrStateWriter::WriteSessionState(const OpenXrStateTable& state_table)
{
    state_table.VisitWrappers([&](const openxr_wrappers::SessionWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Write creation call.
        // TODO: WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());
    });
}

void OpenXrStateWriter::WriteActionSetState(const OpenXrStateTable& state_table)
{
    state_table.VisitWrappers([&](const openxr_wrappers::ActionSetWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Write creation call.
        // TODO: WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());
    });
}

void OpenXrStateWriter::WritePassthroughFBState(const OpenXrStateTable& state_table)
{
    state_table.VisitWrappers([&](const openxr_wrappers::PassthroughFBWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Write creation call.
        // TODO: WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());
    });
}

// TODO: This is the same code used by CaptureManager to write function call data. It could be moved to a format
// utility.
void OpenXrStateWriter::WriteFunctionCall(format::ApiCallId call_id, util::MemoryOutputStream* parameter_buffer)
{
    assert(parameter_buffer != nullptr);

    bool                                 not_compressed      = true;
    format::CompressedFunctionCallHeader compressed_header   = {};
    format::FunctionCallHeader           uncompressed_header = {};
    size_t                               uncompressed_size   = parameter_buffer->GetDataSize();
    size_t                               header_size         = 0;
    const void*                          header_pointer      = nullptr;
    size_t                               data_size           = 0;
    const void*                          data_pointer        = nullptr;

    if (compressor_ != nullptr)
    {
        size_t packet_size = 0;
        size_t compressed_size =
            compressor_->Compress(uncompressed_size, parameter_buffer->GetData(), &compressed_parameter_buffer_, 0);

        if ((0 < compressed_size) && (compressed_size < uncompressed_size))
        {
            data_pointer   = reinterpret_cast<const void*>(compressed_parameter_buffer_.data());
            data_size      = compressed_size;
            header_pointer = reinterpret_cast<const void*>(&compressed_header);
            header_size    = sizeof(format::CompressedFunctionCallHeader);

            compressed_header.block_header.type = format::BlockType::kCompressedFunctionCallBlock;
            compressed_header.api_call_id       = call_id;
            compressed_header.thread_id         = thread_id_;
            compressed_header.uncompressed_size = uncompressed_size;

            packet_size += sizeof(compressed_header.api_call_id) + sizeof(compressed_header.uncompressed_size) +
                           sizeof(compressed_header.thread_id) + compressed_size;

            compressed_header.block_header.size = packet_size;
            not_compressed                      = false;
        }
    }

    if (not_compressed)
    {
        size_t packet_size = 0;
        data_pointer       = reinterpret_cast<const void*>(parameter_buffer->GetData());
        data_size          = uncompressed_size;
        header_pointer     = reinterpret_cast<const void*>(&uncompressed_header);
        header_size        = sizeof(format::FunctionCallHeader);

        uncompressed_header.block_header.type = format::BlockType::kFunctionCallBlock;
        uncompressed_header.api_call_id       = call_id;
        uncompressed_header.thread_id         = thread_id_;

        packet_size += sizeof(uncompressed_header.api_call_id) + sizeof(uncompressed_header.thread_id) + data_size;

        uncompressed_header.block_header.size = packet_size;
    }

    // Write appropriate function call block header.
    output_stream_->Write(header_pointer, header_size);

    // Write parameter data.
    output_stream_->Write(data_pointer, data_size);

    ++blocks_written_;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
