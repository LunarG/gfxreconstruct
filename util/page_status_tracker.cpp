/*
** Copyright (c) 2016 Advanced Micro Devices, Inc. All rights reserved.
** Copyright (c) 2018 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#include <algorithm>
#include <cassert>

#include "util/page_status_tracker.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(util)

PageStatusTracker::PageStatusTracker(size_t page_count)
{
    byte_count_ = page_count / kPageFlagsPerByte;

    if ((page_count % kPageFlagsPerByte) != 0)
    {
        byte_count_ += 1;
    }

    active_writes_.resize(byte_count_, 0);
    active_reads_.resize(byte_count_, 0);
    page_loaded_.resize(byte_count_, 0);
}

PageStatusTracker::~PageStatusTracker() {}

bool PageStatusTracker::TestBit(const PageBits& bits, size_t index) const
{
    assert((index / kPageFlagsPerByte) < byte_count_);

    size_t  bitset_index = index / kPageFlagsPerByte;
    uint8_t test_bit     = 0x01 << (index % kPageFlagsPerByte);
    return ((bits[bitset_index] & test_bit) == test_bit);
}

void PageStatusTracker::SetBit(PageBits* bits, size_t index, bool value)
{
    assert(bits != nullptr);
    assert((index / kPageFlagsPerByte) < byte_count_);

    size_t  bitset_index = index / kPageFlagsPerByte;
    uint8_t set_bit      = 0x01 << (index % kPageFlagsPerByte);

    if (value)
    {
        (*bits)[bitset_index] |= set_bit;
    }
    else
    {
        (*bits)[bitset_index] &= ~set_bit;
    }
}

void PageStatusTracker::ClearAll()
{
    std::fill(active_writes_.begin(), active_writes_.end(), 0);
    std::fill(active_reads_.begin(), active_reads_.end(), 0);
    std::fill(page_loaded_.begin(), page_loaded_.end(), 0);
}

BRIMSTONE_END_NAMESPACE(util)
BRIMSTONE_END_NAMESPACE(brimstone)
