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

#ifndef GFXRECON_ENCODE_VULKAN_DIRECT_DRIVER_INFO_H
#define GFXRECON_ENCODE_VULKAN_DIRECT_DRIVER_INFO_H

#include "format/format.h"
#include "format/format_util.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <cstdint>
#include <string>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

// Exported names that a driver entry point for VK_LUNARG_direct_driver_loading commonly has.
// The capture layer probes these names in order and records the first one that matches the entry point.
inline const std::vector<const char*> kDirectDriverEntryPointNames = { "vk_icdGetInstanceProcAddr",
                                                                       "vkGetInstanceProcAddr" };

// What the capture layer learned about one VkDirectDriverLoadingInfoLUNARG entry.
struct DirectDriverRecord
{
    uint32_t    driver_index{ 0 };
    uint32_t    driver_count{ 0 };
    uint32_t    mode{ VK_DIRECT_DRIVER_LOADING_MODE_EXCLUSIVE_LUNARG };
    uint32_t    flags{ 0 }; // format::DirectDriverInfoFlagBits
    uint64_t    capture_address{ 0 };
    uint64_t    module_offset{ 0 };
    std::string module_path;
    std::string symbol_name;
};

// Fill the fixed part of a SetDirectDriverInfoCommand block from a record. The caller writes the block and
// then the module path and the symbol name, in that order and without terminators.
inline void FillSetDirectDriverInfoCommand(const DirectDriverRecord&           record,
                                           format::ThreadId                    thread_id,
                                           format::SetDirectDriverInfoCommand* command)
{
    command->meta_header.block_header.type = format::BlockType::kMetaDataBlock;
    command->meta_header.block_header.size =
        format::GetMetaDataBlockBaseSize(*command) + record.module_path.size() + record.symbol_name.size();
    command->meta_header.meta_data_id = format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_Vulkan,
                                                               format::MetaDataType::kSetDirectDriverInfoCommand);
    command->thread_id                = thread_id;
    command->driver_index             = record.driver_index;
    command->driver_count             = record.driver_count;
    command->mode                     = record.mode;
    command->flags                    = record.flags;
    command->capture_address          = record.capture_address;
    command->module_offset            = record.module_offset;
    command->module_path_length       = static_cast<uint32_t>(record.module_path.size());
    command->symbol_name_length       = static_cast<uint32_t>(record.symbol_name.size());
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_DIRECT_DRIVER_INFO_H
