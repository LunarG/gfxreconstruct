/*
** Copyright (c) 2024 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_OPENXR_REPLAY_COMMON_STATE_H
#define GFXRECON_DECODE_OPENXR_REPLAY_COMMON_STATE_H

#if ENABLE_OPENXR_SUPPORT
#include "application/application.h"
#include "decode/vulkan_replay_consumer_base.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(openxr)

// Supported graphics bindings for OpenXr replay
enum class GraphicsBindingType
{
    kVulkan,
    kUnknown
};

template <typename T>
class BaseReplayData
{
  public:
    using HandleType = T;
    BaseReplayData(HandleType handle) : handle_(handle) {}
    HandleType GetHandle() const { return handle_; }

  protected:
    HandleType handle_;
};

GFXRECON_END_NAMESPACE(openxr)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_DECODE_OPENXR_REPLAY_COMMON_STATE_H
