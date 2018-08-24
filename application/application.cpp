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

#include "application/application.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(application)

Application::Application() : paused_(false)
{

}

void Application::SetFileProcessor(format::FileProcessor* file_processor)
{
    file_processor_ = file_processor;
}

void Application::Run()
{
    bool keep_playing = true;
    while (keep_playing)
    {
        ProcessEvents(paused_);

        if (!paused_)
        {
            keep_playing = PlaySingleFrame();
        }
    }
}

bool Application::GetPaused()
{
    return paused_;
}

void Application::SetPaused(bool paused)
{
    paused_ = paused;
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
    if (std::find(windows.begin(), windows.end(), window) != windows.end())
    {
        return false;
    }
    windows.push_back(window);
    return true;
}

bool Application::UnregisterWindow(format::Window* window)
{
    auto pos = std::find(windows.begin(), windows.end(), window);
    if (pos == windows.end()) {
        return false;
    }
    windows.erase(pos);
    return true;
}

BRIMSTONE_END_NAMESPACE(application)
BRIMSTONE_END_NAMESPACE(brimstone)
