/*
** Copyright (c) 2020 LunarG, Inc.
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
