/*
** Copyright (c) 2020-2024 LunarG, Inc.
** Copyright (c) 2022-2024 Advanced Micro Devices, Inc. All rights reserved.
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

#include "decode/file_processor.h"

#include "decode/info_decoder.h"
#include "decode/info_consumer.h"

#include "util/argument_parser.h"
#include "util/strings.h"
#include "util/logging.h"
#include "util/to_string.h"
#include "util/platform.h"

#include <string>

#include <nlohmann/json.hpp>

const char                  kHelpShortOption[] = "-h";
const char                  kHelpLongOption[]  = "--help";
const char                  kVersionOption[]   = "--version";
[[maybe_unused]] const char kNoDebugPopup[]    = "--no-debug-popup";

const char kOptions[] = "-h|--help,--version,--no-debug-popup";

[[maybe_unused]] const char kUnrecognizedFormatString[] = "<unrecognized-format>";

static void PrintUsage(const char* exe_name)
{
    std::string app_name     = exe_name;
    size_t      dir_location = app_name.find_last_of("/\\");
    if (dir_location != std::string::npos)
    {
        app_name.replace(0, dir_location + 1, "");
    }
    GFXRECON_WRITE_CONSOLE("\n%s - Patch the file format version of a GFXReconstruct capture file.\n",
                           app_name.c_str());
    GFXRECON_WRITE_CONSOLE("Usage:");
    GFXRECON_WRITE_CONSOLE("  %s [-h | --help] [--version]<file>\n", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("Required arguments:");
    GFXRECON_WRITE_CONSOLE("  <file>\t\tThe GFXReconstruct capture file to be processed.");
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

        if (dir_location != std::string::npos)
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

[[maybe_unused]] std::string GetVersionString(uint32_t api_version)
{
    uint32_t major = api_version >> 22;
    uint32_t minor = (api_version >> 12) & 0x3ff;
    uint32_t patch = api_version & 0xfff;

    return std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(patch);
}

struct FileFormatInfo
{
    uint32_t major_version               = 0;
    uint32_t minor_version               = 0;
    bool     uses_frame_markers          = false;
    bool     file_supports_frame_markers = false;

    FileFormatInfo(const gfxrecon::decode::FileProcessor& file_processor)
    {
        const gfxrecon::format::FileHeader& file_header = file_processor.GetFileHeader();
        major_version                                   = file_header.major_version;
        minor_version                                   = file_header.minor_version;
        uses_frame_markers                              = file_processor.UsesFrameMarkers();
        file_supports_frame_markers                     = file_processor.FileSupportsFrameMarkers();
    }

    bool NeedsUpdate() const
    {
        return major_version == 0 && minor_version == 0 && uses_frame_markers && !file_supports_frame_markers;
    }
};

void PrintFileFormatInfo(const FileFormatInfo& file_format_info)
{
    GFXRECON_WRITE_CONSOLE(
        "\tFile format version: %u.%u", file_format_info.major_version, file_format_info.minor_version);
    const char* frame_marker_type = file_format_info.uses_frame_markers
                                        ? (file_format_info.NeedsUpdate() ? "explicit (unsupported)" : "explicit")
                                        : "implicit";
    GFXRECON_WRITE_CONSOLE("\tFrame delimiters: %s", frame_marker_type);
}

FileFormatInfo GatherFileFormatInfo(gfxrecon::decode::FileProcessor& file_processor,
                                    gfxrecon::decode::InfoConsumer&  info_consumer)
{
    gfxrecon::decode::InfoDecoder info_decoder;
    info_decoder.AddConsumer(&info_consumer);
    file_processor.AddDecoder(&info_decoder);
    bool success = file_processor.ProcessNextFrame();
    if (success && !file_processor.UsesFrameMarkers())
    {
        file_processor.ProcessNextFrame();
    }
    return FileFormatInfo(file_processor);
}

// Get file format info, and if appropriate update it. Only processes the first two frames of a capture
// file.
void PatchFileFormatInfo(const std::string& input_filename)
{
    bool update_file_format = false;
    // Wrap file_processor s.t. it closes the input file
    {
        const gfxrecon::decode::InfoConsumer::NoMaxBlockTag no_max_tag;
        gfxrecon::decode::InfoConsumer                      info_consumer(no_max_tag);
        gfxrecon::decode::FileProcessor                     file_processor;
        if (file_processor.Initialize(input_filename))
        {
            FileFormatInfo file_format_info = GatherFileFormatInfo(file_processor, info_consumer);
            GFXRECON_WRITE_CONSOLE("File format info:");
            PrintFileFormatInfo(file_format_info);
            // Only files with the original format, and containing frame markers can be updated
            if (file_format_info.NeedsUpdate())
            {
                update_file_format = true;
            }
        }
    }

    const char* status = "SKIPPED";
    if (update_file_format)
    {
        // Open and rewrite byte 8 to 1, changing the file version from 0, 0 to 0, 1
        FILE*   file   = nullptr;
        int32_t result = gfxrecon::util::platform::FileOpen(&file, input_filename.c_str(), "rb+");
        status         = "FAILED";
        if (result == 0)
        {
            const int64_t kMinorVersionOffset = 8;
            bool          success             = gfxrecon::util::platform::FileSeek(
                file, kMinorVersionOffset, gfxrecon::util::platform::FileSeekOrigin::FileSeekSet);
            if (success)
            {
                uint8_t one = 1;
                success     = gfxrecon::util::platform::FileWrite(&one, 1, file);
                if (success)
                {
                    status = "SUCCEEDED";
                }
            }
            gfxrecon::util::platform::FileClose(file);
        }
    }
    GFXRECON_WRITE_CONSOLE("File format update: %s", status);
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

    PatchFileFormatInfo(input_filename);

    gfxrecon::util::Log::Release();
    return 0;
}
