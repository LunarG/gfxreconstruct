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
#include "util/date_time.h"
#include "graphics/fps_info.h"

#include <memory>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <limits>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

class Application final
{
  public:
    Application(const std::string& name, decode::FileProcessor* file_processor);

    Application(const std::string& name, const std::string& cli_wsi_extension, decode::FileProcessor* file_processor);

    ~Application();

    const std::string& GetName() const { return name_; }

    const std::unordered_map<std::string, std::unique_ptr<WsiContext>>& GetWsiContexts() const { return wsi_contexts_; }

    const WsiContext* GetWsiContext(const std::string& wsi_extension, bool auto_select = false) const;

    WsiContext* GetWsiContext(const std::string& wsi_extension, bool auto_select = false);

    const std::string& GetWsiCliContext() const { return cli_wsi_extension_; }

    bool IsRunning() const { return running_; }

    void Run();

    bool GetPaused() const { return paused_; }

    void SetPaused(bool paused);

    void SetPauseFrame(uint32_t pause_frame) { pause_frame_ = pause_frame; }

    bool PlaySingleFrame();

    void ProcessEvents(bool wait_for_input);

    void SetFpsInfo(graphics::FpsInfo* fps_info);

    void InitializeWsiContext(const char* surfaceExtensionName, void* pPlatformSpecificData = nullptr);

#if defined(WIN32)
    void InitializeDx12WsiContext();
#endif

    void StopRunning() { running_ = false; }

    uint32_t GetCurrentFrameNumber() const
    {
        return file_processor_->GetCurrentFrameNumber();
    }

    void SetAPIDetected(bool detected_d3d12, bool detected_vulkan)
    {
        detected_d3d12_  = detected_d3d12;
        detected_vulkan_ = detected_vulkan;
    }

  private:
    // clang-format off
    std::string                                                  name_;              ///< Application name to display in window title bar.
    decode::FileProcessor*                                       file_processor_;    ///< The FileProcessor object responsible for decoding and processing capture file data.
    bool                                                         running_;           ///< Indicates that the application is actively processing system events for playback.
    bool                                                         paused_;            ///< Indicates that the playback has been paused.  When paused the application will stop rendering, but will continue processing system events.
    uint32_t                                                     pause_frame_;       ///< The number for a frame that replay should pause after.
    std::unordered_map<std::string, std::unique_ptr<WsiContext>> wsi_contexts_;      ///< Loaded WSI contexts from CLI and VkInstanceCreateInfo
    std::string                                                  cli_wsi_extension_; ///< WSI extension selected on CLI, empty string if no CLI selection
    graphics::FpsInfo*                                           fps_info_;          ///< A optional FPS info object that logs the FPS across a configured framerange.
    bool                                                         detected_d3d12_;    ///<Indicates that the trace uses D3D12
    bool                                                         detected_vulkan_;   ///<Indicates that the trace uses Vulkan
                                                                                     ///< capture file data.
    // clang-format on
};

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_APPLICATION_APPLICATION_H
