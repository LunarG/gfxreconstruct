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

#include "decode/vulkan_cpp_consumer_base.h"
#include "decode/vulkan_cpp_template_strings.h"

#include PROJECT_VERSION_HEADER_FILE
#include "util/file_path.h"
#include "util/platform.h"
#include <util/hash.h>
#include "decode/vulkan_cpp_structs.h"
#include <generated/generated_vulkan_cpp_structs.h>
#include "generated/generated_vulkan_cpp_consumer_extension.h"
#include "generated/generated_vulkan_enum_to_string.h"

#include <algorithm>
#include <cmath>
#include <iomanip>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct GfxToCppPlatformMap
{
    GfxToCppPlatform platform;
    std::string      platform_str;
};

GfxToCppPlatform GetGfxToCppPlatform(const std::string& format_str);
std::string      GfxToCppPlatformToString(GfxToCppPlatform platform);

VulkanCppConsumerBase::VulkanCppConsumerBase() :
    pfn_loader_(), frame_file_(nullptr), global_file_(nullptr), main_file_(nullptr)
{
    counters_[VK_OBJECT_TYPE_UNKNOWN] = 0;
}

VulkanCppConsumerBase::~VulkanCppConsumerBase()
{
    Destroy();
}

bool VulkanCppConsumerBase::CreateSubOutputDirectories(const std::vector<std::string>& subDirs)
{
    for (const std::string& sub_dir : subDirs)
    {
        std::string sub_output_dir = util::filepath::Join(out_dir_, sub_dir);
        if (util::filepath::Exists(sub_output_dir))
        {
            if (!util::filepath::IsDirectory(sub_output_dir))
            {
                GFXRECON_LOG_ERROR("Error while creating directory %s: already exists as file", sub_output_dir.c_str());
                return false;
            }
        }
        else
        {
            int result = util::platform::MakeDirectory(sub_output_dir.c_str());
            if (result < 0)
            {
                GFXRECON_LOG_ERROR("Error while creating directory %s: could not open", sub_output_dir.c_str());
                return false;
            }
        }
    }

    return true;
}

void VulkanCppConsumerBase::WriteMainHeader()
{
    switch (platform_)
    {
        case GfxToCppPlatform::PLATFORM_ANDROID:
            fprintf(main_file_, "%s", sAndroidOutputDrawFunctionStart);
            break;
        case GfxToCppPlatform::PLATFORM_WIN32:
            fprintf(main_file_, "%s", sWin32OutputMainStart);
            break;
        case GfxToCppPlatform::PLATFORM_XCB:
            fprintf(main_file_, "%s", sXcbOutputMainStart);
            break;
        case GfxToCppPlatform::PLATFORM_WAYLAND:
            fprintf(main_file_, "%s", sWaylandOutputMainStart);
            break;
        default:
            GFXRECON_LOG_FATAL("Failed to write main header: Invalid platform (%d)", platform_);
            break;
    }
}

void VulkanCppConsumerBase::WriteMainFooter()
{
    switch (platform_)
    {
        case GfxToCppPlatform::PLATFORM_ANDROID:
            fprintf(main_file_, "%s", sAndroidOutputDrawFunctionEnd);
            break;
        case GfxToCppPlatform::PLATFORM_WIN32:
            fprintf(main_file_, "%s", sWin32OutputMainEnd);
            break;
        case GfxToCppPlatform::PLATFORM_XCB:
            fprintf(main_file_, "%s", sXcbOutputMainEnd);
            break;
        case GfxToCppPlatform::PLATFORM_WAYLAND:
            fprintf(main_file_, "%s", sWaylandOutputMainEnd);
            break;
        default:
            GFXRECON_LOG_FATAL("Failed to write main footer: Invalid platform (%d)", platform_);
            break;
    }
}

bool VulkanCppConsumerBase::WriteGlobalHeaderFile()
{
    FILE*       header_file = nullptr;
    std::string filename    = util::filepath::Join(out_dir_, src_out_dir_ + "/global_var.h");
    int32_t     result      = util::platform::FileOpen(&header_file, filename.c_str(), "w");
    if (result == 0)
    {
        switch (platform_)
        {
            case GfxToCppPlatform::PLATFORM_ANDROID:
                fprintf(header_file,
                        "%s%s%s%s",
                        sAndroidOutputHeadersPlatform,
                        sCommonHeaderOutputHeaders,
                        sAndroidOutputHeader,
                        sCommonOutputHeaderFunctions);
                break;
            case GfxToCppPlatform::PLATFORM_WIN32:
                fprintf(header_file,
                        "%s%s%s%s",
                        sWin32OutputHeadersPlatform,
                        sCommonHeaderOutputHeaders,
                        sWin32OutputHeader,
                        sCommonOutputHeaderFunctions);
                break;
            case GfxToCppPlatform::PLATFORM_XCB:
                fprintf(header_file,
                        "%s%s%s%s",
                        sXcbOutputHeadersPlatform,
                        sCommonHeaderOutputHeaders,
                        sXcbOutputHeader,
                        sCommonOutputHeaderFunctions);
                break;
            case GfxToCppPlatform::PLATFORM_WAYLAND:
                fprintf(header_file,
                        "%s%s%s%s",
                        sWaylandOutputHeadersPlatform,
                        sCommonHeaderOutputHeaders,
                        sWaylandOutputHeader,
                        sCommonOutputHeaderFunctions);
                break;
            default:
                GFXRECON_LOG_FATAL("Failed to write global header file: Invalid platform (%d)", platform_);
                break;
        }

        PrintToFile(header_file, "extern %s;\n", GfxToCppVariable::GenerateStringVec(variable_data_));

        PrintToFile(header_file, "%s", func_data_);

        if (needs_debug_util_callback_)
        {
            fprintf(header_file, "VkBool32 vulkanCppDebugUtilsCallback(\n");
            fprintf(header_file, "    VkDebugUtilsMessageSeverityFlagBitsEXT           messageSeverity,\n");
            fprintf(header_file, "    VkDebugUtilsMessageTypeFlagsEXT                  messageTypes,\n");
            fprintf(header_file, "    const VkDebugUtilsMessengerCallbackDataEXT*      pCallbackData,\n");
            fprintf(header_file, "    void*                                            pUserData);\n");
        }

        util::platform::FileClose(header_file);
    }
    else
    {
        fprintf(stderr, "Error while opening file: %s\n", filename.c_str());
    }
    return result;
}

void VulkanCppConsumerBase::PrintOutCMakeFile()
{
    std::string filename = util::filepath::Join(out_dir_, "CMakeLists.txt");
    FILE*       cmake_file;
    int32_t     result = util::platform::FileOpen(&cmake_file, filename.c_str(), "w");
    if (result == 0)
    {
        switch (platform_)
        {
            case GfxToCppPlatform::PLATFORM_ANDROID:
                // Nothing to do here
                break;
            case GfxToCppPlatform::PLATFORM_WIN32:
                fprintf(cmake_file, "%s", sWin32CMakeFile);
                break;
            case GfxToCppPlatform::PLATFORM_XCB:
                fprintf(cmake_file, "%s", sXcbCMakeFile);
                break;
            case GfxToCppPlatform::PLATFORM_WAYLAND:
                fprintf(cmake_file, "%s", sWaylandCMakeFile);
                break;
            default:
                GFXRECON_LOG_FATAL("Failed to print out CMake file: Unknown platform (%d)", platform_);
                break;
        }
        util::platform::FileClose(cmake_file);
    }
}

// Print the variable declarations to the 'global_var.cpp'.
void VulkanCppConsumerBase::PrintOutGlobalVar()
{
    std::string filename = util::filepath::Join(out_dir_, src_out_dir_ + "/global_var.cpp");
    int32_t     result   = util::platform::FileOpen(&global_file_, filename.c_str(), "w");
    if (result == 0)
    {
        FILE* global_file = GetGlobalFile();
        fputs(sCommonGlobalCppHeader, global_file);

        size_t max_second_dimension = 1;
        for (const auto& pd_mem_types : original_memory_types_)
        {
            if (pd_mem_types.size() > max_second_dimension)
            {
                max_second_dimension = pd_mem_types.size();
            }
        }

        fprintf(global_file,
                "VkMemoryType originalMemoryTypes[%" PRIu64 "][%" PRIu64 "] = {\n",
                util::platform::SizeTtoUint64(original_memory_types_.size()),
                util::platform::SizeTtoUint64(max_second_dimension));
        for (const auto& pd_mem_types : original_memory_types_)
        {
            fprintf(global_file, "  {\n");
            for (size_t index = 0; index < max_second_dimension; ++index)
            {
                if (index < pd_mem_types.size())
                {
                    fprintf(global_file,
                            "  { %s, %d },\n",
                            util::ToString<VkMemoryPropertyFlags>(pd_mem_types[index].property_flags).c_str(),
                            pd_mem_types[index].heap_index);
                }
                else
                {
                    fprintf(global_file, "  { 0, 0 },\n");
                }
            }
            fprintf(global_file, "  },\n");
        }
        fprintf(global_file, "};\n");

        fputs(sCommonQueryPhysicalDeviceMemoryProperties, global_file);
        fputs(sCommonRecalculateAllocationSize, global_file);
        fputs(sCommonRecalculateMemoryTypeIndex, global_file);
        fputs(sCommonLogVkError, global_file);

        switch (platform_)
        {
            case GfxToCppPlatform::PLATFORM_ANDROID:
                fputs(sAndroidOutputGlobalSource, global_file);
                break;
            case GfxToCppPlatform::PLATFORM_WIN32:
            {
                int   size = snprintf(NULL, 0, sWin32OutputOverrideMethod, window_width_, window_height_);
                char* formatted_output_override_method = new char[size + 2];
                snprintf(formatted_output_override_method,
                         size + 2,
                         sWin32OutputOverrideMethod,
                         window_width_,
                         window_height_);
                fputs(formatted_output_override_method, global_file);
                delete[] formatted_output_override_method;
                break;
            }
            case GfxToCppPlatform::PLATFORM_XCB:
            {
                int   size = snprintf(NULL, 0, sXcbOutputOverrideMethod, window_width_, window_height_);
                char* formatted_output_override_method = new char[size + 2];
                snprintf(formatted_output_override_method,
                         size + 2,
                         sXcbOutputOverrideMethod,
                         window_width_,
                         window_height_);
                fputs(formatted_output_override_method, global_file);
                delete[] formatted_output_override_method;
                break;
            }
            case GfxToCppPlatform::PLATFORM_WAYLAND:
            {
                int   size = snprintf(NULL, 0, sWaylandOutputOverrideMethod, window_width_, window_height_);
                char* formatted_output_override_method = new char[size + 2];
                snprintf(formatted_output_override_method,
                         size + 2,
                         sWaylandOutputOverrideMethod,
                         window_width_,
                         window_height_);
                fputs(formatted_output_override_method, global_file);
                delete[] formatted_output_override_method;
                break;
            }
            default:
                GFXRECON_LOG_FATAL("Failed to print out global var: Invalid platform (%d)", platform_);
                break;
        }

        PrintToFile(global_file, "%s;\n", GfxToCppVariable::GenerateStringVec(variable_data_));

        if (needs_debug_util_callback_)
        {
            fprintf(global_file, "\n");
            fprintf(global_file, "VkBool32 vulkanCppDebugUtilsCallback(\n");
            fprintf(global_file, "    VkDebugUtilsMessageSeverityFlagBitsEXT           messageSeverity,\n");
            fprintf(global_file, "    VkDebugUtilsMessageTypeFlagsEXT                  messageTypes,\n");
            fprintf(global_file, "    const VkDebugUtilsMessengerCallbackDataEXT*      pCallbackData,\n");
            fprintf(global_file, "    void*                                            pUserData)\n");
            fprintf(global_file, "{\n");
            fprintf(global_file, "    (void)messageSeverity;\n");
            fprintf(global_file, "    (void)messageTypes;\n");
            fprintf(global_file, "    (void)pCallbackData;\n");
            fprintf(global_file, "    (void)pUserData;\n");
            fprintf(global_file, "    return VK_FALSE;\n");
            fprintf(global_file, "}\n");
        }

        util::platform::FileClose(global_file_);
        global_file_ = nullptr;
    }
    else
    {
        fprintf(stderr, "Error while opening file: %s\n", filename.c_str());
    }
}

bool VulkanCppConsumerBase::WriteSwapchainFiles()
{
    FILE*       header_file     = nullptr;
    FILE*       source_file     = nullptr;
    std::string header_filename = util::filepath::Join(out_dir_, src_out_dir_ + "/swapchain_common.h");
    std::string source_filename = util::filepath::Join(out_dir_, src_out_dir_ + "/swapchain_common.cpp");

    int32_t result = util::platform::FileOpen(&header_file, header_filename.c_str(), "w");
    if (result == 0)
    {
        fputs(sCommonHeaderOutputHeaders, header_file);
        fputs(sSwapchainHeaderCode, header_file);

        if (enable_virtual_swapchain_)
        {
            fputs("\n\n// Enable the virtual swapchain code\n", header_file);
            fputs("#define USE_VIRTUAL_SWAPCHAIN 1\n", header_file);
        }
        else
        {
            fputs("\n\n// Disable the virtual swapchain code\n", header_file);
            fputs("#define USE_VIRTUAL_SWAPCHAIN 0\n", header_file);
        }

        util::platform::FileClose(header_file);

        result = util::platform::FileOpen(&source_file, source_filename.c_str(), "w");
        if (result == 0)
        {
            fputs(sSwapchainSourceCode_part_1, source_file);
            fputs(sSwapchainSourceCode_part_2, source_file);
            fputs(sSwapchainSourceCode_part_3, source_file);

            util::platform::FileClose(source_file);
        }
        else
        {
            fprintf(stderr, "Error while opening swapchain source file: %s\n", source_filename.c_str());
        }
    }
    else
    {
        fprintf(stderr, "Error while opening swapchain header file: %s\n", header_filename.c_str());
    }
    return result;
}

