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
uint32_t RecalculateAllocationSize(VkDeviceSize originalSize,
                                   VkMemoryRequirements memoryRequirements) {
    if (originalSize >= memoryRequirements.size) {
        return originalSize;
    }
    printf("Warning: allocation size changed from %lu to %lu.\n",
           originalSize, memoryRequirements.size);
    return memoryRequirements.size;
}
)";

static const char* sCommonRecalculateMemoryTypeIndex = R"(
static uint8_t CountBits(uint32_t val) {
  if (val == 0) { return 0; }
  return ((val & 1) + CountBits(val >> 1));
}

uint32_t RecalculateMemoryTypeIndex(uint32_t originalMemoryTypeIndex) {
    VkMemoryPropertyFlags target_property_flags = originalMemoryTypes[0][originalMemoryTypeIndex].propertyFlags;
    uint32_t memory_type_index = UINT32_MAX;

    // Always try the same index in case we are attempting a replay on the same device as it was recorded on.
    if ((s_physicalDeviceMemoryProperties.memoryTypes[originalMemoryTypeIndex].propertyFlags & target_property_flags) ==
        target_property_flags) {
        memory_type_index = originalMemoryTypeIndex;
    } else {
        bool     fallback_found         = false;
        uint32_t fallback_index         = 0;
        uint8_t fallback_important_bits = 0;
        uint8_t fallback_normal_bits    = 0;
        for (uint32_t i = 0; i < s_physicalDeviceMemoryProperties.memoryTypeCount; i++) {
            if((s_physicalDeviceMemoryProperties.memoryTypes[i].propertyFlags & target_property_flags) == target_property_flags) {
              memory_type_index = i;
              break;
            }
            uint32_t cur_flags = (s_physicalDeviceMemoryProperties.memoryTypes[i].propertyFlags & target_property_flags);
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

        if (memory_type_index == UINT32_MAX) {
          if (fallback_found) {
            memory_type_index = fallback_index;
          } else {
            printf("Warning: couldn't find a matching memory type index, falling back to original.\n");
            memory_type_index = originalMemoryTypeIndex;
          }
        }

        if (originalMemoryTypeIndex != memory_type_index) {
          printf("Warning: memory type index changed from %u to %u.\n", originalMemoryTypeIndex, memory_type_index);
        }
    }

    return memory_type_index;
}
)";

