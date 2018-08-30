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

// Types for platform extensions.

#if !defined(VK_USE_PLATFORM_ANDROID_KHR)
typedef VkFlags VkAndroidSurfaceCreateFlagsKHR;

struct ANativeWindow;
struct AHardwareBuffer;

struct VkAndroidSurfaceCreateInfoKHR
{
    VkStructureType                sType;
    const void*                    pNext;
    VkAndroidSurfaceCreateFlagsKHR flags;
    ANativeWindow*                 window;
};

struct VkAndroidHardwareBufferUsageANDROID
{
    VkStructureType sType;
    void*           pNext;
    uint64_t        androidHardwareBufferUsage;
};

struct VkAndroidHardwareBufferPropertiesANDROID
{
    VkStructureType sType;
    void*           pNext;
    VkDeviceSize    allocationSize;
    uint32_t        memoryTypeBits;
};

struct VkAndroidHardwareBufferFormatPropertiesANDROID
{
    VkStructureType               sType;
    void*                         pNext;
    VkFormat                      format;
    uint64_t                      externalFormat;
    VkFormatFeatureFlags          formatFeatures;
    VkComponentMapping            samplerYcbcrConversionComponents;
    VkSamplerYcbcrModelConversion suggestedYcbcrModel;
    VkSamplerYcbcrRange           suggestedYcbcrRange;
    VkChromaLocation              suggestedXChromaOffset;
    VkChromaLocation              suggestedYChromaOffset;
};

struct VkImportAndroidHardwareBufferInfoANDROID
{
    VkStructureType         sType;
    const void*             pNext;
    struct AHardwareBuffer* buffer;
};

struct VkMemoryGetAndroidHardwareBufferInfoANDROID
{
    VkStructureType sType;
    const void*     pNext;
    VkDeviceMemory  memory;
};

struct VkExternalFormatANDROID
{
    VkStructureType sType;
    void*           pNext;
    uint64_t        externalFormat;
};

