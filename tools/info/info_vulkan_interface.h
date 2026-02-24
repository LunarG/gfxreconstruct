/*
** Copyright (c) 2026 LunarG, Inc.
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

#ifndef GFXRECON_INFO_VULKAN_INTERFACE_H
#define GFXRECON_INFO_VULKAN_INTERFACE_H

#include "info_api_interface.h"

#include "decode/vulkan_detection_consumer.h"
#include "decode/vulkan_stats_consumer.h"
#include "generated/generated_vulkan_decoder.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(info)

class InfoVulkanInterface : public InfoApiInterface
{
  public:
    InfoVulkanInterface() : vulkan_detection_consumer_(gfxrecon::decode::VulkanDetectionConsumer::kNoBlockLimit) {}
    virtual ~InfoVulkanInterface() = default;

    // Simple "getter" style methods
    virtual format::ApiFamilyId ApiFamilyId() override { return format::ApiFamilyId::ApiFamily_Vulkan; }
    virtual std::string         ApiLabel() override { return "Vulkan"; }
    virtual bool                ApiWasDetected() override { return vulkan_detection_consumer_.WasVulkanAPIDetected(); }
    virtual std::string         ApiCompiledHeaderVersionString() override;

    // API-specific command-line methods (default is do nothing and return true if required)
    virtual void UpdatePossibleCommandLineOptionsArgs(std::string& options, std::string& arguments) override;
    virtual void UpdateCommandLineUsage(std::string& usage) override;
    virtual bool CheckCommandLine(std::shared_ptr<gfxrecon::util::ArgumentParser> arg_parser) override;

    // Method to register this API's decoder elements with the containers
    // FileProcessor
    virtual void RegisterApiDecodeComponents(gfxrecon::decode::FileProcessor& file_processor) override;

    // Output methods%s
    virtual void OutputInfo() override;

    // Frame-specific methods
    virtual uint32_t GetFrameStart() override;

  private:
    gfxrecon::decode::VulkanDetectionConsumer vulkan_detection_consumer_;
    gfxrecon::decode::VulkanStatsConsumer     vulkan_stats_consumer_;
    gfxrecon::decode::VulkanDecoder           vulkan_decoder_;
};

GFXRECON_END_NAMESPACE(info)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_INFO_D3D12_INTERFACE_H
