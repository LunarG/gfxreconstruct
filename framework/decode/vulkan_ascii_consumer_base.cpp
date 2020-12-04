/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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
