/*
** Copyright (c) 2019-2022 LunarG, Inc.
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
    "-h|--help,--version,--log-debugview,--no-debug-popup,--paused,--sync,--sfa|--skip-failed-allocations,--"
    "opcd|--omit-pipeline-cache-data,--remove-unsupported,--validate,--debug-device-lost,--create-dummy-allocations,--"
    "screenshot-all,--onhb|--omit-null-hardware-buffers,--qamr|--quit-after-measurement-"
    "range,--fmr|--flush-measurement-range,--use-captured-swapchain-indices,--dcp,--discard-cached-psos";
const char kArguments[] =
    "--log-level,--log-file,--gpu,--gpu-group,--pause-frame,--wsi,--surface-index,-m|--memory-translation,"
    "--replace-shaders,--screenshots,--denied-messages,--allowed-messages,--screenshot-format,--"
    "screenshot-dir,--screenshot-prefix,--mfr|--measurement-frame-range,--fw|--force-windowed";

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
    GFXRECON_WRITE_CONSOLE("\t\t\t[--sfa | --skip-failed-allocations] [--replace-shaders <dir>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--opcd | --omit-pipeline-cache-data] [--wsi <platform>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--surface-index <N>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--remove-unsupported] [--validate]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--onhb | --omit-null-hardware-buffers]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[-m <mode> | --memory-translation <mode>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--use-captured-swapchain-indices]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--fw <width,height> | --force-windowed <width,height>]");
#if defined(WIN32)
    GFXRECON_WRITE_CONSOLE("\t\t\t[--log-level <level>] [--log-file <file>] [--log-debugview]");
#if defined(_DEBUG)
    GFXRECON_WRITE_CONSOLE("\t\t\t[--api <api>] [--no-debug-popup] <file>\n");
#else
    GFXRECON_WRITE_CONSOLE("\t\t\t[--api <api>] <file>\n");
#endif
#else
    GFXRECON_WRITE_CONSOLE("\t\t\t[--log-level <level>] [--log-file <file>] <file>");
#endif

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
    GFXRECON_WRITE_CONSOLE("  --screenshot-dir <dir>");
    GFXRECON_WRITE_CONSOLE("          \t\tDirectory to write screenshots.  Default is the current");
    GFXRECON_WRITE_CONSOLE("          \t\tworking directory.");
    GFXRECON_WRITE_CONSOLE("  --screenshot-prefix <file-prefix>");
    GFXRECON_WRITE_CONSOLE("          \t\tPrefix to apply to the screenshot file name.  Default is ");
    GFXRECON_WRITE_CONSOLE("          \t\t\"screenshot\", producing file names similar to");
    GFXRECON_WRITE_CONSOLE("          \t\t\"screenshot_frame_8049.bmp\".");
    GFXRECON_WRITE_CONSOLE("  --validate\t\tEnables the Khronos Vulkan validation layer when replaying a");
    GFXRECON_WRITE_CONSOLE("            \t\tVulkan capture or the Direct3D debug layer when replaying a");
    GFXRECON_WRITE_CONSOLE("            \t\tDirect3D 12 capture.");
    GFXRECON_WRITE_CONSOLE("  --gpu <index>\t\tUse the specified device for replay, where index");
    GFXRECON_WRITE_CONSOLE("          \t\tis the zero-based index to the array of physical devices");
    GFXRECON_WRITE_CONSOLE("          \t\treturned by vkEnumeratePhysicalDevices.  Replay may fail");
    GFXRECON_WRITE_CONSOLE("          \t\tif the specified device is not compatible with the");
    GFXRECON_WRITE_CONSOLE("          \t\toriginal capture devices.");
#if defined(WIN32)
    GFXRECON_WRITE_CONSOLE("")
    GFXRECON_WRITE_CONSOLE("Windows-only:")
    GFXRECON_WRITE_CONSOLE("  --api <api>\t\tUse the specified API for replay");
    GFXRECON_WRITE_CONSOLE("          \t\tAvailable values are:");
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\tReplay with the Vulkan API enabled.", kApiFamilyVulkan);
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\tReplay with the Direct3D API enabled.", kApiFamilyD3D12);
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\t\tReplay with both the Vulkan and Direct3D 12 APIs", kApiFamilyAll);
    GFXRECON_WRITE_CONSOLE("          \t\t         \tenabled. This is the default.");
#endif
    GFXRECON_WRITE_CONSOLE("")
    GFXRECON_WRITE_CONSOLE("Vulkan-only:")
    GFXRECON_WRITE_CONSOLE("  --sfa\t\t\tSkip vkAllocateMemory, vkAllocateCommandBuffers, and");
    GFXRECON_WRITE_CONSOLE("       \t\t\tvkAllocateDescriptorSets calls that failed during");
    GFXRECON_WRITE_CONSOLE("       \t\t\tcapture (same as --skip-failed-allocations).");
    GFXRECON_WRITE_CONSOLE("  --replace-shaders <dir> Replace the shader code in each CreateShaderModule");
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
    GFXRECON_WRITE_CONSOLE("  --use-captured-swapchain-indices");
    GFXRECON_WRITE_CONSOLE("          \t\tUse the swapchain indices stored in the capture directly on the swapchain");
    GFXRECON_WRITE_CONSOLE(
        "          \t\tsetup for replay. The default without this option is to use a Virtual Swapchain");
    GFXRECON_WRITE_CONSOLE("          \t\tof images which match the swapchain in effect at capture time and which are");
    GFXRECON_WRITE_CONSOLE("          \t\tcopied to the underlying swapchain of the implementation being replayed on.");
    GFXRECON_WRITE_CONSOLE("  --measurement-frame-range <start_frame>-<end_frame>");
    GFXRECON_WRITE_CONSOLE("          \t\tCustom framerange to measure FPS for.");
    GFXRECON_WRITE_CONSOLE("          \t\tThis range will include the start frame but not the end frame.");
    GFXRECON_WRITE_CONSOLE("          \t\tThe measurement frame range defaults to all frames except the loading");
    GFXRECON_WRITE_CONSOLE("          \t\tframe but can be configured for any range. If the end frame is past the");
    GFXRECON_WRITE_CONSOLE("          \t\tlast frame in the trace it will be clamped to the frame after the last");
    GFXRECON_WRITE_CONSOLE("          \t\t(so in that case the results would include the last frame).");
    GFXRECON_WRITE_CONSOLE("  --quit-after-measurement-range");
    GFXRECON_WRITE_CONSOLE("          \t\tIf this is specified the replayer will abort");
    GFXRECON_WRITE_CONSOLE("          \t\twhen it reaches the <end_frame> specified in");
    GFXRECON_WRITE_CONSOLE("          \t\tthe --measurement-frame-range argument.");
    GFXRECON_WRITE_CONSOLE("  --flush-measurement-range");
    GFXRECON_WRITE_CONSOLE("          \t\tIf this is specified the replayer will flush")
    GFXRECON_WRITE_CONSOLE("          \t\tand wait for all current GPU work to finish at the");
    GFXRECON_WRITE_CONSOLE("          \t\tstart and end of the measurement range.");
    GFXRECON_WRITE_CONSOLE("  --gpu-group <index>\t\tUse the specified device group for replay, where index");
    GFXRECON_WRITE_CONSOLE("          \t\tis the zero-based index to the array of physical device group");
    GFXRECON_WRITE_CONSOLE("          \t\treturned by vkEnumeratePhysicalDeviceGroups.  Replay may fail");
    GFXRECON_WRITE_CONSOLE("          \t\tif the specified device group is not compatible with the");
    GFXRECON_WRITE_CONSOLE("          \t\toriginal capture device group.");

#if defined(WIN32)
    GFXRECON_WRITE_CONSOLE("")
    GFXRECON_WRITE_CONSOLE("D3D12-only:")
    GFXRECON_WRITE_CONSOLE("  --dcp\t\t\tForce CachedPSO to null when creating graphics or compute PSOs.");
    GFXRECON_WRITE_CONSOLE("       \t\t\tCan help enable replay across changing driver installs.");
    GFXRECON_WRITE_CONSOLE("       \t\t\t(Same as --discard-cached-psos)");
    GFXRECON_WRITE_CONSOLE("  --debug-device-lost\tEnables automatic injection of breadcrumbs into command buffers");
    GFXRECON_WRITE_CONSOLE("            \t\tand page fault reporting.");
    GFXRECON_WRITE_CONSOLE("            \t\tUsed to debug Direct3D 12 device removed problems.");
    GFXRECON_WRITE_CONSOLE("  --fw <width,height>\tSetup windowed and override resolution.");
    GFXRECON_WRITE_CONSOLE("                     \t(Same as --force-windowed)");
    GFXRECON_WRITE_CONSOLE("  --create-dummy-allocations Enables creation of dummy heaps and resources");
    GFXRECON_WRITE_CONSOLE("                             for replay validation.");

#endif

#if defined(_DEBUG)
    GFXRECON_WRITE_CONSOLE("  --no-debug-popup\tDisable the 'Abort, Retry, Ignore' message box");
    GFXRECON_WRITE_CONSOLE("       \t\t\tdisplayed when abort() is called (Windows debug only).");
#endif
}

#endif // GFXRECON_REPLAY_SETTINGS_H
