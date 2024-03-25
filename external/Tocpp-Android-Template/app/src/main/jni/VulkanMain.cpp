#include "VulkanMain.hpp"

#include <string>
#include <vulkan/vulkan.h>

#ifdef VK_USE_PLATFORM_ANDROID_KHR
void OverrideVkAndroidSurfaceCreateInfoKHR(VkAndroidSurfaceCreateInfoKHR* createInfo, struct ANativeWindow* window);
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

void FuncCallCheck(VkResult returnValue);


void VulkanDrawFrame(android_app* app) {
// ---- The generated source is placed below. -----

// VkInstanceCreateInfo...

// ---- The generated source is ended. -----
}

#ifdef VK_USE_PLATFORM_ANDROID_KHR
void OverrideVkAndroidSurfaceCreateInfoKHR(VkAndroidSurfaceCreateInfoKHR* createInfo, struct ANativeWindow* window) {
    createInfo->sType = VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR;
    createInfo->pNext = nullptr;
    createInfo->flags = 0;
    createInfo->window = window;
}
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

void FuncCallCheck(VkResult returnValue)
{
    if (returnValue != VK_SUCCESS) {
        throw std::runtime_error("Command failed!");
    }
}
