/*
** Copyright (c) 2018 LunarG, Inc.
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

#include "util/platform.h"
#include "format/vulkan_ascii_consumer.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

VulkanAsciiConsumer::VulkanAsciiConsumer() :
    m_file(nullptr)
{
}

VulkanAsciiConsumer::~VulkanAsciiConsumer()
{
    Destroy();
}

bool VulkanAsciiConsumer::Initialize(const std::string& filename)
{
    bool success = false;

    if (m_file == nullptr)
    {
        int32_t result = util::platform::FileOpen(&m_file, filename.c_str(), "w");
        if (result == 0)
        {
            success = true;
            m_filename = filename;
        }
    }

    return success;
}

void VulkanAsciiConsumer::Destroy()
{
    if (m_file != nullptr)
    {
        util::platform::FileClose(m_file);
    }
}

void VulkanAsciiConsumer::Process_vkUpdateDescriptorSetWithTemplate(HandleId device,
                                                                    HandleId descriptorSet,
                                                                    HandleId descriptorUpdateTemplate,
                                                                    const DescriptorUpdateTemplateDecoder& pData)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(device);
    BRIMSTONE_UNREFERENCED_PARAMETER(descriptorSet);
    BRIMSTONE_UNREFERENCED_PARAMETER(descriptorUpdateTemplate);
    BRIMSTONE_UNREFERENCED_PARAMETER(pData);
    fprintf(m_file, "%s\n", "vkUpdateDescriptorSetWithTemplate");
}

void VulkanAsciiConsumer::Process_vkCmdPushDescriptorSetWithTemplateKHR(HandleId commandBuffer,
                                                                        HandleId descriptorUpdateTemplate,
                                                                        HandleId layout,
                                                                        uint32_t set,
                                                                        const DescriptorUpdateTemplateDecoder& pData)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(commandBuffer);
    BRIMSTONE_UNREFERENCED_PARAMETER(descriptorUpdateTemplate);
    BRIMSTONE_UNREFERENCED_PARAMETER(layout);
    BRIMSTONE_UNREFERENCED_PARAMETER(set);
    BRIMSTONE_UNREFERENCED_PARAMETER(pData);
    fprintf(m_file, "%s\n", "vkCmdPushDescriptorSetWithTemplateKHR");
}

void VulkanAsciiConsumer::Process_vkUpdateDescriptorSetWithTemplateKHR(HandleId device,
                                                                       HandleId descriptorSet,
                                                                       HandleId descriptorUpdateTemplate,
                                                                       const DescriptorUpdateTemplateDecoder& pData)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(device);
    BRIMSTONE_UNREFERENCED_PARAMETER(descriptorSet);
    BRIMSTONE_UNREFERENCED_PARAMETER(descriptorUpdateTemplate);
    BRIMSTONE_UNREFERENCED_PARAMETER(pData);
    fprintf(m_file, "%s\n", "vkUpdateDescriptorSetWithTemplateKHR");
}

#include "generated/generated_api_call_ascii_consumer_definitions.inc"

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)
