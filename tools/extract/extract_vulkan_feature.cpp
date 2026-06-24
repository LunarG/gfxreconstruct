/*
** Copyright (c) 2020-2026 LunarG, Inc.
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

#include "extract_feature.h"

#include "decode/vulkan_detection_consumer.h"
#include "generated/generated_vulkan_consumer.h"
#include "generated/generated_vulkan_decoder.h"
#include "util/feature_module_registry.h"
#include "util/file_path.h"
#include "util/logging.h"
#include "util/platform.h"

#include "vulkan/vulkan.h"

#include <memory>
#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(extract)

class VulkanExtractConsumer : public decode::VulkanConsumer
{
  public:
    VulkanExtractConsumer(const std::string& extract_dir) : extract_dir_(extract_dir) {}

    virtual void
    Process_vkCreateShaderModule(const decode::ApiCallInfo&                                              call_info,
                                 VkResult                                                                returnValue,
                                 format::HandleId                                                        shaderModule,
                                 decode::StructPointerDecoder<decode::Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
                                 decode::StructPointerDecoder<decode::Decoded_VkAllocationCallbacks>*,
                                 decode::HandlePointerDecoder<VkShaderModule>* pShaderModule) override
    {
        if ((returnValue >= 0) && (pCreateInfo != nullptr) && !pCreateInfo->IsNull() && (pShaderModule != nullptr) &&
            !pShaderModule->IsNull())
        {
            const uint32_t* orig_code = pCreateInfo->GetPointer()->pCode;
            size_t          orig_size = pCreateInfo->GetPointer()->codeSize;
            uint64_t        handle_id = *pShaderModule->GetPointer();
            std::string     file_name = "sh" + std::to_string(handle_id);
            std::string     file_path = util::filepath::Join(extract_dir_, file_name);

            FILE*   fp     = nullptr;
            int32_t result = util::platform::FileOpen(&fp, file_path.c_str(), "wb");
            if (result == 0)
            {
                if (!util::platform::FileWrite(orig_code, orig_size, fp))
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

    virtual void
    Process_vkCreateShadersEXT(const decode::ApiCallInfo&                                           call_info,
                               VkResult                                                             returnValue,
                               format::HandleId                                                     device,
                               uint32_t                                                             createInfoCount,
                               decode::StructPointerDecoder<decode::Decoded_VkShaderCreateInfoEXT>* pCreateInfos,
                               decode::StructPointerDecoder<decode::Decoded_VkAllocationCallbacks>* pAllocator,
                               decode::HandlePointerDecoder<VkShaderEXT>*                           pShaders) override
    {
        if ((returnValue >= 0) && (pCreateInfos != nullptr) && !pCreateInfos->IsNull() && (pShaders != nullptr) &&
            !pShaders->IsNull())
        {
            for (size_t i = 0; i < createInfoCount; i++)
            {
                const void* orig_code = pCreateInfos->GetPointer()[i].pCode;
                size_t      orig_size = pCreateInfos->GetPointer()[i].codeSize;
                uint64_t    handle_id = pShaders->GetPointer()[i];
                std::string file_name = "sh" + std::to_string(handle_id);
                std::string file_path = util::filepath::Join(extract_dir_, file_name);

                FILE*   fp     = nullptr;
                int32_t result = util::platform::FileOpen(&fp, file_path.c_str(), "wb");
                if (result == 0)
                {
                    if (!util::platform::FileWrite(orig_code, orig_size, fp))
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

    virtual void Process_vkCreateGraphicsPipelines(
        const decode::ApiCallInfo&                                                  call_info,
        VkResult                                                                    returnValue,
        format::HandleId                                                            device,
        format::HandleId                                                            pipelineCache,
        uint32_t                                                                    createInfoCount,
        decode::StructPointerDecoder<decode::Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos,
        decode::StructPointerDecoder<decode::Decoded_VkAllocationCallbacks>*        pAllocator,
        decode::HandlePointerDecoder<VkPipeline>*                                   pPipelines) override
    {
        if ((returnValue >= 0) && (pCreateInfos != nullptr) && !pCreateInfos->IsNull())
        {
            for (size_t create_info_index = 0; create_info_index < createInfoCount; create_info_index++)
            {
                auto& pipeline_create_info = pCreateInfos->GetPointer()[create_info_index];
                for (size_t stage_index = 0; stage_index < pipeline_create_info.stageCount; stage_index++)
                {
                    auto& stage_create_info = pipeline_create_info.pStages[stage_index];
                    if (stage_create_info.module != VK_NULL_HANDLE)
                    {
                        continue;
                    }

                    const void* pNext = stage_create_info.pNext;
                    while (pNext != nullptr)
                    {
                        auto* base = reinterpret_cast<const VkBaseInStructure*>(pNext);
                        if (base->sType == VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO)
                        {
                            auto*       create_info = reinterpret_cast<const VkShaderModuleCreateInfo*>(base);
                            const void* orig_code   = create_info->pCode;
                            size_t      orig_size   = create_info->codeSize;
                            uint64_t    handle_id   = pPipelines->GetPointer()[create_info_index];
                            std::string file_name =
                                "sh" + std::to_string(handle_id) + "_" + std::to_string(stage_create_info.stage);
                            std::string file_path = util::filepath::Join(extract_dir_, file_name);

                            FILE*   fp     = nullptr;
                            int32_t result = util::platform::FileOpen(&fp, file_path.c_str(), "wb");
                            if (result == 0)
                            {
                                if (!util::platform::FileWrite(orig_code, orig_size, fp))
                                {
                                    GFXRECON_WRITE_CONSOLE("Error while writing file %s: Could not complete",
                                                           file_name.c_str());
                                }
                                util::platform::FileClose(fp);
                            }
                            else
                            {
                                GFXRECON_WRITE_CONSOLE("Error while writing file %s: Could not open",
                                                       file_name.c_str());
                            }
                        }
                        pNext = base->pNext;
                    }
                }
            }
        }
    }

  private:
    std::string extract_dir_;
};

class VulkanExtractFeature : public ExtractFeatureBase
{
  public:
    VulkanExtractFeature() : detect_consumer_(decode::VulkanDetectionConsumer::kNoBlockLimit) {}

    void Initialize(decode::FileProcessor& file_processor, const std::string& extract_dir) override
    {
        extract_consumer_ = std::make_unique<VulkanExtractConsumer>(extract_dir);
        decoder_.AddConsumer(&detect_consumer_);
        decoder_.AddConsumer(extract_consumer_.get());
        file_processor.AddDecoder(&decoder_);
    }

    bool WasDetected() const override { return detect_consumer_.WasVulkanAPIDetected(); }

  private:
    decode::VulkanDetectionConsumer        detect_consumer_;
    decode::VulkanDecoder                  decoder_;
    std::unique_ptr<VulkanExtractConsumer> extract_consumer_;
};

GFXR_UTIL_REGISTER_FEATURE_CREATOR(ExtractFeatureBase, VulkanExtractFeature)

GFXRECON_END_NAMESPACE(extract)
GFXRECON_END_NAMESPACE(gfxrecon)
