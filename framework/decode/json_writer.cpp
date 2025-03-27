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

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

JsonWriter::JsonWriter(const util::JsonOptions& options,
                       const std::string_view   gfxrVersion,
                       const std::string_view   inputFilepath) :
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

    if (json_options_.format == util::JsonFormat::JSON)
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
        if (json_options_.format == util::JsonFormat::JSON)
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
    if (!first_)
    {
        Write(*os_, json_options_.format == util::JsonFormat::JSONL ? "\n" : ",\n");
    }
    first_ = false;
    /// @todo Hand the tree over to a backend thread which dumps it to a string and streams it
    /// while the main thread gets on with building the tree for the next block.
    // Dominates profiling (2/2):
    const std::string block =
        json_data_.dump(json_options_.format == util::JsonFormat::JSONL ? -1 : util::kJsonIndentWidth);
    Write(*os_, block);
    os_->Flush();
}

nlohmann::ordered_json& JsonWriter::WriteApiCallStart(const ApiCallInfo& call_info, const std::string_view command_name)
{
    auto& json_data = WriteBlockStart();

    if (!json_options_.no_index)
    {
        json_data[format::kNameIndex] = call_info.index;
    }

    nlohmann::ordered_json& function = json_data[format::kNameFunction];
    function[format::kNameName]      = command_name;
    function[format::kNameThread]    = call_info.thread_id;

    return function;
}

nlohmann::ordered_json& JsonWriter::WriteApiCallStart(const ApiCallInfo&     call_info,
                                                      const std::string_view object_type,
                                                      const format::HandleId object_id,
                                                      const std::string_view command_name)
{
    auto& json_data = WriteBlockStart();

    if (!json_options_.no_index)
    {
        json_data[format::kNameIndex] = call_info.index;
    }

    nlohmann::ordered_json& method = json_data[format::kNameMethod];
    method[format::kNameName]      = command_name;
    method[format::kNameThread]    = call_info.thread_id;

    nlohmann::ordered_json& object  = method[format::kNameObject];
    object[format::kNameObjectType] = object_type;
    FieldToJson(object[format::kNameObjectHandle], object_id, GetOptions());

    return method;
}

void JsonWriter::WriteMarker(const char* const name, const std::string_view marker_type, uint64_t frame_number)
{
    // Markers are dispatched to all decoders and consumers so de-duplicate them for JSON
    // output in case the build has multiple JSON consumers for different APIs enabled.
    if (frame_number != last_frame_number_ || name != last_marker_name_ || marker_type != last_marker_type_)
    {
        auto& json_data = WriteBlockStart();

        nlohmann::ordered_json& state = json_data[name];
        state["marker_type"]          = marker_type;
        state["frame_number"]         = frame_number;

        WriteBlockEnd();

        last_marker_name_  = name;
        last_marker_type_  = marker_type;
        last_frame_number_ = frame_number;
    }
}

nlohmann::ordered_json& JsonWriter::WriteMetaCommandStart(const std::string_view command_name)
{
    auto& json_data = WriteBlockStart();

    if (!json_options_.no_index)
    {
        json_data[format::kNameIndex] = block_index_;
    }
    nlohmann::ordered_json& meta = json_data[format::kNameMeta];
    meta[format::kNameName]      = command_name;
    return meta[format::kNameArgs];
}

void JsonWriter::ProcessAnnotation(uint64_t               block_index,
                                   format::AnnotationType type,
                                   const std::string&     label,
                                   const std::string&     data)
{
    auto& json_data = WriteBlockStart();
    if (!json_options_.no_index)
    {
        json_data[format::kNameIndex] = block_index;
    }
    auto& annotation    = json_data["annotation"];
    annotation["type"]  = util::AnnotationTypeToString(type);
    annotation["label"] = label;
    annotation["data"]  = data;
    WriteBlockEnd();
}

std::string JsonWriter::GenerateFilename(const std::string_view filename)
{
    num_files_++;
    return std::to_string(num_files_).append("_").append(filename);
}

bool JsonWriter::WriteBinaryFile(const std::string& filename, uint64_t data_size, const uint8_t* data)
{
    FILE* file_output = nullptr;
    if (util::platform::FileOpen(&file_output, filename.c_str(), "wb") == 0)
    {
        bool success = util::platform::FileWrite(data, static_cast<size_t>(data_size), file_output);
        util::platform::FileClose(file_output);
        return success;
    }
    return false;
}

void RepresentBinaryFile(JsonWriter&             writer,
                         nlohmann::ordered_json& jdata,
                         std::string_view        filename_base,
                         const uint64_t          data_size,
                         const uint8_t* const    data)
{
    const util::JsonOptions& json_options = writer.GetOptions();
    if (json_options.dump_binaries)
    {
        std::string filename = writer.GenerateFilename(filename_base);
        std::string basename = gfxrecon::util::filepath::Join(json_options.data_sub_dir, filename);
        std::string filepath = gfxrecon::util::filepath::Join(json_options.root_dir, basename);
        if (writer.WriteBinaryFile(filepath, data_size, data))
        {
            FieldToJson(jdata, basename, json_options);
        }
        else
        {
            FieldToJson(jdata, format::kValWriteFailed, json_options);
        }
    }
    else
    {
        FieldToJson(jdata, format::kValBinary, json_options);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
