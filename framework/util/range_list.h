/*
** Copyright (c) 2026 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_UTIL_RANGE_LIST_H
#define GFXRECON_UTIL_RANGE_LIST_H

#include "util/defines.h"

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <limits>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class RangeList
{
  public:
    struct Range
    {
        uint64_t begin{ 0 };
        uint64_t end{ 0 };

        bool     Empty() const { return begin >= end; }
        uint64_t Size() const { return end - begin; }
    };

    RangeList() = default;

    RangeList(uint64_t offset, uint64_t size) { AddRange(offset, size); }

    void AddRange(uint64_t offset, uint64_t size)
    {
        if (size == 0)
        {
            return;
        }

        const uint64_t max_value = std::numeric_limits<uint64_t>::max();
        const uint64_t end       = (offset > (max_value - size)) ? max_value : (offset + size);
        Add({ offset, end });
    }

    void Add(const Range& range)
    {
        if (range.Empty())
        {
            return;
        }

        Range merged = range;
        auto  iter   = ranges_.begin();

        while (iter != ranges_.end())
        {
            if (merged.end < iter->begin)
            {
                break;
            }

            if (iter->end < merged.begin)
            {
                ++iter;
                continue;
            }

            merged.begin = std::min(merged.begin, iter->begin);
            merged.end   = std::max(merged.end, iter->end);
            iter         = ranges_.erase(iter);
        }

        ranges_.insert(iter, merged);
    }

    void AddRanges(const RangeList& ranges, uint64_t offset = 0)
    {
        for (const auto& range : ranges.ranges_)
        {
            assert(range.begin <= std::numeric_limits<uint64_t>::max() - offset);
            assert(range.end <= std::numeric_limits<uint64_t>::max() - offset);
            Add({ range.begin + offset, range.end + offset });
        }
    }

    bool ContainsRange(uint64_t offset, uint64_t size) const
    {
        if (size == 0)
        {
            return true;
        }

        const uint64_t max_value = std::numeric_limits<uint64_t>::max();
        const uint64_t end       = (offset > (max_value - size)) ? max_value : (offset + size);

        for (const auto& range : ranges_)
        {
            if (range.begin <= offset && end <= range.end)
            {
                return true;
            }
            if (range.begin > offset)
            {
                return false;
            }
        }

        return false;
    }

    RangeList Intersect(uint64_t offset, uint64_t size) const
    {
        RangeList result;
        if (size == 0)
        {
            return result;
        }

        const uint64_t max_value = std::numeric_limits<uint64_t>::max();
        const uint64_t end       = (offset > (max_value - size)) ? max_value : (offset + size);

        for (const auto& range : ranges_)
        {
            if (range.end <= offset)
            {
                continue;
            }
            if (range.begin >= end)
            {
                break;
            }

            result.Add({ std::max(offset, range.begin), std::min(end, range.end) });
        }

        return result;
    }

    const std::vector<Range>& GetRanges() const { return ranges_; }
    bool                      Empty() const { return ranges_.empty(); }
    void                      Clear() { ranges_.clear(); }

  private:
    std::vector<Range> ranges_;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_RANGE_LIST_H
