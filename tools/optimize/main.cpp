/*
** Copyright (c) 2020 LunarG, Inc.
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
#include "file_optimizer.h"

#include "decode/file_processor.h"
#include "format/format.h"
#include "format/format_util.h"
#include "generated/generated_vulkan_decoder.h"
#include "generated/generated_vulkan_referenced_resource_consumer.h"
#include "util/argument_parser.h"
#include "util/logging.h"

#include "vulkan/vulkan.h"

#include <cassert>
#include <stdexcept>
#include <string>
#include <unordered_set>
#include <vector>

const char kHelpShortOption[] = "-h";
const char kHelpLongOption[]  = "--help";
const char kVersionOption[]   = "--version";
const char kNoDebugPopup[]    = "--no-debug-popup";

const char kOptions[] = "-h|--help,--version,--no-debug-popup";

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
#if defined(WIN32) && defined(_DEBUG)
    GFXRECON_WRITE_CONSOLE("  --no-debug-popup\tDisable the 'Abort, Retry, Ignore' message box");
    GFXRECON_WRITE_CONSOLE("        \t\tdisplayed when abort() is called (Windows debug only).");
#endif
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

static std::string GetVersionString(uint32_t api_version)
{
    uint32_t major = api_version >> 22;
    uint32_t minor = (api_version >> 12) & 0x3ff;
    uint32_t patch = api_version & 0xfff;

    return std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(patch);
}

void GetUnreferencedResources(const std::string&                              input_filename,
                              std::unordered_set<gfxrecon::format::HandleId>* unreferenced_ids)
{
    assert(unreferenced_ids != nullptr);

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

int main(int argc, const char** argv)
{
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
        const std::vector<std::string>& positional_arguments = arg_parser.GetPositionalArguments();
        std::string                     input_filename       = positional_arguments[0];
        std::string                     output_filename      = positional_arguments[1];

        GFXRECON_WRITE_CONSOLE("Scanning %s for unreferenced resources.", input_filename.c_str());
        std::unordered_set<gfxrecon::format::HandleId> unreferenced_ids;
        GetUnreferencedResources(input_filename, &unreferenced_ids);

        if (!unreferenced_ids.empty())
        {
            // Filter unreferenced ids.
            GFXRECON_WRITE_CONSOLE("Writing optimized file, removing initialization data for %" PRIu64
                                   " unused resources.",
                                   unreferenced_ids.size());
            FilterUnreferencedResources(input_filename, output_filename, std::move(unreferenced_ids));
        }
        else
        {
            GFXRECON_WRITE_CONSOLE("No unused resources detected.  A new file will not be created.",
                                   input_filename.c_str());
        }
    }
    catch (std::runtime_error error)
    {
        GFXRECON_WRITE_CONSOLE("File processing has encountered a fatal error and cannot continue: %s", error.what());
        return -1;
    }
    catch (...)
    {
        GFXRECON_WRITE_CONSOLE("File processing failed due to an unhandled exception");
        return -1;
    }

    gfxrecon::util::Log::Release();
    return 0;
}
