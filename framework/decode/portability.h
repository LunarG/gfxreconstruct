/*
** Copyright (c) 2020 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_PORTABILITY_H
#define GFXRECON_DECODE_PORTABILITY_H

#include "decode/vulkan_resource_allocator.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(portability)

// Memory types are considered compatible when each capture memory type has a matching replay memory type where the
// replay property flags are a superset of the capture property flags and the replay heap size is >= the capture heap
// size.  When ignore_heap_sizes is true, only the memory propery flags are compared.
bool CheckMemoryTypeCompatibility(const VkPhysicalDeviceMemoryProperties& capture_props,
                                  const VkPhysicalDeviceMemoryProperties& replay_props,
                                  bool                                    ignore_heap_sizes);

// The following tests are used to identify a replay memory type that is compatible with the capture type specified by
// capture_index.  Check will be skipped when the memory property flags value is zero:
// 1. First, check for an exact match between replay and capture memory property flags, and check that the replay heap
//    size is >= capture heap size.
// 2. If a match is not found, check for replay memory property flags that are a superset of the capture flags, and
//    check that the replay heap size is >= capture heap size.
// 3. If a match is not found, check for an exact match between replay and capture memory property flags, without
//    checking heap sizes.
// 4. If a match is not found, check for replay memory property flags that are a superset of the capture flags, without
//    checking heap sizes.
//
// If a match is still not found, the memory property flags will be adjusted for the following cases:
// - If flags was zero, set flags to HOST_VISIBLE|HOST_COHERENT and run checks 1-4. (Previous checks were skipped with
//   flags = 0).
// - If flags contained both the HOST_VISIBLE and DEVICE_LOCAL bits, remove the DEVICE_LOCAL bit and rerun checks 1-4.
uint32_t FindCompatibleMemoryType(uint32_t                                capture_index,
                                  const VkPhysicalDeviceMemoryProperties& capture_props,
                                  const VkPhysicalDeviceMemoryProperties& replay_props);

bool CheckMemoryTypeIndexValidity(std::vector<uint32_t> indexes);

GFXRECON_END_NAMESPACE(portability)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_PORTABILITY_H
