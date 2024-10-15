/*
** Copyright (c) 2023 LunarG, Inc.
** Copyright (c) 2023 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#ifndef GFXRECON_DECODE_VULKAN_PRELOAD_FILE_PROCESSOR_H
#define GFXRECON_DECODE_VULKAN_PRELOAD_FILE_PROCESSOR_H

#include "decode/file_processor.h"
#include "format/format_util.h"

#include "generated/generated_vulkan_preload_decoder.h"
#include "generated/generated_vulkan_preload_replayer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanPreloadFileProcessor : public FileProcessor
{
  public:
    VulkanPreloadFileProcessor();

    void SetPreloadDecoder(VulkanPreloadDecoder* decoder) { vulkan_preload_decoder_ = decoder; }
    void SetConsumer(VulkanReplayConsumer* consumer) { vulkan_preload_replayer_.AddConsumer(consumer); }

    // Preloads *count* frames to continuous, expandable memory buffer
    void PreloadNextFrames(size_t count);

    bool ProcessNextFrame() override;

    void ReplayPreloadedPackets();

  protected:
    bool ProcessFunctionCall(const format::BlockHeader& block_header, format::ApiCallId call_id, bool& should_break);
    bool ProcessMetaData(const format::BlockHeader& block_header, format::MetaDataId meta_data_id);
    bool ProcessStateMarker(const format::BlockHeader& block_header, format::MarkerType marker_type);

  private:
    enum class PreloadStatus
    {
        kInactive,
        kRecord,
        kReplay
    } status_;

    bool ProcessBlocks() override;

    size_t                preload_frames_;
    VulkanPreloadDecoder* vulkan_preload_decoder_;
    VulkanPreloadReplayer vulkan_preload_replayer_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_PRELOAD_FILE_PROCESSOR_H
