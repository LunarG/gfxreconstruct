/*
** Copyright (c) 2023 Valve Corporation
** Copyright (c) 2023 LunarG, Inc.
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

/// @file Common features for writing decoded items to a single json stream, be
/// they from Vulkan, D3D12, metadata, annotations, or any other source.

#include "decode/json_writer.h"
#include "util/output_stream.h"
#include "util/logging.h"
#include "decode/api_decoder.h"
#include "format/format_json.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

using namespace util;

namespace
{
/// @brief Convert an annotation to its string representation
/// @todo This should be moved into util/to_string.h/cpp after the existing
/// code there that is tied to the deprecated toJSON paths is eliminated.
std::string AnnotationTypeToString(const format::AnnotationType& type)
{
    std::string str;
    switch (type)
    {
        case format::AnnotationType::kUnknown:
            str.assign("kUnknown");
            break;
        case format::AnnotationType::kText:
            str.assign("kText");
            break;
        case format::AnnotationType::kJson:
            str.assign("kJson");
            break;
        case format::AnnotationType::kXml:
            str.assign("kXml");
            break;
        default:
            str.assign("OUT_OF_RANGE_ERROR");
            GFXRECON_LOG_WARNING("format::AnnotationType with out of range value: %lu",
                                 static_cast<long unsigned>(type));
            break;
    }
    return str;
}
} // namespace

JsonWriter::JsonWriter(const JsonOptions&     options,
                       const std::string_view gfxrVersion,
                       const std::string_view inputFilepath) :
    json_options_(options)
{
    header_["source-path"]      = inputFilepath;
    header_["gfxrecon-version"] = std::string(gfxrVersion);
}

JsonWriter::~JsonWriter()
{
    if (os_)
    {
        os_->Flush();
    }
}

void JsonWriter::StartStream(util::OutputStream* os)
{
    GFXRECON_ASSERT(os);
    first_ = true;
    os_    = os;

    if (json_options_.format == JsonFormat::JSON)
    {
        Write(*os_, "[\n");
    }

    // Emit the header object as the first line of the file:
    WriteBlockStart();
    json_data_["header"] = header_;
    WriteBlockEnd();

    ++num_streams_;
}

void JsonWriter::EndStream()
{
    if (os_ != nullptr)
    {
        if (json_options_.format == JsonFormat::JSON)
        {
            Write(*os_, "\n]\n");
        }
        else
        {
            Write(*os_, "\n");
        }
        os_->Flush();
        os_ = nullptr;
    }
}

void JsonWriter::Destroy()
{
    EndStream();
}

bool JsonWriter::IsValid() const
{
    return os_ != nullptr && os_->IsValid();
}

nlohmann::ordered_json& JsonWriter::WriteBlockStart()
{
    // Dominates profiling (1/2):
    json_data_.clear();
    return json_data_;
}

void JsonWriter::WriteBlockEnd()
{
    using namespace util::platform;

    if (!first_)
    {
        Write(*os_, json_options_.format == JsonFormat::JSONL ? "\n" : ",\n");
    }
    first_ = false;
    /// @todo Hand the tree over to a backend thread which dumps it to a string and streams it
    /// while the main thread gets on with building the tree for the next block.
    // Dominates profiling (2/2):
    const std::string block = json_data_.dump(json_options_.format == JsonFormat::JSONL ? -1 : kJsonIndentWidth);
    Write(*os_, block);
    os_->Flush();
}

nlohmann::ordered_json& JsonWriter::WriteApiCallStart(const ApiCallInfo& call_info, const std::string_view command_name)
{
    using namespace util;
    auto& json_data = WriteBlockStart();

    json_data[format::kNameIndex] = call_info.index;

    nlohmann::ordered_json& function = json_data[format::kNameFunction];
    function[format::kNameName]      = command_name;
    function[format::kNameThread]    = call_info.thread_id;

    return function;
}

nlohmann::ordered_json& JsonWriter::WriteApiCallStart(const ApiCallInfo&     call_info,
                                                      const std::string_view object_type,
                                                      format::HandleId       object_id,
                                                      const std::string_view command_name)
{
    using namespace util;
    auto& json_data = WriteBlockStart();

    json_data[format::kNameIndex] = call_info.index;

    nlohmann::ordered_json& method = json_data[format::kNameMethod];
    method[format::kNameName]      = command_name;
    method[format::kNameThread]    = call_info.thread_id;

    nlohmann::ordered_json& object  = method[format::kNameObject];
    object[format::kNameObjectType] = object_type;
    FieldToJson(object[format::kNameObjectHandle], object_id, GetOptions());

    return method;
}

void JsonWriter::ProcessAnnotation(uint64_t               block_index,
                                   format::AnnotationType type,
                                   const std::string&     label,
                                   const std::string&     data)
{
    auto& json_data     = WriteBlockStart();
    json_data["index"]  = block_index;
    auto& annotation    = json_data["annotation"];
    annotation["type"]  = AnnotationTypeToString(type);
    annotation["label"] = label;
    annotation["data"]  = data;
    WriteBlockEnd();
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
