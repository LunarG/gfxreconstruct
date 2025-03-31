/*
** Copyright (c) 2024 LunarG, Inc.
** Copyright (c) 2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#ifndef GFXRECON_DECODE_VULKAN_EXAMPLE_MODIFIER_H
#define GFXRECON_DECODE_VULKAN_EXAMPLE_MODIFIER_H

#include "util/defines.h"
#include "util/vulkan_modifier_base.h"
#include "encode/struct_pointer_encoder.h"
#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Example usage of VulkanModifier to add, modify and remove calls from trace.
// This is just for demonstration purposes.
// This modifier will use vkSetDebugUtilsObjectNameEXT call to name all compacted copies of
// other acceleration structures. Performs several operaions:
// 1. Adds vkSetDebugUtilsObjectNameEXT calls after relevant vkCreateAccelerationStructureKHR
// 2. Removes existing vkSetDebugUtilsObjectNameEXT calls for objects marked in step 1.
// 3. Modifies VkCreateInstance call to include VK_EXT_debug_utils in enabled extension list
// To test this example you need any trace that performs an acceleration structure copy with
// VK_COPY_ACCELERATION_STRUCTURE_MODE_COMPACT_KHR mode, for example:
// https://github.com/ARM-software/tracetooltests/blob/main/src/vulkan_as_3.cpp
class VulkanExampleModifier : public util::VulkanModifierBase
{
  public:
    VulkanExampleModifier() = default;

    bool CanOptimize() override { return compacted_copies_.empty(); }

    // Example call modification
    // Add debug utils to list of extensions
    void Process_vkCreateInstance(const ApiCallInfo&                                   call_info,
                                  VkResult                                             returnValue,
                                  StructPointerDecoder<Decoded_VkInstanceCreateInfo>*  pCreateInfo,
                                  StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                  HandlePointerDecoder<VkInstance>*                    pInstance) override
    {
        // Just modification pass, nothing to analyze
        if (parameter_buffer_)
        {
            auto create_info     = pCreateInfo->GetMetaStructPointer()->decoded_value;
            auto extension_count = create_info->enabledExtensionCount;
            if (extension_count)
            {
                bool debug_utils_enabled = false;
                for (uint32_t i = 0; i < extension_count; i++)
                {
                    std::string extension_name = create_info->ppEnabledExtensionNames[i];
                    if (extension_name == VK_EXT_DEBUG_UTILS_EXTENSION_NAME)
                    {
                        debug_utils_enabled = true;
                        break;
                    }
                }
                if (!debug_utils_enabled)
                {
                    auto                     new_extension_count = extension_count + 1;
                    std::vector<const char*> new_extensions(new_extension_count);
                    new_extensions.assign(create_info->ppEnabledExtensionNames,
                                          create_info->ppEnabledExtensionNames + extension_count);
                    new_extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);

                    create_info->enabledExtensionCount   = new_extension_count;
                    create_info->ppEnabledExtensionNames = new_extensions.data();

                    parameter_buffer_->Clear();
                    gfxrecon::encode::ParameterEncoder encoder(parameter_buffer_);
                    EncodeStructPtr(&encoder, pCreateInfo->GetPointer());
                    EncodeStructPtr(&encoder, pAllocator->GetPointer());
                    encoder.EncodeHandleIdPtr(pInstance->GetPointer());
                    encoder.EncodeEnumValue(returnValue);
                }
            }
        }
    }

    // Example call deletion
    // Remove other SetName calls targeting the object we want to name
    void Process_vkSetDebugUtilsObjectNameEXT(
        const ApiCallInfo&                                           call_info,
        VkResult                                                     returnValue,
        format::HandleId                                             device,
        StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>* pNameInfo) override
    {
        if (parameter_buffer_)
        {
            const auto compacted_copy = compacted_copies_.find(pNameInfo->GetPointer()->objectHandle);
            if (compacted_copy != compacted_copies_.end())
            {
                delete_current_call = true;
            }
        }
    }

    // Example call tracking
    // This override does not modify anything, just stores data required for later modifications.
    // In this case, handles of acceleration structures used for compaction purposes are stored in a map
    // along with the handle of the original non-compacted AS.
    void Process_vkCmdCopyAccelerationStructureKHR(
        const ApiCallInfo&                                                call_info,
        format::HandleId                                                  commandBuffer,
        StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo) override
    {
        // Keep track of compacted acceleration structures
        if (!parameter_buffer_)
        {
            const auto* info = pInfo->GetMetaStructPointer();

            if (info->decoded_value->mode == VK_COPY_ACCELERATION_STRUCTURE_MODE_COMPACT_KHR)
            {
                compacted_copies_[info->dst] = info->src;
            }
        }
    }

    // Example of adding new call
    // When vkCreateAccelerationStructureKHR call is processed in the modification pass
    // and there's a record of the created acceleration structure being used later as compacted
    // copy destination, add vkSetDebugUtilsObjectNameEXT after this call.
    void Process_vkCreateAccelerationStructureKHR(
        const ApiCallInfo&                                                  call_info,
        VkResult                                                            returnValue,
        format::HandleId                                                    device,
        StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>*                pAllocator,
        HandlePointerDecoder<VkAccelerationStructureKHR>*                   pAccelerationStructure) override
    {
        // In modification pass, add SetObjectName command after AS creation
        if (parameter_buffer_)
        {
            const auto compaction_info = compacted_copies_.find(*pAccelerationStructure->GetPointer());

            if (compaction_info != compacted_copies_.end())
            {
                // Initialize new call data
                auto new_call        = CreatePostCall();
                new_call->call_id    = gfxrecon::format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT;
                new_call->thread_id  = call_info.thread_id;
                std::string new_name = "Compacted copy of " + std::to_string(compaction_info->second);

                VkDebugUtilsObjectNameInfoEXT object_name_info;
                object_name_info.sType        = VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT;
                object_name_info.objectType   = VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR;
                object_name_info.pObjectName  = new_name.c_str();
                object_name_info.objectHandle = *pAccelerationStructure->GetPointer();
                object_name_info.pNext        = nullptr;
                assert(object_name_info.pNext == nullptr);

                // Encode new call
                gfxrecon::encode::ParameterEncoder encoder(&new_call->parameter_buffer);
                encoder.EncodeHandleIdValue(device);
                encoder.EncodeStructPtrPreamble(&object_name_info, false, false);
                encoder.EncodeEnumValue(object_name_info.sType);
                EncodePNextStruct(&encoder, object_name_info.pNext);
                encoder.EncodeEnumValue(object_name_info.objectType);
                encoder.EncodeUInt64Value(object_name_info.objectHandle);
                encoder.EncodeString(object_name_info.pObjectName);
                encoder.EncodeEnumValue(VK_SUCCESS);
            }
        }
    }

  private:
    // Contains handles of a compacted copy (fist) and the original non-compacted acceleration structure (second)
    std::unordered_map<format::HandleId, format::HandleId> compacted_copies_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_EXAMPLE_MODIFIER_H
