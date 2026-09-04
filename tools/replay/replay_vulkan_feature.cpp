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

#include "tool_feature_options.h"

#include "decode/vulkan_replay_frame_loop_consumer.h"
#include "parse_dump_resources_cli.h"
#if defined(GFXRECON_ENABLE_VULKAN)
#include "encode/vulkan_capture_manager.h"
#include "recapture_vulkan_entry.h"
#endif

#include "plugin/replay_event_plugin_loader.h"
#include "util/api_version_info.h"
#include "util/feature_module_registry.h"
#include "decode/vulkan_state_recording_decoder.h"

// Headers for the Vulkan-only option parsing that this file owns.
#include "decode/vulkan_default_allocator.h"
#include "decode/vulkan_realign_allocator.h"
#include "decode/vulkan_rebind_allocator.h"
#include "decode/vulkan_remap_allocator.h"
#include "decode/vulkan_resource_tracking_consumer.h"
#include "generated/generated_vulkan_decoder.h"
#include "util/platform.h"
#include "util/strings.h"

#include <limits>
#include <sstream>
#include <string>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(replay)

// Register this class as a feature in a module registry
GFXR_UTIL_REGISTER_FEATURE_CREATOR(ReplayFeatureBase, ReplayVulkanFeature)

// ----------------------------------------------------------------------------
// Vulkan-only command-line settings.
//
// The names, the values, and the code that reads them stay with this Feature, so that
// tools/tool_settings.h and tools/replay/replay_settings.h keep only the settings that every
// replay Feature shares.
// ----------------------------------------------------------------------------

const char kCaptureLayer[] = "VK_LAYER_LUNARG_gfxreconstruct";

// The environment variable, or on Android the system property, that lists the active layers.
const char kLayerEnvVar[]   = "VK_INSTANCE_LAYERS";
const char kLayerProperty[] = "debug.vulkan.layers";

const char kDebugMessageSeverityArgument[]     = "--debug-messenger-level";
const char kOverrideGpuGroupArgument[]         = "--gpu-group";
const char kCaptureOption[]                    = "--capture";
const char kSkipFailedAllocationShortOption[]  = "--sfa";
const char kSkipFailedAllocationLongOption[]   = "--skip-failed-allocations";
const char kOmitPipelineCacheDataShortOption[] = "--opcd";
const char kOmitPipelineCacheDataLongOption[]  = "--omit-pipeline-cache-data";
const char kSurfaceIndexArgument[]             = "--surface-index";
const char kMemoryPortabilityShortOption[]     = "-m";
const char kMemoryPortabilityLongOption[]      = "--memory-translation";
const char kShaderReplaceArgument[]            = "--replace-shaders";
const char kSwapchainOption[]                  = "--swapchain";
const char kPresentModeOption[]                = "--present-mode";
const char kPresentOverrideImageArgument[]     = "--present-override";
const char kEnableUseCapturedSwapchainIndices[] =
    "--use-captured-swapchain-indices"; // The same: util::SwapchainOption::kCaptured
const char kVirtualSwapchainSkipBlitShortOption[] = "--vssb";
const char kVirtualSwapchainSkipBlitLongOption[]  = "--virtual-swapchain-skip-blit";
const char kColorspaceFallback[]                  = "--use-colorspace-fallback";
const char kOffscreenSwapchainFrameBoundary[]     = "--offscreen-swapchain-frame-boundary";
// The short forms of the two skip-get-fence entries.
const char kSkipGetFenceStatusShortOption[]         = "--sgfs";
const char kSkipGetFenceRangesShortOption[]         = "--sgfr";
const char kSkipGetFenceStatus[]                    = "--skip-get-fence-status";
const char kSkipGetFenceRanges[]                    = "--skip-get-fence-ranges";
const char kWaitBeforePresent[]                     = "--wait-before-present";
const char kAnnotateInjectedCommands[]              = "--annotate-injected-commands";
const char kSavePipelineCacheArgument[]             = "--save-pipeline-cache";
const char kLoadPipelineCacheArgument[]             = "--load-pipeline-cache";
const char kCreateNewPipelineCacheOption[]          = "--add-new-pipeline-caches";
const char kDeduplicateDevice[]                     = "--deduplicate-device";
const char kIdleBeforeSubmit[]                      = "--idle-before-submit";
const char kSerializeRenderPasses[]                 = "--serialize-render-passes";
const char kScreenshotIgnoreFrameBoundaryArgument[] = "--screenshot-ignore-FrameBoundaryANDROID";
const char kScreenshotApplyPrerotationArgument[]    = "--screenshot-apply-prerotation";
const char kSerializeQueueSubmissions[]             = "--serialize-queue-submissions";
const char kReplayEventPluginPath[]                 = "--replay-event-plugin-path";
const char kReplayEventPluginParams[]               = "--replay-event-plugin-params";
const char kIsolateRenderPasses[]                   = "--isolate-render-passes";
const char kSerializeComputeAndTransfer[]           = "--serialize-compute-and-transfer";

