
/*
** Copyright (c) 2021 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_GRAPHICS_GPU_VA_MAP_H
#define GFXRECON_GRAPHICS_GPU_VA_MAP_H

#include "format/format.h"
#include "util/defines.h"

#include <map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

typedef bool (*ResourceMatchFunctionPtr)(format::HandleId id);

class Dx12GpuVaMap
{
  public:
    void Add(format::HandleId resource_id, uint64_t old_start_address, uint64_t old_size, uint64_t new_start_address);

    void Remove(format::HandleId resource_id, uint64_t old_start_address);

    uint64_t Map(uint64_t                 old_address,
                 format::HandleId*        resource_id             = nullptr,
                 bool*                    found                   = nullptr,
                 uint64_t                 minimum_old_end_address = 0,
                 ResourceMatchFunctionPtr resource_match_func     = nullptr) const;

  private:
    struct GpuVaInfo
    {
        uint64_t old_end_address{ 0 };
        uint64_t new_start_address{ 0 };
    };

    typedef std::map<format::HandleId, GpuVaInfo>                             AliasedResourceVaInfo;
    typedef std::map<uint64_t, AliasedResourceVaInfo, std::greater<uint64_t>> GpuVaMap;

  private:
    bool FindMatch(const AliasedResourceVaInfo& resource_info,
                   uint64_t                     old_start_address,
                   uint64_t&                    address,
                   format::HandleId*            resource_id,
                   uint64_t                     minimum_old_end_address,
                   ResourceMatchFunctionPtr     resource_match_func = nullptr) const;

  private:
    GpuVaMap gpu_va_map_;
};

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GRAPHICS_GPU_VA_MAP_H
