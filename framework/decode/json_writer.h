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

#ifndef GFXRECON_DECODE_JSON_WRITER_H
#define GFXRECON_DECODE_JSON_WRITER_H

#include "annotation_handler.h"
#include "util/json_util.h"
#include "util/platform.h"
#include "util/defines.h"
#include "format/format_json.h"

#include "nlohmann/json.hpp"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
class OutputStream;
GFXRECON_END_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(decode)

struct ApiCallInfo;

/// Manages writing
class JsonWriter : public AnnotationHandler
{
  public:
    JsonWriter(const util::JsonOptions& options,
               const std::string_view   gfxrVersion,
               const std::string_view   inputFilepath);
    ~JsonWriter();

    /// Output any data associated with the start of a logical stream such as a header object.
    void StartStream(util::OutputStream* os);
    /// Output data at end of stream such as closing the JSON array.
    void EndStream();
    void Destroy();
    bool IsValid() const;

    /// Get a clean fresh JSON tree to build a block's representation in.
    /// Users can build the JSON representation of their blocks in this tree before
    /// calling WriteBlockEnd() to serialize it out to the stream.
    nlohmann::ordered_json& WriteBlockStart();

    /// Finalise the current block and stream it out.
    void WriteBlockEnd();

    /// Start the JSON tree for a function call, building the top-level object
    /// with index and function fields, adding name and thread to the function.
    /// @return The "function" object field for the caller to populate further
    /// with return value if any and arguments.
    nlohmann::ordered_json& WriteApiCallStart(const ApiCallInfo& call_info, const std::string_view command_name);

    /// Start the JSON tree for a method call, building the top-level object
    /// with index and function fields, adding name and thread to the function.
    /// @return The "method" object field for the caller to populate further
    /// with return value if any and arguments.
    nlohmann::ordered_json& WriteApiCallStart(const ApiCallInfo&     call_info,
                                              const std::string_view object_type,
                                              const format::HandleId object_id,
                                              const std::string_view command_name);

    void WriteMarker(const char* name, const std::string_view marker_type, uint64_t frame_number);

    /// @brief Output the boilerplate for representing a metadata block in JSON,
    /// returning the root of the empty "args" JSON sub-tree for the caller to populate.
    nlohmann::ordered_json& WriteMetaCommandStart(const std::string_view command_name);

    /// Get the JSON object used to output the per-stream header
    /// Consumers can add their own fields to it.
    nlohmann::ordered_json& GetHeaderJson() { return header_; }

    /// Get the root of the JSON tree for the current block.
    nlohmann::ordered_json& GetBlockJson() { return json_data_; }

    const util::JsonOptions& GetOptions() const { return json_options_; }

    uint32_t GetNumStreams() const { return num_streams_; }

    /// @brief Convert annotations, which are simple {type:enum, key:string, value:string} objects.
    virtual void ProcessAnnotation(uint64_t               block_index,
                                   format::AnnotationType type,
                                   const std::string&     label,
                                   const std::string&     data) override;

    std::string GenerateFilename(const std::string_view filename);
    bool        WriteBinaryFile(const std::string& filename, uint64_t data_size, const uint8_t* data);

    inline void SetCurrentBlockIndex(uint64_t block_index) { block_index_ = block_index; }

  private:
    util::OutputStream*    os_;
    nlohmann::ordered_json header_;
    util::JsonOptions      json_options_;
    nlohmann::ordered_json json_data_;
    uint64_t               block_index_;
    uint32_t               num_streams_{ 0 };
    /// Number of side-files generated for dumping binary blobs etc.
    uint32_t num_files_{ 0 };

    // Account for markers being broadcast to all decoders, all consumers, unlike functions and metadata blocks which
    // are tagged with an API family. A marker is only converted if it differs in one of these three attributes.
    std::string last_marker_name_;
    std::string last_marker_type_;
    uint64_t    last_frame_number_{ 0 };

    bool first_{ true };
};

/// Either write the binary data to a file, and put the filename in the tree or
/// put the tag format::kValBinary in the tree to indicate it
void RepresentBinaryFile(JsonWriter&             writer,
                         nlohmann::ordered_json& jdata,
                         const std::string_view  filename_base,
                         const uint64_t          data_size,
                         const uint8_t* const    data);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_JSON_WRITER_H