static const char* sCommonLogVkError = R"(
void LogVkError(const char* function,
                VkResult returnValue,
                const char* fileName,
                int line,
                VkResult capturedReturnValue)
{
    // hack: '&& returnValue != VK_SUBOPTIMAL_KHR'
    if (returnValue != VK_SUCCESS && returnValue != VK_SUBOPTIMAL_KHR &&
        returnValue != capturedReturnValue) {
        int size = snprintf(NULL, 0,
                            "Function %s returned a non VK_SUCCESS result: %d (0x%x) at %s:%d\n",
                            function, returnValue, returnValue, fileName, line);

        char message[size + 2];
        snprintf(message, size + 2,
                 "Function %s returned a non VK_SUCCESS result: %d (0x%x) at %s:%d\n",
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
// This file is a generated source, follow the instructions under tools/tocpp/README.md to build.
#define VK_USE_PLATFORM_XCB_KHR
)";

static const char* sXcbOutputHeader = R"(
#define VK_CALL_CHECK(VK_CALL, VK_RESULT) \
    LogVkError(#VK_CALL, (VK_CALL), __FILE__, __LINE__, VK_RESULT)

struct XCBApp {
    uint32_t width;
    uint32_t height;
    xcb_connection_t *connection;
    xcb_window_t window;
};

extern XCBApp appdata;

extern void OverrideVkXcbSurfaceCreateInfoKHR(VkXcbSurfaceCreateInfoKHR* createInfo,
                                              struct XCBApp& appdata);
extern void UpdateWindowSize(uint32_t width,
                             uint32_t height,
                             uint32_t pre_transform,
                             struct XCBApp& appdata);
extern void LogVkError(const char* function,
                       VkResult returnValue,
                       const char* file,
                       int line,
                       VkResult capturedReturnValue);
extern size_t LoadBinaryData(const char* filename,
                             size_t file_offset,
                             void* buffer,
                             size_t offset,
                             size_t data_size,
                             struct XCBApp& appdata);
)";

static const char* sXcbOutputOverrideMethod = R"(
void OverrideVkXcbSurfaceCreateInfoKHR(VkXcbSurfaceCreateInfoKHR* createInfo,
                                       struct XCBApp& appdata) {
    // Open the connection to the X server
    xcb_connection_t *connection = xcb_connect(NULL, NULL);

    if (xcb_connection_has_error(connection) > 0)
    {
      printf("Cannot open display\n");
      exit(1);
    }

    // Get the first screen
    const xcb_setup_t      *setup  = xcb_get_setup(connection);
    xcb_screen_iterator_t   iter   = xcb_setup_roots_iterator(setup);
    xcb_screen_t           *screen = iter.data;

    // Create the window
    xcb_window_t window = xcb_generate_id(connection);
    xcb_create_window(connection,                    // Connection
                      XCB_COPY_FROM_PARENT,          // depth (same as root)
                      window,                        // window Id
                      screen->root,                  // parent window
                      0, 0,                          // x, y
                      appdata.width, appdata.height, // width, height
                      10,                            // border_width
                      XCB_WINDOW_CLASS_INPUT_OUTPUT, // class
                      screen->root_visual,           // visual
                      0, NULL );                     // masks, not used yet

    // Map the window on the screen
    xcb_map_window(connection, window);

    // Make sure commands are sent before we pause so that the window gets shown
    xcb_flush(connection);

    appdata.connection = connection;
    appdata.window = window;

    createInfo->sType = VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR;
    createInfo->connection = connection;
    createInfo->window = window;
}

void UpdateWindowSize(uint32_t width,
                      uint32_t height,
                      uint32_t pretransform,
                      struct XCBApp& appdata) {
    if (appdata.width == width && appdata.height == height) {
      return;
    }

    const uint32_t values[] = { width, height };
    xcb_configure_window(appdata.connection, appdata.window,
                         XCB_CONFIG_WINDOW_WIDTH | XCB_CONFIG_WINDOW_HEIGHT,
                         values);

    // Wait until the window size has changed
    while (true) {
      xcb_get_geometry_cookie_t geometryCookie =
          xcb_get_geometry(appdata.connection, appdata.window);
      xcb_get_geometry_reply_t* geometry =
          xcb_get_geometry_reply(appdata.connection, geometryCookie, NULL);

      if (geometry != NULL && geometry->width != appdata.width ||
          geometry->height != appdata.height) {
        break;
      }
      usleep(5000);
    }

    appdata.width = width;
    appdata.height = height;
}

size_t LoadBinaryData(const char* filename,
                      size_t file_offset,
                      void* buffer,
                      size_t offset,
                      size_t data_size,
                      struct XCBApp& appdata) {
    (void)appdata; // Unused

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
target_link_libraries(vulkan_app vulkan xcb)
)";
// End of Xcb template strings

// Beginning of Android template strings
static const char* sAndroidOutputHeadersPlatform = R"(
// This file is a generated source, follow the instructions under tools/tocpp/README.md to build.
#define VK_USE_PLATFORM_ANDROID_KHR
)";

static const char* sAndroidOutputGlobalSource = R"(
#include "ScreenOrientation.hpp"
#include "VulkanMain.hpp"

#include <algorithm>
#include <string>
#include <vulkan/vulkan.h>

void OverrideVkAndroidSurfaceCreateInfoKHR(VkAndroidSurfaceCreateInfoKHR* createInfo,
                                           struct android_app* appdata) {
    createInfo->sType = VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR;
    createInfo->pNext = nullptr;
    createInfo->flags = 0;
    createInfo->window = appdata->window;
}

void LoadBinaryData(const char* filename,
                    size_t file_offset,
                    void* buffer,
                    size_t offset,
                    size_t data_size,
                    android_app* app) {
    AAsset* file = AAssetManager_open(app->activity->assetManager, filename,
                                      AASSET_MODE_STREAMING);
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

void CopyImageSubresourceMemory(uint8_t*       dst,
                                const uint8_t* src,
                                size_t         offset,
                                size_t         size,
                                size_t         dst_row_pitch,
                                size_t         src_row_pitch,
                                uint32_t       height)
{
    if (src_row_pitch == dst_row_pitch)
    {
        // Determine the aligned size of the destination subresource as row_pitch * height to ensure that we don't write
        // past the end of the resource in the case that the capture and replay resources had different slice pitches,
        // and the data size matches the size of a capture resource with a larger slice pitch.
        size_t subresource_size = height * dst_row_pitch;
        size_t copy_size        = std::min(size, (subresource_size - offset));

        // Copy entire range without adjustment.
        memcpy(dst + offset, src, copy_size);
    }
    else
    {
        size_t copy_row_pitch = std::min(dst_row_pitch, src_row_pitch);

        size_t current_row = offset / src_row_pitch;
        size_t row_offset  = offset % src_row_pitch;

        if (row_offset >= copy_row_pitch)
        {
            // When the dst row pitch is smaller than the src row pitch, and the offset points to
            // padding at the end of the row, which is outside the bounds of the dst row pitch, we
            // advance to the start of the next row.  If the write was only to the padding, we set
            // row_offset to zero and advance to the next row without copying anything.
            size -= std::min(src_row_pitch - row_offset, size);
            row_offset = 0;
            ++current_row;
        }

        const uint8_t* copy_src = src;
        uint8_t*       copy_dst = reinterpret_cast<uint8_t*>(dst) + (current_row * dst_row_pitch) + row_offset;

        // Process first partial row.
        if (row_offset > 0)
        {
            // Handle row with both partial begin and end positions.
            size_t copy_size = std::min(copy_row_pitch - row_offset, size);
            memcpy(copy_dst, copy_src, copy_size);

            copy_src += src_row_pitch - row_offset;
            copy_dst += dst_row_pitch - row_offset;

            size -= std::min(src_row_pitch - row_offset, size);

            ++current_row;
        }

        // Process remaining rows.
        if (size > 0)
        {
            size_t total_rows    = size / src_row_pitch;
            size_t row_remainder = size % src_row_pitch;

            // Ensure that we don't write past the end of the resource memory for aligned sizes that produce a
            // total_rows value that is greater than the subresource height.
            size_t subresource_rows = height - current_row;
            if (total_rows >= subresource_rows)
            {
                total_rows    = subresource_rows;
                row_remainder = 0;
            }

            // First process the complete rows.
            for (size_t i = 0; i < total_rows; ++i)
            {
                size_t copy_size = copy_row_pitch;
                memcpy(copy_dst, copy_src, copy_size);

                copy_src += src_row_pitch;
                copy_dst += dst_row_pitch;
            }

            // Process a partial end row.
            if (row_remainder != 0)
            {
                size_t copy_size = std::min(copy_row_pitch, row_remainder);
                memcpy(copy_dst, copy_src, copy_size);
            }
        }
    }
}

AndroidScreen screen;
android_app* appdata;

uint32_t GetHardwareBufferFormatBpp(uint32_t format)
{
    switch (format)
    {
        case AHARDWAREBUFFER_FORMAT_BLOB:
        case AHARDWAREBUFFER_FORMAT_S8_UINT: // VK_FORMAT_S8_UINT
            return 1;
        case AHARDWAREBUFFER_FORMAT_R5G6B5_UNORM: // VK_FORMAT_R5G6B5_UNORM_PACK16
        case AHARDWAREBUFFER_FORMAT_D16_UNORM:    // VK_FORMAT_D16_UNORM
            return 2;
        case AHARDWAREBUFFER_FORMAT_R8G8B8_UNORM: // VK_FORMAT_R8G8B8_UNORM
            return 3;
        case AHARDWAREBUFFER_FORMAT_R8G8B8A8_UNORM:    // VK_FORMAT_R8G8B8A8_UNORM
        case AHARDWAREBUFFER_FORMAT_R8G8B8X8_UNORM:    // VK_FORMAT_R8G8B8A8_UNORM
        case AHARDWAREBUFFER_FORMAT_R10G10B10A2_UNORM: // VK_FORMAT_A2B10G10R10_UNORM_PACK32
        case AHARDWAREBUFFER_FORMAT_D24_UNORM:         // VK_FORMAT_X8_D24_UNORM_PACK32
        case AHARDWAREBUFFER_FORMAT_D24_UNORM_S8_UINT: // VK_FORMAT_D24_UNORM_S8_UINT
        case AHARDWAREBUFFER_FORMAT_D32_FLOAT:         // VK_FORMAT_D32_SFLOAT
            return 4;
        case AHARDWAREBUFFER_FORMAT_R16G16B16A16_FLOAT: // VK_FORMAT_R16G16B16A16_SFLOAT
        case AHARDWAREBUFFER_FORMAT_D32_FLOAT_S8_UINT:  // VK_FORMAT_D32_SFLOAT_S8_UINT
            return 8;
        default:
            break;
    }

    return 0;
}
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
void OverrideVkAndroidSurfaceCreateInfoKHR(VkAndroidSurfaceCreateInfoKHR* createInfo,
                                           struct android_app* appdata) {
    createInfo->sType = VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR;
    createInfo->pNext = nullptr;
    createInfo->flags = 0;
    createInfo->window = appdata->window;
}
)";

static const char* sAndroidOutputHeader = R"(
#include "ScreenOrientation.hpp"

#include <vector>

#define VK_CALL_CHECK(VK_CALL, VK_RESULT) \
    LogVkError(#VK_CALL, (VK_CALL), __FILE__, __LINE__, VK_RESULT)

extern void OverrideVkAndroidSurfaceCreateInfoKHR(VkAndroidSurfaceCreateInfoKHR* createInfo,
                                                  struct android_app* appdata);
extern void LoadBinaryData(const char* filename,
                           size_t file_offset,
                           void* buffer,
                           size_t offset,
                           size_t data_size,
                           android_app* app);
extern void CopyImageSubresourceMemory(uint8_t*       dst,
                                       const uint8_t* src,
                                       size_t         offset,
                                       size_t         size,
                                       size_t         dst_row_pitch,
                                       size_t         src_row_pitch,
                                       uint32_t       height);

struct HardwareBufferPlaneInfo
{
    uint64_t capture_offset;
    uint64_t replay_offset;
    uint32_t capture_row_pitch;
    uint32_t replay_row_pitch;
    uint32_t height;
};

struct HardwareBufferMemoryInfo
{
    AHardwareBuffer*                     hardware_buffer;
    bool                                 compatible_strides;
    std::vector<HardwareBufferPlaneInfo> plane_info;
};

extern AndroidScreen screen;
extern android_app* appdata;

uint32_t GetHardwareBufferFormatBpp(uint32_t format);
)";
// End of Android template strings

// Beginning of Win32 template strings
static const char* sWin32OutputMainStart = R"(
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>

#include "global_var.h"

int main() {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

)";

static const char* sWin32OutputMainEnd = R"(
    glfwDestroyWindow(appdata.window);
    glfwTerminate();

    return 0;
}
)";