struct VkIcdSurfaceAndroid
{
    VkIcdSurfaceBase base;
    ANativeWindow*   window;
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

#if !defined(VK_USE_PLATFORM_IOS_MVK)
typedef VkFlags VkIOSSurfaceCreateFlagsMVK;

struct VkIOSSurfaceCreateInfoMVK
{
    VkStructureType            sType;
    const void*                pNext;
    VkIOSSurfaceCreateFlagsMVK flags;
    const void*                pView;
};

extern "C" {
typedef VkResult(VKAPI_PTR* PFN_vkCreateIOSSurfaceMVK)(VkInstance                       instance,
                                                       const VkIOSSurfaceCreateInfoMVK* pCreateInfo,
                                                       const VkAllocationCallbacks*     pAllocator,
                                                       VkSurfaceKHR*                    pSurface);
}
#endif // VK_USE_PLATFORM_IOS_MVK

#if !defined(VK_USE_PLATFORM_MACOS_MVK)
typedef VkFlags VkMacOSSurfaceCreateFlagsMVK;

struct VkMacOSSurfaceCreateInfoMVK
{
    VkStructureType              sType;
    const void*                  pNext;
    VkMacOSSurfaceCreateFlagsMVK flags;
    const void*                  pView;
};

extern "C" {
typedef VkResult(VKAPI_PTR* PFN_vkCreateMacOSSurfaceMVK)(VkInstance                         instance,
                                                         const VkMacOSSurfaceCreateInfoMVK* pCreateInfo,
                                                         const VkAllocationCallbacks*       pAllocator,
                                                         VkSurfaceKHR*                      pSurface);
}
#endif // VK_USE_PLATFORM_MACOS_MVK

#if !defined(VK_USE_PLATFORM_MIR_KHR)
typedef VkFlags          VkMirSurfaceCreateFlagsKHR;

struct MirConnection;
struct MirSurface;

struct VkMirSurfaceCreateInfoKHR
{
    VkStructureType            sType;
    const void*                pNext;
    VkMirSurfaceCreateFlagsKHR flags;
    MirConnection*             connection;
    MirSurface*                mirSurface;
};

struct VkIcdSurfaceMir
{
    VkIcdSurfaceBase base;
    MirConnection*   connection;
    MirSurface*      mirSurface;
};

extern "C" {
typedef VkResult(VKAPI_PTR* PFN_vkCreateMirSurfaceKHR)(VkInstance                       instance,
                                                       const VkMirSurfaceCreateInfoKHR* pCreateInfo,
                                                       const VkAllocationCallbacks*     pAllocator,
                                                       VkSurfaceKHR*                    pSurface);
typedef VkBool32(VKAPI_PTR* PFN_vkGetPhysicalDeviceMirPresentationSupportKHR)(VkPhysicalDevice physicalDevice,
                                                                              uint32_t         queueFamilyIndex,
                                                                              MirConnection*   connection);
}
#endif // VK_USE_PLATFORM_MIR_KHR

#if !defined(VK_USE_PLATFORM_VI_NN)
typedef VkFlags VkViSurfaceCreateFlagsNN;

struct VkViSurfaceCreateInfoNN
{
    VkStructureType          sType;
    const void*              pNext;
    VkViSurfaceCreateFlagsNN flags;
    void*                    window;
};

extern "C"{
typedef VkResult(VKAPI_PTR* PFN_vkCreateViSurfaceNN)(VkInstance                     instance,
                                                     const VkViSurfaceCreateInfoNN* pCreateInfo,
                                                     const VkAllocationCallbacks*   pAllocator,
                                                     VkSurfaceKHR*                  pSurface);
}
#endif // VK_USE_PLATFORM_VI_NN

#if !defined(VK_USE_PLATFORM_WAYLAND_KHR)
typedef VkFlags VkWaylandSurfaceCreateFlagsKHR;

struct wl_display;
struct wl_surface;

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

#if !defined(VK_USE_PLATFORM_WIN32_KHR)
typedef VkFlags VkWin32SurfaceCreateFlagsKHR;

struct VkWin32SurfaceCreateInfoKHR
{
    VkStructureType              sType;
    const void*                  pNext;
    VkWin32SurfaceCreateFlagsKHR flags;
    HINSTANCE                    hinstance;
    HWND                         hwnd;
};

struct VkImportMemoryWin32HandleInfoKHR
{
    VkStructureType                    sType;
    const void*                        pNext;
    VkExternalMemoryHandleTypeFlagBits handleType;
    HANDLE                             handle;
    LPCWSTR                            name;
};

struct VkExportMemoryWin32HandleInfoKHR
{
    VkStructureType            sType;
    const void*                pNext;
    const SECURITY_ATTRIBUTES* pAttributes;
    DWORD                      dwAccess;
    LPCWSTR                    name;
};

struct VkMemoryWin32HandlePropertiesKHR
{
    VkStructureType sType;
    void*           pNext;
    uint32_t        memoryTypeBits;
};

struct VkMemoryGetWin32HandleInfoKHR
{
    VkStructureType                    sType;
    const void*                        pNext;
    VkDeviceMemory                     memory;
    VkExternalMemoryHandleTypeFlagBits handleType;
};

struct VkWin32KeyedMutexAcquireReleaseInfoKHR
{
    VkStructureType       sType;
    const void*           pNext;
    uint32_t              acquireCount;
    const VkDeviceMemory* pAcquireSyncs;
    const uint64_t*       pAcquireKeys;
    const uint32_t*       pAcquireTimeouts;
    uint32_t              releaseCount;
    const VkDeviceMemory* pReleaseSyncs;
    const uint64_t*       pReleaseKeys;
};

struct VkImportSemaphoreWin32HandleInfoKHR
{
    VkStructureType                       sType;
    const void*                           pNext;
    VkSemaphore                           semaphore;
    VkSemaphoreImportFlags                flags;
    VkExternalSemaphoreHandleTypeFlagBits handleType;
    HANDLE                                handle;
    LPCWSTR                               name;
};

struct VkExportSemaphoreWin32HandleInfoKHR
{
    VkStructureType            sType;
    const void*                pNext;
    const SECURITY_ATTRIBUTES* pAttributes;
    DWORD                      dwAccess;
    LPCWSTR                    name;
};

struct VkD3D12FenceSubmitInfoKHR
{
    VkStructureType sType;
    const void*     pNext;
    uint32_t        waitSemaphoreValuesCount;
    const uint64_t* pWaitSemaphoreValues;
    uint32_t        signalSemaphoreValuesCount;
    const uint64_t* pSignalSemaphoreValues;
};

struct VkSemaphoreGetWin32HandleInfoKHR
{
    VkStructureType                       sType;
    const void*                           pNext;
    VkSemaphore                           semaphore;
    VkExternalSemaphoreHandleTypeFlagBits handleType;
};

struct VkImportFenceWin32HandleInfoKHR
{
    VkStructureType                   sType;
    const void*                       pNext;
    VkFence                           fence;
    VkFenceImportFlags                flags;
    VkExternalFenceHandleTypeFlagBits handleType;
    HANDLE                            handle;
    LPCWSTR                           name;
};

struct VkExportFenceWin32HandleInfoKHR
{
    VkStructureType            sType;
    const void*                pNext;
    const SECURITY_ATTRIBUTES* pAttributes;
    DWORD                      dwAccess;
    LPCWSTR                    name;
};

struct VkFenceGetWin32HandleInfoKHR
{
    VkStructureType                   sType;
    const void*                       pNext;
    VkFence                           fence;
    VkExternalFenceHandleTypeFlagBits handleType;
};

struct VkImportMemoryWin32HandleInfoNV
{
    VkStructureType                   sType;
    const void*                       pNext;
    VkExternalMemoryHandleTypeFlagsNV handleType;
    HANDLE                            handle;
};

struct VkExportMemoryWin32HandleInfoNV
{
    VkStructureType            sType;
    const void*                pNext;
    const SECURITY_ATTRIBUTES* pAttributes;
    DWORD                      dwAccess;
};

struct VkWin32KeyedMutexAcquireReleaseInfoNV
{
    VkStructureType       sType;
    const void*           pNext;
    uint32_t              acquireCount;
    const VkDeviceMemory* pAcquireSyncs;
    const uint64_t*       pAcquireKeys;
    const uint32_t*       pAcquireTimeoutMilliseconds;
    uint32_t              releaseCount;
    const VkDeviceMemory* pReleaseSyncs;
    const uint64_t*       pReleaseKeys;
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

#if !defined(VK_USE_PLATFORM_XCB_KHR)
typedef VkFlags                 VkXcbSurfaceCreateFlagsKHR;

typedef uint32_t                xcb_window_t;
typedef uint32_t                xcb_visualid_t;

struct xcb_connection_t;

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

typedef uint32_t         XID;
typedef uint32_t         VisualID;
typedef XID              Window;

struct Display;

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

typedef VkResult(VKAPI_PTR* PFN_vkAcquireXlibDisplayEXT)(VkPhysicalDevice physicalDevice,
                                                         Display*         dpy,
                                                         VkDisplayKHR     display);
typedef VkResult(VKAPI_PTR* PFN_vkGetRandROutputDisplayEXT)(VkPhysicalDevice physicalDevice,
                                                            Display*         dpy,
                                                            RROutput         rrOutput,
                                                            VkDisplayKHR*    pDisplay);
#endif // VK_USE_PLATFORM_XLIB_XRANDR_EXT

#endif // BRIMSTONE_PLATFORM_TYPES_H
