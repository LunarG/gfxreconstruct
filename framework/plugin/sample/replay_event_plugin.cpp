/*
** Copyright (c) 2026 LunarG, Inc.
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

#include <gfxr/replay_event_plugin.h>

#include <util/logging.h>

#include <chrono>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

#ifdef __ANDROID__
#include <android/trace.h>
#endif

namespace
{
void TraceBeginSection(const char* name)
{
#ifdef __ANDROID__
    ATrace_beginSection(name);
#endif
}

void TraceEndSection()
{
#ifdef __ANDROID__
    ATrace_endSection();
#endif
}
} // namespace

struct SampleReplayPlugin
{
    GfxrReplayPluginV1 base;
    int sleep_around_gpu_frame_ms = 0;
    bool first_queue_submit_in_frame = true;
};

static void destroy(GfxrReplayPluginV1* self)
{
    if (self == NULL)
    {
        GFXRECON_LOG_ERROR("Received NULL plugin instance");
        return;
    }

    GFXRECON_LOG_INFO("Destroying plugin");
    delete reinterpret_cast<SampleReplayPlugin*>(self);
}

static GfxrReplayPluginResult on_event(GfxrReplayPluginV1* self, const GfxrReplayEventHeader* event)
{
    if (self == NULL)
    {
        GFXRECON_LOG_ERROR("Received NULL plugin instance");
        return GFXR_REPLAY_PLUGIN_RESULT_ERROR;
    }

    if (event == NULL)
    {
        GFXRECON_LOG_ERROR("Received NULL event");
        return GFXR_REPLAY_PLUGIN_RESULT_ERROR;
    }

    GFXRECON_LOG_INFO("Received event type %u at timestamp %llu ns", event->type, event->timestamp_ns);

    SampleReplayPlugin* plugin = reinterpret_cast<SampleReplayPlugin*>(self);
    int half_sleep_ms = plugin->sleep_around_gpu_frame_ms / 2;

    switch (event->type)
    {
        case GFXR_REPLAY_EVENT_QUEUE_SUBMIT_BEGIN:
            if (plugin->first_queue_submit_in_frame)
            {
                if (half_sleep_ms > 0) std::this_thread::sleep_for(std::chrono::milliseconds(half_sleep_ms));
                TraceBeginSection("GFXRFrame");
                if (half_sleep_ms > 0) std::this_thread::sleep_for(std::chrono::milliseconds(half_sleep_ms));
                plugin->first_queue_submit_in_frame = false;
            }
            TraceBeginSection("GFXRQueueSubmit");
            break;
        case GFXR_REPLAY_EVENT_QUEUE_SUBMIT_END:
            TraceEndSection();
            break;
        case GFXR_REPLAY_EVENT_FRAME_BEGIN:
            plugin->first_queue_submit_in_frame = true;
            break;
        case GFXR_REPLAY_EVENT_FRAME_END:
            if (half_sleep_ms > 0) std::this_thread::sleep_for(std::chrono::milliseconds(half_sleep_ms));
            TraceEndSection();
            if (half_sleep_ms > 0) std::this_thread::sleep_for(std::chrono::milliseconds(half_sleep_ms));
            break;
        default:
            break;
    }

    return GFXR_REPLAY_PLUGIN_RESULT_OK;
}

GFXR_REPLAY_PLUGIN_EXPORT GfxrReplayPluginV1* gfxrCreateReplayPluginV1(const GfxrReplayPluginCreateInfo* create_info)
{
    if (create_info == NULL)
    {
        GFXRECON_LOG_ERROR("Create info is NULL");
        return NULL;
    }

    if (create_info->abi_version != GFXR_REPLAY_PLUGIN_ABI_VERSION)
    {
        GFXRECON_LOG_ERROR("Unsupported plugin ABI version %u", create_info->abi_version);
        return NULL;
    }

    if (create_info->struct_size != sizeof(GfxrReplayPluginCreateInfo))
    {
        GFXRECON_LOG_ERROR("Unexpected create info struct size %u", create_info->struct_size);
        return NULL;
    }

    gfxrecon::util::Log::Init();
    GFXRECON_LOG_INFO("Creating sample plugin with params: %s",
                      create_info->plugin_params ? create_info->plugin_params : "null");

    SampleReplayPlugin* plugin = new SampleReplayPlugin;
    plugin->base.abi_version = GFXR_REPLAY_PLUGIN_ABI_VERSION;
    plugin->base.struct_size = sizeof(GfxrReplayPluginV1);
    plugin->base.destroy     = destroy;
    plugin->base.on_event    = on_event;

    if (create_info->plugin_params != nullptr)
    {
        std::string params_str(create_info->plugin_params);
        std::istringstream iss(params_str);
        std::string token;
        std::vector<std::string> args;
        
        while (iss >> token)
        {
            args.push_back(token);
        }
        
        for (size_t i = 0; i < args.size(); ++i)
        {
            if (args[i].find("sleep-around-gpu-frame-ms=") == 0)
            {
                try
                {
                    plugin->sleep_around_gpu_frame_ms = std::stoi(args[i].substr(26));
                }
                catch (...)
                {
                    GFXRECON_LOG_ERROR("Invalid value for sleep-around-gpu-frame-ms: %s", args[i].c_str());
                }
            }
            else if (args[i] == "sleep-around-gpu-frame-ms" && i + 1 < args.size())
            {
                try
                {
                    plugin->sleep_around_gpu_frame_ms = std::stoi(args[i + 1]);
                }
                catch (...)
                {
                    GFXRECON_LOG_ERROR("Invalid value for sleep-around-gpu-frame-ms: %s", args[i + 1].c_str());
                }
                i++; // Skip the value argument
            }
            else
            {
                GFXRECON_LOG_WARNING("Unrecognized plugin parameter: %s", args[i].c_str());
            }
        }
    }

    return &plugin->base;
}
