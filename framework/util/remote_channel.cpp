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

// winsock2.h must come before any windows.h.
#if defined(_WIN32)
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>
#endif

#include "util/remote_channel.h"

#include "util/logging.h"

#include <algorithm>
#include <cerrno>
#include <cstddef>
#include <cstring>
#include <limits>

// Undefined on Windows, which has no SIGPIPE, and on macOS, which uses SO_NOSIGPIPE instead (see SetNoSigPipe below).
#ifndef MSG_NOSIGNAL
#define MSG_NOSIGNAL 0
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

namespace
{
constexpr int kHandshakeTimeoutSeconds = 5;

// The rest of this block adapts Winsock and BSD sockets to the one interface used by the logic below.
#if defined(_WIN32)

// Winsock must be initialized before any socket call; the function-local static also tears it down at exit.
bool EnsureSocketLibrary()
{
    struct WinsockScope
    {
        WinsockScope()
        {
            WSADATA data = {};
            status       = WSAStartup(MAKEWORD(2, 2), &data);
        }

        ~WinsockScope()
        {
            if (status == 0)
            {
                WSACleanup();
            }
        }

        int status;
    };

    static const WinsockScope scope;
    if (scope.status != 0)
    {
        GFXRECON_LOG_ERROR("Remote channel: WSAStartup failed with error %d", scope.status);
        return false;
    }
    return true;
}

// Winsock errors never reach errno, so strerror() would report something unrelated.
std::string SocketErrorString()
{
    const DWORD error   = static_cast<DWORD>(WSAGetLastError());
    char*       message = nullptr;
    const DWORD length =
        FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                       nullptr,
                       error,
                       MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                       reinterpret_cast<char*>(&message),
                       0,
                       nullptr);

    std::string result;
    if ((message != nullptr) && (length != 0))
    {
        result.assign(message, length);

        // System messages end in a newline, which would split the log line.
        while (!result.empty() && ((result.back() == '\r') || (result.back() == '\n') || (result.back() == ' ')))
        {
            result.pop_back();
        }
    }
    if (message != nullptr)
    {
        LocalFree(message);
    }

    if (result.empty())
    {
        result = "unknown socket error";
    }
    return result + " (" + std::to_string(error) + ")";
}

bool SocketErrorIsInterrupt()
{
    return WSAGetLastError() == WSAEINTR;
}

void CloseSocket(SocketHandle& fd)
{
    closesocket(fd);
    fd = kInvalidSocket;
}

// A timeout_seconds of 0 restores indefinite blocking. Windows takes SO_RCVTIMEO in milliseconds, POSIX as a timeval.
void SetRecvTimeout(SocketHandle fd, int timeout_seconds)
{
    DWORD timeout = static_cast<DWORD>(timeout_seconds) * 1000;
    setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, reinterpret_cast<const char*>(&timeout), sizeof(timeout));
}

// Windows has no SIGPIPE; a send to a closed peer simply fails.
void SetNoSigPipe(SocketHandle fd)
{
    GFXRECON_UNREFERENCED_PARAMETER(fd);
}

// Windows has no abstract namespace, and the controller has no AF_UNIX there either, so Windows targets speak TCP.
SocketHandle ConnectUnix(const std::string& name)
{
    GFXRECON_UNREFERENCED_PARAMETER(name);
    GFXRECON_LOG_ERROR("Remote channel: Unix domain sockets are not supported on Windows; use a tcp: address");
    return kInvalidSocket;
}

#else // POSIX

bool EnsureSocketLibrary()
{
    return true;
}

std::string SocketErrorString()
{
    return strerror(errno);
}

bool SocketErrorIsInterrupt()
{
    return errno == EINTR;
}

void CloseSocket(SocketHandle& fd)
{
    close(fd);
    fd = kInvalidSocket;
}

// A timeout_seconds of 0 restores indefinite blocking.
void SetRecvTimeout(SocketHandle fd, int timeout_seconds)
{
    timeval timeout = {};
    timeout.tv_sec  = timeout_seconds;
    setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
}

// Suppress SIGPIPE on platforms that signal it instead of honoring MSG_NOSIGNAL (e.g. macOS).
void SetNoSigPipe(SocketHandle fd)
{
#ifdef SO_NOSIGPIPE
    int on = 1;
    setsockopt(fd, SOL_SOCKET, SO_NOSIGPIPE, &on, sizeof(on));
#else
    GFXRECON_UNREFERENCED_PARAMETER(fd);
#endif
}

