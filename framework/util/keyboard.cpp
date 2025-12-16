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

#include "util/keyboard.h"

#include "util/logging.h"
#include "util/platform.h"
#include "util/strings.h"

#if defined(VK_USE_PLATFORM_XCB_KHR)
#include <X11/keysym.h>
#if defined(VK_USE_PLATFORM_XLIB_KHR)
#include <X11/Xlib-xcb.h>
#endif
#endif
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
#include <linux/input-event-codes.h>
#endif

#if defined(VK_USE_PLATFORM_METAL_EXT)
#include <Carbon/Carbon.h>
#endif

#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

const std::vector<std::string> kX11XcbLibNames = {
#if defined(X11_XCB_LIBRARY)
    X11_XCB_LIBRARY,
#endif
    "libX11-xcb.so.1",
    "libX11-xcb.so"
};

#if defined(VK_USE_PLATFORM_XCB_KHR)
bool Keyboard::Initialize(xcb_connection_t* connection)
{
    if (xcb_keysyms_loader_.Initialize())
    {
        xcb_connection_ = connection;
        return true;
    }
    return false;
}
#endif

#if defined(VK_USE_PLATFORM_XLIB_KHR)
bool Keyboard::Initialize(Display* display)
{
#if defined(VK_USE_PLATFORM_XCB_KHR)
    // TODO: Native Xlib support
    auto xlib_xcb = util::platform::OpenLibrary(kX11XcbLibNames);
    if (xlib_xcb)
    {
        // Convert X display to XCB connection
        auto x_get_xcb_connection = reinterpret_cast<decltype(XGetXCBConnection)*>(
            util::platform::GetProcAddress(xlib_xcb, "XGetXCBConnection"));
        auto xcb_connection = x_get_xcb_connection(display);
        util::platform::CloseLibrary(xlib_xcb);

        // Initialize using XCB keyboard implementation
        return Initialize(xcb_connection);
    }
#else
    GFXRECON_UNREFERENCED_PARAMETER(display);
    GFXRECON_LOG_WARNING("Xlib-XCB interop is not enabled on this system");
#endif
    return false;
}
#endif

#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
struct wl_keyboard_listener Keyboard::wayland_keyboard_listener_;
struct wl_seat_listener     Keyboard::wayland_seat_listener_;
struct wl_registry_listener Keyboard::wayland_registry_listener_;

bool Keyboard::Initialize(struct wl_display* display)
{
    wayland_display_ = display;
    bool success     = wayland_loader_.Initialize();
    if (success)
    {
        // Populate callback structs.
        wayland_registry_listener_.global        = HandleRegistryGlobal;
        wayland_registry_listener_.global_remove = HandleRegistryGlobalRemove;

        wayland_seat_listener_.capabilities = HandleSeatCapabilities;

        wayland_keyboard_listener_.keymap    = HandleKeyboardKeymap;
        wayland_keyboard_listener_.enter     = HandleKeyboardEnter;
        wayland_keyboard_listener_.leave     = HandleKeyboardLeave;
        wayland_keyboard_listener_.key       = HandleKeyboardKey;
        wayland_keyboard_listener_.modifiers = HandleKeyboardModifiers;

        auto& wl = GetWaylandFunctionTable();

        // Because we are adding our own keyboard listener to the intercepted wl_display_, we create an event queue that
        // is separate from the default one, as well as create a 'wrapped' wl_display to bind to

        wayland_event_queue_ = wl.display_create_queue(wayland_display_);
        if (wayland_event_queue_ == nullptr)
        {
            GFXRECON_LOG_ERROR("Failed to create Wayland event queue");
            return false;
        }

        wayland_wrapped_display_ = (struct wl_display*)wl.proxy_create_wrapper(wayland_display_);
        if (wayland_wrapped_display_ == nullptr)
        {
            GFXRECON_LOG_ERROR("Failed to wrap Wayland display");
            return false;
        }

        // Bind the wrapped display to the new event queue, allows us to create an isolated wl_registry
        wl.proxy_set_queue((struct wl_proxy*)wayland_wrapped_display_, wayland_event_queue_);

        wayland_registry_ = wl.display_get_registry(wayland_wrapped_display_);
        if (wayland_registry_ == nullptr)
        {
            GFXRECON_LOG_ERROR("Failed to get Wayland registry");
            return false;
        }

        int proxy_return = wl.registry_add_listener(wayland_registry_, &Keyboard::wayland_registry_listener_, this);
        if (proxy_return != 0)
        {
            GFXRECON_LOG_ERROR("Failed to add registry listener to Wayland");
            return false;
        }

        int display_roundtrip_queue_return = wl.display_roundtrip_queue(wayland_display_, wayland_event_queue_);
        if (display_roundtrip_queue_return == -1)
        {
            GFXRECON_LOG_ERROR("Failed Wayland call to wl_display_roundtrip_queue");
            return false;
        }

        if (wayland_seat_ == nullptr)
        {
            GFXRECON_LOG_ERROR("Failed to bind Wayland seat");
            return false;
        }
        if (wayland_keyboard_ == nullptr)
        {
            GFXRECON_LOG_ERROR("Failed to bind Wayland keyboard");
            return false;
        }
    }
    return success;
}
#endif

