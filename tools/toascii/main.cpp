/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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

#include "format/format.h"
#include "generated/generated_vulkan_ascii_consumer.h"

#if defined(WIN32)
#include "generated/generated_dx12_ascii_consumer.h"
#endif

const char kOptions[] = "-h|--help,--version,--no-debug-popup";

const char kArguments[] = ""
#if defined(WIN32)
                          "--api"
#endif
    ;

static void PrintUsage(const char* exe_name)
{
    std::string app_name     = exe_name;
    size_t      dir_location = app_name.find_last_of("/\\");
    if (dir_location >= 0)
    {
        app_name.replace(0, dir_location + 1, "");
    }
    GFXRECON_WRITE_CONSOLE("\n%s - A tool to convert GFXReconstruct capture files to text.\n", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("Usage:");
    GFXRECON_WRITE_CONSOLE("  %s [-h | --help] [--version]", app_name.c_str());
#if defined(WIN32) && defined(_DEBUG)
    GFXRECON_WRITE_CONSOLE("\t\t\t[--api <api>] [--no-debug-popup] <file>\n");
#elif defined(WIN32)
    GFXRECON_WRITE_CONSOLE("\t\t\t[--api <api>] <file>\n");
#else
    GFXRECON_WRITE_CONSOLE("\t\t\t<file>\n");
#endif
    GFXRECON_WRITE_CONSOLE("Required arguments:");
    GFXRECON_WRITE_CONSOLE("  <file>\t\tPath to the GFXReconstruct capture file to be converted");
    GFXRECON_WRITE_CONSOLE("        \t\tto text.");
    GFXRECON_WRITE_CONSOLE("\nOptional arguments:");
    GFXRECON_WRITE_CONSOLE("  -h\t\t\tPrint usage information and exit (same as --help).");
    GFXRECON_WRITE_CONSOLE("  --version\t\tPrint version information and exit.");
#if defined(WIN32)
    GFXRECON_WRITE_CONSOLE("  --api <api>\t\tUse the specified API for replay (Windows only).");
    GFXRECON_WRITE_CONSOLE("          \t\tAvailable values are:");
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\tReplay with the Vulkan API enabled.", kApiFamilyVulkan);
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\tReplay with the Direct3D API enabled.", kApiFamilyD3D12);
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\t\tReplay with both the Vulkan and Direct3D 12 APIs", kApiFamilyAll);
    GFXRECON_WRITE_CONSOLE("          \t\t         \tenabled. This is the default.");
#if defined(_DEBUG)
    GFXRECON_WRITE_CONSOLE("  --no-debug-popup\tDisable the 'Abort, Retry, Ignore' message box");
    GFXRECON_WRITE_CONSOLE("        \t\tdisplayed when abort() is called (Windows debug only).");
#endif
#endif
}

int main(int argc, const char** argv)
{
    gfxrecon::util::Log::Init();

    gfxrecon::util::ArgumentParser arg_parser(argc, argv, kOptions, kArguments);

    if (CheckOptionPrintUsage(argv[0], arg_parser) || CheckOptionPrintVersion(argv[0], arg_parser))
    {
        gfxrecon::util::Log::Release();
        exit(0);
    }
    else if (arg_parser.IsInvalid() || (arg_parser.GetPositionalArgumentsCount() != 1))
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

    const std::vector<std::string>& positional_arguments = arg_parser.GetPositionalArguments();
    std::string                     input_filename       = positional_arguments[0];
    std::string                     output_filename      = input_filename;
    size_t                          suffix_pos           = output_filename.find(GFXRECON_FILE_EXTENSION);
    if (suffix_pos != std::string::npos)
    {
        output_filename = output_filename.substr(0, suffix_pos);
    }

    output_filename += ".txt";

    gfxrecon::decode::FileProcessor file_processor;
    if (file_processor.Initialize(input_filename))
    {
        FILE*   file;
        int32_t result = gfxrecon::util::platform::FileOpen(&file, output_filename.c_str(), "w");
        if (result == 0)
        {
            // Initialize Vulkan API decoder and consumer(s).
            gfxrecon::decode::VulkanTrackedObjectInfoTable tracked_object_info_table;
            gfxrecon::decode::VulkanReplayOptions          vulkan_replay_options =
                GetVulkanReplayOptions(arg_parser, input_filename, &tracked_object_info_table);
            gfxrecon::decode::VulkanDecoder       decoder;
            gfxrecon::decode::VulkanAsciiConsumer ascii_consumer;

            if (vulkan_replay_options.enable_vulkan)
            {
                ascii_consumer.Initialize(output_filename, file);
                decoder.AddConsumer(&ascii_consumer);

                file_processor.AddDecoder(&decoder);
            }

#if defined(WIN32)
            // Initialize D3D12 API decoder and consumer(s).
            gfxrecon::decode::DxReplayOptions   dx_replay_options = GetDxReplayOptions(arg_parser);
            gfxrecon::decode::Dx12Decoder       dx12_decoder;
            gfxrecon::decode::Dx12AsciiConsumer dx12_ascii_consumer;

            if (dx_replay_options.enable_d3d12)
            {
                dx12_ascii_consumer.Initialize(output_filename, file);
                dx12_decoder.AddConsumer(&dx12_ascii_consumer);

                file_processor.AddDecoder(&dx12_decoder);
            }
#endif
            file_processor.ProcessAllFrames();
            gfxrecon::util::platform::FileClose(file);
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to open output file: %s, error code: %d", output_filename.c_str(), result);
        }
    }

    gfxrecon::util::Log::Release();
    return 0;
}
