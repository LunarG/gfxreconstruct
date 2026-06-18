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

#include <cstdint>
#include <map>
#include <mutex>
#include <string>
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

    // The following are thread-safe and are no-ops when disconnected.
    void SendJson(const nlohmann::json& msg);
    void SendDone(bool success); // Also calls Disconnect().

    // Register (or clear, with nullptr) the process-wide channel. Called once during remote setup and cleared during
    // shutdown, both on the main thread.
    static void SetActiveChannel(RemoteChannel* channel);

    // Returns true when a connected channel is registered.
    static bool IsActive();

  private:
    bool SendFrame(const void* data, uint32_t size);
    bool RecvFrame(std::vector<uint8_t>& out);
    bool SendAll(const void* buf, size_t size);
    bool RecvExact(void* buf, size_t size);

    SocketHandle fd_{ kInvalidSocket };
    std::mutex   send_mutex_;

    // Process-wide channel behind the static helpers, for callers that cannot be handed a pointer to it. Only one
    // controller connection exists per process.
    static RemoteChannel* active_channel_;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_REMOTE_CHANNEL_H