void Keyboard::Shutdown()
{
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
    if (wayland_display_)
    {
        auto& wl = GetWaylandFunctionTable();
        if (wayland_keyboard_)
        {
            wl.keyboard_destroy(wayland_keyboard_);
            wayland_keyboard_ = {};
        }
        if (wayland_seat_)
        {
            wl.seat_destroy(wayland_seat_);
            wayland_seat_ = {};
        }
        if (wayland_registry_)
        {
            wl.registry_destroy(wayland_registry_);
            wayland_registry_ = {};
        }
        if (wayland_wrapped_display_)
        {
            wl.proxy_wrapper_destroy(wayland_wrapped_display_);
            wayland_wrapped_display_ = {};
        }
        if (wayland_event_queue_)
        {
            wl.event_queue_destroy(wayland_event_queue_);
            wayland_event_queue_ = {};
        }
        wayland_display_ = {};
    }
#endif
}

bool Keyboard::GetKeyState(const std::string& key)
{
    bool result = false;
    using namespace gfxrecon::util::strings;

#if defined(VK_USE_PLATFORM_WIN32_KHR)
    static const std::unordered_map<std::string, int, CaseInsensitiveHash, CaseInsensitiveEqual> win32_key_code_map = {
        { "F1", VK_F1 },
        { "F2", VK_F2 },
        { "F3", VK_F3 },
        { "F4", VK_F4 },
        { "F5", VK_F5 },
        { "F6", VK_F6 },
        { "F7", VK_F7 },
        { "F8", VK_F8 },
        { "F9", VK_F9 },
        { "F10", VK_F10 },
        { "F11", VK_F11 },
        { "F12", VK_F12 },
        { "TAB", VK_TAB },
        { "ControlLeft", VK_LCONTROL },
        { "ControlRight", VK_RCONTROL }
    };

    auto iterator_key_code = win32_key_code_map.find(key);
    if (iterator_key_code != win32_key_code_map.end())
    {
        result |= (GetAsyncKeyState(iterator_key_code->second) != 0);
    }
#endif

#if defined(VK_USE_PLATFORM_XCB_KHR)
    static const std::unordered_map<std::string, int, CaseInsensitiveHash, CaseInsensitiveEqual> xcb_key_code_map = {
        { "F1", XK_F1 },
        { "F2", XK_F2 },
        { "F3", XK_F3 },
        { "F4", XK_F4 },
        { "F5", XK_F5 },
        { "F6", XK_F6 },
        { "F7", XK_F7 },
        { "F8", XK_F8 },
        { "F9", XK_F9 },
        { "F10", XK_F10 },
        { "F11", XK_F11 },
        { "F12", XK_F12 },
        { "Tab", XK_Tab },
        { "ControlLeft", XK_Control_L },
        { "ControlRight", XK_Control_R }
    };
    if (xcb_connection_)
    {
        auto& xcb_keysyms       = xcb_keysyms_loader_.GetFunctionTable();
        auto  iterator_key_code = xcb_key_code_map.find(key);
        if (iterator_key_code != xcb_key_code_map.end())
        {
            xcb_key_symbols_t* hot_key_symbol = xcb_keysyms.key_symbols_alloc(xcb_connection_);
            if (hot_key_symbol != nullptr)
            {
                xcb_keycode_t* xcb_key_code = xcb_keysyms.key_symbols_get_keycode(
                    hot_key_symbol, static_cast<xcb_keysym_t>(iterator_key_code->second));
                if (xcb_key_code != nullptr)
                {
                    xcb_query_keymap_cookie_t cookie = xcb_keysyms.query_keymap(xcb_connection_);
                    xcb_query_keymap_reply_t* keys_bit_map =
                        xcb_keysyms.query_keymap_reply(xcb_connection_, cookie, NULL);
                    if ((keys_bit_map->keys[(*xcb_key_code / 8)] & (1 << (*xcb_key_code % 8))) != 0)
                    {
                        result = true;
                    }
                    free(keys_bit_map);
                    free(xcb_key_code);
                }
                xcb_keysyms.key_symbols_free(hot_key_symbol);
            }
        }
    }
#endif

#if defined(VK_USE_PLATFORM_METAL_EXT)
    static const std::unordered_map<std::string, CGKeyCode, CaseInsensitiveHash, CaseInsensitiveEqual>
        carbon_key_code_map = {
            { "F1", kVK_F1 },
            { "F2", kVK_F2 },
            { "F3", kVK_F3 },
            { "F4", kVK_F4 },
            { "F5", kVK_F5 },
            { "F6", kVK_F6 },
            { "F7", kVK_F7 },
            { "F8", kVK_F8 },
            { "F9", kVK_F9 },
            { "F10", kVK_F10 },
            { "F11", kVK_F11 },
            { "F12", kVK_F12 },
            { "Tab", kVK_Tab },
            { "ControlLeft", kVK_Control },
            { "ControlRight", kVK_RightControl },
            { "CommandLeft", kVK_Command },
            { "CommandRight", kVK_RightCommand },
        };

    auto iterator_key_code = carbon_key_code_map.find(key);
    if (iterator_key_code != carbon_key_code_map.end())
    {
        result |= CGEventSourceKeyState(kCGEventSourceStateHIDSystemState, iterator_key_code->second);
    }
#endif

#if defined(VK_USE_PLATFORM_WAYLAND_KHR)

    // Every time we check the keyboard key, dispatch the event queue
    if (wayland_display_)
    {
        GetWaylandFunctionTable().display_roundtrip_queue(wayland_display_, wayland_event_queue_);
    }

    static const std::unordered_map<std::string, uint32_t, CaseInsensitiveHash, CaseInsensitiveEqual>
         wayland_key_code_map = { { "F1", 0 },   { "F2", 1 },           { "F3", 2 },           { "F4", 3 },
                                  { "F5", 4 },   { "F6", 5 },           { "F7", 6 },           { "F8", 7 },
                                  { "F9", 8 },   { "F10", 9 },          { "F11", 10 },         { "F12", 11 },
                                  { "Tab", 12 }, { "ControlLeft", 13 }, { "ControlRight", 14 } };
    auto iterator_key_code    = wayland_key_code_map.find(key);
    if (iterator_key_code != wayland_key_code_map.end())
    {
        result |= wayland_keyboard_state_[iterator_key_code->second];
    }
#endif

    return result;
}

