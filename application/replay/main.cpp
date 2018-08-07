#include "format/file_processor.h"
#include "format/vulkan_replay_consumer.h"
#include "format/vulkan_decoder.h"

int main(int argc, char** argv)
{
    brimstone::format::FileProcessor file_processor;

    std::string bin_file_name = "D:\\temp\\brimstone_test.bin";
    if (argc > 1)
    {
        bin_file_name = argv[1];
    }

    if (file_processor.Initialize(bin_file_name))
    {
        brimstone::format::VulkanDecoder decoder;
        brimstone::format::VulkanReplayConsumer ascii_consumer;

        decoder.AddConsumer(&ascii_consumer);

        file_processor.AddDecoder(&decoder);
        file_processor.ProcessAllFrames();
    }

    return 0;
}
