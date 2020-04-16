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

#include "decode/vulkan_ascii_consumer_base.h"

#include "util/platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanAsciiConsumerBase::VulkanAsciiConsumerBase() : m_file(nullptr) {}

VulkanAsciiConsumerBase::~VulkanAsciiConsumerBase()
{
    Destroy();
}

bool VulkanAsciiConsumerBase::Initialize(const std::string& filename)
{
    bool success = false;

    if (m_file == nullptr)
    {
        int32_t result = util::platform::FileOpen(&m_file, filename.c_str(), "w");
        if (result == 0)
        {
            success    = true;
            m_filename = filename;
        }
    }

    return success;
}

void VulkanAsciiConsumerBase::Destroy()
{
    if (m_file != nullptr)
    {
        util::platform::FileClose(m_file);
    }
}

void VulkanAsciiConsumerBase::Process_vkUpdateDescriptorSetWithTemplate(format::HandleId device,
                                                                        format::HandleId descriptorSet,
                                                                        format::HandleId descriptorUpdateTemplate,
                                                                        DescriptorUpdateTemplateDecoder* pData)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(descriptorSet);
    GFXRECON_UNREFERENCED_PARAMETER(descriptorUpdateTemplate);
    GFXRECON_UNREFERENCED_PARAMETER(pData);
    fprintf(m_file, "%s\n", "vkUpdateDescriptorSetWithTemplate");
}

void VulkanAsciiConsumerBase::Process_vkCmdPushDescriptorSetWithTemplateKHR(format::HandleId commandBuffer,
                                                                            format::HandleId descriptorUpdateTemplate,
                                                                            format::HandleId layout,
                                                                            uint32_t         set,
                                                                            DescriptorUpdateTemplateDecoder* pData)
{
    GFXRECON_UNREFERENCED_PARAMETER(commandBuffer);
    GFXRECON_UNREFERENCED_PARAMETER(descriptorUpdateTemplate);
    GFXRECON_UNREFERENCED_PARAMETER(layout);
    GFXRECON_UNREFERENCED_PARAMETER(set);
    GFXRECON_UNREFERENCED_PARAMETER(pData);
    fprintf(m_file, "%s\n", "vkCmdPushDescriptorSetWithTemplateKHR");
}

void VulkanAsciiConsumerBase::Process_vkUpdateDescriptorSetWithTemplateKHR(format::HandleId device,
                                                                           format::HandleId descriptorSet,
                                                                           format::HandleId descriptorUpdateTemplate,
                                                                           DescriptorUpdateTemplateDecoder* pData)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(descriptorSet);
    GFXRECON_UNREFERENCED_PARAMETER(descriptorUpdateTemplate);
    GFXRECON_UNREFERENCED_PARAMETER(pData);
    fprintf(m_file, "%s\n", "vkUpdateDescriptorSetWithTemplateKHR");
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
