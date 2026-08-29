#!/usr/bin/env python3

# Copyright (c) 2026 LunarG, Inc.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to
# deal in the Software without restriction, including without limitation the
# rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
# sell copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
# IN THE SOFTWARE.
'''
Controller for gfxrecon-replay's remote feature.

gfxrecon-replay is the client and connects outward with --remote-connect to
this controller, which acts as the server. This script listens for that connection, sends the replay
settings, then reports what replay sends back.

Wire format: each frame is a little-endian uint32 length prefix followed by
that many payload bytes. Structured messages are JSON. A binary file payload is
a JSON "file" frame immediately followed by a raw binary frame.

Replay settings travel as key/value pairs, not as a command line: a key is a
replay option with its leading dashes stripped and '-' replaced by '_', and
every value is a string. Write them after -- as key=value, or as a bare key for
an option that takes no value; see settings_from_args().

Desktop usage:
    python3 scripts/replay_controller.py --port 9001 -- --loop-count=3 capture_file=capture.gfxr
    gfxrecon-replay --remote-connect tcp:localhost:9001

Android usage (replay connects to an abstract unix socket forwarded to the PC):
    adb reverse localabstract:gfxrecon tcp:9001
    python3 scripts/replay_controller.py --port 9001 -- capture_file=/sdcard/capture.gfxr
    # launch the replay activity with intent args: --remote-connect unix:@gfxrecon

Backpressure testing (a slow controller against replay's bounded send queue):
    python3 scripts/replay_controller.py --port 9001 --slow-recv 8 -- \\
        dump_resources=dr.json capture_file=capture.gfxr
'''

import argparse
import json
import os
import socket
import struct
import sys
import time


def normalize(token):
    '''Convert a command-line spelling to its settings key: strip leading dashes, '-' becomes '_'.

    >>> normalize('--loop-count')
    'loop_count'
    >>> normalize('mfr')
    'mfr'
    '''
    return token.lstrip('-').replace('-', '_')


def assign(options, key, value):
    '''Set options[key], rejecting a second, conflicting assignment of the same key.

    A settings map cannot express a key twice, so one of the two would be silently dropped. Replay cannot catch
    that -- the surviving key is perfectly valid -- so it has to be caught here.
    '''
    if key in options and options[key] != value:
        raise ValueError(f"setting '{key}' given twice, as '{options[key]}' "
                         f"and '{value}'")
    options[key] = value


def settings_from_args(tokens):
    '''Build a settings dict from key=value tokens.

    Each token is read on its own, with no reference to its neighbours or its position:

      * 'key=value' sets key to value. Only the first '=' separates, so a value may contain more.
      * A bare 'key' is an option that takes no value, set to 'true'.

    Keys are normalized, so a replay option's leading dashes may be kept or dropped. What differs from a replay
    command line is the '=' joining an option to its value, and the capture file being named by its key rather
    than positional -- deliberately, since which options take a value is not knowable from the tokens alone.

    >>> settings_from_args(['paused', 'loop_count=3', 'capture_file=cap.gfxr']) == {
    ...     'paused': 'true', 'loop_count': '3', 'capture_file': 'cap.gfxr'}
    True
    >>> settings_from_args(['--paused', '--loop-count=3']) == {
    ...     'paused': 'true', 'loop_count': '3'}
    True
    >>> settings_from_args(['fwo=-10,-10', 'screenshot_dir=/my dir']) == {
    ...     'fwo': '-10,-10', 'screenshot_dir': '/my dir'}
    True
    >>> settings_from_args(['replay_event_plugin_params=a=b'])
    {'replay_event_plugin_params': 'a=b'}
    >>> settings_from_args(['gpu=0', 'gpu=1'])
    Traceback (most recent call last):
    ValueError: setting 'gpu' given twice, as '0' and '1'
    >>> settings_from_args(['=orphan'])
    Traceback (most recent call last):
    ValueError: '=orphan' has no setting name
    '''
    options = {}
    for token in tokens:
        key, separator, value = token.partition('=')
        key = normalize(key)
        if not key:
            raise ValueError(f"'{token}' has no setting name")
        assign(options, key, value if separator else 'true')
    return options


recv_rate = 0.0  # --slow-recv byte rate; 0 leaves reads unthrottled
recv_sleep_seconds = 0.0  # time this side spent deliberately not reading


