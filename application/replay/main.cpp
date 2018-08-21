#include <cstdio>
#include <exception>

#include "util/logging.h"
#include "format/file_processor.h"
#include "format/vulkan_replay_consumer.h"
#include "format/vulkan_decoder.h"
#include "util/argument_parser.h"

void PrintUsage(const char* exe_name)
{
    std::string app_name     = exe_name;
    size_t      dir_location = app_name.find_last_of("/\\");
    if (dir_location >= 0)
    {
        app_name.replace(0, dir_location + 1, "");
    }
    printf("\n\n%s\tis a trace replay tool designed to playback trace binary files.\n\n", app_name.c_str());
    printf("Usage:\n");
    printf("\t%s <binary_file>\n\n", app_name.c_str());
    printf("\t<binary_file>\t\tThe filename (including path if necessary) of the \n");
    printf("\t\t\t\ttrace binary file to replay\n");
}

int main(int argc, const char** argv)
{
    brimstone::util::logging::Init();

    brimstone::format::FileProcessor file_processor;
    std::string                      bin_file_name = "brimstone_test.bin";

    brimstone::util::ArgumentParser arg_parser(argc, argv, "", "", 1);
    const std::vector<std::string> non_optional_arguments = arg_parser.GetNonOptionalArguments();
    if (arg_parser.IsInvalid() || non_optional_arguments.size() != 1)
    {
        PrintUsage(argv[0]);
        exit(-1);
    }
    else
    {
        bin_file_name = non_optional_arguments[0];
    }

    if (file_processor.Initialize(bin_file_name))
    {
        brimstone::format::VulkanDecoder        decoder;
        brimstone::format::VulkanReplayConsumer replay_consumer;

        replay_consumer.SetFatalErrorHandler([](const char* message) { throw std::runtime_error(message); });

        decoder.AddConsumer(&replay_consumer);
        file_processor.AddDecoder(&decoder);

        try
        {
            file_processor.ProcessAllFrames();
        }
        catch (std::runtime_error error)
        {
            printf("Replay failed with error message: %s\n", error.what());
        }
        catch (...)
        {
            printf("Replay failed due to an unhandled exception\n");
        }
    }

    brimstone::util::logging::Release();

    return 0;
}
