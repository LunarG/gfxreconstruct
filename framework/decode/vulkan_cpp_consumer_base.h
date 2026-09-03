//
// Copyright (c) 2020 Samsung
// Copyright (c) 2023 Google
// Copyright (c) 2023 LunarG, Inc
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GFXRECON_DECODE_VULKAN_CPP_CONSUMER_BASE_H
#define GFXRECON_DECODE_VULKAN_CPP_CONSUMER_BASE_H

#include "vulkan_cpp_utilities.h"
#include "decode/vulkan_cpp_code_writer.h"
#include "decode/vulkan_cpp_loader_generator.h"
#include "decode/vulkan_cpp_utilities.h"
#include "format/platform_types.h"
#include "generated/generated_vulkan_consumer.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <cstdio>
#include <string>
#include <sstream>
#include <type_traits>
#include <unordered_set>
#include <queue>

#include "decode/vulkan_cpp_util_datapack.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// The window size that the generated source uses when the capture file has no
// resize command and the user gives no --max-window-dimensions option.
constexpr uint32_t kDefaultWindowWidth  = 1920;
constexpr uint32_t kDefaultWindowHeight = 1080;

struct DescriptorUpdateTemplateEntries
{
    std::vector<VkDescriptorUpdateTemplateEntry> data;
    std::vector<VkDescriptorUpdateTemplateEntry> images;
    std::vector<VkDescriptorUpdateTemplateEntry> buffers;
    std::vector<VkDescriptorUpdateTemplateEntry> texels;
    std::vector<VkDescriptorUpdateTemplateEntry> accelerations;
    std::vector<VkDescriptorUpdateTemplateEntry> inline_uniform_blocks;
};

// Track items that are specific to a given device
struct VkDeviceInfo
{
    format::HandleId                               parent{ 0 };
    std::unordered_map<format::HandleId, uint64_t> opaque_addresses;
};

class VulkanCppConsumerBase : public VulkanConsumer
{
  public:
    VulkanCppConsumerBase();

    virtual ~VulkanCppConsumerBase() override;

    bool Initialize(const std::string& filename, const GfxToCppPlatform& platform, const std::string& outputDir);

    void Destroy();

    void GenerateLoadData(const std::string& filename,
                          uint64_t           fileOffset,
                          const std::string& dataPtrVarName,
                          uint64_t           offset,
                          uint64_t           size);

    bool IsValid() const { return (main_file_ != nullptr); }

    const std::string& GetFilename() const { return filename_; }

    GfxToCppPlatform GetPlatform() { return platform_; }

    uint32_t GetProperWindowWidth(uint32_t width) { return std::min(width, max_window_width_); };
    uint32_t GetProperWindowHeight(uint32_t height) { return std::min(height, max_window_height_); };
    uint32_t GetCurrentFrameNumber() { return frame_number_; }
    uint32_t GetCurrentFrameSplitNumber() { return frame_split_number_; }
    uint32_t GetCurrentApiCallNumber() { return api_call_number_; }

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
        if (found_resource == memory_resource_map_.end() || found_resource->second.empty())
        {
            return false;
        }

        format::HandleId resource_handle = found_resource->second.front().first;
        found_resource->second.pop();

        auto found_requirements = resource_memory_req_map_.find(resource_handle);
        if (found_requirements == resource_memory_req_map_.end() || found_requirements->second.empty())
        {
            // The capture never asked this resource what it needs.
            return false;
        }

