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
    std::vector<VkDescriptorUpdateTemplateEntry> accelerations;
};

class VulkanCppConsumerBase : public VulkanConsumer
{
  public:
    VulkanCppConsumerBase();

    virtual ~VulkanCppConsumerBase() override;

    bool Initialize(const std::string& filename, const GfxTocppPlatform& platform, const std::string& outputDir);

    void Destroy();

    void GenerateLoadData(const std::string& filename,
                          uint64_t           fileOffset,
                          const std::string& dataPtrVarName,
                          uint64_t           offset,
                          uint64_t           size);

    bool IsValid() const { return (main_file_ != nullptr); }

    const std::string& GetFilename() const { return filename_; }

    GfxTocppPlatform GetPlatform() { return platform_; }

    uint32_t GetProperWindowWidth(uint32_t width) { return std::min(width, window_width_); };
    uint32_t GetProperWindowHeight(uint32_t height) { return std::min(height, window_height_); };

    const std::string GetHandle(const format::HandleId& handleId)
    {
        return handle_id_map_.count(handleId) ? handle_id_map_[handleId] : "VK_NULL_HANDLE";
    }

    const std::string GetNextImage(const format::HandleId& swapchain)
    {
        if (next_image_map_.count(swapchain))
        {
            std::string nextImage = next_image_map_[swapchain].front();
            next_image_map_[swapchain].pop();
            return nextImage;
        }

        return "NULL";
    }

    bool GetResourceMemoryRequirements(format::HandleId memoryHandleId, std::string& requirements)
    {
        auto found_resource = memory_resource_map_.find(memoryHandleId);
        if (found_resource != memory_resource_map_.end())
        {
            std::queue<std::pair<format::HandleId, VkDeviceSize>>& resource_handles =
                memory_resource_map_[memoryHandleId];

            format::HandleId resource_handle = resource_handles.front().first;
            resource_handles.pop();

            requirements = resource_memory_req_map_[resource_handle];
            return true;
        }
        return false;
    }

    std::string AddStruct(const std::stringstream& content, const std::string& varnamePrefix);
    std::string
         AddMemoryFilePath(const std::string& fileName, const std::string& outDir, const uint8_t* data, uint64_t size);
    void AddResourceTracker(VulkanCppResourceTracker& resourceTracker) { resource_tracker_ = &resourceTracker; }
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
    void SetMaxCommandLimit(uint32_t max) { max_command_limit_ = max; }

    uint32_t GetNextId();
    uint32_t GetNextId(VkObjectType object_type);

    uint32_t GetCurrentApiCallNumber() { return api_call_number_; }

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

    void Generate_vkGetPhysicalDeviceQueueFamilyProperties(VkResult         returnValue,
                                                           format::HandleId physicalDevice,
                                                           uint32_t         queueFamilyIndex,
                                                           uint64_t         connection,
                                                           uint32_t         visual_id);

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
    Generate_vkGetImageMemoryRequirements2(format::HandleId                                              device,
                                           StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
                                           StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements);
    void
    Generate_vkGetImageMemoryRequirements2KHR(format::HandleId                                              device,
                                              StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
                                              StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements);

    void
         Generate_vkGetBufferMemoryRequirements2(format::HandleId                                               device,
                                                 StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
                                                 StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements);
    void Generate_vkGetBufferMemoryRequirements2KHR(
        format::HandleId                                               device,
        StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2>*           pMemoryRequirements);

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

    void Generate_vkCreateAndroidSurfaceKHR(VkResult                                                     returnValue,
                                            format::HandleId                                             instance,
                                            StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo,
                                            StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
                                            HandlePointerDecoder<VkSurfaceKHR>*                          pSurface);

    void Generate_vkCreateMetalSurfaceEXT(VkResult                                                   returnValue,
                                          format::HandleId                                           instance,
                                          StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT>* pCreateInfo,
                                          StructPointerDecoder<Decoded_VkAllocationCallbacks>*       pAllocator,
                                          HandlePointerDecoder<VkSurfaceKHR>*                        pSurface);

    void Generate_vkCreateWaylandSurfaceKHR(VkResult                                                     returnValue,
                                            format::HandleId                                             instance,
                                            StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo,
                                            StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
                                            HandlePointerDecoder<VkSurfaceKHR>*                          pSurface);

    void Generate_vkCreateWin32SurfaceKHR(VkResult                                                   returnValue,
                                          format::HandleId                                           instance,
                                          StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>* pCreateInfo,
                                          StructPointerDecoder<Decoded_VkAllocationCallbacks>*       pAllocator,
                                          HandlePointerDecoder<VkSurfaceKHR>*                        pSurface);

