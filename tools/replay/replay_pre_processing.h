/*
** Copyright (c) 2025 LunarG, Inc.
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

#ifndef GFXRECON_REPLAY_PRE_PROCESSING_H
#define GFXRECON_REPLAY_PRE_PROCESSING_H

struct ApiReplayOptions
{
    gfxrecon::decode::VulkanReplayOptions* vk_replay_options{ nullptr };

#if defined(D3D12_SUPPORT)
    gfxrecon::decode::DxReplayOptions* dx12_replay_options{ nullptr };
#endif
};

struct ApiReplayConsumer
{
    gfxrecon::decode::VulkanReplayConsumer* vk_replay_consumer{ nullptr };

#if defined(D3D12_SUPPORT)
    gfxrecon::decode::Dx12ReplayConsumer* dx12_replay_consumer{ nullptr };
#endif
};

bool IsRunPreProcessConsumer(ApiReplayOptions& replay_options)
{
    GFXRECON_ASSERT(replay_options.vk_replay_options != nullptr);

    if (replay_options.vk_replay_options->enable_dump_resources)
    {
        return true;
    }

#if defined(D3D12_SUPPORT)
    GFXRECON_ASSERT(replay_options.dx12_replay_options != nullptr);

    if (replay_options.dx12_replay_options->enable_dump_resources)
    {
        return true;
    }
#endif
    return false;
}

void RunPreProcessConsumer(const std::string& input_filename,
                           ApiReplayOptions&  replay_options,
                           ApiReplayConsumer& replay_consumer)
{
    GFXRECON_ASSERT(replay_options.vk_replay_options != nullptr && replay_consumer.vk_replay_consumer != nullptr);

    gfxrecon::decode::FileProcessor file_processor;
    if (file_processor.Initialize(input_filename))
    {
        gfxrecon::decode::VulkanPreProcessConsumer vk_pre_process_consumer;

        if (replay_options.vk_replay_options->using_dump_resources_target)
        {
            vk_pre_process_consumer.EnableDumpResources(replay_options.vk_replay_options->dump_resources_target);
        }

        gfxrecon::decode::VulkanDecoder vk_decoder;
        vk_decoder.AddConsumer(&vk_pre_process_consumer);
        file_processor.AddDecoder(&vk_decoder);

#if defined(D3D12_SUPPORT)
        GFXRECON_ASSERT(replay_options.dx12_replay_options != nullptr &&
                        replay_consumer.dx12_replay_consumer != nullptr);

        gfxrecon::decode::Dx12PreProcessConsumer dx12_pre_process_consumer;
        if (replay_options.dx12_replay_options->enable_dump_resources)
        {
            dx12_pre_process_consumer.EnableDumpResources(replay_options.dx12_replay_options->dump_resources_target);
        }
        gfxrecon::decode::Dx12Decoder dx12_decoder;
        dx12_decoder.AddConsumer(&dx12_pre_process_consumer);
        file_processor.AddDecoder(&dx12_decoder);
#endif

        file_processor.ProcessAllFrames();

        replay_options.vk_replay_options->enable_vulkan = vk_pre_process_consumer.WasVulkanAPIDetected();

        if (replay_options.vk_replay_options->enable_vulkan)
        {
            if (replay_options.vk_replay_options->using_dump_resources_target)
            {
                replay_options.vk_replay_options->dump_resources_block_indices =
                    vk_pre_process_consumer.GetDumpResourcesBlockIndices();
            }

            if (replay_options.vk_replay_options->enable_dump_resources)
            {
                // Process --dump-resources block indices arg.
                if (!gfxrecon::parse_dump_resources::parse_dump_resources_arg(*replay_options.vk_replay_options))
                {
                    GFXRECON_LOG_FATAL("There was an error while parsing dump resources indices. Terminating.");
                    exit(0);
                }
                replay_consumer.vk_replay_consumer->InitializeReplayDumpResources();
            }
        }

#if defined(D3D12_SUPPORT)
        replay_options.dx12_replay_options->enable_d3d12 = dx12_pre_process_consumer.WasD3D12APIDetected();

        if (replay_options.dx12_replay_options->enable_d3d12)
        {
            if (replay_options.dx12_replay_options->enable_dump_resources)
            {
                auto track_dump_target = dx12_pre_process_consumer.GetTrackDumpTarget();
                GFXRECON_ASSERT(track_dump_target != nullptr);
                replay_consumer.dx12_replay_consumer->SetDumpTarget(*track_dump_target);
            }
        }
#endif
    }
}

#endif // GFXRECON_REPLAY_PRE_PROCESSING_H
