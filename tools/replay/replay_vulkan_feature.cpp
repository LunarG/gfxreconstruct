/*
** Copyright (c) 2020-2026 LunarG, Inc.
** Copyright (c) 2022-2024 Advanced Micro Devices, Inc. All rights reserved.
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

#include "replay_vulkan_feature.h"

#include "decode/vulkan_replay_frame_loop_consumer.h"
#include "parse_dump_resources_cli.h"
#if defined(GFXRECON_ENABLE_VULKAN)
#include "encode/vulkan_capture_manager.h"
#include "recapture_vulkan_entry.h"
#endif

#include "plugin/replay_event_plugin_loader.h"
#include "util/api_version_info.h"
#include "util/feature_module_registry.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(replay)

// Register this class as a feature in a module registry
GFXR_UTIL_REGISTER_FEATURE_CREATOR(ReplayFeatureBase, ReplayVulkanFeature)

std::string ReplayVulkanFeature::CompiledHeaderVersionString() const
{
#if defined(GFXRECON_ENABLE_VULKAN)
    return util::GetVulkanHeaderVersionString();
#else
    return "";
#endif
}

void ReplayVulkanFeature::QueryOptions(util::ArgumentParser& arg_parser, const std::string& capture_filename)
{
    capture_filename_    = capture_filename;
    replay_options_      = GetVulkanReplayOptions(arg_parser, capture_filename, &tracked_object_info_table_);
    is_enabled_          = true;
    needs_pre_processor_ = is_enabled_ && replay_options_.enable_dump_resources;
}

void ReplayVulkanFeature::QueryFpsInfoOptions(
    bool& quit_after_range, bool& flush_range, bool& flush_inside_range, bool& preload_range, bool& quit_after_frame)
{
    if (is_enabled_)
    {
        quit_after_range   = replay_options_.quit_after_measurement_frame_range;
        flush_range        = replay_options_.flush_measurement_frame_range;
        flush_inside_range = replay_options_.flush_inside_measurement_range;
        preload_range      = replay_options_.preload_measurement_range;
        quit_after_frame   = replay_options_.quit_after_frame;
    }
}

void ReplayVulkanFeature::CreateConsumer(decode::FileProcessor*                    file_processor,
                                         std::shared_ptr<application::Application> application,
                                         gfxrecon::graphics::FrameLoopInfo*        frame_loop_info)
{
    if (is_enabled_)
    {
        InitConsumer(file_processor, application);

        if (frame_loop_info)
        {
            replay_consumer_ = std::make_unique<gfxrecon::decode::VulkanReplayFrameLoopConsumer>(
                application_, replay_options_, *frame_loop_info);
        }
        else
        {
            replay_consumer_ = std::make_unique<gfxrecon::decode::VulkanReplayConsumer>(application_, replay_options_);
        }

        FinalizeConsumer();
    }
}

std::unique_ptr<gfxrecon::plugin::ReplayEventSink> ReplayVulkanFeature::CreateReplayEventSink()
{
    if (!replay_options_.replay_event_plugin_path.empty())
    {
        return gfxrecon::plugin::LoadPlugin(
            { replay_options_.replay_event_plugin_path, replay_options_.replay_event_plugin_params });
    }
    return ReplayFeature::CreateReplayEventSink();
}

void ReplayVulkanFeature::RegisterDecodeComponents(graphics::FpsInfo* fps_info)
{
    if (is_enabled_)
    {
        RegisterConsumerAndDecoder(fps_info);

        application_->SetPrintBlockInfoFlag(
            replay_options_.enable_print_block_info, replay_options_.block_index_from, replay_options_.block_index_to);
    }
}

void ReplayVulkanFeature::DetectAndSetupRecapture()
{
#if defined(GFXRECON_ENABLE_VULKAN)
    if (is_enabled_ && replay_options_.capture)
    {
        vulkan_recapture::RecaptureVulkanEntry::InitSingleton();

        // Set replay to use the GetInstanceProcAddr function from RecaptureVulkanEntry so that replay first
        // calls into the capture layer instead of directly into the loader and Vulkan runtime.
        // Set the capture manager's instance and device creation callbacks.
        replay_consumer_->SetupForRecapture(vulkan_recapture::GetInstanceProcAddr,
                                            vulkan_recapture::dispatch_CreateInstance,
                                            vulkan_recapture::dispatch_CreateDevice);
    }
#endif // GFXRECON_ENABLE_VULKAN
}

void ReplayVulkanFeature::CompletePreProcessingPass()
{
    if (needs_pre_processor_)
    {
        is_enabled_ = pre_processor_consumer_->WasVulkanAPIDetected();
        if (is_enabled_)
        {
            if (replay_options_.using_dump_resources_target)
            {
                replay_options_.dump_resources_block_indices = pre_processor_consumer_->GetDumpResourcesBlockIndices();
            }

            if (replay_options_.enable_dump_resources)
            {
                // Process --dump-resources block indices arg.
                if (!parse_dump_resources::parse_dump_resources_arg(replay_options_))
                {
                    GFXRECON_LOG_FATAL("There was an error while parsing dump resources indices. Terminating.");
                    exit(1);
                }
                replay_consumer_->InitializeReplayDumpResources();
            }
        }

        TeardownPreProcess();
    }
}

void ReplayVulkanFeature::Destroy()
{
    replay_consumer_.reset();

#if defined(GFXRECON_ENABLE_VULKAN)
    if (is_enabled_ && replay_options_.capture)
    {
        vulkan_recapture::RecaptureVulkanEntry::DestroySingleton();
    }
#endif // GFXRECON_ENABLE_VULKAN
}

GFXRECON_END_NAMESPACE(replay)
GFXRECON_END_NAMESPACE(gfxrecon)
