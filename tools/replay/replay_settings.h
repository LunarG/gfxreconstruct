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

#include "decode/vulkan_default_allocator.h"
#include "decode/vulkan_rebind_allocator.h"
#include "decode/vulkan_remap_allocator.h"
#include "decode/vulkan_replay_options.h"
#include "util/argument_parser.h"
#include "util/logging.h"
#include "util/platform.h"

#include "vulkan/vulkan_core.h"

#include <string>

#ifndef GFXRECON_REPLAY_SETTINGS_H
#define GFXRECON_REPLAY_SETTINGS_H

struct Arguments
{
    static const char kApplicationName[];
    static const char kCaptureLayer[];

    static const char kVersionOption[];
    static const char kOverrideGpuArgument[];
    static const char kPausedOption[];
    static const char kPauseFrameArgument[];
    static const char kSkipFailedAllocationShortOption[];
    static const char kSkipFailedAllocationLongOption[];
    static const char kOmitPipelineCacheDataShortOption[];
    static const char kOmitPipelineCacheDataLongOption[];
    static const char kWsiArgument[];
    static const char kMemoryPortabilityShortOption[];
    static const char kMemoryPortabilityLongOption[];
    static const char kShaderReplaceArgument[];
    static const char kEnableMultipassReplayPortabilityLongOption[];
    static const char kEnableMultipassReplayPortabilityShortOption[];

    static const char kIPAddArgument[];
    static const char kPortArgument[];
    static const char kWinWidthArgument[];
    static const char kWinHeightArgument[];

    // TODO: Make this a vector of strings.
    static const char kOptions[];
    static const char kArguments[];
};

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

const char      kMemoryTranslationNone[]   = "none";
const char      kMemoryTranslationRemap[]  = "remap";
const char      kMemoryTranslationRebind[] = "rebind";
static uint32_t kWindowWidth               = 320;
static uint32_t kWindowHeight              = 240;

static void CheckActiveLayers(const char* env_var)
{
    std::string result = gfxrecon::util::platform::GetEnv(env_var);

    if (!result.empty())
    {
        if (result.find(Arguments::kCaptureLayer) != std::string::npos)
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

static char* GetIpAddress(const gfxrecon::util::ArgumentParser& arg_parser)
{
    std::string value = arg_parser.GetArgumentValue(Arguments::kIPAddArgument);

    if (!value.empty())
    {
        std::vector<char> cvalue(value.c_str(), value.c_str() + value.size() + 1);
        return reinterpret_cast<char*>(cvalue.data());
    }

    return nullptr;
}

static uint32_t GetTcpPort(const gfxrecon::util::ArgumentParser& arg_parser)
{
    uint32_t    tcp_port = 0;
    std::string value    = arg_parser.GetArgumentValue(Arguments::kPortArgument);

    if (!value.empty())
    {
        tcp_port = std::stoi(value);
    }

    return tcp_port;
}

static uint32_t GetWindowWidth(const gfxrecon::util::ArgumentParser& arg_parser)
{
    uint32_t    win_width = 0;
    std::string value     = arg_parser.GetArgumentValue(Arguments::kWinWidthArgument);

    if (!value.empty())
    {
        win_width = std::stoi(value);
    }

    return win_width;
}

static uint32_t GetWindowHeight(const gfxrecon::util::ArgumentParser& arg_parser)
{
    uint32_t    win_height = 0;
    std::string value      = arg_parser.GetArgumentValue(Arguments::kWinHeightArgument);

    if (!value.empty())
    {
        win_height = std::stoi(value);
    }

    return win_height;
}

static uint32_t GetPauseFrame(const gfxrecon::util::ArgumentParser& arg_parser)
{
    uint32_t    pause_frame = 0;
    std::string value       = arg_parser.GetArgumentValue(Arguments::kPauseFrameArgument);

    if (arg_parser.IsOptionSet(Arguments::kPausedOption))
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
    std::string value        = arg_parser.GetArgumentValue(Arguments::kWsiArgument);

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
            GFXRECON_LOG_WARNING("Ignoring unrecongized wsi option %s", value.c_str());
        }
    }

    return wsi_platform;
}

static const std::string GetWsiArgString()
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
GetCreateResourceAllocatorFunc(const gfxrecon::util::ArgumentParser& arg_parser)
{
    gfxrecon::decode::CreateResourceAllocator func = CreateDefaultAllocator;
    std::string value = arg_parser.GetArgumentValue(Arguments::kMemoryPortabilityShortOption);

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
        else if (gfxrecon::util::platform::StringCompareNoCase(kMemoryTranslationNone, value.c_str()) != 0)
        {
            GFXRECON_LOG_WARNING("Ignoring unrecongized memory translation option %s", value.c_str());
        }
    }

    return func;
}

