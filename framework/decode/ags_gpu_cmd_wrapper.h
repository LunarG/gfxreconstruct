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

#ifndef GFXRECON_AGS_GPU_CMD_WRAPPER_H
#define GFXRECON_AGS_GPU_CMD_WRAPPER_H

#include "util/defines.h"
#include "format/format.h"

#include "decode/dx_replay_options.h"

#include <d3d12.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class AgsGpuCmdWrapper
{
  public:
    AgsGpuCmdWrapper(DxReplayOptions*           options,
                     ID3D12GraphicsCommandList* command_list,
                     format::HandleId           capture_id,
                     format::ApiCallId          call_id,
                     uint64_t                   block_idx);

    ~AgsGpuCmdWrapper();

  private:
    DxReplayOptions*           current_options{ nullptr };
    ID3D12GraphicsCommandList* current_command_list{ nullptr };
    bool                       bypass_marker_ = false;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_AGS_GPU_CMD_WRAPPER_H
