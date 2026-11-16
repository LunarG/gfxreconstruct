/*
** Copyright (c) 2026 LunarG, Inc.
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

// Defines the GUIDs (IIDs and CLSIDs) declared by the Agility SDK D3D12 headers.
//
// gfxrecon_decode is built against the Agility SDK headers in external/AgilitySDK, which declare GUIDs that the
// Windows SDK's dxguid.lib doesn't define (for example, ToString<GUID> in generated_dx12_enum_to_string.cpp
// references IID_ID3D12Device15). Defining them here lets any target that links gfxrecon_decode resolve them,
// without each target having to include <initguid.h> itself. The definitions are DECLSPEC_SELECTANY, so they don't
// conflict with dxguid.lib or with other translation units that define the same GUIDs.
//
// The DXGI GUIDs come from the Windows SDK headers, so dxguid.lib already defines them.

// This needs to be included before the D3D12 headers so that their GUIDs are defined and not just declared.
#include <initguid.h>

#include <d3d12.h>
#include <d3d12sdklayers.h>
