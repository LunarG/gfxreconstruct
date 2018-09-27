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

#ifndef BRIMSTONE_APPLICATION_WIN32_APPLICATION_H
#define BRIMSTONE_APPLICATION_WIN32_APPLICATION_H

#include "util/platform.h"
#include "util/defines.h"
#include "application/application.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(application)

class Win32Application : public Application
{
public:
    Win32Application();

    virtual void ProcessEvents(bool wait_for_input) override;

    static LRESULT WINAPI WindowProc(HWND window, unsigned int msg, WPARAM wp, LPARAM lp);
};

BRIMSTONE_END_NAMESPACE(application)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_APPLICATION_WIN32_APPLICATION_H
