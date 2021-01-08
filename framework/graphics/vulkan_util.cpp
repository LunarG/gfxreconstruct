/*
** Copyright (c) 2021 LunarG, Inc.
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

#include "graphics/vulkan_util.h"

#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

void EnableRequiredPhysicalDeviceFeatures(uint32_t                        instance_api_version,
                                          const encode::InstanceTable*    instance_table,
                                          const VkPhysicalDevice          physical_device,
                                          const VkDeviceCreateInfo*       create_info,
                                          ModifiedPhysicalDeviceFeatures& modified_features)
{
    VkBaseOutStructure* current_struct = reinterpret_cast<const VkBaseOutStructure*>(create_info)->pNext;
    while (current_struct != nullptr)
    {
        switch (current_struct->sType)
        {
            // Enable bufferDeviceAddressCaptureReplay if bufferDeviceAddress feature is enabled
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
            {
                VkPhysicalDeviceBufferDeviceAddressFeatures* buffer_address_features =
                    reinterpret_cast<VkPhysicalDeviceBufferDeviceAddressFeatures*>(current_struct);

                modified_features.bufferDeviceAddressCaptureReplay_ptr =
                    (&buffer_address_features->bufferDeviceAddressCaptureReplay);
                modified_features.bufferDeviceAddressCaptureReplay_original =
                    buffer_address_features->bufferDeviceAddressCaptureReplay;

                if (buffer_address_features->bufferDeviceAddress &&
                    !buffer_address_features->bufferDeviceAddressCaptureReplay)
                {
                    // Get buffer_address properties
                    VkPhysicalDeviceFeatures2 features2{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2 };
                    VkPhysicalDeviceBufferDeviceAddressFeatures supported_features{
                        VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES
                    };
                    features2.pNext = &supported_features;
                    if (instance_api_version >= VK_MAKE_VERSION(1, 1, 0))
                    {
                        instance_table->GetPhysicalDeviceFeatures2(physical_device, &features2);
                    }
                    else
                    {
                        instance_table->GetPhysicalDeviceFeatures2KHR(physical_device, &features2);
                    }

                    // Enable bufferDeviceAddressCaptureReplay if it is supported
                    if (supported_features.bufferDeviceAddressCaptureReplay)
                    {
                        buffer_address_features->bufferDeviceAddressCaptureReplay = true;
                    }
                }
            }
            break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT:
            {
                GFXRECON_LOG_ERROR("Extension %s is not supported by GFXReconstruct.",
                                   VK_EXT_BUFFER_DEVICE_ADDRESS_EXTENSION_NAME);
            }
            break;
            default:
                break;
        }
        current_struct = current_struct->pNext;
    }
}

void RestoreModifiedPhysicalDeviceFeatures(const ModifiedPhysicalDeviceFeatures& modified_features)
{
    if (modified_features.bufferDeviceAddressCaptureReplay_ptr != nullptr)
    {
        (*modified_features.bufferDeviceAddressCaptureReplay_ptr) =
            modified_features.bufferDeviceAddressCaptureReplay_original;
    }
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