static gfxrecon::decode::ReplayOptions GetReplayOptions(const gfxrecon::util::ArgumentParser& arg_parser)
{
    gfxrecon::decode::ReplayOptions replay_options;
    std::string                     override_gpu = arg_parser.GetArgumentValue(Arguments::kOverrideGpuArgument);

    if (!override_gpu.empty())
    {
        replay_options.override_gpu_index = std::stoi(override_gpu);
    }

    if (arg_parser.IsOptionSet(Arguments::kSkipFailedAllocationLongOption) ||
        arg_parser.IsOptionSet(Arguments::kSkipFailedAllocationShortOption))
    {
        replay_options.skip_failed_allocations = true;
    }

    if (arg_parser.IsOptionSet(Arguments::kOmitPipelineCacheDataLongOption) ||
        arg_parser.IsOptionSet(Arguments::kOmitPipelineCacheDataShortOption))
    {
        replay_options.omit_pipeline_cache_data = true;
    }

    replay_options.create_resource_allocator = GetCreateResourceAllocatorFunc(arg_parser);
    replay_options.replace_dir               = arg_parser.GetArgumentValue(Arguments::kShaderReplaceArgument);

    if (arg_parser.IsOptionSet(Arguments::kEnableMultipassReplayPortabilityLongOption) ||
        arg_parser.IsOptionSet(Arguments::kEnableMultipassReplayPortabilityShortOption))
    {
        replay_options.enable_multipass_replay_portability = true;
    }

    return replay_options;
}

static bool PrintVersion(const char* exe_name, const gfxrecon::util::ArgumentParser& arg_parser)
{
    if (arg_parser.IsOptionSet(Arguments::kVersionOption))
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
    GFXRECON_WRITE_CONSOLE("  %s\t[--version] [--gpu <index>] [--pause-frame <N>]", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("\t\t\t[--paused] [--sfa | --skip-failed-allocations]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--replace-shaders <dir>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--opcd | --omit-pipeline-cache-data] [--wsi <platform>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[-m <mode> | --memory-translation <mode>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--emrp | --enable-multipass-replay-portability] <file>\n");
    GFXRECON_WRITE_CONSOLE("Required arguments:");
    GFXRECON_WRITE_CONSOLE("  <file>\t\tPath to the capture file to replay.");
    GFXRECON_WRITE_CONSOLE("\nOptional arguments:");
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
    GFXRECON_WRITE_CONSOLE("  -m <mode>\t\tEnable memory translation for replay on GPUs with memory");
    GFXRECON_WRITE_CONSOLE("          \t\ttypes that are not compatible with the capture GPU's");
    GFXRECON_WRITE_CONSOLE("          \t\tmemory types.  Available modes are:");
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\tNo memory translation is performed.  This", kMemoryTranslationNone);
    GFXRECON_WRITE_CONSOLE("          \t\t         \tis the default behavior.");
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\tAttempt to map capture memory types to", kMemoryTranslationRemap);
    GFXRECON_WRITE_CONSOLE("          \t\t         \tcompatible replay memory types, without");
    GFXRECON_WRITE_CONSOLE("          \t\t         \taltering memory allocation behavior.");
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\tChange memory allocation behavior based", kMemoryTranslationRebind);
    GFXRECON_WRITE_CONSOLE("          \t\t         \ton resource usage and replay memory");
    GFXRECON_WRITE_CONSOLE("          \t\t         \tproperties.  Resources may be bound");
    GFXRECON_WRITE_CONSOLE("          \t\t         \tto different allocations with different");
    GFXRECON_WRITE_CONSOLE("          \t\t         \toffsets.  Uses VMA to manage allocations");
    GFXRECON_WRITE_CONSOLE("          \t\t         \tand suballocations.");
    GFXRECON_WRITE_CONSOLE("  --emrp\t\tEnable multipass (2-pass) replay portability for replay");
    GFXRECON_WRITE_CONSOLE("        \t\ton GPU with memory requirements that are different with");
    GFXRECON_WRITE_CONSOLE("        \t\tcapture GPU (same as --enable-multipass-replay-portability).");
}

#endif // GFXRECON_REPLAY_SETTINGS_H
