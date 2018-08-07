#include "format/file_processor.h"
#include "format/vulkan_ascii_consumer.h"
#include "format/vulkan_decoder.h"

int main(int argc, char** argv)
{
    brimstone::format::FileProcessor file_processor;
    std::string bin_file_name = "D:\\temp\\brimstone_test.bin";

    if (argc > 1)
    {
        bin_file_name = argv[1];
    }
    std::string text_file_name = bin_file_name;
    size_t suffix_pos = text_file_name.find(".bin");
    if (suffix_pos == std::string::npos)
    {
        text_file_name += ".txt";
    }
    else
    {
        text_file_name.replace(suffix_pos, 4, ".txt");
    }

    if (file_processor.Initialize(bin_file_name))
    {
        brimstone::format::VulkanDecoder decoder;
        brimstone::format::VulkanAsciiConsumer ascii_consumer;

        ascii_consumer.Initialize(text_file_name);
        decoder.AddConsumer(&ascii_consumer);

        file_processor.AddDecoder(&decoder);
        file_processor.ProcessAllFrames();
    }

    return 0;
}
