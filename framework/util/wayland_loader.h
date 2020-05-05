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

#ifndef GFXRECON_UTIL_WAYLAND_LOADER_H
#define GFXRECON_UTIL_WAYLAND_LOADER_H

#include "util/defines.h"
#include "util/platform.h"

#include <wayland-client.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class WaylandLoader
{
  public:
    class FunctionTable
    {
      public:
        // client functions
        decltype(wl_display_connect)*          display_connect;
        decltype(wl_display_disconnect)*       display_disconnect;
        decltype(wl_display_dispatch)*         display_dispatch;
        decltype(wl_display_dispatch_pending)* display_dispatch_pending;
        decltype(wl_display_flush)*            display_flush;
        decltype(wl_display_roundtrip)*        display_roundtrip;
        decltype(wl_compositor_interface)*     compositor_interface;
        decltype(wl_shell_interface)*          shell_interface;
        decltype(wl_seat_interface)*           seat_interface;

        // proxy functions
        decltype(wl_proxy_add_listener)*                  proxy_add_listener;
        decltype(wl_proxy_destroy)*                       proxy_destroy;
        decltype(wl_proxy_marshal)*                       proxy_marshal;
        decltype(wl_proxy_marshal_constructor)*           proxy_marshal_constructor;
        decltype(wl_proxy_marshal_constructor_versioned)* proxy_marshal_constructor_versioned;

        // interfaces
        decltype(wl_registry_interface)*      registry_interface;
        decltype(wl_keyboard_interface)*      keyboard_interface;
        decltype(wl_output_interface)*        output_interface;
        decltype(wl_pointer_interface)*       pointer_interface;
        decltype(wl_shell_surface_interface)* shell_surface_interface;
        decltype(wl_surface_interface)*       surface_interface;

        // inline functions, adapted from wayland-client-protocol.h
        struct wl_surface* compositor_create_surface(struct wl_compositor* wl_compositor) const
        {
            struct wl_proxy* id;

            id = this->proxy_marshal_constructor(reinterpret_cast<struct wl_proxy*>(wl_compositor),
                                                 WL_COMPOSITOR_CREATE_SURFACE,
                                                 this->surface_interface,
                                                 NULL);

            return reinterpret_cast<struct wl_surface*>(id);
        }

        void compositor_destroy(struct wl_compositor* wl_compositor) const
        {
            this->proxy_destroy(reinterpret_cast<struct wl_proxy*>(wl_compositor));
        }

        struct wl_registry* display_get_registry(struct wl_display* wl_display) const
        {
            struct wl_proxy* registry;

            registry = this->proxy_marshal_constructor(reinterpret_cast<struct wl_proxy*>(wl_display),
                                                       WL_DISPLAY_GET_REGISTRY,
                                                       this->registry_interface,
                                                       NULL);

            return reinterpret_cast<struct wl_registry*>(registry);
        }

        int
        keyboard_add_listener(struct wl_keyboard* wl_keyboard, struct wl_keyboard_listener* listener, void* data) const
        {
            return this->proxy_add_listener(
                reinterpret_cast<struct wl_proxy*>(wl_keyboard), reinterpret_cast<void (**)(void)>(listener), data);
        }

        void keyboard_destroy(struct wl_keyboard* wl_keyboard) const
        {
            this->proxy_destroy(reinterpret_cast<struct wl_proxy*>(wl_keyboard));
        }

        int output_add_listener(struct wl_output* wl_output, struct wl_output_listener* listener, void* data) const
        {
            return this->proxy_add_listener(
                reinterpret_cast<struct wl_proxy*>(wl_output), reinterpret_cast<void (**)(void)>(listener), data);
        }

        int pointer_add_listener(struct wl_pointer* wl_pointer, wl_pointer_listener* listener, void* data) const
        {
            return this->proxy_add_listener(
                reinterpret_cast<struct wl_proxy*>(wl_pointer), reinterpret_cast<void (**)(void)>(listener), data);
        }

        void pointer_destroy(struct wl_pointer* wl_pointer) const
        {
            this->proxy_destroy(reinterpret_cast<struct wl_proxy*>(wl_pointer));
        }

        int
        registry_add_listener(struct wl_registry* wl_registry, struct wl_registry_listener* listener, void* data) const
        {
            return this->proxy_add_listener(
                reinterpret_cast<struct wl_proxy*>(wl_registry), reinterpret_cast<void (**)(void)>(listener), data);
        }

        void* registry_bind(struct wl_registry*        wl_registry,
                            uint32_t                   name,
                            const struct wl_interface* interface,
                            uint32_t                   version) const
        {
            struct wl_proxy* id;

            id = this->proxy_marshal_constructor_versioned(reinterpret_cast<struct wl_proxy*>(wl_registry),
                                                           WL_REGISTRY_BIND,
                                                           interface,
                                                           version,
                                                           name,
                                                           interface->name,
                                                           version,
                                                           NULL);

            return (void*)id;
        }

        void registry_destroy(struct wl_registry* wl_registry) const
        {
            this->proxy_destroy(reinterpret_cast<struct wl_proxy*>(wl_registry));
        }

        int seat_add_listener(struct wl_seat* wl_seat, struct wl_seat_listener* listener, void* data) const
        {
            return proxy_add_listener(
                reinterpret_cast<struct wl_proxy*>(wl_seat), reinterpret_cast<void (**)(void)>(listener), data);
        }

        void seat_destroy(struct wl_seat* wl_seat) const
        {
            this->proxy_destroy(reinterpret_cast<struct wl_proxy*>(wl_seat));
        }

        struct wl_keyboard* seat_get_keyboard(struct wl_seat* wl_seat) const
        {
            struct wl_proxy* id;

            id = this->proxy_marshal_constructor(
                reinterpret_cast<struct wl_proxy*>(wl_seat), WL_SEAT_GET_KEYBOARD, this->keyboard_interface, NULL);

            return reinterpret_cast<struct wl_keyboard*>(id);
        }

        struct wl_pointer* seat_get_pointer(struct wl_seat* wl_seat) const
        {
            struct wl_proxy* id;

            id = this->proxy_marshal_constructor(
                reinterpret_cast<struct wl_proxy*>(wl_seat), WL_SEAT_GET_POINTER, this->pointer_interface, NULL);

            return reinterpret_cast<struct wl_pointer*>(id);
        }

        void shell_destroy(struct wl_shell* wl_shell) const
        {
            this->proxy_destroy(reinterpret_cast<struct wl_proxy*>(wl_shell));
        }

        struct wl_shell_surface* shell_get_shell_surface(struct wl_shell* wl_shell, struct wl_surface* surface) const
        {
            struct wl_proxy* id;

            id = this->proxy_marshal_constructor(reinterpret_cast<struct wl_proxy*>(wl_shell),
                                                 WL_SHELL_GET_SHELL_SURFACE,
                                                 this->shell_surface_interface,
                                                 NULL,
                                                 surface);

            return reinterpret_cast<struct wl_shell_surface*>(id);
        }

        int shell_surface_add_listener(struct wl_shell_surface*          wl_shell_surface,
                                       struct wl_shell_surface_listener* listener,
                                       void*                             data) const
        {
            return this->proxy_add_listener(reinterpret_cast<struct wl_proxy*>(wl_shell_surface),
                                            reinterpret_cast<void (**)(void)>(listener),
                                            data);
        }

        void shell_surface_destroy(struct wl_shell_surface* wl_shell_surface) const
        {
            this->proxy_destroy(reinterpret_cast<struct wl_proxy*>(wl_shell_surface));
        }

        void shell_surface_move(struct wl_shell_surface* wl_shell_surface, struct wl_seat* seat, uint32_t serial) const
        {
            this->proxy_marshal(
                reinterpret_cast<struct wl_proxy*>(wl_shell_surface), WL_SHELL_SURFACE_MOVE, seat, serial);
        }

        void shell_surface_pong(struct wl_shell_surface* wl_shell_surface, uint32_t serial) const
        {
            this->proxy_marshal(reinterpret_cast<struct wl_proxy*>(wl_shell_surface), WL_SHELL_SURFACE_PONG, serial);
        }

        void shell_surface_set_fullscreen(struct wl_shell_surface* wl_shell_surface,
                                          uint32_t                 method,
                                          uint32_t                 framerate,
                                          struct wl_output*        output) const
        {
            this->proxy_marshal(reinterpret_cast<struct wl_proxy*>(wl_shell_surface), WL_SHELL_SURFACE_SET_FULLSCREEN);
        }

        void shell_surface_set_title(struct wl_shell_surface* wl_shell_surface, const char* title) const
        {
            this->proxy_marshal(
                reinterpret_cast<struct wl_proxy*>(wl_shell_surface), WL_SHELL_SURFACE_SET_TITLE, title);
        }

        void shell_surface_set_toplevel(struct wl_shell_surface* wl_shell_surface) const
        {
            this->proxy_marshal(reinterpret_cast<struct wl_proxy*>(wl_shell_surface), WL_SHELL_SURFACE_SET_TOPLEVEL);
        }

        int surface_add_listener(struct wl_surface* wl_surface, struct wl_surface_listener* listener, void* data) const
        {
            return this->proxy_add_listener(
                reinterpret_cast<struct wl_proxy*>(wl_surface), reinterpret_cast<void (**)(void)>(listener), data);
        }

        void surface_set_buffer_scale(struct wl_surface* wl_surface, int32_t scale) const
        {
            this->proxy_marshal(reinterpret_cast<struct wl_proxy*>(wl_surface), WL_SURFACE_SET_BUFFER_SCALE, scale);
        }

        void surface_destroy(struct wl_surface* wl_surface) const
        {
            this->proxy_marshal(reinterpret_cast<struct wl_proxy*>(wl_surface), WL_SURFACE_DESTROY);

            this->proxy_destroy(reinterpret_cast<struct wl_proxy*>(wl_surface));
        }
    };

  public:
    WaylandLoader();

    ~WaylandLoader();

    bool Initialize();

    const FunctionTable& GetFunctionTable() const { return function_table_; }

  private:
    util::platform::LibraryHandle libwayland_;
    FunctionTable                 function_table_;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_WAYLAND_LOADER_H
