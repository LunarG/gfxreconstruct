/*
** Copyright (c) 2021 Advanced Micro Devices, Inc. All rights reserved**
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

#ifndef GFXRECON_ENCODE_DEFERRED_OPERATION_H
#define GFXRECON_ENCODE_DEFERRED_OPERATION_H

#include "encode/capture_settings.h"
#include "encode/descriptor_update_template_info.h"
#include "encode/parameter_buffer.h"
#include "encode/parameter_encoder.h"
#include "encode/vulkan_handle_wrapper_util.h"
#include "encode/vulkan_handle_wrappers.h"
#include "encode/vulkan_state_tracker.h"
#include "format/api_call_id.h"
#include "format/format.h"
#include "format/platform_types.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "generated/generated_vulkan_command_buffer_util.h"
#include "util/compressor.h"
#include "util/defines.h"
#include "util/file_output_stream.h"
#include "util/keyboard.h"
#include "util/shared_mutex.h"

#include "vulkan/vulkan.h"

#include <atomic>
#include <cassert>
#include <memory>
#include <mutex>
#include <set>
#include <shared_mutex>
#include <string>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class DeferredOperation
{
  public:
    DeferredOperation(format::ApiCallId call_id, VkDevice device, VkDeferredOperationKHR deferred_operation_handle) :
        api_call_id_(call_id), deferred_operation_(deferred_operation_handle), device_(device)
    {}
    ~DeferredOperation() {}

    virtual VkResult GetStatus();
    virtual void     PostProcess() = 0;

    format::ApiCallId GetApiCallId() { return api_call_id_; }
  protected:
    format::ApiCallId      api_call_id_;
    VkDeferredOperationKHR deferred_operation_;
    VkDevice               device_;
};

class DeferredOperationManager
{
  public:
    static std::unique_ptr<DeferredOperationManager>& Get() { return instance_; }

    void add(VkDeferredOperationKHR deferred_operation_handle, std::unique_ptr<DeferredOperation> operation)
    {
        const std::lock_guard<std::mutex> lock(mutex_);
        if ((deferred_operation_handle != VK_NULL_HANDLE) && (operation))
        {
            deferred_operations_[deferred_operation_handle] = std::move(operation);
        }
    }

    std::unique_ptr<DeferredOperation>& Find(VkDeferredOperationKHR deferred_operation_handle)
    {
        const std::lock_guard<std::mutex> lock(mutex_);
        return FindDeferredOperation(deferred_operation_handle);
    }

    void PostProcess(VkDeferredOperationKHR deferred_operation_handle)
    {
        const std::lock_guard<std::mutex>   lock(mutex_);
        std::unique_ptr<DeferredOperation>& deferred_operation = FindDeferredOperation(deferred_operation_handle);
        if (deferred_operation)
        {
            deferred_operation->PostProcess();
            deferred_operations_.erase(deferred_operation_handle);
        }
    }

    // return the current status of the deferred operation.
    // return VK_ERROR_UNKNOWN if deferred_operation_handle is not found.
    VkResult GetStatus(VkDeferredOperationKHR deferred_operation_handle)
    {
        const std::lock_guard<std::mutex> lock(mutex_);
        VkResult                          result = VK_ERROR_UNKNOWN;

        std::unique_ptr<DeferredOperation>& deferred_operation = FindDeferredOperation(deferred_operation_handle);
        if (deferred_operation)
        {
            result = deferred_operation->GetStatus();
        }
        return result;
    }

    DeferredOperationManager() {}

    ~DeferredOperationManager() {}

  protected:
    std::unique_ptr<DeferredOperation>& FindDeferredOperation(VkDeferredOperationKHR deferred_operation_handle)
    {
        if (deferred_operations_.find(deferred_operation_handle) != deferred_operations_.end())
        {
            return deferred_operations_[deferred_operation_handle];
        }
        else
        {
            return null_operation_;
        }
    }

  private:
    std::mutex                                                                     mutex_;
    std::unordered_map<VkDeferredOperationKHR, std::unique_ptr<DeferredOperation>> deferred_operations_;
    static std::unique_ptr<DeferredOperationManager>                               instance_;
    std::unique_ptr<DeferredOperation> null_operation_ = std::unique_ptr<DeferredOperation>(nullptr);
};

class DeferredOperationCreateRayTracingPipelines : public DeferredOperation
{
  public:
    DeferredOperationCreateRayTracingPipelines(VkDevice                                 device,
                                               VkDeferredOperationKHR                   deferredOperation,
                                               VkPipelineCache                          pipelineCache,
                                               uint32_t                                 createInfoCount,
                                               const VkRayTracingPipelineCreateInfoKHR* pCreateInfos,
                                               const VkAllocationCallbacks*             pAllocator,
                                               VkPipeline*                              pPipelines) :
        DeferredOperation(format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR, device, deferredOperation),
        pipeline_cache_(pipelineCache), create_info_count_(createInfoCount),
        create_infos_(pCreateInfos), allocator_(pAllocator), pipelines_(pPipelines),
        modified_create_infos_(std::make_unique<VkRayTracingPipelineCreateInfoKHR[]>(createInfoCount))
    {}

    ~DeferredOperationCreateRayTracingPipelines() {}

    void PostProcess();

    std::unique_ptr<VkRayTracingPipelineCreateInfoKHR[]>& GetModifiedCreateInfos() { return modified_create_infos_; }
    HandleUnwrapMemory&                                   GetHandleUnwrapMemory() { return handle_unwrap_memory_; }
    const VkRayTracingPipelineCreateInfoKHR*&             GetCreateInfosUnwrapped() { return create_infos_unwrapped_; }

  private:
    VkPipelineCache                          pipeline_cache_;
    uint32_t                                 create_info_count_;
    const VkRayTracingPipelineCreateInfoKHR* create_infos_;
    const VkAllocationCallbacks*             allocator_;
    VkPipeline*                              pipelines_;

    HandleUnwrapMemory                                   handle_unwrap_memory_;
    std::unique_ptr<VkRayTracingPipelineCreateInfoKHR[]> modified_create_infos_;
    const VkRayTracingPipelineCreateInfoKHR*             create_infos_unwrapped_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_DEFERRED_OPERATION_H
