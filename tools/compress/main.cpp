/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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

#include "decode/compression_converter.h"
#include "decode/file_processor.h"
#include "format/format.h"
#include "util/argument_parser.h"
#include "util/compressor.h"
#include "util/logging.h"

#include "vulkan/vulkan_core.h"

#include <cassert>
#include <cstdlib>

const char kHelpShortOption[] = "-h";
const char kHelpLongOption[]  = "--help";
const char kVersionOption[]   = "--version";
const char kNoDebugPopup[]    = "--no-debug-popup";

const char kOptions[] = "-h|--help,--version,--no-debug-popup";

const char kArgNone[]    = "NONE";
const char kArgLz4[]     = "LZ4";
const char kArgZlib[]    = "ZLIB";
const char kArgZstd[]    = "ZSTD";
const char kArgUnknown[] = "<Unknown>";

static void PrintUsage(const char* exe_name)
{
    std::string app_name     = exe_name;
    size_t      dir_location = app_name.find_last_of("/\\");
    if (dir_location >= 0)
    {
        app_name.replace(0, dir_location + 1, "");
    }
    GFXRECON_WRITE_CONSOLE("\n%s - A tool to compress/decompress GFXReconstruct capture files.\n", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("Usage:");
    GFXRECON_WRITE_CONSOLE("  %s [-h | --help] [--version] <input_file> <output_file> <compression_format>\n",
                           app_name.c_str());
    GFXRECON_WRITE_CONSOLE("Required arguments:");
    GFXRECON_WRITE_CONSOLE("  <input_file>\t\tPath to the input file to process.");
    GFXRECON_WRITE_CONSOLE("  <output_file>\t\tPath to the output file to generate.");
    GFXRECON_WRITE_CONSOLE("  <compression_format>\tCompression format to apply to the output file.");
    GFXRECON_WRITE_CONSOLE("                      \tOptions are: ");
    GFXRECON_WRITE_CONSOLE("                      \t  LZ4  - Use LZ4 compression.");
    GFXRECON_WRITE_CONSOLE("                      \t  ZLIB - Use zlib compression.");
    GFXRECON_WRITE_CONSOLE("                      \t  ZSTD - Use Zstandard compression.");
    GFXRECON_WRITE_CONSOLE("                      \t  NONE - Remove compression.");
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

static std::string GetCompressionTypeName(uint32_t type)
{
    switch (type)
    {
        case gfxrecon::format::CompressionType::kNone:
            return kArgNone;
        case gfxrecon::format::CompressionType::kLz4:
            return kArgLz4;
        case gfxrecon::format::CompressionType::kZlib:
            return kArgZlib;
        case gfxrecon::format::CompressionType::kZstd:
            return kArgZstd;
        default:
            assert(false);
            break;
    }

    return kArgUnknown;
}

int main(int argc, const char** argv)
{
    int return_code = 0;

    gfxrecon::util::Log::Init();

    gfxrecon::util::ArgumentParser arg_parser(argc, argv, kOptions, "");

    if (CheckOptionPrintUsage(argv[0], arg_parser) || CheckOptionPrintVersion(argv[0], arg_parser))
    {
        gfxrecon::util::Log::Release();
        exit(0);
    }
    else if (arg_parser.IsInvalid() || (arg_parser.GetPositionalArgumentsCount() != 3))
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

    const std::vector<std::string>& positional_arguments   = arg_parser.GetPositionalArguments();
    std::string                     input_filename         = positional_arguments[0];
    std::string                     output_filename        = positional_arguments[1];
    std::string                     dst_compression_string = positional_arguments[2];

    gfxrecon::format::CompressionType compression_type = gfxrecon::format::kNone;

    if (gfxrecon::util::platform::StringCompareNoCase(kArgNone, dst_compression_string.c_str()) != 0)
    {
        if (gfxrecon::util::platform::StringCompareNoCase(kArgLz4, dst_compression_string.c_str()) == 0)
        {
            compression_type = gfxrecon::format::CompressionType::kLz4;
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kArgZlib, dst_compression_string.c_str()) == 0)
        {
            compression_type = gfxrecon::format::CompressionType::kZlib;
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kArgZstd, dst_compression_string.c_str()) == 0)
        {
            compression_type = gfxrecon::format::CompressionType::kZstd;
        }
        else
        {
            GFXRECON_LOG_ERROR("Unsupported compression format \'%s\'", dst_compression_string.c_str());
            PrintUsage(argv[0]);
            gfxrecon::util::Log::Release();
            exit(-1);
        }
    }

    gfxrecon::decode::FileProcessor file_processor;

    if (file_processor.Initialize(input_filename))
    {
        gfxrecon::decode::CompressionConverter decoder;

        if (decoder.Initialize(
                output_filename, file_processor.GetFileHeader(), file_processor.GetFileOptions(), compression_type))
        {
            file_processor.AddDecoder(&decoder);
            bool succeeded = file_processor.ProcessAllFrames();

            if (succeeded)
            {
                std::string src_compression = kArgNone;

                for (const auto& option : file_processor.GetFileOptions())
                {
                    if (option.key == gfxrecon::format::kCompressionType)
                    {
                        src_compression = GetCompressionTypeName(option.value);

                        if (src_compression == kArgUnknown)
                        {
                            GFXRECON_LOG_ERROR("Unrecognized source compression type %u", option.value);
                        }
                    }
                }

                if (gfxrecon::format::CompressionType::kNone != compression_type)
                {
                    std::string dst_compression = GetCompressionTypeName(compression_type);
                    uint64_t    bytes_read      = file_processor.GetNumBytesRead();
                    uint64_t    bytes_written   = decoder.NumBytesWritten();
                    float       percent_reduction =
                        100.f * (1.f - (static_cast<float>(bytes_written) / static_cast<float>(bytes_read)));
                    GFXRECON_WRITE_CONSOLE("Compression Results:");
                    GFXRECON_WRITE_CONSOLE("  Original Size   [Compression: %5s] = %" PRIu64 " bytes",
                                           src_compression.c_str(),
                                           bytes_read);
                    GFXRECON_WRITE_CONSOLE("  Compressed Size [Compression: %5s] = %" PRIu64 " bytes",
                                           dst_compression.c_str(),
                                           bytes_written);
                    GFXRECON_WRITE_CONSOLE("  Percent Reduction                    = %.2f%%", percent_reduction);
                }
                else
                {
                    uint64_t bytes_read    = file_processor.GetNumBytesRead();
                    uint64_t bytes_written = decoder.NumBytesWritten();
                    float    percent_increase =
                        100.f * ((static_cast<float>(bytes_written) / static_cast<float>(bytes_read)) - 1.f);
                    GFXRECON_WRITE_CONSOLE("Decompression Results:");
                    GFXRECON_WRITE_CONSOLE("  Original Size   [Compression: %5s] = %" PRIu64 " bytes",
                                           src_compression.c_str(),
                                           bytes_read);
                    GFXRECON_WRITE_CONSOLE("  Uncompressed Size                    = %" PRIu64 " bytes", bytes_written);
                    GFXRECON_WRITE_CONSOLE("  Percent Increase                     = %.2f%%", percent_increase);
                }
            }
            else
            {
                GFXRECON_LOG_ERROR("Failed to process capture file %s", input_filename.c_str());
                return_code = -1;
            }
        }
    }

    gfxrecon::util::Log::Release();

    return return_code;
}
