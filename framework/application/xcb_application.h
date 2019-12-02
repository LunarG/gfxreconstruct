/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
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

#ifndef GFXRECON_APPLICATION_XCB_APPLICATION_H
#define GFXRECON_APPLICATION_XCB_APPLICATION_H

#include "application/application.h"
#include "util/defines.h"
#include "util/xcb_loader.h"

#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

class XcbWindow;

class XcbApplication : public Application
{
  public:
    XcbApplication(const std::string& name);

    virtual ~XcbApplication() override;

    const util::XcbLoader::FunctionTable& GetXcbFunctionTable() const { return xcb_loader_.GetFunctionTable(); }

    xcb_connection_t* GetConnection() const { return connection_; }

    xcb_screen_t* GetScreen() const { return screen_; }

    uint32_t GetLastErrorSequence() const { return last_error_sequence_; }

    uint8_t GetLastErrorCode() const { return last_error_code_; }

    virtual bool Initialize(decode::FileProcessor* file_processor) override;

    bool RegisterXcbWindow(XcbWindow* window);

    bool UnregisterXcbWindow(XcbWindow* window);

    void ClearLastError()
    {
        last_error_sequence_ = 0;
        last_error_code_     = 0;
    }

    virtual void ProcessEvents(bool wait_for_input) override;

  private:
    typedef std::unordered_map<xcb_window_t, XcbWindow*> XcbWindowMap;

  private:
    xcb_connection_t* connection_;
    xcb_screen_t*     screen_;
    uint32_t          last_error_sequence_;
    uint8_t           last_error_code_;
    XcbWindowMap      xcb_windows_;
    util::XcbLoader   xcb_loader_;
};

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_APPLICATION_XCB_APPLICATION_H