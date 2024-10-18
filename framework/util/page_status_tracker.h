/*
** Copyright (c) 2016 Advanced Micro Devices, Inc. All rights reserved.
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
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

#ifndef GFXRECON_UTIL_PAGE_STATUS_TRACKER_H
#define GFXRECON_UTIL_PAGE_STATUS_TRACKER_H

#include "util/defines.h"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class PageStatusTracker
{
  public:
    typedef std::vector<uint8_t> PageStatus;

  public:
    PageStatusTracker(size_t page_count) : active_writes_(page_count, 0), active_reads_(page_count, 0) {}

    ~PageStatusTracker() {}

    bool IsActiveWriteBlock(size_t index) const { return (active_writes_[index] == 1); }
    bool IsActiveReadBlock(size_t index) const { return (active_reads_[index] == 1); }

    void SetActiveWriteBlock(size_t index, bool value) { active_writes_[index] = value ? 1 : 0; }
    void SetActiveReadBlock(size_t index, bool value) { active_reads_[index] = value ? 1 : 0; }

    void SetAllBlocksActiveWrite() { std::fill(active_writes_.begin(), active_writes_.end(), 1); }

    const PageStatus& GetActiveWrites() const { return active_writes_; }

    static bool HasActiveWriteBlock(const PageStatus& pages, size_t first_page, size_t page_count)
    {
        assert(first_page < pages.size());
        assert(first_page + page_count <= pages.size());

        for (size_t p = 0; p < page_count && ((p + first_page) < pages.size()); ++p)
        {
            if (pages[first_page + p])
            {
                return true;
            }
        }

        return false;
    }

    bool HasActiveWriteBlock(size_t first_page, size_t page_count) const
    {
        return HasActiveWriteBlock(active_writes_, first_page, page_count);
    }

    bool HasActiveWriteBlock() const { return HasActiveWriteBlock(0, active_writes_.size()); }

    size_t GetPageCount() const { return active_writes_.size(); }

  private:
    PageStatus active_writes_; //< Track blocks that have been written.
    PageStatus active_reads_;  //< Track blocks that have been read.
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_PAGE_STATUS_TRACKER_H
