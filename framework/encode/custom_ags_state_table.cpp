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

#include "custom_ags_state_table.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

bool AgsStateTable::InsertContextCreateData(AGSContext*                     context,
                                            const util::MemoryOutputStream* create_parameter_buffer)
{
    const auto& inserted = ags_context_create_map_.insert(
        std::make_pair(context,
                       std::make_shared<util::MemoryOutputStream>(create_parameter_buffer->GetData(),
                                                                  create_parameter_buffer->GetDataSize())));
    return inserted.second;
}

void AgsStateTable::RemoveContextCreateData(AGSContext* context)
{
    ags_context_create_map_.erase(context);
}

bool AgsStateTable::InsertDeviceCreateData(ID3D12Device*                   device,
                                           const util::MemoryOutputStream* create_parameter_buffer)
{
    const auto& inserted = ags_device_create_map_.insert(
        std::make_pair(device,
                       std::make_shared<util::MemoryOutputStream>(create_parameter_buffer->GetData(),
                                                                  create_parameter_buffer->GetDataSize())));
    return inserted.second;
}

void AgsStateTable::RemoveDeviceCreateData(ID3D12Device* device)
{
    ags_device_create_map_.erase(device);
}

util::MemoryOutputStream* AgsStateTable::GetAgsContextCreateData() const
{
    util::MemoryOutputStream* create_data = nullptr;

    if (!ags_context_create_map_.empty())
    {
        create_data = ags_context_create_map_.begin()->second.get();
    }

    return create_data;
}

util::MemoryOutputStream* AgsStateTable::GetAgsDeviceCreateData() const
{
    util::MemoryOutputStream* create_data = nullptr;

    if (!ags_device_create_map_.empty())
    {
        create_data = ags_device_create_map_.begin()->second.get();
    }

    return create_data;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
