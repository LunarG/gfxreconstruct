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

Replay dials out to a listening controller with **`--remote-connect
<address>`**. If `--remote-connect` is set but the connection fails, replay
exits with failure and does not fall back to local playback. Local CLI args are
used only when `--remote-connect` is absent.

On Android this is bridged to the PC with `adb reverse localabstract:gfxrecon
tcp:<port>` (adbd binds the abstract name on the device).

## Wire Format

Every frame is a length-prefixed byte string:

```
[uint32_t little-endian length][payload bytes]
```

- All target devices are little-endian; no byte-swapping is performed.
- No maximum frame size is enforced.
- Structured messages are UTF-8 JSON payloads. These could be migrated to a binary format such as protobuf or even GFXR's own encode/decode machinery.

## Startup Handshake

```
replay     → controller:  {"type":"hello","version":"1"}
controller → replay:      {"type":"settings","options":{
                            "loop_count":"3",
                            "capture_file":"/sdcard/capture.gfxr"}}
replay     → controller:  {"type":"ready"}
[replay runs]
```

- Replay sends `hello` first.
- `options` is a set of replay settings, from which replay rebuilds its
  `ArgumentParser`. It completely replaces the traditional command-line
  arguments. See [Settings Keys](#settings-keys).
- A 5-second receive timeout applies during the handshake, and is cleared once
  the handshake succeeds.

## Message Schema

### Controller → replay

```json
{"type":"settings","options":{"<key>":"<value>", ...}}
```

### Replay → controller

```json
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

## Reference Controller

[scripts/replay_controller.py](../scripts/replay_controller.py) is a reference
controller implementation:

- `--host HOST` / `--port PORT` — listen for a `--remote-connect` replay (default
  `127.0.0.1:9001`).
- Replay settings are given after `--` as `key=value`, or as a bare key for an
  option that takes no value. Leading dashes are optional, so options keep their
  familiar spelling. Deliberately *not* a replay command line: which options take
  a value is not knowable from the tokens alone, so requiring `=` removes the
  guesswork rather than inferring it.
- `--self-test` runs the script's doctests.

```
python scripts/replay_controller.py --port 9001 -- --loop-count=3 capture_file=capture.gfxr
```

## Security

The protocol is unauthenticated and unencrypted, intended for trusted links:
loopback, adb-forwarded sockets, or an ssh tunnel. Do not expose either end on
an untrusted network.

- A connected controller fully drives replay: it chooses the settings and
  receives everything replay reports. Connecting is equivalent to running replay
  as that user.

## CLI Reference

```
--remote-connect <address>   Connect out to a listening controller.

  <address> forms:
    tcp:host:port    TCP (all platforms)
    unix:@name       abstract Unix socket (Linux/Android)
    unix:/path       filesystem Unix socket (POSIX)
```
