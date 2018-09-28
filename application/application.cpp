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

#include <algorithm>
#include <cassert>

#include "util/logging.h"
#include "application/application.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(application)

Application::Application() : file_processor_(nullptr), running_(false), paused_(false) {}

Application::~Application()
{
    if (!windows_.empty())
    {
        BRIMSTONE_LOG_INFO(
            "Application manager is destroying windows that were not previously destroyed by their owner");

        for (auto window : windows_)
        {
            delete window;
        }
    }
}

void Application::SetFileProcessor(format::FileProcessor* file_processor)
{
    file_processor_ = file_processor;
}

void Application::Run()
{
    running_ = true;

    while (running_)
    {
        ProcessEvents(paused_);

        // Only process the next frame if a quit event was not processed or not paused.
        if (running_ && !paused_)
        {
            running_ = PlaySingleFrame();
        }
    }
}

bool Application::PlaySingleFrame()
{
    bool success = false;

    if (file_processor_)
    {
        success = file_processor_->ProcessNextFrame();
    }

    return success;
}

bool Application::RegisterWindow(format::Window* window)
{
    assert(window != nullptr);

    if (std::find(windows_.begin(), windows_.end(), window) != windows_.end())
    {
        BRIMSTONE_LOG_INFO("A window was registered with the application more than once");
        return false;
    }

    windows_.push_back(window);

    return true;
}

bool Application::UnregisterWindow(format::Window* window)
{
    assert(window != nullptr);

    auto pos = std::find(windows_.begin(), windows_.end(), window);

    if (pos == windows_.end())
    {
        BRIMSTONE_LOG_INFO(
            "A remove window request was made for an window that was never registered with the application");
        return false;
    }

    windows_.erase(pos);

    return true;
}

BRIMSTONE_END_NAMESPACE(application)
BRIMSTONE_END_NAMESPACE(brimstone)
