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
#pragma once

#include "vulkan/vulkan.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <unistd.h>
#include <unordered_map>
#include <vector>
)";

static const char* sCommonOutputHeaderFunctions = R"(
extern void QueryPhysicalDeviceMemoryProperties(VkPhysicalDevice physicalDevice);
extern uint32_t RecalculateAllocationSize(VkDeviceSize originalSize, VkMemoryRequirements memoryRequirements);
extern uint32_t RecalculateMemoryTypeIndex(uint32_t originalMemoryTypeIndex);
extern void LogVkError(const char* function, VkResult returnValue, const char* file, int line, VkResult capturedReturnValue);
)";

static const char* sCommonGlobalCppHeader = R"(
#include "global_var.h"
#include "loader.h"

#include <cassert>
)";

static const char* sCommonFrameSourceHeader = R"(
#include "global_var.h"
#include "loader.h"
#include "swapchain_common.h"

#include <cassert>
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
        bool     fallback_found          = false;
        uint32_t fallback_index          = 0;
        uint8_t  fallback_important_bits = 0;
        uint8_t  fallback_normal_bits    = 0;
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
    // Don't throw exception on positive return codes (e.g. VK_SUBOPTIMAL_KHR, VK_INCOMPLETE)
    if (returnValue < 0 && returnValue != capturedReturnValue) {
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
    XCBApp(uint32_t w, uint32_t h) {
        width = w;
        height = h;
    }
    uint32_t width { 320 };
    uint32_t height { 240 };
    xcb_connection_t *connection { nullptr };
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

XCBApp appdata(%d, %d);
)";

