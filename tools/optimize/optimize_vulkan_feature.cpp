/*
** Copyright (c) 2020-2026 LunarG, Inc.
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

#include "optimize_vulkan_feature.h"

#include "file_optimizer.h"
#include "decode/file_processor.h"
#include "generated/generated_vulkan_referenced_block_consumer.h"
#include "generated/generated_vulkan_referenced_resource_consumer.h"
#include "util/feature_module_registry.h"
#include "util/logging.h"

#include <cinttypes>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(optimize)

GFXR_UTIL_REGISTER_FEATURE_CREATOR(OptimizeFeature, OptimizeVulkanFeature)

void OptimizeVulkanFeature::RegisterDetectionDecoder(decode::FileProcessor& file_processor, uint64_t block_limit)
{
    // Destroy decoder before consumer: decoder holds a raw pointer to consumer.
    detection_decoder_.reset();
    detection_consumer_ = std::make_unique<decode::VulkanDetectionConsumer>(block_limit);
    detection_decoder_  = std::make_unique<decode::VulkanDecoder>();
    detection_decoder_->AddConsumer(detection_consumer_.get());
    file_processor.AddDecoder(detection_decoder_.get());
}

bool OptimizeVulkanFeature::WasDetected() const
{
    return detection_consumer_ != nullptr && detection_consumer_->WasVulkanAPIDetected();
}

bool OptimizeVulkanFeature::ShouldRun(const util::ArgumentParser& args) const
{
    return WasDetected();
}

bool OptimizeVulkanFeature::GetUnreferencedResources(const std::string&                    input_filename,
                                                     std::unordered_set<format::HandleId>& unreferenced_ids)
{
    decode::FileProcessor file_processor;
    if (!file_processor.Initialize(input_filename))
    {
        return false;
    }

    decode::VulkanDecoder                    decoder;
    decode::VulkanReferencedResourceConsumer resref_consumer;
    decoder.AddConsumer(&resref_consumer);
    file_processor.AddDecoder(&decoder);
    file_processor.ProcessAllFrames();

    if (file_processor.GetCurrentFrameNumber() == 0)
    {
        GFXRECON_WRITE_CONSOLE("File did not contain any frames");
        return false;
    }

    if (file_processor.GetErrorState() != decode::BlockIOError::kErrorNone)
    {
        GFXRECON_WRITE_CONSOLE("A failure has occurred during file processing");
        return false;
    }

    resref_consumer.GetReferencedHandleIds(nullptr, &unreferenced_ids);
    return true;
}

bool OptimizeVulkanFeature::FilterUnreferencedResources(const std::string&                          input_filename,
                                                        const std::string&                          output_filename,
                                                        const std::unordered_set<format::HandleId>& unreferenced_ids)
{
    // Collect the block indices that correspond to unreferenced resources.
    decode::FileProcessor file_processor;
    if (!file_processor.Initialize(input_filename))
    {
        return false;
    }

    decode::VulkanDecoder                 decoder;
    decode::VulkanReferencedBlockConsumer block_ref_consumer(unreferenced_ids);
    decoder.AddConsumer(&block_ref_consumer);
    file_processor.AddDecoder(&decoder);
    file_processor.ProcessAllFrames();

    if (file_processor.GetErrorState() != decode::BlockIOError::kErrorNone)
    {
        GFXRECON_WRITE_CONSOLE("A failure has occurred during file processing");
        return false;
    }

    uint64_t                     num_blocks          = file_processor.GetCurrentBlockIndex();
    std::unordered_set<uint64_t> unreferenced_blocks = block_ref_consumer.GetUnreferencedBlocks();

    // Stream the input to the output, dropping unreferenced blocks.
    FileOptimizer file_optimizer(unreferenced_ids, unreferenced_blocks);
    if (!file_optimizer.Initialize(input_filename, output_filename))
    {
        return false;
    }

    file_optimizer.Process();

    if (file_optimizer.GetErrorState() != decode::BlockIOError::kErrorNone)
    {
        GFXRECON_WRITE_CONSOLE("A failure has occurred during file processing");
        return false;
    }

    GFXRECON_WRITE_CONSOLE(
        "Resource filtering complete - Removed %zu / %" PRIu64 " blocks", unreferenced_blocks.size(), num_blocks);
    GFXRECON_WRITE_CONSOLE("\tOriginal file size: %" PRIu64 " bytes", file_optimizer.GetNumBytesRead());
    GFXRECON_WRITE_CONSOLE("\tOptimized file size: %" PRIu64 " bytes", file_optimizer.GetNumBytesWritten());
    return true;
}

bool OptimizeVulkanFeature::Optimize(const std::string&          input_filename,
                                     const std::string&          output_filename,
                                     const util::ArgumentParser& args)
{
    GFXRECON_WRITE_CONSOLE("Scanning Vulkan file %s for unreferenced resources.", input_filename.c_str());

    std::unordered_set<format::HandleId> unreferenced_ids;
    if (!GetUnreferencedResources(input_filename, unreferenced_ids))
    {
        return false;
    }

    if (unreferenced_ids.empty())
    {
        GFXRECON_WRITE_CONSOLE("No unused resources detected. A new file will not be created.");
        return true;
    }

    GFXRECON_WRITE_CONSOLE("Writing optimized file, removing initialization data for %" PRIu64 " unused resources.",
                           unreferenced_ids.size());
    return FilterUnreferencedResources(input_filename, output_filename, unreferenced_ids);
}

GFXRECON_END_NAMESPACE(optimize)
GFXRECON_END_NAMESPACE(gfxrecon)
