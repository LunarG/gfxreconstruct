/*
** Copyright (c) 2022 LunarG, Inc.
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

#include "dx12_optimize_util.h"

#include "file_optimizer.h"
#include "decode/file_processor.h"

bool GetUnreferencedObjectCreationBlocks(const std::string&                              input_filename,
                                         std::unordered_set<uint64_t>*                   unreferenced_blocks,
                                         gfxrecon::decode::UnreferencedPsoCreationCalls* calls_info)
{
    GFXRECON_ASSERT(unreferenced_blocks != nullptr);

    bool result = false;

    gfxrecon::decode::FileProcessor file_processor;
    if (file_processor.Initialize(input_filename))
    {
        gfxrecon::decode::Dx12Decoder                decoder;
        gfxrecon::decode::Dx12ObjectScanningConsumer resref_consumer;

        decoder.AddConsumer(&resref_consumer);

        file_processor.AddDecoder(&decoder);
        file_processor.ProcessAllFrames();

        if ((file_processor.GetCurrentFrameNumber() > 0) &&
            (file_processor.GetErrorState() == gfxrecon::decode::FileProcessor::kErrorNone))
        {
            resref_consumer.GetUnreferencedObjectCreationBlocks(unreferenced_blocks, calls_info);
            result = true;
        }
        else if (file_processor.GetErrorState() != gfxrecon::decode::FileProcessor::kErrorNone)
        {
            GFXRECON_WRITE_CONSOLE("A failure has occurred during capture processing");
        }
        else
        {
            GFXRECON_WRITE_CONSOLE("Capture did not contain any frames");
        }
    }

    return result;
}

bool FilterUnreferencedObjectCreationBlocks(const std::string&             input_filename,
                                            const std::string&             output_filename,
                                            std::unordered_set<uint64_t>&& unreferenced_blocks)
{
    bool result = false;

    gfxrecon::FileOptimizer file_optimizer;
    if (file_optimizer.Initialize(input_filename, output_filename))
    {
        file_optimizer.SetUnreferencedBlocks(unreferenced_blocks);

        file_optimizer.Process();

        // In a way, "resultant_objects = 0" will prove the two scan passes match.
        uint64_t resultant_objects = file_optimizer.GetUnreferencedBlocksSize();

        if ((file_optimizer.GetErrorState() != gfxrecon::FileOptimizer::kErrorNone) || resultant_objects > 0)
        {
            GFXRECON_WRITE_CONSOLE("A failure has occurred during capture processing");
        }
        else
        {
            GFXRECON_WRITE_CONSOLE("Object removal complete.");
            GFXRECON_WRITE_CONSOLE("\tOriginal file size: %" PRIu64 " bytes", file_optimizer.GetNumBytesRead());
            GFXRECON_WRITE_CONSOLE("\tOptimized file size: %" PRIu64 " bytes", file_optimizer.GetNumBytesWritten());
            result = true;
        }
    }

    return result;
}

bool D3D12RemoveRedundantPSOs(std::string input_filename, std::string output_filename)
{
    GFXRECON_WRITE_CONSOLE("Scanning D3D12 file %s for unreferenced objects.", input_filename.c_str());
    std::unordered_set<uint64_t>                   unreferenced_blocks;
    gfxrecon::decode::UnreferencedPsoCreationCalls calls_info;

    bool scan_result = GetUnreferencedObjectCreationBlocks(input_filename, &unreferenced_blocks, &calls_info);

    if (scan_result == false)
    {
        GFXRECON_WRITE_CONSOLE("File processing has encountered a fatal error and cannot continue.");
        return false;
    }

    if (!unreferenced_blocks.empty())
    {
        GFXRECON_WRITE_CONSOLE("Writing optimized file, removing %" PRIu64 " unused pso related calls.",
                               unreferenced_blocks.size());
        if (calls_info.graphics_pso_creation_calls > 0)
        {
            GFXRECON_WRITE_CONSOLE("Removing %" PRIu64 " graphics pso creation calls.",
                                   calls_info.graphics_pso_creation_calls);
        }
        if (calls_info.compute_pso_creation_calls > 0)
        {
            GFXRECON_WRITE_CONSOLE("Removing %" PRIu64 " compute pso creation calls.",
                                   calls_info.compute_pso_creation_calls);
        }
        if (calls_info.storepipeline_calls > 0)
        {
            GFXRECON_WRITE_CONSOLE("Removing %" PRIu64 " storepipeline calls.", calls_info.storepipeline_calls);
        }

        // Filter unreferenced ids.
        bool filter_result =
            FilterUnreferencedObjectCreationBlocks(input_filename, output_filename, std::move(unreferenced_blocks));
        if (filter_result == false)
        {
            GFXRECON_WRITE_CONSOLE("Falure creating the optimized file.");
            return false;
        }
    }
    else
    {
        GFXRECON_WRITE_CONSOLE("No redundant PSOs detected. Optimized trace will not be created.",
                               input_filename.c_str());
    }
    return true;
}
