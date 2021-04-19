/*
** Copyright (c) 2021 LunarG, Inc.
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
** This file is generated from dx12_struct_add_object_header_generator.py.
**
*/

#ifndef  GFXRECON_GENERATED_DX12_STRUCT_ADD_OBJECTS_H
#define  GFXRECON_GENERATED_DX12_STRUCT_ADD_OBJECTS_H

#include "util/defines.h"
#include "decode/dx12_object_mapping_util.h"
#include "decode/custom_dx12_struct_decoders.h"
#include "generated/generated_dx12_struct_decoders.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
void StructAddObject(const StructPointerDecoder<Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC>* capture_value, const D3D12_GRAPHICS_PIPELINE_STATE_DESC* new_value, Dx12ObjectInfoTable& object_info_table);

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC>* capture_value, const D3D12_COMPUTE_PIPELINE_STATE_DESC* new_value, Dx12ObjectInfoTable& object_info_table);

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_RESOURCE_TRANSITION_BARRIER>* capture_value, const D3D12_RESOURCE_TRANSITION_BARRIER* new_value, Dx12ObjectInfoTable& object_info_table);

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_RESOURCE_ALIASING_BARRIER>* capture_value, const D3D12_RESOURCE_ALIASING_BARRIER* new_value, Dx12ObjectInfoTable& object_info_table);

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_RESOURCE_UAV_BARRIER>* capture_value, const D3D12_RESOURCE_UAV_BARRIER* new_value, Dx12ObjectInfoTable& object_info_table);

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* capture_value, const D3D12_TEXTURE_COPY_LOCATION* new_value, Dx12ObjectInfoTable& object_info_table);

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_GLOBAL_ROOT_SIGNATURE>* capture_value, const D3D12_GLOBAL_ROOT_SIGNATURE* new_value, Dx12ObjectInfoTable& object_info_table);

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_LOCAL_ROOT_SIGNATURE>* capture_value, const D3D12_LOCAL_ROOT_SIGNATURE* new_value, Dx12ObjectInfoTable& object_info_table);

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_EXISTING_COLLECTION_DESC>* capture_value, const D3D12_EXISTING_COLLECTION_DESC* new_value, Dx12ObjectInfoTable& object_info_table);

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_AUTO_BREADCRUMB_NODE>* capture_value, const D3D12_AUTO_BREADCRUMB_NODE* new_value, Dx12ObjectInfoTable& object_info_table);

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_AUTO_BREADCRUMB_NODE1>* capture_value, const D3D12_AUTO_BREADCRUMB_NODE1* new_value, Dx12ObjectInfoTable& object_info_table);

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA>* capture_value, const D3D12_DEVICE_REMOVED_EXTENDED_DATA* new_value, Dx12ObjectInfoTable& object_info_table);

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_DRED_ALLOCATION_NODE1>* capture_value, const D3D12_DRED_ALLOCATION_NODE1* new_value, Dx12ObjectInfoTable& object_info_table);

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT>* capture_value, const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT* new_value, Dx12ObjectInfoTable& object_info_table);

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1>* capture_value, const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1* new_value, Dx12ObjectInfoTable& object_info_table);

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1>* capture_value, const D3D12_DRED_PAGE_FAULT_OUTPUT1* new_value, Dx12ObjectInfoTable& object_info_table);

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS>* capture_value, const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS* new_value, Dx12ObjectInfoTable& object_info_table);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
