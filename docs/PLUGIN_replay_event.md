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
* for `GfxrReplayPluginV1`, `struct_size` is `sizeof(GfxrReplayPluginV1)`
* for events, the `struct_size` field stored in `GfxrReplayEventHeader` is the size of the full event struct being passed to the callback, not the size of `GfxrReplayEventHeader` alone

So for an event callback:

* `GfxrReplayQueueSubmitBeginEvent.header.struct_size == sizeof(GfxrReplayQueueSubmitBeginEvent)`
* `GfxrReplayQueueSubmitEndEvent.header.struct_size == sizeof(GfxrReplayQueueSubmitEndEvent)`
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

typedef struct GfxrReplayQueueSubmitBeginEvent {
    GfxrReplayEventHeader header;
    uint64_t submit_index;
    uint64_t queue_id;
} GfxrReplayQueueSubmitBeginEvent;

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

## ABI Versioning and Compatibility

A replay event plugin is a binary that the customer builds and ships. Replay must load a plugin that the customer built with an older public header. This section gives the rules that keep this true.

### Two Version Levels

The ABI has two version levels. Each level has a different effect on the plugins that already exist.

| Level | Carrier | Changes for | Effect on a plugin that exists |
| :---- | :---- | :---- | :---- |
| Major | the `V1` in `gfxrCreateReplayPluginV1` and `GfxrReplayPluginV1` | a change that breaks the contract | The plugin keeps the old factory symbol. Replay loads it through the old path. |
| Minor | `GFXR_REPLAY_PLUGIN_ABI_VERSION` | a change that only adds | The plugin keeps its behavior. Replay does not emit the new data to it. |

A change that only adds is a new event type, or a new field at the end of an event struct. Every other change breaks the contract.

### Version Negotiation

When replay creates the plugin instance, replay and the plugin agree on one version. This version is the negotiated version. It does not change for the rest of the replay.

The steps are:

1. Replay sets `GfxrReplayPluginCreateInfo.abi_version` to `GFXR_REPLAY_PLUGIN_ABI_VERSION`. This is the newest version that replay knows.
2. The plugin factory function reads that field.
3. The plugin sets `GfxrReplayPluginV1.abi_version` to the lower of two values. The two values are the newest version that the plugin knows, and the value from step 1.
4. When the reported version is in the range from `GFXR_REPLAY_PLUGIN_ABI_MIN_VERSION` to `GFXR_REPLAY_PLUGIN_ABI_VERSION`, the loader accepts the plugin.
5. The negotiated version is the value that the plugin reported in step 3.

Step 3 lets a new plugin run against an older replay. The plugin reports the version that both sides know, in place of a version that replay cannot supply.

Note: the loader accepts only an exact match of the version today. The range test and `GFXR_REPLAY_PLUGIN_ABI_MIN_VERSION` become necessary with the first increase of the version.

### What Replay Emits to an Older Plugin

Replay must not emit an event type that the negotiated version does not contain. A plugin that reports version 1 receives the version 1 event stream and nothing more.

This rule puts the work on replay, not on the plugin. A plugin binary that already exists cannot learn a new rule. Replay is the only side that can change.

Replay holds one table of event types to make this rule mechanical. Each row gives the event type, the size of its struct, and the version that introduced it. The replay sink reads this table. The sink removes each event that the negotiated version does not contain.

CAUTION: Do not emit a new event type to a plugin that reports ABI version 1. The version 1 contract does not tell a plugin to accept an unknown event type. A version 1 plugin can return an error result. Replay then disables the plugin for the full replay.

### Rules for a Plugin

A plugin must obey these rules:

1. Return `GFXR_REPLAY_PLUGIN_RESULT_OK` for an event type that the plugin does not know.
2. Read `header.struct_size` before you read a field that a later version added. When `struct_size` is too small to contain the field, the field is not present.
3. Read `create_info->abi_version` in the factory function. Do not expect an event type that a later version added.
4. Return `GFXR_REPLAY_PLUGIN_RESULT_ERROR` only for an internal failure of the plugin. Replay stops all further events after one error result.

### Rules for a Change to the ABI

These rules apply to every change inside one major version:

* Add a new field only at the end of a struct. Do not insert, move, or resize a field that exists.
* Give a new event type the next unused number. Do not reuse the number of an event type that replay does not emit any more.
* Keep every struct definition that shipped. When an event type becomes obsolete, replay does not emit it any more. The type and its struct stay in the header.
* Keep the `reserved` field in `GfxrReplayEventHeader` at zero. A later version can give this field a meaning.
* When you add to the ABI, increase `GFXR_REPLAY_PLUGIN_ABI_VERSION` by one.
* Add a `static_assert` on the size of each public struct, and on the offset of each field in it. A change to the layout then stops the build.

