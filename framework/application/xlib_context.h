/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018-2021 LunarG, Inc.
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

#ifndef GFXRECON_APPLICATION_XLIB_CONTEXT_H
#define GFXRECON_APPLICATION_XLIB_CONTEXT_H

#include "application/wsi_context.h"
#include "util/defines.h"
#include "util/xlib_loader.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

class Application;
class XlibWindow;

class XlibContext : public WsiContext
{
  public:
    XlibContext(Application* application);

    virtual ~XlibContext() override;

    const util::XlibLoader::FunctionTable& GetXlibFunctionTable() const { return xlib_loader_.GetFunctionTable(); }

    Display* OpenDisplay();

    void CloseDisplay(Display* display);

    bool RegisterXlibWindow(XlibWindow* window);

    bool UnregisterXlibWindow(XlibWindow* window);

    virtual void ProcessEvents(bool wait_for_input) override;

    virtual const char* GetWsiName() override { return "XLIB"; }

  private:
    Display*         display_{};
    size_t           display_open_count_{};
    util::XlibLoader xlib_loader_{};
};

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_APPLICATION_XLIB_CONTEXT_H
