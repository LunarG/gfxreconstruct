/*
** Copyright (c) 2021 Advanced Micro Devices, Inc. All rights reserved.
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

#include "project_version.h"

#include "encode/trace_manager.h"

#include "encode/vulkan_handle_wrapper_util.h"
#include "encode/vulkan_state_writer.h"
#include "format/format_util.h"
#include "generated/generated_vulkan_struct_handle_wrappers.h"
#include "graphics/vulkan_device_util.h"
#include "util/compressor.h"
#include "util/file_path.h"
#include "util/logging.h"
#include "util/page_guard_manager.h"
#include "util/platform.h"
#include "encode/deferred_operation_manager.h"
#include "encode/deferred_operation_create_ray_tracing_pipelines.h"

#include <cassert>
#include <unordered_set>
#include <encode/struct_pointer_encoder.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)
std::unique_ptr<DeferredOperationManager> DeferredOperationManager::instance_ =
    std::make_unique<DeferredOperationManager>();

VkResult DeferredOperation::GetStatus()
{
    VkDevice               device_unwrapped    = GetWrappedHandle<VkDevice>(device_);
    VkDeferredOperationKHR operation_unwrapped = GetWrappedHandle<VkDeferredOperationKHR>(deferred_operation_);

    VkResult result = GetDeviceTable(device_)->GetDeferredOperationResultKHR(device_unwrapped, operation_unwrapped);
    return result;
}

void DeferredOperationCreateRayTracingPipelines::PostProcess()
{
    VkResult result = VK_SUCCESS;
    if (pipelines_ != nullptr)
    {
        auto               device_wrapper = reinterpret_cast<DeviceWrapper*>(device_);
        const DeviceTable* device_table   = GetDeviceTable(device_);
        CreateWrappedHandles<DeviceWrapper, DeferredOperationKHRWrapper, PipelineWrapper>(
            device_, deferred_operation_, pipelines_, create_info_count_, TraceManager::GetUniqueId);

        if (device_wrapper->property_feature_info.feature_rayTracingPipelineShaderGroupHandleCaptureReplay)
        {
            for (uint32_t i = 0; i < create_info_count_; ++i)
            {
                PipelineWrapper* pipeline_wrapper = reinterpret_cast<PipelineWrapper*>(pipelines_[i]);

                uint32_t data_size = device_wrapper->property_feature_info.property_shaderGroupHandleCaptureReplaySize *
                                     create_infos_[i].groupCount;
                std::vector<uint8_t> data(data_size);

                device_table->GetRayTracingCaptureReplayShaderGroupHandlesKHR(device_wrapper->handle,
                                                                              pipeline_wrapper->handle,
                                                                              0,
                                                                              create_infos_[i].groupCount,
                                                                              data_size,
                                                                              data.data());

                TraceManager::Get()->WriteSetRayTracingShaderGroupHandlesCommand(
                    device_wrapper->handle_id, pipeline_wrapper->handle_id, data_size, data.data());

                if ((TraceManager::Get()->GetCaptureMode() & TraceManager::CaptureModeFlags::kModeTrack) ==
                    TraceManager::CaptureModeFlags::kModeTrack)
                {
                    TraceManager::Get()->GetStateTracker()->TrackRayTracingShaderGroupHandles(
                        device_, pipelines_[i], data_size, data.data());
                }
            }
        }
        auto encoder =
            TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR);
        if (encoder)
        {
            encoder->EncodeHandleValue(device_);
            encoder->EncodeHandleValue(deferred_operation_);
            encoder->EncodeHandleValue(pipeline_cache_);
            encoder->EncodeUInt32Value(create_info_count_);
            EncodeStructArray(encoder, create_infos_, create_info_count_);
            EncodeStructPtr(encoder, allocator_);
            encoder->EncodeHandleArray(pipelines_, create_info_count_, false);
            encoder->EncodeEnumValue(VK_OPERATION_DEFERRED_KHR);
            TraceManager::Get()
                ->EndGroupCreateApiCallTrace<VkDevice,
                                             VkDeferredOperationKHR,
                                             PipelineWrapper,
                                             VkRayTracingPipelineCreateInfoKHR>(
                    result, device_, deferred_operation_, create_info_count_, pipelines_, create_infos_);
        }
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
