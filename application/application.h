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

#include "util/defines.h"
#include "format/file_processor.h"
#include "format/window.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(application)

class Application
{
public:
    Application();

    virtual ~Application();

    void SetFileProcessor(format::FileProcessor* file_processor);

    bool IsRunning() const { return running_; }

    void Run();

    bool GetPaused() const { return paused_; }

    void SetPaused(bool paused) { paused_ = paused; }

    bool PlaySingleFrame();

    bool RegisterWindow(format::Window* window);

    bool UnregisterWindow(format::Window* window);

    virtual void ProcessEvents(bool wait_for_input) = 0;

protected:
    void StopRunning() { running_ = false; }

protected:
    std::vector<format::Window*> windows_;

private:
    // clang-format off
    format::FileProcessor*       file_processor_;   ///< The FileProcessor object responsible for decoding and processing
                                                    ///< capture file data.
    bool                         running_;          ///< Indicatess that the application is actively processing system
                                                    ///< events for playback.
    bool                         paused_;           ///< Indicates that the playback has been paused.  When paused the
                                                    ///< application will stop rendering, but will continue processing
                                                    ///< system events.
    // clang-format on
};

BRIMSTONE_END_NAMESPACE(application)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_APPLICATION_APPLICATION_H
