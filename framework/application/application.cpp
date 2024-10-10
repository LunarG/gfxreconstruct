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
#include "decode/preload_file_processor.h"

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
#if defined(VK_USE_PLATFORM_METAL_EXT)
#include "application/metal_context.h"
#endif
#if defined(VK_USE_PLATFORM_DISPLAY_KHR)
#include "application/display_context.h"
#endif
#if defined(VK_USE_PLATFORM_HEADLESS)
#include "application/headless_context.h"
#endif

#include <algorithm>
#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

Application::Application(const std::string& name, decode::FileProcessor* file_processor) :
    Application(name, std::string(), file_processor)
{}

Application::Application(const std::string&     name,
                         const std::string&     cli_wsi_extension,
                         decode::FileProcessor* file_processor) :
    name_(name),
    file_processor_(file_processor), cli_wsi_extension_(cli_wsi_extension), running_(false), paused_(false),
    pause_frame_(0), fps_info_(nullptr)
{
    if (!cli_wsi_extension_.empty())
    {
        InitializeWsiContext(cli_wsi_extension_.c_str());
    }
}

Application ::~Application() {}

const WsiContext* Application::GetWsiContext(const std::string& wsi_extension, bool auto_select) const
{
    auto itr = wsi_contexts_.end();

    // If auto_select is enabled and a WSI extension was selected on the CLI,
    //  attempt to get that WSI context
    if (auto_select && !cli_wsi_extension_.empty())
    {
        itr = wsi_contexts_.find(cli_wsi_extension_);
    }

    // If we don't have a valid WSI context after potential auto_select, fallback
    //  to the current API call request
    if (itr == wsi_contexts_.end())
    {
        itr = wsi_contexts_.find(wsi_extension);
    }

    // If auto_select is enabled and we still don't have a valid WSI context, use
    //  first one we have
    if (auto_select && itr == wsi_contexts_.end())
    {
        itr = wsi_contexts_.begin();
    }

    // If we've gotten here without a valid WSI context then we'll simply return
    //  nullptr letting the caller know that we do not have a WSI context loaded
    //  for the given WSI extension
    return itr != wsi_contexts_.end() ? itr->second.get() : nullptr;
}

WsiContext* Application::GetWsiContext(const std::string& wsi_extension, bool auto_select)
{
    auto const_this  = const_cast<const Application*>(this);
    auto wsi_context = const_this->GetWsiContext(wsi_extension, auto_select);
    return const_cast<WsiContext*>(wsi_context);
}

void Application::SetFpsInfo(graphics::FpsInfo* fps_info)
{
    if (file_processor_ == nullptr)
    {
        GFXRECON_LOG_WARNING("Application file processor not set, cannot set FpsInfo object.");
        return;
    }

    fps_info_ = fps_info;
}