def throttle_recv(count):
    '''Sleep long enough that reads average recv_rate bytes per second.

    Sleeping after the read rather than before it is the point: the kernel keeps filling the receive buffer while
    we are idle, so once that buffer is full the stall propagates back to replay as a blocked send.
    '''
    global recv_sleep_seconds
    if recv_rate <= 0:
        return
    delay = count / recv_rate
    recv_sleep_seconds += delay
    time.sleep(delay)


def apply_recv_throttle(conn, mib_per_second):
    '''Slow this side's reads to mib_per_second, to exercise replay's send queue bound.'''
    global recv_rate
    if mib_per_second <= 0:
        return
    recv_rate = mib_per_second * (1 << 20)

    # Shrink the receive buffer so the stall reaches replay promptly instead of after the kernel has quietly
    # absorbed several MiB. Advisory: the window may already have been negotiated larger.
    try:
        conn.setsockopt(socket.SOL_SOCKET, socket.SO_RCVBUF, 256 * 1024)
    except OSError as e:
        print(f'Warning: could not shrink the receive buffer: {e}',
              file=sys.stderr)

    print(f'Throttling reads to {mib_per_second:.1f} MiB/s')


def recv_exact(conn, length):
    '''Read exactly length bytes, or return None if the peer closes early.'''
    chunks = []
    remaining = length
    while remaining > 0:
        chunk = conn.recv(remaining)
        if not chunk:
            return None
        chunks.append(chunk)
        remaining -= len(chunk)
        throttle_recv(len(chunk))
    return b''.join(chunks)


def recv_frame(conn):
    '''Read one length-prefixed frame. Returns bytes, or None on disconnect.'''
    header = recv_exact(conn, 4)
    if header is None:
        return None
    (length, ) = struct.unpack('<I', header)
    if length == 0:
        return b''
    return recv_exact(conn, length)


def send_frame(conn, payload):
    conn.sendall(struct.pack('<I', len(payload)) + payload)


def send_json(conn, obj):
    send_frame(conn, json.dumps(obj).encode('utf-8'))


def handle_session(conn, options, output_dir):
    '''Run the handshake and process messages until replay reports done.

    options is the settings dict sent to replay.
    '''
    # Handshake: replay greets us, we reply with settings, replay acknowledges.
    hello = recv_frame(conn)
    if hello is None:
        print('Replay disconnected before handshake', file=sys.stderr)
        return False
    hello = json.loads(hello)
    if hello.get('type') != 'hello':
        print(f'Unexpected first message: {hello}', file=sys.stderr)
        return False
    print(f"Connected to replay (protocol version {hello.get('version')})")

    send_json(conn, {'type': 'settings', 'options': options})
    print('Sent settings:')
    for key in sorted(options):
        print(f'  {key}={options[key]}')

    ready = recv_frame(conn)
    if ready is None or json.loads(ready).get('type') != 'ready':
        print('Replay did not acknowledge settings', file=sys.stderr)
        return False

    success = False
    while True:
        frame = recv_frame(conn)
        if frame is None:
            print('Replay disconnected')
            break

        msg = json.loads(frame)
        msg_type = msg.get('type')

        if msg_type == 'file':
            # A "file" message is always followed by a raw binary frame.
            name = msg.get('name', 'unnamed')
            expected = msg.get('size', 0)
            blob = recv_frame(conn)
            blob = blob if blob is not None else b''
            save_file(output_dir, name, blob, expected)
        elif msg_type == 'done':
            success = bool(msg.get('success'))
            print(f'Replay finished (success={success})')
            break
        else:
            print(f'Unknown message: {msg}', file=sys.stderr)

    if recv_rate > 0:
        print(f'--- recv throttle: {recv_rate / (1 << 20):.1f} MiB/s, '
              f'{recv_sleep_seconds:.1f}s spent not reading ---')

    return success


def save_file(output_dir, name, blob, expected_size):
    if len(blob) != expected_size:
        print(
            f"Warning: '{name}' expected {expected_size} bytes, got {len(blob)}",
            file=sys.stderr)

    # Keep the relative path from replay but anchor it under output_dir, and
    # never let it escape via leading slashes or '..'.
    safe_name = os.path.normpath(name).lstrip(os.sep)
    if safe_name.startswith('..'):
        safe_name = os.path.basename(name)
    dest = os.path.join(output_dir, safe_name)

    os.makedirs(os.path.dirname(dest) or '.', exist_ok=True)
    with open(dest, 'wb') as out:
        out.write(blob)
    print(f"Saved file: {dest} ({len(blob)} bytes)")


