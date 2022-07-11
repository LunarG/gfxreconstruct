/*
** Copyright (c) 2020 LunarG, Inc.
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
#include "file_optimizer.h"

#include "../tool_settings.h"

#if defined(WIN32)
#include "dx12_optimize_util.h"
#endif

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

const char kOptions[] = "-h|--help,--version,--no-debug-popup,--d3d12-pso-removal";

const char kD3d12PsoRemoval[] = "--d3d12-pso-removal";

static void PrintUsage(const char* exe_name)
{
    std::string app_name     = exe_name;
    size_t      dir_location = app_name.find_last_of("/\\");
    if (dir_location >= 0)
    {
        app_name.replace(0, dir_location + 1, "");
    }
    GFXRECON_WRITE_CONSOLE(
        "\n%s - Remove unused resource initialization data from trimmed GFXReconstruct capture files.\n",
        app_name.c_str());
    GFXRECON_WRITE_CONSOLE("Usage:");
    GFXRECON_WRITE_CONSOLE("  %s [-h | --help] [--version] <input-file> <output-file>\n", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("Required arguments:");
    GFXRECON_WRITE_CONSOLE("  <input-file>\t\tThe trimmed GFXReconstruct capture file to be processed.");
    GFXRECON_WRITE_CONSOLE("  <output-file>\t\tThe name of the new GFXReconstruct capture file to be created.");
    GFXRECON_WRITE_CONSOLE("\nOptional arguments:");
    GFXRECON_WRITE_CONSOLE("  -h\t\t\tPrint usage information and exit (same as --help).");
    GFXRECON_WRITE_CONSOLE("  --version\t\tPrint version information and exit.");
#if defined(WIN32)
#if defined(_DEBUG)
    GFXRECON_WRITE_CONSOLE("  --no-debug-popup\tDisable the 'Abort, Retry, Ignore' message box");
    GFXRECON_WRITE_CONSOLE("        \t\tdisplayed when abort() is called (Windows debug only).");
#endif
    GFXRECON_WRITE_CONSOLE(
        "  --d3d12-pso-removal\tRemove unused d3d12 pso's. Without it, the trace will be treated as Vulkan.");
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

        if ((file_processor.GetCurrentFrameNumber() > 0) &&
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

int main(int argc, const char** argv)
{
    int64_t start_time = gfxrecon::util::datetime::GetTimestamp();

    gfxrecon::util::Log::Init();

    gfxrecon::util::ArgumentParser arg_parser(argc, argv, kOptions, "");

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

#if defined(WIN32)
        // We can check other d3d12 options in the future here. For now we check only --d3d12-pso-removal.
        bool d3d12_remove_psos = arg_parser.IsOptionSet(kD3d12PsoRemoval);
        if (d3d12_remove_psos)
        {
            bool result = D3D12RemoveRedundantPSOs(input_filename, output_filename);
            if (!result)
            {
                gfxrecon::util::Log::Release();
                return -1;
            }
        }
        else
#endif
        {
            VkRemoveRedundantResources(input_filename, output_filename);
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