const char kMemoryTranslationNone[]    = "none";
const char kMemoryTranslationRemap[]   = "remap";
const char kMemoryTranslationRealign[] = "realign";
const char kMemoryTranslationRebind[]  = "rebind";

const char kSwapchainVirtual[]   = "virtual";
const char kSwapchainCaptured[]  = "captured";
const char kSwapchainOffscreen[] = "offscreen";

const char kPresentModeCapture[]     = "capture";
const char kPresentModeImmediate[]   = "immediate";
const char kPresentModeMailbox[]     = "mailbox";
const char kPresentModeFifo[]        = "fifo";
const char kPresentModeFifoRelaxed[] = "fifo_relaxed";

// The closed sets of accepted values, in the order that the usage text lists them.
const std::vector<std::string> kMemoryTranslationValues = {
    kMemoryTranslationNone, kMemoryTranslationRemap, kMemoryTranslationRealign, kMemoryTranslationRebind
};
const std::vector<std::string> kSwapchainValues   = { kSwapchainVirtual, kSwapchainCaptured, kSwapchainOffscreen };
const std::vector<std::string> kPresentModeValues = {
    kPresentModeCapture, kPresentModeImmediate, kPresentModeMailbox, kPresentModeFifo, kPresentModeFifoRelaxed
};

static void CheckActiveLayers(const std::string& list)
{
    if (!list.empty())
    {
        // Check for the presence of the layer name in the list of active layers.
        size_t start = list.find(kCaptureLayer);

        if (start != std::string::npos)
        {
            size_t end         = start + gfxrecon::util::platform::StringLength(kCaptureLayer);
            bool   match_start = false;
            bool   match_end   = false;

            // For an exact match, the start of the layer name is either at the start of the list or comes after a path
            // separator.
            if ((start == 0) || ((list[start - 1] == ';') || (list[start - 1] == ':')))
            {
                match_start = true;
            }

            // For an exact match, the end of the layer name is either at the end of the list or comes before a path
            // separator.
            if ((list.length() == end) || ((list[end] == ';') || (list[end] == ':')))
            {
                match_end = true;
            }

            if (match_start && match_end)
            {
                GFXRECON_LOG_WARNING("Replay tool has detected that the capture layer is enabled");
            }
        }
    }
}

static gfxrecon::decode::VulkanResourceAllocator* CreateDefaultAllocator()
{
    return new gfxrecon::decode::VulkanDefaultAllocator(
        "Try replay with the '-m remap' or '-m rebind' options to enable memory translation.");
}

static gfxrecon::decode::VulkanResourceAllocator* CreateRemapAllocator()
{
    return new gfxrecon::decode::VulkanRemapAllocator(
        "Try replay with the '-m rebind' option to enable advanced memory translation.");
}

static gfxrecon::decode::VulkanResourceAllocator* CreateRebindAllocator()
{
    return new gfxrecon::decode::VulkanRebindAllocator();
}

