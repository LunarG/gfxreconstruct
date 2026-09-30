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

// Loopback tests for RemoteChannel. The test plays the controller with a plain socket and hand-written framing, so the
// wire format is checked against the specification in docs/remote_protocol.md rather than against itself.

#include "util/remote_channel.h"

#include "nlohmann/json.hpp"
#include <catch2/catch.hpp>

#if defined(_WIN32)
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#endif

#include <cstdint>
#include <cstring>
#include <future>
#include <map>
#include <string>
#include <vector>

using namespace gfxrecon;
using nlohmann::json;

namespace
{

// Every blocking call in these tests is bounded: the unit tests run as a post-build step, so a hang would stall the
// build for everyone rather than just failing.
constexpr int kSocketTimeoutSeconds = 10;

#if defined(_WIN32)
using TestSocket                      = SOCKET;
constexpr TestSocket kInvalidTestSock = INVALID_SOCKET;

void CloseTestSocket(TestSocket sock)
{
    closesocket(sock);
}

void SetTestRecvTimeout(TestSocket sock)
{
    DWORD timeout = kSocketTimeoutSeconds * 1000;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, reinterpret_cast<const char*>(&timeout), sizeof(timeout));
}

// RemoteChannel initializes Winsock for its own sockets, but the listener below is created first.
struct WinsockScope
{
    WinsockScope()
    {
        WSADATA data;
        WSAStartup(MAKEWORD(2, 2), &data);
    }
    ~WinsockScope() { WSACleanup(); }
};
#else
using TestSocket                      = int;
constexpr TestSocket kInvalidTestSock = -1;

void CloseTestSocket(TestSocket sock)
{
    close(sock);
}

void SetTestRecvTimeout(TestSocket sock)
{
    timeval timeout = {};
    timeout.tv_sec  = kSocketTimeoutSeconds;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
}
#endif

// The controller half of the connection: binds an ephemeral loopback port, accepts one RemoteChannel, and reads and
// writes length-prefixed frames directly.
class TestController
{
  public:
    TestController()
    {
        listen_fd_ = socket(AF_INET, SOCK_STREAM, 0);
        REQUIRE(listen_fd_ != kInvalidTestSock);

        sockaddr_in addr     = {};
        addr.sin_family      = AF_INET;
        addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
        addr.sin_port        = 0; // Ephemeral: a fixed port would collide with parallel builds and other runs.

        REQUIRE(bind(listen_fd_, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) == 0);
        REQUIRE(listen(listen_fd_, 1) == 0);

        sockaddr_in bound = {};
#if defined(_WIN32)
        int bound_len = sizeof(bound);
#else
        socklen_t bound_len = sizeof(bound);
#endif
        REQUIRE(getsockname(listen_fd_, reinterpret_cast<sockaddr*>(&bound), &bound_len) == 0);
        port_ = ntohs(bound.sin_port);

        SetTestRecvTimeout(listen_fd_);
    }

    ~TestController()
    {
        if (conn_fd_ != kInvalidTestSock)
        {
            CloseTestSocket(conn_fd_);
        }
        if (listen_fd_ != kInvalidTestSock)
        {
            CloseTestSocket(listen_fd_);
        }
    }

    TestController(const TestController&)            = delete;
    TestController& operator=(const TestController&) = delete;

    std::string Address() const
    {
        return "tcp:127.0.0.1:" + std::to_string(port_);
    }

    void Accept()
    {
        conn_fd_ = accept(listen_fd_, nullptr, nullptr);
        REQUIRE(conn_fd_ != kInvalidTestSock);
        SetTestRecvTimeout(conn_fd_);
    }

    bool RecvFrame(std::vector<uint8_t>& out)
    {
        uint32_t length = 0;
        if (!RecvExact(&length, sizeof(length)))
        {
            return false;
        }
        out.resize(length);
        return (length == 0) || RecvExact(out.data(), length);
    }

    json RecvJson()
    {
        std::vector<uint8_t> frame;
        REQUIRE(RecvFrame(frame));
        return json::parse(frame.begin(), frame.end(), nullptr, false);
    }

    void SendFrame(const void* data, uint32_t size)
    {
        std::vector<uint8_t> buffer(sizeof(size) + size);
        std::memcpy(buffer.data(), &size, sizeof(size));
        if (size != 0)
        {
            std::memcpy(buffer.data() + sizeof(size), data, size);
        }
        SendAll(buffer.data(), buffer.size());
    }

    void SendJson(const json& msg)
    {
        const std::string payload = msg.dump();
        SendFrame(payload.data(), static_cast<uint32_t>(payload.size()));
    }

  private:
    bool RecvExact(void* buf, size_t size)
    {
        auto*  bytes     = static_cast<uint8_t*>(buf);
        size_t remaining = size;
        while (remaining > 0)
        {
            const auto received = recv(conn_fd_, reinterpret_cast<char*>(bytes), static_cast<int>(remaining), 0);
            if (received <= 0)
            {
                return false;
            }
            bytes += received;
            remaining -= static_cast<size_t>(received);
        }
        return true;
    }

