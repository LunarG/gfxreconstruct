/*
** Copyright (c) 2026 LunarG, Inc.
** Copyright (c) 2026 Google LLC
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

#if defined(__linux__)
#ifndef __ANDROID__
#define GFXR_TEST_BYPASS_ANDROID_CHECK
#endif

// Include the source directly so we can test the unexported struct parser
#include "../renderdoc/renderdoc_replay_plugin.cpp"

#ifdef GFXR_TEST_BYPASS_ANDROID_CHECK
#undef GFXR_TEST_BYPASS_ANDROID_CHECK
#endif

TEST_CASE("RenderDoc Replay Plugin - Create", "[plugin][renderdoc]")
{
    GfxrReplayPluginCreateInfo create_info = {};
    create_info.abi_version                = GFXR_REPLAY_PLUGIN_ABI_VERSION;
    create_info.struct_size                = sizeof(GfxrReplayPluginCreateInfo);

    // Provide some synthetic parameters
    create_info.plugin_params = "libcustom.so;frame=42";

    GfxrReplayPluginV1* plugin = gfxrCreateReplayPluginV1(&create_info);
    REQUIRE(plugin != nullptr);
    REQUIRE(plugin->abi_version == GFXR_REPLAY_PLUGIN_ABI_VERSION);
    REQUIRE(plugin->destroy != nullptr);
    REQUIRE(plugin->on_event != nullptr);

    // Cast to the internal struct type to verify parsing success
    RenderDocCapturePlugin* rdoc_plugin = reinterpret_cast<RenderDocCapturePlugin*>(plugin);
    REQUIRE(rdoc_plugin->renderdoc_lib_path == "libcustom.so");
    REQUIRE(rdoc_plugin->target_frame == 42);

    // Cleanup
    plugin->destroy(plugin);
}
#endif
