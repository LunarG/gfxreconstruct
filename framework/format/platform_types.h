/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2023 LunarG, Inc.
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
#if !defined(XR_USE_PLATFORM_ANDROID)
typedef void* jobject;
#endif // XR_USE_PLATFORM_ANDROID

#if !defined(WIN32)
// These are types defined in Microsoft's dxgi.h header
// These are replicated here so that non-Microsoft platforms
// can handle the proper decode.
typedef void* IDXGIAdapter;
typedef void* IDXGIAdapter1;
typedef void* IDXGIAdapter2;
typedef void* IDXGIAdapter3;
typedef UINT  DXGI_USAGE;

#define DXGI_ERROR_ACCESS_DENIED 0x887A002B
#define DXGI_ERROR_ACCESS_LOST 0x887A0026
#define DXGI_ERROR_ALREADY_EXISTS 0x887A0036L
#define DXGI_ERROR_CANNOT_PROTECT_CONTENT 0x887A002A
#define DXGI_ERROR_DEVICE_HUNG 0x887A0006
#define DXGI_ERROR_DEVICE_REMOVED 0x887A0005
#define DXGI_ERROR_DEVICE_RESET 0x887A0007
#define DXGI_ERROR_DRIVER_INTERNAL_ERROR 0x887A0020
#define DXGI_ERROR_FRAME_STATISTICS_DISJOINT 0x887A000B
#define DXGI_ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE 0x887A000C
#define DXGI_ERROR_INVALID_CALL 0x887A0001
#define DXGI_ERROR_MORE_DATA 0x887A0003
#define DXGI_ERROR_NAME_ALREADY_EXISTS 0x887A002C
#define DXGI_ERROR_NONEXCLUSIVE 0x887A0021
#define DXGI_ERROR_NOT_CURRENTLY_AVAILABLE 0x887A0022
#define DXGI_ERROR_NOT_FOUND 0x887A0002
#define DXGI_ERROR_REMOTE_CLIENT_DISCONNECTED 0x887A0023
#define DXGI_ERROR_REMOTE_OUTOFMEMORY 0x887A0024
#define DXGI_ERROR_RESTRICT_TO_OUTPUT_STALE 0x887A0029
#define DXGI_ERROR_SDK_COMPONENT_MISSING 0x887A002D
#define DXGI_ERROR_SESSION_DISCONNECTED 0x887A0028
#define DXGI_ERROR_UNSUPPORTED 0x887A0004
#define DXGI_ERROR_WAIT_TIMEOUT 0x887A0027
#define DXGI_ERROR_WAS_STILL_DRAWING 0x887A000A
#define D3DOK_NOAUTOGEN 141953135
#define D3DERR_WRONGTEXTUREFORMAT 2289436696
#define D3DERR_UNSUPPORTEDCOLOROPERATION 2289436697
#define D3DERR_UNSUPPORTEDCOLORARG 2289436698
#define D3DERR_UNSUPPORTEDALPHAOPERATION 2289436699
#define D3DERR_UNSUPPORTEDALPHAARG 2289436700
#define D3DERR_TOOMANYOPERATIONS 2289436701
#define D3DERR_CONFLICTINGTEXTUREFILTER 2289436702
#define D3DERR_UNSUPPORTEDFACTORVALUE 2289436703
#define D3DERR_CONFLICTINGRENDERSTATE 2289436705
#define D3DERR_UNSUPPORTEDTEXTUREFILTER 2289436706
#define D3DERR_CONFLICTINGTEXTUREPALETTE 2289436710
#define D3DERR_DRIVERINTERNALERROR 2289436711
#define D3DERR_NOTFOUND 2289436774
#define D3DERR_MOREDATA 2289436775
#define D3DERR_DEVICELOST 2289436776
#define D3DERR_DEVICENOTRESET 2289436777
#define D3DERR_NOTAVAILABLE 2289436778
#define D3DERR_OUTOFVIDEOMEMORY 2289435004
#define D3DERR_INVALIDDEVICE 2289436779
#define D3DERR_INVALIDCALL 2289436780
#define D3DERR_DRIVERINVALIDCALL 2289436781
#define D3DERR_WASSTILLDRAWING 2289435164
#define D3DERR_DEVICEREMOVED 2289436784
#define D3DERR_DEVICEHUNG 2289436788
#define D3D12_ERROR_ADAPTER_NOT_FOUND 0x887e0001
#define D3D12_ERROR_INVALID_REDIST 0x887e0003
#define D3D12_ERROR_DRIVER_VERSION_MISMATCH 0x887e0002
#define E_ABORT 0x80004004
#define E_ACCESSDENIED 0x80070005
#define E_FAIL 0x80004005
#define E_HANDLE 0x80070006
#define E_INVALIDARG 0x80070057
#define E_NOINTERFACE 0x80004002
#define E_NOTIMPL 0x80004001
#define E_OUTOFMEMORY 0x8007000E
#define E_POINTER 0x80004003
#define E_UNEXPECTED 0x8000FFFF
#define S_OK 0x00000000L
#define S_FALSE 0x00000001L
#define S_NOT_RESIDENT 141953141
#define S_RESIDENT_IN_SHARED_MEMORY 141953142
#define S_PRESENT_MODE_CHANGED 141953143
#define S_PRESENT_OCCLUDED 141953144

#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
    const GUID name = { l, w1, w2, { b1, b2, b3, b4, b5, b6, b7, b8 } }

DEFINE_GUID(IID_IDXGIAdapter, 0x2411e7e1, 0x12ac, 0x4ccf, 0xbd, 0x14, 0x97, 0x98, 0xe8, 0x53, 0x4d, 0xc0);
DEFINE_GUID(IID_IDXGIAdapter1, 0x29038f61, 0x3839, 0x4626, 0x91, 0xfd, 0x08, 0x68, 0x79, 0x01, 0x1a, 0x05);
DEFINE_GUID(IID_IDXGIAdapter2, 0x0AA1AE0A, 0xFA0E, 0x4B84, 0x86, 0x44, 0xE0, 0x5F, 0xF8, 0xE5, 0xAC, 0xB5);
DEFINE_GUID(IID_IDXGIAdapter3, 0x645967A4, 0x1392, 0x4310, 0xA7, 0x98, 0x80, 0x53, 0xCE, 0x3E, 0x93, 0xFD);
DEFINE_GUID(IID_IDXGIAdapter4, 0x3c8d99d1, 0x4fbf, 0x4181, 0xa8, 0x2c, 0xaf, 0x66, 0xbf, 0x7b, 0xd2, 0x4e);
typedef void* IID_IDXGIAdapter5;
typedef void* IID_IDXGIAdapter6;
DEFINE_GUID(IID_IDXGIDecodeSwapChain, 0x2633066b, 0x4514, 0x4c7a, 0x8f, 0xd8, 0x12, 0xea, 0x98, 0x05, 0x9d, 0x18);
DEFINE_GUID(IID_IDXGIDevice, 0x54ec77fa, 0x1377, 0x44e6, 0x8c, 0x32, 0x88, 0xfd, 0x5f, 0x44, 0xc8, 0x4c);
DEFINE_GUID(IID_IDXGIDevice1, 0x77db970f, 0x6276, 0x48ba, 0xba, 0x28, 0x07, 0x01, 0x43, 0xb4, 0x39, 0x2c);
DEFINE_GUID(IID_IDXGIDevice2, 0x05008617, 0xfbfd, 0x4051, 0xa7, 0x90, 0x14, 0x48, 0x84, 0xb4, 0xf6, 0xa9);
DEFINE_GUID(IID_IDXGIDevice3, 0x6007896c, 0x3244, 0x4afd, 0xbf, 0x18, 0xa6, 0xd3, 0xbe, 0xda, 0x50, 0x23);
DEFINE_GUID(IID_IDXGIDevice4, 0x95B4F95F, 0xD8DA, 0x4CA4, 0x9E, 0xE6, 0x3B, 0x76, 0xD5, 0x96, 0x8A, 0x10);
DEFINE_GUID(IID_IDXGIDeviceSubObject, 0x3d3e0379, 0xf9de, 0x4d58, 0xbb, 0x6c, 0x18, 0xd6, 0x29, 0x92, 0xf1, 0xa6);
DEFINE_GUID(IID_IDXGIDisplayControl, 0xea9dbf1a, 0xc88e, 0x4486, 0x85, 0x4a, 0x98, 0xaa, 0x01, 0x38, 0xf3, 0x0c);
DEFINE_GUID(IID_IDXGIFactory, 0x7b7166ec, 0x21c7, 0x44ae, 0xb2, 0x1a, 0xc9, 0xae, 0x32, 0x1a, 0xe3, 0x69);
DEFINE_GUID(IID_IDXGIFactory1, 0x770aae78, 0xf26f, 0x4dba, 0xa8, 0x29, 0x25, 0x3c, 0x83, 0xd1, 0xb3, 0x87);
DEFINE_GUID(IID_IDXGIFactory2, 0x50c83a1c, 0xe072, 0x4c48, 0x87, 0xb0, 0x36, 0x30, 0xfa, 0x36, 0xa6, 0xd0);
DEFINE_GUID(IID_IDXGIFactory3, 0x25483823, 0xcd46, 0x4c7d, 0x86, 0xca, 0x47, 0xaa, 0x95, 0xb8, 0x37, 0xbd);
DEFINE_GUID(IID_IDXGIFactory4, 0x1bc6ea02, 0xef36, 0x464f, 0xbf, 0x0c, 0x21, 0xca, 0x39, 0xe5, 0x16, 0x8a);
DEFINE_GUID(IID_IDXGIFactory5, 0x7632e1f5, 0xee65, 0x4dca, 0x87, 0xfd, 0x84, 0xcd, 0x75, 0xf8, 0x83, 0x8d);
DEFINE_GUID(IID_IDXGIFactory6, 0xc1b6694f, 0xff09, 0x44a9, 0xb0, 0x3c, 0x77, 0x90, 0x0a, 0x0a, 0x1d, 0x17);
DEFINE_GUID(IID_IDXGIFactory7, 0xa4966eed, 0x76db, 0x44da, 0x84, 0xc1, 0xee, 0x9a, 0x7a, 0xfb, 0x20, 0xa8);
DEFINE_GUID(IID_IDXGIFactoryMedia, 0x41e7d1f2, 0xa591, 0x4f7b, 0xa2, 0xe5, 0xfa, 0x9c, 0x84, 0x3e, 0x1c, 0x12);
DEFINE_GUID(IID_IDXGIKeyedMutex, 0x9d8e1289, 0xd7b3, 0x465f, 0x81, 0x26, 0x25, 0x0e, 0x34, 0x9a, 0xf8, 0x5d);
DEFINE_GUID(IID_IDXGIObject, 0xaec22fb8, 0x76f3, 0x4639, 0x9b, 0xe0, 0x28, 0xeb, 0x43, 0xa6, 0x7a, 0x2e);
DEFINE_GUID(IID_IDXGIOutput, 0xae02eedb, 0xc735, 0x4690, 0x8d, 0x52, 0x5a, 0x8d, 0xc2, 0x02, 0x13, 0xaa);
DEFINE_GUID(IID_IDXGIOutput1, 0x00cddea8, 0x939b, 0x4b83, 0xa3, 0x40, 0xa6, 0x85, 0x22, 0x66, 0x66, 0xcc);
DEFINE_GUID(IID_IDXGIOutput2, 0x595e39d1, 0x2724, 0x4663, 0x99, 0xb1, 0xda, 0x96, 0x9d, 0xe2, 0x83, 0x64);
DEFINE_GUID(IID_IDXGIOutput3, 0x8a6bb301, 0x7e7e, 0x41F4, 0xa8, 0xe0, 0x5b, 0x32, 0xf7, 0xf9, 0x9b, 0x18);
DEFINE_GUID(IID_IDXGIOutput4, 0xdc7dca35, 0x2196, 0x414d, 0x9F, 0x53, 0x61, 0x78, 0x84, 0x03, 0x2a, 0x60);
DEFINE_GUID(IID_IDXGIOutput5, 0x80A07424, 0xAB52, 0x42EB, 0x83, 0x3C, 0x0C, 0x42, 0xFD, 0x28, 0x2D, 0x98);
DEFINE_GUID(IID_IDXGIOutput6, 0x068346e8, 0xaaec, 0x4b84, 0xad, 0xd7, 0x13, 0x7f, 0x51, 0x3f, 0x77, 0xa1);
DEFINE_GUID(IID_IDXGIOutputDuplication, 0x191cfac3, 0xa341, 0x470d, 0xb2, 0x6e, 0xa8, 0x64, 0xf4, 0x28, 0x31, 0x9c);
DEFINE_GUID(IID_IDXGIResource, 0x035f3ab4, 0x482e, 0x4e50, 0xb4, 0x1f, 0x8a, 0x7f, 0x8b, 0xd8, 0x96, 0x0b);
DEFINE_GUID(IID_IDXGIResource1, 0x30961379, 0x4609, 0x4a41, 0x99, 0x8e, 0x54, 0xfe, 0x56, 0x7e, 0xe0, 0xc1);
DEFINE_GUID(IID_IDXGISurface, 0xcafcb56c, 0x6ac3, 0x4889, 0xbf, 0x47, 0x9e, 0x23, 0xbb, 0xd2, 0x60, 0xec);
DEFINE_GUID(IID_IDXGISurface1, 0x4AE63092, 0x6327, 0x4c1b, 0x80, 0xAE, 0xBF, 0xE1, 0x2E, 0xA3, 0x2B, 0x86);
DEFINE_GUID(IID_IDXGISurface2, 0xaba496dd, 0xb617, 0x4cb8, 0xa8, 0x66, 0xbc, 0x44, 0xd7, 0xeb, 0x1f, 0xa2);
DEFINE_GUID(IID_IDXGISwapChain, 0x310d36a0, 0xd2e7, 0x4c0a, 0xaa, 0x04, 0x6a, 0x9d, 0x23, 0xb8, 0x88, 0x6a);
DEFINE_GUID(IID_IDXGISwapChain1, 0x790a45f7, 0x0d42, 0x4876, 0x98, 0x3a, 0x0a, 0x55, 0xcf, 0xe6, 0xf4, 0xaa);
DEFINE_GUID(IID_IDXGISwapChain2, 0xa8be2ac4, 0x199f, 0x4946, 0xb3, 0x31, 0x79, 0x59, 0x9f, 0xb9, 0x8d, 0xe7);
DEFINE_GUID(IID_IDXGISwapChain3, 0x94d99bdb, 0xf1f8, 0x4ab0, 0xb2, 0x36, 0x7d, 0xa0, 0x17, 0x0e, 0xda, 0xb1);
DEFINE_GUID(IID_IDXGISwapChain4, 0x3D585D5A, 0xBD4A, 0x489E, 0xB1, 0xF4, 0x3D, 0xBC, 0xB6, 0x45, 0x2F, 0xFB);
DEFINE_GUID(IID_IDXGISwapChainMedia, 0xdd95b90b, 0xf05f, 0x4f6a, 0xbd, 0x65, 0x25, 0xbf, 0xb2, 0x64, 0xbd, 0x84);
DEFINE_GUID(IID_ID3D10Blob, 0x8ba5fb08, 0x5195, 0x40e2, 0xac, 0x58, 0x0d, 0x98, 0x9c, 0x3a, 0x01, 0x02);
DEFINE_GUID(IID_IUnknown, 0x00000000, 0x0000, 0x0000, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46);

DEFINE_GUID(WKPDID_D3DAutoDebugObjectNameW, 0xd4902e36, 0x757a, 0x4942, 0x95, 0x94, 0xb6, 0x76, 0x9a, 0xfa, 0x43, 0xcd);
DEFINE_GUID(WKPDID_D3DDebugObjectName, 0x429b8c22, 0x9188, 0x4b0c, 0x87, 0x42, 0xac, 0xb0, 0xbf, 0x85, 0xc2, 0x00);
DEFINE_GUID(WKPDID_D3DDebugObjectNameW, 0x4cca5fd8, 0x921f, 0x42c8, 0x85, 0x66, 0x70, 0xca, 0xf2, 0xa9, 0xb7, 0x41);
DEFINE_GUID(WKPDID_CommentStringW, 0xd0149dc0, 0x90e8, 0x4ec8, 0x81, 0x44, 0xe9, 0x00, 0xad, 0x26, 0x6b, 0xb2);

DEFINE_GUID(D3D_TEXTURE_LAYOUT_64KB_STANDARD_SWIZZLE,
            0x4c0f29e3,
            0x3f5f,
            0x4d35,
            0x84,
            0xc9,
            0xbc,
            0x09,
            0x83,
            0xb6,
            0x2c,
            0x28);
DEFINE_GUID(D3D_TEXTURE_LAYOUT_ROW_MAJOR, 0xb5dc234f, 0x72bb, 0x4bec, 0x97, 0x05, 0x8c, 0xf2, 0x58, 0xdf, 0x6b, 0x6c);

DEFINE_GUID(DXGI_DEBUG_D3D11, 0x4b99317b, 0xac39, 0x4aa6, 0xbb, 0x0b, 0xba, 0xa0, 0x47, 0x84, 0x79, 0x8f);
DEFINE_GUID(DXGI_DEBUG_D3D12, 0xcf59a98c, 0xa950, 0x4326, 0x91, 0xef, 0x9b, 0xba, 0xa1, 0x7b, 0xfd, 0x95);

// Enums and Flags

enum DXGI_ADAPTER_FLAG
{
    DXGI_ADAPTER_FLAG_NONE        = 0,
    DXGI_ADAPTER_FLAG_REMOTE      = 1,
    DXGI_ADAPTER_FLAG_SOFTWARE    = 2,
    DXGI_ADAPTER_FLAG_FORCE_DWORD = 0xffffffff
};

enum DXGI_ADAPTER_FLAG3
{
    DXGI_ADAPTER_FLAG3_NONE                         = 0,
    DXGI_ADAPTER_FLAG3_REMOTE                       = 1,
    DXGI_ADAPTER_FLAG3_SOFTWARE                     = 2,
    DXGI_ADAPTER_FLAG3_ACG_COMPATIBLE               = 4,
    DXGI_ADAPTER_FLAG3_SUPPORT_MONITORED_FENCES     = 8,
    DXGI_ADAPTER_FLAG3_SUPPORT_NON_MONITORED_FENCES = 0x10,
    DXGI_ADAPTER_FLAG3_KEYED_MUTEX_CONFORMANCE      = 0x20,
    DXGI_ADAPTER_FLAG3_FORCE_DWORD                  = 0xffffffff
};

enum DXGI_ALPHA_MODE
{
    DXGI_ALPHA_MODE_UNSPECIFIED   = 0,
    DXGI_ALPHA_MODE_PREMULTIPLIED = 1,
    DXGI_ALPHA_MODE_STRAIGHT      = 2,
    DXGI_ALPHA_MODE_IGNORE        = 3,
    DXGI_ALPHA_MODE_FORCE_DWORD   = 0xffffffff
};

enum DXGI_COLOR_SPACE_TYPE
{
    DXGI_COLOR_SPACE_RGB_FULL_G22_NONE_P709           = 0,
    DXGI_COLOR_SPACE_RGB_FULL_G10_NONE_P709           = 1,
    DXGI_COLOR_SPACE_RGB_STUDIO_G22_NONE_P709         = 2,
    DXGI_COLOR_SPACE_RGB_STUDIO_G22_NONE_P2020        = 3,
    DXGI_COLOR_SPACE_RESERVED                         = 4,
    DXGI_COLOR_SPACE_YCBCR_FULL_G22_NONE_P709_X601    = 5,
    DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_LEFT_P601       = 6,
    DXGI_COLOR_SPACE_YCBCR_FULL_G22_LEFT_P601         = 7,
    DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_LEFT_P709       = 8,
    DXGI_COLOR_SPACE_YCBCR_FULL_G22_LEFT_P709         = 9,
    DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_LEFT_P2020      = 10,
    DXGI_COLOR_SPACE_YCBCR_FULL_G22_LEFT_P2020        = 11,
    DXGI_COLOR_SPACE_RGB_FULL_G2084_NONE_P2020        = 12,
    DXGI_COLOR_SPACE_YCBCR_STUDIO_G2084_LEFT_P2020    = 13,
    DXGI_COLOR_SPACE_RGB_STUDIO_G2084_NONE_P2020      = 14,
    DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_TOPLEFT_P2020   = 15,
    DXGI_COLOR_SPACE_YCBCR_STUDIO_G2084_TOPLEFT_P2020 = 16,
    DXGI_COLOR_SPACE_RGB_FULL_G22_NONE_P2020          = 17,
    DXGI_COLOR_SPACE_YCBCR_STUDIO_GHLG_TOPLEFT_P2020  = 18,
    DXGI_COLOR_SPACE_YCBCR_FULL_GHLG_TOPLEFT_P2020    = 19,
    DXGI_COLOR_SPACE_RGB_STUDIO_G24_NONE_P709         = 20,
    DXGI_COLOR_SPACE_RGB_STUDIO_G24_NONE_P2020        = 21,
    DXGI_COLOR_SPACE_YCBCR_STUDIO_G24_LEFT_P709       = 22,
    DXGI_COLOR_SPACE_YCBCR_STUDIO_G24_LEFT_P2020      = 23,
    DXGI_COLOR_SPACE_YCBCR_STUDIO_G24_TOPLEFT_P2020   = 24,
    DXGI_COLOR_SPACE_CUSTOM                           = 0xFFFFFFFF
};

enum DXGI_COMPUTE_PREEMPTION_GRANULARITY
{
    DXGI_COMPUTE_PREEMPTION_DMA_BUFFER_BOUNDARY   = 0,
    DXGI_COMPUTE_PREEMPTION_DISPATCH_BOUNDARY     = 1,
    DXGI_COMPUTE_PREEMPTION_THREAD_GROUP_BOUNDARY = 2,
    DXGI_COMPUTE_PREEMPTION_THREAD_BOUNDARY       = 3,
    DXGI_COMPUTE_PREEMPTION_INSTRUCTION_BOUNDARY  = 4
};

enum DXGI_FEATURE
{
    DXGI_FEATURE_PRESENT_ALLOW_TEARING = 0x0
};

enum DXGI_FORMAT
{
    DXGI_FORMAT_UNKNOWN                    = 0,
    DXGI_FORMAT_R32G32B32A32_TYPELESS      = 1,
    DXGI_FORMAT_R32G32B32A32_FLOAT         = 2,
    DXGI_FORMAT_R32G32B32A32_UINT          = 3,
    DXGI_FORMAT_R32G32B32A32_SINT          = 4,
    DXGI_FORMAT_R32G32B32_TYPELESS         = 5,
    DXGI_FORMAT_R32G32B32_FLOAT            = 6,
    DXGI_FORMAT_R32G32B32_UINT             = 7,
    DXGI_FORMAT_R32G32B32_SINT             = 8,
    DXGI_FORMAT_R16G16B16A16_TYPELESS      = 9,
    DXGI_FORMAT_R16G16B16A16_FLOAT         = 10,
    DXGI_FORMAT_R16G16B16A16_UNORM         = 11,
    DXGI_FORMAT_R16G16B16A16_UINT          = 12,
    DXGI_FORMAT_R16G16B16A16_SNORM         = 13,
    DXGI_FORMAT_R16G16B16A16_SINT          = 14,
    DXGI_FORMAT_R32G32_TYPELESS            = 15,
    DXGI_FORMAT_R32G32_FLOAT               = 16,
    DXGI_FORMAT_R32G32_UINT                = 17,
    DXGI_FORMAT_R32G32_SINT                = 18,
    DXGI_FORMAT_R32G8X24_TYPELESS          = 19,
    DXGI_FORMAT_D32_FLOAT_S8X24_UINT       = 20,
    DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS   = 21,
    DXGI_FORMAT_X32_TYPELESS_G8X24_UINT    = 22,
    DXGI_FORMAT_R10G10B10A2_TYPELESS       = 23,
    DXGI_FORMAT_R10G10B10A2_UNORM          = 24,
    DXGI_FORMAT_R10G10B10A2_UINT           = 25,
    DXGI_FORMAT_R11G11B10_FLOAT            = 26,
    DXGI_FORMAT_R8G8B8A8_TYPELESS          = 27,
    DXGI_FORMAT_R8G8B8A8_UNORM             = 28,
    DXGI_FORMAT_R8G8B8A8_UNORM_SRGB        = 29,
    DXGI_FORMAT_R8G8B8A8_UINT              = 30,
    DXGI_FORMAT_R8G8B8A8_SNORM             = 31,
    DXGI_FORMAT_R8G8B8A8_SINT              = 32,
    DXGI_FORMAT_R16G16_TYPELESS            = 33,
    DXGI_FORMAT_R16G16_FLOAT               = 34,
    DXGI_FORMAT_R16G16_UNORM               = 35,
    DXGI_FORMAT_R16G16_UINT                = 36,
    DXGI_FORMAT_R16G16_SNORM               = 37,
    DXGI_FORMAT_R16G16_SINT                = 38,
    DXGI_FORMAT_R32_TYPELESS               = 39,
    DXGI_FORMAT_D32_FLOAT                  = 40,
    DXGI_FORMAT_R32_FLOAT                  = 41,
    DXGI_FORMAT_R32_UINT                   = 42,
    DXGI_FORMAT_R32_SINT                   = 43,
    DXGI_FORMAT_R24G8_TYPELESS             = 44,
    DXGI_FORMAT_D24_UNORM_S8_UINT          = 45,
    DXGI_FORMAT_R24_UNORM_X8_TYPELESS      = 46,
    DXGI_FORMAT_X24_TYPELESS_G8_UINT       = 47,
    DXGI_FORMAT_R8G8_TYPELESS              = 48,
    DXGI_FORMAT_R8G8_UNORM                 = 49,
    DXGI_FORMAT_R8G8_UINT                  = 50,
    DXGI_FORMAT_R8G8_SNORM                 = 51,
    DXGI_FORMAT_R8G8_SINT                  = 52,
    DXGI_FORMAT_R16_TYPELESS               = 53,
    DXGI_FORMAT_R16_FLOAT                  = 54,
    DXGI_FORMAT_D16_UNORM                  = 55,
    DXGI_FORMAT_R16_UNORM                  = 56,
    DXGI_FORMAT_R16_UINT                   = 57,
    DXGI_FORMAT_R16_SNORM                  = 58,
    DXGI_FORMAT_R16_SINT                   = 59,
    DXGI_FORMAT_R8_TYPELESS                = 60,
    DXGI_FORMAT_R8_UNORM                   = 61,
    DXGI_FORMAT_R8_UINT                    = 62,
    DXGI_FORMAT_R8_SNORM                   = 63,
    DXGI_FORMAT_R8_SINT                    = 64,
    DXGI_FORMAT_A8_UNORM                   = 65,
    DXGI_FORMAT_R1_UNORM                   = 66,
    DXGI_FORMAT_R9G9B9E5_SHAREDEXP         = 67,
    DXGI_FORMAT_R8G8_B8G8_UNORM            = 68,
    DXGI_FORMAT_G8R8_G8B8_UNORM            = 69,
    DXGI_FORMAT_BC1_TYPELESS               = 70,
    DXGI_FORMAT_BC1_UNORM                  = 71,
    DXGI_FORMAT_BC1_UNORM_SRGB             = 72,
    DXGI_FORMAT_BC2_TYPELESS               = 73,
    DXGI_FORMAT_BC2_UNORM                  = 74,
    DXGI_FORMAT_BC2_UNORM_SRGB             = 75,
    DXGI_FORMAT_BC3_TYPELESS               = 76,
    DXGI_FORMAT_BC3_UNORM                  = 77,
    DXGI_FORMAT_BC3_UNORM_SRGB             = 78,
    DXGI_FORMAT_BC4_TYPELESS               = 79,
    DXGI_FORMAT_BC4_UNORM                  = 80,
    DXGI_FORMAT_BC4_SNORM                  = 81,
    DXGI_FORMAT_BC5_TYPELESS               = 82,
    DXGI_FORMAT_BC5_UNORM                  = 83,
    DXGI_FORMAT_BC5_SNORM                  = 84,
    DXGI_FORMAT_B5G6R5_UNORM               = 85,
    DXGI_FORMAT_B5G5R5A1_UNORM             = 86,
    DXGI_FORMAT_B8G8R8A8_UNORM             = 87,
    DXGI_FORMAT_B8G8R8X8_UNORM             = 88,
    DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM = 89,
    DXGI_FORMAT_B8G8R8A8_TYPELESS          = 90,
    DXGI_FORMAT_B8G8R8A8_UNORM_SRGB        = 91,
    DXGI_FORMAT_B8G8R8X8_TYPELESS          = 92,
    DXGI_FORMAT_B8G8R8X8_UNORM_SRGB        = 93,
    DXGI_FORMAT_BC6H_TYPELESS              = 94,
    DXGI_FORMAT_BC6H_UF16                  = 95,
    DXGI_FORMAT_BC6H_SF16                  = 96,
    DXGI_FORMAT_BC7_TYPELESS               = 97,
    DXGI_FORMAT_BC7_UNORM                  = 98,
    DXGI_FORMAT_BC7_UNORM_SRGB             = 99,
    DXGI_FORMAT_AYUV                       = 100,
    DXGI_FORMAT_Y410                       = 101,
    DXGI_FORMAT_Y416                       = 102,
    DXGI_FORMAT_NV12                       = 103,
    DXGI_FORMAT_P010                       = 104,
    DXGI_FORMAT_P016                       = 105,
    DXGI_FORMAT_420_OPAQUE                 = 106,
    DXGI_FORMAT_YUY2                       = 107,
    DXGI_FORMAT_Y210                       = 108,
    DXGI_FORMAT_Y216                       = 109,
    DXGI_FORMAT_NV11                       = 110,
    DXGI_FORMAT_AI44                       = 111,
    DXGI_FORMAT_IA44                       = 112,
    DXGI_FORMAT_P8                         = 113,
    DXGI_FORMAT_A8P8                       = 114,
    DXGI_FORMAT_B4G4R4A4_UNORM             = 115,
    DXGI_FORMAT_P208                       = 130,
    DXGI_FORMAT_V208                       = 131,
    DXGI_FORMAT_V408                       = 132,
    DXGI_FORMAT_SAMPLER_FEEDBACK_MIN_MIP_OPAQUE,
    DXGI_FORMAT_SAMPLER_FEEDBACK_MIP_REGION_USED_OPAQUE,
    DXGI_FORMAT_FORCE_UINT = 0xffffffff
};

enum DXGI_FRAME_PRESENTATION_MODE
{
    DXGI_FRAME_PRESENTATION_MODE_COMPOSED            = 0,
    DXGI_FRAME_PRESENTATION_MODE_OVERLAY             = 1,
    DXGI_FRAME_PRESENTATION_MODE_NONE                = 2,
    DXGI_FRAME_PRESENTATION_MODE_COMPOSITION_FAILURE = 3
};

enum DXGI_GPU_PREFERENCE
{
    DXGI_GPU_PREFERENCE_UNSPECIFIED = 0,
    DXGI_GPU_PREFERENCE_MINIMUM_POWER,
    DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE
};

enum DXGI_GRAPHICS_PREEMPTION_GRANULARITY
{
    DXGI_GRAPHICS_PREEMPTION_DMA_BUFFER_BOUNDARY  = 0,
    DXGI_GRAPHICS_PREEMPTION_PRIMITIVE_BOUNDARY   = 1,
    DXGI_GRAPHICS_PREEMPTION_TRIANGLE_BOUNDARY    = 2,
    DXGI_GRAPHICS_PREEMPTION_PIXEL_BOUNDARY       = 3,
    DXGI_GRAPHICS_PREEMPTION_INSTRUCTION_BOUNDARY = 4
};

enum DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS
{
    DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAG_FULLSCREEN       = 1,
    DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAG_WINDOWED         = 2,
    DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAG_CURSOR_STRETCHED = 4
};

enum DXGI_HDR_METADATA_TYPE
{
    DXGI_HDR_METADATA_TYPE_NONE      = 0x0,
    DXGI_HDR_METADATA_TYPE_HDR10     = 0x1,
    DXGI_HDR_METADATA_TYPE_HDR10PLUS = 0x2
};

enum DXGI_MEMORY_SEGMENT_GROUP
{
    DXGI_MEMORY_SEGMENT_GROUP_LOCAL     = 0,
    DXGI_MEMORY_SEGMENT_GROUP_NON_LOCAL = 1
};

enum DXGI_MODE_ROTATION
{
    DXGI_MODE_ROTATION_UNSPECIFIED = 0,
    DXGI_MODE_ROTATION_IDENTITY    = 1,
    DXGI_MODE_ROTATION_ROTATE90    = 2,
    DXGI_MODE_ROTATION_ROTATE180   = 3,
    DXGI_MODE_ROTATION_ROTATE270   = 4
};

enum DXGI_MODE_SCALING
{
    DXGI_MODE_SCALING_UNSPECIFIED = 0,
    DXGI_MODE_SCALING_CENTERED    = 1,
    DXGI_MODE_SCALING_STRETCHED   = 2
};

enum DXGI_MODE_SCANLINE_ORDER
{
    DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED       = 0,
    DXGI_MODE_SCANLINE_ORDER_PROGRESSIVE       = 1,
    DXGI_MODE_SCANLINE_ORDER_UPPER_FIELD_FIRST = 2,
    DXGI_MODE_SCANLINE_ORDER_LOWER_FIELD_FIRST = 3
};

enum DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS
{
    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAG_NOMINAL_RANGE = 0x1,
    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAG_BT709         = 0x2,
    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAG_xvYCC         = 0x4
};

enum DXGI_OFFER_RESOURCE_FLAGS
{
    DXGI_OFFER_RESOURCE_FLAG_ALLOW_DECOMMIT = 0x1
};

enum DXGI_OFFER_RESOURCE_PRIORITY
{
    DXGI_OFFER_RESOURCE_PRIORITY_LOW = 1,
    DXGI_OFFER_RESOURCE_PRIORITY_NORMAL,
    DXGI_OFFER_RESOURCE_PRIORITY_HIGH
};

enum DXGI_OUTDUPL_FLAG
{
    DXGI_OUTDUPL_COMPOSITED_UI_CAPTURE_ONLY = 0x1
};

enum DXGI_OUTDUPL_POINTER_SHAPE_TYPE
{
    DXGI_OUTDUPL_POINTER_SHAPE_TYPE_MONOCHROME   = 0x1,
    DXGI_OUTDUPL_POINTER_SHAPE_TYPE_COLOR        = 0x2,
    DXGI_OUTDUPL_POINTER_SHAPE_TYPE_MASKED_COLOR = 0x4
};

enum DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAG
{
    DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAG_PRESENT = 0x1
};

enum DXGI_OVERLAY_SUPPORT_FLAG
{
    DXGI_OVERLAY_SUPPORT_FLAG_DIRECT  = 0x1,
    DXGI_OVERLAY_SUPPORT_FLAG_SCALING = 0x2
};

enum DXGI_RECLAIM_RESOURCE_RESULTS
{
    DXGI_RECLAIM_RESOURCE_RESULT_OK            = 0x0,
    DXGI_RECLAIM_RESOURCE_RESULT_DISCARDED     = 0x1,
    DXGI_RECLAIM_RESOURCE_RESULT_NOT_COMMITTED = 0x2
};

enum DXGI_RESIDENCY
{
    DXGI_RESIDENCY_FULLY_RESIDENT            = 1,
    DXGI_RESIDENCY_RESIDENT_IN_SHARED_MEMORY = 2,
    DXGI_RESIDENCY_EVICTED_TO_DISK           = 3
};

enum DXGI_SCALING
{
    DXGI_SCALING_STRETCH              = 0,
    DXGI_SCALING_NONE                 = 1,
    DXGI_SCALING_ASPECT_RATIO_STRETCH = 2
};

enum DXGI_SWAP_CHAIN_FLAG
{
    DXGI_SWAP_CHAIN_FLAG_NONPREROTATED                          = 1,
    DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH                      = 2,
    DXGI_SWAP_CHAIN_FLAG_GDI_COMPATIBLE                         = 4,
    DXGI_SWAP_CHAIN_FLAG_RESTRICTED_CONTENT                     = 8,
    DXGI_SWAP_CHAIN_FLAG_RESTRICT_SHARED_RESOURCE_DRIVER        = 16,
    DXGI_SWAP_CHAIN_FLAG_DISPLAY_ONLY                           = 32,
    DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT          = 64,
    DXGI_SWAP_CHAIN_FLAG_FOREGROUND_LAYER                       = 128,
    DXGI_SWAP_CHAIN_FLAG_FULLSCREEN_VIDEO                       = 256,
    DXGI_SWAP_CHAIN_FLAG_YUV_VIDEO                              = 512,
    DXGI_SWAP_CHAIN_FLAG_HW_PROTECTED                           = 1024,
    DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING                          = 2048,
    DXGI_SWAP_CHAIN_FLAG_RESTRICTED_TO_ALL_HOLOGRAPHIC_DISPLAYS = 4096
};

enum DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG
{
    DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG_PRESENT         = 0x1,
    DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG_OVERLAY_PRESENT = 0x2
};

enum DXGI_SWAP_EFFECT
{
    DXGI_SWAP_EFFECT_DISCARD         = 0,
    DXGI_SWAP_EFFECT_SEQUENTIAL      = 1,
    DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL = 3,
    DXGI_SWAP_EFFECT_FLIP_DISCARD    = 4
};

#define DXGI_CPU_ACCESS_NONE (0)
#define DXGI_CPU_ACCESS_DYNAMIC (1)
#define DXGI_CPU_ACCESS_READ_WRITE (2)
#define DXGI_CPU_ACCESS_SCRATCH (3)
#define DXGI_CPU_ACCESS_FIELD 15
#define DXGI_USAGE_SHADER_INPUT (1L << (0 + 4))
#define DXGI_USAGE_RENDER_TARGET_OUTPUT (1L << (1 + 4))
#define DXGI_USAGE_BACK_BUFFER (1L << (2 + 4))
#define DXGI_USAGE_SHARED (1L << (3 + 4))
#define DXGI_USAGE_READ_ONLY (1L << (4 + 4))
#define DXGI_USAGE_DISCARD_ON_PRESENT (1L << (5 + 4))
#define DXGI_USAGE_UNORDERED_ACCESS (1L << (6 + 4))

// Basic Types

struct POINT
{
    LONG x;
    LONG y;
};

struct RECT
{
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
};

// DXGI Types

struct DXGI_FRAME_STATISTICS
{
    UINT          PresentCount;
    UINT          PresentRefreshCount;
    UINT          SyncRefreshCount;
    LARGE_INTEGER SyncQPCTime;
    LARGE_INTEGER SyncGPUTime;
};

struct DXGI_MAPPED_RECT
{
    INT   Pitch;
    BYTE* pBits;
};

struct DXGI_ADAPTER_DESC
{
    WCHAR  Description[128];
    UINT   VendorId;
    UINT   DeviceId;
    UINT   SubSysId;
    UINT   Revision;
    SIZE_T DedicatedVideoMemory;
    SIZE_T DedicatedSystemMemory;
    SIZE_T SharedSystemMemory;
    LUID   AdapterLuid;
};

struct DXGI_ADAPTER_DESC1
{
    WCHAR  Description[128];
    UINT   VendorId;
    UINT   DeviceId;
    UINT   SubSysId;
    UINT   Revision;
    SIZE_T DedicatedVideoMemory;
    SIZE_T DedicatedSystemMemory;
    SIZE_T SharedSystemMemory;
    LUID   AdapterLuid;
    UINT   Flags;
};

struct DXGI_OUTPUT_DESC
{
    wchar_t            DeviceName[32];
    RECT               DesktopCoordinates;
    BOOL               AttachedToDesktop;
    DXGI_MODE_ROTATION Rotation;
    HMONITOR           Monitor;
};

struct DXGI_OUTPUT_DESC1
{
    WCHAR                 DeviceName[32];
    RECT                  DesktopCoordinates;
    BOOL                  AttachedToDesktop;
    DXGI_MODE_ROTATION    Rotation;
    HMONITOR              Monitor;
    UINT                  BitsPerColor;
    DXGI_COLOR_SPACE_TYPE ColorSpace;
    FLOAT                 RedPrimary[2];
    FLOAT                 GreenPrimary[2];
    FLOAT                 BluePrimary[2];
    FLOAT                 WhitePoint[2];
    FLOAT                 MinLuminance;
    FLOAT                 MaxLuminance;
    FLOAT                 MaxFullFrameLuminance;
};

struct DXGI_SHARED_RESOURCE
{
    HANDLE Handle;
};

struct DXGI_SAMPLE_DESC
{
    UINT Count;
    UINT Quality;
};

struct DXGI_SURFACE_DESC
{
    UINT             Width;
    UINT             Height;
    DXGI_FORMAT      Format;
    DXGI_SAMPLE_DESC SampleDesc;
};

struct DXGI_RATIONAL
{
    UINT Numerator;
    UINT Denominator;
};

struct DXGI_MODE_DESC
{
    UINT                     Width;
    UINT                     Height;
    DXGI_RATIONAL            RefreshRate;
    DXGI_FORMAT              Format;
    DXGI_MODE_SCANLINE_ORDER ScanlineOrdering;
    DXGI_MODE_SCALING        Scaling;
};

struct DXGI_MODE_DESC1
{
    UINT                     Width;
    UINT                     Height;
    DXGI_RATIONAL            RefreshRate;
    DXGI_FORMAT              Format;
    DXGI_MODE_SCANLINE_ORDER ScanlineOrdering;
    DXGI_MODE_SCALING        Scaling;
    BOOL                     Stereo;
};

struct DXGI_SWAP_CHAIN_DESC
{
    DXGI_MODE_DESC   BufferDesc;
    DXGI_SAMPLE_DESC SampleDesc;
    DXGI_USAGE       BufferUsage;
    UINT             BufferCount;
    HWND             OutputWindow;
    BOOL             Windowed;
    DXGI_SWAP_EFFECT SwapEffect;
    UINT             Flags;
};

struct DXGI_SWAP_CHAIN_DESC1
{
    UINT             Width;
    UINT             Height;
    DXGI_FORMAT      Format;
    BOOL             Stereo;
    DXGI_SAMPLE_DESC SampleDesc;
    DXGI_USAGE       BufferUsage;
    UINT             BufferCount;
    DXGI_SCALING     Scaling;
    DXGI_SWAP_EFFECT SwapEffect;
    DXGI_ALPHA_MODE  AlphaMode;
    UINT             Flags;
};

struct DXGI_ADAPTER_DESC2
{
    WCHAR                                Description[128];
    UINT                                 VendorId;
    UINT                                 DeviceId;
    UINT                                 SubSysId;
    UINT                                 Revision;
    SIZE_T                               DedicatedVideoMemory;
    SIZE_T                               DedicatedSystemMemory;
    SIZE_T                               SharedSystemMemory;
    LUID                                 AdapterLuid;
    UINT                                 Flags;
    DXGI_GRAPHICS_PREEMPTION_GRANULARITY GraphicsPreemptionGranularity;
    DXGI_COMPUTE_PREEMPTION_GRANULARITY  ComputePreemptionGranularity;
};

struct DXGI_ADAPTER_DESC3
{
    WCHAR                                Description[128];
    UINT                                 VendorId;
    UINT                                 DeviceId;
    UINT                                 SubSysId;
    UINT                                 Revision;
    SIZE_T                               DedicatedVideoMemory;
    SIZE_T                               DedicatedSystemMemory;
    SIZE_T                               SharedSystemMemory;
    LUID                                 AdapterLuid;
    DXGI_ADAPTER_FLAG3                   Flags;
    DXGI_GRAPHICS_PREEMPTION_GRANULARITY GraphicsPreemptionGranularity;
    DXGI_COMPUTE_PREEMPTION_GRANULARITY  ComputePreemptionGranularity;
};

struct DXGI_DISPLAY_COLOR_SPACE
{
    FLOAT PrimaryCoordinates[8][2];
    FLOAT WhitePoints[16][2];
};

struct DXGI_OUTDUPL_MOVE_RECT
{
    POINT SourcePoint;
    RECT  DestinationRect;
};

struct DXGI_OUTDUPL_DESC
{
    DXGI_MODE_DESC     ModeDesc;
    DXGI_MODE_ROTATION Rotation;
    BOOL               DesktopImageInSystemMemory;
};

struct DXGI_OUTDUPL_POINTER_POSITION
{
    POINT Position;
    BOOL  Visible;
};

struct DXGI_OUTDUPL_POINTER_SHAPE_INFO
{
    UINT  Type;
    UINT  Width;
    UINT  Height;
    UINT  Pitch;
    POINT HotSpot;
};

struct DXGI_OUTDUPL_FRAME_INFO
{
    LARGE_INTEGER                 LastPresentTime;
    LARGE_INTEGER                 LastMouseUpdateTime;
    UINT                          AccumulatedFrames;
    BOOL                          RectsCoalesced;
    BOOL                          ProtectedContentMaskedOut;
    DXGI_OUTDUPL_POINTER_POSITION PointerPosition;
    UINT                          TotalMetadataBufferSize;
    UINT                          PointerShapeBufferSize;
};

struct DXGI_SWAP_CHAIN_FULLSCREEN_DESC
{
    DXGI_RATIONAL            RefreshRate;
    DXGI_MODE_SCANLINE_ORDER ScanlineOrdering;
    DXGI_MODE_SCALING        Scaling;
    BOOL                     Windowed;
};

struct DXGI_PRESENT_PARAMETERS
{
    UINT   DirtyRectsCount;
    RECT*  pDirtyRects;
    RECT*  pScrollRect;
    POINT* pScrollOffset;
};

struct DXGI_DECODE_SWAP_CHAIN_DESC
{
    UINT Flags;
};

struct DXGI_FRAME_STATISTICS_MEDIA
{
    UINT                         PresentCount;
    UINT                         PresentRefreshCount;
    UINT                         SyncRefreshCount;
    LARGE_INTEGER                SyncQPCTime;
    LARGE_INTEGER                SyncGPUTime;
    DXGI_FRAME_PRESENTATION_MODE CompositionMode;
    UINT                         ApprovedPresentDuration;
};

struct DXGI_QUERY_VIDEO_MEMORY_INFO
{
    UINT64 Budget;
    UINT64 CurrentUsage;
    UINT64 AvailableForReservation;
    UINT64 CurrentReservation;
};

struct DXGI_HDR_METADATA_HDR10
{
    UINT16 RedPrimary[2];
    UINT16 GreenPrimary[2];
    UINT16 BluePrimary[2];
    UINT16 WhitePoint[2];
    UINT   MaxMasteringLuminance;
    UINT   MinMasteringLuminance;
    UINT16 MaxContentLightLevel;
    UINT16 MaxFrameAverageLightLevel;
};

struct DXGI_HDR_METADATA_HDR10PLUS
{
    UINT8 Data[72];
};

struct DXGI_RGB
{
    FLOAT Red;
    FLOAT Green;
    FLOAT Blue;
};

struct DXGI_GAMMA_CONTROL
{
    DXGI_RGB Scale;
    DXGI_RGB Offset;
    DXGI_RGB GammaCurve[1025];
};

struct DXGI_GAMMA_CONTROL_CAPABILITIES
{
    BOOL  ScaleAndOffsetSupported;
    FLOAT MaxConvertedValue;
    FLOAT MinConvertedValue;
    UINT  NumGammaControlPoints;
    FLOAT ControlPointPositions[1025];
};

struct DXGI_JPEG_DC_HUFFMAN_TABLE
{
    BYTE CodeCounts[12];
    BYTE CodeValues[12];
};

struct DXGI_JPEG_AC_HUFFMAN_TABLE
{
    BYTE CodeCounts[16];
    BYTE CodeValues[162];
};

struct DXGI_JPEG_QUANTIZATION_TABLE
{
    BYTE Elements[64];
};

struct DXGI_MATRIX_3X2_F
{
    FLOAT _11;
    FLOAT _12;
    FLOAT _21;
    FLOAT _22;
    FLOAT _31;
    FLOAT _32;
};

typedef RECT                tagRECT;
typedef POINT               tagPOINT;
typedef SECURITY_ATTRIBUTES _SECURITY_ATTRIBUTES;

enum D3D_CBUFFER_TYPE
{
    D3D_CT_CBUFFER = 0,
    D3D_CT_TBUFFER,
    D3D_CT_INTERFACE_POINTERS,
    D3D_CT_RESOURCE_BIND_INFO,
    D3D10_CT_CBUFFER,
    D3D10_CT_TBUFFER,
    D3D11_CT_CBUFFER,
    D3D11_CT_TBUFFER,
    D3D11_CT_INTERFACE_POINTERS,
    D3D11_CT_RESOURCE_BIND_INFO
};

enum D3D_DRIVER_TYPE
{
    D3D_DRIVER_TYPE_UNKNOWN = 0,
    D3D_DRIVER_TYPE_HARDWARE,
    D3D_DRIVER_TYPE_REFERENCE,
    D3D_DRIVER_TYPE_NULL,
    D3D_DRIVER_TYPE_SOFTWARE,
    D3D_DRIVER_TYPE_WARP
};

enum D3D_FEATURE_LEVEL
{
    D3D_FEATURE_LEVEL_1_0_CORE = 0x1000,
    D3D_FEATURE_LEVEL_9_1      = 0x9100,
    D3D_FEATURE_LEVEL_9_2      = 0x9200,
    D3D_FEATURE_LEVEL_9_3      = 0x9300,
    D3D_FEATURE_LEVEL_10_0     = 0xa000,
    D3D_FEATURE_LEVEL_10_1     = 0xa100,
    D3D_FEATURE_LEVEL_11_0     = 0xb000,
    D3D_FEATURE_LEVEL_11_1     = 0xb100,
    D3D_FEATURE_LEVEL_12_0     = 0xc000,
    D3D_FEATURE_LEVEL_12_1     = 0xc100,
    D3D_FEATURE_LEVEL_12_2     = 0xc200
};

enum D3D_FORMAT_COMPONENT_NAME
{
    D3DFCN_R = -4,
    D3DFCN_G = -3,
    D3DFCN_B = -2,
    D3DFCN_A = -1,
    D3DFCN_D = 0,
    D3DFCN_S = 1,
    D3DFCN_X = 2
};

enum D3D_FORMAT_COMPONENT_INTERPRETATION
{
    D3DFCI_TYPELESS         = 0,
    D3DFCI_FLOAT            = -4,
    D3DFCI_SNORM            = -3,
    D3DFCI_UNORM            = -2,
    D3DFCI_SINT             = -1,
    D3DFCI_UINT             = 1,
    D3DFCI_UNORM_SRGB       = 2,
    D3DFCI_BIASED_FIXED_2_8 = 3
};

enum D3D_FORMAT_LAYOUT
{
    D3DFL_STANDARD = 0,
    D3DFL_CUSTOM   = -1
};

enum D3D_FORMAT_TYPE_LEVEL
{
    D3DFTL_NO_TYPE      = 0,
    D3DFTL_PARTIAL_TYPE = -2,
    D3DFTL_FULL_TYPE    = -1
};
enum D3D_INCLUDE_TYPE
{
    D3D_INCLUDE_LOCAL = 0,
    D3D_INCLUDE_SYSTEM,
    D3D10_INCLUDE_LOCAL,
    D3D10_INCLUDE_SYSTEM,
    D3D_INCLUDE_FORCE_DWORD = 0x7fffffff
};

enum D3D_INTERPOLATION_MODE
{
    D3D_INTERPOLATION_UNDEFINED                     = 0,
    D3D_INTERPOLATION_CONSTANT                      = 1,
    D3D_INTERPOLATION_LINEAR                        = 2,
    D3D_INTERPOLATION_LINEAR_CENTROID               = 3,
    D3D_INTERPOLATION_LINEAR_NOPERSPECTIVE          = 4,
    D3D_INTERPOLATION_LINEAR_NOPERSPECTIVE_CENTROID = 5,
    D3D_INTERPOLATION_LINEAR_SAMPLE                 = 6,
    D3D_INTERPOLATION_LINEAR_NOPERSPECTIVE_SAMPLE   = 7
};

enum D3D_MIN_PRECISION
{
    D3D_MIN_PRECISION_DEFAULT   = 0,
    D3D_MIN_PRECISION_FLOAT_16  = 1,
    D3D_MIN_PRECISION_FLOAT_2_8 = 2,
    D3D_MIN_PRECISION_RESERVED  = 3,
    D3D_MIN_PRECISION_SINT_16   = 4,
    D3D_MIN_PRECISION_UINT_16   = 5,
    D3D_MIN_PRECISION_ANY_16    = 0xf0,
    D3D_MIN_PRECISION_ANY_10    = 0xf1
};

enum D3D_NAME
{
    D3D_NAME_UNDEFINED                     = 0,
    D3D_NAME_POSITION                      = 1,
    D3D_NAME_CLIP_DISTANCE                 = 2,
    D3D_NAME_CULL_DISTANCE                 = 3,
    D3D_NAME_RENDER_TARGET_ARRAY_INDEX     = 4,
    D3D_NAME_VIEWPORT_ARRAY_INDEX          = 5,
    D3D_NAME_VERTEX_ID                     = 6,
    D3D_NAME_PRIMITIVE_ID                  = 7,
    D3D_NAME_INSTANCE_ID                   = 8,
    D3D_NAME_IS_FRONT_FACE                 = 9,
    D3D_NAME_SAMPLE_INDEX                  = 10,
    D3D_NAME_FINAL_QUAD_EDGE_TESSFACTOR    = 11,
    D3D_NAME_FINAL_QUAD_INSIDE_TESSFACTOR  = 12,
    D3D_NAME_FINAL_TRI_EDGE_TESSFACTOR     = 13,
    D3D_NAME_FINAL_TRI_INSIDE_TESSFACTOR   = 14,
    D3D_NAME_FINAL_LINE_DETAIL_TESSFACTOR  = 15,
    D3D_NAME_FINAL_LINE_DENSITY_TESSFACTOR = 16,
    D3D_NAME_BARYCENTRICS                  = 23,
    D3D_NAME_SHADINGRATE,
    D3D_NAME_CULLPRIMITIVE,
    D3D_NAME_TARGET              = 64,
    D3D_NAME_DEPTH               = 65,
    D3D_NAME_COVERAGE            = 66,
    D3D_NAME_DEPTH_GREATER_EQUAL = 67,
    D3D_NAME_DEPTH_LESS_EQUAL    = 68,
    D3D_NAME_STENCIL_REF         = 69,
    D3D_NAME_INNER_COVERAGE      = 70,
    D3D10_NAME_UNDEFINED,
    D3D10_NAME_POSITION,
    D3D10_NAME_CLIP_DISTANCE,
    D3D10_NAME_CULL_DISTANCE,
    D3D10_NAME_RENDER_TARGET_ARRAY_INDEX,
    D3D10_NAME_VIEWPORT_ARRAY_INDEX,
    D3D10_NAME_VERTEX_ID,
    D3D10_NAME_PRIMITIVE_ID,
    D3D10_NAME_INSTANCE_ID,
    D3D10_NAME_IS_FRONT_FACE,
    D3D10_NAME_SAMPLE_INDEX,
    D3D10_NAME_TARGET,
    D3D10_NAME_DEPTH,
    D3D10_NAME_COVERAGE,
    D3D11_NAME_FINAL_QUAD_EDGE_TESSFACTOR,
    D3D11_NAME_FINAL_QUAD_INSIDE_TESSFACTOR,
    D3D11_NAME_FINAL_TRI_EDGE_TESSFACTOR,
    D3D11_NAME_FINAL_TRI_INSIDE_TESSFACTOR,
    D3D11_NAME_FINAL_LINE_DETAIL_TESSFACTOR,
    D3D11_NAME_FINAL_LINE_DENSITY_TESSFACTOR,
    D3D11_NAME_DEPTH_GREATER_EQUAL,
    D3D11_NAME_DEPTH_LESS_EQUAL,
    D3D11_NAME_STENCIL_REF,
    D3D11_NAME_INNER_COVERAGE,
    D3D12_NAME_BARYCENTRICS,
    D3D12_NAME_SHADINGRATE,
    D3D12_NAME_CULLPRIMITIVE
};

enum D3D_PARAMETER_FLAGS
{
    D3D_PF_NONE        = 0,
    D3D_PF_IN          = 0x1,
    D3D_PF_OUT         = 0x2,
    D3D_PF_FORCE_DWORD = 0x7fffffff
};

enum D3D_PRIMITIVE
{
    D3D_PRIMITIVE_UNDEFINED              = 0,
    D3D_PRIMITIVE_POINT                  = 1,
    D3D_PRIMITIVE_LINE                   = 2,
    D3D_PRIMITIVE_TRIANGLE               = 3,
    D3D_PRIMITIVE_LINE_ADJ               = 6,
    D3D_PRIMITIVE_TRIANGLE_ADJ           = 7,
    D3D_PRIMITIVE_1_CONTROL_POINT_PATCH  = 8,
    D3D_PRIMITIVE_2_CONTROL_POINT_PATCH  = 9,
    D3D_PRIMITIVE_3_CONTROL_POINT_PATCH  = 10,
    D3D_PRIMITIVE_4_CONTROL_POINT_PATCH  = 11,
    D3D_PRIMITIVE_5_CONTROL_POINT_PATCH  = 12,
    D3D_PRIMITIVE_6_CONTROL_POINT_PATCH  = 13,
    D3D_PRIMITIVE_7_CONTROL_POINT_PATCH  = 14,
    D3D_PRIMITIVE_8_CONTROL_POINT_PATCH  = 15,
    D3D_PRIMITIVE_9_CONTROL_POINT_PATCH  = 16,
    D3D_PRIMITIVE_10_CONTROL_POINT_PATCH = 17,
    D3D_PRIMITIVE_11_CONTROL_POINT_PATCH = 18,
    D3D_PRIMITIVE_12_CONTROL_POINT_PATCH = 19,
    D3D_PRIMITIVE_13_CONTROL_POINT_PATCH = 20,
    D3D_PRIMITIVE_14_CONTROL_POINT_PATCH = 21,
    D3D_PRIMITIVE_15_CONTROL_POINT_PATCH = 22,
    D3D_PRIMITIVE_16_CONTROL_POINT_PATCH = 23,
    D3D_PRIMITIVE_17_CONTROL_POINT_PATCH = 24,
    D3D_PRIMITIVE_18_CONTROL_POINT_PATCH = 25,
    D3D_PRIMITIVE_19_CONTROL_POINT_PATCH = 26,
    D3D_PRIMITIVE_20_CONTROL_POINT_PATCH = 27,
    D3D_PRIMITIVE_21_CONTROL_POINT_PATCH = 28,
    D3D_PRIMITIVE_22_CONTROL_POINT_PATCH = 29,
    D3D_PRIMITIVE_23_CONTROL_POINT_PATCH = 30,
    D3D_PRIMITIVE_24_CONTROL_POINT_PATCH = 31,
    D3D_PRIMITIVE_25_CONTROL_POINT_PATCH = 32,
    D3D_PRIMITIVE_26_CONTROL_POINT_PATCH = 33,
    D3D_PRIMITIVE_27_CONTROL_POINT_PATCH = 34,
    D3D_PRIMITIVE_28_CONTROL_POINT_PATCH = 35,
    D3D_PRIMITIVE_29_CONTROL_POINT_PATCH = 36,
    D3D_PRIMITIVE_30_CONTROL_POINT_PATCH = 37,
    D3D_PRIMITIVE_31_CONTROL_POINT_PATCH = 38,
    D3D_PRIMITIVE_32_CONTROL_POINT_PATCH = 39,
    D3D10_PRIMITIVE_UNDEFINED,
    D3D10_PRIMITIVE_POINT,
    D3D10_PRIMITIVE_LINE,
    D3D10_PRIMITIVE_TRIANGLE,
    D3D10_PRIMITIVE_LINE_ADJ,
    D3D10_PRIMITIVE_TRIANGLE_ADJ,
    D3D11_PRIMITIVE_UNDEFINED,
    D3D11_PRIMITIVE_POINT,
    D3D11_PRIMITIVE_LINE,
    D3D11_PRIMITIVE_TRIANGLE,
    D3D11_PRIMITIVE_LINE_ADJ,
    D3D11_PRIMITIVE_TRIANGLE_ADJ,
    D3D11_PRIMITIVE_1_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_2_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_3_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_4_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_5_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_6_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_7_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_8_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_9_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_10_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_11_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_12_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_13_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_14_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_15_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_16_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_17_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_18_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_19_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_20_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_21_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_22_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_23_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_24_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_25_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_26_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_27_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_28_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_29_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_30_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_31_CONTROL_POINT_PATCH,
    D3D11_PRIMITIVE_32_CONTROL_POINT_PATCH
};

enum D3D_PRIMITIVE_TOPOLOGY
{
    D3D_PRIMITIVE_TOPOLOGY_UNDEFINED     = 0,
    D3D_PRIMITIVE_TOPOLOGY_POINTLIST     = 1,
    D3D_PRIMITIVE_TOPOLOGY_LINELIST      = 2,
    D3D_PRIMITIVE_TOPOLOGY_LINESTRIP     = 3,
    D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST  = 4,
    D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP = 5,
    D3D_PRIMITIVE_TOPOLOGY_TRIANGLEFAN,
    D3D_PRIMITIVE_TOPOLOGY_LINELIST_ADJ                 = 10,
    D3D_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ                = 11,
    D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ             = 12,
    D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ            = 13,
    D3D_PRIMITIVE_TOPOLOGY_1_CONTROL_POINT_PATCHLIST    = 33,
    D3D_PRIMITIVE_TOPOLOGY_2_CONTROL_POINT_PATCHLIST    = 34,
    D3D_PRIMITIVE_TOPOLOGY_3_CONTROL_POINT_PATCHLIST    = 35,
    D3D_PRIMITIVE_TOPOLOGY_4_CONTROL_POINT_PATCHLIST    = 36,
    D3D_PRIMITIVE_TOPOLOGY_5_CONTROL_POINT_PATCHLIST    = 37,
    D3D_PRIMITIVE_TOPOLOGY_6_CONTROL_POINT_PATCHLIST    = 38,
    D3D_PRIMITIVE_TOPOLOGY_7_CONTROL_POINT_PATCHLIST    = 39,
    D3D_PRIMITIVE_TOPOLOGY_8_CONTROL_POINT_PATCHLIST    = 40,
    D3D_PRIMITIVE_TOPOLOGY_9_CONTROL_POINT_PATCHLIST    = 41,
    D3D_PRIMITIVE_TOPOLOGY_10_CONTROL_POINT_PATCHLIST   = 42,
    D3D_PRIMITIVE_TOPOLOGY_11_CONTROL_POINT_PATCHLIST   = 43,
    D3D_PRIMITIVE_TOPOLOGY_12_CONTROL_POINT_PATCHLIST   = 44,
    D3D_PRIMITIVE_TOPOLOGY_13_CONTROL_POINT_PATCHLIST   = 45,
    D3D_PRIMITIVE_TOPOLOGY_14_CONTROL_POINT_PATCHLIST   = 46,
    D3D_PRIMITIVE_TOPOLOGY_15_CONTROL_POINT_PATCHLIST   = 47,
    D3D_PRIMITIVE_TOPOLOGY_16_CONTROL_POINT_PATCHLIST   = 48,
    D3D_PRIMITIVE_TOPOLOGY_17_CONTROL_POINT_PATCHLIST   = 49,
    D3D_PRIMITIVE_TOPOLOGY_18_CONTROL_POINT_PATCHLIST   = 50,
    D3D_PRIMITIVE_TOPOLOGY_19_CONTROL_POINT_PATCHLIST   = 51,
    D3D_PRIMITIVE_TOPOLOGY_20_CONTROL_POINT_PATCHLIST   = 52,
    D3D_PRIMITIVE_TOPOLOGY_21_CONTROL_POINT_PATCHLIST   = 53,
    D3D_PRIMITIVE_TOPOLOGY_22_CONTROL_POINT_PATCHLIST   = 54,
    D3D_PRIMITIVE_TOPOLOGY_23_CONTROL_POINT_PATCHLIST   = 55,
    D3D_PRIMITIVE_TOPOLOGY_24_CONTROL_POINT_PATCHLIST   = 56,
    D3D_PRIMITIVE_TOPOLOGY_25_CONTROL_POINT_PATCHLIST   = 57,
    D3D_PRIMITIVE_TOPOLOGY_26_CONTROL_POINT_PATCHLIST   = 58,
    D3D_PRIMITIVE_TOPOLOGY_27_CONTROL_POINT_PATCHLIST   = 59,
    D3D_PRIMITIVE_TOPOLOGY_28_CONTROL_POINT_PATCHLIST   = 60,
    D3D_PRIMITIVE_TOPOLOGY_29_CONTROL_POINT_PATCHLIST   = 61,
    D3D_PRIMITIVE_TOPOLOGY_30_CONTROL_POINT_PATCHLIST   = 62,
    D3D_PRIMITIVE_TOPOLOGY_31_CONTROL_POINT_PATCHLIST   = 63,
    D3D_PRIMITIVE_TOPOLOGY_32_CONTROL_POINT_PATCHLIST   = 64,
    D3D10_PRIMITIVE_TOPOLOGY_UNDEFINED                  = D3D_PRIMITIVE_TOPOLOGY_UNDEFINED,
    D3D10_PRIMITIVE_TOPOLOGY_POINTLIST                  = D3D_PRIMITIVE_TOPOLOGY_POINTLIST,
    D3D10_PRIMITIVE_TOPOLOGY_LINELIST                   = D3D_PRIMITIVE_TOPOLOGY_LINELIST,
    D3D10_PRIMITIVE_TOPOLOGY_LINESTRIP                  = D3D_PRIMITIVE_TOPOLOGY_LINESTRIP,
    D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST               = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
    D3D10_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP              = D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP,
    D3D10_PRIMITIVE_TOPOLOGY_LINELIST_ADJ               = D3D_PRIMITIVE_TOPOLOGY_LINELIST_ADJ,
    D3D10_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ              = D3D_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ,
    D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ           = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ,
    D3D10_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ          = D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ,
    D3D11_PRIMITIVE_TOPOLOGY_UNDEFINED                  = D3D_PRIMITIVE_TOPOLOGY_UNDEFINED,
    D3D11_PRIMITIVE_TOPOLOGY_POINTLIST                  = D3D_PRIMITIVE_TOPOLOGY_POINTLIST,
    D3D11_PRIMITIVE_TOPOLOGY_LINELIST                   = D3D_PRIMITIVE_TOPOLOGY_LINELIST,
    D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP                  = D3D_PRIMITIVE_TOPOLOGY_LINESTRIP,
    D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST               = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
    D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP              = D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP,
    D3D11_PRIMITIVE_TOPOLOGY_LINELIST_ADJ               = D3D_PRIMITIVE_TOPOLOGY_LINELIST_ADJ,
    D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ              = D3D_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ,
    D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ           = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ,
    D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ          = D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ,
    D3D11_PRIMITIVE_TOPOLOGY_1_CONTROL_POINT_PATCHLIST  = D3D_PRIMITIVE_TOPOLOGY_1_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_2_CONTROL_POINT_PATCHLIST  = D3D_PRIMITIVE_TOPOLOGY_2_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_3_CONTROL_POINT_PATCHLIST  = D3D_PRIMITIVE_TOPOLOGY_3_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_4_CONTROL_POINT_PATCHLIST  = D3D_PRIMITIVE_TOPOLOGY_4_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_5_CONTROL_POINT_PATCHLIST  = D3D_PRIMITIVE_TOPOLOGY_5_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_6_CONTROL_POINT_PATCHLIST  = D3D_PRIMITIVE_TOPOLOGY_6_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_7_CONTROL_POINT_PATCHLIST  = D3D_PRIMITIVE_TOPOLOGY_7_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_8_CONTROL_POINT_PATCHLIST  = D3D_PRIMITIVE_TOPOLOGY_8_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_9_CONTROL_POINT_PATCHLIST  = D3D_PRIMITIVE_TOPOLOGY_9_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_10_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_10_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_11_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_11_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_12_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_12_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_13_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_13_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_14_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_14_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_15_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_15_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_16_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_16_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_17_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_17_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_18_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_18_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_19_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_19_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_20_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_20_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_21_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_21_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_22_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_22_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_23_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_23_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_24_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_24_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_25_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_25_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_26_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_26_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_27_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_27_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_28_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_28_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_29_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_29_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_30_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_30_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_31_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_31_CONTROL_POINT_PATCHLIST,
    D3D11_PRIMITIVE_TOPOLOGY_32_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_32_CONTROL_POINT_PATCHLIST,
};

enum D3D_REGISTER_COMPONENT_TYPE
{
    D3D_REGISTER_COMPONENT_UNKNOWN = 0,
    D3D_REGISTER_COMPONENT_UINT32  = 1,
    D3D_REGISTER_COMPONENT_SINT32  = 2,
    D3D_REGISTER_COMPONENT_FLOAT32 = 3,
    D3D_REGISTER_COMPONENT_UINT16,
    D3D_REGISTER_COMPONENT_SINT16,
    D3D_REGISTER_COMPONENT_FLOAT16,
    D3D_REGISTER_COMPONENT_UINT64,
    D3D_REGISTER_COMPONENT_SINT64,
    D3D_REGISTER_COMPONENT_FLOAT64,
    D3D10_REGISTER_COMPONENT_UNKNOWN,
    D3D10_REGISTER_COMPONENT_UINT32,
    D3D10_REGISTER_COMPONENT_SINT32,
    D3D10_REGISTER_COMPONENT_FLOAT32,
    D3D10_REGISTER_COMPONENT_UINT16,
    D3D10_REGISTER_COMPONENT_SINT16,
    D3D10_REGISTER_COMPONENT_FLOAT16,
    D3D10_REGISTER_COMPONENT_UINT64,
    D3D10_REGISTER_COMPONENT_SINT64,
    D3D10_REGISTER_COMPONENT_FLOAT64
};

enum D3D_RESOURCE_RETURN_TYPE
{
    D3D_RETURN_TYPE_UNORM     = 1,
    D3D_RETURN_TYPE_SNORM     = 2,
    D3D_RETURN_TYPE_SINT      = 3,
    D3D_RETURN_TYPE_UINT      = 4,
    D3D_RETURN_TYPE_FLOAT     = 5,
    D3D_RETURN_TYPE_MIXED     = 6,
    D3D_RETURN_TYPE_DOUBLE    = 7,
    D3D_RETURN_TYPE_CONTINUED = 8,
    D3D10_RETURN_TYPE_UNORM,
    D3D10_RETURN_TYPE_SNORM,
    D3D10_RETURN_TYPE_SINT,
    D3D10_RETURN_TYPE_UINT,
    D3D10_RETURN_TYPE_FLOAT,
    D3D10_RETURN_TYPE_MIXED,
    D3D11_RETURN_TYPE_UNORM,
    D3D11_RETURN_TYPE_SNORM,
    D3D11_RETURN_TYPE_SINT,
    D3D11_RETURN_TYPE_UINT,
    D3D11_RETURN_TYPE_FLOAT,
    D3D11_RETURN_TYPE_MIXED,
    D3D11_RETURN_TYPE_DOUBLE,
    D3D11_RETURN_TYPE_CONTINUED
};

enum D3D_ROOT_SIGNATURE_VERSION
{
    D3D_ROOT_SIGNATURE_VERSION_1   = 0x1,
    D3D_ROOT_SIGNATURE_VERSION_1_0 = 0x1,
    D3D_ROOT_SIGNATURE_VERSION_1_1 = 0x2,
    D3D_ROOT_SIGNATURE_VERSION_1_2
};

enum D3D_SHADER_CBUFFER_FLAGS
{
    D3D_CBF_USERPACKED = 1,
    D3D10_CBF_USERPACKED,
    D3D_CBF_FORCE_DWORD = 0x7fffffff
};

enum D3D_SHADER_INPUT_FLAGS
{
    D3D_SIF_USERPACKED          = 0x1,
    D3D_SIF_COMPARISON_SAMPLER  = 0x2,
    D3D_SIF_TEXTURE_COMPONENT_0 = 0x4,
    D3D_SIF_TEXTURE_COMPONENT_1 = 0x8,
    D3D_SIF_TEXTURE_COMPONENTS  = 0xc,
    D3D_SIF_UNUSED              = 0x10,
    D3D10_SIF_USERPACKED,
    D3D10_SIF_COMPARISON_SAMPLER,
    D3D10_SIF_TEXTURE_COMPONENT_0,
    D3D10_SIF_TEXTURE_COMPONENT_1,
    D3D10_SIF_TEXTURE_COMPONENTS,
    D3D_SIF_FORCE_DWORD = 0x7fffffff
};

enum D3D_SHADER_INPUT_TYPE
{
    D3D_SIT_CBUFFER = 0,
    D3D_SIT_TBUFFER,
    D3D_SIT_TEXTURE,
    D3D_SIT_SAMPLER,
    D3D_SIT_UAV_RWTYPED,
    D3D_SIT_STRUCTURED,
    D3D_SIT_UAV_RWSTRUCTURED,
    D3D_SIT_BYTEADDRESS,
    D3D_SIT_UAV_RWBYTEADDRESS,
    D3D_SIT_UAV_APPEND_STRUCTURED,
    D3D_SIT_UAV_CONSUME_STRUCTURED,
    D3D_SIT_UAV_RWSTRUCTURED_WITH_COUNTER,
    D3D_SIT_RTACCELERATIONSTRUCTURE,
    D3D_SIT_UAV_FEEDBACKTEXTURE,
    D3D10_SIT_CBUFFER,
    D3D10_SIT_TBUFFER,
    D3D10_SIT_TEXTURE,
    D3D10_SIT_SAMPLER,
    D3D11_SIT_UAV_RWTYPED,
    D3D11_SIT_STRUCTURED,
    D3D11_SIT_UAV_RWSTRUCTURED,
    D3D11_SIT_BYTEADDRESS,
    D3D11_SIT_UAV_RWBYTEADDRESS,
    D3D11_SIT_UAV_APPEND_STRUCTURED,
    D3D11_SIT_UAV_CONSUME_STRUCTURED,
    D3D11_SIT_UAV_RWSTRUCTURED_WITH_COUNTER
};

enum D3D_SHADER_MODEL
{
    D3D_SHADER_MODEL_NONE,
    D3D_SHADER_MODEL_5_1 = 0x51,
    D3D_SHADER_MODEL_6_0 = 0x60,
    D3D_SHADER_MODEL_6_1 = 0x61,
    D3D_SHADER_MODEL_6_2 = 0x62,
    D3D_SHADER_MODEL_6_3 = 0x63,
    D3D_SHADER_MODEL_6_4 = 0x64,
    D3D_SHADER_MODEL_6_5 = 0x65,
    D3D_SHADER_MODEL_6_6 = 0x66,
    D3D_SHADER_MODEL_6_7 = 0x67,
    D3D_SHADER_MODEL_6_8,
    D3D_SHADER_MODEL_6_9,
    D3D_HIGHEST_SHADER_MODEL
};

enum D3D_SHADER_VARIABLE_CLASS
{
    D3D_SVC_SCALAR = 0,
    D3D_SVC_VECTOR,
    D3D_SVC_MATRIX_ROWS,
    D3D_SVC_MATRIX_COLUMNS,
    D3D_SVC_OBJECT,
    D3D_SVC_STRUCT,
    D3D_SVC_INTERFACE_CLASS,
    D3D_SVC_INTERFACE_POINTER,
    D3D10_SVC_SCALAR,
    D3D10_SVC_VECTOR,
    D3D10_SVC_MATRIX_ROWS,
    D3D10_SVC_MATRIX_COLUMNS,
    D3D10_SVC_OBJECT,
    D3D10_SVC_STRUCT,
    D3D11_SVC_INTERFACE_CLASS,
    D3D11_SVC_INTERFACE_POINTER,
    D3D_SVC_FORCE_DWORD = 0x7fffffff
};

enum D3D_SHADER_VARIABLE_FLAGS
{
    D3D_SVF_USERPACKED          = 1,
    D3D_SVF_USED                = 2,
    D3D_SVF_INTERFACE_POINTER   = 4,
    D3D_SVF_INTERFACE_PARAMETER = 8,
    D3D10_SVF_USERPACKED,
    D3D10_SVF_USED,
    D3D11_SVF_INTERFACE_POINTER,
    D3D11_SVF_INTERFACE_PARAMETER,
    D3D_SVF_FORCE_DWORD = 0x7fffffff
};

enum D3D_SHADER_VARIABLE_TYPE
{
    D3D_SVT_VOID                      = 0,
    D3D_SVT_BOOL                      = 1,
    D3D_SVT_INT                       = 2,
    D3D_SVT_FLOAT                     = 3,
    D3D_SVT_STRING                    = 4,
    D3D_SVT_TEXTURE                   = 5,
    D3D_SVT_TEXTURE1D                 = 6,
    D3D_SVT_TEXTURE2D                 = 7,
    D3D_SVT_TEXTURE3D                 = 8,
    D3D_SVT_TEXTURECUBE               = 9,
    D3D_SVT_SAMPLER                   = 10,
    D3D_SVT_SAMPLER1D                 = 11,
    D3D_SVT_SAMPLER2D                 = 12,
    D3D_SVT_SAMPLER3D                 = 13,
    D3D_SVT_SAMPLERCUBE               = 14,
    D3D_SVT_PIXELSHADER               = 15,
    D3D_SVT_VERTEXSHADER              = 16,
    D3D_SVT_PIXELFRAGMENT             = 17,
    D3D_SVT_VERTEXFRAGMENT            = 18,
    D3D_SVT_UINT                      = 19,
    D3D_SVT_UINT8                     = 20,
    D3D_SVT_GEOMETRYSHADER            = 21,
    D3D_SVT_RASTERIZER                = 22,
    D3D_SVT_DEPTHSTENCIL              = 23,
    D3D_SVT_BLEND                     = 24,
    D3D_SVT_BUFFER                    = 25,
    D3D_SVT_CBUFFER                   = 26,
    D3D_SVT_TBUFFER                   = 27,
    D3D_SVT_TEXTURE1DARRAY            = 28,
    D3D_SVT_TEXTURE2DARRAY            = 29,
    D3D_SVT_RENDERTARGETVIEW          = 30,
    D3D_SVT_DEPTHSTENCILVIEW          = 31,
    D3D_SVT_TEXTURE2DMS               = 32,
    D3D_SVT_TEXTURE2DMSARRAY          = 33,
    D3D_SVT_TEXTURECUBEARRAY          = 34,
    D3D_SVT_HULLSHADER                = 35,
    D3D_SVT_DOMAINSHADER              = 36,
    D3D_SVT_INTERFACE_POINTER         = 37,
    D3D_SVT_COMPUTESHADER             = 38,
    D3D_SVT_DOUBLE                    = 39,
    D3D_SVT_RWTEXTURE1D               = 40,
    D3D_SVT_RWTEXTURE1DARRAY          = 41,
    D3D_SVT_RWTEXTURE2D               = 42,
    D3D_SVT_RWTEXTURE2DARRAY          = 43,
    D3D_SVT_RWTEXTURE3D               = 44,
    D3D_SVT_RWBUFFER                  = 45,
    D3D_SVT_BYTEADDRESS_BUFFER        = 46,
    D3D_SVT_RWBYTEADDRESS_BUFFER      = 47,
    D3D_SVT_STRUCTURED_BUFFER         = 48,
    D3D_SVT_RWSTRUCTURED_BUFFER       = 49,
    D3D_SVT_APPEND_STRUCTURED_BUFFER  = 50,
    D3D_SVT_CONSUME_STRUCTURED_BUFFER = 51,
    D3D_SVT_MIN8FLOAT                 = 52,
    D3D_SVT_MIN10FLOAT                = 53,
    D3D_SVT_MIN16FLOAT                = 54,
    D3D_SVT_MIN12INT                  = 55,
    D3D_SVT_MIN16INT                  = 56,
    D3D_SVT_MIN16UINT                 = 57,
    D3D_SVT_INT16,
    D3D_SVT_UINT16,
    D3D_SVT_FLOAT16,
    D3D_SVT_INT64,
    D3D_SVT_UINT64,
    D3D10_SVT_VOID,
    D3D10_SVT_BOOL,
    D3D10_SVT_INT,
    D3D10_SVT_FLOAT,
    D3D10_SVT_STRING,
    D3D10_SVT_TEXTURE,
    D3D10_SVT_TEXTURE1D,
    D3D10_SVT_TEXTURE2D,
    D3D10_SVT_TEXTURE3D,
    D3D10_SVT_TEXTURECUBE,
    D3D10_SVT_SAMPLER,
    D3D10_SVT_SAMPLER1D,
    D3D10_SVT_SAMPLER2D,
    D3D10_SVT_SAMPLER3D,
    D3D10_SVT_SAMPLERCUBE,
    D3D10_SVT_PIXELSHADER,
    D3D10_SVT_VERTEXSHADER,
    D3D10_SVT_PIXELFRAGMENT,
    D3D10_SVT_VERTEXFRAGMENT,
    D3D10_SVT_UINT,
    D3D10_SVT_UINT8,
    D3D10_SVT_GEOMETRYSHADER,
    D3D10_SVT_RASTERIZER,
    D3D10_SVT_DEPTHSTENCIL,
    D3D10_SVT_BLEND,
    D3D10_SVT_BUFFER,
    D3D10_SVT_CBUFFER,
    D3D10_SVT_TBUFFER,
    D3D10_SVT_TEXTURE1DARRAY,
    D3D10_SVT_TEXTURE2DARRAY,
    D3D10_SVT_RENDERTARGETVIEW,
    D3D10_SVT_DEPTHSTENCILVIEW,
    D3D10_SVT_TEXTURE2DMS,
    D3D10_SVT_TEXTURE2DMSARRAY,
    D3D10_SVT_TEXTURECUBEARRAY,
    D3D11_SVT_HULLSHADER,
    D3D11_SVT_DOMAINSHADER,
    D3D11_SVT_INTERFACE_POINTER,
    D3D11_SVT_COMPUTESHADER,
    D3D11_SVT_DOUBLE,
    D3D11_SVT_RWTEXTURE1D,
    D3D11_SVT_RWTEXTURE1DARRAY,
    D3D11_SVT_RWTEXTURE2D,
    D3D11_SVT_RWTEXTURE2DARRAY,
    D3D11_SVT_RWTEXTURE3D,
    D3D11_SVT_RWBUFFER,
    D3D11_SVT_BYTEADDRESS_BUFFER,
    D3D11_SVT_RWBYTEADDRESS_BUFFER,
    D3D11_SVT_STRUCTURED_BUFFER,
    D3D11_SVT_RWSTRUCTURED_BUFFER,
    D3D11_SVT_APPEND_STRUCTURED_BUFFER,
    D3D11_SVT_CONSUME_STRUCTURED_BUFFER,
    D3D_SVT_FORCE_DWORD = 0x7fffffff
};

enum D3D_SRV_DIMENSION
{
    D3D_SRV_DIMENSION_UNKNOWN          = 0,
    D3D_SRV_DIMENSION_BUFFER           = 1,
    D3D_SRV_DIMENSION_TEXTURE1D        = 2,
    D3D_SRV_DIMENSION_TEXTURE1DARRAY   = 3,
    D3D_SRV_DIMENSION_TEXTURE2D        = 4,
    D3D_SRV_DIMENSION_TEXTURE2DARRAY   = 5,
    D3D_SRV_DIMENSION_TEXTURE2DMS      = 6,
    D3D_SRV_DIMENSION_TEXTURE2DMSARRAY = 7,
    D3D_SRV_DIMENSION_TEXTURE3D        = 8,
    D3D_SRV_DIMENSION_TEXTURECUBE      = 9,
    D3D_SRV_DIMENSION_TEXTURECUBEARRAY = 10,
    D3D_SRV_DIMENSION_BUFFEREX         = 11,
    D3D10_SRV_DIMENSION_UNKNOWN,
    D3D10_SRV_DIMENSION_BUFFER,
    D3D10_SRV_DIMENSION_TEXTURE1D,
    D3D10_SRV_DIMENSION_TEXTURE1DARRAY,
    D3D10_SRV_DIMENSION_TEXTURE2D,
    D3D10_SRV_DIMENSION_TEXTURE2DARRAY,
    D3D10_SRV_DIMENSION_TEXTURE2DMS,
    D3D10_SRV_DIMENSION_TEXTURE2DMSARRAY,
    D3D10_SRV_DIMENSION_TEXTURE3D,
    D3D10_SRV_DIMENSION_TEXTURECUBE,
    D3D10_1_SRV_DIMENSION_UNKNOWN,
    D3D10_1_SRV_DIMENSION_BUFFER,
    D3D10_1_SRV_DIMENSION_TEXTURE1D,
    D3D10_1_SRV_DIMENSION_TEXTURE1DARRAY,
    D3D10_1_SRV_DIMENSION_TEXTURE2D,
    D3D10_1_SRV_DIMENSION_TEXTURE2DARRAY,
    D3D10_1_SRV_DIMENSION_TEXTURE2DMS,
    D3D10_1_SRV_DIMENSION_TEXTURE2DMSARRAY,
    D3D10_1_SRV_DIMENSION_TEXTURE3D,
    D3D10_1_SRV_DIMENSION_TEXTURECUBE,
    D3D10_1_SRV_DIMENSION_TEXTURECUBEARRAY,
    D3D11_SRV_DIMENSION_UNKNOWN,
    D3D11_SRV_DIMENSION_BUFFER,
    D3D11_SRV_DIMENSION_TEXTURE1D,
    D3D11_SRV_DIMENSION_TEXTURE1DARRAY,
    D3D11_SRV_DIMENSION_TEXTURE2D,
    D3D11_SRV_DIMENSION_TEXTURE2DARRAY,
    D3D11_SRV_DIMENSION_TEXTURE2DMS,
    D3D11_SRV_DIMENSION_TEXTURE2DMSARRAY,
    D3D11_SRV_DIMENSION_TEXTURE3D,
    D3D11_SRV_DIMENSION_TEXTURECUBE,
    D3D11_SRV_DIMENSION_TEXTURECUBEARRAY,
    D3D11_SRV_DIMENSION_BUFFEREX
};

enum D3D_TESSELLATOR_DOMAIN
{
    D3D_TESSELLATOR_DOMAIN_UNDEFINED = 0,
    D3D_TESSELLATOR_DOMAIN_ISOLINE   = 1,
    D3D_TESSELLATOR_DOMAIN_TRI       = 2,
    D3D_TESSELLATOR_DOMAIN_QUAD      = 3,
    D3D11_TESSELLATOR_DOMAIN_UNDEFINED,
    D3D11_TESSELLATOR_DOMAIN_ISOLINE,
    D3D11_TESSELLATOR_DOMAIN_TRI,
    D3D11_TESSELLATOR_DOMAIN_QUAD
};

enum D3D_TESSELLATOR_OUTPUT_PRIMITIVE
{
    D3D_TESSELLATOR_OUTPUT_UNDEFINED    = 0,
    D3D_TESSELLATOR_OUTPUT_POINT        = 1,
    D3D_TESSELLATOR_OUTPUT_LINE         = 2,
    D3D_TESSELLATOR_OUTPUT_TRIANGLE_CW  = 3,
    D3D_TESSELLATOR_OUTPUT_TRIANGLE_CCW = 4,
    D3D11_TESSELLATOR_OUTPUT_UNDEFINED,
    D3D11_TESSELLATOR_OUTPUT_POINT,
    D3D11_TESSELLATOR_OUTPUT_LINE,
    D3D11_TESSELLATOR_OUTPUT_TRIANGLE_CW,
    D3D11_TESSELLATOR_OUTPUT_TRIANGLE_CCW
};

enum D3D_TESSELLATOR_PARTITIONING
{
    D3D_TESSELLATOR_PARTITIONING_UNDEFINED       = 0,
    D3D_TESSELLATOR_PARTITIONING_INTEGER         = 1,
    D3D_TESSELLATOR_PARTITIONING_POW2            = 2,
    D3D_TESSELLATOR_PARTITIONING_FRACTIONAL_ODD  = 3,
    D3D_TESSELLATOR_PARTITIONING_FRACTIONAL_EVEN = 4,
    D3D11_TESSELLATOR_PARTITIONING_UNDEFINED,
    D3D11_TESSELLATOR_PARTITIONING_INTEGER,
    D3D11_TESSELLATOR_PARTITIONING_POW2,
    D3D11_TESSELLATOR_PARTITIONING_FRACTIONAL_ODD,
    D3D11_TESSELLATOR_PARTITIONING_FRACTIONAL_EVEN
};

struct D3DCOLORVALUE
{
    FLOAT r;
    FLOAT g;
    FLOAT b;
    FLOAT a;
};

#if !defined(D3D11_SUPPORT)
typedef void* ID3D11Device;
typedef void* ID3D11Texture2D;

#endif

#if !defined(D3D12_SUPPORT)
typedef UINT64 D3D12_GPU_VIRTUAL_ADDRESS;
typedef RECT   D3D12_RECT;

DEFINE_GUID(CLSID_D3D12Debug, 0xf2352aeb, 0xdd84, 0x49fe, 0xb9, 0x7b, 0xa9, 0xdc, 0xfd, 0xcc, 0x1b, 0x4f);
DEFINE_GUID(CLSID_D3D12DeviceFactory, 0x114863bf, 0xc386, 0x4aee, 0xb3, 0x9d, 0x8f, 0x0b, 0xbb, 0x06, 0x29, 0x55);
DEFINE_GUID(
    CLSID_D3D12DeviceRemovedExtendedData, 0x4a75bbc4, 0x9ff4, 0x4ad8, 0x9f, 0x18, 0xab, 0xae, 0x84, 0xdc, 0x5f, 0xf2);
DEFINE_GUID(CLSID_D3D12DSRDeviceFactory, 0x7f9bdcac, 0xf629, 0x455e, 0xab, 0x13, 0xa8, 0x07, 0xfb, 0xe9, 0xab, 0xa4);
DEFINE_GUID(CLSID_D3D12SDKConfiguration, 0x7cda6aca, 0xa03e, 0x49c8, 0x94, 0x58, 0x03, 0x34, 0xd2, 0x0e, 0x07, 0xce);
DEFINE_GUID(CLSID_D3D12Tools, 0xe38216b1, 0x3c8c, 0x4833, 0xaa, 0x09, 0x0a, 0x06, 0xb6, 0x5d, 0x96, 0xc8);

DEFINE_GUID(IID_ID3D12CommandAllocator, 0x6102dee4, 0xaf59, 0x4b09, 0xb9, 0x99, 0xb4, 0x4d, 0x73, 0xf0, 0x9b, 0x24);
DEFINE_GUID(IID_ID3D12CommandList, 0x7116d91c, 0xe7e4, 0x47ce, 0xb8, 0xc6, 0xec, 0x81, 0x68, 0xf4, 0x37, 0xe5);
DEFINE_GUID(IID_ID3D12CommandQueue, 0x0ec870a6, 0x5d7e, 0x4c22, 0x8c, 0xfc, 0x5b, 0xaa, 0xe0, 0x76, 0x16, 0xed);
DEFINE_GUID(IID_ID3D12CommandSignature, 0xc36a797c, 0xec80, 0x4f0a, 0x89, 0x85, 0xa7, 0xb2, 0x47, 0x50, 0x82, 0xd1);
DEFINE_GUID(IID_ID3D12Debug, 0x344488b7, 0x6846, 0x474b, 0xb9, 0x89, 0xf0, 0x27, 0x44, 0x82, 0x45, 0xe0);
DEFINE_GUID(IID_ID3D12Debug1, 0xaffaa4ca, 0x63fe, 0x4d8e, 0xb8, 0xad, 0x15, 0x90, 0x00, 0xaf, 0x43, 0x04);
DEFINE_GUID(IID_ID3D12Debug2, 0x93a665c4, 0xa3b2, 0x4e5d, 0xb6, 0x92, 0xa2, 0x6a, 0xe1, 0x4e, 0x33, 0x74);
DEFINE_GUID(IID_ID3D12Debug3, 0x5cf4e58f, 0xf671, 0x4ff1, 0xa5, 0x42, 0x36, 0x86, 0xe3, 0xd1, 0x53, 0xd1);
DEFINE_GUID(IID_ID3D12Debug4, 0x014b816e, 0x9ec5, 0x4a2f, 0xa8, 0x45, 0xff, 0xbe, 0x44, 0x1c, 0xe1, 0x3a);
DEFINE_GUID(IID_ID3D12Debug5, 0x548d6b12, 0x09fa, 0x40e0, 0x90, 0x69, 0x5d, 0xcd, 0x58, 0x9a, 0x52, 0xc9);
DEFINE_GUID(IID_ID3D12Debug6, 0x82a816d6, 0x5d01, 0x4157, 0x97, 0xd0, 0x49, 0x75, 0x46, 0x3f, 0xd1, 0xed);
DEFINE_GUID(IID_ID3D12DebugCommandList, 0x09e0bf36, 0x54ac, 0x484f, 0x88, 0x47, 0x4b, 0xae, 0xea, 0xb6, 0x05, 0x3f);
DEFINE_GUID(IID_ID3D12DebugCommandList1, 0x102ca951, 0x311b, 0x4b01, 0xb1, 0x1f, 0xec, 0xb8, 0x3e, 0x06, 0x1b, 0x37);
DEFINE_GUID(IID_ID3D12DebugCommandList2, 0xaeb575cf, 0x4e06, 0x48be, 0xba, 0x3b, 0xc4, 0x50, 0xfc, 0x96, 0x65, 0x2e);
DEFINE_GUID(IID_ID3D12DebugCommandList3, 0x197d5e15, 0x4d37, 0x4d34, 0xaf, 0x78, 0x72, 0x4c, 0xd7, 0x0f, 0xdb, 0x1f);
DEFINE_GUID(IID_ID3D12DebugCommandQueue, 0x09e0bf36, 0x54ac, 0x484f, 0x88, 0x47, 0x4b, 0xae, 0xea, 0xb6, 0x05, 0x3a);
DEFINE_GUID(IID_ID3D12DebugCommandQueue1, 0x16be35a2, 0xbfd6, 0x49f2, 0xbc, 0xae, 0xea, 0xae, 0x4a, 0xff, 0x86, 0x2d);
DEFINE_GUID(IID_ID3D12DebugDevice, 0x3febd6dd, 0x4973, 0x4787, 0x81, 0x94, 0xe4, 0x5f, 0x9e, 0x28, 0x92, 0x3e);
DEFINE_GUID(IID_ID3D12DebugDevice1, 0xa9b71770, 0xd099, 0x4a65, 0xa6, 0x98, 0x3d, 0xee, 0x10, 0x02, 0x0f, 0x88);
DEFINE_GUID(IID_ID3D12DebugDevice2, 0x60eccbc1, 0x378d, 0x4df1, 0x89, 0x4c, 0xf8, 0xac, 0x5c, 0xe4, 0xd7, 0xdd);
DEFINE_GUID(IID_ID3D12DescriptorHeap, 0x8efb471d, 0x616c, 0x4f49, 0x90, 0xf7, 0x12, 0x7b, 0xb7, 0x63, 0xfa, 0x51);
DEFINE_GUID(IID_ID3D12Device, 0x189819f1, 0x1db6, 0x4b57, 0xbe, 0x54, 0x18, 0x21, 0x33, 0x9b, 0x85, 0xf7);
DEFINE_GUID(IID_ID3D12Device1, 0x77acce80, 0x638e, 0x4e65, 0x88, 0x95, 0xc1, 0xf2, 0x33, 0x86, 0x86, 0x3e);
DEFINE_GUID(IID_ID3D12Device2, 0x30baa41e, 0xb15b, 0x475c, 0xa0, 0xbb, 0x1a, 0xf5, 0xc5, 0xb6, 0x43, 0x28);
DEFINE_GUID(IID_ID3D12Device3, 0x81dadc15, 0x2bad, 0x4392, 0x93, 0xc5, 0x10, 0x13, 0x45, 0xc4, 0xaa, 0x98);
DEFINE_GUID(IID_ID3D12Device4, 0xe865df17, 0xa9ee, 0x46f9, 0xa4, 0x63, 0x30, 0x98, 0x31, 0x5a, 0xa2, 0xe5);
DEFINE_GUID(IID_ID3D12Device5, 0x8b4f173b, 0x2fea, 0x4b80, 0x8f, 0x58, 0x43, 0x07, 0x19, 0x1a, 0xb9, 0x5d);
DEFINE_GUID(IID_ID3D12Device6, 0xc70b221b, 0x40e4, 0x4a17, 0x89, 0xaf, 0x02, 0x5a, 0x07, 0x27, 0xa6, 0xdc);
DEFINE_GUID(IID_ID3D12Device7, 0x5c014b53, 0x68a1, 0x4b9b, 0x8b, 0xd1, 0xdd, 0x60, 0x46, 0xb9, 0x35, 0x8b);
DEFINE_GUID(IID_ID3D12Device8, 0x9218e6bb, 0xf944, 0x4f7e, 0xa7, 0x5c, 0xb1, 0xb2, 0xc7, 0xb7, 0x01, 0xf3);
DEFINE_GUID(IID_ID3D12Device9, 0x4c80e962, 0xf032, 0x4f60, 0xbc, 0x9e, 0xeb, 0xc2, 0xcf, 0xa1, 0xd8, 0x3c);
DEFINE_GUID(IID_ID3D12Device10, 0x517f8718, 0xaa66, 0x49f9, 0xb0, 0x2b, 0xa7, 0xab, 0x89, 0xc0, 0x60, 0x31);
DEFINE_GUID(IID_ID3D12Device11, 0x5405c344, 0xd457, 0x444e, 0xb4, 0xdd, 0x23, 0x66, 0xe4, 0x5a, 0xee, 0x39);
DEFINE_GUID(IID_ID3D12Device12, 0x5af5c532, 0x4c91, 0x4cd0, 0xb5, 0x41, 0x15, 0xa4, 0x05, 0x39, 0x5f, 0xc5);
DEFINE_GUID(IID_ID3D12Device13, 0x14eecffc, 0x4df8, 0x40f7, 0xa1, 0x18, 0x5c, 0x81, 0x6f, 0x45, 0x69, 0x5e);
DEFINE_GUID(IID_ID3D12DeviceChild, 0x905db94b, 0xa00c, 0x4140, 0x9d, 0xf5, 0x2b, 0x64, 0xca, 0x9e, 0xa3, 0x57);
DEFINE_GUID(IID_ID3D12DeviceConfiguration, 0x78dbf87b, 0xf766, 0x422b, 0xa6, 0x1c, 0xc8, 0xc4, 0x46, 0xbd, 0xb9, 0xad);
DEFINE_GUID(IID_ID3D12DeviceConfiguration1, 0xed342442, 0x6343, 0x4e16, 0xbb, 0x82, 0xa3, 0xa5, 0x77, 0x87, 0x4e, 0x56);
DEFINE_GUID(IID_ID3D12DeviceExperimental, 0x5f6e592d, 0xd895, 0x44c2, 0x8e, 0x4a, 0x88, 0xad, 0x49, 0x26, 0xd3, 0x23);
DEFINE_GUID(IID_ID3D12DeviceFactory, 0x61f307d3, 0xd34e, 0x4e7c, 0x83, 0x74, 0x3b, 0xa4, 0xde, 0x23, 0xcc, 0xcb);
DEFINE_GUID(
    IID_ID3D12DeviceRemovedExtendedData, 0x98931d33, 0x5ae8, 0x4791, 0xaa, 0x3c, 0x1a, 0x73, 0xa2, 0x93, 0x4e, 0x71);
DEFINE_GUID(
    IID_ID3D12DeviceRemovedExtendedData1, 0x9727a022, 0xcf1d, 0x4dda, 0x9e, 0xba, 0xef, 0xfa, 0x65, 0x3f, 0xc5, 0x06);
DEFINE_GUID(
    IID_ID3D12DeviceRemovedExtendedData2, 0x67fc5816, 0xe4ca, 0x4915, 0xbf, 0x18, 0x42, 0x54, 0x12, 0x72, 0xda, 0x54);
DEFINE_GUID(IID_ID3D12DeviceRemovedExtendedDataSettings,
            0x82BC481C,
            0x6B9B,
            0x4030,
            0xAE,
            0xDB,
            0x7E,
            0xE3,
            0xD1,
            0xDF,
            0x1E,
            0x63);
DEFINE_GUID(IID_ID3D12DeviceRemovedExtendedDataSettings1,
            0xDBD5AE51,
            0x3317,
            0x4F0A,
            0xAD,
            0xF9,
            0x1D,
            0x7C,
            0xED,
            0xCA,
            0xAE,
            0x0B);
DEFINE_GUID(IID_ID3D12DeviceRemovedExtendedDataSettings2,
            0x61552388,
            0x01ab,
            0x4008,
            0xa4,
            0x36,
            0x83,
            0xdb,
            0x18,
            0x95,
            0x66,
            0xea);
DEFINE_GUID(IID_ID3D12DSRDeviceFactory, 0x51ee7783, 0x6426, 0x4428, 0xb1, 0x82, 0x42, 0xf3, 0x54, 0x1f, 0xca, 0x71);
DEFINE_GUID(IID_ID3D12Fence, 0x0a753dcf, 0xc4d8, 0x4b91, 0xad, 0xf6, 0xbe, 0x5a, 0x60, 0xd9, 0x5a, 0x76);
DEFINE_GUID(IID_ID3D12Fence1, 0x433685fe, 0xe22b, 0x4ca0, 0xa8, 0xdb, 0xb5, 0xb4, 0xf4, 0xdd, 0x0e, 0x4a);
DEFINE_GUID(IID_ID3D12GraphicsCommandList, 0x5b160d0f, 0xac1b, 0x4185, 0x8b, 0xa8, 0xb3, 0xae, 0x42, 0xa5, 0xa4, 0x55);
DEFINE_GUID(IID_ID3D12GraphicsCommandList1, 0x553103fb, 0x1fe7, 0x4557, 0xbb, 0x38, 0x94, 0x6d, 0x7d, 0x0e, 0x7c, 0xa7);
DEFINE_GUID(IID_ID3D12GraphicsCommandList2, 0x38C3E585, 0xFF17, 0x412C, 0x91, 0x50, 0x4F, 0xC6, 0xF9, 0xD7, 0x2A, 0x28);
DEFINE_GUID(IID_ID3D12GraphicsCommandList3, 0x6fda83a7, 0xb84c, 0x4e38, 0x9a, 0xc8, 0xc7, 0xbd, 0x22, 0x01, 0x6b, 0x3d);
DEFINE_GUID(IID_ID3D12GraphicsCommandList4, 0x8754318e, 0xd3a9, 0x4541, 0x98, 0xcf, 0x64, 0x5b, 0x50, 0xdc, 0x48, 0x74);
DEFINE_GUID(IID_ID3D12GraphicsCommandList5, 0x55050859, 0x4024, 0x474c, 0x87, 0xf5, 0x64, 0x72, 0xea, 0xee, 0x44, 0xea);
DEFINE_GUID(IID_ID3D12GraphicsCommandList6, 0xc3827890, 0xe548, 0x4cfa, 0x96, 0xcf, 0x56, 0x89, 0xa9, 0x37, 0x0f, 0x80);
DEFINE_GUID(IID_ID3D12GraphicsCommandList7, 0xdd171223, 0x8b61, 0x4769, 0x90, 0xe3, 0x16, 0x0c, 0xcd, 0xe4, 0xe2, 0xc1);
DEFINE_GUID(IID_ID3D12GraphicsCommandList8, 0xee936ef9, 0x599d, 0x4d28, 0x93, 0x8e, 0x23, 0xc4, 0xad, 0x05, 0xce, 0x51);
DEFINE_GUID(IID_ID3D12GraphicsCommandList9, 0x34ed2808, 0xffe6, 0x4c2b, 0xb1, 0x1a, 0xca, 0xbd, 0x2b, 0x0c, 0x59, 0xe1);
DEFINE_GUID(IID_ID3D12GraphicsCommandListExperimental,
            0x7013c015,
            0xd161,
            0x4b63,
            0xa0,
            0x8c,
            0x23,
            0x85,
            0x52,
            0xdd,
            0x8a,
            0xcc);
DEFINE_GUID(IID_ID3D12Heap, 0x6b3b2502, 0x6e51, 0x45b3, 0x90, 0xee, 0x98, 0x84, 0x26, 0x5e, 0x8d, 0xf3);
DEFINE_GUID(IID_ID3D12Heap1, 0x572f7389, 0x2168, 0x49e3, 0x96, 0x93, 0xd6, 0xdf, 0x58, 0x71, 0xbf, 0x6d);
DEFINE_GUID(IID_ID3D12InfoQueue, 0x0742a90b, 0xc387, 0x483f, 0xb9, 0x46, 0x30, 0xa7, 0xe4, 0xe6, 0x14, 0x58);
DEFINE_GUID(IID_ID3D12InfoQueue1, 0x2852dd88, 0xb484, 0x4c0c, 0xb6, 0xb1, 0x67, 0x16, 0x85, 0x00, 0xe6, 0x00);
DEFINE_GUID(IID_ID3D12LifetimeOwner, 0xe667af9f, 0xcd56, 0x4f46, 0x83, 0xce, 0x03, 0x2e, 0x59, 0x5d, 0x70, 0xa8);
DEFINE_GUID(IID_ID3D12LifetimeTracker, 0x3fd03d36, 0x4eb1, 0x424a, 0xa5, 0x82, 0x49, 0x4e, 0xcb, 0x8b, 0xa8, 0x13);
DEFINE_GUID(
    IID_ID3D12ManualWriteTrackingResource, 0x86ca3b85, 0x49ad, 0x4b6e, 0xae, 0xd5, 0xed, 0xdb, 0x18, 0x54, 0x0f, 0x41);
DEFINE_GUID(IID_ID3D12MetaCommand, 0xDBB84C27, 0x36CE, 0x4FC9, 0xB8, 0x01, 0xF0, 0x48, 0xC4, 0x6A, 0xC5, 0x70);
DEFINE_GUID(IID_ID3D12Object, 0xc4fec28f, 0x7966, 0x4e95, 0x9f, 0x94, 0xf4, 0x31, 0xcb, 0x56, 0xc3, 0xb8);
DEFINE_GUID(IID_ID3D12Pageable, 0x63ee58fb, 0x1268, 0x4835, 0x86, 0xda, 0xf0, 0x08, 0xce, 0x62, 0xf0, 0xd6);
DEFINE_GUID(IID_ID3D12PipelineLibrary, 0xc64226a8, 0x9201, 0x46af, 0xb4, 0xcc, 0x53, 0xfb, 0x9f, 0xf7, 0x41, 0x4f);
DEFINE_GUID(IID_ID3D12PipelineLibrary1, 0x80eabf42, 0x2568, 0x4e5e, 0xbd, 0x82, 0xc3, 0x7f, 0x86, 0x96, 0x1d, 0xc3);
DEFINE_GUID(IID_ID3D12PipelineState, 0x765a30f3, 0xf624, 0x4c6f, 0xa8, 0x28, 0xac, 0xe9, 0x48, 0x62, 0x24, 0x45);
DEFINE_GUID(IID_ID3D12ProtectedSession, 0xA1533D18, 0x0AC1, 0x4084, 0x85, 0xB9, 0x89, 0xA9, 0x61, 0x16, 0x80, 0x6B);
DEFINE_GUID(
    IID_ID3D12ProtectedResourceSession, 0x6CD696F4, 0xF289, 0x40CC, 0x80, 0x91, 0x5A, 0x6C, 0x0A, 0x09, 0x9C, 0x3D);
DEFINE_GUID(
    IID_ID3D12ProtectedResourceSession1, 0xD6F12DD6, 0x76FB, 0x406E, 0x89, 0x61, 0x42, 0x96, 0xEE, 0xFC, 0x04, 0x09);
DEFINE_GUID(IID_ID3D12QueryHeap, 0x0d9658ae, 0xed45, 0x469e, 0xa6, 0x1d, 0x97, 0x0e, 0xc5, 0x83, 0xca, 0xb4);
DEFINE_GUID(IID_ID3D12Resource, 0x696442be, 0xa72e, 0x4059, 0xbc, 0x79, 0x5b, 0x5c, 0x98, 0x04, 0x0f, 0xad);
DEFINE_GUID(IID_ID3D12Resource1, 0x9d5e227a, 0x4430, 0x4161, 0x88, 0xb3, 0x3e, 0xca, 0x6b, 0xb1, 0x6e, 0x19);
DEFINE_GUID(IID_ID3D12Resource2, 0xbe36ec3b, 0xea85, 0x4aeb, 0xa4, 0x5a, 0xe9, 0xd7, 0x64, 0x04, 0xa4, 0x95);
DEFINE_GUID(IID_ID3D12RootSignature, 0xc54a6b66, 0x72df, 0x4ee8, 0x8b, 0xe5, 0xa9, 0x46, 0xa1, 0x42, 0x92, 0x14);
DEFINE_GUID(IID_ID3D12SDKConfiguration, 0xe9eb5314, 0x33aa, 0x42b2, 0xa7, 0x18, 0xd7, 0x7f, 0x58, 0xb1, 0xf1, 0xc7);
DEFINE_GUID(IID_ID3D12SDKConfiguration1, 0x8aaf9303, 0xad25, 0x48b9, 0x9a, 0x57, 0xd9, 0xc3, 0x7e, 0x00, 0x9d, 0x9f);
DEFINE_GUID(IID_ID3D12ShaderCacheSession, 0x28e2495d, 0x0f64, 0x4ae4, 0xa6, 0xec, 0x12, 0x92, 0x55, 0xdc, 0x49, 0xa8);
DEFINE_GUID(
    IID_ID3D12RootSignatureDeserializer, 0x34AB647B, 0x3CC8, 0x46AC, 0x84, 0x1B, 0xC0, 0x96, 0x56, 0x45, 0xC0, 0x46);
DEFINE_GUID(IID_ID3D12SharingContract, 0x0adf7d52, 0x929c, 0x4e61, 0xad, 0xdb, 0xff, 0xed, 0x30, 0xde, 0x66, 0xef);
DEFINE_GUID(IID_ID3D12StateObject, 0x47016943, 0xfca8, 0x4594, 0x93, 0xea, 0xaf, 0x25, 0x8b, 0x55, 0x34, 0x6d);
DEFINE_GUID(
    IID_ID3D12StateObjectProperties, 0xde5fa827, 0x9bf9, 0x4f26, 0x89, 0xff, 0xd7, 0xf5, 0x6f, 0xde, 0x38, 0x60);
DEFINE_GUID(
    IID_ID3D12StateObjectProperties1, 0x460caac7, 0x1d24, 0x446a, 0xa1, 0x84, 0xca, 0x67, 0xdb, 0x49, 0x41, 0x38);
DEFINE_GUID(IID_ID3D12SwapChainAssistant, 0xf1df64b6, 0x57fd, 0x49cd, 0x88, 0x07, 0xc0, 0xeb, 0x88, 0xb4, 0x5c, 0x8f);
DEFINE_GUID(IID_ID3D12Tools, 0x7071e1f0, 0xe84b, 0x4b33, 0x97, 0x4f, 0x12, 0xfa, 0x49, 0xde, 0x65, 0xc5);
DEFINE_GUID(IID_ID3D12VersionedRootSignatureDeserializer,
            0x7F91CE67,
            0x090C,
            0x4BB7,
            0xB7,
            0x8E,
            0xED,
            0x8F,
            0xF2,
            0xE3,
            0x1D,
            0xA0);
DEFINE_GUID(
    IID_ID3D12VirtualizationGuestDevice, 0xbc66d368, 0x7373, 0x4943, 0x87, 0x57, 0xfc, 0x87, 0xdc, 0x79, 0xe4, 0x76);
DEFINE_GUID(IID_ID3D12WorkGraphProperties, 0x065acf71, 0xf863, 0x4b89, 0x82, 0xf4, 0x02, 0xe4, 0xd5, 0x88, 0x67, 0x57);

DEFINE_GUID(D3D12_PROTECTED_RESOURCES_SESSION_HARDWARE_PROTECTED,
            0x62b0084e,
            0xc70e,
            0x4daa,
            0xa1,
            0x09,
            0x30,
            0xff,
            0x8d,
            0x5a,
            0x04,
            0x82);

DEFINE_GUID(WKPDID_D3D12UniqueObjectId, 0xf00f00, 0xf00, 0xf00, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0);

// Enums and Flags

enum D3D12_AUTO_BREADCRUMB_OP
{
    D3D12_AUTO_BREADCRUMB_OP_SETMARKER,
    D3D12_AUTO_BREADCRUMB_OP_BEGINEVENT,
    D3D12_AUTO_BREADCRUMB_OP_ENDEVENT,
    D3D12_AUTO_BREADCRUMB_OP_DRAWINSTANCED,
    D3D12_AUTO_BREADCRUMB_OP_DRAWINDEXEDINSTANCED,
    D3D12_AUTO_BREADCRUMB_OP_EXECUTEINDIRECT,
    D3D12_AUTO_BREADCRUMB_OP_DISPATCH,
    D3D12_AUTO_BREADCRUMB_OP_COPYBUFFERREGION,
    D3D12_AUTO_BREADCRUMB_OP_COPYTEXTUREREGION,
    D3D12_AUTO_BREADCRUMB_OP_COPYRESOURCE,
    D3D12_AUTO_BREADCRUMB_OP_COPYTILES,
    D3D12_AUTO_BREADCRUMB_OP_RESOLVESUBRESOURCE,
    D3D12_AUTO_BREADCRUMB_OP_CLEARRENDERTARGETVIEW,
    D3D12_AUTO_BREADCRUMB_OP_CLEARUNORDEREDACCESSVIEW,
    D3D12_AUTO_BREADCRUMB_OP_CLEARDEPTHSTENCILVIEW,
    D3D12_AUTO_BREADCRUMB_OP_RESOURCEBARRIER,
    D3D12_AUTO_BREADCRUMB_OP_EXECUTEBUNDLE,
    D3D12_AUTO_BREADCRUMB_OP_PRESENT,
    D3D12_AUTO_BREADCRUMB_OP_RESOLVEQUERYDATA,
    D3D12_AUTO_BREADCRUMB_OP_BEGINSUBMISSION,
    D3D12_AUTO_BREADCRUMB_OP_ENDSUBMISSION,
    D3D12_AUTO_BREADCRUMB_OP_DECODEFRAME,
    D3D12_AUTO_BREADCRUMB_OP_PROCESSFRAMES,
    D3D12_AUTO_BREADCRUMB_OP_ATOMICCOPYBUFFERUINT,
    D3D12_AUTO_BREADCRUMB_OP_ATOMICCOPYBUFFERUINT64,
    D3D12_AUTO_BREADCRUMB_OP_RESOLVESUBRESOURCEREGION,
    D3D12_AUTO_BREADCRUMB_OP_WRITEBUFFERIMMEDIATE,
    D3D12_AUTO_BREADCRUMB_OP_DECODEFRAME1,
    D3D12_AUTO_BREADCRUMB_OP_SETPROTECTEDRESOURCESESSION,
    D3D12_AUTO_BREADCRUMB_OP_DECODEFRAME2,
    D3D12_AUTO_BREADCRUMB_OP_PROCESSFRAMES1,
    D3D12_AUTO_BREADCRUMB_OP_BUILDRAYTRACINGACCELERATIONSTRUCTURE,
    D3D12_AUTO_BREADCRUMB_OP_EMITRAYTRACINGACCELERATIONSTRUCTUREPOSTBUILDINFO,
    D3D12_AUTO_BREADCRUMB_OP_COPYRAYTRACINGACCELERATIONSTRUCTURE,
    D3D12_AUTO_BREADCRUMB_OP_DISPATCHRAYS,
    D3D12_AUTO_BREADCRUMB_OP_INITIALIZEMETACOMMAND,
    D3D12_AUTO_BREADCRUMB_OP_EXECUTEMETACOMMAND,
    D3D12_AUTO_BREADCRUMB_OP_ESTIMATEMOTION,
    D3D12_AUTO_BREADCRUMB_OP_RESOLVEMOTIONVECTORHEAP,
    D3D12_AUTO_BREADCRUMB_OP_SETPIPELINESTATE1,
    D3D12_AUTO_BREADCRUMB_OP_INITIALIZEEXTENSIONCOMMAND,
    D3D12_AUTO_BREADCRUMB_OP_EXECUTEEXTENSIONCOMMAND,
    D3D12_AUTO_BREADCRUMB_OP_DISPATCHMESH,
    D3D12_AUTO_BREADCRUMB_OP_ENCODEFRAME,
    D3D12_AUTO_BREADCRUMB_OP_RESOLVEENCODEROUTPUTMETADATA,
    D3D12_AUTO_BREADCRUMB_OP_BARRIER,
    D3D12_AUTO_BREADCRUMB_OP_BEGIN_COMMAND_LIST,
    D3D12_AUTO_BREADCRUMB_OP_DISPATCHGRAPH,
    D3D12_AUTO_BREADCRUMB_OP_SETPROGRAM
};

enum D3D12_AXIS_SHADING_RATE
{
    D3D12_AXIS_SHADING_RATE_1X = 0,
    D3D12_AXIS_SHADING_RATE_2X = 0x1,
    D3D12_AXIS_SHADING_RATE_4X = 0x2
};

enum D3D12_BACKGROUND_PROCESSING_MODE
{
    D3D12_BACKGROUND_PROCESSING_MODE_ALLOWED = 0,
    D3D12_BACKGROUND_PROCESSING_MODE_ALLOW_INTRUSIVE_MEASUREMENTS,
    D3D12_BACKGROUND_PROCESSING_MODE_DISABLE_BACKGROUND_WORK,
    D3D12_BACKGROUND_PROCESSING_MODE_DISABLE_PROFILING_BY_SYSTEM
};

enum D3D12_BARRIER_ACCESS
{
    D3D12_BARRIER_ACCESS_COMMON,
    D3D12_BARRIER_ACCESS_VERTEX_BUFFER,
    D3D12_BARRIER_ACCESS_CONSTANT_BUFFER,
    D3D12_BARRIER_ACCESS_INDEX_BUFFER,
    D3D12_BARRIER_ACCESS_RENDER_TARGET,
    D3D12_BARRIER_ACCESS_UNORDERED_ACCESS,
    D3D12_BARRIER_ACCESS_DEPTH_STENCIL_WRITE,
    D3D12_BARRIER_ACCESS_DEPTH_STENCIL_READ,
    D3D12_BARRIER_ACCESS_SHADER_RESOURCE,
    D3D12_BARRIER_ACCESS_STREAM_OUTPUT,
    D3D12_BARRIER_ACCESS_INDIRECT_ARGUMENT,
    D3D12_BARRIER_ACCESS_PREDICATION,
    D3D12_BARRIER_ACCESS_COPY_DEST,
    D3D12_BARRIER_ACCESS_COPY_SOURCE,
    D3D12_BARRIER_ACCESS_RESOLVE_DEST,
    D3D12_BARRIER_ACCESS_RESOLVE_SOURCE,
    D3D12_BARRIER_ACCESS_RAYTRACING_ACCELERATION_STRUCTURE_READ,
    D3D12_BARRIER_ACCESS_RAYTRACING_ACCELERATION_STRUCTURE_WRITE,
    D3D12_BARRIER_ACCESS_SHADING_RATE_SOURCE,
    D3D12_BARRIER_ACCESS_VIDEO_DECODE_READ,
    D3D12_BARRIER_ACCESS_VIDEO_DECODE_WRITE,
    D3D12_BARRIER_ACCESS_VIDEO_PROCESS_READ,
    D3D12_BARRIER_ACCESS_VIDEO_PROCESS_WRITE,
    D3D12_BARRIER_ACCESS_VIDEO_ENCODE_READ,
    D3D12_BARRIER_ACCESS_VIDEO_ENCODE_WRITE,
    D3D12_BARRIER_ACCESS_NO_ACCESS
};

enum D3D12_BARRIER_LAYOUT
{
    D3D12_BARRIER_LAYOUT_UNDEFINED,
    D3D12_BARRIER_LAYOUT_COMMON,
    D3D12_BARRIER_LAYOUT_PRESENT,
    D3D12_BARRIER_LAYOUT_GENERIC_READ,
    D3D12_BARRIER_LAYOUT_RENDER_TARGET,
    D3D12_BARRIER_LAYOUT_UNORDERED_ACCESS,
    D3D12_BARRIER_LAYOUT_DEPTH_STENCIL_WRITE,
    D3D12_BARRIER_LAYOUT_DEPTH_STENCIL_READ,
    D3D12_BARRIER_LAYOUT_SHADER_RESOURCE,
    D3D12_BARRIER_LAYOUT_COPY_SOURCE,
    D3D12_BARRIER_LAYOUT_COPY_DEST,
    D3D12_BARRIER_LAYOUT_RESOLVE_SOURCE,
    D3D12_BARRIER_LAYOUT_RESOLVE_DEST,
    D3D12_BARRIER_LAYOUT_SHADING_RATE_SOURCE,
    D3D12_BARRIER_LAYOUT_VIDEO_DECODE_READ,
    D3D12_BARRIER_LAYOUT_VIDEO_DECODE_WRITE,
    D3D12_BARRIER_LAYOUT_VIDEO_PROCESS_READ,
    D3D12_BARRIER_LAYOUT_VIDEO_PROCESS_WRITE,
    D3D12_BARRIER_LAYOUT_VIDEO_ENCODE_READ,
    D3D12_BARRIER_LAYOUT_VIDEO_ENCODE_WRITE,
    D3D12_BARRIER_LAYOUT_DIRECT_QUEUE_COMMON,
    D3D12_BARRIER_LAYOUT_DIRECT_QUEUE_GENERIC_READ,
    D3D12_BARRIER_LAYOUT_DIRECT_QUEUE_UNORDERED_ACCESS,
    D3D12_BARRIER_LAYOUT_DIRECT_QUEUE_SHADER_RESOURCE,
    D3D12_BARRIER_LAYOUT_DIRECT_QUEUE_COPY_SOURCE,
    D3D12_BARRIER_LAYOUT_DIRECT_QUEUE_COPY_DEST,
    D3D12_BARRIER_LAYOUT_COMPUTE_QUEUE_COMMON,
    D3D12_BARRIER_LAYOUT_COMPUTE_QUEUE_GENERIC_READ,
    D3D12_BARRIER_LAYOUT_COMPUTE_QUEUE_UNORDERED_ACCESS,
    D3D12_BARRIER_LAYOUT_COMPUTE_QUEUE_SHADER_RESOURCE,
    D3D12_BARRIER_LAYOUT_COMPUTE_QUEUE_COPY_SOURCE,
    D3D12_BARRIER_LAYOUT_COMPUTE_QUEUE_COPY_DEST,
    D3D12_BARRIER_LAYOUT_VIDEO_QUEUE_COMMON
};

enum D3D12_BARRIER_SYNC
{
    D3D12_BARRIER_SYNC_NONE,
    D3D12_BARRIER_SYNC_ALL,
    D3D12_BARRIER_SYNC_DRAW,
    D3D12_BARRIER_SYNC_INDEX_INPUT,
    D3D12_BARRIER_SYNC_VERTEX_SHADING,
    D3D12_BARRIER_SYNC_PIXEL_SHADING,
    D3D12_BARRIER_SYNC_DEPTH_STENCIL,
    D3D12_BARRIER_SYNC_RENDER_TARGET,
    D3D12_BARRIER_SYNC_COMPUTE_SHADING,
    D3D12_BARRIER_SYNC_RAYTRACING,
    D3D12_BARRIER_SYNC_COPY,
    D3D12_BARRIER_SYNC_RESOLVE,
    D3D12_BARRIER_SYNC_EXECUTE_INDIRECT,
    D3D12_BARRIER_SYNC_PREDICATION,
    D3D12_BARRIER_SYNC_ALL_SHADING,
    D3D12_BARRIER_SYNC_NON_PIXEL_SHADING,
    D3D12_BARRIER_SYNC_EMIT_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO,
    D3D12_BARRIER_SYNC_CLEAR_UNORDERED_ACCESS_VIEW,
    D3D12_BARRIER_SYNC_VIDEO_DECODE,
    D3D12_BARRIER_SYNC_VIDEO_PROCESS,
    D3D12_BARRIER_SYNC_VIDEO_ENCODE,
    D3D12_BARRIER_SYNC_BUILD_RAYTRACING_ACCELERATION_STRUCTURE,
    D3D12_BARRIER_SYNC_COPY_RAYTRACING_ACCELERATION_STRUCTURE,
    D3D12_BARRIER_SYNC_SPLIT
};

enum D3D12_BARRIER_TYPE
{
    D3D12_BARRIER_TYPE_GLOBAL,
    D3D12_BARRIER_TYPE_TEXTURE,
    D3D12_BARRIER_TYPE_BUFFER
};

enum D3D12_BLEND
{
    D3D12_BLEND_ZERO             = 1,
    D3D12_BLEND_ONE              = 2,
    D3D12_BLEND_SRC_COLOR        = 3,
    D3D12_BLEND_INV_SRC_COLOR    = 4,
    D3D12_BLEND_SRC_ALPHA        = 5,
    D3D12_BLEND_INV_SRC_ALPHA    = 6,
    D3D12_BLEND_DEST_ALPHA       = 7,
    D3D12_BLEND_INV_DEST_ALPHA   = 8,
    D3D12_BLEND_DEST_COLOR       = 9,
    D3D12_BLEND_INV_DEST_COLOR   = 10,
    D3D12_BLEND_SRC_ALPHA_SAT    = 11,
    D3D12_BLEND_BLEND_FACTOR     = 14,
    D3D12_BLEND_INV_BLEND_FACTOR = 15,
    D3D12_BLEND_SRC1_COLOR       = 16,
    D3D12_BLEND_INV_SRC1_COLOR   = 17,
    D3D12_BLEND_SRC1_ALPHA       = 18,
    D3D12_BLEND_INV_SRC1_ALPHA   = 19,
    D3D12_BLEND_ALPHA_FACTOR     = 20,
    D3D12_BLEND_INV_ALPHA_FACTOR = 21
};

enum D3D12_BLEND_OP
{
    D3D12_BLEND_OP_ADD          = 1,
    D3D12_BLEND_OP_SUBTRACT     = 2,
    D3D12_BLEND_OP_REV_SUBTRACT = 3,
    D3D12_BLEND_OP_MIN          = 4,
    D3D12_BLEND_OP_MAX          = 5
};

enum D3D12_BUFFER_SRV_FLAGS
{
    D3D12_BUFFER_SRV_FLAG_NONE = 0,
    D3D12_BUFFER_SRV_FLAG_RAW  = 0x1
};

enum D3D12_BUFFER_UAV_FLAGS
{
    D3D12_BUFFER_UAV_FLAG_NONE = 0,
    D3D12_BUFFER_UAV_FLAG_RAW  = 0x1
};

enum D3D12_CLEAR_FLAGS
{
    D3D12_CLEAR_FLAG_DEPTH   = 0x1,
    D3D12_CLEAR_FLAG_STENCIL = 0x2
};

enum D3D12_COLOR_WRITE_ENABLE
{
    D3D12_COLOR_WRITE_ENABLE_RED   = 1,
    D3D12_COLOR_WRITE_ENABLE_GREEN = 2,
    D3D12_COLOR_WRITE_ENABLE_BLUE  = 4,
    D3D12_COLOR_WRITE_ENABLE_ALPHA = 8,
    D3D12_COLOR_WRITE_ENABLE_ALL
};

enum D3D12_COMMAND_LIST_FLAGS
{
    D3D12_COMMAND_LIST_FLAG_NONE
};

enum D3D12_COMMAND_LIST_SUPPORT_FLAGS
{
    D3D12_COMMAND_LIST_SUPPORT_FLAG_NONE = 0,
    D3D12_COMMAND_LIST_SUPPORT_FLAG_DIRECT,
    D3D12_COMMAND_LIST_SUPPORT_FLAG_BUNDLE,
    D3D12_COMMAND_LIST_SUPPORT_FLAG_COMPUTE,
    D3D12_COMMAND_LIST_SUPPORT_FLAG_COPY,
    D3D12_COMMAND_LIST_SUPPORT_FLAG_VIDEO_DECODE,
    D3D12_COMMAND_LIST_SUPPORT_FLAG_VIDEO_PROCESS,
    D3D12_COMMAND_LIST_SUPPORT_FLAG_VIDEO_ENCODE
};

enum D3D12_COMMAND_LIST_TYPE
{
    D3D12_COMMAND_LIST_TYPE_DIRECT        = 0,
    D3D12_COMMAND_LIST_TYPE_BUNDLE        = 1,
    D3D12_COMMAND_LIST_TYPE_COMPUTE       = 2,
    D3D12_COMMAND_LIST_TYPE_COPY          = 3,
    D3D12_COMMAND_LIST_TYPE_VIDEO_DECODE  = 4,
    D3D12_COMMAND_LIST_TYPE_VIDEO_PROCESS = 5,
    D3D12_COMMAND_LIST_TYPE_VIDEO_ENCODE,
    D3D12_COMMAND_LIST_TYPE_NONE
};

enum D3D12_COMMAND_POOL_FLAGS
{
    D3D12_COMMAND_POOL_FLAG_NONE
};

enum D3D12_COMMAND_QUEUE_FLAGS
{
    D3D12_COMMAND_QUEUE_FLAG_NONE                = 0,
    D3D12_COMMAND_QUEUE_FLAG_DISABLE_GPU_TIMEOUT = 0x1
};

enum D3D12_COMMAND_QUEUE_PRIORITY
{
    D3D12_COMMAND_QUEUE_PRIORITY_NORMAL          = 0,
    D3D12_COMMAND_QUEUE_PRIORITY_HIGH            = 100,
    D3D12_COMMAND_QUEUE_PRIORITY_GLOBAL_REALTIME = 10000
};

enum D3D12_COMMAND_RECORDER_FLAGS
{
    D3D12_COMMAND_RECORDER_FLAG_NONE
};

enum D3D12_COMPARISON_FUNC
{
    D3D12_COMPARISON_FUNC_NONE,
    D3D12_COMPARISON_FUNC_NEVER         = 1,
    D3D12_COMPARISON_FUNC_LESS          = 2,
    D3D12_COMPARISON_FUNC_EQUAL         = 3,
    D3D12_COMPARISON_FUNC_LESS_EQUAL    = 4,
    D3D12_COMPARISON_FUNC_GREATER       = 5,
    D3D12_COMPARISON_FUNC_NOT_EQUAL     = 6,
    D3D12_COMPARISON_FUNC_GREATER_EQUAL = 7,
    D3D12_COMPARISON_FUNC_ALWAYS        = 8
};

enum D3D12_CONSERVATIVE_RASTERIZATION_MODE
{
    D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF = 0,
    D3D12_CONSERVATIVE_RASTERIZATION_MODE_ON  = 1
};

enum D3D12_CONSERVATIVE_RASTERIZATION_TIER
{
    D3D12_CONSERVATIVE_RASTERIZATION_TIER_NOT_SUPPORTED = 0,
    D3D12_CONSERVATIVE_RASTERIZATION_TIER_1             = 1,
    D3D12_CONSERVATIVE_RASTERIZATION_TIER_2             = 2,
    D3D12_CONSERVATIVE_RASTERIZATION_TIER_3             = 3
};

enum D3D12_CPU_PAGE_PROPERTY
{
    D3D12_CPU_PAGE_PROPERTY_UNKNOWN       = 0,
    D3D12_CPU_PAGE_PROPERTY_NOT_AVAILABLE = 1,
    D3D12_CPU_PAGE_PROPERTY_WRITE_COMBINE = 2,
    D3D12_CPU_PAGE_PROPERTY_WRITE_BACK    = 3
};

enum D3D12_CROSS_NODE_SHARING_TIER
{
    D3D12_CROSS_NODE_SHARING_TIER_NOT_SUPPORTED = 0,
    D3D12_CROSS_NODE_SHARING_TIER_1_EMULATED    = 1,
    D3D12_CROSS_NODE_SHARING_TIER_1             = 2,
    D3D12_CROSS_NODE_SHARING_TIER_2             = 3,
    D3D12_CROSS_NODE_SHARING_TIER_3             = 4
};

enum D3D12_CULL_MODE
{
    D3D12_CULL_MODE_NONE  = 1,
    D3D12_CULL_MODE_FRONT = 2,
    D3D12_CULL_MODE_BACK  = 3
};

enum D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE
{
    D3D12_DEBUG_COMMAND_LIST_PARAMETER_GPU_BASED_VALIDATION_SETTINGS = 0
};

enum D3D12_DEBUG_DEVICE_PARAMETER_TYPE
{
    D3D12_DEBUG_DEVICE_PARAMETER_FEATURE_FLAGS = 0,
    D3D12_DEBUG_DEVICE_PARAMETER_GPU_BASED_VALIDATION_SETTINGS,
    D3D12_DEBUG_DEVICE_PARAMETER_GPU_SLOWDOWN_PERFORMANCE_FACTOR
};

enum D3D12_DEBUG_FEATURE
{
    D3D12_DEBUG_FEATURE_NONE                                   = 0,
    D3D12_DEBUG_FEATURE_ALLOW_BEHAVIOR_CHANGING_DEBUG_AIDS     = 0x1,
    D3D12_DEBUG_FEATURE_CONSERVATIVE_RESOURCE_STATE_TRACKING   = 0x2,
    D3D12_DEBUG_FEATURE_DISABLE_VIRTUALIZED_BUNDLES_VALIDATION = 0x4,
    D3D12_DEBUG_FEATURE_EMULATE_WINDOWS7
};

enum D3D12_DEPTH_WRITE_MASK
{
    D3D12_DEPTH_WRITE_MASK_ZERO = 0,
    D3D12_DEPTH_WRITE_MASK_ALL  = 1
};

enum D3D12_DESCRIPTOR_HEAP_FLAGS
{
    D3D12_DESCRIPTOR_HEAP_FLAG_NONE           = 0,
    D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE = 0x1
};

enum D3D12_DESCRIPTOR_HEAP_TYPE
{
    D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV = 0,
    D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER,
    D3D12_DESCRIPTOR_HEAP_TYPE_RTV,
    D3D12_DESCRIPTOR_HEAP_TYPE_DSV,
    D3D12_DESCRIPTOR_HEAP_TYPE_NUM_TYPES
};

enum D3D12_DESCRIPTOR_RANGE_FLAGS
{
    D3D12_DESCRIPTOR_RANGE_FLAG_NONE                                            = 0,
    D3D12_DESCRIPTOR_RANGE_FLAG_DESCRIPTORS_VOLATILE                            = 0x1,
    D3D12_DESCRIPTOR_RANGE_FLAG_DATA_VOLATILE                                   = 0x2,
    D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC_WHILE_SET_AT_EXECUTE                = 0x4,
    D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC                                     = 0x8,
    D3D12_DESCRIPTOR_RANGE_FLAG_DESCRIPTORS_STATIC_KEEPING_BUFFER_BOUNDS_CHECKS = 0x10000
};

enum D3D12_DESCRIPTOR_RANGE_TYPE
{
    D3D12_DESCRIPTOR_RANGE_TYPE_SRV = 0,
    D3D12_DESCRIPTOR_RANGE_TYPE_UAV,
    D3D12_DESCRIPTOR_RANGE_TYPE_CBV,
    D3D12_DESCRIPTOR_RANGE_TYPE_SAMPLER
};

enum D3D12_DEVICE_FACTORY_FLAGS
{
    D3D12_DEVICE_FACTORY_FLAG_NONE                                         = 0,
    D3D12_DEVICE_FACTORY_FLAG_ALLOW_RETURNING_EXISTING_DEVICE              = 0x1,
    D3D12_DEVICE_FACTORY_FLAG_ALLOW_RETURNING_INCOMPATIBLE_EXISTING_DEVICE = 0x2,
    D3D12_DEVICE_FACTORY_FLAG_DISALLOW_STORING_NEW_DEVICE_AS_SINGLETON     = 0x4,
};

enum D3D12_DEVICE_FLAGS
{
    D3D12_DEVICE_FLAG_NONE                                           = 0,
    D3D12_DEVICE_FLAG_DEBUG_LAYER_ENABLED                            = 0x001,
    D3D12_DEVICE_FLAG_GPU_BASED_VALIDATION_ENABLED                   = 0x002,
    D3D12_DEVICE_FLAG_SYNCHRONIZED_COMMAND_QUEUE_VALIDATION_DISABLED = 0x004,
    D3D12_DEVICE_FLAG_DRED_AUTO_BREADCRUMBS_ENABLED                  = 0x008,
    D3D12_DEVICE_FLAG_DRED_PAGE_FAULT_REPORTING_ENABLED              = 0x010,
    D3D12_DEVICE_FLAG_DRED_WATSON_REPORTING_ENABLED                  = 0x020,
    D3D12_DEVICE_FLAG_DRED_BREADCRUMB_CONTEXT_ENABLED                = 0x040,
    D3D12_DEVICE_FLAG_DRED_USE_MARKERS_ONLY_BREADCRUMBS              = 0x080,
    D3D12_DEVICE_FLAG_SHADER_INSTRUMENTATION_ENABLED                 = 0x100,
    D3D12_DEVICE_FLAG_AUTO_DEBUG_NAME_ENABLED                        = 0x200,
    D3D12_DEVICE_FLAG_FORCE_LEGACY_STATE_VALIDATION                  = 0x400,
};

enum D3D12_DRED_ALLOCATION_TYPE
{
    D3D12_DRED_ALLOCATION_TYPE_COMMAND_QUEUE,
    D3D12_DRED_ALLOCATION_TYPE_COMMAND_ALLOCATOR,
    D3D12_DRED_ALLOCATION_TYPE_PIPELINE_STATE,
    D3D12_DRED_ALLOCATION_TYPE_COMMAND_LIST,
    D3D12_DRED_ALLOCATION_TYPE_FENCE,
    D3D12_DRED_ALLOCATION_TYPE_DESCRIPTOR_HEAP,
    D3D12_DRED_ALLOCATION_TYPE_HEAP,
    D3D12_DRED_ALLOCATION_TYPE_QUERY_HEAP,
    D3D12_DRED_ALLOCATION_TYPE_COMMAND_SIGNATURE,
    D3D12_DRED_ALLOCATION_TYPE_PIPELINE_LIBRARY,
    D3D12_DRED_ALLOCATION_TYPE_VIDEO_DECODER,
    D3D12_DRED_ALLOCATION_TYPE_VIDEO_PROCESSOR,
    D3D12_DRED_ALLOCATION_TYPE_RESOURCE,
    D3D12_DRED_ALLOCATION_TYPE_PASS,
    D3D12_DRED_ALLOCATION_TYPE_CRYPTOSESSION,
    D3D12_DRED_ALLOCATION_TYPE_CRYPTOSESSIONPOLICY,
    D3D12_DRED_ALLOCATION_TYPE_PROTECTEDRESOURCESESSION,
    D3D12_DRED_ALLOCATION_TYPE_VIDEO_DECODER_HEAP,
    D3D12_DRED_ALLOCATION_TYPE_COMMAND_POOL,
    D3D12_DRED_ALLOCATION_TYPE_COMMAND_RECORDER,
    D3D12_DRED_ALLOCATION_TYPE_STATE_OBJECT,
    D3D12_DRED_ALLOCATION_TYPE_METACOMMAND,
    D3D12_DRED_ALLOCATION_TYPE_SCHEDULINGGROUP,
    D3D12_DRED_ALLOCATION_TYPE_VIDEO_MOTION_ESTIMATOR,
    D3D12_DRED_ALLOCATION_TYPE_VIDEO_MOTION_VECTOR_HEAP,
    D3D12_DRED_ALLOCATION_TYPE_VIDEO_EXTENSION_COMMAND,
    D3D12_DRED_ALLOCATION_TYPE_VIDEO_ENCODER,
    D3D12_DRED_ALLOCATION_TYPE_VIDEO_ENCODER_HEAP,
    D3D12_DRED_ALLOCATION_TYPE_INVALID
};

enum D3D12_DRED_DEVICE_STATE
{
    D3D12_DRED_DEVICE_STATE_UNKNOWN,
    D3D12_DRED_DEVICE_STATE_HUNG,
    D3D12_DRED_DEVICE_STATE_FAULT,
    D3D12_DRED_DEVICE_STATE_PAGEFAULT
};

enum D3D12_DRED_ENABLEMENT
{
    D3D12_DRED_ENABLEMENT_SYSTEM_CONTROLLED,
    D3D12_DRED_ENABLEMENT_FORCED_OFF,
    D3D12_DRED_ENABLEMENT_FORCED_ON
};

enum D3D12_DRED_FLAGS
{
    D3D12_DRED_FLAG_NONE,
    D3D12_DRED_FLAG_FORCE_ENABLE,
    D3D12_DRED_FLAG_DISABLE_AUTOBREADCRUMBS
};

enum D3D12_DRED_PAGE_FAULT_FLAGS
{
    D3D12_DRED_PAGE_FAULT_FLAGS_NONE
};

enum D3D12_DRED_VERSION
{
    D3D12_DRED_VERSION_1_0,
    D3D12_DRED_VERSION_1_1,
    D3D12_DRED_VERSION_1_2,
    D3D12_DRED_VERSION_1_3
};

enum D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS
{
    D3D12_DRIVER_MATCHING_IDENTIFIER_COMPATIBLE_WITH_DEVICE = 0,
    D3D12_DRIVER_MATCHING_IDENTIFIER_UNSUPPORTED_TYPE       = 0x1,
    D3D12_DRIVER_MATCHING_IDENTIFIER_UNRECOGNIZED           = 0x2,
    D3D12_DRIVER_MATCHING_IDENTIFIER_INCOMPATIBLE_VERSION   = 0x3,
    D3D12_DRIVER_MATCHING_IDENTIFIER_INCOMPATIBLE_TYPE      = 0x4
};

enum D3D12_DSV_DIMENSION
{
    D3D12_DSV_DIMENSION_UNKNOWN          = 0,
    D3D12_DSV_DIMENSION_TEXTURE1D        = 1,
    D3D12_DSV_DIMENSION_TEXTURE1DARRAY   = 2,
    D3D12_DSV_DIMENSION_TEXTURE2D        = 3,
    D3D12_DSV_DIMENSION_TEXTURE2DARRAY   = 4,
    D3D12_DSV_DIMENSION_TEXTURE2DMS      = 5,
    D3D12_DSV_DIMENSION_TEXTURE2DMSARRAY = 6
};

enum D3D12_DSV_FLAGS
{
    D3D12_DSV_FLAG_NONE              = 0,
    D3D12_DSV_FLAG_READ_ONLY_DEPTH   = 0x1,
    D3D12_DSV_FLAG_READ_ONLY_STENCIL = 0x2
};

enum D3D12_ELEMENTS_LAYOUT
{
    D3D12_ELEMENTS_LAYOUT_ARRAY             = 0,
    D3D12_ELEMENTS_LAYOUT_ARRAY_OF_POINTERS = 0x1
};

enum D3D12_EXPORT_FLAGS
{
    D3D12_EXPORT_FLAG_NONE = 0
};

enum D3D12_FEATURE
{
    D3D12_FEATURE_D3D12_OPTIONS                      = 0,
    D3D12_FEATURE_ARCHITECTURE                       = 1,
    D3D12_FEATURE_FEATURE_LEVELS                     = 2,
    D3D12_FEATURE_FORMAT_SUPPORT                     = 3,
    D3D12_FEATURE_MULTISAMPLE_QUALITY_LEVELS         = 4,
    D3D12_FEATURE_FORMAT_INFO                        = 5,
    D3D12_FEATURE_GPU_VIRTUAL_ADDRESS_SUPPORT        = 6,
    D3D12_FEATURE_SHADER_MODEL                       = 7,
    D3D12_FEATURE_D3D12_OPTIONS1                     = 8,
    D3D12_FEATURE_PROTECTED_RESOURCE_SESSION_SUPPORT = 10,
    D3D12_FEATURE_ROOT_SIGNATURE                     = 12,
    D3D12_FEATURE_ARCHITECTURE1                      = 16,
    D3D12_FEATURE_D3D12_OPTIONS2                     = 18,
    D3D12_FEATURE_SHADER_CACHE                       = 19,
    D3D12_FEATURE_COMMAND_QUEUE_PRIORITY             = 20,
    D3D12_FEATURE_D3D12_OPTIONS3                     = 21,
    D3D12_FEATURE_EXISTING_HEAPS                     = 22,
    D3D12_FEATURE_D3D12_OPTIONS4                     = 23,
    D3D12_FEATURE_SERIALIZATION                      = 24,
    D3D12_FEATURE_CROSS_NODE                         = 25,
    D3D12_FEATURE_D3D12_OPTIONS5                     = 27,
    D3D12_FEATURE_DISPLAYABLE,
    D3D12_FEATURE_D3D12_OPTIONS6                        = 30,
    D3D12_FEATURE_QUERY_META_COMMAND                    = 31,
    D3D12_FEATURE_D3D12_OPTIONS7                        = 32,
    D3D12_FEATURE_PROTECTED_RESOURCE_SESSION_TYPE_COUNT = 33,
    D3D12_FEATURE_PROTECTED_RESOURCE_SESSION_TYPES      = 34,
    D3D12_FEATURE_D3D12_OPTIONS8                        = 36,
    D3D12_FEATURE_D3D12_OPTIONS9                        = 37,
    D3D12_FEATURE_D3D12_OPTIONS10,
    D3D12_FEATURE_D3D12_OPTIONS11,
    D3D12_FEATURE_D3D12_OPTIONS12,
    D3D12_FEATURE_D3D12_OPTIONS13,
    D3D12_FEATURE_D3D12_OPTIONS14,
    D3D12_FEATURE_D3D12_OPTIONS15,
    D3D12_FEATURE_D3D12_OPTIONS16,
    D3D12_FEATURE_D3D12_OPTIONS17,
    D3D12_FEATURE_D3D12_OPTIONS18,
    D3D12_FEATURE_D3D12_OPTIONS19,
    D3D12_FEATURE_D3D12_OPTIONS20,
    D3D12_FEATURE_PREDICATION,
    D3D12_FEATURE_PLACED_RESOURCE_SUPPORT_INFO,
    D3D12_FEATURE_HARDWARE_COPY,
    D3D12_FEATURE_D3D12_OPTIONS21
};

enum D3D12_FENCE_FLAGS
{
    D3D12_FENCE_FLAG_NONE                 = 0,
    D3D12_FENCE_FLAG_SHARED               = 0x1,
    D3D12_FENCE_FLAG_SHARED_CROSS_ADAPTER = 0x2,
    D3D12_FENCE_FLAG_NON_MONITORED        = 0x4
};

enum D3D12_FILL_MODE
{
    D3D12_FILL_MODE_WIREFRAME = 2,
    D3D12_FILL_MODE_SOLID     = 3
};

enum D3D12_FILTER
{
    D3D12_FILTER_MIN_MAG_MIP_POINT               = 0,
    D3D12_FILTER_MIN_MAG_POINT_MIP_LINEAR        = 0x1,
    D3D12_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT  = 0x4,
    D3D12_FILTER_MIN_POINT_MAG_MIP_LINEAR        = 0x5,
    D3D12_FILTER_MIN_LINEAR_MAG_MIP_POINT        = 0x10,
    D3D12_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR = 0x11,
    D3D12_FILTER_MIN_MAG_LINEAR_MIP_POINT        = 0x14,
    D3D12_FILTER_MIN_MAG_MIP_LINEAR              = 0x15,
    D3D12_FILTER_MIN_MAG_ANISOTROPIC_MIP_POINT,
    D3D12_FILTER_ANISOTROPIC                                = 0x55,
    D3D12_FILTER_COMPARISON_MIN_MAG_MIP_POINT               = 0x80,
    D3D12_FILTER_COMPARISON_MIN_MAG_POINT_MIP_LINEAR        = 0x81,
    D3D12_FILTER_COMPARISON_MIN_POINT_MAG_LINEAR_MIP_POINT  = 0x84,
    D3D12_FILTER_COMPARISON_MIN_POINT_MAG_MIP_LINEAR        = 0x85,
    D3D12_FILTER_COMPARISON_MIN_LINEAR_MAG_MIP_POINT        = 0x90,
    D3D12_FILTER_COMPARISON_MIN_LINEAR_MAG_POINT_MIP_LINEAR = 0x91,
    D3D12_FILTER_COMPARISON_MIN_MAG_LINEAR_MIP_POINT        = 0x94,
    D3D12_FILTER_COMPARISON_MIN_MAG_MIP_LINEAR              = 0x95,
    D3D12_FILTER_COMPARISON_MIN_MAG_ANISOTROPIC_MIP_POINT,
    D3D12_FILTER_COMPARISON_ANISOTROPIC                  = 0xd5,
    D3D12_FILTER_MINIMUM_MIN_MAG_MIP_POINT               = 0x100,
    D3D12_FILTER_MINIMUM_MIN_MAG_POINT_MIP_LINEAR        = 0x101,
    D3D12_FILTER_MINIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT  = 0x104,
    D3D12_FILTER_MINIMUM_MIN_POINT_MAG_MIP_LINEAR        = 0x105,
    D3D12_FILTER_MINIMUM_MIN_LINEAR_MAG_MIP_POINT        = 0x110,
    D3D12_FILTER_MINIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR = 0x111,
    D3D12_FILTER_MINIMUM_MIN_MAG_LINEAR_MIP_POINT        = 0x114,
    D3D12_FILTER_MINIMUM_MIN_MAG_MIP_LINEAR              = 0x115,
    D3D12_FILTER_MINIMUM_MIN_MAG_ANISOTROPIC_MIP_POINT,
    D3D12_FILTER_MINIMUM_ANISOTROPIC                     = 0x155,
    D3D12_FILTER_MAXIMUM_MIN_MAG_MIP_POINT               = 0x180,
    D3D12_FILTER_MAXIMUM_MIN_MAG_POINT_MIP_LINEAR        = 0x181,
    D3D12_FILTER_MAXIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT  = 0x184,
    D3D12_FILTER_MAXIMUM_MIN_POINT_MAG_MIP_LINEAR        = 0x185,
    D3D12_FILTER_MAXIMUM_MIN_LINEAR_MAG_MIP_POINT        = 0x190,
    D3D12_FILTER_MAXIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR = 0x191,
    D3D12_FILTER_MAXIMUM_MIN_MAG_LINEAR_MIP_POINT        = 0x194,
    D3D12_FILTER_MAXIMUM_MIN_MAG_MIP_LINEAR              = 0x195,
    D3D12_FILTER_MAXIMUM_MIN_MAG_ANISOTROPIC_MIP_POINT,
    D3D12_FILTER_MAXIMUM_ANISOTROPIC = 0x1d5
};

enum D3D12_FILTER_REDUCTION_TYPE
{
    D3D12_FILTER_REDUCTION_TYPE_STANDARD   = 0,
    D3D12_FILTER_REDUCTION_TYPE_COMPARISON = 1,
    D3D12_FILTER_REDUCTION_TYPE_MINIMUM    = 2,
    D3D12_FILTER_REDUCTION_TYPE_MAXIMUM    = 3
};

enum D3D12_FILTER_TYPE
{
    D3D12_FILTER_TYPE_POINT  = 0,
    D3D12_FILTER_TYPE_LINEAR = 1
};

enum D3D12_FORMAT_SUPPORT1
{
    D3D12_FORMAT_SUPPORT1_NONE                        = 0,
    D3D12_FORMAT_SUPPORT1_BUFFER                      = 0x1,
    D3D12_FORMAT_SUPPORT1_IA_VERTEX_BUFFER            = 0x2,
    D3D12_FORMAT_SUPPORT1_IA_INDEX_BUFFER             = 0x4,
    D3D12_FORMAT_SUPPORT1_SO_BUFFER                   = 0x8,
    D3D12_FORMAT_SUPPORT1_TEXTURE1D                   = 0x10,
    D3D12_FORMAT_SUPPORT1_TEXTURE2D                   = 0x20,
    D3D12_FORMAT_SUPPORT1_TEXTURE3D                   = 0x40,
    D3D12_FORMAT_SUPPORT1_TEXTURECUBE                 = 0x80,
    D3D12_FORMAT_SUPPORT1_SHADER_LOAD                 = 0x100,
    D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE               = 0x200,
    D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE_COMPARISON    = 0x400,
    D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE_MONO_TEXT     = 0x800,
    D3D12_FORMAT_SUPPORT1_MIP                         = 0x1000,
    D3D12_FORMAT_SUPPORT1_RENDER_TARGET               = 0x4000,
    D3D12_FORMAT_SUPPORT1_BLENDABLE                   = 0x8000,
    D3D12_FORMAT_SUPPORT1_DEPTH_STENCIL               = 0x10000,
    D3D12_FORMAT_SUPPORT1_MULTISAMPLE_RESOLVE         = 0x40000,
    D3D12_FORMAT_SUPPORT1_DISPLAY                     = 0x80000,
    D3D12_FORMAT_SUPPORT1_CAST_WITHIN_BIT_LAYOUT      = 0x100000,
    D3D12_FORMAT_SUPPORT1_MULTISAMPLE_RENDERTARGET    = 0x200000,
    D3D12_FORMAT_SUPPORT1_MULTISAMPLE_LOAD            = 0x400000,
    D3D12_FORMAT_SUPPORT1_SHADER_GATHER               = 0x800000,
    D3D12_FORMAT_SUPPORT1_BACK_BUFFER_CAST            = 0x1000000,
    D3D12_FORMAT_SUPPORT1_TYPED_UNORDERED_ACCESS_VIEW = 0x2000000,
    D3D12_FORMAT_SUPPORT1_SHADER_GATHER_COMPARISON    = 0x4000000,
    D3D12_FORMAT_SUPPORT1_DECODER_OUTPUT              = 0x8000000,
    D3D12_FORMAT_SUPPORT1_VIDEO_PROCESSOR_OUTPUT      = 0x10000000,
    D3D12_FORMAT_SUPPORT1_VIDEO_PROCESSOR_INPUT       = 0x20000000,
    D3D12_FORMAT_SUPPORT1_VIDEO_ENCODER               = 0x40000000
};

enum D3D12_FORMAT_SUPPORT2
{
    D3D12_FORMAT_SUPPORT2_NONE                                         = 0,
    D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_ADD                               = 0x1,
    D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_BITWISE_OPS                       = 0x2,
    D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_COMPARE_STORE_OR_COMPARE_EXCHANGE = 0x4,
    D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_EXCHANGE                          = 0x8,
    D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_SIGNED_MIN_OR_MAX                 = 0x10,
    D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_UNSIGNED_MIN_OR_MAX               = 0x20,
    D3D12_FORMAT_SUPPORT2_UAV_TYPED_LOAD                               = 0x40,
    D3D12_FORMAT_SUPPORT2_UAV_TYPED_STORE                              = 0x80,
    D3D12_FORMAT_SUPPORT2_OUTPUT_MERGER_LOGIC_OP                       = 0x100,
    D3D12_FORMAT_SUPPORT2_TILED                                        = 0x200,
    D3D12_FORMAT_SUPPORT2_MULTIPLANE_OVERLAY                           = 0x4000,
    D3D12_FORMAT_SUPPORT2_SAMPLER_FEEDBACK
};

enum D3D12_GPU_BASED_VALIDATION_FLAGS
{
    D3D12_GPU_BASED_VALIDATION_FLAGS_NONE                   = 0,
    D3D12_GPU_BASED_VALIDATION_FLAGS_DISABLE_STATE_TRACKING = 0x1
};

enum D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS
{
    D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAG_NONE                                           = 0,
    D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAG_FRONT_LOAD_CREATE_TRACKING_ONLY_SHADERS        = 0x1,
    D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAG_FRONT_LOAD_CREATE_UNGUARDED_VALIDATION_SHADERS = 0x2,
    D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAG_FRONT_LOAD_CREATE_GUARDED_VALIDATION_SHADERS   = 0x4,
    D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS_VALID_MASK                                    = 0x7
};

enum D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE
{
    D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE_NONE = 0,
    D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE_STATE_TRACKING_ONLY,
    D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE_UNGUARDED_VALIDATION,
    D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE_GUARDED_VALIDATION,
    NUM_D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODES
};

enum D3D12_GRAPHICS_STATES
{
    D3D12_GRAPHICS_STATE_NONE = 0,
    D3D12_GRAPHICS_STATE_IA_VERTEX_BUFFERS,
    D3D12_GRAPHICS_STATE_IA_INDEX_BUFFER,
    D3D12_GRAPHICS_STATE_IA_PRIMITIVE_TOPOLOGY,
    D3D12_GRAPHICS_STATE_DESCRIPTOR_HEAP,
    D3D12_GRAPHICS_STATE_GRAPHICS_ROOT_SIGNATURE,
    D3D12_GRAPHICS_STATE_COMPUTE_ROOT_SIGNATURE,
    D3D12_GRAPHICS_STATE_RS_VIEWPORTS,
    D3D12_GRAPHICS_STATE_RS_SCISSOR_RECTS,
    D3D12_GRAPHICS_STATE_PREDICATION,
    D3D12_GRAPHICS_STATE_OM_RENDER_TARGETS,
    D3D12_GRAPHICS_STATE_OM_STENCIL_REF,
    D3D12_GRAPHICS_STATE_OM_BLEND_FACTOR,
    D3D12_GRAPHICS_STATE_PIPELINE_STATE,
    D3D12_GRAPHICS_STATE_SO_TARGETS,
    D3D12_GRAPHICS_STATE_OM_DEPTH_BOUNDS,
    D3D12_GRAPHICS_STATE_SAMPLE_POSITIONS,
    D3D12_GRAPHICS_STATE_VIEW_INSTANCE_MASK
};

enum D3D12_HEAP_FLAGS
{
    D3D12_HEAP_FLAG_NONE                    = 0,
    D3D12_HEAP_FLAG_SHARED                  = 0x1,
    D3D12_HEAP_FLAG_DENY_BUFFERS            = 0x4,
    D3D12_HEAP_FLAG_ALLOW_DISPLAY           = 0x8,
    D3D12_HEAP_FLAG_SHARED_CROSS_ADAPTER    = 0x20,
    D3D12_HEAP_FLAG_DENY_RT_DS_TEXTURES     = 0x40,
    D3D12_HEAP_FLAG_DENY_NON_RT_DS_TEXTURES = 0x80,
    D3D12_HEAP_FLAG_HARDWARE_PROTECTED      = 0x100,
    D3D12_HEAP_FLAG_ALLOW_WRITE_WATCH       = 0x200,
    D3D12_HEAP_FLAG_ALLOW_SHADER_ATOMICS    = 0x400,
    D3D12_HEAP_FLAG_CREATE_NOT_RESIDENT     = 0x800,
    D3D12_HEAP_FLAG_CREATE_NOT_ZEROED       = 0x1000,
    D3D12_HEAP_FLAG_TOOLS_USE_MANUAL_WRITE_TRACKING,
    D3D12_HEAP_FLAG_ALLOW_ALL_BUFFERS_AND_TEXTURES = 0,
    D3D12_HEAP_FLAG_ALLOW_ONLY_BUFFERS             = 0xc0,
    D3D12_HEAP_FLAG_ALLOW_ONLY_NON_RT_DS_TEXTURES  = 0x44,
    D3D12_HEAP_FLAG_ALLOW_ONLY_RT_DS_TEXTURES      = 0x84
};

enum D3D12_HEAP_SERIALIZATION_TIER
{
    D3D12_HEAP_SERIALIZATION_TIER_0,
    D3D12_HEAP_SERIALIZATION_TIER_10
};

enum D3D12_HEAP_TYPE
{
    D3D12_HEAP_TYPE_DEFAULT  = 1,
    D3D12_HEAP_TYPE_UPLOAD   = 2,
    D3D12_HEAP_TYPE_READBACK = 3,
    D3D12_HEAP_TYPE_CUSTOM   = 4,
    D3D12_HEAP_TYPE_GPU_UPLOAD
};

enum D3D12_HIT_GROUP_TYPE
{
    D3D12_HIT_GROUP_TYPE_TRIANGLES            = 0,
    D3D12_HIT_GROUP_TYPE_PROCEDURAL_PRIMITIVE = 0x1
};

enum D3D12_HIT_KIND
{
    D3D12_HIT_KIND_TRIANGLE_FRONT_FACE,
    D3D12_HIT_KIND_TRIANGLE_BACK_FACE
};

enum D3D12_INDEX_BUFFER_STRIP_CUT_VALUE
{
    D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_DISABLED   = 0,
    D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_0xFFFF     = 1,
    D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_0xFFFFFFFF = 2
};

enum D3D12_INDIRECT_ARGUMENT_TYPE
{
    D3D12_INDIRECT_ARGUMENT_TYPE_DRAW = 0,
    D3D12_INDIRECT_ARGUMENT_TYPE_DRAW_INDEXED,
    D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH,
    D3D12_INDIRECT_ARGUMENT_TYPE_VERTEX_BUFFER_VIEW,
    D3D12_INDIRECT_ARGUMENT_TYPE_INDEX_BUFFER_VIEW,
    D3D12_INDIRECT_ARGUMENT_TYPE_CONSTANT,
    D3D12_INDIRECT_ARGUMENT_TYPE_CONSTANT_BUFFER_VIEW,
    D3D12_INDIRECT_ARGUMENT_TYPE_SHADER_RESOURCE_VIEW,
    D3D12_INDIRECT_ARGUMENT_TYPE_UNORDERED_ACCESS_VIEW,
    D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH_RAYS,
    D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH_MESH,
    D3D12_INDIRECT_ARGUMENT_TYPE_INCREMENTING_CONSTANT
};

enum D3D12_INPUT_CLASSIFICATION
{
    D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA   = 0,
    D3D12_INPUT_CLASSIFICATION_PER_INSTANCE_DATA = 1
};

enum D3D12_LIFETIME_STATE
{
    D3D12_LIFETIME_STATE_IN_USE = 0,
    D3D12_LIFETIME_STATE_NOT_IN_USE
};

enum D3D12_LINE_RASTERIZATION_MODE
{
    D3D12_LINE_RASTERIZATION_MODE_ALIASED,
    D3D12_LINE_RASTERIZATION_MODE_ALPHA_ANTIALIASED,
    D3D12_LINE_RASTERIZATION_MODE_QUADRILATERAL_WIDE,
    D3D12_LINE_RASTERIZATION_MODE_QUADRILATERAL_NARROW,
};

enum D3D12_LOGIC_OP
{
    D3D12_LOGIC_OP_CLEAR = 0,
    D3D12_LOGIC_OP_SET,
    D3D12_LOGIC_OP_COPY,
    D3D12_LOGIC_OP_COPY_INVERTED,
    D3D12_LOGIC_OP_NOOP,
    D3D12_LOGIC_OP_INVERT,
    D3D12_LOGIC_OP_AND,
    D3D12_LOGIC_OP_NAND,
    D3D12_LOGIC_OP_OR,
    D3D12_LOGIC_OP_NOR,
    D3D12_LOGIC_OP_XOR,
    D3D12_LOGIC_OP_EQUIV,
    D3D12_LOGIC_OP_AND_REVERSE,
    D3D12_LOGIC_OP_AND_INVERTED,
    D3D12_LOGIC_OP_OR_REVERSE,
    D3D12_LOGIC_OP_OR_INVERTED
};

enum D3D12_MEASUREMENTS_ACTION
{
    D3D12_MEASUREMENTS_ACTION_KEEP_ALL = 0,
    D3D12_MEASUREMENTS_ACTION_COMMIT_RESULTS,
    D3D12_MEASUREMENTS_ACTION_COMMIT_RESULTS_HIGH_PRIORITY,
    D3D12_MEASUREMENTS_ACTION_DISCARD_PREVIOUS
};

enum D3D12_MEMORY_POOL
{
    D3D12_MEMORY_POOL_UNKNOWN = 0,
    D3D12_MEMORY_POOL_L0      = 1,
    D3D12_MEMORY_POOL_L1      = 2
};

enum D3D12_MESH_SHADER_TIER
{
    D3D12_MESH_SHADER_TIER_NOT_SUPPORTED = 0,
    D3D12_MESH_SHADER_TIER_1             = 10
};

enum D3D12_MESSAGE_CALLBACK_FLAGS
{
    D3D12_MESSAGE_CALLBACK_FLAG_NONE      = 0x00,
    D3D12_MESSAGE_CALLBACK_IGNORE_FILTERS = 0x01,
};

enum D3D12_MESSAGE_CATEGORY
{
    D3D12_MESSAGE_CATEGORY_APPLICATION_DEFINED = 0,
    D3D12_MESSAGE_CATEGORY_MISCELLANEOUS,
    D3D12_MESSAGE_CATEGORY_INITIALIZATION,
    D3D12_MESSAGE_CATEGORY_CLEANUP,
    D3D12_MESSAGE_CATEGORY_COMPILATION,
    D3D12_MESSAGE_CATEGORY_STATE_CREATION,
    D3D12_MESSAGE_CATEGORY_STATE_SETTING,
    D3D12_MESSAGE_CATEGORY_STATE_GETTING,
    D3D12_MESSAGE_CATEGORY_RESOURCE_MANIPULATION,
    D3D12_MESSAGE_CATEGORY_EXECUTION,
    D3D12_MESSAGE_CATEGORY_SHADER
};

enum D3D12_MESSAGE_ID
{
    D3D12_MESSAGE_ID_UNKNOWN                                                                     = 0,
    D3D12_MESSAGE_ID_STRING_FROM_APPLICATION                                                     = 1,
    D3D12_MESSAGE_ID_CORRUPTED_THIS                                                              = 2,
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER1                                                        = 3,
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER2                                                        = 4,
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER3                                                        = 5,
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER4                                                        = 6,
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER5                                                        = 7,
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER6                                                        = 8,
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER7                                                        = 9,
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER8                                                        = 10,
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER9                                                        = 11,
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER10                                                       = 12,
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER11                                                       = 13,
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER12                                                       = 14,
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER13                                                       = 15,
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER14                                                       = 16,
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER15                                                       = 17,
    D3D12_MESSAGE_ID_CORRUPTED_MULTITHREADING                                                    = 18,
    D3D12_MESSAGE_ID_MESSAGE_REPORTING_OUTOFMEMORY                                               = 19,
    D3D12_MESSAGE_ID_GETPRIVATEDATA_MOREDATA                                                     = 20,
    D3D12_MESSAGE_ID_SETPRIVATEDATA_INVALIDFREEDATA                                              = 21,
    D3D12_MESSAGE_ID_SETPRIVATEDATA_CHANGINGPARAMS                                               = 24,
    D3D12_MESSAGE_ID_SETPRIVATEDATA_OUTOFMEMORY                                                  = 25,
    D3D12_MESSAGE_ID_CREATESHADERRESOURCEVIEW_UNRECOGNIZEDFORMAT                                 = 26,
    D3D12_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDDESC                                        = 27,
    D3D12_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDFORMAT                                      = 28,
    D3D12_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDVIDEOPLANESLICE                             = 29,
    D3D12_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDPLANESLICE                                  = 30,
    D3D12_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDDIMENSIONS                                  = 31,
    D3D12_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDRESOURCE                                    = 32,
    D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_UNRECOGNIZEDFORMAT                                   = 35,
    D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_UNSUPPORTEDFORMAT                                    = 36,
    D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDDESC                                          = 37,
    D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDFORMAT                                        = 38,
    D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDVIDEOPLANESLICE                               = 39,
    D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDPLANESLICE                                    = 40,
    D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDDIMENSIONS                                    = 41,
    D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDRESOURCE                                      = 42,
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_UNRECOGNIZEDFORMAT                                   = 45,
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDDESC                                          = 46,
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDFORMAT                                        = 47,
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDDIMENSIONS                                    = 48,
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDRESOURCE                                      = 49,
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_OUTOFMEMORY                                               = 52,
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_TOOMANYELEMENTS                                           = 53,
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDFORMAT                                             = 54,
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_INCOMPATIBLEFORMAT                                        = 55,
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDSLOT                                               = 56,
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDINPUTSLOTCLASS                                     = 57,
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_STEPRATESLOTCLASSMISMATCH                                 = 58,
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDSLOTCLASSCHANGE                                    = 59,
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDSTEPRATECHANGE                                     = 60,
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDALIGNMENT                                          = 61,
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_DUPLICATESEMANTIC                                         = 62,
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_UNPARSEABLEINPUTSIGNATURE                                 = 63,
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_NULLSEMANTIC                                              = 64,
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_MISSINGELEMENT                                            = 65,
    D3D12_MESSAGE_ID_CREATEVERTEXSHADER_OUTOFMEMORY                                              = 66,
    D3D12_MESSAGE_ID_CREATEVERTEXSHADER_INVALIDSHADERBYTECODE                                    = 67,
    D3D12_MESSAGE_ID_CREATEVERTEXSHADER_INVALIDSHADERTYPE                                        = 68,
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADER_OUTOFMEMORY                                            = 69,
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADER_INVALIDSHADERBYTECODE                                  = 70,
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADER_INVALIDSHADERTYPE                                      = 71,
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_OUTOFMEMORY                            = 72,
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSHADERBYTECODE                  = 73,
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSHADERTYPE                      = 74,
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDNUMENTRIES                      = 75,
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_OUTPUTSTREAMSTRIDEUNUSED               = 76,
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_OUTPUTSLOT0EXPECTED                    = 79,
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDOUTPUTSLOT                      = 80,
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_ONLYONEELEMENTPERSLOT                  = 81,
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDCOMPONENTCOUNT                  = 82,
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSTARTCOMPONENTANDCOMPONENTCOUNT = 83,
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDGAPDEFINITION                   = 84,
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_REPEATEDOUTPUT                         = 85,
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDOUTPUTSTREAMSTRIDE              = 86,
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_MISSINGSEMANTIC                        = 87,
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_MASKMISMATCH                           = 88,
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_CANTHAVEONLYGAPS                       = 89,
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_DECLTOOCOMPLEX                         = 90,
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_MISSINGOUTPUTSIGNATURE                 = 91,
    D3D12_MESSAGE_ID_CREATEPIXELSHADER_OUTOFMEMORY                                               = 92,
    D3D12_MESSAGE_ID_CREATEPIXELSHADER_INVALIDSHADERBYTECODE                                     = 93,
    D3D12_MESSAGE_ID_CREATEPIXELSHADER_INVALIDSHADERTYPE                                         = 94,
    D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDFILLMODE                                       = 95,
    D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDCULLMODE                                       = 96,
    D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDDEPTHBIASCLAMP                                 = 97,
    D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDSLOPESCALEDDEPTHBIAS                           = 98,
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDDEPTHWRITEMASK                               = 100,
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDDEPTHFUNC                                    = 101,
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILFAILOP                       = 102,
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILZFAILOP                      = 103,
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILPASSOP                       = 104,
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILFUNC                         = 105,
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILFAILOP                        = 106,
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILZFAILOP                       = 107,
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILPASSOP                        = 108,
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILFUNC                          = 109,
    D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDSRCBLEND                                            = 111,
    D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDDESTBLEND                                           = 112,
    D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDBLENDOP                                             = 113,
    D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDSRCBLENDALPHA                                       = 114,
    D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDDESTBLENDALPHA                                      = 115,
    D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDBLENDOPALPHA                                        = 116,
    D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDRENDERTARGETWRITEMASK                               = 117,
    D3D12_MESSAGE_ID_GET_PROGRAM_IDENTIFIER_ERROR,
    D3D12_MESSAGE_ID_GET_WORK_GRAPH_PROPERTIES_ERROR,
    D3D12_MESSAGE_ID_SET_PROGRAM_ERROR,
    D3D12_MESSAGE_ID_CLEARDEPTHSTENCILVIEW_INVALID                                                     = 135,
    D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_ROOT_SIGNATURE_NOT_SET                                          = 200,
    D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_ROOT_SIGNATURE_MISMATCH                                         = 201,
    D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_VERTEX_BUFFER_NOT_SET                                           = 202,
    D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_VERTEX_BUFFER_STRIDE_TOO_SMALL                                  = 209,
    D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_VERTEX_BUFFER_TOO_SMALL                                         = 210,
    D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_INDEX_BUFFER_NOT_SET                                            = 211,
    D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_INDEX_BUFFER_FORMAT_INVALID                                     = 212,
    D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_INDEX_BUFFER_TOO_SMALL                                          = 213,
    D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_INVALID_PRIMITIVETOPOLOGY                                       = 219,
    D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_VERTEX_STRIDE_UNALIGNED                                         = 221,
    D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_INDEX_OFFSET_UNALIGNED                                          = 222,
    D3D12_MESSAGE_ID_DEVICE_REMOVAL_PROCESS_AT_FAULT                                                   = 232,
    D3D12_MESSAGE_ID_DEVICE_REMOVAL_PROCESS_POSSIBLY_AT_FAULT                                          = 233,
    D3D12_MESSAGE_ID_DEVICE_REMOVAL_PROCESS_NOT_AT_FAULT                                               = 234,
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_TRAILING_DIGIT_IN_SEMANTIC                                      = 239,
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_TRAILING_DIGIT_IN_SEMANTIC                   = 240,
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_TYPE_MISMATCH                                                   = 245,
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_EMPTY_LAYOUT                                                    = 253,
    D3D12_MESSAGE_ID_LIVE_OBJECT_SUMMARY                                                               = 255,
    D3D12_MESSAGE_ID_LIVE_DEVICE                                                                       = 274,
    D3D12_MESSAGE_ID_LIVE_SWAPCHAIN                                                                    = 275,
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDFLAGS                                               = 276,
    D3D12_MESSAGE_ID_CREATEVERTEXSHADER_INVALIDCLASSLINKAGE                                            = 277,
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADER_INVALIDCLASSLINKAGE                                          = 278,
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSTREAMTORASTERIZER                    = 280,
    D3D12_MESSAGE_ID_CREATEPIXELSHADER_INVALIDCLASSLINKAGE                                             = 283,
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSTREAM                                = 284,
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_UNEXPECTEDENTRIES                            = 285,
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_UNEXPECTEDSTRIDES                            = 286,
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDNUMSTRIDES                            = 287,
    D3D12_MESSAGE_ID_CREATEHULLSHADER_OUTOFMEMORY                                                      = 289,
    D3D12_MESSAGE_ID_CREATEHULLSHADER_INVALIDSHADERBYTECODE                                            = 290,
    D3D12_MESSAGE_ID_CREATEHULLSHADER_INVALIDSHADERTYPE                                                = 291,
    D3D12_MESSAGE_ID_CREATEHULLSHADER_INVALIDCLASSLINKAGE                                              = 292,
    D3D12_MESSAGE_ID_CREATEDOMAINSHADER_OUTOFMEMORY                                                    = 294,
    D3D12_MESSAGE_ID_CREATEDOMAINSHADER_INVALIDSHADERBYTECODE                                          = 295,
    D3D12_MESSAGE_ID_CREATEDOMAINSHADER_INVALIDSHADERTYPE                                              = 296,
    D3D12_MESSAGE_ID_CREATEDOMAINSHADER_INVALIDCLASSLINKAGE                                            = 297,
    D3D12_MESSAGE_ID_RESOURCE_UNMAP_NOTMAPPED                                                          = 310,
    D3D12_MESSAGE_ID_DEVICE_CHECKFEATURESUPPORT_MISMATCHED_DATA_SIZE                                   = 318,
    D3D12_MESSAGE_ID_CREATECOMPUTESHADER_OUTOFMEMORY                                                   = 321,
    D3D12_MESSAGE_ID_CREATECOMPUTESHADER_INVALIDSHADERBYTECODE                                         = 322,
    D3D12_MESSAGE_ID_CREATECOMPUTESHADER_INVALIDCLASSLINKAGE                                           = 323,
    D3D12_MESSAGE_ID_DEVICE_CREATEVERTEXSHADER_DOUBLEFLOATOPSNOTSUPPORTED                              = 331,
    D3D12_MESSAGE_ID_DEVICE_CREATEHULLSHADER_DOUBLEFLOATOPSNOTSUPPORTED                                = 332,
    D3D12_MESSAGE_ID_DEVICE_CREATEDOMAINSHADER_DOUBLEFLOATOPSNOTSUPPORTED                              = 333,
    D3D12_MESSAGE_ID_DEVICE_CREATEGEOMETRYSHADER_DOUBLEFLOATOPSNOTSUPPORTED                            = 334,
    D3D12_MESSAGE_ID_DEVICE_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_DOUBLEFLOATOPSNOTSUPPORTED            = 335,
    D3D12_MESSAGE_ID_DEVICE_CREATEPIXELSHADER_DOUBLEFLOATOPSNOTSUPPORTED                               = 336,
    D3D12_MESSAGE_ID_DEVICE_CREATECOMPUTESHADER_DOUBLEFLOATOPSNOTSUPPORTED                             = 337,
    D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDRESOURCE                                         = 340,
    D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDDESC                                             = 341,
    D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDFORMAT                                           = 342,
    D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDVIDEOPLANESLICE                                  = 343,
    D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDPLANESLICE                                       = 344,
    D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDDIMENSIONS                                       = 345,
    D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_UNRECOGNIZEDFORMAT                                      = 346,
    D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDFLAGS                                            = 354,
    D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDFORCEDSAMPLECOUNT                                    = 401,
    D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDLOGICOPS                                                  = 403,
    D3D12_MESSAGE_ID_DEVICE_CREATEVERTEXSHADER_DOUBLEEXTENSIONSNOTSUPPORTED                            = 410,
    D3D12_MESSAGE_ID_DEVICE_CREATEHULLSHADER_DOUBLEEXTENSIONSNOTSUPPORTED                              = 412,
    D3D12_MESSAGE_ID_DEVICE_CREATEDOMAINSHADER_DOUBLEEXTENSIONSNOTSUPPORTED                            = 414,
    D3D12_MESSAGE_ID_DEVICE_CREATEGEOMETRYSHADER_DOUBLEEXTENSIONSNOTSUPPORTED                          = 416,
    D3D12_MESSAGE_ID_DEVICE_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_DOUBLEEXTENSIONSNOTSUPPORTED          = 418,
    D3D12_MESSAGE_ID_DEVICE_CREATEPIXELSHADER_DOUBLEEXTENSIONSNOTSUPPORTED                             = 420,
    D3D12_MESSAGE_ID_DEVICE_CREATECOMPUTESHADER_DOUBLEEXTENSIONSNOTSUPPORTED                           = 422,
    D3D12_MESSAGE_ID_DEVICE_CREATEVERTEXSHADER_UAVSNOTSUPPORTED                                        = 425,
    D3D12_MESSAGE_ID_DEVICE_CREATEHULLSHADER_UAVSNOTSUPPORTED                                          = 426,
    D3D12_MESSAGE_ID_DEVICE_CREATEDOMAINSHADER_UAVSNOTSUPPORTED                                        = 427,
    D3D12_MESSAGE_ID_DEVICE_CREATEGEOMETRYSHADER_UAVSNOTSUPPORTED                                      = 428,
    D3D12_MESSAGE_ID_DEVICE_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_UAVSNOTSUPPORTED                      = 429,
    D3D12_MESSAGE_ID_DEVICE_CREATEPIXELSHADER_UAVSNOTSUPPORTED                                         = 430,
    D3D12_MESSAGE_ID_DEVICE_CREATECOMPUTESHADER_UAVSNOTSUPPORTED                                       = 431,
    D3D12_MESSAGE_ID_DEVICE_CLEARVIEW_INVALIDSOURCERECT                                                = 447,
    D3D12_MESSAGE_ID_DEVICE_CLEARVIEW_EMPTYRECT                                                        = 448,
    D3D12_MESSAGE_ID_UPDATETILEMAPPINGS_INVALID_PARAMETER                                              = 493,
    D3D12_MESSAGE_ID_COPYTILEMAPPINGS_INVALID_PARAMETER                                                = 494,
    D3D12_MESSAGE_ID_CREATEDEVICE_INVALIDARGS                                                          = 506,
    D3D12_MESSAGE_ID_CREATEDEVICE_WARNING                                                              = 507,
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_TYPE                                                     = 519,
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_NULL_POINTER                                                     = 520,
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_SUBRESOURCE                                              = 521,
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_RESERVED_BITS                                                    = 522,
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_MISSING_BIND_FLAGS                                               = 523,
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_MISMATCHING_MISC_FLAGS                                           = 524,
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_MATCHING_STATES                                                  = 525,
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_COMBINATION                                              = 526,
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_BEFORE_AFTER_MISMATCH                                            = 527,
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_RESOURCE                                                 = 528,
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_SAMPLE_COUNT                                                     = 529,
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_FLAGS                                                    = 530,
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_COMBINED_FLAGS                                           = 531,
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_FLAGS_FOR_FORMAT                                         = 532,
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_SPLIT_BARRIER                                            = 533,
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_UNMATCHED_END                                                    = 534,
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_UNMATCHED_BEGIN                                                  = 535,
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_FLAG                                                     = 536,
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_COMMAND_LIST_TYPE                                        = 537,
    D3D12_MESSAGE_ID_INVALID_SUBRESOURCE_STATE                                                         = 538,
    D3D12_MESSAGE_ID_COMMAND_ALLOCATOR_CONTENTION                                                      = 540,
    D3D12_MESSAGE_ID_COMMAND_ALLOCATOR_RESET                                                           = 541,
    D3D12_MESSAGE_ID_COMMAND_ALLOCATOR_RESET_BUNDLE                                                    = 542,
    D3D12_MESSAGE_ID_COMMAND_ALLOCATOR_CANNOT_RESET                                                    = 543,
    D3D12_MESSAGE_ID_COMMAND_LIST_OPEN                                                                 = 544,
    D3D12_MESSAGE_ID_INVALID_BUNDLE_API                                                                = 546,
    D3D12_MESSAGE_ID_COMMAND_LIST_CLOSED                                                               = 547,
    D3D12_MESSAGE_ID_WRONG_COMMAND_ALLOCATOR_TYPE                                                      = 549,
    D3D12_MESSAGE_ID_COMMAND_ALLOCATOR_SYNC                                                            = 552,
    D3D12_MESSAGE_ID_COMMAND_LIST_SYNC                                                                 = 553,
    D3D12_MESSAGE_ID_SET_DESCRIPTOR_HEAP_INVALID                                                       = 554,
    D3D12_MESSAGE_ID_CREATE_COMMANDQUEUE                                                               = 557,
    D3D12_MESSAGE_ID_CREATE_COMMANDALLOCATOR                                                           = 558,
    D3D12_MESSAGE_ID_CREATE_PIPELINESTATE                                                              = 559,
    D3D12_MESSAGE_ID_CREATE_COMMANDLIST12                                                              = 560,
    D3D12_MESSAGE_ID_CREATE_RESOURCE                                                                   = 562,
    D3D12_MESSAGE_ID_CREATE_DESCRIPTORHEAP                                                             = 563,
    D3D12_MESSAGE_ID_CREATE_ROOTSIGNATURE                                                              = 564,
    D3D12_MESSAGE_ID_CREATE_LIBRARY                                                                    = 565,
    D3D12_MESSAGE_ID_CREATE_HEAP                                                                       = 566,
    D3D12_MESSAGE_ID_CREATE_MONITOREDFENCE                                                             = 567,
    D3D12_MESSAGE_ID_CREATE_QUERYHEAP                                                                  = 568,
    D3D12_MESSAGE_ID_CREATE_COMMANDSIGNATURE                                                           = 569,
    D3D12_MESSAGE_ID_LIVE_COMMANDQUEUE                                                                 = 570,
    D3D12_MESSAGE_ID_LIVE_COMMANDALLOCATOR                                                             = 571,
    D3D12_MESSAGE_ID_LIVE_PIPELINESTATE                                                                = 572,
    D3D12_MESSAGE_ID_LIVE_COMMANDLIST12                                                                = 573,
    D3D12_MESSAGE_ID_LIVE_RESOURCE                                                                     = 575,
    D3D12_MESSAGE_ID_LIVE_DESCRIPTORHEAP                                                               = 576,
    D3D12_MESSAGE_ID_LIVE_ROOTSIGNATURE                                                                = 577,
    D3D12_MESSAGE_ID_LIVE_LIBRARY                                                                      = 578,
    D3D12_MESSAGE_ID_LIVE_HEAP                                                                         = 579,
    D3D12_MESSAGE_ID_LIVE_MONITOREDFENCE                                                               = 580,
    D3D12_MESSAGE_ID_LIVE_QUERYHEAP                                                                    = 581,
    D3D12_MESSAGE_ID_LIVE_COMMANDSIGNATURE                                                             = 582,
    D3D12_MESSAGE_ID_DESTROY_COMMANDQUEUE                                                              = 583,
    D3D12_MESSAGE_ID_DESTROY_COMMANDALLOCATOR                                                          = 584,
    D3D12_MESSAGE_ID_DESTROY_PIPELINESTATE                                                             = 585,
    D3D12_MESSAGE_ID_DESTROY_COMMANDLIST12                                                             = 586,
    D3D12_MESSAGE_ID_DESTROY_RESOURCE                                                                  = 588,
    D3D12_MESSAGE_ID_DESTROY_DESCRIPTORHEAP                                                            = 589,
    D3D12_MESSAGE_ID_DESTROY_ROOTSIGNATURE                                                             = 590,
    D3D12_MESSAGE_ID_DESTROY_LIBRARY                                                                   = 591,
    D3D12_MESSAGE_ID_DESTROY_HEAP                                                                      = 592,
    D3D12_MESSAGE_ID_DESTROY_MONITOREDFENCE                                                            = 593,
    D3D12_MESSAGE_ID_DESTROY_QUERYHEAP                                                                 = 594,
    D3D12_MESSAGE_ID_DESTROY_COMMANDSIGNATURE                                                          = 595,
    D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDDIMENSIONS                                                  = 597,
    D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDMISCFLAGS                                                   = 599,
    D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDARG_RETURN                                                  = 602,
    D3D12_MESSAGE_ID_CREATERESOURCE_OUTOFMEMORY_RETURN                                                 = 603,
    D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDDESC                                                        = 604,
    D3D12_MESSAGE_ID_POSSIBLY_INVALID_SUBRESOURCE_STATE                                                = 607,
    D3D12_MESSAGE_ID_INVALID_USE_OF_NON_RESIDENT_RESOURCE                                              = 608,
    D3D12_MESSAGE_ID_POSSIBLE_INVALID_USE_OF_NON_RESIDENT_RESOURCE                                     = 609,
    D3D12_MESSAGE_ID_BUNDLE_PIPELINE_STATE_MISMATCH                                                    = 610,
    D3D12_MESSAGE_ID_PRIMITIVE_TOPOLOGY_MISMATCH_PIPELINE_STATE                                        = 611,
    D3D12_MESSAGE_ID_RENDER_TARGET_FORMAT_MISMATCH_PIPELINE_STATE                                      = 613,
    D3D12_MESSAGE_ID_RENDER_TARGET_SAMPLE_DESC_MISMATCH_PIPELINE_STATE                                 = 614,
    D3D12_MESSAGE_ID_DEPTH_STENCIL_FORMAT_MISMATCH_PIPELINE_STATE                                      = 615,
    D3D12_MESSAGE_ID_DEPTH_STENCIL_SAMPLE_DESC_MISMATCH_PIPELINE_STATE                                 = 616,
    D3D12_MESSAGE_ID_CREATESHADER_INVALIDBYTECODE                                                      = 622,
    D3D12_MESSAGE_ID_CREATEHEAP_NULLDESC                                                               = 623,
    D3D12_MESSAGE_ID_CREATEHEAP_INVALIDSIZE                                                            = 624,
    D3D12_MESSAGE_ID_CREATEHEAP_UNRECOGNIZEDHEAPTYPE                                                   = 625,
    D3D12_MESSAGE_ID_CREATEHEAP_UNRECOGNIZEDCPUPAGEPROPERTIES                                          = 626,
    D3D12_MESSAGE_ID_CREATEHEAP_UNRECOGNIZEDMEMORYPOOL                                                 = 627,
    D3D12_MESSAGE_ID_CREATEHEAP_INVALIDPROPERTIES                                                      = 628,
    D3D12_MESSAGE_ID_CREATEHEAP_INVALIDALIGNMENT                                                       = 629,
    D3D12_MESSAGE_ID_CREATEHEAP_UNRECOGNIZEDMISCFLAGS                                                  = 630,
    D3D12_MESSAGE_ID_CREATEHEAP_INVALIDMISCFLAGS                                                       = 631,
    D3D12_MESSAGE_ID_CREATEHEAP_INVALIDARG_RETURN                                                      = 632,
    D3D12_MESSAGE_ID_CREATEHEAP_OUTOFMEMORY_RETURN                                                     = 633,
    D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_NULLHEAPPROPERTIES                                          = 634,
    D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_UNRECOGNIZEDHEAPTYPE                                        = 635,
    D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_UNRECOGNIZEDCPUPAGEPROPERTIES                               = 636,
    D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_UNRECOGNIZEDMEMORYPOOL                                      = 637,
    D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_INVALIDHEAPPROPERTIES                                       = 638,
    D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_UNRECOGNIZEDHEAPMISCFLAGS                                   = 639,
    D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_INVALIDHEAPMISCFLAGS                                        = 640,
    D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_INVALIDARG_RETURN                                           = 641,
    D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_OUTOFMEMORY_RETURN                                          = 642,
    D3D12_MESSAGE_ID_GETCUSTOMHEAPPROPERTIES_UNRECOGNIZEDHEAPTYPE                                      = 643,
    D3D12_MESSAGE_ID_GETCUSTOMHEAPPROPERTIES_INVALIDHEAPTYPE                                           = 644,
    D3D12_MESSAGE_ID_CREATE_DESCRIPTOR_HEAP_INVALID_DESC                                               = 645,
    D3D12_MESSAGE_ID_INVALID_DESCRIPTOR_HANDLE                                                         = 646,
    D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_INVALID_CONSERVATIVERASTERMODE                              = 647,
    D3D12_MESSAGE_ID_CREATE_CONSTANT_BUFFER_VIEW_INVALID_RESOURCE                                      = 649,
    D3D12_MESSAGE_ID_CREATE_CONSTANT_BUFFER_VIEW_INVALID_DESC                                          = 650,
    D3D12_MESSAGE_ID_CREATE_UNORDEREDACCESS_VIEW_INVALID_COUNTER_USAGE                                 = 652,
    D3D12_MESSAGE_ID_COPY_DESCRIPTORS_INVALID_RANGES                                                   = 653,
    D3D12_MESSAGE_ID_COPY_DESCRIPTORS_WRITE_ONLY_DESCRIPTOR                                            = 654,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_RTV_FORMAT_NOT_UNKNOWN                                = 655,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INVALID_RENDER_TARGET_COUNT                           = 656,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_VERTEX_SHADER_NOT_SET                                 = 657,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INPUTLAYOUT_NOT_SET                                   = 658,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_HS_DS_SIGNATURE_MISMATCH               = 659,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_REGISTERINDEX                          = 660,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_COMPONENTTYPE                          = 661,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_REGISTERMASK                           = 662,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_SYSTEMVALUE                            = 663,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_NEVERWRITTEN_ALWAYSREADS               = 664,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_MINPRECISION                           = 665,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_SEMANTICNAME_NOT_FOUND                 = 666,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_HS_XOR_DS_MISMATCH                                    = 667,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_HULL_SHADER_INPUT_TOPOLOGY_MISMATCH                   = 668,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_HS_DS_CONTROL_POINT_COUNT_MISMATCH                    = 669,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_HS_DS_TESSELLATOR_DOMAIN_MISMATCH                     = 670,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INVALID_USE_OF_CENTER_MULTISAMPLE_PATTERN             = 671,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INVALID_USE_OF_FORCED_SAMPLE_COUNT                    = 672,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INVALID_PRIMITIVETOPOLOGY                             = 673,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INVALID_SYSTEMVALUE                                   = 674,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_OM_DUAL_SOURCE_BLENDING_CAN_ONLY_HAVE_RENDER_TARGET_0 = 675,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_OM_RENDER_TARGET_DOES_NOT_SUPPORT_BLENDING            = 676,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_PS_OUTPUT_TYPE_MISMATCH                               = 677,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_OM_RENDER_TARGET_DOES_NOT_SUPPORT_LOGIC_OPS           = 678,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_RENDERTARGETVIEW_NOT_SET                              = 679,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_DEPTHSTENCILVIEW_NOT_SET                              = 680,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_GS_INPUT_PRIMITIVE_MISMATCH                           = 681,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_POSITION_NOT_PRESENT                                  = 682,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_MISSING_ROOT_SIGNATURE_FLAGS                          = 683,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INVALID_INDEX_BUFFER_PROPERTIES                       = 684,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INVALID_SAMPLE_DESC                                   = 685,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_HS_ROOT_SIGNATURE_MISMATCH                            = 686,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_DS_ROOT_SIGNATURE_MISMATCH                            = 687,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_VS_ROOT_SIGNATURE_MISMATCH                            = 688,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_GS_ROOT_SIGNATURE_MISMATCH                            = 689,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_PS_ROOT_SIGNATURE_MISMATCH                            = 690,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_MISSING_ROOT_SIGNATURE                                = 691,
    D3D12_MESSAGE_ID_EXECUTE_BUNDLE_OPEN_BUNDLE                                                        = 692,
    D3D12_MESSAGE_ID_EXECUTE_BUNDLE_DESCRIPTOR_HEAP_MISMATCH                                           = 693,
    D3D12_MESSAGE_ID_EXECUTE_BUNDLE_TYPE                                                               = 694,
    D3D12_MESSAGE_ID_DRAW_EMPTY_SCISSOR_RECTANGLE                                                      = 695,
    D3D12_MESSAGE_ID_CREATE_ROOT_SIGNATURE_BLOB_NOT_FOUND                                              = 696,
    D3D12_MESSAGE_ID_CREATE_ROOT_SIGNATURE_DESERIALIZE_FAILED                                          = 697,
    D3D12_MESSAGE_ID_CREATE_ROOT_SIGNATURE_INVALID_CONFIGURATION                                       = 698,
    D3D12_MESSAGE_ID_CREATE_ROOT_SIGNATURE_NOT_SUPPORTED_ON_DEVICE                                     = 699,
    D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_NULLRESOURCEPROPERTIES                                      = 700,
    D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_NULLHEAP                                                    = 701,
    D3D12_MESSAGE_ID_GETRESOURCEALLOCATIONINFO_INVALIDRDESCS                                           = 702,
    D3D12_MESSAGE_ID_MAKERESIDENT_NULLOBJECTARRAY                                                      = 703,
    D3D12_MESSAGE_ID_EVICT_NULLOBJECTARRAY                                                             = 705,
    D3D12_MESSAGE_ID_SET_DESCRIPTOR_TABLE_INVALID                                                      = 708,
    D3D12_MESSAGE_ID_SET_ROOT_CONSTANT_INVALID                                                         = 709,
    D3D12_MESSAGE_ID_SET_ROOT_CONSTANT_BUFFER_VIEW_INVALID                                             = 710,
    D3D12_MESSAGE_ID_SET_ROOT_SHADER_RESOURCE_VIEW_INVALID                                             = 711,
    D3D12_MESSAGE_ID_SET_ROOT_UNORDERED_ACCESS_VIEW_INVALID                                            = 712,
    D3D12_MESSAGE_ID_SET_VERTEX_BUFFERS_INVALID_DESC                                                   = 713,
    D3D12_MESSAGE_ID_SET_INDEX_BUFFER_INVALID_DESC                                                     = 715,
    D3D12_MESSAGE_ID_SET_STREAM_OUTPUT_BUFFERS_INVALID_DESC                                            = 717,
    D3D12_MESSAGE_ID_CREATERESOURCE_UNRECOGNIZEDDIMENSIONALITY                                         = 718,
    D3D12_MESSAGE_ID_CREATERESOURCE_UNRECOGNIZEDLAYOUT                                                 = 719,
    D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDDIMENSIONALITY                                              = 720,
    D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDALIGNMENT                                                   = 721,
    D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDMIPLEVELS                                                   = 722,
    D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDSAMPLEDESC                                                  = 723,
    D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDLAYOUT                                                      = 724,
    D3D12_MESSAGE_ID_SET_INDEX_BUFFER_INVALID                                                          = 725,
    D3D12_MESSAGE_ID_SET_VERTEX_BUFFERS_INVALID                                                        = 726,
    D3D12_MESSAGE_ID_SET_STREAM_OUTPUT_BUFFERS_INVALID                                                 = 727,
    D3D12_MESSAGE_ID_SET_RENDER_TARGETS_INVALID                                                        = 728,
    D3D12_MESSAGE_ID_CREATEQUERY_HEAP_INVALID_PARAMETERS                                               = 729,
    D3D12_MESSAGE_ID_BEGIN_END_QUERY_INVALID_PARAMETERS                                                = 731,
    D3D12_MESSAGE_ID_CLOSE_COMMAND_LIST_OPEN_QUERY                                                     = 732,
    D3D12_MESSAGE_ID_RESOLVE_QUERY_DATA_INVALID_PARAMETERS                                             = 733,
    D3D12_MESSAGE_ID_SET_PREDICATION_INVALID_PARAMETERS                                                = 734,
    D3D12_MESSAGE_ID_TIMESTAMPS_NOT_SUPPORTED                                                          = 735,
    D3D12_MESSAGE_ID_CREATERESOURCE_UNRECOGNIZEDFORMAT                                                 = 737,
    D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDFORMAT                                                      = 738,
    D3D12_MESSAGE_ID_GETCOPYABLEFOOTPRINTS_INVALIDSUBRESOURCERANGE                                     = 739,
    D3D12_MESSAGE_ID_GETCOPYABLEFOOTPRINTS_INVALIDBASEOFFSET                                           = 740,
    D3D12_MESSAGE_ID_GETCOPYABLELAYOUT_INVALIDSUBRESOURCERANGE                                         = 739,
    D3D12_MESSAGE_ID_GETCOPYABLELAYOUT_INVALIDBASEOFFSET                                               = 740,
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_HEAP                                                     = 741,
    D3D12_MESSAGE_ID_CREATE_SAMPLER_INVALID                                                            = 742,
    D3D12_MESSAGE_ID_CREATECOMMANDSIGNATURE_INVALID                                                    = 743,
    D3D12_MESSAGE_ID_EXECUTE_INDIRECT_INVALID_PARAMETERS                                               = 744,
    D3D12_MESSAGE_ID_GETGPUVIRTUALADDRESS_INVALID_RESOURCE_DIMENSION                                   = 745,
    D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDCLEARVALUE                                                  = 815,
    D3D12_MESSAGE_ID_CREATERESOURCE_UNRECOGNIZEDCLEARVALUEFORMAT                                       = 816,
    D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDCLEARVALUEFORMAT                                            = 817,
    D3D12_MESSAGE_ID_CREATERESOURCE_CLEARVALUEDENORMFLUSH                                              = 818,
    D3D12_MESSAGE_ID_CLEARRENDERTARGETVIEW_MISMATCHINGCLEARVALUE                                       = 820,
    D3D12_MESSAGE_ID_CLEARDEPTHSTENCILVIEW_MISMATCHINGCLEARVALUE                                       = 821,
    D3D12_MESSAGE_ID_MAP_INVALIDHEAP                                                                   = 822,
    D3D12_MESSAGE_ID_UNMAP_INVALIDHEAP                                                                 = 823,
    D3D12_MESSAGE_ID_MAP_INVALIDRESOURCE                                                               = 824,
    D3D12_MESSAGE_ID_UNMAP_INVALIDRESOURCE                                                             = 825,
    D3D12_MESSAGE_ID_MAP_INVALIDSUBRESOURCE                                                            = 826,
    D3D12_MESSAGE_ID_UNMAP_INVALIDSUBRESOURCE                                                          = 827,
    D3D12_MESSAGE_ID_MAP_INVALIDRANGE                                                                  = 828,
    D3D12_MESSAGE_ID_UNMAP_INVALIDRANGE                                                                = 829,
    D3D12_MESSAGE_ID_MAP_INVALIDDATAPOINTER                                                            = 832,
    D3D12_MESSAGE_ID_MAP_INVALIDARG_RETURN                                                             = 833,
    D3D12_MESSAGE_ID_MAP_OUTOFMEMORY_RETURN                                                            = 834,
    D3D12_MESSAGE_ID_EXECUTECOMMANDLISTS_BUNDLENOTSUPPORTED                                            = 835,
    D3D12_MESSAGE_ID_EXECUTECOMMANDLISTS_COMMANDLISTMISMATCH                                           = 836,
    D3D12_MESSAGE_ID_EXECUTECOMMANDLISTS_OPENCOMMANDLIST                                               = 837,
    D3D12_MESSAGE_ID_EXECUTECOMMANDLISTS_FAILEDCOMMANDLIST                                             = 838,
    D3D12_MESSAGE_ID_COPYBUFFERREGION_NULLDST                                                          = 839,
    D3D12_MESSAGE_ID_COPYBUFFERREGION_INVALIDDSTRESOURCEDIMENSION                                      = 840,
    D3D12_MESSAGE_ID_COPYBUFFERREGION_DSTRANGEOUTOFBOUNDS                                              = 841,
    D3D12_MESSAGE_ID_COPYBUFFERREGION_NULLSRC                                                          = 842,
    D3D12_MESSAGE_ID_COPYBUFFERREGION_INVALIDSRCRESOURCEDIMENSION                                      = 843,
    D3D12_MESSAGE_ID_COPYBUFFERREGION_SRCRANGEOUTOFBOUNDS                                              = 844,
    D3D12_MESSAGE_ID_COPYBUFFERREGION_INVALIDCOPYFLAGS                                                 = 845,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_NULLDST                                                         = 846,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_UNRECOGNIZEDDSTTYPE                                             = 847,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTRESOURCEDIMENSION                                     = 848,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTRESOURCE                                              = 849,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTSUBRESOURCE                                           = 850,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTOFFSET                                                = 851,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_UNRECOGNIZEDDSTFORMAT                                           = 852,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTFORMAT                                                = 853,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTDIMENSIONS                                            = 854,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTROWPITCH                                              = 855,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTPLACEMENT                                             = 856,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTDSPLACEDFOOTPRINTFORMAT                               = 857,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_DSTREGIONOUTOFBOUNDS                                            = 858,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_NULLSRC                                                         = 859,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_UNRECOGNIZEDSRCTYPE                                             = 860,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCRESOURCEDIMENSION                                     = 861,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCRESOURCE                                              = 862,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCSUBRESOURCE                                           = 863,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCOFFSET                                                = 864,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_UNRECOGNIZEDSRCFORMAT                                           = 865,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCFORMAT                                                = 866,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCDIMENSIONS                                            = 867,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCROWPITCH                                              = 868,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCPLACEMENT                                             = 869,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCDSPLACEDFOOTPRINTFORMAT                               = 870,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_SRCREGIONOUTOFBOUNDS                                            = 871,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTCOORDINATES                                           = 872,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCBOX                                                   = 873,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_FORMATMISMATCH                                                  = 874,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_EMPTYBOX                                                        = 875,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDCOPYFLAGS                                                = 876,
    D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_INVALID_SUBRESOURCE_INDEX                                      = 877,
    D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_INVALID_FORMAT                                                 = 878,
    D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_RESOURCE_MISMATCH                                              = 879,
    D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_INVALID_SAMPLE_COUNT                                           = 880,
    D3D12_MESSAGE_ID_CREATECOMPUTEPIPELINESTATE_INVALID_SHADER                                         = 881,
    D3D12_MESSAGE_ID_CREATECOMPUTEPIPELINESTATE_CS_ROOT_SIGNATURE_MISMATCH                             = 882,
    D3D12_MESSAGE_ID_CREATECOMPUTEPIPELINESTATE_MISSING_ROOT_SIGNATURE                                 = 883,
    D3D12_MESSAGE_ID_CREATEPIPELINESTATE_INVALIDCACHEDBLOB                                             = 884,
    D3D12_MESSAGE_ID_CREATEPIPELINESTATE_CACHEDBLOBADAPTERMISMATCH                                     = 885,
    D3D12_MESSAGE_ID_CREATEPIPELINESTATE_CACHEDBLOBDRIVERVERSIONMISMATCH                               = 886,
    D3D12_MESSAGE_ID_CREATEPIPELINESTATE_CACHEDBLOBDESCMISMATCH                                        = 887,
    D3D12_MESSAGE_ID_CREATEPIPELINESTATE_CACHEDBLOBIGNORED                                             = 888,
    D3D12_MESSAGE_ID_WRITETOSUBRESOURCE_INVALIDHEAP                                                    = 889,
    D3D12_MESSAGE_ID_WRITETOSUBRESOURCE_INVALIDRESOURCE                                                = 890,
    D3D12_MESSAGE_ID_WRITETOSUBRESOURCE_INVALIDBOX                                                     = 891,
    D3D12_MESSAGE_ID_WRITETOSUBRESOURCE_INVALIDSUBRESOURCE                                             = 892,
    D3D12_MESSAGE_ID_WRITETOSUBRESOURCE_EMPTYBOX                                                       = 893,
    D3D12_MESSAGE_ID_READFROMSUBRESOURCE_INVALIDHEAP                                                   = 894,
    D3D12_MESSAGE_ID_READFROMSUBRESOURCE_INVALIDRESOURCE                                               = 895,
    D3D12_MESSAGE_ID_READFROMSUBRESOURCE_INVALIDBOX                                                    = 896,
    D3D12_MESSAGE_ID_READFROMSUBRESOURCE_INVALIDSUBRESOURCE                                            = 897,
    D3D12_MESSAGE_ID_READFROMSUBRESOURCE_EMPTYBOX                                                      = 898,
    D3D12_MESSAGE_ID_TOO_MANY_NODES_SPECIFIED                                                          = 899,
    D3D12_MESSAGE_ID_INVALID_NODE_INDEX                                                                = 900,
    D3D12_MESSAGE_ID_GETHEAPPROPERTIES_INVALIDRESOURCE                                                 = 901,
    D3D12_MESSAGE_ID_NODE_MASK_MISMATCH                                                                = 902,
    D3D12_MESSAGE_ID_COMMAND_LIST_OUTOFMEMORY                                                          = 903,
    D3D12_MESSAGE_ID_COMMAND_LIST_MULTIPLE_SWAPCHAIN_BUFFER_REFERENCES                                 = 904,
    D3D12_MESSAGE_ID_COMMAND_LIST_TOO_MANY_SWAPCHAIN_REFERENCES                                        = 905,
    D3D12_MESSAGE_ID_COMMAND_QUEUE_TOO_MANY_SWAPCHAIN_REFERENCES                                       = 906,
    D3D12_MESSAGE_ID_EXECUTECOMMANDLISTS_WRONGSWAPCHAINBUFFERREFERENCE                                 = 907,
    D3D12_MESSAGE_ID_COMMAND_LIST_SETRENDERTARGETS_INVALIDNUMRENDERTARGETS                             = 908,
    D3D12_MESSAGE_ID_CREATE_QUEUE_INVALID_TYPE                                                         = 909,
    D3D12_MESSAGE_ID_CREATE_QUEUE_INVALID_FLAGS                                                        = 910,
    D3D12_MESSAGE_ID_CREATESHAREDRESOURCE_INVALIDFLAGS                                                 = 911,
    D3D12_MESSAGE_ID_CREATESHAREDRESOURCE_INVALIDFORMAT                                                = 912,
    D3D12_MESSAGE_ID_CREATESHAREDHEAP_INVALIDFLAGS                                                     = 913,
    D3D12_MESSAGE_ID_REFLECTSHAREDPROPERTIES_UNRECOGNIZEDPROPERTIES                                    = 914,
    D3D12_MESSAGE_ID_REFLECTSHAREDPROPERTIES_INVALIDSIZE                                               = 915,
    D3D12_MESSAGE_ID_REFLECTSHAREDPROPERTIES_INVALIDOBJECT                                             = 916,
    D3D12_MESSAGE_ID_KEYEDMUTEX_INVALIDOBJECT                                                          = 917,
    D3D12_MESSAGE_ID_KEYEDMUTEX_INVALIDKEY                                                             = 918,
    D3D12_MESSAGE_ID_KEYEDMUTEX_WRONGSTATE                                                             = 919,
    D3D12_MESSAGE_ID_CREATE_QUEUE_INVALID_PRIORITY                                                     = 920,
    D3D12_MESSAGE_ID_OBJECT_DELETED_WHILE_STILL_IN_USE                                                 = 921,
    D3D12_MESSAGE_ID_CREATEPIPELINESTATE_INVALID_FLAGS                                                 = 922,
    D3D12_MESSAGE_ID_HEAP_ADDRESS_RANGE_HAS_NO_RESOURCE                                                = 923,
    D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_RENDER_TARGET_DELETED                                           = 924,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_ALL_RENDER_TARGETS_HAVE_UNKNOWN_FORMAT                = 925,
    D3D12_MESSAGE_ID_HEAP_ADDRESS_RANGE_INTERSECTS_MULTIPLE_BUFFERS                                    = 926,
    D3D12_MESSAGE_ID_EXECUTECOMMANDLISTS_GPU_WRITTEN_READBACK_RESOURCE_MAPPED                          = 927,
    D3D12_MESSAGE_ID_UNMAP_RANGE_NOT_EMPTY                                                             = 929,
    D3D12_MESSAGE_ID_MAP_INVALID_NULLRANGE                                                             = 930,
    D3D12_MESSAGE_ID_UNMAP_INVALID_NULLRANGE                                                           = 931,
    D3D12_MESSAGE_ID_NO_GRAPHICS_API_SUPPORT                                                           = 932,
    D3D12_MESSAGE_ID_NO_COMPUTE_API_SUPPORT                                                            = 933,
    D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_RESOURCE_FLAGS_NOT_SUPPORTED                                   = 934,
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_ROOT_ARGUMENT_UNINITIALIZED                                  = 935,
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_DESCRIPTOR_HEAP_INDEX_OUT_OF_BOUNDS                          = 936,
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_DESCRIPTOR_TABLE_REGISTER_INDEX_OUT_OF_BOUNDS                = 937,
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_DESCRIPTOR_UNINITIALIZED                                     = 938,
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_DESCRIPTOR_TYPE_MISMATCH                                     = 939,
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_SRV_RESOURCE_DIMENSION_MISMATCH                              = 940,
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_UAV_RESOURCE_DIMENSION_MISMATCH                              = 941,
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_INCOMPATIBLE_RESOURCE_STATE                                  = 942,
    D3D12_MESSAGE_ID_COPYRESOURCE_NULLDST                                                              = 943,
    D3D12_MESSAGE_ID_COPYRESOURCE_INVALIDDSTRESOURCE                                                   = 944,
    D3D12_MESSAGE_ID_COPYRESOURCE_NULLSRC                                                              = 945,
    D3D12_MESSAGE_ID_COPYRESOURCE_INVALIDSRCRESOURCE                                                   = 946,
    D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_NULLDST                                                        = 947,
    D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_INVALIDDSTRESOURCE                                             = 948,
    D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_NULLSRC                                                        = 949,
    D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_INVALIDSRCRESOURCE                                             = 950,
    D3D12_MESSAGE_ID_PIPELINE_STATE_TYPE_MISMATCH                                                      = 951,
    D3D12_MESSAGE_ID_COMMAND_LIST_DISPATCH_ROOT_SIGNATURE_NOT_SET                                      = 952,
    D3D12_MESSAGE_ID_COMMAND_LIST_DISPATCH_ROOT_SIGNATURE_MISMATCH                                     = 953,
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_ZERO_BARRIERS                                                    = 954,
    D3D12_MESSAGE_ID_BEGIN_END_EVENT_MISMATCH                                                          = 955,
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_POSSIBLE_BEFORE_AFTER_MISMATCH                                   = 956,
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_MISMATCHING_BEGIN_END                                            = 957,
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_INVALID_RESOURCE                                             = 958,
    D3D12_MESSAGE_ID_USE_OF_ZERO_REFCOUNT_OBJECT                                                       = 959,
    D3D12_MESSAGE_ID_OBJECT_EVICTED_WHILE_STILL_IN_USE                                                 = 960,
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_ROOT_DESCRIPTOR_ACCESS_OUT_OF_BOUNDS                         = 961,
    D3D12_MESSAGE_ID_CREATEPIPELINELIBRARY_INVALIDLIBRARYBLOB                                          = 962,
    D3D12_MESSAGE_ID_CREATEPIPELINELIBRARY_DRIVERVERSIONMISMATCH                                       = 963,
    D3D12_MESSAGE_ID_CREATEPIPELINELIBRARY_ADAPTERVERSIONMISMATCH                                      = 964,
    D3D12_MESSAGE_ID_CREATEPIPELINELIBRARY_UNSUPPORTED                                                 = 965,
    D3D12_MESSAGE_ID_CREATE_PIPELINELIBRARY                                                            = 966,
    D3D12_MESSAGE_ID_LIVE_PIPELINELIBRARY                                                              = 967,
    D3D12_MESSAGE_ID_DESTROY_PIPELINELIBRARY                                                           = 968,
    D3D12_MESSAGE_ID_STOREPIPELINE_NONAME                                                              = 969,
    D3D12_MESSAGE_ID_STOREPIPELINE_DUPLICATENAME                                                       = 970,
    D3D12_MESSAGE_ID_LOADPIPELINE_NAMENOTFOUND                                                         = 971,
    D3D12_MESSAGE_ID_LOADPIPELINE_INVALIDDESC                                                          = 972,
    D3D12_MESSAGE_ID_PIPELINELIBRARY_SERIALIZE_NOTENOUGHMEMORY                                         = 973,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_PS_OUTPUT_RT_OUTPUT_MISMATCH                          = 974,
    D3D12_MESSAGE_ID_SETEVENTONMULTIPLEFENCECOMPLETION_INVALIDFLAGS                                    = 975,
    D3D12_MESSAGE_ID_CREATE_QUEUE_VIDEO_NOT_SUPPORTED                                                  = 976,
    D3D12_MESSAGE_ID_CREATE_COMMAND_ALLOCATOR_VIDEO_NOT_SUPPORTED                                      = 977,
    D3D12_MESSAGE_ID_CREATEQUERY_HEAP_VIDEO_DECODE_STATISTICS_NOT_SUPPORTED                            = 978,
    D3D12_MESSAGE_ID_CREATE_VIDEODECODECOMMANDLIST                                                     = 979,
    D3D12_MESSAGE_ID_CREATE_VIDEODECODER                                                               = 980,
    D3D12_MESSAGE_ID_CREATE_VIDEODECODESTREAM                                                          = 981,
    D3D12_MESSAGE_ID_LIVE_VIDEODECODECOMMANDLIST                                                       = 982,
    D3D12_MESSAGE_ID_LIVE_VIDEODECODER                                                                 = 983,
    D3D12_MESSAGE_ID_LIVE_VIDEODECODESTREAM                                                            = 984,
    D3D12_MESSAGE_ID_DESTROY_VIDEODECODECOMMANDLIST                                                    = 985,
    D3D12_MESSAGE_ID_DESTROY_VIDEODECODER                                                              = 986,
    D3D12_MESSAGE_ID_DESTROY_VIDEODECODESTREAM                                                         = 987,
    D3D12_MESSAGE_ID_DECODE_FRAME_INVALID_PARAMETERS                                                   = 988,
    D3D12_MESSAGE_ID_DEPRECATED_API                                                                    = 989,
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_MISMATCHING_COMMAND_LIST_TYPE                                    = 990,
    D3D12_MESSAGE_ID_COMMAND_LIST_DESCRIPTOR_TABLE_NOT_SET                                             = 991,
    D3D12_MESSAGE_ID_COMMAND_LIST_ROOT_CONSTANT_BUFFER_VIEW_NOT_SET                                    = 992,
    D3D12_MESSAGE_ID_COMMAND_LIST_ROOT_SHADER_RESOURCE_VIEW_NOT_SET                                    = 993,
    D3D12_MESSAGE_ID_COMMAND_LIST_ROOT_UNORDERED_ACCESS_VIEW_NOT_SET                                   = 994,
    D3D12_MESSAGE_ID_DISCARD_INVALID_SUBRESOURCE_RANGE                                                 = 995,
    D3D12_MESSAGE_ID_DISCARD_ONE_SUBRESOURCE_FOR_MIPS_WITH_RECTS                                       = 996,
    D3D12_MESSAGE_ID_DISCARD_NO_RECTS_FOR_NON_TEXTURE2D                                                = 997,
    D3D12_MESSAGE_ID_COPY_ON_SAME_SUBRESOURCE                                                          = 998,
    D3D12_MESSAGE_ID_SETRESIDENCYPRIORITY_INVALID_PAGEABLE                                             = 999,
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_UNSUPPORTED                                                  = 1000,
    D3D12_MESSAGE_ID_STATIC_DESCRIPTOR_INVALID_DESCRIPTOR_CHANGE                                       = 1001,
    D3D12_MESSAGE_ID_DATA_STATIC_DESCRIPTOR_INVALID_DATA_CHANGE                                        = 1002,
    D3D12_MESSAGE_ID_DATA_STATIC_WHILE_SET_AT_EXECUTE_DESCRIPTOR_INVALID_DATA_CHANGE                   = 1003,
    D3D12_MESSAGE_ID_EXECUTE_BUNDLE_STATIC_DESCRIPTOR_DATA_STATIC_NOT_SET                              = 1004,
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_RESOURCE_ACCESS_OUT_OF_BOUNDS                                = 1005,
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_SAMPLER_MODE_MISMATCH                                        = 1006,
    D3D12_MESSAGE_ID_CREATE_FENCE_INVALID_FLAGS                                                        = 1007,
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_DUPLICATE_SUBRESOURCE_TRANSITIONS                                = 1008,
    D3D12_MESSAGE_ID_SETRESIDENCYPRIORITY_INVALID_PRIORITY                                             = 1009,
    D3D12_MESSAGE_ID_CREATE_DESCRIPTOR_HEAP_LARGE_NUM_DESCRIPTORS                                      = 1013,
    D3D12_MESSAGE_ID_BEGIN_EVENT                                                                       = 1014,
    D3D12_MESSAGE_ID_END_EVENT                                                                         = 1015,
    D3D12_MESSAGE_ID_CREATEDEVICE_DEBUG_LAYER_STARTUP_OPTIONS                                          = 1016,
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_DEPTHBOUNDSTEST_UNSUPPORTED                               = 1017,
    D3D12_MESSAGE_ID_CREATEPIPELINESTATE_DUPLICATE_SUBOBJECT                                           = 1018,
    D3D12_MESSAGE_ID_CREATEPIPELINESTATE_UNKNOWN_SUBOBJECT                                             = 1019,
    D3D12_MESSAGE_ID_CREATEPIPELINESTATE_ZERO_SIZE_STREAM                                              = 1020,
    D3D12_MESSAGE_ID_CREATEPIPELINESTATE_INVALID_STREAM                                                = 1021,
    D3D12_MESSAGE_ID_CREATEPIPELINESTATE_CANNOT_DEDUCE_TYPE                                            = 1022,
    D3D12_MESSAGE_ID_COMMAND_LIST_STATIC_DESCRIPTOR_RESOURCE_DIMENSION_MISMATCH                        = 1023,
    D3D12_MESSAGE_ID_CREATE_COMMAND_QUEUE_INSUFFICIENT_PRIVILEGE_FOR_GLOBAL_REALTIME                   = 1024,
    D3D12_MESSAGE_ID_CREATE_COMMAND_QUEUE_INSUFFICIENT_HARDWARE_SUPPORT_FOR_GLOBAL_REALTIME            = 1025,
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_ARCHITECTURE                                             = 1026,
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_NULL_DST                                                         = 1027,
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_DST_RESOURCE_DIMENSION                                   = 1028,
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_DST_RANGE_OUT_OF_BOUNDS                                          = 1029,
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_NULL_SRC                                                         = 1030,
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_SRC_RESOURCE_DIMENSION                                   = 1031,
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_SRC_RANGE_OUT_OF_BOUNDS                                          = 1032,
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_OFFSET_ALIGNMENT                                         = 1033,
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_NULL_DEPENDENT_RESOURCES                                         = 1034,
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_NULL_DEPENDENT_SUBRESOURCE_RANGES                                = 1035,
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_DEPENDENT_RESOURCE                                       = 1036,
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_DEPENDENT_SUBRESOURCE_RANGE                              = 1037,
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_DEPENDENT_SUBRESOURCE_OUT_OF_BOUNDS                              = 1038,
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_DEPENDENT_RANGE_OUT_OF_BOUNDS                                    = 1039,
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_ZERO_DEPENDENCIES                                                = 1040,
    D3D12_MESSAGE_ID_DEVICE_CREATE_SHARED_HANDLE_INVALIDARG                                            = 1041,
    D3D12_MESSAGE_ID_DESCRIPTOR_HANDLE_WITH_INVALID_RESOURCE                                           = 1042,
    D3D12_MESSAGE_ID_SETDEPTHBOUNDS_INVALIDARGS                                                        = 1043,
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_RESOURCE_STATE_IMPRECISE                                     = 1044,
    D3D12_MESSAGE_ID_COMMAND_LIST_PIPELINE_STATE_NOT_SET                                               = 1045,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_MODEL_MISMATCH                                 = 1046,
    D3D12_MESSAGE_ID_OBJECT_ACCESSED_WHILE_STILL_IN_USE                                                = 1047,
    D3D12_MESSAGE_ID_PROGRAMMABLE_MSAA_UNSUPPORTED                                                     = 1048,
    D3D12_MESSAGE_ID_SETSAMPLEPOSITIONS_INVALIDARGS                                                    = 1049,
    D3D12_MESSAGE_ID_RESOLVESUBRESOURCEREGION_INVALID_RECT                                             = 1050,
    D3D12_MESSAGE_ID_CREATE_VIDEODECODECOMMANDQUEUE                                                    = 1051,
    D3D12_MESSAGE_ID_CREATE_VIDEOPROCESSCOMMANDLIST                                                    = 1052,
    D3D12_MESSAGE_ID_CREATE_VIDEOPROCESSCOMMANDQUEUE                                                   = 1053,
    D3D12_MESSAGE_ID_LIVE_VIDEODECODECOMMANDQUEUE                                                      = 1054,
    D3D12_MESSAGE_ID_LIVE_VIDEOPROCESSCOMMANDLIST                                                      = 1055,
    D3D12_MESSAGE_ID_LIVE_VIDEOPROCESSCOMMANDQUEUE                                                     = 1056,
    D3D12_MESSAGE_ID_DESTROY_VIDEODECODECOMMANDQUEUE                                                   = 1057,
    D3D12_MESSAGE_ID_DESTROY_VIDEOPROCESSCOMMANDLIST                                                   = 1058,
    D3D12_MESSAGE_ID_DESTROY_VIDEOPROCESSCOMMANDQUEUE                                                  = 1059,
    D3D12_MESSAGE_ID_CREATE_VIDEOPROCESSOR                                                             = 1060,
    D3D12_MESSAGE_ID_CREATE_VIDEOPROCESSSTREAM                                                         = 1061,
    D3D12_MESSAGE_ID_LIVE_VIDEOPROCESSOR                                                               = 1062,
    D3D12_MESSAGE_ID_LIVE_VIDEOPROCESSSTREAM                                                           = 1063,
    D3D12_MESSAGE_ID_DESTROY_VIDEOPROCESSOR                                                            = 1064,
    D3D12_MESSAGE_ID_DESTROY_VIDEOPROCESSSTREAM                                                        = 1065,
    D3D12_MESSAGE_ID_PROCESS_FRAME_INVALID_PARAMETERS                                                  = 1066,
    D3D12_MESSAGE_ID_COPY_INVALIDLAYOUT                                                                = 1067,
    D3D12_MESSAGE_ID_CREATE_CRYPTO_SESSION                                                             = 1068,
    D3D12_MESSAGE_ID_CREATE_CRYPTO_SESSION_POLICY                                                      = 1069,
    D3D12_MESSAGE_ID_CREATE_PROTECTED_RESOURCE_SESSION                                                 = 1070,
    D3D12_MESSAGE_ID_LIVE_CRYPTO_SESSION                                                               = 1071,
    D3D12_MESSAGE_ID_LIVE_CRYPTO_SESSION_POLICY                                                        = 1072,
    D3D12_MESSAGE_ID_LIVE_PROTECTED_RESOURCE_SESSION                                                   = 1073,
    D3D12_MESSAGE_ID_DESTROY_CRYPTO_SESSION                                                            = 1074,
    D3D12_MESSAGE_ID_DESTROY_CRYPTO_SESSION_POLICY                                                     = 1075,
    D3D12_MESSAGE_ID_DESTROY_PROTECTED_RESOURCE_SESSION                                                = 1076,
    D3D12_MESSAGE_ID_PROTECTED_RESOURCE_SESSION_UNSUPPORTED                                            = 1077,
    D3D12_MESSAGE_ID_FENCE_INVALIDOPERATION                                                            = 1078,
    D3D12_MESSAGE_ID_CREATEQUERY_HEAP_COPY_QUEUE_TIMESTAMPS_NOT_SUPPORTED                              = 1079,
    D3D12_MESSAGE_ID_SAMPLEPOSITIONS_MISMATCH_DEFERRED                                                 = 1080,
    D3D12_MESSAGE_ID_SAMPLEPOSITIONS_MISMATCH_RECORDTIME_ASSUMEDFROMFIRSTUSE                           = 1081,
    D3D12_MESSAGE_ID_SAMPLEPOSITIONS_MISMATCH_RECORDTIME_ASSUMEDFROMCLEAR                              = 1082,
    D3D12_MESSAGE_ID_CREATE_VIDEODECODERHEAP                                                           = 1083,
    D3D12_MESSAGE_ID_LIVE_VIDEODECODERHEAP                                                             = 1084,
    D3D12_MESSAGE_ID_DESTROY_VIDEODECODERHEAP                                                          = 1085,
    D3D12_MESSAGE_ID_OPENEXISTINGHEAP_INVALIDARG_RETURN                                                = 1086,
    D3D12_MESSAGE_ID_OPENEXISTINGHEAP_OUTOFMEMORY_RETURN                                               = 1087,
    D3D12_MESSAGE_ID_OPENEXISTINGHEAP_INVALIDADDRESS                                                   = 1088,
    D3D12_MESSAGE_ID_OPENEXISTINGHEAP_INVALIDHANDLE                                                    = 1089,
    D3D12_MESSAGE_ID_WRITEBUFFERIMMEDIATE_INVALID_DEST                                                 = 1090,
    D3D12_MESSAGE_ID_WRITEBUFFERIMMEDIATE_INVALID_MODE                                                 = 1091,
    D3D12_MESSAGE_ID_WRITEBUFFERIMMEDIATE_INVALID_ALIGNMENT                                            = 1092,
    D3D12_MESSAGE_ID_WRITEBUFFERIMMEDIATE_NOT_SUPPORTED                                                = 1093,
    D3D12_MESSAGE_ID_SETVIEWINSTANCEMASK_INVALIDARGS                                                   = 1094,
    D3D12_MESSAGE_ID_VIEW_INSTANCING_UNSUPPORTED                                                       = 1095,
    D3D12_MESSAGE_ID_VIEW_INSTANCING_INVALIDARGS                                                       = 1096,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_MISMATCH_DECODE_REFERENCE_ONLY_FLAG                             = 1097,
    D3D12_MESSAGE_ID_COPYRESOURCE_MISMATCH_DECODE_REFERENCE_ONLY_FLAG                                  = 1098,
    D3D12_MESSAGE_ID_CREATE_VIDEO_DECODE_HEAP_CAPS_FAILURE                                             = 1099,
    D3D12_MESSAGE_ID_CREATE_VIDEO_DECODE_HEAP_CAPS_UNSUPPORTED                                         = 1100,
    D3D12_MESSAGE_ID_VIDEO_DECODE_SUPPORT_INVALID_INPUT                                                = 1101,
    D3D12_MESSAGE_ID_CREATE_VIDEO_DECODER_UNSUPPORTED                                                  = 1102,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_METADATA_ERROR                                        = 1103,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_VIEW_INSTANCING_VERTEX_SIZE_EXCEEDED                  = 1104,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_RUNTIME_INTERNAL_ERROR                                = 1105,
    D3D12_MESSAGE_ID_NO_VIDEO_API_SUPPORT                                                              = 1106,
    D3D12_MESSAGE_ID_VIDEO_PROCESS_SUPPORT_INVALID_INPUT                                               = 1107,
    D3D12_MESSAGE_ID_CREATE_VIDEO_PROCESSOR_CAPS_FAILURE                                               = 1108,
    D3D12_MESSAGE_ID_VIDEO_PROCESS_SUPPORT_UNSUPPORTED_FORMAT                                          = 1109,
    D3D12_MESSAGE_ID_VIDEO_DECODE_FRAME_INVALID_ARGUMENT                                               = 1110,
    D3D12_MESSAGE_ID_ENQUEUE_MAKE_RESIDENT_INVALID_FLAGS                                               = 1111,
    D3D12_MESSAGE_ID_OPENEXISTINGHEAP_UNSUPPORTED                                                      = 1112,
    D3D12_MESSAGE_ID_VIDEO_PROCESS_FRAMES_INVALID_ARGUMENT                                             = 1113,
    D3D12_MESSAGE_ID_VIDEO_DECODE_SUPPORT_UNSUPPORTED                                                  = 1114,
    D3D12_MESSAGE_ID_CREATE_COMMANDRECORDER                                                            = 1115,
    D3D12_MESSAGE_ID_LIVE_COMMANDRECORDER                                                              = 1116,
    D3D12_MESSAGE_ID_DESTROY_COMMANDRECORDER                                                           = 1117,
    D3D12_MESSAGE_ID_CREATE_COMMAND_RECORDER_VIDEO_NOT_SUPPORTED                                       = 1118,
    D3D12_MESSAGE_ID_CREATE_COMMAND_RECORDER_INVALID_SUPPORT_FLAGS                                     = 1119,
    D3D12_MESSAGE_ID_CREATE_COMMAND_RECORDER_INVALID_FLAGS                                             = 1120,
    D3D12_MESSAGE_ID_CREATE_COMMAND_RECORDER_MORE_RECORDERS_THAN_LOGICAL_PROCESSORS                    = 1121,
    D3D12_MESSAGE_ID_CREATE_COMMANDPOOL                                                                = 1122,
    D3D12_MESSAGE_ID_LIVE_COMMANDPOOL                                                                  = 1123,
    D3D12_MESSAGE_ID_DESTROY_COMMANDPOOL                                                               = 1124,
    D3D12_MESSAGE_ID_CREATE_COMMAND_POOL_INVALID_FLAGS                                                 = 1125,
    D3D12_MESSAGE_ID_CREATE_COMMAND_LIST_VIDEO_NOT_SUPPORTED                                           = 1126,
    D3D12_MESSAGE_ID_COMMAND_RECORDER_SUPPORT_FLAGS_MISMATCH                                           = 1127,
    D3D12_MESSAGE_ID_COMMAND_RECORDER_CONTENTION                                                       = 1128,
    D3D12_MESSAGE_ID_COMMAND_RECORDER_USAGE_WITH_CREATECOMMANDLIST_COMMAND_LIST                        = 1129,
    D3D12_MESSAGE_ID_COMMAND_ALLOCATOR_USAGE_WITH_CREATECOMMANDLIST1_COMMAND_LIST                      = 1130,
    D3D12_MESSAGE_ID_CANNOT_EXECUTE_EMPTY_COMMAND_LIST                                                 = 1131,
    D3D12_MESSAGE_ID_CANNOT_RESET_COMMAND_POOL_WITH_OPEN_COMMAND_LISTS                                 = 1132,
    D3D12_MESSAGE_ID_CANNOT_USE_COMMAND_RECORDER_WITHOUT_CURRENT_TARGET                                = 1133,
    D3D12_MESSAGE_ID_CANNOT_CHANGE_COMMAND_RECORDER_TARGET_WHILE_RECORDING                             = 1134,
    D3D12_MESSAGE_ID_COMMAND_POOL_SYNC                                                                 = 1135,
    D3D12_MESSAGE_ID_EVICT_UNDERFLOW                                                                   = 1136,
    D3D12_MESSAGE_ID_CREATE_META_COMMAND                                                               = 1137,
    D3D12_MESSAGE_ID_LIVE_META_COMMAND                                                                 = 1138,
    D3D12_MESSAGE_ID_DESTROY_META_COMMAND                                                              = 1139,
    D3D12_MESSAGE_ID_COPYBUFFERREGION_INVALID_DST_RESOURCE                                             = 1140,
    D3D12_MESSAGE_ID_COPYBUFFERREGION_INVALID_SRC_RESOURCE                                             = 1141,
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_DST_RESOURCE                                             = 1142,
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_SRC_RESOURCE                                             = 1143,
    D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_NULL_BUFFER                                          = 1144,
    D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_NULL_RESOURCE_DESC                                   = 1145,
    D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_UNSUPPORTED                                          = 1146,
    D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_INVALID_BUFFER_DIMENSION                             = 1147,
    D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_INVALID_BUFFER_FLAGS                                 = 1148,
    D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_INVALID_BUFFER_OFFSET                                = 1149,
    D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_INVALID_RESOURCE_DIMENSION                           = 1150,
    D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_INVALID_RESOURCE_FLAGS                               = 1151,
    D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_OUTOFMEMORY_RETURN                                   = 1152,
    D3D12_MESSAGE_ID_CANNOT_CREATE_GRAPHICS_AND_VIDEO_COMMAND_RECORDER                                 = 1153,
    D3D12_MESSAGE_ID_UPDATETILEMAPPINGS_POSSIBLY_MISMATCHING_PROPERTIES                                = 1154,
    D3D12_MESSAGE_ID_CREATE_COMMAND_LIST_INVALID_COMMAND_LIST_TYPE                                     = 1155,
    D3D12_MESSAGE_ID_CLEARUNORDEREDACCESSVIEW_INCOMPATIBLE_WITH_STRUCTURED_BUFFERS                     = 1156,
    D3D12_MESSAGE_ID_COMPUTE_ONLY_DEVICE_OPERATION_UNSUPPORTED                                         = 1157,
    D3D12_MESSAGE_ID_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INVALID                                   = 1158,
    D3D12_MESSAGE_ID_EMIT_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_INVALID                     = 1159,
    D3D12_MESSAGE_ID_COPY_RAYTRACING_ACCELERATION_STRUCTURE_INVALID                                    = 1160,
    D3D12_MESSAGE_ID_DISPATCH_RAYS_INVALID                                                             = 1161,
    D3D12_MESSAGE_ID_GET_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO_INVALID                       = 1162,
    D3D12_MESSAGE_ID_CREATE_LIFETIMETRACKER                                                            = 1163,
    D3D12_MESSAGE_ID_LIVE_LIFETIMETRACKER                                                              = 1164,
    D3D12_MESSAGE_ID_DESTROY_LIFETIMETRACKER                                                           = 1165,
    D3D12_MESSAGE_ID_DESTROYOWNEDOBJECT_OBJECTNOTOWNED                                                 = 1166,
    D3D12_MESSAGE_ID_CREATE_TRACKEDWORKLOAD                                                            = 1167,
    D3D12_MESSAGE_ID_LIVE_TRACKEDWORKLOAD                                                              = 1168,
    D3D12_MESSAGE_ID_DESTROY_TRACKEDWORKLOAD                                                           = 1169,
    D3D12_MESSAGE_ID_RENDER_PASS_ERROR                                                                 = 1170,
    D3D12_MESSAGE_ID_META_COMMAND_ID_INVALID                                                           = 1171,
    D3D12_MESSAGE_ID_META_COMMAND_UNSUPPORTED_PARAMS                                                   = 1172,
    D3D12_MESSAGE_ID_META_COMMAND_FAILED_ENUMERATION                                                   = 1173,
    D3D12_MESSAGE_ID_META_COMMAND_PARAMETER_SIZE_MISMATCH                                              = 1174,
    D3D12_MESSAGE_ID_UNINITIALIZED_META_COMMAND                                                        = 1175,
    D3D12_MESSAGE_ID_META_COMMAND_INVALID_GPU_VIRTUAL_ADDRESS                                          = 1176,
    D3D12_MESSAGE_ID_CREATE_VIDEOENCODECOMMANDLIST                                                     = 1177,
    D3D12_MESSAGE_ID_LIVE_VIDEOENCODECOMMANDLIST                                                       = 1178,
    D3D12_MESSAGE_ID_DESTROY_VIDEOENCODECOMMANDLIST                                                    = 1179,
    D3D12_MESSAGE_ID_CREATE_VIDEOENCODECOMMANDQUEUE                                                    = 1180,
    D3D12_MESSAGE_ID_LIVE_VIDEOENCODECOMMANDQUEUE                                                      = 1181,
    D3D12_MESSAGE_ID_DESTROY_VIDEOENCODECOMMANDQUEUE                                                   = 1182,
    D3D12_MESSAGE_ID_CREATE_VIDEOMOTIONESTIMATOR                                                       = 1183,
    D3D12_MESSAGE_ID_LIVE_VIDEOMOTIONESTIMATOR                                                         = 1184,
    D3D12_MESSAGE_ID_DESTROY_VIDEOMOTIONESTIMATOR                                                      = 1185,
    D3D12_MESSAGE_ID_CREATE_VIDEOMOTIONVECTORHEAP                                                      = 1186,
    D3D12_MESSAGE_ID_LIVE_VIDEOMOTIONVECTORHEAP                                                        = 1187,
    D3D12_MESSAGE_ID_DESTROY_VIDEOMOTIONVECTORHEAP                                                     = 1188,
    D3D12_MESSAGE_ID_MULTIPLE_TRACKED_WORKLOADS                                                        = 1189,
    D3D12_MESSAGE_ID_MULTIPLE_TRACKED_WORKLOAD_PAIRS                                                   = 1190,
    D3D12_MESSAGE_ID_OUT_OF_ORDER_TRACKED_WORKLOAD_PAIR                                                = 1191,
    D3D12_MESSAGE_ID_CANNOT_ADD_TRACKED_WORKLOAD                                                       = 1192,
    D3D12_MESSAGE_ID_INCOMPLETE_TRACKED_WORKLOAD_PAIR                                                  = 1193,
    D3D12_MESSAGE_ID_CREATE_STATE_OBJECT_ERROR                                                         = 1194,
    D3D12_MESSAGE_ID_GET_SHADER_IDENTIFIER_ERROR                                                       = 1195,
    D3D12_MESSAGE_ID_GET_SHADER_STACK_SIZE_ERROR                                                       = 1196,
    D3D12_MESSAGE_ID_GET_PIPELINE_STACK_SIZE_ERROR                                                     = 1197,
    D3D12_MESSAGE_ID_SET_PIPELINE_STACK_SIZE_ERROR                                                     = 1198,
    D3D12_MESSAGE_ID_GET_SHADER_IDENTIFIER_SIZE_INVALID                                                = 1199,
    D3D12_MESSAGE_ID_CHECK_DRIVER_MATCHING_IDENTIFIER_INVALID                                          = 1200,
    D3D12_MESSAGE_ID_CHECK_DRIVER_MATCHING_IDENTIFIER_DRIVER_REPORTED_ISSUE                            = 1201,
    D3D12_MESSAGE_ID_RENDER_PASS_INVALID_RESOURCE_BARRIER                                              = 1202,
    D3D12_MESSAGE_ID_RENDER_PASS_DISALLOWED_API_CALLED                                                 = 1203,
    D3D12_MESSAGE_ID_RENDER_PASS_CANNOT_NEST_RENDER_PASSES                                             = 1204,
    D3D12_MESSAGE_ID_RENDER_PASS_CANNOT_END_WITHOUT_BEGIN                                              = 1205,
    D3D12_MESSAGE_ID_RENDER_PASS_CANNOT_CLOSE_COMMAND_LIST                                             = 1206,
    D3D12_MESSAGE_ID_RENDER_PASS_GPU_WORK_WHILE_SUSPENDED                                              = 1207,
    D3D12_MESSAGE_ID_RENDER_PASS_MISMATCHING_SUSPEND_RESUME                                            = 1208,
    D3D12_MESSAGE_ID_RENDER_PASS_NO_PRIOR_SUSPEND_WITHIN_EXECUTECOMMANDLISTS                           = 1209,
    D3D12_MESSAGE_ID_RENDER_PASS_NO_SUBSEQUENT_RESUME_WITHIN_EXECUTECOMMANDLISTS                       = 1210,
    D3D12_MESSAGE_ID_TRACKED_WORKLOAD_COMMAND_QUEUE_MISMATCH                                           = 1211,
    D3D12_MESSAGE_ID_TRACKED_WORKLOAD_NOT_SUPPORTED                                                    = 1212,
    D3D12_MESSAGE_ID_RENDER_PASS_MISMATCHING_NO_ACCESS                                                 = 1213,
    D3D12_MESSAGE_ID_RENDER_PASS_UNSUPPORTED_RESOLVE                                                   = 1214,
    D3D12_MESSAGE_ID_CLEARUNORDEREDACCESSVIEW_INVALID_RESOURCE_PTR                                     = 1215,
    D3D12_MESSAGE_ID_WINDOWS7_FENCE_OUTOFORDER_SIGNAL                                                  = 1216,
    D3D12_MESSAGE_ID_WINDOWS7_FENCE_OUTOFORDER_WAIT                                                    = 1217,
    D3D12_MESSAGE_ID_VIDEO_CREATE_MOTION_ESTIMATOR_INVALID_ARGUMENT                                    = 1218,
    D3D12_MESSAGE_ID_VIDEO_CREATE_MOTION_VECTOR_HEAP_INVALID_ARGUMENT                                  = 1219,
    D3D12_MESSAGE_ID_ESTIMATE_MOTION_INVALID_ARGUMENT                                                  = 1220,
    D3D12_MESSAGE_ID_RESOLVE_MOTION_VECTOR_HEAP_INVALID_ARGUMENT                                       = 1221,
    D3D12_MESSAGE_ID_GETGPUVIRTUALADDRESS_INVALID_HEAP_TYPE                                            = 1222,
    D3D12_MESSAGE_ID_SET_BACKGROUND_PROCESSING_MODE_INVALID_ARGUMENT                                   = 1223,
    D3D12_MESSAGE_ID_CREATE_COMMAND_LIST_INVALID_COMMAND_LIST_TYPE_FOR_FEATURE_LEVEL                   = 1224,
    D3D12_MESSAGE_ID_CREATE_VIDEOEXTENSIONCOMMAND                                                      = 1225,
    D3D12_MESSAGE_ID_LIVE_VIDEOEXTENSIONCOMMAND                                                        = 1226,
    D3D12_MESSAGE_ID_DESTROY_VIDEOEXTENSIONCOMMAND                                                     = 1227,
    D3D12_MESSAGE_ID_INVALID_VIDEO_EXTENSION_COMMAND_ID                                                = 1228,
    D3D12_MESSAGE_ID_VIDEO_EXTENSION_COMMAND_INVALID_ARGUMENT                                          = 1229,
    D3D12_MESSAGE_ID_CREATE_ROOT_SIGNATURE_NOT_UNIQUE_IN_DXIL_LIBRARY                                  = 1230,
    D3D12_MESSAGE_ID_VARIABLE_SHADING_RATE_NOT_ALLOWED_WITH_TIR                                        = 1231,
    D3D12_MESSAGE_ID_GEOMETRY_SHADER_OUTPUTTING_BOTH_VIEWPORT_ARRAY_INDEX_AND_SHADING_RATE_NOT_SUPPORTED_ON_DEVICE =
        1232,
    D3D12_MESSAGE_ID_RSSETSHADING_RATE_INVALID_SHADING_RATE                                                      = 1233,
    D3D12_MESSAGE_ID_RSSETSHADING_RATE_SHADING_RATE_NOT_PERMITTED_BY_CAP                                         = 1234,
    D3D12_MESSAGE_ID_RSSETSHADING_RATE_INVALID_COMBINER                                                          = 1235,
    D3D12_MESSAGE_ID_RSSETSHADINGRATEIMAGE_REQUIRES_TIER_2                                                       = 1236,
    D3D12_MESSAGE_ID_RSSETSHADINGRATE_REQUIRES_TIER_1                                                            = 1237,
    D3D12_MESSAGE_ID_SHADING_RATE_IMAGE_INCORRECT_FORMAT                                                         = 1238,
    D3D12_MESSAGE_ID_SHADING_RATE_IMAGE_INCORRECT_ARRAY_SIZE                                                     = 1239,
    D3D12_MESSAGE_ID_SHADING_RATE_IMAGE_INCORRECT_MIP_LEVEL                                                      = 1240,
    D3D12_MESSAGE_ID_SHADING_RATE_IMAGE_INCORRECT_SAMPLE_COUNT                                                   = 1241,
    D3D12_MESSAGE_ID_SHADING_RATE_IMAGE_INCORRECT_SAMPLE_QUALITY                                                 = 1242,
    D3D12_MESSAGE_ID_NON_RETAIL_SHADER_MODEL_WONT_VALIDATE                                                       = 1243,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_AS_ROOT_SIGNATURE_MISMATCH                                      = 1244,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_MS_ROOT_SIGNATURE_MISMATCH                                      = 1245,
    D3D12_MESSAGE_ID_ADD_TO_STATE_OBJECT_ERROR                                                                   = 1246,
    D3D12_MESSAGE_ID_CREATE_PROTECTED_RESOURCE_SESSION_INVALID_ARGUMENT                                          = 1247,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_MS_PSO_DESC_MISMATCH                                            = 1248,
    D3D12_MESSAGE_ID_CREATEPIPELINESTATE_MS_INCOMPLETE_TYPE                                                      = 1249,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_AS_NOT_MS_MISMATCH                                              = 1250,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_MS_NOT_PS_MISMATCH                                              = 1251,
    D3D12_MESSAGE_ID_NONZERO_SAMPLER_FEEDBACK_MIP_REGION_WITH_INCOMPATIBLE_FORMAT                                = 1252,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INPUTLAYOUT_SHADER_MISMATCH                                     = 1253,
    D3D12_MESSAGE_ID_EMPTY_DISPATCH                                                                              = 1254,
    D3D12_MESSAGE_ID_RESOURCE_FORMAT_REQUIRES_SAMPLER_FEEDBACK_CAPABILITY                                        = 1255,
    D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_MAP_INVALID_MIP_REGION                                                     = 1256,
    D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_MAP_INVALID_DIMENSION                                                      = 1257,
    D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_MAP_INVALID_SAMPLE_COUNT                                                   = 1258,
    D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_MAP_INVALID_SAMPLE_QUALITY                                                 = 1259,
    D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_MAP_INVALID_LAYOUT                                                         = 1260,
    D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_MAP_REQUIRES_UNORDERED_ACCESS_FLAG                                         = 1261,
    D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_CREATE_UAV_NULL_ARGUMENTS                                                  = 1262,
    D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_UAV_REQUIRES_SAMPLER_FEEDBACK_CAPABILITY                                   = 1263,
    D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_CREATE_UAV_REQUIRES_FEEDBACK_MAP_FORMAT                                    = 1264,
    D3D12_MESSAGE_ID_CREATEMESHSHADER_INVALIDSHADERBYTECODE                                                      = 1265,
    D3D12_MESSAGE_ID_CREATEMESHSHADER_OUTOFMEMORY                                                                = 1266,
    D3D12_MESSAGE_ID_CREATEMESHSHADERWITHSTREAMOUTPUT_INVALIDSHADERTYPE                                          = 1267,
    D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_SAMPLER_FEEDBACK_TRANSCODE_INVALID_FORMAT                                = 1268,
    D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_SAMPLER_FEEDBACK_INVALID_MIP_LEVEL_COUNT                                 = 1269,
    D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_SAMPLER_FEEDBACK_TRANSCODE_ARRAY_SIZE_MISMATCH                           = 1270,
    D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_CREATE_UAV_MISMATCHING_TARGETED_RESOURCE                                   = 1271,
    D3D12_MESSAGE_ID_CREATEMESHSHADER_OUTPUTEXCEEDSMAXSIZE                                                       = 1272,
    D3D12_MESSAGE_ID_CREATEMESHSHADER_GROUPSHAREDEXCEEDSMAXSIZE                                                  = 1273,
    D3D12_MESSAGE_ID_VERTEX_SHADER_OUTPUTTING_BOTH_VIEWPORT_ARRAY_INDEX_AND_SHADING_RATE_NOT_SUPPORTED_ON_DEVICE = 1274,
    D3D12_MESSAGE_ID_MESH_SHADER_OUTPUTTING_BOTH_VIEWPORT_ARRAY_INDEX_AND_SHADING_RATE_NOT_SUPPORTED_ON_DEVICE   = 1275,
    D3D12_MESSAGE_ID_CREATEMESHSHADER_MISMATCHEDASMSPAYLOADSIZE                                                  = 1276,
    D3D12_MESSAGE_ID_CREATE_ROOT_SIGNATURE_UNBOUNDED_STATIC_DESCRIPTORS                                          = 1277,
    D3D12_MESSAGE_ID_CREATEAMPLIFICATIONSHADER_INVALIDSHADERBYTECODE                                             = 1278,
    D3D12_MESSAGE_ID_CREATEAMPLIFICATIONSHADER_OUTOFMEMORY                                                       = 1279,
    D3D12_MESSAGE_ID_CREATE_SHADERCACHESESSION                                                                   = 1280,
    D3D12_MESSAGE_ID_LIVE_SHADERCACHESESSION                                                                     = 1281,
    D3D12_MESSAGE_ID_DESTROY_SHADERCACHESESSION                                                                  = 1282,
    D3D12_MESSAGE_ID_CREATESHADERCACHESESSION_INVALIDARGS                                                        = 1283,
    D3D12_MESSAGE_ID_CREATESHADERCACHESESSION_DISABLED                                                           = 1284,
    D3D12_MESSAGE_ID_CREATESHADERCACHESESSION_ALREADYOPEN                                                        = 1285,
    D3D12_MESSAGE_ID_SHADERCACHECONTROL_DEVELOPERMODE                                                            = 1286,
    D3D12_MESSAGE_ID_SHADERCACHECONTROL_INVALIDFLAGS                                                             = 1287,
    D3D12_MESSAGE_ID_SHADERCACHECONTROL_STATEALREADYSET                                                          = 1288,
    D3D12_MESSAGE_ID_SHADERCACHECONTROL_IGNOREDFLAG                                                              = 1289,
    D3D12_MESSAGE_ID_SHADERCACHESESSION_STOREVALUE_ALREADYPRESENT                                                = 1290,
    D3D12_MESSAGE_ID_SHADERCACHESESSION_STOREVALUE_HASHCOLLISION                                                 = 1291,
    D3D12_MESSAGE_ID_SHADERCACHESESSION_STOREVALUE_CACHEFULL                                                     = 1292,
    D3D12_MESSAGE_ID_SHADERCACHESESSION_FINDVALUE_NOTFOUND                                                       = 1293,
    D3D12_MESSAGE_ID_SHADERCACHESESSION_CORRUPT                                                                  = 1294,
    D3D12_MESSAGE_ID_SHADERCACHESESSION_DISABLED                                                                 = 1295,
    D3D12_MESSAGE_ID_OVERSIZED_DISPATCH                                                                          = 1296,
    D3D12_MESSAGE_ID_CREATE_VIDEOENCODER                                                                         = 1297,
    D3D12_MESSAGE_ID_LIVE_VIDEOENCODER                                                                           = 1298,
    D3D12_MESSAGE_ID_DESTROY_VIDEOENCODER                                                                        = 1299,
    D3D12_MESSAGE_ID_CREATE_VIDEOENCODERHEAP                                                                     = 1300,
    D3D12_MESSAGE_ID_LIVE_VIDEOENCODERHEAP                                                                       = 1301,
    D3D12_MESSAGE_ID_DESTROY_VIDEOENCODERHEAP                                                                    = 1302,
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_MISMATCH_ENCODE_REFERENCE_ONLY_FLAG                                       = 1303,
    D3D12_MESSAGE_ID_COPYRESOURCE_MISMATCH_ENCODE_REFERENCE_ONLY_FLAG                                            = 1304,
    D3D12_MESSAGE_ID_ENCODE_FRAME_INVALID_PARAMETERS                                                             = 1305,
    D3D12_MESSAGE_ID_ENCODE_FRAME_UNSUPPORTED_PARAMETERS                                                         = 1306,
    D3D12_MESSAGE_ID_RESOLVE_ENCODER_OUTPUT_METADATA_INVALID_PARAMETERS                                          = 1307,
    D3D12_MESSAGE_ID_RESOLVE_ENCODER_OUTPUT_METADATA_UNSUPPORTED_PARAMETERS                                      = 1308,
    D3D12_MESSAGE_ID_CREATE_VIDEO_ENCODER_INVALID_PARAMETERS                                                     = 1309,
    D3D12_MESSAGE_ID_CREATE_VIDEO_ENCODER_UNSUPPORTED_PARAMETERS                                                 = 1310,
    D3D12_MESSAGE_ID_CREATE_VIDEO_ENCODER_HEAP_INVALID_PARAMETERS                                                = 1311,
    D3D12_MESSAGE_ID_CREATE_VIDEO_ENCODER_HEAP_UNSUPPORTED_PARAMETERS                                            = 1312,
    D3D12_MESSAGE_ID_CREATECOMMANDLIST_NULL_COMMANDALLOCATOR,
    D3D12_MESSAGE_ID_CLEAR_UNORDERED_ACCESS_VIEW_INVALID_DESCRIPTOR_HANDLE,
    D3D12_MESSAGE_ID_DESCRIPTOR_HEAP_NOT_SHADER_VISIBLE,
    D3D12_MESSAGE_ID_CREATEBLENDSTATE_BLENDOP_WARNING,
    D3D12_MESSAGE_ID_CREATEBLENDSTATE_BLENDOPALPHA_WARNING,
    D3D12_MESSAGE_ID_WRITE_COMBINE_PERFORMANCE_WARNING,
    D3D12_MESSAGE_ID_RESOLVE_QUERY_INVALID_QUERY_STATE,
    D3D12_MESSAGE_ID_SETPRIVATEDATA_NO_ACCESS,
    D3D12_MESSAGE_ID_COMMAND_LIST_STATIC_DESCRIPTOR_SAMPLER_MODE_MISMATCH,
    D3D12_MESSAGE_ID_GETCOPYABLEFOOTPRINTS_UNSUPPORTED_BUFFER_WIDTH,
    D3D12_MESSAGE_ID_CREATEMESHSHADER_TOPOLOGY_MISMATCH,
    D3D12_MESSAGE_ID_VRS_SUM_COMBINER_REQUIRES_CAPABILITY,
    D3D12_MESSAGE_ID_SETTING_SHADING_RATE_FROM_MS_REQUIRES_CAPABILITY,
    D3D12_MESSAGE_ID_SHADERCACHESESSION_SHADERCACHEDELETE_NOTSUPPORTED,
    D3D12_MESSAGE_ID_SHADERCACHECONTROL_SHADERCACHECLEAR_NOTSUPPORTED,
    D3D12_MESSAGE_ID_CREATERESOURCE_STATE_IGNORED,
    D3D12_MESSAGE_ID_UNUSED_CROSS_EXECUTE_SPLIT_BARRIER,
    D3D12_MESSAGE_ID_DEVICE_OPEN_SHARED_HANDLE_ACCESS_DENIED,
    D3D12_MESSAGE_ID_INCOMPATIBLE_BARRIER_VALUES,
    D3D12_MESSAGE_ID_INCOMPATIBLE_BARRIER_ACCESS,
    D3D12_MESSAGE_ID_INCOMPATIBLE_BARRIER_SYNC,
    D3D12_MESSAGE_ID_INCOMPATIBLE_BARRIER_LAYOUT,
    D3D12_MESSAGE_ID_INCOMPATIBLE_BARRIER_TYPE,
    D3D12_MESSAGE_ID_OUT_OF_BOUNDS_BARRIER_SUBRESOURCE_RANGE,
    D3D12_MESSAGE_ID_INCOMPATIBLE_BARRIER_RESOURCE_DIMENSION,
    D3D12_MESSAGE_ID_SET_SCISSOR_RECTS_INVALID_RECT,
    D3D12_MESSAGE_ID_SHADING_RATE_SOURCE_REQUIRES_DIMENSION_TEXTURE2D,
    D3D12_MESSAGE_ID_BUFFER_BARRIER_SUBREGION_OUT_OF_BOUNDS,
    D3D12_MESSAGE_ID_UNSUPPORTED_BARRIER_LAYOUT,
    D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_INVALID_PARAMETERS,
    D3D12_MESSAGE_ID_ENHANCED_BARRIERS_NOT_SUPPORTED,
    D3D12_MESSAGE_ID_LEGACY_BARRIER_VALIDATION_FORCED_ON,
    D3D12_MESSAGE_ID_EMPTY_ROOT_DESCRIPTOR_TABLE,
    D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_ELEMENT_OFFSET_UNALIGNED,
    D3D12_MESSAGE_ID_ALPHA_BLEND_FACTOR_NOT_SUPPORTED,
    D3D12_MESSAGE_ID_BARRIER_INTEROP_INVALID_LAYOUT,
    D3D12_MESSAGE_ID_BARRIER_INTEROP_INVALID_STATE,
    D3D12_MESSAGE_ID_GRAPHICS_PIPELINE_STATE_DESC_ZERO_SAMPLE_MASK,
    D3D12_MESSAGE_ID_INDEPENDENT_STENCIL_REF_NOT_SUPPORTED,
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INDEPENDENT_MASKS_UNSUPPORTED,
    D3D12_MESSAGE_ID_TEXTURE_BARRIER_SUBRESOURCES_OUT_OF_BOUNDS,
    D3D12_MESSAGE_ID_NON_OPTIMAL_BARRIER_ONLY_EXECUTE_COMMAND_LISTS,
    D3D12_MESSAGE_ID_EXECUTE_INDIRECT_ZERO_COMMAND_COUNT,
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_INCOMPATIBLE_TEXTURE_LAYOUT,
    D3D12_MESSAGE_ID_DYNAMIC_INDEX_BUFFER_STRIP_CUT_NOT_SUPPORTED,
    D3D12_MESSAGE_ID_PRIMITIVE_TOPOLOGY_TRIANGLE_FANS_NOT_SUPPORTED,
    D3D12_MESSAGE_ID_CREATE_SAMPLER_COMPARISON_FUNC_IGNORED,
    D3D12_MESSAGE_ID_CREATEHEAP_INVALIDHEAPTYPE,
    D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_INVALIDHEAPTYPE,
    D3D12_MESSAGE_ID_DYNAMIC_DEPTH_BIAS_NOT_SUPPORTED,
    D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_NON_WHOLE_DYNAMIC_DEPTH_BIAS,
    D3D12_MESSAGE_ID_DYNAMIC_DEPTH_BIAS_FLAG_MISSING,
    D3D12_MESSAGE_ID_DYNAMIC_DEPTH_BIAS_NO_PIPELINE,
    D3D12_MESSAGE_ID_DYNAMIC_INDEX_BUFFER_STRIP_CUT_FLAG_MISSING,
    D3D12_MESSAGE_ID_DYNAMIC_INDEX_BUFFER_STRIP_CUT_NO_PIPELINE,
    D3D12_MESSAGE_ID_NONNORMALIZED_COORDINATE_SAMPLING_NOT_SUPPORTED,
    D3D12_MESSAGE_ID_INVALID_CAST_TARGET,
    D3D12_MESSAGE_ID_RENDER_PASS_COMMANDLIST_INVALID_END_STATE,
    D3D12_MESSAGE_ID_RENDER_PASS_COMMANDLIST_INVALID_START_STATE,
    D3D12_MESSAGE_ID_RENDER_PASS_MISMATCHING_ACCESS,
    D3D12_MESSAGE_ID_RENDER_PASS_MISMATCHING_LOCAL_PRESERVE_PARAMETERS,
    D3D12_MESSAGE_ID_RENDER_PASS_LOCAL_PRESERVE_RENDER_PARAMETERS_ERROR,
    D3D12_MESSAGE_ID_RENDER_PASS_LOCAL_DEPTH_STENCIL_ERROR,
    D3D12_MESSAGE_ID_DRAW_POTENTIALLY_OUTSIDE_OF_VALID_RENDER_AREA,
    D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_INVALID_LINERASTERIZATIONMODE,
    D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDALIGNMENT_SMALLRESOURCE,
    D3D12_MESSAGE_ID_GENERIC_DEVICE_OPERATION_UNSUPPORTED,
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_RENDER_TARGET_WRONG_WRITE_MASK,
    D3D12_MESSAGE_ID_PROBABLE_PIX_EVENT_LEAK,
    D3D12_MESSAGE_ID_PIX_EVENT_UNDERFLOW,
    D3D12_MESSAGE_ID_RECREATEAT_INVALID_TARGET,
    D3D12_MESSAGE_ID_RECREATEAT_INSUFFICIENT_SUPPORT,
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_STRUCTURED_BUFFER_STRIDE_MISMATCH,
    D3D12_MESSAGE_ID_D3D12_MESSAGES_END
};

enum D3D12_MESSAGE_SEVERITY
{
    D3D12_MESSAGE_SEVERITY_CORRUPTION = 0,
    D3D12_MESSAGE_SEVERITY_ERROR,
    D3D12_MESSAGE_SEVERITY_WARNING,
    D3D12_MESSAGE_SEVERITY_INFO,
    D3D12_MESSAGE_SEVERITY_MESSAGE
};

enum D3D12_META_COMMAND_PARAMETER_FLAGS
{
    D3D12_META_COMMAND_PARAMETER_FLAG_INPUT  = 0x1,
    D3D12_META_COMMAND_PARAMETER_FLAG_OUTPUT = 0x2
};

enum D3D12_META_COMMAND_PARAMETER_STAGE
{
    D3D12_META_COMMAND_PARAMETER_STAGE_CREATION       = 0,
    D3D12_META_COMMAND_PARAMETER_STAGE_INITIALIZATION = 1,
    D3D12_META_COMMAND_PARAMETER_STAGE_EXECUTION      = 2
};

enum D3D12_META_COMMAND_PARAMETER_TYPE
{
    D3D12_META_COMMAND_PARAMETER_TYPE_FLOAT                                       = 0,
    D3D12_META_COMMAND_PARAMETER_TYPE_UINT64                                      = 1,
    D3D12_META_COMMAND_PARAMETER_TYPE_GPU_VIRTUAL_ADDRESS                         = 2,
    D3D12_META_COMMAND_PARAMETER_TYPE_CPU_DESCRIPTOR_HANDLE_HEAP_TYPE_CBV_SRV_UAV = 3,
    D3D12_META_COMMAND_PARAMETER_TYPE_GPU_DESCRIPTOR_HANDLE_HEAP_TYPE_CBV_SRV_UAV = 4
};

enum D3D12_MULTIPLE_FENCE_WAIT_FLAGS
{
    D3D12_MULTIPLE_FENCE_WAIT_FLAG_NONE = 0,
    D3D12_MULTIPLE_FENCE_WAIT_FLAG_ANY  = 0x1,
    D3D12_MULTIPLE_FENCE_WAIT_FLAG_ALL  = 0
};

enum D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS
{
    D3D12_MULTISAMPLE_QUALITY_LEVELS_FLAG_NONE           = 0,
    D3D12_MULTISAMPLE_QUALITY_LEVELS_FLAG_TILED_RESOURCE = 0x1
};

enum D3D12_PIPELINE_STATE_FLAGS
{
    D3D12_PIPELINE_STATE_FLAG_NONE       = 0,
    D3D12_PIPELINE_STATE_FLAG_TOOL_DEBUG = 0x1,
    D3D12_PIPELINE_STATE_FLAG_DYNAMIC_DEPTH_BIAS,
    D3D12_PIPELINE_STATE_FLAG_DYNAMIC_INDEX_BUFFER_STRIP_CUT
};

enum D3D12_PIPELINE_STATE_SUBOBJECT_TYPE
{
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_ROOT_SIGNATURE = 0,
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_VS,
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_PS,
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DS,
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_HS,
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_GS,
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_CS,
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_STREAM_OUTPUT,
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_BLEND,
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_SAMPLE_MASK,
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_RASTERIZER,
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL,
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_INPUT_LAYOUT,
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_IB_STRIP_CUT_VALUE,
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_PRIMITIVE_TOPOLOGY,
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_RENDER_TARGET_FORMATS,
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL_FORMAT,
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_SAMPLE_DESC,
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_NODE_MASK,
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_CACHED_PSO,
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_FLAGS,
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL1,
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_VIEW_INSTANCING,
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_AS = 24,
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_MS = 25,
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL2,
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_RASTERIZER1,
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_RASTERIZER2,
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_MAX_VALID
};

enum D3D12_PREDICATION_OP
{
    D3D12_PREDICATION_OP_EQUAL_ZERO     = 0,
    D3D12_PREDICATION_OP_NOT_EQUAL_ZERO = 1
};

enum D3D12_PRIMITIVE_TOPOLOGY_TYPE
{
    D3D12_PRIMITIVE_TOPOLOGY_TYPE_UNDEFINED = 0,
    D3D12_PRIMITIVE_TOPOLOGY_TYPE_POINT     = 1,
    D3D12_PRIMITIVE_TOPOLOGY_TYPE_LINE      = 2,
    D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE  = 3,
    D3D12_PRIMITIVE_TOPOLOGY_TYPE_PATCH     = 4
};

enum D3D12_PROGRAMMABLE_SAMPLE_POSITIONS_TIER
{
    D3D12_PROGRAMMABLE_SAMPLE_POSITIONS_TIER_NOT_SUPPORTED = 0,
    D3D12_PROGRAMMABLE_SAMPLE_POSITIONS_TIER_1             = 1,
    D3D12_PROGRAMMABLE_SAMPLE_POSITIONS_TIER_2             = 2
};

enum D3D12_PROTECTED_RESOURCE_SESSION_FLAGS
{
    D3D12_PROTECTED_RESOURCE_SESSION_FLAG_NONE = 0
};

enum D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS
{
    D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAG_NONE,
    D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAG_SUPPORTED
};

enum D3D12_PROTECTED_SESSION_STATUS
{
    D3D12_PROTECTED_SESSION_STATUS_OK      = 0,
    D3D12_PROTECTED_SESSION_STATUS_INVALID = 1
};

enum D3D12_QUERY_HEAP_TYPE
{
    D3D12_QUERY_HEAP_TYPE_OCCLUSION               = 0,
    D3D12_QUERY_HEAP_TYPE_TIMESTAMP               = 1,
    D3D12_QUERY_HEAP_TYPE_PIPELINE_STATISTICS     = 2,
    D3D12_QUERY_HEAP_TYPE_SO_STATISTICS           = 3,
    D3D12_QUERY_HEAP_TYPE_VIDEO_DECODE_STATISTICS = 4,
    D3D12_QUERY_HEAP_TYPE_COPY_QUEUE_TIMESTAMP    = 5,
    D3D12_QUERY_HEAP_TYPE_PIPELINE_STATISTICS1
};

enum D3D12_QUERY_TYPE
{
    D3D12_QUERY_TYPE_OCCLUSION               = 0,
    D3D12_QUERY_TYPE_BINARY_OCCLUSION        = 1,
    D3D12_QUERY_TYPE_TIMESTAMP               = 2,
    D3D12_QUERY_TYPE_PIPELINE_STATISTICS     = 3,
    D3D12_QUERY_TYPE_SO_STATISTICS_STREAM0   = 4,
    D3D12_QUERY_TYPE_SO_STATISTICS_STREAM1   = 5,
    D3D12_QUERY_TYPE_SO_STATISTICS_STREAM2   = 6,
    D3D12_QUERY_TYPE_SO_STATISTICS_STREAM3   = 7,
    D3D12_QUERY_TYPE_VIDEO_DECODE_STATISTICS = 8,
    D3D12_QUERY_TYPE_PIPELINE_STATISTICS1
};

enum D3D12_RAY_FLAGS
{
    D3D12_RAY_FLAG_NONE                            = 0,
    D3D12_RAY_FLAG_FORCE_OPAQUE                    = 0x1,
    D3D12_RAY_FLAG_FORCE_NON_OPAQUE                = 0x2,
    D3D12_RAY_FLAG_ACCEPT_FIRST_HIT_AND_END_SEARCH = 0x4,
    D3D12_RAY_FLAG_SKIP_CLOSEST_HIT_SHADER         = 0x8,
    D3D12_RAY_FLAG_CULL_BACK_FACING_TRIANGLES      = 0x10,
    D3D12_RAY_FLAG_CULL_FRONT_FACING_TRIANGLES     = 0x20,
    D3D12_RAY_FLAG_CULL_OPAQUE                     = 0x40,
    D3D12_RAY_FLAG_CULL_NON_OPAQUE                 = 0x80,
    D3D12_RAY_FLAG_SKIP_TRIANGLES,
    D3D12_RAY_FLAG_SKIP_PROCEDURAL_PRIMITIVES
};

enum D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE
{
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL    = 0,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL = 0x1
};

enum D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS
{
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_NONE              = 0,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_UPDATE      = 0x1,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_COMPACTION  = 0x2,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PREFER_FAST_TRACE = 0x4,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PREFER_FAST_BUILD = 0x8,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_MINIMIZE_MEMORY   = 0x10,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PERFORM_UPDATE    = 0x20
};

enum D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE
{
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE_CLONE                          = 0,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE_COMPACT                        = 0x1,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE_VISUALIZATION_DECODE_FOR_TOOLS = 0x2,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE_SERIALIZE                      = 0x3,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE_DESERIALIZE                    = 0x4
};

enum D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TYPE
{
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE      = 0,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION = 0x1,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION       = 0x2,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE        = 0x3
};

enum D3D12_RAYTRACING_GEOMETRY_FLAGS
{
    D3D12_RAYTRACING_GEOMETRY_FLAG_NONE                           = 0,
    D3D12_RAYTRACING_GEOMETRY_FLAG_OPAQUE                         = 0x1,
    D3D12_RAYTRACING_GEOMETRY_FLAG_NO_DUPLICATE_ANYHIT_INVOCATION = 0x2
};

enum D3D12_RAYTRACING_GEOMETRY_TYPE
{
    D3D12_RAYTRACING_GEOMETRY_TYPE_TRIANGLES = 0,
    D3D12_RAYTRACING_GEOMETRY_TYPE_PROCEDURAL_PRIMITIVE_AABBS
};

enum D3D12_RAYTRACING_INSTANCE_FLAGS
{
    D3D12_RAYTRACING_INSTANCE_FLAG_NONE                            = 0,
    D3D12_RAYTRACING_INSTANCE_FLAG_TRIANGLE_CULL_DISABLE           = 0x1,
    D3D12_RAYTRACING_INSTANCE_FLAG_TRIANGLE_FRONT_COUNTERCLOCKWISE = 0x2,
    D3D12_RAYTRACING_INSTANCE_FLAG_FORCE_OPAQUE                    = 0x4,
    D3D12_RAYTRACING_INSTANCE_FLAG_FORCE_NON_OPAQUE                = 0x8
};

enum D3D12_RAYTRACING_PIPELINE_FLAGS
{
    D3D12_RAYTRACING_PIPELINE_FLAG_NONE                       = 0,
    D3D12_RAYTRACING_PIPELINE_FLAG_SKIP_TRIANGLES             = 0x100,
    D3D12_RAYTRACING_PIPELINE_FLAG_SKIP_PROCEDURAL_PRIMITIVES = 0x200
};

enum D3D12_RAYTRACING_TIER
{
    D3D12_RAYTRACING_TIER_NOT_SUPPORTED = 0,
    D3D12_RAYTRACING_TIER_1_0           = 10,
    D3D12_RAYTRACING_TIER_1_1
};

enum D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE
{
    D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_DISCARD = 0,
    D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE,
    D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_CLEAR,
    D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_NO_ACCESS,
    D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE_LOCAL_RENDER,
    D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE_LOCAL_SRV,
    D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE_LOCAL_UAV
};

enum D3D12_RENDER_PASS_ENDING_ACCESS_TYPE
{
    D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_DISCARD = 0,
    D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE,
    D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_RESOLVE,
    D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_NO_ACCESS,
    D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE_LOCAL_RENDER,
    D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE_LOCAL_SRV,
    D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE_LOCAL_UAV
};

enum D3D12_RENDER_PASS_FLAGS
{
    D3D12_RENDER_PASS_FLAG_NONE             = 0,
    D3D12_RENDER_PASS_FLAG_ALLOW_UAV_WRITES = 0x1,
    D3D12_RENDER_PASS_FLAG_SUSPENDING_PASS  = 0x2,
    D3D12_RENDER_PASS_FLAG_RESUMING_PASS    = 0x4,
    D3D12_RENDER_PASS_FLAG_BIND_READ_ONLY_DEPTH,
    D3D12_RENDER_PASS_FLAG_BIND_READ_ONLY_STENCIL
};

enum D3D12_RENDER_PASS_TIER
{
    D3D12_RENDER_PASS_TIER_0 = 0,
    D3D12_RENDER_PASS_TIER_1 = 1,
    D3D12_RENDER_PASS_TIER_2 = 2
};

enum D3D12_RESIDENCY_FLAGS
{
    D3D12_RESIDENCY_FLAG_NONE            = 0,
    D3D12_RESIDENCY_FLAG_DENY_OVERBUDGET = 0x1
};

enum D3D12_RESIDENCY_PRIORITY
{
    D3D12_RESIDENCY_PRIORITY_MINIMUM = 0x28000000,
    D3D12_RESIDENCY_PRIORITY_LOW     = 0x50000000,
    D3D12_RESIDENCY_PRIORITY_NORMAL  = 0x78000000,
    D3D12_RESIDENCY_PRIORITY_HIGH    = 0xa0010000,
    D3D12_RESIDENCY_PRIORITY_MAXIMUM = 0xc8000000
};

enum D3D12_RESOLVE_MODE
{
    D3D12_RESOLVE_MODE_DECOMPRESS = 0,
    D3D12_RESOLVE_MODE_MIN        = 1,
    D3D12_RESOLVE_MODE_MAX        = 2,
    D3D12_RESOLVE_MODE_AVERAGE    = 3,
    D3D12_RESOLVE_MODE_ENCODE_SAMPLER_FEEDBACK,
    D3D12_RESOLVE_MODE_DECODE_SAMPLER_FEEDBACK
};

enum D3D12_RESOURCE_BARRIER_FLAGS
{
    D3D12_RESOURCE_BARRIER_FLAG_NONE       = 0,
    D3D12_RESOURCE_BARRIER_FLAG_BEGIN_ONLY = 0x1,
    D3D12_RESOURCE_BARRIER_FLAG_END_ONLY   = 0x2
};

enum D3D12_RESOURCE_BARRIER_TYPE
{
    D3D12_RESOURCE_BARRIER_TYPE_TRANSITION = 0,
    D3D12_RESOURCE_BARRIER_TYPE_ALIASING,
    D3D12_RESOURCE_BARRIER_TYPE_UAV
};

enum D3D12_RESOURCE_BINDING_TIER
{
    D3D12_RESOURCE_BINDING_TIER_1 = 1,
    D3D12_RESOURCE_BINDING_TIER_2 = 2,
    D3D12_RESOURCE_BINDING_TIER_3 = 3
};

enum D3D12_RESOURCE_DIMENSION
{
    D3D12_RESOURCE_DIMENSION_UNKNOWN   = 0,
    D3D12_RESOURCE_DIMENSION_BUFFER    = 1,
    D3D12_RESOURCE_DIMENSION_TEXTURE1D = 2,
    D3D12_RESOURCE_DIMENSION_TEXTURE2D = 3,
    D3D12_RESOURCE_DIMENSION_TEXTURE3D = 4
};

enum D3D12_RESOURCE_FLAGS
{
    D3D12_RESOURCE_FLAG_NONE                              = 0,
    D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET               = 0x1,
    D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL               = 0x2,
    D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS            = 0x4,
    D3D12_RESOURCE_FLAG_DENY_SHADER_RESOURCE              = 0x8,
    D3D12_RESOURCE_FLAG_ALLOW_CROSS_ADAPTER               = 0x10,
    D3D12_RESOURCE_FLAG_ALLOW_SIMULTANEOUS_ACCESS         = 0x20,
    D3D12_RESOURCE_FLAG_VIDEO_DECODE_REFERENCE_ONLY       = 0x40,
    D3D12_RESOURCE_FLAG_VIDEO_ENCODE_REFERENCE_ONLY       = 0x80,
    D3D12_RESOURCE_FLAG_RAYTRACING_ACCELERATION_STRUCTURE = 0x100
};

enum D3D12_RESOURCE_HEAP_TIER
{
    D3D12_RESOURCE_HEAP_TIER_1 = 1,
    D3D12_RESOURCE_HEAP_TIER_2 = 2
};

enum D3D12_RESOURCE_STATES
{
    D3D12_RESOURCE_STATE_COMMON                            = 0,
    D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER        = 0x1,
    D3D12_RESOURCE_STATE_INDEX_BUFFER                      = 0x2,
    D3D12_RESOURCE_STATE_RENDER_TARGET                     = 0x4,
    D3D12_RESOURCE_STATE_UNORDERED_ACCESS                  = 0x8,
    D3D12_RESOURCE_STATE_DEPTH_WRITE                       = 0x10,
    D3D12_RESOURCE_STATE_DEPTH_READ                        = 0x20,
    D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE         = 0x40,
    D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE             = 0x80,
    D3D12_RESOURCE_STATE_STREAM_OUT                        = 0x100,
    D3D12_RESOURCE_STATE_INDIRECT_ARGUMENT                 = 0x200,
    D3D12_RESOURCE_STATE_COPY_DEST                         = 0x400,
    D3D12_RESOURCE_STATE_COPY_SOURCE                       = 0x800,
    D3D12_RESOURCE_STATE_RESOLVE_DEST                      = 0x1000,
    D3D12_RESOURCE_STATE_RESOLVE_SOURCE                    = 0x2000,
    D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE = 0x400000,
    D3D12_RESOURCE_STATE_SHADING_RATE_SOURCE               = 0x1000000,
    D3D12_RESOURCE_STATE_RESERVED_INTERNAL_8000,
    D3D12_RESOURCE_STATE_RESERVED_INTERNAL_4000,
    D3D12_RESOURCE_STATE_RESERVED_INTERNAL_100000,
    D3D12_RESOURCE_STATE_RESERVED_INTERNAL_40000000,
    D3D12_RESOURCE_STATE_RESERVED_INTERNAL_80000000,
    D3D12_RESOURCE_STATE_GENERIC_READ,
    D3D12_RESOURCE_STATE_ALL_SHADER_RESOURCE,
    D3D12_RESOURCE_STATE_PRESENT             = 0,
    D3D12_RESOURCE_STATE_PREDICATION         = 0x200,
    D3D12_RESOURCE_STATE_VIDEO_DECODE_READ   = 0x10000,
    D3D12_RESOURCE_STATE_VIDEO_DECODE_WRITE  = 0x20000,
    D3D12_RESOURCE_STATE_VIDEO_PROCESS_READ  = 0x40000,
    D3D12_RESOURCE_STATE_VIDEO_PROCESS_WRITE = 0x80000,
    D3D12_RESOURCE_STATE_VIDEO_ENCODE_READ   = 0x200000,
    D3D12_RESOURCE_STATE_VIDEO_ENCODE_WRITE  = 0x800000
};

enum D3D12_RLDO_FLAGS
{
    D3D12_RLDO_NONE            = 0,
    D3D12_RLDO_SUMMARY         = 0x1,
    D3D12_RLDO_DETAIL          = 0x2,
    D3D12_RLDO_IGNORE_INTERNAL = 0x4
};

enum D3D12_ROOT_DESCRIPTOR_FLAGS
{
    D3D12_ROOT_DESCRIPTOR_FLAG_NONE                             = 0,
    D3D12_ROOT_DESCRIPTOR_FLAG_DATA_VOLATILE                    = 0x2,
    D3D12_ROOT_DESCRIPTOR_FLAG_DATA_STATIC_WHILE_SET_AT_EXECUTE = 0x4,
    D3D12_ROOT_DESCRIPTOR_FLAG_DATA_STATIC                      = 0x8
};

enum D3D12_ROOT_PARAMETER_TYPE
{
    D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE = 0,
    D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS,
    D3D12_ROOT_PARAMETER_TYPE_CBV,
    D3D12_ROOT_PARAMETER_TYPE_SRV,
    D3D12_ROOT_PARAMETER_TYPE_UAV
};

enum D3D12_ROOT_SIGNATURE_FLAGS
{
    D3D12_ROOT_SIGNATURE_FLAG_NONE                                  = 0,
    D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT    = 0x1,
    D3D12_ROOT_SIGNATURE_FLAG_DENY_VERTEX_SHADER_ROOT_ACCESS        = 0x2,
    D3D12_ROOT_SIGNATURE_FLAG_DENY_HULL_SHADER_ROOT_ACCESS          = 0x4,
    D3D12_ROOT_SIGNATURE_FLAG_DENY_DOMAIN_SHADER_ROOT_ACCESS        = 0x8,
    D3D12_ROOT_SIGNATURE_FLAG_DENY_GEOMETRY_SHADER_ROOT_ACCESS      = 0x10,
    D3D12_ROOT_SIGNATURE_FLAG_DENY_PIXEL_SHADER_ROOT_ACCESS         = 0x20,
    D3D12_ROOT_SIGNATURE_FLAG_ALLOW_STREAM_OUTPUT                   = 0x40,
    D3D12_ROOT_SIGNATURE_FLAG_LOCAL_ROOT_SIGNATURE                  = 0x80,
    D3D12_ROOT_SIGNATURE_FLAG_DENY_AMPLIFICATION_SHADER_ROOT_ACCESS = 0x100,
    D3D12_ROOT_SIGNATURE_FLAG_DENY_MESH_SHADER_ROOT_ACCESS          = 0x200,
    D3D12_ROOT_SIGNATURE_FLAG_CBV_SRV_UAV_HEAP_DIRECTLY_INDEXED     = 0x400,
    D3D12_ROOT_SIGNATURE_FLAG_SAMPLER_HEAP_DIRECTLY_INDEXED         = 0x800
};

enum D3D12_RTV_DIMENSION
{
    D3D12_RTV_DIMENSION_UNKNOWN          = 0,
    D3D12_RTV_DIMENSION_BUFFER           = 1,
    D3D12_RTV_DIMENSION_TEXTURE1D        = 2,
    D3D12_RTV_DIMENSION_TEXTURE1DARRAY   = 3,
    D3D12_RTV_DIMENSION_TEXTURE2D        = 4,
    D3D12_RTV_DIMENSION_TEXTURE2DARRAY   = 5,
    D3D12_RTV_DIMENSION_TEXTURE2DMS      = 6,
    D3D12_RTV_DIMENSION_TEXTURE2DMSARRAY = 7,
    D3D12_RTV_DIMENSION_TEXTURE3D        = 8
};

enum D3D12_SAMPLER_FLAGS
{
    D3D12_SAMPLER_FLAG_NONE                       = 0x0,
    D3D12_SAMPLER_FLAG_UINT_BORDER_COLOR          = 0x01,
    D3D12_SAMPLER_FLAG_NON_NORMALIZED_COORDINATES = 0x02,

};

enum D3D12_SAMPLER_FEEDBACK_TIER
{
    D3D12_SAMPLER_FEEDBACK_TIER_NOT_SUPPORTED = 0,
    D3D12_SAMPLER_FEEDBACK_TIER_0_9           = 90,
    D3D12_SAMPLER_FEEDBACK_TIER_1_0           = 100
};

enum D3D12_SHADER_CACHE_CONTROL_FLAGS
{
    D3D12_SHADER_CACHE_CONTROL_FLAG_DISABLE = 0x1,
    D3D12_SHADER_CACHE_CONTROL_FLAG_ENABLE  = 0x2,
    D3D12_SHADER_CACHE_CONTROL_FLAG_CLEAR   = 0x4
};

enum D3D12_SERIALIZED_DATA_TYPE
{
    D3D12_SERIALIZED_DATA_RAYTRACING_ACCELERATION_STRUCTURE = 0
};

enum D3D12_SHADER_CACHE_FLAGS
{
    D3D12_SHADER_CACHE_FLAG_NONE             = 0,
    D3D12_SHADER_CACHE_FLAG_DRIVER_VERSIONED = 0x1,
    D3D12_SHADER_CACHE_FLAG_USE_WORKING_DIR  = 0x2
};

enum D3D12_SHADER_CACHE_KIND_FLAGS
{
    D3D12_SHADER_CACHE_KIND_FLAG_IMPLICIT_D3D_CACHE_FOR_DRIVER = 0x1,
    D3D12_SHADER_CACHE_KIND_FLAG_IMPLICIT_D3D_CONVERSIONS      = 0x2,
    D3D12_SHADER_CACHE_KIND_FLAG_IMPLICIT_DRIVER_MANAGED       = 0x4,
    D3D12_SHADER_CACHE_KIND_FLAG_APPLICATION_MANAGED           = 0x8
};

enum D3D12_SHADER_CACHE_MODE
{
    D3D12_SHADER_CACHE_MODE_MEMORY = 0,
    D3D12_SHADER_CACHE_MODE_DISK
};

enum D3D12_SHADER_CACHE_SUPPORT_FLAGS
{
    D3D12_SHADER_CACHE_SUPPORT_NONE                   = 0,
    D3D12_SHADER_CACHE_SUPPORT_SINGLE_PSO             = 0x1,
    D3D12_SHADER_CACHE_SUPPORT_LIBRARY                = 0x2,
    D3D12_SHADER_CACHE_SUPPORT_AUTOMATIC_INPROC_CACHE = 0x4,
    D3D12_SHADER_CACHE_SUPPORT_AUTOMATIC_DISK_CACHE   = 0x8,
    D3D12_SHADER_CACHE_SUPPORT_DRIVER_MANAGED_CACHE,
    D3D12_SHADER_CACHE_SUPPORT_SHADER_CONTROL_CLEAR,
    D3D12_SHADER_CACHE_SUPPORT_SHADER_SESSION_DELETE
};

enum D3D12_SHADER_COMPONENT_MAPPING
{
    D3D12_SHADER_COMPONENT_MAPPING_FROM_MEMORY_COMPONENT_0 = 0,
    D3D12_SHADER_COMPONENT_MAPPING_FROM_MEMORY_COMPONENT_1 = 1,
    D3D12_SHADER_COMPONENT_MAPPING_FROM_MEMORY_COMPONENT_2 = 2,
    D3D12_SHADER_COMPONENT_MAPPING_FROM_MEMORY_COMPONENT_3 = 3,
    D3D12_SHADER_COMPONENT_MAPPING_FORCE_VALUE_0           = 4,
    D3D12_SHADER_COMPONENT_MAPPING_FORCE_VALUE_1           = 5
};

enum D3D12_SHADER_MIN_PRECISION_SUPPORT
{
    D3D12_SHADER_MIN_PRECISION_SUPPORT_NONE   = 0,
    D3D12_SHADER_MIN_PRECISION_SUPPORT_10_BIT = 0x1,
    D3D12_SHADER_MIN_PRECISION_SUPPORT_16_BIT = 0x2
};

enum D3D12_SHADER_VISIBILITY
{
    D3D12_SHADER_VISIBILITY_ALL           = 0,
    D3D12_SHADER_VISIBILITY_VERTEX        = 1,
    D3D12_SHADER_VISIBILITY_HULL          = 2,
    D3D12_SHADER_VISIBILITY_DOMAIN        = 3,
    D3D12_SHADER_VISIBILITY_GEOMETRY      = 4,
    D3D12_SHADER_VISIBILITY_PIXEL         = 5,
    D3D12_SHADER_VISIBILITY_AMPLIFICATION = 6,
    D3D12_SHADER_VISIBILITY_MESH          = 7
};

enum D3D12_SHADING_RATE
{
    D3D12_SHADING_RATE_1X1 = 0,
    D3D12_SHADING_RATE_1X2 = 0x1,
    D3D12_SHADING_RATE_2X1 = 0x4,
    D3D12_SHADING_RATE_2X2 = 0x5,
    D3D12_SHADING_RATE_2X4 = 0x6,
    D3D12_SHADING_RATE_4X2 = 0x9,
    D3D12_SHADING_RATE_4X4 = 0xa
};

enum D3D12_SHADING_RATE_COMBINER
{
    D3D12_SHADING_RATE_COMBINER_PASSTHROUGH = 0,
    D3D12_SHADING_RATE_COMBINER_OVERRIDE    = 1,
    D3D12_SHADING_RATE_COMBINER_MIN         = 2,
    D3D12_SHADING_RATE_COMBINER_MAX         = 3,
    D3D12_SHADING_RATE_COMBINER_SUM         = 4
};

enum D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER
{
    D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER_0 = 0,
    D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER_1,
    D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER_2
};

enum D3D12_SRV_DIMENSION
{
    D3D12_SRV_DIMENSION_UNKNOWN                           = 0,
    D3D12_SRV_DIMENSION_BUFFER                            = 1,
    D3D12_SRV_DIMENSION_TEXTURE1D                         = 2,
    D3D12_SRV_DIMENSION_TEXTURE1DARRAY                    = 3,
    D3D12_SRV_DIMENSION_TEXTURE2D                         = 4,
    D3D12_SRV_DIMENSION_TEXTURE2DARRAY                    = 5,
    D3D12_SRV_DIMENSION_TEXTURE2DMS                       = 6,
    D3D12_SRV_DIMENSION_TEXTURE2DMSARRAY                  = 7,
    D3D12_SRV_DIMENSION_TEXTURE3D                         = 8,
    D3D12_SRV_DIMENSION_TEXTURECUBE                       = 9,
    D3D12_SRV_DIMENSION_TEXTURECUBEARRAY                  = 10,
    D3D12_SRV_DIMENSION_RAYTRACING_ACCELERATION_STRUCTURE = 11
};
enum D3D12_STATE_SUBOBJECT_TYPE
{
    D3D12_STATE_SUBOBJECT_TYPE_STATE_OBJECT_CONFIG                   = 0,
    D3D12_STATE_SUBOBJECT_TYPE_GLOBAL_ROOT_SIGNATURE                 = 1,
    D3D12_STATE_SUBOBJECT_TYPE_LOCAL_ROOT_SIGNATURE                  = 2,
    D3D12_STATE_SUBOBJECT_TYPE_NODE_MASK                             = 3,
    D3D12_STATE_SUBOBJECT_TYPE_DXIL_LIBRARY                          = 5,
    D3D12_STATE_SUBOBJECT_TYPE_EXISTING_COLLECTION                   = 6,
    D3D12_STATE_SUBOBJECT_TYPE_SUBOBJECT_TO_EXPORTS_ASSOCIATION      = 7,
    D3D12_STATE_SUBOBJECT_TYPE_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION = 8,
    D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_SHADER_CONFIG              = 9,
    D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_PIPELINE_CONFIG            = 10,
    D3D12_STATE_SUBOBJECT_TYPE_HIT_GROUP                             = 11,
    D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_PIPELINE_CONFIG1,
    D3D12_STATE_SUBOBJECT_TYPE_WORK_GRAPH,
    D3D12_STATE_SUBOBJECT_TYPE_STREAM_OUTPUT,
    D3D12_STATE_SUBOBJECT_TYPE_BLEND,
    D3D12_STATE_SUBOBJECT_TYPE_SAMPLE_MASK,
    D3D12_STATE_SUBOBJECT_TYPE_RASTERIZER,
    D3D12_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL,
    D3D12_STATE_SUBOBJECT_TYPE_INPUT_LAYOUT,
    D3D12_STATE_SUBOBJECT_TYPE_IB_STRIP_CUT_VALUE,
    D3D12_STATE_SUBOBJECT_TYPE_PRIMITIVE_TOPOLOGY,
    D3D12_STATE_SUBOBJECT_TYPE_RENDER_TARGET_FORMATS,
    D3D12_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL_FORMAT,
    D3D12_STATE_SUBOBJECT_TYPE_SAMPLE_DESC,
    D3D12_STATE_SUBOBJECT_TYPE_FLAGS,
    D3D12_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL1,
    D3D12_STATE_SUBOBJECT_TYPE_VIEW_INSTANCING,
    D3D12_STATE_SUBOBJECT_TYPE_GENERIC_PROGRAM,
    D3D12_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL2,
    D3D12_STATE_SUBOBJECT_TYPE_MAX_VALID
};

enum D3D12_STATE_OBJECT_FLAGS
{
    D3D12_STATE_OBJECT_FLAG_NONE                                             = 0,
    D3D12_STATE_OBJECT_FLAG_ALLOW_LOCAL_DEPENDENCIES_ON_EXTERNAL_DEFINITIONS = 0x1,
    D3D12_STATE_OBJECT_FLAG_ALLOW_EXTERNAL_DEPENDENCIES_ON_LOCAL_DEFINITIONS = 0x2,
    D3D12_STATE_OBJECT_FLAG_ALLOW_STATE_OBJECT_ADDITIONS
};

enum D3D12_STATE_OBJECT_TYPE
{
    D3D12_STATE_OBJECT_TYPE_COLLECTION          = 0,
    D3D12_STATE_OBJECT_TYPE_RAYTRACING_PIPELINE = 3,
    D3D12_STATE_OBJECT_TYPE_EXECUTABLE
};

enum D3D12_STATIC_BORDER_COLOR
{
    D3D12_STATIC_BORDER_COLOR_TRANSPARENT_BLACK = 0,
    D3D12_STATIC_BORDER_COLOR_OPAQUE_BLACK,
    D3D12_STATIC_BORDER_COLOR_OPAQUE_WHITE,
    D3D12_STATIC_BORDER_COLOR_OPAQUE_BLACK_UINT,
    D3D12_STATIC_BORDER_COLOR_OPAQUE_WHITE_UINT
};

enum D3D12_STENCIL_OP
{
    D3D12_STENCIL_OP_KEEP     = 1,
    D3D12_STENCIL_OP_ZERO     = 2,
    D3D12_STENCIL_OP_REPLACE  = 3,
    D3D12_STENCIL_OP_INCR_SAT = 4,
    D3D12_STENCIL_OP_DECR_SAT = 5,
    D3D12_STENCIL_OP_INVERT   = 6,
    D3D12_STENCIL_OP_INCR     = 7,
    D3D12_STENCIL_OP_DECR     = 8
};

enum D3D12_TEXTURE_ADDRESS_MODE
{
    D3D12_TEXTURE_ADDRESS_MODE_WRAP        = 1,
    D3D12_TEXTURE_ADDRESS_MODE_MIRROR      = 2,
    D3D12_TEXTURE_ADDRESS_MODE_CLAMP       = 3,
    D3D12_TEXTURE_ADDRESS_MODE_BORDER      = 4,
    D3D12_TEXTURE_ADDRESS_MODE_MIRROR_ONCE = 5
};

enum D3D12_TEXTURE_BARRIER_FLAGS
{
    D3D12_TEXTURE_BARRIER_FLAG_NONE,
    D3D12_TEXTURE_BARRIER_FLAG_DISCARD
};

enum D3D12_TEXTURE_COPY_TYPE
{
    D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX = 0,
    D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT  = 1
};

enum D3D12_TEXTURE_LAYOUT
{
    D3D12_TEXTURE_LAYOUT_UNKNOWN                = 0,
    D3D12_TEXTURE_LAYOUT_ROW_MAJOR              = 1,
    D3D12_TEXTURE_LAYOUT_64KB_UNDEFINED_SWIZZLE = 2,
    D3D12_TEXTURE_LAYOUT_64KB_STANDARD_SWIZZLE  = 3
};

enum D3D12_TILE_COPY_FLAGS
{
    D3D12_TILE_COPY_FLAG_NONE                                     = 0,
    D3D12_TILE_COPY_FLAG_NO_HAZARD                                = 0x1,
    D3D12_TILE_COPY_FLAG_LINEAR_BUFFER_TO_SWIZZLED_TILED_RESOURCE = 0x2,
    D3D12_TILE_COPY_FLAG_SWIZZLED_TILED_RESOURCE_TO_LINEAR_BUFFER = 0x4
};

enum D3D12_TILE_MAPPING_FLAGS
{
    D3D12_TILE_MAPPING_FLAG_NONE      = 0,
    D3D12_TILE_MAPPING_FLAG_NO_HAZARD = 0x1
};

enum D3D12_TILE_RANGE_FLAGS
{
    D3D12_TILE_RANGE_FLAG_NONE              = 0,
    D3D12_TILE_RANGE_FLAG_NULL              = 1,
    D3D12_TILE_RANGE_FLAG_SKIP              = 2,
    D3D12_TILE_RANGE_FLAG_REUSE_SINGLE_TILE = 4
};

enum D3D12_TILED_RESOURCES_TIER
{
    D3D12_TILED_RESOURCES_TIER_NOT_SUPPORTED = 0,
    D3D12_TILED_RESOURCES_TIER_1             = 1,
    D3D12_TILED_RESOURCES_TIER_2             = 2,
    D3D12_TILED_RESOURCES_TIER_3             = 3,
    D3D12_TILED_RESOURCES_TIER_4             = 4
};

enum D3D12_TRI_STATE
{
    D3D12_TRI_STATE_UNKNOWN,
    D3D12_TRI_STATE_FALSE,
    D3D12_TRI_STATE_TRUE
};

enum D3D12_UAV_DIMENSION
{
    D3D12_UAV_DIMENSION_UNKNOWN        = 0,
    D3D12_UAV_DIMENSION_BUFFER         = 1,
    D3D12_UAV_DIMENSION_TEXTURE1D      = 2,
    D3D12_UAV_DIMENSION_TEXTURE1DARRAY = 3,
    D3D12_UAV_DIMENSION_TEXTURE2D      = 4,
    D3D12_UAV_DIMENSION_TEXTURE2DARRAY = 5,
    D3D12_UAV_DIMENSION_TEXTURE2DMS,
    D3D12_UAV_DIMENSION_TEXTURE2DMSARRAY,
    D3D12_UAV_DIMENSION_TEXTURE3D = 8
};
enum D3D12_VARIABLE_SHADING_RATE_TIER
{
    D3D12_VARIABLE_SHADING_RATE_TIER_NOT_SUPPORTED = 0,
    D3D12_VARIABLE_SHADING_RATE_TIER_1             = 1,
    D3D12_VARIABLE_SHADING_RATE_TIER_2             = 2
};

enum D3D12_VIEW_INSTANCING_FLAGS
{
    D3D12_VIEW_INSTANCING_FLAG_NONE                         = 0,
    D3D12_VIEW_INSTANCING_FLAG_ENABLE_VIEW_INSTANCE_MASKING = 0x1
};

enum D3D12_VIEW_INSTANCING_TIER
{
    D3D12_VIEW_INSTANCING_TIER_NOT_SUPPORTED = 0,
    D3D12_VIEW_INSTANCING_TIER_1             = 1,
    D3D12_VIEW_INSTANCING_TIER_2             = 2,
    D3D12_VIEW_INSTANCING_TIER_3             = 3
};

enum D3D12_WAVE_MMA_TIER
{
    D3D12_WAVE_MMA_TIER_NOT_SUPPORTED = 0,
    D3D12_WAVE_MMA_TIER_1_0           = 10
};

enum D3D12_WRITEBUFFERIMMEDIATE_MODE
{
    D3D12_WRITEBUFFERIMMEDIATE_MODE_DEFAULT    = 0,
    D3D12_WRITEBUFFERIMMEDIATE_MODE_MARKER_IN  = 0x1,
    D3D12_WRITEBUFFERIMMEDIATE_MODE_MARKER_OUT = 0x2
};

// General types
typedef void* ID3D12Device;
typedef void* ID3D12CommandQueue;
typedef void* ID3D12Resource;
typedef void* ID3D12CommandQueue;
typedef void* ID3D12RootSignature;
typedef void* ID3D12StateObject;
typedef void* ID3D12GraphicsCommandList;

// Structs

struct D3D12_COMMAND_QUEUE_DESC
{
    D3D12_COMMAND_LIST_TYPE   Type;
    INT                       Priority;
    D3D12_COMMAND_QUEUE_FLAGS Flags;
    UINT                      NodeMask;
};

struct D3D12_INPUT_ELEMENT_DESC
{
    LPCSTR                     SemanticName;
    UINT                       SemanticIndex;
    DXGI_FORMAT                Format;
    UINT                       InputSlot;
    UINT                       AlignedByteOffset;
    D3D12_INPUT_CLASSIFICATION InputSlotClass;
    UINT                       InstanceDataStepRate;
};

struct D3D12_SO_DECLARATION_ENTRY
{
    UINT   Stream;
    LPCSTR SemanticName;
    UINT   SemanticIndex;
    BYTE   StartComponent;
    BYTE   ComponentCount;
    BYTE   OutputSlot;
};

struct D3D12_VIEWPORT
{
    FLOAT TopLeftX;
    FLOAT TopLeftY;
    FLOAT Width;
    FLOAT Height;
    FLOAT MinDepth;
    FLOAT MaxDepth;
};

struct D3D12_BOX
{
    UINT left;
    UINT top;
    UINT front;
    UINT right;
    UINT bottom;
    UINT back;
};

struct D3D12_DEPTH_STENCILOP_DESC
{
    D3D12_STENCIL_OP      StencilFailOp;
    D3D12_STENCIL_OP      StencilDepthFailOp;
    D3D12_STENCIL_OP      StencilPassOp;
    D3D12_COMPARISON_FUNC StencilFunc;
};

struct D3D12_DEPTH_STENCILOP_DESC1
{
    D3D12_STENCIL_OP      StencilFailOp;
    D3D12_STENCIL_OP      StencilDepthFailOp;
    D3D12_STENCIL_OP      StencilPassOp;
    D3D12_COMPARISON_FUNC StencilFunc;
    UINT8                 StencilReadMask;
    UINT8                 StencilWriteMask;
};

struct D3D12_DEPTH_STENCIL_DESC
{
    BOOL                       DepthEnable;
    D3D12_DEPTH_WRITE_MASK     DepthWriteMask;
    D3D12_COMPARISON_FUNC      DepthFunc;
    BOOL                       StencilEnable;
    UINT8                      StencilReadMask;
    UINT8                      StencilWriteMask;
    D3D12_DEPTH_STENCILOP_DESC FrontFace;
    D3D12_DEPTH_STENCILOP_DESC BackFace;
};

struct D3D12_DEPTH_STENCIL_DESC1
{
    BOOL                       DepthEnable;
    D3D12_DEPTH_WRITE_MASK     DepthWriteMask;
    D3D12_COMPARISON_FUNC      DepthFunc;
    BOOL                       StencilEnable;
    UINT8                      StencilReadMask;
    UINT8                      StencilWriteMask;
    D3D12_DEPTH_STENCILOP_DESC FrontFace;
    D3D12_DEPTH_STENCILOP_DESC BackFace;
    BOOL                       DepthBoundsTestEnable;
};

struct D3D12_DEPTH_STENCIL_DESC2
{
    BOOL                        DepthEnable;
    D3D12_DEPTH_WRITE_MASK      DepthWriteMask;
    D3D12_COMPARISON_FUNC       DepthFunc;
    BOOL                        StencilEnable;
    D3D12_DEPTH_STENCILOP_DESC1 FrontFace;
    D3D12_DEPTH_STENCILOP_DESC1 BackFace;
    BOOL                        DepthBoundsTestEnable;
};

struct D3D12_RENDER_TARGET_BLEND_DESC
{
    BOOL           BlendEnable;
    BOOL           LogicOpEnable;
    D3D12_BLEND    SrcBlend;
    D3D12_BLEND    DestBlend;
    D3D12_BLEND_OP BlendOp;
    D3D12_BLEND    SrcBlendAlpha;
    D3D12_BLEND    DestBlendAlpha;
    D3D12_BLEND_OP BlendOpAlpha;
    D3D12_LOGIC_OP LogicOp;
    UINT8          RenderTargetWriteMask;
};

struct D3D12_BLEND_DESC
{
    BOOL                           AlphaToCoverageEnable;
    BOOL                           IndependentBlendEnable;
    D3D12_RENDER_TARGET_BLEND_DESC RenderTarget[8];
};

struct D3D12_SHADER_BYTECODE
{
    const void* pShaderBytecode;
    SIZE_T      BytecodeLength;
};

struct D3D12_STREAM_OUTPUT_DESC
{
    const D3D12_SO_DECLARATION_ENTRY* pSODeclaration;
    UINT                              NumEntries;
    const UINT*                       pBufferStrides;
    UINT                              NumStrides;
    UINT                              RasterizedStream;
};

struct D3D12_INPUT_LAYOUT_DESC
{
    const D3D12_INPUT_ELEMENT_DESC* pInputElementDescs;
    UINT                            NumElements;
};

struct D3D12_CACHED_PIPELINE_STATE
{
    const void* pCachedBlob;
    SIZE_T      CachedBlobSizeInBytes;
};

struct D3D12_RASTERIZER_DESC
{
    D3D12_FILL_MODE                       FillMode;
    D3D12_CULL_MODE                       CullMode;
    BOOL                                  FrontCounterClockwise;
    INT                                   DepthBias;
    FLOAT                                 DepthBiasClamp;
    FLOAT                                 SlopeScaledDepthBias;
    BOOL                                  DepthClipEnable;
    BOOL                                  MultisampleEnable;
    BOOL                                  AntialiasedLineEnable;
    UINT                                  ForcedSampleCount;
    D3D12_CONSERVATIVE_RASTERIZATION_MODE ConservativeRaster;
};

struct D3D12_RASTERIZER_DESC1
{
    D3D12_FILL_MODE                       FillMode;
    D3D12_CULL_MODE                       CullMode;
    BOOL                                  FrontCounterClockwise;
    FLOAT                                 DepthBias;
    FLOAT                                 DepthBiasClamp;
    FLOAT                                 SlopeScaledDepthBias;
    BOOL                                  DepthClipEnable;
    BOOL                                  MultisampleEnable;
    BOOL                                  AntialiasedLineEnable;
    UINT                                  ForcedSampleCount;
    D3D12_CONSERVATIVE_RASTERIZATION_MODE ConservativeRaster;
};

struct D3D12_RASTERIZER_DESC2
{
    D3D12_FILL_MODE                       FillMode;
    D3D12_CULL_MODE                       CullMode;
    BOOL                                  FrontCounterClockwise;
    FLOAT                                 DepthBias;
    FLOAT                                 DepthBiasClamp;
    FLOAT                                 SlopeScaledDepthBias;
    BOOL                                  DepthClipEnable;
    D3D12_LINE_RASTERIZATION_MODE         LineRasterizationMode;
    UINT                                  ForcedSampleCount;
    D3D12_CONSERVATIVE_RASTERIZATION_MODE ConservativeRaster;
};

struct D3D12_GRAPHICS_PIPELINE_STATE_DESC
{
    ID3D12RootSignature*               pRootSignature;
    D3D12_SHADER_BYTECODE              VS;
    D3D12_SHADER_BYTECODE              PS;
    D3D12_SHADER_BYTECODE              DS;
    D3D12_SHADER_BYTECODE              HS;
    D3D12_SHADER_BYTECODE              GS;
    D3D12_STREAM_OUTPUT_DESC           StreamOutput;
    D3D12_BLEND_DESC                   BlendState;
    UINT                               SampleMask;
    D3D12_RASTERIZER_DESC              RasterizerState;
    D3D12_DEPTH_STENCIL_DESC           DepthStencilState;
    D3D12_INPUT_LAYOUT_DESC            InputLayout;
    D3D12_INDEX_BUFFER_STRIP_CUT_VALUE IBStripCutValue;
    D3D12_PRIMITIVE_TOPOLOGY_TYPE      PrimitiveTopologyType;
    UINT                               NumRenderTargets;
    DXGI_FORMAT                        RTVFormats[8];
    DXGI_FORMAT                        DSVFormat;
    DXGI_SAMPLE_DESC                   SampleDesc;
    UINT                               NodeMask;
    D3D12_CACHED_PIPELINE_STATE        CachedPSO;
    D3D12_PIPELINE_STATE_FLAGS         Flags;
};

struct D3D12_COMPUTE_PIPELINE_STATE_DESC
{
    ID3D12RootSignature*        pRootSignature;
    D3D12_SHADER_BYTECODE       CS;
    UINT                        NodeMask;
    D3D12_CACHED_PIPELINE_STATE CachedPSO;
    D3D12_PIPELINE_STATE_FLAGS  Flags;
};

struct D3D12_RT_FORMAT_ARRAY
{
    DXGI_FORMAT RTFormats[8];
    UINT        NumRenderTargets;
};

struct D3D11_FEATURE_DATA_D3D11_OPTIONS
{
    BOOL OutputMergerLogicOp;
    BOOL UAVOnlyRenderingForcedSampleCount;
    BOOL DiscardAPIsSeenByDriver;
    BOOL FlagsForUpdateAndCopySeenByDriver;
    BOOL ClearView;
    BOOL CopyWithOverlap;
    BOOL ConstantBufferPartialUpdate;
    BOOL ConstantBufferOffsetting;
    BOOL MapNoOverwriteOnDynamicConstantBuffer;
    BOOL MapNoOverwriteOnDynamicBufferSRV;
    BOOL MultisampleRTVWithForcedSampleCountOne;
    BOOL SAD4ShaderInstructions;
    BOOL ExtendedDoublesShaderInstructions;
};

struct D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT
{
    UINT MaxGPUVirtualAddressBitsPerResource;
    UINT MaxGPUVirtualAddressBitsPerProcess;
};

struct D3D11_FEATURE_DATA_D3D11_OPTIONS3
{
    BOOL VPAndRTArrayIndexFromAnyShaderFeedingRasterizer;
};

struct D3D12_FEATURE_DATA_ROOT_SIGNATURE
{
    D3D_ROOT_SIGNATURE_VERSION HighestVersion;
};

struct D3D12_FEATURE_DATA_ARCHITECTURE
{
    UINT NodeIndex;
    BOOL TileBasedRenderer;
    BOOL UMA;
    BOOL CacheCoherentUMA;
};

struct D3D12_FEATURE_DATA_ARCHITECTURE1
{
    UINT NodeIndex;
    BOOL TileBasedRenderer;
    BOOL UMA;
    BOOL CacheCoherentUMA;
    BOOL IsolatedMMU;
};

struct D3D12_FEATURE_DATA_FEATURE_LEVELS
{
    UINT                     NumFeatureLevels;
    const D3D_FEATURE_LEVEL* pFeatureLevelsRequested;
    D3D_FEATURE_LEVEL        MaxSupportedFeatureLevel;
};

struct D3D12_FEATURE_DATA_SHADER_MODEL
{
    D3D_SHADER_MODEL HighestShaderModel;
};

struct D3D12_FEATURE_DATA_FORMAT_SUPPORT
{
    DXGI_FORMAT           Format;
    D3D12_FORMAT_SUPPORT1 Support1;
    D3D12_FORMAT_SUPPORT2 Support2;
};

struct D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS
{
    DXGI_FORMAT                           Format;
    UINT                                  SampleCount;
    D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS Flags;
    UINT                                  NumQualityLevels;
};

struct D3D12_FEATURE_DATA_FORMAT_INFO
{
    DXGI_FORMAT Format;
    UINT8       PlaneCount;
};

struct D3D12_FEATURE_DATA_SHADER_CACHE
{
    D3D12_SHADER_CACHE_SUPPORT_FLAGS SupportFlags;
};

struct D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY
{
    D3D12_COMMAND_LIST_TYPE CommandListType;
    UINT                    Priority;
    BOOL                    PriorityForTypeIsSupported;
};

struct D3D12_FEATURE_DATA_EXISTING_HEAPS
{
    BOOL Supported;
};

struct D3D12_FEATURE_DATA_DISPLAYABLE
{
    BOOL                                     DisplayableTexture;
    D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER SharedResourceCompatibilityTier;
};

struct D3D12_FEATURE_DATA_D3D12_OPTIONS
{
    BOOL                                  DoublePrecisionFloatShaderOps;
    BOOL                                  OutputMergerLogicOp;
    D3D12_SHADER_MIN_PRECISION_SUPPORT    MinPrecisionSupport;
    D3D12_TILED_RESOURCES_TIER            TiledResourcesTier;
    D3D12_RESOURCE_BINDING_TIER           ResourceBindingTier;
    BOOL                                  PSSpecifiedStencilRefSupported;
    BOOL                                  TypedUAVLoadAdditionalFormats;
    BOOL                                  ROVsSupported;
    D3D12_CONSERVATIVE_RASTERIZATION_TIER ConservativeRasterizationTier;
    UINT                                  MaxGPUVirtualAddressBitsPerResource;
    BOOL                                  StandardSwizzle64KBSupported;
    D3D12_CROSS_NODE_SHARING_TIER         CrossNodeSharingTier;
    BOOL                                  CrossAdapterRowMajorTextureSupported;
    BOOL                                  VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation;
    D3D12_RESOURCE_HEAP_TIER              ResourceHeapTier;
};

struct D3D12_FEATURE_DATA_D3D12_OPTIONS1
{
    BOOL WaveOps;
    UINT WaveLaneCountMin;
    UINT WaveLaneCountMax;
    UINT TotalLaneCount;
    BOOL ExpandedComputeResourceStates;
    BOOL Int64ShaderOps;
};

struct D3D12_FEATURE_DATA_D3D12_OPTIONS2
{
    BOOL                                     DepthBoundsTestSupported;
    D3D12_PROGRAMMABLE_SAMPLE_POSITIONS_TIER ProgrammableSamplePositionsTier;
};

struct D3D12_FEATURE_DATA_D3D12_OPTIONS3
{
    BOOL                             CopyQueueTimestampQueriesSupported;
    BOOL                             CastingFullyTypedFormatSupported;
    D3D12_COMMAND_LIST_SUPPORT_FLAGS WriteBufferImmediateSupportFlags;
    D3D12_VIEW_INSTANCING_TIER       ViewInstancingTier;
    BOOL                             BarycentricsSupported;
};

struct D3D12_FEATURE_DATA_D3D12_OPTIONS4
{
    BOOL                                     MSAA64KBAlignedTextureSupported;
    D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER SharedResourceCompatibilityTier;
    BOOL                                     Native16BitShaderOpsSupported;
};

struct D3D12_FEATURE_DATA_D3D12_OPTIONS5
{
    BOOL                   SRVOnlyTiledResourceTier3;
    D3D12_RENDER_PASS_TIER RenderPassesTier;
    D3D12_RAYTRACING_TIER  RaytracingTier;
};

struct D3D12_FEATURE_DATA_D3D12_OPTIONS6
{
    BOOL                             AdditionalShadingRatesSupported;
    BOOL                             PerPrimitiveShadingRateSupportedWithViewportIndexing;
    D3D12_VARIABLE_SHADING_RATE_TIER VariableShadingRateTier;
    UINT                             ShadingRateImageTileSize;
    BOOL                             BackgroundProcessingSupported;
};

struct D3D12_FEATURE_DATA_D3D12_OPTIONS7
{
    D3D12_MESH_SHADER_TIER      MeshShaderTier;
    D3D12_SAMPLER_FEEDBACK_TIER SamplerFeedbackTier;
};

struct D3D12_FEATURE_DATA_D3D12_OPTIONS8
{
    BOOL UnalignedBlockTexturesSupported;
};

struct D3D12_FEATURE_DATA_D3D12_OPTIONS9
{
    BOOL                MeshShaderPipelineStatsSupported;
    BOOL                MeshShaderSupportsFullRangeRenderTargetArrayIndex;
    BOOL                AtomicInt64OnTypedResourceSupported;
    BOOL                AtomicInt64OnGroupSharedSupported;
    BOOL                DerivativesInMeshAndAmplificationShadersSupported;
    D3D12_WAVE_MMA_TIER WaveMMATier;
};

struct D3D12_FEATURE_DATA_D3D12_OPTIONS10
{
    BOOL VariableRateShadingSumCombinerSupported;
    BOOL MeshShaderPerPrimitiveShadingRateSupported;
};

struct D3D12_FEATURE_DATA_D3D12_OPTIONS11
{
    BOOL AtomicInt64OnDescriptorHeapResourceSupported;
};

struct D3D12_FEATURE_DATA_D3D12_OPTIONS12
{
    D3D12_TRI_STATE MSPrimitivesPipelineStatisticIncludesCulledPrimitives;
    BOOL            EnhancedBarriersSupported;
    BOOL            RelaxedFormatCastingSupported;
};

struct D3D12_FEATURE_DATA_D3D12_OPTIONS13
{
    BOOL UnrestrictedBufferTextureCopyPitchSupported;
    BOOL UnrestrictedVertexElementAlignmentSupported;
    BOOL InvertedViewportHeightFlipsYSupported;
    BOOL InvertedViewportDepthFlipsZSupported;
    BOOL TextureCopyBetweenDimensionsSupported;
    BOOL AlphaBlendFactorSupported;
};

struct D3D12_FEATURE_DATA_D3D12_OPTIONS14
{
    BOOL AdvancedTextureOpsSupported;
    BOOL WriteableMSAATexturesSupported;
    BOOL IndependentFrontAndBackStencilRefMaskSupported;
};

struct D3D12_FEATURE_DATA_D3D12_OPTIONS15
{
    BOOL TriangleFanSupported;
    BOOL DynamicIndexBufferStripCutSupported;
};

struct D3D12_FEATURE_DATA_D3D12_OPTIONS16
{
    BOOL DynamicDepthBiasSupported;
    BOOL GPUUploadHeapSupported;
};

struct D3D12_FEATURE_DATA_D3D12_OPTIONS17
{
    BOOL NonNormalizedCoordinateSamplersSupported;
    BOOL ManualWriteTrackingResourceSupported;
};

struct D3D12_FEATURE_DATA_D3D12_OPTIONS18
{
    BOOL RenderPassesValid;
};

struct D3D12_FEATURE_DATA_D3D12_OPTIONS19
{
    INT32  MismatchingOutputDimensionsSupported;
    UINT32 SupportedSampleCountsWithNoOutputs;
    INT32  PointSamplingAddressesNeverRoundUp;
    INT32  RasterizerDesc2Supported;
    INT32  NarrowQuadrilateralLinesSupported;
    INT32  AnisoFilterWithPointMipSupported;
    UINT32 MaxSamplerDescriptorHeapSize;
    UINT32 MaxSamplerDescriptorHeapSizeWithStaticSamplers;
    UINT32 MaxViewDescriptorHeapSize;
    INT32  ComputeOnlyCustomHeapSupported;
};

struct D3D12_FEATURE_DATA_SERIALIZATION
{
    UINT                          NodeIndex;
    D3D12_HEAP_SERIALIZATION_TIER HeapSerializationTier;
};

struct D3D12_FEATURE_DATA_CROSS_NODE
{
    D3D12_CROSS_NODE_SHARING_TIER SharingTier;
    BOOL                          AtomicShaderInstructions;
};

struct D3D12_FEATURE_DATA_QUERY_META_COMMAND
{
    GUID        CommandId;
    UINT        NodeMask;
    const void* pQueryInputData;
    SIZE_T      QueryInputDataSizeInBytes;
    void*       pQueryOutputData;
    SIZE_T      QueryOutputDataSizeInBytes;
};

struct D3D12_RESOURCE_ALLOCATION_INFO
{
    UINT64 SizeInBytes;
    UINT64 Alignment;
};

struct D3D12_RESOURCE_ALLOCATION_INFO1
{
    UINT64 Offset;
    UINT64 Alignment;
    UINT64 SizeInBytes;
};

struct D3D12_HEAP_PROPERTIES
{
    D3D12_HEAP_TYPE         Type;
    D3D12_CPU_PAGE_PROPERTY CPUPageProperty;
    D3D12_MEMORY_POOL       MemoryPoolPreference;
    UINT                    CreationNodeMask;
    UINT                    VisibleNodeMask;
};

struct D3D12_HEAP_DESC
{
    UINT64                SizeInBytes;
    D3D12_HEAP_PROPERTIES Properties;
    UINT64                Alignment;
    D3D12_HEAP_FLAGS      Flags;
};

struct D3D12_MIP_REGION
{
    UINT Width;
    UINT Height;
    UINT Depth;
};

struct D3D12_RESOURCE_DESC
{
    D3D12_RESOURCE_DIMENSION Dimension;
    UINT64                   Alignment;
    UINT64                   Width;
    UINT                     Height;
    UINT16                   DepthOrArraySize;
    UINT16                   MipLevels;
    DXGI_FORMAT              Format;
    DXGI_SAMPLE_DESC         SampleDesc;
    D3D12_TEXTURE_LAYOUT     Layout;
    D3D12_RESOURCE_FLAGS     Flags;
};

struct D3D12_RESOURCE_DESC1
{
    D3D12_RESOURCE_DIMENSION Dimension;
    UINT64                   Alignment;
    UINT64                   Width;
    UINT                     Height;
    UINT16                   DepthOrArraySize;
    UINT16                   MipLevels;
    DXGI_FORMAT              Format;
    DXGI_SAMPLE_DESC         SampleDesc;
    D3D12_TEXTURE_LAYOUT     Layout;
    D3D12_RESOURCE_FLAGS     Flags;
    D3D12_MIP_REGION         SamplerFeedbackMipRegion;
};

struct D3D12_DEPTH_STENCIL_VALUE
{
    FLOAT Depth;
    UINT8 Stencil;
};

struct D3D12_RANGE
{
    SIZE_T Begin;
    SIZE_T End;
};

struct D3D12_RANGE_UINT64
{
    UINT64 Begin;
    UINT64 End;
};

struct D3D12_SUBRESOURCE_RANGE_UINT64
{
    UINT               Subresource;
    D3D12_RANGE_UINT64 Range;
};

struct D3D12_SUBRESOURCE_INFO
{
    UINT64 Offset;
    UINT   RowPitch;
    UINT   DepthPitch;
};

struct D3D12_TILED_RESOURCE_COORDINATE
{
    UINT X;
    UINT Y;
    UINT Z;
    UINT Subresource;
};

struct D3D12_TILE_REGION_SIZE
{
    UINT   NumTiles;
    BOOL   UseBox;
    UINT   Width;
    UINT16 Height;
    UINT16 Depth;
};

struct D3D12_SUBRESOURCE_TILING
{
    UINT   WidthInTiles;
    UINT16 HeightInTiles;
    UINT16 DepthInTiles;
    UINT   StartTileIndexInOverallResource;
};

struct D3D12_TILE_SHAPE
{
    UINT WidthInTexels;
    UINT HeightInTexels;
    UINT DepthInTexels;
};

struct D3D12_PACKED_MIP_INFO
{
    UINT8 NumStandardMips;
    UINT8 NumPackedMips;
    UINT  NumTilesForPackedMips;
    UINT  StartTileIndexInOverallResource;
};

struct D3D12_RESOURCE_TRANSITION_BARRIER
{
    ID3D12Resource*       pResource;
    UINT                  Subresource;
    D3D12_RESOURCE_STATES StateBefore;
    D3D12_RESOURCE_STATES StateAfter;
};

struct D3D12_RESOURCE_ALIASING_BARRIER
{
    ID3D12Resource* pResourceBefore;
    ID3D12Resource* pResourceAfter;
};

struct D3D12_RESOURCE_UAV_BARRIER
{
    ID3D12Resource* pResource;
};

struct D3D12_SUBRESOURCE_FOOTPRINT
{
    DXGI_FORMAT Format;
    UINT        Width;
    UINT        Height;
    UINT        Depth;
    UINT        RowPitch;
};

struct D3D12_PLACED_SUBRESOURCE_FOOTPRINT
{
    UINT64                      Offset;
    D3D12_SUBRESOURCE_FOOTPRINT Footprint;
};

struct D3D12_SAMPLE_POSITION
{
    INT8 X;
    INT8 Y;
};

struct D3D12_VIEW_INSTANCE_LOCATION
{
    UINT ViewportArrayIndex;
    UINT RenderTargetArrayIndex;
};

struct D3D12_VIEW_INSTANCING_DESC
{
    UINT                                ViewInstanceCount;
    const D3D12_VIEW_INSTANCE_LOCATION* pViewInstanceLocations;
    D3D12_VIEW_INSTANCING_FLAGS         Flags;
};

struct D3D12_BUFFER_SRV
{
    UINT64                 FirstElement;
    UINT                   NumElements;
    UINT                   StructureByteStride;
    D3D12_BUFFER_SRV_FLAGS Flags;
};

struct D3D12_TEX1D_SRV
{
    UINT  MostDetailedMip;
    UINT  MipLevels;
    FLOAT ResourceMinLODClamp;
};

struct D3D12_TEX1D_ARRAY_SRV
{
    UINT  MostDetailedMip;
    UINT  MipLevels;
    UINT  FirstArraySlice;
    UINT  ArraySize;
    FLOAT ResourceMinLODClamp;
};

struct D3D12_TEX2D_SRV
{
    UINT  MostDetailedMip;
    UINT  MipLevels;
    UINT  PlaneSlice;
    FLOAT ResourceMinLODClamp;
};

struct D3D12_TEX2DMS_SRV
{
    UINT UnusedField_NothingToDefine;
};

struct D3D12_TEX2D_ARRAY_SRV
{
    UINT  MostDetailedMip;
    UINT  MipLevels;
    UINT  FirstArraySlice;
    UINT  ArraySize;
    UINT  PlaneSlice;
    FLOAT ResourceMinLODClamp;
};

struct D3D12_TEX2DMS_ARRAY_SRV
{
    UINT FirstArraySlice;
    UINT ArraySize;
};

struct D3D12_TEX3D_SRV
{
    UINT  MostDetailedMip;
    UINT  MipLevels;
    FLOAT ResourceMinLODClamp;
};

struct D3D12_TEXCUBE_SRV
{
    UINT  MostDetailedMip;
    UINT  MipLevels;
    FLOAT ResourceMinLODClamp;
};

struct D3D12_TEXCUBE_ARRAY_SRV
{
    UINT  MostDetailedMip;
    UINT  MipLevels;
    UINT  First2DArrayFace;
    UINT  NumCubes;
    FLOAT ResourceMinLODClamp;
};

struct D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV
{
    D3D12_GPU_VIRTUAL_ADDRESS Location;
};

struct D3D12_CONSTANT_BUFFER_VIEW_DESC
{
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation;
    UINT                      SizeInBytes;
};

struct D3D12_SAMPLER_DESC
{
    D3D12_FILTER               Filter;
    D3D12_TEXTURE_ADDRESS_MODE AddressU;
    D3D12_TEXTURE_ADDRESS_MODE AddressV;
    D3D12_TEXTURE_ADDRESS_MODE AddressW;
    FLOAT                      MipLODBias;
    UINT                       MaxAnisotropy;
    D3D12_COMPARISON_FUNC      ComparisonFunc;
    FLOAT                      BorderColor[4];
    FLOAT                      MinLOD;
    FLOAT                      MaxLOD;
};

struct D3D12_SAMPLER_DESC2
{
    D3D12_FILTER               Filter;
    D3D12_TEXTURE_ADDRESS_MODE AddressU;
    D3D12_TEXTURE_ADDRESS_MODE AddressV;
    D3D12_TEXTURE_ADDRESS_MODE AddressW;
    FLOAT                      MipLODBias;
    UINT                       MaxAnisotropy;
    D3D12_COMPARISON_FUNC      ComparisonFunc;
    union
    {
        FLOAT FloatBorderColor[4];
        UINT  UintBorderColor[4];
    };
    FLOAT               MinLOD;
    FLOAT               MaxLOD;
    D3D12_SAMPLER_FLAGS Flags;
};

struct D3D12_BUFFER_UAV
{
    UINT64                 FirstElement;
    UINT                   NumElements;
    UINT                   StructureByteStride;
    UINT64                 CounterOffsetInBytes;
    D3D12_BUFFER_UAV_FLAGS Flags;
};

struct D3D12_TEX1D_UAV
{
    UINT MipSlice;
};

struct D3D12_TEX1D_ARRAY_UAV
{
    UINT MipSlice;
    UINT FirstArraySlice;
    UINT ArraySize;
};

struct D3D12_TEX2D_UAV
{
    UINT MipSlice;
    UINT PlaneSlice;
};

struct D3D12_TEX2D_ARRAY_UAV
{
    UINT MipSlice;
    UINT FirstArraySlice;
    UINT ArraySize;
    UINT PlaneSlice;
};

struct D3D12_TEX2DMS_UAV
{
    UINT UnusedField_NothingToDefine;
};

struct D3D12_TEX2DMS_ARRAY_UAV
{
    UINT FirstArraySlice;
    UINT ArraySize;
};

struct D3D12_TEX3D_UAV
{
    UINT MipSlice;
    UINT FirstWSlice;
    UINT WSize;
};

struct D3D12_BUFFER_RTV
{
    UINT64 FirstElement;
    UINT   NumElements;
};

struct D3D12_TEX1D_RTV
{
    UINT MipSlice;
};

struct D3D12_TEX1D_ARRAY_RTV
{
    UINT MipSlice;
    UINT FirstArraySlice;
    UINT ArraySize;
};

struct D3D12_TEX2D_RTV
{
    UINT MipSlice;
    UINT PlaneSlice;
};

struct D3D12_TEX2D_ARRAY_RTV
{
    UINT MipSlice;
    UINT FirstArraySlice;
    UINT ArraySize;
    UINT PlaneSlice;
};

struct D3D12_TEX2DMS_RTV
{
    UINT UnusedField_NothingToDefine;
};

struct D3D12_TEX2DMS_ARRAY_RTV
{
    UINT FirstArraySlice;
    UINT ArraySize;
};

struct D3D12_TEX3D_RTV
{
    UINT MipSlice;
    UINT FirstWSlice;
    UINT WSize;
};

struct D3D12_TEX1D_DSV
{
    UINT MipSlice;
};

struct D3D12_TEX1D_ARRAY_DSV
{
    UINT MipSlice;
    UINT FirstArraySlice;
    UINT ArraySize;
};

struct D3D12_TEX2D_DSV
{
    UINT MipSlice;
};

struct D3D12_TEX2D_ARRAY_DSV
{
    UINT MipSlice;
    UINT FirstArraySlice;
    UINT ArraySize;
};

struct D3D12_TEX2DMS_DSV
{
    UINT UnusedField_NothingToDefine;
};

struct D3D12_TEX2DMS_ARRAY_DSV
{
    UINT FirstArraySlice;
    UINT ArraySize;
};

struct D3D12_DESCRIPTOR_HEAP_DESC
{
    D3D12_DESCRIPTOR_HEAP_TYPE  Type;
    UINT                        NumDescriptors;
    D3D12_DESCRIPTOR_HEAP_FLAGS Flags;
    UINT                        NodeMask;
};

struct D3D12_DESCRIPTOR_RANGE
{
    D3D12_DESCRIPTOR_RANGE_TYPE RangeType;
    UINT                        NumDescriptors;
    UINT                        BaseShaderRegister;
    UINT                        RegisterSpace;
    UINT                        OffsetInDescriptorsFromTableStart;
};

struct D3D12_DESCRIPTOR_RANGE1
{
    D3D12_DESCRIPTOR_RANGE_TYPE  RangeType;
    UINT                         NumDescriptors;
    UINT                         BaseShaderRegister;
    UINT                         RegisterSpace;
    D3D12_DESCRIPTOR_RANGE_FLAGS Flags;
    UINT                         OffsetInDescriptorsFromTableStart;
};

struct D3D12_ROOT_DESCRIPTOR_TABLE
{
    UINT                          NumDescriptorRanges;
    const D3D12_DESCRIPTOR_RANGE* pDescriptorRanges;
};

struct D3D12_ROOT_DESCRIPTOR_TABLE1
{
    UINT                           NumDescriptorRanges;
    const D3D12_DESCRIPTOR_RANGE1* pDescriptorRanges;
};

struct D3D12_ROOT_CONSTANTS
{
    UINT ShaderRegister;
    UINT RegisterSpace;
    UINT Num32BitValues;
};

struct D3D12_ROOT_DESCRIPTOR
{
    UINT ShaderRegister;
    UINT RegisterSpace;
};

struct D3D12_ROOT_DESCRIPTOR1
{
    UINT                        ShaderRegister;
    UINT                        RegisterSpace;
    D3D12_ROOT_DESCRIPTOR_FLAGS Flags;
};

struct D3D12_STATIC_SAMPLER_DESC
{
    D3D12_FILTER               Filter;
    D3D12_TEXTURE_ADDRESS_MODE AddressU;
    D3D12_TEXTURE_ADDRESS_MODE AddressV;
    D3D12_TEXTURE_ADDRESS_MODE AddressW;
    FLOAT                      MipLODBias;
    UINT                       MaxAnisotropy;
    D3D12_COMPARISON_FUNC      ComparisonFunc;
    D3D12_STATIC_BORDER_COLOR  BorderColor;
    FLOAT                      MinLOD;
    FLOAT                      MaxLOD;
    UINT                       ShaderRegister;
    UINT                       RegisterSpace;
    D3D12_SHADER_VISIBILITY    ShaderVisibility;
};

struct D3D12_STATIC_SAMPLER_DESC1
{
    D3D12_FILTER               Filter;
    D3D12_TEXTURE_ADDRESS_MODE AddressU;
    D3D12_TEXTURE_ADDRESS_MODE AddressV;
    D3D12_TEXTURE_ADDRESS_MODE AddressW;
    FLOAT                      MipLODBias;
    UINT                       MaxAnisotropy;
    D3D12_COMPARISON_FUNC      ComparisonFunc;
    D3D12_STATIC_BORDER_COLOR  BorderColor;
    FLOAT                      MinLOD;
    FLOAT                      MaxLOD;
    UINT                       ShaderRegister;
    UINT                       RegisterSpace;
    D3D12_SHADER_VISIBILITY    ShaderVisibility;
    UINT                       Flags;
};

struct D3D12_ROOT_PARAMETER
{
    D3D12_ROOT_PARAMETER_TYPE ParameterType;
    union
    {
        D3D12_ROOT_DESCRIPTOR_TABLE DescriptorTable;
        D3D12_ROOT_CONSTANTS        Constants;
        D3D12_ROOT_DESCRIPTOR       Descriptor;
    };
    D3D12_SHADER_VISIBILITY ShaderVisibility;
};

struct D3D12_ROOT_PARAMETER1
{
    D3D12_ROOT_PARAMETER_TYPE ParameterType;
    union
    {
        D3D12_ROOT_DESCRIPTOR_TABLE1 DescriptorTable;
        D3D12_ROOT_CONSTANTS         Constants;
        D3D12_ROOT_DESCRIPTOR1       Descriptor;
    };
    D3D12_SHADER_VISIBILITY ShaderVisibility;
};

struct D3D12_ROOT_SIGNATURE_DESC
{
    UINT                             NumParameters;
    const D3D12_ROOT_PARAMETER*      pParameters;
    UINT                             NumStaticSamplers;
    const D3D12_STATIC_SAMPLER_DESC* pStaticSamplers;
    D3D12_ROOT_SIGNATURE_FLAGS       Flags;
};

struct D3D12_ROOT_SIGNATURE_DESC1
{
    UINT                             NumParameters;
    const D3D12_ROOT_PARAMETER1*     pParameters;
    UINT                             NumStaticSamplers;
    const D3D12_STATIC_SAMPLER_DESC* pStaticSamplers;
    D3D12_ROOT_SIGNATURE_FLAGS       Flags;
};

struct D3D12_ROOT_SIGNATURE_DESC2
{
    UINT                              NumParameters;
    const D3D12_ROOT_PARAMETER1*      pParameters;
    UINT                              NumStaticSamplers;
    const D3D12_STATIC_SAMPLER_DESC1* pStaticSamplers;
    D3D12_ROOT_SIGNATURE_FLAGS        Flags;
};

struct D3D12_VERSIONED_ROOT_SIGNATURE_DESC
{
    D3D_ROOT_SIGNATURE_VERSION Version;
    union
    {
        D3D12_ROOT_SIGNATURE_DESC  Desc_1_0;
        D3D12_ROOT_SIGNATURE_DESC1 Desc_1_1;
        D3D12_ROOT_SIGNATURE_DESC2 Desc_1_2;
    };
};

struct D3D12_GPU_DESCRIPTOR_HANDLE
{
    UINT64 ptr;
};

struct D3D12_DISCARD_REGION
{
    UINT              NumRects;
    const D3D12_RECT* pRects;
    UINT              FirstSubresource;
    UINT              NumSubresources;
};

struct D3D12_QUERY_HEAP_DESC
{
    D3D12_QUERY_HEAP_TYPE Type;
    UINT                  Count;
    UINT                  NodeMask;
};

struct D3D12_QUERY_DATA_PIPELINE_STATISTICS
{
    UINT64 IAVertices;
    UINT64 IAPrimitives;
    UINT64 VSInvocations;
    UINT64 GSInvocations;
    UINT64 GSPrimitives;
    UINT64 CInvocations;
    UINT64 CPrimitives;
    UINT64 PSInvocations;
    UINT64 HSInvocations;
    UINT64 DSInvocations;
    UINT64 CSInvocations;
};

struct D3D12_QUERY_DATA_PIPELINE_STATISTICS1
{
    UINT64 IAVertices;
    UINT64 IAPrimitives;
    UINT64 VSInvocations;
    UINT64 GSInvocations;
    UINT64 GSPrimitives;
    UINT64 CInvocations;
    UINT64 CPrimitives;
    UINT64 PSInvocations;
    UINT64 HSInvocations;
    UINT64 DSInvocations;
    UINT64 CSInvocations;
    UINT64 ASInvocations;
    UINT64 MSInvocations;
    UINT64 MSPrimitives;
};

struct D3D12_QUERY_DATA_SO_STATISTICS
{
    UINT64 NumPrimitivesWritten;
    UINT64 PrimitivesStorageNeeded;
};

struct D3D12_STREAM_OUTPUT_BUFFER_VIEW
{
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation;
    UINT64                    SizeInBytes;
    D3D12_GPU_VIRTUAL_ADDRESS BufferFilledSizeLocation;
};

struct D3D12_DRAW_ARGUMENTS
{
    UINT VertexCountPerInstance;
    UINT InstanceCount;
    UINT StartVertexLocation;
    UINT StartInstanceLocation;
};

struct D3D12_DRAW_INDEXED_ARGUMENTS
{
    UINT IndexCountPerInstance;
    UINT InstanceCount;
    UINT StartIndexLocation;
    INT  BaseVertexLocation;
    UINT StartInstanceLocation;
};

struct D3D12_DISPATCH_ARGUMENTS
{
    UINT ThreadGroupCountX;
    UINT ThreadGroupCountY;
    UINT ThreadGroupCountZ;
};

struct D3D12_VERTEX_BUFFER_VIEW
{
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation;
    UINT                      SizeInBytes;
    UINT                      StrideInBytes;
};

struct D3D12_INDEX_BUFFER_VIEW
{
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation;
    UINT                      SizeInBytes;
    DXGI_FORMAT               Format;
};

struct D3D12_INDIRECT_ARGUMENT_DESC
{
    D3D12_INDIRECT_ARGUMENT_TYPE Type;
    union
    {
        struct
        {
            UINT Slot;
        } VertexBuffer;
        struct
        {
            UINT RootParameterIndex;
            UINT DestOffsetIn32BitValues;
            UINT Num32BitValuesToSet;
        } Constant;
        struct
        {
            UINT RootParameterIndex;
        } ConstantBufferView;
        struct
        {
            UINT RootParameterIndex;
        } ShaderResourceView;
        struct
        {
            UINT RootParameterIndex;
        } UnorderedAccessView;
        struct
        {
            UINT RootParameterIndex;
            UINT DestOffsetIn32BitValues;
        } IncrementingConstant;
    };
};

struct D3D12_COMMAND_SIGNATURE_DESC
{
    UINT                                ByteStride;
    UINT                                NumArgumentDescs;
    const D3D12_INDIRECT_ARGUMENT_DESC* pArgumentDescs;
    UINT                                NodeMask;
};

struct D3D12_WRITEBUFFERIMMEDIATE_PARAMETER
{
    D3D12_GPU_VIRTUAL_ADDRESS Dest;
    UINT32                    Value;
};

struct D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT
{
    UINT                                           NodeIndex;
    D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS Support;
};

struct D3D12_PROTECTED_RESOURCE_SESSION_DESC
{
    UINT                                   NodeMask;
    D3D12_PROTECTED_RESOURCE_SESSION_FLAGS Flags;
};

struct D3D12_PROTECTED_RESOURCE_SESSION_DESC1
{
    UINT                                   NodeMask;
    D3D12_PROTECTED_RESOURCE_SESSION_FLAGS Flags;
    GUID                                   ProtectionType;
};

struct D3D12_META_COMMAND_PARAMETER_DESC
{
    LPCWSTR                            Name;
    D3D12_META_COMMAND_PARAMETER_TYPE  Type;
    D3D12_META_COMMAND_PARAMETER_FLAGS Flags;
    D3D12_RESOURCE_STATES              RequiredResourceState;
    UINT                               StructureOffset;
};

struct D3D12_META_COMMAND_DESC
{
    GUID                  Id;
    LPCWSTR               Name;
    D3D12_GRAPHICS_STATES InitializationDirtyState;
    D3D12_GRAPHICS_STATES ExecutionDirtyState;
};

struct D3D12_STATE_OBJECT_CONFIG
{
    D3D12_STATE_OBJECT_FLAGS Flags;
};

struct D3D12_GLOBAL_ROOT_SIGNATURE
{
    ID3D12RootSignature* pGlobalRootSignature;
};

struct D3D12_LOCAL_ROOT_SIGNATURE
{
    ID3D12RootSignature* pLocalRootSignature;
};

struct D3D12_NODE_MASK
{
    UINT NodeMask;
};

struct D3D12_EXPORT_DESC
{
    LPCWSTR            Name;
    LPCWSTR            ExportToRename;
    D3D12_EXPORT_FLAGS Flags;
};

struct D3D12_DXIL_LIBRARY_DESC
{
    D3D12_SHADER_BYTECODE    DXILLibrary;
    UINT                     NumExports;
    const D3D12_EXPORT_DESC* pExports;
};

struct D3D12_EXISTING_COLLECTION_DESC
{
    ID3D12StateObject*       pExistingCollection;
    UINT                     NumExports;
    const D3D12_EXPORT_DESC* pExports;
};

struct D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION
{
    LPCWSTR  SubobjectToAssociate;
    UINT     NumExports;
    LPCWSTR* pExports;
};

struct D3D12_HIT_GROUP_DESC
{
    LPCWSTR              HitGroupExport;
    D3D12_HIT_GROUP_TYPE Type;
    LPCWSTR              AnyHitShaderImport;
    LPCWSTR              ClosestHitShaderImport;
    LPCWSTR              IntersectionShaderImport;
};

struct D3D12_RAYTRACING_SHADER_CONFIG
{
    UINT MaxPayloadSizeInBytes;
    UINT MaxAttributeSizeInBytes;
};

struct D3D12_RAYTRACING_PIPELINE_CONFIG
{
    UINT MaxTraceRecursionDepth;
};

struct D3D12_RAYTRACING_PIPELINE_CONFIG1
{
    UINT                            MaxTraceRecursionDepth;
    D3D12_RAYTRACING_PIPELINE_FLAGS Flags;
};

struct D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE
{
    D3D12_GPU_VIRTUAL_ADDRESS StartAddress;
    UINT64                    StrideInBytes;
};

struct D3D12_GPU_VIRTUAL_ADDRESS_RANGE
{
    D3D12_GPU_VIRTUAL_ADDRESS StartAddress;
    UINT64                    SizeInBytes;
};

struct D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE
{
    D3D12_GPU_VIRTUAL_ADDRESS StartAddress;
    UINT64                    SizeInBytes;
    UINT64                    StrideInBytes;
};

struct D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC
{
    D3D12_GPU_VIRTUAL_ADDRESS            Transform3x4;
    DXGI_FORMAT                          IndexFormat;
    DXGI_FORMAT                          VertexFormat;
    UINT                                 IndexCount;
    UINT                                 VertexCount;
    D3D12_GPU_VIRTUAL_ADDRESS            IndexBuffer;
    D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE VertexBuffer;
};

struct D3D12_RAYTRACING_AABB
{
    FLOAT MinX;
    FLOAT MinY;
    FLOAT MinZ;
    FLOAT MaxX;
    FLOAT MaxY;
    FLOAT MaxZ;
};

struct D3D12_RAYTRACING_GEOMETRY_AABBS_DESC
{
    UINT64                               AABBCount;
    D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE AABBs;
};

struct D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC
{
    D3D12_GPU_VIRTUAL_ADDRESS                                   DestBuffer;
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TYPE InfoType;
};

struct D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC
{
    UINT64 CompactedSizeInBytes;
};

struct D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC
{
    UINT64 DecodedSizeInBytes;
};

struct D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER
{
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE Type;
    UINT                                         NumDescs;
};

struct D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC
{
    UINT64 SerializedSizeInBytes;
    UINT64 NumBottomLevelAccelerationStructurePointers;
};

struct D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER
{
    GUID DriverOpaqueGUID;
    BYTE DriverOpaqueVersioningData[16];
};

struct D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER
{
    D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER DriverMatchingIdentifier;
    UINT64                                           SerializedSizeInBytesIncludingHeader;
    UINT64                                           DeserializedSizeInBytes;
    UINT64                                           NumBottomLevelAccelerationStructurePointersAfterHeader;
};

struct D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC
{
    UINT64 CurrentSizeInBytes;
};

struct D3D12_RAYTRACING_GEOMETRY_DESC
{
    D3D12_RAYTRACING_GEOMETRY_TYPE  Type;
    D3D12_RAYTRACING_GEOMETRY_FLAGS Flags;
    union
    {
        D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC Triangles;
        D3D12_RAYTRACING_GEOMETRY_AABBS_DESC     AABBs;
    };
};

struct D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS
{
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE        Type;
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS Flags;
    UINT                                                NumDescs;
    D3D12_ELEMENTS_LAYOUT                               DescsLayout;
    union
    {
        D3D12_GPU_VIRTUAL_ADDRESS                    InstanceDescs;
        const D3D12_RAYTRACING_GEOMETRY_DESC*        pGeometryDescs;
        const D3D12_RAYTRACING_GEOMETRY_DESC* const* ppGeometryDescs;
    };
};

struct D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC
{
    D3D12_GPU_VIRTUAL_ADDRESS                            DestAccelerationStructureData;
    D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS Inputs;
    D3D12_GPU_VIRTUAL_ADDRESS                            SourceAccelerationStructureData;
    D3D12_GPU_VIRTUAL_ADDRESS                            ScratchAccelerationStructureData;
};

struct D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO
{
    UINT64 ResultDataMaxSizeInBytes;
    UINT64 ScratchDataSizeInBytes;
    UINT64 UpdateScratchDataSizeInBytes;
};

struct D3D12_AUTO_BREADCRUMB_NODE
{
    const char*                       pCommandListDebugNameA;
    const wchar_t*                    pCommandListDebugNameW;
    const char*                       pCommandQueueDebugNameA;
    const wchar_t*                    pCommandQueueDebugNameW;
    ID3D12GraphicsCommandList*        pCommandList;
    ID3D12CommandQueue*               pCommandQueue;
    UINT32                            BreadcrumbCount;
    const UINT32*                     pLastBreadcrumbValue;
    const D3D12_AUTO_BREADCRUMB_OP*   pCommandHistory;
    const D3D12_AUTO_BREADCRUMB_NODE* pNext;
};

struct D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT
{
    const D3D12_AUTO_BREADCRUMB_NODE* pHeadAutoBreadcrumbNode;
};

struct D3D12_DRED_BREADCRUMB_CONTEXT
{
    UINT           BreadcrumbIndex;
    const wchar_t* pContextString;
};

struct D3D12_DRED_ALLOCATION_NODE
{
    const char*                       ObjectNameA;
    const wchar_t*                    ObjectNameW;
    D3D12_DRED_ALLOCATION_TYPE        AllocationType;
    const D3D12_DRED_ALLOCATION_NODE* pNext;
};

struct D3D12_DRED_ALLOCATION_NODE1
{
    const char*                        ObjectNameA;
    const wchar_t*                     ObjectNameW;
    D3D12_DRED_ALLOCATION_TYPE         AllocationType;
    const D3D12_DRED_ALLOCATION_NODE1* pNext;
    const IUnknown*                    pObject;
};

struct D3D12_AUTO_BREADCRUMB_NODE1
{
    const char*                        pCommandListDebugNameA;
    const wchar_t*                     pCommandListDebugNameW;
    const char*                        pCommandQueueDebugNameA;
    const wchar_t*                     pCommandQueueDebugNameW;
    ID3D12GraphicsCommandList*         pCommandList;
    ID3D12CommandQueue*                pCommandQueue;
    UINT                               BreadcrumbCount;
    const UINT*                        pLastBreadcrumbValue;
    const D3D12_AUTO_BREADCRUMB_OP*    pCommandHistory;
    const D3D12_AUTO_BREADCRUMB_NODE1* pNext;
    UINT                               BreadcrumbContextsCount;
    D3D12_DRED_BREADCRUMB_CONTEXT*     pBreadcrumbContexts;
};

struct D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1
{
    const D3D12_AUTO_BREADCRUMB_NODE1* pHeadAutoBreadcrumbNode;
};

struct D3D12_DRED_PAGE_FAULT_OUTPUT
{
    D3D12_GPU_VIRTUAL_ADDRESS         PageFaultVA;
    const D3D12_DRED_ALLOCATION_NODE* pHeadExistingAllocationNode;
    const D3D12_DRED_ALLOCATION_NODE* pHeadRecentFreedAllocationNode;
};

struct D3D12_DRED_PAGE_FAULT_OUTPUT1
{
    D3D12_GPU_VIRTUAL_ADDRESS          PageFaultVA;
    const D3D12_DRED_ALLOCATION_NODE1* pHeadExistingAllocationNode;
    const D3D12_DRED_ALLOCATION_NODE1* pHeadRecentFreedAllocationNode;
};

struct D3D12_DRED_PAGE_FAULT_OUTPUT2
{
    D3D12_GPU_VIRTUAL_ADDRESS          PageFaultVA;
    const D3D12_DRED_ALLOCATION_NODE1* pHeadExistingAllocationNode;
    const D3D12_DRED_ALLOCATION_NODE1* pHeadRecentFreedAllocationNode;
    D3D12_DRED_PAGE_FAULT_FLAGS        PageFaultFlags;
};

struct D3D12_DEVICE_REMOVED_EXTENDED_DATA
{
    D3D12_DRED_FLAGS            Flags;
    D3D12_AUTO_BREADCRUMB_NODE* pHeadAutoBreadcrumbNode;
};

struct D3D12_DEVICE_REMOVED_EXTENDED_DATA1
{
    HRESULT                            DeviceRemovedReason;
    D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT AutoBreadcrumbsOutput;
    D3D12_DRED_PAGE_FAULT_OUTPUT       PageFaultOutput;
};

struct D3D12_DEVICE_REMOVED_EXTENDED_DATA2
{
    HRESULT                             DeviceRemovedReason;
    D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1 AutoBreadcrumbsOutput;
    D3D12_DRED_PAGE_FAULT_OUTPUT1       PageFaultOutput;
};

struct D3D12_DEVICE_REMOVED_EXTENDED_DATA3
{
    HRESULT                             DeviceRemovedReason;
    D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1 AutoBreadcrumbsOutput;
    D3D12_DRED_PAGE_FAULT_OUTPUT2       PageFaultOutput;
    D3D12_DRED_DEVICE_STATE             DeviceState;
};

struct D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT
{
    UINT NodeIndex;
    UINT Count;
};

struct D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES
{
    UINT  NodeIndex;
    UINT  Count;
    GUID* pTypes;
};

struct D3D12_CLEAR_VALUE
{
    DXGI_FORMAT Format;
    union
    {
        FLOAT                     Color[4];
        D3D12_DEPTH_STENCIL_VALUE DepthStencil;
    };
};

struct D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS
{
    D3D12_CLEAR_VALUE ClearValue;
};

struct D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS
{
    UINT AdditionalWidth;
    UINT AdditionalHeight;
};

struct D3D12_RENDER_PASS_BEGINNING_ACCESS
{
    D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE Type;
    union
    {
        D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS          Clear;
        D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS PreserveLocal;
    };
};

struct D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS
{
    UINT       SrcSubresource;
    UINT       DstSubresource;
    UINT       DstX;
    UINT       DstY;
    D3D12_RECT SrcRect;
};

struct D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS
{
    ID3D12Resource*                                                       pSrcResource;
    ID3D12Resource*                                                       pDstResource;
    UINT                                                                  SubresourceCount;
    const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS* pSubresourceParameters;
    DXGI_FORMAT                                                           Format;
    D3D12_RESOLVE_MODE                                                    ResolveMode;
    BOOL                                                                  PreserveResolveSource;
};

struct D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS
{
    UINT AdditionalWidth;
    UINT AdditionalHeight;
};

struct D3D12_CPU_DESCRIPTOR_HANDLE
{
    SIZE_T ptr;
};

struct D3D12_RENDER_PASS_ENDING_ACCESS
{
    D3D12_RENDER_PASS_ENDING_ACCESS_TYPE Type;
    union
    {
        D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS        Resolve;
        D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS PreserveLocal;
    };
};

struct D3D12_RENDER_PASS_RENDER_TARGET_DESC
{
    D3D12_CPU_DESCRIPTOR_HANDLE        cpuDescriptor;
    D3D12_RENDER_PASS_BEGINNING_ACCESS BeginningAccess;
    D3D12_RENDER_PASS_ENDING_ACCESS    EndingAccess;
};

struct D3D12_RENDER_PASS_DEPTH_STENCIL_DESC
{
    D3D12_CPU_DESCRIPTOR_HANDLE        cpuDescriptor;
    D3D12_RENDER_PASS_BEGINNING_ACCESS DepthBeginningAccess;
    D3D12_RENDER_PASS_BEGINNING_ACCESS StencilBeginningAccess;
    D3D12_RENDER_PASS_ENDING_ACCESS    DepthEndingAccess;
    D3D12_RENDER_PASS_ENDING_ACCESS    StencilEndingAccess;
};

struct D3D12_DISPATCH_RAYS_DESC
{
    D3D12_GPU_VIRTUAL_ADDRESS_RANGE            RayGenerationShaderRecord;
    D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE MissShaderTable;
    D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE HitGroupTable;
    D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE CallableShaderTable;
    UINT                                       Width;
    UINT                                       Height;
    UINT                                       Depth;
};

struct D3D12_SHADER_CACHE_SESSION_DESC
{
    GUID                     Identifier;
    D3D12_SHADER_CACHE_MODE  Mode;
    D3D12_SHADER_CACHE_FLAGS Flags;
    UINT                     MaximumInMemoryCacheSizeBytes;
    UINT                     MaximumInMemoryCacheEntries;
    UINT                     MaximumValueFileSizeBytes;
    UINT64                   Version;
};

struct D3D12_BARRIER_SUBRESOURCE_RANGE
{
    UINT IndexOrFirstMipLevel;
    UINT NumMipLevels;
    UINT FirstArraySlice;
    UINT NumArraySlices;
    UINT FirstPlane;
    UINT NumPlanes;
};

struct D3D12_GLOBAL_BARRIER
{
    D3D12_BARRIER_SYNC   SyncBefore;
    D3D12_BARRIER_SYNC   SyncAfter;
    D3D12_BARRIER_ACCESS AccessBefore;
    D3D12_BARRIER_ACCESS AccessAfter;
};

struct D3D12_BUFFER_BARRIER
{
    D3D12_BARRIER_SYNC   SyncBefore;
    D3D12_BARRIER_SYNC   SyncAfter;
    D3D12_BARRIER_ACCESS AccessBefore;
    D3D12_BARRIER_ACCESS AccessAfter;
    ID3D12Resource*      pResource;
    UINT64               Offset;
    UINT64               Size;
};

struct D3D12_TEXTURE_BARRIER
{
    D3D12_BARRIER_SYNC              SyncBefore;
    D3D12_BARRIER_SYNC              SyncAfter;
    D3D12_BARRIER_ACCESS            AccessBefore;
    D3D12_BARRIER_ACCESS            AccessAfter;
    D3D12_BARRIER_LAYOUT            LayoutBefore;
    D3D12_BARRIER_LAYOUT            LayoutAfter;
    ID3D12Resource*                 pResource;
    D3D12_BARRIER_SUBRESOURCE_RANGE Subresources;
    D3D12_TEXTURE_BARRIER_FLAGS     Flags;
};

struct D3D12_SUBRESOURCE_DATA
{
    const void* pData;
    LONG_PTR    RowPitch;
    LONG_PTR    SlicePitch;
};

struct D3D12_MEMCPY_DEST
{
    void*  pData;
    SIZE_T RowPitch;
    SIZE_T SlicePitch;
};

struct D3D12_DEVICE_CONFIGURATION_DESC
{
    UINT Flags;
    UINT GpuBasedValidationFlags;
    UINT SDKVersion;
    UINT NumEnabledExperimentalFeatures;
};

struct D3D12_DISPATCH_MESH_ARGUMENTS
{
    UINT ThreadGroupCountX;
    UINT ThreadGroupCountY;
    UINT ThreadGroupCountZ;
};

struct D3D_SHADER_MACRO
{
    LPCSTR Name;
    LPCSTR Definition;
};

struct D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS
{
    UINT                                                   MaxMessagesPerCommandList;
    D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE           DefaultShaderPatchMode;
    D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS PipelineStateCreateFlags;
};

struct D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS
{
    D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE ShaderPatchMode;
};

struct D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR
{
    FLOAT SlowdownFactor;
};

struct D3D12_MESSAGE
{
    D3D12_MESSAGE_CATEGORY Category;
    D3D12_MESSAGE_SEVERITY Severity;
    D3D12_MESSAGE_ID       ID;
    const char*            pDescription;
    SIZE_T                 DescriptionByteLength;
};

struct D3D12_INFO_QUEUE_FILTER_DESC
{
    UINT                    NumCategories;
    D3D12_MESSAGE_CATEGORY* pCategoryList;
    UINT                    NumSeverities;
    D3D12_MESSAGE_SEVERITY* pSeverityList;
    UINT                    NumIDs;
    D3D12_MESSAGE_ID*       pIDList;
};

struct D3D12_INFO_QUEUE_FILTER
{
    D3D12_INFO_QUEUE_FILTER_DESC AllowList;
    D3D12_INFO_QUEUE_FILTER_DESC DenyList;
};

struct D3D12_RAYTRACING_INSTANCE_DESC
{
    FLOAT                     Transform[3][4];
    UINT                      InstanceID : 24;
    UINT                      InstanceMask : 8;
    UINT                      InstanceContributionToHitGroupIndex : 24;
    UINT                      Flags : 8;
    D3D12_GPU_VIRTUAL_ADDRESS AccelerationStructure;
};

struct D3D12_RESOURCE_BARRIER
{
    D3D12_RESOURCE_BARRIER_TYPE  Type;
    D3D12_RESOURCE_BARRIER_FLAGS Flags;
    union
    {
        D3D12_RESOURCE_TRANSITION_BARRIER Transition;
        D3D12_RESOURCE_ALIASING_BARRIER   Aliasing;
        D3D12_RESOURCE_UAV_BARRIER        UAV;
    };
};

struct D3D12_TEXTURE_COPY_LOCATION
{
    ID3D12Resource*         pResource;
    D3D12_TEXTURE_COPY_TYPE Type;
    union
    {
        D3D12_PLACED_SUBRESOURCE_FOOTPRINT PlacedFootprint;
        UINT                               SubresourceIndex;
    };
};

struct D3D12_SHADER_RESOURCE_VIEW_DESC
{
    DXGI_FORMAT         Format;
    D3D12_SRV_DIMENSION ViewDimension;
    UINT                Shader4ComponentMapping;
    union
    {
        D3D12_BUFFER_SRV                            Buffer;
        D3D12_TEX1D_SRV                             Texture1D;
        D3D12_TEX1D_ARRAY_SRV                       Texture1DArray;
        D3D12_TEX2D_SRV                             Texture2D;
        D3D12_TEX2D_ARRAY_SRV                       Texture2DArray;
        D3D12_TEX2DMS_SRV                           Texture2DMS;
        D3D12_TEX2DMS_ARRAY_SRV                     Texture2DMSArray;
        D3D12_TEX3D_SRV                             Texture3D;
        D3D12_TEXCUBE_SRV                           TextureCube;
        D3D12_TEXCUBE_ARRAY_SRV                     TextureCubeArray;
        D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV RaytracingAccelerationStructure;
    };
};

struct D3D12_UNORDERED_ACCESS_VIEW_DESC
{
    DXGI_FORMAT         Format;
    D3D12_UAV_DIMENSION ViewDimension;
    union
    {
        D3D12_BUFFER_UAV        Buffer;
        D3D12_TEX1D_UAV         Texture1D;
        D3D12_TEX1D_ARRAY_UAV   Texture1DArray;
        D3D12_TEX2D_UAV         Texture2D;
        D3D12_TEX2D_ARRAY_UAV   Texture2DArray;
        D3D12_TEX2DMS_UAV       Texture2DMS;
        D3D12_TEX2DMS_ARRAY_UAV Texture2DMSArray;
        D3D12_TEX3D_UAV         Texture3D;
    };
};

struct D3D12_RENDER_TARGET_VIEW_DESC
{
    DXGI_FORMAT         Format;
    D3D12_RTV_DIMENSION ViewDimension;
    union
    {
        D3D12_BUFFER_RTV        Buffer;
        D3D12_TEX1D_RTV         Texture1D;
        D3D12_TEX1D_ARRAY_RTV   Texture1DArray;
        D3D12_TEX2D_RTV         Texture2D;
        D3D12_TEX2D_ARRAY_RTV   Texture2DArray;
        D3D12_TEX2DMS_RTV       Texture2DMS;
        D3D12_TEX2DMS_ARRAY_RTV Texture2DMSArray;
        D3D12_TEX3D_RTV         Texture3D;
    };
};

struct D3D12_DEPTH_STENCIL_VIEW_DESC
{
    DXGI_FORMAT         Format;
    D3D12_DSV_DIMENSION ViewDimension;
    D3D12_DSV_FLAGS     Flags;
    union
    {
        D3D12_TEX1D_DSV         Texture1D;
        D3D12_TEX1D_ARRAY_DSV   Texture1DArray;
        D3D12_TEX2D_DSV         Texture2D;
        D3D12_TEX2D_ARRAY_DSV   Texture2DArray;
        D3D12_TEX2DMS_DSV       Texture2DMS;
        D3D12_TEX2DMS_ARRAY_DSV Texture2DMSArray;
    };
};

struct D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA
{
    D3D12_DRED_VERSION Version;
    union
    {
        D3D12_DEVICE_REMOVED_EXTENDED_DATA  Dred_1_0;
        D3D12_DEVICE_REMOVED_EXTENDED_DATA1 Dred_1_1;
        D3D12_DEVICE_REMOVED_EXTENDED_DATA2 Dred_1_2;
        D3D12_DEVICE_REMOVED_EXTENDED_DATA3 Dred_1_3;
    };
};

struct D3D12_PIPELINE_STATE_STREAM_DESC
{
    SIZE_T SizeInBytes;
    void*  pPipelineStateSubobjectStream;
};

struct D3D12_STATE_SUBOBJECT
{
    D3D12_STATE_SUBOBJECT_TYPE Type;
    const void*                pDesc;
};

struct D3D12_STATE_OBJECT_DESC
{
    D3D12_STATE_OBJECT_TYPE      Type;
    UINT                         NumSubobjects;
    const D3D12_STATE_SUBOBJECT* pSubobjects;
};

struct D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION
{
    const D3D12_STATE_SUBOBJECT* pSubobjectToAssociate;
    UINT                         NumExports;
    LPCWSTR*                     pExports;
};

struct D3D12_BARRIER_GROUP
{
    D3D12_BARRIER_TYPE Type;
    UINT32             NumBarriers;
    union
    {
        const D3D12_GLOBAL_BARRIER*  pGlobalBarriers;
        const D3D12_TEXTURE_BARRIER* pTextureBarriers;
        const D3D12_BUFFER_BARRIER*  pBufferBarriers;
    };
};

#endif // !defined(D3D12_SUPPORT)

#else

#include <d3dcommon.h>
#include <d3d11.h>
#include <d3d12.h>

#endif // !defined(WIN32)

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
