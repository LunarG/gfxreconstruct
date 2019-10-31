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

    /// Send Asic Information function
    //
    /// This function retrieve and send the Asic information over TCP.
    /// The Asic information sent includes chip family, chip ID,
    /// revision ID, gpu counter frequency, core clock frequency,
    /// memory clock frequency, video memory size, number of shader engines,
    /// number of shader arrays per SE, total CU and number of SIMD per CU
    void SendAsicInfo();

    void Run();

    void Run(char* file_name, uint32_t port, char* ip_address);

    bool GetPaused() const { return paused_; }

    void SetPaused(bool paused);

    void SetPauseFrame(uint32_t pause_frame) { pause_frame_ = pause_frame; }

    bool PlaySingleFrame();

    bool PlaySingleFrame(char* file_name, bool tcp_send_data);

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
    std::shared_ptr<TcpClient>   tcp_client;        ///< Tcp client used to send messages for tuning.
    // clang-format on
};

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_APPLICATION_APPLICATION_H
