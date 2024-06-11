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

#include <string>
#include <unordered_map>
#include <map>
#include <vector>

#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class SpirVParsingUtil
{
  public:
    struct BufferReferenceInfo
    {
        uint32_t set                 = 0;
        uint32_t binding             = 0;
        bool     push_constant_block = false;
        uint32_t buffer_offset       = 0;
        uint32_t array_stride        = 0;
    };

    SpirVParsingUtil() = default;

    bool Parse(const uint32_t* spirv_code, size_t spirv_num_bytes);

    [[nodiscard]] std::vector<BufferReferenceInfo> GetBufferReferenceInfos() const;

  private:
    class Instruction;

    const Instruction* FindDef(uint32_t id);
    const Instruction* FindVariableStoring(uint32_t variable_id);
    bool GetVariableDecorations(const Instruction* variable_insn, BufferReferenceInfo& buffer_reference_info);

    // LUT for hopping around instructions from a result ID
    std::unordered_map<uint32_t, const Instruction*> definitions_{};

    std::vector<const Instruction*>                         store_instructions_{};
    std::vector<const Instruction*>                         decorations_instructions_{};
    std::map<BufferReferenceInfo, std::vector<std::string>> buffer_reference_map_{};
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECONSTRUCT_UTIL_SPIRV_PARSING_UTIL_H
