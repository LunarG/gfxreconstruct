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

#ifndef BRIMSTONE_APPLICATION_APPLICATION_H
#define BRIMSTONE_APPLICATION_APPLICATION_H

#include <vector>
#include <algorithm>

#include "format/file_processor.h"
#include "format/window.h"

#include "util/defines.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(application)


class Application
{
public:
    Application();
    virtual ~Application() {};

    void SetFileProcessor(format::FileProcessor* file_processor);

    void Run();

    bool GetPaused();

    void SetPaused(bool paused);

    bool PlaySingleFrame();

    bool RegisterWindow(format::Window* window);

    bool UnregisterWindow(format::Window* window);

public:
    std::vector<format::Window*> windows;

protected:
    virtual void ProcessEvents(bool wait_for_input) = 0;

private:
    format::FileProcessor* file_processor_ = nullptr;
    bool paused_;
};

BRIMSTONE_END_NAMESPACE(application)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_APPLICATION_APPLICATION_H