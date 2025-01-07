/*
** Copyright (c) 2020 LunarG, Inc.
** Copyright (c) 2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#include "util/ahardwarebuffer_format_converter.h"

#include "encode/vulkan_handle_wrapper_util.h"
#include "graphics/vulkan_struct_get_pnext.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

std::unordered_set<uint32_t> standard_android_buffer_format = {
    0x01, // AHARDWAREBUFFER_FORMAT_R8G8B8A8_UNORM     = VK_FORMAT_R8G8B8A8_UNORM
    0x02, // AHARDWAREBUFFER_FORMAT_R8G8B8X8_UNORM     = VK_FORMAT_R8G8B8A8_UNORM
    0x03, // AHARDWAREBUFFER_FORMAT_R8G8B8_UNORM       = VK_FORMAT_R8G8B8_UNORM
    0x04, // AHARDWAREBUFFER_FORMAT_R5G6B5_UNORM       = VK_FORMAT_R5G6B5_UNORM_PACK16
    0x16, // AHARDWAREBUFFER_FORMAT_R16G16B16A16_FLOAT = VK_FORMAT_R16G16B16A16_SFLOAT
    0x2b, // AHARDWAREBUFFER_FORMAT_R10G10B10A2_UNORM  = VK_FORMAT_A2B10G10R10_UNORM_PACK32
    0x21, // AHARDWAREBUFFER_FORMAT_BLOB
    0x30, // AHARDWAREBUFFER_FORMAT_D16_UNORM          = VK_FORMAT_D16_UNORM
    0x31, // AHARDWAREBUFFER_FORMAT_D24_UNORM          = VK_FORMAT_X8_D24_UNORM_PACK32
    0x32, // AHARDWAREBUFFER_FORMAT_D24_UNORM_S8_UINT  = VK_FORMAT_D24_UNORM_S8_UINT
    0x33, // AHARDWAREBUFFER_FORMAT_D32_FLOAT          = VK_FORMAT_D32_SFLOAT
    0x34, // AHARDWAREBUFFER_FORMAT_D32_FLOAT_S8_UINT  = VK_FORMAT_D32_SFLOAT_S8_UINT
    0x35, // AHARDWAREBUFFER_FORMAT_S8_UINT            = VK_FORMAT_S8_UINT
    0x23, // AHARDWAREBUFFER_FORMAT_Y8Cb8Cr8_420
    0x36, // AHARDWAREBUFFER_FORMAT_YCbCr_P010
    0x38, // AHARDWAREBUFFER_FORMAT_R8_UNORM           = VK_FORMAT_R8_UNORM
    0x39, // AHARDWAREBUFFER_FORMAT_R16_UINT           = VK_FORMAT_R16_UINT
    0x3a, // AHARDWAREBUFFER_FORMAT_R16G16_UINT        = VK_FORMAT_R16G16_UINT;
    0x3b, // AHARDWAREBUFFER_FORMAT_R10G10B10A10_UNORM = VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16
};

bool isStandardAndroidBufferFormat(uint32_t format)
{
    return standard_android_buffer_format.find(format) != standard_android_buffer_format.end();
}

AHardwareBufferFormatConverter::AHardwareBufferFormatConverter() {}

AHardwareBufferFormatConverter::AHardwareBufferFormatConverter(VkDevice device)
{
    device_ = device;
}

AHardwareBufferFormatConverter::~AHardwareBufferFormatConverter() {}

#if 0
#version 450

layout(location = 0) in vec2 inPosition;
layout(location = 0) out vec2 fragTexCoord;
layout(location = 1) in vec2 inTexCoord;

void main()
{
    gl_Position = vec4(inPosition, 0.0, 1.0);
    fragTexCoord = inTexCoord;
}

#endif

static uint32_t vertex_shader[] = {
    119734787,  65536,      851979,     31,         0,          131089,     1,          393227,     1,
    1280527431, 1685353262, 808793134,  0,          196622,     0,          1,          589839,     0,
    4,          1852399981, 0,          13,         18,         28,         29,         196611,     2,
    450,        655364,     1197427783, 1279741775, 1885560645, 1953718128, 1600482425, 1701734764, 1919509599,
    1769235301, 25974,      524292,     1197427783, 1279741775, 1852399429, 1685417059, 1768185701, 1952671090,
    6649449,    262149,     4,          1852399981, 0,          393221,     11,         1348430951, 1700164197,
    2019914866, 0,          393222,     11,         0,          1348430951, 1953067887, 7237481,    458758,
    11,         1,          1348430951, 1953393007, 1702521171, 0,          458758,     11,         2,
    1130327143, 1148217708, 1635021673, 6644590,    458758,     11,         3,          1130327143, 1147956341,
    1635021673, 6644590,    196613,     13,         0,          327685,     18,         1867542121, 1769236851,
    28271,      393221,     28,         1734439526, 1131963732, 1685221231, 0,          327685,     29,
    1700032105, 1869562744, 25714,      327752,     11,         0,          11,         0,          327752,
    11,         1,          11,         1,          327752,     11,         2,          11,         3,
    327752,     11,         3,          11,         4,          196679,     11,         2,          262215,
    18,         30,         0,          262215,     28,         30,         0,          262215,     29,
    30,         1,          131091,     2,          196641,     3,          2,          196630,     6,
    32,         262167,     7,          6,          4,          262165,     8,          32,         0,
    262187,     8,          9,          1,          262172,     10,         6,          9,          393246,
    11,         7,          6,          10,         10,         262176,     12,         3,          11,
    262203,     12,         13,         3,          262165,     14,         32,         1,          262187,
    14,         15,         0,          262167,     16,         6,          2,          262176,     17,
    1,          16,         262203,     17,         18,         1,          262187,     6,          20,
    0,          262187,     6,          21,         1065353216, 262176,     25,         3,          7,
    262176,     27,         3,          16,         262203,     27,         28,         3,          262203,
    17,         29,         1,          327734,     2,          4,          0,          3,          131320,
    5,          262205,     16,         19,         18,         327761,     6,          22,         19,
    0,          327761,     6,          23,         19,         1,          458832,     7,          24,
    22,         23,         20,         21,         327745,     25,         26,         13,         15,
    196670,     26,         24,         262205,     16,         30,         29,         196670,     28,
    30,         65789,      65592
};

#if 0
#version 450

layout(binding = 1) uniform sampler2D texSampler;

layout(location = 0) out vec4 outColor;
layout(location = 0) in vec2 fragTexCoord;

void main()
{
    outColor = texture(texSampler, fragTexCoord);
}

#endif

static uint32_t fragment_shader[] = {
    119734787,  65536,      851979,     20,         0,          131089,     1,          393227,     1,
    1280527431, 1685353262, 808793134,  0,          196622,     0,          1,          458767,     4,
    4,          1852399981, 0,          9,          17,         196624,     4,          7,          196611,
    2,          450,        655364,     1197427783, 1279741775, 1885560645, 1953718128, 1600482425, 1701734764,
    1919509599, 1769235301, 25974,      524292,     1197427783, 1279741775, 1852399429, 1685417059, 1768185701,
    1952671090, 6649449,    262149,     4,          1852399981, 0,          327685,     9,          1131705711,
    1919904879, 0,          327685,     13,         1400399220, 1819307361, 29285,      393221,     17,
    1734439526, 1131963732, 1685221231, 0,          262215,     9,          30,         0,          262215,
    13,         34,         0,          262215,     13,         33,         1,          262215,     17,
    30,         0,          131091,     2,          196641,     3,          2,          196630,     6,
    32,         262167,     7,          6,          4,          262176,     8,          3,          7,
    262203,     8,          9,          3,          589849,     10,         6,          1,          0,
    0,          0,          1,          0,          196635,     11,         10,         262176,     12,
    0,          11,         262203,     12,         13,         0,          262167,     15,         6,
    2,          262176,     16,         1,          15,         262203,     16,         17,         1,
    327734,     2,          4,          0,          3,          131320,     5,          262205,     11,
    14,         13,         262205,     15,         18,         17,         327767,     7,          19,
    14,         18,         196670,     9,          19,         65789,      65592
};

VkResult AHardwareBufferFormatConverter::ConvertImageFormat(VkQueue                                   queue,
                                                            const VkMemoryAllocateInfo*               pAllocateInfo,
                                                            void*                                     pDesc,
                                                            VkImage                                   extImage,
                                                            VkDeviceMemory                            extMemory,
                                                            VkImage                                   rgbImage,
                                                            VkDeviceMemory*                           rgbMemory,
                                                            VkImportAndroidHardwareBufferInfoANDROID* import_ahb_info,
                                                            VkAndroidHardwareBufferFormatPropertiesANDROID properties)
{
    VkResult              result = VK_SUCCESS;
    AHardwareBuffer_Desc* pDesc_ = static_cast<AHardwareBuffer_Desc*>(pDesc);

    if (!is_created_ && import_ahb_info && isValid(device_))
    {
        is_created_ = true;

        // create a Y′CBCR conversion
        if (sampler_conversion_ == VK_NULL_HANDLE)
        {
            VkExternalFormatANDROID external_format_Android = {};
            external_format_Android.sType                   = VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID;
            external_format_Android.externalFormat          = properties.externalFormat;

            VkSamplerYcbcrModelConversion sampler_ycbcr_model_conversion = properties.suggestedYcbcrModel;
            VkSamplerYcbcrRange           sampler_ycbcr_range            = properties.suggestedYcbcrRange;
            VkComponentMapping            compenent_mapping              = properties.samplerYcbcrConversionComponents;
            VkChromaLocation              x_chroma_offset                = properties.suggestedXChromaOffset;
            VkChromaLocation              y_chroma_offset                = properties.suggestedYChromaOffset;

            VkSamplerYcbcrConversionCreateInfo conversion_create_info = {};
            conversion_create_info.sType                       = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO;
            conversion_create_info.pNext                       = &external_format_Android;
            conversion_create_info.ycbcrModel                  = sampler_ycbcr_model_conversion;
            conversion_create_info.ycbcrRange                  = sampler_ycbcr_range;
            conversion_create_info.components.r                = compenent_mapping.r;
            conversion_create_info.components.g                = compenent_mapping.g;
            conversion_create_info.components.b                = compenent_mapping.b;
            conversion_create_info.components.a                = compenent_mapping.a;
            conversion_create_info.xChromaOffset               = x_chroma_offset;
            conversion_create_info.yChromaOffset               = y_chroma_offset;
            conversion_create_info.chromaFilter                = VK_FILTER_NEAREST;
            conversion_create_info.forceExplicitReconstruction = 0;
            result = encode::vulkan_wrappers::GetDeviceTable(device_)->CreateSamplerYcbcrConversion(
                device_, &conversion_create_info, nullptr, &sampler_conversion_);
            if (result != VK_SUCCESS)
            {
                GFXRECON_LOG_ERROR("Failed to create sampler Ycbcr conversion when converting image format!(Returned "
                                   "error value: %ld)",
                                   result);
                return result;
            }
        }
        // create sampler for external format image
        VkSamplerYcbcrConversionInfo sampler_ycbcr_conversion_info = {};
        sampler_ycbcr_conversion_info.sType                        = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO;
        sampler_ycbcr_conversion_info.conversion                   = sampler_conversion_;

        VkSamplerCreateInfo sampler_create_info = {};
        sampler_create_info.sType               = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
        sampler_create_info.pNext               = &sampler_ycbcr_conversion_info;
        sampler_create_info.magFilter = sampler_create_info.minFilter = VK_FILTER_NEAREST;
        sampler_create_info.mipmapMode                                = VK_SAMPLER_MIPMAP_MODE_NEAREST;
        sampler_create_info.addressModeU = sampler_create_info.addressModeV = sampler_create_info.addressModeW =
            VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE;
        sampler_create_info.maxAnisotropy = 1;
        sampler_create_info.borderColor   = VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE;
        result                            = encode::vulkan_wrappers::GetDeviceTable(device_)->CreateSampler(
            device_, &sampler_create_info, nullptr, &ext_image_sampler_);
        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Failed to create sampler when converting image format!(Returned error value: %ld)",
                               result);
            return result;
        }

        VertexFormat vertex[] = { { { -1.0f, -1.0f }, { 0.0f, 0.0f } }, { { 1.0f, -1.0f }, { 1.0f, 0.0f } },
                                  { { 1.0f, 1.0f }, { 1.0f, 1.0f } },   { { -1.0f, -1.0f }, { 0.0f, 0.0f } },
                                  { { 1.0f, 1.0f }, { 1.0f, 1.0f } },   { { -1.0f, 1.0f }, { 0.0f, 1.0f } } };

        // create buffer for vertex
        VkBufferCreateInfo vertex_buffer_create_info = {};
        vertex_buffer_create_info.sType              = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
        vertex_buffer_create_info.size               = sizeof(float) * 24;
        vertex_buffer_create_info.usage = (VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_VERTEX_BUFFER_BIT);
        result                          = encode::vulkan_wrappers::GetDeviceTable(device_)->CreateBuffer(
            device_, &vertex_buffer_create_info, nullptr, &vertex_buffer_);
        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Failed to create buffer when converting image format!(Returned error value: %ld)",
                               result);
            return result;
        }
        // allocate memory for vertex buffer
        VkMemoryAllocateInfo vertex_memory_allocate_info = {};
        vertex_memory_allocate_info.sType                = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
        vertex_memory_allocate_info.allocationSize       = vertex_buffer_create_info.size;
        result = encode::vulkan_wrappers::GetDeviceTable(device_)->AllocateMemory(
            device_, &vertex_memory_allocate_info, nullptr, &vertex_memory_);
        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Failed to allocate memory when converting image format!(Returned error value: %ld)",
                               result);
            return result;
        }
        // copy vertex data to vertex buffer
        void* pData = nullptr;
        encode::vulkan_wrappers::GetDeviceTable(device_)->MapMemory(
            device_, vertex_memory_, 0, vertex_buffer_create_info.size, 0, &pData);

        memcpy(pData, vertex, vertex_buffer_create_info.size);
        VkMappedMemoryRange mapped_memory_range = {};
        mapped_memory_range.sType               = VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE;
        mapped_memory_range.memory              = vertex_memory_;
        mapped_memory_range.offset              = 0;
        mapped_memory_range.size                = vertex_buffer_create_info.size;
        encode::vulkan_wrappers::GetDeviceTable(device_)->FlushMappedMemoryRanges(device_, 1, &mapped_memory_range);

        encode::vulkan_wrappers::GetDeviceTable(device_)->UnmapMemory(device_, vertex_memory_);

        // bind vertex buffer and memory
        encode::vulkan_wrappers::GetDeviceTable(device_)->BindBufferMemory(device_, vertex_buffer_, vertex_memory_, 0);

        // create shader module
        VkShaderModuleCreateInfo vertex_shader_module_create_info = {};
        vertex_shader_module_create_info.sType                    = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        vertex_shader_module_create_info.codeSize                 = sizeof(vertex_shader);
        vertex_shader_module_create_info.pCode                    = reinterpret_cast<const uint32_t*>(vertex_shader);
        encode::vulkan_wrappers::GetDeviceTable(device_)->CreateShaderModule(
            device_, &vertex_shader_module_create_info, nullptr, &vertex_shader_module_);
        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR(
                "Failed to create vertex shader module when converting image format!(Returned error value: %ld)",
                result);
            return result;
        }
        VkShaderModuleCreateInfo fragment_shader_module_create_info = {};
        fragment_shader_module_create_info.sType                    = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        fragment_shader_module_create_info.codeSize                 = sizeof(fragment_shader);
        fragment_shader_module_create_info.pCode = reinterpret_cast<const uint32_t*>(fragment_shader);
        encode::vulkan_wrappers::GetDeviceTable(device_)->CreateShaderModule(
            device_, &fragment_shader_module_create_info, nullptr, &fragment_shader_module_);
        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR(
                "Failed to create fragment shader module when converting image format!(Returned error value: %ld)",
                result);
            return result;
        }

        // create renderpass
        VkAttachmentDescription color_attachment = {};
        color_attachment.format                  = VK_FORMAT_R8G8B8A8_UNORM;
        color_attachment.samples                 = VK_SAMPLE_COUNT_1_BIT;
        color_attachment.loadOp                  = VK_ATTACHMENT_LOAD_OP_CLEAR;
        color_attachment.storeOp                 = VK_ATTACHMENT_STORE_OP_STORE;
        color_attachment.stencilLoadOp           = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
        color_attachment.stencilStoreOp          = VK_ATTACHMENT_STORE_OP_DONT_CARE;
        color_attachment.initialLayout           = VK_IMAGE_LAYOUT_UNDEFINED;
        color_attachment.finalLayout             = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

        VkAttachmentReference color_attachment_reference = {};
        color_attachment_reference.attachment            = 0;
        color_attachment_reference.layout                = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

        VkSubpassDescription subpass = {};
        subpass.pipelineBindPoint    = VK_PIPELINE_BIND_POINT_GRAPHICS;
        subpass.colorAttachmentCount = 1;
        subpass.pColorAttachments    = &color_attachment_reference;

        VkSubpassDependency dependency = {};
        dependency.srcSubpass          = VK_SUBPASS_EXTERNAL;
        dependency.dstSubpass          = 0;
        dependency.srcStageMask        = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
        dependency.srcAccessMask       = 0;
        dependency.dstStageMask        = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
        dependency.dstAccessMask       = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;

        VkRenderPassCreateInfo render_pass_create_info = {};
        render_pass_create_info.sType                  = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
        render_pass_create_info.attachmentCount        = 1;
        render_pass_create_info.pAttachments           = &color_attachment;
        render_pass_create_info.subpassCount           = 1;
        render_pass_create_info.pSubpasses             = &subpass;
        render_pass_create_info.dependencyCount        = 1;
        render_pass_create_info.pDependencies          = &dependency;
        encode::vulkan_wrappers::GetDeviceTable(device_)->CreateRenderPass(
            device_, &render_pass_create_info, nullptr, &render_pass_);
        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Failed to create render pass when converting image format!(Returned error value: %ld)",
                               result);
            return result;
        }

        // create descriptor pool
        VkDescriptorPoolSize descriptor_pool_size[2] = {};
        descriptor_pool_size[0].type                 = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        descriptor_pool_size[0].descriptorCount      = 6;
        descriptor_pool_size[1].type                 = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        descriptor_pool_size[1].descriptorCount      = 6;

        VkDescriptorPoolCreateInfo descriptor_pool_create_info = {};
        descriptor_pool_create_info.sType                      = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
        descriptor_pool_create_info.poolSizeCount              = 2;
        descriptor_pool_create_info.pPoolSizes                 = descriptor_pool_size;
        descriptor_pool_create_info.maxSets                    = 6;
        encode::vulkan_wrappers::GetDeviceTable(device_)->CreateDescriptorPool(
            device_, &descriptor_pool_create_info, nullptr, &descriptor_pool_);
        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR(
                "Failed to create descriptor pool when converting image format!(Returned error value: %ld)", result);
            return result;
        }
        // create descriptor set layout
        VkDescriptorSetLayoutCreateInfo descriptor_set_layout_create_info = {};
        descriptor_set_layout_create_info.sType        = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
        descriptor_set_layout_create_info.bindingCount = 2;

        VkDescriptorSetLayoutBinding bind[2]        = {};
        descriptor_set_layout_create_info.pBindings = bind;
        bind[0].binding                             = 0;
        bind[0].descriptorType                      = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        bind[0].descriptorCount                     = 1;
        bind[0].stageFlags                          = VK_SHADER_STAGE_VERTEX_BIT;
        bind[0].pImmutableSamplers                  = nullptr;
        bind[1].binding                             = 1;
        bind[1].descriptorType                      = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        bind[1].descriptorCount                     = 1;
        bind[1].stageFlags                          = VK_SHADER_STAGE_FRAGMENT_BIT;
        bind[1].pImmutableSamplers                  = &ext_image_sampler_;
        encode::vulkan_wrappers::GetDeviceTable(device_)->CreateDescriptorSetLayout(
            device_, &descriptor_set_layout_create_info, nullptr, &descriptor_set_layout_);
        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR(
                "Failed to create descriptor set layout when converting image format!(Returned error value: %ld)",
                result);
            return result;
        }

        // allocate descriptor set
        VkDescriptorSetAllocateInfo descriptor_set_allocate_info = {};
        descriptor_set_allocate_info.sType                       = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
        descriptor_set_allocate_info.descriptorPool              = descriptor_pool_;
        descriptor_set_allocate_info.descriptorSetCount          = 1;
        descriptor_set_allocate_info.pSetLayouts                 = &descriptor_set_layout_;
        encode::vulkan_wrappers::GetDeviceTable(device_)->AllocateDescriptorSets(
            device_, &descriptor_set_allocate_info, &descriptor_set_);
        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR(
                "Failed to allocate descriptor sets when converting image format!(Returned error value: %ld)", result);
            return result;
        }
        // create pipeline layout
        VkPipelineLayoutCreateInfo pipeline_layout_create_info = {};
        pipeline_layout_create_info.sType                      = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
        pipeline_layout_create_info.setLayoutCount             = 1;
        pipeline_layout_create_info.pSetLayouts                = &descriptor_set_layout_;
        encode::vulkan_wrappers::GetDeviceTable(device_)->CreatePipelineLayout(
            device_, &pipeline_layout_create_info, nullptr, &pipeline_layout_);
        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR(
                "Failed to create pipeline layout when converting image format!(Returned error value: %ld)", result);
            return result;
        }

        // create pipeline
        VkPipelineShaderStageCreateInfo vertex_pipeline_shader_stage_info = {};
        vertex_pipeline_shader_stage_info.sType  = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
        vertex_pipeline_shader_stage_info.stage  = VK_SHADER_STAGE_VERTEX_BIT;
        vertex_pipeline_shader_stage_info.module = vertex_shader_module_;
        vertex_pipeline_shader_stage_info.pName  = "main";

        VkPipelineShaderStageCreateInfo fragment_pipeline_shader_stage_info = {};
        fragment_pipeline_shader_stage_info.sType      = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
        fragment_pipeline_shader_stage_info.stage      = VK_SHADER_STAGE_FRAGMENT_BIT;
        fragment_pipeline_shader_stage_info.module     = fragment_shader_module_;
        fragment_pipeline_shader_stage_info.pName      = "main";
        VkPipelineShaderStageCreateInfo shaderStages[] = { vertex_pipeline_shader_stage_info,
                                                           fragment_pipeline_shader_stage_info };

        VkPipelineVertexInputStateCreateInfo pipeline_vertex_input_stage_create_info = {};
        pipeline_vertex_input_stage_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
        pipeline_vertex_input_stage_create_info.vertexBindingDescriptionCount = 1;

        VkVertexInputBindingDescription vertex_input_binding_description   = {};
        pipeline_vertex_input_stage_create_info.pVertexBindingDescriptions = &vertex_input_binding_description;
        vertex_input_binding_description.binding                           = 0;
        vertex_input_binding_description.stride                            = sizeof(VertexFormat);
        vertex_input_binding_description.inputRate                         = VK_VERTEX_INPUT_RATE_VERTEX;

        pipeline_vertex_input_stage_create_info.vertexAttributeDescriptionCount = 2;
        VkVertexInputAttributeDescription vertex_input_attribute_description[2];
        pipeline_vertex_input_stage_create_info.pVertexAttributeDescriptions = vertex_input_attribute_description;
        vertex_input_attribute_description[0].binding                        = 0;
        vertex_input_attribute_description[0].location                       = 0;
        vertex_input_attribute_description[0].format                         = VK_FORMAT_R32G32_SFLOAT;
        vertex_input_attribute_description[0].offset                         = offsetof(VertexFormat, position);

        vertex_input_attribute_description[1].binding  = 0;
        vertex_input_attribute_description[1].location = 1;
        vertex_input_attribute_description[1].format   = VK_FORMAT_R32G32_SFLOAT;
        vertex_input_attribute_description[1].offset   = offsetof(VertexFormat, texcoord);

        VkPipelineInputAssemblyStateCreateInfo pipeline_input_assembly_state_create_info = {};
        pipeline_input_assembly_state_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
        pipeline_input_assembly_state_create_info.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;

        VkPipelineViewportStateCreateInfo pipeline_viewport_state_create_info = {};
        pipeline_viewport_state_create_info.sType         = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
        pipeline_viewport_state_create_info.viewportCount = 1;
        pipeline_viewport_state_create_info.scissorCount  = 1;
        VkDynamicState                   dynamics[]       = { VK_DYNAMIC_STATE_VIEWPORT, VK_DYNAMIC_STATE_SCISSOR };
        VkPipelineDynamicStateCreateInfo pipeline_dynamic_state_create_info = {};
        pipeline_dynamic_state_create_info.sType             = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
        pipeline_dynamic_state_create_info.pDynamicStates    = dynamics;
        pipeline_dynamic_state_create_info.dynamicStateCount = 2;

        VkPipelineRasterizationStateCreateInfo pipeline_rasterization_state_create_info = {};
        pipeline_rasterization_state_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
        pipeline_rasterization_state_create_info.depthClampEnable        = VK_FALSE;
        pipeline_rasterization_state_create_info.rasterizerDiscardEnable = VK_FALSE;
        pipeline_rasterization_state_create_info.polygonMode             = VK_POLYGON_MODE_FILL;
        pipeline_rasterization_state_create_info.lineWidth               = 1.0f;
        pipeline_rasterization_state_create_info.cullMode                = VK_CULL_MODE_NONE;
        pipeline_rasterization_state_create_info.frontFace               = VK_FRONT_FACE_COUNTER_CLOCKWISE;
        pipeline_rasterization_state_create_info.depthBiasEnable         = VK_FALSE;

        VkPipelineMultisampleStateCreateInfo pipeline_multisample_state_create_info = {};
        pipeline_multisample_state_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
        pipeline_multisample_state_create_info.sampleShadingEnable  = VK_FALSE;
        pipeline_multisample_state_create_info.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
        pipeline_multisample_state_create_info.minSampleShading     = 1;

        VkPipelineColorBlendAttachmentState pipeline_color_blend_attachment_state = {};
        pipeline_color_blend_attachment_state.colorWriteMask =
            VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
        pipeline_color_blend_attachment_state.blendEnable = VK_FALSE;

        VkPipelineColorBlendStateCreateInfo pipeline_color_blend_state_create_info = {};
        pipeline_color_blend_state_create_info.sType         = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
        pipeline_color_blend_state_create_info.logicOpEnable = VK_FALSE;
        pipeline_color_blend_state_create_info.logicOp       = VK_LOGIC_OP_COPY;
        pipeline_color_blend_state_create_info.attachmentCount   = 1;
        pipeline_color_blend_state_create_info.pAttachments      = &pipeline_color_blend_attachment_state;
        pipeline_color_blend_state_create_info.blendConstants[0] = 0.0f;
        pipeline_color_blend_state_create_info.blendConstants[1] = 0.0f;
        pipeline_color_blend_state_create_info.blendConstants[2] = 0.0f;
        pipeline_color_blend_state_create_info.blendConstants[3] = 0.0f;

        VkGraphicsPipelineCreateInfo graphics_pipeline_create_info = {};
        graphics_pipeline_create_info.sType                        = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
        graphics_pipeline_create_info.stageCount                   = 2;
        graphics_pipeline_create_info.pStages                      = shaderStages;
        graphics_pipeline_create_info.pVertexInputState            = &pipeline_vertex_input_stage_create_info;
        graphics_pipeline_create_info.pInputAssemblyState          = &pipeline_input_assembly_state_create_info;
        graphics_pipeline_create_info.pViewportState               = &pipeline_viewport_state_create_info;
        graphics_pipeline_create_info.pRasterizationState          = &pipeline_rasterization_state_create_info;
        graphics_pipeline_create_info.pMultisampleState            = &pipeline_multisample_state_create_info;
        graphics_pipeline_create_info.pColorBlendState             = &pipeline_color_blend_state_create_info;
        graphics_pipeline_create_info.pDynamicState                = &pipeline_dynamic_state_create_info;
        graphics_pipeline_create_info.layout                       = pipeline_layout_;
        graphics_pipeline_create_info.renderPass                   = render_pass_;
        graphics_pipeline_create_info.subpass                      = 0;
        graphics_pipeline_create_info.basePipelineHandle           = VK_NULL_HANDLE;
        graphics_pipeline_create_info.basePipelineIndex            = -1;
        encode::vulkan_wrappers::GetDeviceTable(device_)->CreateGraphicsPipelines(
            device_, VK_NULL_HANDLE, 1, &graphics_pipeline_create_info, nullptr, &pipeline_);
        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR(
                "Failed to create graphics pipeline when converting image format!(Returned error value: %ld)", result);
            return result;
        }

        // create a command pool
        VkCommandPoolCreateInfo command_pool_create_info = {};
        command_pool_create_info.sType                   = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
        command_pool_create_info.flags                   = VK_COMMAND_POOL_CREATE_TRANSIENT_BIT;
        command_pool_create_info.queueFamilyIndex        = 0;
        encode::vulkan_wrappers::GetDeviceTable(device_)->CreateCommandPool(
            device_, &command_pool_create_info, nullptr, &command_pool_);

        // allocate a command buffer from pool
        VkCommandBufferAllocateInfo command_buffer_allocate_info = {};
        command_buffer_allocate_info.sType                       = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        command_buffer_allocate_info.commandPool                 = command_pool_;
        command_buffer_allocate_info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        command_buffer_allocate_info.commandBufferCount          = 1;
        encode::vulkan_wrappers::GetDeviceTable(device_)->AllocateCommandBuffers(
            device_, &command_buffer_allocate_info, &command_buffer_);
        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR(
                "Failed to allocate command buffers when converting image format!(Returned error value: %ld)", result);
            return result;
        }
    }

    // bind the memory and image for external format image
    encode::vulkan_wrappers::GetDeviceTable(device_)->BindImageMemory(device_, extImage, extMemory, 0);

    // allocate hardware buffer for rgba image
    pDesc_->usage = AHARDWAREBUFFER_USAGE_GPU_COLOR_OUTPUT | AHARDWAREBUFFER_USAGE_CPU_WRITE_OFTEN |
                    AHARDWAREBUFFER_USAGE_CPU_READ_MASK;
    pDesc_->format = AHARDWAREBUFFER_FORMAT_R8G8B8A8_UNORM;
    int ret        = AHardwareBuffer_allocate(pDesc_, &(import_ahb_info->buffer));
    if (ret != 0)
    {
        GFXRECON_LOG_ERROR(
            "Failed to allocate Android hardware buffer when converting image format!(Returned error value: %ld)",
            result);
        return VK_ERROR_OUT_OF_DEVICE_MEMORY;
    }

    // get Android hardware buffer properties
    VkAndroidHardwareBufferFormatPropertiesANDROID ahb_format_properties;
    memset(&ahb_format_properties, 0, sizeof(ahb_format_properties));
    ahb_format_properties.sType = VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID;
    VkAndroidHardwareBufferPropertiesANDROID androidHardwareBufferPropertiesANDROID = {
        VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID, &ahb_format_properties, 0, 0
    };
    encode::vulkan_wrappers::GetDeviceTable(device_)->GetAndroidHardwareBufferPropertiesANDROID(
        device_, import_ahb_info->buffer, &androidHardwareBufferPropertiesANDROID);

    // allocate vkmemory for rgba image
    const_cast<VkMemoryAllocateInfo*>(pAllocateInfo)->allocationSize =
        androidHardwareBufferPropertiesANDROID.allocationSize;
    auto memory_dedicated_allocate_info =
        graphics::vulkan_struct_get_pnext<VkMemoryDedicatedAllocateInfo>(pAllocateInfo);
    const_cast<VkMemoryDedicatedAllocateInfo*>(memory_dedicated_allocate_info)->image = rgbImage;
    encode::vulkan_wrappers::GetDeviceTable(device_)->AllocateMemory(device_, pAllocateInfo, nullptr, rgbMemory);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Failed to allocate memory when converting image format!(Returned error value: %ld)",
                           result);
        return result;
    }

    // describe the Android hardware buffer
    AHardwareBuffer_describe(import_ahb_info->buffer, pDesc_);

    // bind the memory and image for rgb image
    encode::vulkan_wrappers::GetDeviceTable(device_)->BindImageMemory(device_, rgbImage, *rgbMemory, 0);

    // create the imageview for external format image
    VkSamplerYcbcrConversionInfo conversion_create_info = {};
    conversion_create_info.sType                        = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO;
    conversion_create_info.conversion                   = sampler_conversion_;

    VkImageViewCreateInfo ext_image_view_create_info           = {};
    ext_image_view_create_info.sType                           = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
    ext_image_view_create_info.pNext                           = &conversion_create_info;
    ext_image_view_create_info.image                           = extImage;
    ext_image_view_create_info.viewType                        = VK_IMAGE_VIEW_TYPE_2D;
    ext_image_view_create_info.format                          = VK_FORMAT_UNDEFINED;
    ext_image_view_create_info.components.r                    = VK_COMPONENT_SWIZZLE_IDENTITY;
    ext_image_view_create_info.components.g                    = VK_COMPONENT_SWIZZLE_IDENTITY;
    ext_image_view_create_info.components.b                    = VK_COMPONENT_SWIZZLE_IDENTITY;
    ext_image_view_create_info.components.a                    = VK_COMPONENT_SWIZZLE_IDENTITY;
    ext_image_view_create_info.subresourceRange.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
    ext_image_view_create_info.subresourceRange.baseMipLevel   = 0;
    ext_image_view_create_info.subresourceRange.levelCount     = 1;
    ext_image_view_create_info.subresourceRange.baseArrayLayer = 0;
    ext_image_view_create_info.subresourceRange.layerCount     = 1;
    VkImageView ext_image_view                                 = VK_NULL_HANDLE;
    encode::vulkan_wrappers::GetDeviceTable(device_)->CreateImageView(
        device_, &ext_image_view_create_info, nullptr, &ext_image_view);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Failed to create image view for external format image when converting image "
                           "format!(Returned error value: %ld)",
                           result);
        return result;
    }

    // create the imageview for rgb image
    VkImageViewCreateInfo rgb_image_view_create_info           = {};
    rgb_image_view_create_info.sType                           = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
    rgb_image_view_create_info.image                           = rgbImage;
    rgb_image_view_create_info.viewType                        = VK_IMAGE_VIEW_TYPE_2D;
    rgb_image_view_create_info.format                          = VK_FORMAT_R8G8B8A8_UNORM;
    rgb_image_view_create_info.components.r                    = VK_COMPONENT_SWIZZLE_IDENTITY;
    rgb_image_view_create_info.components.g                    = VK_COMPONENT_SWIZZLE_IDENTITY;
    rgb_image_view_create_info.components.b                    = VK_COMPONENT_SWIZZLE_IDENTITY;
    rgb_image_view_create_info.components.a                    = VK_COMPONENT_SWIZZLE_IDENTITY;
    rgb_image_view_create_info.subresourceRange.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
    rgb_image_view_create_info.subresourceRange.baseMipLevel   = 0;
    rgb_image_view_create_info.subresourceRange.levelCount     = 1;
    rgb_image_view_create_info.subresourceRange.baseArrayLayer = 0;
    rgb_image_view_create_info.subresourceRange.layerCount     = 1;
    VkImageView rgb_image_view                                 = VK_NULL_HANDLE;
    encode::vulkan_wrappers::GetDeviceTable(device_)->CreateImageView(
        device_, &rgb_image_view_create_info, nullptr, &rgb_image_view);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR(
            "Failed to create image view for rgb image when converting image format!(Returned error value: %ld)",
            result);
        return result;
    }

    // create the framebuffer for rgba image
    VkFramebufferCreateInfo framebuffer_create_info = {};
    framebuffer_create_info.sType                   = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
    framebuffer_create_info.renderPass              = render_pass_;
    framebuffer_create_info.attachmentCount         = 1;
    framebuffer_create_info.pAttachments            = &rgb_image_view;
    framebuffer_create_info.width                   = pDesc_->width;
    framebuffer_create_info.height                  = pDesc_->height;
    framebuffer_create_info.layers                  = 1;
    VkFramebuffer framebuffer                       = VK_NULL_HANDLE;
    encode::vulkan_wrappers::GetDeviceTable(device_)->CreateFramebuffer(
        device_, &framebuffer_create_info, nullptr, &framebuffer);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Failed to create frame buffer when converting image format!(Returned error value: %ld)",
                           result);
        return result;
    }

    // update the descriptor set
    VkDescriptorImageInfo descriptor_image_info = {};
    descriptor_image_info.imageLayout           = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
    descriptor_image_info.imageView             = ext_image_view;
    descriptor_image_info.sampler               = ext_image_sampler_;

    VkWriteDescriptorSet writeDescriptorSet = {};
    writeDescriptorSet.sType                = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
    writeDescriptorSet.dstSet               = descriptor_set_;
    writeDescriptorSet.dstBinding           = 1;
    writeDescriptorSet.dstArrayElement      = 0;
    writeDescriptorSet.descriptorType       = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
    writeDescriptorSet.descriptorCount      = 1;
    writeDescriptorSet.pImageInfo           = &descriptor_image_info;
    encode::vulkan_wrappers::GetDeviceTable(device_)->UpdateDescriptorSets(device_, 1, &writeDescriptorSet, 0, nullptr);

    // begin record command
    VkCommandBufferBeginInfo command_buffer_begin_Info = {};
    command_buffer_begin_Info.sType                    = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    command_buffer_begin_Info.flags                    = VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT;
    encode::vulkan_wrappers::GetDeviceTable(device_)->BeginCommandBuffer(command_buffer_, &command_buffer_begin_Info);

    // bind descriptor sets
    encode::vulkan_wrappers::GetDeviceTable(device_)->CmdBindDescriptorSets(
        command_buffer_, VK_PIPELINE_BIND_POINT_GRAPHICS, pipeline_layout_, 0, 1, &descriptor_set_, 0, nullptr);

    VkRenderPassBeginInfo renderpass_begin_info    = {};
    renderpass_begin_info.sType                    = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
    renderpass_begin_info.renderPass               = render_pass_;
    renderpass_begin_info.framebuffer              = framebuffer;
    renderpass_begin_info.renderArea.offset.x      = 0;
    renderpass_begin_info.renderArea.offset.y      = 0;
    renderpass_begin_info.renderArea.extent.width  = framebuffer_create_info.width;
    renderpass_begin_info.renderArea.extent.height = framebuffer_create_info.height;
    renderpass_begin_info.clearValueCount          = 1;

    VkClearValue clearValue            = {};
    renderpass_begin_info.pClearValues = &clearValue;
    encode::vulkan_wrappers::GetDeviceTable(device_)->CmdBeginRenderPass(
        command_buffer_, &renderpass_begin_info, VK_SUBPASS_CONTENTS_INLINE);

    encode::vulkan_wrappers::GetDeviceTable(device_)->CmdBindPipeline(
        command_buffer_, VK_PIPELINE_BIND_POINT_GRAPHICS, pipeline_);

    VkViewport viewport = { 0.0f, 0.0f, (float)pDesc_->width, (float)pDesc_->height, 0.0f, 1.0f };
    encode::vulkan_wrappers::GetDeviceTable(device_)->CmdSetViewport(command_buffer_, 0, 1, &viewport);

    VkRect2D scissor      = {};
    scissor.extent.width  = pDesc_->width;
    scissor.extent.height = pDesc_->height;
    encode::vulkan_wrappers::GetDeviceTable(device_)->CmdSetScissor(command_buffer_, 0, 1, &scissor);

    VkDeviceSize offset = 0;
    encode::vulkan_wrappers::GetDeviceTable(device_)->CmdBindVertexBuffers(
        command_buffer_, 0, 1, &vertex_buffer_, &offset);
    encode::vulkan_wrappers::GetDeviceTable(device_)->CmdDraw(command_buffer_, 6, 1, 0, 0);
    encode::vulkan_wrappers::GetDeviceTable(device_)->CmdEndRenderPass(command_buffer_);
    encode::vulkan_wrappers::GetDeviceTable(device_)->EndCommandBuffer(command_buffer_);

    VkSubmitInfo submit_info       = {};
    submit_info.sType              = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submit_info.commandBufferCount = 1;
    submit_info.pCommandBuffers    = &command_buffer_;
    VkFence nullFence              = { VK_NULL_HANDLE };
    result = encode::vulkan_wrappers::GetDeviceTable(device_)->QueueSubmit(queue, 1, &submit_info, nullFence);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Failed to submit queue when converting image format!(Returned error value: %ld)", result);
        return result;
    }

    result = encode::vulkan_wrappers::GetDeviceTable(device_)->QueueWaitIdle(queue);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR(
            "Failed to wait for queue to become idle when converting image format!(Returned error value: %ld)", result);
        return result;
    }

    encode::vulkan_wrappers::GetDeviceTable(device_)->DestroyFramebuffer(device_, framebuffer, nullptr);
    encode::vulkan_wrappers::GetDeviceTable(device_)->DestroyImageView(device_, rgb_image_view, nullptr);
    encode::vulkan_wrappers::GetDeviceTable(device_)->DestroyImageView(device_, ext_image_view, nullptr);
    return result;
}

void AHardwareBufferFormatConverter::DestroyFormatConverterObjects()
{
    if (device_ == VK_NULL_HANDLE)
    {
        return;
    }
    if (ext_image_sampler_ != VK_NULL_HANDLE)
    {
        encode::vulkan_wrappers::GetDeviceTable(device_)->DestroySampler(device_, ext_image_sampler_, nullptr);
        ext_image_sampler_ = VK_NULL_HANDLE;
    }
    if (vertex_buffer_ != VK_NULL_HANDLE)
    {
        encode::vulkan_wrappers::GetDeviceTable(device_)->DestroyBuffer(device_, vertex_buffer_, nullptr);
        vertex_buffer_ = VK_NULL_HANDLE;
    }
    if (vertex_memory_ != VK_NULL_HANDLE)
    {
        encode::vulkan_wrappers::GetDeviceTable(device_)->FreeMemory(device_, vertex_memory_, nullptr);
        vertex_memory_ = VK_NULL_HANDLE;
    }
    if (vertex_shader_module_ != VK_NULL_HANDLE)
    {
        encode::vulkan_wrappers::GetDeviceTable(device_)->DestroyShaderModule(device_, vertex_shader_module_, nullptr);
        vertex_shader_module_ = VK_NULL_HANDLE;
    }
    if (fragment_shader_module_ != VK_NULL_HANDLE)
    {
        encode::vulkan_wrappers::GetDeviceTable(device_)->DestroyShaderModule(
            device_, fragment_shader_module_, nullptr);
        fragment_shader_module_ = VK_NULL_HANDLE;
    }
    if (render_pass_ != VK_NULL_HANDLE)
    {
        encode::vulkan_wrappers::GetDeviceTable(device_)->DestroyRenderPass(device_, render_pass_, nullptr);
        render_pass_ = VK_NULL_HANDLE;
    }
    if (descriptor_pool_ != VK_NULL_HANDLE)
    {
        encode::vulkan_wrappers::GetDeviceTable(device_)->DestroyDescriptorPool(device_, descriptor_pool_, nullptr);
        descriptor_pool_ = VK_NULL_HANDLE;
    }
    if (command_pool_ != VK_NULL_HANDLE)
    {
        encode::vulkan_wrappers::GetDeviceTable(device_)->DestroyCommandPool(device_, command_pool_, nullptr);
        command_pool_ = VK_NULL_HANDLE;
    }
    if (descriptor_set_layout_ != VK_NULL_HANDLE)
    {
        encode::vulkan_wrappers::GetDeviceTable(device_)->DestroyDescriptorSetLayout(
            device_, descriptor_set_layout_, nullptr);
        descriptor_set_layout_ = VK_NULL_HANDLE;
    }
    if (pipeline_layout_ != VK_NULL_HANDLE)
    {
        encode::vulkan_wrappers::GetDeviceTable(device_)->DestroyPipelineLayout(device_, pipeline_layout_, nullptr);
        pipeline_layout_ = VK_NULL_HANDLE;
    }
    if (pipeline_ != VK_NULL_HANDLE)
    {
        encode::vulkan_wrappers::GetDeviceTable(device_)->DestroyPipeline(device_, pipeline_, nullptr);
        pipeline_ = VK_NULL_HANDLE;
    }
    if (sampler_conversion_ != VK_NULL_HANDLE)
    {
        encode::vulkan_wrappers::GetDeviceTable(device_)->DestroySamplerYcbcrConversion(
            device_, sampler_conversion_, nullptr);
        sampler_conversion_ = VK_NULL_HANDLE;
    }

    is_created_ = false;
    device_     = VK_NULL_HANDLE;
}

bool AHardwareBufferFormatConverter::ConvertCreateImage(const VkImageCreateInfo* pCreateInfo)
{
    // Change the format and usage of pCreateInfo and externalFormat of VkExternalFormatANDROID in pNext
    if (auto external_memory_image_create_info =
            graphics::vulkan_struct_get_pnext<VkExternalMemoryImageCreateInfo>(pCreateInfo))
    {
        if (external_memory_image_create_info->handleTypes ==
                VK_EXTERNAL_MEMORY_HANDLE_TYPE_ANDROID_HARDWARE_BUFFER_BIT_ANDROID &&
            pCreateInfo->format == VK_FORMAT_UNDEFINED)
        {
            const_cast<VkImageCreateInfo*>(pCreateInfo)->format = VK_FORMAT_R8G8B8A8_UNORM;
            const_cast<VkImageCreateInfo*>(pCreateInfo)->usage =
                pCreateInfo->usage | VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT |
                VK_IMAGE_USAGE_TRANSFER_DST_BIT;

            if (auto external_format = graphics::vulkan_struct_get_pnext<VkExternalFormatANDROID>(pCreateInfo))
            {
                const_cast<VkExternalFormatANDROID*>(external_format)->externalFormat = 0;
            }

            return true;
        }
    }

    return false;
}

void AHardwareBufferFormatConverter::DestroyImage(VkImage capture_image, const VkAllocationCallbacks* pAllocator)
{
    // If the capture image has an exteranl format, return its corresponding rgb format image or return null handle
    auto entry = ext_to_rgb_images_.find(capture_image);
    if (entry != ext_to_rgb_images_.end() && isValid(device_))
    {
        VkImage rgb_image = entry->second;
        encode::vulkan_wrappers::GetDeviceTable(device_)->DestroyImage(device_, rgb_image, pAllocator);
        ext_to_rgb_images_.erase(entry);

        encode::vulkan_wrappers::DestroyWrappedHandle<encode::vulkan_wrappers::ImageWrapper>(rgb_image);
    }
}

void AHardwareBufferFormatConverter::ConvertCreateImageView(const VkImageViewCreateInfo* pCreateInfo)
{
    // Change the format of pCreateInfo and skip VkSamplerYcbcrConversionInfo structure in pNext
    auto entry = ext_to_rgb_images_.find(pCreateInfo->image);
    if (entry != ext_to_rgb_images_.end())
    {
        VkImage rgb_image                                       = entry->second;
        const_cast<VkImageViewCreateInfo*>(pCreateInfo)->format = VK_FORMAT_R8G8B8A8_UNORM;

        VkBaseOutStructure* pnext_chain = (VkBaseOutStructure*)(pCreateInfo);
        while (pnext_chain->pNext != nullptr &&
               pnext_chain->pNext->sType != VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO)
        {
            pnext_chain = pnext_chain->pNext;
        }

        if (pnext_chain->pNext == nullptr)
        {
            pnext_chain = nullptr;
        }
        else
        {
            pnext_chain->pNext = pnext_chain->pNext->pNext;
        }
    }
}

VkResult AHardwareBufferFormatConverter::AllocateMemory(const VkMemoryAllocateInfo* pAllocateInfo,
                                                        VkDeviceMemory*             pMemory,
                                                        VkQueue                     queue,
                                                        VkMemoryAllocateInfo*       pAllocateInfo_unwrapped,
                                                        const VkImportAndroidHardwareBufferInfoANDROID* import_ahb_info,
                                                        VkAndroidHardwareBufferFormatPropertiesANDROID  properties,
                                                        VkDeviceMemory&                                 rgb_memory,
                                                        VkDeviceSize&                                   allocation_size)
{
    if (auto memory_dedicated_allocate_info =
            graphics::vulkan_struct_get_pnext<VkMemoryDedicatedAllocateInfo>(pAllocateInfo_unwrapped))
    {
        external_format_hardware_buffer = nullptr;
        rgb_hardware_buffer             = nullptr;

        VkMemoryAllocateInfo modified_create_info = (*pAllocateInfo_unwrapped);

        auto entry_img = ext_to_rgb_images_.find(memory_dedicated_allocate_info->image);
        if (entry_img != ext_to_rgb_images_.end())
        {
            external_format_hardware_buffer = import_ahb_info->buffer;

            AHardwareBuffer_Desc desc;
            AHardwareBuffer_describe(import_ahb_info->buffer, &desc);

            VkResult result = ConvertImageFormat(queue,
                                                 pAllocateInfo_unwrapped,
                                                 &desc,
                                                 entry_img->first,
                                                 *pMemory,
                                                 entry_img->second,
                                                 &rgb_memory,
                                                 const_cast<VkImportAndroidHardwareBufferInfoANDROID*>(import_ahb_info),
                                                 properties);
            allocation_size = pAllocateInfo_unwrapped->allocationSize;
        }
    }

    return (rgb_memory == VK_NULL_HANDLE) ? VK_ERROR_INITIALIZATION_FAILED : VK_SUCCESS;
}

void AHardwareBufferFormatConverter::PostProcess_AllocateMemory(
    VkDeviceMemory*                                 pMemory,
    const VkMemoryAllocateInfo*                     pAllocateInfo,
    const VkImportAndroidHardwareBufferInfoANDROID* import_ahb_info,
    VkAndroidHardwareBufferFormatPropertiesANDROID  properties,
    VkDeviceMemory&                                 rgb_memory,
    VkDeviceSize                                    allocation_size)
{
    ext_to_rgb_image_device_memory_[*pMemory] = rgb_memory;

    rgb_hardware_buffer = import_ahb_info->buffer;

    // change the pAllocatInfo
    const_cast<VkMemoryAllocateInfo*>(pAllocateInfo)->allocationSize = allocation_size;

    auto orig_import_ahb_info =
        graphics::vulkan_struct_get_pnext<VkImportAndroidHardwareBufferInfoANDROID>(pAllocateInfo);
    const_cast<VkImportAndroidHardwareBufferInfoANDROID*>(orig_import_ahb_info)->buffer = rgb_hardware_buffer;

    if (external_format_hardware_buffer)
    {
        AHardwareBuffer_release(rgb_hardware_buffer);
    }
}

void AHardwareBufferFormatConverter::FreeMemory(VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator)
{
    auto entry = ext_to_rgb_image_device_memory_.find(memory);
    if (entry != ext_to_rgb_image_device_memory_.end() && isValid(device_))
    {
        VkDeviceMemory rgb_memory = entry->second;
        encode::vulkan_wrappers::GetDeviceTable(device_)->FreeMemory(device_, rgb_memory, pAllocator);

        encode::vulkan_wrappers::DestroyWrappedHandle<encode::vulkan_wrappers::DeviceMemoryWrapper>(rgb_memory);
    }
}

void AHardwareBufferFormatConverter::ConvertCreateSampler(const VkSamplerCreateInfo* pCreateInfo)
{
    // Skip VkSamplerYcbcrConversionInfo structure in pNext
    VkBaseOutStructure* pnext_chain = (VkBaseOutStructure*)(pCreateInfo);
    while (pnext_chain->pNext != nullptr &&
           pnext_chain->pNext->sType != VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO)
    {
        pnext_chain = pnext_chain->pNext;
    }

    if (pnext_chain->pNext == nullptr)
    {
        pnext_chain = nullptr;
    }
    else
    {
        pnext_chain->pNext = pnext_chain->pNext->pNext;
    }
}

void AHardwareBufferFormatConverter::AddImage(VkImage capture_image, VkImage rgb_image)
{
    ext_to_rgb_images_[capture_image] = rgb_image;
}

bool AHardwareBufferFormatConverter::isValid(VkDevice device)
{
    return device != VK_NULL_HANDLE;
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)