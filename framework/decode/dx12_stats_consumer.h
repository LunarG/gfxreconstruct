/*
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

#ifndef GFXRECON_DECODE_DX12_STAT_CONSUMER_H
#define GFXRECON_DECODE_DX12_STAT_CONSUMER_H

#include "generated/generated_dx12_consumer.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class Dx12StatsConsumer : public Dx12Consumer
{
  public:
    Dx12StatsConsumer() :
        device_ID_(0), vendor_ID_(0), subsys_id_(0), revision_(0), dedicated_video_memory_(0),
        dedicated_system_memory_(0), shared_system_memory_(0), data_retrieved_(false)
    {
        memset(&adapter_luid_, sizeof(adapter_luid_), 0);
    }

    WCHAR*   GetAdapterDescription() { return description_; }
    uint32_t GetVendorID() { return vendor_ID_; }
    uint32_t GetDeviceID() { return device_ID_; }
    uint32_t GetSubsysID() { return subsys_id_; }
    uint32_t GetRevision() { return revision_; }
    uint64_t GetDedicatedVideoMemory() { return dedicated_video_memory_; }
    uint64_t GetDedicatedSystemMemory() { return dedicated_system_memory_; }
    uint64_t GetSharedSystemMemory() { return shared_system_memory_; }
    DWORD    GetAdapterLUIDLowPart() { return adapter_luid_.LowPart; };
    LONG     GetAdapterLUIDHighPart() { return adapter_luid_.HighPart; };

    bool IsComplete(uint64_t current_block_index) override { return data_retrieved_; }

    virtual void
    Process_IDXGIAdapter1_GetDesc1(const gfxrecon::decode::ApiCallInfo&                                call_info,
                                   gfxrecon::format::HandleId                                          object_id,
                                   HRESULT                                                             return_value,
                                   gfxrecon::decode::StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC1>* pDesc)
    {
        wcscpy_s(description_, pDesc->GetPointer()->Description);
        vendor_ID_               = pDesc->GetPointer()->VendorId;
        device_ID_               = pDesc->GetPointer()->DeviceId;
        subsys_id_               = pDesc->GetPointer()->SubSysId;
        revision_                = pDesc->GetPointer()->Revision;
        dedicated_video_memory_  = pDesc->GetPointer()->DedicatedVideoMemory;
        dedicated_system_memory_ = pDesc->GetPointer()->DedicatedSystemMemory;
        shared_system_memory_    = pDesc->GetPointer()->SharedSystemMemory;
        adapter_luid_            = pDesc->GetPointer()->AdapterLuid;
        data_retrieved_          = true;
    }

    virtual void Process_IDXGIAdapter_GetDesc(const gfxrecon::decode::ApiCallInfo& call_info,
                                              gfxrecon::format::HandleId           object_id,
                                              HRESULT                              return_value,
                                              gfxrecon::decode::StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC>* pDesc)
    {
        wcscpy_s(description_, pDesc->GetPointer()->Description);
        vendor_ID_               = pDesc->GetPointer()->VendorId;
        device_ID_               = pDesc->GetPointer()->DeviceId;
        subsys_id_               = pDesc->GetPointer()->SubSysId;
        revision_                = pDesc->GetPointer()->Revision;
        dedicated_video_memory_  = pDesc->GetPointer()->DedicatedVideoMemory;
        dedicated_system_memory_ = pDesc->GetPointer()->DedicatedSystemMemory;
        shared_system_memory_    = pDesc->GetPointer()->SharedSystemMemory;
        adapter_luid_            = pDesc->GetPointer()->AdapterLuid;
        data_retrieved_          = true;
    }

  private:
    WCHAR    description_[128] = {};
    uint32_t vendor_ID_;
    uint32_t device_ID_;
    uint32_t subsys_id_;
    uint32_t revision_;
    uint64_t dedicated_video_memory_;
    uint64_t dedicated_system_memory_;
    uint64_t shared_system_memory_;
    LUID     adapter_luid_;
    bool     data_retrieved_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_STAT_CONSUMER_H
