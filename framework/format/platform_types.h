/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2024 LunarG, Inc.
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

#ifndef GFXRECON_PLATFORM_TYPES_H
#define GFXRECON_PLATFORM_TYPES_H

#include "util/logging.h"
#include "VK_ANDROID_frame_boundary.h"

#ifdef ENABLE_OPENXR_SUPPORT
#include "openxr/openxr.h"
#endif

#include "vulkan/vulkan.h"

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
typedef void*          HMONITOR;
typedef void*          HDC;
typedef void*          HGLRC;

// Define a version of the WIN32 SECURITY_ATTRIBUTES struct that
// is suitable for decoding on non-WIN32 platforms.
typedef uint32_t    DWORD;
typedef void*       LPVOID;
typedef char        CHAR;
typedef wchar_t     WCHAR;
typedef const char* LPCSTR;
typedef size_t      LONG_PTR;
typedef int8_t      INT8;
typedef uint8_t     UINT8;
typedef int16_t     INT16;
typedef uint16_t    UINT16;
typedef int32_t     INT32;
typedef uint32_t    UINT32;
typedef int64_t     INT64;
typedef uint64_t    UINT64;
typedef float       FLOAT;
typedef double      DOUBLE;
typedef uint8_t     BYTE;
#ifndef __APPLE__
// NOTE: Conflicts with objective-c declaration on macOS
typedef int32_t   BOOL;
#endif
typedef uint16_t  WORD;
typedef uint32_t  DWORD;
typedef int32_t   INT;
typedef uint32_t  UINT;
typedef int32_t   LONG; // long on Windows is always 4 bytes
typedef uint32_t  ULONG;
typedef size_t    SIZE_T;
typedef LONG      HRESULT;
typedef WORD      SECURITY_DESCRIPTOR_CONTROL;
typedef uint32_t& REFIID;
typedef void*     IUnknown;

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

struct GUID
{
    UINT32 Data1;
    UINT16 Data2;
    UINT16 Data3;
    UINT8  Data4[8];
};

static bool operator==(GUID guid1, GUID guid2)
{
    return !memcmp(&guid1, &guid2, sizeof(GUID));
}

struct LUID
{
    DWORD LowPart;
    LONG  HighPart;
};

typedef LUID* PLUID;
typedef GUID  IID;

struct LARGE_INTEGER
{
    int64_t QuadPart;
};

#endif // WIN32

#ifndef __ANDROID__
typedef void* jobject;
#endif

#if defined(XR_USE_PLATFORM_XLIB) && !defined(WIN32)
#include <X11/Xlib.h>
#include "GL/glx.h"
#else
typedef void*        GLXFBConfig;
typedef size_t       GLXDrawable;
typedef void*        GLXContext;
#endif // XR_USE_PLATFORM_XLIB

#ifdef XR_USE_GRAPHICS_API_OPENGL_ES
#include "EGL/egl.h"
#else
typedef unsigned int EGLenum;
typedef void*        EGLDisplay;
typedef void*        EGLConfig;
typedef void*        EGLContext;
#endif // XR_USE_GRAPHICS_API_OPENGL_ES

#ifdef XR_USE_PLATFORM_XCB
#include <xcb/xcb.h>
#include "xcb/glx.h"
#endif

#if !defined(XR_USE_PLATFORM_XLIB)
typedef void*  GLXFBConfig;
typedef size_t GLXDrawable;
typedef void*  GLXContext;
#endif // !XR_USE_PLATFORM_XLIB

#if !defined(VK_USE_PLATFORM_XCB_KHR) && !defined(XR_USE_PLATFORM_XCB)
struct xcb_connection_t;
typedef uint32_t xcb_glx_fbconfig_t;
typedef uint32_t xcb_glx_drawable_t;
typedef uint32_t xcb_glx_context_t;
typedef uint32_t xcb_window_t;
typedef uint32_t xcb_visualid_t;
#endif // !VK_USE_PLATFORM_XCB_KHR && !XR_USE_PLATFORM_XCB

#if !defined(VK_USE_PLATFORM_WAYLAND_KHR) && !defined(XR_USE_PLATFORM_WAYLAND)
struct wl_display;
struct wl_surface;
#endif // !VK_USE_PLATFORM_WAYLAND_KHR && !XR_USE_PLATFORM_WAYLAND

// Types for platform extensions.

#if !defined(VK_USE_PLATFORM_ANDROID_KHR)
#define VK_KHR_ANDROID_SURFACE_EXTENSION_NAME "VK_KHR_android_surface"

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

struct VkAndroidHardwareBufferFormatProperties2ANDROID
{
    VkStructureType               sType;
    void*                         pNext;
    VkFormat                      format;
    uint64_t                      externalFormat;
    VkFormatFeatureFlags2KHR      formatFeatures;
    VkComponentMapping            samplerYcbcrConversionComponents;
    VkSamplerYcbcrModelConversion suggestedYcbcrModel;
    VkSamplerYcbcrRange           suggestedYcbcrRange;
    VkChromaLocation              suggestedXChromaOffset;
    VkChromaLocation              suggestedYChromaOffset;
};

struct VkPhysicalDeviceExternalFormatResolveFeaturesANDROID
{
    VkStructureType sType;
    void*           pNext;
    VkBool32        externalFormatResolve;
};

struct VkPhysicalDeviceExternalFormatResolvePropertiesANDROID
{
    VkStructureType  sType;
    void*            pNext;
    VkBool32         nullColorAttachmentWithExternalFormatResolve;
    VkChromaLocation externalFormatResolveChromaOffsetX;
    VkChromaLocation externalFormatResolveChromaOffsetY;
};

struct VkAndroidHardwareBufferFormatResolvePropertiesANDROID
{
    VkStructureType sType;
    void*           pNext;
    VkFormat        colorAttachmentFormat;
};

extern "C"
{
    typedef VkResult(VKAPI_PTR* PFN_vkCreateAndroidSurfaceKHR)(VkInstance                           instance,
                                                               const VkAndroidSurfaceCreateInfoKHR* pCreateInfo,
                                                               const VkAllocationCallbacks*         pAllocator,
                                                               VkSurfaceKHR*                        pSurface);
    typedef VkResult(VKAPI_PTR* PFN_vkGetAndroidHardwareBufferPropertiesANDROID)(
        VkDevice device, const struct AHardwareBuffer* buffer, VkAndroidHardwareBufferPropertiesANDROID* pProperties);
    typedef VkResult(VKAPI_PTR* PFN_vkGetMemoryAndroidHardwareBufferANDROID)(
        VkDevice device, const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo, struct AHardwareBuffer** pBuffer);

    static VKAPI_ATTR VkResult VKAPI_CALL vkCreateAndroidSurfaceKHR(VkInstance,
                                                                    const VkAndroidSurfaceCreateInfoKHR*,
                                                                    const VkAllocationCallbacks*,
                                                                    VkSurfaceKHR*)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkCreateAndroidSurfaceKHR");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    static VKAPI_ATTR VkResult VKAPI_CALL vkGetAndroidHardwareBufferPropertiesANDROID(
        VkDevice, const struct AHardwareBuffer*, VkAndroidHardwareBufferPropertiesANDROID*)
    {
        GFXRECON_LOG_ERROR(
            "Calling unsupported platform extension function vkGetAndroidHardwareBufferPropertiesANDROID");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    static VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryAndroidHardwareBufferANDROID(
        VkDevice, const VkMemoryGetAndroidHardwareBufferInfoANDROID*, struct AHardwareBuffer**)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkGetMemoryAndroidHardwareBufferANDROID");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }
}
#endif // VK_USE_PLATFORM_ANDROID_KHR

