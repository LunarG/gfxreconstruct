/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2024 LunarG, Inc.
** Copyright (c) 2020 Advanced Micro Devices, Inc.
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
#include "tool_settings.h"
#include "decode/json_writer.h" /// @todo move to util?
#include "decode/decode_api_detection.h"
#include "format/format.h"
#include "util/file_output_stream.h"
#include "util/file_path.h"
#include "util/platform.h"

#include "generated/generated_vulkan_json_consumer.h"
#include "decode/marker_json_consumer.h"
#include "decode/metadata_json_consumer.h"
#if defined(CONVERT_EXPERIMENTAL_D3D12)
#include "generated/generated_dx12_json_consumer.h"
#endif

using gfxrecon::util::JsonFormat;
using VulkanJsonConsumer = gfxrecon::decode::MetadataJsonConsumer<
    gfxrecon::decode::MarkerJsonConsumer<gfxrecon::decode::VulkanExportJsonConsumer>>;
#if defined(CONVERT_EXPERIMENTAL_D3D12)
using Dx12JsonConsumer =
    gfxrecon::decode::MetadataJsonConsumer<gfxrecon::decode::MarkerJsonConsumer<gfxrecon::decode::Dx12JsonConsumer>>;
#endif
const char kOptions[] = "-h|--help,--version,--no-debug-popup,--file-per-frame,--include-binaries,--expand-flags";

const char kArguments[] = "--output,--format";

