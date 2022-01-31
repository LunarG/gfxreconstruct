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

#ifndef GFXRECON_DECODE_DEFERRED_OPERATION_INFO_MANAGER_H
#define GFXRECON_DECODE_DEFERRED_OPERATION_INFO_MANAGER_H

#include "generated/generated_vulkan_struct_decoders.h"
#include "decode/vulkan_object_info.h"
#include "decode/deferred_operation_info.h"

#include "vulkan/vulkan.h"

#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class DeferredOperationInfoManager
{
  public:
    static std::shared_ptr<DeferredOperationInfoManager>& Get() { return instance_; }

    void add(format::HandleId deferred_operation_handle, std::shared_ptr<DeferredOperationInfo> operation)
    {
        if ((deferred_operation_handle != gfxrecon::format::kNullHandleId) && (operation))
        {
            deferred_operations_[deferred_operation_handle] = std::move(operation);
        }
    }

    std::shared_ptr<DeferredOperationInfo>& find(format::HandleId deferred_operation_handle)
    {
        if (deferred_operations_.find(deferred_operation_handle) != deferred_operations_.end())
        {
            return deferred_operations_[deferred_operation_handle];
        }
        else
        {
            // The return of this function is a reference. If changed to nullptr
            // , a std::shared_ptr instance will be initialized with nullptr in
            // the function, the instance's reference will be return. But the
            // instance will be destroyed when the function end. So caller get
            // a reference of destroyed instance. This is the reason we use
            // null_operation_ here.
            return null_operation_;
        }
    }

    void Remove(format::HandleId deferred_operation_handle)
    {
        std::shared_ptr<DeferredOperationInfo> deferred_operation = std::move(find(deferred_operation_handle));
        deferred_operations_.erase(deferred_operation_handle);
    }

    DeferredOperationInfoManager() {}

    ~DeferredOperationInfoManager() {}

  protected:
    std::unordered_map<format::HandleId, std::shared_ptr<DeferredOperationInfo>> deferred_operations_;
    static std::shared_ptr<DeferredOperationInfoManager>                         instance_;
    std::shared_ptr<DeferredOperationInfo> null_operation_ = std::shared_ptr<DeferredOperationInfo>(nullptr);
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DEFERRED_OPERATION_INFO_MANAGER_H
