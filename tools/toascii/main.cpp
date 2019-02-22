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

#include "decode/file_processor.h"
#include "format/format.h"
#include "generated/generated_vulkan_ascii_consumer.h"
#include "generated/generated_vulkan_decoder.h"
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
    GFXRECON_WRITE_CONSOLE("\n\n%s\tis a replay tool designed to output the API commands", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("\t\tfound inside of a GFXReconstruct capture file.\n");
    GFXRECON_WRITE_CONSOLE("Usage:");
    GFXRECON_WRITE_CONSOLE("\t%s <file>\n", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("\t<file>\t\tThe filename (including path if necessary) of the capture");
    GFXRECON_WRITE_CONSOLE("\t\t\t\tfile whose API command contents should be outputted.");
    GFXRECON_WRITE_CONSOLE("\t\t\t\tThe results will be output to a file of the same name but");
    GFXRECON_WRITE_CONSOLE("\t\t\t\twith \'" GFXRECON_FILE_EXTENSION "\' suffix replaced with \'.txt\'.");
}

int main(int argc, const char** argv)
{
    std::string                     input_filename;
    gfxrecon::decode::FileProcessor file_processor;
    gfxrecon::util::ArgumentParser  arg_parser(argc, argv, "", "", 1);

    gfxrecon::util::Log::Init();

    if (arg_parser.IsInvalid() || (arg_parser.GetPositionalArgumentsCount() != 1))
    {
        PrintUsage(argv[0]);
        gfxrecon::util::Log::Release();
        exit(-1);
    }
    else
    {
        const std::vector<std::string>& positional_arguments = arg_parser.GetPositionalArguments();
        input_filename                                       = positional_arguments[0];
    }

    std::string output_filename = input_filename;
    size_t      suffix_pos      = output_filename.find(GFXRECON_FILE_EXTENSION);
    if (suffix_pos != std::string::npos)
    {
        output_filename = output_filename.substr(0, suffix_pos);
    }

    output_filename += ".txt";

    if (file_processor.Initialize(input_filename))
    {
        gfxrecon::decode::VulkanDecoder       decoder;
        gfxrecon::decode::VulkanAsciiConsumer ascii_consumer;

        ascii_consumer.Initialize(output_filename);
        decoder.AddConsumer(&ascii_consumer);

        file_processor.AddDecoder(&decoder);
        file_processor.ProcessAllFrames();
    }

    gfxrecon::util::Log::Release();
    return 0;
}
