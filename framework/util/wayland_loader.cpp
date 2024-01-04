/*
** Copyright (c) 2020 Valve Corporation
** Copyright (c) 2020 LunarG, Inc.
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

#include "util/wayland_loader.h"

#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

const std::vector<std::string> kWaylandLibNames = {
#if defined(WAYLAND_LIBRARY)
    WAYLAND_LIBRARY,
#endif
    "libwayland-client.so.0",
    "libwayland-client.so"
};

WaylandLoader::WaylandLoader() : libwayland_(nullptr), function_table_{} {}

WaylandLoader::~WaylandLoader()
{
    if (libwayland_)
    {
        util::platform::CloseLibrary(libwayland_);
        libwayland_ = nullptr;
    }
}

bool WaylandLoader::Initialize()
{
    bool success = true;

    // Guard against double initialization
    if (!libwayland_)
    {
        libwayland_ = util::platform::OpenLibrary(kWaylandLibNames);
        if (libwayland_)
        {
            // Client functions
            function_table_.display_connect = reinterpret_cast<decltype(wl_display_connect)*>(
                util::platform::GetProcAddress(libwayland_, "wl_display_connect"));
            function_table_.display_disconnect = reinterpret_cast<decltype(wl_display_disconnect)*>(
                util::platform::GetProcAddress(libwayland_, "wl_display_disconnect"));
            function_table_.display_dispatch = reinterpret_cast<decltype(wl_display_dispatch)*>(
                util::platform::GetProcAddress(libwayland_, "wl_display_dispatch"));
            function_table_.display_dispatch_pending = reinterpret_cast<decltype(wl_display_dispatch_pending)*>(
                util::platform::GetProcAddress(libwayland_, "wl_display_dispatch_pending"));
            function_table_.display_flush = reinterpret_cast<decltype(wl_display_flush)*>(
                util::platform::GetProcAddress(libwayland_, "wl_display_flush"));
            function_table_.display_roundtrip = reinterpret_cast<decltype(wl_display_roundtrip)*>(
                util::platform::GetProcAddress(libwayland_, "wl_display_roundtrip"));

            // Proxy functions
            function_table_.proxy_add_listener = reinterpret_cast<decltype(wl_proxy_add_listener)*>(
                util::platform::GetProcAddress(libwayland_, "wl_proxy_add_listener"));
            function_table_.proxy_destroy = reinterpret_cast<decltype(wl_proxy_destroy)*>(
                util::platform::GetProcAddress(libwayland_, "wl_proxy_destroy"));
            function_table_.proxy_marshal = reinterpret_cast<decltype(wl_proxy_marshal)*>(
                util::platform::GetProcAddress(libwayland_, "wl_proxy_marshal"));
            function_table_.proxy_marshal_constructor = reinterpret_cast<decltype(wl_proxy_marshal_constructor)*>(
                util::platform::GetProcAddress(libwayland_, "wl_proxy_marshal_constructor"));
            function_table_.proxy_marshal_constructor_versioned =
                reinterpret_cast<decltype(wl_proxy_marshal_constructor_versioned)*>(
                    util::platform::GetProcAddress(libwayland_, "wl_proxy_marshal_constructor_versioned"));

            // Interfaces
            function_table_.compositor_interface = reinterpret_cast<decltype(wl_compositor_interface)*>(
                util::platform::GetProcAddress(libwayland_, "wl_compositor_interface"));
            function_table_.shell_interface = reinterpret_cast<decltype(wl_shell_interface)*>(
                util::platform::GetProcAddress(libwayland_, "wl_shell_interface"));
            function_table_.seat_interface = reinterpret_cast<decltype(wl_seat_interface)*>(
                util::platform::GetProcAddress(libwayland_, "wl_seat_interface"));
            function_table_.registry_interface = reinterpret_cast<decltype(wl_registry_interface)*>(
                util::platform::GetProcAddress(libwayland_, "wl_registry_interface"));
            function_table_.keyboard_interface = reinterpret_cast<decltype(wl_keyboard_interface)*>(
                util::platform::GetProcAddress(libwayland_, "wl_keyboard_interface"));
            function_table_.output_interface = reinterpret_cast<decltype(wl_output_interface)*>(
                util::platform::GetProcAddress(libwayland_, "wl_output_interface"));
            function_table_.pointer_interface = reinterpret_cast<decltype(wl_pointer_interface)*>(
                util::platform::GetProcAddress(libwayland_, "wl_pointer_interface"));
            function_table_.surface_interface = reinterpret_cast<decltype(wl_surface_interface)*>(
                util::platform::GetProcAddress(libwayland_, "wl_surface_interface"));
            function_table_.shell_surface_interface = reinterpret_cast<decltype(wl_shell_surface_interface)*>(
                util::platform::GetProcAddress(libwayland_, "wl_shell_surface_interface"));

            // additional protocols
            function_table_.xdg = std::make_unique<wayland_xdg_shell_table>();
            function_table_.xdg->initialize(this);
        }
        else
        {
            GFXRECON_LOG_DEBUG("Failed to load libwayland-client.so");
            success = false;
        }
    }

    return success;
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