// Connect a Unix domain socket. A leading '@' in name selects the abstract namespace. Returns a connected fd, or
// kInvalidSocket on failure.
SocketHandle ConnectUnix(const std::string& name)
{
    SocketHandle fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (fd == kInvalidSocket)
    {
        GFXRECON_LOG_ERROR("Remote channel: failed to create Unix socket: %s", SocketErrorString().c_str());
        return kInvalidSocket;
    }

    sockaddr_un addr = {};
    addr.sun_family  = AF_UNIX;

    socklen_t addrlen = 0;
    if (!name.empty() && name[0] == '@')
    {
        // Abstract socket: leading null byte, name starts at sun_path[1], no trailing null.
        std::string abstract_name = name.substr(1);
        if (abstract_name.size() + 1 > sizeof(addr.sun_path))
        {
            GFXRECON_LOG_ERROR("Remote channel: abstract socket name '%s' is too long", name.c_str());
            CloseSocket(fd);
            return kInvalidSocket;
        }
        addr.sun_path[0] = '\0';
        memcpy(addr.sun_path + 1, abstract_name.data(), abstract_name.size());
        addrlen = static_cast<socklen_t>(offsetof(sockaddr_un, sun_path) + 1 + abstract_name.size());
    }
    else
    {
        if (name.size() + 1 > sizeof(addr.sun_path))
        {
            GFXRECON_LOG_ERROR("Remote channel: Unix socket path '%s' is too long", name.c_str());
            CloseSocket(fd);
            return kInvalidSocket;
        }
        memcpy(addr.sun_path, name.data(), name.size());
        addrlen = static_cast<socklen_t>(offsetof(sockaddr_un, sun_path) + name.size() + 1);
    }

    if (connect(fd, reinterpret_cast<sockaddr*>(&addr), addrlen) != 0)
    {
        GFXRECON_LOG_ERROR(
            "Remote channel: failed to connect to Unix socket '%s': %s", name.c_str(), SocketErrorString().c_str());
        CloseSocket(fd);
        return kInvalidSocket;
    }

    SetNoSigPipe(fd);
    return fd;
}

#endif // defined(_WIN32)

// send() and recv() take a char buffer and an int length on Windows, a void buffer and a size_t on POSIX. The clamp
// lets an oversized buffer take several passes, which the calling loops already handle, rather than overflow the int.
int64_t SocketSend(SocketHandle fd, const void* buf, size_t size)
{
#if defined(_WIN32)
    const int length = static_cast<int>(std::min<size_t>(size, std::numeric_limits<int>::max()));
    return send(fd, static_cast<const char*>(buf), length, MSG_NOSIGNAL);
#else
    return send(fd, buf, size, MSG_NOSIGNAL);
#endif
}

int64_t SocketRecv(SocketHandle fd, void* buf, size_t size)
{
#if defined(_WIN32)
    const int length = static_cast<int>(std::min<size_t>(size, std::numeric_limits<int>::max()));
    return recv(fd, static_cast<char*>(buf), length, 0);
#else
    return recv(fd, buf, size, 0);
#endif
}

// Windows mirrors getaddrinfo() failures into the socket error, and its gai_strerror() is not thread-safe.
std::string AddrInfoErrorString(int error)
{
#if defined(_WIN32)
    GFXRECON_UNREFERENCED_PARAMETER(error);
    return SocketErrorString();
#else
    return gai_strerror(error);
#endif
}

// Connect a TCP socket described by "host:port". Returns a connected fd, or kInvalidSocket on failure.
SocketHandle ConnectTcp(const std::string& host_port)
{
    size_t colon = host_port.find_last_of(':');
    if (colon == std::string::npos)
    {
        GFXRECON_LOG_ERROR("Remote channel: invalid TCP address '%s' (expected host:port)", host_port.c_str());
        return kInvalidSocket;
    }

    std::string host = host_port.substr(0, colon);
    std::string port = host_port.substr(colon + 1);

    addrinfo hints    = {};
    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    addrinfo* results = nullptr;
    int       err     = getaddrinfo(host.c_str(), port.c_str(), &hints, &results);
    if (err != 0)
    {
        GFXRECON_LOG_ERROR(
            "Remote channel: failed to resolve '%s': %s", host_port.c_str(), AddrInfoErrorString(err).c_str());
        return kInvalidSocket;
    }

    SocketHandle fd = kInvalidSocket;
    for (addrinfo* ai = results; ai != nullptr; ai = ai->ai_next)
    {
        fd = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol);
        if (fd == kInvalidSocket)
        {
            continue;
        }
        if (connect(fd, ai->ai_addr, static_cast<socklen_t>(ai->ai_addrlen)) == 0)
        {
            SetNoSigPipe(fd);
            break;
        }
        CloseSocket(fd);
    }

    freeaddrinfo(results);

    if (fd == kInvalidSocket)
    {
        GFXRECON_LOG_ERROR("Remote channel: failed to connect to '%s'", host_port.c_str());
    }
    return fd;
}
} // namespace

