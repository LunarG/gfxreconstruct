/*
** Copyright (c) 2019-2023 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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

#include "../tool_settings.h"

#ifndef GFXRECON_REPLAY_SETTINGS_H
#define GFXRECON_REPLAY_SETTINGS_H

const char kOptions[] =
    "-h|--help,--version,--log-debugview,--no-debug-popup,--paused,--sync,--sfa|--skip-failed-allocations,--opcd|--"
    "omit-pipeline-cache-data,--remove-unsupported,--validate,--debug-device-lost,--create-dummy-allocations,--"
    "screenshot-all,--onhb|--omit-null-hardware-buffers,--qamr|--quit-after-measurement-range,--fmr|--flush-"
    "measurement-range,--flush-inside-measurement-range,--vssb|--virtual-swapchain-skip-blit,--use-captured-swapchain-"
    "indices,--dcp,--discard-cached-psos,--use-colorspace-fallback,--use-cached-psos,--dx12-override-object-names,--"
    "offscreen-swapchain-frame-boundary,--wait-before-present,--dump-resources-before-draw,"
    "--dump-resources-dump-depth-attachment,--dump-"
    "resources-dump-vertex-index-buffers,--dump-resources-json-output-per-command,--dump-resources-dump-immutable-"
    "resources,--dump-resources-dump-all-image-subresources";
const char kArguments[] =
    "--log-level,--log-file,--gpu,--gpu-group,--pause-frame,--wsi,--surface-index,-m|--memory-translation,"
    "--replace-shaders,--screenshots,--denied-messages,--allowed-messages,--screenshot-format,--"
    "screenshot-dir,--screenshot-prefix,--screenshot-size,--screenshot-scale,--mfr|--measurement-frame-range,--fw|--"
    "force-windowed,--fwo|--force-windowed-origin,--batching-memory-usage,--measurement-file,--swapchain,--sgfs|--skip-"
    "get-fence-status,--sgfr|--"
    "skip-get-fence-ranges,--dump-resources,--dump-resources-scale,--dump-resources-image-format,--dump-resources-dir,"
    "--dump-resources-dump-color-attachment-index";

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
    GFXRECON_WRITE_CONSOLE("  %s\t[-h | --help] [--version] [--gpu <index>] [--gpu-group <index>]", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("\t\t\t[--pause-frame <N>] [--paused] [--sync] [--screenshot-all]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--screenshots <N1(-N2),...>] [--screenshot-format <format>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--screenshot-dir <dir>] [--screenshot-prefix <file-prefix>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--screenshot-size <width>x<height>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--screenshot-scale <scale>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--sfa | --skip-failed-allocations] [--replace-shaders <dir>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--opcd | --omit-pipeline-cache-data] [--wsi <platform>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--use-cached-psos] [--surface-index <N>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--remove-unsupported] [--validate]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--onhb | --omit-null-hardware-buffers]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[-m <mode> | --memory-translation <mode>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--swapchain <mode>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--vssb | --virtual-swapchain-skip-blit]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--use-captured-swapchain-indices]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--use-colorspace-fallback]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--offscreen-swapchain-frame-boundary]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--mfr|--measurement-frame-range <start-frame>-<end-frame>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--measurement-file <file>] [--quit-after-measurement-range]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--flush-measurement-range]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--fw <width,height> | --force-windowed <width,height>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--sgfs <status> | --skip-get-fence-status <status>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--sgfr <frame-ranges> | --skip-get-fence-ranges <frame-ranges>]");
#if defined(WIN32)
    GFXRECON_WRITE_CONSOLE("\t\t\t[--dump-resources <submit-index,command-index,drawcall-index>]");
#endif
    GFXRECON_WRITE_CONSOLE("\t\t\t[--dump-resources <arg>] [--dump-resources <file>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--dump-resources-before-draw] [--dump-resources-scale <scale>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--dump-resources-dir <dir>] [--dump-resources-image-format <format>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--dump-resources-dump-depth-attachment]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--dump-resources-dump-color-attachment-index <index>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--dump-resources-dump-vertex-index-buffers]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--dump-resources-json-output-per-command]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--dump-resources-dump-immutable-resources]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--dump-resources-dump-all-image-subresources]");
#if defined(WIN32)
    GFXRECON_WRITE_CONSOLE("\t\t\t[--fwo <x,y> | --force-windowed-origin <x,y>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--log-level <level>] [--log-file <file>] [--log-debugview]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--batching-memory-usage <pct>]");
#if defined(_DEBUG)
    GFXRECON_WRITE_CONSOLE("\t\t\t[--no-debug-popup]");
#endif
#else
    GFXRECON_WRITE_CONSOLE("\t\t\t[--log-level <level>] [--log-file <file>]");
#endif
    GFXRECON_WRITE_CONSOLE("\t\t\t<file>\n");

    GFXRECON_WRITE_CONSOLE("Required arguments:");
    GFXRECON_WRITE_CONSOLE("  <file>\t\tPath to the capture file to replay.");
    GFXRECON_WRITE_CONSOLE("\nOptional arguments:");
    GFXRECON_WRITE_CONSOLE("  -h\t\t\tPrint usage information and exit (same as --help).");
    GFXRECON_WRITE_CONSOLE("  --version\t\tPrint version information and exit.");
    GFXRECON_WRITE_CONSOLE("  --log-level <level>\tSpecify highest level message to log. Options are:");
    GFXRECON_WRITE_CONSOLE("          \t\tdebug, info, warning, error, and fatal. Default is info.");
    GFXRECON_WRITE_CONSOLE("  --log-file <file>\tWrite log messages to a file at the specified path.")
    GFXRECON_WRITE_CONSOLE("          \t\tDefault is: Empty string (file logging disabled).");
#if defined(WIN32)
    GFXRECON_WRITE_CONSOLE("  --log-debugview\tLog messages with OutputDebugStringA.");
#endif
    GFXRECON_WRITE_CONSOLE("  --pause-frame <N>\tPause after replaying frame number N.");
    GFXRECON_WRITE_CONSOLE("  --paused\t\tPause after replaying the first frame (same");
    GFXRECON_WRITE_CONSOLE("          \t\tas --pause-frame 1).");
    GFXRECON_WRITE_CONSOLE("  --screenshot-all");
    GFXRECON_WRITE_CONSOLE("          \t\tGenerate screenshots for all frames.  When this");
    GFXRECON_WRITE_CONSOLE("          \t\toption is specified, --screenshots is ignored.");
    GFXRECON_WRITE_CONSOLE("  --screenshots <N1[-N2][,...]>");
    GFXRECON_WRITE_CONSOLE("          \t\tGenerate screenshots for the specified frames.");
    GFXRECON_WRITE_CONSOLE("          \t\tTarget frames are specified as a comma separated");
    GFXRECON_WRITE_CONSOLE("          \t\tlist of frame ranges.  A frame range can be specified");
    GFXRECON_WRITE_CONSOLE("          \t\tas a single value, to specify a single frame, or as");
    GFXRECON_WRITE_CONSOLE("          \t\ttwo hyphenated values, to specify the first and last");
    GFXRECON_WRITE_CONSOLE("          \t\tframes to process.  Frame ranges should be specified in");
    GFXRECON_WRITE_CONSOLE("          \t\tascending order and cannot overlap.  Note that frame");
    GFXRECON_WRITE_CONSOLE("          \t\tnumbering is 1-based (i.e. the first frame is frame 1).");
    GFXRECON_WRITE_CONSOLE("          \t\tExample: 200,301-305 will generate six screenshots.");
    GFXRECON_WRITE_CONSOLE("  --screenshot-format <format>");
    GFXRECON_WRITE_CONSOLE("          \t\tImage file format to use for screenshot generation.");
    GFXRECON_WRITE_CONSOLE("          \t\tAvailable formats are:");
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\t\tBitmap file format.  This is the default format.",
                           kScreenshotFormatBmp);
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\t\tPortable Network Graphics file format.", kScreenshotFormatPng);
    GFXRECON_WRITE_CONSOLE("  --screenshot-dir <dir>");
    GFXRECON_WRITE_CONSOLE("          \t\tDirectory to write screenshots.  Default is the current");
    GFXRECON_WRITE_CONSOLE("          \t\tworking directory.");
    GFXRECON_WRITE_CONSOLE("  --screenshot-prefix <file-prefix>");
    GFXRECON_WRITE_CONSOLE("          \t\tPrefix to apply to the screenshot file name.  Default is ");
    GFXRECON_WRITE_CONSOLE("          \t\t\"screenshot\", producing file names similar to");
    GFXRECON_WRITE_CONSOLE("          \t\t\"screenshot_frame_8049.bmp\".");
    GFXRECON_WRITE_CONSOLE("  --screenshot-scale <factor>");
    GFXRECON_WRITE_CONSOLE("          \t\tSpecify a decimal factor which will determine screenshot sizes.");
    GFXRECON_WRITE_CONSOLE("          \t\tThe factor will be multiplied with the swapchain images");
    GFXRECON_WRITE_CONSOLE("          \t\tdimension to determine the screenshot dimensions. Default is 1.0.");
    GFXRECON_WRITE_CONSOLE("  --screenshot-size <width>x<height>");
    GFXRECON_WRITE_CONSOLE("          \t\tSpecify desired screenshot dimensions. Leaving this unspecified");
    GFXRECON_WRITE_CONSOLE("          \t\tscreenshots will use the swapchain images dimensions. If ");
    GFXRECON_WRITE_CONSOLE("          \t\t--screenshot-scale is also specified then this option is ignored.");
    GFXRECON_WRITE_CONSOLE("  --validate\t\tEnable the Khronos Vulkan validation layer when replaying a");
    GFXRECON_WRITE_CONSOLE("            \t\tVulkan capture or the Direct3D debug layer when replaying a");
    GFXRECON_WRITE_CONSOLE("            \t\tDirect3D 12 capture.");
    GFXRECON_WRITE_CONSOLE("  --gpu <index>\t\tUse the specified device for replay, where index");
    GFXRECON_WRITE_CONSOLE("          \t\tis the zero-based index to the array of physical devices");
    GFXRECON_WRITE_CONSOLE("          \t\treturned by vkEnumeratePhysicalDevices or IDXGIFactory1::EnumAdapters1.");
    GFXRECON_WRITE_CONSOLE("          \t\tReplay may fail if the specified device is not compatible with the");
    GFXRECON_WRITE_CONSOLE("          \t\toriginal capture devices.");
#if defined(WIN32)
    GFXRECON_WRITE_CONSOLE("")
    GFXRECON_WRITE_CONSOLE("Windows only:")
    GFXRECON_WRITE_CONSOLE(
        "  --fwo <x,y>\t\tForce windowed mode if not already, and allow setting of a custom window location.");
    GFXRECON_WRITE_CONSOLE("          \t\t(Same as --force-windowed-origin)");
#if defined(_DEBUG)
    GFXRECON_WRITE_CONSOLE("  --no-debug-popup\tDisable the 'Abort, Retry, Ignore' message box");
    GFXRECON_WRITE_CONSOLE("       \t\t\tdisplayed when abort() is called (Windows debug only).");
#endif
#endif
    GFXRECON_WRITE_CONSOLE("")
    GFXRECON_WRITE_CONSOLE("Vulkan only:")
    GFXRECON_WRITE_CONSOLE("  --sfa\t\t\tSkip vkAllocateMemory, vkAllocateCommandBuffers, and");
    GFXRECON_WRITE_CONSOLE("       \t\t\tvkAllocateDescriptorSets calls that failed during");
    GFXRECON_WRITE_CONSOLE("       \t\t\tcapture (same as --skip-failed-allocations).");
    GFXRECON_WRITE_CONSOLE("  --replace-shaders <dir>");
    GFXRECON_WRITE_CONSOLE("       \t\t\tReplace the shader code in each CreateShaderModule");
    GFXRECON_WRITE_CONSOLE("       \t\t\twith the contents of the file <dir>/sh<handle_id> if found, where");
    GFXRECON_WRITE_CONSOLE("       \t\t\t<handle_id> is the handle id of the CreateShaderModule call.");
    GFXRECON_WRITE_CONSOLE("       \t\t\tSee gfxrecon-extract.");
    GFXRECON_WRITE_CONSOLE("  --opcd\t\tOmit pipeline cache data from calls to");
    GFXRECON_WRITE_CONSOLE("        \t\tvkCreatePipelineCache and skip calls to");
    GFXRECON_WRITE_CONSOLE("        \t\tvkGetPipelineCacheData (same as");
    GFXRECON_WRITE_CONSOLE("        \t\t--omit-pipeline-cache-data).");
    GFXRECON_WRITE_CONSOLE("  --wsi <platform>\tForce replay to use the specified wsi platform.");
    GFXRECON_WRITE_CONSOLE("                  \tAvailable platforms are: %s", GetWsiArgString().c_str());
    GFXRECON_WRITE_CONSOLE("  --surface-index <N>\tRestrict rendering to the Nth surface object created.");
    GFXRECON_WRITE_CONSOLE("                  \tUsed with captures that include multiple surfaces.  Default");
    GFXRECON_WRITE_CONSOLE("                  \tis -1 (render to all surfaces).");
    GFXRECON_WRITE_CONSOLE("  --sync\t\tSynchronize after each queue submission with vkQueueWaitIdle.");
    GFXRECON_WRITE_CONSOLE("  --remove-unsupported\tRemove unsupported extensions and features from instance");
    GFXRECON_WRITE_CONSOLE("                      \tand device creation parameters.");
    GFXRECON_WRITE_CONSOLE("  -m <mode>\t\tEnable memory translation for replay on GPUs with memory");
    GFXRECON_WRITE_CONSOLE("          \t\ttypes that are not compatible with the capture GPU's");
    GFXRECON_WRITE_CONSOLE("          \t\tmemory types.  Available modes are:");
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\tNo memory translation is performed.  This", kMemoryTranslationNone);
    GFXRECON_WRITE_CONSOLE("          \t\t         \tis the default behavior.");
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\tAttempt to map capture memory types to", kMemoryTranslationRemap);
    GFXRECON_WRITE_CONSOLE("          \t\t         \tcompatible replay memory types, without");
    GFXRECON_WRITE_CONSOLE("          \t\t         \taltering memory allocation behavior.");
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\tAdjust memory allocation sizes and", kMemoryTranslationRealign);
    GFXRECON_WRITE_CONSOLE("          \t\t         \tresource binding offsets based on");
    GFXRECON_WRITE_CONSOLE("          \t\t         \treplay memory properties.");
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\tChange memory allocation behavior based", kMemoryTranslationRebind);
    GFXRECON_WRITE_CONSOLE("          \t\t         \ton resource usage and replay memory");
    GFXRECON_WRITE_CONSOLE("          \t\t         \tproperties.  Resources may be bound");
    GFXRECON_WRITE_CONSOLE("          \t\t         \tto different allocations with different");
    GFXRECON_WRITE_CONSOLE("          \t\t         \toffsets.  Uses VMA to manage allocations");
    GFXRECON_WRITE_CONSOLE("          \t\t         \tand suballocations.");
    GFXRECON_WRITE_CONSOLE("  --swapchain <mode>\tChoose a swapchain mode to replay.");
    GFXRECON_WRITE_CONSOLE("          \t\tAvailable modes are:");
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\tVirtual Swapchain of images which match", kSwapchainVirtual);
    GFXRECON_WRITE_CONSOLE("          \t\t         \tthe swapchain in effect at capture time and");
    GFXRECON_WRITE_CONSOLE("          \t\t         \twhich are copied to the underlying swapchain of the");
    GFXRECON_WRITE_CONSOLE("          \t\t         \timplementation being replayed on. This is default.");
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\tUse the swapchain indices stored in the ", kSwapchainCaptured);
    GFXRECON_WRITE_CONSOLE("          \t\t         \tcapture directly on the swapchain setup for replay.");
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\tDisable creating swapchains, surfaces", kSwapchainOffscreen);
    GFXRECON_WRITE_CONSOLE("          \t\t         \tand windows. To see rendering, add the --screenshots option.");
    GFXRECON_WRITE_CONSOLE("  --vssb");
    GFXRECON_WRITE_CONSOLE("          \t\tSkip blit to real swapchain to gain performance during replay.");
    GFXRECON_WRITE_CONSOLE("  --use-captured-swapchain-indices");
    GFXRECON_WRITE_CONSOLE("          \t\tSame as \"--swapchain captured\".");
    GFXRECON_WRITE_CONSOLE("          \t\tIgnored if the \"--swapchain\" option is used.");
    GFXRECON_WRITE_CONSOLE("  --offscreen-swapchain-frame-boundary");
    GFXRECON_WRITE_CONSOLE("          \t\tShould only be used with offscreen swapchain.");
    GFXRECON_WRITE_CONSOLE("          \t\tActivates the extension VK_EXT_frame_boundary (always supported if");
    GFXRECON_WRITE_CONSOLE("          \t\ttrimming, checks for driver support otherwise) and inserts command");
    GFXRECON_WRITE_CONSOLE("          \t\tbuffer submission with VkFrameBoundaryEXT where vkQueuePresentKHR");
    GFXRECON_WRITE_CONSOLE("          \t\twas called in the original capture.");
    GFXRECON_WRITE_CONSOLE("          \t\tThis allows preserving frames when capturing a replay that uses.");
    GFXRECON_WRITE_CONSOLE("          \t\toffscreen swapchain.");
    GFXRECON_WRITE_CONSOLE("  --measurement-frame-range <start_frame>-<end_frame>");
    GFXRECON_WRITE_CONSOLE("          \t\tCustom framerange to measure FPS for.");
    GFXRECON_WRITE_CONSOLE("          \t\tThis range will include the start frame but not the end frame.");
    GFXRECON_WRITE_CONSOLE("          \t\tThe measurement frame range defaults to all frames except the loading");
    GFXRECON_WRITE_CONSOLE("          \t\tframe but can be configured for any range. If the end frame is past the");
    GFXRECON_WRITE_CONSOLE("          \t\tlast frame in the trace it will be clamped to the frame after the last");
    GFXRECON_WRITE_CONSOLE("          \t\t(so in that case the results would include the last frame).");
    GFXRECON_WRITE_CONSOLE("  --use-colorspace-fallback");
    GFXRECON_WRITE_CONSOLE("          \t\tSwap the swapchain color space if unsupported by replay device.");
    GFXRECON_WRITE_CONSOLE("          \t\tCheck if color space is not supported by replay device and fallback to "
                           "VK_COLOR_SPACE_SRGB_NONLINEAR_KHR.");
    GFXRECON_WRITE_CONSOLE("  --measurement-file <file>");
    GFXRECON_WRITE_CONSOLE("          \t\tWrite measurements to a file at the specified path.");
    GFXRECON_WRITE_CONSOLE("          \t\tDefault is: '/sdcard/gfxrecon-measurements.json' on android and");
    GFXRECON_WRITE_CONSOLE("          \t\t'./gfxrecon-measurements.json' on desktop.");
    GFXRECON_WRITE_CONSOLE("  --quit-after-measurement-range");
    GFXRECON_WRITE_CONSOLE("          \t\tIf this is specified the replayer will abort");
    GFXRECON_WRITE_CONSOLE("          \t\twhen it reaches the <end_frame> specified in");
    GFXRECON_WRITE_CONSOLE("          \t\tthe --measurement-frame-range argument.");
    GFXRECON_WRITE_CONSOLE("  --flush-measurement-range");
    GFXRECON_WRITE_CONSOLE("          \t\tIf this is specified the replayer will flush")
    GFXRECON_WRITE_CONSOLE("          \t\tand wait for all current GPU work to finish at the");
    GFXRECON_WRITE_CONSOLE("          \t\tstart and end of the measurement range.");
    GFXRECON_WRITE_CONSOLE("  --flush-inside-measurement-range");
    GFXRECON_WRITE_CONSOLE("          \t\tIf this is specified the replayer will flush")
    GFXRECON_WRITE_CONSOLE("          \t\tand wait for all current GPU work to finish at the");
    GFXRECON_WRITE_CONSOLE("          \t\tend of each frame inside the measurement range.");
    GFXRECON_WRITE_CONSOLE("  --gpu-group <index>\tUse the specified device group for replay, where index");
    GFXRECON_WRITE_CONSOLE("          \t\tis the zero-based index to the array of physical device group");
    GFXRECON_WRITE_CONSOLE("          \t\treturned by vkEnumeratePhysicalDeviceGroups.  Replay may fail");
    GFXRECON_WRITE_CONSOLE("          \t\tif the specified device group is not compatible with the");
    GFXRECON_WRITE_CONSOLE("          \t\toriginal capture device group.");
    GFXRECON_WRITE_CONSOLE("  --sgfs <status>");
    GFXRECON_WRITE_CONSOLE("          \t\tSpecify behaviour to skip calls to vkWaitForFences and vkGetFenceStatus:");
    GFXRECON_WRITE_CONSOLE("          \t\t\tstatus=0 : Don't skip");
    GFXRECON_WRITE_CONSOLE("          \t\t\tstatus=1 : Skip unsuccessful calls");
    GFXRECON_WRITE_CONSOLE("          \t\t\tstatus=2 : Always skip");
    GFXRECON_WRITE_CONSOLE("          \t\tIf no skip frame range is specified (--sgfr), the status applies to all");
    GFXRECON_WRITE_CONSOLE("          \t\tframes.");
    GFXRECON_WRITE_CONSOLE("  --sgfr <frame-ranges>");
    GFXRECON_WRITE_CONSOLE("          \t\tFrame ranges where --sgfs applies. The format is:");
    GFXRECON_WRITE_CONSOLE("          \t\t\t<frame-start-1>-<frame-end-1>[,<frame-start-1>-<frame-end-1>]*");
    GFXRECON_WRITE_CONSOLE("  --wait-before-present");
    GFXRECON_WRITE_CONSOLE("          \t\tForce wait on completion of queue operations for all queues");
    GFXRECON_WRITE_CONSOLE("          \t\tbefore calling Present. This is needed for accurate acquisition");
    GFXRECON_WRITE_CONSOLE("          \t\tof instrumentation data on some platforms.");
    GFXRECON_WRITE_CONSOLE("  --dump-resources <arg>");
    GFXRECON_WRITE_CONSOLE("          \t\t<arg> is BeginCommandBuffer=<n>,Draw=<m>,BeginRenderPass=<o>,");
    GFXRECON_WRITE_CONSOLE("          \t\tNextSubpass=<p>,Dispatch=<q>,CmdTraceRays=<r>,QueueSubmit=<s>");
    GFXRECON_WRITE_CONSOLE("          \t\tGPU resources are dumped after the given vkCmdDraw*,");
    GFXRECON_WRITE_CONSOLE("          \t\tvkCmdDispatch, or vkCmdTraceRaysKHR is replayed.");
    GFXRECON_WRITE_CONSOLE("  --dump-resources <file>");
    GFXRECON_WRITE_CONSOLE("          \t\tExtract --dump-resources args from the specified file. Can be");
    GFXRECON_WRITE_CONSOLE("          \t\teither a json or a text file. If a text file is used, each");
    GFXRECON_WRITE_CONSOLE("          \t\tline of the file should contain comma separated indices as in");
    GFXRECON_WRITE_CONSOLE("          \t\t--dump-resources <arg> above.");
    GFXRECON_WRITE_CONSOLE("  --dump-resources-before-draw");
    GFXRECON_WRITE_CONSOLE("          \t\tIn addition to dumping GPU resources after the Vulkan draw calls");
    GFXRECON_WRITE_CONSOLE("          \t\tspecified by the --dump-resources argument, also dump resources");
    GFXRECON_WRITE_CONSOLE("          \t\tbefore the draw calls.");
    GFXRECON_WRITE_CONSOLE("  --dump-resources-scale <scale>");
    GFXRECON_WRITE_CONSOLE("          \t\tScale images generated by dump resources by the given scale factor.");
    GFXRECON_WRITE_CONSOLE("          \t\tThe scale factor must be a floating point number greater than 0.");
    GFXRECON_WRITE_CONSOLE("          \t\tValues greater than 10 are capped at 10. Default value is 1.0.");
    GFXRECON_WRITE_CONSOLE("  --dump-resources-dir <dir>");
    GFXRECON_WRITE_CONSOLE("          \t\tDirectory to write dump resources output files.");
    GFXRECON_WRITE_CONSOLE("          \t\tDefault is the current working directory.");
    GFXRECON_WRITE_CONSOLE("  --dump-resources-image-format <format>");
    GFXRECON_WRITE_CONSOLE("          \t\tImage file format to use when dumping image resources.");
    GFXRECON_WRITE_CONSOLE("          \t\tAvailable formats are: bmp, png");
    GFXRECON_WRITE_CONSOLE("  --dump-resources-dump-depth-attachment");
    GFXRECON_WRITE_CONSOLE("          \t\tConfigures whether to dump the depth attachment of draw calls.");
    GFXRECON_WRITE_CONSOLE("          \t\tDefault is false.");
    GFXRECON_WRITE_CONSOLE("  --dump-resources-dump-color-attachment-index <index>");
    GFXRECON_WRITE_CONSOLE("          \t\tConfigures which color attachment to dump when dumping draw calls.");
    GFXRECON_WRITE_CONSOLE("          \t\tDefault is all attachments.");
    GFXRECON_WRITE_CONSOLE("  --dump-resources-dump-vertex-index-buffers");
    GFXRECON_WRITE_CONSOLE("          \t\tEnable dumping of vertex and index buffers while dumping draw");
    GFXRECON_WRITE_CONSOLE("          \t\tcall resources. Default is disabled.");
    GFXRECON_WRITE_CONSOLE("  --dump-resources-json-output-per-command");
    GFXRECON_WRITE_CONSOLE("          \t\tEnable storing a json output file for each dumped command.");
    GFXRECON_WRITE_CONSOLE("          \t\tOverrides default behavior which is generating one output json file that");
    GFXRECON_WRITE_CONSOLE("          \t\tcontains the information for all dumped commands.");
    GFXRECON_WRITE_CONSOLE("  --dump-resources-dump-immutable-resources");
    GFXRECON_WRITE_CONSOLE("          \t\tDump immutable shader resources.");
    GFXRECON_WRITE_CONSOLE("  --dump-resources-dump-all-image-subresources");
    GFXRECON_WRITE_CONSOLE("          \t\tDump all available mip levels and layers when dumping images.");

#if defined(WIN32)
    GFXRECON_WRITE_CONSOLE("")
    GFXRECON_WRITE_CONSOLE("D3D12 only:")
    GFXRECON_WRITE_CONSOLE(
        "  --use-cached-psos  \tPermit using cached PSOs when creating graphics or compute pipelines.");
    GFXRECON_WRITE_CONSOLE(
        "       \t\t\tUsing cached PSOs may reduce PSO creation time but may result in replay errors.");
    GFXRECON_WRITE_CONSOLE("  --debug-device-lost\tEnable automatic injection of breadcrumbs into command buffers");
    GFXRECON_WRITE_CONSOLE("            \t\tand page fault reporting.");
    GFXRECON_WRITE_CONSOLE("            \t\tUsed to debug Direct3D 12 device removed problems.");
    GFXRECON_WRITE_CONSOLE("  --fw <width,height>\tSetup windowed and override resolution.");
    GFXRECON_WRITE_CONSOLE("                     \t(Same as --force-windowed)");
    GFXRECON_WRITE_CONSOLE("  --create-dummy-allocations");
    GFXRECON_WRITE_CONSOLE("          \t\tEnable creation of dummy heaps and resources for replay validation.");
    GFXRECON_WRITE_CONSOLE("  --dx12-override-object-names");
    GFXRECON_WRITE_CONSOLE("          \t\tGenerate unique names for all ID3D12Objects and");
    GFXRECON_WRITE_CONSOLE("          \t\tassign each object the generated name.");
    GFXRECON_WRITE_CONSOLE("          \t\tThis is intended to assist in replay debugging.");
    GFXRECON_WRITE_CONSOLE("  --batching-memory-usage <pct>");
    GFXRECON_WRITE_CONSOLE("          \t\tMax amount of memory consumption while loading a trimmed capture file.");
    GFXRECON_WRITE_CONSOLE("          \t\tAcceptable values range from 0 to 100 (default: 80)");
    GFXRECON_WRITE_CONSOLE("          \t\t0 means no batching at all");
    GFXRECON_WRITE_CONSOLE("          \t\t100 means use all available system and GPU memory");
    GFXRECON_WRITE_CONSOLE("  --dump-resources <submit-index,command-index,drawcall-index>");
    GFXRECON_WRITE_CONSOLE("          \t\tOutput binaray resources for a specific drawcall.");
    GFXRECON_WRITE_CONSOLE("          \t\tInclude vertex, index, const buffer, shader resource, render target,");
    GFXRECON_WRITE_CONSOLE("          \t\tand depth stencil. And for before and after drawcall.");
    GFXRECON_WRITE_CONSOLE("          \t\tArguments becomes three indices, submit index, command index,");
    GFXRECON_WRITE_CONSOLE("          \t\tdrawcall index. The command index is based on its in ExecuteCommandLists.");
#endif
}

#endif // GFXRECON_REPLAY_SETTINGS_H
