/*
** Copyright (c) 2026 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#include <catch2/catch.hpp>
#include "decode/annotation_handler.h"
#include "decode/file_processor.h"
#include "decode/preload_file_processor.h"
#include "decode/vulkan_decoder_base.h"

#include <chrono>
#include <filesystem>
#include <fstream>

using namespace gfxrecon;

TEST_CASE("Block skip ranges preserve structural blocks and wide indices", "[skip-index]")
{
    decode::file_processor::BlockSkipRanges skip;
    skip.SetRanges({ { 10, 20 }, { 0, 0 }, { 7, 10 }, { 18, 25 }, { UINT32_MAX, UINT32_MAX } });
    const auto type = GENERATE(format::kFunctionCallBlock,
                               format::kMethodCallBlock,
                               format::kMetaDataBlock,
                               format::kCompressedFunctionCallBlock,
                               format::kCompressedMethodCallBlock,
                               format::kCompressedMetaDataBlock);
    for (uint64_t index = 0; index <= 30; ++index)
    {
        REQUIRE(skip(index, type) == (index == 0 || (index >= 7 && index <= 25)));
    }
    REQUIRE(skip(UINT32_MAX, type));
    REQUIRE_FALSE(skip(static_cast<uint64_t>(UINT32_MAX) + 1, type));
    REQUIRE_FALSE(skip(UINT64_MAX, type));
    for (auto marker : { format::kFrameMarkerBlock, format::kStateMarkerBlock, format::kAnnotation })
    {
        REQUIRE_FALSE(skip(7, marker));
    }
    skip.SetRanges({ { 0, UINT32_MAX }, { UINT32_MAX, UINT32_MAX } });
    REQUIRE(skip(2147483648U, type));
    REQUIRE(skip(UINT32_MAX, type));
    skip.SetRanges({});
    REQUIRE_FALSE(skip(7, type));
    skip.SetRanges({ { 3, 2 } });
    REQUIRE_FALSE(skip(3, type));
}

namespace
{
class RecordingDecoder : public decode::VulkanDecoderBase, public decode::AnnotationHandler
{
  public:
    explicit RecordingDecoder(decode::FileProcessor& processor) : processor_(processor) {}
    bool IsComplete(uint64_t) override { return false; }
    bool SupportsApiCall(format::ApiCallId) override { return true; }
    void DecodeFunctionCall(format::ApiCallId, const decode::ApiCallInfo&, const uint8_t*, size_t) override
    {
        calls.push_back(processor_.GetCurrentBlockIndex());
    }
    void
    DecodeMethodCall(format::ApiCallId, format::HandleId, const decode::ApiCallInfo&, const uint8_t*, size_t) override
    {
        calls.push_back(processor_.GetCurrentBlockIndex());
    }
    void DispatchDisplayMessageCommand(format::ThreadId, const std::string&) override
    {
        calls.push_back(processor_.GetCurrentBlockIndex());
    }
    void DispatchStateBeginMarker(uint64_t) override
    {
        REQUIRE(processor_.GetLoadingTrimmedState());
        markers.push_back(processor_.GetCurrentBlockIndex());
    }
    void DispatchStateEndMarker(uint64_t) override
    {
        REQUIRE_FALSE(processor_.GetLoadingTrimmedState());
        markers.push_back(processor_.GetCurrentBlockIndex());
    }
    void DispatchFrameEndMarker(uint64_t) override { markers.push_back(processor_.GetCurrentBlockIndex()); }
    void ProcessAnnotation(uint64_t index, format::AnnotationType, const std::string&, const std::string&) override
    {
        annotations.push_back(index);
    }
    std::vector<uint64_t> calls, markers, annotations;

  private:
    decode::FileProcessor& processor_;
};

struct CaptureFile
{
    std::filesystem::path path =
        std::filesystem::temp_directory_path() /
        ("gfxrecon-skip-index-" + std::to_string(std::chrono::steady_clock::now().time_since_epoch().count()) +
         ".gfxr");
    ~CaptureFile() { std::filesystem::remove(path); }
};
} // namespace

TEST_CASE("File processing skips only selected calls in synchronous and asynchronous replay", "[skip-index]")
{
    const bool  async          = GENERATE(false, true);
    const bool  use_ranges     = GENERATE(false, true);
    const bool  optimizer_skip = GENERATE(false, true);
    const bool  preload        = GENERATE(false, true);
    CaptureFile capture;
    {
        std::ofstream output(capture.path, std::ios::binary);
        auto          write = [&output](const auto& value) {
            output.write(reinterpret_cast<const char*>(&value), sizeof(value));
        };
        write(format::FileHeader{ GFXRECON_FOURCC, GFXRECON_CURRENT_FILE_MAJOR, GFXRECON_CURRENT_FILE_MINOR, 0 });
        const auto marker_size  = sizeof(format::Marker) - sizeof(format::BlockHeader);
        const auto call_size    = sizeof(format::FunctionCallHeader) - sizeof(format::BlockHeader);
        const auto method_size  = sizeof(format::MethodCallHeader) - sizeof(format::BlockHeader);
        const auto message_size = sizeof(format::DisplayMessageCommandHeader) - sizeof(format::BlockHeader);
        const format::FunctionCallHeader call{ { call_size, format::kFunctionCallBlock },
                                               format::ApiCallId::ApiCall_vkCreateInstance,
                                               1 };
        const format::MethodCallHeader   method{
            { method_size, format::kMethodCallBlock }, format::ApiCallId::ApiCall_vkCreateInstance, 1, 1
        };
        const format::DisplayMessageCommandHeader message{ { { message_size, format::kMetaDataBlock },
                                                             format::MakeMetaDataId(
                                                                 format::ApiFamilyId::ApiFamily_Vulkan,
                                                                 format::MetaDataType::kDisplayMessageCommand) },
                                                           1 };
        write(format::Marker{ { marker_size, format::kStateMarkerBlock }, format::kBeginMarker, 1 }); // 0
        write(call);                                                                                  // 1
        write(method);                                                                                // 2
        write(message);                                                                               // 3
        write(format::AnnotationHeader{
            { sizeof(format::AnnotationHeader) - sizeof(format::BlockHeader) + 3, format::kAnnotation },
            format::kJson,
            1,
            2 }); // 4
        output.write("x{}", 3);
        write(format::Marker{ { marker_size, format::kStateMarkerBlock }, format::kEndMarker, 1 }); // 5
        write(call);                                                                                // 6
        write(format::Marker{ { marker_size, format::kFrameMarkerBlock }, format::kEndMarker, 1 }); // 7
        write(method);                                                                              // 8
        write(message);                                                                             // 9
        write(format::Marker{ { marker_size, format::kFrameMarkerBlock }, format::kEndMarker, 2 }); // 10
        REQUIRE(output.good());
    }
    std::unique_ptr<decode::FileProcessor> processor_owner;
    if (preload)
    {
        processor_owner = std::make_unique<decode::PreloadFileProcessor>();
    }
    else
    {
        processor_owner = std::make_unique<decode::FileProcessor>();
    }
    auto&            processor = *processor_owner;
    RecordingDecoder decoder(processor);
    processor.AddDecoder(&decoder);
    processor.SetAnnotationProcessor(&decoder);
    if (use_ranges)
    {
        processor.SetSkipBlockIndices({ { 7, 7 }, { 0, 5 }, { 1, 2 } });
    }
    if (optimizer_skip)
    {
        processor.SetBlocksToSkip({ 1, 6 }); // Index 1 overlaps configured ranges; completion must still be reported.
    }
    REQUIRE(processor.Initialize(capture.path.string()));
    decode::file_processor::FrameProcessingParams params;
    params.async = async;
    REQUIRE(processor.InitializeFrameProcessing(params));
    if (preload)
    {
        static_cast<decode::PreloadFileProcessor&>(processor).PreloadNextFrames(2);
    }
    REQUIRE(processor.ProcessAllFrames());
    std::vector<uint64_t> expected;
    for (auto index : { 1, 2, 3, 6, 8, 9 })
    {
        if (!(use_ranges && index <= 5) && !(optimizer_skip && (index == 1 || index == 6)))
        {
            expected.push_back(index);
        }
    }
    REQUIRE(decoder.calls == expected);
    REQUIRE(decoder.markers == std::vector<uint64_t>{ 0, 5, 7, 10 });
    REQUIRE(decoder.annotations == std::vector<uint64_t>{ 4 });
    REQUIRE(processor.IsSkippingFinished());
    REQUIRE(processor.EntireFileWasProcessed());
}
