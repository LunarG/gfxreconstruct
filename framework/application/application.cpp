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

#include "application/application.h"
#include "util/logging.h"
#include "util/asic_info_amdext_loader.h"
#include "framework/tcpclient/tcp_client.h"

#include <algorithm>
#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

Application::Application(const std::string& name) :
    file_processor_(nullptr), running_(false), paused_(false), name_(name)
{}

Application::~Application()
{
    if (!windows_.empty())
    {
        GFXRECON_LOG_INFO(
            "Application manager is destroying windows that were not previously destroyed by their owner");

        for (auto window : windows_)
        {
            delete window;
        }
    }
}

void Application::SetFileProcessor(decode::FileProcessor* file_processor)
{
    file_processor_ = file_processor;
}

void Application::SendAsicInfo()
{
#ifdef _WIN32
    static bool asic_info_sent = false;
    if (true == asic_info_sent)
    {
        return;
    }
    asic_info_sent = true;

    AmdDxASICInfo asic_info;
    if (true == AsicInfoAmdExtLoader::GetAsicInfo(&asic_info))
    {
        if (asic_info.gpuCount > 0)
        {
            AmdDxASICInfoHWInfo* hw_info = &(asic_info.hwInfo[0]);
            tcp_client->TransmitData("ASICINFO:"
                                     "chipFamily=%d|"
                                     "chipID=%d|"
                                     "revisionID=%d|"
                                     "gpuCounterFrequency=%llu|"
                                     "coreClockInHz=%llu|"
                                     "memClockInHz=%llu|"
                                     "videoMemSize=%llu|"
                                     "numShaderEngines=%d|"
                                     "numShaderArraysPerSE=%d|"
                                     "totalCU=%d|"
                                     "numSimdsPerCU=%d|",
                                     "numWaveSlotsPerSimd=%d|",
                                     "chipName=%d|",
                                     hw_info->chipFamily,
                                     hw_info->chipID,
                                     hw_info->revisionID,
                                     hw_info->gpuCounterFrequency,
                                     hw_info->coreClockInHz,
                                     hw_info->memClockInHz,
                                     hw_info->videoMemSize,
                                     hw_info->numShaderEngines,
                                     hw_info->numShaderArraysPerSE,
                                     hw_info->totalCU,
                                     hw_info->numSimdsPerCU,
                                     hw_info->waveSlotsPerSimd,
                                     hw_info->asicName);
        }
    }
#else
    GFXRECON_LOG_ERROR("Application SendAsicInfo is supported in Windows only.");
#endif
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
            PlaySingleFrame();
        }
    }
}

void Application::Run(char* file_name, uint32_t port, char* ip_address)
{
    running_ = true;

    bool tcp_send_data = ((0 != port) && (nullptr != ip_address) && (0 != strlen(ip_address)));

    if (tcp_send_data)
    {
        tcp_client = TcpClient::Create(ip_address, port, nullptr, file_name, tcp_send_data);
        SendAsicInfo();
    }

    while (running_)
    {
        ProcessEvents(paused_);

        // Only process the next frame if a quit event was not processed or not paused.
        if (running_ && !paused_)
        {
            PlaySingleFrame(file_name, tcp_send_data);
        }
    }
}

void Application::SetPaused(bool paused)
{

    paused_ = paused;

    if (paused_ && (file_processor_ != nullptr))
    {
        uint32_t current_frame = file_processor_->GetCurrentFrameNumber();
        if (current_frame > 0)
        {
            GFXRECON_LOG_INFO("Paused at frame %u", file_processor_->GetCurrentFrameNumber());
        }
    }
}

bool Application::PlaySingleFrame()
{
    bool success = false;

    if (file_processor_)
    {
        success = file_processor_->ProcessNextFrame();

        if (success)
        {
            if (file_processor_->GetCurrentFrameNumber() == pause_frame_)
            {
                paused_ = true;
            }

            // Check paused state separately from previous check to print messages for two different cases: replay has
            // paused on the user specified pause frame (tested above), or the user has pressed a key to advance forward
            // by one frame while paused.
            if (paused_)
            {
                GFXRECON_LOG_INFO("Paused at frame %u", file_processor_->GetCurrentFrameNumber());
            }
        }
        else
        {
            running_ = false;
        }
    }

    return success;
}

bool Application::PlaySingleFrame(char* file_name, bool tcp_send_data)
{
    bool success = false;

    if (file_processor_)
    {
        success = file_processor_->ProcessNextFrame(tcp_client, tcp_send_data, file_name);

        if (success)
        {
            if (file_processor_->GetCurrentFrameNumber() == pause_frame_)
            {
                paused_ = true;
            }

            // Check paused state separately from previous check to print messages for two different cases: replay has
            // paused on the user specified pause frame (tested above), or the user has pressed a key to advance forward
            // by one frame while paused.
            if (paused_)
            {
                GFXRECON_LOG_INFO("Paused at frame %u", file_processor_->GetCurrentFrameNumber());
            }
        }
        else
        {
            running_ = false;
        }
    }

    return success;
}

bool Application::RegisterWindow(decode::Window* window)
{
    assert(window != nullptr);

    if (std::find(windows_.begin(), windows_.end(), window) != windows_.end())
    {
        GFXRECON_LOG_INFO("A window was registered with the application more than once");
        return false;
    }

    windows_.push_back(window);

    return true;
}

bool Application::UnregisterWindow(decode::Window* window)
{
    assert(window != nullptr);

    auto pos = std::find(windows_.begin(), windows_.end(), window);

    if (pos == windows_.end())
    {
        GFXRECON_LOG_INFO(
            "A remove window request was made for an window that was never registered with the application");
        return false;
    }

    windows_.erase(pos);

    return true;
}

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)