static const char* sXcbCMakeFile = R"(
cmake_minimum_required(VERSION 3.16.3)
project(vulkan_app)
set (CMAKE_CXX_STANDARD 20)
include_directories(${PROJECT_SOURCE_DIR}/src/)
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB MAIN_FILE ${PROJECT_SOURCE_DIR}/*.cpp)
add_executable(vulkan_app ${SRC_FILES} ${MAIN_FILE})
target_link_libraries(vulkan_app vulkan xcb)
)";
// End of Xcb template strings

// Beginning of Wayland template strings
static const char* sWaylandOutputMainStart = R"(
#include "global_var.h"

int main() {
)";

static const char* sWaylandOutputMainEnd = R"(
    return 0;
}
)";

static const char* sWaylandOutputHeadersPlatform = R"(
// This file is a generated source, follow the instructions under tools/tocpp/README.md to build.
#define VK_USE_PLATFORM_WAYLAND_KHR
)";

static const char* sWaylandOutputHeader = R"(
#include <wayland-client.h>
#include <xdg-shell-client-protocol.h>

#define VK_CALL_CHECK(VK_CALL, VK_RESULT) \
    LogVkError(#VK_CALL, (VK_CALL), __FILE__, __LINE__, VK_RESULT)

struct WaylandApp {
    WaylandApp(uint32_t w, uint32_t h) {
        width = w;
        height = h;
    }

    ~WaylandApp();

    uint32_t width { 320 };
    uint32_t height { 240 };

    struct {
        wl_display *display { nullptr };
        wl_compositor *compositor { nullptr };
        wl_surface *surface { nullptr };
        int shm_fd {-1};
        wl_shm *shm { nullptr };
        wl_shm_pool *shm_pool { nullptr };
        wl_buffer *buffer { nullptr };
    } wl;

    struct {
        xdg_wm_base *wm_base { nullptr };
        xdg_surface *surface { nullptr };
        xdg_toplevel *toplevel { nullptr };
    } xdg;
};

extern WaylandApp appdata;

extern void OverrideVkWaylandSurfaceCreateInfoKHR(VkWaylandSurfaceCreateInfoKHR* createInfo,
                                                  struct WaylandApp& appdata);
extern void UpdateWindowSize(uint32_t width,
                             uint32_t height,
                             uint32_t pre_transform,
                             struct WaylandApp& appdata);
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
                             struct WaylandApp& appdata);
)";

static const char* sWaylandOutputOverrideMethod = R"(
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <time.h>
#include <unistd.h>

WaylandApp::~WaylandApp()
{
  wl_buffer_destroy(appdata.wl.buffer);
  wl_shm_pool_destroy(appdata.wl.shm_pool);
  wl_shm_destroy(appdata.wl.shm);
  close(appdata.wl.shm_fd);
  xdg_wm_base_destroy(appdata.xdg.wm_base);
  xdg_toplevel_destroy(appdata.xdg.toplevel);
  xdg_surface_destroy(appdata.xdg.surface);
  wl_surface_destroy(appdata.wl.surface);
  wl_compositor_destroy(appdata.wl.compositor);
  wl_display_disconnect(appdata.wl.display);
}

static void Randname(char *buf)
{
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    long r = ts.tv_nsec;
    for (int i = 0; i < 6; ++i) {
        buf[i] = 'A'+(r&15)+(r&16)*2;
        r >>= 5;
    }
}

static int CreateShmFile(void)
{
    int retries = 100;
    do {
        char name[] = "/wl_shm-XXXXXX";
        Randname(name + sizeof(name) - 7);
        --retries;
        int fd = shm_open(name, O_RDWR | O_CREAT | O_EXCL, 0600);
        if (fd >= 0) {
            shm_unlink(name);
            return fd;
        }
    } while (retries > 0 && errno == EEXIST);
    return -1;
}

int AllocateShmFile(size_t size)
{
    int fd = CreateShmFile();
    if (fd < 0)
        return -1;
    int ret;
    do {
        ret = ftruncate(fd, size);
    } while (ret < 0 && errno == EINTR);
    if (ret < 0) {
        close(fd);
        return -1;
    }
    return fd;
}

static void
RegistryHandleGlobal(void *data, wl_registry *registry, uint32_t name, const char* interface, uint32_t version)
{
    WaylandApp *app = (WaylandApp *)data;
    if (strcmp(interface, wl_compositor_interface.name) == 0)
    {
        app->wl.compositor = (wl_compositor *)wl_registry_bind(registry, name, &wl_compositor_interface, 4);
    }
    if (strcmp(interface, wl_shm_interface.name) == 0)
    {
        app->wl.shm = (wl_shm *)wl_registry_bind(registry, name, &wl_shm_interface, 1);
    }
    if (strcmp(interface, xdg_wm_base_interface.name) == 0)
    {
      app->xdg.wm_base = (xdg_wm_base *)wl_registry_bind(registry, name, &xdg_wm_base_interface, 1);
    }
}

static void RegistryHandleGlobalRemove(void *data, wl_registry *registry, uint32_t name)
{
}

static const wl_registry_listener registry_listener = {
    .global = RegistryHandleGlobal,
    .global_remove = RegistryHandleGlobalRemove,
};

static void XdgSurfaceConfigure(void *data, xdg_surface *xdg_surface, uint32_t serial) {}

static const xdg_surface_listener surface_listener = {
    .configure = XdgSurfaceConfigure,
};

void OverrideVkWaylandSurfaceCreateInfoKHR(VkWaylandSurfaceCreateInfoKHR* createInfo, WaylandApp& appdata)
{
    if (appdata.wl.display == nullptr) {
        // Open the connection to the wayland server
        appdata.wl.display = wl_display_connect(nullptr);

        if (appdata.wl.display == nullptr)
        {
          printf("Cannot open display\n");
          exit(1);
        }

        wl_registry* registry = wl_display_get_registry(appdata.wl.display);
        wl_registry_add_listener(registry, &registry_listener, &appdata);
        wl_display_roundtrip(appdata.wl.display);
        wl_registry_destroy(registry);

        appdata.wl.surface = wl_compositor_create_surface(appdata.wl.compositor);

        appdata.xdg.surface = xdg_wm_base_get_xdg_surface(appdata.xdg.wm_base, appdata.wl.surface);
        xdg_surface_add_listener(appdata.xdg.surface, &surface_listener, &appdata);
        appdata.xdg.toplevel = xdg_surface_get_toplevel(appdata.xdg.surface);
        xdg_toplevel_set_title(appdata.xdg.toplevel, "vulkan-app");

        const int width = appdata.width;
        const int height = appdata.height;
        const int stride = width * 4;
        const int shm_pool_size = height * stride * 2;

        appdata.wl.shm_fd = AllocateShmFile(shm_pool_size);

        appdata.wl.shm_pool = wl_shm_create_pool(appdata.wl.shm, appdata.wl.shm_fd, shm_pool_size);

        int index = 0;
        int offset = height * stride * index;
        appdata.wl.buffer = wl_shm_pool_create_buffer(
            appdata.wl.shm_pool, offset, width, height, stride, WL_SHM_FORMAT_XRGB8888);

        wl_surface_attach(appdata.wl.surface, appdata.wl.buffer, 0, 0);
        wl_surface_damage(appdata.wl.surface, 0, 0, UINT32_MAX, UINT32_MAX);
        wl_surface_commit(appdata.wl.surface);
    }

    createInfo->sType = VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR;
    createInfo->display = appdata.wl.display;
    createInfo->surface = appdata.wl.surface;
}

void UpdateWindowSize(uint32_t width, uint32_t height, uint32_t pretransform, WaylandApp& appdata)
{
    appdata.width = width;
    appdata.height = height;
}

size_t LoadBinaryData(const char* filename,
                      size_t file_offset,
                      void* buffer,
                      size_t offset,
                      size_t data_size,
                      WaylandApp& appdata)
{
    (void)appdata; // Unused

    FILE* fp = fopen(filename, "rb");
    if (fp == nullptr)
    {
        throw std::runtime_error("Error while opening file: " + std::string(filename));
    }

    fseek(fp, file_offset, SEEK_SET);
    size_t read_size = fread((uint8_t *)buffer + offset, sizeof(uint8_t), data_size, fp);
    if (read_size != data_size)
    {
        fclose(fp);
        throw std::runtime_error("Error while reading file: " + std::string(filename));
    }

    fclose(fp);
    return read_size;
}

WaylandApp appdata(%d, %d);
)";

static const char* sWaylandCMakeFile = R"(
cmake_minimum_required(VERSION 3.16.3)
project(vulkan_app)
set (CMAKE_CXX_STANDARD 20)

find_program(WAYLAND_SCANNER NAMES wayland-scanner REQUIRED)
set(XDG_SHELL_PROTOCOL_C ${CMAKE_CURRENT_BINARY_DIR}/xdg-shell-protocol.c)
set(XDG_SHELL_CLIENT_PROTOCOL_H ${CMAKE_CURRENT_BINARY_DIR}/xdg-shell-client-protocol.h)
set(XDG_SHELL_XML /usr/share/wayland-protocols/stable/xdg-shell/xdg-shell.xml)
add_custom_command(
    OUTPUT ${XDG_SHELL_CLIENT_PROTOCOL_H} ${XDG_SHELL_PROTOCOL_C}
    COMMAND ${WAYLAND_SCANNER} client-header ${XDG_SHELL_XML} ${XDG_SHELL_CLIENT_PROTOCOL_H}
    COMMAND ${WAYLAND_SCANNER} private-code ${XDG_SHELL_XML} ${XDG_SHELL_PROTOCOL_C}
    DEPENDS ${XDG_SHELL_XML}
)

include_directories(${PROJECT_SOURCE_DIR}/src/ ${CMAKE_CURRENT_BINARY_DIR})
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB MAIN_FILE ${PROJECT_SOURCE_DIR}/*.cpp)
add_executable(vulkan_app ${SRC_FILES} ${MAIN_FILE} ${XDG_SHELL_PROTOCOL_C})
find_package(Vulkan REQUIRED)
find_package(PkgConfig)
pkg_check_modules(WAYLAND_CLIENT REQUIRED wayland-client)
target_link_libraries(vulkan_app Vulkan::Vulkan ${WAYLAND_CLIENT_LIBRARIES})
)";
// End of Wayland template strings

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

void OverrideVkAndroidSurfaceCreateInfoKHR(VkAndroidSurfaceCreateInfoKHR* createInfo, struct android_app* appdata)
{
    createInfo->sType  = VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR;
    createInfo->pNext  = nullptr;
    createInfo->flags  = 0;
    createInfo->window = appdata->window;
}

void LoadBinaryData(
    const char* filename, size_t file_offset, void* buffer, size_t offset, size_t data_size, android_app* app)
{
    AAsset* file = AAssetManager_open(app->activity->assetManager, filename, AASSET_MODE_STREAMING);
    if (!file)
    {
        throw std::runtime_error("Can't open file: " + std::string(filename));
    }

    AAsset_seek64(file, file_offset, SEEK_SET);
    int read_size = AAsset_read(file, (uint8_t*)buffer + offset, data_size);
    if (read_size < 0)
    {
        AAsset_close(file);
        throw std::runtime_error("Error while reading file: " + std::string(filename));
    }
    AAsset_close(file);
}

void CopyImageSubresourceMemory(const char*  filename,
                                size_t       file_offset,
                                uint8_t*     dst,
                                size_t       dst_offset,
                                size_t       size,
                                size_t       dst_row_pitch,
                                size_t       src_row_pitch,
                                uint32_t     height,
                                android_app* app)
{
    AAsset* file = AAssetManager_open(app->activity->assetManager, filename, AASSET_MODE_STREAMING);
    if (!file)
    {
        throw std::runtime_error("Can't open file: " + std::string(filename));
    }

    AAsset_seek64(file, file_offset, SEEK_SET);
    if (src_row_pitch == dst_row_pitch)
    {
        // Determine the aligned size of the destination subresource as row_pitch * height to ensure that we don't write
        // past the end of the resource in the case that the capture and replay resources had different slice pitches,
        // and the data size matches the size of a capture resource with a larger slice pitch.
        size_t subresource_size = height * dst_row_pitch;
        size_t copy_size        = std::min(size, (subresource_size - dst_offset));

        int read_size = AAsset_read(file, (uint8_t*)dst + dst_offset, copy_size);
        if (read_size < 0)
        {
            AAsset_close(file);
            throw std::runtime_error("Error while reading file: " + std::string(filename));
        }
    }
    else
    {
        size_t copy_row_pitch = std::min(dst_row_pitch, src_row_pitch);

        size_t current_row = dst_offset / src_row_pitch;
        size_t row_offset  = dst_offset % src_row_pitch;

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

        size_t   src_offset = file_offset;
        uint8_t* copy_dst = reinterpret_cast<uint8_t*>(dst) + (current_row * dst_row_pitch) + row_offset;

        // Process first partial row.
        if (row_offset > 0)
        {
            AAsset_seek64(file, src_offset, SEEK_SET);

            // Handle row with both partial begin and end positions.
            size_t copy_size = std::min(copy_row_pitch - row_offset, size);
            int read_size = AAsset_read(file, copy_dst, copy_size);
            if (read_size < 0)
            {
                AAsset_close(file);
                throw std::runtime_error("Error while reading file: " + std::string(filename));
            }

            src_offset += src_row_pitch - row_offset;
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
                AAsset_seek64(file, src_offset, SEEK_SET);

                size_t copy_size = copy_row_pitch;
                int    read_size = AAsset_read(file, copy_dst, copy_size);
                if (read_size < 0)
                {
                    AAsset_close(file);
                    throw std::runtime_error("Error while reading file: " + std::string(filename));
                }

                src_offset += src_row_pitch;
                copy_dst   += dst_row_pitch;
            }

            // Process a partial end row.
            if (row_remainder != 0)
            {
                AAsset_seek64(file, src_offset, SEEK_SET);

                size_t copy_size = std::min(copy_row_pitch, row_remainder);
                int    read_size = AAsset_read(file, copy_dst, copy_size);
                if (read_size < 0)
                {
                    AAsset_close(file);
                    throw std::runtime_error("Error while reading file: " + std::string(filename));
                }
            }
        }
    }
    AAsset_close(file);
}

AndroidScreen screen;
android_app*  appdata;

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
extern void CopyImageSubresourceMemory(const char*  filename,
                                       size_t       file_offset,
                                       uint8_t*     dst,
                                       size_t       dst_offset,
                                       size_t       size,
                                       size_t       dst_row_pitch,
                                       size_t       src_row_pitch,
                                       uint32_t     height,
                                       android_app* app);

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
    Win32App(uint32_t w, uint32_t h) {
        width = w;
        height = h;
    }
    uint32_t width { 320 };
    uint32_t height { 240 };
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
                                         struct Win32App& appdata)
{
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
                      struct Win32App& appdata)
{
    if (appdata.width == width && appdata.height == height)
    {
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
                      struct Win32App& appdata)
{
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

Win32App appdata(%d, %d);
)";

static const char* sWin32CMakeFile = R"(
cmake_minimum_required(VERSION 3.16.3)
project(vulkan_app)
set (CMAKE_CXX_STANDARD 20)
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

// Swapchain code
static const char* sSwapchainHeaderCode = R"(
#include <cassert>

// Device-specific Info

struct ToCppDeviceFeatures
{
    VkPhysicalDeviceFeatures                    features_1_0;
    VkPhysicalDeviceVulkan11Features            features_1_1;
    VkPhysicalDeviceVulkan12Features            features_1_2;
    VkPhysicalDeviceBufferDeviceAddressFeatures features_dev_buf_addr;
#ifndef VK_USE_PLATFORM_ANDROID_KHR
    VkPhysicalDeviceAccelerationStructureFeaturesKHR features_accel_struct;
    VkPhysicalDeviceRayTracingPipelineFeaturesKHR    features_ray_trace_pipeline;
#endif
};

struct ToCppQueueFamilyInfo
{
    VkDeviceQueueCreateFlags creation_flags;
    VkQueueFamilyProperties  family_props;
};

struct ToCppDeviceInfo
{
    VkPhysicalDevice                                   parent{ VK_NULL_HANDLE };
    ToCppDeviceFeatures                                features;
    std::unordered_map<uint32_t, ToCppQueueFamilyInfo> queue_family_info;
    std::vector<bool>                                  queue_family_enabled;
};
extern std::unordered_map<VkDevice, ToCppDeviceInfo*> g_device_info;

bool toCppInitDeviceInfo(VkPhysicalDevice physical_device, VkDevice device, VkDeviceCreateInfo* create_info);
void toCppDestroyDeviceInfo(VkDevice device);

// Queue-specific Info

struct ToCppQueueInfo
{
    VkDevice parent{ VK_NULL_HANDLE };
    uint32_t family_index{ 0 };
    uint32_t queue_index{ 0 };
};
extern std::unordered_map<VkQueue, ToCppQueueInfo> g_queue_info;

void toCppGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue);

// Swapchain-specific Info

struct ToCppVirtualImage
{
    VkDeviceMemory memory{ VK_NULL_HANDLE };
    VkImage        image{ VK_NULL_HANDLE };
};

struct ToCppCopyCmdData
{
    VkCommandPool                command_pool{ VK_NULL_HANDLE };
    std::vector<VkCommandBuffer> command_buffers;
    std::vector<VkSemaphore>     semaphores;
};

struct ToCppAcquiredData
{
    uint32_t index = { 0 };
    bool     acquired{ false };
};

struct ToCppSwapchainInfo
{
    VkDevice                                       parent;
    VkSurfaceKHR                                   surface;
    VkSwapchainCreateFlagsKHR                      flags;
    VkFormat                                       image_format;
    VkColorSpaceKHR                                image_color_space;
    VkExtent2D                                     image_extent;
    uint32_t                                       image_array_layers;
    VkImageUsageFlags                              image_usage;
    VkSharingMode                                  image_sharing_mode;
    VkPresentModeKHR                               present_mode;
    std::vector<uint32_t>                          queue_family_indices;
    std::unordered_map<uint32_t, ToCppCopyCmdData> copy_cmd_data;
    std::vector<ToCppVirtualImage>                 virtual_images;
    std::vector<VkImage>                           replay_images;
    std::vector<ToCppAcquiredData>                 acquired_indices;
};

extern std::unordered_map<VkSwapchainKHR, ToCppSwapchainInfo*> g_swapchain_info;

VkResult toCppCreateSwapchainKHR(VkDevice                        device,
                                 const VkSwapchainCreateInfoKHR* create_info,
                                 const VkAllocationCallbacks*    allocator,
                                 VkSwapchainKHR*                 swapchain);
void     toCppDestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* allocator);
VkResult toCppGetSwapchainImagesKHR(VkDevice       device,
                                    VkSwapchainKHR swapchain,
                                    uint32_t       captured_image_count,
                                    uint32_t*      replay_image_count,
                                    VkImage*       swapchain_images);
VkResult toCppAcquireNextImageKHR(VkResult       expected_result,
                                  VkDevice       device,
                                  VkSwapchainKHR swapchain,
                                  uint64_t       timeout,
                                  VkSemaphore    semaphore,
                                  VkFence        fence,
                                  uint32_t       captured_index,
                                  uint32_t*      replay_index);
VkResult toCppQueuePresentKHR(VkQueue queue, VkPresentInfoKHR* pPresentInfo);
)";

static const char* sSwapchainSourceCode_part_1 = R"(
#include "global_var.h"
#include "loader.h"
#include "swapchain_common.h"

#include <inttypes.h>

#include <limits>
#include <numeric>

// Global unordered_maps
std::unordered_map<VkDevice, ToCppDeviceInfo*>          g_device_info;
std::unordered_map<VkQueue, ToCppQueueInfo>             g_queue_info;
std::unordered_map<VkSwapchainKHR, ToCppSwapchainInfo*> g_swapchain_info;

bool toCppInitDeviceInfo(VkPhysicalDevice physical_device, VkDevice device, VkDeviceCreateInfo* create_info)
{
    bool             success  = false;
    ToCppDeviceInfo* dev_info = new ToCppDeviceInfo();
    if (dev_info == nullptr)
    {
        printf("ERROR: Failed to create ToCppDeviceInfo for new device.\n");
        return success;
    }
    dev_info->parent = physical_device;
    memset(&dev_info->features, 0, sizeof(ToCppDeviceFeatures));

    if (create_info->pEnabledFeatures != nullptr)
    {
        dev_info->features.features_1_0 = *(create_info->pEnabledFeatures);
    }

    const VkBaseInStructure* cur_next = reinterpret_cast<const VkBaseInStructure*>(create_info->pNext);
    while (cur_next != nullptr)
    {
        switch (cur_next->sType)
        {
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
                memcpy(&dev_info->features.features_1_1, cur_next, sizeof(VkPhysicalDeviceVulkan11Features));
                dev_info->features.features_1_1.pNext = nullptr;
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
                memcpy(&dev_info->features.features_1_2, cur_next, sizeof(VkPhysicalDeviceVulkan12Features));
                dev_info->features.features_1_2.pNext = nullptr;
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
                memcpy(&dev_info->features.features_dev_buf_addr,
                       cur_next,
                       sizeof(VkPhysicalDeviceBufferDeviceAddressFeatures));
                dev_info->features.features_dev_buf_addr.pNext = nullptr;
                break;
#ifndef VK_USE_PLATFORM_ANDROID_KHR
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR:
                memcpy(&dev_info->features.features_accel_struct,
                       cur_next,
                       sizeof(VkPhysicalDeviceAccelerationStructureFeaturesKHR));
                dev_info->features.features_accel_struct.pNext = nullptr;
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR:
                memcpy(&dev_info->features.features_ray_trace_pipeline,
                       cur_next,
                       sizeof(VkPhysicalDeviceRayTracingPipelineFeaturesKHR));
                dev_info->features.features_ray_trace_pipeline.pNext = nullptr;
                break;
#endif
            default:
                break;
        } // switch
        cur_next = cur_next->pNext;
    } // while

    // Keep track of what queue families this device is planning on using.  This information is
    // very important if we end up using the VulkanVirtualSwapchain path.
    auto max = [](uint32_t current_max, const VkDeviceQueueCreateInfo& dqci) {
        return std::max(current_max, dqci.queueFamilyIndex);
    };
    uint32_t max_queue_family = std::accumulate(
        create_info->pQueueCreateInfos, create_info->pQueueCreateInfos + create_info->queueCreateInfoCount, 0, max);
    dev_info->queue_family_enabled.clear();
    dev_info->queue_family_enabled.resize(max_queue_family + 1, false);

    uint32_t                             property_count = 0;
    std::vector<VkQueueFamilyProperties> props;
    vkGetPhysicalDeviceQueueFamilyProperties(physical_device, &property_count, nullptr);
    props.resize(property_count);
    vkGetPhysicalDeviceQueueFamilyProperties(physical_device, &property_count, props.data());

    for (uint32_t q = 0; q < create_info->queueCreateInfoCount; ++q)
    {
        ToCppQueueFamilyInfo queue_family_info{};

        const VkDeviceQueueCreateInfo* queue_create_info = &create_info->pQueueCreateInfos[q];
        assert(dev_info->queue_family_info.find(queue_create_info->queueFamilyIndex) ==
               dev_info->queue_family_info.end());

        queue_family_info.creation_flags = queue_create_info->flags;
        queue_family_info.family_props   = props[queue_create_info->queueFamilyIndex];

        dev_info->queue_family_info.emplace(queue_create_info->queueFamilyIndex, std::move(queue_family_info));
        dev_info->queue_family_enabled[queue_create_info->queueFamilyIndex] = true;
    }

    // Save device information for this device
    g_device_info[device] = dev_info;

    success = true;
    return success;
}

void toCppDestroyDeviceInfo(VkDevice device)
{
    if (g_device_info.find(device) != g_device_info.end())
    {
        ToCppDeviceInfo* dev_info = g_device_info[device];
        delete dev_info;
        g_device_info.erase(device);
    }
}

void toCppGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue)
{
    vkGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);

    if (g_queue_info.find(*pQueue) == g_queue_info.end())
    {
        ToCppQueueInfo queue_info;
        queue_info.parent       = device;
        queue_info.family_index = queueFamilyIndex;
        queue_info.queue_index  = queueIndex;
        g_queue_info.emplace(*pQueue, std::move(queue_info));
    }
}

VkResult toCppCreateSwapchainKHR(VkDevice                        device,
                                 const VkSwapchainCreateInfoKHR* create_info,
                                 const VkAllocationCallbacks*    allocator,
                                 VkSwapchainKHR*                 swapchain)
{
    VkSwapchainCreateInfoKHR modified_create_info = *create_info;
    ToCppDeviceInfo*         dev_info             = nullptr;
    ToCppSwapchainInfo*      swapchain_info       = nullptr;
    if (g_device_info.find(device) != g_device_info.end())
    {
        dev_info = g_device_info[device];
#if USE_VIRTUAL_SWAPCHAIN
        modified_create_info.imageUsage =
            modified_create_info.imageUsage | VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;
#endif // USE_VIRTUAL_SWAPCHAIN

        VkSurfaceCapabilitiesKHR surface_caps;
        if (VK_SUCCESS ==
            loaded_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(dev_info->parent, create_info->surface, &surface_caps))
        {
            if (modified_create_info.minImageCount < surface_caps.minImageCount)
            {
                modified_create_info.minImageCount = surface_caps.minImageCount;
            }
            if ((surface_caps.maxImageCount > 0) && (modified_create_info.minImageCount > surface_caps.maxImageCount))
            {
                modified_create_info.minImageCount = surface_caps.maxImageCount;
            }
        }

        swapchain_info = new ToCppSwapchainInfo();
        assert(swapchain_info != nullptr);

        swapchain_info->parent             = device;
        swapchain_info->surface            = create_info->surface;
        swapchain_info->image_format       = create_info->imageFormat;
        swapchain_info->image_color_space  = create_info->imageColorSpace;
        swapchain_info->image_array_layers = create_info->imageArrayLayers;
        swapchain_info->image_usage        = modified_create_info.imageUsage;
        swapchain_info->image_sharing_mode = modified_create_info.imageSharingMode;
        swapchain_info->present_mode       = modified_create_info.presentMode;

        memcpy(&swapchain_info->image_extent, &create_info->imageExtent, sizeof(VkExtent2D));
        for (uint32_t q = 0; q < create_info->queueFamilyIndexCount; ++q)
        {
            swapchain_info->queue_family_indices.push_back(create_info->pQueueFamilyIndices[q]);
        }
    }

    VkResult ret_value = loaded_vkCreateSwapchainKHR(device, &modified_create_info, allocator, swapchain);
    if (ret_value == VK_SUCCESS && dev_info != nullptr)
    {
        // Save swapchain information
        g_swapchain_info[*swapchain] = swapchain_info;
    }
    return ret_value;
}

void toCppDestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* allocator)
{
    if (g_swapchain_info.find(swapchain) != g_swapchain_info.end())
    {
        ToCppSwapchainInfo* swapchain_info = g_swapchain_info[swapchain];

        for (auto& image : swapchain_info->virtual_images)
        {
            vkFreeMemory(device, image.memory, nullptr);
            vkDestroyImage(device, image.image, nullptr);
        }

        delete swapchain_info;
        g_swapchain_info.erase(swapchain);
    }
    loaded_vkDestroySwapchainKHR(device, swapchain, allocator);
}

VkResult toCppCreateVirtualSwapchainImage(VkDevice                 device,
                                          const ToCppDeviceInfo*   device_info,
                                          const VkImageCreateInfo& image_create_info,
                                          ToCppVirtualImage&       image)
{
    VkResult result = vkCreateImage(device, &image_create_info, nullptr, &image.image);
    if (result == VK_SUCCESS)
    {
        VkMemoryRequirements memory_reqs;
        vkGetImageMemoryRequirements(device, image.image, &memory_reqs);

        VkMemoryPropertyFlags property_flags    = VK_QUEUE_FLAG_BITS_MAX_ENUM;
        uint32_t              memory_type_index = std::numeric_limits<uint32_t>::max();
        {
            VkPhysicalDeviceMemoryProperties properties;
            vkGetPhysicalDeviceMemoryProperties(device_info->parent, &properties);
            for (uint32_t i = 0; i < properties.memoryTypeCount; i++)
            {
                if ((memory_reqs.memoryTypeBits & (1 << i)) &&
                    ((properties.memoryTypes[i].propertyFlags & property_flags) != 0))
                {
                    memory_type_index = i;
                    break;
                }
            }
            assert(memory_type_index != std::numeric_limits<uint32_t>::max());
        }

        VkMemoryAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO };
        alloc_info.pNext                = nullptr;
        alloc_info.memoryTypeIndex      = memory_type_index;
        alloc_info.allocationSize       = memory_reqs.size;

        result = vkAllocateMemory(device, &alloc_info, nullptr, &image.memory);
        if (result == VK_SUCCESS)
        {
            result = vkBindImageMemory(device, image.image, image.memory, 0);
        }

        if (result != VK_SUCCESS)
        {
            if (image.memory != VK_NULL_HANDLE)
            {
                vkFreeMemory(device, image.memory, nullptr);
                image.memory = VK_NULL_HANDLE;
            }

            vkDestroyImage(device, image.image, nullptr);
            image.image = VK_NULL_HANDLE;
        }
    }
    return result;
}

VkResult toCppGetSwapchainImagesKHR(VkDevice       device,
                                    VkSwapchainKHR swapchain,
                                    uint32_t       captured_image_count,
                                    uint32_t*      replay_image_count,
                                    VkImage*       swapchain_images)
{
    VkResult result = VK_SUCCESS;
#if USE_VIRTUAL_SWAPCHAIN
    if (swapchain_images != nullptr && g_device_info.find(device) != g_device_info.end() &&
        g_swapchain_info.find(swapchain) != g_swapchain_info.end())
    {
        ToCppDeviceInfo*    dev_info       = g_device_info[device];
        ToCppSwapchainInfo* swapchain_info = g_swapchain_info[swapchain];

        swapchain_info->replay_images.resize(*replay_image_count);
        result =
            loaded_vkGetSwapchainImagesKHR(device, swapchain, replay_image_count, swapchain_info->replay_images.data());

        VkQueue  initial_copy_queue                = VK_NULL_HANDLE;
        bool     found_copy_queue_family           = false;
        uint32_t copy_queue_family_index           = VK_QUEUE_FAMILY_IGNORED;
        bool     found_transfer_queue_family_index = false;
        uint32_t transfer_queue_family_index       = 0;
        uint32_t max_queues                        = static_cast<uint32_t>(dev_info->queue_family_enabled.size());

        for (uint32_t queue_family = 0; queue_family < max_queues; ++queue_family)
        {
            if (dev_info->queue_family_info.find(queue_family) == dev_info->queue_family_info.end())
            {
                continue;
            }

            // If we find a graphics queue, we're good, so grab it and bail
            if (dev_info->queue_family_info[queue_family].family_props.queueFlags & VK_QUEUE_GRAPHICS_BIT)
            {
                copy_queue_family_index = queue_family;
                found_copy_queue_family = true;
                break;
            }

            // Find a transfer queue as an alternative, just in case
            if (!found_transfer_queue_family_index &&
                dev_info->queue_family_info[queue_family].family_props.queueFlags & VK_QUEUE_TRANSFER_BIT)
            {
                transfer_queue_family_index       = queue_family;
                found_transfer_queue_family_index = true;
            }
        }
        if (!found_copy_queue_family)
        {
            if (!found_transfer_queue_family_index)
            {
                printf("ERROR: Virtual swapchain failed finding a queue to create initial virtual swapchain "
                       "images for swapchain %p\n",
                       static_cast<void*>(swapchain));
                return VK_ERROR_OUT_OF_HOST_MEMORY;
            }
            copy_queue_family_index = transfer_queue_family_index;
        }
        vkGetDeviceQueue(device, copy_queue_family_index, 0, &initial_copy_queue);
        if (initial_copy_queue == VK_NULL_HANDLE)
        {
            printf("ERROR: Virtual swapchain failed getting transfer queue %u to create initial virtual swapchain "
                   "images for swapchain %p\n",
                   transfer_queue_family_index,
                   static_cast<void*>(swapchain));
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        for (uint32_t queue_family = 0; queue_family < max_queues; ++queue_family)
        {
            if (swapchain_info->copy_cmd_data.find(queue_family) == swapchain_info->copy_cmd_data.end())
            {
                // We only want to look at a given queue if it was enabled during device creation time
                // and if it supports present.  Otherwise, we don't need to create a command pool,
                // command buffers, and semaphores for performing the swapchain copy.
                if (dev_info->queue_family_enabled.size() <= queue_family ||
                    !dev_info->queue_family_enabled[queue_family])
                {
                    printf("INFO: Virtual swapchain skipping creating blit info for queue family %u because it "
                           "was not enabled by the device for swapchain %p\n",
                           queue_family,
                           static_cast<void*>(swapchain));
                    continue;
                }

                VkBool32 supported = VK_FALSE;
                result             = vkGetPhysicalDeviceSurfaceSupportKHR(
                    dev_info->parent, queue_family, swapchain_info->surface, &supported);
                if (result != VK_SUCCESS || supported == VK_FALSE)
                {
                    printf("INFO: Virtual swapchain skipping queue family %u since present support is not "
                           "present for swapchain %p\n",
                           queue_family,
                           static_cast<void*>(swapchain));
                    continue;
                }

)";

static const char* sSwapchainSourceCode_part_2 = R"(
                ToCppCopyCmdData copy_cmd_data = {};

                // Create one command pool per queue.
                VkCommandPoolCreateInfo command_pool_create_info = {
                    VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO,                                             // sType
                    nullptr,                                                                                // pNext
                    VK_COMMAND_POOL_CREATE_TRANSIENT_BIT | VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT, // flags
                    queue_family
                };

                result = vkCreateCommandPool(device, &command_pool_create_info, nullptr, &copy_cmd_data.command_pool);
                if (result != VK_SUCCESS)
                {
                    printf("ERROR: Virtual swapchain failed creating command pool %u for swapchain %p\n",
                           queue_family,
                           static_cast<void*>(swapchain));
                    return result;
                }
                swapchain_info->copy_cmd_data.emplace(queue_family, std::move(copy_cmd_data));
            }

            auto& copy_cmd_data = swapchain_info->copy_cmd_data[queue_family];

            // Make sure we have enough storage for each of our tracked components (Command pools,
            // Command Buffers, Semaphores, etc) as many queue families that are available.
            // This is because at any point, the application may get a Device queue from that family and
            // use it during the present.
            uint32_t start_size = static_cast<uint32_t>(copy_cmd_data.command_buffers.size());
            uint32_t new_count  = max_queues;
            if (start_size < new_count)
            {
                // Create one command buffer per queue per swapchain image so that we don't reset a command buffer
                // that may be in active use.
                uint32_t command_buffer_count = static_cast<uint32_t>(copy_cmd_data.command_buffers.size());
                if (command_buffer_count < captured_image_count)
                {
                    copy_cmd_data.command_buffers.resize(captured_image_count);

                    uint32_t                    new_count     = captured_image_count - command_buffer_count;
                    VkCommandBufferAllocateInfo allocate_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
                                                                  nullptr,
                                                                  copy_cmd_data.command_pool,
                                                                  VK_COMMAND_BUFFER_LEVEL_PRIMARY,
                                                                  new_count };

                    result = vkAllocateCommandBuffers(
                        device, &allocate_info, &copy_cmd_data.command_buffers[command_buffer_count]);
                    if (result != VK_SUCCESS)
                    {
                        printf("ERROR: Virtual swapchain failed allocating internal command buffer %u for "
                               "swapchain %p\n",
                               queue_family,
                               static_cast<void*>(swapchain));
                        return result;
                    }
                }
                uint32_t semaphore_count = static_cast<uint32_t>(copy_cmd_data.semaphores.size());
                if (semaphore_count < captured_image_count)
                {
                    copy_cmd_data.semaphores.resize(captured_image_count);

                    for (uint32_t ii = semaphore_count; ii < captured_image_count; ++ii)
                    {
                        VkSemaphoreCreateInfo semaphore_create_info = { VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO,
                                                                        nullptr,
                                                                        0 };

                        VkSemaphore semaphore = 0;
                        result                = vkCreateSemaphore(device, &semaphore_create_info, nullptr, &semaphore);
                        if (result != VK_SUCCESS)
                        {
                            printf("ERROR: Virtual swapchain failed creating internal copy semaphore for "
                                   "swapchain %p\n",
                                   static_cast<void*>(swapchain));
                            return result;
                        }
                        copy_cmd_data.semaphores[ii] = semaphore;
                    }
                }
            }
        }

        uint32_t virtual_swapchain_count = static_cast<uint32_t>(swapchain_info->virtual_images.size());

        // If the call was made more than once because the first call returned VK_INCOMPLETE, only the new images
        // returned by the second call will have virtual images created and appended to the end of the virtual image
        // array.
        if (virtual_swapchain_count < captured_image_count)
        {
            //  Create an image for the virtual swapchain.  Based on vkspec.html#swapchain-wsi-image-create-info.
            VkImageCreateInfo image_create_info = {
                VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
                nullptr,
                0,
                VK_IMAGE_TYPE_2D,
                swapchain_info->image_format,
                VkExtent3D{ swapchain_info->image_extent.width, swapchain_info->image_extent.height, 1 },
                1,
                swapchain_info->image_array_layers,
                VK_SAMPLE_COUNT_1_BIT,
                VK_IMAGE_TILING_OPTIMAL,
                swapchain_info->image_usage,
                swapchain_info->image_sharing_mode,
                max_queues,
                swapchain_info->queue_family_indices.data(),
                VK_IMAGE_LAYOUT_UNDEFINED
            };

            if ((swapchain_info->flags & VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR) ==
                VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR)
            {
                image_create_info.flags |= VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT;
            }

            for (uint32_t i = virtual_swapchain_count; i < captured_image_count; ++i)
            {
                ToCppVirtualImage image;
                result = toCppCreateVirtualSwapchainImage(device, dev_info, image_create_info, image);
                if (result != VK_SUCCESS)
                {
                    printf("ERROR: Failed to create virtual swapchain image for swapchain %p\n",
                           static_cast<void*>(swapchain));
                    break;
                }
                swapchain_info->virtual_images.emplace_back(std::move(image));
            }

            VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
            begin_info.pNext                    = nullptr;
            begin_info.flags                    = 0;
            begin_info.pInheritanceInfo         = nullptr;

            auto command_buffer = swapchain_info->copy_cmd_data[copy_queue_family_index].command_buffers[0];

            result = vkResetCommandBuffer(command_buffer, 0);
            if (result != VK_SUCCESS)
            {
                printf("ERROR: Virtual swapchain failed resetting internal command buffer %u for swapchain %p\n",
                       copy_queue_family_index,
                       static_cast<void*>(swapchain));
                return result;
            }

            result = vkBeginCommandBuffer(command_buffer, &begin_info);
            if (result != VK_SUCCESS)
            {
                printf("ERROR: Virtual swapchain failed starting internal command buffer %u for swapchain %p\n",
                       copy_queue_family_index,
                       static_cast<void*>(swapchain));
                return result;
            }

            VkImageMemoryBarrier barrier = {
                VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER, // sType
                nullptr,                                // pNext
                0,                                      // srcAccessMask (VK_ACCESS_NONE)
                0,                                      // dstAccessMask (VK_ACCESS_NONE)
                VK_IMAGE_LAYOUT_UNDEFINED,              // oldLayout
                VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,        // newLayout
                VK_QUEUE_FAMILY_IGNORED,                // srcQueueFamilyIndex
                VK_QUEUE_FAMILY_IGNORED,                // dstQueueFamilyIndex
                VK_NULL_HANDLE,                         // image
                VkImageSubresourceRange{
                    VK_IMAGE_ASPECT_COLOR_BIT,
                    0,
                    image_create_info.mipLevels,
                    0,
                    image_create_info.arrayLayers,
                }, // subResourceRange
            };

            for (uint32_t i = 0; i < *replay_image_count; ++i)
            {
                barrier.image = swapchain_info->replay_images[i];
                vkCmdPipelineBarrier(command_buffer,
                                     VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                     VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                     0,
                                     0,
                                     nullptr,
                                     0,
                                     nullptr,
                                     1,
                                     &barrier);
            }

            result = vkEndCommandBuffer(command_buffer);
            if (result != VK_SUCCESS)
            {
                printf("ERROR: Virtual swapchain failed ending internal command buffer %u for swapchain %p\n",
                       copy_queue_family_index,
                       static_cast<void*>(swapchain));
                return result;
            }

            VkSubmitInfo submit_info       = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
            submit_info.commandBufferCount = 1;
            submit_info.pCommandBuffers    = &command_buffer;

            result = vkQueueSubmit(initial_copy_queue, 1, &submit_info, VK_NULL_HANDLE);
            if (result != VK_SUCCESS)
            {
                printf("ERROR: Virtual swapchain failed submitting internal command buffer %u for swapchain %p\n",
                       copy_queue_family_index,
                       static_cast<void*>(swapchain));
                return result;
            }
            result = vkQueueWaitIdle(initial_copy_queue);
            if (result != VK_SUCCESS)
            {
                printf("ERROR: Virtual swapchain failed waiting for internal command buffer %u for swapchain %p\n",
                       copy_queue_family_index,
                       static_cast<void*>(swapchain));
                return result;
            }
        }

        for (uint32_t i = 0; i < captured_image_count; ++i)
        {
            swapchain_images[i] = swapchain_info->virtual_images[i].image;
        }
    }
    else
    {
        result = loaded_vkGetSwapchainImagesKHR(device, swapchain, replay_image_count, swapchain_images);
    }
#else  // USE_VIRTUAL_SWAPCHAIN
    result = loaded_vkGetSwapchainImagesKHR(device, swapchain, replay_image_count, swapchain_images);
#endif // USE_VIRTUAL_SWAPCHAIN

    return result;
}

VkResult toCppAcquireNextImageKHR(VkResult       expected_result,
                                  VkDevice       device,
                                  VkSwapchainKHR swapchain,
                                  uint64_t       timeout,
                                  VkSemaphore    semaphore,
                                  VkFence        fence,
                                  uint32_t       captured_index,
                                  uint32_t*      replay_index)
{
    VkResult result = VK_SUCCESS;
    if (expected_result == VK_SUCCESS)
    {
        while ((result = loaded_vkAcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, replay_index)) !=
               VK_SUCCESS)
        {
            usleep(5000);
        };
    }
    else
    {
        result = loaded_vkAcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, replay_index);
    }

#if USE_VIRTUAL_SWAPCHAIN
    // Record the capture versus replay indices
    if (result == VK_SUCCESS && g_swapchain_info.find(swapchain) != g_swapchain_info.end())
    {
        ToCppSwapchainInfo* swapchain_info     = g_swapchain_info[swapchain];
        uint32_t            replay_image_index = *replay_index;
        if (replay_image_index >= static_cast<uint32_t>(swapchain_info->acquired_indices.size()))
        {
            swapchain_info->acquired_indices.resize(replay_image_index + 1);
        }

        swapchain_info->acquired_indices[replay_image_index].index    = captured_index;
        swapchain_info->acquired_indices[replay_image_index].acquired = true;
    }
#endif // USE_VIRTUAL_SWAPCHAIN
    return result;
}

VkResult toCppQueuePresentKHR(VkQueue queue, VkPresentInfoKHR* pPresentInfo)
{
#if USE_VIRTUAL_SWAPCHAIN
    VkResult result = VK_SUCCESS;

    if (g_queue_info.find(queue) != g_queue_info.end())
    {
        ToCppQueueInfo&          queue_info = g_queue_info[queue];
        VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO, nullptr, 0, nullptr };

        VkImageMemoryBarrier initial_barrier_virtual_image;
        VkImageMemoryBarrier initial_barrier_swapchain_image;
        VkImageMemoryBarrier final_barrier_virtual_image;
        VkImageMemoryBarrier final_barrier_swapchain_image;

        initial_barrier_virtual_image = {
            VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
            nullptr,
            0, // VK_ACCESS_NONE,
            VK_ACCESS_TRANSFER_READ_BIT,
            VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
            VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
            VK_QUEUE_FAMILY_IGNORED,
            VK_QUEUE_FAMILY_IGNORED,
            VK_NULL_HANDLE,
            VkImageSubresourceRange{
                VK_IMAGE_ASPECT_COLOR_BIT,
                0,
                1,
                0,
                0,
            },
        };

        final_barrier_virtual_image               = initial_barrier_virtual_image;
        final_barrier_virtual_image.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
        final_barrier_virtual_image.dstAccessMask = VK_ACCESS_MEMORY_READ_BIT;
        final_barrier_virtual_image.oldLayout     = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
        final_barrier_virtual_image.newLayout     = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

        initial_barrier_swapchain_image               = initial_barrier_virtual_image;
        initial_barrier_swapchain_image.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
        initial_barrier_swapchain_image.newLayout     = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;

        final_barrier_swapchain_image           = final_barrier_virtual_image;
        final_barrier_swapchain_image.oldLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;

)";

static const char* sSwapchainSourceCode_part_3 = R"(
        VkImageSubresourceLayers subresource     = { VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 0 };
        VkOffset3D               offset          = { 0, 0, 0 };
        auto                     swapchain_count = pPresentInfo->swapchainCount;
        std::vector<VkSemaphore> present_wait_semaphores;

        // TODO: There is a potential issue here where a vkQueuePresent comes in on a queue (let's call
        // it QueueX) which does not support vkCmdCopyImage (i.e. a video-only queue).  In that case,
        // we would need to insert an emtpy command buffer into the command stream of QueueX which
        // triggers a semaphore (let's say SemA), then we would need to submit the vkCmdCopyImage in a
        // command buffer on a queue that supports it (let's say QueueY) which will wait on SemA to
        // start and signaling another semaphore (SemB) when it is done.  Then, we need to add the
        // QueuePresent to QueueX, but waiting on SemB before it executes.  And that is assuming that
        // the buffer image is even accessible on both Queues!

        for (uint32_t i = 0; i < swapchain_count; ++i)
        {
            VkSwapchainKHR swapchain = pPresentInfo->pSwapchains[i];
            if (g_swapchain_info.find(swapchain) == g_swapchain_info.end())
            {
                continue;
            }
            ToCppSwapchainInfo* swapchain_info      = g_swapchain_info[swapchain];
            uint32_t            replay_image_index  = pPresentInfo->pImageIndices[i];
            uint32_t            capture_image_index = swapchain_info->acquired_indices[replay_image_index].index;

            // Find the appropriate CommandCopyData struct for this queue family
            if (swapchain_info->copy_cmd_data.find(queue_info.family_index) == swapchain_info->copy_cmd_data.end())
            {
                printf("ERROR: Virtual swapchain vkQueuePresentKHR missing swapchain resource copy command data for "
                       "queue %p in swapchain %p\n",
                       static_cast<void*>(queue),
                       static_cast<void*>(swapchain));
                continue;
            }

            const auto& virtual_image = swapchain_info->virtual_images[capture_image_index];
            const auto& replay_image  = swapchain_info->replay_images[replay_image_index];

            // Use a command buffer and semaphore from the same queue index
            auto& copy_cmd_data  = swapchain_info->copy_cmd_data[queue_info.family_index];
            auto  command_buffer = copy_cmd_data.command_buffers[capture_image_index];
            auto  copy_semaphore = copy_cmd_data.semaphores[capture_image_index];

            std::vector<VkSemaphore> wait_semaphores;
            std::vector<VkSemaphore> signal_semaphores;

            // Only wait for the present semaphore dependencies on the first copy command buffer.
            // The others will automatically inherit that dependency because of their order in the
            // command buffer.
            if (i == 0 && pPresentInfo->waitSemaphoreCount > 0)
            {
                wait_semaphores.assign(pPresentInfo->pWaitSemaphores,
                                       pPresentInfo->pWaitSemaphores + pPresentInfo->waitSemaphoreCount);
            }

            // Only trigger a semaphore on the last copy
            if (i == swapchain_count - 1)
            {
                signal_semaphores.push_back(copy_semaphore);
                present_wait_semaphores.emplace_back(copy_semaphore);
            }

            result = vkResetCommandBuffer(command_buffer, 0);
            if (result != VK_SUCCESS)
            {
                return result;
            }
            result = vkBeginCommandBuffer(command_buffer, &begin_info);
            if (result != VK_SUCCESS)
            {
                return result;
            }

            initial_barrier_virtual_image.image                         = virtual_image.image;
            initial_barrier_virtual_image.subresourceRange.layerCount   = swapchain_info->image_array_layers;
            initial_barrier_swapchain_image.image                       = replay_image;
            initial_barrier_swapchain_image.subresourceRange.layerCount = swapchain_info->image_array_layers;

            vkCmdPipelineBarrier(command_buffer,
                                 VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                 VK_PIPELINE_STAGE_TRANSFER_BIT,
                                 0,
                                 0,
                                 nullptr,
                                 0,
                                 nullptr,
                                 1,
                                 &initial_barrier_virtual_image);

            vkCmdPipelineBarrier(command_buffer,
                                 VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
                                 VK_PIPELINE_STAGE_TRANSFER_BIT,
                                 0,
                                 0,
                                 nullptr,
                                 0,
                                 nullptr,
                                 1,
                                 &initial_barrier_swapchain_image);

            subresource.layerCount   = swapchain_info->image_array_layers;
            VkExtent3D  image_extent = { swapchain_info->image_extent.width, swapchain_info->image_extent.height, 1 };
            VkImageCopy image_copy   = { subresource, offset, subresource, offset, image_extent };

            // NOTE: vkCmdCopyImage works on Queues of types including Graphics, Compute
            //       and Transfer.  So should work on any queues we get a vkQueuePresentKHR from.
            vkCmdCopyImage(command_buffer,
                           virtual_image.image,
                           VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                           replay_image,
                           VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                           1,
                           &image_copy);

            final_barrier_virtual_image.image                         = virtual_image.image;
            final_barrier_virtual_image.subresourceRange.layerCount   = swapchain_info->image_array_layers;
            final_barrier_swapchain_image.image                       = replay_image;
            final_barrier_swapchain_image.subresourceRange.layerCount = swapchain_info->image_array_layers;

            vkCmdPipelineBarrier(command_buffer,
                                 VK_PIPELINE_STAGE_TRANSFER_BIT,
                                 VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                 0,
                                 0,
                                 nullptr,
                                 0,
                                 nullptr,
                                 1,
                                 &final_barrier_virtual_image);

            vkCmdPipelineBarrier(command_buffer,
                                 VK_PIPELINE_STAGE_TRANSFER_BIT,
                                 VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
                                 0,
                                 0,
                                 nullptr,
                                 0,
                                 nullptr,
                                 1,
                                 &final_barrier_swapchain_image);

            result = vkEndCommandBuffer(command_buffer);
            if (result != VK_SUCCESS)
            {
                return result;
            }

            VkPipelineStageFlags wait_stage = VK_PIPELINE_STAGE_TRANSFER_BIT;

            VkSubmitInfo submit_info       = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
            submit_info.waitSemaphoreCount = static_cast<uint32_t>(wait_semaphores.size());
            if (pPresentInfo->waitSemaphoreCount > 0)
            {
                submit_info.pWaitSemaphores = wait_semaphores.data();
            }
            else
            {
                submit_info.pWaitSemaphores = nullptr;
            }
            submit_info.pWaitDstStageMask    = &wait_stage;
            submit_info.signalSemaphoreCount = static_cast<uint32_t>(signal_semaphores.size());
            submit_info.pSignalSemaphores    = signal_semaphores.data();
            submit_info.commandBufferCount   = 1;
            submit_info.pCommandBuffers      = &command_buffer;

            result = vkQueueSubmit(queue, 1, &submit_info, VK_NULL_HANDLE);
            if (result != VK_SUCCESS)
            {
                return result;
            }
        }

        VkPresentInfoKHR modified_present_info   = *pPresentInfo;
        modified_present_info.waitSemaphoreCount = static_cast<uint32_t>(present_wait_semaphores.size());
        modified_present_info.pWaitSemaphores    = present_wait_semaphores.data();
        return loaded_vkQueuePresentKHR(queue, &modified_present_info);
    }
#endif
    return loaded_vkQueuePresentKHR(queue, pPresentInfo);
}
)";

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif // GFXRECON_DECODE_VULKAN_CPP_TEMPLATE_STRINGS_H
