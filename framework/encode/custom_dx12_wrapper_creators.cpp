/*
** Copyright (c) 2023 Qualcomm Technologies, Inc. and/or its subsidiaries.
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to
** deal in the Software without restriction, including without limitation the
** rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
** sell copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
** IN THE SOFTWARE.
*/

#include "encode/custom_dx12_wrapper_creators.h"

#include "generated/generated_dx12_wrappers.h"
#include "generated/generated_dx12_wrapper_creators.h"
#include "util/logging.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void WrapID3D11Resource(REFIID riid, void** object, DxWrapperResources* resources)
{
    GFXRECON_UNREFERENCED_PARAMETER(riid);
    GFXRECON_ASSERT((object != nullptr) && (*object != nullptr) && IsEqualIID(riid, IID_ID3D11Resource));

    auto resource = reinterpret_cast<ID3D11Resource**>(object);
    auto type     = D3D11_RESOURCE_DIMENSION{};
    (*resource)->GetType(&type);

    if (type == D3D11_RESOURCE_DIMENSION_TEXTURE2D)
    {
        WrapID3D11Texture2D(IID_ID3D11Texture2D, object, resources);
    }
    else if (type == D3D11_RESOURCE_DIMENSION_BUFFER)
    {
        WrapID3D11Buffer(IID_ID3D11Buffer, object, resources);
    }
    else if (type == D3D11_RESOURCE_DIMENSION_TEXTURE3D)
    {
        WrapID3D11Texture1D(IID_ID3D11Texture1D, object, resources);
    }
    else if (type == D3D11_RESOURCE_DIMENSION_TEXTURE1D)
    {
        WrapID3D11Texture3D(IID_ID3D11Texture3D, object, resources);
    }
    else
    {
        GFXRECON_LOG_DEBUG(
            "An object wrapper for an ID3D11Resource object could not be created because the resource dimension type "
            "is unknown. GFXReconstruct cannot track the object and may produce an invalid capture");
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
