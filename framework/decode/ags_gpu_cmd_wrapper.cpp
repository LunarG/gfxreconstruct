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

#include "decode/ags_gpu_cmd_wrapper.h"

#include "generated/generated_dx12_call_id_to_string.h"
#include "graphics/dx12_ags_marker_injector.h"

#include <locale>
#include <codecvt>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

AgsGpuCmdWrapper::AgsGpuCmdWrapper(DxReplayOptions*           options,
                                   ID3D12GraphicsCommandList* command_list,
                                   format::HandleId           capture_id,
                                   format::ApiCallId          call_id,
                                   uint64_t                   block_idx)
{
    if ((options != nullptr))
    {
        current_options = options;

        if (current_options->ags_inject_markers)
        {
            if (command_list != nullptr)
            {
                current_command_list = command_list;

                if (call_id == format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_BeginEvent ||
                    call_id == format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_EndEvent ||
                    call_id == format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetMarker)
                {
                    bypass_marker_ = true;
                }

                if (bypass_marker_ == false)
                {
                    graphics::Dx12AgsMarkerInjector* injector = graphics::Dx12AgsMarkerInjector::Get();

                    if (injector != nullptr)
                    {
                        std::wstring api_id_w = gfxrecon::util::GetDx12CallIdString(call_id);

                        std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> temp_convert;
                        std::string api_id = temp_convert.to_bytes(api_id_w);

                        std::string marker_str = "gfxr_cmd_list_";
                        marker_str.append(std::to_string(capture_id));
                        marker_str.append(" - ");
                        marker_str.append(api_id);
                        marker_str.append(" - ");
                        marker_str.append("block_idx_");
                        marker_str.append(std::to_string(block_idx));

                        injector->PushMarker(current_command_list, marker_str);
                    }
                }
            }
        }
    }
}

AgsGpuCmdWrapper::~AgsGpuCmdWrapper()
{
    if (current_options != nullptr)
    {
        if (current_options->ags_inject_markers)
        {
            if (current_command_list != nullptr)
            {
                if (bypass_marker_ == false)
                {
                    graphics::Dx12AgsMarkerInjector* injector = graphics::Dx12AgsMarkerInjector::Get();

                    if (injector != nullptr)
                    {
                        injector->PopMarker(current_command_list);
                    }
                }
            }
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
