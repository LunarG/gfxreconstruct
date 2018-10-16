#include <cassert>

#include "format/format.h"
#include "decode/file_processor.h"
#include "decode/compression_converter.h"
#include "util/compressor.h"
#include "util/argument_parser.h"
#include "util/logging.h"

void PrintUsage(const char* exe_name)
{
    std::string app_name     = exe_name;
    size_t      dir_location = app_name.find_last_of("/\\");
    if (dir_location >= 0)
    {
        app_name.replace(0, dir_location + 1, "");
    }
    BRIMSTONE_WRITE_CONSOLE("\n\n%s\tis a compression/decompression tool for working with", app_name.c_str());
    BRIMSTONE_WRITE_CONSOLE("\t\ttrace binary files.\n");
    BRIMSTONE_WRITE_CONSOLE("Usage:");
    BRIMSTONE_WRITE_CONSOLE("\t%s <input_file> <output_file> <compression_format>\n", app_name.c_str());
    BRIMSTONE_WRITE_CONSOLE("\t<input_file>\t\tThe filename (including path if necessary) of the ");
    BRIMSTONE_WRITE_CONSOLE("\t\t\t\tincoming binary file to manipulate");
    BRIMSTONE_WRITE_CONSOLE("\t<output_file>\t\tThe filename (including path if necessary) of the ");
    BRIMSTONE_WRITE_CONSOLE("\t\t\t\tresulting binary file to generate");
    BRIMSTONE_WRITE_CONSOLE("\t<compression_format>\tThe compression format to use when generating");
    BRIMSTONE_WRITE_CONSOLE("\t\t\t\tthe output file.  Possible values are: ");
    BRIMSTONE_WRITE_CONSOLE("\t\t\t\t\tLZ4  - To output using LZ4 compression");
    BRIMSTONE_WRITE_CONSOLE("\t\t\t\t\tLZ77 - To output using LZ77 compression");
    BRIMSTONE_WRITE_CONSOLE("\t\t\t\t\tNONE - To output without using compression");
}

int main(int argc, const char** argv)
{
    brimstone::decode::FileProcessor   file_processor;
    brimstone::format::CompressionType compression_type       = brimstone::format::kNone;
    std::string                        dst_compression_string = "NONE";
    bool                               print_usage            = false;
    std::string                        input_file_name        = "brimstone_out";
    std::string                        output_file_name       = "gcapcompress_out";

    input_file_name += BRIMSTONE_FILE_EXTENSION;
    output_file_name += BRIMSTONE_FILE_EXTENSION;

    brimstone::util::logging::Init();

    brimstone::util::ArgumentParser arg_parser(argc, argv, "", "", 3);
    const std::vector<std::string>  non_optional_arguments = arg_parser.GetNonOptionalArguments();
    if (arg_parser.IsInvalid() || non_optional_arguments.size() != 3)
    {
        print_usage = true;
    }
    else
    {
        input_file_name  = non_optional_arguments[0];
        output_file_name = non_optional_arguments[1];
        if (non_optional_arguments[2] == "NONE")
        {
            // Nothing to do here.
        }
        else if (non_optional_arguments[2] == "LZ4")
        {
            compression_type       = brimstone::format::CompressionType::kLz4;
            dst_compression_string = non_optional_arguments[2];
        }
        else if (non_optional_arguments[2] == "LZ77")
        {
            compression_type       = brimstone::format::CompressionType::kLz77;
            dst_compression_string = non_optional_arguments[2];
        }
        else
        {
            BRIMSTONE_LOG_ERROR("Unsupported compression format \'%s\'", non_optional_arguments[2].c_str());
            print_usage = true;
        }
    }

    if (print_usage)
    {
        PrintUsage(argv[0]);
        exit(-1);
    }

    if (file_processor.Initialize(input_file_name))
    {
        brimstone::decode::CompressionConverter decoder;

        if (decoder.Initialize(
                output_file_name, file_processor.GetFileHeader(), file_processor.GetFileOptions(), compression_type))
        {
            std::string src_compression = "NONE";
            file_processor.AddDecoder(&decoder);
            file_processor.ProcessAllFrames();

            for (const auto& option : file_processor.GetFileOptions())
            {
                if (option.key == brimstone::format::kCompressionType)
                {
                    switch (option.value)
                    {
                        case brimstone::format::CompressionType::kNone:
                            // Nothing to do
                            break;
                        case brimstone::format::CompressionType::kLz4:
                            src_compression = "LZ4";
                            break;
                        case brimstone::format::CompressionType::kLz77:
                            src_compression = "LZ77";
                            break;
                        default:
                            BRIMSTONE_LOG_ERROR("Unknown source compression type %d", option.value);
                            assert(false);
                            break;
                    }
                }
            }

            if (brimstone::format::CompressionType::kNone != compression_type)
            {
                uint64_t bytes_read    = file_processor.NumBytesRead();
                uint64_t bytes_written = decoder.NumBytesWritten();
                float    percent_reduction =
                    100.f * (1.f - (static_cast<float>(bytes_written) / static_cast<float>(bytes_read)));
                BRIMSTONE_WRITE_CONSOLE("Compression Results:");
                BRIMSTONE_WRITE_CONSOLE(
                    "  Original Size   [Compression: %5s] = %" PRIu64 " bytes", src_compression.c_str(), bytes_read);
                BRIMSTONE_WRITE_CONSOLE("  Compressed Size [Compression: %5s] = %" PRIu64 " bytes",
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
                BRIMSTONE_WRITE_CONSOLE("Uncompression Results:");
                BRIMSTONE_WRITE_CONSOLE(
                    "  Original Size   [Compression: %5s] = %" PRIu64 " bytes", src_compression.c_str(), bytes_read);
                BRIMSTONE_WRITE_CONSOLE("  Uncompressed Size                    = %" PRIu64 " bytes", bytes_written);
                BRIMSTONE_WRITE_CONSOLE("  Percent Increase                     = %.2f%%", percent_increase);
            }
        }
    }

    return 0;
}
