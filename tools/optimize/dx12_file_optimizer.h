/*
** Copyright (c) 2023 LunarG, Inc.
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

#ifndef GFXRECON_DX12_FILE_OPTIMIZER_H
#define GFXRECON_DX12_FILE_OPTIMIZER_H

#include "decode/dx12_resource_value_tracker.h"
#include "file_optimizer.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

class Dx12FileOptimizer : public FileOptimizer
{
  public:
    Dx12FileOptimizer() :
        fill_command_resource_values_(nullptr), inject_noop_resource_value_optimization_(false),
        num_optimized_fill_commands_(0)
    {}

    void SetFillCommandResourceValues(const decode::Dx12FillCommandResourceValueMap* fill_command_resource_values,
                                      bool inject_noop_resource_value_optimization);

    uint64_t GetNumOptimizedFillCommands() { return num_optimized_fill_commands_; }

  private:
    bool AddFillMemoryResourceValueCommand(const format::BlockHeader& block_header, format::MetaDataId meta_data_id);

    virtual bool ProcessMetaData(const format::BlockHeader& block_header, format::MetaDataId meta_data_id) override;

    const decode::Dx12FillCommandResourceValueMap*          fill_command_resource_values_;
    decode::Dx12FillCommandResourceValueMap::const_iterator resource_values_iter_;
    bool                                                    inject_noop_resource_value_optimization_;

    size_t num_optimized_fill_commands_;

    std::vector<uint8_t> write_buffer_;
};

GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_FILE_OPTIMIZER_H
