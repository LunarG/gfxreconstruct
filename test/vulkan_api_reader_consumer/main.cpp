#include "decode/vulkan_api_call_reader.h"

#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "usage: vulkan_api_reader_consumer capture.gfxr\n";
        return 2;
    }

    gfxrecon::decode::VulkanApiCallReader     reader;
    gfxrecon::decode::VulkanNativeCommandInfo create_instance;
    if (!reader.GetSupportedCallbackInfo("vkCreateInstance", &create_instance))
    {
        std::cerr << "vkCreateInstance is not supported by the installed reader\n";
        return 3;
    }

    if (!reader.Initialize(argv[1]) || !reader.ProcessAllFrames())
    {
        std::cerr << "failed to process capture\n";
        return 4;
    }

    return 0;
}
