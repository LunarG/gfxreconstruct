/*
** Copyright (c) 2019-2023 LunarG, Inc.
** Copyright (c) 2021-2023 Advanced Micro Devices, Inc. All rights reserved.
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

#include "project_version.h"

#if defined(D3D12_SUPPORT)
#include "decode/dx_replay_options.h"
#include <initguid.h>
#include "generated/generated_dx12_decoder.h"
#endif
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
#include "util/options.h"
#include "util/strings.h"

#include "vulkan/vulkan_core.h"

#include <cstdlib>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

#ifndef GFXRECON_PLATFORM_SETTINGS_H
#define GFXRECON_PLATFORM_SETTINGS_H

const char kApplicationName[] = "GFXReconstruct Replay";
const char kCaptureLayer[]    = "VK_LAYER_LUNARG_gfxreconstruct";

const char kHelpShortOption[]                    = "-h";
const char kHelpLongOption[]                     = "--help";
const char kVersionOption[]                      = "--version";
const char kLogLevelArgument[]                   = "--log-level";
const char kLogFileArgument[]                    = "--log-file";
const char kLogDebugView[]                       = "--log-debugview";
const char kNoDebugPopup[]                       = "--no-debug-popup";
const char kOverrideGpuArgument[]                = "--gpu";
const char kOverrideGpuGroupArgument[]           = "--gpu-group";
const char kPausedOption[]                       = "--paused";
const char kPauseFrameArgument[]                 = "--pause-frame";
const char kSkipFailedAllocationShortOption[]    = "--sfa";
const char kSkipFailedAllocationLongOption[]     = "--skip-failed-allocations";
const char kDiscardCachedPsosShortOption[]       = "--dcp";
const char kDiscardCachedPsosLongOption[]        = "--discard-cached-psos";
const char kUseCachedPsosOption[]                = "--use-cached-psos";
const char kOmitPipelineCacheDataShortOption[]   = "--opcd";
const char kOmitPipelineCacheDataLongOption[]    = "--omit-pipeline-cache-data";
const char kWsiArgument[]                        = "--wsi";
const char kSurfaceIndexArgument[]               = "--surface-index";
const char kMemoryPortabilityShortOption[]       = "-m";
const char kMemoryPortabilityLongOption[]        = "--memory-translation";
const char kSyncOption[]                         = "--sync";
const char kRemoveUnsupportedOption[]            = "--remove-unsupported";
const char kValidateOption[]                     = "--validate";
const char kDebugDeviceLostOption[]              = "--debug-device-lost";
const char kCreateDummyAllocationsOption[]       = "--create-dummy-allocations";
const char kOmitNullHardwareBuffersLongOption[]  = "--omit-null-hardware-buffers";
const char kOmitNullHardwareBuffersShortOption[] = "--onhb";
const char kDeniedMessages[]                     = "--denied-messages";
const char kAllowedMessages[]                    = "--allowed-messages";
const char kShaderReplaceArgument[]              = "--replace-shaders";
const char kScreenshotAllOption[]                = "--screenshot-all";
const char kScreenshotRangeArgument[]            = "--screenshots";
const char kScreenshotFormatArgument[]           = "--screenshot-format";
const char kScreenshotDirArgument[]              = "--screenshot-dir";
const char kScreenshotFilePrefixArgument[]       = "--screenshot-prefix";
const char kScreenshotSizeArgument[]             = "--screenshot-size";
const char kScreenshotScaleArgument[]            = "--screenshot-scale";
const char kForceWindowedShortArgument[]         = "--fw";
const char kForceWindowedLongArgument[]          = "--force-windowed";
const char kOutput[]                             = "--output";
const char kMeasurementRangeArgument[]           = "--measurement-frame-range";
const char kQuitAfterMeasurementRangeOption[]    = "--quit-after-measurement-range";
const char kFlushMeasurementRangeOption[]        = "--flush-measurement-range";
const char kEnableUseCapturedSwapchainIndices[]  = "--use-captured-swapchain-indices";
const char kFormatArgument[]                     = "--format";
const char kIncludeBinariesOption[]              = "--include-binaries";
const char kExpandFlagsOption[]                  = "--expand-flags";
const char kFilePerFrameOption[]                 = "--file-per-frame";
#if defined(WIN32)
const char kApiFamilyOption[]       = "--api";
const char kDxTwoPassReplay[]       = "--dx12-two-pass-replay";
const char kDxOverrideObjectNames[] = "--dx12-override-object-names";
#endif

enum class WsiPlatform
{
    kAuto,
    kWin32,
    kXlib,
    kXcb,
    kWayland,
    kDisplay,
    kHeadless
};

const char kWsiPlatformAuto[]     = "auto";
const char kWsiPlatformWin32[]    = "win32";
const char kWsiPlatformXlib[]     = "xlib";
const char kWsiPlatformXcb[]      = "xcb";
const char kWsiPlatformWayland[]  = "wayland";
const char kWsiPlatformDisplay[]  = "display";
const char kWsiPlatformHeadless[] = "headless";

const char kMemoryTranslationNone[]    = "none";
const char kMemoryTranslationRemap[]   = "remap";
const char kMemoryTranslationRealign[] = "realign";
const char kMemoryTranslationRebind[]  = "rebind";

#if defined(WIN32)
const char kApiFamilyVulkan[] = "vulkan";
const char kApiFamilyD3D12[]  = "d3d12";
const char kApiFamilyAll[]    = "all";
#endif

const char kScreenshotFormatBmp[] = "bmp";
const char kScreenshotFormatPng[] = "png";

#if defined(__ANDROID__)
const char kDefaultScreenshotDir[] = "/sdcard";
#else
const char kDefaultScreenshotDir[] = "";
#endif

void ProcessDisableDebugPopup(const gfxrecon::util::ArgumentParser& arg_parser);

void CheckActiveLayers(const std::string& list);

gfxrecon::decode::VulkanResourceAllocator* CreateDefaultAllocator();

gfxrecon::decode::VulkanResourceAllocator* CreateRemapAllocator();

gfxrecon::decode::VulkanResourceAllocator* CreateRebindAllocator();

gfxrecon::decode::CreateResourceAllocator
InitRealignAllocatorCreateFunc(const std::string&                              filename,
                               const gfxrecon::decode::VulkanReplayOptions&    replay_options,
                               gfxrecon::decode::VulkanTrackedObjectInfoTable* tracked_object_info_table);

uint32_t GetPauseFrame(const gfxrecon::util::ArgumentParser& arg_parser);

WsiPlatform GetWsiPlatform(const gfxrecon::util::ArgumentParser& arg_parser);

std::string GetWsiExtensionName(WsiPlatform wsi_platform);

std::string GetWsiArgString();

// Modifies settings parameter with values set via command line
void GetLogSettings(const gfxrecon::util::ArgumentParser& arg_parser, gfxrecon::util::Log::Settings& log_settings);

std::string GetScreenshotDir(const gfxrecon::util::ArgumentParser& arg_parser);

void GetScreenshotSize(const gfxrecon::util::ArgumentParser& arg_parser, uint32_t& width, uint32_t& height);

float GetScreenshotScale(const gfxrecon::util::ArgumentParser& arg_parser);

std::vector<gfxrecon::decode::ScreenshotRange> GetScreenshotRanges(const gfxrecon::util::ArgumentParser& arg_parser);

bool GetMeasurementFrameRange(const gfxrecon::util::ArgumentParser& arg_parser,
                              uint32_t&                             start_frame,
                              uint32_t&                             end_frame);

gfxrecon::decode::CreateResourceAllocator
GetCreateResourceAllocatorFunc(const gfxrecon::util::ArgumentParser&           arg_parser,
                               const std::string&                              filename,
                               const gfxrecon::decode::VulkanReplayOptions&    replay_options,
                               gfxrecon::decode::VulkanTrackedObjectInfoTable* tracked_object_info_table);

#if defined(WIN32)
bool IsApiFamilyIdEnabled(const gfxrecon::util::ArgumentParser& arg_parser, gfxrecon::format::ApiFamilyId api);
#endif

void IsForceWindowed(gfxrecon::decode::ReplayOptions& options, const gfxrecon::util::ArgumentParser& arg_parser);

std::vector<int32_t> GetFilteredMsgs(const gfxrecon::util::ArgumentParser& arg_parser, const char* filter_messages);

void GetReplayOptions(gfxrecon::decode::ReplayOptions& options, const gfxrecon::util::ArgumentParser& arg_parser);

gfxrecon::decode::VulkanReplayOptions
GetVulkanReplayOptions(const gfxrecon::util::ArgumentParser&           arg_parser,
                       const std::string&                              filename,
                       gfxrecon::decode::VulkanTrackedObjectInfoTable* tracked_object_info_table);

#if defined(D3D12_SUPPORT)
gfxrecon::decode::DxReplayOptions GetDxReplayOptions(const gfxrecon::util::ArgumentParser& arg_parser);
#endif

bool CheckOptionPrintVersion(const char* exe_name, const gfxrecon::util::ArgumentParser& arg_parser);

void PrintUsage(const char* exe_name);

bool CheckOptionPrintUsage(const char* exe_name, const gfxrecon::util::ArgumentParser& arg_parser);

#endif // GFXRECON_PLATFORM_SETTINGS_H
