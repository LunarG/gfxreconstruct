/*
** Copyright (c) 2022-2023 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_CUSTOM_AGS_STATE_TABLE_H
#define GFXRECON_CUSTOM_AGS_STATE_TABLE_H

#include "util/memory_output_stream.h"

#include <d3d12.h>

#include <map>
#include <memory>

#include <amd_ags.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

// TODO: to merge this table into the Dx12 table (generated code). With a change to the code generator.

class AgsStateTable
{
  public:
    AgsStateTable() {}
    ~AgsStateTable() {}

    bool InsertContextCreateData(AGSContext* context, const util::MemoryOutputStream* create_parameter_buffer);
    void RemoveContextCreateData(AGSContext* context);
    bool InsertDeviceCreateData(ID3D12Device* device, const util::MemoryOutputStream* create_parameter_buffer);
    void RemoveDeviceCreateData(ID3D12Device* device);

    util::MemoryOutputStream* GetAgsContextCreateData() const;
    util::MemoryOutputStream* GetAgsDeviceCreateData() const;

  private:
    std::map<AGSContext*, std::shared_ptr<util::MemoryOutputStream>>   ags_context_create_map_;
    std::map<ID3D12Device*, std::shared_ptr<util::MemoryOutputStream>> ags_device_create_map_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
