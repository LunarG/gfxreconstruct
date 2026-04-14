<!-- markdownlint-disable MD033 -->
<!-- markdownlint-disable MD041 -->
<p align="left"><img src="https://vulkan.lunarg.com/img/NewLunarGLogoBlack.png" alt="LunarG" width=263 height=113 /></p>

[![Creative Commons][1]][2]

[1]: https://i.creativecommons.org/l/by-nd/4.0/88x31.png "Creative Commons License"
[2]: https://creativecommons.org/licenses/by-nd/4.0/

Copyright &copy; 2026 LunarG, Inc.

# GFXReconstruct Replay Event Plugins - Vulkan

***This document defines the v1 contract and implementation sequence for replay-side event plugins for Vulkan replay on desktop and Android.***

The goal is to let an external module observe replay frame- and submit-related events without requiring the module to embed gfxreconstruct as a library.

## Purpose

This feature allows users to replay captures with `gfxrecon-replay` or `replay-debug.apk` and route replay events to an external module. Profiling is the primary motivating example, such as a Perfetto-based workflow, but the same event interface can support other observer-style integrations.

The event-plugin interface described here is intended to:

* report frame-related replay events  
* report queue-submit-related replay events  
* keep gfxreconstruct replay generic and tool-agnostic  
* allow use of the replay application rather than forcing library embedding

Examples of non-profiling uses include:

* structured replay-event logging  
* benchmark or telemetry collection  
* replay timeline export  
* event streaming to an external process  
* custom diagnostics or regression instrumentation

## Scope

This document covers Vulkan replay on desktop and Android and uses an external event-plugin model loaded by the replay application.

This document does not propose:

* Perfetto-specific code inside gfxreconstruct core  
* exact completion tracking below the granularity of a replayed `vkQueueSubmit*` call  
* forcing customers to use gfxreconstruct as an in-process library  
* a fully general replay plugin system that can arbitrarily modify replay behavior

## Requirements

gfxreconstruct replay shall support loading a customer-supplied replay event plugin library from a path provided at launch time, and shall invoke generic frame- and submit-related callbacks from replay so the customer can consume those events without embedding gfxreconstruct as a library.

The first implementation shall support the following minimum event set:

1. `QueueSubmitBegin`  
2. `QueueSubmitEnd`  
3. `FrameBegin`  
4. `FrameEnd`

The plugin loading interface shall use a narrow C ABI.

Replay shall also support:

* An optional opaque plugin-parameter string passed unchanged to the plugin factory  
* An opt-in `--sync` mode that moves `QueueSubmitEnd` from submit-return timing to queue-wait-idle completion timing when replay can wait successfully.

Replay behavior shall remain unchanged when no plugin is configured.

Plugin integration failure shall fail open by default:

* log a clear error  
* disable plugin integration  
* continue replay when possible

## Integration Model

The replay executable remains the main entry point.

The integration model is:

1. The user launches replay with a path to a customer-owned plugin library.  
2. Replay loads that shared library at startup.  
3. Replay resolves a small C ABI factory function.  
4. Replay creates a plugin instance and adapts it to an internal replay sink.  
5. Replay emits generic replay events through that sink.  
6. The plugin implementation translates those generic events into tool-specific external behavior.

This keeps the separation of responsibilities clear:

* gfxreconstruct owns replay state, event timing, and the generic ABI  
* the customer owns the external plugin implementation

In this document, a **replay sink** is the internal replay-side event interface that receives replay events from replay code. Replay code emits events to the sink without knowing whether the sink is:

* a loaded plugin adapter  
* a null implementation that drops all events  
* a future test sink or logging sink

The replay sink is not the public plugin ABI. It is an internal seam inside replay that keeps replay logic independent from shared-library loading, symbol resolution, and any particular external integration.

## Event Contract

The v1 event set and emission points are fixed as follows:

