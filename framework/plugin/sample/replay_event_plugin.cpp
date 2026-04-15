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

#include <stdio.h>

static void destroy(GfxrReplayPluginV1* self)
{
    if (self == NULL)
    {
        printf("Received NULL plugin instance\n");
        return;
    }

    printf("Destroying plugin\n");
}

static GfxrReplayPluginResult on_event(GfxrReplayPluginV1* self, const GfxrReplayEventHeader* event)
{
    if (self == NULL)
    {
        printf("Received NULL plugin instance\n");
        return GFXR_REPLAY_PLUGIN_RESULT_ERROR;
    }

    if (event == NULL)
    {
        printf("Received NULL event\n");
        return GFXR_REPLAY_PLUGIN_RESULT_ERROR;
    }

    printf("Received event type %u at timestamp %llu ns\n", event->type, event->timestamp_ns);
    return GFXR_REPLAY_PLUGIN_RESULT_OK;
}

static GfxrReplayPluginV1 plugin = {
    GFXR_REPLAY_PLUGIN_ABI_VERSION,
    sizeof(GfxrReplayPluginV1),
    destroy,
    on_event,
};

GFXR_EXPORT GfxrReplayPluginV1* gfxrCreateReplayPluginV1(const GfxrReplayPluginCreateInfo* create_info)
{
    if (create_info == NULL)
    {
        printf("Create info is NULL\n");
        return NULL;
    }

    if (create_info->abi_version != GFXR_REPLAY_PLUGIN_ABI_VERSION)
    {
        printf("Unsupported plugin ABI version %u\n", create_info->abi_version);
        return NULL;
    }

    if (create_info->struct_size != sizeof(GfxrReplayPluginCreateInfo))
    {
        printf("Unexpected create info struct size %u\n", create_info->struct_size);
        return NULL;
    }

    return &plugin;
}
