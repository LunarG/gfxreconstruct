/*
** Copyright (c) 2023 Valve Corporation
** Copyright (c) 2023 LunarG, Inc.
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

#ifndef GFXRECON_CHILD_LAYER_H_
#define GFXRECON_CHILD_LAYER_H_

#include "util/defines.h"
#include "vulkan/vulkan.h"
#include "vulkan/vk_layer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

// The following functions must be defined by each implemented layer

VkResult layer_CreateInstance(const VkInstanceCreateInfo*  pCreateInfo,
                              const VkAllocationCallbacks* pAllocator,
                              VkInstance*                  pInstance);

VkResult layer_CreateDevice(VkPhysicalDevice             physicalDevice,
                            const VkDeviceCreateInfo*    pCreateInfo,
                            const VkAllocationCallbacks* pAllocator,
                            VkDevice*                    pDevice);

PFN_vkVoidFunction layer_GetInstanceProcAddr(VkInstance instance, const char* pName);
PFN_vkVoidFunction layer_GetDeviceProcAddr(VkDevice device, const char* pName);

GFXRECON_END_NAMESPACE(gfxrecon)

extern "C"
{
    VKAPI_ATTR VkResult VKAPI_CALL vkNegotiateLoaderLayerInterfaceVersion(VkNegotiateLayerInterface* pVersionStruct);
    VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetInstanceProcAddr(VkInstance instance, const char* pName);
    VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetDeviceProcAddr(VkDevice device, const char* pName);
}

#endif // GFXRECON_CHILD_LAYER_H_