| Event | Emitted when | Not emitted when | Minimum payload fields |
| :---- | :---- | :---- | :---- |
| `QueueSubmitBegin` | Immediately before replay calls `vkQueueSubmit`, `vkQueueSubmit2`, `vkQueueSubmit2KHR.`In case of error, a `QueueSubmitEnd` failed event is emitted. | If replay never submits to a queue | `timestamp_ns`, `frame_index`, `submit_index`, `queue_id` |
| `QueueSubmitEnd` | Immediately after `vkQueueSubmit`, `vkQueueSubmit2`, `vkQueueSubmit2KHR` or, when `--sync` is enabled, immediately after replay waits for the gpu to become idle with `vkQueueWaitIdle()` | If replay never submits to a queue | `timestamp_ns`, `frame_index`, `submit_index`, `queue_id`, `completion_source, result` |
| `FrameBegin` | Explicitly when the first replayed frame becomes active, and explicitly when each later replayed frame becomes active according to replay frame-boundary semantics | If replay never activates that frame | `timestamp_ns`, `frame_index` |
| `FrameEnd` | Explicitly when replay reaches the frame boundary according to replay frame-boundary semantics | If replay never reaches the boundary for that frame | `timestamp_ns`, `frame_index`, `first_submit_index`, `last_submit_index` |

For v1, every attempted replay submit emits `QueueSubmitBegin` followed by exactly one `QueueSubmitEnd`. The completion event reports whether replay stopped at submit return or at queue-wait-idle completion point, and it carries the associated `VkResult`.

## Event Semantics

### QueueSubmitBegin

`QueueSubmitBegin` is a replay CPU-side event. It is emitted immediately before replay calls `vkQueueSubmit*`, not after the call and not at GPU completion.

This event is intended for:

* CPU-side timing between replay submit points  
* optional plugin-controlled delay injection before replay hands work to the queue  
* correlation of replay submit order with external traces

The event carries the global zero-based replay `submit_index`, which does not reset at frame boundaries, and the opaque stable `queue_id`, which is the queue's capture-side handle ID rather than the raw replay `VkQueue` handle value.

### QueueSubmitEnd

`QueueSubmitEnd` is emitted exactly once for each `QueueSubmitBegin`.

By default, replay emits `QueueSubmitEnd` immediately after `vkQueueSubmit*` returns. In that mode, `completion_source` is `GFXR_REPLAY_QUEUE_SUBMIT_COMPLETION_SOURCE_SUBMIT_RETURN`, and `result` is the returned `VkResult` from `vkQueueSubmit*`.

When `--sync` is enabled and the submit returns `VK_SUCCESS`, replay waits for the queue to become idle before emitting the event.

When `--sync` is enabled and replay waits successfully, this gives exact completion at the granularity of the replayed `vkQueueSubmit*` call. It does not distinguish individual `VkSubmitInfo` elements within a multi-submit call.

This design has important implications:

* replay becomes more serialized because the host waits after each successful submit  
* this changes later host-observed timing, even though the captured command stream itself is unchanged  

This event is intended for:

* A post-submit marker for every replay submit attempt  
* An exact completion marker for the replayed submit call when `--sync` is enabled and replay waits for the queue to become idle successfully
* correlation of replay submit order with a queue-wait-idle completion point

### FrameBegin

`FrameBegin` is explicit for the first replayed frame and for every later replayed frame. It is not inferred from the first submit.

Frame start and end must follow replay's existing frame-boundary machinery rather than introducing a plugin-only frame model.

This event is intended for:

* frame-level correlation in external traces  
* measuring replay work grouped by replay frame  
* support for frames that contain zero submits

`frame_index` is replay-local and zero-based. The first replayed frame is `0`, even when replay starts from trimmed state or otherwise does not begin at capture frame `0`.

### FrameEnd

`FrameEnd` is emitted when replay reaches the frame boundary according to replay frame-boundary semantics. It carries the first and last submit indices associated with that replay frame, or the invalid submit sentinel when the frame contains no submits.

This event is intended for:

* frame duration visualization  
* association of submit ranges with a replay frame

## Indexing and Sentinel Values

The event-plugin contract defines its own indexing semantics. These indices do not need to match existing internal helper counters or capture frame numbers.

The v1 rules are:

* `frame_index` is replay-local and zero-based  
* `submit_index` is global across the whole replay and zero-based  
* `GFXR_REPLAY_INVALID_SUBMIT_INDEX` is defined as `UINT64_MAX`  
* `queue_id` is the queue's capture-side handle ID expressed as an opaque stable identifier  
* `QueueSubmitEnd` is exact at the granularity of the replayed `vkQueueSubmit*` call only when `--sync` is enabled and replay waits for the queue to become idle successfully; otherwise it marks the replay CPU-side end of the submit attempt.

The invalid submit sentinel is used as follows:

* `FrameEnd` sets both fields to `GFXR_REPLAY_INVALID_SUBMIT_INDEX` when the frame contains no submits  
* queue-submit events always carry a valid zero-based `submit_index`

