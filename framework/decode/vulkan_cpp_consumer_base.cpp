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

const GfxToCppPlatform GetGfxToCppPlatform(const std::string& format_str);

const std::string      GfxToCppPlatformToString(GfxToCppPlatform platform);

VulkanCppConsumerBase::VulkanCppConsumerBase() :
    frame_file_(nullptr), global_file_(nullptr), main_file_(nullptr), pfn_loader_()
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
    if (result != 0)
    {
        GFXRECON_LOG_ERROR("Error while opening file: %s", filename.c_str());
        return false;
    }

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

    return true;
}

void VulkanCppConsumerBase::RecordDeviceSelectionData(format::HandleId          physicalDevice,
                                                      const VkDeviceCreateInfo* createInfo)
{
    // Find which slot of the enumeration held this physical device.
    for (uint32_t index = 0; index < enumerated_physical_devices_.size(); ++index)
    {
        if (enumerated_physical_devices_[index] != physicalDevice)
        {
            continue;
        }
        if (std::find(used_physical_device_indices_.begin(), used_physical_device_indices_.end(), index) ==
            used_physical_device_indices_.end())
        {
            used_physical_device_indices_.push_back(index);
        }
        break;
    }

    if (createInfo == nullptr)
    {
        return;
    }

    for (uint32_t index = 0; index < createInfo->enabledExtensionCount; ++index)
    {
        const char* name = createInfo->ppEnabledExtensionNames[index];
        if (name == nullptr)
        {
            continue;
        }
        if (std::find(required_device_extensions_.begin(), required_device_extensions_.end(), name) ==
            required_device_extensions_.end())
        {
            required_device_extensions_.emplace_back(name);
        }
    }
}

