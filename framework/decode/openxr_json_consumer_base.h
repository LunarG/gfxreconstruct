/*
** Copyright (c) 2022-2024 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_OPENXR_JSON_CONSUMER_BASE_H
#define GFXRECON_DECODE_OPENXR_JSON_CONSUMER_BASE_H

#if ENABLE_OPENXR_SUPPORT

#include "util/output_stream.h"
#include "util/defines.h"
#include "annotation_handler.h"
#include "format/platform_types.h"
#include "format/format_json.h"
#include "generated/generated_openxr_consumer.h"
#include "decode/json_writer.h"
#include "util/json_util.h"
#include "openxr/openxr.h"

#include <cstdio>
#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class OpenXrExportJsonConsumerBase : public OpenXrConsumer
{
  public:
    OpenXrExportJsonConsumerBase();

    virtual ~OpenXrExportJsonConsumerBase() override;

    void Initialize(JsonWriter* writer, const std::string_view openxrVersion);

    void Destroy();

    bool IsValid() const { return writer_ && writer_->IsValid(); }

  protected:
    const util::JsonOptions& GetJsonOptions() const { return writer_->GetOptions(); }

    nlohmann::ordered_json& WriteBlockStart() { return writer_->WriteBlockStart(); }

    /// Output the current in-memory json tree to the destination file.
    void WriteBlockEnd() { writer_->WriteBlockEnd(); }

    // Wrappers for json field names allowing change without code gen and
    // leaving door open for switching output based on internal state.
    /// @todo Just use the constants directly: the requirement to be able to have
    /// different versions of field names switchable at runtime that I added these
    /// as a first step towards during Export PR integration has gone away.
    constexpr const char* NameFunction() const { return format::kNameFunction; }
    constexpr const char* NameMeta() const { return format::kNameMeta; }
    constexpr const char* NameState() const { return format::kNameState; }
    constexpr const char* NameFrame() const { return format::kNameFrame; }
    constexpr const char* NameName() const { return format::kNameName; }
    constexpr const char* NameIndex() const { return format::kNameIndex; }
    constexpr const char* NameThread() const { return format::kNameThread; }
    constexpr const char* NameReturn() const { return format::kNameReturn; }
    constexpr const char* NameArgs() const { return format::kNameArgs; }
    /// A field not present in binary format which identifies the index of each
    /// command within its command buffer.
    /// @todo Make this field optional.
    constexpr const char* NameCommandIndex() const { return "cmd_index"; }
    /// A field not present in binary format which identifies the index of each
    /// submit in the global order of all submits to all queues as recorded in
    /// the binary trace file.
    /// @todo Make this field optional.
    constexpr const char* NameSubmitIndex() const { return "sub_index"; }

    nlohmann::ordered_json& WriteApiCallStart(const ApiCallInfo& call_info, const std::string& command_name)
    {
        return writer_->WriteApiCallStart(call_info, command_name);
    }

    /// A utility wrapper so that manual output functions can provide a lambda which only needs to output
    /// the fields unique to their call and this tops and tails with the standard boilerplate, defining it
    /// once here. Generated functions avoid the indirection through this.
    template <typename ToJsonFunctionType>
    inline void
    WriteApiCallToFile(const ApiCallInfo& call_info, const std::string& command_name, ToJsonFunctionType toJsonFunction)
    {
        nlohmann::ordered_json& function = WriteApiCallStart(call_info, command_name);
        toJsonFunction(function);
        WriteBlockEnd();
    }

    std::string GenerateFilename(const std::string& filename);
    bool        WriteBinaryFile(const std::string& filename, uint64_t data_size, const uint8_t* data);

    void Process_xrEnumerateSwapchainImages(const ApiCallInfo&        call_info,
                                            XrResult                  returnValue,
                                            format::HandleId          swapchain,
                                            uint32_t                  imageCapacityInput,
                                            PointerDecoder<uint32_t>* imageCountOutput,
                                            StructPointerDecoder<Decoded_XrSwapchainImageBaseHeader>* images);

    uint32_t submit_index_{ 0 }; // index of submissions across the trace

    JsonWriter* writer_{ nullptr };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_DECODE_OPENXR_JSON_CONSUMER_BASE_H
