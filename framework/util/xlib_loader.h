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

#ifndef GFXRECON_UTIL_XLIB_LOADER_H
#define GFXRECON_UTIL_XLIB_LOADER_H

#include "util/defines.h"
#include "util/platform.h"

#include <X11/Xlib.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class XlibLoader
{
  public:
    struct FunctionTable
    {
        decltype(XChangeProperty)*      ChangeProperty;
        decltype(XCloseDisplay)*        CloseDisplay;
        decltype(XCreateWindow)*        CreateWindow;
        decltype(XDestroyWindow)*       DestroyWindow;
        decltype(XFlush)*               Flush;
        decltype(XGetErrorText)*        GetErrorText;
        decltype(XGetWindowAttributes)* GetWindowAttributes;
        decltype(XInternAtom)*          InternAtom;
        decltype(XMapWindow)*           MapWindow;
        decltype(XMoveWindow)*          MoveWindow;
        decltype(XNextEvent)*           NextEvent;
        decltype(XOpenDisplay)*         OpenDisplay;
        decltype(XPending)*             Pending;
        decltype(XResizeWindow)*        ResizeWindow;
        decltype(XSendEvent)*           SendEvent;
        decltype(XSetErrorHandler)*     SetErrorHandler;
        decltype(XStoreName)*           StoreName;
        decltype(XSync)*                Sync;
        decltype(XUnmapWindow)*         UnmapWindow;
    };

  public:
    XlibLoader();

    ~XlibLoader();

    bool Initialize();

    const FunctionTable& GetFunctionTable() const { return function_table_; }

  private:
    util::platform::LibraryHandle libx11_;
    FunctionTable                 function_table_;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_XLIB_LOADER_H