#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
const util::WaylandLoader::FunctionTable& Keyboard::GetWaylandFunctionTable() const
{
    return wayland_loader_.GetFunctionTable();
}

void Keyboard::HandleRegistryGlobal(
    void* data, wl_registry* registry, uint32_t id, const char* interface, uint32_t version)
{
    auto  wayland_context = reinterpret_cast<Keyboard*>(data);
    auto& wl              = wayland_context->GetWaylandFunctionTable();

    if (util::platform::StringCompare(interface, wl.seat_interface->name) == 0)
    {
        wayland_context->wayland_seat_ =
            reinterpret_cast<wl_seat*>(wl.registry_bind(registry, id, wl.seat_interface, 1));
        wl.seat_add_listener(wayland_context->wayland_seat_, &wayland_seat_listener_, wayland_context);
    }
}

void Keyboard::HandleRegistryGlobalRemove(void* data, wl_registry* registry, uint32_t name) {}

void Keyboard::HandleSeatCapabilities(void* data, wl_seat* seat, uint32_t caps)
{
    auto  wayland_context = reinterpret_cast<Keyboard*>(data);
    auto& wl              = wayland_context->GetWaylandFunctionTable();

    // Subscribe to keyboard events.
    if (caps & WL_SEAT_CAPABILITY_KEYBOARD)
    {
        wayland_context->wayland_keyboard_ = wl.seat_get_keyboard(seat);
        wl.keyboard_add_listener(wayland_context->wayland_keyboard_, &wayland_keyboard_listener_, wayland_context);
    }
    else if (!(caps & WL_SEAT_CAPABILITY_KEYBOARD))
    {
        wl.keyboard_destroy(wayland_context->wayland_keyboard_);
        wayland_context->wayland_keyboard_ = nullptr;
    }
}

