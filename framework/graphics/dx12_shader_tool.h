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

#ifndef GFXRECON_GRAPHICS_DX12_SHADER_TOOL_H
#define GFXRECON_GRAPHICS_DX12_SHADER_TOOL_H

#include "util/defines.h"

#include <cstddef>
#include <cstdint>
#include <functional>
#include <memory>
#include <string>

#include <d3d12.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

class Dx12ShaderTool
{
  public:
    enum class ShaderType
    {
        kVertex,
        kDomain,
        kHull,
        kGeometry,
        kPixel,
        kCompute,
        kAmplification,
        kMesh,
        // StateObject subobject type D3D12_STATE_SUBOBJECT_TYPE_DXIL_LIBRARY
        kStateObjectDxilLibrary,
        kUnknown
    };

    struct PipelineStateShader
    {
        ShaderType             type;
        const char*            extension;
        D3D12_SHADER_BYTECODE* bytecode;
    };

    using PipelineStateShaderCallback    = std::function<void(const PipelineStateShader&)>;
    using PipelineStateCachedPsoCallback = std::function<void(D3D12_CACHED_PIPELINE_STATE&)>;

    // File naming convention matches tools/extract and replay --replace-shaders logic.
    // Pipeline stage shaders:
    //   sh<handle_id>.{v/p/d/h/g/c/a/m}so
    // StateObject DXIL libraries:
    //   sh<handle_id>_<subobject_index>.dxil
    static std::string MakePipelineShaderFileName(uint64_t handle_id, ShaderType type);

    static std::string MakeStateObjectDxilLibraryFileName(uint64_t handle_id, uint32_t subobject_index);

    static bool ForEachPipelineStateStreamShader(D3D12_PIPELINE_STATE_STREAM_DESC&     desc,
                                                 const PipelineStateShaderCallback&    shader_callback,
                                                 const PipelineStateCachedPsoCallback& cached_pso_callback = {});

    // Replacement helpers (read shader bytecode from replace_shader_dir)
    static bool LoadReplacementShaderFromDir(const std::string&       replace_shader_dir,
                                             const std::string&       file_name,
                                             std::unique_ptr<char[]>& out_code,
                                             size_t&                  out_size);

    static bool LoadReplacementPipelineShaderFromDir(const std::string&       replace_shader_dir,
                                                     uint64_t                 handle_id,
                                                     ShaderType               type,
                                                     std::unique_ptr<char[]>& out_code,
                                                     size_t&                  out_size);

    static bool LoadReplacementStateObjectDxilLibraryFromDir(const std::string&       replace_shader_dir,
                                                             uint64_t                 handle_id,
                                                             uint32_t                 subobject_index,
                                                             std::unique_ptr<char[]>& out_code,
                                                             size_t&                  out_size);
};

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GRAPHICS_DX12_SHADER_TOOL_H