## Plugin Lifecycle and Failure Policy

The v1 plugin lifecycle is:

1. replay makes sure the shared library is copied to its package folder  
2. replay loads the shared library  
3. replay resolves the plugin factory symbol  
4. replay creates the plugin instance  
5. replay invokes the plugin event callback during replay  
6. replay destroys the plugin instance during shutdown or plugin teardown

The plugin's create-time configuration is carried by the opaque parameter string in `GfxrReplayPluginCreateInfo`.

Failure policy is:

* if the plugin option is absent, plugin integration is disabled and replay proceeds unchanged  
* if shared-library loading fails, replay logs the failure, disables plugin integration, and continues replay  
* if symbol lookup fails, replay logs the failure, disables plugin integration, and continues replay  
* if plugin creation fails, replay logs the failure, disables plugin integration, and continues replay  
* if the plugin event callback reports an error, replay logs once, disables plugin integration, and continues replay  
* if plugin code crashes the process, gfxreconstruct does not guarantee containment or recovery

## Public Plugin ABI

The v1 ABI should be intentionally small and stable.

In this document, an event consists of:

* a common event header shared by all event types  
* an event payload, which is the event-type-specific data carried in addition to that header

Public event delivery uses a single generic callback. Replay passes a pointer to the common header at the start of the full concrete event object. A plugin inspects `type` and `struct_size`, then casts the same address to the matching concrete event type when it recognizes that event.

For example:

* queue-submit events carry submit-specific payload fields such as `submit_index`, `queue_id`, and `completion_source`  
* frame end event carries frame-specific payload fields such as `first_submit_index` and `last_submit_index`

Every top-level ABI struct also carries a `struct_size` field. `struct_size` is the size in bytes of the full concrete struct instance crossing the ABI boundary.

Examples:

* for `GfxrReplayPluginCreateInfo`, `struct_size` is `sizeof(GfxrReplayPluginCreateInfo)`  
* for `GfxrReplayPluginV1`, `struct_size` is `sizeof> (GfxrReplayPluginV1)`  
* for events, the `struct_size` field stored in `GfxrReplayEventHeader` is the size of the full event struct being passed to the callback, not the size of `GfxrReplayEventHeader` alone

So for an event callback:

* `GfxrReplayQueueSubmitBeginEvent.header.struct_size == sizeof(GfxrReplayQueueSubmitBeginEvent)`
* `GfxrReplayQueueSubmitEndEvent.header.struct_size == sizeof (GfxrReplayQueueSubmitEndEvent)`
* `GfxrReplayFrameBeginEvent.header.struct_size == sizeof(GfxrReplayFrameBeginEvent)`
* `GfxrReplayFrameEndEvent.header.struct_size == sizeof(GfxrReplayFrameEndEvent)`

This is used for ABI compatibility and future extension. A plugin can verify that the struct it received is at least as large as the fields it expects before reading newer trailing fields.

Design constraints:

* C-compatible  
* fixed-size integer types  
* POD event payloads  
* no C++ exceptions across the boundary  
* no STL types across the boundary  
* explicit ABI versioning  
* no strings in event payloads for v1

The recommended v1 shape is:

* one ABI version constant  
* one invalid submit sentinel constant  
* one plugin factory symbol  
* one plugin object with a destroy callback and one generic event callback  
* one optional create-time UTF-8 parameter string  
* one result enum for callback success or failure  
* one completion-source enum for queue-submit completion semantics  
* one common event header shared by all event payloads and used for event dispatch  
* queue-submit event structs carrying submit-specific payload fields  
* frame event structs carrying frame-specific payload fields  
* a size or version field in every top-level struct that crosses the ABI

For v1, `queue_id` is an opaque stable identifier sourced from the queue's capture-side handle ID.

Illustrative ABI skeleton:

