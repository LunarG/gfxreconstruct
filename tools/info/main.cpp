/*
** Copyright (c) 2020 LunarG, Inc.
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

#include "project_version.h"

#include "decode/stat_consumer_base.h"
#include "decode/stat_decoder_base.h"
#include "decode/file_processor.h"
#include "format/format.h"
#include "format/format_util.h"
#include "generated/generated_vulkan_consumer.h"
#include "generated/generated_vulkan_decoder.h"
#if defined(WIN32)
#include "generated/generated_dx12_decoder.h"
#endif
#include "util/argument_parser.h"
#include "util/logging.h"
#include "util/to_string.h"

#include "vulkan/vulkan.h"

#include <cassert>
#include <cstdlib>
#include <limits>
#include <set>
#include <string>
#include <unordered_map>

const char kHelpShortOption[] = "-h";
const char kHelpLongOption[]  = "--help";
const char kVersionOption[]   = "--version";
const char kNoDebugPopup[]    = "--no-debug-popup";

const char kOptions[] = "-h|--help,--version,--no-debug-popup";

const char kUnrecognizedFormatString[] = "<unrecognized-format>";

static void PrintUsage(const char* exe_name)
{
    std::string app_name     = exe_name;
    size_t      dir_location = app_name.find_last_of("/\\");
    if (dir_location >= 0)
    {
        app_name.replace(0, dir_location + 1, "");
    }
    GFXRECON_WRITE_CONSOLE("\n%s - Print statistics for a GFXReconstruct capture file.\n", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("Usage:");
    GFXRECON_WRITE_CONSOLE("  %s [-h | --help] [--version] <file>\n", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("Required arguments:");
    GFXRECON_WRITE_CONSOLE("  <file>\t\tThe GFXReconstruct capture file to be processed.");
    GFXRECON_WRITE_CONSOLE("\nOptional arguments:");
    GFXRECON_WRITE_CONSOLE("  -h\t\t\tPrint usage information and exit (same as --help).");
    GFXRECON_WRITE_CONSOLE("  --version\t\tPrint version information and exit.");
#if defined(WIN32) && defined(_DEBUG)
    GFXRECON_WRITE_CONSOLE("  --no-debug-popup\tDisable the 'Abort, Retry, Ignore' message box");
    GFXRECON_WRITE_CONSOLE("        \t\tdisplayed when abort() is called (Windows debug only).");
#endif
}

static bool CheckOptionPrintUsage(const char* exe_name, const gfxrecon::util::ArgumentParser& arg_parser)
{
    if (arg_parser.IsOptionSet(kHelpShortOption) || arg_parser.IsOptionSet(kHelpLongOption))
    {
        PrintUsage(exe_name);
        return true;
    }

    return false;
}

static bool CheckOptionPrintVersion(const char* exe_name, const gfxrecon::util::ArgumentParser& arg_parser)
{
    if (arg_parser.IsOptionSet(kVersionOption))
    {
        std::string app_name     = exe_name;
        size_t      dir_location = app_name.find_last_of("/\\");

        if (dir_location >= 0)
        {
            app_name.replace(0, dir_location + 1, "");
        }

        GFXRECON_WRITE_CONSOLE("%s version info:", app_name.c_str());
        GFXRECON_WRITE_CONSOLE("  GFXReconstruct Version %s", GFXRECON_PROJECT_VERSION_STRING);
        GFXRECON_WRITE_CONSOLE("  Vulkan Header Version %u.%u.%u",
                               VK_VERSION_MAJOR(VK_HEADER_VERSION_COMPLETE),
                               VK_VERSION_MINOR(VK_HEADER_VERSION_COMPLETE),
                               VK_VERSION_PATCH(VK_HEADER_VERSION_COMPLETE));

        return true;
    }

    return false;
}

static std::string GetVersionString(uint32_t api_version)
{
    uint32_t major = api_version >> 22;
    uint32_t minor = (api_version >> 12) & 0x3ff;
    uint32_t patch = api_version & 0xfff;

    return std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(patch);
}

class StatConsumer : public gfxrecon::decode::StatConsumerBase
{
  public:
    StatConsumer() {}
    const std::string GetAppExeName() const { return exe_info.AppExeName; }
    uint32_t          GetTrimmedStartFrame() const { return trimmed_frame_; }
    uint32_t*         GetAppVersion() { return exe_info.AppVersion; }
    char*             GetCompanyName() { return exe_info.CompanyName; }
    char*             GetFileDescription() { return exe_info.FileDescription; }
    char*             GetFileVersion() { return exe_info.FileVersion; }
    char*             GetInternalName() { return exe_info.InternalName; }
    char*             GetOriginalFileName() { return exe_info.OriginalFilename; }
    char*             GetProductName() { return exe_info.ProductName; }
    char*             GetProductVersion() { return exe_info.ProductVersion; }
    virtual void      Process_ExeFileInfo(gfxrecon::util::filepath::ExeFileInfo& info) { exe_info = info; }
    virtual void      ProcessStateBeginMarker(uint64_t frame_number) override
    {
        GFXRECON_UNREFERENCED_PARAMETER(frame_number);
        // Theres should only be one of these in a capture file.
        trimmed_frame_ = static_cast<uint32_t>(frame_number);
    }

  private:
    gfxrecon::util::filepath::ExeFileInfo exe_info = {};
    uint32_t                              trimmed_frame_{ 0 };
};

#if defined(WIN32)

class Dx12StatsConsumer : public gfxrecon::decode::Dx12Consumer
{
  public:
    Dx12StatsConsumer() :
        dx12_consumer_usage_(false), device_ID_(0), vendor_ID_(0), subsys_id_(0), revision_(0),
        dedicated_video_memory_(0), dedicated_system_memory_(0), shared_system_memory_(0)
    {
        memset(&adapter_luid_, sizeof(adapter_luid_), 0);
    }

    WCHAR*   GetAdapterDescription() { return description_; }
    uint32_t GetVendorID() { return vendor_ID_; }
    uint32_t GetDeviceID() { return device_ID_; }
    uint32_t GetSubsysID() { return subsys_id_; }
    uint32_t GetRevision() { return revision_; }
    uint64_t GetDedicatedVideoMemory() { return dedicated_video_memory_; }
    uint64_t GetDedicatedSystemMemory() { return dedicated_system_memory_; }
    uint64_t GetSharedSystemMemory() { return shared_system_memory_; }
    DWORD    GetAdapterLUIDLowPart() { return adapter_luid_.LowPart; };
    LONG     GetAdapterLUIDHighPart() { return adapter_luid_.HighPart; };

    virtual void Process_D3D12CreateDevice(const gfxrecon::decode::ApiCallInfo&           call_info,
                                           HRESULT                                        return_value,
                                           gfxrecon::format::HandleId                     pAdapter,
                                           D3D_FEATURE_LEVEL                              MinimumFeatureLevel,
                                           gfxrecon::decode::Decoded_GUID                 riid,
                                           gfxrecon::decode::HandlePointerDecoder<void*>* ppDevice)
    {
        dx12_consumer_usage_ = true;
    }

    virtual void Process_IDXGIAdapter1_GetDesc1(
        const gfxrecon::decode::ApiCallInfo&                                                  call_info,
        gfxrecon::format::HandleId                                                            object_id,
        HRESULT                                                                               return_value,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_DXGI_ADAPTER_DESC1>* pDesc)
    {
        wcscpy_s(description_, pDesc->GetPointer()->Description);
        vendor_ID_               = pDesc->GetPointer()->VendorId;
        device_ID_               = pDesc->GetPointer()->DeviceId;
        subsys_id_               = pDesc->GetPointer()->SubSysId;
        revision_                = pDesc->GetPointer()->Revision;
        dedicated_video_memory_  = pDesc->GetPointer()->DedicatedVideoMemory;
        dedicated_system_memory_ = pDesc->GetPointer()->DedicatedSystemMemory;
        shared_system_memory_    = pDesc->GetPointer()->SharedSystemMemory;
        adapter_luid_            = pDesc->GetPointer()->AdapterLuid;
    }

    virtual void Process_IDXGIAdapter_GetDesc(
        const gfxrecon::decode::ApiCallInfo&                                                 call_info,
        gfxrecon::format::HandleId                                                           object_id,
        HRESULT                                                                              return_value,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_DXGI_ADAPTER_DESC>* pDesc)
    {
        wcscpy_s(description_, pDesc->GetPointer()->Description);
        vendor_ID_               = pDesc->GetPointer()->VendorId;
        device_ID_               = pDesc->GetPointer()->DeviceId;
        subsys_id_               = pDesc->GetPointer()->SubSysId;
        revision_                = pDesc->GetPointer()->Revision;
        dedicated_video_memory_  = pDesc->GetPointer()->DedicatedVideoMemory;
        dedicated_system_memory_ = pDesc->GetPointer()->DedicatedSystemMemory;
        shared_system_memory_    = pDesc->GetPointer()->SharedSystemMemory;
        adapter_luid_            = pDesc->GetPointer()->AdapterLuid;
    }

    bool WasD3D12APIDetected() { return dx12_consumer_usage_; }

  private:
    bool     dx12_consumer_usage_;
    WCHAR    description_[128] = {};
    uint32_t vendor_ID_;
    uint32_t device_ID_;
    uint32_t subsys_id_;
    uint32_t revision_;
    uint64_t dedicated_video_memory_;
    uint64_t dedicated_system_memory_;
    uint64_t shared_system_memory_;
    LUID     adapter_luid_;
};

#endif
class VulkanStatsConsumer : public gfxrecon::decode::VulkanConsumer
{
  public:
    uint32_t           GetTrimmedStartFrame() const { return trimmed_frame_; }
    const std::string& GetAppName() const { return app_name_; }
    uint32_t           GetAppVersion() const { return app_version_; }
    const std::string& GetEngineName() const { return engine_name_; }
    uint32_t           GetEngineVersion() const { return engine_version_; }
    uint32_t           GetApiVersion() const { return api_version_; }
    uint64_t           GetGraphicsPipelineCount() const { return graphics_pipelines_; }
    uint64_t           GetComputePipelineCount() const { return compute_pipelines_; }
    uint64_t           GetDrawCount() const { return draw_count_; }
    uint64_t           GetDispatchCount() const { return dispatch_count_; }
    uint64_t           GetAllocationCount() const { return allocation_count_; }
    uint64_t           GetMinAllocationSize() const { return min_allocation_size_; }
    uint64_t           GetMaxAllocationSize() const { return max_allocation_size_; }

    const std::set<gfxrecon::format::HandleId>& GetInstantiatedDevices() const { return used_physical_devices_; }
    const VkPhysicalDeviceProperties*           GetDeviceProperties(gfxrecon::format::HandleId id) const
    {
        auto entry = physical_device_properties_.find(id);
        if (entry != physical_device_properties_.end())
        {
            return &entry->second;
        }

        return nullptr;
    }

    bool WasVulkanAPIDetected() { return vulkan_consumer_used_; }

    virtual void ProcessStateBeginMarker(uint64_t frame_number) override
    {
        GFXRECON_UNREFERENCED_PARAMETER(frame_number);
        // Theres should only be one of these in a capture file.
        trimmed_frame_ = static_cast<uint32_t>(frame_number);
    }

    virtual void Process_vkCreateInstance(
        const gfxrecon::decode::ApiCallInfo&                                                    call_info,
        VkResult                                                                                returnValue,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkInstanceCreateInfo>* pCreateInfo,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkAllocationCallbacks>*,
        gfxrecon::decode::HandlePointerDecoder<VkInstance>*) override
    {
        vulkan_consumer_used_ = true;
        if ((pCreateInfo != nullptr) && (returnValue >= 0) && !pCreateInfo->IsNull())
        {
            auto create_info = pCreateInfo->GetPointer();
            auto app_info    = create_info->pApplicationInfo;
            if (app_info != nullptr)
            {
                if (app_info->pApplicationName != nullptr)
                {
                    app_name_ = app_info->pApplicationName;
                }

                if (app_info->pEngineName != nullptr)
                {
                    engine_name_ = app_info->pEngineName;
                }

                app_version_    = app_info->applicationVersion;
                engine_version_ = app_info->engineVersion;
                api_version_    = app_info->apiVersion;
            }
        }
    }

    virtual void Process_vkGetPhysicalDeviceProperties(
        const gfxrecon::decode::ApiCallInfo&                                                          call_info,
        gfxrecon::format::HandleId                                                                    physicalDevice,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkPhysicalDeviceProperties>* pProperties)
        override
    {
        if ((pProperties != nullptr) && !pProperties->IsNull())
        {
            physical_device_properties_[physicalDevice] = *pProperties->GetPointer();
        }
    }

    virtual void Process_vkGetPhysicalDeviceProperties2(
        const gfxrecon::decode::ApiCallInfo&                                                           call_info,
        gfxrecon::format::HandleId                                                                     physicalDevice,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkPhysicalDeviceProperties2>* pProperties)
        override
    {
        if ((pProperties != nullptr) && !pProperties->IsNull())
        {
            auto properties2                            = pProperties->GetPointer();
            physical_device_properties_[physicalDevice] = properties2->properties;
        }
    }

    virtual void Process_vkGetPhysicalDeviceProperties2KHR(
        const gfxrecon::decode::ApiCallInfo&                                                           call_info,
        gfxrecon::format::HandleId                                                                     physicalDevice,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkPhysicalDeviceProperties2>* pProperties)
        override
    {
        if ((pProperties != nullptr) && !pProperties->IsNull())
        {
            auto properties2                            = pProperties->GetPointer();
            physical_device_properties_[physicalDevice] = properties2->properties;
        }
    }

    virtual void
    Process_vkCreateDevice(const gfxrecon::decode::ApiCallInfo& call_info,
                           VkResult                             returnValue,
                           gfxrecon::format::HandleId           physicalDevice,
                           gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkDeviceCreateInfo>*,
                           gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkAllocationCallbacks>*,
                           gfxrecon::decode::HandlePointerDecoder<VkDevice>*) override
    {
        if (returnValue >= 0)
        {
            used_physical_devices_.insert(physicalDevice);
        }
    }

    virtual void Process_vkCreateGraphicsPipelines(
        const gfxrecon::decode::ApiCallInfo& call_info,
        VkResult                             returnValue,
        gfxrecon::format::HandleId,
        gfxrecon::format::HandleId,
        uint32_t createInfoCount,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkGraphicsPipelineCreateInfo>*,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkAllocationCallbacks>*,
        gfxrecon::decode::HandlePointerDecoder<VkPipeline>*) override
    {
        if (returnValue >= 0)
        {
            graphics_pipelines_ += createInfoCount;
        }
    }

    virtual void Process_vkCreateComputePipelines(
        const gfxrecon::decode::ApiCallInfo& call_info,
        VkResult                             returnValue,
        gfxrecon::format::HandleId,
        gfxrecon::format::HandleId,
        uint32_t createInfoCount,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkComputePipelineCreateInfo>*,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkAllocationCallbacks>*,
        gfxrecon::decode::HandlePointerDecoder<VkPipeline>*) override
    {
        if (returnValue >= 0)
        {
            compute_pipelines_ += createInfoCount;
        }
    }

    virtual void Process_vkCmdDraw(const gfxrecon::decode::ApiCallInfo& call_info,
                                   gfxrecon::format::HandleId,
                                   uint32_t,
                                   uint32_t,
                                   uint32_t,
                                   uint32_t) override
    {
        ++draw_count_;
    }

    virtual void Process_vkCmdDrawIndexed(const gfxrecon::decode::ApiCallInfo& call_info,
                                          gfxrecon::format::HandleId,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          int32_t,
                                          uint32_t) override
    {
        ++draw_count_;
    }

    virtual void Process_vkCmdDrawIndirect(const gfxrecon::decode::ApiCallInfo& call_info,
                                           gfxrecon::format::HandleId,
                                           gfxrecon::format::HandleId,
                                           VkDeviceSize,
                                           uint32_t,
                                           uint32_t) override
    {
        ++draw_count_;
    }

    virtual void Process_vkCmdDrawIndexedIndirect(const gfxrecon::decode::ApiCallInfo& call_info,
                                                  gfxrecon::format::HandleId,
                                                  gfxrecon::format::HandleId,
                                                  VkDeviceSize,
                                                  uint32_t,
                                                  uint32_t) override
    {
        ++draw_count_;
    }

    virtual void Process_vkCmdDrawIndirectCountKHR(const gfxrecon::decode::ApiCallInfo& call_info,
                                                   gfxrecon::format::HandleId,
                                                   gfxrecon::format::HandleId,
                                                   VkDeviceSize,
                                                   gfxrecon::format::HandleId,
                                                   VkDeviceSize,
                                                   uint32_t,
                                                   uint32_t) override
    {
        ++draw_count_;
    }

    virtual void Process_vkCmdDrawIndexedIndirectCountKHR(const gfxrecon::decode::ApiCallInfo& call_info,
                                                          gfxrecon::format::HandleId,
                                                          gfxrecon::format::HandleId,
                                                          VkDeviceSize,
                                                          gfxrecon::format::HandleId,
                                                          VkDeviceSize,
                                                          uint32_t,
                                                          uint32_t) override
    {
        ++draw_count_;
    }

    virtual void Process_vkCmdDrawIndirectByteCountEXT(const gfxrecon::decode::ApiCallInfo& call_info,
                                                       gfxrecon::format::HandleId,
                                                       uint32_t,
                                                       uint32_t,
                                                       gfxrecon::format::HandleId,
                                                       VkDeviceSize,
                                                       uint32_t,
                                                       uint32_t) override
    {
        ++draw_count_;
    }

    virtual void Process_vkCmdDrawIndirectCountAMD(const gfxrecon::decode::ApiCallInfo& call_info,
                                                   gfxrecon::format::HandleId,
                                                   gfxrecon::format::HandleId,
                                                   VkDeviceSize,
                                                   gfxrecon::format::HandleId,
                                                   VkDeviceSize,
                                                   uint32_t,
                                                   uint32_t) override
    {
        ++draw_count_;
    }

    virtual void Process_vkCmdDrawIndexedIndirectCountAMD(const gfxrecon::decode::ApiCallInfo& call_info,
                                                          gfxrecon::format::HandleId,
                                                          gfxrecon::format::HandleId,
                                                          VkDeviceSize,
                                                          gfxrecon::format::HandleId,
                                                          VkDeviceSize,
                                                          uint32_t,
                                                          uint32_t) override
    {
        ++draw_count_;
    }

    virtual void Process_vkCmdDrawMeshTasksNV(const gfxrecon::decode::ApiCallInfo& call_info,
                                              gfxrecon::format::HandleId,
                                              uint32_t,
                                              uint32_t) override
    {
        ++draw_count_;
    }

    virtual void Process_vkCmdDrawMeshTasksIndirectNV(const gfxrecon::decode::ApiCallInfo& call_info,
                                                      gfxrecon::format::HandleId,
                                                      gfxrecon::format::HandleId,
                                                      VkDeviceSize,
                                                      uint32_t,
                                                      uint32_t) override
    {
        ++draw_count_;
    }

    virtual void Process_vkCmdDrawMeshTasksIndirectCountNV(const gfxrecon::decode::ApiCallInfo& call_info,
                                                           gfxrecon::format::HandleId,
                                                           gfxrecon::format::HandleId,
                                                           VkDeviceSize,
                                                           gfxrecon::format::HandleId,
                                                           VkDeviceSize,
                                                           uint32_t,
                                                           uint32_t) override
    {
        ++draw_count_;
    }

    virtual void Process_vkCmdDispatch(const gfxrecon::decode::ApiCallInfo& call_info,
                                       gfxrecon::format::HandleId,
                                       uint32_t,
                                       uint32_t,
                                       uint32_t) override
    {
        ++dispatch_count_;
    }

    virtual void Process_vkCmdDispatchIndirect(const gfxrecon::decode::ApiCallInfo& call_info,
                                               gfxrecon::format::HandleId,
                                               gfxrecon::format::HandleId,
                                               VkDeviceSize) override
    {
        ++dispatch_count_;
    }

    virtual void Process_vkCmdDispatchBase(const gfxrecon::decode::ApiCallInfo& call_info,
                                           gfxrecon::format::HandleId,
                                           uint32_t,
                                           uint32_t,
                                           uint32_t,
                                           uint32_t,
                                           uint32_t,
                                           uint32_t) override
    {
        ++dispatch_count_;
    }

    virtual void Process_vkCmdDispatchBaseKHR(const gfxrecon::decode::ApiCallInfo& call_info,
                                              gfxrecon::format::HandleId,
                                              uint32_t,
                                              uint32_t,
                                              uint32_t,
                                              uint32_t,
                                              uint32_t,
                                              uint32_t) override
    {
        ++dispatch_count_;
    }

    virtual void Process_vkAllocateMemory(
        const gfxrecon::decode::ApiCallInfo& call_info,
        VkResult                             returnValue,
        gfxrecon::format::HandleId,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkMemoryAllocateInfo>* pAllocateInfo,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkAllocationCallbacks>*,
        gfxrecon::decode::HandlePointerDecoder<VkDeviceMemory>*) override
    {
        assert(pAllocateInfo != nullptr);

        if (returnValue >= 0)
        {
            ++allocation_count_;

            if (!pAllocateInfo->IsNull())
            {
                auto allocate_info = pAllocateInfo->GetPointer();

                if (allocate_info->allocationSize < min_allocation_size_)
                {
                    min_allocation_size_ = allocate_info->allocationSize;
                }

                if (allocate_info->allocationSize > max_allocation_size_)
                {
                    max_allocation_size_ = allocate_info->allocationSize;
                }
            }
        }
    }

  private:
    bool     vulkan_consumer_used_{ false };
    uint32_t trimmed_frame_{ 0 };

    // Application info.
    std::string app_name_;
    uint32_t    app_version_{ 0 };
    std::string engine_name_;
    uint32_t    engine_version_{ 0 };
    uint32_t    api_version_{ 0 };

    // Physical device info.
    std::set<gfxrecon::format::HandleId>                                       used_physical_devices_;
    std::unordered_map<gfxrecon::format::HandleId, VkPhysicalDeviceProperties> physical_device_properties_;

    // Total pipeline counts by type.
    uint64_t graphics_pipelines_{ 0 };
    uint64_t compute_pipelines_{ 0 };

    // Total draw/dispatch counts.
    uint64_t draw_count_{ 0 };
    uint64_t dispatch_count_{ 0 };

    // Memory allocation info.
    uint64_t allocation_count_{ 0 };
    uint64_t min_allocation_size_{ std::numeric_limits<uint64_t>::max() };
    uint64_t max_allocation_size_{ 0 };
};

int main(int argc, const char** argv)
{
    gfxrecon::util::Log::Init();

    gfxrecon::util::ArgumentParser arg_parser(argc, argv, kOptions, "");

    if (CheckOptionPrintUsage(argv[0], arg_parser) || CheckOptionPrintVersion(argv[0], arg_parser))
    {
        gfxrecon::util::Log::Release();
        exit(0);
    }
    else if (arg_parser.IsInvalid() || (arg_parser.GetPositionalArgumentsCount() != 1))
    {
        PrintUsage(argv[0]);
        gfxrecon::util::Log::Release();
        exit(-1);
    }
    else
    {
#if defined(WIN32) && defined(_DEBUG)
        if (arg_parser.IsOptionSet(kNoDebugPopup))
        {
            _set_abort_behavior(0, _WRITE_ABORT_MSG | _CALL_REPORTFAULT);
        }
#endif
    }

    const std::vector<std::string>& positional_arguments = arg_parser.GetPositionalArguments();
    std::string                     input_filename       = positional_arguments[0];

    gfxrecon::decode::FileProcessor file_processor;
    if (file_processor.Initialize(input_filename))
    {
        gfxrecon::decode::VulkanDecoder vulkan_decoder;
        VulkanStatsConsumer             vulkan_stats_consumer;
        vulkan_decoder.AddConsumer(&vulkan_stats_consumer);
        file_processor.AddDecoder(&vulkan_decoder);
        gfxrecon::decode::StatDecoderBase stat_decoder;
        StatConsumer                      stat_consumer;
        stat_decoder.AddConsumer(&stat_consumer);
        file_processor.AddDecoder(&stat_decoder);
#if defined(WIN32)
        gfxrecon::decode::Dx12Decoder dx12_decoder;
        Dx12StatsConsumer             dx12_consumer;
        dx12_decoder.AddConsumer(&dx12_consumer);
        file_processor.AddDecoder(&dx12_decoder);
#endif
        file_processor.ProcessAllFrames();
        if ((file_processor.GetCurrentFrameNumber() > 0) &&
            (file_processor.GetErrorState() == gfxrecon::decode::FileProcessor::kErrorNone))
        {
            GFXRECON_WRITE_CONSOLE("File info:");
            // File options.
            gfxrecon::format::CompressionType compression_type = gfxrecon::format::CompressionType::kNone;

            auto file_options = file_processor.GetFileOptions();
            for (const auto& option : file_options)
            {
                if (option.key == gfxrecon::format::FileOption::kCompressionType)
                {
                    compression_type = static_cast<gfxrecon::format::CompressionType>(option.value);
                }
            }

            // Compression type.
            std::string compression_type_name = gfxrecon::format::GetCompressionTypeName(compression_type);
            if (!compression_type_name.empty())
            {
                GFXRECON_WRITE_CONSOLE("\tCompression format: %s", compression_type_name.c_str());
            }
            else
            {
                GFXRECON_WRITE_CONSOLE("\tCompression format: %s", kUnrecognizedFormatString);
            }

            // Frame counts.
            uint32_t trim_start_frame = stat_consumer.GetTrimmedStartFrame();
            uint32_t frame_count      = file_processor.GetCurrentFrameNumber();

            if (trim_start_frame == 0)
            {
                // Not a trimmed file.
                GFXRECON_WRITE_CONSOLE("\tTotal frames: %u", frame_count);
            }
            else
            {
                // Include the frame range for trimmed files.
                GFXRECON_WRITE_CONSOLE("\tTotal frames: %u (trimmed frame range %u-%u)",
                                       frame_count,
                                       trim_start_frame,
                                       trim_start_frame + frame_count - 1);
            }
            GFXRECON_WRITE_CONSOLE("\nApplication info:");
            GFXRECON_WRITE_CONSOLE("\tApplication exe name: %s", stat_consumer.GetAppExeName().c_str());
#if defined(WIN32)
            auto exe_version = stat_consumer.GetAppVersion();
            GFXRECON_WRITE_CONSOLE(
                "\tApplication version: %d.%d.%d.%d", exe_version[0], exe_version[1], exe_version[2], exe_version[3]);
            GFXRECON_WRITE_CONSOLE("\tApplication Company name: %s", stat_consumer.GetCompanyName());
            // we are combining file description and product name and presenting both only if they are not same
            std::string app_data = stat_consumer.GetFileDescription();
            if (strcmp(stat_consumer.GetProductName(), "N/A") != 0)
            {
                if (strcmp(stat_consumer.GetProductName(), stat_consumer.GetFileDescription()) != 0)
                {
                    app_data += " // ";
                    app_data += stat_consumer.GetProductName();
                }
            }
            if (dx12_consumer.WasD3D12APIDetected())
            {
                GFXRECON_WRITE_CONSOLE(
                    "\tAdapter Description: %s",
                    gfxrecon::util::WCharArrayToString(dx12_consumer.GetAdapterDescription()).c_str());
                GFXRECON_WRITE_CONSOLE("\tVendor ID: 0x%x", dx12_consumer.GetVendorID());
                GFXRECON_WRITE_CONSOLE("\tDevice ID: 0x%x", dx12_consumer.GetDeviceID());
                GFXRECON_WRITE_CONSOLE("\tSubsys ID: 0x%x", dx12_consumer.GetSubsysID());
                GFXRECON_WRITE_CONSOLE("\tRevision: %u", dx12_consumer.GetRevision());
                GFXRECON_WRITE_CONSOLE("\tDedicated Video Memory: %u", dx12_consumer.GetDedicatedVideoMemory());
                GFXRECON_WRITE_CONSOLE("\tDedicated System Memory: %u", dx12_consumer.GetDedicatedSystemMemory());
                GFXRECON_WRITE_CONSOLE("\tShared System Memory: %u", dx12_consumer.GetSharedSystemMemory());
                GFXRECON_WRITE_CONSOLE("\tAdapter LUID:%u %u",
                                       dx12_consumer.GetAdapterLUIDHighPart(),
                                       dx12_consumer.GetAdapterLUIDLowPart());
            }
#endif
            if (vulkan_stats_consumer.WasVulkanAPIDetected())
            {
                uint32_t api_version = vulkan_stats_consumer.GetApiVersion();

                GFXRECON_WRITE_CONSOLE("\tApplication name: %s", vulkan_stats_consumer.GetAppName().c_str());
                GFXRECON_WRITE_CONSOLE("\tApplication version: %u", vulkan_stats_consumer.GetAppVersion());
                GFXRECON_WRITE_CONSOLE("\tEngine name: %s", vulkan_stats_consumer.GetEngineName().c_str());
                GFXRECON_WRITE_CONSOLE("\tEngine version: %u", vulkan_stats_consumer.GetEngineVersion());
                GFXRECON_WRITE_CONSOLE(
                    "\tTarget API version: %u (%s)", api_version, GetVersionString(api_version).c_str());
                // Properties for physical devices used to create logical devices.
                std::vector<const VkPhysicalDeviceProperties*> used_device_properties;
                auto used_devices = vulkan_stats_consumer.GetInstantiatedDevices();
                for (auto entry : used_devices)
                {
                    auto properties = vulkan_stats_consumer.GetDeviceProperties(entry);
                    if (properties != nullptr)
                    {
                        used_device_properties.push_back(properties);
                    }
                }
                // Don't print anything if no queries were made for VkPhysicalDeviceProperties.
                if (!used_device_properties.empty())
                {
                    for (auto entry : used_device_properties)
                    {
                        GFXRECON_WRITE_CONSOLE("\nPhysical device info:");
                        GFXRECON_WRITE_CONSOLE("\tDevice name: %s", entry->deviceName);
                        GFXRECON_WRITE_CONSOLE("\tDevice ID: 0x%x", entry->deviceID);
                        GFXRECON_WRITE_CONSOLE("\tVendor ID: 0x%x", entry->vendorID);
                        GFXRECON_WRITE_CONSOLE(
                            "\tDriver version: %u (0x%x)", entry->driverVersion, entry->driverVersion);
                        GFXRECON_WRITE_CONSOLE(
                            "\tAPI version: %u (%s)", entry->apiVersion, GetVersionString(entry->apiVersion).c_str());
                    }
                }
                GFXRECON_WRITE_CONSOLE("\nDevice memory allocation info:");
                GFXRECON_WRITE_CONSOLE("\tTotal allocations: %" PRIu64, vulkan_stats_consumer.GetAllocationCount());
                GFXRECON_WRITE_CONSOLE("\tMin allocation size: %" PRIu64, vulkan_stats_consumer.GetMinAllocationSize());
                GFXRECON_WRITE_CONSOLE("\tMax allocation size: %" PRIu64, vulkan_stats_consumer.GetMaxAllocationSize());
                GFXRECON_WRITE_CONSOLE("\nPipeline info:");
                GFXRECON_WRITE_CONSOLE("\tTotal graphics pipelines: %" PRIu64,
                                       vulkan_stats_consumer.GetGraphicsPipelineCount());
                GFXRECON_WRITE_CONSOLE("\tTotal compute pipelines: %" PRIu64,
                                       vulkan_stats_consumer.GetComputePipelineCount());
            }

            // TODO: This is the number of recorded draw calls, which will not reflect the number of draw calls executed
            // when recorded once to a command buffer that is submitted/replayed more than once.
            // GFXRECON_WRITE_CONSOLE("\nDraw/dispatch call info:");
            // GFXRECON_WRITE_CONSOLE("\tTotal draw calls: %" PRIu64, vulkan_stats_consumer.GetDrawCount());
            // GFXRECON_WRITE_CONSOLE("\tTotal dispatch calls: %" PRIu64, vulkan_stats_consumer.GetDispatchCount());
        }
        else if (file_processor.GetErrorState() != gfxrecon::decode::FileProcessor::kErrorNone)
        {
            GFXRECON_WRITE_CONSOLE("A failure has occurred during file processing");
            gfxrecon::util::Log::Release();
            exit(-1);
        }
        else
        {
            GFXRECON_WRITE_CONSOLE("File did not contain any frames");
        }
    }

    gfxrecon::util::Log::Release();
    return 0;
}
