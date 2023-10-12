//
// Copyright (c) 2021 Samsung
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GFXRECON_DECODE_VULKAN_CPP_TEMPLATE_STRINGS_H
#define GFXRECON_DECODE_VULKAN_CPP_TEMPLATE_STRINGS_H

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Beginning of common template strings
static const char* sCommonHeaderOutputHeaders = R"(
#ifndef GLOBAL_VAR_H
#define GLOBAL_VAR_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <unistd.h>
#include <unordered_map>
#include <vector>

#include <vulkan/vulkan.h>
)";

static const char* sCommonHeaderOutputFooter = R"(
#endif // GLOBAL_VAR_H
)";

static const char* sCommonOutputHeaderFunctions = R"(
extern void QueryPhysicalDeviceMemoryProperties(VkPhysicalDevice physicalDevice);
extern uint32_t RecalculateAllocationSize(VkDeviceSize originalSize, VkMemoryRequirements memoryRequirements);
extern uint32_t RecalculateMemoryTypeIndex(uint32_t originalMemoryTypeIndex);
extern void LogVkError(const char* function, VkResult returnValue, const char* file, int line, VkResult capturedReturnValue);
)";

static const char* sCommonGlobalCppHeader = R"(
#include "global_var.h"
#include "vulkan/vulkan.h"
)";

static const char* sCommonFrameSourceHeader = R"(
#include "global_var.h"
#include "loader.h"
#include "vulkan/vulkan.h"
#include <vector>
)";

static const char* sCommonFrameSourceFooter = R"(
} // frame end
)";

static const char* sCommonQueryPhysicalDeviceMemoryProperties = R"(
static VkPhysicalDeviceMemoryProperties s_physicalDeviceMemoryProperties;
void QueryPhysicalDeviceMemoryProperties(VkPhysicalDevice physicalDevice) {
    vkGetPhysicalDeviceMemoryProperties(physicalDevice, &s_physicalDeviceMemoryProperties);
}
)";

static const char* sCommonRecalculateAllocationSize = R"(
uint32_t RecalculateAllocationSize(VkDeviceSize originalSize, VkMemoryRequirements memoryRequirements) {
    if (originalSize >= memoryRequirements.size) {
        return originalSize;
    }
    printf("Warning: allocation size changed from %lu to %lu.\n", originalSize, memoryRequirements.size);
    return memoryRequirements.size;
}
)";

static const char* sCommonRecalculateMemoryTypeIndex = R"(
static uint8_t CountBits(uint32_t val) {
  if (val == 0) { return 0; }
  return ((val & 1) + CountBits(val >> 1));
}

uint32_t RecalculateMemoryTypeIndex(uint32_t originalMemoryTypeIndex) {
    VkMemoryPropertyFlags targetPropertyFlags = originalMemoryTypes[0][originalMemoryTypeIndex].propertyFlags;
    uint32_t memoryTypeIndex = UINT32_MAX;

    // Always try the same index in case we are attempting a replay on the same device as it was recorded on.
    if ((s_physicalDeviceMemoryProperties.memoryTypes[originalMemoryTypeIndex].propertyFlags & targetPropertyFlags) ==
        targetPropertyFlags) {
        memoryTypeIndex = originalMemoryTypeIndex;
    } else {
        bool     fallback_found         = false;
        uint32_t fallback_index         = 0;
        uint8_t fallback_important_bits = 0;
        uint8_t fallback_normal_bits    = 0;
        for (uint32_t i = 0; i < s_physicalDeviceMemoryProperties.memoryTypeCount; i++) {
            if((s_physicalDeviceMemoryProperties.memoryTypes[i].propertyFlags & targetPropertyFlags) == targetPropertyFlags) {
              memoryTypeIndex = i;
              break;
            }
            uint32_t cur_flags = (s_physicalDeviceMemoryProperties.memoryTypes[i].propertyFlags & targetPropertyFlags);
            uint8_t normal_bits = CountBits(cur_flags);
            uint32_t important_flags = (cur_flags & (VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT));
            uint8_t important_bits = CountBits(important_flags);
            if (important_bits > fallback_important_bits && normal_bits >= fallback_normal_bits) {
              fallback_index = i;
              fallback_found = false;
              fallback_important_bits = important_bits;
              fallback_normal_bits    = normal_bits;
            }
        }

        if (memoryTypeIndex == UINT32_MAX) {
          if (fallback_found) {
            memoryTypeIndex = fallback_index;
          } else {
            printf("Warning: couldn't find a matching memory type index, falling back to original.\n");
            memoryTypeIndex = originalMemoryTypeIndex;
          }
        }

        if (originalMemoryTypeIndex != memoryTypeIndex) {
          printf("Warning: memory type index changed from %u to %u.\n", originalMemoryTypeIndex, memoryTypeIndex);
        }
    }

    return memoryTypeIndex;
}
)";

