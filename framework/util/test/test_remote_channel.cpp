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

#include <catch2/catch.hpp>

#include "util/remote_channel.h"

#include "util/logging.h"
#include "util/output_file.h"

#include "nlohmann/json.hpp"

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
#include <filesystem>
#include <future>
#include <map>
#include <memory>
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

    // A length prefix with no payload, for frames too large to actually send.
    void SendLengthPrefix(uint32_t length)
    {
        SendAll(&length, sizeof(length));
    }

    void Close()
    {
        CloseTestSocket(conn_fd_);
        conn_fd_ = kInvalidTestSock;
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

// Clears the process-wide channel even when a failed REQUIRE unwinds the test, so later tests never see a dead one.
class ActiveChannelScope
{
  public:
    explicit ActiveChannelScope(util::RemoteChannel& channel) { util::RemoteChannel::SetActiveChannel(&channel); }
    ~ActiveChannelScope() { util::RemoteChannel::SetActiveChannel(nullptr); }

    ActiveChannelScope(const ActiveChannelScope&)            = delete;
    ActiveChannelScope& operator=(const ActiveChannelScope&) = delete;
};

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

TEST_CASE("OpenOutputFile sends the whole file to the active channel when the stream is destroyed", "[remote_channel]")
{
    TestController                     controller;
    util::RemoteChannel                channel;
    std::map<std::string, std::string> settings;
    ChannelRunner                      runner(channel, controller.Address(), settings);

    AcceptAndReadHello(controller);
    controller.SendJson(SettingsMessage());
    REQUIRE(controller.RecvJson().at("type") == "ready");
    REQUIRE(runner.Result());

    {
        ActiveChannelScope active(channel);

        std::unique_ptr<util::OutputStream> stream = util::OpenOutputFile("results.json", util::FileWriteMode::kText);
        REQUIRE(stream->IsValid());

        util::Write(*stream, "[\n");
        stream->Flush(); // The screenshot JSON flushes after every block; that must not send a partial file.
        util::Write(*stream, "]");
    }

    const std::string expected = "[\n]";

    const json header = controller.RecvJson();
    CHECK(header.at("type") == "file");
    CHECK(header.at("name") == "results.json");
    CHECK(header.at("size") == expected.size());

    std::vector<uint8_t> received;
    REQUIRE(controller.RecvFrame(received));
    CHECK(std::string(received.begin(), received.end()) == expected);
}

TEST_CASE("RemoteChannel reports status and completion", "[remote_channel]")
{
    TestController                     controller;
    util::RemoteChannel                channel;
    std::map<std::string, std::string> settings;
    ChannelRunner                      runner(channel, controller.Address(), settings);

    AcceptAndReadHello(controller);
    controller.SendJson(SettingsMessage());
    REQUIRE(controller.RecvJson().at("type") == "ready");
    REQUIRE(runner.Result());

    channel.SendStatus("paused", 42, 1337);
    const json status = controller.RecvJson();
    CHECK(status.at("type") == "status");
    CHECK(status.at("state") == "paused");
    CHECK(status.at("frame") == 42);
    CHECK(status.at("block") == 1337);

    channel.SendDone(true);
    const json done = controller.RecvJson();
    CHECK(done.at("type") == "done");
    CHECK(done.at("success") == true);
}

TEST_CASE("RemoteChannel queues control actions from the controller", "[remote_channel]")
{
    TestController                     controller;
    util::RemoteChannel                channel;
    std::map<std::string, std::string> settings;
    ChannelRunner                      runner(channel, controller.Address(), settings);

    AcceptAndReadHello(controller);
    controller.SendJson(SettingsMessage());
    REQUIRE(controller.RecvJson().at("type") == "ready");
    REQUIRE(runner.Result());

    controller.SendJson({ { "type", "control" }, { "action", "pause" } });

    std::string action;
    CHECK(channel.WaitPopControl(&action, std::chrono::seconds(kSocketTimeoutSeconds)));
    CHECK(action == "pause");

    // Actions are delivered in the order the controller sent them.
    controller.SendJson({ { "type", "control" }, { "action", "step" } });
    controller.SendJson({ { "type", "control" }, { "action", "resume" } });

    CHECK(channel.WaitPopControl(&action, std::chrono::seconds(kSocketTimeoutSeconds)));
    CHECK(action == "step");
    CHECK(channel.WaitPopControl(&action, std::chrono::seconds(kSocketTimeoutSeconds)));
    CHECK(action == "resume");
}

TEST_CASE("RemoteChannel ignores malformed control messages", "[remote_channel]")
{
    TestController                     controller;
    util::RemoteChannel                channel;
    std::map<std::string, std::string> settings;
    ChannelRunner                      runner(channel, controller.Address(), settings);

    AcceptAndReadHello(controller);
    controller.SendJson(SettingsMessage());
    REQUIRE(controller.RecvJson().at("type") == "ready");
    REQUIRE(runner.Result());

    const std::string not_json = "not json";
    controller.SendFrame(not_json.data(), static_cast<uint32_t>(not_json.size()));
    controller.SendJson({ { "type", "control" } });
    controller.SendJson({ { "type", "control" }, { "action", 5 } });
    controller.SendJson({ { "type", "control" }, { "action", "" } });
    controller.SendJson({ { "type", "control" }, { "action", "pause" } });

    // Only the valid action arrives, which also shows the receiver thread survived the others.
    std::string action;
    CHECK(channel.WaitPopControl(&action, std::chrono::seconds(kSocketTimeoutSeconds)));
    CHECK(action == "pause");
    CHECK_FALSE(channel.TryPopControl(&action));
    CHECK(channel.IsConnected());
}

TEST_CASE("RemoteChannel rejects an oversized frame from the controller", "[remote_channel]")
{
    TestController                     controller;
    util::RemoteChannel                channel;
    std::map<std::string, std::string> settings;
    ChannelRunner                      runner(channel, controller.Address(), settings);

    AcceptAndReadHello(controller);
    controller.SendLengthPrefix(0xFFFFFFFF);

    CHECK_FALSE(runner.Result());
}

TEST_CASE("RemoteChannel reports when the controller closes", "[remote_channel]")
{
    TestController                     controller;
    util::RemoteChannel                channel;
    std::map<std::string, std::string> settings;
    ChannelRunner                      runner(channel, controller.Address(), settings);

    AcceptAndReadHello(controller);
    controller.SendJson(SettingsMessage());
    REQUIRE(controller.RecvJson().at("type") == "ready");
    REQUIRE(runner.Result());
    CHECK_FALSE(channel.IsControllerClosed());

    controller.Close();

    // The close wakes the wait early rather than letting it run out the timeout.
    const auto  start = std::chrono::steady_clock::now();
    std::string action;
    CHECK_FALSE(channel.WaitPopControl(&action, std::chrono::seconds(kSocketTimeoutSeconds)));
    CHECK(std::chrono::steady_clock::now() - start < std::chrono::seconds(kSocketTimeoutSeconds / 2));
    CHECK(channel.IsControllerClosed());
    CHECK_FALSE(channel.IsConnected());
}

TEST_CASE("RemoteChannel reports progress on the active channel", "[remote_channel]")
{
    TestController                     controller;
    util::RemoteChannel                channel;
    std::map<std::string, std::string> settings;
    ChannelRunner                      runner(channel, controller.Address(), settings);

    AcceptAndReadHello(controller);
    controller.SendJson(SettingsMessage());
    REQUIRE(controller.RecvJson().at("type") == "ready");
    REQUIRE(runner.Result());

    {
        ActiveChannelScope active(channel);
        util::RemoteChannel::SendActiveProgress("dump_resources", 3, 7);
    }

    const json progress = controller.RecvJson();
    CHECK(progress.at("type") == "progress");
    CHECK(progress.at("operation") == "dump_resources");
    CHECK(progress.at("current") == 3);
    CHECK(progress.at("total") == 7);
}

TEST_CASE("RemoteChannel relays log output from the logging target", "[remote_channel]")
{
    TestController                     controller;
    util::RemoteChannel                channel;
    std::map<std::string, std::string> settings;
    ChannelRunner                      runner(channel, controller.Address(), settings);

    AcceptAndReadHello(controller);
    controller.SendJson(SettingsMessage());
    REQUIRE(controller.RecvJson().at("type") == "ready");
    REQUIRE(runner.Result());

    // Other tests leave the process-wide log level raised.
    util::Log::Init(util::LoggingSeverity::kInfo);
    {
        ActiveChannelScope active(channel);
        GFXRECON_LOG_WARNING("relayed %d", 7);
        GFXRECON_WRITE_CONSOLE("console");
    }
    util::Log::Release();

    const json warning = controller.RecvJson();
    CHECK(warning.at("type") == "log");
    CHECK(warning.at("level") == "warning");
    CHECK(warning.at("message").get<std::string>().find("relayed 7") != std::string::npos);

    // Output the log level never filters has no level of its own.
    const json console = controller.RecvJson();
    CHECK(console.at("type") == "log");
    CHECK(console.at("level") == "info");
    CHECK(console.at("message") == "console");
}

TEST_CASE("RemoteChannel replaces invalid UTF-8 instead of failing", "[remote_channel]")
{
    TestController                     controller;
    util::RemoteChannel                channel;
    std::map<std::string, std::string> settings;
    ChannelRunner                      runner(channel, controller.Address(), settings);

    AcceptAndReadHello(controller);
    controller.SendJson(SettingsMessage());
    REQUIRE(controller.RecvJson().at("type") == "ready");
    REQUIRE(runner.Result());

    channel.SendLog(util::LoggingSeverity::kInfo, "bad \xff byte");
    const json log = controller.RecvJson();
    CHECK(log.at("message") == "bad \xEF\xBF\xBD byte");

    channel.SendDone(true);
    CHECK(controller.RecvJson().at("type") == "done");
}

TEST_CASE("OpenOutputFile writes nothing to disk after the controller closes", "[remote_channel]")
{
    TestController                     controller;
    util::RemoteChannel                channel;
    std::map<std::string, std::string> settings;
    ChannelRunner                      runner(channel, controller.Address(), settings);

    AcceptAndReadHello(controller);
    controller.SendJson(SettingsMessage());
    REQUIRE(controller.RecvJson().at("type") == "ready");
    REQUIRE(runner.Result());

    controller.Close();
    std::string action;
    channel.WaitPopControl(&action, std::chrono::seconds(kSocketTimeoutSeconds));
    REQUIRE(channel.IsControllerClosed());

    const std::filesystem::path path =
        std::filesystem::temp_directory_path() / "gfxrecon_test_remote_channel_discarded.bin";
    std::filesystem::remove(path);

    {
        ActiveChannelScope                  active(channel);
        std::unique_ptr<util::OutputStream> stream = util::OpenOutputFile(path.string());
        util::Write(*stream, "dropped");
    }

    CHECK_FALSE(std::filesystem::exists(path));
}
