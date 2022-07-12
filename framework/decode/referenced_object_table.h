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

#ifndef GFXRECON_DECODE_REFERENCED_OBJECT_TABLE_H
#define GFXRECON_DECODE_REFERENCED_OBJECT_TABLE_H

#include "format/format.h"
#include "util/defines.h"

#include <memory>
#include <unordered_map>
#include <unordered_set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct UnreferencedPsoCreationCalls
{
    uint64_t graphics_pso_creation_calls{ 0 };
    uint64_t compute_pso_creation_calls{ 0 };
    uint64_t storepipeline_calls{ 0 };
};

// This class is for collecting objects, such as pso's, with their creation/reference info
// The purpose of it is for the optimizer to check if created objects are referenced at all in the trace.
class ReferencedObjectTable
{
  public:
    void AddObjectWithCreator(format::HandleId object_id, uint64_t block_index, format::ApiCallId call_id);

    void AddObjectStoreBlock(format::HandleId object_id, uint64_t store_block_index);

    void MarkObjectReferenced(format::HandleId object_id);

    void GetUnreferencedObjectCreationBlocks(std::unordered_set<uint64_t>*         unreferenced_blocks,
                                             decode::UnreferencedPsoCreationCalls* calls_info) const;

  private:
    // Track the referenced/used state of a object (pso for the first implementation).
    struct ObjectInfo
    {
        bool                         used{ false };
        uint64_t                     block_index{ 0 };
        std::unordered_set<uint64_t> store_block_indices;
        format::ApiCallId            creator_call_id{ format::ApiCallId::ApiCall_Unknown };
    };

    std::unordered_map<format::HandleId, std::shared_ptr<ObjectInfo>> objects_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_REFERENCED_OBJECT_TABLE_H