static const char* sCommonLogVkError = R"(
void LogVkError(const char* function, VkResult returnValue, const char* fileName, int line, VkResult capturedReturnValue)
{
    // hack: '&& returnValue != VK_SUBOPTIMAL_KHR'
    if (returnValue != VK_SUCCESS && returnValue != VK_SUBOPTIMAL_KHR && returnValue != capturedReturnValue) {
        int size = snprintf(NULL, 0, "Function %s returned a non VK_SUCCESS result: %d (0x%x) at %s:%d\n",
                            function, returnValue, returnValue, fileName, line);

        char message[size + 2];
        snprintf(message, size + 2, "Function %s returned a non VK_SUCCESS result: %d (0x%x) at %s:%d\n",
                 function, returnValue, returnValue, fileName, line);

        throw std::runtime_error(message);
    }
}
)";
// End of common template strings

// Beginning of Xcb template strings
static const char* sXcbOutputMainStart = R"(
#include "global_var.h"

int main() {
)";

static const char* sXcbOutputMainEnd = R"(
    return 0;
}
)";

static const char* sXcbOutputHeadersPlatform = R"(
/* This file is a generated source, follow the instructions under tools/tocpp/README.md to build. */
#define VK_USE_PLATFORM_XCB_KHR
)";

static const char* sXcbOutputHeader = R"(
#define VK_CALL_CHECK(VK_CALL, VK_RESULT) LogVkError(#VK_CALL, (VK_CALL), __FILE__, __LINE__, VK_RESULT)

struct XCBApp {
    uint32_t width;
    uint32_t height;
    xcb_connection_t *connection;
    xcb_window_t window;
};

extern XCBApp appdata;

extern void OverrideVkXcbSurfaceCreateInfoKHR(VkXcbSurfaceCreateInfoKHR* createInfo, struct XCBApp& appdata);
extern void UpdateWindowSize(uint32_t width, uint32_t height, uint32_t pre_transform, struct XCBApp& appdata);
extern void LogVkError(const char* function, VkResult returnValue, const char* file, int line, VkResult capturedReturnValue);
extern size_t loadData(const char* filename, size_t file_offset, void* buffer, size_t offset, size_t data_size, struct XCBApp& appdata);
)";

static const char* sXcbOutputOverrideMethod = R"(
void OverrideVkXcbSurfaceCreateInfoKHR(VkXcbSurfaceCreateInfoKHR* createInfo, struct XCBApp& appdata) {
    /* Open the connection to the X server */
    xcb_connection_t *connection = xcb_connect(NULL, NULL);

    if (xcb_connection_has_error(connection) > 0)
    {
      printf("Cannot open display\n");
      exit(1);
    }

    /* Get the first screen */
    const xcb_setup_t      *setup  = xcb_get_setup(connection);
    xcb_screen_iterator_t   iter   = xcb_setup_roots_iterator(setup);
    xcb_screen_t           *screen = iter.data;

    /* Create the window */
    xcb_window_t window = xcb_generate_id(connection);
    xcb_create_window(connection,                    /* Connection          */
                      XCB_COPY_FROM_PARENT,          /* depth (same as root)*/
                      window,                        /* window Id           */
                      screen->root,                  /* parent window       */
                      0, 0,                          /* x, y                */
                      appdata.width, appdata.height, /* width, height       */
                      10,                            /* border_width        */
                      XCB_WINDOW_CLASS_INPUT_OUTPUT, /* class               */
                      screen->root_visual,           /* visual              */
                      0, NULL );                     /* masks, not used yet */


    /* Map the window on the screen */
    xcb_map_window(connection, window);

    /* Make sure commands are sent before we pause so that the window gets shown */
    xcb_flush(connection);

    appdata.connection = connection;
    appdata.window = window;

    createInfo->sType = VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR;
    createInfo->connection = connection;
    createInfo->window = window;
}

void UpdateWindowSize(uint32_t width, uint32_t height, uint32_t pretransform, struct XCBApp& appdata) {
    if (appdata.width == width && appdata.height == height) {
      return;
    }

    const uint32_t values[] = { width, height };
    xcb_configure_window(appdata.connection, appdata.window, XCB_CONFIG_WINDOW_WIDTH | XCB_CONFIG_WINDOW_HEIGHT, values);

    // Wait until the window size has changed
    while (true) {
      xcb_get_geometry_cookie_t geometryCookie = xcb_get_geometry(appdata.connection, appdata.window);
      xcb_get_geometry_reply_t* geometry = xcb_get_geometry_reply(appdata.connection, geometryCookie, NULL);

      if (geometry != NULL && geometry->width != appdata.width || geometry->height != appdata.height) {
        break;
      }
      usleep(5000);
    }

    appdata.width = width;
    appdata.height = height;
}

