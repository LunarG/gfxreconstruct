/*
** Copyright (c) 2023 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_CUSTOM_DX12_ARRAY_SIZE_2D_H
#define GFXRECON_ENCODE_CUSTOM_DX12_ARRAY_SIZE_2D_H

#include "format/platform_types.h"
#include "util/defines.h"

#include <d3d12.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

template <typename... T>
class ArraySize2D
{};

template <>
class ArraySize2D<UINT,
                  UINT,
                  const D3D12_RESOURCE_DESC1*,
                  const UINT32*,
                  const DXGI_FORMAT* const*,
                  D3D12_RESOURCE_ALLOCATION_INFO1*>
{
  public:
    ArraySize2D(UINT                             visibleMask,
                UINT                             numResourceDescs,
                const D3D12_RESOURCE_DESC1*      pResourceDescs,
                const UINT32*                    pNumCastableFormats,
                const DXGI_FORMAT* const*        ppCastableFormats,
                D3D12_RESOURCE_ALLOCATION_INFO1* pResourceAllocationInfo1) :
        size_(numResourceDescs),
        num_castable_formats_(pNumCastableFormats){};
    size_t size() const { return size_; }
    size_t operator[](size_t i) const { return (num_castable_formats_ != nullptr) ? num_castable_formats_[i] : 0; }

  private:
    const size_t  size_;
    const UINT32* num_castable_formats_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_CUSTOM_DX12_ARRAY_SIZE_2D_H