        requirements = found_requirements->second;
        return true;
    }

    std::string AddStruct(const std::stringstream& content, const std::string& varnamePrefix);
    std::string
         AddMemoryFilePath(const std::string& fileName, const std::string& outDir, const uint8_t* data, uint64_t size);
    void AddKnownVariables(const std::string& type, const std::string& name);
    void AddKnownVariables(const std::string& type, const std::string& name, uint32_t count);
    void AddKnownVariables(const std::string& type, const std::string& name, const format::HandleId* handleId);
    void AddKnownVariables(const std::string&      type,
                           const std::string&      name,
                           const format::HandleId* handleId,
                           uint32_t                count);
    void SetMemoryResourceMap(
        const std::map<format::HandleId, std::queue<std::pair<format::HandleId, VkDeviceSize>>> memoryImageMap);
    // Set the upper limit for the window size, from the --max-window-dimensions option.
    void SetMaxWindowSize(uint32_t maxWindowWidth, uint32_t maxWindowHeight);
    void SetMaxCommandLimit(uint32_t max) { max_command_limit_ = max; }

    void DisableVirtualSwapchain() { enable_virtual_swapchain_ = false; }

    uint32_t GetNextId();
    uint32_t GetNextId(VkObjectType object_type);

    std::string GetAndroidHwBufferName(uint64_t buffer);

    // True when the target platform has AHardwareBuffer.  Only Android does.  The
    // types and the entry points do not exist anywhere else, so the generated
    // source must leave that work out or it will not compile.
    bool SupportsAndroidHardwareBuffers();

    void SetNeedsDebugUtilsCallback(bool value) { needs_debug_util_callback_ = value; }

    // Custom code generation commands
    void Generate_vkEnumeratePhysicalDevices(args::EnumeratePhysicalDevices& args);

    void Generate_vkCreateSwapchainKHR(args::CreateSwapchainKHR& args);

    void Generate_vkDestroySwapchainKHR(args::DestroySwapchainKHR& args);

    void Generate_vkGetSwapchainImagesKHR(args::GetSwapchainImagesKHR& args);

    void Generate_vkGetPhysicalDeviceSurfaceFormatsKHR(args::GetPhysicalDeviceSurfaceFormatsKHR& args);

    void Generate_vkGetPhysicalDeviceSurfacePresentModesKHR(args::GetPhysicalDeviceSurfacePresentModesKHR& args);

    void Generate_vkGetPhysicalDeviceQueueFamilyProperties(args::GetPhysicalDeviceQueueFamilyProperties& args);

    void Generate_vkGetPhysicalDeviceQueueFamilyProperties(VkResult         returnValue,
                                                           format::HandleId physicalDevice,
                                                           uint32_t         queueFamilyIndex,
                                                           uint64_t         connection,
                                                           uint32_t         visual_id);
    void Generate_vkCreateDevice(args::CreateDevice& args);
    void Generate_vkDestroyDevice(args::DestroyDevice& args);

    void Generate_vkGetImageMemoryRequirements(args::GetImageMemoryRequirements& args);

    void Generate_vkGetBufferMemoryRequirements(args::GetBufferMemoryRequirements& args);

    void Generate_vkGetImageSparseMemoryRequirements(args::GetImageSparseMemoryRequirements& args);

    void Generate_vkGetImageMemoryRequirements2(args::GetImageMemoryRequirements2& args, const char* extension = "");
    void Generate_vkGetImageMemoryRequirements2KHR(args::GetImageMemoryRequirements2KHR& args);

    void Generate_vkGetBufferMemoryRequirements2(args::GetBufferMemoryRequirements2& args, const char* extension = "");
    void Generate_vkGetBufferMemoryRequirements2KHR(args::GetBufferMemoryRequirements2KHR& args);

    void Generate_vkGetFenceStatus(args::GetFenceStatus& args);

    void Generate_vkMapMemory(args::MapMemory& args);

    void Generate_vkUnmapMemory(args::UnmapMemory& args);

    void Generate_vkAllocateMemory(args::AllocateMemory& args);
    void Generate_vkCreateBuffer(args::CreateBuffer& args);

    void Generate_vkCreateInstance(args::CreateInstance& args);

    void Generate_vkCreateShaderModule(args::CreateShaderModule& args);

    void Generate_vkCreatePipelineCache(args::CreatePipelineCache& args);

    void GenerateSurfaceCreation(GfxToCppPlatform        platform,
                                 VkResult                returnValue,
                                 format::HandleId        instance,
                                 void*                   pSurfaceCreateInfo,
                                 const format::HandleId* surface);

    void Generate_vkCreateAndroidSurfaceKHR(args::CreateAndroidSurfaceKHR& args);

    void Generate_vkCreateMetalSurfaceEXT(args::CreateMetalSurfaceEXT& args);

    void Generate_vkCreateWaylandSurfaceKHR(args::CreateWaylandSurfaceKHR& args);

    void Generate_vkCreateWin32SurfaceKHR(args::CreateWin32SurfaceKHR& args);

    void Generate_vkCreateXcbSurfaceKHR(args::CreateXcbSurfaceKHR& args);

    void Generate_vkCreateXlibSurfaceKHR(args::CreateXlibSurfaceKHR& args);

    void Generate_vkAcquireNextImageKHR(args::AcquireNextImageKHR& args);

    void Generate_vkAcquireNextImage2KHR(args::AcquireNextImage2KHR& args);

    void Generate_vkWaitForFences(args::WaitForFences& args);

    void Generate_vkGetQueryPoolResults(args::GetQueryPoolResults& args);

    void Generate_vkSetDebugUtilsObjectNameEXT(args::SetDebugUtilsObjectNameEXT& args);
    void Generate_vkSetDebugUtilsObjectTagEXT(args::SetDebugUtilsObjectTagEXT& args);
    void Generate_vkDebugMarkerSetObjectNameEXT(args::DebugMarkerSetObjectNameEXT& args);
    void Generate_vkDebugMarkerSetObjectTagEXT(args::DebugMarkerSetObjectTagEXT& args);

    void Generate_vkCreateDescriptorUpdateTemplate(args::CreateDescriptorUpdateTemplate& args,
                                                   const char*                           extension = "");

    void Generate_vkCreateDescriptorUpdateTemplateKHR(args::CreateDescriptorUpdateTemplateKHR& args)
    {
        Generate_vkCreateDescriptorUpdateTemplate(reinterpret_cast<args::CreateDescriptorUpdateTemplate&>(args), "KHR");
    }

    void Generate_vkUpdateDescriptorSetWithTemplate(args::UpdateDescriptorSetWithTemplate& args,
                                                    const char*                            extension = "");

    void Generate_vkUpdateDescriptorSetWithTemplateKHR(args::UpdateDescriptorSetWithTemplateKHR& args)
    {
        Generate_vkUpdateDescriptorSetWithTemplate(reinterpret_cast<args::UpdateDescriptorSetWithTemplate&>(args),
                                                   "KHR");
    }

    void Generate_vkCreateGraphicsPipelines(args::CreateGraphicsPipelines& args);
    void Generate_vkCreateComputePipelines(args::CreateComputePipelines& args);
    void Generate_vkCreateRayTracingPipelinesKHR(args::CreateRayTracingPipelinesKHR& args);

    void Generate_vkGetAndroidHardwareBufferPropertiesANDROID(args::GetAndroidHardwareBufferPropertiesANDROID& args);
    void Generate_vkGetDeviceQueue(args::GetDeviceQueue& args);
    void Generate_vkGetMemoryAndroidHardwareBufferANDROID(args::GetMemoryAndroidHardwareBufferANDROID& args);
    void Generate_vkGetSemaphoreWin32HandleKHR(args::GetSemaphoreWin32HandleKHR& args);
    void Generate_vkImportSemaphoreWin32HandleKHR(args::ImportSemaphoreWin32HandleKHR& args);
    void Generate_vkGetSemaphoreFdKHR(args::GetSemaphoreFdKHR& args);
    void Generate_vkImportSemaphoreFdKHR(args::ImportSemaphoreFdKHR& args);

    void Generate_vkQueueSubmit(args::QueueSubmit& args);

    void Generate_vkQueueSubmit2(args::QueueSubmit2& args, const char* extension = "");

    void Generate_vkQueueSubmit2KHR(args::QueueSubmit2KHR& args)
    {
        Generate_vkQueueSubmit2(reinterpret_cast<args::QueueSubmit2&>(args), "KHR");
    }

    void Generate_vkQueueBindSparse(args::QueueBindSparse& args);

    void Generate_vkQueuePresentKHR(args::QueuePresentKHR& args);

    // Intercept commands that perform additional work prior to the standard code generation
    void Intercept_vkBindImageMemory(args::BindImageMemory& args);

    void Intercept_vkBindImageMemory2(args::BindImageMemory2& args, const char* extension = "");

    void Intercept_vkBindImageMemory2KHR(args::BindImageMemory2KHR& args)
    {
        Intercept_vkBindImageMemory2(reinterpret_cast<args::BindImageMemory2&>(args), "KHR");
    }

    void Intercept_vkBindBufferMemory(args::BindBufferMemory& args);

    void Intercept_vkBindBufferMemory2(args::BindBufferMemory2& args);

    void Intercept_vkBindBufferMemory2KHR(args::BindBufferMemory2KHR& args)
    {
        Intercept_vkBindBufferMemory2(reinterpret_cast<args::BindBufferMemory2&>(args));
    }

    void Intercept_vkCmdBeginRenderPass(args::CmdBeginRenderPass& args);

    void Intercept_vkCreateFramebuffer(args::CreateFramebuffer& args);

    void Intercept_vkCreateSwapchainKHR(args::CreateSwapchainKHR& args);

    void Intercept_vkDestroySemaphore(args::DestroySemaphore& args);

    // Complete manual process functions
    void Process_vkCreateRayTracingPipelinesKHR(const ApiCallInfo&                  call_info,
                                                args::CreateRayTracingPipelinesKHR& args) override;

    void Process_vkDeferredOperationJoinKHR(const ApiCallInfo&              call_info,
                                            args::DeferredOperationJoinKHR& args) override;

    void Process_vkUpdateDescriptorSetWithTemplate(const ApiCallInfo&                     call_info,
                                                   args::UpdateDescriptorSetWithTemplate& args) override;

    virtual void
    Process_vkCmdPushDescriptorSetWithTemplateKHR(const ApiCallInfo&                         call_info,
                                                  args::CmdPushDescriptorSetWithTemplateKHR& args) override;

    virtual void Process_vkUpdateDescriptorSetWithTemplateKHR(const ApiCallInfo&                        call_info,
                                                              args::UpdateDescriptorSetWithTemplateKHR& args) override;

    virtual void
    Process_vkCmdPushDescriptorSetWithTemplate2KHR(const ApiCallInfo&                          call_info,
                                                   args::CmdPushDescriptorSetWithTemplate2KHR& args) override;

    // String utilities
    static std::string ToEscape(const char* value);
    static std::string EscapeStringArray(const char* const* layerNames, const uint32_t stringArrayLength);
    static std::string ToEscape(const std::string& value);
    static std::string EscapeStringArray(const std::vector<std::string>& strings);

    // Special case struct build functions for cleaner use in generated code.
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
    static std::string BuildValue(const StdVideoAV1FrameRestorationType values);
    static std::string BuildValue(const StdVideoAV1FrameRestorationType* values, uint32_t count);

    template <typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
    static std::string BuildValue(const T* values, size_t count)
    {
        std::stringstream output;
        output << "{";
        for (size_t idx = 0; idx < count; idx++)
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
    ProcessCreateHardwareBufferCommand(format::HandleId                                    device_id,
                                       format::HandleId                                    memory_id,
                                       uint64_t                                            buffer_id,
                                       uint32_t                                            format,
                                       uint32_t                                            width,
                                       uint32_t                                            height,
                                       uint32_t                                            stride,
                                       uint64_t                                            usage,
                                       uint32_t                                            layers,
                                       const std::vector<format::HardwareBufferPlaneInfo>& plane_info) override;

    virtual void ProcessDisplayMessageCommand(const std::string& message) override;
    virtual void ProcessDestroyHardwareBufferCommand(uint64_t buffer_id) override;
    virtual void
    ProcessSetOpaqueAddressCommand(format::HandleId device_id, format::HandleId object_id, uint64_t address) override;

  protected:
    FILE* GetFrameFile();

    // Writes into the current frame file and owns the indent level.  The frame
    // body sits inside a function, so the indent starts at one.
    CodeWriter& GetFrameWriter() { return frame_writer_; }

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

    struct VulkanCppAndroidMemoryInfo
    {
        std::string name;
        std::string buffer_name;
    };

    std::unordered_map<VkObjectType, uint32_t>                            counters_;
    VulkanCppLoaderGenerator                                              pfn_loader_;
    std::unordered_map<format::HandleId, std::string>                     handle_id_map_;
    std::unordered_map<format::HandleId, VkDeviceInfo*>                   device_info_map_;
    std::vector<std::string>                                              func_data_;
    std::unordered_map<uint64_t, std::string>                             memory_id_map_;
    std::unordered_map<uint64_t, VulkanCppAndroidBufferInfo>              android_buffer_id_map_;
    std::unordered_map<uint64_t, VulkanCppAndroidMemoryInfo>              android_memory_id_map_;
    std::unordered_map<format::HandleId, std::queue<std::string>>         next_image_map_;
    // Count variable names for the two-call query idiom.  The first call asks for
    // the count, the second call asks for the data.  These are separate Process_
    // calls with separate argument objects, so the key must be the handle that the
    // query is about.  A pointer into the argument object is not stable across the
    // two calls.  One map for each query, because two queries can share a handle.
    std::unordered_map<format::HandleId, std::string>                     swapchain_image_count_map_;
    std::unordered_map<format::HandleId, std::string>                     surface_format_count_map_;
    std::unordered_map<format::HandleId, std::string>                     surface_present_mode_count_map_;
    std::unordered_map<format::HandleId, std::string>                     queue_family_count_map_;
    std::unordered_map<uint64_t, std::string>                             struct_map_; // hash -> name
    // The current window size, which a resize command in the capture file can change.
    uint32_t window_width_{ kDefaultWindowWidth };
    uint32_t window_height_{ kDefaultWindowHeight };
    // The upper limit for the window size. UINT32_MAX applies no limit.
    uint32_t                                                              max_window_width_{ UINT32_MAX };
    uint32_t                                                              max_window_height_{ UINT32_MAX };
    uint32_t                                                              max_command_limit_{ 1000 };
    std::vector<GfxToCppVariable>                                         variable_data_;
    std::vector<format::HandleId>                                         imported_semaphores_;
    std::unordered_map<format::HandleId, DescriptorUpdateTemplateEntries> descriptor_update_template_entry_map_;
    std::map<format::HandleId, std::queue<std::pair<format::HandleId, VkDeviceSize>>> memory_resource_map_;
    std::unordered_map<format::HandleId, std::string>                                 resource_memory_req_map_;

    bool needs_debug_util_callback_ = false;

    // Warn once, not for each call that the capture made.
    bool warned_about_android_hardware_buffers_ = false;

  private:
    bool CreateSubOutputDirectories(const std::vector<std::string>& subDirs);
    void PrintOutCMakeFile();
    void WriteMainHeader();
    void WriteMainFooter();
    bool WriteGlobalHeaderFile();
    void PrintOutGlobalVar();
    bool WriteSwapchainFiles();

    // Write the device extension list and the device slots that the capture used.
    void PrintOutDeviceSelectionData(FILE* file);

    // The slot that this physical device had in vkEnumeratePhysicalDevices during
    // capture.  Returns 0 when the slot is not known.
    uint32_t GetCapturedPhysicalDeviceIndex(format::HandleId physicalDevice) const;

    // Note the slot and the extensions that one vkCreateDevice call needed.
    void RecordDeviceSelectionData(format::HandleId physicalDevice, const VkDeviceCreateInfo* createInfo);

    struct FrameTempMemory
    {
        std::string name;
        size_t      size;
    };

    // The physical devices in the order that vkEnumeratePhysicalDevices gave during
    // capture, the slots that vkCreateDevice used, and every device extension that
    // the capture enabled.  The generated source uses these to choose a device.
    std::vector<format::HandleId> enumerated_physical_devices_;
    std::vector<uint32_t>         used_physical_device_indices_;
    std::vector<std::string>      required_device_extensions_;

    bool                                               enable_virtual_swapchain_{ true };
    uint32_t                                           frame_number_;
    uint32_t                                           frame_split_number_;
    uint32_t                                           frame_api_call_number_;
    uint32_t                                           api_call_number_;
    std::vector<FrameTempMemory>                       frame_split_temp_memory_;
    FILE*                                              frame_file_;
    CodeWriter                                         frame_writer_;
    FILE*                                              global_file_;
    FILE*                                              main_file_;
    std::string                                        filename_;
    GfxToCppPlatform                                   platform_;
    std::string                                        out_dir_;
    std::string                                        bin_out_dir_;
    std::string                                        spv_out_dir_;
    std::string                                        src_out_dir_;
    DataFilePacker                                     data_packer_;
    DataFilePacker                                     spv_saver_;
    std::vector<std::vector<format::DeviceMemoryType>> original_memory_types_;
    std::vector<std::vector<format::DeviceMemoryHeap>> original_memory_heaps_;

    // The memory types that the capture file recorded, by physical device.  The
    // generated source needs the row for the device that it uses, and the order in
    // which the meta commands arrive is not that order.
    std::unordered_map<format::HandleId, std::vector<format::DeviceMemoryType>> captured_memory_types_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_CPP_CONSUMER_BASE_H
