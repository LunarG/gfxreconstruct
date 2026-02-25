/*
** Copyright (c) 2020-2024 LunarG, Inc.
** Copyright (c) 2022-2024 Advanced Micro Devices, Inc. All rights reserved.
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

#include PROJECT_VERSION_HEADER_FILE

#include "info_container.h"
#include "info_d3d12_interface.h"
#include "info_openxr_interface.h"
#include "info_vulkan_interface.h"

int main(int argc, const char** argv)
{
    bool success = false;

    gfxrecon::info::InfoContainer info_container;

    // Register APIs for handling info
    info_container.RegisterApiInterface(std::make_unique<gfxrecon::info::InfoVulkanInterface>());
#if defined(D3D12_SUPPORT)
    info_container.RegisterApiInterface(std::make_unique<gfxrecon::info::InfoD3d12Interface>());
#endif
#if ENABLE_OPENXR_SUPPORT
    info_container.RegisterApiInterface(std::make_unique<gfxrecon::info::InfoOpenXrInterface>());
#endif

    // Process the command-line
    if (info_container.ProcessCommandLine(argc, argv))
    {
        success = (info_container.ProcessCapture() && info_container.OutputContent());
    }

    return success ? EXIT_SUCCESS : EXIT_FAILURE;
}
