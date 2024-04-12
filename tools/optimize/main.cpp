/*
** Copyright (c) 2020 LunarG, Inc.
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
#include "file_optimizer.h"

#include "../tool_settings.h"

#if defined(D3D12_SUPPORT)
#include "dx12_optimize_util.h"
#endif

#include "decode/decode_api_detection.h"
#include "decode/dx12_optimize_options.h"
#include "decode/file_processor.h"
#include "format/format.h"
#include "format/format_util.h"
#include "generated/generated_vulkan_decoder.h"
#include "generated/generated_vulkan_referenced_resource_consumer.h"
#include "util/argument_parser.h"
#include "util/logging.h"
#include "util/date_time.h"

#include "vulkan/vulkan.h"

#include <cassert>
#include <stdexcept>
#include <string>
#include <unordered_set>
#include <vector>

#if defined(WIN32)
extern "C"
{
    __declspec(dllexport) extern const UINT D3D12SDKVersion = 610;
}
extern "C"
{
    __declspec(dllexport) extern const char* D3D12SDKPath = u8".\\D3D12\\";
}
#endif

const char kOptions[]   = "-h|--help,--version,--no-debug-popup,--d3d12-pso-removal,--dxr,--dxr-experimental";
const char kArguments[] = "--gpu";

const char kD3d12PsoRemoval[]             = "--d3d12-pso-removal";
const char kDx12OptimizeDxr[]             = "--dxr";
const char kDx12OptimizeDxrExperimental[] = "--dxr-experimental";

static void PrintUsage(const char* exe_name)
{
    std::string app_name     = exe_name;
    size_t      dir_location = app_name.find_last_of("/\\");
    if (dir_location >= 0)
    {
        app_name.replace(0, dir_location + 1, "");
    }
    GFXRECON_WRITE_CONSOLE("\n%s - Produce new captures with enhanced performance characteristics", app_name.c_str());

    GFXRECON_WRITE_CONSOLE("\t\t\tFor Vulkan, the optimizer will remove unused buffer and image initialization data "
                           "(for trimmed captures)");
    GFXRECON_WRITE_CONSOLE(
        "\t\t\tFor D3D12, the optimizer will improve DXR replay performance and remove unused PSOs (for all captures)");
    GFXRECON_WRITE_CONSOLE("");
    GFXRECON_WRITE_CONSOLE("Usage:");
    GFXRECON_WRITE_CONSOLE(
        "  %s [-h | --help] [--version] [--d3d12-pso-removal] [--dxr] [--gpu <index>] <input-file> <output-file>",
        app_name.c_str());
    GFXRECON_WRITE_CONSOLE("");
    GFXRECON_WRITE_CONSOLE("Required arguments:");
    GFXRECON_WRITE_CONSOLE("  <input-file>\t\tThe path to input GFXReconstruct capture file to be processed.");
    GFXRECON_WRITE_CONSOLE("  <output-file>\t\tThe path to output GFXReconstruct capture file to be created.");
    GFXRECON_WRITE_CONSOLE("");
    GFXRECON_WRITE_CONSOLE("Optional arguments:");
    GFXRECON_WRITE_CONSOLE("  -h\t\t\tPrint usage information and exit (same as --help).");
    GFXRECON_WRITE_CONSOLE("  --version\t\tPrint version information and exit.");
#if defined(WIN32)
#if defined(_DEBUG)
    GFXRECON_WRITE_CONSOLE("  --no-debug-popup\tDisable the 'Abort, Retry, Ignore' message box");
    GFXRECON_WRITE_CONSOLE("        \t\tdisplayed when abort() is called (Windows debug only).");
#endif
    GFXRECON_WRITE_CONSOLE("  --d3d12-pso-removal\tD3D12-only: Remove creation of unreferenced PSOs.");
    GFXRECON_WRITE_CONSOLE("  --dxr\t\t\tD3D12-only: Optimize for DXR and ExecuteIndirect replay.");
    GFXRECON_WRITE_CONSOLE("  --gpu <index>\t\tUse the specified device for the optimizer replay, where index");
    GFXRECON_WRITE_CONSOLE("          \t\tis the zero-based index to the array of physical devices");
    GFXRECON_WRITE_CONSOLE("          \t\treturned by vkEnumeratePhysicalDevices or IDXGIFactory1::EnumAdapters1.");
    GFXRECON_WRITE_CONSOLE(
        "          \t\tThe optimizer replay may fail if the specified device is not compatible with the");
    GFXRECON_WRITE_CONSOLE("          \t\toriginal capture devices.");
    GFXRECON_WRITE_CONSOLE("");
    GFXRECON_WRITE_CONSOLE("Note: running without optional arguments will instruct the optimizer to detect API and run "
                           "all available optimizations.");
#endif
}

void GetUnreferencedResources(const std::string&                              input_filename,
                              std::unordered_set<gfxrecon::format::HandleId>* unreferenced_ids)
{
    GFXRECON_ASSERT(unreferenced_ids != nullptr);

    gfxrecon::decode::FileProcessor file_processor;
    if (file_processor.Initialize(input_filename))
    {
        gfxrecon::decode::VulkanDecoder                    decoder;
        gfxrecon::decode::VulkanReferencedResourceConsumer resref_consumer;

        decoder.AddConsumer(&resref_consumer);

        file_processor.AddDecoder(&decoder);
        file_processor.ProcessAllFrames();

        if (resref_consumer.WasNotOptimizable())
        {
            GFXRECON_WRITE_CONSOLE("File did not contain trim state setup - no optimization was performed");
            gfxrecon::util::Log::Release();
            exit(65);
        }
        else if ((file_processor.GetCurrentFrameNumber() > 0) &&
                 (file_processor.GetErrorState() == gfxrecon::decode::FileProcessor::kErrorNone))
        {
            // Get the list of resources that were included in a command buffer submission during replay.
            resref_consumer.GetReferencedResourceIds(nullptr, unreferenced_ids);
        }
        else if (file_processor.GetErrorState() != gfxrecon::decode::FileProcessor::kErrorNone)
        {
            GFXRECON_WRITE_CONSOLE("A failure has occurred during file processing");
            gfxrecon::util::Log::Release();
            exit(-1);
        }
        else
        {
            GFXRECON_WRITE_CONSOLE("File did not contain any frames");
            gfxrecon::util::Log::Release();
            exit(0);
        }
    }
}

void FilterUnreferencedResources(const std::string&                               input_filename,
                                 const std::string&                               output_filename,
                                 std::unordered_set<gfxrecon::format::HandleId>&& unreferenced_ids)
{
    gfxrecon::FileOptimizer file_processor(std::move(unreferenced_ids));
    if (file_processor.Initialize(input_filename, output_filename))
    {
        file_processor.Process();

        if (file_processor.GetErrorState() != gfxrecon::FileOptimizer::kErrorNone)
        {
            GFXRECON_WRITE_CONSOLE("A failure has occurred during file processing");
            gfxrecon::util::Log::Release();
            exit(-1);
        }

        GFXRECON_WRITE_CONSOLE("Resource filtering complete.");
        GFXRECON_WRITE_CONSOLE("\tOriginal file size: %" PRIu64 " bytes", file_processor.GetNumBytesRead());
        GFXRECON_WRITE_CONSOLE("\tOptimized file size: %" PRIu64 " bytes", file_processor.GetNumBytesWritten());
    }
}

void VkRemoveRedundantResources(std::string input_filename, std::string output_filename)
{
    GFXRECON_WRITE_CONSOLE("Scanning Vulkan file %s for unreferenced resources.", input_filename.c_str());
    std::unordered_set<gfxrecon::format::HandleId> unreferenced_ids;
    GetUnreferencedResources(input_filename, &unreferenced_ids);

    if (!unreferenced_ids.empty())
    {
        // Filter unreferenced ids.
        GFXRECON_WRITE_CONSOLE("Writing optimized file, removing initialization data for %" PRIu64 " unused resources.",
                               unreferenced_ids.size());
        FilterUnreferencedResources(input_filename, output_filename, std::move(unreferenced_ids));
    }
    else
    {
        GFXRECON_WRITE_CONSOLE("No unused resources detected.  A new file will not be created.",
                               input_filename.c_str());
    }
}

void RunDx12Optimizations(const std::string&                        input_filename,
                          const std::string&                        output_filename,
                          gfxrecon::decode::Dx12OptimizationOptions dx12_options)
{
#if defined(D3D12_SUPPORT)
    bool result = gfxrecon::Dx12OptimizeFile(input_filename, output_filename, dx12_options);
    if (!result)
    {
        gfxrecon::util::Log::Release();
        exit(-1);
    }
#endif
}

int main(int argc, const char** argv)
{
    int64_t start_time = gfxrecon::util::datetime::GetTimestamp();

    gfxrecon::util::Log::Init();

    gfxrecon::util::ArgumentParser arg_parser(argc, argv, kOptions, kArguments);

    if (CheckOptionPrintUsage(argv[0], arg_parser) || CheckOptionPrintVersion(argv[0], arg_parser))
    {
        gfxrecon::util::Log::Release();
        exit(0);
    }
    else if (arg_parser.IsInvalid() || (arg_parser.GetPositionalArgumentsCount() != 2))
    {
        PrintUsage(argv[0]);
        gfxrecon::util::Log::Release();
        exit(-1);
    }
    else
    {
#if defined(WIN32) && defined(_DEBUG)
        if (arg_parser.IsOptionSet(kNoDebugPopup))
        {
            _set_abort_behavior(0, _WRITE_ABORT_MSG | _CALL_REPORTFAULT);
        }
#endif
    }

    try
    {
        std::string                     input_filename;
        std::string                     output_filename;
        const std::vector<std::string>& positional_arguments = arg_parser.GetPositionalArguments();
        input_filename                                       = positional_arguments[0];
        output_filename                                      = positional_arguments[1];

        // Parameter checking and API detection
        gfxrecon::decode::Dx12OptimizationOptions dx12_options;
        dx12_options.optimize_resource_values              = arg_parser.IsOptionSet(kDx12OptimizeDxr);
        dx12_options.optimize_resource_values_experimental = arg_parser.IsOptionSet(kDx12OptimizeDxrExperimental);
        dx12_options.remove_redundant_psos                 = arg_parser.IsOptionSet(kD3d12PsoRemoval);
        const auto& override_gpu                           = arg_parser.GetArgumentValue(kOverrideGpuArgument);
        if (!override_gpu.empty())
        {
            dx12_options.override_gpu_index = std::stoi(override_gpu);
        }

        if (dx12_options.optimize_resource_values_experimental)
        {
            GFXRECON_WRITE_CONSOLE("Running experimental DXR optimization. This mode is experimental, and should only "
                                   "be used if --dxr did not produce a valid capture file.");
            dx12_options.optimize_resource_values = true;
        }

        // Automatic mode. User specified no options.
        if ((dx12_options.optimize_resource_values == false) && (dx12_options.remove_redundant_psos == false))
        {
            bool detected_d3d12  = false;
            bool detected_vulkan = false;
            bool detected_openxr = false;
            gfxrecon::decode::DetectAPIs(input_filename, detected_d3d12, detected_vulkan, detected_openxr);

            if ((!detected_d3d12) && (!detected_vulkan))
            {
                // Detect with no block limit
                gfxrecon::decode::DetectAPIs(input_filename, detected_d3d12, detected_vulkan, detected_openxr, true);
            }

            if (detected_d3d12)
            {
                dx12_options.optimize_resource_values = true;
                dx12_options.remove_redundant_psos    = true;
                RunDx12Optimizations(input_filename, output_filename, dx12_options);
            }
            else if (detected_vulkan)
            {
                VkRemoveRedundantResources(input_filename, output_filename);
            }
            else
            {
                GFXRECON_LOG_ERROR("Could not detect graphics API. Aborting optimization.")
            }
        }
        // Manual mode. Follow user instructions.
        else
        {
            RunDx12Optimizations(input_filename, output_filename, dx12_options);
        }
    }
    catch (const std::runtime_error& error)
    {
        GFXRECON_WRITE_CONSOLE("File processing has encountered a fatal error and cannot continue: %s", error.what());
        gfxrecon::util::Log::Release();
        return -1;
    }
    catch (...)
    {
        GFXRECON_WRITE_CONSOLE("File processing failed due to an unhandled exception");
        gfxrecon::util::Log::Release();
        return -1;
    }

    int64_t end_time        = gfxrecon::util::datetime::GetTimestamp();
    int     time_in_seconds = static_cast<int>(gfxrecon::util::datetime::ConvertTimestampToSeconds(
        gfxrecon::util::datetime::DiffTimestamps(start_time, end_time)));
    GFXRECON_WRITE_CONSOLE("File processing time: %d seconds", time_in_seconds);

    gfxrecon::util::Log::Release();
    return 0;
}
