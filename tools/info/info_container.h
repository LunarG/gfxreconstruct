/*
** Copyright (c) 2026 LunarG, Inc.
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

#ifndef GFXRECON_INFO_CONTAINER_H
#define GFXRECON_INFO_CONTAINER_H

#include "decode/decode_api_detection.h"
#include "decode/file_processor.h"
#include "decode/info_consumer.h"
#include "decode/info_decoder.h"
#include "decode/stat_consumer.h"
#include "decode/stat_decoder_base.h"
#include "decode/stat_consumer_base.h"
#include "format/format.h"
#include "format/format_util.h"

#include "info_api_interface.h"

#include <memory>
#include <vector>

#include <nlohmann/json.hpp>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(info)

class InfoContainer
{
  public:
    InfoContainer();
    ~InfoContainer();

    bool RegisterApiInterface(std::unique_ptr<InfoApiInterface> api_interface);

    void PrintUsage();
    bool ProcessCommandLine(int32_t argc, const char** argv);

    bool ProcessCapture();

    bool OutputContent();

    // Temporary - only for transition (will be removed)
    std::string GetInputFilename()
    {
        return argument_parser_->GetPositionalArguments().size() > 0 ? argument_parser_->GetPositionalArguments()[0]
                                                                     : "";
    }
    InfoApiInterface::InfoOutputLevel GetOutputLevel() { return output_level_; }

  protected:
    bool CheckOptionPrintUsage(const gfxrecon::util::ArgumentParser& arg_parser);
    bool CheckOptionPrintVersion(const gfxrecon::util::ArgumentParser& arg_parser);

    void PrintVersion();

    void WriteOutput(const std::string& message);

  private:
    class AnnotationRecorder : public gfxrecon::decode::AnnotationHandler
    {
      public:
        std::vector<std::string> operation_annotations_;

        virtual void ProcessAnnotation(uint64_t                         block_index,
                                       gfxrecon::format::AnnotationType type,
                                       const std::string&               label,
                                       const std::string&               data) override
        {
            if (type == gfxrecon::format::AnnotationType::kJson &&
                label.compare(gfxrecon::format::kAnnotationLabelOperation) == 0)
            {
                if (data.size() > 0)
                {
                    // Inspect annotations spotted in the capture file
                    nlohmann::json json_obj = nlohmann::json::parse(data);
                    if (json_obj.is_discarded())
                    {
                        GFXRECON_LOG_WARNING("Invalid JSON in annotation: \"%s\"", data.c_str());
                    }
                    else
                    {
                        operation_annotations_.push_back(data);
                    }
                }
            }
        }
    };

    struct ApiAgnosticStats
    {
        gfxrecon::format::CompressionType compression_type;
        uint32_t                          trim_start_frame;
        uint32_t                          frame_count;
        gfxrecon::decode::BlockIOError    error_state;
        uint32_t                          blank_frame_count;
        bool                              uses_frame_markers;
    };

    struct FileFormatInfo
    {
        uint32_t major_version               = 0;
        uint32_t minor_version               = 0;
        bool     uses_frame_markers          = false;
        bool     file_supports_frame_markers = false;

        FileFormatInfo(const gfxrecon::decode::FileProcessor& file_processor)
        {
            const gfxrecon::format::FileHeader& file_header = file_processor.GetFileHeader();
            major_version                                   = file_header.major_version;
            minor_version                                   = file_header.minor_version;
            uses_frame_markers                              = file_processor.UsesFrameMarkers();
            file_supports_frame_markers                     = file_processor.FileSupportsFrameMarkers();
        }

        bool NeedsUpdate() const
        {
            return major_version == 0 && minor_version == 0 && uses_frame_markers && !file_supports_frame_markers;
        }
    };

    std::string                                     app_name_;
    InfoApiInterface::InfoOutputLevel               output_level_{ InfoApiInterface::InfoOutputLevel::kBasic };
    std::ofstream                                   output_file_;
    std::vector<std::unique_ptr<InfoApiInterface>>  api_interfaces_;
    bool                                            api_restricted_output_{ false };
    gfxrecon::decode::FileProcessor                 file_processor_;
    gfxrecon::decode::StatDecoderBase               stat_decoder_;
    gfxrecon::decode::StatConsumer                  stat_consumer_;
    gfxrecon::decode::InfoConsumer                  info_consumer_;
    gfxrecon::decode::InfoDecoder                   info_decoder_;
    AnnotationRecorder                              annotation_recorder_;
    std::shared_ptr<gfxrecon::util::ArgumentParser> argument_parser_;
};

GFXRECON_END_NAMESPACE(info)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_INFO_CONTAINER_H
