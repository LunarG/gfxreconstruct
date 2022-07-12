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
#include "decode/dx12_object_info.h"
#include "generated/generated_dx12_replay_consumer.h"
#include "decode/dx12_resource_value_tracker.h"
#include "decode/file_processor.h"

#include <map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

struct Dx12OptimizationInfo
{
    // PSO removal
    std::unordered_set<uint64_t>         unreferenced_blocks;
    decode::UnreferencedPsoCreationCalls calls_info{};

    // DXR optimization
    decode::Dx12FillCommandResourceValueMap fill_command_resource_values;
};

class Dx12ResourceValueTrackingConsumer : public decode::Dx12ReplayConsumer
{
  public:
    Dx12ResourceValueTrackingConsumer(std::shared_ptr<application::Application> application,
                                      const decode::DxReplayOptions&            options) :
        Dx12ReplayConsumer(application, options)
    {
        GetResourceValueMapper()->EnableResourceValueTracker();
    }

    auto GetTrackedResourceValues() { return GetResourceValueMapper()->GetTrackedResourceValues(); }
};

void CreateResourceValueTrackingConsumer(decode::FileProcessor*                              file_processor,
                                         std::unique_ptr<Dx12ResourceValueTrackingConsumer>& dx12_replay_consumer,
                                         std::shared_ptr<application::Application>&          application)
{
    // Dx12ReplayConsumer requires a windowed application.
    application = std::make_shared<gfxrecon::application::Application>("GFXReconstruct Optimizer - analyzing file",
                                                                       file_processor);
    application->InitializeDx12WsiContext();

    // Use default replay options.
    decode::DxReplayOptions dx_replay_options;

    // Create the replay consumer.
    dx12_replay_consumer = std::make_unique<Dx12ResourceValueTrackingConsumer>(application, dx_replay_options);
    dx12_replay_consumer->SetFatalErrorHandler([](const char* message) { throw std::runtime_error(message); });
}

bool GetDx12OptimizationInfo(const std::string&             input_filename,
                             const Dx12OptimizationOptions& options,
                             Dx12OptimizationInfo&          info)
{
    bool result = false;

    std::shared_ptr<application::Application> application;
    decode::FileProcessor file_processor;
    if (file_processor.Initialize(input_filename))
    {
        gfxrecon::decode::Dx12Decoder                      decoder;
        gfxrecon::decode::Dx12ObjectScanningConsumer       resref_consumer;
        std::unique_ptr<Dx12ResourceValueTrackingConsumer> resource_value_tracking_consumer = nullptr;

        if (options.remove_redundant_psos)
        {
            GFXRECON_WRITE_CONSOLE("Scanning D3D12 file %s for unreferenced objects.", input_filename.c_str());
            decoder.AddConsumer(&resref_consumer);
        }

        if (options.optimize_dxr)
        {
            GFXRECON_WRITE_CONSOLE("Scanning D3D12 file %s for DXR optimization information.", input_filename.c_str());
            CreateResourceValueTrackingConsumer(&file_processor, resource_value_tracking_consumer, application);
            decoder.AddConsumer(resource_value_tracking_consumer.get());
        }

        file_processor.AddDecoder(&decoder);

        // If a windowed application was created, run it. Otherwise process using the file_processor directly.
        if (application)
        {
            application->Run();
        }
        else
        {
            file_processor.ProcessAllFrames();
        }

        if ((file_processor.GetCurrentFrameNumber() > 0) &&
            (file_processor.GetErrorState() == gfxrecon::decode::FileProcessor::kErrorNone) &&
            file_processor.EntireFileWasProcessed())
        {
            if (options.remove_redundant_psos)
            {
                resref_consumer.GetUnreferencedObjectCreationBlocks(&info.unreferenced_blocks, &info.calls_info);
            }

            if (options.optimize_dxr)
            {
                info.fill_command_resource_values = resource_value_tracking_consumer->GetTrackedResourceValues();
            }

            GFXRECON_WRITE_CONSOLE("Finished scanning capture file.");

            result = true;
        }
        else if (file_processor.GetErrorState() != gfxrecon::decode::FileProcessor::kErrorNone)
        {
            GFXRECON_WRITE_CONSOLE("A failure has occurred during capture processing");
        }
        else if (!file_processor.EntireFileWasProcessed())
        {
            GFXRECON_WRITE_CONSOLE("Failed to process the entire capture file.");
        }
        else
        {
            GFXRECON_WRITE_CONSOLE("Capture did not contain any frames");
        }
    }

    return result;
}

bool ApplyDx12OptimizationInfo(const std::string&             input_filename,
                               const std::string&             output_filename,
                               const Dx12OptimizationOptions& options,
                               const Dx12OptimizationInfo&    info)
{
    bool result = false;

    gfxrecon::FileOptimizer file_optimizer;
    if (file_optimizer.Initialize(input_filename, output_filename))
    {
        file_optimizer.SetUnreferencedBlocks(info.unreferenced_blocks);

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

bool Dx12OptimizeFile(std::string input_filename, std::string output_filename, const Dx12OptimizationOptions& options)
{
    // Return early if no DX12 optimizations were enabled.
    if (!options.remove_redundant_psos && !options.optimize_dxr)
    {
        return true;
    }

    // Run a scanning pass to collect the necessary optimization info.
    Dx12OptimizationInfo info;
    bool                 scan_result = GetDx12OptimizationInfo(input_filename, options, info);
    if (scan_result == false)
    {
        GFXRECON_WRITE_CONSOLE("File processing has encountered a fatal error and cannot continue.");
        return false;
    }

    // Use the result of the scanning pass to write an optimized file.
    if (!info.unreferenced_blocks.empty())
    {
        auto& calls_info = info.calls_info;

        GFXRECON_WRITE_CONSOLE("Writing optimized file, removing %" PRIu64 " unused pso related calls.",
                               info.unreferenced_blocks.size());
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
        bool filter_result = ApplyDx12OptimizationInfo(input_filename, output_filename, options, info);
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

GFXRECON_END_NAMESPACE(gfxrecon)
