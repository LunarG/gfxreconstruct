/*
** Copyright (c) 2021 LunarG, Inc.
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

#ifndef GFXRECON_APPLICATION_WSI_CONTEXT_H
#define GFXRECON_APPLICATION_WSI_CONTEXT_H

#include "decode/window.h"
#include "util/defines.h"

#include <memory>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

class Application;

class WsiContext
{
  public:
    WsiContext(Application* application);

    virtual ~WsiContext() = 0;

    const Application* GetApplication() const { return application_; }

    Application* GetApplication() { return application_; }

    const decode::WindowFactory* GetWindowFactory() const { return window_factory_.get(); }

    decode::WindowFactory* GetWindowFactory() { return window_factory_.get(); }

    const std::vector<decode::Window*>& GetWindows() const { return windows_; }

    bool RegisterWindow(decode::Window* window);

    bool UnregisterWindow(decode::Window* window);

    virtual void ProcessEvents(bool wait_for_input);

    bool Valid() const;

    virtual const char* GetWsiName() = 0;

  protected:
    Application*                           application_;
    std::unique_ptr<decode::WindowFactory> window_factory_;

  private:
    std::vector<decode::Window*> windows_;
};

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_APPLICATION_WSI_CONTEXT_H
