/*
** Copyright (c) 2020-2026 LunarG, Inc.
** Copyright (c) 2022-2024 Advanced Micro Devices, Inc. All rights reserved.
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

#if defined(D3D12_SUPPORT)

#include "extract_feature.h"

#include "decode/dx12_detection_consumer.h"
#include "generated/generated_dx12_consumer.h"
#include "generated/generated_dx12_decoder.h"
#include "util/feature_module_registry.h"
#include "util/file_path.h"
#include "util/logging.h"
#include "util/platform.h"

#include <d3d12.h>

#include <memory>
#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(extract)

class Dx12ExtractConsumer : public decode::Dx12Consumer
{
  public:
    Dx12ExtractConsumer(const std::string& extract_dir) : extract_dir_(extract_dir) {}

    virtual void Process_ID3D12Device_CreateGraphicsPipelineState(
        const decode::ApiCallInfo&                                                        call_info,
        format::HandleId                                                                  object_id,
        HRESULT                                                                           return_value,
        decode::StructPointerDecoder<decode::Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC>* pDesc,
        decode::Decoded_GUID                                                              riid,
        decode::HandlePointerDecoder<void*>*                                              ppPipelineState) override
    {
        if ((return_value == S_OK) && (pDesc != nullptr) && !pDesc->IsNull() && (ppPipelineState != nullptr) &&
            !ppPipelineState->IsNull())
        {
            uint64_t handle_id = *ppPipelineState->GetPointer();

            WriteShaderBytecode(pDesc->GetPointer()->VS, handle_id, ".vso");
            WriteShaderBytecode(pDesc->GetPointer()->PS, handle_id, ".pso");
            WriteShaderBytecode(pDesc->GetPointer()->DS, handle_id, ".dso");
            WriteShaderBytecode(pDesc->GetPointer()->HS, handle_id, ".hso");
            WriteShaderBytecode(pDesc->GetPointer()->GS, handle_id, ".gso");
        }
    }

    virtual void Process_ID3D12Device_CreateComputePipelineState(
        const decode::ApiCallInfo&                                                       call_info,
        format::HandleId                                                                 object_id,
        HRESULT                                                                          return_value,
        decode::StructPointerDecoder<decode::Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC>* pDesc,
        decode::Decoded_GUID                                                             riid,
        decode::HandlePointerDecoder<void*>*                                             ppPipelineState) override
    {
        if ((return_value == S_OK) && (pDesc != nullptr) && !pDesc->IsNull() && (ppPipelineState != nullptr) &&
            !ppPipelineState->IsNull())
        {
            uint64_t handle_id = *ppPipelineState->GetPointer();
            WriteShaderBytecode(pDesc->GetPointer()->CS, handle_id, ".cso");
        }
    }

    virtual void Process_ID3D12Device5_CreateStateObject(
        const decode::ApiCallInfo&                                             call_info,
        format::HandleId                                                       object_id,
        HRESULT                                                                return_value,
        decode::StructPointerDecoder<decode::Decoded_D3D12_STATE_OBJECT_DESC>* pDesc,
        decode::Decoded_GUID                                                   riid,
        decode::HandlePointerDecoder<void*>*                                   ppStateObject) override
    {
        WriteDxilSubobjects(return_value, pDesc, ppStateObject);
    }

    virtual void Process_ID3D12Device7_AddToStateObject(
        const decode::ApiCallInfo&                                             call_info,
        format::HandleId                                                       object_id,
        HRESULT                                                                return_value,
        decode::StructPointerDecoder<decode::Decoded_D3D12_STATE_OBJECT_DESC>* pAddition,
        format::HandleId                                                       pStateObjectToGrowFrom,
        decode::Decoded_GUID                                                   riid,
        decode::HandlePointerDecoder<void*>*                                   ppNewStateObject) override
    {
        WriteDxilSubobjects(return_value, pAddition, ppNewStateObject);
    }

  private:
    void WriteShaderBytecode(const D3D12_SHADER_BYTECODE& bytecode, uint64_t handle_id, const char* extension)
    {
        if ((bytecode.BytecodeLength > 0) && (bytecode.pShaderBytecode != nullptr))
        {
            std::string file_name = "sh" + std::to_string(handle_id) + extension;
            std::string file_path = util::filepath::Join(extract_dir_, file_name);

            FILE*   fp     = nullptr;
            int32_t result = util::platform::FileOpen(&fp, file_path.c_str(), "wb");
            if (result == 0)
            {
                if (!util::platform::FileWrite(bytecode.pShaderBytecode, bytecode.BytecodeLength, fp))
                {
                    GFXRECON_WRITE_CONSOLE("Error while writing file %s: Could not complete", file_name.c_str());
                }
                util::platform::FileClose(fp);
            }
            else
            {
                GFXRECON_WRITE_CONSOLE("Error while writing file %s: Could not open", file_name.c_str());
            }
        }
    }

    void WriteDxilSubobjects(HRESULT                                                                return_value,
                             decode::StructPointerDecoder<decode::Decoded_D3D12_STATE_OBJECT_DESC>* pDesc,
                             decode::HandlePointerDecoder<void*>*                                   ppStateObject)
    {
        if ((return_value == S_OK) && (pDesc != nullptr) && !pDesc->IsNull() && (ppStateObject != nullptr) &&
            !ppStateObject->IsNull())
        {
            uint64_t handle_id  = *ppStateObject->GetPointer();
            auto&    subobjects = pDesc->GetPointer()->pSubobjects;

            for (uint32_t i = 0; i < pDesc->GetPointer()->NumSubobjects; i++)
            {
                if ((subobjects[i].pDesc == nullptr) || (subobjects[i].Type != D3D12_STATE_SUBOBJECT_TYPE_DXIL_LIBRARY))
                {
                    continue;
                }

                auto& dxil_lib = reinterpret_cast<const D3D12_DXIL_LIBRARY_DESC*>(subobjects[i].pDesc)->DXILLibrary;

                std::string file_name = "sh" + std::to_string(handle_id) + "_" + std::to_string(i) + ".dxil";
                std::string file_path = util::filepath::Join(extract_dir_, file_name);

                FILE*   fp     = nullptr;
                int32_t result = util::platform::FileOpen(&fp, file_path.c_str(), "wb");
                if (result == 0)
                {
                    if (!util::platform::FileWrite(dxil_lib.pShaderBytecode, dxil_lib.BytecodeLength, fp))
                    {
                        GFXRECON_WRITE_CONSOLE("Error while writing file %s: Could not complete", file_name.c_str());
                    }
                    util::platform::FileClose(fp);
                }
                else
                {
                    GFXRECON_WRITE_CONSOLE("Error while writing file %s: Could not open", file_name.c_str());
                }
            }
        }
    }

    std::string extract_dir_;
};

class Dx12ExtractFeature : public ExtractFeatureBase
{
  public:
    Dx12ExtractFeature() : detect_consumer_(decode::Dx12DetectionConsumer::kNoBlockLimit) {}

    std::string Label() const override { return "D3D12"; }

    void Initialize(decode::FileProcessor& file_processor, const std::string& extract_dir) override
    {
        extract_consumer_ = std::make_unique<Dx12ExtractConsumer>(extract_dir);
        decoder_.AddConsumer(&detect_consumer_);
        decoder_.AddConsumer(extract_consumer_.get());
        file_processor.AddDecoder(&decoder_);
    }

    bool WasDetected() const override { return detect_consumer_.WasD3D12APIDetected(); }

  private:
    decode::Dx12DetectionConsumer        detect_consumer_;
    decode::Dx12Decoder                  decoder_;
    std::unique_ptr<Dx12ExtractConsumer> extract_consumer_;
};

GFXR_UTIL_REGISTER_FEATURE_CREATOR(ExtractFeatureBase, Dx12ExtractFeature)

GFXRECON_END_NAMESPACE(extract)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // D3D12_SUPPORT