static gfxrecon::decode::CreateResourceAllocator
InitRealignAllocatorCreateFunc(const std::string&                              filename,
                               const gfxrecon::decode::VulkanReplayOptions&    replay_options,
                               gfxrecon::decode::VulkanTrackedObjectInfoTable* tracked_object_info_table)
{
    // Enable first pass of replay to generate resource tracking information.
    GFXRECON_WRITE_CONSOLE("First pass of replay resource tracking for realign memory portability mode. This may take "
                           "some time. Please wait...");

    gfxrecon::decode::FileProcessor file_processor_resource_tracking;
    gfxrecon::decode::VulkanDecoder decoder;

    auto resource_tracking_consumer =
        new gfxrecon::decode::VulkanResourceTrackingConsumer(replay_options, tracked_object_info_table);

    if (file_processor_resource_tracking.Initialize(filename))
    {
        decoder.AddConsumer(resource_tracking_consumer);
        file_processor_resource_tracking.AddDecoder(&decoder);
        file_processor_resource_tracking.InitializeFrameProcessing();
        file_processor_resource_tracking.ProcessAllFrames();
        file_processor_resource_tracking.RemoveDecoder(&decoder);
        decoder.RemoveConsumer(resource_tracking_consumer);
    }

    // Sort the bound resources according to the binding offsets.
    resource_tracking_consumer->SortMemoriesBoundResourcesByOffset();

    // calculate the replay binding offset of the bound resources and replay memory allocation size
    resource_tracking_consumer->CalculateReplayBindingOffsetAndMemoryAllocationSize();

    GFXRECON_WRITE_CONSOLE("First pass of replay resource tracking done.");

    return [tracked_object_info_table]() -> gfxrecon::decode::VulkanResourceAllocator* {
        return new gfxrecon::decode::VulkanRealignAllocator(
            tracked_object_info_table, "Try replay with the '-m rebind' option to enable advanced memory translation.");
    };
}

static gfxrecon::decode::CreateResourceAllocator
GetCreateResourceAllocatorFunc(const gfxrecon::util::ArgumentParser&           arg_parser,
                               const std::string&                              filename,
                               const gfxrecon::decode::VulkanReplayOptions&    replay_options,
                               gfxrecon::decode::VulkanTrackedObjectInfoTable* tracked_object_info_table)
{
    gfxrecon::decode::CreateResourceAllocator func  = CreateDefaultAllocator;
    const auto&                               value = arg_parser.GetArgumentValue(kMemoryPortabilityShortOption);

    if (!value.empty())
    {
        if (gfxrecon::util::platform::StringCompareNoCase(kMemoryTranslationRebind, value.c_str()) == 0)
        {
            func = CreateRebindAllocator;
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kMemoryTranslationRemap, value.c_str()) == 0)
        {
            func = CreateRemapAllocator;
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kMemoryTranslationRealign, value.c_str()) == 0)
        {
            func = InitRealignAllocatorCreateFunc(filename, replay_options, tracked_object_info_table);
        }
    }

    return func;
}