#if !defined VK_USE_PLATFORM_FUCHSIA
#define VK_FUCHSIA_IMAGEPIPE_SURFACE_EXTENSION_NAME "VK_FUCHSIA_imagepipe_surface"

typedef VkFlags VkImagePipeSurfaceCreateFlagsFUCHSIA;

typedef uint32_t zx_handle_t;

struct VkImagePipeSurfaceCreateInfoFUCHSIA
{
    VkStructureType                      sType;
    const void*                          pNext;
    VkImagePipeSurfaceCreateFlagsFUCHSIA flags;
    zx_handle_t                          imagePipeHandle;
};

typedef VkResult(VKAPI_PTR* PFN_vkCreateImagePipeSurfaceFUCHSIA)(VkInstance                                 instance,
                                                                 const VkImagePipeSurfaceCreateInfoFUCHSIA* pCreateInfo,
                                                                 const VkAllocationCallbacks*               pAllocator,
                                                                 VkSurfaceKHR*                              pSurface);

struct VkImportMemoryZirconHandleInfoFUCHSIA
{
    VkStructureType                    sType;
    const void*                        pNext;
    VkExternalMemoryHandleTypeFlagBits handleType;
    zx_handle_t                        handle;
};

struct VkMemoryZirconHandlePropertiesFUCHSIA
{
    VkStructureType sType;
    void*           pNext;
    uint32_t        memoryTypeBits;
};

struct VkMemoryGetZirconHandleInfoFUCHSIA
{
    VkStructureType                    sType;
    const void*                        pNext;
    VkDeviceMemory                     memory;
    VkExternalMemoryHandleTypeFlagBits handleType;
};

typedef VkResult(VKAPI_PTR* PFN_vkGetMemoryZirconHandleFUCHSIA)(
    VkDevice device, const VkMemoryGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle);

typedef VkResult(VKAPI_PTR* PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA)(
    VkDevice                               device,
    VkExternalMemoryHandleTypeFlagBits     handleType,
    zx_handle_t                            zirconHandle,
    VkMemoryZirconHandlePropertiesFUCHSIA* pMemoryZirconHandleProperties);

struct VkImportSemaphoreZirconHandleInfoFUCHSIA
{
    VkStructureType                       sType;
    const void*                           pNext;
    VkSemaphore                           semaphore;
    VkSemaphoreImportFlags                flags;
    VkExternalSemaphoreHandleTypeFlagBits handleType;
    zx_handle_t                           zirconHandle;
};

struct VkSemaphoreGetZirconHandleInfoFUCHSIA
{
    VkStructureType                       sType;
    const void*                           pNext;
    VkSemaphore                           semaphore;
    VkExternalSemaphoreHandleTypeFlagBits handleType;
};

typedef VkResult(VKAPI_PTR* PFN_vkImportSemaphoreZirconHandleFUCHSIA)(
    VkDevice device, const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo);
typedef VkResult(VKAPI_PTR* PFN_vkGetSemaphoreZirconHandleFUCHSIA)(
    VkDevice device, const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle);

extern "C"
{
    static VKAPI_ATTR VkResult VKAPI_CALL vkCreateImagePipeSurfaceFUCHSIA(VkInstance,
                                                                          const VkImagePipeSurfaceCreateInfoFUCHSIA*,
                                                                          const VkAllocationCallbacks*,
                                                                          VkSurfaceKHR*)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkCreateImagePipeSurfaceFUCHSIA");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    static VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryZirconHandleFUCHSIA(
        VkDevice device, const VkMemoryGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkGetMemoryZirconHandleFUCHSIA");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    static VKAPI_ATTR VkResult VKAPI_CALL
    vkGetMemoryZirconHandlePropertiesFUCHSIA(VkDevice                               device,
                                             VkExternalMemoryHandleTypeFlagBits     handleType,
                                             zx_handle_t                            zirconHandle,
                                             VkMemoryZirconHandlePropertiesFUCHSIA* pMemoryZirconHandleProperties)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkGetMemoryZirconHandlePropertiesFUCHSIA");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    static VKAPI_ATTR VkResult VKAPI_CALL vkImportSemaphoreZirconHandleFUCHSIA(
        VkDevice device, const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkImportSemaphoreZirconHandleFUCHSIA");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    static VKAPI_ATTR VkResult VKAPI_CALL vkGetSemaphoreZirconHandleFUCHSIA(
        VkDevice device, const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkGetSemaphoreZirconHandleFUCHSIA");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }
}
#endif // defined VK_USE_PLATFORM_FUCHSIA

#if !defined(VK_USE_PLATFORM_IOS_MVK)
#define VK_MVK_IOS_SURFACE_EXTENSION_NAME "VK_MVK_ios_surface"

typedef VkFlags VkIOSSurfaceCreateFlagsMVK;

struct VkIOSSurfaceCreateInfoMVK
{
    VkStructureType            sType;
    const void*                pNext;
    VkIOSSurfaceCreateFlagsMVK flags;
    const void*                pView;
};

extern "C"
{
    typedef VkResult(VKAPI_PTR* PFN_vkCreateIOSSurfaceMVK)(VkInstance                       instance,
                                                           const VkIOSSurfaceCreateInfoMVK* pCreateInfo,
                                                           const VkAllocationCallbacks*     pAllocator,
                                                           VkSurfaceKHR*                    pSurface);

    static VKAPI_ATTR VkResult VKAPI_CALL vkCreateIOSSurfaceMVK(VkInstance,
                                                                const VkIOSSurfaceCreateInfoMVK*,
                                                                const VkAllocationCallbacks*,
                                                                VkSurfaceKHR*)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkCreateIOSSurfaceMVK");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }
}
#endif // VK_USE_PLATFORM_IOS_MVK

#if !defined(VK_USE_PLATFORM_MACOS_MVK)
#define VK_MVK_MACOS_SURFACE_EXTENSION_NAME "VK_MVK_macos_surface"

typedef VkFlags VkMacOSSurfaceCreateFlagsMVK;

struct VkMacOSSurfaceCreateInfoMVK
{
    VkStructureType              sType;
    const void*                  pNext;
    VkMacOSSurfaceCreateFlagsMVK flags;
    const void*                  pView;
};

extern "C"
{
    typedef VkResult(VKAPI_PTR* PFN_vkCreateMacOSSurfaceMVK)(VkInstance                         instance,
                                                             const VkMacOSSurfaceCreateInfoMVK* pCreateInfo,
                                                             const VkAllocationCallbacks*       pAllocator,
                                                             VkSurfaceKHR*                      pSurface);

    static VKAPI_ATTR VkResult VKAPI_CALL vkCreateMacOSSurfaceMVK(VkInstance,
                                                                  const VkMacOSSurfaceCreateInfoMVK*,
                                                                  const VkAllocationCallbacks*,
                                                                  VkSurfaceKHR*)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkCreateMacOSSurfaceMVK");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }
}
#endif // VK_USE_PLATFORM_MACOS_MVK

#if !defined(VK_USE_PLATFORM_METAL_EXT)
#define VK_EXT_METAL_SURFACE_EXTENSION_NAME "VK_EXT_metal_surface"

typedef VkFlags VkMetalSurfaceCreateFlagsEXT;

