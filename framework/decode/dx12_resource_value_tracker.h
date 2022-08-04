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

#ifndef GFXRECON_DECODE_DX12_RESOURCE_VALUE_TRACKER_H
#define GFXRECON_DECODE_DX12_RESOURCE_VALUE_TRACKER_H

#include "decode/dx12_object_info.h"
#include "decode/handle_pointer_decoder.h"
#include "util/defines.h"

#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

typedef uint64_t Dx12FillCommandBlockIndex;
typedef uint64_t Dx12FillCommandByteOffset;
#pragma pack(push)
#pragma pack(1)
// There will be many Dx12FillCommandResourceValues. Set struct packing to 1 to minimize memory used.
struct Dx12FillCommandResourceValue
{
    Dx12FillCommandByteOffset offset;
    ResourceValueType         type;
};
#pragma pack(pop)
typedef std::map<Dx12FillCommandBlockIndex, std::vector<Dx12FillCommandResourceValue>> Dx12FillCommandResourceValueMap;

class Dx12ResourceValueTracker
{
  public:
    Dx12ResourceValueTracker(std::function<DxObjectInfo*(format::HandleId id)> get_object_info_func) :
        get_object_info_func_(get_object_info_func)
    {}

    // When Dx12ResourceValueMapper encounters a resource value that needs to be mapped, it will call
    // AddTrackedResourceValue which tries to determine which FillMemoryCommand originally wrote the data based on the
    // FillMemoryCommands and resource copies previously processed by the Dx12ResourceValueTracker.
    void AddTrackedResourceValue(format::HandleId resource_id, ResourceValueType type, uint64_t offset);

    void PostProcessExecuteCommandLists(DxObjectInfo*                             command_queue_object_info,
                                        UINT                                      num_command_lists,
                                        HandlePointerDecoder<ID3D12CommandList*>* command_lists_decoder);

    void PostProcessFillMemoryCommand(uint64_t resource_id, uint64_t offset, uint64_t size, uint64_t block_index);

    void PostProcessInitSubresourceCommand(const format::InitSubresourceCommandHeader& command_header,
                                           uint64_t                                    block_index);

    void GetTrackedResourceValues(Dx12FillCommandResourceValueMap& values)
    {
        values = std::move(tracked_resource_values_);
        tracked_resource_values_.clear();
    }

  private:
    struct TrackedFillCommandInfo
    {
        uint64_t fill_command_block_index{ 0 };
        uint64_t original_offset{ 0 }; ///< Offset into the original resource from the original fill command.
        uint64_t offset{ 0 }; ///< Offset into the containing resource that has data from the original fill command.
        uint64_t size{ 0 };   ///< How much data in the containing resource came from this fill command.
    };

    struct ProcessExecuteCommandListArgs
    {
        std::vector<ResourceCopyInfo> resource_copies;
    };

  private:
    void UpdateFillCommandState(format::HandleId resource_id, const TrackedFillCommandInfo& new_fill_command);

    void ProcessExecuteCommandList(ProcessExecuteCommandListArgs args);

    QueueSyncEventInfo CreateProcessExecuteCommandListSyncEvent(ProcessExecuteCommandListArgs args)
    {
        return QueueSyncEventInfo{ false, false, nullptr, 0, [this, captured_args = std::move(args)]() {
                                      ProcessExecuteCommandList(captured_args);
                                  } };
    }

    std::map<format::HandleId, std::map<uint64_t, TrackedFillCommandInfo>> tracked_fill_commands_;

    Dx12FillCommandResourceValueMap tracked_resource_values_;

    std::function<DxObjectInfo*(format::HandleId id)> get_object_info_func_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_RESOURCE_VALUE_TRACKER_H
