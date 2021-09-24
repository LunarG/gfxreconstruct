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

#include "application/wsi_context.h"
#include "decode/file_processor.h"
#include "decode/window.h"
#include "util/defines.h"

#include <memory>
#include <string>
#include <utility>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

class Application final
{
  public:
    Application(const std::string& name, decode::FileProcessor* file_processor);

    ~Application();

    const std::string& GetName() const { return name_; }

    const WsiContext* GetWsiContext() const { return wsi_context_.get(); }

    WsiContext* GetWsiContext() { return wsi_context_.get(); }

    bool IsRunning() const { return running_; }

    void Run();

    void StopRunning() { running_ = false; }

    bool GetPaused() const { return paused_; }

    void SetPaused(bool paused);

    void SetPauseFrame(uint32_t pause_frame) { pause_frame_ = pause_frame; }

    bool PlaySingleFrame();

    void ProcessEvents(bool wait_for_input);

    void InitializeWsiContext(const char* surfaceExtensionName, void* pPlatformSpecificData = nullptr);

  private:
    // clang-format off
    std::string                 name_;           ///< Application name to display in window title bar.
    decode::FileProcessor*      file_processor_; ///< The FileProcessor object responsible for decoding and processing capture file data.
    bool                        running_;        ///< Indicates that the application is actively processing system events for playback.
    bool                        paused_;         ///< Indicates that the playback has been paused.  When paused the application will stop rendering, but will continue processing system events.
    uint32_t                    pause_frame_;    ///< The number for a frame that replay should pause after.
    std::unique_ptr<WsiContext> wsi_context_;    ///< The window system context used for playback
    // clang-format on
};

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_APPLICATION_APPLICATION_H
