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

/* BlockBatch: ParsedBlocks and associated memory for a collection of Blocks */
#include "decode/block_allocator.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

uint8_t* BlockAllocator::StartBlock(const BlockAllocationInfo& info)
{
    uint8_t* raw_block_data = nullptr;
    if (info.mode == AllocatorMode::kImmediate)
    {
        // In immediate mode, reset the current batch for each block
        // and use the working buffer for raw block data
        GFXRECON_ASSERT(current_batch_.get() != nullptr);
        // This is the quickest way to reset the batch without reallocating
        current_batch_->reset();
        raw_block_working_buffer_.ReserveDiscarding(info.raw_block_size);
        raw_block_data = raw_block_working_buffer_.get();
    }
    else
    {
        // Enqueue mode
        if (current_batch_->IsBatchFull() || (current_batch_->BytesRemaining() < info.linear_allocation))
        {
            // If the current batch is full, or doesn't have enough space for the new block's linear allocation,
            // flush it and start a new batch.
            FlushBatch();
        }
        raw_block_data = static_cast<uint8_t*>(current_batch_->Allocate(info.raw_block_size));
    }
    return raw_block_data;
}
uint8_t* BlockAllocator::Allocate(size_t size)
{
    GFXRECON_ASSERT(current_batch_.get() != nullptr);
    return static_cast<uint8_t*>(current_batch_->Allocate(size));
}

BlockBatch& BlockAllocator::GetCurrentBatch()
{
    GFXRECON_ASSERT(current_batch_.get() != nullptr);
    return *current_batch_;
}

void BlockAllocator::FlushBatch()
{
    if (batch_sink_proc_.get() != nullptr)
    {
        GFXRECON_ASSERT(current_batch_.get() != nullptr);
        batch_sink_proc_->operator()(std::move(current_batch_));
        current_batch_ = std::make_shared<BlockBatch>();
    }
    else
    {
        // pipe /dev/null
        current_batch_->reset();
    }
}

void BlockAllocator::SetBatchSinkProc(const SinkProc& sink_proc)
{
    batch_sink_proc_ = std::make_unique<SinkProc>(sink_proc);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
