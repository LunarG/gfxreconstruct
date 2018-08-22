/*
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

#ifndef BRIMSTONE_APPLICATION_XCB_APPLICATION_H
#define BRIMSTONE_APPLICATION_XCB_APPLICATION_H

#include <xcb/xcb.h>

#include "application/application.h"

#include "util/defines.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(application)

class XcbApplication : public Application
{
public:
    XcbApplication();

    void ProcessEvents(bool wait_for_input) override;

public:
    xcb_connection_t*           connection;
    xcb_screen_t*               screen;
};

BRIMSTONE_END_NAMESPACE(application)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_APPLICATION_XCB_APPLICATION_H