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

#ifndef GFXRECON_REPLAY_EVENT_PLUGIN_H
#define GFXRECON_REPLAY_EVENT_PLUGIN_H

#include "stdint.h"

#if defined(__GNUC__) && __GNUC__ >= 4
#define GFXR_EXPORT __attribute__((visibility("default")))
#else
#define GFXR_EXPORT
#endif

#define GFXR_REPLAY_PLUGIN_ABI_VERSION 1u
#define GFXR_REPLAY_INVALID_SUBMIT_INDEX UINT64_MAX

typedef enum GfxrReplayEventType : uint32_t
{
    GFXR_REPLAY_EVENT_QUEUE_SUBMIT_BEGIN = 1,
    GFXR_REPLAY_EVENT_QUEUE_SUBMIT_END   = 2,
    GFXR_REPLAY_EVENT_FRAME_BEGIN        = 3,
    GFXR_REPLAY_EVENT_FRAME_END          = 4,
} GfxrReplayEventType;

typedef enum GfxrReplayPluginResult : uint32_t
{
    GFXR_REPLAY_PLUGIN_RESULT_OK    = 0,
    GFXR_REPLAY_PLUGIN_RESULT_ERROR = 1,
} GfxrReplayPluginResult;

typedef enum GfxrReplayQueueSubmitCompletionSource : uint32_t
{
    GFXR_REPLAY_QUEUE_SUBMIT_COMPLETION_SOURCE_SUBMIT_RETURN  = 1,
    GFXR_REPLAY_QUEUE_SUBMIT_COMPLETION_SOURCE_ORIGINAL_FENCE = 2,
    GFXR_REPLAY_QUEUE_SUBMIT_COMPLETION_SOURCE_INJECTED_FENCE = 3,
} GfxrReplayQueueSubmitCompletionSource;

typedef struct GfxrReplayPluginCreateInfo
{
    uint32_t abi_version;
    /* Size in bytes of GfxrReplayPluginCreateInfo. */
    uint32_t struct_size;
    /* Optional opaque null-terminated UTF-8 parameter string. */
    const char* plugin_params;
} GfxrReplayPluginCreateInfo;

typedef struct GfxrReplayEventHeader
{
    uint32_t abi_version;
    /* Size in bytes of the full concrete event struct, not just this header. */
    uint32_t            struct_size;
    GfxrReplayEventType type;
    uint32_t            reserved;
    uint64_t            timestamp_ns;
    uint64_t            frame_index;
} GfxrReplayEventHeader;

typedef struct GfxrReplayQueueSubmitBeginEvent
{
    GfxrReplayEventHeader header;
    uint64_t              submit_index;
    uint64_t              queue_id;
} GfxrReplayQueueSubmitBeginEvent;

typedef struct GfxrReplayQueueSubmitEndEvent
{
    GfxrReplayEventHeader                 header;
    uint64_t                              submit_index;
    uint64_t                              queue_id;
    int32_t                               result;
    GfxrReplayQueueSubmitCompletionSource completion_source;
} GfxrReplayQueueSubmitEndEvent;

typedef struct GfxrReplayFrameBeginEvent
{
    GfxrReplayEventHeader header;
} GfxrReplayFrameBeginEvent;

typedef struct GfxrReplayFrameEndEvent
{
    GfxrReplayEventHeader header;
    uint64_t              first_submit_index;
    uint64_t              last_submit_index;
} GfxrReplayFrameEndEvent;

typedef struct GfxrReplayPluginV1
{
    uint32_t abi_version;
    /* Size in bytes of GfxrReplayPluginV1. */
    uint32_t struct_size;
    void (*destroy)(struct GfxrReplayPluginV1* self);
    /* Points at the start of the full concrete event object. Inspect type and struct_size before casting. */
    GfxrReplayPluginResult (*on_event)(struct GfxrReplayPluginV1* self, const GfxrReplayEventHeader* event);
} GfxrReplayPluginV1;

typedef GfxrReplayPluginV1* (*PFN_gfxrCreateReplayPluginV1)(const GfxrReplayPluginCreateInfo* create_info);

#ifdef __cplusplus
extern "C"
{
#endif

    GfxrReplayPluginV1* GFXR_EXPORT gfxrCreateReplayPluginV1(const GfxrReplayPluginCreateInfo* create_info);

#ifdef __cplusplus
}
#endif

#endif // GFXRECON_REPLAY_EVENT_PLUGIN_H
