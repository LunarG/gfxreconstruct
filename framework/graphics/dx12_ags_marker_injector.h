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

#ifndef GFXRECON_DX12_AGS_MARKER_INJECTOR_H
#define GFXRECON_DX12_AGS_MARKER_INJECTOR_H

#include "util/defines.h"

#include <string>
#include <d3d12.h>
#include <amd_ags.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

class Dx12AgsMarkerInjector
{
  public:
    static Dx12AgsMarkerInjector* Get();
    static Dx12AgsMarkerInjector* Create();
    bool                          PushMarker(ID3D12GraphicsCommandList* command_list, const std::string& marker);
    bool                          PopMarker(ID3D12GraphicsCommandList* command_list);
    bool                          SetMarker(ID3D12GraphicsCommandList* command_list, const std::string& marker);
    void                          SetContext(AGSContext* context) { ags_context_ = context; }
    AGSContext*                   Context() { return ags_context_; }

  private:
    AGSContext* ags_context_{ nullptr };
};

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DX12_AGS_MARKER_INJECTOR_H