struct CAMetalLayer;

struct VkMetalSurfaceCreateInfoEXT
{
    VkStructureType              sType;
    const void*                  pNext;
    VkMetalSurfaceCreateFlagsEXT flags;
    const CAMetalLayer*          pLayer;
};

extern "C"
{
    typedef VkResult(VKAPI_PTR* PFN_vkCreateMetalSurfaceEXT)(VkInstance                         instance,
                                                             const VkMetalSurfaceCreateInfoEXT* pCreateInfo,
                                                             const VkAllocationCallbacks*       pAllocator,
                                                             VkSurfaceKHR*                      pSurface);

    static VKAPI_ATTR VkResult VKAPI_CALL vkCreateMetalSurfaceEXT(VkInstance,
                                                                  const VkMetalSurfaceCreateInfoEXT*,
                                                                  const VkAllocationCallbacks*,
                                                                  VkSurfaceKHR*)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkCreateMetalSurfaceEXT");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }
}
#endif // VK_USE_PLATFORM_METAL_EXT

#if !defined(VK_USE_PLATFORM_MIR_KHR)
#define VK_KHR_MIR_SURFACE_EXTENSION_NAME "VK_KHR_mir_surface"

typedef VkFlags VkMirSurfaceCreateFlagsKHR;

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

extern "C"
{
    typedef VkResult(VKAPI_PTR* PFN_vkCreateMirSurfaceKHR)(VkInstance                       instance,
                                                           const VkMirSurfaceCreateInfoKHR* pCreateInfo,
                                                           const VkAllocationCallbacks*     pAllocator,
                                                           VkSurfaceKHR*                    pSurface);
    typedef VkBool32(VKAPI_PTR* PFN_vkGetPhysicalDeviceMirPresentationSupportKHR)(VkPhysicalDevice physicalDevice,
                                                                                  uint32_t         queueFamilyIndex,
                                                                                  MirConnection*   connection);

    static VKAPI_ATTR VkResult VKAPI_CALL vkCreateMirSurfaceKHR(VkInstance,
                                                                const VkMirSurfaceCreateInfoKHR*,
                                                                const VkAllocationCallbacks*,
                                                                VkSurfaceKHR*)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkCreateMirSurfaceKHR");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    static VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceMirPresentationSupportKHR(VkPhysicalDevice,
                                                                                       uint32_t,
                                                                                       MirConnection*)
    {
        GFXRECON_LOG_ERROR(
            "Calling unsupported platform extension function vkGetPhysicalDeviceMirPresentationSupportKHR");
        return VK_FALSE;
    }
}
#endif // VK_USE_PLATFORM_MIR_KHR

#if !defined(VK_USE_PLATFORM_VI_NN)
#define VK_NN_VI_SURFACE_EXTENSION_NAME "VK_NN_vi_surface"

typedef VkFlags VkViSurfaceCreateFlagsNN;

struct VkViSurfaceCreateInfoNN
{
    VkStructureType          sType;
    const void*              pNext;
    VkViSurfaceCreateFlagsNN flags;
    void*                    window;
};

extern "C"
{
    typedef VkResult(VKAPI_PTR* PFN_vkCreateViSurfaceNN)(VkInstance                     instance,
                                                         const VkViSurfaceCreateInfoNN* pCreateInfo,
                                                         const VkAllocationCallbacks*   pAllocator,
                                                         VkSurfaceKHR*                  pSurface);

    static VKAPI_ATTR VkResult VKAPI_CALL vkCreateViSurfaceNN(VkInstance,
                                                              const VkViSurfaceCreateInfoNN*,
                                                              const VkAllocationCallbacks*,
                                                              VkSurfaceKHR*)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkCreateViSurfaceNN");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }
}
#endif // VK_USE_PLATFORM_VI_NN

#if !defined(VK_USE_PLATFORM_WAYLAND_KHR)
#define VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME "VK_KHR_wayland_surface"

typedef VkFlags VkWaylandSurfaceCreateFlagsKHR;

struct VkWaylandSurfaceCreateInfoKHR
{
    VkStructureType                sType;
    const void*                    pNext;
    VkWaylandSurfaceCreateFlagsKHR flags;
    struct wl_display*             display;
    struct wl_surface*             surface;
};

extern "C"
{
    typedef VkResult(VKAPI_PTR* PFN_vkCreateWaylandSurfaceKHR)(VkInstance                           instance,
                                                               const VkWaylandSurfaceCreateInfoKHR* pCreateInfo,
                                                               const VkAllocationCallbacks*         pAllocator,
                                                               VkSurfaceKHR*                        pSurface);
    typedef VkBool32(VKAPI_PTR* PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR)(VkPhysicalDevice physicalDevice,
                                                                                      uint32_t         queueFamilyIndex,
                                                                                      struct wl_display* display);
    static VKAPI_ATTR VkResult VKAPI_CALL vkCreateWaylandSurfaceKHR(VkInstance,
                                                                    const VkWaylandSurfaceCreateInfoKHR*,
                                                                    const VkAllocationCallbacks*,
                                                                    VkSurfaceKHR*)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkCreateWaylandSurfaceKHR");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    static VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceWaylandPresentationSupportKHR(VkPhysicalDevice,
                                                                                           uint32_t,
                                                                                           struct wl_display*)
    {
        GFXRECON_LOG_ERROR(
            "Calling unsupported platform extension function vkGetPhysicalDeviceWaylandPresentationSupportKHR");
        return VK_FALSE;
    }
}
#endif // VK_USE_PLATFORM_WAYLAND_KHR

#if !defined(VK_USE_PLATFORM_WIN32_KHR)
#define VK_KHR_WIN32_SURFACE_EXTENSION_NAME "VK_KHR_win32_surface"

typedef VkFlags VkWin32SurfaceCreateFlagsKHR;

enum VkFullScreenExclusiveEXT
{
    VK_FULL_SCREEN_EXCLUSIVE_DEFAULT_EXT                = 0,
    VK_FULL_SCREEN_EXCLUSIVE_ALLOWED_EXT                = 1,
    VK_FULL_SCREEN_EXCLUSIVE_DISALLOWED_EXT             = 2,
    VK_FULL_SCREEN_EXCLUSIVE_APPLICATION_CONTROLLED_EXT = 3,
    VK_FULL_SCREEN_EXCLUSIVE_BEGIN_RANGE_EXT            = VK_FULL_SCREEN_EXCLUSIVE_DEFAULT_EXT,
    VK_FULL_SCREEN_EXCLUSIVE_END_RANGE_EXT              = VK_FULL_SCREEN_EXCLUSIVE_APPLICATION_CONTROLLED_EXT,
    VK_FULL_SCREEN_EXCLUSIVE_RANGE_SIZE_EXT =
        (VK_FULL_SCREEN_EXCLUSIVE_APPLICATION_CONTROLLED_EXT - VK_FULL_SCREEN_EXCLUSIVE_DEFAULT_EXT + 1),
    VK_FULL_SCREEN_EXCLUSIVE_MAX_ENUM_EXT = 0x7FFFFFFF
};

struct VkWin32SurfaceCreateInfoKHR
{
    VkStructureType              sType;
    const void*                  pNext;
    VkWin32SurfaceCreateFlagsKHR flags;
    HINSTANCE                    hinstance;
    HWND                         hwnd;
};

struct VkSurfaceFullScreenExclusiveInfoEXT
{
    VkStructureType          sType;
    void*                    pNext;
    VkFullScreenExclusiveEXT fullScreenExclusive;
};

