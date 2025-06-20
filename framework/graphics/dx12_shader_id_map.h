
/*
** Copyright (c) 2022 LunarG, Inc.
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

#ifndef GFXRECON_GRAPHICS_SHADER_ID_MAP_H
#define GFXRECON_GRAPHICS_SHADER_ID_MAP_H

#include "format/format.h"
#include "util/defines.h"

#include <map>
#include <array>
#include <d3d12.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

typedef std::array<uint8_t, D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES> Dx12ShaderIdentifier;

Dx12ShaderIdentifier PackDx12ShaderIdentifier(const uint8_t* shader_id);
void                 UnpackDx12ShaderIdentifier(uint8_t* dest, Dx12ShaderIdentifier src);

class Dx12ShaderIdMap
{
  public:
    void Add(const uint8_t* old_shader_id, const uint8_t* new_shader_id);

    void Remove(const uint8_t* old_shader_id);

    bool Map(uint8_t* translated_shader_id) const;

    bool Map(uint8_t* dst_translated_shader_id, const uint8_t* src_translated_shader_id) const;

  private:
    // Key is old shader id. Value is new.
    typedef std::map<Dx12ShaderIdentifier, Dx12ShaderIdentifier> ShaderIdMap;

  private:
    ShaderIdMap shader_id_map_;
};

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GRAPHICS_SHADER_ID_MAP_H
