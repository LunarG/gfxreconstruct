# Remote Replay Protocol

> This protocol is in development and not yet stable; message types, field
> names, and CLI options may still change.

## Overview

`gfxrecon-replay` can connect to a controller process over a socket for
bidirectional I/O. The controller supplies replay settings and replay reports
back over the same socket; [Message Schema](#message-schema) lists what each side
sends.

The core abstraction is `util::RemoteChannel`
([framework/util/remote_channel.h](../framework/util/remote_channel.h)).

## Transport

| Environment | Transport | Example address |
|---|---|---|
| Any (Windows, Linux, macOS, Android) | TCP | `tcp:localhost:9001` |
| Android / Linux | Abstract Unix domain socket | `unix:@gfxrecon` |
| Linux / macOS | Filesystem Unix domain socket | `unix:/tmp/gfxrecon.sock` |

Windows targets speak TCP only: there is no abstract namespace, and the
controller has no `AF_UNIX` support there either. A `unix:` address on Windows
is rejected with an error rather than silently falling back.

Replay can establish the socket in either direction; the wire protocol is
identical once the socket exists:

- **`--remote-connect <address>`** — replay is the client, dialing out to a
  listening controller.
- **`--remote-listen <address>`** — replay is the server, accepting one
  controller that dials in. Waits up to 30 seconds for the connection.

The two options are mutually exclusive (specifying both is a fatal error). If a
remote option is set but the channel cannot be established (connection failure or
accept timeout), replay exits with failure and does not fall back to local
playback. Local CLI args are used only when neither remote option is present.

On Android these can be bridged to the PC over adb:

- `--remote-connect`: `adb reverse localabstract:gfxrecon tcp:<port>` (adbd
  binds the abstract name on the device).
- `--remote-listen`: `adb forward tcp:<port> localabstract:gfxrecon` (adbd only
  connects to the name).

## Wire Format

Every frame is a length-prefixed byte string:

```
[uint32_t little-endian length][payload bytes]
```

- All target devices are little-endian; no byte-swapping is performed.
- Frames from the controller are limited to 1 MiB, except the contents of an
  [input file](#input-files); a larger length prefix is treated as the
  controller closing the connection. Frames from replay have no size limit.
- Structured messages are UTF-8 JSON payloads. These could be migrated to a binary format such as protobuf or even GFXR's own encode/decode machinery.
- Replay replaces invalid UTF-8 in a string value it sends, such as a log line
  or a non-UTF-8 file name, with U+FFFD.
- Binary file payloads are sent as a JSON `"file"` metadata frame **immediately
  followed** by a separate raw binary frame (no base64). After a `"file"`
  message the receiver treats the next frame as raw bytes.

## Startup Handshake

```
replay     → controller:  {"type":"hello","version":"1"}
controller → replay:      {"type":"file","name":"dr.json","size":812}   (0..N, optional)
                          <812 raw bytes: separate binary frame, no encoding>
controller → replay:      {"type":"settings","options":{
                            "dump_resources":"dr.json",
                            "capture_file":"/sdcard/capture.gfxr"}}
replay     → controller:  {"type":"ready"}
[replay runs]
```

- Replay sends `hello` first regardless of which side dialed.
- `options` is a set of replay settings, from which replay rebuilds its
  `ArgumentParser`. It completely replaces the traditional command-line
  arguments. See [Settings Keys](#settings-keys).
- Any `file` messages precede `settings`, which ends the controller's opening
  turn. There is no file count or terminator. See [Input Files](#input-files).
- Replay fails to start if the controller goes silent for 5 seconds before
  `settings` arrives.

## Message Schema

### Controller → replay

```json
{"type":"file","name":"dr.json","size":812}   // handshake only, before "settings"
<812 raw bytes: separate binary frame, no encoding>
{"type":"settings","options":{"<key>":"<value>", ...}}
{"type":"control","action":"pause"}   // "pause" | "resume" | "step" | "stop"
```

### Replay → controller

```json
{"type":"log","level":"info","message":"..."}
{"type":"status","state":"running","frame":42,"block":1234}
{"type":"progress","operation":"dump_resources","current":37,"total":90}
{"type":"file","name":"dump/frame_0042.png","size":204800,"meta":{...}}
<204800 raw bytes — separate binary frame, no encoding>
{"type":"done","success":true}
```

`log` carries one line of replay's log output. `message` is the line exactly as
replay writes it to its console, prefix included, so it follows the log settings
the controller sent. `level` is one of `verbose`, `debug`, `info`, `warning`,
`error`, or `fatal`. Console output that the log level does not filter, such as
usage text, is sent as `info` regardless of `--log-level`; a controller that
filters by level will hide it.

`done` is the final message. Replay then half-closes the connection and waits up
to 2 seconds for the controller to close its end before closing its own; the
controller should close once it has read `done`. Closing first could reset the
connection and discard a `done` the controller has not read yet. `success`
reports whether replay ran without error; a `stop` from the controller is not a
failure.

`meta` is optional; see [File Metadata](#file-metadata).

## Settings Keys

The `settings` message carries option name/value pairs rather than a command
line, so a value containing spaces needs no escaping.

**Keys derive from replay's option spellings**: strip the leading dashes and
replace `-` with `_`. There is no mapping table to maintain.

| Command line | Key |
|---|---|
| `--loop-count` | `loop_count` |
| `--mfr`, `--measurement-frame-range` | `mfr`, `measurement_frame_range` |

Any alias works; the long form is canonical. Derived spellings are not accepted
on the command line — `--log_level` is still an error there.

**The capture file** has no spelling to derive, so it takes the key
`capture_file`. Replay accepts exactly one.

**Values are always strings**, never coerced; a non-string JSON value fails the
handshake. `--cpu-mask 0011` sent as a number would arrive as a different mask.

**Options taking no command-line value** use `"true"` / `"false"`. Accepted
spellings are those `util::ParseBoolString` recognizes — `true` / `false` in any
case, or an integer string. Anything else is an error naming the key.

An unknown key is also an error naming the key, reported as received rather than
re-normalized, and fails the handshake instead of printing usage text.

The same payload shape will carry capture-side settings, whose native model is
already a `<string, string>` map. The key sets are disjoint; the shape is not.

## Status and Progress

`{"type":"status","state":S,"frame":N,"block":B}` is a complete snapshot of
replay's state, sent after each replayed frame and whenever `state` changes.
`state` is `running` or `paused`, whatever caused the change (keyboard,
controller, or Android focus); controllers should tolerate values they do not
recognize.

`frame` and `block` are monotonic positions, not fractions: the capture file
carries no total frame or block count, so no percentage is reported. A
percentage would require a total stamped at capture time (a future capture-side
addition) or a full pre-scan, which is impossible for a streamed capture. Use
`block` for a finer-grained position and rate than `frame` alone.

Only state owned by the tool's main loop belongs in `status`. A subsystem
reports through a message of its own, such as `progress`.

`{"type":"progress","operation":<op>,"current":X,"total":Y}` reports a bounded
operation with a running total. Used by dump-resources, where `total` is the sum
of all targeted commands (draw + dispatch + trace-rays + transfer). The count is
a best-effort measure of work done against work targeted: a target that is never
found or a dump that fails leaves `current` short of `total`.

## Playback Controls

Control actions (`pause` / `resume` / `step` / `stop`) are received on replay's
receiver thread and queued. The replay thread applies them at replayed-frame
boundaries, so an action arriving mid-frame takes effect when that frame
finishes; a frame with dump-resources targets can take a long time. `step`
replays one frame and is ignored unless replay is paused. While paused, replay
waits on the control queue in 10 ms intervals rather than blocking on window
events, since a remote session may have nobody at the device. Each pause,
resume, and step is reflected in the next `status` message.

Closing the connection, including closing only the controller's write side,
ends the session: replay stops at the next replayed-frame boundary and exits
with failure.

## Input Files

Paths in `settings` resolve on the replay device's filesystem. For these
options the controller can instead push the file during the handshake and set
the option's value to the pushed `name`:

| Setting | Contents |
|---|---|
| `dump_resources` | dump-resources JSON |
| `frame_warm_up_spirv` | SPIR-V module |
| `load_pipeline_cache` | pipeline cache blob |

- A `file` message is valid only before `settings`. Afterwards replay ignores
  it, and its binary frame is subject to the 1 MiB frame limit.
- `size` must equal the binary frame's length prefix, so a file is at most
  2^32 - 1 bytes.
- `name` must be a bare filename and is matched literally against the option's
  value. Keep the extension: `--dump-resources` selects its parser by the
  `.json` suffix.
- An option value that matches no pushed `name` is a device path as usual. A
  pushed file takes precedence over a same-named file on the device.
- A malformed transfer fails the handshake.
- How replay stores a pushed file is unspecified.

Not covered: `--replace-shaders`, `--replay-event-plugin-path`, and the capture
file.

## File Streaming

When a channel is active (`RemoteChannel::IsActive()`), file writers stream their
output over the socket instead of writing to disk, using process-wide statics
(`SetActiveChannel` / `SendActiveFile`). Writers open their output with
`util::OpenOutputFile()`, which returns a `FileOutputStream` normally and, with a
channel active, a memory stream that sends the whole file as one "file" message
when it is destroyed:

- Screenshots and dump-resources images: `image_writer.cpp`.
- Screenshot results JSON (`--screenshot-results`): `vulkan_screenshot_json.cpp`.
- Dump-resources buffers: `buffer_writer.cpp`.
- Dump-resources JSON: `vulkan_replay_dump_resources_json.cpp`.

Once a channel is registered, files are never written to disk. If the
controller has gone, their contents are discarded.

## File Metadata

A `file` message may carry a `meta` object that describes the file, so a
controller can act on each file as it arrives instead of waiting for a summary
JSON that is written last. Writers hand it to `util::OpenOutputFile()`; it is
never written to disk.

- `meta` is absent when the writer has nothing to say about the file.
- `producer` names what wrote the file and decides the rest of the schema.
  Ignore producers and keys you do not recognize.
- Key names follow the producer's own JSON output where it has one.
- When an image's alpha channel is written to a separate file, both files carry
  the same `meta`.

### Dump resources

`producer` is `dumpResources`. The only other key is the dr.json array name for
the command type (`drawCallCommands`, `dispatchCommands`, `traceRaysCommands` or
`transferCommands`). It holds that command's dr.json entry, built by the code that
writes dr.json and cut down to the branch that leads to this file:

- Branches that lead only to other files are dropped.
- Each array on the file's branch keeps just the file's element, which gains an
  `index` key holding its position in dr.json. dr.json itself never uses
  `index` in arrays that hold files.
- Everything else is kept, such as the command's indices and `parameters`.

To find the file's own entry, match the message `name` against the dr.json file
keys. The key that holds it tells which file it is: `file`, `fileAlpha`,
`beforeFile` or `beforeFileAlpha`.

The entry is built before the file is written, so it lacks what is only known
afterwards:

- `compressedSize`: the message's own `size`.
- For a file dumped before the command, the keys of the after file (`file`,
  `fileAlpha`, `size`, `compressedSize`, `compressedSizeBefore`).

Some facts dr.json keeps outside the entry are not repeated:

- Encoding: the file extension, `.png`, `.bmp`, `.bin` or `.json`.
- Compression: `.bin` files use the codec named by `BinaryFileCompressionType`
  in the input JSON's `DumpResourcesOptions`. The header of each per-command
  JSON also names it.
- Scaled size: an image with `scaleFailed` is unscaled. Otherwise its width and
  height are `max(1, floor(dimension * scale))`, depth is unchanged, and mip
  levels are derived from the scaled base extent.

A controller that relies on any of these should set the option explicitly, so a
change to replay's defaults cannot move it.

A per-command JSON file is sent after the files of its command, so its arrival
marks that command complete. Its meta is the command's entry with every file
dropped. The single dr.json carries only `producer` and arrives when replay
finishes.

```json
{"type":"file","name":"dump/image_6874884585821301596.bin","size":2579,"meta":{
  "producer":"dumpResources",
  "drawCallCommands":{
    "drawIndex":115,"beginCommandBufferIndex":109,"queueSubmitIndex":120,
    "parameters":{"drawCallType":"vkCmdDraw","vertexCount":36,"instanceCount":1,
                  "firstVertex":0,"firstInstance":0},
    "depthAttachment":{
      "imageId":45,"format":"VK_FORMAT_D16_UNORM","extent":[400,300,1],
      "imageType":"VK_IMAGE_TYPE_2D","levels":1,"layers":1,"sampleCount":1,
      "subresources":[{"index":0,"aspect":"DEPTH","dimensions":[400,300,1],
                       "mipLevel":0,"arrayLayer":0,"depth":0,
                       "file":"dump/image_6874884585821301596.bin","size":240000}]}}}}
```

## Threading Model

`RemoteChannel` runs a sender thread and a receiver thread:

- All `Send*` calls serialize their message into a single buffer and enqueue it;
  the sender thread drains the queue in order. `SendFile` packs the JSON header
  and binary data into one buffer so they are never interleaved with another
  message.
- The receiver thread demultiplexes incoming frames into the control queue.
- `Disconnect()` drains and joins the sender (flushing queued messages), then
  half-closes the socket and waits for the receiver to see the controller close.
  If the controller does not close in time, it wakes the receiver itself. It
  then joins the receiver and closes.

## Reference Controller

[scripts/replay_controller.py](../scripts/replay_controller.py) is a reference
controller implementation:

- `--listen HOST:PORT` — accept a connection from a `--remote-connect` replay.
- `--connect HOST:PORT` — dial out to a `--remote-listen` replay (retries a
  refused connection for up to 30 s to cover launch races).
- `--launch-adb` — set up the appropriate adb mapping and launch the replay activity on
  a connected Android device.
- `--save-meta`: write each received file's `meta` next to it as
  `<name>.meta.json`.
- Replay settings are given after `--` as `key=value`, or as a bare key for an
  option that takes no value. Leading dashes are optional, so options keep their
  familiar spelling. Deliberately *not* a replay command line: which options take
  a value is not knowable from the tokens alone, so requiring `=` removes the
  guesswork rather than inferring it.
- Pushes the file when an [input file option](#input-files) names one on the
  controller's machine, rewriting the option value to the bare filename.
- Reads `p` / `r` / `s` / `q` from stdin to send pause/resume/step/stop controls.
- `--self-test` runs the script's doctests.

```
python scripts/replay_controller.py --connect localhost:9000 --launch-adb -- --dump-resources=dr.json capture_file=/sdcard/capture.gfxr
```

Only the capture file has to exist on the device; `dr.json` is read from the
controller's working directory and pushed.

## Security

The protocol is unauthenticated and unencrypted, intended for trusted links:
loopback, adb-forwarded sockets, or an ssh tunnel. Do not expose either end on
an untrusted network.

- `--remote-listen` accepts the first connection from anyone who can reach the
  address; prefer loopback or adb/ssh forwarding over binding a routable
  interface.
- A connected controller fully drives replay: it chooses the settings, pushes
  input files, and receives everything replay reports. Connecting is equivalent
  to running replay as that user.
- Replay currently keeps pushed input files in a predictably named scratch
  directory under the system temp directory (the app's private data directory
  on Android) until the run ends. Like the socket, this assumes no hostile local
  users: where the temp directory is shared, another user could read the files
  or plant the directory in advance.
- The reference controller anchors received files under `--output-dir` and
  strips path components that would escape it.

## CLI Reference

```
--remote-connect <address>   Connect out to a listening controller.
--remote-listen  <address>   Listen for and accept one controller (30 s timeout).

  <address> forms:
    tcp:host:port    TCP (all platforms)
    unix:@name       abstract Unix socket (Linux/Android)
    unix:/path       filesystem Unix socket (POSIX)
```
