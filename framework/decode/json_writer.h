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
#include "decode/vulkan_json_util.h"
#include "util/platform.h"
#include "util/defines.h"

#include "nlohmann/json.hpp"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
class OutputStream;
GFXRECON_END_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(decode)

/// Manages writing
class JsonWriter : public AnnotationHandler
{
  public:
    JsonWriter(const JsonOptions& options, const std::string_view gfxrVersion, const std::string_view inputFilepath);
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

    /// Get the JSON object used to output the per-stream header
    /// Consumers can add their own fields to it.
    nlohmann::ordered_json& GetHeaderkJson() { return header_; }

    /// Get the root of the JSON tree for the current block.
    nlohmann::ordered_json& GetBlockJson() { return json_data_; }

    const JsonOptions& GetOptions() const { return json_options_; }

    uint32_t GetNumStreams() const { return num_streams_; }

    /// @brief Convert annotations, which are simple {type:enum, key:string, value:string} objects.
    virtual void ProcessAnnotation(uint64_t               block_index,
                                   format::AnnotationType type,
                                   const std::string&     label,
                                   const std::string&     data) override;

  private:
    util::OutputStream*    os_;
    nlohmann::ordered_json header_;
    JsonOptions            json_options_;
    nlohmann::ordered_json json_data_;
    uint32_t               num_streams_{ 0 };
    bool                   first_{ true };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_JSON_WRITER_H
