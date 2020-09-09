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

#ifndef GFXRECON_APPLICATION_XLIB_APPLICATION_H
#define GFXRECON_APPLICATION_XLIB_APPLICATION_H

#include "application/application.h"
#include "util/defines.h"
#include "util/xlib_loader.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

class XlibWindow;

class XlibApplication : public Application
{
  public:
    XlibApplication(const std::string& name);

    virtual ~XlibApplication() override;

    const util::XlibLoader::FunctionTable& GetXlibFunctionTable() const { return xlib_loader_.GetFunctionTable(); }

    Display* GetDisplay() const { return display_; }

    virtual bool Initialize(decode::FileProcessor* file_processor) override;

    bool RegisterXlibWindow(XlibWindow* window);

    bool UnregisterXlibWindow(XlibWindow* window);

    virtual void ProcessEvents(bool wait_for_input) override;

  private:
    Display*         display_;
    util::XlibLoader xlib_loader_;
};

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_APPLICATION_XLIB_APPLICATION_H