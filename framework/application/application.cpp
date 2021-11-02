/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
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

#include "application/application.h"
#include "util/logging.h"
#include "util/platform.h"

#if defined(VK_USE_PLATFORM_WIN32_KHR)
#include "application/win32_context.h"
#endif
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
#include "application/wayland_context.h"
#endif
#if defined(VK_USE_PLATFORM_XCB_KHR)
#include "application/xcb_context.h"
#endif
#if defined(VK_USE_PLATFORM_XLIB_KHR)
#include "application/xlib_context.h"
#endif
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
#include "application/android_context.h"
#endif
#if defined(VK_USE_PLATFORM_HEADLESS)
#include "application/headless_context.h"
#endif

#include <algorithm>
#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

Application::Application(const std::string& name, decode::FileProcessor* file_processor) :
    name_(name), file_processor_(file_processor), running_(false), paused_(false), pause_frame_(0)
{}

Application ::~Application() {}

void Application::Run()
{
    running_ = true;

    while (running_)
    {
        ProcessEvents(paused_);

        // Only process the next frame if a quit event was not processed or not paused.
        if (running_ && !paused_)
        {
            PlaySingleFrame();
        }
    }
}

void Application::SetPaused(bool paused)
{
    paused_ = paused;

    if (paused_ && (file_processor_ != nullptr))
    {
        uint32_t current_frame = file_processor_->GetCurrentFrameNumber();
        if (current_frame > 0)
        {
            GFXRECON_LOG_INFO("Paused at frame %u", file_processor_->GetCurrentFrameNumber());
        }
    }
}

bool Application::PlaySingleFrame()
{
    bool success = false;

    if (file_processor_)
    {
        success = file_processor_->ProcessNextFrame();

        if (success)
        {
            if (file_processor_->GetCurrentFrameNumber() == pause_frame_)
            {
                paused_ = true;
            }

            // Check paused state separately from previous check to print messages for two different cases: replay has
            // paused on the user specified pause frame (tested above), or the user has pressed a key to advance forward
            // by one frame while paused.
            if (paused_)
            {
                GFXRECON_LOG_INFO("Paused at frame %u", file_processor_->GetCurrentFrameNumber());
            }
        }
        else
        {
            running_ = false;
        }
    }

    return success;
}

void Application::ProcessEvents(bool wait_for_input)
{
    if (wsi_context_)
    {
        wsi_context_->ProcessEvents(wait_for_input);
    }
}

void Application::InitializeWsiContext(const char* surfaceExtensionName, void* pPlatformSpecificData)
{
    if (!wsi_context_)
    {
#if defined(VK_USE_PLATFORM_WIN32_KHR)
        if (!util::platform::StringCompare(surfaceExtensionName, VK_KHR_WIN32_SURFACE_EXTENSION_NAME))
        {
            wsi_context_ = std::make_unique<Win32Context>(this);
        }
        else
#endif
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
            if (!util::platform::StringCompare(surfaceExtensionName, VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME))
        {
            wsi_context_ = std::make_unique<WaylandContext>(this);
        }
        else
#endif
#if defined(VK_USE_PLATFORM_XCB_KHR)
            if (!util::platform::StringCompare(surfaceExtensionName, VK_KHR_XCB_SURFACE_EXTENSION_NAME))
        {
            wsi_context_ = std::make_unique<XcbContext>(this);
        }
        else
#endif
#if defined(VK_USE_PLATFORM_XLIB_KHR)
            if (!util::platform::StringCompare(surfaceExtensionName, VK_KHR_XLIB_SURFACE_EXTENSION_NAME))
        {
            wsi_context_ = std::make_unique<XlibContext>(this);
        }
        else
#endif
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
            if (!util::platform::StringCompare(surfaceExtensionName, VK_KHR_ANDROID_SURFACE_EXTENSION_NAME))
        {
            wsi_context_ =
                std::make_unique<AndroidContext>(this, reinterpret_cast<struct android_app*>(pPlatformSpecificData));
        }
        else
#endif
#if defined(VK_USE_PLATFORM_HEADLESS)
            if (!util::platform::StringCompare(surfaceExtensionName, VK_EXT_HEADLESS_SURFACE_EXTENSION_NAME))
        {
            wsi_context_ = std::make_unique<HeadlessContext>(this);
        }
        else
#endif
        {
            // NOOP :
        }
    }
}

#if defined(WIN32)
void Application::InitializeDx12WsiContext()
{
    wsi_context_ = std::make_unique<Win32Context>(this);
}
#endif

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)
