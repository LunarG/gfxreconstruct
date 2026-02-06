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

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

const char* Dx12ShaderTool::ShaderTypeToString(ShaderType type)
{
    switch (type)
    {
        case ShaderType::kVertex:
            return "vertex";
        case ShaderType::kDomain:
            return "domain";
        case ShaderType::kHull:
            return "hull";
        case ShaderType::kGeometry:
            return "geometry";
        case ShaderType::kPixel:
            return "pixel";
        case ShaderType::kCompute:
            return "compute";
        case ShaderType::kStateObjectDxilLibrary:
            return "dxil_library";
        default:
            return "unknown";
    }
}

std::string Dx12ShaderTool::MakePipelineShaderFileName(uint64_t handle_id, ShaderType type)
{
    std::string suffix;
    switch (type)
    {
        case ShaderType::kVertex:
            suffix = ".vs.cso";
            break;
        case ShaderType::kPixel:
            suffix = ".ps.cso";
            break;
        case ShaderType::kDomain:
            suffix = ".ds.cso";
            break;
        case ShaderType::kHull:
            suffix = ".hs.cso";
            break;
        case ShaderType::kGeometry:
            suffix = ".gs.cso";
            break;
        case ShaderType::kCompute:
            suffix = ".cs.cso";
            break;
        default:
            suffix = ".cso";
            break;
    }

    return "sh" + std::to_string(handle_id) + suffix;
}

std::string Dx12ShaderTool::MakeStateObjectDxilLibraryFileName(uint64_t handle_id, uint32_t subobject_index)
{
    return "sh" + std::to_string(handle_id) + "_" + std::to_string(subobject_index) + ".cso";
}

bool Dx12ShaderTool::ExtractShaderToDir(const std::string& extract_dir,
                                        const std::string& file_name,
                                        const void*        code,
                                        size_t             code_size)
{
    if ((code == nullptr) || (code_size == 0))
    {
        return false;
    }

    std::string file_path = util::filepath::Join(extract_dir, file_name);

    FILE* fp     = nullptr;
    auto  result = util::platform::FileOpen(&fp, file_path.c_str(), "wb");
    if ((result == 0) && (fp != nullptr))
    {
        if (!util::platform::FileWrite(code, code_size, fp))
        {
            GFXRECON_WRITE_CONSOLE("Error while writing file %s: Could not complete", file_name.c_str());
            util::platform::FileClose(fp);
            return false;
        }
        util::platform::FileClose(fp);
        return true;
    }

    GFXRECON_WRITE_CONSOLE("Error while writing file %s: Could not open", file_name.c_str());
    return false;
}

bool Dx12ShaderTool::ExtractPipelineShaderToDir(
    const std::string& extract_dir, uint64_t handle_id, ShaderType type, const void* code, size_t code_size)
{
    return ExtractShaderToDir(extract_dir, MakePipelineShaderFileName(handle_id, type), code, code_size);
}

bool Dx12ShaderTool::ExtractStateObjectDxilLibraryToDir(const std::string& extract_dir,
                                                        uint64_t           state_object_handle_id,
                                                        uint32_t           subobject_index,
                                                        const void*        code,
                                                        size_t             code_size)
{
    return ExtractShaderToDir(
        extract_dir, MakeStateObjectDxilLibraryFileName(state_object_handle_id, subobject_index), code, code_size);
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
        return false;
    }

    util::platform::FileSeek(fp, 0L, util::platform::FileSeekEnd);
    size_t file_size = static_cast<size_t>(util::platform::FileTell(fp));
    util::platform::FileSeek(fp, 0L, util::platform::FileSeekSet);
    if (file_size == 0)
    {
        util::platform::FileClose(fp);
        return false;
    }

    auto buffer = std::make_unique<char[]>(file_size);
    util::platform::FileRead(buffer.get(), file_size, fp);
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