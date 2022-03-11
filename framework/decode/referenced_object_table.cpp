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

#include "decode/referenced_object_table.h"
#include "util/logging.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void ReferencedObjectTable::AddObjectWithCreator(format::HandleId  object_id,
                                                 uint64_t          block_index,
                                                 format::ApiCallId call_id)
{
    if (object_id != format::kNullHandleId)
    {
        auto object_info             = std::make_shared<ObjectInfo>();
        object_info->block_index     = block_index;
        object_info->creator_call_id = call_id;
        objects_.emplace(object_id, object_info);
    }
}

void ReferencedObjectTable::AddObjectStoreBlock(format::HandleId object_id, uint64_t store_block_index)
{
    auto object_entry = objects_.find(object_id);

    if (object_entry != objects_.end())
    {
        object_entry->second->store_block_indices.insert(store_block_index);
        objects_[object_id] = object_entry->second;
    }
}

void ReferencedObjectTable::MarkObjectReferenced(format::HandleId object_id)
{
    auto object_entry = objects_.find(object_id);

    if (object_entry != objects_.end())
    {
        object_entry->second->used = true;
        objects_[object_id]        = object_entry->second;
    }
}

void ReferencedObjectTable::GetUnreferencedObjectCreationBlocks(std::unordered_set<uint64_t>* unreferenced_blocks,
                                                                decode::UnreferencedPsoCreationCalls* calls_info) const
{
    GFXRECON_ASSERT(unreferenced_blocks != nullptr && calls_info != nullptr);

    if (unreferenced_blocks != nullptr && calls_info != nullptr)
    {
        *calls_info = {};
        for (auto object_entry : objects_)
        {
            if (!(object_entry.second->used))
            {
                unreferenced_blocks->insert(object_entry.second->block_index);
                switch (object_entry.second->creator_call_id)
                {
                    case format::ApiCallId::ApiCall_ID3D12Device_CreateGraphicsPipelineState:
                        calls_info->graphics_pso_creation_calls++;
                        break;
                    case format::ApiCallId::ApiCall_ID3D12Device_CreateComputePipelineState:
                        calls_info->compute_pso_creation_calls++;
                        break;
                    default:
                        GFXRECON_LOG_WARNING("Creation function ID %u is not expected",
                                             object_entry.second->creator_call_id);
                        break;
                }
                if (object_entry.second->store_block_indices.size() != 0)
                {
                    for (auto index_entry : object_entry.second->store_block_indices)
                    {
                        unreferenced_blocks->insert(index_entry);
                        calls_info->storepipeline_calls++;
                    }
                }
            }
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