    void Generate_vkCreateXcbSurfaceKHR(VkResult                                                 returnValue,
                                        format::HandleId                                         instance,
                                        StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo,
                                        StructPointerDecoder<Decoded_VkAllocationCallbacks>*     pAllocator,
                                        HandlePointerDecoder<VkSurfaceKHR>*                      pSurface);

    void Generate_vkCreateXlibSurfaceKHR(VkResult                                                  returnValue,
                                         format::HandleId                                          instance,
                                         StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>* pCreateInfo,
                                         StructPointerDecoder<Decoded_VkAllocationCallbacks>*      pAllocator,
                                         HandlePointerDecoder<VkSurfaceKHR>*                       pSurface);

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
        HandlePointerDecoder<VkDescriptorUpdateTemplate>*                   pDescriptorUpdateTemplate,
        const char*                                                         extension = "");

    void Generate_vkCreateDescriptorUpdateTemplateKHR(
        VkResult                                                            returnValue,
        format::HandleId                                                    device,
        StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>*                pAllocator,
        HandlePointerDecoder<VkDescriptorUpdateTemplate>*                   pDescriptorUpdateTemplate)
    {
        Generate_vkCreateDescriptorUpdateTemplate(
            returnValue, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate, "KHR");
    }

    void Generate_vkUpdateDescriptorSetWithTemplate(format::HandleId                 device,
                                                    format::HandleId                 descriptorSet,
                                                    format::HandleId                 descriptorUpdateTemplate,
                                                    DescriptorUpdateTemplateDecoder* pData,
                                                    const char*                      extension = "");

    void Generate_vkUpdateDescriptorSetWithTemplateKHR(format::HandleId                 device,
                                                       format::HandleId                 descriptorSet,
                                                       format::HandleId                 descriptorUpdateTemplate,
                                                       DescriptorUpdateTemplateDecoder* pData)
    {
        Generate_vkUpdateDescriptorSetWithTemplate(device, descriptorSet, descriptorUpdateTemplate, pData, "KHR");
    }

    void Generate_vkCreateGraphicsPipelines(VkResult                                                    returnValue,
                                            format::HandleId                                            device,
                                            format::HandleId                                            pipelineCache,
                                            uint32_t                                                    createInfoCount,
                                            StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos,
                                            StructPointerDecoder<Decoded_VkAllocationCallbacks>*        pAllocator,
                                            HandlePointerDecoder<VkPipeline>*                           pPipelines);
    void Generate_vkCreateComputePipelines(VkResult                                                   returnValue,
                                           format::HandleId                                           device,
                                           format::HandleId                                           pipelineCache,
                                           uint32_t                                                   createInfoCount,
                                           StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfos,
                                           StructPointerDecoder<Decoded_VkAllocationCallbacks>*       pAllocator,
                                           HandlePointerDecoder<VkPipeline>*                          pPipelines);
    void Generate_vkCreateRayTracingPipelinesKHR(
        VkResult                                                         returnValue,
        format::HandleId                                                 deferredOperation,
        format::HandleId                                                 device,
        format::HandleId                                                 pipelineCache,
        uint32_t                                                         createInfoCount,
        StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>* pCreateInfos,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>*             pAllocator,
        HandlePointerDecoder<VkPipeline>*                                pPipelines);

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

    void Process_vkCreateRayTracingPipelinesKHR(
        const ApiCallInfo&                                               call_info,
        VkResult                                                         returnValue,
        format::HandleId                                                 device,
        format::HandleId                                                 deferredOperation,
        format::HandleId                                                 pipelineCache,
        uint32_t                                                         createInfoCount,
        StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>* pCreateInfos,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>*             pAllocator,
        HandlePointerDecoder<VkPipeline>*                                pPipelines) override;

    void Process_vkDeferredOperationJoinKHR(const ApiCallInfo& call_info,
                                            VkResult           returnValue,
                                            format::HandleId   device,
                                            format::HandleId   operation) override;

    virtual void Process_vkUpdateDescriptorSetWithTemplate(const ApiCallInfo&               call_info,
                                                           format::HandleId                 device,
                                                           format::HandleId                 descriptorSet,
                                                           format::HandleId                 descriptorUpdateTemplate,
                                                           DescriptorUpdateTemplateDecoder* pData) override;

    virtual void Process_vkCmdPushDescriptorSetWithTemplateKHR(const ApiCallInfo& call_info,
                                                               format::HandleId   commandBuffer,
                                                               format::HandleId   descriptorUpdateTemplate,
                                                               format::HandleId   layout,
                                                               uint32_t           set,
                                                               DescriptorUpdateTemplateDecoder* pData) override;

    virtual void Process_vkUpdateDescriptorSetWithTemplateKHR(const ApiCallInfo&               call_info,
                                                              format::HandleId                 device,
                                                              format::HandleId                 descriptorSet,
                                                              format::HandleId                 descriptorUpdateTemplate,
                                                              DescriptorUpdateTemplateDecoder* pData) override;

    static std::string ToEscape(const char* value);
    static std::string EscapeStringArray(const char* const* layerNames, const uint32_t stringArrayLength);
    static std::string ToEscape(const std::string& value);
    static std::string EscapeStringArray(const std::vector<std::string>& strings);

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

    void SetNeedsDebugUtilsCallback(bool value) { needs_debug_util_callback_ = value; }

    // Meta data commands
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
    virtual void
                 ProcessCreateHardwareBufferCommand(format::HandleId                                    memory_id,
                                                    uint64_t                                            buffer_id,
                                                    uint32_t                                            format,
                                                    uint32_t                                            width,
                                                    uint32_t                                            height,
                                                    uint32_t                                            stride,
                                                    uint64_t                                            usage,
                                                    uint32_t                                            layers,
                                                    const std::vector<format::HardwareBufferPlaneInfo>& plane_info) override;
    virtual void ProcessDestroyHardwareBufferCommand(uint64_t buffer_id) override;

  protected:
    FILE* GetFrameFile();
    FILE* GetHeaderFile() const { return header_file_; };
    FILE* GetGlobalFile() const { return global_file_; };

    std::string GenFrameName(uint32_t frameNumber, uint32_t frameSplitNumber, uint32_t fillLength);

    void NewFrameFile(uint32_t frameNumber, uint32_t frameSplitNumber);
    void EndFrameFile(uint32_t frameNumber, uint32_t frameSplitNumber);
    void NextFrame(bool isSplit);

    void Post_APICall(format::ApiCallId callId);

    void AddHandles(const std::string& outputName, const format::HandleId* ptrs, uint32_t count);
    void AddHandles(const std::string& outputName, const format::HandleId* ptrs);

    void GenerateDescriptorUpdateTemplateData(DescriptorUpdateTemplateDecoder* decoder,
                                              format::HandleId                 desc_update_template,
                                              FILE*                            frame_file,
                                              std::string&                     template_data_var_name);

    struct VulkanCppAndroidBufferInfo
    {
        std::string name;
        uint64_t    memory_id;
    };

    std::unordered_map<VkObjectType, uint32_t>                  counters_;
    VulkanCppResourceTracker*                                   resource_tracker_;
    VulkanCppLoaderGenerator                                    pfn_loader_;
    std::map<format::HandleId, std::string>                     handle_id_map_;
    std::vector<std::string>                                    func_data_;
    std::map<uint64_t, std::string>                             memory_id_map_;
    std::map<uint64_t, VulkanCppAndroidBufferInfo>              android_buffer_id_map_;
    std::map<uint64_t, std::string>                             android_memory_id_map_;
    std::map<format::HandleId, std::queue<std::string>>         next_image_map_;
    std::map<void*, std::string>                                ptr_map_;
    std::map<uint64_t, std::string>                             struct_map_; // hash -> name
    uint32_t                                                    window_width_;
    uint32_t                                                    window_height_;
    uint32_t                                                    max_command_limit_{ 1000 };
    std::vector<GfxToCppVariable>                               variable_data_;
    std::map<format::HandleId, DescriptorUpdateTemplateEntries> descriptor_update_template_entry_map_;
    std::map<format::HandleId, std::queue<std::pair<format::HandleId, VkDeviceSize>>> memory_resource_map_;
    std::map<format::HandleId, std::string>                                           resource_memory_req_map_;

    bool needs_debug_util_callback_ = false;

  private:
    bool CreateSubOutputDirectories(const std::vector<std::string>& subDirs);

    void WriteMainHeader();
    void WriteMainFooter();
    void WriteGlobalHeaderFile();
    void PrintOutGlobalVar();
    void PrintOutCMakeFile();

    struct FrameTempMemory
    {
        std::string name;
        size_t      size;
    };
    std::vector<FrameTempMemory> frame_split_temp_memory_;

    uint32_t                                           frame_number_;
    uint32_t                                           frame_split_number_;
    uint32_t                                           frame_api_call_number_;
    uint32_t                                           api_call_number_;
    FILE*                                              frame_file_;
    FILE*                                              global_file_;
    FILE*                                              header_file_;
    FILE*                                              main_file_;
    std::string                                        filename_;
    GfxTocppPlatform                                   platform_;
    std::string                                        out_dir_;
    std::string                                        bin_out_dir_;
    std::string                                        spv_out_dir_;
    std::string                                        src_out_dir_;
    DataFilePacker                                     data_packer_;
    DataFilePacker                                     spv_saver_;
    std::vector<std::vector<format::DeviceMemoryType>> original_memory_types_;
    std::vector<std::vector<format::DeviceMemoryHeap>> original_memory_heaps_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_CPP_CONSUMER_BASE_H