struct VkSurfaceCapabilitiesFullScreenExclusiveEXT
{
    VkStructureType sType;
    void*           pNext;
    VkBool32        fullScreenExclusiveSupported;
};

struct VkSurfaceFullScreenExclusiveWin32InfoEXT
{
    VkStructureType sType;
    const void*     pNext;
    HMONITOR        hmonitor;
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

extern "C"
{
    typedef VkResult(VKAPI_PTR* PFN_vkCreateWin32SurfaceKHR)(VkInstance                         instance,
                                                             const VkWin32SurfaceCreateInfoKHR* pCreateInfo,
                                                             const VkAllocationCallbacks*       pAllocator,
                                                             VkSurfaceKHR*                      pSurface);
    typedef VkBool32(VKAPI_PTR* PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR)(VkPhysicalDevice physicalDevice,
                                                                                    uint32_t         queueFamilyIndex);
    typedef VkResult(VKAPI_PTR* PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT)(
        VkPhysicalDevice                       physicalDevice,
        const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
        uint32_t*                              pPresentModeCount,
        VkPresentModeKHR*                      pPresentModes);
    typedef VkResult(VKAPI_PTR* PFN_vkAcquireFullScreenExclusiveModeEXT)(VkDevice device, VkSwapchainKHR swapchain);
    typedef VkResult(VKAPI_PTR* PFN_vkReleaseFullScreenExclusiveModeEXT)(VkDevice device, VkSwapchainKHR swapchain);
    typedef VkResult(VKAPI_PTR* PFN_vkGetDeviceGroupSurfacePresentModes2EXT)(
        VkDevice device, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkDeviceGroupPresentModeFlagsKHR* pModes);
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
    typedef VkResult(VKAPI_PTR* PFN_vkAcquireWinrtDisplayNV)(VkPhysicalDevice physicalDevice, VkDisplayKHR display);
    typedef VkResult(VKAPI_PTR* PFN_vkGetWinrtDisplayNV)(VkPhysicalDevice physicalDevice,
                                                         uint32_t         deviceRelativeId,
                                                         VkDisplayKHR*    pDisplay);

    static VKAPI_ATTR VkResult VKAPI_CALL vkCreateWin32SurfaceKHR(VkInstance,
                                                                  const VkWin32SurfaceCreateInfoKHR*,
                                                                  const VkAllocationCallbacks*,
                                                                  VkSurfaceKHR*)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkCreateWin32SurfaceKHR");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    static VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceWin32PresentationSupportKHR(VkPhysicalDevice, uint32_t)
    {
        GFXRECON_LOG_ERROR(
            "Calling unsupported platform extension function vkGetPhysicalDeviceWin32PresentationSupportKHR");
        return VK_FALSE;
    }

    static VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfacePresentModes2EXT(
        VkPhysicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR*, uint32_t*, VkPresentModeKHR*)
    {
        GFXRECON_LOG_ERROR(
            "Calling unsupported platform extension function vkGetPhysicalDeviceSurfacePresentModes2EXT");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    static VKAPI_ATTR VkResult VKAPI_CALL vkAcquireFullScreenExclusiveModeEXT(VkDevice, VkSwapchainKHR)
    {
        // Convert full screen exclusive calls to no-op functions that report success on non-WIN32 platforms.
        GFXRECON_LOG_INFO("Ignoring WIN32 platform-specific extension function vkAcquireFullScreenExclusiveModeEXT");
        return VK_SUCCESS;
    }

    static VKAPI_ATTR VkResult VKAPI_CALL vkReleaseFullScreenExclusiveModeEXT(VkDevice, VkSwapchainKHR)
    {
        // Convert full screen exclusive calls to no-op functions that report success on non-WIN32 platforms.
        GFXRECON_LOG_INFO("Ignoring WIN32 platform-specific extension function vkReleaseFullScreenExclusiveModeEXT");
        return VK_SUCCESS;
    }

    static VKAPI_ATTR VkResult VKAPI_CALL vkGetDeviceGroupSurfacePresentModes2EXT(
        VkDevice, const VkPhysicalDeviceSurfaceInfo2KHR*, VkDeviceGroupPresentModeFlagsKHR*)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkGetDeviceGroupSurfacePresentModes2EXT");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    static VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryWin32HandleKHR(VkDevice,
                                                                    const VkMemoryGetWin32HandleInfoKHR*,
                                                                    HANDLE*)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkGetMemoryWin32HandleKHR");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    static VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryWin32HandlePropertiesKHR(VkDevice,
                                                                              VkExternalMemoryHandleTypeFlagBits,
                                                                              HANDLE,
                                                                              VkMemoryWin32HandlePropertiesKHR*)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkGetMemoryWin32HandlePropertiesKHR");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    static VKAPI_ATTR VkResult VKAPI_CALL vkImportSemaphoreWin32HandleKHR(VkDevice,
                                                                          const VkImportSemaphoreWin32HandleInfoKHR*)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkImportSemaphoreWin32HandleKHR");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    static VKAPI_ATTR VkResult VKAPI_CALL vkGetSemaphoreWin32HandleKHR(VkDevice,
                                                                       const VkSemaphoreGetWin32HandleInfoKHR*,
                                                                       HANDLE*)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkGetSemaphoreWin32HandleKHR");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    static VKAPI_ATTR VkResult VKAPI_CALL vkImportFenceWin32HandleKHR(VkDevice, const VkImportFenceWin32HandleInfoKHR*)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkImportFenceWin32HandleKHR");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    static VKAPI_ATTR VkResult VKAPI_CALL vkGetFenceWin32HandleKHR(VkDevice,
                                                                   const VkFenceGetWin32HandleInfoKHR*,
                                                                   HANDLE*)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkGetFenceWin32HandleKHR");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    static VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryWin32HandleNV(VkDevice,
                                                                   VkDeviceMemory,
                                                                   VkExternalMemoryHandleTypeFlagsNV,
                                                                   HANDLE*)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkGetMemoryWin32HandleNV");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    static VKAPI_ATTR VkResult VKAPI_CALL vkAcquireWinrtDisplayNV(VkPhysicalDevice physicalDevice, VkDisplayKHR display)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkAcquireWinrtDisplayNV");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    static VKAPI_ATTR VkResult VKAPI_CALL vkGetWinrtDisplayNV(VkPhysicalDevice physicalDevice,
                                                              uint32_t         deviceRelativeId,
                                                              VkDisplayKHR*    pDisplay)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkGetWinrtDisplayNV");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }
}
#endif // VK_USE_PLATFORM_WIN32_KHR

#if !defined(VK_USE_PLATFORM_XCB_KHR)
#define VK_KHR_XCB_SURFACE_EXTENSION_NAME "VK_KHR_xcb_surface"

typedef VkFlags VkXcbSurfaceCreateFlagsKHR;

struct VkXcbSurfaceCreateInfoKHR
{
    VkStructureType            sType;
    const void*                pNext;
    VkXcbSurfaceCreateFlagsKHR flags;
    xcb_connection_t*          connection;
    xcb_window_t               window;
};