void Application::Run()
{
    running_ = true;

    while (running_)
    {
        ProcessEvents(paused_);

        // Only process the next frame if a quit event was not processed or not paused.
        if (running_ && !paused_)
        {
            // Add one to match "trim frame range semantic"
            uint32_t frame_number = file_processor_->GetCurrentFrameNumber() + 1;

            if (fps_info_ != nullptr)
            {
                if (fps_info_->ShouldQuit(frame_number))
                {
                    running_ = false;
                    break;
                }

                if (fps_info_->ShouldWaitIdleBeforeFrame(frame_number))
                {
                    file_processor_->WaitDecodersIdle();
                }

                auto preload_frames_count = fps_info_->ShouldPreloadFrames(frame_number);
                if (preload_frames_count > 0U)
                {
                    auto* preload_processor = dynamic_cast<decode::PreloadFileProcessor*>(file_processor_);
                    GFXRECON_ASSERT(preload_processor)
                    preload_processor->PreloadNextFrames(preload_frames_count);
                }

                fps_info_->BeginFrame(frame_number);
            }

            // PlaySingleFrame() increments this->current_frame_number_ *if* there's an end-of-frame
            PlaySingleFrame();

            if (fps_info_ != nullptr)
            {
                fps_info_->EndFrame(frame_number);

                if (fps_info_->ShouldWaitIdleAfterFrame(frame_number))
                {
                    file_processor_->WaitDecodersIdle();
                }
            }
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
    for (const auto& itr : wsi_contexts_)
    {
        const auto& wsi_context       = itr.second;
        bool        activeWsiContext  = wsi_context && !wsi_context->GetWindows().empty();
        auto        pWindowFactory    = wsi_context ? wsi_context->GetWindowFactory() : nullptr;
        bool        androidWsiContext = pWindowFactory && (strcmp(pWindowFactory->GetSurfaceExtensionName(),
                                                           VK_KHR_ANDROID_SURFACE_EXTENSION_NAME) == 0);
        if (activeWsiContext || androidWsiContext)
        {
            wsi_context->ProcessEvents(wait_for_input);
        }
    }
}

void Application::InitializeWsiContext(const char* pSurfaceExtensionName, void* pPlatformSpecificData)
{
    assert(pSurfaceExtensionName);
    auto itr = wsi_contexts_.find(pSurfaceExtensionName);
    if (itr == wsi_contexts_.end())
    {
#if defined(VK_USE_PLATFORM_WIN32_KHR)
        if (!util::platform::StringCompare(pSurfaceExtensionName, VK_KHR_WIN32_SURFACE_EXTENSION_NAME))
        {
            wsi_contexts_[VK_KHR_WIN32_SURFACE_EXTENSION_NAME] = std::make_unique<Win32Context>(this);
        }
        else
#endif
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
            if (!util::platform::StringCompare(pSurfaceExtensionName, VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME))
        {
            wsi_contexts_[VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME] = std::make_unique<WaylandContext>(this);
        }
        else
#endif
#if defined(VK_USE_PLATFORM_XCB_KHR)
            if (!util::platform::StringCompare(pSurfaceExtensionName, VK_KHR_XCB_SURFACE_EXTENSION_NAME))
        {
            wsi_contexts_[VK_KHR_XCB_SURFACE_EXTENSION_NAME] = std::make_unique<XcbContext>(this);
        }
        else
#endif
#if defined(VK_USE_PLATFORM_XLIB_KHR)
            if (!util::platform::StringCompare(pSurfaceExtensionName, VK_KHR_XLIB_SURFACE_EXTENSION_NAME))
        {
            wsi_contexts_[VK_KHR_XLIB_SURFACE_EXTENSION_NAME] = std::make_unique<XlibContext>(this);
        }
        else
#endif
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
            if (!util::platform::StringCompare(pSurfaceExtensionName, VK_KHR_ANDROID_SURFACE_EXTENSION_NAME))
        {
            wsi_contexts_[VK_KHR_ANDROID_SURFACE_EXTENSION_NAME] =
                std::make_unique<AndroidContext>(this, reinterpret_cast<struct android_app*>(pPlatformSpecificData));
        }
        else
#endif
#if defined(VK_USE_PLATFORM_METAL_EXT)
            if (!util::platform::StringCompare(pSurfaceExtensionName, VK_EXT_METAL_SURFACE_EXTENSION_NAME))
        {
            wsi_contexts_[VK_EXT_METAL_SURFACE_EXTENSION_NAME] = std::make_unique<MetalContext>(this);
        }
        else
#endif
#if defined(VK_USE_PLATFORM_DISPLAY_KHR)
            if (!util::platform::StringCompare(pSurfaceExtensionName, VK_KHR_DISPLAY_EXTENSION_NAME))
        {
            wsi_contexts_[VK_KHR_DISPLAY_EXTENSION_NAME] = std::make_unique<DisplayContext>(this);
        }
        else
#endif
#if defined(VK_USE_PLATFORM_HEADLESS)
            if (!util::platform::StringCompare(pSurfaceExtensionName, VK_EXT_HEADLESS_SURFACE_EXTENSION_NAME))
        {
            wsi_contexts_[VK_EXT_HEADLESS_SURFACE_EXTENSION_NAME] = std::make_unique<HeadlessContext>(this);
        }
        else
#endif
        {
            // NOOP :
        }
    }
}

#if defined(D3D12_SUPPORT)
void Application::InitializeDx12WsiContext()
{
    wsi_contexts_["Dx12WsiContext"] = std::make_unique<Win32Context>(this);
}
#endif

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)
