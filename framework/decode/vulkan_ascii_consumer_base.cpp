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
#include "decode/vulkan_ascii_consumer_base.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(decode)

VulkanAsciiConsumerBase::VulkanAsciiConsumerBase() :
    m_file(nullptr)
{
}

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
            success = true;
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
                                                                        const DescriptorUpdateTemplateDecoder& pData)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(device);
    BRIMSTONE_UNREFERENCED_PARAMETER(descriptorSet);
    BRIMSTONE_UNREFERENCED_PARAMETER(descriptorUpdateTemplate);
    BRIMSTONE_UNREFERENCED_PARAMETER(pData);
    fprintf(m_file, "%s\n", "vkUpdateDescriptorSetWithTemplate");
}

void VulkanAsciiConsumerBase::Process_vkCmdPushDescriptorSetWithTemplateKHR(
    format::HandleId                       commandBuffer,
    format::HandleId                       descriptorUpdateTemplate,
    format::HandleId                       layout,
    uint32_t                               set,
    const DescriptorUpdateTemplateDecoder& pData)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(commandBuffer);
    BRIMSTONE_UNREFERENCED_PARAMETER(descriptorUpdateTemplate);
    BRIMSTONE_UNREFERENCED_PARAMETER(layout);
    BRIMSTONE_UNREFERENCED_PARAMETER(set);
    BRIMSTONE_UNREFERENCED_PARAMETER(pData);
    fprintf(m_file, "%s\n", "vkCmdPushDescriptorSetWithTemplateKHR");
}

void VulkanAsciiConsumerBase::Process_vkUpdateDescriptorSetWithTemplateKHR(format::HandleId device,
                                                                           format::HandleId descriptorSet,
                                                                           format::HandleId descriptorUpdateTemplate,
                                                                           const DescriptorUpdateTemplateDecoder& pData)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(device);
    BRIMSTONE_UNREFERENCED_PARAMETER(descriptorSet);
    BRIMSTONE_UNREFERENCED_PARAMETER(descriptorUpdateTemplate);
    BRIMSTONE_UNREFERENCED_PARAMETER(pData);
    fprintf(m_file, "%s\n", "vkUpdateDescriptorSetWithTemplateKHR");
}

void VulkanAsciiConsumerBase::Process_vkRegisterObjectsNVX(
    VkResult                                                   returnValue,
    format::HandleId                                           device,
    format::HandleId                                           objectTable,
    uint32_t                                                   objectCount,
    const StructPointerDecoder<Decoded_VkObjectTableEntryNVX>& ppObjectTableEntries,
    const PointerDecoder<uint32_t>&                            pObjectIndices)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(returnValue);
    BRIMSTONE_UNREFERENCED_PARAMETER(device);
    BRIMSTONE_UNREFERENCED_PARAMETER(objectTable);
    BRIMSTONE_UNREFERENCED_PARAMETER(objectCount);
    BRIMSTONE_UNREFERENCED_PARAMETER(ppObjectTableEntries);
    BRIMSTONE_UNREFERENCED_PARAMETER(pObjectIndices);
    fprintf(m_file, "%s\n", "vkRegisterObjectsNVX");
}

BRIMSTONE_END_NAMESPACE(decode)
BRIMSTONE_END_NAMESPACE(brimstone)