bool VulkanCppConsumerBase::Initialize(const std::string&      filename,
                                       const GfxToCppPlatform& platform,
                                       const std::string&      outputDir)
{
    bool success = false;

    if (main_file_ == nullptr)
    {
        int32_t result = util::platform::FileOpen(&main_file_, filename.c_str(), "w");
        if (result == 0)
        {
            filename_    = filename;
            platform_    = platform;
            out_dir_     = outputDir;
            bin_out_dir_ = "bin";
            spv_out_dir_ = "spv";
            src_out_dir_ = "src";
            success      = true;

            WriteMainHeader();
        }
    }

    if (!CreateSubOutputDirectories({ bin_out_dir_, spv_out_dir_, src_out_dir_ }))
    {
        GFXRECON_LOG_ERROR("Couldn't create sub output directories!");
        gfxrecon::util::Log::Release();
        exit(-1);
    }

    data_packer_.Initialize(out_dir_, util::filepath::Join(bin_out_dir_, "dataPack"), "bin", 40 * 1024 * 1024);
    // All spv files should be separate ones
    spv_saver_.Initialize(out_dir_, util::filepath::Join(spv_out_dir_, "shader"), "spv", 0);

    // Initialize frame 0
    frame_number_          = 0;
    frame_split_number_    = 0;
    frame_api_call_number_ = 0;
    api_call_number_       = 0;
    NewFrameFile(frame_number_, frame_split_number_);

    // Always add the following swapchain/surface functions since we have the virtual swapchain path which
    // will always attempt to use them (listed alphabetically).  This only gets the toCpp loader.h/.cpp
    // code to attempt to pre-load the functions so that they are accessible as "loaded_(func_name)"
    // functions and adds no logic forcing them to be used otherwise.
    pfn_loader_.AddMethodName("vkAcquireNextImageKHR");
    pfn_loader_.AddMethodName("vkCreateSwapchainKHR");
    pfn_loader_.AddMethodName("vkDestroySwapchainKHR");
    pfn_loader_.AddMethodName("vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
    pfn_loader_.AddMethodName("vkGetSwapchainImagesKHR");
    pfn_loader_.AddMethodName("vkQueuePresentKHR");

    return success;
}

void VulkanCppConsumerBase::Destroy()
{
    EndFrameFile(frame_number_, frame_split_number_);

    if (main_file_ != nullptr)
    {
        PrintOutGlobalVar();
        bool result = WriteGlobalHeaderFile();
        if (result == 0)
        {
            WriteMainFooter();
            util::platform::FileClose(main_file_);
            main_file_ = nullptr;
            if (platform_ != GfxToCppPlatform::PLATFORM_ANDROID)
            {
                PrintOutCMakeFile();
            }
            WriteSwapchainFiles();
        }
        pfn_loader_.WriteOutLoaderGenerator(util::filepath::Join(out_dir_, src_out_dir_), platform_);
    }
}

void VulkanCppConsumerBase::NewFrameFile(uint32_t frameNumber, uint32_t frameSplitNumber)
{
    assert(frame_file_ == nullptr);

    // Create new Frame
    std::string new_frame_dir       = gfxrecon::util::filepath::Join(out_dir_, src_out_dir_);
    std::string new_frame_filename  = GenFrameName(frameNumber, frameSplitNumber, 4);
    std::string new_frame_file_path = gfxrecon::util::filepath::Join(new_frame_dir, new_frame_filename) + ".cpp";

    int32_t result = util::platform::FileOpen(&frame_file_, new_frame_file_path.c_str(), "w");
    if (result != 0)
    {
        fprintf(stderr, "Error while opening file: %s\n", new_frame_file_path.c_str());
        exit(-1);
    }

    fprintf(frame_file_, "%s\n", sCommonFrameSourceHeader);

    std::string frameFunctionName = "void " + new_frame_filename + "()";
    fprintf(frame_file_, "%s {\n", frameFunctionName.c_str());
}

void VulkanCppConsumerBase::EndFrameFile(uint32_t frameNumber, uint32_t frameSplitNumber)
{
    assert(frame_file_ != nullptr);
    assert(main_file_ != nullptr);

    // Write out closing data for previous frame file.
    fprintf(frame_file_, "%s", sCommonFrameSourceFooter);
    util::platform::FileClose(frame_file_);
    frame_file_ = nullptr;

    // The 'struct tracking' mechanism's restricted for every frame call.
    struct_map_.clear();

    // Write out the frame call
    // TODO generate at last step
    // TODO: generate this into the main.cpp only
    std::string frameFunctionName = GenFrameName(frameNumber, frameSplitNumber, 4);
    func_data_.push_back("extern void " + frameFunctionName + "();\n");
    fprintf(main_file_, "    %s();\n", frameFunctionName.c_str());
}

void VulkanCppConsumerBase::NextFrame(bool isSplit)
{
    EndFrameFile(frame_number_, frame_split_number_);
    frame_api_call_number_ = 0;
    frame_split_temp_memory_.clear();
    if (isSplit)
    {
        frame_split_number_++;
    }
    else
    {
        frame_split_number_ = 0;
        frame_number_++;
    }
    NewFrameFile(frame_number_, frame_split_number_);
}

void VulkanCppConsumerBase::Post_APICall(format::ApiCallId callId)
{
    // Replicate FileProcessor's frame counter increment process
    if (callId == format::ApiCallId::ApiCall_vkQueuePresentKHR ||
        callId == format::ApiCallId::ApiCall_vkFrameBoundaryANDROID)
    {
        NextFrame(false);
    }
    else if (frame_api_call_number_ != 0 && (frame_api_call_number_ % max_command_limit_ == 0))
    {
        NextFrame(true);
    }

    if (callId != format::ApiCallId::ApiCall_vkAcquireNextImageKHR)
    {
        frame_api_call_number_++;
        api_call_number_++;
    }
}

void VulkanCppConsumerBase::GenerateLoadData(
    const std::string& filename, uint64_t fileOffset, const std::string& dataPtrVarName, uint64_t offset, uint64_t size)
{
    fprintf(GetFrameFile(),
            "\tLoadBinaryData(\"%s\", %" PRIu64 ", %s, %" PRIu64 ", %" PRIu64 ", appdata);\n",
            filename.c_str(),
            fileOffset,
            dataPtrVarName.c_str(),
            offset,
            size);
}

FILE* VulkanCppConsumerBase::GetFrameFile()
{
    return frame_file_;
}

std::string VulkanCppConsumerBase::GenFrameName(uint32_t frameNumber, uint32_t frameSplitNumber, uint32_t fillLength)
{
    std::stringstream frame_name_stream;
    frame_name_stream << "frame_" << std::setw(fillLength) << std::setfill('0') << frameNumber << "_"
                      << std::setw(fillLength) << std::setfill('0') << frameSplitNumber;

    return frame_name_stream.str();
}

void VulkanCppConsumerBase::AddHandles(const std::string& outputName, const format::HandleId* ptrs, uint32_t count)
{
    for (uint32_t idx = 0; idx < count; idx++)
    {
        handle_id_map_[ptrs[idx]] = outputName + "[" + std::to_string(idx) + "]";
    }
}

void VulkanCppConsumerBase::AddHandles(const std::string& outputName, const format::HandleId* ptrs)
{
    handle_id_map_[*ptrs] = outputName;
}

void VulkanCppConsumerBase::Generate_vkEnumeratePhysicalDevices(
    VkResult                                returnValue,
    format::HandleId                        instance,
    PointerDecoder<uint32_t>*               pPhysicalDeviceCount,
    HandlePointerDecoder<VkPhysicalDevice>* pPhysicalDevices)
{
    FILE* file = GetFrameFile();

    if (pPhysicalDevices->GetPointer() != nullptr)
    {
        fprintf(file, "\t{\n");
        uint32_t          recorded_count = *(pPhysicalDeviceCount->GetPointer());
        const std::string physical_device_names =
            "physicalDevices_" + std::to_string(GetNextId(VK_OBJECT_TYPE_PHYSICAL_DEVICE));

        AddKnownVariables("VkPhysicalDevice", physical_device_names, pPhysicalDevices->GetPointer(), recorded_count);
        fprintf(file, "\t\tuint32_t deviceCount = %d;\n", recorded_count);
        fprintf(file,
                "\t\tvkEnumeratePhysicalDevices(%s, &deviceCount, %s);\n",
                handle_id_map_[instance].c_str(),
                physical_device_names.c_str());

        AddHandles(physical_device_names, pPhysicalDevices->GetPointer(), recorded_count);
        fprintf(file, "\t}\n");
    }
}

void VulkanCppConsumerBase::Generate_vkCreateSwapchainKHR(
    VkResult                                                returnValue,
    format::HandleId                                        device,
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*                   pSwapchain)
{
    FILE* file = GetFrameFile();

    fprintf(file, "\t{\n");

    std::stringstream         stream_pcreate_info;
    VkSwapchainCreateInfoKHR* struct_info = pCreateInfo->GetPointer();
    if (platform_ == GfxToCppPlatform::PLATFORM_ANDROID)
    {
        struct_info->imageExtent.width  = GetProperWindowWidth(struct_info->imageExtent.width);
        struct_info->imageExtent.height = GetProperWindowHeight(struct_info->imageExtent.height);
    }
    std::string pcreate_info_struct = GenerateStruct_VkSwapchainCreateInfoKHR(
        stream_pcreate_info, struct_info, pCreateInfo->GetMetaStructPointer(), *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pswapchain_name = "pSwapchain_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SWAPCHAIN_KHR));
    AddKnownVariables("VkSwapchainKHR", pswapchain_name, pSwapchain->GetPointer());
    if (returnValue == VK_SUCCESS)
    {
        this->AddHandles(pswapchain_name, pSwapchain->GetPointer());
    }

    fprintf(file,
            "\t\tVK_CALL_CHECK(toCppCreateSwapchainKHR(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pswapchain_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::Generate_vkDestroySwapchainKHR(
    format::HandleId                                     device,
    format::HandleId                                     swapchain,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\ttoCppDestroySwapchainKHR(%s, %s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(swapchain).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::Generate_vkGetSwapchainImagesKHR(VkResult                       returnValue,
                                                             format::HandleId               device,
                                                             format::HandleId               swapchain,
                                                             PointerDecoder<uint32_t>*      pSwapchainImageCount,
                                                             HandlePointerDecoder<VkImage>* pSwapchainImages)
{
    FILE* file = GetFrameFile();

    std::string swapchain_images_var_name = "NULL";
    if (pSwapchainImages->GetPointer() == NULL)
    {
        const std::string swapchain_image_count_var_name = "pSwapchainImageCount_" + std::to_string(GetNextId());
        AddKnownVariables("uint32_t", swapchain_image_count_var_name);
        ptr_map_[pSwapchainImageCount] = swapchain_image_count_var_name;
    }
    else
    {
        swapchain_images_var_name = "pSwapchainImages_" + std::to_string(GetNextId());
        fprintf(file,
                "\t%s = new VkImage[%s];\n",
                swapchain_images_var_name.c_str(),
                ptr_map_[pSwapchainImageCount].c_str());
        AddKnownVariables("VkImage*", swapchain_images_var_name);
        if (returnValue == VK_SUCCESS)
        {
            AddHandles(swapchain_images_var_name, pSwapchainImages->GetPointer(), pSwapchainImages->GetLength());
        }
    }

    pfn_loader_.AddMethodName("vkGetSwapchainImagesKHR");

    uint32_t captured_swapchain_count = 0;
    if (pSwapchainImageCount->GetPointer() != nullptr)
    {
        captured_swapchain_count = *pSwapchainImageCount->GetPointer();
    }

    fprintf(file,
            "\tVK_CALL_CHECK(toCppGetSwapchainImagesKHR(%s, %s, %u, &%s, %s), %s);\n",
            GetHandle(device).c_str(),
            handle_id_map_[swapchain].c_str(),
            captured_swapchain_count,
            ptr_map_[pSwapchainImageCount].c_str(),
            swapchain_images_var_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
}

void VulkanCppConsumerBase::Generate_vkGetPhysicalDeviceSurfaceFormatsKHR(
    VkResult                                          returnValue,
    format::HandleId                                  physicalDevice,
    format::HandleId                                  surface,
    PointerDecoder<uint32_t>*                         pSurfaceFormatCount,
    StructPointerDecoder<Decoded_VkSurfaceFormatKHR>* pSurfaceFormats)
{
    FILE* file = GetFrameFile();

    std::string surface_formats_var_name = "NULL";
    if (pSurfaceFormats->GetPointer() == NULL)
    {
        const std::string surface_format_count_name = "pSurfaceFormatCount_" + std::to_string(GetNextId());
        fprintf(file, "\tuint32_t %s;\n", surface_format_count_name.c_str());
        ptr_map_[pSurfaceFormatCount] = surface_format_count_name;
    }
    else
    {
        surface_formats_var_name = "pSurfaceFormats_" + std::to_string(GetNextId());
        fprintf(file,
                "\tVkSurfaceFormatKHR %s[%s];\n",
                surface_formats_var_name.c_str(),
                ptr_map_[pSurfaceFormatCount].c_str());
        // TODO: connect these formats to their usages? How?
    }

    pfn_loader_.AddMethodName("vkGetPhysicalDeviceSurfaceFormatsKHR");
    fprintf(file,
            "\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceSurfaceFormatsKHR(%s, %s, &%s, %s), %s);\n",
            GetHandle(physicalDevice).c_str(),
            GetHandle(surface).c_str(),
            ptr_map_[pSurfaceFormatCount].c_str(),
            surface_formats_var_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());

    fprintf(file, "\n");
}

void VulkanCppConsumerBase::Generate_vkGetPhysicalDeviceSurfacePresentModesKHR(
    VkResult                          returnValue,
    format::HandleId                  physicalDevice,
    format::HandleId                  surface,
    PointerDecoder<uint32_t>*         pPresentModeCount,
    PointerDecoder<VkPresentModeKHR>* pPresentModes)
{
    FILE* file = GetFrameFile();

    std::string present_modes_var_name = "NULL";
    if (pPresentModes->GetPointer() == NULL)
    {
        const std::string present_mode_count_var_name = "pPresentModeCount_" + std::to_string(GetNextId());
        fprintf(file, "\tuint32_t %s;\n", present_mode_count_var_name.c_str());
        ptr_map_[pPresentModeCount] = present_mode_count_var_name;
    }
    else
    {
        present_modes_var_name = "pPresentModes_" + std::to_string(GetNextId());
        fprintf(
            file, "\tVkPresentModeKHR %s[%s];\n", present_modes_var_name.c_str(), ptr_map_[pPresentModeCount].c_str());
        // TODO: connect these formats to their usages? How?
    }

    pfn_loader_.AddMethodName("vkGetPhysicalDeviceSurfacePresentModesKHR");
    fprintf(file,
            "\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceSurfacePresentModesKHR(%s, %s, &%s, %s), %s);\n",
            GetHandle(physicalDevice).c_str(),
            GetHandle(surface).c_str(),
            ptr_map_[pPresentModeCount].c_str(),
            present_modes_var_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());

    fprintf(file, "\n");
}

void VulkanCppConsumerBase::Generate_vkGetPhysicalDeviceQueueFamilyProperties(
    format::HandleId                                       physicalDevice,
    PointerDecoder<uint32_t>*                              pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties>* pQueueFamilyProperties)
{
    FILE* file = GetFrameFile();

    std::string queue_family_props_var_name = "NULL";
    if (pQueueFamilyProperties->GetPointer() == NULL)
    {
        const std::string queue_family_props_count_var_name =
            "pQueueFamilyPropertyCount_" + std::to_string(GetNextId());
        fprintf(file, "\tuint32_t %s;\n", queue_family_props_count_var_name.c_str());
        ptr_map_[pQueueFamilyPropertyCount] = queue_family_props_count_var_name;
    }
    else
    {
        queue_family_props_var_name = "pQueueFamilyProperties_" + std::to_string(GetNextId());
        fprintf(file,
                "\tVkQueueFamilyProperties %s[%s];\n",
                queue_family_props_var_name.c_str(),
                ptr_map_[pQueueFamilyPropertyCount].c_str());
        // TODO: connect these formats to their usages? How?
    }

    fprintf(file,
            "\tvkGetPhysicalDeviceQueueFamilyProperties(%s, &%s, %s);\n",
            GetHandle(physicalDevice).c_str(),
            ptr_map_[pQueueFamilyPropertyCount].c_str(),
            queue_family_props_var_name.c_str());

    fprintf(file, "\n");
}

void VulkanCppConsumerBase::Generate_vkGetBufferMemoryRequirements(
    format::HandleId                                    device,
    format::HandleId                                    buffer,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    FILE* file = GetFrameFile();

    std::string memory_requirements_var_name =
        "pMemoryRequirements_" + std::to_string(VulkanCppConsumerBase::GetNextId());
    AddKnownVariables("VkMemoryRequirements", memory_requirements_var_name);

    fprintf(file,
            "\tvkGetBufferMemoryRequirements(%s, %s, &%s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(buffer).c_str(),
            memory_requirements_var_name.c_str());

    resource_memory_req_map_[buffer] = memory_requirements_var_name;

    fprintf(file, "\n");
}

void VulkanCppConsumerBase::Generate_vkGetImageMemoryRequirements(
    format::HandleId                                    device,
    format::HandleId                                    image,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    FILE* file = GetFrameFile();

    std::string memory_requirements_var_name =
        "pMemoryRequirements_" + std::to_string(VulkanCppConsumerBase::GetNextId());
    AddKnownVariables("VkMemoryRequirements", memory_requirements_var_name);

    fprintf(file,
            "\tvkGetImageMemoryRequirements(%s, %s, &%s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(image).c_str(),
            memory_requirements_var_name.c_str());

    resource_memory_req_map_[image] = memory_requirements_var_name;

    fprintf(file, "\n");
}

void VulkanCppConsumerBase::Generate_vkGetBufferMemoryRequirements2(
    format::HandleId                                               device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>*           pMemoryRequirements,
    const char*                                                    extension)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    // device
    // pInfo
    std::stringstream stream_info;
    std::string       info_struct_name = GenerateStruct_VkBufferMemoryRequirementsInfo2(
        stream_info, pInfo->GetPointer(), pInfo->GetMetaStructPointer(), *this);
    fprintf(file, "%s", stream_info.str().c_str());
    // pMemoryRequirements
    std::string       memory_requirements_var_name = "pMemoryRequirements_" + std::to_string(this->GetNextId());
    std::stringstream stream_memory_requirements;
    memory_requirements_var_name = GenerateStruct_VkMemoryRequirements2(stream_memory_requirements,
                                                                        pMemoryRequirements->GetPointer(),
                                                                        pMemoryRequirements->GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "%s", stream_memory_requirements.str().c_str());
    AddKnownVariables("VkMemoryRequirements2", memory_requirements_var_name);

    std::string method_name = "vkGetBufferMemoryRequirements2";
    method_name += extension;
    pfn_loader_.AddMethodName(method_name);

    fprintf(file,
            "\t\tloaded_%s(%s, &%s, &%s);\n",
            method_name.c_str(),
            this->GetHandle(device).c_str(),
            info_struct_name.c_str(),
            memory_requirements_var_name.c_str());
    fprintf(file, "\t}\n");
    resource_memory_req_map_[pInfo->GetMetaStructPointer()->buffer] = memory_requirements_var_name;
}

void VulkanCppConsumerBase::Generate_vkGetBufferMemoryRequirements2KHR(
    format::HandleId                                               device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>*           pMemoryRequirements)
{
    return Generate_vkGetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements, "KHR");
}

void VulkanCppConsumerBase::Generate_vkGetImageMemoryRequirements2(
    format::HandleId                                              device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>*          pMemoryRequirements,
    const char*                                                   extension)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    // device
    // pInfo
    std::stringstream stream_info;
    std::string       info_struct_name = GenerateStruct_VkImageMemoryRequirementsInfo2(
        stream_info, pInfo->GetPointer(), pInfo->GetMetaStructPointer(), *this);
    fprintf(file, "%s", stream_info.str().c_str());
    // pMemoryRequirements
    std::string       memory_requirements_var_name = "pMemoryRequirements_" + std::to_string(this->GetNextId());
    std::stringstream stream_memory_requirements;
    memory_requirements_var_name = GenerateStruct_VkMemoryRequirements2(stream_memory_requirements,
                                                                        pMemoryRequirements->GetPointer(),
                                                                        pMemoryRequirements->GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "%s", stream_memory_requirements.str().c_str());
    AddKnownVariables("VkMemoryRequirements2", memory_requirements_var_name);

    std::string method_name = "vkGetImageMemoryRequirements2";
    method_name += extension;
    pfn_loader_.AddMethodName(method_name);

    fprintf(file,
            "\t\tloaded_%s(%s, &%s, &%s);\n",
            method_name.c_str(),
            this->GetHandle(device).c_str(),
            info_struct_name.c_str(),
            memory_requirements_var_name.c_str());
    fprintf(file, "\t}\n");
    resource_memory_req_map_[pInfo->GetMetaStructPointer()->image] = memory_requirements_var_name;
}

void VulkanCppConsumerBase::Generate_vkGetImageMemoryRequirements2KHR(
    format::HandleId                                              device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>*          pMemoryRequirements)
{
    return Generate_vkGetImageMemoryRequirements2(device, pInfo, pMemoryRequirements, "KHR");
}

void VulkanCppConsumerBase::Generate_vkGetImageSparseMemoryRequirements(
    format::HandleId                                               device,
    format::HandleId                                               image,
    PointerDecoder<uint32_t>*                                      pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements>* pSparseMemoryRequirements)
{
    FILE* file = GetFrameFile();

    std::string spare_memory_reqs_count_var_name =
        "pSparseMemoryRequirementCount_" + std::to_string(VulkanCppConsumerBase::GetNextId());
    fprintf(file, "\tuint32_t %s;\n", spare_memory_reqs_count_var_name.c_str());

    std::string sparse_mem_reqs_var_name =
        "pSparseMemoryRequirements_" + std::to_string(VulkanCppConsumerBase::GetNextId());
    const uint32_t* in_pSparseMemoryRequirementCount = pSparseMemoryRequirementCount->GetPointer();

    AddKnownVariables("VkSparseImageMemoryRequirements", sparse_mem_reqs_var_name, *in_pSparseMemoryRequirementCount);
    fprintf(file,
            "\tvkGetImageSparseMemoryRequirements(%s, %s, &%s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(image).c_str(),
            spare_memory_reqs_count_var_name.c_str(),
            sparse_mem_reqs_var_name.c_str());

    resource_memory_req_map_[image] = sparse_mem_reqs_var_name;
}

void VulkanCppConsumerBase::Generate_vkGetFenceStatus(VkResult         returnValue,
                                                      format::HandleId device,
                                                      format::HandleId fence)
{
    if (returnValue == VK_SUCCESS)
    {
        fprintf(GetFrameFile(),
                "\twhile (vkGetFenceStatus(%s, %s) != VK_SUCCESS) { usleep(5000); }\n",
                this->GetHandle(device).c_str(),
                this->GetHandle(fence).c_str());
    }
    else
    {
        fprintf(GetFrameFile(),
                "\tVK_CALL_CHECK(vkGetFenceStatus(%s, %s), %s);\n",
                this->GetHandle(device).c_str(),
                this->GetHandle(fence).c_str(),
                util::ToString<VkResult>(returnValue).c_str());
    }
}

void VulkanCppConsumerBase::Generate_vkMapMemory(VkResult                         returnValue,
                                                 format::HandleId                 device,
                                                 format::HandleId                 memory,
                                                 VkDeviceSize                     offset,
                                                 VkDeviceSize                     size,
                                                 VkMemoryMapFlags                 flags,
                                                 PointerDecoder<uint64_t, void*>* ppData)
{
    std::string data_var_name = "ppData_" + std::to_string(GetNextId());
    AddKnownVariables("void*", data_var_name);

    fprintf(GetFrameFile(),
            "\tVK_CALL_CHECK(vkMapMemory(%s, %s, %" PRIu64 "UL, %" PRIu64 "UL, %s, &%s), %s);\n",
            handle_id_map_[device].c_str(),
            handle_id_map_[memory].c_str(),
            offset,
            size,
            util::ToString<VkMemoryMapFlags>(flags).c_str(),
            data_var_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());

    memory_id_map_[(uint64_t)memory] = data_var_name;
}

void VulkanCppConsumerBase::Generate_vkUnmapMemory(format::HandleId device, format::HandleId memory)
{
    fprintf(
        GetFrameFile(), "\tvkUnmapMemory(%s, %s);\n", handle_id_map_[device].c_str(), handle_id_map_[memory].c_str());

    memory_id_map_[(uint64_t)memory] = "<<INVALID>>";
}

void VulkanCppConsumerBase::Generate_vkAllocateMemory(VkResult                                            returnValue,
                                                      format::HandleId                                    device,
                                                      StructPointerDecoder<Decoded_VkMemoryAllocateInfo>* pAllocateInfo,
                                                      StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                                      HandlePointerDecoder<VkDeviceMemory>*                pMemory)
{
    FILE* file = GetFrameFile();

    fprintf(file, "\t{\n");

    // Check to see if we need to worry about opaque memory here.
    VkDeviceInfo* dev_info = nullptr;
    if (device_info_map_.find(device) != device_info_map_.end())
    {
        dev_info                       = device_info_map_[device];
        format::HandleId memory_handle = *pMemory->GetPointer();

        // If we don't have this memory handle in the opaque address list, set it back to NULL since we
        // won't be using it here.
        if (dev_info->opaque_addresses.find(memory_handle) == dev_info->opaque_addresses.end())
        {
            dev_info = nullptr;
        }
        else
        {
            // Create a opaque memory struct for use in the pNext chain in case we need it.
            // and set all the appropriate variables that can be used to track if it is needed.
            // This way the various pNext structures can just use these variables to determine
            // the appropriate action.
            fprintf(file, "\t\tVkMemoryOpaqueCaptureAddressAllocateInfo address_info = {\n");
            fprintf(file, "\t\t\tVK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO,\n");
            fprintf(file, "\t\t};\n");
            fprintf(file, "\n");

            fprintf(file, "\t\tbool     can_use_opaque_address = false;\n");
            fprintf(file, "\t\tbool     uses_opaque_address    = false;\n");
            fprintf(file, "\t\tbool     imports_memory         = false;\n");
            fprintf(file, "\n");
            fprintf(file, "\t\tif (g_device_info.find(%s) != g_device_info.end()){\n", this->GetHandle(device).c_str());
            fprintf(file, "\t\t\tToCppDeviceInfo* dev_info = g_device_info[%s];\n", this->GetHandle(device).c_str());
            fprintf(file, "\t\t\tif (dev_info->features.features_dev_buf_addr.bufferDeviceAddressCaptureReplay ||\n");
            fprintf(file, "\t\t\t    dev_info->features.features_1_2.bufferDeviceAddressCaptureReplay) {\n");
            fprintf(file, "\t\t\t\tcan_use_opaque_address = true;\n");
            fprintf(file,
                    "\t\t\t\taddress_info.opaque_address = %" PRIu64 "ULL;\n",
                    dev_info->opaque_addresses[memory_handle]);
            fprintf(file, "\t\t\t}\n");
            fprintf(file, "\n");
        }
    }

    std::stringstream stream_alloc_info;
    std::string       alloc_info_struct_var_name = GenerateStruct_VkMemoryAllocateInfo(stream_alloc_info,
                                                                                 *pMemory->GetPointer(),
                                                                                 pAllocateInfo->GetPointer(),
                                                                                 pAllocateInfo->GetMetaStructPointer(),
                                                                                 *this);
    fprintf(file, "%s", stream_alloc_info.str().c_str());
    std::string memory_var_name = "pMemory_" + std::to_string(this->GetNextId());
    AddKnownVariables("VkDeviceMemory", memory_var_name, pMemory->GetPointer());
    if (returnValue == VK_SUCCESS)
    {
        this->AddHandles(memory_var_name, pMemory->GetPointer());
    }

    // Now that the pNext items are done, perform any work that needs to be done last and update
    // the vkMemoryAllocationInfo pNext array to start with our custom one.
    if (dev_info != nullptr)
    {
        fprintf(file, "\t\tif (uses_opaque_address) {\n");
        fprintf(file, "\t\t\tif (imports_memory) {\n");
        fprintf(file,
                "\t\t\t\t// The Vulkan spec states: If the pNext chain includes a VkImportMemoryHostPointerInfoEXT\n");
        fprintf(file,
                "\t\t\t\t// structure, VkMemoryOpaqueCaptureAddressAllocateInfo::opaqueCaptureAddress must be zer\n");
        fprintf(file, "\t\t\t\taddress_info.opaque_address = 0;\n");
        fprintf(file, "\t\t\t}\n");
        fprintf(file, "\t\t\taddress_info.pNext = %s.pNext;\n", alloc_info_struct_var_name.c_str());
        fprintf(file, "\t\t\t%s.pNext = &address_info;\n", alloc_info_struct_var_name.c_str());
        fprintf(file, "\t\t}\n");
    }

    fprintf(file,
            "\t\tVK_CALL_CHECK(vkAllocateMemory(%s, &%s, %s, &%s), %s);\n",
            GetHandle(device).c_str(),
            alloc_info_struct_var_name.c_str(),
            "nullptr",
            memory_var_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::Generate_vkCreateBuffer(VkResult                                             returnValue,
                                                    format::HandleId                                     device,
                                                    StructPointerDecoder<Decoded_VkBufferCreateInfo>*    pCreateInfo,
                                                    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                                    HandlePointerDecoder<VkBuffer>*                      pBuffer)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");

    VkDeviceInfo*    dev_info      = nullptr;
    format::HandleId buffer_handle = *pBuffer->GetPointer();
    if (device_info_map_.find(device) != device_info_map_.end())
    {
        dev_info = device_info_map_[device];
        if (dev_info != nullptr)
        {
            // Determine if this buffer uses an opaque address, if so, we need to search through the
            // buffer usage and set additional flags as necessary and record the appropriate address.
            if (dev_info->opaque_addresses.find(buffer_handle) != dev_info->opaque_addresses.end())
            {
                // This is only used in certain cases, but it needs to be scoped locally to this function for it to be
                // valid
                fprintf(file, "\t\tVkBufferOpaqueCaptureAddressCreateInfo address_info = {\n");
                fprintf(file, "\t\t\tVK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO\n");
                fprintf(file, "\t\t};\n");
                fprintf(file, "\n");
            }
            else
            {
                // Nothing to do here.
                dev_info = nullptr;
            }
        }
    }

    std::stringstream stream_pcreate_info;
    std::string       pcreate_info_struct = GenerateStruct_VkBufferCreateInfo(
        stream_pcreate_info, pCreateInfo->GetPointer(), pCreateInfo->GetMetaStructPointer(), *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pbuffer_name = "pBuffer_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_BUFFER));

    if (dev_info != nullptr)
    {
        fprintf(file, "\t\tif (g_device_info.find(%s) != g_device_info.end()){\n", this->GetHandle(device).c_str());
        fprintf(file, "\t\t\tToCppDeviceInfo* dev_info = g_device_info[%s];\n", this->GetHandle(device).c_str());
        fprintf(file, "\t\t\tif (dev_info->features.features_dev_buf_addr.bufferDeviceAddressCaptureReplay ||\n");
        fprintf(file, "\t\t\t    dev_info->features.features_1_2.bufferDeviceAddressCaptureReplay) {\n");
        fprintf(file, "\t\t\t\tbool                uses_address         = false;\n");
        fprintf(file, "\t\t\t\tVkBufferCreateFlags address_create_flags = 0;\n");
        fprintf(file, "\t\t\t\tVkBufferUsageFlags  address_usage_flags  = 0;\n");
        fprintf(file, "\n");
        fprintf(file,
                "\t\t\t\tif ((%s->usage & VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT) ==\n",
                pcreate_info_struct.c_str());
        fprintf(file, "\t\t\t\t    VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT)\n");
        fprintf(file, "\t\t\t\t{\n");
        fprintf(file, "\t\t\t\t    uses_address = true;\n");
        fprintf(file, "\t\t\t\t    address_create_flags |= VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT;\n");
        fprintf(file, "\t\t\t\t}\n");
        fprintf(file,
                "\t\t\t\tif ((%s->usage & VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR) ==\n",
                pcreate_info_struct.c_str());
        fprintf(file, "\t\t\t\t    VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR)\n");
        fprintf(file, "\t\t\t\t{\n");
        fprintf(file, "\t\t\t\t    uses_address = true;\n");
        fprintf(file, "\t\t\t\t    address_create_flags |= VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT;\n");
        fprintf(file, "\t\t\t\t    address_usage_flags |= VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT;\n");
        fprintf(file, "\t\t\t\t}\n");
        fprintf(file, "\n");

        fprintf(file, "\t\t\t\tif (uses_address)\n");
        fprintf(file, "\t\t\t\t{\n");
        fprintf(file,
                "\t\t\t\t\taddress_info.opaqueCaptureAddress = %" PRIu64 "LLU;\n",
                dev_info->opaque_addresses[buffer_handle]);
        fprintf(file, "\n");
        fprintf(file,
                "\t\t\t\t\t// The shallow copy of VkBufferCreateInfo references the same pNext list from the "
                "copy source.  We insert\n");
        fprintf(file,
                "\t\t\t\t\t// the buffer address extension struct at the start of the list to avoid modifying "
                "the original by appending\n");
        fprintf(file, "\t\t\t\t\t// to the end.\n");
        fprintf(file, "\t\tt\t\taddress_info.pNext = %s.pNext;\n", this->GetHandle(device).c_str());
        fprintf(file, "\t\t\t\t\t%s.pNext = &address_info;\n", this->GetHandle(device).c_str());
        fprintf(file, "\n");
        fprintf(file, "\t\t\t\t\t%s.flags |= address_create_flags;\n", this->GetHandle(device).c_str());
        fprintf(file, "\t\t\t\t\t%s.usage |= address_usage_flags;\n", this->GetHandle(device).c_str());
        fprintf(file, "\t\t\t\t}\n");
        fprintf(file, "\t\t\t}\n");
        fprintf(file, "\t\t}\n");
    }

    AddKnownVariables("VkBuffer", pbuffer_name, pBuffer->GetPointer());
    if (returnValue == VK_SUCCESS)
    {
        this->AddHandles(pbuffer_name, pBuffer->GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateBuffer(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pbuffer_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::Generate_vkGetQueryPoolResults(VkResult                 returnValue,
                                                           format::HandleId         device,
                                                           format::HandleId         queryPool,
                                                           uint32_t                 firstQuery,
                                                           uint32_t                 queryCount,
                                                           size_t                   dataSize,
                                                           PointerDecoder<uint8_t>* pData,
                                                           VkDeviceSize             stride,
                                                           VkQueryResultFlags       flags)
{
    FILE* file = GetFrameFile();

    // Try to re-use a temporary memory storage big enough to store this.
    std::string temp_memory_name;
    for (auto& temp_memory : frame_split_temp_memory_)
    {
        if (temp_memory.size >= dataSize)
        {
            temp_memory_name = temp_memory.name;
            break;
        }
    }
    if (temp_memory_name.size() == 0)
    {
        FrameTempMemory temp_memory;
        temp_memory.name = "pData_" + std::to_string(this->GetNextId());
        temp_memory.size = dataSize;
        frame_split_temp_memory_.push_back(temp_memory);
        temp_memory_name = temp_memory.name;

        fprintf(
            file, "\tuint8_t %s[%" PRIu64 "];\n", temp_memory_name.c_str(), util::platform::SizeTtoUint64(dataSize));
    }

    if (returnValue == VK_SUCCESS)
    {
        fprintf(file,
                "\twhile (vkGetQueryPoolResults(%s, %s, %u, %u, %" PRIu64 "UL, %s, %" PRIu64
                "UL, %s) != VK_SUCCESS) { usleep(5000); }\n",
                GetHandle(device).c_str(),
                GetHandle(queryPool).c_str(),
                firstQuery,
                queryCount,
                util::platform::SizeTtoUint64(dataSize),
                temp_memory_name.c_str(),
                stride,
                util::ToString<VkQueryResultFlags>(flags).c_str());
    }
    else
    {
        fprintf(file,
                "\tVK_CALL_CHECK(vkGetQueryPoolResults(%s, %s, %u, %u, %" PRIu64 "UL, %s, %" PRIu64 "UL, %s), %s);\n",
                GetHandle(device).c_str(),
                GetHandle(queryPool).c_str(),
                firstQuery,
                queryCount,
                util::platform::SizeTtoUint64(dataSize),
                temp_memory_name.c_str(),
                stride,
                util::ToString<VkQueryResultFlags>(flags).c_str(),
                util::ToString<VkResult>(returnValue).c_str());
    }
}

static std::vector<std::string> FilterLayers(const char* const* layerArray, const uint32_t layerArrayLength)
{
    std::vector<std::string> enabled_layers;
    if (layerArrayLength == 0)
    {
        return enabled_layers;
    }

    const std::vector<std::string> layer_black_list = {
        GFXRECON_PROJECT_VULKAN_LAYER_NAME,
        "VK_LAYER_LUNARG_device_simulation",
    };

    for (uint32_t idx = 0; idx < layerArrayLength; ++idx)
    {
        bool isBlacklisted = std::any_of(layer_black_list.begin(),
                                         layer_black_list.end(),
                                         [&](const std::string& name) { return name == layerArray[idx]; });
        if (!isBlacklisted)
        {
            enabled_layers.emplace_back(layerArray[idx]);
        }
    }

    return enabled_layers;
}

static std::vector<std::string> ReplaceExtensions(const char* const*                        extensionArray,
                                                  const uint32_t                            extensionArrayLength,
                                                  const std::map<std::string, std::string>& remapInfo)
{
    std::vector<std::string> enabled_extensions;
    enabled_extensions.reserve(extensionArrayLength);

    for (uint32_t idx = 0; idx < extensionArrayLength; ++idx)
    {
        std::string extension_name(extensionArray[idx]);

        const auto& it = remapInfo.find(extension_name);
        if (it != remapInfo.end())
        {
            extension_name = it->second;
        }
        enabled_extensions.emplace_back(extension_name);
    }

    return enabled_extensions;
}

static void BuildInstanceCreateInfo(std::ostream&                       out,
                                    const VkInstanceCreateInfo*         struct_info,
                                    const Decoded_VkInstanceCreateInfo* metaInfo,
                                    const std::string&                  var_name,
                                    VulkanCppConsumerBase&              consumer)
{
    // Collect enabled layer names except the GFXReconstruct's own layer.
    const std::vector<std::string> layerNames =
        FilterLayers(struct_info->ppEnabledLayerNames, struct_info->enabledLayerCount);

    std::string next_name                = GenerateExtension(out, struct_info->pNext, metaInfo->pNext, consumer);
    std::string app_info_struct_var_name = "NULL";
    if (struct_info->pApplicationInfo != NULL)
    {
        app_info_struct_var_name =
            "&" + GenerateStruct_VkApplicationInfo(
                      out, struct_info->pApplicationInfo, metaInfo->pApplicationInfo->GetMetaStructPointer(), consumer);
    }

    // Print out enabled layers if there is any
    std::string enabled_layers_value = "NULL";
    if (layerNames.size() > 0)
    {
        enabled_layers_value = "ppEnabledLayerNames_" + std::to_string(consumer.GetNextId());
        out << "\t\tconst char* " << enabled_layers_value
            << "[] = " << VulkanCppConsumerBase::EscapeStringArray(layerNames) << ";" << std::endl;
    }

    std::vector<std::string> extension_names;
    std::string              enabled_extensions_names = "NULL";
    if (struct_info->enabledExtensionCount > 0)
    {
        GfxToCppPlatform cur_platform       = consumer.GetPlatform();
        std::string      cur_extension_name = kTargetPlatforms.at(cur_platform).wsiSurfaceExtName;

        // Generate a map of WSI extensions to the new extension for this current platform
        std::map<std::string, std::string> replace_map;
        for (const auto& [platform_enum, info] : kTargetPlatforms)
        {
            replace_map[info.wsiSurfaceExtName] = cur_extension_name;
        }

        extension_names =
            ReplaceExtensions(struct_info->ppEnabledExtensionNames, struct_info->enabledExtensionCount, replace_map);

        enabled_extensions_names = "ppEnabledExtensionNames_" + std::to_string(consumer.GetNextId());
        out << "\t\tconst char* " << enabled_extensions_names
            << "[] = " << VulkanCppConsumerBase::EscapeStringArray(extension_names) << ";" << std::endl;
    }

    out << "\t\tVkInstanceCreateInfo " << var_name << " = {" << std::endl;
    out << "\t\t" << util::ToString<VkStructureType>(struct_info->sType) << ", // sType" << std::endl;
    out << "\t\t" << next_name << ", // pNext" << std::endl;
    out << "\t\t" << util::ToString<VkInstanceCreateFlags>(struct_info->flags) << ", // flags" << std::endl;
    out << "\t\t" << app_info_struct_var_name << ", // pApplicationInfo" << std::endl;
    out << "\t\t" << layerNames.size() << ", // enabledLayerCount" << std::endl;
    out << "\t\t" << enabled_layers_value << ", // ppEnabledLayerNames" << std::endl;
    out << "\t\t" << extension_names.size() << ", // enabledExtensionCount" << std::endl;
    out << "\t\t" << enabled_extensions_names << " // ppEnabledExtensionNames" << std::endl;
    out << "\t\t};" << std::endl;

    std::string vkInstanceCreateInfoVar = "VkInstanceCreateInfo " + var_name + ";\n";
}

void VulkanCppConsumerBase::Generate_vkCreateInstance(VkResult                                             returnValue,
                                                      StructPointerDecoder<Decoded_VkInstanceCreateInfo>*  pCreateInfo,
                                                      StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                                      HandlePointerDecoder<VkInstance>*                    pInstance)
{
    FILE* file = GetFrameFile();

    std::string       create_info_struct_var_name = "pCreateInfo_" + std::to_string(GetNextId());
    std::stringstream stream_instance_create_info;
    BuildInstanceCreateInfo(stream_instance_create_info,
                            pCreateInfo->GetPointer(),
                            pCreateInfo->GetMetaStructPointer(),
                            create_info_struct_var_name,
                            *this);

    std::string instance_var_name = "instance_" + std::to_string(GetNextId(VK_OBJECT_TYPE_INSTANCE));
    AddKnownVariables("VkInstance", instance_var_name);

    fprintf(file, "\t{\n");
    fprintf(file, "%s", stream_instance_create_info.str().c_str());
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateInstance(&%s, %s, &%s), %s);\n",
            create_info_struct_var_name.c_str(),
            "nullptr",
            instance_var_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());

    fprintf(file, "\t\tloadFunctions(%s);\n", instance_var_name.c_str());
    fprintf(file, "\t}\n");

    if (returnValue == VK_SUCCESS)
    {
        AddHandles(instance_var_name, pInstance->GetPointer());
    }
}

void VulkanCppConsumerBase::Generate_vkCreateDevice(VkResult                                             returnValue,
                                                    format::HandleId                                     physicalDevice,
                                                    StructPointerDecoder<Decoded_VkDeviceCreateInfo>*    pCreateInfo,
                                                    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                                    HandlePointerDecoder<VkDevice>*                      pDevice)
{
    FILE* file = GetFrameFile();

    VkDeviceInfo* new_dev_info               = new VkDeviceInfo();
    new_dev_info->parent                     = physicalDevice;
    device_info_map_[*pDevice->GetPointer()] = new_dev_info;

    fprintf(file, "\t{\n");
    fprintf(file, "\t\tQueryPhysicalDeviceMemoryProperties(%s);\n", this->GetHandle(physicalDevice).c_str());
    // physicalDevice
    // pCreateInfo
    std::stringstream stream_pcreate_info;
    std::string       pcreate_info_struct = GenerateStruct_VkDeviceCreateInfo(
        stream_pcreate_info, pCreateInfo->GetPointer(), pCreateInfo->GetMetaStructPointer(), *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    // pAllocator
    // pDevice
    std::string pdevice_name = "pDevice_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_DEVICE));
    AddKnownVariables("VkDevice", pdevice_name, pDevice->GetPointer());
    if (returnValue == VK_SUCCESS)
    {
        this->AddHandles(pdevice_name, pDevice->GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateDevice(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(physicalDevice).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pdevice_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());

    fprintf(file, "\n");
    fprintf(file,
            "\t\tif (!toCppInitDeviceInfo(%s, %s, &%s)) {\n",
            this->GetHandle(physicalDevice).c_str(),
            pdevice_name.c_str(),
            pcreate_info_struct.c_str());
    fprintf(
        file,
        "\t\t\tprintf(\"ERROR: Failed to generate device info for device %s created from physical device %s\\n\");\n",
        pdevice_name.c_str(),
        this->GetHandle(physicalDevice).c_str());
    fprintf(file, "\t\t}\n");

    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::Generate_vkDestroyDevice(format::HandleId                                     device,
                                                     StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    FILE* file = GetFrameFile();

    if (device_info_map_.find(device) != device_info_map_.end())
    {
        VkDeviceInfo* dev_info = device_info_map_[device];
        delete dev_info;
        device_info_map_.erase(device);
    }

    fprintf(file, "\t{\n");
    fprintf(file, "\t\ttoCppDestroyDeviceInfo(%s);\n", this->GetHandle(device).c_str());
    fprintf(file, "\n");
    fprintf(file, "\t\tvkDestroyDevice(%s, %s);\n", this->GetHandle(device).c_str(), "nullptr");
    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::Generate_vkCreateShaderModule(
    VkResult                                                returnValue,
    format::HandleId                                        device,
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
    HandlePointerDecoder<VkShaderModule>*                   pShaderModule)
{
    FILE* file = GetFrameFile();

    const VkShaderModuleCreateInfo* struct_info = pCreateInfo->GetPointer();

    // emit spirv data load.
    std::string         code_var_name = "pCode_" + std::to_string(VulkanCppConsumerBase::GetNextId());
    const SavedFileInfo file_info =
        spv_saver_.AddFileContents((const uint8_t*)struct_info->pCode, struct_info->codeSize);

    fprintf(file, "\t{\n");

    fprintf(file, "\t\tuint8_t *%s = new uint8_t[%zu];\n\t", code_var_name.c_str(), struct_info->codeSize);
    GenerateLoadData(file_info.file_path, file_info.byte_offset, code_var_name, 0, struct_info->codeSize);

    std::string create_info_struct_name = "pCreateInfo_" + std::to_string(VulkanCppConsumerBase::GetNextId());

    std::stringstream out_struct;
    out_struct << "\t\tVkShaderModuleCreateInfo " << create_info_struct_name << " = {" << std::endl;
    out_struct << "\t\t" << util::ToString<VkStructureType>(struct_info->sType) << ", // sType" << std::endl;
    out_struct << "\t\t" << struct_info->pNext << ", // pNext" << std::endl;
    out_struct << "\t\t" << util::ToString<VkShaderModuleCreateFlags>(struct_info->flags) << ", // flags" << std::endl;
    out_struct << "\t\t" << struct_info->codeSize << ", // codeSize" << std::endl;
    out_struct << "\t\t(const uint32_t*)" << code_var_name << " // pCode" << std::endl;
    out_struct << "\t\t};" << std::endl;
    fprintf(file, "%s", out_struct.str().c_str());

    std::string shader_module_name = "pShaderModule_" + std::to_string(VulkanCppConsumerBase::GetNextId());
    AddKnownVariables("VkShaderModule", shader_module_name, pShaderModule->GetPointer());

    if (returnValue == VK_SUCCESS)
    {
        AddHandles(shader_module_name, pShaderModule->GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateShaderModule(%s, &%s, %s, &%s), %s);\n",
            GetHandle(device).c_str(),
            create_info_struct_name.c_str(),
            "nullptr",
            shader_module_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());

    // emit delete the allocated spv data.
    fprintf(file, "\t\tdelete [] %s;\n\n", code_var_name.c_str());
    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::Generate_vkCreatePipelineCache(
    VkResult                                                 returnValue,
    format::HandleId                                         device,
    StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*     pAllocator,
    HandlePointerDecoder<VkPipelineCache>*                   pPipelineCache)
{
    FILE* file = GetFrameFile();

    const VkPipelineCacheCreateInfo* struct_info = pCreateInfo->GetPointer();

    fprintf(file, "\t{\n");
    std::string       create_info_struct_var_name = "pCreateInfo_" + std::to_string(VulkanCppConsumerBase::GetNextId());
    std::stringstream stream_create_info;

    stream_create_info << "\t\tVkPipelineCacheCreateInfo " << create_info_struct_var_name << " {" << std::endl;
    stream_create_info << "\t\t" << util::ToString<VkStructureType>(struct_info->sType) << ", // sType" << std::endl;
    stream_create_info << "\t\t" << struct_info->pNext << ", // pNext" << std::endl;
    stream_create_info << "\t\t" << util::ToString<VkPipelineCacheCreateFlags>(struct_info->flags) << ", // flags"
                       << std::endl;
    stream_create_info << "\t\t0, // initialDataSize" << std::endl;
    stream_create_info << "\t\tNULL // pInitialData" << std::endl;
    stream_create_info << "\t\t};" << std::endl;
    fprintf(file, "\n%s", stream_create_info.str().c_str());

    std::string pipeline_cache_var_name = "pPipelineCache_" + std::to_string(VulkanCppConsumerBase::GetNextId());
    AddKnownVariables("VkPipelineCache", pipeline_cache_var_name);

    if (returnValue == VK_SUCCESS)
    {
        AddHandles(pipeline_cache_var_name, pPipelineCache->GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreatePipelineCache(%s, &%s, %s, &%s), %s);\n",
            GetHandle(device).c_str(),
            create_info_struct_var_name.c_str(),
            "nullptr",
            pipeline_cache_var_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::Generate_vkCreateAndroidSurfaceKHR(
    VkResult                                                     returnValue,
    format::HandleId                                             instance,
    StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                          pSurface)
{
    GenerateSurfaceCreation(platform_, returnValue, instance, (void*)pCreateInfo, pSurface->GetPointer());
}

void VulkanCppConsumerBase::Generate_vkCreateMetalSurfaceEXT(
    VkResult                                                   returnValue,
    format::HandleId                                           instance,
    StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*       pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                        pSurface)
{
    GenerateSurfaceCreation(platform_, returnValue, instance, (void*)pCreateInfo, pSurface->GetPointer());
}

void VulkanCppConsumerBase::Generate_vkCreateWaylandSurfaceKHR(
    VkResult                                                     returnValue,
    format::HandleId                                             instance,
    StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                          pSurface)
{
    GenerateSurfaceCreation(platform_, returnValue, instance, (void*)pCreateInfo, pSurface->GetPointer());
}

void VulkanCppConsumerBase::Generate_vkCreateWin32SurfaceKHR(
    VkResult                                                   returnValue,
    format::HandleId                                           instance,
    StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*       pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                        pSurface)
{
    GenerateSurfaceCreation(platform_, returnValue, instance, (void*)pCreateInfo, pSurface->GetPointer());
}

void VulkanCppConsumerBase::Generate_vkCreateXcbSurfaceKHR(
    VkResult                                                 returnValue,
    format::HandleId                                         instance,
    StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*     pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                      pSurface)
{
    GenerateSurfaceCreation(platform_, returnValue, instance, (void*)pCreateInfo, pSurface->GetPointer());
}

void VulkanCppConsumerBase::Generate_vkCreateXlibSurfaceKHR(
    VkResult                                                  returnValue,
    format::HandleId                                          instance,
    StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*      pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                       pSurface)
{
    GenerateSurfaceCreation(platform_, returnValue, instance, (void*)pCreateInfo, pSurface->GetPointer());
}

void VulkanCppConsumerBase::GenerateSurfaceCreation(GfxToCppPlatform        platform,
                                                    VkResult                returnValue,
                                                    format::HandleId        instance,
                                                    void*                   pSurfaceCreateInfo,
                                                    const format::HandleId* pSurface)
{
    FILE* file = GetFrameFile();

    std::stringstream stream_create_info;
    std::string       surface_var_name            = "pSurface_" + std::to_string(GetNextId());
    std::string       create_info_struct_var_name = "";
    std::string       surface_create_func_call    = "";

    fprintf(file, "\t{\n");

    switch (platform_)
    {
        case GfxToCppPlatform::PLATFORM_ANDROID:
        {
            VkAndroidSurfaceCreateInfoKHR         android_struct_info  = {};
            Decoded_VkAndroidSurfaceCreateInfoKHR decoded_android_info = {};

            if (platform_ == platform)
            {
                android_struct_info =
                    *reinterpret_cast<StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>*>(pSurfaceCreateInfo)
                         ->GetPointer();
            }
            android_struct_info.sType   = VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR;
            create_info_struct_var_name = GenerateStruct_VkAndroidSurfaceCreateInfoKHR(
                stream_create_info, &android_struct_info, &decoded_android_info, *this);
            surface_create_func_call = "vkCreateAndroidSurfaceKHR";
            break;
        }
        case GfxToCppPlatform::PLATFORM_WIN32:
        {
            VkWin32SurfaceCreateInfoKHR         win32_struct_info  = {};
            Decoded_VkWin32SurfaceCreateInfoKHR decoded_win32_info = {};

            if (platform_ == platform)
            {
                win32_struct_info =
                    *reinterpret_cast<StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>*>(pSurfaceCreateInfo)
                         ->GetPointer();
            }
            win32_struct_info.sType     = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
            create_info_struct_var_name = GenerateStruct_VkWin32SurfaceCreateInfoKHR(
                stream_create_info, &win32_struct_info, &decoded_win32_info, *this);
            surface_create_func_call = "vkCreateWin32SurfaceKHR";
            break;
        }
        case GfxToCppPlatform::PLATFORM_XCB:
        {
            VkXcbSurfaceCreateInfoKHR         xcb_struct_info  = {};
            Decoded_VkXcbSurfaceCreateInfoKHR decoded_xcb_info = {};

            if (platform_ == platform)
            {
                xcb_struct_info =
                    *reinterpret_cast<StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>*>(pSurfaceCreateInfo)
                         ->GetPointer();
            }
            xcb_struct_info.sType       = VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR;
            create_info_struct_var_name = GenerateStruct_VkXcbSurfaceCreateInfoKHR(
                stream_create_info, &xcb_struct_info, &decoded_xcb_info, *this);
            surface_create_func_call = "vkCreateXcbSurfaceKHR";
            break;
        }
        case GfxToCppPlatform::PLATFORM_WAYLAND:
        {
            VkWaylandSurfaceCreateInfoKHR         wayland_struct_info  = {};
            Decoded_VkWaylandSurfaceCreateInfoKHR decoded_wayland_info = {};

            if (platform_ == platform)
            {
                wayland_struct_info =
                    *reinterpret_cast<StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>*>(pSurfaceCreateInfo)
                         ->GetPointer();
            }
            wayland_struct_info.sType   = VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR;
            create_info_struct_var_name = GenerateStruct_VkWaylandSurfaceCreateInfoKHR(
                stream_create_info, &wayland_struct_info, &decoded_wayland_info, *this);
            surface_create_func_call = "vkCreateWaylandSurfaceKHR";
            break;
        }
        default:
            GFXRECON_LOG_FATAL("Failed to generate surface creation: Invalid platform (%d)", platform_);
            break;
    }
    fprintf(file, "\n%s", stream_create_info.str().c_str());
    AddKnownVariables("VkSurfaceKHR", surface_var_name, pSurface);
    AddHandles(surface_var_name, pSurface);
    pfn_loader_.AddMethodName(surface_create_func_call);
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_%s(%s, &%s, %s, &%s), %s);\n",
            surface_create_func_call.c_str(),
            GetHandle(instance).c_str(),
            create_info_struct_var_name.c_str(),
            "nullptr",
            surface_var_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());

    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::Intercept_vkBindImageMemory(VkResult         returnValue,
                                                        format::HandleId device,
                                                        format::HandleId image,
                                                        format::HandleId memory,
                                                        VkDeviceSize     memoryOffset)
{
    memory_resource_map_[memory].emplace(std::make_pair(image, memoryOffset));
}

void VulkanCppConsumerBase::Intercept_vkBindImageMemory2(
    VkResult                                             returnValue,
    format::HandleId                                     device,
    uint32_t                                             bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    for (uint32_t index = 0; index < bindInfoCount; ++index)
    {
        const VkBindImageMemoryInfo* cur_image_memory = pBindInfos->GetPointer() + index;
        memory_resource_map_[(format::HandleId)cur_image_memory->memory].emplace(
            std::make_pair((format::HandleId)cur_image_memory->image, cur_image_memory->memoryOffset));
    }
}

void VulkanCppConsumerBase::Intercept_vkBindBufferMemory(VkResult         returnValue,
                                                         format::HandleId device,
                                                         format::HandleId buffer,
                                                         format::HandleId memory,
                                                         VkDeviceSize     memoryOffset)
{
    memory_resource_map_[memory].emplace(std::make_pair(buffer, memoryOffset));
}

void VulkanCppConsumerBase::Intercept_vkBindBufferMemory2(
    VkResult                                              returnValue,
    format::HandleId                                      device,
    uint32_t                                              bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    for (uint32_t index = 0; index < bindInfoCount; ++index)
    {
        const VkBindBufferMemoryInfo* cur_buffer_memory = pBindInfos->GetPointer() + index;
        memory_resource_map_[(format::HandleId)cur_buffer_memory->memory].emplace(
            std::make_pair((format::HandleId)cur_buffer_memory->buffer, cur_buffer_memory->memoryOffset));
    }
}
void VulkanCppConsumerBase::Intercept_vkCreateFramebuffer(
    VkResult                                               returnValue,
    format::HandleId                                       device,
    StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*   pAllocator,
    HandlePointerDecoder<VkFramebuffer>*                   pFramebuffer)
{
    if (platform_ == GfxToCppPlatform::PLATFORM_ANDROID)
    {
        VkFramebufferCreateInfo* struct_info = pCreateInfo->GetPointer();
        struct_info->width                   = GetProperWindowWidth(struct_info->width);
        struct_info->height                  = GetProperWindowHeight(struct_info->height);
    }
}

void VulkanCppConsumerBase::Intercept_vkCmdBeginRenderPass(
    format::HandleId                                     commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                                    contents)
{
    if (platform_ == GfxToCppPlatform::PLATFORM_ANDROID)
    {
        // TODO: This completely breaks desktop, especially if anti-aliasing is enabled.
        //       Leaving this in as the original drop had this code and it may be required
        //       for Android.  But it needs verification.
        VkRenderPassBeginInfo* struct_info    = pRenderPassBegin->GetPointer();
        struct_info->renderArea.extent.width  = GetProperWindowWidth(struct_info->renderArea.extent.width);
        struct_info->renderArea.extent.height = GetProperWindowHeight(struct_info->renderArea.extent.height);
    }
}

void VulkanCppConsumerBase::Intercept_vkDestroySemaphore(
    format::HandleId                                     device,
    format::HandleId                                     semaphore,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    if (semaphore != format::kNullHandleId)
    {
        imported_semaphores_.erase(std::remove(imported_semaphores_.begin(), imported_semaphores_.end(), semaphore),
                                   imported_semaphores_.end());
    }
}

void VulkanCppConsumerBase::Generate_vkAcquireNextImageKHR(VkResult                  returnValue,
                                                           format::HandleId          device,
                                                           format::HandleId          swapchain,
                                                           uint64_t                  timeout,
                                                           format::HandleId          semaphore,
                                                           format::HandleId          fence,
                                                           PointerDecoder<uint32_t>* pImageIndex)
{
    FILE*       file                 = GetFrameFile();
    std::string image_index_var_name = "pImageIndex_" + std::to_string(GetNextId());
    next_image_map_[swapchain].push(image_index_var_name);

    AddKnownVariables("uint32_t", image_index_var_name);

    pfn_loader_.AddMethodName("vkAcquireNextImageKHR");
    fprintf(file,
            "\tVK_CALL_CHECK(toCppAcquireNextImageKHR(static_cast<VkResult>(0x%08x), %s, %s, %" PRIu64
            "UL, %s, %s, %u, &%s), %s);\n",
            returnValue,
            GetHandle(device).c_str(),
            GetHandle(swapchain).c_str(),
            timeout,
            GetHandle(semaphore).c_str(),
            GetHandle(fence).c_str(),
            (*pImageIndex->GetPointer()),
            image_index_var_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
}

void VulkanCppConsumerBase::Generate_vkAcquireNextImage2KHR(
    VkResult                                                 returnValue,
    format::HandleId                                         device,
    StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo,
    PointerDecoder<uint32_t>*                                pImageIndex)
{
    FILE*             file = GetFrameFile();
    std::stringstream stream_acquire_info;
    std::string       acquire_info_var_name = GenerateStruct_VkAcquireNextImageInfoKHR(
        stream_acquire_info, pAcquireInfo->GetPointer(), pAcquireInfo->GetMetaStructPointer(), *this);
    fprintf(file, "\n%s", stream_acquire_info.str().c_str());
    std::string image_index_var_name = "pImageIndex_" + std::to_string(GetNextId());
    fprintf(file, "\tuint32_t %s;\n", image_index_var_name.c_str());
    pfn_loader_.AddMethodName("vkAcquireNextImage2KHR");

    if (returnValue == VK_SUCCESS)
    {
        fprintf(file,
                "\twhile (loaded_vkAcquireNextImage2KHR(%s, %s, &%s)) != VK_SUCCESS) { usleep(5000); };\n",
                GetHandle(device).c_str(),
                acquire_info_var_name.c_str(),
                image_index_var_name.c_str());
    }
    else
    {
        fprintf(file,
                "\tVK_CALL_CHECK(loaded_vkAcquireNextImage2KHR(%s, &%s, &%s), %s);\n",
                GetHandle(device).c_str(),
                acquire_info_var_name.c_str(),
                image_index_var_name.c_str(),
                util::ToString<VkResult>(returnValue).c_str());
    }
}

void VulkanCppConsumerBase::Generate_vkWaitForFences(VkResult                       returnValue,
                                                     format::HandleId               device,
                                                     uint32_t                       fenceCount,
                                                     HandlePointerDecoder<VkFence>* pFences,
                                                     VkBool32                       waitAll,
                                                     uint64_t                       timeout)
{
    FILE*       file = GetFrameFile();
    char        indent_tabs[16];
    std::string fences_array     = "NULL";
    std::string fences_var_names = toStringJoin(
        pFences->GetPointer(),
        pFences->GetPointer() + fenceCount,
        [&](const format::HandleId current) { return GetHandle(current); },
        ", ");
    if (fenceCount == 1)
    {
        fences_array   = "&" + fences_var_names;
        indent_tabs[0] = '\t';
        indent_tabs[1] = '\0';
    }
    else if (fenceCount > 1)
    {
        fprintf(file, "\t{\n");
        fences_array = "fences_array_" + std::to_string(GetNextId());
        fprintf(file, "\t\tVkFence %s[] = { %s };\n", fences_array.c_str(), fences_var_names.c_str());
        indent_tabs[0] = '\t';
        indent_tabs[1] = '\t';
        indent_tabs[2] = '\0';
    }
    if (returnValue == VK_SUCCESS)
    {
        fprintf(file,
                "%swhile (vkWaitForFences(%s, %u, %s, %u, %" PRIu64 "UL) != VK_SUCCESS) { usleep(5000); };\n",
                indent_tabs,
                GetHandle(device).c_str(),
                fenceCount,
                fences_array.c_str(),
                waitAll,
                timeout);
    }
    else
    {
        fprintf(file,
                "%sVK_CALL_CHECK(vkWaitForFences(%s, %u, %s, %u, %" PRIu64 "UL), %s);\n",
                indent_tabs,
                GetHandle(device).c_str(),
                fenceCount,
                fences_array.c_str(),
                waitAll,
                timeout,
                util::ToString<VkResult>(returnValue).c_str());
    }
    if (fenceCount > 1)
    {
        fprintf(file, "\t}\n");
    }
}

void VulkanCppConsumerBase::Generate_vkCreateDescriptorUpdateTemplate(
    VkResult                                                            returnValue,
    format::HandleId                                                    device,
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*                pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>*                   pDescriptorUpdateTemplate,
    const char*                                                         extension)
{
    FILE*             file = GetFrameFile();
    std::string       create_info_struct_var_name;
    std::stringstream stream_create_info;
    std::string       desc_update_template_var_name = "pDescriptorUpdateTemplate_" + std::to_string(this->GetNextId());
    AddKnownVariables("VkDescriptorUpdateTemplate", desc_update_template_var_name);
    std::string method_name = "vkCreateDescriptorUpdateTemplate";
    method_name += extension;

    fprintf(file, "\t{\n");
    VkDescriptorUpdateTemplateCreateInfo* tocpp_create_info = pCreateInfo->GetPointer();
    if (tocpp_create_info != nullptr)
    {
        // Modify the layout of the update template entries to match the tight packing performed by the trace encoding.
        // The trace encoding wrote the update template entries as a tightly packed array of VkDescriptorImageInfo
        // values, followed by an array of VkDescriptorBufferInfo values, followed by an array of VkBufferView values.
        VkDescriptorUpdateTemplateCreateInfo override_create_info = (*tocpp_create_info);

        std::vector<VkDescriptorUpdateTemplateEntry> entries(
            override_create_info.pDescriptorUpdateEntries,
            (override_create_info.pDescriptorUpdateEntries + override_create_info.descriptorUpdateEntryCount));

        auto template_handle_id = *pDescriptorUpdateTemplate->GetPointer();

        // Count the number of values of each type.
        size_t                  image_info_count             = 0;
        size_t                  buffer_info_count            = 0;
        size_t                  texel_buffer_view_count      = 0;
        size_t                  acceleration_structure_count = 0;
        [[maybe_unused]] size_t inline_uniform_block_count   = 0;

        for (auto entry = entries.begin(); entry != entries.end(); ++entry)
        {
            VkDescriptorType type = entry->descriptorType;

            if ((type == VK_DESCRIPTOR_TYPE_SAMPLER) || (type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER) ||
                (type == VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE) || (type == VK_DESCRIPTOR_TYPE_STORAGE_IMAGE) ||
                (type == VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT))
            {
                image_info_count += entry->descriptorCount;
            }
            else if ((type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER) || (type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER) ||
                     (type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC) ||
                     (type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC))
            {
                buffer_info_count += entry->descriptorCount;
            }
            else if ((type == VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER) ||
                     (type == VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER))
            {
                texel_buffer_view_count += entry->descriptorCount;
            }
            else if (type == VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR)
            {
                acceleration_structure_count += entry->descriptorCount;
            }
            else if (type == VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK)
            {
                inline_uniform_block_count += entry->descriptorCount;
            }
            else
            {
                assert(false);
            }
        }

        // Compute start offsets for each type.
        size_t image_info_offset        = 0;
        size_t buffer_info_offset       = image_info_count * sizeof(VkDescriptorImageInfo);
        size_t texel_buffer_view_offset = buffer_info_offset + (buffer_info_count * sizeof(VkDescriptorBufferInfo));
        size_t accel_struct_offset      = texel_buffer_view_offset + (texel_buffer_view_count * sizeof(VkBufferView));
        size_t inline_uniform_block_offset =
            accel_struct_offset + (acceleration_structure_count * sizeof(VkAccelerationStructureKHR));

        // Track descriptor image type.
        std::vector<VkDescriptorType> image_types;

        for (auto entry = entries.begin(); entry != entries.end(); ++entry)
        {
            VkDescriptorType type = entry->descriptorType;

            descriptor_update_template_entry_map_[template_handle_id].data.emplace_back(*entry);

            if ((type == VK_DESCRIPTOR_TYPE_SAMPLER) || (type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER) ||
                (type == VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE) || (type == VK_DESCRIPTOR_TYPE_STORAGE_IMAGE) ||
                (type == VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT))
            {
                image_types.insert(image_types.end(), entry->descriptorCount, entry->descriptorType);

                entry->stride = sizeof(VkDescriptorImageInfo);
                entry->offset = image_info_offset;
                image_info_offset += entry->descriptorCount * sizeof(VkDescriptorImageInfo);

                descriptor_update_template_entry_map_[template_handle_id].images.emplace_back(*entry);
            }
            else if ((type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER) || (type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER) ||
                     (type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC) ||
                     (type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC))
            {
                entry->stride = sizeof(VkDescriptorBufferInfo);
                entry->offset = buffer_info_offset;
                buffer_info_offset += entry->descriptorCount * sizeof(VkDescriptorBufferInfo);

                descriptor_update_template_entry_map_[template_handle_id].buffers.emplace_back(*entry);
            }
            else if ((type == VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER) ||
                     (type == VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER))
            {
                entry->stride = sizeof(VkBufferView);
                entry->offset = texel_buffer_view_offset;
                texel_buffer_view_offset += entry->descriptorCount * sizeof(VkBufferView);

                descriptor_update_template_entry_map_[template_handle_id].texels.emplace_back(*entry);
            }
            else if (type == VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR)
            {
                entry->stride = sizeof(VkAccelerationStructureKHR);
                entry->offset = accel_struct_offset;
                accel_struct_offset += entry->descriptorCount * sizeof(VkAccelerationStructureKHR);

                descriptor_update_template_entry_map_[template_handle_id].accelerations.emplace_back(*entry);
            }
            else if (type == VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK)
            {
                constexpr size_t byte_stride = 1;
                entry->stride                = byte_stride;
                entry->offset                = inline_uniform_block_offset;
                inline_uniform_block_offset += entry->descriptorCount * byte_stride;

                descriptor_update_template_entry_map_[template_handle_id].inline_uniform_blocks.emplace_back(*entry);
            }
            else
            {
                assert(false);
            }
        }

        override_create_info.pDescriptorUpdateEntries = entries.data();

        create_info_struct_var_name = GenerateStruct_VkDescriptorUpdateTemplateCreateInfo(
            stream_create_info, &override_create_info, pCreateInfo->GetMetaStructPointer(), *this);
    }
    else
    {
        create_info_struct_var_name = GenerateStruct_VkDescriptorUpdateTemplateCreateInfo(
            stream_create_info, pCreateInfo->GetPointer(), pCreateInfo->GetMetaStructPointer(), *this);

        auto template_handle_id = *pDescriptorUpdateTemplate->GetPointer();
        for (uint32_t idx = 0; idx < tocpp_create_info->descriptorUpdateEntryCount; idx++)
        {
            auto create_info_entry = tocpp_create_info->pDescriptorUpdateEntries[idx];
            descriptor_update_template_entry_map_[template_handle_id].data.emplace_back(create_info_entry);
            switch (GetDescriptorBaseType(create_info_entry.descriptorType))
            {
                case DESCRIPTOR_BASE_TYPE_SAMPLER:
                case DESCRIPTOR_BASE_TYPE_IMAGE:
                case DESCRIPTOR_BASE_TYPE_COMBINED_IMAGE_SAMPLER:
                {
                    descriptor_update_template_entry_map_[template_handle_id].images.emplace_back(create_info_entry);
                    break;
                }
                case DESCRIPTOR_BASE_TYPE_BUFFER:
                {
                    descriptor_update_template_entry_map_[template_handle_id].buffers.emplace_back(create_info_entry);
                    break;
                }
                case DESCRIPTOR_BASE_TYPE_TEXEL:
                {
                    descriptor_update_template_entry_map_[template_handle_id].texels.emplace_back(create_info_entry);
                    break;
                }
                default:
                {
                    assert(false); // This should never happen
                }
            }
        }
    }

    if (returnValue == VK_SUCCESS)
    {
        this->AddHandles(desc_update_template_var_name, pDescriptorUpdateTemplate->GetPointer());
    }

    fprintf(file, "%s", stream_create_info.str().c_str());
    pfn_loader_.AddMethodName(method_name);
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_%s(%s, &%s, NULL, &%s), %s);\n",
            method_name.c_str(),
            this->GetHandle(device).c_str(),
            create_info_struct_var_name.c_str(),
            desc_update_template_var_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
}

struct VariableOffset
{
    std::string      name;
    VkDescriptorType type;
    uint32_t         count;
    uint64_t         offset;
};

bool VariableOffsetCompare(VariableOffset& a, VariableOffset& b)
{
    return a.offset < b.offset;
}

void VulkanCppConsumerBase::GenerateDescriptorUpdateTemplateData(DescriptorUpdateTemplateDecoder* decoder,
                                                                 format::HandleId descriptor_update_template,
                                                                 FILE*            frame_file,
                                                                 std::string&     template_data_var_name)
{
    std::vector<VariableOffset> variables;
    std::stringstream           struct_define_stream;
    std::stringstream           struct_implement_stream;
    std::vector<std::string>    image_desc_info_variables;
    std::vector<std::string>    buffer_desc_info_variables;
    std::vector<std::string>    texel_desc_info_variables;
    std::vector<std::string>    accel_desc_info_variables;
    std::vector<std::string>    inline_uniform_block_info_variables;

    uint32_t image_info_count        = static_cast<uint32_t>(decoder->GetImageInfoCount());
    uint32_t buffer_info_count       = static_cast<uint32_t>(decoder->GetBufferInfoCount());
    uint32_t texel_buffer_view_count = static_cast<uint32_t>(decoder->GetTexelBufferViewCount());
    uint32_t accel_struct_count      = static_cast<uint32_t>(decoder->GetAccelerationStructureKHRCount());

    assert(descriptor_update_template_entry_map_.find(descriptor_update_template) !=
           descriptor_update_template_entry_map_.end());

    const DescriptorUpdateTemplateEntries& template_entries =
        descriptor_update_template_entry_map_[descriptor_update_template];

    // Generate the appropriate info structure based on the descriptor type

    // Image info structures
    if (decoder->GetImageInfoPointer() != nullptr && image_info_count > 0)
    {
        std::stringstream              desc_image_info_stream;
        VkDescriptorImageInfo*         infos                = decoder->GetImageInfoPointer();
        Decoded_VkDescriptorImageInfo* meta_structs         = decoder->GetImageInfoMetaStructPointer();
        uint32_t                       image_template_index = 0;
        uint32_t                       cur_desc_count       = template_entries.images[0].descriptorCount;

        for (uint32_t idx = 0; idx < image_info_count; idx++)
        {
            // Only use the next template if every descriptor has been generated for the current template
            if (idx == cur_desc_count)
            {
                image_template_index++;
                cur_desc_count += template_entries.images[image_template_index].descriptorCount;
            }

            std::string varName = GenerateStruct_VkDescriptorImageInfo(desc_image_info_stream,
                                                                       template_entries.images[image_template_index],
                                                                       &infos[idx],
                                                                       &meta_structs[idx],
                                                                       *this);
            image_desc_info_variables.emplace_back(varName);
        }
        fprintf(frame_file, "%s", desc_image_info_stream.str().c_str());
    }

    // Buffer info structures
    if (decoder->GetBufferInfoPointer() != nullptr && buffer_info_count > 0)
    {
        std::stringstream               desc_buffer_info_stream;
        VkDescriptorBufferInfo*         infos        = decoder->GetBufferInfoPointer();
        Decoded_VkDescriptorBufferInfo* meta_structs = decoder->GetBufferInfoMetaStructPointer();

        for (uint32_t idx = 0; idx < buffer_info_count; idx++)
        {
            std::string varName =
                GenerateStruct_VkDescriptorBufferInfo(desc_buffer_info_stream, &infos[idx], &meta_structs[idx], *this);
            buffer_desc_info_variables.emplace_back(varName);
        }
        fprintf(frame_file, "%s", desc_buffer_info_stream.str().c_str());
    }

    // Texel Handle info structures
    // TODO: Due to a lack of test examples using texel buffer views, this part requires more testing
    if (decoder->GetTexelBufferViewPointer() != nullptr && texel_buffer_view_count > 0)
    {
        format::HandleId* handles = decoder->GetTexelBufferViewHandleIdsPointer();
        for (uint32_t idx = 0; idx < texel_buffer_view_count; idx++)
        {
            std::string cur_handle = GetHandle(handles[idx]);
            texel_desc_info_variables.emplace_back(cur_handle);
        }
    }

    // Acceleration Handle info structures
    // TODO: Due to a lack of test examples using acceleration structures, this part requires more testing
    if (decoder->GetAccelerationStructureKHRPointer() != nullptr && accel_struct_count > 0)
    {
        format::HandleId* handles = decoder->GetAccelerationStructureKHRHandleIdsPointer();
        for (uint32_t idx = 0; idx < accel_struct_count; idx++)
        {
            std::string cur_handle = GetHandle(handles[idx]);
            accel_desc_info_variables.emplace_back(cur_handle);
        }
    }

    std::string struct_type_name      = "StructDefine_" + std::to_string(GetNextId());
    std::string struct_implement_name = "pData_" + std::to_string(GetNextId());

    struct_define_stream << "\t\tstruct " << struct_type_name << " {\n";
    struct_implement_stream << "\t\t" << struct_type_name << " " << struct_implement_name << " {\n";
    uint32_t cur_count = 0;

    // Now loop through the descriptor template entry list and find each item and it's
    // offset into the template structure.  This is then used to sort the names of the
    // corresponding variables based on the offset so they are defined in the template
    // definition correctly.
    uint32_t template_descriptor_count = 0;
    for (auto const& entry : template_entries.data)
    {
        template_descriptor_count += entry.descriptorCount;
        switch (entry.descriptorType)
        {
            case VK_DESCRIPTOR_TYPE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
            case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
            case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
            {
                VariableOffset offset = {
                    image_desc_info_variables[0], entry.descriptorType, entry.descriptorCount, entry.offset
                };
                image_desc_info_variables.erase(image_desc_info_variables.begin());
                variables.push_back(std::move(offset));
                break;
            }
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
            {
                VariableOffset offset = {
                    buffer_desc_info_variables[0], entry.descriptorType, entry.descriptorCount, entry.offset
                };
                buffer_desc_info_variables.erase(buffer_desc_info_variables.begin());
                variables.push_back(std::move(offset));
                break;
            }
            case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
            {
                VariableOffset offset = {
                    texel_desc_info_variables[0], entry.descriptorType, entry.descriptorCount, entry.offset
                };
                texel_desc_info_variables.erase(texel_desc_info_variables.begin());
                variables.push_back(std::move(offset));
                break;
            }
            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
            {
                VariableOffset offset = {
                    accel_desc_info_variables[0], entry.descriptorType, entry.descriptorCount, entry.offset
                };
                accel_desc_info_variables.erase(accel_desc_info_variables.begin());
                variables.push_back(std::move(offset));
                break;
            }
            case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
            {
                // TODO: needs testing, unsure when/how we'll use this
                assert(false);

                VariableOffset offset = {
                    inline_uniform_block_info_variables[0], entry.descriptorType, entry.descriptorCount, entry.offset
                };
                inline_uniform_block_info_variables.erase(inline_uniform_block_info_variables.begin());
                variables.push_back(std::move(offset));
                break;
            }
            default:
                break;
        }
    }

    // Check if the number of descriptors in pData equal the number of descriptors in the template
    uint32_t expected_data_count = decoder->GetImageInfoCount() + decoder->GetBufferInfoCount() +
                                   decoder->GetTexelBufferViewCount() + decoder->GetAccelerationStructureKHRCount();
    assert(template_descriptor_count == expected_data_count);

    // Sort the variables based on the offset
    std::sort(variables.begin(), variables.end(), VariableOffsetCompare);

    // Now that they are sorted, write out the template definition and implementation.
    for (auto const& var : variables)
    {
        struct_implement_stream << "\t\t\t{ ";
        for (uint32_t jdx = 0; jdx < var.count; jdx++)
        {
            if (jdx == 0)
            {
                switch (var.type)
                {
                    case VK_DESCRIPTOR_TYPE_SAMPLER:
                    case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                    case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                    case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                    case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                        struct_define_stream << "\t\t\tVkDescriptorImageInfo descImageInfo" << cur_count++ << "["
                                             << var.count << "];\n";
                        break;
                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                        struct_define_stream << "\t\t\tVkDescriptorBufferInfo descBufferInfo" << cur_count++ << "["
                                             << var.count << "];\n";
                        break;
                    case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                    case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                        struct_define_stream << "\t\t\tVkBufferView descTexelInfo" << cur_count++ << "[" << var.count
                                             << "];\n";
                        break;
                    case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                        struct_define_stream << "\t\t\tVkAccelerationStructureKHR descAccelInfo" << cur_count++ << "["
                                             << var.count << "];\n";
                        break;
                    case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                        struct_define_stream << "\t\t\tInlineUniformBlock descInlineUniformInfo" << cur_count++ << "["
                                             << var.count << "];\n";
                        break;
                    default:
                        assert(false);
                        struct_define_stream << "UNKNOWN DESCRIPTOR_TYPE, ";
                        break;
                }
            }
            struct_implement_stream << var.name << ", ";
        }
        struct_implement_stream << "},\n";
    }

    struct_define_stream << "\t\t};\n";
    struct_implement_stream << "\t\t};\n";
    fprintf(frame_file, "%s", struct_define_stream.str().c_str());
    fprintf(frame_file, "%s", struct_implement_stream.str().c_str());

    template_data_var_name = struct_implement_name;
}

void VulkanCppConsumerBase::Generate_vkUpdateDescriptorSetWithTemplate(format::HandleId device,
                                                                       format::HandleId descriptorSet,
                                                                       format::HandleId descriptorUpdateTemplate,
                                                                       DescriptorUpdateTemplateDecoder* pData,
                                                                       const char*                      extension)
{
    FILE*       file = GetFrameFile();
    std::string var_name;

    fprintf(file, "\t{\n");

    GenerateDescriptorUpdateTemplateData(pData, descriptorUpdateTemplate, file, var_name);

    std::string method_name = "vkUpdateDescriptorSetWithTemplate";
    method_name += extension;
    pfn_loader_.AddMethodName(method_name);
    fprintf(file,
            "\t\tloaded_%s(%s, %s, %s, &%s);\n",
            method_name.c_str(),
            GetHandle(device).c_str(),
            GetHandle(descriptorSet).c_str(),
            GetHandle(descriptorUpdateTemplate).c_str(),
            var_name.c_str());
    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::Generate_vkSetDebugUtilsObjectNameEXT(
    VkResult                                                     returnValue,
    format::HandleId                                             device,
    StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>* pNameInfo)
{}
void VulkanCppConsumerBase::Generate_vkSetDebugUtilsObjectTagEXT(
    VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT>* pTagInfo)
{}
void VulkanCppConsumerBase::Generate_vkDebugMarkerSetObjectNameEXT(
    VkResult                                                      returnValue,
    format::HandleId                                              device,
    StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT>* pNameInfo)
{}
void VulkanCppConsumerBase::Generate_vkDebugMarkerSetObjectTagEXT(
    VkResult                                                     returnValue,
    format::HandleId                                             device,
    StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT>* pTagInfo)
{}

void VulkanCppConsumerBase::Generate_vkCreateGraphicsPipelines(
    VkResult                                                    returnValue,
    format::HandleId                                            device,
    format::HandleId                                            pipelineCache,
    uint32_t                                                    createInfoCount,
    StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*        pAllocator,
    HandlePointerDecoder<VkPipeline>*                           pPipelines)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
    // device
    // pipelineCache
    // createInfoCount
    // pCreateInfos
    std::stringstream stream_create_infos;
    std::string       create_infos_array_variable = "NULL";
    PointerPairContainer<decltype(pCreateInfos->GetPointer()), decltype(pCreateInfos->GetMetaStructPointer())>
        create_infos_var_pair{ pCreateInfos->GetPointer(), pCreateInfos->GetMetaStructPointer(), createInfoCount };
    std::string create_info_var_name = toStringJoin(
        create_infos_var_pair.begin(),
        create_infos_var_pair.end(),
        [&](auto pair) {
            return GenerateStruct_VkGraphicsPipelineCreateInfo(stream_create_infos, pair.t1, pair.t2, *this);
        },
        ", ");
    fprintf(file, "\n%s", stream_create_infos.str().c_str());
    if (createInfoCount == 1)
    {
        create_infos_array_variable = "&" + create_info_var_name;
    }
    else if (createInfoCount > 1)
    {
        create_infos_array_variable = "pCreateInfos_" + std::to_string(this->GetNextId());
        fprintf(file,
                "VkGraphicsPipelineCreateInfo %s[] = { %s };\n",
                create_infos_array_variable.c_str(),
                create_info_var_name.c_str());
    }
    // pAllocator
    // pPipelines
    std::string pipeline_var_name = "pPipelines_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_PIPELINE));
    AddKnownVariables("VkPipeline", pipeline_var_name, pPipelines->GetPointer(), createInfoCount);
    if (returnValue == VK_SUCCESS)
    {
        this->AddHandles(pipeline_var_name, pPipelines->GetPointer(), createInfoCount);
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateGraphicsPipelines(%s, %s, %u, %s, %s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipelineCache).c_str(),
            createInfoCount,
            create_infos_array_variable.c_str(),
            "nullptr",
            pipeline_var_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
}

void VulkanCppConsumerBase::Generate_vkCreateRayTracingPipelinesKHR(
    VkResult                                                         returnValue,
    format::HandleId                                                 deferredOperation,
    format::HandleId                                                 device,
    format::HandleId                                                 pipelineCache,
    uint32_t                                                         createInfoCount,
    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*             pAllocator,
    HandlePointerDecoder<VkPipeline>*                                pPipelines)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
    // device
    // pipelineCache
    // createInfoCount
    // pCreateInfos
    std::stringstream stream_create_infos;
    std::string       create_infos_array_variable = "NULL";
    PointerPairContainer<decltype(pCreateInfos->GetPointer()), decltype(pCreateInfos->GetMetaStructPointer())>
        create_infos_var_pair{ pCreateInfos->GetPointer(), pCreateInfos->GetMetaStructPointer(), createInfoCount };
    std::string create_info_var_name = toStringJoin(
        create_infos_var_pair.begin(),
        create_infos_var_pair.end(),
        [&](auto pair) {
            return GenerateStruct_VkRayTracingPipelineCreateInfoKHR(stream_create_infos, pair.t1, pair.t2, *this);
        },
        ", ");
    fprintf(file, "\n%s", stream_create_infos.str().c_str());
    if (createInfoCount == 1)
    {
        create_infos_array_variable = "&" + create_info_var_name;
    }
    else if (createInfoCount > 1)
    {
        create_infos_array_variable = "pCreateInfos_" + std::to_string(this->GetNextId());
        fprintf(file,
                "VkRayTracingPipelineCreateInfoKHR %s[] = { %s };\n",
                create_infos_array_variable.c_str(),
                create_info_var_name.c_str());
    }
    // pAllocator
    // pPipelines
    std::string pipeline_var_name = "pPipelines_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_PIPELINE));
    AddKnownVariables("VkPipeline", pipeline_var_name, pPipelines->GetPointer(), createInfoCount);
    if (returnValue == VK_SUCCESS)
    {
        this->AddHandles(pipeline_var_name, pPipelines->GetPointer(), createInfoCount);
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateRayTracingPipelinesKHR(%s, %s, %u, %s, %s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipelineCache).c_str(),
            createInfoCount,
            create_infos_array_variable.c_str(),
            "nullptr",
            pipeline_var_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
}

void VulkanCppConsumerBase::Generate_vkCreateComputePipelines(
    VkResult                                                   returnValue,
    format::HandleId                                           device,
    format::HandleId                                           pipelineCache,
    uint32_t                                                   createInfoCount,
    StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*       pAllocator,
    HandlePointerDecoder<VkPipeline>*                          pPipelines)
{
    FILE* file = GetFrameFile();
    fprintf(file, "    {\n");
    // device
    // pipelineCache
    // createInfoCount
    // pCreateInfos
    std::stringstream stream_create_infos;
    std::string       create_infos_array_variable = "NULL";
    PointerPairContainer<decltype(pCreateInfos->GetPointer()), decltype(pCreateInfos->GetMetaStructPointer())>
        create_infos_var_pair{ pCreateInfos->GetPointer(), pCreateInfos->GetMetaStructPointer(), createInfoCount };
    std::string create_info_var_name = toStringJoin(
        create_infos_var_pair.begin(),
        create_infos_var_pair.end(),
        [&](auto pair) {
            return GenerateStruct_VkComputePipelineCreateInfo(stream_create_infos, pair.t1, pair.t2, *this);
        },
        ", ");
    fprintf(file, "\n%s", stream_create_infos.str().c_str());
    if (createInfoCount == 1)
    {
        create_infos_array_variable = "&" + create_info_var_name;
    }
    else if (createInfoCount > 1)
    {
        create_infos_array_variable = "pCreateInfos_" + std::to_string(this->GetNextId());
        fprintf(file,
                "VkComputePipelineCreateInfo %s[] = { %s };\n",
                create_infos_array_variable.c_str(),
                create_info_var_name.c_str());
    }
    // pAllocator
    // pPipelines
    std::string pipeline_var_name = "pPipelines_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_PIPELINE));
    AddKnownVariables("VkPipeline", pipeline_var_name, pPipelines->GetPointer(), createInfoCount);
    if (returnValue == VK_SUCCESS)
    {
        this->AddHandles(pipeline_var_name, pPipelines->GetPointer(), createInfoCount);
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateComputePipelines(%s, %s, %u, %s, %s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipelineCache).c_str(),
            createInfoCount,
            create_infos_array_variable.c_str(),
            "nullptr",
            pipeline_var_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
}

void VulkanCppConsumerBase::Generate_vkGetSemaphoreWin32HandleKHR(
    VkResult                                                        returnValue,
    format::HandleId                                                device,
    StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*                                pHandle)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pGetWin32HandleInfo);
    GFXRECON_UNREFERENCED_PARAMETER(pHandle);
    FILE* file = GetFrameFile();
    fprintf(file, "\t// vkGetSemaphoreWin32HandleKHR ignored\n");

    // No other work necessary because we're not actually sharing the semaphore during replay
}

void VulkanCppConsumerBase::Generate_vkImportSemaphoreWin32HandleKHR(
    VkResult                                                           returnValue,
    format::HandleId                                                   device,
    StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>* pImportSemaphoreWin32HandleInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);
    GFXRECON_UNREFERENCED_PARAMETER(device);

    // Add the semaphore to the list of imported semaphores
    imported_semaphores_.push_back(pImportSemaphoreWin32HandleInfo->GetMetaStructPointer()->semaphore);

    // No other work necessary because we're not actually importing the semaphore during replay
}

void VulkanCppConsumerBase::Generate_vkGetSemaphoreFdKHR(
    VkResult                                               returnValue,
    format::HandleId                                       device,
    StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                                   pFd)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pGetFdInfo);
    GFXRECON_UNREFERENCED_PARAMETER(pFd);
    FILE* file = GetFrameFile();
    fprintf(file, "\t// vkGetSemaphoreFdKHR ignored\n");

    // No other work necessary because we're not actually sharing the semaphore during replay
}

void VulkanCppConsumerBase::Generate_vkImportSemaphoreFdKHR(
    VkResult                                                  returnValue,
    format::HandleId                                          device,
    StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>* pImportSemaphoreFdInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);
    GFXRECON_UNREFERENCED_PARAMETER(device);

    // Add the semaphore to the list of imported semaphores
    imported_semaphores_.push_back(pImportSemaphoreFdInfo->GetMetaStructPointer()->semaphore);

    // No other work necessary because we're not actually importing the semaphore during replay
}

std::string VulkanCppConsumerBase::ToEscape(const char* value)
{
    return (value != nullptr) ? std::string("\"") + value + "\"" : "NULL";
}

std::string VulkanCppConsumerBase::ToEscape(const std::string& value)
{
    return std::string("\"") + value + "\"";
}

std::string VulkanCppConsumerBase::EscapeStringArray(const char* const* stringArray, const uint32_t stringArrayLength)
{
    if (stringArrayLength == 0)
    {
        return std::string("{\"\"}");
    }

    std::string escaped_strings = "{";
    for (uint32_t idx = 0; idx < stringArrayLength; ++idx)
    {
        escaped_strings += ToEscape(*(stringArray + idx)) + std::string(",");
    }

    // Replace the comma after the last item to a curly bracket.
    escaped_strings.back() = '}';
    return escaped_strings;
}

std::string VulkanCppConsumerBase::EscapeStringArray(const std::vector<std::string>& strings)
{
    if (strings.size() == 0)
    {
        return std::string("{\"\"}");
    }

    std::string escaped_strings = "{";
    for (uint32_t idx = 0; idx < strings.size(); ++idx)
    {
        escaped_strings += ToEscape(strings[idx]) + std::string(",");
    }

    // Replace the comma after the last item to a curly bracket.
    escaped_strings.back() = '}';
    return escaped_strings;
}

std::string VulkanCppConsumerBase::BuildValue(const VkClearColorValue color)
{
    float values[4];
    // normalize the float values, to avoid inf/nan outputs
    for (size_t idx = 0; idx < 4; idx++)
    {
        values[idx] = std::isfinite(color.float32[idx]) ? color.float32[idx] : 0;
    }

    std::stringstream output;
    output << "{{" << values[0] << ", " << values[1] << ", " << values[2] << ", " << values[3] << ""
           << "}}";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkClearValue clearValue)
{
    std::stringstream output;
    output << "{ (VkClearColorValue)" << BuildValue(clearValue.color) << " }";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkClearValue* values, uint32_t count)
{
    std::stringstream output;
    output << "{";
    for (uint32_t idx = 0; idx < count; idx++)
    {
        output << VulkanCppConsumerBase::BuildValue(values[idx]) << ", ";
    }
    output << "}";

    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkComponentMapping components)
{
    std::stringstream output;
    output << "(VkComponentMapping){ " << util::ToString<VkComponentSwizzle>(components.r) << ", "
           << util::ToString<VkComponentSwizzle>(components.g) << ", "
           << util::ToString<VkComponentSwizzle>(components.b) << ", "
           << util::ToString<VkComponentSwizzle>(components.a) << " }";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkOffset2D offSet2D)
{
    std::stringstream output;
    output << "(VkOffset2D){ " << offSet2D.x << ", " << offSet2D.y << " }";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkOffset3D offSet3D)
{
    std::stringstream output;
    output << "(VkOffset3D){ " << offSet3D.x << ", " << offSet3D.y << ", " << offSet3D.z << " }";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkOffset3D* values, uint32_t count)
{
    std::stringstream output;
    output << "{";
    for (uint32_t idx = 0; idx < count; idx++)
    {
        output << VulkanCppConsumerBase::BuildValue(values[idx]) << ", ";
    }
    output << "}";

    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkExtent2D extent2D)
{
    std::stringstream output;
    output << "(VkExtent2D){ " << extent2D.width << ", " << extent2D.height << " }";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkExtent3D extent3D)
{
    std::stringstream output;
    output << "(VkExtent3D){ " << extent3D.width << ", " << extent3D.height << ", " << extent3D.depth << " }";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkRect2D rect2D)
{
    std::stringstream output;
    output << "(VkRect2D){ " << BuildValue(rect2D.offset) << ", " << BuildValue(rect2D.extent) << " }";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkRect2D* rect2D)
{
    std::stringstream output;
    output << "(VkRect2D){ " << BuildValue(rect2D->offset) << ", " << BuildValue(rect2D->extent) << " }";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkRect2D* values, uint32_t count)
{
    std::stringstream output;
    output << "{";
    for (uint32_t idx = 0; idx < count; idx++)
    {
        output << VulkanCppConsumerBase::BuildValue(values[idx]) << ", ";
    }
    output << "}";

    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkImageSubresourceRange subresourceRange)
{
    std::stringstream output;
    output << "(VkImageSubresourceRange){ " << util::ToString<VkImageAspectFlags>(subresourceRange.aspectMask) << ", "
           << subresourceRange.baseMipLevel << ", " << subresourceRange.levelCount << ", "
           << subresourceRange.baseArrayLayer << ", " << subresourceRange.layerCount << " }";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkImageSubresourceLayers subresourceLayer)
{
    std::stringstream output;
    output << "(VkImageSubresourceLayers){ " << util::ToString<VkImageAspectFlags>(subresourceLayer.aspectMask) << ", "
           << subresourceLayer.mipLevel << ", " << subresourceLayer.baseArrayLayer << ", "
           << subresourceLayer.layerCount << " }";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkStencilOpState stencilOpState)
{
    std::stringstream output;
    output << "(VkStencilOpState){ " << util::ToString<VkStencilOp>(stencilOpState.failOp) << ", "
           << util::ToString<VkStencilOp>(stencilOpState.passOp) << ", "
           << util::ToString<VkStencilOp>(stencilOpState.depthFailOp) << ", "
           << util::ToString<VkCompareOp>(stencilOpState.compareOp) << ", " << stencilOpState.compareMask << ", "
           << stencilOpState.writeMask << ", " << stencilOpState.reference << " }";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkQueueGlobalPriorityKHR value)
{
    std::stringstream output;
    output << "(VkQueueGlobalPriorityKHR){ " << util::ToString<VkQueueGlobalPriorityKHR>(value) << " }";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkQueueGlobalPriorityKHR* values, uint32_t count)
{
    std::stringstream output;
    output << "{";
    for (uint32_t idx = 0; idx < count; idx++)
    {
        output << VulkanCppConsumerBase::BuildValue(values[idx]) << ", ";
    }
    output << "}";

    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkFragmentShadingRateCombinerOpKHR value)
{
    std::stringstream output;
    output << "(VkFragmentShadingRateCombinerOpKHR){ " << util::ToString<VkFragmentShadingRateCombinerOpKHR>(value)
           << " }";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkFragmentShadingRateCombinerOpKHR* values, uint32_t count)
{
    std::stringstream output;
    output << "{";
    for (uint32_t idx = 0; idx < count; idx++)
    {
        output << VulkanCppConsumerBase::BuildValue(values[idx]) << ", ";
    }
    output << "}";

    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const VkPipelineExecutableStatisticValueKHR& value)
{
    std::stringstream output;
    output << "(VkPipelineExecutableStatisticValueKHR){ " << util::ToString<uint64_t>(value.u64) << " }";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const StdVideoAV1FrameRestorationType value)
{
    std::stringstream output;
    output << "(StdVideoAV1FrameRestorationType){ " << util::ToString<StdVideoAV1FrameRestorationType>(value) << "}";
    return output.str();
}

std::string VulkanCppConsumerBase::BuildValue(const StdVideoAV1FrameRestorationType* values, uint32_t count)
{
    std::stringstream output;
    output << "{";
    for (uint32_t idx = 0; idx < count; idx++)
    {
        output << VulkanCppConsumerBase::BuildValue(values[idx]) << ", ";
    }
    output << "}";

    return output.str();
}

GfxToCppPlatform getGfxToCppPlatform(const std::string& format_str)
{
    return kTargetPlatformByName.at(format_str);
}

std::string GfxToCppPlatformToString(GfxToCppPlatform platform)
{
    return kTargetPlatforms.at(platform).platformName;
}

std::string VulkanCppConsumerBase::AddStruct(const std::stringstream& content, const std::string& var_namePrefix)
{
    const std::string content_string = content.str();
    const uint64_t    hash_value     = util::hash::GenerateCheckSum<uint64_t>(
        reinterpret_cast<const uint8_t*>(content_string.c_str()), content_string.size());

    std::string var_name    = var_namePrefix + "_" + std::to_string(GetNextId());
    struct_map_[hash_value] = var_name;

    return var_name;
}

void VulkanCppConsumerBase::AddKnownVariables(const std::string& type, const std::string& name)
{
    GfxToCppVariable new_var = { type, name, 0 };
    auto             found   = std::find_if(
        variable_data_.begin(), variable_data_.end(), [&cur_var = new_var](const GfxToCppVariable& v) -> bool {
            return (cur_var.type == v.type && cur_var.name == v.name && cur_var.count == v.count);
        });
    if (found == variable_data_.end())
    {
        variable_data_.emplace_back(new_var);
    }
}

void VulkanCppConsumerBase::AddKnownVariables(const std::string& type, const std::string& name, uint32_t count)
{
    GfxToCppVariable new_var = { type, name, count };
    auto             found   = std::find_if(
        variable_data_.begin(), variable_data_.end(), [&cur_var = new_var](const GfxToCppVariable& v) -> bool {
            return (cur_var.type == v.type && cur_var.name == v.name && cur_var.count == v.count);
        });
    if (found == variable_data_.end())
    {
        variable_data_.emplace_back(new_var);
    }
}

void VulkanCppConsumerBase::AddKnownVariables(const std::string&      type,
                                              const std::string&      name,
                                              const format::HandleId* handleId)
{
    GfxToCppVariable variable = { type, name, 0 };
    variable_data_.emplace_back(variable);
}

void VulkanCppConsumerBase::AddKnownVariables(const std::string&      type,
                                              const std::string&      name,
                                              const format::HandleId* handleId,
                                              uint32_t                count)
{
    GfxToCppVariable variable = { type, name, count };
    variable_data_.emplace_back(variable);
}

void VulkanCppConsumerBase::SetMemoryResourceMap(
    const std::map<format::HandleId, std::queue<std::pair<format::HandleId, VkDeviceSize>>> memoryImageMap)
{
    memory_resource_map_ = memoryImageMap;
}

void VulkanCppConsumerBase::SetWindowSize(uint32_t width, uint32_t height)
{
    window_width_  = width;
    window_height_ = height;
}

uint32_t VulkanCppConsumerBase::GetNextId()
{
    return counters_[VK_OBJECT_TYPE_UNKNOWN]++;
}

uint32_t VulkanCppConsumerBase::GetNextId(VkObjectType object_type)
{
    if (counters_.find(object_type) == counters_.end())
    {
        counters_[object_type] = 0;
    }
    return counters_[object_type]++;
}

// Meta data commands

void VulkanCppConsumerBase::ProcessDisplayMessageCommand(const std::string& message)
{
    GFXRECON_LOG_INFO("ProcessDisplayMessageCommand: %s", message.c_str());
}

void VulkanCppConsumerBase::ProcessSetDeviceMemoryPropertiesCommand(
    format::HandleId                             physical_device_id,
    const std::vector<format::DeviceMemoryType>& memory_types,
    const std::vector<format::DeviceMemoryHeap>& memory_heaps)
{
    original_memory_types_.push_back(memory_types);
    original_memory_heaps_.push_back(memory_heaps);
}

void VulkanCppConsumerBase::ProcessFillMemoryCommand(uint64_t       memory_id,
                                                     uint64_t       offset,
                                                     uint64_t       size,
                                                     const uint8_t* data)
{
    const SavedFileInfo file_info = data_packer_.AddFileContents(data, size);

    auto entry = memory_id_map_.find(memory_id);
    if (entry != memory_id_map_.end())
    {
        GenerateLoadData(file_info.file_path, file_info.byte_offset, memory_id_map_[memory_id].c_str(), offset, size);
    }
    else if (android_memory_id_map_.find(memory_id) != android_memory_id_map_.end())
    {
        // Update the memory using the Android Hardware buffer path (using "vulkan_replay_consumer_base" as a reference)
        VulkanCppAndroidMemoryInfo android_memory_info = android_memory_id_map_[memory_id];
        std::string                android_hw_mem_name = android_memory_info.name;
        FILE*                      file                = GetFrameFile();
        fprintf(file, "#if defined(VK_USE_PLATFORM_ANDROID_KHR)\n");
        fprintf(file, "\t{\n");
        fprintf(file, "\t\tresult            = VK_SUCCESS;\n");
        fprintf(file, "\t\tvoid* buffer_data = nullptr;\n");
        fprintf(file, "\t\tint lock_result   = AHardwareBuffer_lock(\n");
        fprintf(file,
                "\t\t\t%s, AHARDWAREBUFFER_USAGE_CPU_WRITE_OFTEN, -1, nullptr, &buffer_data);\n",
                android_memory_info.buffer_name.c_str());
        fprintf(file, "\t\tif (lock_result == 0)\n");
        fprintf(file, "\t\t{\n");
        fprintf(file, "\t\t\tassert(buffer_data != nullptr);\n");
        fprintf(file, "\t\t\tif (%s.plane_info.size() == 1)\n", android_hw_mem_name.c_str());
        fprintf(file, "\t\t\t{\n");
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size);
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, offset);
        fprintf(file, "\t\t\t\tsize_t   data_size         = static_cast<size_t>(%" PRIu64 ");\n", size);
        fprintf(file, "\t\t\t\tsize_t   data_offset       = static_cast<size_t>(%" PRIu64 ");\n", offset);
        fprintf(file,
                "\t\t\t\tsize_t   capture_row_pitch = %s.plane_info[0].capture_row_pitch;\n",
                android_hw_mem_name.c_str());
        fprintf(file,
                "\t\t\t\tsize_t   replay_row_pitch  = %s.plane_info[0].replay_row_pitch;\n",
                android_hw_mem_name.c_str());
        fprintf(file, "\t\t\t\tuint32_t height            = %s.plane_info[0].height;\n", android_hw_mem_name.c_str());
        fprintf(file, "\t\t\t\tCopyImageSubresourceMemory(%s,\n", file_info.file_path.c_str());
        fprintf(file, "\t\t\t\t\t\t\t\t\t%" PRIu64 ",\n", file_info.byte_offset);
        fprintf(file, "\t\t\t\t\t\t\t\t\tstatic_cast<uint8_t*>(buffer_data),\n");
        fprintf(file, "\t\t\t\t\t\t\t\t\toffset,v\n");
        fprintf(file, "\t\t\t\t\t\t\t\t\tdata_size,v\n");
        fprintf(file, "\t\t\t\t\t\t\t\t\treplay_row_pitch,\n");
        fprintf(file, "\t\t\t\t\t\t\t\t\tcapture_row_pitch,\n");
        fprintf(file, "\t\t\t\t\t\t\t\t\theight,\n");
        fprintf(file, "\t\t\t\t\t\t\t\t\tappdata);\n");
        fprintf(file, "\t\t\t}\n");
        fprintf(file, "\t\t\telse\n");
        fprintf(file, "\t\t\t{\n");
        fprintf(file, "\t\t\t\t// TODO: multi-plane image format support when strides do not match.\n");
        fprintf(file,
                "\t\t\t\tprintf(\"ERROR: Ignoring fill memory command for AHardwareBuffer with multi-plane "
                "format and\"\n");
        fprintf(file, "\t\t\t\t\t\"mismatched capture/replay strides (Memory ID = %%\" PRIu64\n");
        fprintf(file, "\t\t\t\t\t\"): support not yet implemented\",\n");
        fprintf(file, "\t\t\t\t\tmemory_id);\n");
        fprintf(file, "\t\t\t}\n");
        fprintf(file,
                "\t\t\tlock_result = AHardwareBuffer_unlock(%s, nullptr);\n",
                android_memory_info.buffer_name.c_str());
        fprintf(file, "\t\t\tif (lock_result != 0)\n");
        fprintf(file, "\t\t\t{\n");
        fprintf(file,
                "\t\t\t\tprintf(\"ERROR: AHardwareBuffer_unlock failed for AHardwareBuffer object (Memory ID = "
                "%%\" PRIu64 \")\",\n");
        fprintf(file, "\t\t\t\t\t\t%" PRIu64 ");\n", memory_id);
        fprintf(file, "\t\t\t}\n");
        fprintf(file, "\t\t}\n");
        fprintf(file, "\t\telse\n");
        fprintf(file, "\t\t{\n");
        fprintf(file,
                "\t\t\tprintf(\"ERROR: AHardwareBuffer_lock failed for AHardwareBuffer object (Memory ID = %%\" "
                "PRIu64 \")\",\n");
        fprintf(file, "\t\t\t\t\t%" PRIu64 ");\n", memory_id);
        fprintf(file, "\t\t}\n");
        fprintf(file, "\t}\n");
        fprintf(file, "#endif\n");
    }
}

void VulkanCppConsumerBase::ProcessResizeWindowCommand(format::HandleId surface_id, uint32_t width, uint32_t height)
{
    ProcessResizeWindowCommand2(surface_id, width, height, 0);
}

void VulkanCppConsumerBase::ProcessResizeWindowCommand2(format::HandleId surface_id,
                                                        uint32_t         width,
                                                        uint32_t         height,
                                                        uint32_t         pre_transform)
{
    FILE* file = GetFrameFile();

    window_width_  = width;
    window_height_ = height;

    if (platform_ == GfxToCppPlatform::PLATFORM_ANDROID)
    {
        fprintf(
            file, "\tscreen.windowSetSizePreTransform(%u, %u, %u);\n", window_width_, window_height_, pre_transform);
    }
    else
    {
        fprintf(file, "\tUpdateWindowSize(%u, %u, %u, appdata);\n", window_width_, window_height_, pre_transform);
    }
}

void VulkanCppConsumerBase::ProcessCreateHardwareBufferCommand(
    format::HandleId                                    device_id,
    format::HandleId                                    memory_id,
    uint64_t                                            buffer_id,
    uint32_t                                            format,
    uint32_t                                            width,
    uint32_t                                            height,
    uint32_t                                            stride,
    uint64_t                                            usage,
    uint32_t                                            layers,
    const std::vector<format::HardwareBufferPlaneInfo>& plane_info)
{
    // Create an Android Hardware buffer using the code from "vulkan_replay_consumer_base" as a reference.
    if (platform_ == GfxToCppPlatform::PLATFORM_ANDROID)
    {
        FILE* file = GetFrameFile();

        VulkanCppAndroidBufferInfo buffer_info;
        buffer_info.name      = "and_hw_buffer_" + std::to_string(GetNextId());
        buffer_info.memory_id = memory_id;
        AddKnownVariables("AHardwareBuffer*", buffer_info.name);
        android_buffer_id_map_[buffer_id] = buffer_info;

        VulkanCppAndroidMemoryInfo memory_info;
        memory_info.name        = "and_hw_buf_mem_info_" + std::to_string(GetNextId());
        memory_info.buffer_name = buffer_info.name;
        AddKnownVariables("HardwareBufferMemoryInfo", memory_info.name);
        android_memory_id_map_[memory_id] = memory_info;

        std::string memory_name;
        if (memory_id_map_.find(memory_id) != memory_id_map_.end())
        {
            memory_name = memory_id_map_[memory_id];
        }

        fprintf(file, "\t{\n");
        fprintf(file, "\t\tAHardwareBuffer_Desc desc = {};\n");
        fprintf(file, "\t\tdesc.format               = %u;\n", format);
        fprintf(file, "\t\tdesc.height               = %u;\n", height);
        fprintf(file, "\t\tdesc.layers               = %u;\n", layers);
        fprintf(file, "\t\tdesc.usage                = %" PRIu64 ";\n", usage);
        fprintf(file, "\t\tdesc.width                = %u;\n", width);
        fprintf(file, "\n");
        fprintf(file, "\t\tint ahwbuf_res = AHardwareBuffer_allocate(&desc, &%s);\n", buffer_info.name.c_str());
        fprintf(file, "\t\tif (ahwbuf_res == 0 && %s != nullptr)\n", buffer_info.name.c_str());
        fprintf(file, "\t\t{\n");
        fprintf(file, "\t\t\tahwbuf_res = -1;\n");
        fprintf(file, "\n");
        fprintf(file, "\t\t\tstd::vector<HardwareBufferPlaneInfo> replay_plane_info;\n");
        fprintf(file, "\n");
        fprintf(
            file,
            "// The multi-plane functions are declared for API 26, but are only available to link with API 29.  So, "
            "this\n");
        fprintf(file, "// could be turned into a run-time check dependent on dlsym returning a valid pointer for\n");
        fprintf(file, "// AHardwareBuffer_lockPlanes.\n");
        fprintf(file, "#if __ANDROID_API__ >= 29\n");
        fprintf(file, "\t\t\tif (desc.usage & AHARDWAREBUFFER_USAGE_CPU_WRITE_MASK)\n");
        fprintf(file, "\t\t\t{\n");
        fprintf(file, "\t\t\t\tAHardwareBuffer_Planes ahb_planes;\n");
        fprintf(file, "\t\t\t\tahwbuf_res =\n");
        fprintf(file,
                "\t\t\t\t\tAHardwareBuffer_lockPlanes(buffer, AHARDWAREBUFFER_USAGE_CPU_WRITE_OFTEN, -1, "
                "nullptr, &ahb_planes);\n");
        fprintf(file, "\t\t\t\tif (ahwbuf_res == 0)\n");
        fprintf(file, "\t\t\t\t{\n");
        fprintf(file, "\t\t\t\t\tvoid* data = ahb_planes.planes[0].data;\n");
        fprintf(file, "\n");
        fprintf(file, "\t\t\t\t\tfor (uint32_t i = 0; i < ahb_planes.planeCount; ++i)\n");
        fprintf(file, "\t\t\t\t\t{\n");
        fprintf(file, "\t\t\t\t\t\tHardwareBufferPlaneInfo ahb_plane_info;\n");
        fprintf(file, "\t\t\t\t\t\tahb_plane_info.offset =\n");
        fprintf(file,
                "\t\t\t\t\t\t\treinterpret_cast<uint8_t*>(ahb_planes.planes[i].data) - "
                "reinterpret_cast<uint8_t*>(data);\n");
        fprintf(file, "\t\t\t\t\t\tahb_plane_info.pixel_stride = ahb_planes.planes[i].pixelStride;\n");
        fprintf(file, "\t\t\t\t\t\tahb_plane_info.row_pitch    = ahb_planes.planes[i].rowStride;\n");
        fprintf(file, "\t\t\t\t\t\treplay_plane_info.emplace_back(std::move(ahb_plane_info));\n");
        fprintf(file, "\t\t\t\t\t}\n");
        fprintf(file, "\n");
        fprintf(file, "\t\t\t\t\t\tif (AHardwareBuffer_unlock(buffer, nullptr) != 0)\n");
        fprintf(file, "\t\t\t\t\t\t{\n");
        fprintf(file, "\t\t\t\t\t\t\tprintf(\"ERROR: AHardwareBuffer_unlock failed for AHardwareBuffer object\"\n");
        if (memory_name.length() > 0)
        {
            fprintf(
                file, "\t\t\t\t\t\t\t\"(Buffer %s, Memory %s)\");\n", buffer_info.name.c_str(), memory_name.c_str());
        }
        else
        {
            fprintf(file, "\t\t\t\t\t\t\t\"(Buffer %s)\");\n", buffer_info.name.c_str());
        }
        fprintf(file, "\t\t\t\t\t}\n");
        fprintf(file, "\t\t\t\t}\n");
        fprintf(file, "\t\t\t\telse\n");
        fprintf(file, "\t\t\t\t{\n");
        fprintf(file, "\t\t\t\t\tprintf(\"WARNING: AHardwareBuffer_lockPlanes failed.\");\n");
        fprintf(file, "\t\t\t\t}\n");
        fprintf(file, "\t\t\t}\n");
        fprintf(file, "#endif\n");

        fprintf(file, "\n");
        fprintf(file, "\t\t\t%s.compatible_strides = true;\n", memory_info.name.c_str());
        fprintf(file, "\n");
        fprintf(file, "\t\t\t// Check for matching strides.\n");
        if (plane_info.empty())
        {
            fprintf(file, "\t\t\tuint32_t bpp = GetHardwareBufferFormatBpp(%u);\n", format);
            fprintf(file, "\n");
            fprintf(file, "\t\t\tAHardwareBuffer_describe(%s, &desc);\n", buffer_info.name.c_str());
            fprintf(file, "\t\t\tif (%u != desc.stride)\n", stride);
            fprintf(file, "\t\t\t{\n");
            fprintf(file, "\t\t\t\t%s.compatible_strides = false;\n", memory_info.name.c_str());
            fprintf(file, "\t\t\t}\n");
            fprintf(file, "\n");
            fprintf(file, "\t\t\t%s.plane_info.resize(1);\n", memory_info.name.c_str());
            fprintf(file, "\t\t\t%s.plane_info[0].capture_offset    = 0;\n", memory_info.name.c_str());
            fprintf(file, "\t\t\t%s.plane_info[0].replay_offset     = 0;\n", memory_info.name.c_str());
            fprintf(file, "\t\t\t%s.plane_info[0].capture_row_pitch = bpp * %u;\n", memory_info.name.c_str(), stride);
            fprintf(file, "\t\t\t%s.plane_info[0].replay_row_pitch  = bpp * desc.stride;\n", memory_info.name.c_str());
            fprintf(file, "\t\t\t%s.plane_info[0].height            = %u;\n", memory_info.name.c_str(), height);
        }
        else
        {
            fprintf(file,
                    "\t\t\t%s.plane_info.resize(%" PRIu64 ");\n",
                    memory_info.name.c_str(),
                    util::platform::SizeTtoUint64(plane_info.size()));
            fprintf(file, "\n");
            for (uint32_t i = 0; i < static_cast<uint32_t>(plane_info.size()); ++i)
            {
                fprintf(file,
                        "\t\t\t%s.plane_info[%u].capture_offset    = %" PRId64 ";\n",
                        memory_info.name.c_str(),
                        i,
                        plane_info[i].offset);
                fprintf(file,
                        "\t\t\t%s.plane_info[%u].replay_offset     = replay_plane_info[%u].offset;\n",
                        memory_info.name.c_str(),
                        i,
                        i);
                fprintf(file,
                        "\t\t\t%s.plane_info[%u].capture_row_pitch = %u;\n",
                        memory_info.name.c_str(),
                        i,
                        plane_info[i].row_pitch);
                fprintf(file,
                        "\t\t\t%s.plane_info[%u].replay_row_pitch  = replay_plane_info[%u].row_pitch;\n",
                        memory_info.name.c_str(),
                        i,
                        i);
                fprintf(file, "\t\t\t%s.plane_info[%u].height            = %u;\n", memory_info.name.c_str(), i, height);
                fprintf(file, "\n");
                fprintf(file, "\t\t\tif ((%" PRIu64 " != replay_plane_info[%u].offset) ||\n", plane_info[i].offset, i);
                fprintf(file, "\t\t\t\t(%u != replay_plane_info[%u].row_pitch))\n", plane_info[i].row_pitch, i);
                fprintf(file, "\t\t\t{\n");
                fprintf(file, "\t\t\t\t%s.compatible_strides = false;\n", memory_info.name.c_str());
                fprintf(file, "\t\t\t}\n");
            }
        }

        fprintf(file, "\t\t}\n");
        fprintf(file, "\t\telse\n");
        fprintf(file, "\t\t{\n");
        fprintf(file, "\t\t\tprintf(\"ERROR: AHardwareBuffer_allocate failed for AHardwareBuffer object \"\n");
        if (memory_name.length() > 0)
        {
            fprintf(file, "\t\t\t\t\t\"(Buffer %s, Memory %s)\");\n", buffer_info.name.c_str(), memory_name.c_str());
        }
        else
        {
            fprintf(file, "\t\t\t\t\t\"(Buffer %s)\");\n", buffer_info.name.c_str());
        }
        fprintf(file, "\t\t}\n");
        fprintf(file, "\t}\n");
    }
}

std::string VulkanCppConsumerBase::GetAndroidHwBufferName(uint64_t buffer)
{
    if (android_buffer_id_map_.find(buffer) != android_buffer_id_map_.end())
    {
        return android_buffer_id_map_[buffer].name;
    }
    return "VK_NULL_HANDLE";
}

void VulkanCppConsumerBase::ProcessSetOpaqueAddressCommand(format::HandleId device_id,
                                                           format::HandleId object_id,
                                                           uint64_t         address)
{
    if (device_info_map_.find(device_id) != device_info_map_.end())
    {
        VkDeviceInfo* dev_info = device_info_map_[device_id];
        // Store the opaque address to use at object creation.
        dev_info->opaque_addresses[object_id] = address;
    }
}

void VulkanCppConsumerBase::Generate_vkGetDeviceQueue(format::HandleId               device,
                                                      uint32_t                       queueFamilyIndex,
                                                      uint32_t                       queueIndex,
                                                      HandlePointerDecoder<VkQueue>* pQueue)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pqueue_name = "pQueue_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_QUEUE));
    AddKnownVariables("VkQueue", pqueue_name, pQueue->GetPointer());
    this->AddHandles(pqueue_name, pQueue->GetPointer());
    fprintf(file,
            "\t\ttoCppGetDeviceQueue(%s, %u, %u, &%s);\n",
            this->GetHandle(device).c_str(),
            queueFamilyIndex,
            queueIndex,
            pqueue_name.c_str());
    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::Generate_vkGetAndroidHardwareBufferPropertiesANDROID(
    VkResult                                                                returnValue,
    format::HandleId                                                        device,
    uint64_t                                                                buffer,
    StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>* pProperties)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");

    std::string buffer_name;
    if (android_buffer_id_map_.find(buffer) == android_buffer_id_map_.end())
    {
        buffer_name = "buffer_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tvoid* %s;\n", buffer_name.c_str());
    }
    else
    {
        buffer_name = android_buffer_id_map_[buffer].name;
    }

    std::string       properties_name = "properties_" + std::to_string(this->GetNextId());
    std::stringstream stream_properties;
    properties_name = GenerateStruct_VkAndroidHardwareBufferPropertiesANDROID(
        stream_properties, pProperties->GetPointer(), pProperties->GetMetaStructPointer(), *this);
    fprintf(file, "%s", stream_properties.str().c_str());
    pfn_loader_.AddMethodName("vkGetAndroidHardwareBufferPropertiesANDROID");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetAndroidHardwareBufferPropertiesANDROID(%s, %s, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            buffer_name.c_str(),
            properties_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());

    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::Generate_vkGetMemoryAndroidHardwareBufferANDROID(
    VkResult                                                                   returnValue,
    format::HandleId                                                           device,
    StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID>* pInfo,
    PointerDecoder<uint64_t, void*>*                                           pBuffer)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");

    std::stringstream stream_info;
    std::string       info_struct = GenerateStruct_VkMemoryGetAndroidHardwareBufferInfoANDROID(
        stream_info, pInfo->GetPointer(), pInfo->GetMetaStructPointer(), *this);
    fprintf(file, "%s", stream_info.str().c_str());

    format::HandleId memory_id = pInfo->GetMetaStructPointer()->memory;

    std::string buffer_name;
    std::string buffer_argument;
    if (pBuffer->IsNull())
    {
        buffer_name     = "";
        buffer_argument = "nullptr";
    }
    else
    {
        buffer_name     = "and_hw_buffer_" + std::to_string(GetNextId());
        buffer_argument = "&" + buffer_name;
    }

    VulkanCppAndroidBufferInfo buffer_info;
    buffer_info.name      = buffer_name;
    buffer_info.memory_id = memory_id;
    AddKnownVariables("AHardwareBuffer*", buffer_info.name);

    // TODO: Not sure if this is necessary
    VulkanCppAndroidMemoryInfo memory_info;
    memory_info.name                  = "";
    memory_info.buffer_name           = buffer_name;
    android_memory_id_map_[memory_id] = memory_info;

    pfn_loader_.AddMethodName("vkGetMemoryAndroidHardwareBufferANDROID");

    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetMemoryAndroidHardwareBufferANDROID(%s, &%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            info_struct.c_str(),
            buffer_argument.c_str(),
            util::ToString<VkResult>(returnValue).c_str());

    android_buffer_id_map_[*pBuffer->GetPointer()] = buffer_info;

    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::Generate_vkQueueSubmit(VkResult                                    returnValue,
                                                   format::HandleId                            queue,
                                                   uint32_t                                    submitCount,
                                                   StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
                                                   format::HandleId                            fence)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    // queue
    // submitCount
    // pSubmits
    std::stringstream stream_psubmits;
    std::string       psubmits_array = "NULL";
    PointerPairContainer<decltype(pSubmits->GetPointer()), decltype(pSubmits->GetMetaStructPointer())> psubmits_pair{
        pSubmits->GetPointer(), pSubmits->GetMetaStructPointer(), submitCount
    };
    std::string psubmits_names = toStringJoin(
        psubmits_pair.begin(),
        psubmits_pair.end(),
        [&](auto pair) {
            {
                return GenerateStruct_VkSubmitInfo(stream_psubmits, pair.t1, pair.t2, imported_semaphores_, *this);
            }
        },
        ", ");
    if (stream_psubmits.str().length() > 0)
    {
        fprintf(file, "%s", stream_psubmits.str().c_str());
        if (submitCount == 1)
        {
            psubmits_array = "&" + psubmits_names;
        }
        else if (submitCount > 1)
        {
            psubmits_array = "submits_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkSubmitInfo %s[] = { %s };\n", psubmits_array.c_str(), psubmits_names.c_str());
        }
    }
    // fence
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkQueueSubmit(%s, %u, %s, %s), %s);\n",
            this->GetHandle(queue).c_str(),
            submitCount,
            psubmits_array.c_str(),
            this->GetHandle(fence).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::Generate_vkQueueSubmit2(VkResult                                     returnValue,
                                                    format::HandleId                             queue,
                                                    uint32_t                                     submitCount,
                                                    StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
                                                    format::HandleId                             fence,
                                                    const char*                                  extension)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    // queue
    // submitCount
    // pSubmits
    std::stringstream stream_psubmits;
    std::string       psubmits_array = "NULL";
    PointerPairContainer<decltype(pSubmits->GetPointer()), decltype(pSubmits->GetMetaStructPointer())> psubmits_pair{
        pSubmits->GetPointer(), pSubmits->GetMetaStructPointer(), submitCount
    };
    std::string psubmits_names = toStringJoin(
        psubmits_pair.begin(),
        psubmits_pair.end(),
        [&](auto pair) {
            {
                return GenerateStruct_VkSubmitInfo2(stream_psubmits, pair.t1, pair.t2, imported_semaphores_, *this);
            }
        },
        ", ");
    if (stream_psubmits.str().length() > 0)
    {
        fprintf(file, "%s", stream_psubmits.str().c_str());
        if (submitCount == 1)
        {
            psubmits_array = "&" + psubmits_names;
        }
        else if (submitCount > 1)
        {
            psubmits_array = "submits_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkSubmitInfo2 %s[] = { %s };\n", psubmits_array.c_str(), psubmits_names.c_str());
        }
    }
    // fence
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkQueueSubmit2%s(%s, %u, %s, %s), %s);\n",
            extension,
            this->GetHandle(queue).c_str(),
            submitCount,
            psubmits_array.c_str(),
            this->GetHandle(fence).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::Generate_vkQueueBindSparse(VkResult                                        returnValue,
                                                       format::HandleId                                queue,
                                                       uint32_t                                        bindInfoCount,
                                                       StructPointerDecoder<Decoded_VkBindSparseInfo>* pBindInfo,
                                                       format::HandleId                                fence)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    // queue
    // bindInfoCount
    // pBindInfo
    std::stringstream stream_pbind_info;
    std::string       pbind_info_array = "NULL";
    PointerPairContainer<decltype(pBindInfo->GetPointer()), decltype(pBindInfo->GetMetaStructPointer())>
                pbind_info_pair{ pBindInfo->GetPointer(), pBindInfo->GetMetaStructPointer(), bindInfoCount };
    std::string pbind_info_names = toStringJoin(
        pbind_info_pair.begin(),
        pbind_info_pair.end(),
        [&](auto pair) {
            {
                return GenerateStruct_VkBindSparseInfo(
                    stream_pbind_info, pair.t1, pair.t2, imported_semaphores_, *this);
            }
        },
        ", ");
    if (stream_pbind_info.str().length() > 0)
    {
        fprintf(file, "%s", stream_pbind_info.str().c_str());
        if (bindInfoCount == 1)
        {
            pbind_info_array = "&" + pbind_info_names;
        }
        else if (bindInfoCount > 1)
        {
            pbind_info_array = "bind_info_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBindSparseInfo %s[] = { %s };\n", pbind_info_array.c_str(), pbind_info_names.c_str());
        }
    }
    // fence
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkQueueBindSparse(%s, %u, %s, %s), %s);\n",
            this->GetHandle(queue).c_str(),
            bindInfoCount,
            pbind_info_array.c_str(),
            this->GetHandle(fence).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::Generate_vkQueuePresentKHR(VkResult                                        returnValue,
                                                       format::HandleId                                queue,
                                                       StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_present_info;
    std::string       present_info_struct = GenerateStruct_VkPresentInfoKHR(stream_present_info,
                                                                      pPresentInfo->GetPointer(),
                                                                      pPresentInfo->GetMetaStructPointer(),
                                                                      imported_semaphores_,
                                                                      *this);
    fprintf(file, "%s", stream_present_info.str().c_str());
    pfn_loader_.AddMethodName("vkQueuePresentKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(toCppQueuePresentKHR(%s, &%s), %s);\n",
            this->GetHandle(queue).c_str(),
            present_info_struct.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::ProcessDestroyHardwareBufferCommand(uint64_t buffer_id)
{
    if (android_buffer_id_map_.find(buffer_id) != android_buffer_id_map_.end())
    {
        auto& buffer_info = android_buffer_id_map_[buffer_id];
        FILE* file        = GetFrameFile();
        fprintf(file, "\t{\n");
        fprintf(file, "\t\tAHardwareBuffer_release(%s);\n", android_buffer_id_map_[buffer_id].name.c_str());
        android_memory_id_map_.erase(buffer_info.memory_id);
        android_buffer_id_map_.erase(buffer_id);
        fprintf(file, "\t}\n");
    }
}

void VulkanCppConsumerBase::Process_vkUpdateDescriptorSetWithTemplate(const ApiCallInfo& call_info,
                                                                      format::HandleId   device,
                                                                      format::HandleId   descriptorSet,
                                                                      format::HandleId   descriptorUpdateTemplate,
                                                                      DescriptorUpdateTemplateDecoder* pData)
{
    Generate_vkUpdateDescriptorSetWithTemplate(device, descriptorSet, descriptorUpdateTemplate, pData);
    Post_APICall(format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate);
}

void VulkanCppConsumerBase::Process_vkCmdPushDescriptorSetWithTemplateKHR(const ApiCallInfo& call_info,
                                                                          format::HandleId   commandBuffer,
                                                                          format::HandleId   descriptorUpdateTemplate,
                                                                          format::HandleId   layout,
                                                                          uint32_t           set,
                                                                          DescriptorUpdateTemplateDecoder* pData)
{
    FILE*       file = GetFrameFile();
    std::string var_name;

    fprintf(file, "\t{\n");

    GenerateDescriptorUpdateTemplateData(pData, descriptorUpdateTemplate, file, var_name);

    pfn_loader_.AddMethodName("vkCmdPushDescriptorSetWithTemplateKHR");
    fprintf(file,
            "\t\tloaded_vkCmdPushDescriptorSetWithTemplateKHR(%s, %s, %s, %u, %s);\n",
            this->GetHandle(commandBuffer).c_str(),
            this->GetHandle(descriptorUpdateTemplate).c_str(),
            this->GetHandle(layout).c_str(),
            set,
            var_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR);
}

void VulkanCppConsumerBase::Process_vkUpdateDescriptorSetWithTemplateKHR(const ApiCallInfo& call_info,
                                                                         format::HandleId   device,
                                                                         format::HandleId   descriptorSet,
                                                                         format::HandleId   descriptorUpdateTemplate,
                                                                         DescriptorUpdateTemplateDecoder* pData)
{
    Generate_vkUpdateDescriptorSetWithTemplateKHR(device, descriptorSet, descriptorUpdateTemplate, pData);
    Post_APICall(format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR);
}

void VulkanCppConsumerBase::Process_vkCmdPushDescriptorSetWithTemplate2KHR(
    const ApiCallInfo&                                                 call_info,
    format::HandleId                                                   commandBuffer,
    StructPointerDecoder<Decoded_VkPushDescriptorSetWithTemplateInfo>* pPushDescriptorSetWithTemplateInfo)
{
    FILE*       file = GetFrameFile();
    std::string var_name;

    Decoded_VkPushDescriptorSetWithTemplateInfo* decoded_info =
        pPushDescriptorSetWithTemplateInfo->GetMetaStructPointer();

    fprintf(file, "\t{\n");

    pfn_loader_.AddMethodName("vkCmdPushDescriptorSetWithTemplate2KHR");

    DescriptorUpdateTemplateDecoder pData;
    const uint8_t*                  ptr = static_cast<const uint8_t*>(decoded_info->pNext->GetPointer());
    pData.Decode(ptr, pData.GetLength());
    GenerateDescriptorUpdateTemplateData(&pData, decoded_info->descriptorUpdateTemplate, file, var_name);

    fprintf(file,
            "\t\tVkPushDescriptorSetWithTemplateInfoKHR info;\n\
                        \t\tinfo.sType = VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_WITH_TEMPLATE_INFO_KHR;\n\
                        \t\tinfo.pNext = nullptr;\n\
                        \t\tinfo.descriptorUpdateTemplate = %s;\n\
                        \t\tinfo.layout = %s\n\
                        \t\tinfo.set = %u\n\
                        \t\tinfo.pData = %s\n",
            this->GetHandle(decoded_info->descriptorUpdateTemplate).c_str(),
            this->GetHandle(decoded_info->layout).c_str(),
            decoded_info->decoded_value->set,
            var_name.c_str());

    fprintf(file,
            "\t\tloaded_vkCmdPushDescriptorSetWithTemplate2KHR(%s, &info);\n",
            this->GetHandle(commandBuffer).c_str());
    fprintf(file, "\t}\n");

    Post_APICall(format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplate2KHR);
}

void VulkanCppConsumerBase::Process_vkCreateRayTracingPipelinesKHR(
    const ApiCallInfo&                                               call_info,
    VkResult                                                         returnValue,
    format::HandleId                                                 device,
    format::HandleId                                                 deferredOperation,
    format::HandleId                                                 pipelineCache,
    uint32_t                                                         createInfoCount,
    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*             pAllocator,
    HandlePointerDecoder<VkPipeline>*                                pPipelines)
{
    Generate_vkCreateRayTracingPipelinesKHR(
        returnValue, device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR);
}

void VulkanCppConsumerBase::Process_vkDeferredOperationJoinKHR(const ApiCallInfo& call_info,
                                                               VkResult           returnValue,
                                                               format::HandleId   device,
                                                               format::HandleId   operation)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    // device
    // operation
    pfn_loader_.AddMethodName("vkDeferredOperationJoinKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkDeferredOperationJoinKHR(%s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(operation).c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
