/*
** Copyright (c) 2016 Advanced Micro Devices, Inc. All rights reserved.
** Copyright (c) 2018 Valve Corporation
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

#ifndef GFXRECON_UTIL_PAGE_STATUS_TRACKER_H
#define GFXRECON_UTIL_PAGE_STATUS_TRACKER_H

#include "util/defines.h"

#include <cstddef>
#include <cstdint>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class PageStatusTracker
{
  public:
    PageStatusTracker(size_t page_count) : active_writes_(page_count, 0), active_reads_(page_count, 0) {}

    ~PageStatusTracker() {}

    bool IsActiveWriteBlock(size_t index) const { return (active_writes_[index] == 1); }
    bool IsActiveReadBlock(size_t index) const { return (active_reads_[index] == 1); }

    void SetActiveWriteBlock(size_t index, bool value) { active_writes_[index] = value ? 1 : 0; }
    void SetActiveReadBlock(size_t index, bool value) { active_reads_[index] = value ? 1 : 0; }

  private:
    typedef std::vector<uint8_t> PageStatus;

  private:
    PageStatus active_writes_; //< Track blocks that have been written.
    PageStatus active_reads_;  //< Track blocks that have been read.
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_PAGE_STATUS_TRACKER_H
