/*
** Copyright (c) 2020-2026 LunarG, Inc.
** Copyright (c) 2022-2023 Advanced Micro Devices, Inc. All rights reserved.
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

#include PROJECT_VERSION_HEADER_FILE

#include "optimize_feature.h"
#include "tool_settings.h"
#include "tool_feature_version.h"

#include "decode/decode_api_detection.h"
#include "decode/file_processor.h"
#include "util/argument_parser.h"
#include "util/d3d12_agility_sdk_version.h"
#include "util/date_time.h"
#include "util/feature_module_registry.h"
#include "util/logging.h"

#include <algorithm>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

#if defined(_WIN32)
extern "C"
{
    __declspec(dllexport) extern const UINT D3D12SDKVersion = gfxrecon::util::kD3D12AgilitySdkVersion;
}
extern "C"
{
    __declspec(dllexport) extern const char* D3D12SDKPath = reinterpret_cast<const char*>(u8".\\D3D12\\");
}
#endif

// Module-level features vector so PrintUsage() can access it.
// tool_settings.h forward-declares PrintUsage(const char*); the signature is fixed.
static std::vector<std::unique_ptr<gfxrecon::optimize::OptimizeFeature>> g_optimize_features;

static void PrintUsage(const char* exe_name)
{
    std::string app_name = GetApplicationName(exe_name);

    // Build synopsis from feature fragments so it stays in sync automatically.
    std::string synopsis = app_name + " [-h | --help] [--version]";
    for (const auto& feature : g_optimize_features)
    {
        const std::string fragment = feature->GetSynopsisFragment();
        if (!fragment.empty())
        {
            synopsis += " " + fragment;
        }
    }
    synopsis += " <input-file> <output-file>";

    GFXRECON_WRITE_CONSOLE("\n%s - Produce new captures with enhanced performance characteristics", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("\t\t\tFor Vulkan, the optimizer will remove unused buffer and image initialization data "
                           "(for trimmed captures)");
    GFXRECON_WRITE_CONSOLE(
        "\t\t\tFor D3D12, the optimizer will improve DXR replay performance and remove unused PSOs (for all captures)");
    GFXRECON_WRITE_CONSOLE("");
    GFXRECON_WRITE_CONSOLE("Usage:");
    GFXRECON_WRITE_CONSOLE("  %s", synopsis.c_str());
    GFXRECON_WRITE_CONSOLE("");
    GFXRECON_WRITE_CONSOLE("Required arguments:");
    GFXRECON_WRITE_CONSOLE("  <input-file>\t\tThe path to input GFXReconstruct capture file to be processed.");
    GFXRECON_WRITE_CONSOLE("  <output-file>\t\tThe path to output GFXReconstruct capture file to be created.");
    GFXRECON_WRITE_CONSOLE("");
    GFXRECON_WRITE_CONSOLE("Optional arguments:");
    GFXRECON_WRITE_CONSOLE("  -h\t\t\t\tPrint usage information and exit (same as --help).");
    GFXRECON_WRITE_CONSOLE("  --version\t\t\tPrint version information and exit.");

#if defined(_WIN32) && defined(_DEBUG)
    GFXRECON_WRITE_CONSOLE("  --no-debug-popup\t\tDisable the 'Abort, Retry, Ignore' message box");
    GFXRECON_WRITE_CONSOLE("        \t\t\tdisplayed when abort() is called (Windows debug only).");
#endif

    for (const auto& feature : g_optimize_features)
    {
        feature->PrintUsage();
    }
    GFXRECON_WRITE_CONSOLE("");
    GFXRECON_WRITE_CONSOLE("Note: running without optional arguments will instruct the optimizer to detect the API "
                           "and run all available optimizations.");
}

int32_t main(int32_t argc, const char** argv)
{
    bool    success    = false;
    int64_t start_time = gfxrecon::util::datetime::GetTimestamp();
    int64_t end_time{ 0 };
    int32_t time_in_seconds{ 0 };
    struct LogGuard
    {
        LogGuard()
        {
            gfxrecon::util::Log::Init();
            gfxrecon::util::Log::SetFatalCallback([](const char* message) { throw std::runtime_error(message); });
        }
        ~LogGuard() { gfxrecon::util::Log::Release(); }
    } log_guard;

    // Build features first; they must exist before we construct the ArgumentParser
    // (to contribute their options/arguments) and before PrintUsage() is called.
    for (const auto& creator :
         gfxrecon::util::FeatureModuleRegistry<gfxrecon::optimize::OptimizeFeature>::GetSingleton()
             .GetRegisteredFeatureCreators())
    {
        g_optimize_features.push_back(creator());
    }

    // Aggregate option flags and argument keys from all features plus common flags.
    std::string options   = "-h|--help,--version";
    std::string arguments = "";

#if defined(WIN32) && defined(_DEBUG)
    options += ",--no-debug-popup";
#endif

    for (const auto& feature : g_optimize_features)
    {
        const std::string feature_opts = feature->GetOptions();
        if (!feature_opts.empty())
        {
            options += "," + feature_opts;
        }
        const std::string feature_args = feature->GetArguments();
        if (!feature_args.empty())
        {
            if (!arguments.empty())
            {
                arguments += ",";
            }
            arguments += feature_args;
        }
    }

    gfxrecon::util::ArgumentParser arg_parser(argc, argv, options, arguments);

    if (CheckOptionPrintUsage(argv[0], arg_parser) ||
        CheckOptionPrintFeatureVersions<gfxrecon::optimize::OptimizeFeature>(argv[0], arg_parser))
    {
        return EXIT_SUCCESS;
    }
    else if (arg_parser.IsInvalid() || (arg_parser.GetPositionalArgumentsCount() != 2))
    {
        PrintUsage(argv[0]);
        return EXIT_FAILURE;
    }
    else
    {
#if defined(_WIN32) && defined(_DEBUG)
        if (arg_parser.IsOptionSet(kNoDebugPopup))
        {
            _set_abort_behavior(0, _WRITE_ABORT_MSG | _CALL_REPORTFAULT);
        }
#endif
    }

    try
    {
        const std::vector<std::string>& positional_arguments = arg_parser.GetPositionalArguments();
        const std::string&              input_filename       = positional_arguments[0];
        const std::string&              output_filename      = positional_arguments[1];

        // Two-phase detection: quick limited scan first, full scan only if needed.
        // This mirrors the original DetectAPIs behavior and avoids reading the whole
        // file when the API headers appear in the first kDefaultDetectionBlockLimit blocks.
        auto run_detection_pass = [&](uint64_t block_limit) {
            gfxrecon::decode::FileProcessor detection_processor;
            if (detection_processor.Initialize(input_filename))
            {
                for (auto& feature : g_optimize_features)
                {
                    feature->RegisterDetectionDecoder(detection_processor, block_limit);
                }
                detection_processor.ProcessAllFrames();
            }
        };

        using Feature = gfxrecon::optimize::OptimizeFeature;
        run_detection_pass(Feature::kDefaultDetectionBlockLimit);

        bool did_any_run = std::any_of(g_optimize_features.begin(), g_optimize_features.end(), [&](const auto& f) {
            return f->ShouldRun(arg_parser);
        });
        if (!did_any_run)
        {
            run_detection_pass(Feature::kNoDetectionBlockLimit);
        }

        // Run every feature that should execute given the current arguments and detection results.
        bool any_ran = false;
        for (auto& feature : g_optimize_features)
        {
            if (feature->ShouldRun(arg_parser))
            {
                if (feature->Optimize(input_filename, output_filename, arg_parser))
                {
                    any_ran = true;
                }
            }
        }

        if (!any_ran)
        {
            GFXRECON_LOG_ERROR("Could not detect graphics API. Aborting optimization.");
        }
        else
        {
            success = true;
        }
    }
    catch (const std::runtime_error& error)
    {
        GFXRECON_WRITE_CONSOLE("File processing has encountered a fatal error and cannot continue: %s", error.what());
        return EXIT_FAILURE;
    }
    catch (...)
    {
        GFXRECON_WRITE_CONSOLE("File processing failed due to an unhandled exception");
        return EXIT_FAILURE;
    }

    end_time        = gfxrecon::util::datetime::GetTimestamp();
    time_in_seconds = static_cast<int32_t>(gfxrecon::util::datetime::ConvertTimestampToSeconds(
        gfxrecon::util::datetime::DiffTimestamps(start_time, end_time)));
    GFXRECON_WRITE_CONSOLE("File processing time: %d seconds", time_in_seconds);

    return success ? EXIT_SUCCESS : EXIT_FAILURE;
}