bool RemoteChannel::Connect(const std::string& address)
{
    Disconnect();

    if (!EnsureSocketLibrary())
    {
        return false;
    }

    constexpr const char kTcpPrefix[]  = "tcp:";
    constexpr const char kUnixPrefix[] = "unix:";

    if (address.rfind(kTcpPrefix, 0) == 0)
    {
        fd_ = ConnectTcp(address.substr(sizeof(kTcpPrefix) - 1));
    }
    else if (address.rfind(kUnixPrefix, 0) == 0)
    {
        fd_ = ConnectUnix(address.substr(sizeof(kUnixPrefix) - 1));
    }
    else
    {
        GFXRECON_LOG_ERROR("Remote channel: unrecognized address '%s' (expected tcp: or unix: prefix)",
                           address.c_str());
        return false;
    }

    return fd_ != kInvalidSocket;
}

bool RemoteChannel::IsConnected() const
{
    return fd_ != kInvalidSocket;
}

void RemoteChannel::Disconnect()
{
    if (fd_ != kInvalidSocket)
    {
        CloseSocket(fd_);
    }
}

bool RemoteChannel::Handshake(std::map<std::string, std::string>& settings)
{
    if (fd_ == kInvalidSocket)
    {
        return false;
    }

    SendJson({ { "type", "hello" }, { "version", "1" } });

    // Bound the handshake receive so a missing/unresponsive controller does not hang startup.
    // A timed-out Winsock call leaves the socket indeterminate, so every failure below has to stay fatal.
    SetRecvTimeout(fd_, kHandshakeTimeoutSeconds);

    std::vector<uint8_t> frame;
    if (!RecvFrame(frame))
    {
        GFXRECON_LOG_ERROR("Remote channel: handshake failed waiting for settings");
        return false;
    }

    nlohmann::json msg = nlohmann::json::parse(frame.begin(), frame.end(), nullptr, false);
    if (msg.is_discarded() || !msg.contains("type") || msg["type"] != "settings")
    {
        GFXRECON_LOG_ERROR("Remote channel: handshake received unexpected message");
        return false;
    }

    // Not value(), which throws on a type mismatch: a controller bug should fail the handshake, not kill replay.
    const auto options_entry = msg.find("options");
    if ((options_entry == msg.end()) || !options_entry->is_object())
    {
        GFXRECON_LOG_ERROR("Remote channel: settings message is missing an options object");
        return false;
    }

    // A JSON scalar is a controller-side mistake, never coerced.
    for (const auto& option : options_entry->items())
    {
        if (!option.value().is_string())
        {
            GFXRECON_LOG_ERROR("Remote channel: value of setting \"%s\" is not a string", option.key().c_str());
            return false;
        }
        settings[option.key()] = option.value().get<std::string>();
    }

    if (settings.empty())
    {
        GFXRECON_LOG_ERROR("Remote channel: controller provided no settings");
        return false;
    }

    SendJson({ { "type", "ready" } });

    return true;
}

void RemoteChannel::SendJson(const nlohmann::json& msg)
{
    if (fd_ == kInvalidSocket)
    {
        return;
    }

    std::string                       payload = msg.dump();
    const std::lock_guard<std::mutex> lock(send_mutex_);
    SendFrame(payload.data(), static_cast<uint32_t>(payload.size()));
}

void RemoteChannel::SendDone(bool success)
{
    SendJson({ { "type", "done" }, { "success", success } });
    Disconnect();
}

bool RemoteChannel::SendFrame(const void* data, uint32_t size)
{
    uint32_t length = size; // All target devices are little-endian; no byte-swap needed.
    if (!SendAll(&length, sizeof(length)))
    {
        return false;
    }
    return SendAll(data, size);
}

bool RemoteChannel::RecvFrame(std::vector<uint8_t>& out)
{
    uint32_t length = 0;
    if (!RecvExact(&length, sizeof(length)))
    {
        return false;
    }

    out.resize(length);
    if (length == 0)
    {
        return true;
    }
    return RecvExact(out.data(), length);
}

bool RemoteChannel::SendAll(const void* buf, size_t size)
{
    const uint8_t* ptr       = static_cast<const uint8_t*>(buf);
    size_t         remaining = size;
    while (remaining > 0)
    {
        int64_t sent = SocketSend(fd_, ptr, remaining);
        if (sent <= 0)
        {
            if (sent < 0 && SocketErrorIsInterrupt())
            {
                continue;
            }
            return false;
        }
        ptr += sent;
        remaining -= static_cast<size_t>(sent);
    }
    return true;
}

bool RemoteChannel::RecvExact(void* buf, size_t size)
{
    uint8_t* ptr       = static_cast<uint8_t*>(buf);
    size_t   remaining = size;
    while (remaining > 0)
    {
        int64_t received = SocketRecv(fd_, ptr, remaining);
        if (received <= 0)
        {
            if (received < 0 && SocketErrorIsInterrupt())
            {
                continue;
            }
            return false;
        }
        ptr += received;
        remaining -= static_cast<size_t>(received);
    }
    return true;
}

RemoteChannel* RemoteChannel::active_channel_ = nullptr;

void RemoteChannel::SetActiveChannel(RemoteChannel* channel)
{
    active_channel_ = channel;
}

bool RemoteChannel::IsActive()
{
    return active_channel_ != nullptr && active_channel_->IsConnected();
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