static void PrintUsage(const char* exe_name)
{
    std::string app_name     = exe_name;
    size_t      dir_location = app_name.find_last_of("/\\");
    if (dir_location >= 0)
    {
        app_name.replace(0, dir_location + 1, "");
    }
    GFXRECON_WRITE_CONSOLE("\n%s - A tool to convert the contents of GFXReconstruct capture files to JSON.\n",
                           app_name.c_str());
    GFXRECON_WRITE_CONSOLE("Usage:");
    GFXRECON_WRITE_CONSOLE("  %s [-h | --help] [--version] <file>\n", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("Required arguments:");
    GFXRECON_WRITE_CONSOLE("  <file>\t\tPath to the GFXReconstruct capture file to be converted");
    GFXRECON_WRITE_CONSOLE("        \t\tto text.");
    GFXRECON_WRITE_CONSOLE("\nOptional arguments:");
    GFXRECON_WRITE_CONSOLE("  -h\t\t\tPrint usage information and exit (same as --help).");
    GFXRECON_WRITE_CONSOLE("  --version\t\tPrint version information and exit.");
    GFXRECON_WRITE_CONSOLE("  --output file\t\t'stdout' or a path to a file to write JSON output");
    GFXRECON_WRITE_CONSOLE("        \t\tto. Default is the input filepath with \"gfxr\" replaced by \"json\".");
    GFXRECON_WRITE_CONSOLE("  --format <format>\tJSON format to write.");
    GFXRECON_WRITE_CONSOLE("           json\t\tStandard JSON format (indented)");
    GFXRECON_WRITE_CONSOLE("           jsonl\tJSON lines format (every object in a single line)");
    GFXRECON_WRITE_CONSOLE("  --include-binaries\tDump binaries from Vulkan traces in a separate file with an unique "
                           "name. The main JSON file");
    GFXRECON_WRITE_CONSOLE("                    \twill include a reference with the file name. The binary files are "
                           "dumped in a subdirectory");
    GFXRECON_WRITE_CONSOLE("  --expand-flags\tPrint flags values from Vulkan traces with its correspondent symbolic "
                           "representation. Otherwise,");
    GFXRECON_WRITE_CONSOLE("                \tthe flags are printed as hexadecimal value.");
    GFXRECON_WRITE_CONSOLE(
        "  --file-per-frame\tCreates a new file for every frame processed. Frame number is added as a suffix");
    GFXRECON_WRITE_CONSOLE("                  \tto the output file name.");

#if defined(WIN32) && defined(_DEBUG)
    GFXRECON_WRITE_CONSOLE("  --no-debug-popup\tDisable the 'Abort, Retry, Ignore' message box");
    GFXRECON_WRITE_CONSOLE("        \t\tdisplayed when abort() is called (Windows debug only).");
#endif
}

static std::string GetOutputFileName(const gfxrecon::util::ArgumentParser& arg_parser,
                                     const std::string&                    input_filename,
                                     JsonFormat                            output_format)
{
    std::string output_filename;
    if (arg_parser.IsArgumentSet(kOutput))
    {
        output_filename = arg_parser.GetArgumentValue(kOutput);
    }
    else
    {
        output_filename   = input_filename;
        auto ext_pos      = output_filename.find_last_of(".");
        auto path_sep_pos = output_filename.find_last_of(gfxrecon::util::filepath::kPathSepStr);
        if (ext_pos != std::string::npos && (path_sep_pos == std::string::npos || ext_pos > path_sep_pos))
        {
            output_filename = output_filename.substr(0, ext_pos);
        }
        switch (output_format)
        {
            case JsonFormat::JSONL:
                output_filename += ".jsonl";
                break;
            case JsonFormat::JSON:
            default:
                output_filename += ".json";
        }
    }
    return output_filename;
}

static gfxrecon::util::JsonFormat GetOutputFormat(const gfxrecon::util::ArgumentParser& arg_parser)
{
    std::string output_format;
    if (arg_parser.IsArgumentSet(kFormatArgument))
    {
        output_format = arg_parser.GetArgumentValue(kFormatArgument);
        if (output_format == "json")
        {
            return JsonFormat::JSON;
        }
        else if (output_format == "jsonl")
        {
            return JsonFormat::JSONL;
        }
        else
        {
            GFXRECON_LOG_WARNING("Unrecognized format %s. Defaulting to JSON format.", output_format.c_str());
            return JsonFormat::JSON;
        }
    }
    return JsonFormat::JSON;
}

std::string FormatFrameNumber(uint32_t frame_number)
{
    std::ostringstream stream;
    stream << std::setfill('0') << std::setw(5) << frame_number;
    return stream.str();
}

int main(int argc, const char** argv)
{
    int ret_code = 0;

    gfxrecon::util::Log::Init();

    gfxrecon::util::ArgumentParser arg_parser(argc, argv, kOptions, kArguments);

    if (CheckOptionPrintUsage(argv[0], arg_parser) || CheckOptionPrintVersion(argv[0], arg_parser))
    {
        gfxrecon::util::Log::Release();
        exit(0);
    }
    if (arg_parser.IsInvalid() || (arg_parser.GetPositionalArgumentsCount() != 1))
    {
        PrintUsage(argv[0]);
        gfxrecon::util::Log::Release();
        exit(1);
    }
    if (arg_parser.IsArgumentSet(kOutput) && arg_parser.GetArgumentValue(kOutput).empty())
    {
        GFXRECON_LOG_ERROR("Empty string given for argument \"--output\"; must be a valid path or 'stdout'");
        gfxrecon::util::Log::Release();
        exit(1);
    }
#if defined(WIN32) && defined(_DEBUG)
    if (arg_parser.IsOptionSet(kNoDebugPopup))
    {
        _set_abort_behavior(0, _WRITE_ABORT_MSG | _CALL_REPORTFAULT);
    }
#endif

    const auto& positional_arguments = arg_parser.GetPositionalArguments();
    std::string input_filename       = positional_arguments[0];
    JsonFormat  output_format        = GetOutputFormat(arg_parser);
    std::string output_filename      = GetOutputFileName(arg_parser, input_filename, output_format);
    std::string filename_stem        = gfxrecon::util::filepath::GetFilenameStem(output_filename);
    std::string output_dir           = gfxrecon::util::filepath::GetBasedir(output_filename);
    std::string data_dir             = gfxrecon::util::filepath::Join(output_dir, filename_stem);
    bool        dump_binaries        = arg_parser.IsOptionSet(kIncludeBinariesOption);
    bool        expand_flags         = arg_parser.IsOptionSet(kExpandFlagsOption);
    bool        file_per_frame       = arg_parser.IsOptionSet(kFilePerFrameOption);
    bool        output_to_stdout     = output_filename == "stdout";

    gfxrecon::decode::FileProcessor file_processor;

#ifndef CONVERT_EXPERIMENTAL_D3D12
    bool detected_d3d12  = false;
    bool detected_vulkan = false;
    bool detected_openxr = false;
    gfxrecon::decode::DetectAPIs(input_filename, detected_d3d12, detected_vulkan, detected_openxr);

    if (detected_d3d12)
    {
        GFXRECON_LOG_INFO("D3D12 support for gfxrecon-convert is currently experimental.");
        GFXRECON_LOG_INFO("To enable it, run cmake again with switch -DCONVERT_EXPERIMENTAL_D3D12");
        goto exit;
    }
#endif

    if (file_per_frame && output_to_stdout)
    {
        GFXRECON_LOG_WARNING("Outputting a file per frame is not consistent with outputting to stdout.");
        file_per_frame = false;
    }

    if (dump_binaries)
    {
        gfxrecon::util::filepath::MakeDirectory(data_dir);
    }

    if (file_processor.Initialize(input_filename))
    {
        std::string json_filename;
        FILE*       out_file_handle = nullptr;

        if (file_per_frame)
        {
            json_filename = gfxrecon::util::filepath::InsertFilenamePostfix(
                output_filename, +"_" + FormatFrameNumber(file_processor.GetCurrentFrameNumber()));
        }
        else
        {
            json_filename = output_filename;
        }
        if (output_to_stdout)
        {
            out_file_handle = stdout;
        }
        else
        {
            gfxrecon::util::platform::FileOpen(&out_file_handle, json_filename.c_str(), "w");
        }

        if (!out_file_handle)
        {
            GFXRECON_LOG_ERROR("Failed to open/create output file \"%s\"; is the path valid?", output_filename.c_str());
            ret_code = 1;
        }
        else
        {
            gfxrecon::util::FileNoLockOutputStream out_stream{ out_file_handle, false };
            VulkanJsonConsumer                     json_consumer;
            gfxrecon::util::JsonOptions            json_options;
            gfxrecon::decode::VulkanDecoder        decoder;
            decoder.AddConsumer(&json_consumer);
            file_processor.AddDecoder(&decoder);

            json_options.root_dir      = output_dir;
            json_options.data_sub_dir  = filename_stem;
            json_options.format        = output_format;
            json_options.dump_binaries = dump_binaries;
            json_options.expand_flags  = expand_flags;

            gfxrecon::decode::JsonWriter json_writer{ json_options, GFXRECON_PROJECT_VERSION_STRING, input_filename };
            file_processor.SetAnnotationProcessor(&json_writer);

            bool              success = true;
            const std::string vulkan_version{ std::to_string(VK_VERSION_MAJOR(VK_HEADER_VERSION_COMPLETE)) + "." +
                                              std::to_string(VK_VERSION_MINOR(VK_HEADER_VERSION_COMPLETE)) + "." +
                                              std::to_string(VK_VERSION_PATCH(VK_HEADER_VERSION_COMPLETE)) };
            json_consumer.Initialize(&json_writer, vulkan_version);
            json_writer.StartStream(&out_stream);

            // If CONVERT_EXPERIMENTAL_D3D12 was set, then add DX12 consumer/decoder
#ifdef CONVERT_EXPERIMENTAL_D3D12
            Dx12JsonConsumer                    dx12_json_consumer;
            gfxrecon::decode::Dx12Decoder       dx12_decoder;

            dx12_decoder.AddConsumer(&dx12_json_consumer);
            file_processor.AddDecoder(&dx12_decoder);
            auto dx12_json_flags = output_format == JsonFormat::JSON ? gfxrecon::util::kToString_Formatted
                                                                     : gfxrecon::util::kToString_Unformatted;
            dx12_json_consumer.Initialize(&json_writer);
#endif

            while (success)
            {
                success = file_processor.ProcessNextFrame();
                if (success && file_per_frame)
                {
                    json_writer.EndStream();
                    gfxrecon::util::platform::FileClose(out_file_handle);
                    json_filename = gfxrecon::util::filepath::InsertFilenamePostfix(
                        output_filename, +"_" + FormatFrameNumber(file_processor.GetCurrentFrameNumber()));
                    gfxrecon::util::platform::FileOpen(&out_file_handle, json_filename.c_str(), "w");
                    success = out_file_handle != nullptr;
                    if (success)
                    {
                        out_stream.Reset(out_file_handle);
                        json_writer.StartStream(&out_stream);
                    }
                    else
                    {
                        GFXRECON_LOG_ERROR("Failed to create file: '%s'.", json_filename.c_str());
                        ret_code = 1;
                    }
                }
            }
            json_consumer.Destroy();
            // If CONVERT_EXPERIMENTAL_D3D12 was set, then cleanup DX12 consumer
#ifdef CONVERT_EXPERIMENTAL_D3D12
            dx12_json_consumer.Destroy();
#endif
            if (!output_to_stdout)
            {
                gfxrecon::util::platform::FileClose(out_file_handle);
            }
            if (file_processor.GetErrorState() != gfxrecon::decode::FileProcessor::kErrorNone)
            {
                GFXRECON_LOG_ERROR("Failed to process trace.");
                ret_code = 1;
            }
        }
    }
    goto exit; // The other goto is inside an #ifdef and if compiled-out an unreferenced label warning results.
exit:
    gfxrecon::util::Log::Release();
    return ret_code;
}
