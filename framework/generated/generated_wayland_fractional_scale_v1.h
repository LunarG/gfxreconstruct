/*
** Copyright (c) 2024 LunarG, Inc.
** Copyright (c) 2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#ifndef GFXRECON_GENERATED_WAYLAND_FRACTIONAL_SCALE_V1_H
#define GFXRECON_GENERATED_WAYLAND_FRACTIONAL_SCALE_V1_H

#include <vector>

#include <wayland-client.h>

#include "util/defines.h"
#include "util/wayland_loader.h"

struct wp_fractional_scale_manager_v1;
struct wp_fractional_scale_v1;

// wp_fractional_scale_manager_v1 static declarations

enum wp_fractional_scale_manager_v1_error
{
	WP_FRACTIONAL_SCALE_MANAGER_V1_ERROR_FRACTIONAL_SCALE_EXISTS = 0,
};

// wp_fractional_scale_v1 static declarations

struct wp_fractional_scale_v1_listener
{
	void (*preferred_scale)(void* data, wp_fractional_scale_v1* object, uint32_t scale);
};

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// Global to fractional_scale_v1

class wayland_fractional_scale_v1_table
{
	private:

		const WaylandLoader::FunctionTable* _wl;
		std::vector<wl_message> _messages;
		std::vector<const wl_interface*> _messageArgs;

	public:

		// wp_fractional_scale_manager_v1 dynamic declarations

		wl_interface wp_fractional_scale_manager_v1_interface;

		void wp_fractional_scale_manager_v1_destroy(wp_fractional_scale_manager_v1* self) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 0);
			_wl->proxy_destroy(reinterpret_cast<wl_proxy*>(self));
		}

		wp_fractional_scale_v1* wp_fractional_scale_manager_v1_get_fractional_scale(wp_fractional_scale_manager_v1* self, wl_surface* surface) const
		{
			return reinterpret_cast<wp_fractional_scale_v1*>(_wl->proxy_marshal_constructor(reinterpret_cast<wl_proxy*>(self), 1, &wp_fractional_scale_v1_interface, NULL, surface));
		}

		// wp_fractional_scale_v1 dynamic declarations

		wl_interface wp_fractional_scale_v1_interface;

		int wp_fractional_scale_v1_add_listener(wp_fractional_scale_v1* self, wp_fractional_scale_v1_listener* listener, void* data) const
		{
			return _wl->proxy_add_listener(reinterpret_cast<wl_proxy*>(self), reinterpret_cast<void (**)(void)>(listener), data);
		}

		void wp_fractional_scale_v1_destroy(wp_fractional_scale_v1* self) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 0);
			_wl->proxy_destroy(reinterpret_cast<wl_proxy*>(self));
		}

		// Call this once libwayland-client is successfully loaded

		void initialize(const WaylandLoader* waylandLoader)
		{
			_wl = &waylandLoader->GetFunctionTable();

			_messageArgs = {
				&wp_fractional_scale_v1_interface,
				_wl->surface_interface,
				nullptr,
			};

			_messages = {
				{ "destroy", "", _messageArgs.data() + 0 },
				{ "get_fractional_scale", "no", _messageArgs.data() + 0 },
				{ "destroy", "", _messageArgs.data() + 0 },
				{ "preferred_scale", "u", _messageArgs.data() + 2 },
			};

			wp_fractional_scale_manager_v1_interface = { "wp_fractional_scale_manager_v1", 1, 2, _messages.data() + 0, 0, _messages.data() + 2 };
			wp_fractional_scale_v1_interface = { "wp_fractional_scale_v1", 1, 1, _messages.data() + 2, 1, _messages.data() + 3 };
		}
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GENERATED_WAYLAND_FRACTIONAL_SCALE_V1_H
