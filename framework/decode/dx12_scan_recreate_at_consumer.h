/*
** Copyright (c) 2025 Qualcomm Technologies, Inc. and/or its subsidiaries.
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

#ifndef GFXRECON_DECODE_DX12_SCAN_RECREATE_AT_CONSUMER_H
#define GFXRECON_DECODE_DX12_SCAN_RECREATE_AT_CONSUMER_H

#include "generated/generated_dx12_consumer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class Dx12RecreateAtScanner : public Dx12Consumer
{
  public:
    virtual void ProcessSetGpuVirtualAddressRangeCommand(format::HandleId device_id,
                                                         format::HandleId pageable_id,
                                                         uint64_t         start_address,
                                                         uint64_t         size) override
    {
        D3D12_GPU_VIRTUAL_ADDRESS_RANGE range;
        range.StartAddress = start_address;
        range.SizeInBytes  = size;

        auto ranges_iter = va_ranges.find(device_id);
        if (ranges_iter == va_ranges.end())
        {
            auto result = va_ranges.emplace(device_id, std::make_shared<graphics::dx12::ResourceVaRanges>());
            ranges_iter = result.first;
        }

        auto& ranges = ranges_iter->second;
        ranges->emplace(pageable_id, std::move(range));
    }

    graphics::dx12::DeviceVaRanges GetDeviceVaRanges() { return va_ranges; }

    const graphics::dx12::DeviceVaRanges& GetDeviceVaRanges() const { return va_ranges; }

  public:
    graphics::dx12::DeviceVaRanges va_ranges;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_SCAN_RECREATE_AT_CONSUMER_H
