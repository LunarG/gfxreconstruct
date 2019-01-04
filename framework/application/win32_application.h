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

#ifndef GFXRECON_APPLICATION_WIN32_APPLICATION_H
#define GFXRECON_APPLICATION_WIN32_APPLICATION_H

#include "application/application.h"
#include "util/defines.h"
#include "util/platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

class Win32Application : public Application
{
  public:
    Win32Application(const std::string& name, bool dpi_aware = true);

    virtual ~Win32Application() override {}

    virtual bool Initialize(decode::FileProcessor* file_processor) override;

    virtual void ProcessEvents(bool wait_for_input) override;

    static LRESULT WINAPI WindowProc(HWND window, unsigned int msg, WPARAM wp, LPARAM lp);
};

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_APPLICATION_WIN32_APPLICATION_H
