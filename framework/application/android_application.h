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

#ifndef GFXRECON_APPLICATION_ANDROID_APPLICATION_H
#define GFXRECON_APPLICATION_ANDROID_APPLICATION_H

#include "application/application.h"
#include "util/defines.h"
#include "util/platform.h"

#include <android_native_app_glue.h>

#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

class AndroidWindow;

class AndroidApplication : public Application
{
  public:
    enum ScreenOrientation : int32_t
    {
        kLandscape = 0,
        kPortrait  = 1
    };

  public:
    AndroidApplication(const std::string& name, struct android_app* app);

    virtual ~AndroidApplication() override {}

    virtual bool Initialize(decode::FileProcessor* file_processor) override;

    virtual void ProcessEvents(bool wait_for_input) override;

    AndroidWindow* GetWindow() const { return window_.get(); }

    void InitWindow();

    void SetOrientation(ScreenOrientation orientation);

  private:
    std::unique_ptr<AndroidWindow> window_;
    struct android_app*            android_app_;
};

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_APPLICATION_ANDROID_APPLICATION_H
