/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
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

#include "decode/compression_converter.h"
#include "decode/file_processor.h"
#include "format/format.h"
#include "util/argument_parser.h"
#include "util/compressor.h"
#include "util/logging.h"

#include <cassert>

void PrintUsage(const char* exe_name)
{
    std::string app_name     = exe_name;
    size_t      dir_location = app_name.find_last_of("/\\");
    if (dir_location >= 0)
    {
        app_name.replace(0, dir_location + 1, "");
    }
    GFXRECON_WRITE_CONSOLE("\n\n%s\tis a compression/decompression tool for working with", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("\t\tGFXReconstruct capture files.\n");
    GFXRECON_WRITE_CONSOLE("Usage:");
    GFXRECON_WRITE_CONSOLE("\t%s <input_file> <output_file> <compression_format>\n", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("\t<input_file>\t\tThe filename (including path if necessary) of the ");
    GFXRECON_WRITE_CONSOLE("\t\t\t\tincoming capture file to manipulate");
    GFXRECON_WRITE_CONSOLE("\t<output_file>\t\tThe filename (including path if necessary) of the ");
    GFXRECON_WRITE_CONSOLE("\t\t\t\tresulting capture file to generate");
    GFXRECON_WRITE_CONSOLE("\t<compression_format>\tThe compression format to use when generating");
    GFXRECON_WRITE_CONSOLE("\t\t\t\tthe output file.  Possible values are: ");
    GFXRECON_WRITE_CONSOLE("\t\t\t\t\tLZ4  - To output using LZ4 compression");
    GFXRECON_WRITE_CONSOLE("\t\t\t\t\tLZ77 - To output using LZ77 compression");
    GFXRECON_WRITE_CONSOLE("\t\t\t\t\tNONE - To output without using compression");
}

int main(int argc, const char** argv)
{
    gfxrecon::decode::FileProcessor   file_processor;
    gfxrecon::format::CompressionType compression_type       = gfxrecon::format::kNone;
    std::string                       dst_compression_string = "NONE";
    bool                              print_usage            = false;
    std::string                       input_filename;
    std::string                       output_filename;

    gfxrecon::util::Log::Init(gfxrecon::util::Log::kInfoSeverity);

    gfxrecon::util::ArgumentParser arg_parser(argc, argv, "", "", 3);

    if (arg_parser.IsInvalid() || (arg_parser.GetPositionalArgumentsCount() != 3))
    {
        print_usage = true;
    }
    else
    {
        const std::vector<std::string>& positional_arguments = arg_parser.GetPositionalArguments();

        input_filename         = positional_arguments[0];
        output_filename        = positional_arguments[1];
        dst_compression_string = positional_arguments[2];

        if (dst_compression_string != "NONE")
        {
            if (dst_compression_string == "LZ4")
            {
                compression_type = gfxrecon::format::CompressionType::kLz4;
            }
            else if (dst_compression_string == "LZ77")
            {
                compression_type = gfxrecon::format::CompressionType::kLz77;
            }
            else
            {
                GFXRECON_LOG_ERROR("Unsupported compression format \'%s\'", positional_arguments[2].c_str());
                print_usage = true;
            }
        }
    }

    if (print_usage)
    {
        PrintUsage(argv[0]);
        gfxrecon::util::Log::Release();
        exit(-1);
    }

    if (file_processor.Initialize(input_filename))
    {
        gfxrecon::decode::CompressionConverter decoder;

        if (decoder.Initialize(
                output_filename, file_processor.GetFileHeader(), file_processor.GetFileOptions(), compression_type))
        {
            std::string src_compression = "NONE";
            file_processor.AddDecoder(&decoder);
            file_processor.ProcessAllFrames();

            for (const auto& option : file_processor.GetFileOptions())
            {
                if (option.key == gfxrecon::format::kCompressionType)
                {
                    switch (option.value)
                    {
                        case gfxrecon::format::CompressionType::kNone:
                            // Nothing to do
                            break;
                        case gfxrecon::format::CompressionType::kLz4:
                            src_compression = "LZ4";
                            break;
                        case gfxrecon::format::CompressionType::kLz77:
                            src_compression = "LZ77";
                            break;
                        default:
                            GFXRECON_LOG_ERROR("Unknown source compression type %d", option.value);
                            assert(false);
                            break;
                    }
                }
            }

            if (gfxrecon::format::CompressionType::kNone != compression_type)
            {
                uint64_t bytes_read    = file_processor.NumBytesRead();
                uint64_t bytes_written = decoder.NumBytesWritten();
                float    percent_reduction =
                    100.f * (1.f - (static_cast<float>(bytes_written) / static_cast<float>(bytes_read)));
                GFXRECON_WRITE_CONSOLE("Compression Results:");
                GFXRECON_WRITE_CONSOLE(
                    "  Original Size   [Compression: %5s] = %" PRIu64 " bytes", src_compression.c_str(), bytes_read);
                GFXRECON_WRITE_CONSOLE("  Compressed Size [Compression: %5s] = %" PRIu64 " bytes",
                                       dst_compression_string.c_str(),
                                       bytes_written);
                printf("  Percent Reduction                    = %.2f%%", percent_reduction);
            }
            else
            {
                uint64_t bytes_read    = file_processor.NumBytesRead();
                uint64_t bytes_written = decoder.NumBytesWritten();
                float    percent_increase =
                    100.f * ((static_cast<float>(bytes_written) / static_cast<float>(bytes_read)) - 1.f);
                GFXRECON_WRITE_CONSOLE("Uncompression Results:");
                GFXRECON_WRITE_CONSOLE(
                    "  Original Size   [Compression: %5s] = %" PRIu64 " bytes", src_compression.c_str(), bytes_read);
                GFXRECON_WRITE_CONSOLE("  Uncompressed Size                    = %" PRIu64 " bytes", bytes_written);
                GFXRECON_WRITE_CONSOLE("  Percent Increase                     = %.2f%%", percent_increase);
            }
        }
    }

    gfxrecon::util::Log::Release();
    return 0;
}
