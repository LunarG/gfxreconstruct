/*
** Copyright (c) 2022-2023 Advanced Micro Devices, Inc. All rights reserved.
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

#include "decode_api_detection.h"
#include "decode/file_processor.h"
#include "decode/vulkan_detection_consumer.h"
#include "generated/generated_vulkan_decoder.h"

#ifdef ENABLE_OPENXR_SUPPORT
#include "decode/openxr_detection_consumer.h"
#include "generated/generated_openxr_decoder.h"
#endif

#if defined(D3D12_SUPPORT)
#include "decode/dx12_detection_consumer.h"
#endif

#ifdef GFXRECON_AGS_SUPPORT
#include "decode/custom_ags_decoder.h"
#include "decode/ags_detection_consumer.h"
#endif // GFXRECON_AGS_SUPPORT

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

bool DetectAPIs(const std::string& input_filename,
                bool&              dx12_detected,
                bool&              vulkan_detected,
                bool&              openxr_detected,
                bool               no_block_limit)
{
    dx12_detected   = false;
    vulkan_detected = false;
    openxr_detected = false;

    gfxrecon::decode::FileProcessor file_processor;
    if (file_processor.Initialize(input_filename))
    {
        uint64_t vulkan_block_limit = no_block_limit ? gfxrecon::decode::VulkanDetectionConsumer::kNoBlockLimit
                                                     : gfxrecon::decode::VulkanDetectionConsumer::kDefaultBlockLimit;
        gfxrecon::decode::VulkanDetectionConsumer vulkan_detection_consumer(vulkan_block_limit);
        gfxrecon::decode::VulkanDecoder           vulkan_decoder;
        vulkan_decoder.AddConsumer(&vulkan_detection_consumer);
        file_processor.AddDecoder(&vulkan_decoder);
#if defined(D3D12_SUPPORT)
        uint64_t dx12_block_limit = no_block_limit ? gfxrecon::decode::Dx12DetectionConsumer::kNoBlockLimit
                                                   : gfxrecon::decode::Dx12DetectionConsumer::kDefaultBlockLimit;
        gfxrecon::decode::Dx12DetectionConsumer dx12_detection_consumer(dx12_block_limit);
        gfxrecon::decode::Dx12Decoder           dx12_decoder;
        dx12_decoder.AddConsumer(&dx12_detection_consumer);
        file_processor.AddDecoder(&dx12_decoder);

#ifdef GFXRECON_AGS_SUPPORT
        gfxrecon::decode::AgsDetectionConsumer ags_detection_consumer;
        gfxrecon::decode::AgsDecoder           ags_decoder;
        ags_decoder.AddConsumer(&ags_detection_consumer);
        file_processor.AddDecoder(&ags_decoder);
#endif // GFXRECON_AGS_SUPPORT

#endif

#ifdef ENABLE_OPENXR_SUPPORT
        gfxrecon::decode::OpenXrDetectionConsumer openxr_detection_consumer;
        gfxrecon::decode::OpenXrDecoder           openxr_decoder;
        openxr_decoder.AddConsumer(&openxr_detection_consumer);
        file_processor.AddDecoder(&openxr_decoder);
#endif // ENABLE_OPENXR_SUPPORT

        file_processor.ProcessAllFrames();
#if defined(D3D12_SUPPORT)
        if (dx12_detection_consumer.WasD3D12APIDetected())
        {
            dx12_detected = true;
        }

#ifdef GFXRECON_AGS_SUPPORT
        if (ags_detection_consumer.WasAgsDx12Detected())
        {
            dx12_detected = true;
        }
#endif // GFXRECON_AGS_SUPPORT

#endif

        if (vulkan_detection_consumer.WasVulkanAPIDetected())
        {
            vulkan_detected = true;
        }

#ifdef ENABLE_OPENXR_SUPPORT
        if (openxr_detection_consumer.WasOpenXrAPIDetected())
        {
            openxr_detected = true;
        }
#endif // ENABLE_OPENXR_SUPPORT
    }
    return dx12_detected || vulkan_detected || openxr_detected;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
