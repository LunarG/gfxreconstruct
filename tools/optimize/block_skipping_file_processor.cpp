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

#include "block_skipping_file_processor.h"

#include "decode/decode_allocator.h"
#include "format/format_util.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void BlockSkippingFileProcessor::SetBlocksToSkip(std::unordered_set<uint64_t> blocks_to_skip)
{
    blocks_to_skip_ = blocks_to_skip;
    blocks_skipped_ = 0;
}

bool BlockSkippingFileProcessor::IsSkippingFinished()
{
    return blocks_skipped_ == blocks_to_skip_.size();
}

bool BlockSkippingFileProcessor::SkipBlockProcessing()
{
    if (ShouldSkipBlock())
    {
        blocks_skipped_++;
        return true;
    }
    return false;
}

bool BlockSkippingFileProcessor::ShouldSkipBlock()
{
    return (!(blocks_to_skip_.empty())) && (blocks_to_skip_.find(block_index_) != blocks_to_skip_.end());
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
