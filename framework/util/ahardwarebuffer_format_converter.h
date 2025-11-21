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

#ifndef GFXRECON_AHARDWAREBUFFER_FORMAT_CONVERTER_H
#define GFXRECON_AHARDWAREBUFFER_FORMAT_CONVERTER_H

#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <unordered_map>
#include <unordered_set>

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
#include <android/hardware_buffer.h>
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class AHardwareBufferFormatConverter
{
  public:
    AHardwareBufferFormatConverter();
    AHardwareBufferFormatConverter(VkDevice device);
    ~AHardwareBufferFormatConverter();

    VkResult ConvertImageFormat(VkQueue                                        queue,
                                const VkMemoryAllocateInfo*                    pAllocateInfo,
                                void*                                          pDesc,
                                VkImage                                        extImage,
                                VkDeviceMemory                                 extMemory,
                                VkImage                                        rgbImage,
                                VkDeviceMemory*                                rgbMemory,
                                VkImportAndroidHardwareBufferInfoANDROID*      import_ahb_info,
                                VkAndroidHardwareBufferFormatPropertiesANDROID properties);

    void DestroyFormatConverterObjects();

    bool ConvertCreateImage(const VkImageCreateInfo* pCreateInfo);

    void DestroyImage(VkImage image, const VkAllocationCallbacks* pAllocator);

    void AddImage(VkImage capture_image, VkImage rgb_image);

    void ConvertCreateImageView(const VkImageViewCreateInfo* pCreateInfo);

    VkResult AllocateMemory(const VkMemoryAllocateInfo*                     pAllocateInfo,
                            VkDeviceMemory*                                 pMemory,
                            VkQueue                                         queue,
                            VkMemoryAllocateInfo*                           pAllocateInfo_unwrapped,
                            const VkImportAndroidHardwareBufferInfoANDROID* import_ahb_info,
                            VkAndroidHardwareBufferFormatPropertiesANDROID  properties,
                            VkDeviceMemory&                                 rgb_memory,
                            VkDeviceSize&                                   allocation_size);

    void PostProcess_AllocateMemory(VkDeviceMemory*                                 pMemory,
                                    const VkMemoryAllocateInfo*                     pAllocateInfo,
                                    const VkImportAndroidHardwareBufferInfoANDROID* import_ahb_info,
                                    VkAndroidHardwareBufferFormatPropertiesANDROID  properties,
                                    VkDeviceMemory&                                 rgb_memory,
                                    VkDeviceSize                                    allocation_size);

    void FreeMemory(VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator);

    void ConvertCreateSampler(const VkSamplerCreateInfo* pCreateInfo);

  private:
    bool isValid(VkDevice device);

    struct VertexFormat
    {
        float position[2];
        float texcoord[2];
    };
    typedef std::unordered_map<VkImage, VkImage>               ExternalFormatToRGBImageMap;
    typedef std::unordered_map<VkDeviceMemory, VkDeviceMemory> ExternalFormatToRGBDeviceMemoryMap;

    ExternalFormatToRGBImageMap        ext_to_rgb_images_;
    ExternalFormatToRGBDeviceMemoryMap ext_to_rgb_image_device_memory_;

    VkDevice                 device_                 = VK_NULL_HANDLE;
    VkSamplerYcbcrConversion sampler_conversion_     = VK_NULL_HANDLE;
    VkSampler                ext_image_sampler_      = VK_NULL_HANDLE;
    VkBuffer                 vertex_buffer_          = VK_NULL_HANDLE;
    VkDeviceMemory           vertex_memory_          = VK_NULL_HANDLE;
    VkShaderModule           vertex_shader_module_   = VK_NULL_HANDLE;
    VkShaderModule           fragment_shader_module_ = VK_NULL_HANDLE;
    VkRenderPass             render_pass_            = VK_NULL_HANDLE;
    VkDescriptorPool         descriptor_pool_        = VK_NULL_HANDLE;
    VkCommandPool            command_pool_           = VK_NULL_HANDLE;
    VkCommandBuffer          command_buffer_         = VK_NULL_HANDLE;
    VkDescriptorSetLayout    descriptor_set_layout_  = VK_NULL_HANDLE;
    VkDescriptorSet          descriptor_set_         = VK_NULL_HANDLE;
    VkPipelineLayout         pipeline_layout_        = VK_NULL_HANDLE;
    VkPipeline               pipeline_               = VK_NULL_HANDLE;

    bool is_created_ = false;

    void*            external_format_hardware_buffer = nullptr;
    AHardwareBuffer* rgb_hardware_buffer             = nullptr;
};

bool isStandardAndroidBufferFormat(uint32_t format);

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_AHARDWAREBUFFER_FORMAT_CONVERTER_H