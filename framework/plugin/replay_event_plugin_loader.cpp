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

#include "replay_event_sink.h"

#include <util/logging.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(plugin)

struct ReplayEventPluginLoadInfo
{
    std::string library_path;
    std::string plugin_params;
};

static bool IsValidPlugin(const GfxrReplayPluginV1* plugin)
{
    return plugin != nullptr &&
           plugin->abi_version == GFXR_REPLAY_PLUGIN_ABI_VERSION &&
           plugin->struct_size >= sizeof(GfxrReplayPluginV1) &&
           plugin->destroy != nullptr &&
           plugin->on_event != nullptr;
}

std::unique_ptr<ReplayEventSink> LoadPlugin(const ReplayEventPluginLoadInfo& load_info)
{
    if (load_info.library_path.empty())
    {
        GFXRECON_LOG_ERROR("Plugin library path is empty");
        return nullptr;
    }

    auto library = util::platform::OpenLibrary(load_info.library_path.c_str());
    if (library == nullptr)
    {
        GFXRECON_LOG_ERROR("Failed to load plugin library: %s", load_info.library_path.c_str());
        return nullptr;
    }

    auto create_func = reinterpret_cast<PFN_gfxrCreateReplayPluginV1>(
        util::platform::GetProcAddress(library, "gfxrCreateReplayPluginV1"));
    if (create_func == nullptr)
    {
        GFXRECON_LOG_ERROR("Failed to get plugin create function: %s", load_info.library_path.c_str());
        return nullptr;
    }

    GfxrReplayPluginCreateInfo create_info = {};
    create_info.abi_version              = GFXR_REPLAY_PLUGIN_ABI_VERSION;
    create_info.struct_size              = sizeof(GfxrReplayPluginCreateInfo);
    create_info.plugin_params            = load_info.plugin_params.c_str();

    GfxrReplayPluginV1* plugin = create_func(&create_info);
    if (plugin == nullptr)
    {
        GFXRECON_LOG_ERROR("Failed to create plugin instance: %s", load_info.library_path.c_str());
        util::platform::CloseLibrary(library);
        return nullptr;
    }

    if (!IsValidPlugin(plugin))
    {
        GFXRECON_LOG_ERROR("Invalid plugin instance: %s", load_info.library_path.c_str());
        util::platform::CloseLibrary(library);
        return nullptr;
    }

    return std::make_unique<PluginReplayEventSink>(library, plugin);
}

GFXRECON_END_NAMESPACE(plugin)
GFXRECON_END_NAMESPACE(gfxrecon)