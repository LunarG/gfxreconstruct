/*
** Copyright (c) 2019-2020 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#include "project_version.h"

#include "decode/file_processor.h"
#include "decode/vulkan_default_allocator.h"
#include "decode/vulkan_realign_allocator.h"
#include "decode/vulkan_rebind_allocator.h"
#include "decode/vulkan_remap_allocator.h"
#include "decode/vulkan_replay_options.h"
#include "decode/vulkan_resource_tracking_consumer.h"
#include "decode/vulkan_tracked_object_info_table.h"
#include "generated/generated_vulkan_decoder.h"
#include "util/argument_parser.h"
#include "util/logging.h"
#include "util/platform.h"

#include "vulkan/vulkan_core.h"

#include <cstdlib>
#include <string>

#ifndef GFXRECON_REPLAY_SETTINGS_H
#define GFXRECON_REPLAY_SETTINGS_H

const char kApplicationName[] = "GFXReconstruct Replay";
const char kCaptureLayer[]    = "VK_LAYER_LUNARG_gfxreconstruct";

const char kHelpShortOption[]                  = "-h";
const char kHelpLongOption[]                   = "--help";
const char kVersionOption[]                    = "--version";
const char kNoDebugPopup[]                     = "--no-debug-popup";
const char kOverrideGpuArgument[]              = "--gpu";
const char kPausedOption[]                     = "--paused";
const char kPauseFrameArgument[]               = "--pause-frame";
const char kSkipFailedAllocationShortOption[]  = "--sfa";
const char kSkipFailedAllocationLongOption[]   = "--skip-failed-allocations";
const char kOmitPipelineCacheDataShortOption[] = "--opcd";
const char kOmitPipelineCacheDataLongOption[]  = "--omit-pipeline-cache-data";
const char kWsiArgument[]                      = "--wsi";
const char kMemoryPortabilityShortOption[]     = "-m";
const char kMemoryPortabilityLongOption[]      = "--memory-translation";
const char kShaderReplaceArgument[]            = "--replace-shaders";

const char kOptions[] = "-h|--help,--version,--no-debug-popup,--paused,--sfa|--skip-failed-allocations,--opcd|--omit-"
                        "pipeline-cache-data";
const char kArguments[] = "--gpu,--pause-frame,--wsi,-m|--memory-translation,--replace-shaders";

enum class WsiPlatform
{
    kAuto,
    kWin32,
    kXcb,
    kWayland
};

const char kWsiPlatformAuto[]    = "auto";
const char kWsiPlatformWin32[]   = "win32";
const char kWsiPlatformXcb[]     = "xcb";
const char kWsiPlatformWayland[] = "wayland";

const char kMemoryTranslationNone[]    = "none";
const char kMemoryTranslationRemap[]   = "remap";
const char kMemoryTranslationRealign[] = "realign";
const char kMemoryTranslationRebind[]  = "rebind";

static void ProcessDisableDebugPopup(const gfxrecon::util::ArgumentParser& arg_parser)
{
#if defined(WIN32) && defined(_DEBUG)
    if (arg_parser.IsOptionSet(kNoDebugPopup))
    {
        _set_abort_behavior(0, _WRITE_ABORT_MSG | _CALL_REPORTFAULT);
    }
#endif
}

static void CheckActiveLayers(const char* env_var)
{
    std::string result = gfxrecon::util::platform::GetEnv(env_var);

    if (!result.empty())
    {
        if (result.find(kCaptureLayer) != std::string::npos)
        {
            GFXRECON_LOG_WARNING("Replay tool has detected that the capture layer is enabled");
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
                               const gfxrecon::decode::ReplayOptions&          replay_options,
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

static uint32_t GetPauseFrame(const gfxrecon::util::ArgumentParser& arg_parser)
{
    uint32_t    pause_frame = 0;
    std::string value       = arg_parser.GetArgumentValue(kPauseFrameArgument);

    if (arg_parser.IsOptionSet(kPausedOption))
    {
        pause_frame = 1;
    }
    else if (!value.empty())
    {
        pause_frame = std::stoi(value);
    }

    return pause_frame;
}

static WsiPlatform GetWsiPlatform(const gfxrecon::util::ArgumentParser& arg_parser)
{
    WsiPlatform wsi_platform = WsiPlatform::kAuto;
    std::string value        = arg_parser.GetArgumentValue(kWsiArgument);

    if (!value.empty())
    {
        if (gfxrecon::util::platform::StringCompareNoCase(kWsiPlatformAuto, value.c_str()) == 0)
        {
            wsi_platform = WsiPlatform::kAuto;
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kWsiPlatformWin32, value.c_str()) == 0)
        {
#if defined(VK_USE_PLATFORM_WIN32_KHR)
            wsi_platform = WsiPlatform::kWin32;
#else
            GFXRECON_LOG_WARNING("Ignoring wsi option %s, which is not enabled on this system", value.c_str());
#endif
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kWsiPlatformXcb, value.c_str()) == 0)
        {
#if defined(VK_USE_PLATFORM_XCB_KHR)
            wsi_platform = WsiPlatform::kXcb;
#else
            GFXRECON_LOG_WARNING("Ignoring wsi option %s, which is not enabled on this system", value.c_str());
#endif
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kWsiPlatformWayland, value.c_str()) == 0)
        {
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
            wsi_platform = WsiPlatform::kWayland;
#else
            GFXRECON_LOG_WARNING("Ignoring wsi option %s, which is not enabled on this system", value.c_str());
#endif
        }
        else
        {
            GFXRECON_LOG_WARNING("Ignoring unrecognized wsi option %s", value.c_str());
        }
    }

    return wsi_platform;
}

const std::string GetWsiArgString()
{
    std::string wsi_args = kWsiPlatformAuto;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    wsi_args += ',';
    wsi_args += kWsiPlatformWin32;
#endif
#if defined(VK_USE_PLATFORM_XCB_KHR)
    wsi_args += ',';
    wsi_args += kWsiPlatformXcb;
#endif
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
    wsi_args += ',';
    wsi_args += kWsiPlatformWayland;
#endif
    return wsi_args;
}

static gfxrecon::decode::CreateResourceAllocator
GetCreateResourceAllocatorFunc(const gfxrecon::util::ArgumentParser&           arg_parser,
                               const std::string&                              filename,
                               const gfxrecon::decode::ReplayOptions&          replay_options,
                               gfxrecon::decode::VulkanTrackedObjectInfoTable* tracked_object_info_table)
{
    gfxrecon::decode::CreateResourceAllocator func  = CreateDefaultAllocator;
    std::string                               value = arg_parser.GetArgumentValue(kMemoryPortabilityShortOption);

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
        else if (gfxrecon::util::platform::StringCompareNoCase(kMemoryTranslationNone, value.c_str()) != 0)
        {
            GFXRECON_LOG_WARNING("Ignoring unrecognized memory translation option %s", value.c_str());
        }
    }

    return func;
}

static gfxrecon::decode::ReplayOptions
GetReplayOptions(const gfxrecon::util::ArgumentParser&           arg_parser,
                 const std::string&                              filename,
                 gfxrecon::decode::VulkanTrackedObjectInfoTable* tracked_object_info_table)
{
    gfxrecon::decode::ReplayOptions replay_options;
    std::string                     override_gpu = arg_parser.GetArgumentValue(kOverrideGpuArgument);

    if (!override_gpu.empty())
    {
        replay_options.override_gpu_index = std::stoi(override_gpu);
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

    replay_options.replace_dir = arg_parser.GetArgumentValue(kShaderReplaceArgument);
    replay_options.create_resource_allocator =
        GetCreateResourceAllocatorFunc(arg_parser, filename, replay_options, tracked_object_info_table);

    return replay_options;
}

static bool CheckOptionPrintVersion(const char* exe_name, const gfxrecon::util::ArgumentParser& arg_parser)
{
    if (arg_parser.IsOptionSet(kVersionOption))
    {
        std::string app_name     = exe_name;
        size_t      dir_location = app_name.find_last_of("/\\");

        if (dir_location >= 0)
        {
            app_name.replace(0, dir_location + 1, "");
        }

        GFXRECON_WRITE_CONSOLE("%s version info:", app_name.c_str());
        GFXRECON_WRITE_CONSOLE("  GFXReconstruct Version %s", GFXRECON_PROJECT_VERSION_STRING);
        GFXRECON_WRITE_CONSOLE("  Vulkan Header Version %u.%u.%u",
                               VK_VERSION_MAJOR(VK_HEADER_VERSION_COMPLETE),
                               VK_VERSION_MINOR(VK_HEADER_VERSION_COMPLETE),
                               VK_VERSION_PATCH(VK_HEADER_VERSION_COMPLETE));

        return true;
    }

    return false;
}

static void PrintUsage(const char* exe_name)
{
    std::string app_name     = exe_name;
    size_t      dir_location = app_name.find_last_of("/\\");

    if (dir_location >= 0)
    {
        app_name.replace(0, dir_location + 1, "");
    }

    GFXRECON_WRITE_CONSOLE("\n%s - A tool to replay GFXReconstruct capture files.\n", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("Usage:");
    GFXRECON_WRITE_CONSOLE("  %s\t[-h | --help] [--version] [--gpu <index>]", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("\t\t\t[--pause-frame <N>] [--paused]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--sfa | --skip-failed-allocations] [--replace-shaders <dir>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--opcd | --omit-pipeline-cache-data] [--wsi <platform>]");
#if defined(WIN32) && defined(_DEBUG)
    GFXRECON_WRITE_CONSOLE("\t\t\t[--no-debug-popup]");
#endif
    GFXRECON_WRITE_CONSOLE("\t\t\t[-m <mode> | --memory-translation <mode>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--emrp | --enable-multipass-replay-portability] <file>\n");
    GFXRECON_WRITE_CONSOLE("Required arguments:");
    GFXRECON_WRITE_CONSOLE("  <file>\t\tPath to the capture file to replay.");
    GFXRECON_WRITE_CONSOLE("\nOptional arguments:");
    GFXRECON_WRITE_CONSOLE("  -h\t\t\tPrint usage information and exit (same as --help).");
    GFXRECON_WRITE_CONSOLE("  --version\t\tPrint version information and exit.");
    GFXRECON_WRITE_CONSOLE("  --gpu <index>\t\tUse the specified device for replay, where index");
    GFXRECON_WRITE_CONSOLE("          \t\tis the zero-based index to the array of physical devices");
    GFXRECON_WRITE_CONSOLE("          \t\treturned by vkEnumeratePhysicalDevices.  Replay may fail");
    GFXRECON_WRITE_CONSOLE("          \t\tif the specified device is not compatible with the");
    GFXRECON_WRITE_CONSOLE("          \t\toriginal capture devices.");
    GFXRECON_WRITE_CONSOLE("  --pause-frame <N>\tPause after replaying frame number N.");
    GFXRECON_WRITE_CONSOLE("  --paused\t\tPause after replaying the first frame (same");
    GFXRECON_WRITE_CONSOLE("          \t\tas --pause-frame 1).");
    GFXRECON_WRITE_CONSOLE("  --sfa\t\t\tSkip vkAllocateMemory, vkAllocateCommandBuffers, and");
    GFXRECON_WRITE_CONSOLE("       \t\t\tvkAllocateDescriptorSets calls that failed during");
    GFXRECON_WRITE_CONSOLE("       \t\t\tcapture (same as --skip-failed-allocations).");
    GFXRECON_WRITE_CONSOLE("  --replace-shaders <dir> Replace the shader code in each CreateShaderModule");
    GFXRECON_WRITE_CONSOLE("       \t\t\twith the contents of the file <dir>/sh<handle_id> if found, where");
    GFXRECON_WRITE_CONSOLE("       \t\t\t<handle_id> is the handle id of the CreateShaderModule call.");
    GFXRECON_WRITE_CONSOLE("       \t\t\tSee gfxrecon-extract.");
    GFXRECON_WRITE_CONSOLE("  --opcd\t\tOmit pipeline cache data from calls to");
    GFXRECON_WRITE_CONSOLE("        \t\tvkCreatePipelineCache (same as --omit-pipeline-cache-data).");
    GFXRECON_WRITE_CONSOLE("  --wsi <platform>\tForce replay to use the specified wsi platform.");
    GFXRECON_WRITE_CONSOLE("                  \tAvailable platforms are: %s", GetWsiArgString().c_str());
#if defined(WIN32) && defined(_DEBUG)
    GFXRECON_WRITE_CONSOLE("  --no-debug-popup\tDisable the 'Abort, Retry, Ignore' message box");
    GFXRECON_WRITE_CONSOLE("       \t\t\tdisplayed when abort() is called (Windows debug only).");
#endif
    GFXRECON_WRITE_CONSOLE("  -m <mode>\t\tEnable memory translation for replay on GPUs with memory");
    GFXRECON_WRITE_CONSOLE("          \t\ttypes that are not compatible with the capture GPU's");
    GFXRECON_WRITE_CONSOLE("          \t\tmemory types.  Available modes are:");
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\tNo memory translation is performed.  This", kMemoryTranslationNone);
    GFXRECON_WRITE_CONSOLE("          \t\t         \tis the default behavior.");
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\tAttempt to map capture memory types to", kMemoryTranslationRemap);
    GFXRECON_WRITE_CONSOLE("          \t\t         \tcompatible replay memory types, without");
    GFXRECON_WRITE_CONSOLE("          \t\t         \taltering memory allocation behavior.");
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\tAdjust memory allocation sizes and", kMemoryTranslationRealign);
    GFXRECON_WRITE_CONSOLE("          \t\t         \tresource binding offests based on");
    GFXRECON_WRITE_CONSOLE("          \t\t         \treplay memory properties.");
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\tChange memory allocation behavior based", kMemoryTranslationRebind);
    GFXRECON_WRITE_CONSOLE("          \t\t         \ton resource usage and replay memory");
    GFXRECON_WRITE_CONSOLE("          \t\t         \tproperties.  Resources may be bound");
    GFXRECON_WRITE_CONSOLE("          \t\t         \tto different allocations with different");
    GFXRECON_WRITE_CONSOLE("          \t\t         \toffsets.  Uses VMA to manage allocations");
    GFXRECON_WRITE_CONSOLE("          \t\t         \tand suballocations.");
}

static bool CheckOptionPrintUsage(const char* exe_name, const gfxrecon::util::ArgumentParser& arg_parser)
{
    if (arg_parser.IsOptionSet(kHelpShortOption) || arg_parser.IsOptionSet(kHelpLongOption))
    {
        PrintUsage(exe_name);
        return true;
    }

    return false;
}

#endif // GFXRECON_REPLAY_SETTINGS_H
