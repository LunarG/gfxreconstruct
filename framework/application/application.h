/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

#ifndef GFXRECON_APPLICATION_APPLICATION_H
#define GFXRECON_APPLICATION_APPLICATION_H

#include "decode/file_processor.h"
#include "decode/window.h"
#include "util/defines.h"

#include <string>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

class Application
{
  public:
    Application(const std::string& name);

    virtual ~Application();

    const std::string& GetName() const { return name_; }

    virtual bool Initialize(decode::FileProcessor* file_processor) = 0;

    bool IsRunning() const { return running_; }

    void Run();

    bool GetPaused() const { return paused_; }

    void SetPaused(bool paused);

    void SetPauseFrame(uint32_t pause_frame) { pause_frame_ = pause_frame; }

    bool PlaySingleFrame();

    bool RegisterWindow(decode::Window* window);

    bool UnregisterWindow(decode::Window* window);

    virtual void ProcessEvents(bool wait_for_input) = 0;

  protected:
    void StopRunning() { running_ = false; }

    void SetFileProcessor(decode::FileProcessor* file_processor);

  private:
    // clang-format off
    std::vector<decode::Window*> windows_;          ///< List of windows that have been registered with the application.
    decode::FileProcessor*       file_processor_;   ///< The FileProcessor object responsible for decoding and processing
                                                    ///< capture file data.
    bool                         running_;          ///< Indicates that the application is actively processing system
                                                    ///< events for playback.
    bool                         paused_;           ///< Indicates that the playback has been paused.  When paused the
                                                    ///< application will stop rendering, but will continue processing
                                                    ///< system events.
    std::string                  name_;             ///< Application name to display in window title bar.
    uint32_t                     pause_frame_;      ///< The number for a frame that replay should pause after.
    // clang-format on
};

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_APPLICATION_APPLICATION_H
