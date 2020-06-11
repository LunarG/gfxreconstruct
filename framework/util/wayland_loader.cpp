/*
** Copyright (c) 2020 Valve Corporation
** Copyright (c) 2020 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#include "util/wayland_loader.h"

#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

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
        libwayland_ = util::platform::OpenLibrary("libwayland-client.so");
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
            function_table_.compositor_interface = reinterpret_cast<decltype(wl_compositor_interface)*>(
                util::platform::GetProcAddress(libwayland_, "wl_compositor_interface"));
            function_table_.shell_interface = reinterpret_cast<decltype(wl_shell_interface)*>(
                util::platform::GetProcAddress(libwayland_, "wl_shell_interface"));
            function_table_.seat_interface = reinterpret_cast<decltype(wl_seat_interface)*>(
                util::platform::GetProcAddress(libwayland_, "wl_seat_interface"));

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
            function_table_.registry_interface = reinterpret_cast<decltype(wl_registry_interface)*>(
                util::platform::GetProcAddress(libwayland_, "wl_registry_interface"));
            function_table_.keyboard_interface = reinterpret_cast<decltype(wl_keyboard_interface)*>(
                util::platform::GetProcAddress(libwayland_, "wl_keyboard_interface"));
            function_table_.output_interface = reinterpret_cast<decltype(wl_output_interface)*>(
                util::platform::GetProcAddress(libwayland_, "wl_output_interface"));
            function_table_.pointer_interface = reinterpret_cast<decltype(wl_pointer_interface)*>(
                util::platform::GetProcAddress(libwayland_, "wl_pointer_interface"));
            function_table_.shell_surface_interface = reinterpret_cast<decltype(wl_shell_surface_interface)*>(
                util::platform::GetProcAddress(libwayland_, "wl_shell_surface_interface"));
            function_table_.surface_interface = reinterpret_cast<decltype(wl_surface_interface)*>(
                util::platform::GetProcAddress(libwayland_, "wl_surface_interface"));
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
