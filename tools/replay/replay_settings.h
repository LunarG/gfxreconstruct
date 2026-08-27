/*
** Copyright (c) 2019-2023 LunarG, Inc.
** Copyright (c) 2023-2025 Advanced Micro Devices, Inc. All rights reserved.
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

#include "tool_settings.h"
#include "tool_command_line.h"
#include "tool_feature_options.h"

#include "replay_main_common.h"

#ifndef GFXRECON_REPLAY_SETTINGS_H
#define GFXRECON_REPLAY_SETTINGS_H

const char kOptions[] =
    "-h|--help,--version,--log-debugview,--no-debug-popup,--paused,--sync,--remove-unsupported,--validate,"
    "--debug-device-lost,--create-dummy-allocations,--screenshot-all,--onhb|--omit-null-hardware-buffers,"
    "--qamr|--quit-after-measurement-range,--fmr|--flush-measurement-range,--flush-inside-measurement-range,"
    "--pbi-all,--preload-measurement-range,--log-timestamps,--async-processing,"
    "--dump-resources-before-draw,--dump-resources-modifiable-state-only";

const char kArguments[] =
    "--log-level,--log-file,--cpu-mask,--gpu,--pause-frame,--wsi,--screenshots,--screenshot-interval,"
    "--screenshot-format,--screenshot-dir,--screenshot-prefix,--screenshot-size,--screenshot-scale,"
    "--mfr|--measurement-frame-range,--fw|--force-windowed,--fwo|--force-windowed-origin,--measurement-file,"
    "--dump-resources,--dump-resources-dir,--dump-resources-image-format,--pbis,"
    "--pcj|--pipeline-creation-jobs,--quit-after-frame,"
    "--wait-before-first-submit,--frame-warm-up-spirv,--frame-warm-up-load,--wait-before-frame,--loop-frame,"
    "--loop-count";

// The three names below belong to the D3D12 Feature, but they stay in the shared lists above:
//     --dump-resources-before-draw            The D3D12 Feature reads it.
//     --dump-resources-modifiable-state-only  The D3D12 Feature reads it.
//     --dump-resources-image-format           No code reads it yet.
// Each platform accepted the three names before the Features had their own command-line entries.
// An application can depend on that behavior, so each platform must continue to accept them. A
// build without the D3D12 Feature parses the three names and then ignores them.

// Prints the Feature part of the synopsis as lines that match the width of the lines that the
// usage function writes before them. A line break comes only between two bracketed fragments.
static void PrintFeatureSynopsisLines(const std::string& synopsis)
{
    const size_t kWrapColumn = 64;
    std::string  line;
    size_t       start = 0;

    while (start < synopsis.size())
    {
        // A fragment ends at the bracket that closes it, and the next fragment starts two
        // characters later, after the bracket and the space.
        size_t end = synopsis.find("] [", start);
        end        = (end == std::string::npos) ? synopsis.size() : (end + 1);

        const std::string fragment = synopsis.substr(start, end - start);

        if (!line.empty() && ((line.size() + fragment.size() + 1) > kWrapColumn))
        {
            GFXRECON_WRITE_CONSOLE("\t\t\t%s", line.c_str());
            line.clear();
        }

        if (!line.empty())
        {
            line += " ";
        }
        line += fragment;

        start = (end < synopsis.size()) ? (end + 1) : end;
    }

    if (!line.empty())
    {
        GFXRECON_WRITE_CONSOLE("\t\t\t%s", line.c_str());
    }
}

static void PrintUsage(const char* exe_name)
{
    std::string app_name = std::filesystem::path(exe_name).stem().string();

    GFXRECON_WRITE_CONSOLE("\n%s - A tool to replay GFXReconstruct capture files.\n", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("Usage:");
    GFXRECON_WRITE_CONSOLE("  %s\t[-h | --help] [--version]", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("\t\t\t[--cpu-mask <binary-mask>] [--gpu <index>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--pause-frame <N>] [--paused] [--sync] [--screenshot-all]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--screenshots <N1(-N2),...>] [--screenshot-format <format>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--screenshot-dir <dir>] [--screenshot-prefix <file-prefix>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--screenshot-size <width>x<height>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--screenshot-scale <scale>] [--screenshot-interval <N>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--wsi <platform>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--remove-unsupported] [--validate]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--onhb | --omit-null-hardware-buffers]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--mfr|--measurement-frame-range <start-frame>-<end-frame>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--measurement-file <file>] [--quit-after-measurement-range]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--flush-measurement-range]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--fw <width,height> | --force-windowed <width,height>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--wait-before-first-submit <milliseconds>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--frame-warm-up-spirv <spirv-file>] [--frame-warm-up-load <load>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--pbi-all] [--pbis <index1,index2>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--wait-before-frame <milliseconds>]");
#if !defined(_WIN32)
    GFXRECON_WRITE_CONSOLE("\t\t\t[--dump-resources <filename>.json]");
#endif
#if defined(_WIN32)
    GFXRECON_WRITE_CONSOLE("\t\t\t[--dump-resources <submit-index,command-index,drawcall-index>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--dump-resources-image-format <format>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--dump-resources-modifiable-state-only]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--fwo <x,y> | --force-windowed-origin <x,y>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--log-level <level>] [--log-file <file>] [--log-debugview]");
#if defined(_DEBUG)
    GFXRECON_WRITE_CONSOLE("\t\t\t[--no-debug-popup]");
#endif
#else
    GFXRECON_WRITE_CONSOLE("\t\t\t[--log-level <level>] [--log-file <file>]");
#endif

    // Each Feature contributes the entries that belong only to that Feature, so an entry is in
    // the synopsis only when the build contains the Feature that reads it.
    PrintFeatureSynopsisLines(BuildFeatureSynopsis(gfxrecon::replay::GetLoadedFeatures()));

    GFXRECON_WRITE_CONSOLE("\t\t\t<file>\n");

    GFXRECON_WRITE_CONSOLE("Required arguments:");
    GFXRECON_WRITE_CONSOLE("  <file>\t\tPath to the capture file to replay.");
    GFXRECON_WRITE_CONSOLE("\nOptional arguments:");
    GFXRECON_WRITE_CONSOLE("  -h\t\t\tPrint usage information and exit (same as --help).");
    GFXRECON_WRITE_CONSOLE("  --version\t\tPrint version information and exit.");
    GFXRECON_WRITE_CONSOLE("  --log-level <level>\tSpecify lowest level message to log. Options are:");
    GFXRECON_WRITE_CONSOLE("          \t\tfatal, error, warning, info, and debug. Default is info.");
    GFXRECON_WRITE_CONSOLE("  --log-timestamps\tOutput a timestamp in front of each log message.");
    GFXRECON_WRITE_CONSOLE("  --log-file <file>\tWrite log messages to a file at the specified path.")
    GFXRECON_WRITE_CONSOLE("          \t\tDefault is: Empty string (file logging disabled).");
#if defined(_WIN32)
    GFXRECON_WRITE_CONSOLE("  --log-debugview\tLog messages with OutputDebugStringA.");
#endif
    GFXRECON_WRITE_CONSOLE(
        "  --debug-messenger-level <level>\tSpecify lowest debug messenger severity level. Options are:")
    GFXRECON_WRITE_CONSOLE("          \t\terror, warning, info, and debug. Default is warning.");
    GFXRECON_WRITE_CONSOLE("  --pause-frame <N>\tPause after replaying frame number N.");
    GFXRECON_WRITE_CONSOLE("  --paused\t\tPause after replaying the first frame (same");
    GFXRECON_WRITE_CONSOLE("          \t\tas --pause-frame 1).");
    GFXRECON_WRITE_CONSOLE("  --loop-frame <N>\tEnable frame repeat (experimental).");
    GFXRECON_WRITE_CONSOLE("          \t\tN specifies the frame number to repeat; default is 0.");
    GFXRECON_WRITE_CONSOLE("  --loop-count <N>\tSpecify the number of times to repeat the frame when");
    GFXRECON_WRITE_CONSOLE("          \t\tloop frame is enabled. Default is 0: replay forever.");
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
    GFXRECON_WRITE_CONSOLE("  --screenshot-interval <N>");
    GFXRECON_WRITE_CONSOLE("          \t\tSpecifies the number of frames between two screenshots");
    GFXRECON_WRITE_CONSOLE("          \t\twithin a screenshot range.");
    GFXRECON_WRITE_CONSOLE("          \t\tExample: If screenshot range is 10-15 and interval is 2,");
    GFXRECON_WRITE_CONSOLE("          \t\tscreenshot will be generated for frames 10, 12 and 14.");
    GFXRECON_WRITE_CONSOLE("          \t\tDefault is 1.");
    GFXRECON_WRITE_CONSOLE("  --screenshot-format <format>");
    GFXRECON_WRITE_CONSOLE("          \t\tImage file format to use for screenshot generation.");
    GFXRECON_WRITE_CONSOLE("          \t\tAvailable formats are:");
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\t\tBitmap file format.  This is the default format.",
                           gfxrecon::util::kScreenshotFormatBmp);
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\t\tPortable Network Graphics file format.",
                           gfxrecon::util::kScreenshotFormatPng);
    GFXRECON_WRITE_CONSOLE("  --screenshot-dir <dir>");
    GFXRECON_WRITE_CONSOLE("          \t\tDirectory to write screenshots.  Default is the current");
    GFXRECON_WRITE_CONSOLE("          \t\tworking directory.");
    GFXRECON_WRITE_CONSOLE("  --screenshot-prefix <file-prefix>");
    GFXRECON_WRITE_CONSOLE("          \t\tPrefix to apply to the screenshot file name.  Default is ");
    GFXRECON_WRITE_CONSOLE("          \t\t\"screenshot\", producing file names similar to");
    GFXRECON_WRITE_CONSOLE("          \t\t\"screenshot_frame_8049.bmp\".");
    GFXRECON_WRITE_CONSOLE("  --screenshot-scale <factor>[,<factor_y>]");
    GFXRECON_WRITE_CONSOLE("          \t\tSpecify one or two float scale factors to resize screenshot output.");
    GFXRECON_WRITE_CONSOLE("          \t\tUse --screenshot-scale <factor_x>,<factor_y> for non-uniform scaling.");
    GFXRECON_WRITE_CONSOLE("          \t\tA negative scale factor flips the output on that axis.");
    GFXRECON_WRITE_CONSOLE("          \t\te.g. --screenshot-scale 0.5, --screenshot-scale 1.0,-1.0 (flip Y).");
    GFXRECON_WRITE_CONSOLE("          \t\tDefault: 1.0 (original size).");
    GFXRECON_WRITE_CONSOLE("  --screenshot-size <width>x<height>");
    GFXRECON_WRITE_CONSOLE("          \t\tSpecify desired screenshot dimensions. Leaving this unspecified");
    GFXRECON_WRITE_CONSOLE("          \t\tscreenshots will use the swapchain images dimensions. If ");
    GFXRECON_WRITE_CONSOLE("          \t\t--screenshot-scale is also specified then this option is ignored.");
    GFXRECON_WRITE_CONSOLE("  --validate\t\tEnable the Khronos Vulkan validation layer when replaying a");
    GFXRECON_WRITE_CONSOLE("            \t\tVulkan capture or the Direct3D debug layer when replaying a");
    GFXRECON_WRITE_CONSOLE("            \t\tDirect3D 12 capture.");
    GFXRECON_WRITE_CONSOLE("  --cpu-mask <binary-mask>");
    GFXRECON_WRITE_CONSOLE("          \t\tSet of CPU cores used by the replayer.");
    GFXRECON_WRITE_CONSOLE("          \t\t`binary-mask` is a succession of '0' and '1' read from left to right");
    GFXRECON_WRITE_CONSOLE("          \t\tthat specifies used/unused cores.");
    GFXRECON_WRITE_CONSOLE("          \t\tFor example '10010' activates the first and");
    GFXRECON_WRITE_CONSOLE("          \t\tfourth cores and deactivate all other cores.");
    GFXRECON_WRITE_CONSOLE("          \t\tIf the option is not set, all cores can be used. If the option");
    GFXRECON_WRITE_CONSOLE("          \t\tis set only for some cores, the other cores are not used.");
    GFXRECON_WRITE_CONSOLE("  --gpu <index>\t\tUse the specified device for replay, where index");
    GFXRECON_WRITE_CONSOLE("          \t\tis the zero-based index to the array of physical devices");
    GFXRECON_WRITE_CONSOLE("          \t\treturned by vkEnumeratePhysicalDevices or IDXGIFactory1::EnumAdapters1.");
    GFXRECON_WRITE_CONSOLE("          \t\tReplay may fail if the specified device is not compatible with the");
    GFXRECON_WRITE_CONSOLE("          \t\toriginal capture devices.");
    GFXRECON_WRITE_CONSOLE("  --pbi-all\t\tPrint all block information.");
    GFXRECON_WRITE_CONSOLE(
        "  --pbis <index1,index2>\t\tPrint block information between block index1 and block index2.");
#if defined(_WIN32)
    GFXRECON_WRITE_CONSOLE("")
    GFXRECON_WRITE_CONSOLE("Windows only:")
    GFXRECON_WRITE_CONSOLE("  --dump-resources <submit-index,command-index,drawcall-index>");
    GFXRECON_WRITE_CONSOLE("          \t\tDump resources for a specific drawcall.");
    GFXRECON_WRITE_CONSOLE(
        "          \t\tThis can include vertex, index, const buffer, shader resource, render target,");
    GFXRECON_WRITE_CONSOLE("          \t\tand depth stencil resources. Resources are dumped after the drawcall.");
    GFXRECON_WRITE_CONSOLE(
        "  --fwo <x,y>\t\tForce windowed mode if not already, and allow setting of a custom window location.");
    GFXRECON_WRITE_CONSOLE("          \t\t(Same as --force-windowed-origin)");
    GFXRECON_WRITE_CONSOLE("  --debug-device-lost\tEnable automatic injection of breadcrumbs into command buffers");
    GFXRECON_WRITE_CONSOLE("            \t\tand page fault reporting.");
    GFXRECON_WRITE_CONSOLE("            \t\tUsed to debug Direct3D 12 device removed problems.");
    GFXRECON_WRITE_CONSOLE("  --fw <width,height>\tSetup windowed and override resolution.");
    GFXRECON_WRITE_CONSOLE("                     \t(Same as --force-windowed)");
    GFXRECON_WRITE_CONSOLE("  --create-dummy-allocations");
    GFXRECON_WRITE_CONSOLE("          \t\tEnable creation of dummy heaps and resources for replay validation.");
#if defined(_DEBUG)
    GFXRECON_WRITE_CONSOLE("  --no-debug-popup\tDisable the 'Abort, Retry, Ignore' message box");
    GFXRECON_WRITE_CONSOLE("       \t\t\tdisplayed when abort() is called (Windows debug only).");
#endif
#endif
    GFXRECON_WRITE_CONSOLE("  --wsi <platform>\tForce replay to use the specified wsi platform. If no surface");
    GFXRECON_WRITE_CONSOLE("                  \twas available at capture time the option is ignored and no");
    GFXRECON_WRITE_CONSOLE("                  \tsurface is chosen.");
    GFXRECON_WRITE_CONSOLE("                  \tAvailable platforms are: %s", GetWsiArgString().c_str());
    GFXRECON_WRITE_CONSOLE("                  \tauto (default): Picks the same surface as at capture time if");
    GFXRECON_WRITE_CONSOLE("                  \t                possible, otherwise picks a surface available");
    GFXRECON_WRITE_CONSOLE("                  \t                on the replay device");
    GFXRECON_WRITE_CONSOLE("  --sync\t\tSynchronize after each queue submission with vkQueueWaitIdle.");
    GFXRECON_WRITE_CONSOLE("  --remove-unsupported\tRemove unsupported extensions and features from instance");
    GFXRECON_WRITE_CONSOLE("                      \tand device creation parameters.");
    GFXRECON_WRITE_CONSOLE("  --measurement-frame-range <start_frame>-<end_frame>");
    GFXRECON_WRITE_CONSOLE("          \t\tCustom framerange to measure FPS for.");
    GFXRECON_WRITE_CONSOLE("          \t\tThis range will include the start frame but not the end frame.");
    GFXRECON_WRITE_CONSOLE("          \t\tThe measurement frame range defaults to all frames except the loading");
    GFXRECON_WRITE_CONSOLE("          \t\tframe but can be configured for any range. If the end frame is past the");
    GFXRECON_WRITE_CONSOLE("          \t\tlast frame in the trace it will be clamped to the frame after the last");
    GFXRECON_WRITE_CONSOLE("          \t\t(so in that case the results would include the last frame).");
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
#if !defined(_WIN32)
    GFXRECON_WRITE_CONSOLE("  --dump-resources <filename>.json");
    GFXRECON_WRITE_CONSOLE("          \t\tExtract dump resources block indices and options from the");
    GFXRECON_WRITE_CONSOLE("          \t\tspecified json file. The format for the json file is");
    GFXRECON_WRITE_CONSOLE("          \t\tdocumented in detail in vulkan_dump_resources.md.");
#else
    GFXRECON_WRITE_CONSOLE("  --dump-resources-image-format <format>");
    GFXRECON_WRITE_CONSOLE("          \t\tImage file format to use when dumping image resources.");
    GFXRECON_WRITE_CONSOLE("          \t\tAvailable formats are: bmp, png");
    GFXRECON_WRITE_CONSOLE("  --dump-resources-modifiable-state-only");
    GFXRECON_WRITE_CONSOLE("          \t\tDump only the resources that a D3D12 ResourceBarrier put into a");
    GFXRECON_WRITE_CONSOLE("          \t\tmodifiable state.");
#endif
    GFXRECON_WRITE_CONSOLE("  --pipeline-creation-jobs <num_jobs>");
    GFXRECON_WRITE_CONSOLE("          \t\tSpecify the number of asynchronous pipeline-creation jobs as integer.");
    GFXRECON_WRITE_CONSOLE("          \t\tIf <num_jobs> is negative it will be added to the number of cpu-cores");
    GFXRECON_WRITE_CONSOLE("          \t\tDefault: 0 (do not use asynchronous operations).");
    GFXRECON_WRITE_CONSOLE("          \t\tSame as --pcj <num_jobs>");
    GFXRECON_WRITE_CONSOLE("  --wait-before-first-submit <milliseconds>");
    GFXRECON_WRITE_CONSOLE("          \t\tWait specified milliseconds before submitting the first command buffer.");
    GFXRECON_WRITE_CONSOLE("  --frame-warm-up-spirv <spirv-file>");
    GFXRECON_WRITE_CONSOLE("          \t\tSpecify a user-provided SPIR-V compute shader for the warm-up pass.");
    GFXRECON_WRITE_CONSOLE("          \t\tThe shader must use entry point `main` and set 0, binding 0 as a");
    GFXRECON_WRITE_CONSOLE("          \t\tstorage buffer. Warm-up runs before the first submit of each replayed");
    GFXRECON_WRITE_CONSOLE("          \t\tframe only when this option and a non-zero `--frame-warm-up-load`");
    GFXRECON_WRITE_CONSOLE("          \t\tare both provided.");
    GFXRECON_WRITE_CONSOLE("  --frame-warm-up-load <load>");
    GFXRECON_WRITE_CONSOLE("          \t\tSpecify workload scale factor for a compute dispatch warm-up pass");
    GFXRECON_WRITE_CONSOLE("          \t\trun before each frame replay. Default is 0 (disabled).");
    GFXRECON_WRITE_CONSOLE("  --wait-before-frame <milliseconds>");
    GFXRECON_WRITE_CONSOLE("          \t\tWait for the specified amount of milliseconds before starting to replay");
    GFXRECON_WRITE_CONSOLE("          \t\teach frame. Default is 0 (no wait).");

    // The entries that belong to one Feature come last, in one section for each Feature.
    PrintFeatureUsage(gfxrecon::replay::GetLoadedFeatures());
}

#endif // GFXRECON_REPLAY_SETTINGS_H