    void SendAll(const void* buf, size_t size)
    {
        const auto* bytes     = static_cast<const uint8_t*>(buf);
        size_t      remaining = size;
        while (remaining > 0)
        {
            const auto sent = send(conn_fd_, reinterpret_cast<const char*>(bytes), static_cast<int>(remaining), 0);
            REQUIRE(sent > 0);
            bytes += sent;
            remaining -= static_cast<size_t>(sent);
        }
    }

#if defined(_WIN32)
    WinsockScope winsock_;
#endif
    TestSocket listen_fd_{ kInvalidTestSock };
    TestSocket conn_fd_{ kInvalidTestSock };
    uint16_t   port_{ 0 };
};

// Drives Connect() plus Handshake() off the test thread so the test can act as the controller, and bounds the wait so a
// broken handshake fails the test instead of hanging the build.
class ChannelRunner
{
  public:
    ChannelRunner(util::RemoteChannel&                channel,
                  const std::string&                  address,
                  std::map<std::string, std::string>& settings)
    {
        future_ = std::async(std::launch::async, [&channel, address, &settings]() {
            return channel.Connect(address) && channel.Handshake(settings);
        });
    }

    bool Result()
    {
        REQUIRE(future_.wait_for(std::chrono::seconds(kSocketTimeoutSeconds)) == std::future_status::ready);
        return future_.get();
    }

  private:
    std::future<bool> future_;
};

// The hello the tool sends first, after the controller has accepted.
json AcceptAndReadHello(TestController& controller)
{
    controller.Accept();
    return controller.RecvJson();
}

json SettingsMessage()
{
    return json{ { "type", "settings" }, { "options", { { "capture_file", "capture.gfxr" } } } };
}

} // namespace

TEST_CASE("RemoteChannel hello announces the protocol version", "[remote_channel]")
{
    TestController                     controller;
    util::RemoteChannel                channel;
    std::map<std::string, std::string> settings;
    ChannelRunner                      runner(channel, controller.Address(), settings);

    const json hello = AcceptAndReadHello(controller);

    REQUIRE_FALSE(hello.is_discarded());
    CHECK(hello.at("type") == "hello");
    CHECK(hello.at("version") == "1");

    controller.SendJson(SettingsMessage());

    const json ready = controller.RecvJson();
    CHECK(ready.at("type") == "ready");

    CHECK(runner.Result());
    CHECK(settings["capture_file"] == "capture.gfxr");
}

TEST_CASE("RemoteChannel handshake rejects a malformed opening turn", "[remote_channel]")
{
    // Every case here must fail the handshake rather than degrade silently, so a controller bug surfaces at startup.
    SECTION("settings carrying a non-string value")
    {
        TestController                     controller;
        util::RemoteChannel                channel;
        std::map<std::string, std::string> settings;
        ChannelRunner                      runner(channel, controller.Address(), settings);

        AcceptAndReadHello(controller);
        controller.SendJson({ { "type", "settings" }, { "options", { { "loop_count", 3 } } } });

        CHECK_FALSE(runner.Result());
    }

    SECTION("settings with no options at all")
    {
        TestController                     controller;
        util::RemoteChannel                channel;
        std::map<std::string, std::string> settings;
        ChannelRunner                      runner(channel, controller.Address(), settings);

        AcceptAndReadHello(controller);
        controller.SendJson({ { "type", "settings" }, { "options", json::object() } });

        CHECK_FALSE(runner.Result());
    }

    SECTION("an unparseable frame")
    {
        TestController                     controller;
        util::RemoteChannel                channel;
        std::map<std::string, std::string> settings;
        ChannelRunner                      runner(channel, controller.Address(), settings);

        AcceptAndReadHello(controller);
        const std::string garbage = "not json";
        controller.SendFrame(garbage.data(), static_cast<uint32_t>(garbage.size()));

        CHECK_FALSE(runner.Result());
    }
}

TEST_CASE("RemoteChannel sends a file as a header frame followed by its payload", "[remote_channel]")
{
    TestController                     controller;
    util::RemoteChannel                channel;
    std::map<std::string, std::string> settings;
    ChannelRunner                      runner(channel, controller.Address(), settings);

    AcceptAndReadHello(controller);
    controller.SendJson(SettingsMessage());
    REQUIRE(controller.RecvJson().at("type") == "ready");
    REQUIRE(runner.Result());

    // Comfortably larger than a single socket read, so the length prefix has to carry the reassembly.
    std::vector<uint8_t> payload(512 * 1024);
    for (size_t i = 0; i < payload.size(); ++i)
    {
        payload[i] = static_cast<uint8_t>((i * 31) & 0xff);
    }

    channel.SendFile("screenshot.png", payload.data(), payload.size());

    const json header = controller.RecvJson();
    CHECK(header.at("type") == "file");
    CHECK(header.at("name") == "screenshot.png");
    CHECK(header.at("size") == payload.size());

    std::vector<uint8_t> received;
    REQUIRE(controller.RecvFrame(received));
    CHECK(received == payload);
}

TEST_CASE("RemoteChannel reports completion", "[remote_channel]")
{
    TestController                     controller;
    util::RemoteChannel                channel;
    std::map<std::string, std::string> settings;
    ChannelRunner                      runner(channel, controller.Address(), settings);

    AcceptAndReadHello(controller);
    controller.SendJson(SettingsMessage());
    REQUIRE(controller.RecvJson().at("type") == "ready");
    REQUIRE(runner.Result());

    channel.SendDone(true);
    const json done = controller.RecvJson();
    CHECK(done.at("type") == "done");
    CHECK(done.at("success") == true);
}
