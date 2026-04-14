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

#ifndef GFXRECON_REPLAY_EVENT_PLUGIN_LOADER_H
#define GFXRECON_REPLAY_EVENT_PLUGIN_LOADER_H

#include <string>
#include <util/defines.h>

#include "replay_event_sink.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(plugin)

struct ReplayEventPluginLoadInfo
{
    std::string library_path;
    std::string plugin_params;
};

std::unique_ptr<ReplayEventSink> LoadPlugin(const ReplayEventPluginLoadInfo& load_info);

struct ReplayEventPluginLoadOps
{
    util::platform::LibraryHandle (*open_library)(const char* library_path);
    void* (*get_proc_address)(util::platform::LibraryHandle library, const char* symbol_name);
    void (*close_library)(util::platform::LibraryHandle library);
};

std::unique_ptr<ReplayEventSink> LoadPlugin(const ReplayEventPluginLoadInfo& load_info,
                                            const ReplayEventPluginLoadOps&  ops);

GFXRECON_END_NAMESPACE(plugin)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_REPLAY_EVENT_PLUGIN_LOADER_H