static const char* sWin32OutputHeadersPlatform = R"(
// This file is a generated source, follow the instructions under tools/tocpp/README.md to build.
#define VK_USE_PLATFORM_WIN32_KHR
)";

static const char* sWin32OutputHeader = R"(
#define VK_CALL_CHECK(VK_CALL, VK_RESULT) \
    LogVkError(#VK_CALL, (VK_CALL), __FILE__, __LINE__, VK_RESULT)

struct Win32App {
    uint32_t width;
    uint32_t height;
    GLFWwindow* window;
    HINSTANCE hInstance;
    HWND hWnd;
};

extern Win32App appdata;

extern void OverrideVkWin32SurfaceCreateInfoKHR(VkWin32SurfaceCreateInfoKHR* createInfo,
                                                struct Win32App& appdata);
extern void UpdateWindowSize(uint32_t width,
                             uint32_t height,
                             uint32_t pre_transform,
                             struct Win32App& appdata);
extern void LogVkError(const char* function,
                       VkResult returnValue,
                       const char* file,
                       int line,
                       VkResult capturedReturnValue);
extern size_t LoadBinaryData(const char* filename,
                             size_t file_offset,
                             void* buffer,
                             size_t offset,
                             size_t data_size,
                             struct Win32App& appdata);
)";

