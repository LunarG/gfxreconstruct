/*
** Copyright (c) 2020 Samsung
** Copyright (c) 2023 Google
** Copyright (c) 2023 LunarG, Inc
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

#ifndef GFXRECON_DECODE_VULKAN_CPP_CONSUMER_BASE_H
#define GFXRECON_DECODE_VULKAN_CPP_CONSUMER_BASE_H

#include "vulkan_cpp_utilities.h"
#include "decode/file_processor.h"
#include "decode/vulkan_cpp_loader_generator.h"
#include "decode/vulkan_cpp_utilities.h"
#include "format/platform_types.h"
#include "generated/generated_vulkan_consumer.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <cstdio>
#include <map>
#include <string>
#include <sstream>
#include <type_traits>
#include <unordered_set>
#include <queue>

#include "decode/vulkan_cpp_util_datapack.h"
#include "vulkan_cpp_resource_tracker.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct DescriptorUpdateTemplateEntries
{
    std::vector<VkDescriptorUpdateTemplateEntry> data;
    std::vector<VkDescriptorUpdateTemplateEntry> images;
    std::vector<VkDescriptorUpdateTemplateEntry> buffers;
    std::vector<VkDescriptorUpdateTemplateEntry> texels;
};

class VulkanCppConsumerBase : public VulkanConsumer
{
  public:
    VulkanCppConsumerBase();

    virtual ~VulkanCppConsumerBase() override;

    bool Initialize(const std::string& filename, const std::string& platform, const std::string& outputDir);

    void Destroy();

    void GenerateLoadData(const std::string& filename,
                          uint64_t           fileOffset,
                          const std::string& dataPtrVarName,
                          uint64_t           offset,
                          uint64_t           size);

    bool IsValid() const { return (m_main_file != nullptr); }

    const std::string& GetFilename() const { return m_filename; }

    GfxTocppPlatform GetPlatform() { return m_platform; }

    uint32_t GetProperWindowWidth(uint32_t width) { return std::min(width, m_windowWidth); };
    uint32_t GetProperWindowHeight(uint32_t height) { return std::min(height, m_windowHeight); };

    const std::string GetHandle(const format::HandleId& handleId)
    {
        return m_handleIdMap.count(handleId) ? m_handleIdMap[handleId] : "VK_NULL_HANDLE";
    }

    const std::string GetNextImage(const format::HandleId& swapchain)
    {
        if (m_nextImageMap.count(swapchain))
        {
            std::string nextImage = m_nextImageMap[swapchain].front();
            m_nextImageMap[swapchain].pop();
            return nextImage;
        }

        return "NULL";
    }

    const std::string& GetResourceMemoryRequirements(format::HandleId memoryHandleId)
    {
        std::queue<std::pair<format::HandleId, VkDeviceSize>>& resourceHandles = m_memoryResourceMap[memoryHandleId];
        format::HandleId                                       resourceHandle  = resourceHandles.front().first;
        resourceHandles.pop();

        return m_resourceMemoryReqMap[resourceHandle];
    }

    std::string AddStruct(const std::stringstream& content, const std::string& varnamePrefix);
    std::string
         AddMemoryFilePath(const std::string& fileName, const std::string& outDir, const uint8_t* data, uint64_t size);
    void AddResourceTracker(VulkanCppResourceTracker& resourceTracker) { m_resourceTracker = &resourceTracker; }
    void AddKnownVariables(const std::string& type, const std::string& name);
    void AddKnownVariables(const std::string& type, const std::string& name, uint32_t count);
    void AddKnownVariables(const std::string& type, const std::string& name, const format::HandleId* handleId);
    void AddKnownVariables(const std::string&      type,
                           const std::string&      name,
                           const format::HandleId* handleId,
                           uint32_t                count);
    void SetMemoryResourceMap(
        const std::map<format::HandleId, std::queue<std::pair<format::HandleId, VkDeviceSize>>> memoryImageMap);
    void SetWindowSize(uint32_t appWindowWidth, uint32_t appWindowHeight);
    void SetMaxCommandLimit(uint32_t max) { m_max_command_limit = max; }

    uint32_t getNextId();
    uint32_t getNextId(VkObjectType object_type);

    uint32_t GetCurrentApiCallNumber() { return m_apiCallNumber; }

    void Generate_vkEnumeratePhysicalDevices(VkResult                                returnValue,
                                             format::HandleId                        instance,
                                             PointerDecoder<uint32_t>*               pPhysicalDeviceCount,
                                             HandlePointerDecoder<VkPhysicalDevice>* pPhysicalDevices);

    void Generate_vkGetSwapchainImagesKHR(VkResult                       returnValue,
                                          format::HandleId               device,
                                          format::HandleId               swapchain,
                                          PointerDecoder<uint32_t>*      pSwapchainImageCount,
                                          HandlePointerDecoder<VkImage>* pSwapchainImages);

    void
    Generate_vkGetPhysicalDeviceSurfaceFormatsKHR(VkResult                                          returnValue,
                                                  format::HandleId                                  physicalDevice,
                                                  format::HandleId                                  surface,
                                                  PointerDecoder<uint32_t>*                         pSurfaceFormatCount,
                                                  StructPointerDecoder<Decoded_VkSurfaceFormatKHR>* pSurfaceFormats);

    void Generate_vkGetPhysicalDeviceSurfacePresentModesKHR(VkResult                          returnValue,
                                                            format::HandleId                  physicalDevice,
                                                            format::HandleId                  surface,
                                                            PointerDecoder<uint32_t>*         pPresentModeCount,
                                                            PointerDecoder<VkPresentModeKHR>* pPresentModes);

    void Generate_vkGetPhysicalDeviceQueueFamilyProperties(
        format::HandleId                                       physicalDevice,
        PointerDecoder<uint32_t>*                              pQueueFamilyPropertyCount,
        StructPointerDecoder<Decoded_VkQueueFamilyProperties>* pQueueFamilyProperties);

    void Generate_vkGetImageMemoryRequirements(format::HandleId                                    device,
                                               format::HandleId                                    image,
                                               StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements);

    void
    Generate_vkGetBufferMemoryRequirements(format::HandleId                                    device,
                                           format::HandleId                                    buffer,
                                           StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements);

    void Generate_vkGetImageSparseMemoryRequirements(
        format::HandleId                                               device,
        format::HandleId                                               image,
        PointerDecoder<uint32_t>*                                      pSparseMemoryRequirementCount,
        StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements>* pSparseMemoryRequirements);

    void
         Generate_vkGetImageMemoryRequirements2KHR(format::HandleId                                              device,
                                                   StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
                                                   StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements);
    void Post_vkGetImageMemoryRequirements2KHR(format::HandleId                                              device,
                                               StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
                                               StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements,
                                               const std::string&                                   deviceName,
                                               const std::string&                                   pInfoName,
                                               const std::string& pMemoryRequirementsName);

    void Generate_vkGetBufferMemoryRequirements2KHR(
        format::HandleId                                               device,
        StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2>*           pMemoryRequirements);
    void
    Post_vkGetBufferMemoryRequirements2KHR(format::HandleId                                               device,
                                           StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
                                           StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements,
                                           const std::string&                                   deviceName,
                                           const std::string&                                   pInfoName,
                                           const std::string& pMemoryRequirementsName);

    void Generate_vkGetFenceStatus(VkResult returnValue, format::HandleId device, format::HandleId fence);

    void Generate_vkMapMemory(VkResult                         returnValue,
                              format::HandleId                 device,
                              format::HandleId                 memory,
                              VkDeviceSize                     offset,
                              VkDeviceSize                     size,
                              VkMemoryMapFlags                 flags,
                              PointerDecoder<uint64_t, void*>* ppData);

    void Generate_vkUnmapMemory(format::HandleId device, format::HandleId memory);

    void Generate_vkAllocateMemory(VkResult                                             returnValue,
                                   format::HandleId                                     device,
                                   StructPointerDecoder<Decoded_VkMemoryAllocateInfo>*  pAllocateInfo,
                                   StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                   HandlePointerDecoder<VkDeviceMemory>*                pMemory);

    void Generate_vkCreateInstance(VkResult                                             returnValue,
                                   StructPointerDecoder<Decoded_VkInstanceCreateInfo>*  pCreateInfo,
                                   StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                   HandlePointerDecoder<VkInstance>*                    pInstance);

    void Generate_vkCreateShaderModule(VkResult                                                returnValue,
                                       format::HandleId                                        device,
                                       StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
                                       StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
                                       HandlePointerDecoder<VkShaderModule>*                   pShaderModule);

    void Generate_vkCreatePipelineCache(VkResult                                                 returnValue,
                                        format::HandleId                                         device,
                                        StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>* pCreateInfo,
                                        StructPointerDecoder<Decoded_VkAllocationCallbacks>*     pAllocator,
                                        HandlePointerDecoder<VkPipelineCache>*                   pPipelineCache);

    void GenerateSurfaceCreation(GfxTocppPlatform        platform,
                                 VkResult                returnValue,
                                 format::HandleId        instance,
                                 void*                   pSurfaceCreateInfo,
                                 const format::HandleId* surface);

    void Generate_vkCreateXcbSurfaceKHR(VkResult                                                 returnValue,
                                        format::HandleId                                         instance,
                                        StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo,
                                        StructPointerDecoder<Decoded_VkAllocationCallbacks>*     pAllocator,
                                        HandlePointerDecoder<VkSurfaceKHR>*                      pSurface);

    void Generate_vkCreateWaylandSurfaceKHR(VkResult                                                     returnValue,
                                            format::HandleId                                             instance,
                                            StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo,
                                            StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
                                            HandlePointerDecoder<VkSurfaceKHR>*                          pSurface);

    void Generate_vkCreateAndroidSurfaceKHR(VkResult                                                     returnValue,
                                            format::HandleId                                             instance,
                                            StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo,
                                            StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
                                            HandlePointerDecoder<VkSurfaceKHR>*                          pSurface);

    void Generate_vkAcquireNextImageKHR(VkResult                  returnValue,
                                        format::HandleId          device,
                                        format::HandleId          swapchain,
                                        uint64_t                  timeout,
                                        format::HandleId          semaphore,
                                        format::HandleId          fence,
                                        PointerDecoder<uint32_t>* pImageIndex);

    void Generate_vkAcquireNextImage2KHR(VkResult                                                 returnValue,
                                         format::HandleId                                         device,
                                         StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo,
                                         PointerDecoder<uint32_t>*                                pImageIndex);

    void Generate_vkWaitForFences(VkResult                       returnValue,
                                  format::HandleId               device,
                                  uint32_t                       fenceCount,
                                  HandlePointerDecoder<VkFence>* pFences,
                                  VkBool32                       waitAll,
                                  uint64_t                       timeout);

    void Generate_vkGetQueryPoolResults(VkResult                 returnValue,
                                        format::HandleId         device,
                                        format::HandleId         queryPool,
                                        uint32_t                 firstQuery,
                                        uint32_t                 queryCount,
                                        size_t                   dataSize,
                                        PointerDecoder<uint8_t>* pData,
                                        VkDeviceSize             stride,
                                        VkQueryResultFlags       flags);

    void Generate_vkSetDebugUtilsObjectNameEXT(VkResult                                                     returnValue,
                                               format::HandleId                                             device,
                                               StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>* pNameInfo);
    void Generate_vkSetDebugUtilsObjectTagEXT(VkResult                                                    returnValue,
                                              format::HandleId                                            device,
                                              StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT>* pTagInfo);
    void
         Generate_vkDebugMarkerSetObjectNameEXT(VkResult                                                      returnValue,
                                                format::HandleId                                              device,
                                                StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT>* pNameInfo);
    void Generate_vkDebugMarkerSetObjectTagEXT(VkResult                                                     returnValue,
                                               format::HandleId                                             device,
                                               StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT>* pTagInfo);

    void Generate_vkCreateDescriptorUpdateTemplate(
        VkResult                                                            returnValue,
        format::HandleId                                                    device,
        StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>*                pAllocator,
        HandlePointerDecoder<VkDescriptorUpdateTemplate>*                   pDescriptorUpdateTemplate);

    void Generate_vkCreateDescriptorUpdateTemplateKHR(
        VkResult                                                            returnValue,
        format::HandleId                                                    device,
        StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>*                pAllocator,
        HandlePointerDecoder<VkDescriptorUpdateTemplate>*                   pDescriptorUpdateTemplate)
    {
        Generate_vkCreateDescriptorUpdateTemplate(
            returnValue, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    }

    void Generate_vkUpdateDescriptorSetWithTemplate(format::HandleId                 device,
                                                    format::HandleId                 descriptorSet,
                                                    format::HandleId                 descriptorUpdateTemplate,
                                                    DescriptorUpdateTemplateDecoder* pData);

    void Generate_vkUpdateDescriptorSetWithTemplateKHR(format::HandleId                 device,
                                                       format::HandleId                 descriptorSet,
                                                       format::HandleId                 descriptorUpdateTemplate,
                                                       DescriptorUpdateTemplateDecoder* pData)
    {
        Generate_vkUpdateDescriptorSetWithTemplate(device, descriptorSet, descriptorUpdateTemplate, pData);
    }

    virtual void
    ProcessSetDeviceMemoryPropertiesCommand(format::HandleId                             physical_device_id,
                                            const std::vector<format::DeviceMemoryType>& memory_types,
                                            const std::vector<format::DeviceMemoryHeap>& memory_heaps) override;
    virtual void
    ProcessFillMemoryCommand(uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data) override;

    virtual void ProcessResizeWindowCommand(format::HandleId surface_id, uint32_t width, uint32_t height) override;

    virtual void ProcessResizeWindowCommand2(format::HandleId surface_id,
                                             uint32_t         width,
                                             uint32_t         height,
                                             uint32_t         pre_transform) override;

    void Intercept_vkCreateDevice(VkResult                                             returnValue,
                                  format::HandleId                                     physicalDevice,
                                  StructPointerDecoder<Decoded_VkDeviceCreateInfo>*    pCreateInfo,
                                  StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                  HandlePointerDecoder<VkDevice>*                      pDevice);

    void Intercept_vkCreateSwapchainKHR(VkResult                                                returnValue,
                                        format::HandleId                                        device,
                                        StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
                                        StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
                                        HandlePointerDecoder<VkSwapchainKHR>*                   pSwapchain);

    void Intercept_vkCreateFramebuffer(VkResult                                               returnValue,
                                       format::HandleId                                       device,
                                       StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* pCreateInfo,
                                       StructPointerDecoder<Decoded_VkAllocationCallbacks>*   pAllocator,
                                       HandlePointerDecoder<VkFramebuffer>*                   pFramebuffer);

    void Intercept_vkCmdBeginRenderPass(format::HandleId                                     commandBuffer,
                                        StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
                                        VkSubpassContents                                    contents);

    static std::string toEscape(const char* value);
    static std::string escapeStringArray(const char* const* layerNames, const uint32_t stringArrayLength);
    static std::string toEscape(const std::string& value);
    static std::string escapeStringArray(const std::vector<std::string>& strings);

    static std::string BuildValue(const VkClearColorValue color);
    static std::string BuildValue(const VkClearValue clearValue);
    static std::string BuildValue(const VkClearValue* clearValue);
    static std::string BuildValue(const VkClearValue* values, uint32_t count);
    static std::string BuildValue(const VkComponentMapping components);
    static std::string BuildValue(const VkOffset2D offSet2D);
    static std::string BuildValue(const VkOffset3D offSet3D);
    static std::string BuildValue(const VkOffset3D* values, uint32_t count);
    static std::string BuildValue(const VkExtent2D extent2D);
    static std::string BuildValue(const VkRect2D rect2D);
    static std::string BuildValue(const VkRect2D* rect2D);
    static std::string BuildValue(const VkRect2D* values, uint32_t count);
    static std::string BuildValue(const VkExtent3D extent3D);
    static std::string BuildValue(const VkImageSubresourceRange subresourceRange);
    static std::string BuildValue(const VkImageSubresourceLayers subresourceLayer);
    static std::string BuildValue(const VkStencilOpState stencilOpSate);
    static std::string BuildValue(const VkQueueGlobalPriorityKHR value);
    static std::string BuildValue(const VkQueueGlobalPriorityKHR* values, uint32_t count);
    static std::string BuildValue(const VkFragmentShadingRateCombinerOpKHR value);
    static std::string BuildValue(const VkFragmentShadingRateCombinerOpKHR* values, uint32_t count);
    static std::string BuildValue(const VkPipelineExecutableStatisticValueKHR& value);

    template <typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
    static std::string BuildValue(const T* values, uint32_t count)
    {
        std::stringstream output;
        output << "{";
        for (uint32_t idx = 0; idx < count; idx++)
        {
            output << std::to_string(values[idx]) << ", ";
        }
        output << "}";
        return output.str();
    }

    template <typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
    static std::string BuildValue(const T* values, uint32_t count1, uint32_t count2)
    {
        std::stringstream output;
        output << "{";
        for (uint32_t idx1 = 0; idx1 < count1; idx1++)
        {
            output << "{";
            for (uint32_t idx2 = 0; idx2 < count2; idx2++)
            {
                output << std::to_string(values[(idx1 * count2) + idx2]) << ", ";
            }
            output << "}";
        }
        output << "}";
        return output.str();
    }

    void SetNeedsDebugUtilsCallback(bool value) { m_needsDebugUtilCallback = value; }

  protected:
    FILE* GetFrameFile();
    FILE* GetHeaderFile() const { return m_header_file; };
    FILE* GetGlobalFile() const { return m_global_file; };

    std::string GenFrameName(uint32_t frameNumber, uint32_t frameSplitNumber, uint32_t fillLength);

    void NewFrameFile(uint32_t frameNumber, uint32_t frameSplitNumber);
    void EndFrameFile(uint32_t frameNumber, uint32_t frameSplitNumber);
    void NextFrame(bool isSplit);

    void Post_APICall(format::ApiCallId callId);

    std::unordered_map<VkObjectType, uint32_t>                  m_counters;
    VulkanCppResourceTracker*                                   m_resourceTracker;
    VulkanCppLoaderGenerator                                    m_pfnLoader;
    std::map<format::HandleId, std::string>                     m_handleIdMap;
    std::vector<std::string>                                    m_func_data;
    std::map<uint64_t, std::string>                             m_memoryIdMap;
    std::map<format::HandleId, std::queue<std::string>>         m_nextImageMap;
    std::map<void*, std::string>                                m_ptrMap;
    std::map<uint64_t, std::string>                             m_structMap; // hash -> name
    uint32_t                                                    m_windowWidth;
    uint32_t                                                    m_windowHeight;
    uint32_t                                                    m_max_command_limit{ 1000 };
    std::vector<GfxToCppVariable>                               m_var_data;
    std::map<format::HandleId, DescriptorUpdateTemplateEntries> m_descriptorUpdateTemplateEntryMap;

    std::map<format::HandleId, std::queue<std::pair<format::HandleId, VkDeviceSize>>> m_memoryResourceMap;
    std::map<format::HandleId, std::string>                                           m_resourceMemoryReqMap;

    void AddHandles(const std::string& outputName, const format::HandleId* ptrs, uint32_t count);
    void AddHandles(const std::string& outputName, const format::HandleId* ptrs);

    void AddDescriptorUpdateTemplateEntry(format::HandleId                templateHandleId,
                                          VkDescriptorUpdateTemplateEntry templateEntry);

    bool m_needsDebugUtilCallback = false;

  private:
    struct FrameTempMemory
    {
        std::string name;
        size_t      size;
    };
    std::vector<FrameTempMemory> m_frameSplitTempMemory;

    uint32_t m_frameNumber;
    uint32_t m_frameSplitNumber;
    uint32_t m_frameApiCallNumber;
    uint32_t m_apiCallNumber;
    FILE*    m_frameFile;

    FILE*            m_global_file;
    FILE*            m_header_file;
    FILE*            m_main_file;
    std::string      m_filename;
    GfxTocppPlatform m_platform;
    std::string      m_outDir;
    std::string      m_binOutDir;
    std::string      m_spvOutDir;
    std::string      m_srcOutDir;

    DataFilePacker m_dataPacker;
    DataFilePacker m_spvSaver;
    bool           createSubOutputDirectories(const std::vector<std::string>& subDirs);

    std::vector<std::vector<format::DeviceMemoryType>> m_original_memory_types;
    std::vector<std::vector<format::DeviceMemoryHeap>> m_original_memory_heaps;

    void WriteMainHeader();
    void WriteMainFooter();
    void WriteGlobalHeaderFile();
    void PrintOutGlobalVar();
    void PrintOutCMakeFile();
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_CPP_CONSUMER_BASE_H
