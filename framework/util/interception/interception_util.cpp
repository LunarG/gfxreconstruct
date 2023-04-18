/*
** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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

#include "interception_util.h"

#include "util/file_path.h"
#include "util/interception/injection.h"
#include "util/platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(interception)

// Enable this to debug capture if using the launcher
#define LAUNCHER_DEBUG 0

const char kCaptureLib[]        = "d3d12_capture.dll";
const char kInterceptorLib[]    = "gfxrecon_interceptor.dll";
const char kGfxrCaptureFolder[] = "d3d12_capture";

std::string CaptureLibFolder()
{
    std::string gfxr_location       = gfxrecon::util::platform::GetEnv(gfxrecon::util::interception::kGfxrInstallEnv);
    std::string gfxr_capture_folder = std::string(gfxrecon::util::filepath::kPathSepStr) +
                                      std::string(kGfxrCaptureFolder) +
                                      std::string(gfxrecon::util::filepath::kPathSepStr);

    return gfxr_location + gfxr_capture_folder;
}

std::string CaptureLibPath()
{
    std::string gfxr_d3d12_capture_path = CaptureLibFolder() + kCaptureLib;

#if LAUNCHER_DEBUG
    gfxr_d3d12_capture_path = GFXR_D3D12_CAPTURE_PATH;
#endif

    return gfxr_d3d12_capture_path;
}

std::string D3d12LibPath()
{
    std::string gfxr_d3d12_path = CaptureLibFolder() + kD3d12Lib;

#if LAUNCHER_DEBUG
    gfxr_d3d12_path = GFXR_D3D12_PATH;
#endif

    return gfxr_d3d12_path;
}

std::string DxgiLibPath()
{
    std::string gfxr_dxgi_path = CaptureLibFolder() + kDxgiLib;

#if LAUNCHER_DEBUG
    gfxr_dxgi_path = GFXR_DXGI_PATH;
#endif

    return gfxr_dxgi_path;
}

std::string InterceptorPath(std::string working_dir, std::string app_path)
{
    std::string gfxr_interceptor_path =
        working_dir + std::string(gfxrecon::util::filepath::kPathSepStr) + kInterceptorLib;

#if BUILD_LAUNCHER_AND_INTERCEPTOR
#if LAUNCHER_DEBUG
    gfxr_interceptor_path = gfxrecon::util::interception::GetInterceptorPath(app_path);
#endif
#endif

    return gfxr_interceptor_path;
}

GFXRECON_END_NAMESPACE(interception)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