static gfxrecon::decode::VulkanReplayOptions
GetVulkanReplayOptions(const gfxrecon::util::ArgumentParser&           arg_parser,
                       const std::string&                              filename,
                       gfxrecon::decode::VulkanTrackedObjectInfoTable* tracked_object_info_table)
{
    gfxrecon::decode::VulkanReplayOptions replay_options;
    GetReplayOptions(replay_options, arg_parser, filename);

    if (arg_parser.IsOptionSet(kCaptureOption))
    {
        replay_options.capture = true;
    }

    const auto& override_gpu_group = arg_parser.GetArgumentValue(kOverrideGpuGroupArgument);
    if (!override_gpu_group.empty())
    {
        replay_options.override_gpu_group_index = std::stoi(override_gpu_group);
    }

    if (arg_parser.IsOptionSet(kSkipFailedAllocationLongOption) ||
        arg_parser.IsOptionSet(kSkipFailedAllocationShortOption))
    {
        replay_options.skip_failed_allocations = true;
    }

    if (arg_parser.IsOptionSet(kOmitPipelineCacheDataLongOption) ||
        arg_parser.IsOptionSet(kOmitPipelineCacheDataShortOption))
    {
        replay_options.omit_pipeline_cache_data = true;
    }

    auto swapchain_option          = arg_parser.GetArgumentValue(kSwapchainOption);
    auto enable_captured_swapchain = arg_parser.IsOptionSet(kEnableUseCapturedSwapchainIndices);
    if (swapchain_option.empty())
    {
        if (enable_captured_swapchain)
        {
            replay_options.swapchain_option = gfxrecon::util::SwapchainOption::kCaptured;
        }
    }
    else
    {
        if (enable_captured_swapchain)
        {
            GFXRECON_LOG_WARNING("Ignoring option: \"%s\" because option: \"%s\" is added",
                                 kEnableUseCapturedSwapchainIndices,
                                 kSwapchainOption);
        }

        if (gfxrecon::util::platform::StringCompareNoCase(kSwapchainCaptured, swapchain_option.c_str()) == 0)
        {
            replay_options.swapchain_option = gfxrecon::util::SwapchainOption::kCaptured;
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kSwapchainOffscreen, swapchain_option.c_str()) == 0)
        {
            replay_options.swapchain_option = gfxrecon::util::SwapchainOption::kOffscreen;
        }
    }

    auto present_mode_option = arg_parser.GetArgumentValue(kPresentModeOption);
    if (gfxrecon::util::platform::StringCompareNoCase(kPresentModeCapture, present_mode_option.c_str()) == 0)
    {
        replay_options.present_mode_option = gfxrecon::util::PresentModeOption::kCapture;
    }
    else if (gfxrecon::util::platform::StringCompareNoCase(kPresentModeImmediate, present_mode_option.c_str()) == 0)
    {
        replay_options.present_mode_option = gfxrecon::util::PresentModeOption::kImmediate;
    }
    else if (gfxrecon::util::platform::StringCompareNoCase(kPresentModeMailbox, present_mode_option.c_str()) == 0)
    {
        replay_options.present_mode_option = gfxrecon::util::PresentModeOption::kMailbox;
    }
    else if (gfxrecon::util::platform::StringCompareNoCase(kPresentModeFifo, present_mode_option.c_str()) == 0)
    {
        replay_options.present_mode_option = gfxrecon::util::PresentModeOption::kFifo;
    }
    else if (gfxrecon::util::platform::StringCompareNoCase(kPresentModeFifoRelaxed, present_mode_option.c_str()) == 0)
    {
        replay_options.present_mode_option = gfxrecon::util::PresentModeOption::kFifoRelaxed;
    }

    if (arg_parser.IsOptionSet(kColorspaceFallback))
    {
        replay_options.use_colorspace_fallback = true;
    }

    if (arg_parser.IsOptionSet(kOffscreenSwapchainFrameBoundary))
    {
        replay_options.offscreen_swapchain_frame_boundary = true;
    }

    if (arg_parser.IsOptionSet(kVirtualSwapchainSkipBlitLongOption) ||
        arg_parser.IsOptionSet(kVirtualSwapchainSkipBlitShortOption))
    {
        replay_options.virtual_swapchain_skip_blit = true;
    }

    const std::string debug_severity_string = arg_parser.GetArgumentValue(kDebugMessageSeverityArgument);
    if (!debug_severity_string.empty())
    {
        if (gfxrecon::util::platform::StringCompareNoCase("debug", debug_severity_string.c_str()) == 0)
        {
            replay_options.debug_message_severity =
                VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT |
                VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
        }
        else if (gfxrecon::util::platform::StringCompareNoCase("info", debug_severity_string.c_str()) == 0)
        {
            replay_options.debug_message_severity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT |
                                                    VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
                                                    VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
        }
        else if (gfxrecon::util::platform::StringCompareNoCase("warning", debug_severity_string.c_str()) == 0)
        {
            replay_options.debug_message_severity =
                VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
        }
        else if (gfxrecon::util::platform::StringCompareNoCase("error", debug_severity_string.c_str()) == 0)
        {
            replay_options.debug_message_severity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
        }
        else
        {
            GFXRECON_LOG_WARNING("Ignoring unrecognized debug messenger severity option value \"%s\"",
                                 debug_severity_string.c_str());
        }
    }

    replay_options.replace_shader_dir = arg_parser.GetArgumentValue(kShaderReplaceArgument);
    replay_options.create_resource_allocator =
        GetCreateResourceAllocatorFunc(arg_parser, filename, replay_options, tracked_object_info_table);

    if (auto override_name = arg_parser.GetArgumentValue(kPresentOverrideImageArgument); !override_name.empty())
    {
        replay_options.present_override_image_name = override_name;
    }

    if (arg_parser.IsOptionSet(kScreenshotIgnoreFrameBoundaryArgument))
    {
        replay_options.screenshot_ignore_frameBoundaryAndroid = true;
    }

    if (arg_parser.IsOptionSet(kQuitAfterMeasurementRangeOption))
    {
        replay_options.quit_after_measurement_frame_range = true;
    }

    if (arg_parser.IsOptionSet(kFlushMeasurementRangeOption))
    {
        replay_options.flush_measurement_frame_range = true;
    }

    std::string surface_index = arg_parser.GetArgumentValue(kSurfaceIndexArgument);
    if (!surface_index.empty())
    {
        replay_options.surface_index = std::stoi(surface_index);
    }

    const std::string& skip_get_fence_status = arg_parser.GetArgumentValue(kSkipGetFenceStatus);
    if (!skip_get_fence_status.empty())
    {
        const int i_skip_get_fence_status = std::stoi(skip_get_fence_status);
        if (i_skip_get_fence_status < static_cast<int>(gfxrecon::decode::SkipGetFenceStatus::COUNT))
        {
            replay_options.skip_get_fence_status =
                static_cast<gfxrecon::decode::SkipGetFenceStatus>(i_skip_get_fence_status);
        }
        else
        {
            GFXRECON_LOG_FATAL("Unexpected value after '--skip-get-fence-status': '%s'", skip_get_fence_status.c_str());
        }
    }

    const std::string& skip_get_fence_ranges = arg_parser.GetArgumentValue(kSkipGetFenceRanges);
    if (skip_get_fence_ranges.empty())
    {
        gfxrecon::util::UintRange range;
        range.first = 1;
        range.last  = std::numeric_limits<uint32_t>::max();
        replay_options.skip_get_fence_ranges.push_back(range);
    }
    else
    {
        replay_options.skip_get_fence_ranges =
            gfxrecon::util::GetUintRanges(skip_get_fence_ranges.c_str(), "skip-get-fence-ranges");
    }
    if (arg_parser.IsOptionSet(kWaitBeforePresent))
    {
        replay_options.wait_before_present = true;
    }
    if (arg_parser.IsOptionSet(kAnnotateInjectedCommands))
    {
        replay_options.annotate_injected_commands = true;
    }
    if (arg_parser.IsOptionSet(kPreloadMeasurementRangeOption))
    {
        replay_options.preload_measurement_range = true;
    }

    const std::string& dump_resources = arg_parser.GetArgumentValue(kDumpResourcesArgument);
    if (!dump_resources.empty())
    {
        replay_options.enable_dump_resources = true;
        if (dump_resources.find_first_not_of("0123456789,") == std::string::npos)
        {
            std::vector<std::string> values = gfxrecon::util::strings::SplitString(dump_resources, ',');
            if (values.size() == 3)
            {
                replay_options.dump_resources_target.submit_index    = std::stoi(values[0]);
                replay_options.dump_resources_target.command_index   = std::stoi(values[1]);
                replay_options.dump_resources_target.draw_call_index = std::stoi(values[2]);
                replay_options.using_dump_resources_target           = true;
            }
        }
        else
        {
            replay_options.dump_resources_block_indices = dump_resources;
        }
    }

    replay_options.dump_resources_output_dir = GetDumpResourcesDir(arg_parser);

    replay_options.save_pipeline_cache_filename = arg_parser.GetArgumentValue(kSavePipelineCacheArgument);
    replay_options.load_pipeline_cache_filename = arg_parser.GetArgumentValue(kLoadPipelineCacheArgument);
    replay_options.add_new_pipeline_caches      = arg_parser.IsOptionSet(kCreateNewPipelineCacheOption);
    replay_options.do_device_deduplication      = arg_parser.IsOptionSet(kDeduplicateDevice);

    GetWaitBeforeFirstSubmit(arg_parser, replay_options.wait_before_first_submit);
    replay_options.idle_before_submit          = arg_parser.IsOptionSet(kIdleBeforeSubmit);
    replay_options.serialize_render_passes     = arg_parser.IsOptionSet(kSerializeRenderPasses);
    replay_options.serialize_queue_submissions = arg_parser.IsOptionSet(kSerializeQueueSubmissions);

    GetFrameWarmUpOptions(arg_parser, replay_options.frame_warm_up_spirv_path, replay_options.frame_warm_up_load);
    GetWaitBeforeFrame(arg_parser, replay_options.wait_before_frame);

    replay_options.replay_event_plugin_path       = arg_parser.GetArgumentValue(kReplayEventPluginPath);
    replay_options.replay_event_plugin_params     = arg_parser.GetArgumentValue(kReplayEventPluginParams);
    replay_options.isolate_render_passes          = arg_parser.IsOptionSet(kIsolateRenderPasses);
    replay_options.serialize_compute_and_transfer = arg_parser.IsOptionSet(kSerializeComputeAndTransfer);

    replay_options.screenshot_apply_prerotation = arg_parser.IsOptionSet(kScreenshotApplyPrerotationArgument);

    return replay_options;
}

