/*
** Copyright (c) 2018-2020 Valve Corporation
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

#ifndef GFXRECON_ENCODE_CUSTOM_OPENXR_API_CALL_ENCODERS_H
#define GFXRECON_ENCODE_CUSTOM_OPENXR_API_CALL_ENCODERS_H

#if ENABLE_OPENXR_SUPPORT

#include "encode/parameter_encoder.h"
#include "format/platform_types.h"
#include "util/defines.h"

// Define the platform defines so that we can have entrypoints for each
// possible entrypoint in our dispatch table.
#ifndef XR_USE_PLATFORM_WIN32
#define XR_USE_PLATFORM_WIN32
#endif
#ifndef XR_USE_PLATFORM_WAYLAND
#define XR_USE_PLATFORM_WAYLAND
#endif
#ifndef XR_USE_PLATFORM_XCB
#define XR_USE_PLATFORM_XCB
#endif
#ifndef XR_USE_PLATFORM_XLIB
#define XR_USE_PLATFORM_XLIB
#endif
#ifndef XR_USE_PLATFORM_ANDROID
#define XR_USE_PLATFORM_ANDROID
#endif
#ifndef XR_USE_PLATFORM_ML
#define XR_USE_PLATFORM_ML
#endif
#ifndef XR_USE_PLATFORM_EGL
#define XR_USE_PLATFORM_EGL
#endif
#ifndef XR_USE_GRAPHICS_API_VULKAN
#define XR_USE_GRAPHICS_API_VULKAN
#endif
#ifndef XR_USE_GRAPHICS_API_OPENGL
#define XR_USE_GRAPHICS_API_OPENGL
#endif
#ifndef XR_USE_GRAPHICS_API_OPENGL_ES
#define XR_USE_GRAPHICS_API_OPENGL_ES
#endif
#ifndef XR_USE_GRAPHICS_API_D3D11
#define XR_USE_GRAPHICS_API_D3D11
#endif
#ifndef XR_USE_GRAPHICS_API_D3D12
#define XR_USE_GRAPHICS_API_D3D12
#endif
#ifndef XR_USE_TIMESPEC
#define XR_USE_TIMESPEC
#endif

#include "openxr/openxr.h"
#include "openxr/openxr_platform.h"
#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

XRAPI_ATTR XrResult XRAPI_CALL xrCreateTriangleMeshFB(XrSession                         session,
                                                      const XrTriangleMeshCreateInfoFB* createInfo,
                                                      XrTriangleMeshFB*                 outTriangleMesh);
XRAPI_ATTR XrResult XRAPI_CALL xrDestroyTriangleMeshFB(XrTriangleMeshFB mesh);
XRAPI_ATTR XrResult XRAPI_CALL xrTriangleMeshGetVertexBufferFB(XrTriangleMeshFB mesh, XrVector3f** outVertexBuffer);
XRAPI_ATTR XrResult XRAPI_CALL xrTriangleMeshGetIndexBufferFB(XrTriangleMeshFB mesh, uint32_t** outIndexBuffer);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_ENCODE_CUSTOM_OPENXR_API_CALL_ENCODERS_H
