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

#ifndef GFXRECON_APPLICATION_XCB_CONTEXT_H
#define GFXRECON_APPLICATION_XCB_CONTEXT_H

#include "application/wsi_context.h"
#include "util/defines.h"
#include "util/xcb_loader.h"

#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

class Application;
class XcbWindow;

class XcbContext : public WsiContext
{
  public:
    XcbContext(Application* application);

    virtual ~XcbContext() override;

    const util::XcbLoader::FunctionTable& GetXcbFunctionTable() const { return xcb_loader_.GetFunctionTable(); }

    xcb_connection_t* GetConnection() const { return connection_; }

    xcb_screen_t* GetScreen() const { return screen_; }

    uint32_t GetLastErrorSequence() const { return last_error_sequence_; }

    uint8_t GetLastErrorCode() const { return last_error_code_; }

    bool RegisterXcbWindow(XcbWindow* window);

    bool UnregisterXcbWindow(XcbWindow* window);

    void ClearLastError()
    {
        last_error_sequence_ = 0;
        last_error_code_     = 0;
    }

    virtual void ProcessEvents(bool wait_for_input) override;

    virtual const char* GetWsiName() override { return "XCB"; }

  private:
    typedef std::unordered_map<xcb_window_t, XcbWindow*> XcbWindowMap;

    xcb_connection_t* connection_{};
    xcb_screen_t*     screen_{};
    uint32_t          last_error_sequence_{};
    uint8_t           last_error_code_{};
    XcbWindowMap      xcb_windows_{};
    util::XcbLoader   xcb_loader_{};
};

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_APPLICATION_XCB_CONTEXT_H