void Keyboard::HandleKeyboardKeymap(void* data, struct wl_keyboard* keyboard, uint32_t format, int fd, uint32_t size) {}

void Keyboard::HandleKeyboardEnter(
    void* data, struct wl_keyboard* keyboard, uint32_t serial, struct wl_surface* surface, struct wl_array* keys)
{
    auto wayland_context                               = reinterpret_cast<Keyboard*>(data);
    wayland_context->wayland_current_keyboard_surface_ = surface;
}

void Keyboard::HandleKeyboardLeave(void*               data,
                                   struct wl_keyboard* keyboard,
                                   uint32_t            serial,
                                   struct wl_surface*  surface)
{}

void Keyboard::HandleKeyboardKey(
    void* data, struct wl_keyboard* keyboard, uint32_t serial, uint32_t time, uint32_t key, uint32_t state)
{
    static const std::unordered_map<uint32_t, uint32_t> wayland_key_code_map = {
        { KEY_F1, 0 },   { KEY_F2, 1 },   { KEY_F3, 2 },   { KEY_F4, 3 },        { KEY_F5, 4 },
        { KEY_F6, 5 },   { KEY_F7, 6 },   { KEY_F8, 7 },   { KEY_F9, 8 },        { KEY_F10, 9 },
        { KEY_F11, 10 }, { KEY_F12, 11 }, { KEY_TAB, 12 }, { KEY_LEFTCTRL, 13 }, { KEY_RIGHTCTRL, 14 }
    };
    if (wayland_key_code_map.count(key) > 0 &&
        (state == WL_KEYBOARD_KEY_STATE_RELEASED || state == WL_KEYBOARD_KEY_STATE_PRESSED))
    {
        auto wayland_context                                                   = reinterpret_cast<Keyboard*>(data);
        wayland_context->wayland_keyboard_state_[wayland_key_code_map.at(key)] = static_cast<bool>(state);
    }
}

void Keyboard::HandleKeyboardModifiers(void*        data,
                                       wl_keyboard* keyboard,
                                       uint32_t     serial,
                                       uint32_t     mods_depressed,
                                       uint32_t     mods_latched,
                                       uint32_t     mods_locked,
                                       uint32_t     group)
{}
#endif

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
