/*
** Copyright (c) 2019-2020 Valve Corporation
** Copyright (c) 2019-2021 LunarG, Inc.
** Copyright (c) 2023-2025 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_DECODE_DX_REPLAY_OPTIONS_H
#define GFXRECON_DECODE_DX_REPLAY_OPTIONS_H

#include "decode/replay_options.h"

#include "util/defines.h"
#include "util/options.h"
#include "util/logging.h"

#include <vector>
#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

static constexpr uint32_t kDefaultBatchingMemoryUsage = 80;

struct DxReplayOptions : public ReplayOptions
{
    bool                 enable_d3d12{ true };
    bool                 enable_d3d12_two_pass_replay{ false };
    bool                 use_cached_psos{ false };
    std::vector<int32_t> AllowedDebugMessages;
    std::vector<int32_t> DeniedDebugMessages;
    bool                 override_object_names{ false };
    bool                 ags_inject_markers{ false };
    int32_t              memory_usage{ kDefaultBatchingMemoryUsage };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX_REPLAY_OPTIONS_H