void VulkanCppConsumerBase::PrintOutDeviceSelectionData(FILE* file)
{
    fprintf(file, "\nconst char* const g_required_device_extensions[] = {\n");
    for (const std::string& name : required_device_extensions_)
    {
        fprintf(file, "    \"%s\",\n", name.c_str());
    }
    // Keep at least one entry so that the array is valid C++.
    if (required_device_extensions_.empty())
    {
        fprintf(file, "    nullptr,\n");
    }
    fprintf(file, "};\n");
    fprintf(file,
            "const uint32_t g_required_device_extension_count = %" PRIu64 ";\n",
            util::platform::SizeTtoUint64(required_device_extensions_.size()));

    fprintf(file, "\nconst uint32_t g_captured_device_indices[] = {\n");
    for (uint32_t index : used_physical_device_indices_)
    {
        fprintf(file, "    %u,\n", index);
    }
    if (used_physical_device_indices_.empty())
    {
        fprintf(file, "    0,\n");
    }
    fprintf(file, "};\n");
    fprintf(file,
            "const uint32_t g_captured_device_index_count = %" PRIu64 ";\n",
            util::platform::SizeTtoUint64(used_physical_device_indices_.size()));
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

        PrintOutDeviceSelectionData(global_file);
        fputs(sCommonSelectPhysicalDevices, global_file);
        fputs(sCommonFilterDeviceExtensions, global_file);
        fputs(sCommonParseCommandLine, global_file);
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
        if (WriteGlobalHeaderFile())
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

    // The frame body is inside a function, so statements start one level in.
    frame_writer_.SetFile(frame_file_, 1);

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
    frame_writer_.SetFile(nullptr);

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

void VulkanCppConsumerBase::Intercept_vkCreateFramebuffer(args::CreateFramebuffer& args)
{
    if (platform_ == GfxToCppPlatform::PLATFORM_ANDROID)
    {
        VkFramebufferCreateInfo* struct_info = args.pCreateInfo.GetPointer();
        struct_info->width                   = GetProperWindowWidth(struct_info->width);
        struct_info->height                  = GetProperWindowHeight(struct_info->height);
    }
}

void VulkanCppConsumerBase::Intercept_vkCmdBeginRenderPass(args::CmdBeginRenderPass& args)
{
    if (platform_ == GfxToCppPlatform::PLATFORM_ANDROID)
    {
        // TODO: This completely breaks desktop, especially if anti-aliasing is enabled.
        //       Leaving this in as the original drop had this code and it may be required
        //       for Android.  But it needs verification.
        VkRenderPassBeginInfo* struct_info    = args.pRenderPassBegin.GetPointer();
        struct_info->renderArea.extent.width  = GetProperWindowWidth(struct_info->renderArea.extent.width);
        struct_info->renderArea.extent.height = GetProperWindowHeight(struct_info->renderArea.extent.height);
    }
}

void VulkanCppConsumerBase::Generate_vkUpdateDescriptorSetWithTemplate(args::UpdateDescriptorSetWithTemplate& args,
                                                                       const char*                            extension)
{
    FILE*       file = GetFrameFile();
    std::string var_name;

    fprintf(file, "\t{\n");

    GenerateDescriptorUpdateTemplateData(&args.pData, args.descriptorUpdateTemplate, file, var_name);

    std::string method_name = "vkUpdateDescriptorSetWithTemplate";
    method_name += extension;
    pfn_loader_.AddMethodName(method_name);
    fprintf(file,
            "\t\tloaded_%s(%s, %s, %s, &%s);\n",
            method_name.c_str(),
            GetHandle(args.device).c_str(),
            GetHandle(args.descriptorSet).c_str(),
            GetHandle(args.descriptorUpdateTemplate).c_str(),
            var_name.c_str());
    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::Generate_vkSetDebugUtilsObjectNameEXT(args::SetDebugUtilsObjectNameEXT& args) {}

void VulkanCppConsumerBase::Generate_vkSetDebugUtilsObjectTagEXT(args::SetDebugUtilsObjectTagEXT& args) {}

void VulkanCppConsumerBase::Generate_vkDebugMarkerSetObjectNameEXT(args::DebugMarkerSetObjectNameEXT& args) {}

void VulkanCppConsumerBase::Generate_vkDebugMarkerSetObjectTagEXT(args::DebugMarkerSetObjectTagEXT& args) {}

const GfxToCppPlatform getGfxToCppPlatform(const std::string& format_str)
{
    return kTargetPlatformByName.at(format_str);
}

const std::string GfxToCppPlatformToString(GfxToCppPlatform platform)
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

void VulkanCppConsumerBase::SetMaxWindowSize(uint32_t maxWindowWidth, uint32_t maxWindowHeight)
{
    max_window_width_  = maxWindowWidth;
    max_window_height_ = maxWindowHeight;

    // Apply the new limit to the current size.
    window_width_  = std::min(window_width_, max_window_width_);
    window_height_ = std::min(window_height_, max_window_height_);
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

    window_width_  = std::min(width, max_window_width_);
    window_height_ = std::min(height, max_window_height_);

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

void VulkanCppConsumerBase::Process_vkUpdateDescriptorSetWithTemplate(const ApiCallInfo&                     call_info,
                                                                      args::UpdateDescriptorSetWithTemplate& args)
{
    Generate_vkUpdateDescriptorSetWithTemplate(args);
    Post_APICall(format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate);
}

void VulkanCppConsumerBase::Process_vkCmdPushDescriptorSetWithTemplateKHR(
    const ApiCallInfo& call_info, args::CmdPushDescriptorSetWithTemplateKHR& args)
{
    FILE*       file = GetFrameFile();
    std::string var_name;

    fprintf(file, "\t{\n");

    GenerateDescriptorUpdateTemplateData(&args.pData, args.descriptorUpdateTemplate, file, var_name);

    pfn_loader_.AddMethodName("vkCmdPushDescriptorSetWithTemplateKHR");
    fprintf(file,
            "\t\tloaded_vkCmdPushDescriptorSetWithTemplateKHR(%s, %s, %s, %u, %s);\n",
            this->GetHandle(args.commandBuffer).c_str(),
            this->GetHandle(args.descriptorUpdateTemplate).c_str(),
            this->GetHandle(args.layout).c_str(),
            args.set,
            var_name.c_str());
    fprintf(file, "\t}\n");
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR);
}

void VulkanCppConsumerBase::Process_vkUpdateDescriptorSetWithTemplateKHR(const ApiCallInfo& call_info,
                                                                         args::UpdateDescriptorSetWithTemplateKHR& args)
{
    Generate_vkUpdateDescriptorSetWithTemplateKHR(args);
    Post_APICall(format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR);
}

void VulkanCppConsumerBase::Process_vkCmdPushDescriptorSetWithTemplate2KHR(
    const ApiCallInfo& call_info, args::CmdPushDescriptorSetWithTemplate2KHR& args)
{
    FILE*       file = GetFrameFile();
    std::string var_name;

    Decoded_VkPushDescriptorSetWithTemplateInfo* decoded_info =
        args.pPushDescriptorSetWithTemplateInfo.GetMetaStructPointer();

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
                        \t\tinfo.layout = %s;\n\
                        \t\tinfo.set = %u;\n\
                        \t\tinfo.pData = &%s;\n",
            this->GetHandle(decoded_info->descriptorUpdateTemplate).c_str(),
            this->GetHandle(decoded_info->layout).c_str(),
            decoded_info->decoded_value->set,
            var_name.c_str());

    fprintf(file,
            "\t\tloaded_vkCmdPushDescriptorSetWithTemplate2KHR(%s, &info);\n",
            this->GetHandle(args.commandBuffer).c_str());
    fprintf(file, "\t}\n");

    Post_APICall(format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplate2KHR);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
