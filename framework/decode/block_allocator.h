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

#ifndef GFXRECON_DECODE_BLOCK_ALLOCATOR_H
#define GFXRECON_DECODE_BLOCK_ALLOCATOR_H

// BlockAllocator: Wrapper/Manager for BlockBatch's

#include "decode/parsed_block.h"
#include "decode/block_batch.h"
#include "util/defines.h"

#include <functional>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class BlockAllocator
{
  public:
    using DataType = uint8_t;
    using SinkProc = std::function<void(BlockBatch::BatchPtr&&)>;

    enum class AllocatorMode : uint8_t
    {
        kImmediate, // Only store a single block in the current batch, resetting on each StartBlock
        kEnqueue    // Accumulate blocks in the current batch until flushed or full, and then enqueue via sink proc
    };

    struct BlockAllocationInfo
    {
        size_t        raw_block_size     = 0;
        size_t        linear_allocation  = 0;
        bool          use_working_buffer = true;
        AllocatorMode mode               = AllocatorMode::kImmediate;
    };

    // 4 KB working buffer for immediate mode raw block data
    // Minimize repeated allocations for early small blocks, though eventually large blocks will exceed this size
    constexpr static size_t kDefaultWorkingSize = 4 * 1024;

    BlockAllocator() : raw_block_working_buffer_(kDefaultWorkingSize), current_batch_(std::make_shared<BlockBatch>()) {}
    ~BlockAllocator() { FlushBatch(); }

    // Start a new block allocation, returning pointer to raw block data storage
    // Estimated block size is used to determine if the current batch can accommodate the block
    uint8_t* StartBlock(const BlockAllocationInfo& info);

    uint8_t*    Allocate(size_t size, size_t alignment);
    BlockBatch& GetCurrentBatch();
    void        FlushBatch();

    void SetBatchSinkProc(const SinkProc& sink_proc);
    void ResetBatchSinkProc() { batch_sink_proc_.reset(); }

    static constexpr bool IsJumboAllocation(size_t size) noexcept { return size >= BlockBatch::kJumboSize; }

  private:
    // In kImmediate mode, use working buffer for raw block data to avoid repeated allocations
    // Because of how BlockParser manages decompression, the working buffer for decomressed data
    // is stored in BlockParser, not here.
    util::HeapBuffer          raw_block_working_buffer_;
    BlockBatch::BatchPtr      current_batch_;
    std::unique_ptr<SinkProc> batch_sink_proc_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_BLOCK_ALLOCATOR_H