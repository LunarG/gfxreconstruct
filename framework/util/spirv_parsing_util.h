/*
** Copyright (c) 2024 LunarG, Inc.
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

#ifndef GFXRECONSTRUCT_UTIL_SPIRV_PARSING_UTIL_H
#define GFXRECONSTRUCT_UTIL_SPIRV_PARSING_UTIL_H

#include <set>
#include <vector>
#include <tuple>

#include "util/defines.h"
#include "encode/vulkan_state_info.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class SpirVParsingUtil
{
  public:
    enum class BufferReferenceLocation
    {
        INVALID = 0,
        UNIFORM_BUFFER,
        STORAGE_BUFFER,
        SHADER_RECORD_BUFFER,
        PUSH_CONSTANT_BLOCK
    };

    struct BufferReferenceInfo
    {
        BufferReferenceLocation source        = BufferReferenceLocation::INVALID;
        uint32_t                set           = 0;
        uint32_t                binding       = 0;
        uint32_t                buffer_offset = 0;
        uint32_t                array_stride  = 0;

        //! an address inside the buffer that the address at 'buffer_offset' points to, at 'chain_offset'
        bool     chain        = false;
        uint32_t chain_offset = 0;

        //! stride of 'chain_offset' in the pointee, 0 for a single location
        uint32_t chain_stride = 0;

        bool operator==(const SpirVParsingUtil::BufferReferenceInfo& other) const = default;
    };

    SpirVParsingUtil() = default;

    bool ParseBufferReferences(const uint32_t* spirv_code, size_t spirv_num_bytes);

    [[nodiscard]] std::vector<BufferReferenceInfo> GetBufferReferenceInfos() const;

  private:
    std::set<BufferReferenceInfo> buffer_references_{};
};

// used to enable type as key for std::set/map
inline bool operator<(const SpirVParsingUtil::BufferReferenceInfo& lhs,
                      const SpirVParsingUtil::BufferReferenceInfo& rhs)
{
    auto key = [](const SpirVParsingUtil::BufferReferenceInfo& info) {
        return std::tie(info.source,
                        info.set,
                        info.binding,
                        info.buffer_offset,
                        info.array_stride,
                        info.chain,
                        info.chain_offset,
                        info.chain_stride);
    };
    return key(lhs) < key(rhs);
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECONSTRUCT_UTIL_SPIRV_PARSING_UTIL_H
