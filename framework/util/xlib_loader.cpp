/*
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

#include "util/xlib_loader.h"

#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

const std::vector<std::string> kXlibNames = {
#if defined(X11_LIBRARY)
    X11_LIBRARY,
#endif
    "libX11.so.6",
    "libX11.so"
};

XlibLoader::XlibLoader() : libx11_(nullptr), function_table_{} {}

XlibLoader::~XlibLoader()
{
    if (libx11_)
    {
        util::platform::CloseLibrary(libx11_);
        libx11_ = nullptr;
    }
}

bool XlibLoader::Initialize()
{
    bool success = true;

    // Guard against double initialization
    if (!libx11_)
    {
        libx11_ = util::platform::OpenLibrary(kXlibNames);
        if (libx11_)
        {
            function_table_.ChangeProperty = reinterpret_cast<decltype(XChangeProperty)*>(
                util::platform::GetProcAddress(libx11_, "XChangeProperty"));
            function_table_.CloseDisplay =
                reinterpret_cast<decltype(XCloseDisplay)*>(util::platform::GetProcAddress(libx11_, "XCloseDisplay"));
            function_table_.CreateWindow =
                reinterpret_cast<decltype(XCreateWindow)*>(util::platform::GetProcAddress(libx11_, "XCreateWindow"));
            function_table_.DestroyWindow =
                reinterpret_cast<decltype(XDestroyWindow)*>(util::platform::GetProcAddress(libx11_, "XDestroyWindow"));
            function_table_.Flush =
                reinterpret_cast<decltype(XFlush)*>(util::platform::GetProcAddress(libx11_, "XFlush"));
            function_table_.GetErrorText =
                reinterpret_cast<decltype(XGetErrorText)*>(util::platform::GetProcAddress(libx11_, "XGetErrorText"));
            function_table_.GetWindowAttributes = reinterpret_cast<decltype(XGetWindowAttributes)*>(
                util::platform::GetProcAddress(libx11_, "XGetWindowAttributes"));
            function_table_.InternAtom =
                reinterpret_cast<decltype(XInternAtom)*>(util::platform::GetProcAddress(libx11_, "XInternAtom"));
            function_table_.MapWindow =
                reinterpret_cast<decltype(XMapWindow)*>(util::platform::GetProcAddress(libx11_, "XMapWindow"));
            function_table_.MoveWindow =
                reinterpret_cast<decltype(XMoveWindow)*>(util::platform::GetProcAddress(libx11_, "XMoveWindow"));
            function_table_.NextEvent =
                reinterpret_cast<decltype(XNextEvent)*>(util::platform::GetProcAddress(libx11_, "XNextEvent"));
            function_table_.OpenDisplay =
                reinterpret_cast<decltype(XOpenDisplay)*>(util::platform::GetProcAddress(libx11_, "XOpenDisplay"));
            function_table_.Pending =
                reinterpret_cast<decltype(XPending)*>(util::platform::GetProcAddress(libx11_, "XPending"));
            function_table_.ResizeWindow =
                reinterpret_cast<decltype(XResizeWindow)*>(util::platform::GetProcAddress(libx11_, "XResizeWindow"));
            function_table_.SendEvent =
                reinterpret_cast<decltype(XSendEvent)*>(util::platform::GetProcAddress(libx11_, "XSendEvent"));
            function_table_.SetErrorHandler = reinterpret_cast<decltype(XSetErrorHandler)*>(
                util::platform::GetProcAddress(libx11_, "XSetErrorHandler"));
            function_table_.StoreName =
                reinterpret_cast<decltype(XStoreName)*>(util::platform::GetProcAddress(libx11_, "XStoreName"));
            function_table_.Sync = reinterpret_cast<decltype(XSync)*>(util::platform::GetProcAddress(libx11_, "XSync"));
            function_table_.UnmapWindow =
                reinterpret_cast<decltype(XUnmapWindow)*>(util::platform::GetProcAddress(libx11_, "XUnmapWindow"));
            function_table_.VisualIDFromVisual = reinterpret_cast<decltype(XVisualIDFromVisual)*>(
                util::platform::GetProcAddress(libx11_, "XVisualIDFromVisual"));
        }
        else
        {
            GFXRECON_LOG_DEBUG("Failed to load libX11.so");
            success = false;
        }
    }

    return success;
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