```c
#define GFXR_REPLAY_PLUGIN_ABI_VERSION 1u
#define GFXR_REPLAY_INVALID_SUBMIT_INDEX UINT64_MAX

typedef enum GfxrReplayEventType {
    GFXR_REPLAY_EVENT_QUEUE_SUBMIT_BEGIN = 1,
    GFXR_REPLAY_EVENT_QUEUE_SUBMIT_END = 2,
    GFXR_REPLAY_EVENT_FRAME_BEGIN = 3,
    GFXR_REPLAY_EVENT_FRAME_END = 4,
} GfxrReplayEventType;

typedef enum GfxrReplayPluginResult {
    GFXR_REPLAY_PLUGIN_RESULT_OK = 0,
    GFXR_REPLAY_PLUGIN_RESULT_ERROR = 1,
} GfxrReplayPluginResult;

typedef enum GfxrReplayQueueSubmitCompletionSource {
    GFXR_REPLAY_QUEUE_SUBMIT_COMPLETION_SOURCE_SUBMIT_RETURN = 1,
    GFXR_REPLAY_QUEUE_SUBMIT_COMPLETION_SOURCE_QUEUE_IDLE = 2,
} GfxrReplayQueueSubmitCompletionSource;

typedef struct GfxrReplayPluginCreateInfo {
    uint32_t abi_version;
    /* Size in bytes of GfxrReplayPluginCreateInfo. */
    uint32_t struct_size;
    /* Optional opaque null-terminated UTF-8 parameter string. */
    const char* plugin_params;
} GfxrReplayPluginCreateInfo;

typedef struct GfxrReplayEventHeader {
    uint32_t abi_version;
    /* Size in bytes of the full concrete event struct, not just this header. */
    uint32_t struct_size;
    uint32_t type;
    uint32_t reserved;
    uint64_t timestamp_ns;
    uint64_t frame_index;
} GfxrReplayEventHeader;

typedef struct GfxrReplayQueueSubmitEvent {
    GfxrReplayEventHeader header;
    uint64_t submit_index;
    uint64_t queue_id;
} GfxrReplayQueueSubmitEvent;

typedef struct GfxrReplayQueueSubmitEndEvent {
    GfxrReplayEventHeader header;
    uint64_t submit_index;
    uint64_t queue_id;
    int32_t result;
    uint32_t completion_source;
} GfxrReplayQueueSubmitEndEvent;

typedef struct GfxrReplayFrameBeginEvent {
    GfxrReplayEventHeader header;
} GfxrReplayFrameBeginEvent;

typedef struct GfxrReplayFrameEndEvent {
    GfxrReplayEventHeader header;
    uint64_t first_submit_index;
    uint64_t last_submit_index;
} GfxrReplayFrameEndEvent;

typedef struct GfxrReplayPluginV1 {
    uint32_t abi_version;
    /* Size in bytes of GfxrReplayPluginV1. */
    uint32_t struct_size;
    void (*destroy)(struct GfxrReplayPluginV1* self);
    /* Points at the start of the full concrete event object. Inspect type and struct_size before casting. */
    GfxrReplayPluginResult (*on_event)(struct GfxrReplayPluginV1* self,
                                       const GfxrReplayEventHeader* event);
} GfxrReplayPluginV1;

typedef GfxrReplayPluginV1* (*PFN_gfxrCreateReplayPluginV1)(const GfxrReplayPluginCreateInfo* create_info);
```

This sketch is intentionally narrow. The eventual public header should stay materially equivalent to this shape unless the contract above changes.

## Replay Workflow and Platform Plumbing

The replay-side flow is:

1. Parse a plugin-library path from replay options.  
2. On Android, copy any externally supplied plugin library into package-visible app storage and use that copied absolute path for loading.  
3. Load the shared library.  
4. Resolve the plugin factory symbol.  
5. Create the plugin instance.  
6. Install an internal adapter that forwards replay events to the plugin.  
7. Emit queue-submit and frame events during replay.  
8. Destroy the plugin cleanly during replay shutdown.

The replay consumer should know only about an internal replay sink. It should not know about shared-library loading, symbol resolution, platform-specific loader APIs, or plugin object lifetime rules. The loader layer is responsible for creating a plugin, wrapping it as a replay sink, and installing that sink into replay.

The replay option should be shared across desktop and Android:

```
--replay-event-plugin /path/to/libcustomer_replay_event_plugin.so
--replay-event-plugin-params "--test 100"
--sync
```

Desktop expectations:

* the option is passed directly to `gfxrecon-replay`  
* the optional parameter string is passed unchanged into `GfxrReplayPluginCreateInfo.plugin_params`   
* if loading fails, replay logs the failure and continues without plugin integration

Android expectations:

* `replay-debug.apk` reuses the existing replay argument path rather than inventing a second mechanism  
* the plugin path is passed through the existing `args` intent extra parsed by `tools/replay/android_main.cpp`  
* if the plugin library originates outside package-visible storage, the launcher copies it into `getFilesDir()` or an equivalent app-private directory first and passes that copied absolute path  
* failure diagnostics must be visible in normal replay logging and logcat
