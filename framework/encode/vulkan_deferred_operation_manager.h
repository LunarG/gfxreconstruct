/*
** Copyright (c) 2021-2022 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_ENCODE_DEFERRED_OPERATION_MANAGER_H
#define GFXRECON_ENCODE_DEFERRED_OPERATION_MANAGER_H

#include "encode/vulkan_deferred_operation.h"

#include "vulkan/vulkan.h"

#include <mutex>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class VulkanDeferredOperationManager
{
  public:

    VulkanDeferredOperationManager() {}

    ~VulkanDeferredOperationManager() {}

    static std::shared_ptr<VulkanDeferredOperationManager>& Get() { return instance_; }

    void Add(VkDeferredOperationKHR deferred_operation_handle, std::shared_ptr<VulkanDeferredOperation> operation)
    {
        const std::lock_guard<std::mutex> lock(mutex_);

        if ((deferred_operation_handle != VK_NULL_HANDLE) && (operation))
        {
            deferred_operations_[deferred_operation_handle] = std::move(operation);
        }
    }

    std::shared_ptr<VulkanDeferredOperation>& Find(VkDeferredOperationKHR deferred_operation_handle)
    {
        const std::lock_guard<std::mutex> lock(mutex_);
        return FindDeferredOperation(deferred_operation_handle);
    }

    void PostProcess(VkDeferredOperationKHR deferred_operation_handle)
    {
        const std::lock_guard<std::mutex>   lock(mutex_);
        std::shared_ptr<VulkanDeferredOperation>& deferred_operation = FindDeferredOperation(deferred_operation_handle);

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

        std::shared_ptr<VulkanDeferredOperation>& deferred_operation = FindDeferredOperation(deferred_operation_handle);
        if (deferred_operation)
        {
            result = deferred_operation->GetStatus();
        }
        return result;
    }

  protected:
    std::shared_ptr<VulkanDeferredOperation>& FindDeferredOperation(VkDeferredOperationKHR deferred_operation_handle)
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
    std::unordered_map<VkDeferredOperationKHR, std::shared_ptr<VulkanDeferredOperation>> deferred_operations_;
    static std::shared_ptr<VulkanDeferredOperationManager>                               instance_;
    std::shared_ptr<VulkanDeferredOperation> null_operation_ = std::shared_ptr<VulkanDeferredOperation>(nullptr);
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_DEFERRED_OPERATION_MANAGER_H
