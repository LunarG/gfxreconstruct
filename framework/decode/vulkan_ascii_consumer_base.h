/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef GFXRECON_DECODE_VULKAN_ASCII_CONSUMER_BASE_H
#define GFXRECON_DECODE_VULKAN_ASCII_CONSUMER_BASE_H

#include "format/platform_types.h"
#include "generated/generated_vulkan_consumer.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <cstdio>
#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanAsciiConsumerBase : public VulkanConsumer
{
  public:
    VulkanAsciiConsumerBase();

    virtual ~VulkanAsciiConsumerBase() override;

    bool Initialize(const std::string& filename);

    void Destroy();

    bool IsValid() const { return (m_file != nullptr); }

    const std::string& GetFilename() const { return m_filename; }

    virtual void Process_vkUpdateDescriptorSetWithTemplate(format::HandleId                 device,
                                                           format::HandleId                 descriptorSet,
                                                           format::HandleId                 descriptorUpdateTemplate,
                                                           DescriptorUpdateTemplateDecoder* pData) override;

    virtual void Process_vkCmdPushDescriptorSetWithTemplateKHR(format::HandleId commandBuffer,
                                                               format::HandleId descriptorUpdateTemplate,
                                                               format::HandleId layout,
                                                               uint32_t         set,
                                                               DescriptorUpdateTemplateDecoder* pData) override;

    virtual void Process_vkUpdateDescriptorSetWithTemplateKHR(format::HandleId                 device,
                                                              format::HandleId                 descriptorSet,
                                                              format::HandleId                 descriptorUpdateTemplate,
                                                              DescriptorUpdateTemplateDecoder* pData) override;

  protected:
    FILE* GetFile() const { return m_file; }

  private:
    FILE*       m_file;
    std::string m_filename;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_ASCII_CONSUMER_BASE_H
