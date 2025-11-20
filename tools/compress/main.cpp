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

#include PROJECT_VERSION_HEADER_FILE
#include "compression_converter.h"

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
    if (dir_location != std::string::npos)
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
#if defined(GFXRECON_ENABLE_LZ4_COMPRESSION)
    GFXRECON_WRITE_CONSOLE("                      \t  LZ4  - Use LZ4 compression.");
#endif
#if defined(GFXRECON_ENABLE_ZLIB_COMPRESSION)
    GFXRECON_WRITE_CONSOLE("                      \t  ZLIB - Use zlib compression.");
#endif
#if defined(GFXRECON_ENABLE_ZSTD_COMPRESSION)
    GFXRECON_WRITE_CONSOLE("                      \t  ZSTD - Use Zstandard compression.");
#endif
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
            break;
    }

    return kArgUnknown;
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

    gfxrecon::CompressionConverter file_converter;

    if (file_converter.Initialize(input_filename, output_filename, compression_type))
    {
        if (file_converter.Process())
        {
            std::string src_compression = kArgNone;

            for (const auto& option : file_converter.GetFileOptions())
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
                uint64_t    bytes_read      = file_converter.GetNumBytesRead();
                uint64_t    bytes_written   = file_converter.GetNumBytesWritten();
                float       percent_reduction =
                    100.f * (1.f - (static_cast<float>(bytes_written) / static_cast<float>(bytes_read)));
                GFXRECON_WRITE_CONSOLE("Compression Results:");
                GFXRECON_WRITE_CONSOLE(
                    "  Original Size   [Compression: %5s] = %" PRIu64 " bytes", src_compression.c_str(), bytes_read);
                GFXRECON_WRITE_CONSOLE(
                    "  Compressed Size [Compression: %5s] = %" PRIu64 " bytes", dst_compression.c_str(), bytes_written);
                GFXRECON_WRITE_CONSOLE("  Percent Reduction                    = %.2f%%", percent_reduction);
            }
            else
            {
                uint64_t bytes_read    = file_converter.GetNumBytesRead();
                uint64_t bytes_written = file_converter.GetNumBytesWritten();
                float    percent_increase =
                    100.f * ((static_cast<float>(bytes_written) / static_cast<float>(bytes_read)) - 1.f);
                GFXRECON_WRITE_CONSOLE("Decompression Results:");
                GFXRECON_WRITE_CONSOLE(
                    "  Original Size   [Compression: %5s] = %" PRIu64 " bytes", src_compression.c_str(), bytes_read);
                GFXRECON_WRITE_CONSOLE("  Uncompressed Size                    = %" PRIu64 " bytes", bytes_written);
                GFXRECON_WRITE_CONSOLE("  Percent Increase                     = %.2f%%", percent_increase);
            }
        }
        else
        {
            GFXRECON_WRITE_CONSOLE("Capture file %s could not be converted.", input_filename.c_str());
            gfxrecon::util::Log::Release();
            exit(-1);
        }
    }
    else
    {
        GFXRECON_WRITE_CONSOLE("CompressionConverter could not be initialized.");
        gfxrecon::util::Log::Release();
        exit(-1);
    }

    gfxrecon::util::Log::Release();

    return 0;
}
