/*
** Copyright (c) 2018 LunarG, Inc.
**
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

#ifndef BRIMSTONE_PLATFORM_TYPES_H
#define BRIMSTONE_PLATFORM_TYPES_H

#include "vulkan/vulkan.h"
#include "vulkan/vk_icd.h"

// System types for WIN32 platform extensions.
#if defined(WIN32)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#else // WIN32
#include <cwchar>

typedef const wchar_t* LPCWSTR;
typedef void*          HINSTANCE;
typedef void*          HWND;
typedef void*          HANDLE;

// Define a version of the WIN32 SECURITY_ATTRIBUTES struct that
// is suitable for decoding on non-WIN32 platforms.
typedef uint32_t       DWORD;
typedef int32_t        BOOL;
typedef void*          LPVOID;
typedef uint8_t        BYTE;
typedef uint16_t       WORD;
typedef WORD           SECURITY_DESCRIPTOR_CONTROL;

struct SID_IDENTIFIER_AUTHORITY
{
    BYTE Value[6];
};

struct SID
{
    BYTE                     Revision;
    BYTE                     SubAuthorityCount;
    SID_IDENTIFIER_AUTHORITY IdentifierAuthority;
    DWORD                    SubAuthority[1];
};

struct ACL
{
    BYTE AclRevision;
    BYTE Sbz1;
    WORD AclSize;
    WORD AceCount;
    WORD Sbz2;
};

typedef void* PSID;
typedef ACL*  PACL;

struct SECURITY_DESCRIPTOR
{
    BYTE                        Revision;
    BYTE                        Sbz1;
    SECURITY_DESCRIPTOR_CONTROL Control;
    PSID                        Owner;
    PSID                        Group;
    PACL                        Sacl;
    PACL                        Dacl;
};

struct SECURITY_ATTRIBUTES
{
    DWORD  nLength;
    LPVOID lpSecurityDescriptor;
    BOOL   bInheritHandle;
};
#endif // WIN32

// Types for WSI platform extensions.

#if !defined(VK_USE_PLATFORM_XCB_KHR)
typedef VkFlags                 VkXcbSurfaceCreateFlagsKHR;
typedef struct xcb_connection_t xcb_connection_t;
typedef uint32_t                xcb_window_t;
typedef uint32_t                xcb_visualid_t;

struct VkXcbSurfaceCreateInfoKHR
{
    VkStructureType            sType;
    const void*                pNext;
    VkXcbSurfaceCreateFlagsKHR flags;
    xcb_connection_t*          connection;
    xcb_window_t               window;
};

struct VkIcdSurfaceXcb
{
    VkIcdSurfaceBase  base;
    xcb_connection_t* connection;
    xcb_window_t      window;
};

extern "C" {
typedef VkResult(VKAPI_PTR* PFN_vkCreateXcbSurfaceKHR)(VkInstance                       instance,
                                                       const VkXcbSurfaceCreateInfoKHR* pCreateInfo,
                                                       const VkAllocationCallbacks*     pAllocator,
                                                       VkSurfaceKHR*                    pSurface);
typedef VkBool32(VKAPI_PTR* PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR)(VkPhysicalDevice  physicalDevice,
                                                                              uint32_t          queueFamilyIndex,
                                                                              xcb_connection_t* connection,
                                                                              xcb_visualid_t    visual_id);
}
#endif // VK_USE_PLATFORM_XCB_KHR

#if !defined(VK_USE_PLATFORM_XLIB_KHR)
typedef VkFlags          VkXlibSurfaceCreateFlagsKHR;
typedef struct _XDisplay Display;
typedef uint32_t         CARD32;
typedef CARD32           XID;
typedef XID              Window;
typedef CARD32           VisualID;
typedef XID              RROutput;

struct VkXlibSurfaceCreateInfoKHR
{
    VkStructureType             sType;
    const void*                 pNext;
    VkXlibSurfaceCreateFlagsKHR flags;
    Display*                    dpy;
    Window                      window;
};

struct VkIcdSurfaceXlib
{
    VkIcdSurfaceBase base;
    Display*         dpy;
    Window           window;
};

extern "C" {
typedef VkResult(VKAPI_PTR* PFN_vkCreateXlibSurfaceKHR)(VkInstance                        instance,
                                                        const VkXlibSurfaceCreateInfoKHR* pCreateInfo,
                                                        const VkAllocationCallbacks*      pAllocator,
                                                        VkSurfaceKHR*                     pSurface);
typedef VkBool32(VKAPI_PTR* PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR)(VkPhysicalDevice physicalDevice,
                                                                               uint32_t         queueFamilyIndex,
                                                                               Display*         dpy,
                                                                               VisualID         visualID);
}
#endif // VK_USE_PLATFORM_XLIB_KHR

#if !defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
typedef XID RROutput;
#endif // VK_USE_PLATFORM_XLIB_XRANDR_EXT

#if !defined(VK_USE_PLATFORM_WAYLAND_KHR)
typedef VkFlags VkWaylandSurfaceCreateFlagsKHR;

struct VkWaylandSurfaceCreateInfoKHR
{
    VkStructureType                sType;
    const void*                    pNext;
    VkWaylandSurfaceCreateFlagsKHR flags;
    struct wl_display*             display;
    struct wl_surface*             surface;
};

struct VkIcdSurfaceWayland
{
    VkIcdSurfaceBase   base;
    struct wl_display* display;
    struct wl_surface* surface;
};

extern "C" {
typedef VkResult(VKAPI_PTR* PFN_vkCreateWaylandSurfaceKHR)(VkInstance                           instance,
                                                           const VkWaylandSurfaceCreateInfoKHR* pCreateInfo,
                                                           const VkAllocationCallbacks*         pAllocator,
                                                           VkSurfaceKHR*                        pSurface);
typedef VkBool32(VKAPI_PTR* PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR)(VkPhysicalDevice   physicalDevice,
                                                                                  uint32_t           queueFamilyIndex,
                                                                                  struct wl_display* display);
}
#endif // VK_USE_PLATFORM_WAYLAND_KHR

#if !defined(VK_USE_PLATFORM_ANDROID_KHR)
typedef VkFlags   VkAndroidSurfaceCreateFlagsKHR;
typedef uint32_t* ANativeWindow;

struct VkAndroidSurfaceCreateInfoKHR
{
    VkStructureType                sType;
    const void*                    pNext;
    VkAndroidSurfaceCreateFlagsKHR flags;
    ANativeWindow*                 window;
};

struct VkIcdSurfaceAndroid
{
    ANativeWindow* window;
};

struct AHardwareBuffer
{
    int notYetImplemented;
};

struct VkAndroidHardwareBufferPropertiesANDROID
{
    int notYetImplemented;
};

struct VkMemoryGetAndroidHardwareBufferInfoANDROID
{
    int notYetImplemented;
};

extern "C" {
typedef VkResult(VKAPI_PTR* PFN_vkCreateAndroidSurfaceKHR)(VkInstance                           instance,
                                                           const VkAndroidSurfaceCreateInfoKHR* pCreateInfo,
                                                           const VkAllocationCallbacks*         pAllocator,
                                                           VkSurfaceKHR*                        pSurface);
typedef VkResult(VKAPI_PTR* PFN_vkGetAndroidHardwareBufferPropertiesANDROID)(
    VkDevice device, const struct AHardwareBuffer* buffer, VkAndroidHardwareBufferPropertiesANDROID* pProperties);
typedef VkResult(VKAPI_PTR* PFN_vkGetMemoryAndroidHardwareBufferANDROID)(
    VkDevice device, const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo, struct AHardwareBuffer** pBuffer);
}
#endif // VK_USE_PLATFORM_ANDROID_KHR

#if !defined(VK_USE_PLATFORM_WIN32_KHR)
typedef VkFlags VkWin32SurfaceCreateFlagsKHR;

struct VkWin32SurfaceCreateInfoKHR
{
    VkStructureType              sType;
    const void*                  pNext;
    VkWin32SurfaceCreateFlagsKHR flags;
    HINSTANCE                    hinstance;
    HWND                         window;
};

struct VkMemoryWin32HandlePropertiesKHR
{
    VkStructureType sType;
    void*           pNext;
    uint32_t        memoryTypeBits;
};

struct VkMemoryGetWin32HandleInfoKHR
{
    VkStructureType                       sType;
    const void*                           pNext;
    VkDeviceMemory                        memory;
    VkExternalMemoryHandleTypeFlagBitsKHR handleType;
};

struct VkImportSemaphoreWin32HandleInfoKHR
{
    VkStructureType                          sType;
    const void*                              pNext;
    VkSemaphore                              semaphore;
    VkSemaphoreImportFlagsKHR                flags;
    VkExternalSemaphoreHandleTypeFlagBitsKHR handleType;
    HANDLE                                   handle;
    LPCWSTR                                  name;
};

struct VkSemaphoreGetWin32HandleInfoKHR
{
    VkStructureType                          sType;
    const void*                              pNext;
    VkSemaphore                              semaphore;
    VkExternalSemaphoreHandleTypeFlagBitsKHR handleType;
};

struct VkImportFenceWin32HandleInfoKHR
{
    VkStructureType                      sType;
    const void*                          pNext;
    VkFence                              fence;
    VkFenceImportFlagsKHR                flags;
    VkExternalFenceHandleTypeFlagBitsKHR handleType;
    HANDLE                               handle;
    LPCWSTR                              name;
};

struct VkFenceGetWin32HandleInfoKHR
{
    VkStructureType                      sType;
    const void*                          pNext;
    VkFence                              fence;
    VkExternalFenceHandleTypeFlagBitsKHR handleType;
};

extern "C" {
typedef VkResult(VKAPI_PTR* PFN_vkCreateWin32SurfaceKHR)(VkInstance                         instance,
                                                         const VkWin32SurfaceCreateInfoKHR* pCreateInfo,
                                                         const VkAllocationCallbacks*       pAllocator,
                                                         VkSurfaceKHR*                      pSurface);
typedef VkBool32(VKAPI_PTR* PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR)(VkPhysicalDevice physicalDevice,
                                                                                uint32_t         queueFamilyIndex);
typedef VkResult(VKAPI_PTR* PFN_vkGetMemoryWin32HandleKHR)(VkDevice                             device,
                                                           const VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo,
                                                           HANDLE*                              pHandle);
typedef VkResult(VKAPI_PTR* PFN_vkGetMemoryWin32HandlePropertiesKHR)(
    VkDevice                           device,
    VkExternalMemoryHandleTypeFlagBits handleType,
    HANDLE                             handle,
    VkMemoryWin32HandlePropertiesKHR*  pMemoryWin32HandleProperties);
typedef VkResult(VKAPI_PTR* PFN_vkImportSemaphoreWin32HandleKHR)(
    VkDevice device, const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo);
typedef VkResult(VKAPI_PTR* PFN_vkGetSemaphoreWin32HandleKHR)(
    VkDevice device, const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle);
typedef VkResult(VKAPI_PTR* PFN_vkImportFenceWin32HandleKHR)(
    VkDevice device, const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo);
typedef VkResult(VKAPI_PTR* PFN_vkGetFenceWin32HandleKHR)(VkDevice                            device,
                                                          const VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo,
                                                          HANDLE*                             pHandle);
typedef VkResult(VKAPI_PTR* PFN_vkGetMemoryWin32HandleNV)(VkDevice                          device,
                                                          VkDeviceMemory                    memory,
                                                          VkExternalMemoryHandleTypeFlagsNV handleType,
                                                          HANDLE*                           pHandle);
}
#endif // VK_USE_PLATFORM_WIN32_KHR

#endif // BRIMSTONE_PLATFORM_TYPES_H
