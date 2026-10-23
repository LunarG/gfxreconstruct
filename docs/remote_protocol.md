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
- No maximum frame size is enforced.
- Structured messages are UTF-8 JSON payloads. These could be migrated to a binary format such as protobuf or even GFXR's own encode/decode machinery.
- Binary file payloads are sent as a JSON `"file"` metadata frame **immediately
  followed** by a separate raw binary frame (no base64). After a `"file"`
  message the receiver treats the next frame as raw bytes.

## Startup Handshake

```
replay     → controller:  {"type":"hello","version":"1"}
controller → replay:      {"type":"settings","options":{
                            "loop_count":"3",
                            "capture_file":"/sdcard/capture.gfxr"}}
replay     → controller:  {"type":"ready"}
[replay runs]
```

- Replay sends `hello` first regardless of which side dialed.
- `options` is a set of replay settings, from which replay rebuilds its
  `ArgumentParser`. It completely replaces the traditional command-line
  arguments. See [Settings Keys](#settings-keys).
- Replay waits up to 5 seconds for `settings` to arrive, and fails to start if
  the controller stays silent that long.

## Message Schema

### Controller → replay

```json
{"type":"settings","options":{"<key>":"<value>", ...}}
```

### Replay → controller

```json
{"type":"file","name":"dump/frame_0042.png","size":204800}
<204800 raw bytes — separate binary frame, no encoding>
{"type":"done","success":true}
```

`done` is the final message; replay disconnects after sending it.

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

If a send fails, `IsActive()` / `IsConnected()` become false and files opened
afterward go to disk.

## Threading Model

`RemoteChannel` runs a sender thread:

- All `Send*` calls serialize their message into a single buffer and enqueue it;
  the sender thread drains the queue in order. `SendFile` packs the JSON header
  and binary data into one buffer so they are never interleaved with another
  message.
- `Disconnect()` drains and joins the sender (flushing queued messages), then
  closes the socket.

## Reference Controller

[scripts/replay_controller.py](../scripts/replay_controller.py) is a reference
controller implementation:

- `--listen HOST:PORT` — accept a connection from a `--remote-connect` replay.
- `--connect HOST:PORT` — dial out to a `--remote-listen` replay (retries a
  refused connection for up to 30 s to cover launch races).
- `--launch-adb` — set up the appropriate adb mapping and launch the replay activity on
  a connected Android device.
- Replay settings are given after `--` as `key=value`, or as a bare key for an
  option that takes no value. Leading dashes are optional, so options keep their
  familiar spelling. Deliberately *not* a replay command line: which options take
  a value is not knowable from the tokens alone, so requiring `=` removes the
  guesswork rather than inferring it.
- `--self-test` runs the script's doctests.

```
python scripts/replay_controller.py --connect localhost:9000 --launch-adb -- --dump-resources=/sdcard/dr.json capture_file=/sdcard/capture.gfxr
```

## Security

The protocol is unauthenticated and unencrypted, intended for trusted links:
loopback, adb-forwarded sockets, or an ssh tunnel. Do not expose either end on
an untrusted network.

- `--remote-listen` accepts the first connection from anyone who can reach the
  address; prefer loopback or adb/ssh forwarding over binding a routable
  interface.
- A connected controller fully drives replay: it chooses the settings and
  receives everything replay reports. Connecting is equivalent to running replay
  as that user.
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
