/*
** Copyright (c) 2025 Advanced Micro Devices, Inc. All rights reserved.
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

#include "graphics/dx12_ags_marker_injector.h"

#include "graphics/dx12_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

Dx12AgsMarkerInjector* instance_ = nullptr;

Dx12AgsMarkerInjector* Dx12AgsMarkerInjector::Get()
{
    return instance_;
}

Dx12AgsMarkerInjector* Dx12AgsMarkerInjector::Create()
{
    if (instance_ == nullptr)
    {
        instance_ = new Dx12AgsMarkerInjector();
    }

    return instance_;
}

bool Dx12AgsMarkerInjector::PushMarker(ID3D12GraphicsCommandList* command_list, const std::string& marker)
{
    bool result = false;

    if ((ags_context_ != nullptr) && (command_list != nullptr))
    {
        char marker_buf[graphics::dx12::kMaxMarkerStrLength] = {};
        strcpy(marker_buf, marker.c_str());

        AGSReturnCode ags_return = agsDriverExtensionsDX12_PushMarker(ags_context_, command_list, marker_buf);

        if (ags_return == AGS_SUCCESS)
        {
            result = true;
        }
        else
        {
            GFXRECON_LOG_WARNING("AGS PushMarker() failed");
        }
    }

    return result;
}

bool Dx12AgsMarkerInjector::PopMarker(ID3D12GraphicsCommandList* command_list)
{
    bool result = false;

    if ((ags_context_ != nullptr) && (command_list != nullptr))
    {
        AGSReturnCode ags_return = agsDriverExtensionsDX12_PopMarker(ags_context_, command_list);

        if (ags_return == AGS_SUCCESS)
        {
            result = true;
        }
        else
        {
            GFXRECON_LOG_WARNING("AGS PopMarker() failed");
        }
    }

    return result;
}

bool Dx12AgsMarkerInjector::SetMarker(ID3D12GraphicsCommandList* command_list, const std::string& marker)
{
    bool result = false;

    if ((ags_context_ != nullptr) && (command_list != nullptr))
    {
        char marker_buf[graphics::dx12::kMaxMarkerStrLength] = {};
        strcpy(marker_buf, marker.c_str());

        AGSReturnCode ags_return = agsDriverExtensionsDX12_SetMarker(ags_context_, command_list, marker_buf);

        if (ags_return == AGS_SUCCESS)
        {
            result = true;
        }
        else
        {
            GFXRECON_LOG_WARNING("AGS SetMarker() failed");
        }
    }

    return result;
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
