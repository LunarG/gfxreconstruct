/*
** Copyright (c) 2022 LunarG, Inc.
** Copyright (c) 2022 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_DECODE_DX12_RESOURCE_MAPPING_UTIL_H
#define GFXRECON_DECODE_DX12_RESOURCE_MAPPING_UTIL_H

#include "decode/dx12_object_info.h"
#include "decode/dx12_object_mapping_util.h"
#include "decode/dx12_descriptor_map.h"
#include "decode/string_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "graphics/dx12_gpu_va_map.h"
#include "graphics/dx12_resource_data_util.h"
#include "graphics/dx12_shader_id_map.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class Dx12ResourceValueMapper
{
  public:
    void PostProcessCommandListReset(DxObjectInfo* command_list_object_info);

    void PostProcessCreateCommandSignature(HandlePointerDecoder<void*>*        command_signature_decoder,
                                           const D3D12_COMMAND_SIGNATURE_DESC* desc);

    void PostProcessExecuteIndirect(DxObjectInfo* command_list_object_info,
                                    DxObjectInfo* command_signature_object_info,
                                    UINT          max_command_count,
                                    DxObjectInfo* argument_buffer_object_info,
                                    UINT64        argument_buffer_offset,
                                    DxObjectInfo* count_buffer_object_info,
                                    UINT64        count_buffer_offset);
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_RESOURCE_MAPPING_UTIL_H
