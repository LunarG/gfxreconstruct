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

#ifndef GFXRECON_DECODE_DX12_DXIL_LRS_PARSER_H
#define GFXRECON_DECODE_DX12_DXIL_LRS_PARSER_H

#include "decode/dx12_object_info.h"
#include "util/defines.h"

#include <cstdint>
#include <map>
#include <set>
#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

#if defined(GFXRECON_DXC_SUPPORT)
// Parse local root signatures and their associations from inside a DXIL library. This function is defined in
// dx12_resource_value_mapper.cpp and declared here so the decode unit tests in framework/decode/test/dxr_lrs_tests.cpp
// can exercise it.
void GetDxilLibraryInDxilLrsInfo(const void*                                          dxil_library_bytecode,
                                 SIZE_T                                               bytecode_length,
                                 format::HandleId                                     state_object_id,
                                 ID3D12DeviceConfiguration1*                          device_config,
                                 std::set<ResourceValueInfo>&                         default_lrs_value_infos,
                                 std::map<std::wstring, std::set<ResourceValueInfo>>& export_lrs_value_infos);
#endif // GFXRECON_DXC_SUPPORT

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_DXIL_LRS_PARSER_H
