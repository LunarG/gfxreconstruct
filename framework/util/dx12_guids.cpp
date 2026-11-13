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

// Defines the D3D12 and DXGI interface and class GUIDs for every library and executable that
// uses them. The newer Agility SDK GUIDs are in no import library, so some translation unit has
// to define them. initguid.h makes each DEFINE_GUID in the headers below a definition instead
// of a declaration. The definitions are DECLSPEC_SELECTANY, so a second definition elsewhere,
// such as one from dxguid.lib, does not conflict.
//
// initguid.h must come before every other header in this file.
#include <initguid.h>

#include <d3d12.h>
#include <d3d12sdklayers.h>
#include <d3d12video.h>
#include <dxgi1_6.h>
#include <dxgidebug.h>

#if defined(GFXRECON_DXC_SUPPORT)
#include <d3d12shader.h>
#include <dxcapi.h>
#endif