extern "C"
{
    typedef VkResult(VKAPI_PTR* PFN_vkCreateXcbSurfaceKHR)(VkInstance                       instance,
                                                           const VkXcbSurfaceCreateInfoKHR* pCreateInfo,
                                                           const VkAllocationCallbacks*     pAllocator,
                                                           VkSurfaceKHR*                    pSurface);
    typedef VkBool32(VKAPI_PTR* PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR)(VkPhysicalDevice  physicalDevice,
                                                                                  uint32_t          queueFamilyIndex,
                                                                                  xcb_connection_t* connection,
                                                                                  xcb_visualid_t    visual_id);

    static VKAPI_ATTR VkResult VKAPI_CALL vkCreateXcbSurfaceKHR(VkInstance,
                                                                const VkXcbSurfaceCreateInfoKHR*,
                                                                const VkAllocationCallbacks*,
                                                                VkSurfaceKHR*)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkCreateXcbSurfaceKHR");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    static VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceXcbPresentationSupportKHR(VkPhysicalDevice,
                                                                                       uint32_t,
                                                                                       xcb_connection_t*,
                                                                                       xcb_visualid_t)
    {
        GFXRECON_LOG_ERROR(
            "Calling unsupported platform extension function vkGetPhysicalDeviceXcbPresentationSupportKHR");
        return VK_FALSE;
    }
}
#endif // VK_USE_PLATFORM_XCB_KHR

// Xlib type definitions common to both XLIB_KHR and XLIB_XRANDR_KHR
#if !defined(VK_USE_PLATFORM_XLIB_KHR) && !defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
typedef size_t XID;
typedef size_t VisualID;
typedef XID    Window;

struct Display;
#endif // VK_USE_PLATFORM_XLIB_KHR && VK_USE_PLATFORM_XLIB_XRANDR_EXT

#if !defined(VK_USE_PLATFORM_XLIB_KHR)
#define VK_KHR_XLIB_SURFACE_EXTENSION_NAME "VK_KHR_xlib_surface"

typedef VkFlags VkXlibSurfaceCreateFlagsKHR;

struct VkXlibSurfaceCreateInfoKHR
{
    VkStructureType             sType;
    const void*                 pNext;
    VkXlibSurfaceCreateFlagsKHR flags;
    Display*                    dpy;
    Window                      window;
};

extern "C"
{
    typedef VkResult(VKAPI_PTR* PFN_vkCreateXlibSurfaceKHR)(VkInstance                        instance,
                                                            const VkXlibSurfaceCreateInfoKHR* pCreateInfo,
                                                            const VkAllocationCallbacks*      pAllocator,
                                                            VkSurfaceKHR*                     pSurface);
    typedef VkBool32(VKAPI_PTR* PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR)(VkPhysicalDevice physicalDevice,
                                                                                   uint32_t         queueFamilyIndex,
                                                                                   Display*         dpy,
                                                                                   VisualID         visualID);

    static VKAPI_ATTR VkResult VKAPI_CALL vkCreateXlibSurfaceKHR(VkInstance,
                                                                 const VkXlibSurfaceCreateInfoKHR*,
                                                                 const VkAllocationCallbacks*,
                                                                 VkSurfaceKHR*)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkCreateXlibSurfaceKHR");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    static VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceXlibPresentationSupportKHR(VkPhysicalDevice,
                                                                                        uint32_t,
                                                                                        Display*,
                                                                                        VisualID)
    {
        GFXRECON_LOG_ERROR(
            "Calling unsupported platform extension function vkGetPhysicalDeviceXlibPresentationSupportKHR");
        return VK_FALSE;
    }
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

extern "C"
{
    static VKAPI_ATTR VkResult VKAPI_CALL vkAcquireXlibDisplayEXT(VkPhysicalDevice, Display*, VkDisplayKHR)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkAcquireXlibDisplayEXT");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    static VKAPI_ATTR VkResult VKAPI_CALL vkGetRandROutputDisplayEXT(VkPhysicalDevice,
                                                                     Display*,
                                                                     RROutput,
                                                                     VkDisplayKHR*)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkGetRandROutputDisplayEXT");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }
}
#endif // VK_USE_PLATFORM_XLIB_XRANDR_EXT

#if !defined(VK_USE_PLATFORM_GGP)
#define VK_GGP_STREAM_DESCRIPTOR_SURFACE_EXTENSION_NAME "VK_GGP_stream_descriptor_surface"

typedef VkFlags VkStreamDescriptorSurfaceCreateFlagsGGP;

// Using a type that is large enough to hold any integer/pointer value; actual types are currently unknown.
typedef uint64_t GgpStreamDescriptor;
typedef uint64_t GgpFrameToken;

struct VkStreamDescriptorSurfaceCreateInfoGGP
{
    VkStructureType                         sType;
    const void*                             pNext;
    VkStreamDescriptorSurfaceCreateFlagsGGP flags;
    GgpStreamDescriptor                     streamDescriptor;
};

struct VkPresentFrameTokenGGP
{
    VkStructureType sType;
    const void*     pNext;
    GgpFrameToken   frameToken;
};

typedef VkResult(VKAPI_PTR* PFN_vkCreateStreamDescriptorSurfaceGGP)(
    VkInstance                                    instance,
    const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo,
    const VkAllocationCallbacks*                  pAllocator,
    VkSurfaceKHR*                                 pSurface);

extern "C"
{
    static VKAPI_ATTR VkResult VKAPI_CALL
    vkCreateStreamDescriptorSurfaceGGP(VkInstance                                    instance,
                                       const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo,
                                       const VkAllocationCallbacks*                  pAllocator,
                                       VkSurfaceKHR*                                 pSurface)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkCreateStreamDescriptorSurfaceGGP");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }
}

#endif // VK_USE_PLATFORM_GGP

#if !defined(VK_USE_PLATFORM_DIRECTFB_EXT)
#define VK_EXT_DIRECTFB_SURFACE_EXTENSION_NAME "VK_EXT_directfb_surface"

typedef VkFlags VkDirectFBSurfaceCreateFlagsEXT;

struct IDirectFB;
struct IDirectFBSurface;

struct VkDirectFBSurfaceCreateInfoEXT
{
    VkStructureType                 sType;
    const void*                     pNext;
    VkDirectFBSurfaceCreateFlagsEXT flags;
    IDirectFB*                      dfb;
    IDirectFBSurface*               surface;
};

typedef VkResult(VKAPI_PTR* PFN_vkCreateDirectFBSurfaceEXT)(VkInstance                            instance,
                                                            const VkDirectFBSurfaceCreateInfoEXT* pCreateInfo,
                                                            const VkAllocationCallbacks*          pAllocator,
                                                            VkSurfaceKHR*                         pSurface);

typedef VkBool32(VKAPI_PTR* PFN_vkGetPhysicalDeviceDirectFBPresentationSupportEXT)(VkPhysicalDevice physicalDevice,
                                                                                   uint32_t         queueFamilyIndex,
                                                                                   IDirectFB*       dfb);

extern "C"
{
    static VKAPI_ATTR VkResult VKAPI_CALL vkCreateDirectFBSurfaceEXT(VkInstance,
                                                                     const VkDirectFBSurfaceCreateInfoEXT*,
                                                                     const VkAllocationCallbacks*,
                                                                     VkSurfaceKHR*)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkCreateDirectFBSurfaceEXT");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    static VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceDirectFBPresentationSupportEXT(VkPhysicalDevice,
                                                                                            uint32_t,
                                                                                            IDirectFB*)
    {
        GFXRECON_LOG_ERROR(
            "Calling unsupported platform extension function vkGetPhysicalDeviceDirectFBPresentationSupportEXT");
        return VK_FALSE;
    }
}
#endif // VK_USE_PLATFORM_DIRECTFB_EXT

