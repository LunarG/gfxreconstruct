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

#ifndef BRIMSTONE_UTIL_PAGE_STATUS_TRACKER_H
#define BRIMSTONE_UTIL_PAGE_STATUS_TRACKER_H

#include <cstdint>
#include <vector>

#include "util/defines.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(util)

class PageStatusTracker
{
  public:
    PageStatusTracker(size_t page_count);

    ~PageStatusTracker();

    bool IsActiveWriteBlock(size_t index) const { return TestBit(active_writes_, index); }
    bool IsActiveReadBlock(size_t index) const { return TestBit(active_reads_, index); }
    bool IsBlockLoaded(size_t index) const { return TestBit(page_loaded_, index); }

    void SetActiveWriteBlock(size_t index, bool value) { SetBit(&active_writes_, index, value); }
    void SetActiveReadBlock(size_t index, bool value) { SetBit(&active_reads_, index, value); }
    void SetBlockLoaded(size_t index, bool value) { SetBit(&page_loaded_, index, value); }

    void ClearAll();

  private:
    static const size_t          kPageFlagsPerByte = 8;
    typedef std::vector<uint8_t> PageBits;

  private:
    bool TestBit(const PageBits& bits, size_t index) const;
    void SetBit(PageBits* bits, size_t index, bool value);

  private:
    size_t   byte_count_;     //< Number of bytes required to track page status, based on #kPageFlagsPerByte.
    PageBits active_writes_;  //< Track blocks that have been written.
    PageBits active_reads_;   //< Track blocks that have been read.

    /// the array is used for remove initial memcpy real mapped memory to shadow
    /// mapped memory in map process. When target app call map/unmap memory,
    /// some title use large mapped size and only access small part of mapped
    /// memory, if do memcpy for whole mapped size, that cause target title
    /// capture speed extremely slow, so we remove the memcpy from map process,
    /// and put the work in page guard exception handler at first time access to
    /// the page, and only for those pages which are truly accessed.
    ///
    /// we give every page a flag in this array to indicate that page is loaded
    /// or not. In pageguard handler, if the page hasn't been loaded, we copy
    /// the page from real mapped memory to shadow memory to finish the work that
    /// we do in map process previously and set the flag to loaded. The optimization
    /// significantly improve some title capture time from hours to minutes.
    ///
    /// The titles which use big size multiple map/unmap can get capture speed
    /// improved by this optimization, especially if the title only access small
    /// part of mapped size during pair of map/unmap.
    ///
    /// currently the optimization is only used in Windows because it depend on
    /// the page memcpy is inserted just before first access to the page
    /// which is implemented by page guard handler, once we find a way on other
    /// platforms to capture read/write a page, we can also use it on those
    /// platforms.
    PageBits page_loaded_;
};

BRIMSTONE_END_NAMESPACE(util)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_UTIL_PAGE_STATUS_TRACKER_H