### When a New Major Version is Necessary

A new major version is necessary for these changes:

* the meaning of a field that exists changes
* a change removes, moves, or resizes a field
* a change removes an event type
* the signature of `on_event` or of the factory function changes
* the failure policy changes

To add a major version, do these steps:

1. Add `GfxrReplayPluginV2` and the factory name `gfxrCreateReplayPluginV2` to the header.
2. Keep the version 1 declarations in the header without a change.
3. Make the loader look for the version 2 symbol first, then for the version 1 symbol.
4. Add a sink that emits only the version 1 event stream to a version 1 plugin.

The internal replay sink makes step 4 small. Replay code emits events to the sink. Replay code does not know which plugin version is behind the sink.

### Procedure to Add an Event Type

To add an event type, do these steps:

1. Add the enumerant to `GfxrReplayEventType` with the next unused number.
2. Add the event struct. Put `GfxrReplayEventHeader` first in it.
3. Add a `static_assert` on the size of the new struct.
4. Increase `GFXR_REPLAY_PLUGIN_ABI_VERSION` by one.
5. Add a row to the event table in replay. Give the size of the struct and the new version.
6. Add a row to the event contract table and to the version history table in this document.
7. Add a test with a plugin that reports the new version. The plugin must receive the new event type.
8. Add a test with a plugin that reports the previous version. The plugin must not receive the new event type.

### Version History

| ABI version | Event types | Changes |
| :---- | :---- | :---- |
| 1 | `QueueSubmitBegin`, `QueueSubmitEnd`, `FrameBegin`, `FrameEnd` | first public version |

Add a row for each increase of `GFXR_REPLAY_PLUGIN_ABI_VERSION`.

## Replay Workflow and Platform Plumbing

The replay-side flow is:

1. Parse a plugin-library path from replay options.
2. On Android, use a plugin-library path that the developer has already staged under the app's
   internal files directory.
3. Load the shared library.
4. Resolve the plugin factory symbol.
5. Create the plugin instance.
6. Install an internal adapter that forwards replay events to the plugin.
7. Emit queue-submit and frame events during replay.
8. Destroy the plugin cleanly during replay shutdown.

The replay consumer should know only about an internal replay sink. It should not know about shared-library loading, symbol resolution, platform-specific loader APIs, or plugin object lifetime rules. The loader layer is responsible for creating a plugin, wrapping it as a replay sink, and installing that sink into replay.

The replay option should be shared across desktop and Android:

```
--replay-event-plugin-path /path/to/libcustomer_replay_event_plugin.so
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
* for security reasons, the developer explicitly stages the plugin library into the app's internal
  files directory and passes that staged absolute path
* failure diagnostics must be visible in normal replay logging and logcat

The Android staging workflow assumes a debuggable replay APK because it uses `run-as`.
Set the package name, local plugin path, and plugin file name on the host first:

```bash
export PKG="com.lunarg.gfxreconstruct.replay"
export SO="/path/to/libcustomer_replay_event_plugin.so"
export PLUGIN_NAME="$(basename "$SO")"
```

Confirm the app-internal base directory. This is the directory that replay can access as
the app user:

```bash
adb shell run-as "$PKG" pwd
```

Create an app-internal directory for replay event plugins:

```bash
adb shell run-as "$PKG" mkdir -p files/plugins
```

Push the local shared library to a temporary device path that `adb push` can write:

```bash
adb push "$SO" "/data/local/tmp/$PLUGIN_NAME"
```

Make the temporary copy readable so the app user can copy it:

```bash
adb shell chmod 0644 "/data/local/tmp/$PLUGIN_NAME"
```

Copy the temporary library into the replay app's internal `files/plugins` directory:

```bash
adb shell run-as "$PKG" cp "/data/local/tmp/$PLUGIN_NAME" "files/plugins/$PLUGIN_NAME"
```

Remove the temporary world-readable copy after it has been staged:

```bash
adb shell rm "/data/local/tmp/$PLUGIN_NAME"
```

Restrict the staged plugin library to the app user:

```bash
adb shell run-as "$PKG" chmod 0600 "files/plugins/$PLUGIN_NAME"
```

Verify the staged library path and permissions:

```bash
adb shell run-as "$PKG" ls -l "files/plugins/$PLUGIN_NAME"
```

Capture the absolute app-internal directory path on the host and build the plugin path
to pass to replay:

```bash
export APP_DIR="$(adb shell run-as "$PKG" pwd | tr -d '\r')"
export PLUGIN_PATH="${APP_DIR}/files/plugins/${PLUGIN_NAME}"
echo "$PLUGIN_PATH"
```

Start replay with the staged plugin path through the existing Android `args` extra:

```bash
adb shell am start ... --es args "--replay-event-plugin-path $PLUGIN_PATH ..."
```
