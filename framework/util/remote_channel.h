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

#ifndef GFXRECON_UTIL_REMOTE_CHANNEL_H
#define GFXRECON_UTIL_REMOTE_CHANNEL_H

#include "util/defines.h"
#include "util/logging_common.h"

#include "nlohmann/json.hpp"

#include <atomic>
#include <condition_variable>
#include <cstdint>
#include <deque>
#include <map>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// Winsock's SOCKET is unsigned and pointer-sized; POSIX uses an int descriptor. Aliased to keep winsock2.h out of
// this header.
#if defined(_WIN32)
using SocketHandle = uintptr_t;
#else
using SocketHandle = int;
#endif

constexpr SocketHandle kInvalidSocket = static_cast<SocketHandle>(-1); // Also Winsock's INVALID_SOCKET.

// RemoteChannel connects gfxrecon-replay (the client) to a controller process (the server) over a socket for
// bidirectional I/O. The controller sends replay settings; replay sends back log messages, progress, screenshots, and
// dump-resources files.
//
// Wire format: each frame is a little-endian uint32_t length prefix followed by that many payload bytes. Structured
// messages are JSON frames. A binary file payload is sent as a JSON "file" metadata frame immediately followed by a raw
// binary frame.
class RemoteChannel
{
  public:
    RemoteChannel() = default;
    ~RemoteChannel() { Disconnect(); }

    RemoteChannel(const RemoteChannel&)            = delete;
    RemoteChannel& operator=(const RemoteChannel&) = delete;

    // Connect to the controller. Address forms:
    //   "tcp:host:port"  - TCP connection (all platforms)
    //   "unix:@name"     - abstract Unix domain socket (Linux/Android)
    //   "unix:/path"     - filesystem-backed Unix domain socket (POSIX)
    // Returns true on success.
    bool Connect(const std::string& address);

    bool IsConnected() const;
    void Disconnect();

    // Perform the startup handshake. Sends "hello", waits for a "settings" message, then sends "ready". On success
    // fills settings with the controller-supplied option name/value pairs (keys as described by ArgumentParser's
    // settings-map constructor, values always strings).
    bool Handshake(std::map<std::string, std::string>& settings);

    // The following are thread-safe, non-blocking, and no-ops when disconnected. Messages are queued and delivered
    // in order by a background sender thread; if a send fails, queued messages are dropped and the channel reports
    // disconnected. Disconnect() flushes any queued messages before closing the socket.
    void SendJson(const nlohmann::json& msg);
    void SendDone(bool success); // Also calls Disconnect().

    // Register (or clear, with nullptr) the process-wide channel. Called once during remote setup and cleared during
    // shutdown, both on the main thread.
    static void SetActiveChannel(RemoteChannel* channel);

    // Returns true when a connected channel is registered.
    static bool IsActive();

  private:
    // Append a length-prefixed frame to buffer.
    static void AppendFrame(std::vector<uint8_t>& buffer, const void* data, uint32_t size);

    // Queue a pre-framed buffer for the sender thread; drops the buffer when disconnected or after a send failure.
    void EnqueueFrames(std::vector<uint8_t>&& buffer);

    // Sender thread entry point: sends queued buffers in order until stopped or a send fails.
    void SenderThread();

    bool RecvFrame(std::vector<uint8_t>& out);
    bool SendAll(const void* buf, size_t size);
    bool RecvExact(void* buf, size_t size);

    SocketHandle fd_{ kInvalidSocket };

    std::thread                      sender_thread_;
    std::mutex                       queue_mutex_;
    std::condition_variable          queue_cv_;
    std::deque<std::vector<uint8_t>> send_queue_;              // Guarded by queue_mutex_.
    bool                             stop_requested_{ false }; // Guarded by queue_mutex_.
    std::atomic<bool>                send_failed_{ false };

    // Process-wide channel behind the static helpers, for callers that cannot be handed a pointer to it. Only one
    // controller connection exists per process.
    static RemoteChannel* active_channel_;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_REMOTE_CHANNEL_H
