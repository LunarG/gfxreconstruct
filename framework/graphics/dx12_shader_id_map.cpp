
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

#include "graphics/dx12_shader_id_map.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

Dx12ShaderIdentifier PackDx12ShaderIdentifier(const uint8_t* shader_id)
{
    Dx12ShaderIdentifier shader_identifier;
    util::platform::MemoryCopy(shader_identifier.data(),
                               D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES,
                               shader_id,
                               D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES);
    return shader_identifier;
}

void UnpackDx12ShaderIdentifier(uint8_t* dest, Dx12ShaderIdentifier src)
{
    util::platform::MemoryCopy(
        dest, D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES, src.data(), D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES);
}

void Dx12ShaderIdMap::Add(const uint8_t* old_shader_id, const uint8_t* new_shader_id)
{
    Dx12ShaderIdentifier old_shader_identifier = PackDx12ShaderIdentifier(old_shader_id);
    Dx12ShaderIdentifier new_shader_identifier = PackDx12ShaderIdentifier(new_shader_id);

    shader_id_map_.insert(std::pair<Dx12ShaderIdentifier, Dx12ShaderIdentifier>(std::move(old_shader_identifier),
                                                                                std::move(new_shader_identifier)));
}

void Dx12ShaderIdMap::Remove(const uint8_t* old_shader_id)
{
    Dx12ShaderIdentifier old_shader_identifier = PackDx12ShaderIdentifier(old_shader_id);

    shader_id_map_.erase(old_shader_identifier);
}

bool Dx12ShaderIdMap::Map(uint8_t* translated_shader_id) const
{
    return Dx12ShaderIdMap::Map(translated_shader_id, translated_shader_id);
}

bool Dx12ShaderIdMap::Map(uint8_t* dst_translated_shader_id, const uint8_t* src_translated_shader_id) const
{
    Dx12ShaderIdentifier old_shader_id = PackDx12ShaderIdentifier(src_translated_shader_id);

    auto entry = shader_id_map_.find(old_shader_id);
    if (entry != shader_id_map_.end())
    {
        UnpackDx12ShaderIdentifier(dst_translated_shader_id, entry->second);
        return true;
    }
    return false;
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
