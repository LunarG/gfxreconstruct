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

#include <catch2/catch.hpp>

#include "decode/api_payload.h"
#include "decode/block_buffer.h"
#include "decode/block_parser.h"
#include "decode/parsed_block.h"
#include "encode/vulkan_direct_driver_info.h"
#include "format/format.h"

#include <cstdint>
#include <cstring>
#include <string>
#include <variant>
#include <vector>

using namespace gfxrecon;

namespace
{

// Build the bytes of one SetDirectDriverInfoCommand block, the way the capture layer writes them.
std::vector<uint8_t> BuildBlock(const encode::DirectDriverRecord& record, format::ThreadId thread_id)
{
    format::SetDirectDriverInfoCommand command = {};
    encode::FillSetDirectDriverInfoCommand(record, thread_id, &command);

    std::vector<uint8_t> bytes(sizeof(command));
    memcpy(bytes.data(), &command, sizeof(command));
    bytes.insert(bytes.end(), record.module_path.begin(), record.module_path.end());
    bytes.insert(bytes.end(), record.symbol_name.begin(), record.symbol_name.end());
    return bytes;
}

} // namespace

TEST_CASE("BlockParser parses SetDirectDriverInfoCommand", "[metadata]")
{
    encode::DirectDriverRecord record;
    record.driver_index    = 1;
    record.driver_count    = 2;
    record.mode            = VK_DIRECT_DRIVER_LOADING_MODE_INCLUSIVE_LUNARG;
    record.flags           = format::kDirectDriverInfoModuleFound | format::kDirectDriverInfoSymbolFound;
    record.capture_address = 0x00007f0012345678ull;
    record.module_offset   = 0x5678;
    record.module_path     = "/opt/vendor/lib/libvendor_icd.so";
    record.symbol_name     = "vk_icdGetInstanceProcAddr";

    std::vector<uint8_t> bytes = BuildBlock(record, 42);

    decode::BlockBuffer block_buffer;
    block_buffer.Reset(bytes.data(), bytes.size());
    REQUIRE(block_buffer.IsValid());

    bool error_triggered = false;
    auto error_handler   = [&error_triggered](decode::BlockIOError, const char*) { error_triggered = true; };
    decode::BlockParser block_parser(error_handler, nullptr);

    const decode::ParsedBlock& parsed = block_parser.ParseBlock(block_buffer);
    REQUIRE_FALSE(error_triggered);

    auto args = std::get_if<decode::SetDirectDriverInfoArgs*>(&parsed.GetArgs());
    REQUIRE(args != nullptr);
    REQUIRE(*args != nullptr);

    const decode::SetDirectDriverInfoArgs& info = **args;
    CHECK(format::GetMetaDataType(info.meta_data_id) == format::MetaDataType::kSetDirectDriverInfoCommand);
    CHECK(format::GetMetaDataApi(info.meta_data_id) == format::ApiFamilyId::ApiFamily_Vulkan);
    CHECK(info.header.thread_id == 42);
    CHECK(info.header.driver_index == 1);
    CHECK(info.header.driver_count == 2);
    CHECK(info.header.mode == VK_DIRECT_DRIVER_LOADING_MODE_INCLUSIVE_LUNARG);
    CHECK(info.header.flags == record.flags);
    CHECK(info.header.capture_address == record.capture_address);
    CHECK(info.header.module_offset == record.module_offset);
    CHECK(info.header.module_path_length == record.module_path.size());
    CHECK(info.header.symbol_name_length == record.symbol_name.size());
    CHECK(info.module_path == record.module_path);
    CHECK(info.symbol_name == record.symbol_name);
}

TEST_CASE("BlockParser parses SetDirectDriverInfoCommand with empty strings", "[metadata]")
{
    // A lookup that fails leaves both strings empty and no flags set.
    encode::DirectDriverRecord record;
    record.driver_count    = 1;
    record.mode            = VK_DIRECT_DRIVER_LOADING_MODE_EXCLUSIVE_LUNARG;
    record.capture_address = 0x1000;

    std::vector<uint8_t> bytes = BuildBlock(record, 1);

    decode::BlockBuffer block_buffer;
    block_buffer.Reset(bytes.data(), bytes.size());
    REQUIRE(block_buffer.IsValid());

    bool error_triggered = false;
    auto error_handler   = [&error_triggered](decode::BlockIOError, const char*) { error_triggered = true; };
    decode::BlockParser block_parser(error_handler, nullptr);

    const decode::ParsedBlock& parsed = block_parser.ParseBlock(block_buffer);
    REQUIRE_FALSE(error_triggered);

    auto args = std::get_if<decode::SetDirectDriverInfoArgs*>(&parsed.GetArgs());
    REQUIRE(args != nullptr);
    REQUIRE(*args != nullptr);

    const decode::SetDirectDriverInfoArgs& info = **args;
    CHECK(info.header.flags == 0);
    CHECK(info.header.module_path_length == 0);
    CHECK(info.header.symbol_name_length == 0);
    CHECK(info.module_path.empty());
    CHECK(info.symbol_name.empty());
}

TEST_CASE("BlockParser reports a truncated SetDirectDriverInfoCommand", "[metadata]")
{
    encode::DirectDriverRecord record;
    record.driver_count = 1;
    record.module_path  = "/some/path/libdriver.so";
    record.symbol_name  = "vk_icdGetInstanceProcAddr";

    std::vector<uint8_t> bytes = BuildBlock(record, 1);

    // Drop the last bytes of the symbol name, but keep the block header size unchanged.
    bytes.resize(bytes.size() - 4);
    auto header  = reinterpret_cast<format::BlockHeader*>(bytes.data());
    header->size = bytes.size() - sizeof(format::BlockHeader);

    decode::BlockBuffer block_buffer;
    block_buffer.Reset(bytes.data(), bytes.size());
    REQUIRE(block_buffer.IsValid());

    bool error_triggered = false;
    auto error_handler   = [&error_triggered](decode::BlockIOError, const char*) { error_triggered = true; };
    decode::BlockParser block_parser(error_handler, nullptr);

    block_parser.ParseBlock(block_buffer);
    CHECK(error_triggered);
}
