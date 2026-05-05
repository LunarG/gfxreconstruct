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

static void destroy(GfxrReplayPluginV1* self)
{
    if (self == NULL)
    {
        GFXRECON_LOG_ERROR("Received NULL plugin instance");
        return;
    }

    GFXRECON_LOG_INFO("Destroying plugin");
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
    return GFXR_REPLAY_PLUGIN_RESULT_OK;
}

static GfxrReplayPluginV1 plugin = {
    GFXR_REPLAY_PLUGIN_ABI_VERSION,
    sizeof(GfxrReplayPluginV1),
    destroy,
    on_event,
};

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

    return &plugin;
}
