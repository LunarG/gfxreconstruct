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

#ifndef BRIMSTONE_UTIL_APPLICATION_H
#define BRIMSTONE_UTIL_APPLICATION_H

#include <vector>
#include <algorithm>

#include "format/file_processor.h"

#include "util/defines.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(util)


class Application
{
public:
    Application();
    virtual ~Application() {};

    void SetFileProcessor(format::FileProcessor* file_processor);

    void Run();

    bool GetPaused();

    void SetPaused(bool paused);

    void PlaySingleFrame();

    bool RegisterWindow(class Window* window);

    bool UnregisterWindow(class Window* window);

public:
    std::vector<class Window*> windows;

protected:
    virtual void ProcessEvents(bool wait_for_input) = 0;

private:
    format::FileProcessor* file_processor_;
    bool paused_;
};

BRIMSTONE_END_NAMESPACE(util)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_UTIL_APPLICATION_H