size_t loadData(const char* filename, size_t file_offset, void* buffer, size_t offset, size_t data_size, struct XCBApp& appdata) {
    FILE* fp = fopen(filename, "rb");

    if (fp == nullptr) {
        throw std::runtime_error("Error while opening file: " + std::string(filename));
    }

    fseek(fp, file_offset, SEEK_SET);
    size_t read_size = fread((uint8_t*)buffer + offset, sizeof(uint8_t), data_size, fp);
    if (read_size != data_size) {
        fclose(fp);
        throw std::runtime_error("Error while reading file: " + std::string(filename));
    }

    fclose(fp);
    return read_size;
}

XCBApp appdata = { %d, %d };
)";

static const char* sXcbCMakeFile = R"(
cmake_minimum_required(VERSION 3.3)
project(vulkan_app)
set (CMAKE_CXX_STANDARD 11)
include_directories(${PROJECT_SOURCE_DIR}/src/)
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB MAIN_FILE ${PROJECT_SOURCE_DIR}/*.cpp)
add_executable(vulkan_app ${SRC_FILES} ${MAIN_FILE})
target_compile_options(vulkan_app PRIVATE -fPIC -mcmodel=large)
target_link_libraries(vulkan_app vulkan xcb)
target_link_options(vulkan_app PRIVATE -mcmodel=large)
)";
// End of Xcb template strings

// Beginning of Android template strings
static const char* sAndroidOutputHeadersPlatform = R"(
/* This file is a generated source, follow the instructions under tools/tocpp/README.md to build. */
#define VK_USE_PLATFORM_ANDROID_KHR
)";

static const char* sAndroidOutputGlobalSource = R"(
#include "ScreenOrientation.hpp"
#include "VulkanMain.hpp"

#include <string>
#include <vulkan/vulkan.h>

void OverrideVkAndroidSurfaceCreateInfoKHR(VkAndroidSurfaceCreateInfoKHR* createInfo, struct android_app* appdata) {
    createInfo->sType = VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR;
    createInfo->pNext = nullptr;
    createInfo->flags = 0;
    createInfo->window = appdata->window;
}

void loadData(const char* filename, size_t file_offset, void* buffer, size_t offset, size_t data_size, android_app* app) {
    AAsset* file = AAssetManager_open(app->activity->assetManager, filename, AASSET_MODE_STREAMING);
    if (!file) {
        throw std::runtime_error("Can't open file: " + std::string(filename));
    }

    AAsset_seek64(file, file_offset, SEEK_SET);
    int read_size = AAsset_read(file, (uint8_t*)buffer + offset, data_size);
    if (read_size < 0) {
        AAsset_close(file);
        throw std::runtime_error("Error while reading file: " + std::string(filename));
    }
    AAsset_close(file);
}

AndroidScreen screen;
android_app* appdata;
)";

static const char* sAndroidOutputDrawFunctionStart = R"(
#include "global_var.h"
#include "ScreenOrientation.hpp"

void VulkanDrawFrame(android_app* appdata_main) {
    appdata = appdata_main;
    screen = AndroidScreen(appdata);
)";

static const char* sAndroidOutputDrawFunctionEnd = R"(
    // Don't repeat all the call above again, they might fail due to unreleased resources.
    appdata->destroyRequested = 1;
}
)";

static const char* sAndroidOutputOverrideMethod = R"(
void OverrideVkAndroidSurfaceCreateInfoKHR(VkAndroidSurfaceCreateInfoKHR* createInfo, struct android_app* appdata) {
    createInfo->sType = VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR;
    createInfo->pNext = nullptr;
    createInfo->flags = 0;
    createInfo->window = appdata->window;
}
)";

static const char* sAndroidOutputHeader = R"(
#include "ScreenOrientation.hpp"

#define VK_CALL_CHECK(VK_CALL, VK_RESULT) LogVkError(#VK_CALL, (VK_CALL), __FILE__, __LINE__, VK_RESULT)

extern void OverrideVkAndroidSurfaceCreateInfoKHR(VkAndroidSurfaceCreateInfoKHR* createInfo, struct android_app* appdata);
extern void loadData(const char* filename, size_t file_offset, void* buffer, size_t offset, size_t data_size, android_app* app);

extern AndroidScreen screen;
extern android_app* appdata;
)";
// End of Android template strings

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif // GFXRECON_DECODE_VULKAN_CPP_TEMPLATE_STRINGS_H
