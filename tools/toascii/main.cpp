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
    BRIMSTONE_WRITE_CONSOLE("\n\n%s\tis a trace replay tool designed to output the API commands", app_name.c_str());
    BRIMSTONE_WRITE_CONSOLE("\t\tfound inside of a trace binary file.\n");
    BRIMSTONE_WRITE_CONSOLE("Usage:");
    BRIMSTONE_WRITE_CONSOLE("\t%s <file>\n", app_name.c_str());
    BRIMSTONE_WRITE_CONSOLE("\t<file>\t\tThe filename (including path if necessary) of the trace");
    BRIMSTONE_WRITE_CONSOLE("\t\t\t\tbinary file whose API command contents should be outputted.");
    BRIMSTONE_WRITE_CONSOLE("\t\t\t\tThe results will be output to a file of the same name but");
    BRIMSTONE_WRITE_CONSOLE("\t\t\t\twith \'" BRIMSTONE_FILE_EXTENSION "\' suffix replaced with \'.txt\'.");
}

int main(int argc, const char** argv)
{
    brimstone::decode::FileProcessor file_processor;
    brimstone::util::ArgumentParser  arg_parser(argc, argv, "", "", 1);
    std::string                      filename = "brimstone_test";
    filename += BRIMSTONE_FILE_EXTENSION;

    brimstone::util::logging::Init();

    const std::vector<std::string> non_optional_arguments = arg_parser.GetNonOptionalArguments();
    if (arg_parser.IsInvalid() || non_optional_arguments.size() != 1)
    {
        PrintUsage(argv[0]);
        exit(-1);
    }
    else
    {
        filename = non_optional_arguments[0];
    }

    if (argc > 1)
    {
        filename = argv[1];
    }

    std::string text_file_name = filename;
    size_t      suffix_pos     = text_file_name.find(BRIMSTONE_FILE_EXTENSION);
    if (suffix_pos != std::string::npos)
    {
        text_file_name = text_file_name.substr(0, suffix_pos);
    }

    text_file_name += ".txt";

    if (file_processor.Initialize(filename))
    {
        brimstone::decode::VulkanDecoder       decoder;
        brimstone::decode::VulkanAsciiConsumer ascii_consumer;

        ascii_consumer.Initialize(text_file_name);
        decoder.AddConsumer(&ascii_consumer);

        file_processor.AddDecoder(&decoder);
        file_processor.ProcessAllFrames();
    }

    return 0;
}