#if !defined(VK_USE_PLATFORM_SCREEN_QNX)
#define VK_QNX_SCREEN_SURFACE_EXTENSION_NAME "VK_QNX_screen_surface"

typedef VkFlags VkScreenSurfaceCreateFlagsQNX;

struct _screen_context;
struct _screen_window;
struct VkScreenSurfaceCreateInfoQNX
{
    VkStructureType               sType;
    const void*                   pNext;
    VkScreenSurfaceCreateFlagsQNX flags;
    struct _screen_context*       context;
    struct _screen_window*        window;
};

typedef VkResult(VKAPI_PTR* PFN_vkCreateScreenSurfaceQNX)(VkInstance                          instance,
                                                          const VkScreenSurfaceCreateInfoQNX* pCreateInfo,
                                                          const VkAllocationCallbacks*        pAllocator,
                                                          VkSurfaceKHR*                       pSurface);

typedef VkBool32(VKAPI_PTR* PFN_vkGetPhysicalDeviceScreenPresentationSupportQNX)(VkPhysicalDevice physicalDevice,
                                                                                 uint32_t         queueFamilyIndex,
                                                                                 struct _screen_window* window);

extern "C"
{
    static VKAPI_ATTR VkResult VKAPI_CALL vkCreateScreenSurfaceQNX(VkInstance                          instance,
                                                                   const VkScreenSurfaceCreateInfoQNX* pCreateInfo,
                                                                   const VkAllocationCallbacks*        pAllocator,
                                                                   VkSurfaceKHR*                       pSurface)
    {
        GFXRECON_LOG_ERROR("Calling unsupported platform extension function vkCreateScreenSurfaceQNX");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    static VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceScreenPresentationSupportQNX(
        VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct _screen_window* window)
    {
        GFXRECON_LOG_ERROR(
            "Calling unsupported platform extension function vkGetPhysicalDeviceScreenPresentationSupportQNX");
        return VK_FALSE;
    }
}

#endif // VK_USE_PLATFORM_SCREEN_QNX

#ifdef ENABLE_OPENXR_SUPPORT

#if defined(XR_USE_PLATFORM_ANDROID)
#include "jni.h"
#endif // XR_USE_PLATFORM_ANDROID

#include "platform_types_d3d_overrides.h"

#if !defined(XR_USE_PLATFORM_ML)
typedef struct MLCoordinateFrameUID
{
    uint64_t data[2];
} MLCoordinateFrameUID;

typedef struct XrCoordinateSpaceCreateInfoML
{
    XrStructureType          type;
    const void* XR_MAY_ALIAS next;
    MLCoordinateFrameUID     cfuid;
    XrPosef                  poseInCoordinateSpace;
} XrCoordinateSpaceCreateInfoML;

extern "C"
{
    typedef XrResult(XRAPI_PTR* PFN_xrCreateSpaceFromCoordinateFrameUIDML)(
        XrSession session, const XrCoordinateSpaceCreateInfoML* createInfo, XrSpace* space);
} // extern "C"

#endif // XR_USE_PLATFORM_ML

#ifndef XR_USE_PLATFORM_ANDROID
typedef enum XrAndroidThreadTypeKHR
{
    XR_ANDROID_THREAD_TYPE_APPLICATION_MAIN_KHR   = 1,
    XR_ANDROID_THREAD_TYPE_APPLICATION_WORKER_KHR = 2,
    XR_ANDROID_THREAD_TYPE_RENDERER_MAIN_KHR      = 3,
    XR_ANDROID_THREAD_TYPE_RENDERER_WORKER_KHR    = 4,
    XR_ANDROID_THREAD_TYPE_MAX_ENUM_KHR           = 0x7FFFFFFF
} XrAndroidThreadTypeKHR;

typedef struct XrInstanceCreateInfoAndroidKHR
{
    XrStructureType          type;
    const void* XR_MAY_ALIAS next;
    void* XR_MAY_ALIAS       applicationVM;
    void* XR_MAY_ALIAS       applicationActivity;
} XrInstanceCreateInfoAndroidKHR;

typedef struct XrLoaderInitInfoAndroidKHR
{
    XrStructureType          type;
    const void* XR_MAY_ALIAS next;
    void* XR_MAY_ALIAS       applicationVM;
    void* XR_MAY_ALIAS       applicationContext;
} XrLoaderInitInfoAndroidKHR;

typedef XrFlags64 XrAndroidSurfaceSwapchainFlagsFB;

// Flag bits for XrAndroidSurfaceSwapchainFlagsFB
static const XrAndroidSurfaceSwapchainFlagsFB XR_ANDROID_SURFACE_SWAPCHAIN_SYNCHRONOUS_BIT_FB    = 0x00000001;
static const XrAndroidSurfaceSwapchainFlagsFB XR_ANDROID_SURFACE_SWAPCHAIN_USE_TIMESTAMPS_BIT_FB = 0x00000002;

typedef struct XrAndroidSurfaceSwapchainCreateInfoFB
{
    XrStructureType                  type;
    const void* XR_MAY_ALIAS         next;
    XrAndroidSurfaceSwapchainFlagsFB createFlags;
} XrAndroidSurfaceSwapchainCreateInfoFB;

typedef struct XrSwapchainStateAndroidSurfaceDimensionsFB
{
    XrStructureType    type;
    void* XR_MAY_ALIAS next;
    uint32_t           width;
    uint32_t           height;
} XrSwapchainStateAndroidSurfaceDimensionsFB;

extern "C"
{
    typedef XrResult(XRAPI_PTR* PFN_xrSetAndroidApplicationThreadKHR)(XrSession              session,
                                                                      XrAndroidThreadTypeKHR threadType,
                                                                      uint32_t               threadId);
    typedef XrResult(XRAPI_PTR* PFN_xrCreateSwapchainAndroidSurfaceKHR)(XrSession                    session,
                                                                        const XrSwapchainCreateInfo* info,
                                                                        XrSwapchain*                 swapchain,
                                                                        jobject*                     surface);
} // extern "C"
#endif // !XR_USE_PLATFORM_ANDROID

#ifndef XR_USE_GRAPHICS_API_OPENGL
typedef struct XrGraphicsBindingOpenGLWin32KHR
{
    XrStructureType          type;
    const void* XR_MAY_ALIAS next;
    HDC                      hDC;
    HGLRC                    hGLRC;
} XrGraphicsBindingOpenGLWin32KHR;

typedef struct XrGraphicsBindingOpenGLXlibKHR
{
    XrStructureType          type;
    const void* XR_MAY_ALIAS next;
    Display*                 xDisplay;
    uint32_t                 visualid;
    GLXFBConfig              glxFBConfig;
    GLXDrawable              glxDrawable;
    GLXContext               glxContext;
} XrGraphicsBindingOpenGLXlibKHR;

typedef struct XrGraphicsBindingOpenGLXcbKHR
{
    XrStructureType          type;
    const void* XR_MAY_ALIAS next;
    xcb_connection_t*        connection;
    uint32_t                 screenNumber;
    xcb_glx_fbconfig_t       fbconfigid;
    xcb_visualid_t           visualid;
    xcb_glx_drawable_t       glxDrawable;
    xcb_glx_context_t        glxContext;
} XrGraphicsBindingOpenGLXcbKHR;

typedef struct XrGraphicsBindingOpenGLWaylandKHR
{
    XrStructureType          type;
    const void* XR_MAY_ALIAS next;
    struct wl_display*       display;
} XrGraphicsBindingOpenGLWaylandKHR;

typedef struct XrSwapchainImageOpenGLKHR
{
    XrStructureType    type;
    void* XR_MAY_ALIAS next;
    uint32_t           image;
} XrSwapchainImageOpenGLKHR;

typedef struct XrGraphicsRequirementsOpenGLKHR
{
    XrStructureType    type;
    void* XR_MAY_ALIAS next;
    XrVersion          minApiVersionSupported;
    XrVersion          maxApiVersionSupported;
} XrGraphicsRequirementsOpenGLKHR;

extern "C"
{
    typedef XrResult(XRAPI_PTR* PFN_xrGetOpenGLGraphicsRequirementsKHR)(
        XrInstance instance, XrSystemId systemId, XrGraphicsRequirementsOpenGLKHR* graphicsRequirements);
} // extern "C"

#endif // !XR_USE_GRAPHICS_API_OPENGL

#ifndef XR_USE_GRAPHICS_API_OPENGL_ES
typedef struct XrGraphicsBindingOpenGLESAndroidKHR
{
    XrStructureType          type;
    const void* XR_MAY_ALIAS next;
    EGLDisplay               display;
    EGLConfig                config;
    EGLContext               context;
} XrGraphicsBindingOpenGLESAndroidKHR;

typedef struct XrSwapchainImageOpenGLESKHR
{
    XrStructureType    type;
    void* XR_MAY_ALIAS next;
    uint32_t           image;
} XrSwapchainImageOpenGLESKHR;

typedef struct XrGraphicsRequirementsOpenGLESKHR
{
    XrStructureType    type;
    void* XR_MAY_ALIAS next;
    XrVersion          minApiVersionSupported;
    XrVersion          maxApiVersionSupported;
} XrGraphicsRequirementsOpenGLESKHR;

typedef struct XrSwapchainStateSamplerOpenGLESFB
{
    XrStructureType    type;
    void* XR_MAY_ALIAS next;
    EGLenum            minFilter;
    EGLenum            magFilter;
    EGLenum            wrapModeS;
    EGLenum            wrapModeT;
    EGLenum            swizzleRed;
    EGLenum            swizzleGreen;
    EGLenum            swizzleBlue;
    EGLenum            swizzleAlpha;
    float              maxAnisotropy;
    XrColor4f          borderColor;
} XrSwapchainStateSamplerOpenGLESFB;

extern "C"
{
    typedef XrResult(XRAPI_PTR* PFN_xrGetOpenGLESGraphicsRequirementsKHR)(
        XrInstance instance, XrSystemId systemId, XrGraphicsRequirementsOpenGLESKHR* graphicsRequirements);
} // extern "C"

#endif // !XR_USE_GRAPHICS_API_OPENGL_ES

#ifndef XR_USE_GRAPHICS_API_VULKAN

typedef struct XrGraphicsBindingVulkanKHR
{
    XrStructureType          type;
    const void* XR_MAY_ALIAS next;
    VkInstance               instance;
    VkPhysicalDevice         physicalDevice;
    VkDevice                 device;
    uint32_t                 queueFamilyIndex;
    uint32_t                 queueIndex;
} XrGraphicsBindingVulkanKHR;

typedef struct XrSwapchainImageVulkanKHR
{
    XrStructureType    type;
    void* XR_MAY_ALIAS next;
    VkImage            image;
} XrSwapchainImageVulkanKHR;

typedef struct XrGraphicsRequirementsVulkanKHR
{
    XrStructureType    type;
    void* XR_MAY_ALIAS next;
    XrVersion          minApiVersionSupported;
    XrVersion          maxApiVersionSupported;
} XrGraphicsRequirementsVulkanKHR;

typedef XrFlags64 XrVulkanInstanceCreateFlagsKHR;
typedef XrFlags64 XrVulkanDeviceCreateFlagsKHR;
typedef struct XrVulkanInstanceCreateInfoKHR
{
    XrStructureType                type;
    const void* XR_MAY_ALIAS       next;
    XrSystemId                     systemId;
    XrVulkanInstanceCreateFlagsKHR createFlags;
    PFN_vkGetInstanceProcAddr      pfnGetInstanceProcAddr;
    const VkInstanceCreateInfo*    vulkanCreateInfo;
    const VkAllocationCallbacks*   vulkanAllocator;
} XrVulkanInstanceCreateInfoKHR;

typedef struct XrVulkanDeviceCreateInfoKHR
{
    XrStructureType              type;
    const void* XR_MAY_ALIAS     next;
    XrSystemId                   systemId;
    XrVulkanDeviceCreateFlagsKHR createFlags;
    PFN_vkGetInstanceProcAddr    pfnGetInstanceProcAddr;
    VkPhysicalDevice             vulkanPhysicalDevice;
    const VkDeviceCreateInfo*    vulkanCreateInfo;
    const VkAllocationCallbacks* vulkanAllocator;
} XrVulkanDeviceCreateInfoKHR;

typedef XrGraphicsBindingVulkanKHR XrGraphicsBindingVulkan2KHR;

typedef struct XrVulkanGraphicsDeviceGetInfoKHR
{
    XrStructureType          type;
    const void* XR_MAY_ALIAS next;
    XrSystemId               systemId;
    VkInstance               vulkanInstance;
} XrVulkanGraphicsDeviceGetInfoKHR;

typedef XrSwapchainImageVulkanKHR XrSwapchainImageVulkan2KHR;

typedef XrGraphicsRequirementsVulkanKHR XrGraphicsRequirementsVulkan2KHR;

typedef struct XrSwapchainImageFoveationVulkanFB
{
    XrStructureType    type;
    void* XR_MAY_ALIAS next;
    VkImage            image;
    uint32_t           width;
    uint32_t           height;
} XrSwapchainImageFoveationVulkanFB;

typedef struct XrSwapchainStateSamplerVulkanFB
{
    XrStructureType      type;
    void* XR_MAY_ALIAS   next;
    VkFilter             minFilter;
    VkFilter             magFilter;
    VkSamplerMipmapMode  mipmapMode;
    VkSamplerAddressMode wrapModeS;
    VkSamplerAddressMode wrapModeT;
    VkComponentSwizzle   swizzleRed;
    VkComponentSwizzle   swizzleGreen;
    VkComponentSwizzle   swizzleBlue;
    VkComponentSwizzle   swizzleAlpha;
    float                maxAnisotropy;
    XrColor4f            borderColor;
} XrSwapchainStateSamplerVulkanFB;

typedef struct XrVulkanSwapchainCreateInfoMETA
{
    XrStructureType          type;
    const void* XR_MAY_ALIAS next;
    VkImageCreateFlags       additionalCreateFlags;
    VkImageUsageFlags        additionalUsageFlags;
} XrVulkanSwapchainCreateInfoMETA;

extern "C"
{
    typedef XrResult(XRAPI_PTR* PFN_xrGetVulkanInstanceExtensionsKHR)(XrInstance instance,
                                                                      XrSystemId systemId,
                                                                      uint32_t   bufferCapacityInput,
                                                                      uint32_t*  bufferCountOutput,
                                                                      char*      buffer);
    typedef XrResult(XRAPI_PTR* PFN_xrGetVulkanDeviceExtensionsKHR)(XrInstance instance,
                                                                    XrSystemId systemId,
                                                                    uint32_t   bufferCapacityInput,
                                                                    uint32_t*  bufferCountOutput,
                                                                    char*      buffer);
    typedef XrResult(XRAPI_PTR* PFN_xrGetVulkanGraphicsDeviceKHR)(XrInstance        instance,
                                                                  XrSystemId        systemId,
                                                                  VkInstance        vkInstance,
                                                                  VkPhysicalDevice* vkPhysicalDevice);
    typedef XrResult(XRAPI_PTR* PFN_xrGetVulkanGraphicsRequirementsKHR)(
        XrInstance instance, XrSystemId systemId, XrGraphicsRequirementsVulkanKHR* graphicsRequirements);
    typedef XrResult(XRAPI_PTR* PFN_xrCreateVulkanInstanceKHR)(XrInstance                           instance,
                                                               const XrVulkanInstanceCreateInfoKHR* createInfo,
                                                               VkInstance*                          vulkanInstance,
                                                               VkResult*                            vulkanResult);
    typedef XrResult(XRAPI_PTR* PFN_xrCreateVulkanDeviceKHR)(XrInstance                         instance,
                                                             const XrVulkanDeviceCreateInfoKHR* createInfo,
                                                             VkDevice*                          vulkanDevice,
                                                             VkResult*                          vulkanResult);
    typedef XrResult(XRAPI_PTR* PFN_xrGetVulkanGraphicsDevice2KHR)(XrInstance                              instance,
                                                                   const XrVulkanGraphicsDeviceGetInfoKHR* getInfo,
                                                                   VkPhysicalDevice* vulkanPhysicalDevice);
    typedef XrResult(XRAPI_PTR* PFN_xrGetVulkanGraphicsRequirements2KHR)(
        XrInstance instance, XrSystemId systemId, XrGraphicsRequirementsVulkanKHR* graphicsRequirements);
} // extern "C"

#endif // !XR_USE_GRAPHICS_API_VULKAN

#ifndef XR_USE_GRAPHICS_API_D3D11
typedef struct XrGraphicsBindingD3D11KHR
{
    XrStructureType          type;
    const void* XR_MAY_ALIAS next;
    ID3D11Device*            device;
} XrGraphicsBindingD3D11KHR;

typedef struct XrSwapchainImageD3D11KHR
{
    XrStructureType    type;
    void* XR_MAY_ALIAS next;
    ID3D11Texture2D*   texture;
} XrSwapchainImageD3D11KHR;

typedef struct XrGraphicsRequirementsD3D11KHR
{
    XrStructureType    type;
    void* XR_MAY_ALIAS next;
    LUID               adapterLuid;
    D3D_FEATURE_LEVEL  minFeatureLevel;
} XrGraphicsRequirementsD3D11KHR;

extern "C"
{
    typedef XrResult(XRAPI_PTR* PFN_xrGetD3D11GraphicsRequirementsKHR)(
        XrInstance instance, XrSystemId systemId, XrGraphicsRequirementsD3D11KHR* graphicsRequirements);
} // extern "C"
#endif // XR_USE_GRAPHICS_API_D3D11

#ifndef XR_USE_GRAPHICS_API_D3D12
typedef struct XrGraphicsBindingD3D12KHR
{
    XrStructureType          type;
    const void* XR_MAY_ALIAS next;
    ID3D12Device*            device;
    ID3D12CommandQueue*      queue;
} XrGraphicsBindingD3D12KHR;

typedef struct XrSwapchainImageD3D12KHR
{
    XrStructureType    type;
    void* XR_MAY_ALIAS next;
    ID3D12Resource*    texture;
} XrSwapchainImageD3D12KHR;

typedef struct XrGraphicsRequirementsD3D12KHR
{
    XrStructureType    type;
    void* XR_MAY_ALIAS next;
    LUID               adapterLuid;
    D3D_FEATURE_LEVEL  minFeatureLevel;
} XrGraphicsRequirementsD3D12KHR;

extern "C"
{
    typedef XrResult(XRAPI_PTR* PFN_xrGetD3D12GraphicsRequirementsKHR)(
        XrInstance instance, XrSystemId systemId, XrGraphicsRequirementsD3D12KHR* graphicsRequirements);
} // extern "C"
#endif // XR_USE_GRAPHICS_API_D3D12

#ifndef XR_USE_PLATFORM_WIN32
#define XR_MAX_AUDIO_DEVICE_STR_SIZE_OCULUS 128

typedef struct XrHolographicWindowAttachmentMSFT
{
    XrStructureType          type;
    const void* XR_MAY_ALIAS next;
    IUnknown*                holographicSpace;
    IUnknown*                coreWindow;
} XrHolographicWindowAttachmentMSFT;

extern "C"
{
    typedef XrResult(XRAPI_PTR* PFN_xrConvertWin32PerformanceCounterToTimeKHR)(XrInstance           instance,
                                                                               const LARGE_INTEGER* performanceCounter,
                                                                               XrTime*              time);
    typedef XrResult(XRAPI_PTR* PFN_xrConvertTimeToWin32PerformanceCounterKHR)(XrInstance     instance,
                                                                               XrTime         time,
                                                                               LARGE_INTEGER* performanceCounter);
    typedef XrResult(XRAPI_PTR* PFN_xrCreateSpatialAnchorFromPerceptionAnchorMSFT)(XrSession session,
                                                                                   IUnknown* perceptionAnchor,
                                                                                   XrSpatialAnchorMSFT* anchor);
    typedef XrResult(XRAPI_PTR* PFN_xrTryGetPerceptionAnchorFromSpatialAnchorMSFT)(XrSession           session,
                                                                                   XrSpatialAnchorMSFT anchor,
                                                                                   IUnknown** perceptionAnchor);
    typedef XrResult(XRAPI_PTR* PFN_xrGetAudioOutputDeviceGuidOculus)(
        XrInstance instance, wchar_t buffer[XR_MAX_AUDIO_DEVICE_STR_SIZE_OCULUS]);
    typedef XrResult(XRAPI_PTR* PFN_xrGetAudioInputDeviceGuidOculus)(
        XrInstance instance, wchar_t buffer[XR_MAX_AUDIO_DEVICE_STR_SIZE_OCULUS]);
} // extern "C"

#endif // !XR_USE_PLATFORM_WIN32

#ifndef XR_USE_TIMESPEC

extern "C"
{
    typedef XrResult(XRAPI_PTR* PFN_xrConvertTimespecTimeToTimeKHR)(XrInstance             instance,
                                                                    const struct timespec* timespecTime,
                                                                    XrTime*                time);
    typedef XrResult(XRAPI_PTR* PFN_xrConvertTimeToTimespecTimeKHR)(XrInstance       instance,
                                                                    XrTime           time,
                                                                    struct timespec* timespecTime);
} // extern "C"

#endif // !XR_USE_TIMESPEC

#ifndef XR_USE_PLATFORM_EGL
extern "C"
{
    typedef PFN_xrVoidFunction (*PFN_xrEglGetProcAddressMNDX)(const char* name);
} // extern "C"

typedef struct XrGraphicsBindingEGLMNDX
{
    XrStructureType             type;
    const void* XR_MAY_ALIAS    next;
    PFN_xrEglGetProcAddressMNDX getProcAddress;
    EGLDisplay                  display;
    EGLConfig                   config;
    EGLContext                  context;
} XrGraphicsBindingEGLMNDX;
#endif // !XR_USE_PLATFORM_EGL

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_PLATFORM_TYPES_H
