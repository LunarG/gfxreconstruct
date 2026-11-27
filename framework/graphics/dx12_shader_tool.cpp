/*
** Copyright (c) 2025 LunarG, Inc.
** Copyright (c) 2025-2026 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#include "graphics/dx12_shader_tool.h"

#include "util/file_path.h"
#include "util/logging.h"
#include "util/platform.h"

#include <cstring>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

namespace
{
struct PipelineShaderInfo
{
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE subobject_type;
    Dx12ShaderTool::ShaderType          shader_type;
    const char*                         extension;
};

constexpr PipelineShaderInfo kPipelineShaderInfos[] = {
    { D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_VS, Dx12ShaderTool::ShaderType::kVertex, ".vso" },
    { D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_PS, Dx12ShaderTool::ShaderType::kPixel, ".pso" },
    { D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DS, Dx12ShaderTool::ShaderType::kDomain, ".dso" },
    { D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_HS, Dx12ShaderTool::ShaderType::kHull, ".hso" },
    { D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_GS, Dx12ShaderTool::ShaderType::kGeometry, ".gso" },
    { D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_CS, Dx12ShaderTool::ShaderType::kCompute, ".cso" },
    { D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_AS, Dx12ShaderTool::ShaderType::kAmplification, ".aso" },
    { D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_MS, Dx12ShaderTool::ShaderType::kMesh, ".mso" },
};

const PipelineShaderInfo* GetPipelineShaderInfo(D3D12_PIPELINE_STATE_SUBOBJECT_TYPE subobject_type)
{
    for (const auto& shader_info : kPipelineShaderInfos)
    {
        if (shader_info.subobject_type == subobject_type)
        {
            return &shader_info;
        }
    }

    return nullptr;
}

const PipelineShaderInfo* GetPipelineShaderInfo(Dx12ShaderTool::ShaderType shader_type)
{
    for (const auto& shader_info : kPipelineShaderInfos)
    {
        if (shader_info.shader_type == shader_type)
        {
            return &shader_info;
        }
    }

    return nullptr;
}

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4324)
#endif
template <typename T>
struct alignas(void*) PipelineStateSubobject
{
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE type;
    T                                   value;
};
#ifdef _MSC_VER
#pragma warning(pop)
#endif

size_t GetPipelineStateSubobjectSize(D3D12_PIPELINE_STATE_SUBOBJECT_TYPE type)
{
    switch (type)
    {
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_ROOT_SIGNATURE:
            return sizeof(PipelineStateSubobject<ID3D12RootSignature*>);
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_VS:
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_PS:
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DS:
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_HS:
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_GS:
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_CS:
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_AS:
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_MS:
            return sizeof(PipelineStateSubobject<D3D12_SHADER_BYTECODE>);
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_STREAM_OUTPUT:
            return sizeof(PipelineStateSubobject<D3D12_STREAM_OUTPUT_DESC>);
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_BLEND:
            return sizeof(PipelineStateSubobject<D3D12_BLEND_DESC>);
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_SAMPLE_MASK:
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_NODE_MASK:
            return sizeof(PipelineStateSubobject<UINT>);
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_RASTERIZER:
            return sizeof(PipelineStateSubobject<D3D12_RASTERIZER_DESC>);
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL:
            return sizeof(PipelineStateSubobject<D3D12_DEPTH_STENCIL_DESC>);
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_INPUT_LAYOUT:
            return sizeof(PipelineStateSubobject<D3D12_INPUT_LAYOUT_DESC>);
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_IB_STRIP_CUT_VALUE:
            return sizeof(PipelineStateSubobject<D3D12_INDEX_BUFFER_STRIP_CUT_VALUE>);
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_PRIMITIVE_TOPOLOGY:
            return sizeof(PipelineStateSubobject<D3D12_PRIMITIVE_TOPOLOGY_TYPE>);
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_RENDER_TARGET_FORMATS:
            return sizeof(PipelineStateSubobject<D3D12_RT_FORMAT_ARRAY>);
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL_FORMAT:
            return sizeof(PipelineStateSubobject<DXGI_FORMAT>);
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_SAMPLE_DESC:
            return sizeof(PipelineStateSubobject<DXGI_SAMPLE_DESC>);
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_CACHED_PSO:
            return sizeof(PipelineStateSubobject<D3D12_CACHED_PIPELINE_STATE>);
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_FLAGS:
            return sizeof(PipelineStateSubobject<D3D12_PIPELINE_STATE_FLAGS>);
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL1:
            return sizeof(PipelineStateSubobject<D3D12_DEPTH_STENCIL_DESC1>);
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_VIEW_INSTANCING:
            return sizeof(PipelineStateSubobject<D3D12_VIEW_INSTANCING_DESC>);
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_RASTERIZER1:
            return sizeof(PipelineStateSubobject<D3D12_RASTERIZER_DESC1>);
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_RASTERIZER2:
            return sizeof(PipelineStateSubobject<D3D12_RASTERIZER_DESC2>);
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL2:
            return sizeof(PipelineStateSubobject<D3D12_DEPTH_STENCIL_DESC2>);
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_SERIALIZED_ROOT_SIGNATURE:
            return sizeof(PipelineStateSubobject<D3D12_SERIALIZED_ROOT_SIGNATURE_DESC>);
        default:
            return 0;
    }
}
} // namespace

std::string Dx12ShaderTool::MakePipelineShaderFileName(uint64_t handle_id, ShaderType type)
{
    const auto* shader_info = GetPipelineShaderInfo(type);
    const char* extension   = (shader_info != nullptr) ? shader_info->extension : ".cso";

    return "sh" + std::to_string(handle_id) + extension;
}

std::string Dx12ShaderTool::MakeStateObjectDxilLibraryFileName(uint64_t handle_id, uint32_t subobject_index)
{
    return "sh" + std::to_string(handle_id) + "_" + std::to_string(subobject_index) + ".dxil";
}

bool Dx12ShaderTool::ForEachPipelineStateStreamShader(D3D12_PIPELINE_STATE_STREAM_DESC&     desc,
                                                      const PipelineStateShaderCallback&    shader_callback,
                                                      const PipelineStateCachedPsoCallback& cached_pso_callback)
{
    if (desc.SizeInBytes == 0)
    {
        return true;
    }

    if (desc.pPipelineStateSubobjectStream == nullptr)
    {
        return false;
    }

    auto*        stream      = static_cast<uint8_t*>(desc.pPipelineStateSubobjectStream);
    const size_t stream_size = static_cast<size_t>(desc.SizeInBytes);
    size_t       offset      = 0;

    while (offset < stream_size)
    {
        if ((stream_size - offset) < sizeof(D3D12_PIPELINE_STATE_SUBOBJECT_TYPE))
        {
            return false;
        }

        auto* current = stream + offset;

        D3D12_PIPELINE_STATE_SUBOBJECT_TYPE type{};
        std::memcpy(&type, current, sizeof(type));

        const size_t subobject_size = GetPipelineStateSubobjectSize(type);
        if ((subobject_size == 0) || (subobject_size > (stream_size - offset)))
        {
            return false;
        }

        const auto* shader_info = GetPipelineShaderInfo(type);
        if ((shader_info != nullptr) && shader_callback)
        {
            auto* bytecode = reinterpret_cast<D3D12_SHADER_BYTECODE*>(
                current + offsetof(PipelineStateSubobject<D3D12_SHADER_BYTECODE>, value));
            shader_callback({ shader_info->shader_type, shader_info->extension, bytecode });
        }
        else if ((type == D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_CACHED_PSO) && cached_pso_callback)
        {
            auto* cached_pso = reinterpret_cast<D3D12_CACHED_PIPELINE_STATE*>(
                current + offsetof(PipelineStateSubobject<D3D12_CACHED_PIPELINE_STATE>, value));
            cached_pso_callback(*cached_pso);
        }

        offset += subobject_size;
    }

    return true;
}

bool Dx12ShaderTool::LoadReplacementShaderFromDir(const std::string&       replace_shader_dir,
                                                  const std::string&       file_name,
                                                  std::unique_ptr<char[]>& out_code,
                                                  size_t&                  out_size)
{
    out_code.reset();
    out_size = 0;

    if (replace_shader_dir.empty())
    {
        return false;
    }

    std::string file_path = util::filepath::Join(replace_shader_dir, file_name);
    FILE*       fp        = nullptr;
    int32_t     result    = util::platform::FileOpen(&fp, file_path.c_str(), "rb");
    if ((result != 0) || (fp == nullptr))
    {
        if (util::filepath::Exists(file_path))
        {
            GFXRECON_LOG_WARNING("Failed to open replacement shader: %s", file_path.c_str());
        }
        return false;
    }

    util::platform::FileSeek(fp, 0L, util::platform::FileSeekEnd);
    int64_t tell_size = util::platform::FileTell(fp);
    util::platform::FileSeek(fp, 0L, util::platform::FileSeekSet);
    if (tell_size <= 0)
    {
        util::platform::FileClose(fp);
        GFXRECON_LOG_WARNING("Skipping empty replacement shader: %s", file_path.c_str());
        return false;
    }

    size_t file_size = static_cast<size_t>(tell_size);
    auto   buffer    = std::make_unique<char[]>(file_size);
    if (!util::platform::FileRead(buffer.get(), file_size, fp))
    {
        util::platform::FileClose(fp);
        GFXRECON_LOG_WARNING("Failed to read replacement shader: %s", file_path.c_str());
        return false;
    }
    util::platform::FileClose(fp);

    out_code = std::move(buffer);
    out_size = file_size;
    return true;
}

bool Dx12ShaderTool::LoadReplacementPipelineShaderFromDir(const std::string&       replace_shader_dir,
                                                          uint64_t                 handle_id,
                                                          ShaderType               type,
                                                          std::unique_ptr<char[]>& out_code,
                                                          size_t&                  out_size)
{
    return LoadReplacementShaderFromDir(
        replace_shader_dir, MakePipelineShaderFileName(handle_id, type), out_code, out_size);
}

bool Dx12ShaderTool::LoadReplacementStateObjectDxilLibraryFromDir(const std::string&       replace_shader_dir,
                                                                  uint64_t                 handle_id,
                                                                  uint32_t                 subobject_index,
                                                                  std::unique_ptr<char[]>& out_code,
                                                                  size_t&                  out_size)
{
    return LoadReplacementShaderFromDir(
        replace_shader_dir, MakeStateObjectDxilLibraryFileName(handle_id, subobject_index), out_code, out_size);
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