// ----------------------------------------------------------------------------
// End of the Vulkan-only command-line settings.
// ----------------------------------------------------------------------------

std::string ReplayVulkanFeature::CompiledHeaderVersionString() const
{
#if defined(GFXRECON_ENABLE_VULKAN)
    return util::GetVulkanHeaderVersionString();
#else
    return "";
#endif
}

std::vector<util::FeatureOptionDesc> ReplayVulkanFeature::GetOptionDescs() const
{
    return { { "",
               { "Capture the replaying GFXR file. Capture uses the same log options as",
                 "replay. All other capture option behavior and usage is the same as when",
                 "capturing with the GFXR layer. The capture functionality is included in",
                 "the `gfxrecon-replay` executable--no GFXR capture layer is added to the",
                 "Vulkan layer chain." },
               false,
               kCaptureOption },
             { "",
               { "Skip vkAllocateMemory, vkAllocateCommandBuffers, and",
                 "vkAllocateDescriptorSets calls that failed during capture." },
               false,
               AliasNames(kSkipFailedAllocationShortOption, kSkipFailedAllocationLongOption) },
             { "<dir>",
               { "Replace the shader code in each CreateShaderModule with the contents of",
                 "the file <dir>/sh<handle_id> if found, where <handle_id> is the handle id",
                 "of the CreateShaderModule call. See gfxrecon-extract." },
               true,
               kShaderReplaceArgument },
             { "",
               { "Omit pipeline cache data from calls to vkCreatePipelineCache and skip",
                 "calls to vkGetPipelineCacheData." },
               false,
               AliasNames(kOmitPipelineCacheDataShortOption, kOmitPipelineCacheDataLongOption) },
             { "<N>",
               { "Restrict rendering to the Nth surface object created. Used with captures",
                 "that include multiple surfaces. Default is -1 (render to all surfaces)." },
               true,
               kSurfaceIndexArgument },
             { "<mode>",
               { "Enable memory translation for replay on GPUs with memory types that are",
                 "not compatible with the memory types of the capture GPU.",
                 "    none     No memory translation. This is the default behavior.",
                 "    remap    Map capture memory types to compatible replay memory",
                 "             types, without a change to the allocation behavior.",
                 "    realign  Adjust the allocation sizes and the resource binding",
                 "             offsets to the replay memory properties.",
                 "    rebind   Change the allocation behavior to the resource usage and",
                 "             the replay memory properties. Resources can bind to",
                 "             different allocations with different offsets. This mode",
                 "             uses VMA to manage allocations and suballocations." },
               true,
               AliasNames(kMemoryPortabilityShortOption, kMemoryPortabilityLongOption),
               kMemoryTranslationValues },
             { "<mode>",
               { "Choose a swapchain mode to replay.",
                 "    virtual    A swapchain of images that match the swapchain in effect",
                 "               at capture time. The images are copied to the swapchain",
                 "               of the implementation that replays them. This mode also",
                 "               shows offscreen frame boundaries in an additional window.",
                 "               This is the default mode.",
                 "    captured   Use the swapchain indices from the capture directly on",
                 "               the swapchain that replay sets up.",
                 "    offscreen  Do not create swapchains, surfaces, and windows. To see",
                 "               the rendering, add the --screenshots option." },
               true,
               kSwapchainOption,
               kSwapchainValues },
             { "<mode>",
               { "Set the VkPresentModeKHR of the swapchain.",
                 "    capture       The present mode from capture time.",
                 "    immediate     VK_PRESENT_MODE_IMMEDIATE_KHR",
                 "    mailbox       VK_PRESENT_MODE_MAILBOX_KHR",
                 "    fifo          VK_PRESENT_MODE_FIFO_KHR",
                 "    fifo_relaxed  VK_PRESENT_MODE_FIFO_RELAXED_KHR" },
               true,
               kPresentModeOption,
               kPresentModeValues },
             { "<debug-name>",
               { "Also present an image that a substring match against its",
                 "VK_EXT_debug_utils object name identifies (depth and stencil images are",
                 "ignored). The matched image is presented in a dedicated swapchain on",
                 "every present, and is used for screenshot operations. A multi-layer",
                 "image is presented tiled into a single window, one tile for each array",
                 "layer. If more than one image matches, replay uses the most recently",
                 "named one." },
               true,
               kPresentOverrideImageArgument },
             { "",
               { "Skip the blit to the real swapchain to increase replay performance." },
               false,
               AliasNames(kVirtualSwapchainSkipBlitShortOption, kVirtualSwapchainSkipBlitLongOption) },
             { "",
               { "The same as \"--swapchain captured\".",
                 "Replay ignores this entry when the \"--swapchain\" entry is present." },
               false,
               kEnableUseCapturedSwapchainIndices },
             { "",
               { "Use this entry only with the offscreen swapchain. It activates the",
                 "VK_EXT_frame_boundary extension (always supported for a trimmed",
                 "capture, and checked against the driver otherwise) and it inserts a",
                 "command buffer submission with VkFrameBoundaryEXT where the original",
                 "capture called vkQueuePresentKHR. This keeps the frames when you",
                 "capture a replay that uses the offscreen swapchain." },
               false,
               kOffscreenSwapchainFrameBoundary },
             { "",
               { "Swap the color space of the swapchain when the replay device does not",
                 "support it. Replay falls back to VK_COLOR_SPACE_SRGB_NONLINEAR_KHR." },
               false,
               kColorspaceFallback },
             { "<index>",
               { "Use the specified device group for replay, where index is the",
                 "zero-based index to the array of physical device groups that",
                 "vkEnumeratePhysicalDeviceGroups returns. Replay can fail when the",
                 "specified device group is not compatible with the original capture",
                 "device group." },
               true,
               kOverrideGpuGroupArgument },
             { "<status>",
               { "Specify the behavior that skips calls to vkWaitForFences and",
                 "vkGetFenceStatus:",
                 "    status=0  Do not skip.",
                 "    status=1  Skip unsuccessful calls.",
                 "    status=2  Always skip.",
                 "The status applies to all frames when no skip frame range (--sgfr) is",
                 "specified." },
               true,
               AliasNames(kSkipGetFenceStatusShortOption, kSkipGetFenceStatus) },
             { "<frame-ranges>",
               { "The frame ranges where --sgfs applies. The format is:",
                 "    <frame-start-1>-<frame-end-1>[,<frame-start-2>-<frame-end-2>]*" },
               true,
               AliasNames(kSkipGetFenceRangesShortOption, kSkipGetFenceRanges) },
             { "",
               { "Force a wait on the completion of the queue operations for all queues",
                 "before the call to Present. Some platforms need this to get accurate",
                 "instrumentation data." },
               false,
               kWaitBeforePresent },
             { "",
               { "Put the commands that replay injects, which are not in the capture (for",
                 "example, the virtual-swapchain copies and the ray-tracing SBT fixups), in",
                 "VK_EXT_debug_utils labels with the name \"GFXR Replay: <category>\"." },
               false,
               kAnnotateInjectedCommands },
             { "<cache-file>",
               { "Produce pipeline caches at replay time instead of the use of the cache",
                 "saved at capture time, and save those caches in <cache-file>." },
               true,
               kSavePipelineCacheArgument },
             { "<cache-file>",
               { "Load the data that the `--save-pipeline-cache` entry created in",
                 "<cache-file>, and use it to create the pipelines instead of the",
                 "pipeline caches saved at capture time." },
               true,
               kLoadPipelineCacheArgument },
             { "",
               { "Let gfxreconstruct create new vkPipelineCache objects when it finds a",
                 "pipeline created without a cache. Use this entry together with",
                 "`--save-pipeline-cache` and `--load-pipeline-cache`." },
               false,
               kCreateNewPipelineCacheOption },
             { "",
               { "Ignore the frames that vkFrameBoundaryANDROID switches in the", "screenshot handler." },
               false,
               kScreenshotIgnoreFrameBoundaryArgument },
             { "",
               { "Apply the preTransform of the swapchain to the screenshots." },
               false,
               kScreenshotApplyPrerotationArgument },
             { "",
               { "Create at most one VkDevice for each VkPhysicalDevice, for the RenderDoc", "and DXVK case." },
               false,
               kDeduplicateDevice },
             { "", { "Wait for the GPU to become idle before each submit." }, false, kIdleBeforeSubmit },
             { "",
               { "Serialize the render passes. Replay injects execution barriers before",
                 "the start of a render pass." },
               false,
               kSerializeRenderPasses },
             { "",
               { "Serialize the submit entries within one vkQueueSubmit or vkQueueSubmit2",
                 "call. Replay adds semaphores between consecutive submits." },
               false,
               kSerializeQueueSubmissions },
             { "<path>",
               { "Path to a replay event plugin library. Replay loads the plugin and uses",
                 "it to process the replay events." },
               true,
               kReplayEventPluginPath },
             { "<params>",
               { "Parameters to forward to the replay event plugin. The plugin determines",
                 "the format of the parameters, and replay does not interpret them." },
               true,
               kReplayEventPluginParams },
             { "",
               { "Isolate the render passes. Replay splits the command buffer into more", "than one submit." },
               false,
               kIsolateRenderPasses },
             { "<level>",
               { "The highest debug messenger severity level to report. The levels are",
                 "debug, info, warning, and error. The default is warning." },
               true,
               kDebugMessageSeverityArgument },
             // This entry has no description, so it stays out of the usage text.
             { "", {}, false, kSerializeComputeAndTransfer } };
}

void ReplayVulkanFeature::CheckEnvironment()
{
    // platform::GetEnv() reads an environment variable on the desktop platforms and a system
    // property on Android.
#if defined(__ANDROID__)
    const std::string active_layers = gfxrecon::util::platform::GetEnv(kLayerProperty);
#else
    const std::string active_layers = gfxrecon::util::platform::GetEnv(kLayerEnvVar);
#endif

    CheckActiveLayers(active_layers);
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
        if (replay_options_.isolate_render_passes)
        {
            auto  decoder  = std::make_unique<decode::VulkanStateRecordingDecoder>();
            auto* consumer = dynamic_cast<decode::VulkanReplayConsumerBase*>(replay_consumer_.get());
            GFXRECON_ASSERT(consumer != nullptr);
            consumer->SetDecoder(decoder.get());
            RegisterConsumerAndDecoder(fps_info, std::move(decoder));
        }
        else
        {
            RegisterConsumerAndDecoder(fps_info);
        }

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
