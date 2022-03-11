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

#ifndef GFXRECON_DECODE_DX12_OBJECT_SCANNING_CONSUMER_BASE_H
#define GFXRECON_DECODE_DX12_OBJECT_SCANNING_CONSUMER_BASE_H

#include "decode/referenced_object_table.h"
#include "generated/generated_dx12_consumer.h"
#include "util/to_string.h"

#include <cctype>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class Dx12ObjectScanningConsumerBase : public Dx12Consumer
{
  public:
    Dx12ObjectScanningConsumerBase(){}; // No implementation file yet...
    virtual ~Dx12ObjectScanningConsumerBase(){};

    void AddObjectWithCreator(format::HandleId object_id, uint64_t block_index, format::ApiCallId call_id)
    {
        referenced_objects_.AddObjectWithCreator(object_id, block_index, call_id);
    }

    void AddObjectStoreBlock(format::HandleId object_id, uint64_t store_block_index)
    {
        referenced_objects_.AddObjectStoreBlock(object_id, store_block_index);
    }

    void MarkObjectReferenced(format::HandleId object_id) { referenced_objects_.MarkObjectReferenced(object_id); }

    void GetUnreferencedObjectCreationBlocks(std::unordered_set<uint64_t>*         unreferenced_blocks,
                                             decode::UnreferencedPsoCreationCalls* calls_info) const
    {
        referenced_objects_.GetUnreferencedObjectCreationBlocks(unreferenced_blocks, calls_info);
    }

  private:
    ReferencedObjectTable referenced_objects_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_OBJECT_SCANNING_CONSUMER_BASE_H
