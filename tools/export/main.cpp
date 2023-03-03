/*
** Copyright (c) 2022 LunarG, Inc.
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

#include "tool_settings.h"
#include "format/format.h"
#include "generated/generated_vulkan_export_json_consumer.h"
#include "util/platform.h"
#include "util/file_path.h"

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
    GFXRECON_WRITE_CONSOLE("\n%s - A tool to export contents of GFXReconstruct capture files to JSON.\n",
                           app_name.c_str());
    GFXRECON_WRITE_CONSOLE("Usage:");
    GFXRECON_WRITE_CONSOLE("  %s [-h | --help] [--version] <file>\n", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("Required arguments:");
    GFXRECON_WRITE_CONSOLE("  <file>\t\tPath to the GFXReconstruct capture file to be converted");
    GFXRECON_WRITE_CONSOLE("        \t\tto text.");
    GFXRECON_WRITE_CONSOLE("\nOptional arguments:");
    GFXRECON_WRITE_CONSOLE("  -h\t\t\tPrint usage information and exit (same as --help).");
    GFXRECON_WRITE_CONSOLE("  --version\t\tPrint version information and exit.");
    GFXRECON_WRITE_CONSOLE("  --output file\t\t'a path to a file to write JSON output");
    GFXRECON_WRITE_CONSOLE("        \t\tto. Default is the input filepath with \"gfxr\" replaced by \"json\".");
    GFXRECON_WRITE_CONSOLE("  --format <format>\t\t'JSON format to write.");
    GFXRECON_WRITE_CONSOLE("         json   Standard JSON format (indented)");
    GFXRECON_WRITE_CONSOLE("         jsonl  JSON lines format (every object in a single line)");
    GFXRECON_WRITE_CONSOLE(
        "  --include-binaries\t\t'Dump binaries in a separate file with an unique name. The main JSON file");
    GFXRECON_WRITE_CONSOLE(
        "         will include a reference with the file name. The binary files are dumped in a subdirectory");
    GFXRECON_WRITE_CONSOLE(
        "  --expand-flags\t\t'Print flags values with its correspondent symbolic representation. Otherwise,");
    GFXRECON_WRITE_CONSOLE("         the flags are printed as hexadecimal value.");
    GFXRECON_WRITE_CONSOLE(
        "  --file-per-frame\t\t'Creates a new file per every frame processed. Frame number is added as a suffix");
    GFXRECON_WRITE_CONSOLE("         to the output file name.");

#if defined(WIN32) && defined(_DEBUG)
    GFXRECON_WRITE_CONSOLE("  --no-debug-popup\tDisable the 'Abort, Retry, Ignore' message box");
    GFXRECON_WRITE_CONSOLE("        \t\tdisplayed when abort() is called (Windows debug only).");
#endif
}

static std::string GetOutputFileName(const gfxrecon::util::ArgumentParser& arg_parser,
                                     const std::string&                    input_filename,
                                     gfxrecon::decode::JsonFormat          output_format)
{
    std::string output_filename;
    if (arg_parser.IsArgumentSet(kOutput))
    {
        output_filename = arg_parser.GetArgumentValue(kOutput);
    }
    else
    {
        output_filename   = input_filename;
        size_t suffix_pos = output_filename.find(GFXRECON_FILE_EXTENSION);
        if (suffix_pos != std::string::npos)
        {
            output_filename = output_filename.substr(0, suffix_pos);
        }
        switch (output_format)
        {
            case gfxrecon::decode::JsonFormat::JSONL:
                output_filename += ".jsonl";
                break;
            case gfxrecon::decode::JsonFormat::JSON:
            default:
                output_filename += ".json";
        }
    }
    return output_filename;
}

static gfxrecon::decode::JsonFormat GetOutputFormat(const gfxrecon::util::ArgumentParser& arg_parser)
{
    std::string output_format;
    if (arg_parser.IsArgumentSet(kFormatArgument))
    {
        output_format = arg_parser.GetArgumentValue(kFormatArgument);
        if (output_format == "json")
        {
            return gfxrecon::decode::JsonFormat::JSON;
        }
        else if (output_format == "jsonl")
        {
            return gfxrecon::decode::JsonFormat::JSONL;
        }
        else
        {
            GFXRECON_LOG_WARNING("Unrecognized format %s. Defaulting to JSON format.", output_format.c_str());
            return gfxrecon::decode::JsonFormat::JSON;
        }
    }
    return gfxrecon::decode::JsonFormat::JSON;
}

std::string FormatFrameNumber(uint32_t frame_number)
{
    std::stringstream stream;
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
    auto        output_format        = GetOutputFormat(arg_parser);
    std::string output_filename      = GetOutputFileName(arg_parser, input_filename, output_format);
    std::string filename_stem        = gfxrecon::util::filepath::GetFilenameStem(output_filename);
    std::string output_dir           = gfxrecon::util::filepath::GetBasedir(output_filename);
    std::string data_dir             = gfxrecon::util::filepath::Join(output_dir, filename_stem);
    bool        dump_binaries        = arg_parser.IsOptionSet(kIncludeBinariesOption);
    bool        expand_flags         = arg_parser.IsOptionSet(kExpandFlagsOption);
    bool        file_per_frame       = arg_parser.IsOptionSet(kFilePerFrameOption);

    if (dump_binaries)
    {
        gfxrecon::util::filepath::MakeDirectory(data_dir);
    }

    gfxrecon::decode::FileProcessor file_processor;
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
        gfxrecon::util::platform::FileOpen(&out_file_handle, json_filename.c_str(), "w");

        if (!out_file_handle)
        {
            GFXRECON_LOG_ERROR("Failed to open/create output file \"%s\"; is the path valid?", output_filename.c_str());
            ret_code = 1;
        }
        else
        {
            gfxrecon::decode::VulkanExportJsonConsumer json_consumer;
            gfxrecon::decode::JsonOptions              json_options;
            gfxrecon::decode::VulkanDecoder            decoder;
            decoder.AddConsumer(&json_consumer);
            file_processor.AddDecoder(&decoder);

            json_options.root_dir      = output_dir;
            json_options.data_sub_dir  = filename_stem;
            json_options.format        = output_format;
            json_options.dump_binaries = dump_binaries;
            json_options.expand_flags  = expand_flags;

            bool success = true;
            const std::string vulkan_version{ std::to_string(VK_VERSION_MAJOR(VK_HEADER_VERSION_COMPLETE)) + "." +
                                              std::to_string(VK_VERSION_MINOR(VK_HEADER_VERSION_COMPLETE)) + "." +
                                              std::to_string(VK_VERSION_PATCH(VK_HEADER_VERSION_COMPLETE)) };
            json_consumer.Initialize(json_options, GFXRECON_PROJECT_VERSION_STRING, vulkan_version, input_filename);
            json_consumer.StartFile(out_file_handle);
            while (success)
            {
                success = file_processor.ProcessNextFrame();
                if (success && file_per_frame)
                {
                    json_consumer.EndFile();
                    gfxrecon::util::platform::FileClose(out_file_handle);
                    json_filename = gfxrecon::util::filepath::InsertFilenamePostfix(
                        output_filename, +"_" + FormatFrameNumber(file_processor.GetCurrentFrameNumber()));
                    gfxrecon::util::platform::FileOpen(&out_file_handle, json_filename.c_str(), "w");
                    success = out_file_handle != nullptr;
                    if (success)
                    {
                        json_consumer.StartFile(out_file_handle);
                    }
                    else
                    {
                        GFXRECON_LOG_ERROR("Failed to create file: '%s'.", json_filename.c_str());
                        ret_code = 1;
                    }
                }
            }
            json_consumer.EndFile();
            if (file_processor.GetErrorState() != gfxrecon::decode::FileProcessor::kErrorNone)
            {
                GFXRECON_LOG_ERROR("Failed to process trace.");
                ret_code = 1;
            }
        }
    }

    gfxrecon::util::Log::Release();
    return ret_code;
}
