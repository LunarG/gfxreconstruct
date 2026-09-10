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

#include <gtest/gtest.h>

#include "verify-gfxr.h"

// These tests feed small documents through the same parse callback that the capture comparison
// uses. They need no app, no driver and no capture file.

static nlohmann::json normalize(const char* text)
{
    return nlohmann::json::parse(text, clean_gfxr_json);
}

TEST(JsonNormalizer, DropsIgnoredKeysAndKeepsTheRest)
{
    auto result = normalize(R"([{"index": 1, "args": {"hwnd": 7, "fd": 3, "ppData": "0x1", "keep": 2}}])");
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[0]["args"], nlohmann::json::parse(R"({"keep": 2})"));
}

TEST(JsonNormalizer, DropsIgnoredKeysAtAnyDepth)
{
    auto result = normalize(R"([{"index": 1, "a": {"b": {"apiVersion": 1, "pipelineCacheUUID": [1, 2], "c": 3}}}])");
    EXPECT_EQ(result[0]["a"]["b"], nlohmann::json::parse(R"({"c": 3})"));
}

TEST(JsonNormalizer, DropsFunctionPointerKeysByPrefix)
{
    auto result = normalize(R"([{"index": 1, "args": {"pfnCallback": "0x1", "pfnUserCallback": "0x2", "flags": 0}}])");
    EXPECT_EQ(result[0]["args"], nlohmann::json::parse(R"({"flags": 0})"));
}

TEST(JsonNormalizer, KeepsKeysThatOnlyContainAnIgnoredName)
{
    auto result = normalize(R"([{"index": 1, "args": {"apiVersionCount": 1, "myfd": 2, "xpfn": 3}}])");
    EXPECT_EQ(result[0]["args"], nlohmann::json::parse(R"({"apiVersionCount": 1, "myfd": 2, "xpfn": 3})"));
}

TEST(JsonNormalizer, DropsHeaderAndAnnotationBlocks)
{
    auto result = normalize(R"([
        {"header": {"source-path": "/tmp/a.gfxr", "gfxrecon-version": "1.0.5-dev"}},
        {"index": 0, "meta": {"name": "SetDeviceMemoryProperties"}},
        {"index": 1, "annotation": {"label": "x", "data": "y"}},
        {"index": 2, "function": {"name": "vkCreateInstance"}}
    ])");
    ASSERT_EQ(result.size(), 2);
    EXPECT_TRUE(result[0].contains("meta"));
    EXPECT_TRUE(result[1].contains("function"));
}

TEST(JsonNormalizer, KeepsNestedObjectsThatUseTheBlockKeyNames)
{
    // Only a top-level block is dropped. A nested object with the same key name stays.
    auto result = normalize(R"([{"index": 1, "args": {"header": 1, "annotation": 2}}])");
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[0]["args"], nlohmann::json::parse(R"({"header": 1, "annotation": 2})"));
}

TEST(JsonNormalizer, DropsTheAhbBufferOnlyAfterItsMarker)
{
    auto result = normalize(R"([
        {"index": 1, "args": {"sType": "VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID", "buffer": "0x1"}},
        {"index": 2, "args": {"buffer": "0x2", "size": 4}}
    ])");
    ASSERT_EQ(result.size(), 2);
    EXPECT_FALSE(result[0]["args"].contains("buffer"));
    EXPECT_EQ(result[1]["args"], nlohmann::json::parse(R"({"buffer": "0x2", "size": 4})"));
}

TEST(JsonNormalizer, DropsTheAhbBufferAfterThePropertiesCall)
{
    auto result = normalize(R"([
        {"index": 1, "function": {"name": "vkGetAndroidHardwareBufferPropertiesANDROID", "args": {"buffer": "0x1", "device": 1}}}
    ])");
    EXPECT_EQ(result[0]["function"]["args"], nlohmann::json::parse(R"({"device": 1})"));
}

TEST(JsonNormalizer, TwoNormalizedDocumentsCompareEqual)
{
    // The same capture from two runs differs only in the ignored fields.
    auto first =
        normalize(R"([{"header": {"source-path": "/a"}}, {"index": 1, "args": {"ppData": "0x1", "size": 8}}])");
    auto second =
        normalize(R"([{"header": {"source-path": "/b"}}, {"index": 1, "args": {"ppData": "0x2", "size": 8}}])");
    EXPECT_EQ(nlohmann::json::diff(first, second).size(), 0);
}
