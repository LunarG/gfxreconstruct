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

#include "format/api_call_log.h"

#include <catch2/catch.hpp>

#include <cstring>
#include <vector>

using gfxrecon::format::ApiCallId;
using gfxrecon::format::ApiCallLog;

namespace
{
struct RecordedEntry
{
    ApiCallId            call_id;
    std::vector<uint8_t> parameters;
};

struct TestMeta
{
    uint64_t index{ 0 };
    uint64_t thread_id{ 0 };
};
} // namespace

TEST_CASE("an empty ApiCallLog visits nothing", "[api_call_log]")
{
    ApiCallLog<> log;
    REQUIRE(log.IsEmpty());

    size_t visit_count = 0;
    log.ForEach([&](ApiCallId, const uint8_t*, size_t) { ++visit_count; });
    REQUIRE(visit_count == 0);
}

TEST_CASE("ApiCallLog round-trips entries in append order", "[api_call_log]")
{
    const std::vector<RecordedEntry> entries = {
        { ApiCallId::ApiCall_vkCmdBindPipeline, { 0x01, 0x02, 0x03 } },
        { ApiCallId::ApiCall_vkCmdDraw, {} },
        { ApiCallId::ApiCall_vkCmdDispatch, { 0xff, 0x00, 0xaa, 0xbb, 0xcc } },
    };

    ApiCallLog<> log;
    for (const auto& entry : entries)
    {
        log.Append(entry.call_id, entry.parameters.data(), entry.parameters.size());
    }
    REQUIRE(!log.IsEmpty());

    size_t index = 0;
    log.ForEach([&](ApiCallId call_id, const uint8_t* parameter_data, size_t parameter_size) {
        REQUIRE(index < entries.size());
        REQUIRE(call_id == entries[index].call_id);
        REQUIRE(parameter_size == entries[index].parameters.size());
        REQUIRE(std::memcmp(parameter_data, entries[index].parameters.data(), parameter_size) == 0);
        ++index;
    });
    REQUIRE(index == entries.size());

    log.Clear();
    REQUIRE(log.IsEmpty());
}

TEST_CASE("ApiCallLog round-trips per-entry metadata", "[api_call_log]")
{
    const std::vector<uint8_t> parameters = { 0x10, 0x20, 0x30, 0x40 };

    ApiCallLog<TestMeta> log;
    log.Append(ApiCallId::ApiCall_vkCmdBindDescriptorSets, TestMeta{ 42, 7 }, parameters.data(), parameters.size());
    log.Append(ApiCallId::ApiCall_vkCmdBindIndexBuffer, TestMeta{ 43, 8 }, parameters.data(), 0);

    size_t index = 0;
    log.ForEach([&](ApiCallId call_id, const TestMeta& meta, const uint8_t* parameter_data, size_t parameter_size) {
        if (index == 0)
        {
            REQUIRE(call_id == ApiCallId::ApiCall_vkCmdBindDescriptorSets);
            REQUIRE(meta.index == 42);
            REQUIRE(meta.thread_id == 7);
            REQUIRE(parameter_size == parameters.size());
            REQUIRE(std::memcmp(parameter_data, parameters.data(), parameter_size) == 0);
        }
        else
        {
            REQUIRE(call_id == ApiCallId::ApiCall_vkCmdBindIndexBuffer);
            REQUIRE(meta.index == 43);
            REQUIRE(meta.thread_id == 8);
            REQUIRE(parameter_size == 0);
        }
        ++index;
    });
    REQUIRE(index == 2);
}