# --- Session driving -----------------------------------------------------------------------------------
#
# Everything below is importable without argparse, so another harness can drive a replay session without
# duplicating the handshake or shelling out to this script.


class ControllerError(Exception):
    '''A setup failure worth reporting to the user rather than tracing back.

    Raised for the things that go wrong before a session exists, such as a port we cannot bind. Session
    outcomes are reported by the return value instead.
    '''


def open_listen_socket(host, port):
    '''Bind and listen for one replay. Returns the listening socket.'''
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    if sys.platform == 'win32':
        # Not SO_REUSEADDR: on Windows that lets an unrelated process take over a port we have bound.
        server.setsockopt(socket.SOL_SOCKET, socket.SO_EXCLUSIVEADDRUSE, 1)
    else:
        # Rebind a port left in TIME_WAIT by a previous run.
        server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    try:
        server.bind((host, port))
        server.listen(1)
    except OSError as e:
        server.close()
        raise ControllerError(f'could not listen on {host}:{port}: {e}') from e
    return server


def run_session(conn, options, output_dir, slow_recv=0.0):
    '''Drive one replay session over an already-connected socket. Returns True on success.'''
    apply_recv_throttle(conn, slow_recv)
    with conn:
        return handle_session(conn, options, output_dir)


def run_replay(options,
               output_dir,
               host='127.0.0.1',
               port=9001,
               slow_recv=0.0):
    '''Listen for replay to connect with --remote-connect, then drive one session. Returns True on success.'''
    os.makedirs(output_dir, exist_ok=True)

    server = open_listen_socket(host, port)
    print(f'Listening on {host}:{port}')
    with server:
        conn, peer = server.accept()
        print(f'Replay connected from {peer[0]}:{peer[1]}')
    return run_session(conn, options, output_dir, slow_recv)


def main():
    parser = argparse.ArgumentParser(
        description='Control gfxrecon-replay over its remote socket.',
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog='''\
Everything after -- becomes replay's settings, which travel over the socket as
key/value pairs rather than as a command line. Write each one as key=value, or
as a bare key for an option that takes no value:

    -- paused --loop-count=3 --dump-resources=dr.json capture_file=cap.gfxr

Leading dashes are optional, so options keep their familiar spelling. What
differs from a replay command line is the '=' joining an option to its value,
and the capture file being named by its key rather than positional. Replay
rejects any key it does not recognize, naming it in the error.''')
    parser.add_argument('--host',
                        default='127.0.0.1',
                        help='Address to listen on (default: 127.0.0.1).')
    parser.add_argument('--port',
                        type=int,
                        default=9001,
                        help='TCP port to listen on (default: 9001).')
    parser.add_argument(
        '--output-dir',
        default='remote_output',
        help=
        'Directory for files streamed back by replay (default: remote_output).'
    )
    parser.add_argument(
        '--slow-recv',
        type=float,
        default=0.0,
        metavar='MIB_PER_S',
        help='Read at roughly this rate instead of as fast as possible, to '
        'exercise replay\'s bounded send queue. Also shrinks this side\'s '
        'receive buffer so the stall reaches replay promptly. 0 (the default) '
        'leaves reads unthrottled.')
    parser.add_argument('--self-test',
                        action='store_true',
                        help='Run this script\'s doctests and exit.')
    parser.add_argument(
        'replay_args',
        nargs=argparse.REMAINDER,
        help='Replay settings, e.g. -- --loop-count 3 capture.gfxr')
    args = parser.parse_args()

    if args.self_test:
        import doctest
        return 1 if doctest.testmod(verbose=False).failed else 0

    # Strip a leading '--' separator if argparse left it in the remainder.
    replay_args = args.replay_args
    if replay_args and replay_args[0] == '--':
        replay_args = replay_args[1:]
    if not replay_args:
        parser.error(
            'No replay args given. Pass them after --, e.g. -- capture.gfxr')

    try:
        options = settings_from_args(replay_args)
    except ValueError as e:
        parser.error(str(e))

    try:
        success = run_replay(options,
                             args.output_dir,
                             host=args.host,
                             port=args.port,
                             slow_recv=args.slow_recv)
    except KeyboardInterrupt:
        print('\nInterrupted', file=sys.stderr)
        return 1
    except ControllerError as e:
        print(f'Error: {e}', file=sys.stderr)
        return 1

    return 0 if success else 1


if __name__ == '__main__':
    sys.exit(main())
