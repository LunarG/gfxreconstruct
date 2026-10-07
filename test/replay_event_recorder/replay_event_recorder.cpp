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

/*
** A replay event plugin that appends every event it receives to a text file. The file to write is
** given by --replay-event-plugin-params.
**
** Each event becomes one line of whitespace separated key=value pairs: the fields carried by every
** event header, followed by the fields of that particular event struct.
**
**     type=2 abi=3 size=48 frame=1 timestamp_ns=94518200 submit_index=3 queue_id=1 result=0 completion_source=1
*/

#include <gfxr/replay_event_plugin.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct RecorderPlugin
{
    GfxrReplayPluginV1 base;
    FILE*              output;
} RecorderPlugin;

static void destroy(GfxrReplayPluginV1* self)
{
    RecorderPlugin* recorder = (RecorderPlugin*)self;
    if (recorder == NULL)
    {
        return;
    }

    if (recorder->output != NULL)
    {
        fclose(recorder->output);
    }

    /* Allocated by this library, so it is freed by this library. */
    free(recorder);
}

static void append_unsigned(FILE* output, const char* key, uint64_t value)
{
    fprintf(output, " %s=%llu", key, (unsigned long long)value);
}

static void append_signed(FILE* output, const char* key, int64_t value)
{
    fprintf(output, " %s=%lld", key, (long long)value);
}

static void append_payload(FILE* output, const GfxrReplayEventHeader* event)
{
    switch (event->type)
    {
        case GFXR_REPLAY_EVENT_QUEUE_SUBMIT_BEGIN:
        {
            const GfxrReplayQueueSubmitBeginEvent* submit_begin = (const GfxrReplayQueueSubmitBeginEvent*)event;

            append_unsigned(output, "submit_index", submit_begin->submit_index);
            append_unsigned(output, "queue_id", submit_begin->queue_id);
            break;
        }

        case GFXR_REPLAY_EVENT_QUEUE_SUBMIT_END:
        {
            const GfxrReplayQueueSubmitEndEvent* submit_end = (const GfxrReplayQueueSubmitEndEvent*)event;

            append_unsigned(output, "submit_index", submit_end->submit_index);
            append_unsigned(output, "queue_id", submit_end->queue_id);
            // VkResult, is negative for a Vulkan error
            append_signed(output, "result", submit_end->result);
            append_unsigned(output, "completion_source", submit_end->completion_source);
            break;
        }

        case GFXR_REPLAY_EVENT_FRAME_END:
        {
            const GfxrReplayFrameEndEvent* frame_end = (const GfxrReplayFrameEndEvent*)event;

            append_unsigned(output, "first_submit_index", frame_end->first_submit_index);
            append_unsigned(output, "last_submit_index", frame_end->last_submit_index);
            break;
        }

        case GFXR_REPLAY_EVENT_WAIT_BEGIN:
        {
            const GfxrReplayWaitBeginEvent* wait_begin = (const GfxrReplayWaitBeginEvent*)event;

            append_unsigned(output, "requested_duration_ms", wait_begin->requested_duration_ms);
            break;
        }

        // These carry nothing beyond the header
        case GFXR_REPLAY_EVENT_FRAME_BEGIN:
        case GFXR_REPLAY_EVENT_STATE_SETUP_BEGIN:
        case GFXR_REPLAY_EVENT_STATE_SETUP_END:
        case GFXR_REPLAY_EVENT_WAIT_END:
            break;

        // Unknown event types such as from a newer ABI
        default:
            append_unsigned(output, "unknown_type", 1);
            break;
    }
}

static GfxrReplayPluginResult on_event(GfxrReplayPluginV1* self, const GfxrReplayEventHeader* event)
{
    RecorderPlugin* recorder = (RecorderPlugin*)self;
    if ((recorder == NULL) || (recorder->output == NULL) || (event == NULL))
    {
        return GFXR_REPLAY_PLUGIN_RESULT_ERROR;
    }

    fprintf(recorder->output, "type=%u", (unsigned int)event->type);
    append_unsigned(recorder->output, "abi", event->abi_version);
    append_unsigned(recorder->output, "size", event->struct_size);
    append_unsigned(recorder->output, "frame", event->frame_index);
    append_unsigned(recorder->output, "timestamp_ns", event->timestamp_ns);

    append_payload(recorder->output, event);

    fputc('\n', recorder->output);

    fflush(recorder->output);

    return GFXR_REPLAY_PLUGIN_RESULT_OK;
}

GFXR_REPLAY_PLUGIN_EXPORT GfxrReplayPluginV1* gfxrCreateReplayPluginV1(const GfxrReplayPluginCreateInfo* create_info)
{
    if ((create_info == NULL) || (create_info->struct_size != sizeof(GfxrReplayPluginCreateInfo)) ||
        (create_info->abi_version != GFXR_REPLAY_PLUGIN_ABI_VERSION))
    {
        return NULL;
    }

    if ((create_info->plugin_params == NULL) || (create_info->plugin_params[0] == '\0'))
    {
        fprintf(stderr, "replay event recorder: --replay-event-plugin-params must name an output file\n");
        return NULL;
    }

    RecorderPlugin* recorder = (RecorderPlugin*)calloc(1, sizeof(RecorderPlugin));
    if (recorder == NULL)
    {
        return NULL;
    }

    recorder->output = fopen(create_info->plugin_params, "w");
    if (recorder->output == NULL)
    {
        fprintf(stderr, "replay event recorder: failed to open '%s' for writing\n", create_info->plugin_params);
        free(recorder);
        return NULL;
    }

    recorder->base.abi_version = GFXR_REPLAY_PLUGIN_ABI_VERSION;
    recorder->base.struct_size = sizeof(GfxrReplayPluginV1);
    recorder->base.destroy     = destroy;
    recorder->base.on_event    = on_event;

    return &recorder->base;
}
