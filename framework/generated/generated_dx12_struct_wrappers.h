/*
** Copyright (c) 2021-2023 LunarG, Inc.
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

/*
** This file is generated from dx12_struct_wrapper_header_generator.py.
**
*/

#ifndef  GFXRECON_GENERATED_DX12_STRUCT_WRAPPERS_H
#define  GFXRECON_GENERATED_DX12_STRUCT_WRAPPERS_H

#include "util/defines.h"

#include <dxgiformat.h>
#include <d3d12.h>
#include <d3dcommon.h>
#include <d3d12sdklayers.h>
#include <dxgi.h>
#include <dxgi1_2.h>
#include <dxgi1_3.h>
#include <dxgi1_4.h>
#include <dxgi1_5.h>
#include <dxgi1_6.h>
#include <dxgicommon.h>
#include <dxgitype.h>
#include <Unknwnbase.h>
#include <guiddef.h>
#include <windef.h>


GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)
void WrapStruct(const D3D12_GRAPHICS_PIPELINE_STATE_DESC* value);

void WrapStruct(const D3D12_COMPUTE_PIPELINE_STATE_DESC* value);

void WrapStruct(const D3D12_RESOURCE_TRANSITION_BARRIER* value);

void WrapStruct(const D3D12_RESOURCE_ALIASING_BARRIER* value);

void WrapStruct(const D3D12_RESOURCE_UAV_BARRIER* value);

void WrapStruct(const D3D12_TEXTURE_COPY_LOCATION* value);

void WrapStruct(const D3D12_GLOBAL_ROOT_SIGNATURE* value);

void WrapStruct(const D3D12_LOCAL_ROOT_SIGNATURE* value);

void WrapStruct(const D3D12_EXISTING_COLLECTION_DESC* value);

void WrapStruct(const D3D12_AUTO_BREADCRUMB_NODE* value);

void WrapStruct(const D3D12_AUTO_BREADCRUMB_NODE1* value);

void WrapStruct(const D3D12_DEVICE_REMOVED_EXTENDED_DATA* value);

void WrapStruct(const D3D12_DRED_ALLOCATION_NODE1* value);

void WrapStruct(const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT* value);

void WrapStruct(const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1* value);

void WrapStruct(const D3D12_DRED_PAGE_FAULT_OUTPUT1* value);

void WrapStruct(const D3D12_DRED_PAGE_FAULT_OUTPUT2* value);

void WrapStruct(const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS* value);

void WrapStruct(const D3D12_TEXTURE_BARRIER* value);

void WrapStruct(const D3D12_BUFFER_BARRIER* value);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