static const char* sWin32OutputOverrideMethod = R"(
void OverrideVkWin32SurfaceCreateInfoKHR(VkWin32SurfaceCreateInfoKHR* createInfo,
                                         struct Win32App& appdata) {
    appdata.window = glfwCreateWindow(appdata.width,
                                      appdata.height,
                                      "Vulkan",
                                      nullptr,
                                      nullptr);
    appdata.hWnd = glfwGetWin32Window(appdata.window);
    appdata.hInstance = GetModuleHandle(nullptr);

    glfwMakeContextCurrent(appdata.window);

    createInfo->sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
    createInfo->hinstance = appdata.hInstance;
    createInfo->hwnd = appdata.hWnd;
}

void UpdateWindowSize(uint32_t width,
                      uint32_t height,
                      uint32_t pretransform,
                      struct Win32App& appdata) {
    if (appdata.width == width && appdata.height == height) {
      return;
    }

    // TODO: Implement Win32 resizing using GLFW

    appdata.width = width;
    appdata.height = height;
}

size_t LoadBinaryData(const char* filename,
                      size_t file_offset,
                      void* buffer,
                      size_t offset,
                      size_t data_size,
                      struct Win32App& appdata) {
    (void)appdata; // Unused

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

Win32App appdata = { %d, %d };
)";

static const char* sWin32CMakeFile = R"(
cmake_minimum_required(VERSION 3.3)
project(vulkan_app)
set (CMAKE_CXX_STANDARD 11)
include_directories(${PROJECT_SOURCE_DIR}/src/)
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB MAIN_FILE ${PROJECT_SOURCE_DIR}/*.cpp)
add_executable(vulkan_app ${SRC_FILES} ${MAIN_FILE})

target_compile_definitions(vulkan_app PRIVATE
    VK_USE_PLATFORM_WIN32_KHR
    WIN32_LEAN_AND_MEAN
    _CRT_SECURE_NO_WARNINGS
    VK_NO_PROTOTYPES
)
target_link_libraries(vulkan_app vulkan)
)";
// End of Win32 template strings

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif // GFXRECON_DECODE_VULKAN_CPP_TEMPLATE_STRINGS_H
