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

#include "decode/vulkan_cpp_consumer_base.h"
#include "decode/vulkan_cpp_template_strings.h"

#include "project_version.h"
#include "util/file_path.h"
#include "util/platform.h"
#include <util/xxhash64.h>
#include "decode/vulkan_cpp_structs.h"
#include <generated/generated_vulkan_cpp_structs.h>
#include "generated/generated_vulkan_cpp_consumer_extension.h"
#include "generated/generated_vulkan_enum_to_string.h"

#include <iomanip>
#include <cmath>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct GfxTocppPlatformMap
{
    GfxTocppPlatform platform;
    std::string      platform_str;
};

const GfxTocppPlatform getGfxTocppPlatform(const std::string& format_str);
const std::string      GfxTocppPlatformToString(GfxTocppPlatform platform);
bool                   gfxTocppPlatformIsValid(const GfxTocppPlatform& platform);

VulkanCppConsumerBase::VulkanCppConsumerBase() :
    m_frameFile(nullptr), m_global_file(nullptr), m_header_file(nullptr), m_main_file(nullptr), m_pfnLoader()
{
    m_counters[VK_OBJECT_TYPE_UNKNOWN] = 0;
}

VulkanCppConsumerBase::~VulkanCppConsumerBase()
{
    Destroy();
}

bool VulkanCppConsumerBase::createSubOutputDirectories(const std::vector<std::string>& subDirs)
{
    for (const std::string& subDir : subDirs)
    {
        std::string subOutDir = util::filepath::Join(m_outDir, subDir);
        if (util::filepath::Exists(subOutDir))
        {
            if (!util::filepath::IsDirectory(subOutDir))
            {
                GFXRECON_LOG_ERROR("Error while creating directory %s: already exists as file", subOutDir.c_str());
                return false;
            }
        }
        else
        {
            int result = util::platform::MakeDirectory(subOutDir.c_str());
            if (result < 0)
            {
                GFXRECON_LOG_ERROR("Error while creating directory %s: could not open", subOutDir.c_str());
                return false;
            }
        }
    }

    return true;
}

void VulkanCppConsumerBase::WriteMainHeader()
{
    switch (m_platform)
    {
        case GfxTocppPlatform::PLATFORM_ANDROID:
            fprintf(m_main_file, "%s", sAndroidOutputDrawFunctionStart);
            break;
        case GfxTocppPlatform::PLATFORM_WIN32:
            fprintf(m_main_file, "%s", sWin32OutputMainStart);
            break;
        case GfxTocppPlatform::PLATFORM_XCB:
            fprintf(m_main_file, "%s", sXcbOutputMainStart);
            break;
        case GfxTocppPlatform::PLATFORM_COUNT:
        default:
        {
            fprintf(m_main_file,
                    "// Nothing to generate for unknown platform: %s\n",
                    GfxTocppPlatformToString(m_platform).c_str());
            assert(false);
            break;
        }
    }
}

void VulkanCppConsumerBase::WriteMainFooter()
{
    switch (m_platform)
    {
        case GfxTocppPlatform::PLATFORM_ANDROID:
            fprintf(m_main_file, "%s", sAndroidOutputDrawFunctionEnd);
            break;
        case GfxTocppPlatform::PLATFORM_WIN32:
            fprintf(m_main_file, "%s", sWin32OutputMainEnd);
            break;
        case GfxTocppPlatform::PLATFORM_XCB:
            fprintf(m_main_file, "%s", sXcbOutputMainEnd);
            break;
        case GfxTocppPlatform::PLATFORM_COUNT:
        default:
        {
            fprintf(m_main_file,
                    "// Nothing to generate for unknown platform: %s\n",
                    GfxTocppPlatformToString(m_platform).c_str());
            assert(false);
            break;
        }
    }
}

void VulkanCppConsumerBase::WriteGlobalHeaderFile()
{
    switch (m_platform)
    {
        case GfxTocppPlatform::PLATFORM_ANDROID:
            fprintf(GetHeaderFile(),
                    "%s%s%s%s",
                    sAndroidOutputHeadersPlatform,
                    sCommonHeaderOutputHeaders,
                    sAndroidOutputHeader,
                    sCommonOutputHeaderFunctions);
            break;
        case GfxTocppPlatform::PLATFORM_WIN32:
            fprintf(GetHeaderFile(),
                    "%s%s%s%s",
                    sWin32OutputHeadersPlatform,
                    sCommonHeaderOutputHeaders,
                    sWin32OutputHeader,
                    sCommonOutputHeaderFunctions);
            break;
        case GfxTocppPlatform::PLATFORM_XCB:
            fprintf(GetHeaderFile(),
                    "%s%s%s%s",
                    sXcbOutputHeadersPlatform,
                    sCommonHeaderOutputHeaders,
                    sXcbOutputHeader,
                    sCommonOutputHeaderFunctions);
            break;
        case GfxTocppPlatform::PLATFORM_COUNT:
        default:
        {
            fprintf(m_main_file,
                    "// Nothing to generate for unknown platform: %s\n",
                    GfxTocppPlatformToString(m_platform).c_str());
            assert(false);
            break;
        }
    }

    PrintToFile(GetHeaderFile(), "extern %s;\n", GfxToCppVariable::toStrVec(m_var_data));

    PrintToFile(GetHeaderFile(), "%s", m_func_data);

    if (m_needsDebugUtilCallback)
    {
        fprintf(GetHeaderFile(), "VkBool32 vulkanCppDebugUtilsCallback(\n");
        fprintf(GetHeaderFile(), "    VkDebugUtilsMessageSeverityFlagBitsEXT           messageSeverity,\n");
        fprintf(GetHeaderFile(), "    VkDebugUtilsMessageTypeFlagsEXT                  messageTypes,\n");
        fprintf(GetHeaderFile(), "    const VkDebugUtilsMessengerCallbackDataEXT*      pCallbackData,\n");
        fprintf(GetHeaderFile(), "    void*                                            pUserData);\n");
    }

    fprintf(GetHeaderFile(), "%s", sCommonHeaderOutputFooter);
    util::platform::FileClose(m_header_file);
}

void VulkanCppConsumerBase::PrintOutCMakeFile()
{
    std::string filename = util::filepath::Join(m_outDir, "CMakeLists.txt");
    FILE*       cmakeFile;
    int32_t     result = util::platform::FileOpen(&cmakeFile, filename.c_str(), "w");
    if (result == 0)
    {
        switch (m_platform)
        {
            case GfxTocppPlatform::PLATFORM_ANDROID:
                // Nothing to do here
                break;
            case GfxTocppPlatform::PLATFORM_WIN32:
                fprintf(cmakeFile, "%s", sWin32CMakeFile);
                break;
            case GfxTocppPlatform::PLATFORM_XCB:
                fprintf(cmakeFile, "%s", sXcbCMakeFile);
                break;
            case GfxTocppPlatform::PLATFORM_COUNT:
            default:
            {
                fprintf(stderr, "Error while opening file: %s\n", filename.c_str());
                assert(false);
                break;
            }
        }
        util::platform::FileClose(cmakeFile);
    }
}

// Print the variable declarations to the 'global_var.cpp'.
void VulkanCppConsumerBase::PrintOutGlobalVar()
{
    std::string filename = util::filepath::Join(m_outDir, m_srcOutDir + "/global_var.cpp");
    int32_t     result   = util::platform::FileOpen(&m_global_file, filename.c_str(), "w");
    if (result == 0)
    {
        FILE* globalFile = GetGlobalFile();
        fputs(sCommonGlobalCppHeader, globalFile);

        size_t max_second_dimension = 1;
        for (const auto& pd_mem_types : m_original_memory_types)
        {
            if (pd_mem_types.size() > max_second_dimension)
            {
                max_second_dimension = pd_mem_types.size();
            }
        }

        fprintf(globalFile,
                "\nVkMemoryType originalMemoryTypes[%" PRId64 "][%" PRId64 "] = {\n",
                m_original_memory_types.size(),
                max_second_dimension);
        for (const auto& pd_mem_types : m_original_memory_types)
        {
            fprintf(globalFile, "  {\n");
            for (size_t index = 0; index < max_second_dimension; ++index)
            {
                if (index < pd_mem_types.size())
                {
                    fprintf(globalFile,
                            "  { %s, %d },\n",
                            util::ToString<VkMemoryPropertyFlags>(pd_mem_types[index].property_flags).c_str(),
                            pd_mem_types[index].heap_index);
                }
                else
                {
                    fprintf(globalFile, "  { 0, 0 },\n");
                }
            }
            for (const auto& cur_type : pd_mem_types)
            {
            }
            fprintf(globalFile, "  },\n");
        }
        fprintf(globalFile, "};\n");

        fputs(sCommonQueryPhysicalDeviceMemoryProperties, globalFile);
        fputs(sCommonRecalculateAllocationSize, globalFile);
        fputs(sCommonRecalculateMemoryTypeIndex, globalFile);
        fputs(sCommonLogVkError, globalFile);

        switch (m_platform)
        {
            case GfxTocppPlatform::PLATFORM_ANDROID:
                fputs(sAndroidOutputGlobalSource, globalFile);
                break;
            case GfxTocppPlatform::PLATFORM_WIN32:
            {
                int   size = snprintf(NULL, 0, sWin32OutputOverrideMethod, m_windowWidth, m_windowHeight);
                char* formattedOutputOverrideMethod = new char[size + 2];
                snprintf(
                    formattedOutputOverrideMethod, size + 2, sWin32OutputOverrideMethod, m_windowWidth, m_windowHeight);
                fputs(formattedOutputOverrideMethod, globalFile);
                delete[] formattedOutputOverrideMethod;
                break;
            }
            case GfxTocppPlatform::PLATFORM_XCB:
            {
                int   size = snprintf(NULL, 0, sXcbOutputOverrideMethod, m_windowWidth, m_windowHeight);
                char* formattedOutputOverrideMethod = new char[size + 2];
                snprintf(
                    formattedOutputOverrideMethod, size + 2, sXcbOutputOverrideMethod, m_windowWidth, m_windowHeight);
                fputs(formattedOutputOverrideMethod, globalFile);
                delete[] formattedOutputOverrideMethod;
                break;
            }
            case GfxTocppPlatform::PLATFORM_COUNT:
            default:
            {
                fprintf(m_main_file,
                        "// Nothing to generate for unknown platform: %s\n",
                        GfxTocppPlatformToString(m_platform).c_str());
                return;
            }
        }

        PrintToFile(globalFile, "%s;\n", GfxToCppVariable::toStrVec(m_var_data));

        if (m_needsDebugUtilCallback)
        {
            fprintf(globalFile, "\n");
            fprintf(globalFile, "VkBool32 vulkanCppDebugUtilsCallback(\n");
            fprintf(globalFile, "    VkDebugUtilsMessageSeverityFlagBitsEXT           messageSeverity,\n");
            fprintf(globalFile, "    VkDebugUtilsMessageTypeFlagsEXT                  messageTypes,\n");
            fprintf(globalFile, "    const VkDebugUtilsMessengerCallbackDataEXT*      pCallbackData,\n");
            fprintf(globalFile, "    void*                                            pUserData)\n");
            fprintf(globalFile, "{\n");
            fprintf(globalFile, "    (void)messageSeverity;\n");
            fprintf(globalFile, "    (void)messageTypes;\n");
            fprintf(globalFile, "    (void)pCallbackData;\n");
            fprintf(globalFile, "    (void)pUserData;\n");
            fprintf(globalFile, "    return VK_FALSE;\n");
            fprintf(globalFile, "}\n");
        }

        util::platform::FileClose(m_global_file);
    }
    else
    {
        fprintf(stderr, "Error while opening file: %s\n", filename.c_str());
    }
}

bool VulkanCppConsumerBase::Initialize(const std::string&      filename,
                                       const GfxTocppPlatform& platform,
                                       const std::string&      outputDir)
{
    bool success = false;

    if (m_main_file == nullptr)
    {
        int32_t result = util::platform::FileOpen(&m_main_file, filename.c_str(), "w");
        if (result == 0)
        {
            if (platform != GfxTocppPlatform::PLATFORM_COUNT)
            {
                m_filename  = filename;
                m_platform  = platform;
                m_outDir    = outputDir;
                m_binOutDir = "bin";
                m_spvOutDir = "spv";
                m_srcOutDir = "src";
                success     = true;
            }

            WriteMainHeader();
        }
    }

    if (!createSubOutputDirectories({ m_binOutDir, m_spvOutDir, m_srcOutDir }))
    {
        GFXRECON_LOG_ERROR("Couldn't create sub output directories!");
        gfxrecon::util::Log::Release();
        exit(-1);
    }

    m_dataPacker.Initialize(m_outDir, util::filepath::Join(m_binOutDir, "dataPack"), "bin", 40 * 1024 * 1024);
    // All spv files should be separate ones
    m_spvSaver.Initialize(m_outDir, util::filepath::Join(m_spvOutDir, "shader"), "spv", 0);

    // Initialize frame 0
    m_frameNumber        = 0;
    m_frameSplitNumber   = 0;
    m_frameApiCallNumber = 0;
    m_apiCallNumber      = 0;
    NewFrameFile(m_frameNumber, m_frameSplitNumber);

    return success;
}

void VulkanCppConsumerBase::Destroy()
{
    EndFrameFile(m_frameNumber, m_frameSplitNumber);

    if (m_main_file != nullptr)
    {
        PrintOutGlobalVar();
        std::string filename = util::filepath::Join(m_outDir, m_srcOutDir + "/global_var.h");
        int32_t     result   = util::platform::FileOpen(&m_header_file, filename.c_str(), "w");
        if (result == 0)
        {
            // Close the last frame call.
            WriteGlobalHeaderFile();
            WriteMainFooter();
            util::platform::FileClose(m_main_file);
            if (m_platform != GfxTocppPlatform::PLATFORM_ANDROID)
            {
                PrintOutCMakeFile();
            }
        }
        else
        {
            fprintf(stderr, "Error while opening file: %s\n", filename.c_str());
        }
        m_pfnLoader.WriteOutLoaderGenerator(util::filepath::Join(m_outDir, m_srcOutDir), m_platform);
    }
}

void VulkanCppConsumerBase::NewFrameFile(uint32_t frameNumber, uint32_t frameSplitNumber)
{
    assert(m_frameFile == nullptr);

    // Create new Frame
    std::string newFrameDir      = gfxrecon::util::filepath::Join(m_outDir, m_srcOutDir);
    std::string newFrameFileName = GenFrameName(frameNumber, frameSplitNumber, 4);
    std::string newFrameFilePath = gfxrecon::util::filepath::Join(newFrameDir, newFrameFileName) + ".cpp";

    int32_t result = util::platform::FileOpen(&m_frameFile, newFrameFilePath.c_str(), "w");
    if (result != 0)
    {
        fprintf(stderr, "Error while opening file: %s\n", newFrameFilePath.c_str());
        exit(-1);
    }

    fprintf(m_frameFile, "%s\n", sCommonFrameSourceHeader);

    std::string frameFunctionName = "void " + newFrameFileName + "()";
    fprintf(m_frameFile, "%s {\n", frameFunctionName.c_str());
}

void VulkanCppConsumerBase::EndFrameFile(uint32_t frameNumber, uint32_t frameSplitNumber)
{
    assert(m_frameFile != nullptr);
    assert(m_main_file != nullptr);

    // Write out closing data for previous frame file.
    fprintf(m_frameFile, "%s", sCommonFrameSourceFooter);
    util::platform::FileClose(m_frameFile);
    m_frameFile = nullptr;

    // The 'struct tracking' mechanism's restricted for every frame call.
    m_structMap.clear();

    // Write out the frame call
    // TODO generate at last step
    // TODO: generate this into the main.cpp only
    std::string frameFunctionName = GenFrameName(frameNumber, frameSplitNumber, 4);
    m_func_data.push_back("extern void " + frameFunctionName + "();\n");
    fprintf(m_main_file, "    %s();\n", frameFunctionName.c_str());
}

void VulkanCppConsumerBase::NextFrame(bool isSplit)
{
    EndFrameFile(m_frameNumber, m_frameSplitNumber);
    m_frameApiCallNumber = 0;
    m_frameSplitTempMemory.clear();
    if (isSplit)
    {
        m_frameSplitNumber++;
    }
    else
    {
        m_frameSplitNumber = 0;
        m_frameNumber++;
    }
    NewFrameFile(m_frameNumber, m_frameSplitNumber);
}

void VulkanCppConsumerBase::Post_APICall(format::ApiCallId callId)
{
    // Replicate FileProcessor's frame counter increment process
    if (callId == format::ApiCallId::ApiCall_vkQueuePresentKHR)
    {
        NextFrame(false);
    }
    else if (m_frameApiCallNumber != 0 && (m_frameApiCallNumber % m_max_command_limit == 0))
    {
        NextFrame(true);
    }

    if (callId != format::ApiCallId::ApiCall_vkAcquireNextImageKHR)
    {
        m_frameApiCallNumber++;
        m_apiCallNumber++;
    }
}

void VulkanCppConsumerBase::GenerateLoadData(
    const std::string& filename, uint64_t fileOffset, const std::string& dataPtrVarName, uint64_t offset, uint64_t size)
{
    fprintf(GetFrameFile(),
            "\tloadData(\"%s\", %" PRIu64 ", %s, %" PRIu64 ", %" PRIu64 ", appdata);\n",
            filename.c_str(),
            fileOffset,
            dataPtrVarName.c_str(),
            offset,
            size);
}

FILE* VulkanCppConsumerBase::GetFrameFile()
{
    return m_frameFile;
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
        m_handleIdMap[ptrs[idx]] = outputName + "[" + std::to_string(idx) + "]";
    }
}

void VulkanCppConsumerBase::AddHandles(const std::string& outputName, const format::HandleId* ptrs)
{
    m_handleIdMap[*ptrs] = outputName;
}

void VulkanCppConsumerBase::Generate_vkEnumeratePhysicalDevices(
    VkResult                                returnValue,
    format::HandleId                        instance,
    PointerDecoder<uint32_t>*               pPhysicalDeviceCount,
    HandlePointerDecoder<VkPhysicalDevice>* pPhysicalDevices)
{
    FILE* file = GetFrameFile();

    static bool deviceFound = false;
    if (!deviceFound && pPhysicalDevices->GetPointer() != nullptr)
    {
        deviceFound                            = true;
        uint32_t          recorded_count       = *(pPhysicalDeviceCount->GetPointer());
        const std::string pPhysicalDevicesName = "physicalDevices";

        AddKnownVariables("VkPhysicalDevice", pPhysicalDevicesName, pPhysicalDevices->GetPointer(), recorded_count);
        fprintf(file, "\tuint32_t deviceCount = %d;\n", recorded_count);
        fprintf(file,
                "\tvkEnumeratePhysicalDevices(%s, &deviceCount, %s);\n",
                m_handleIdMap[instance].c_str(),
                pPhysicalDevicesName.c_str());

        AddHandles(pPhysicalDevicesName, pPhysicalDevices->GetPointer(), recorded_count);
    }
}

void VulkanCppConsumerBase::Generate_vkGetSwapchainImagesKHR(VkResult                       returnValue,
                                                             format::HandleId               device,
                                                             format::HandleId               swapchain,
                                                             PointerDecoder<uint32_t>*      pSwapchainImageCount,
                                                             HandlePointerDecoder<VkImage>* pSwapchainImages)
{
    FILE* file = GetFrameFile();

    std::string pSwapchainImagesName = "NULL";
    if (pSwapchainImages->GetPointer() == NULL)
    {
        const std::string pSwapchainImageCountName = "pSwapchainImageCount_" + std::to_string(getNextId());
        AddKnownVariables("uint32_t", pSwapchainImageCountName);
        m_ptrMap[pSwapchainImageCount] = pSwapchainImageCountName;
    }
    else
    {
        pSwapchainImagesName = "pSwapchainImages_" + std::to_string(getNextId());
        fprintf(
            file, "\t%s = new VkImage[%s];\n", pSwapchainImagesName.c_str(), m_ptrMap[pSwapchainImageCount].c_str());
        AddKnownVariables("VkImage*", pSwapchainImagesName);
        if (returnValue == VK_SUCCESS)
        {
            AddHandles(pSwapchainImagesName, pSwapchainImages->GetPointer(), pSwapchainImages->GetLength());
        }
    }

    m_pfnLoader.AddMethodName("vkGetSwapchainImagesKHR");

    fprintf(file,
            "\tVK_CALL_CHECK(loaded_vkGetSwapchainImagesKHR(%s, %s, &%s, %s), %s);\n",
            GetHandle(device).c_str(),
            m_handleIdMap[swapchain].c_str(),
            m_ptrMap[pSwapchainImageCount].c_str(),
            pSwapchainImagesName.c_str(),
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

    std::string pSurfaceFormatsName = "NULL";
    if (pSurfaceFormats->GetPointer() == NULL)
    {
        const std::string pSurfaceFormatCountName = "pSurfaceFormatCount_" + std::to_string(getNextId());
        fprintf(file, "\tuint32_t %s;\n", pSurfaceFormatCountName.c_str());
        m_ptrMap[pSurfaceFormatCount] = pSurfaceFormatCountName;
    }
    else
    {
        pSurfaceFormatsName = "pSurfaceFormats_" + std::to_string(getNextId());
        fprintf(
            file, "\tVkSurfaceFormatKHR %s[%s];\n", pSurfaceFormatsName.c_str(), m_ptrMap[pSurfaceFormatCount].c_str());
        // TODO: connect these formats to their usages? How?
    }

    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceSurfaceFormatsKHR");
    fprintf(file,
            "\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceSurfaceFormatsKHR(%s, %s, &%s, %s), %s);\n",
            GetHandle(physicalDevice).c_str(),
            GetHandle(surface).c_str(),
            m_ptrMap[pSurfaceFormatCount].c_str(),
            pSurfaceFormatsName.c_str(),
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

    std::string pPresentModesName = "NULL";
    if (pPresentModes->GetPointer() == NULL)
    {
        const std::string pPresentModeCountName = "pPresentModeCount_" + std::to_string(getNextId());
        fprintf(file, "\tuint32_t %s;\n", pPresentModeCountName.c_str());
        m_ptrMap[pPresentModeCount] = pPresentModeCountName;
    }
    else
    {
        pPresentModesName = "pPresentModes_" + std::to_string(getNextId());
        fprintf(file, "\tVkPresentModeKHR %s[%s];\n", pPresentModesName.c_str(), m_ptrMap[pPresentModeCount].c_str());
        // TODO: connect these formats to their usages? How?
    }

    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceSurfacePresentModesKHR");
    fprintf(file,
            "\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceSurfacePresentModesKHR(%s, %s, &%s, %s), %s);\n",
            GetHandle(physicalDevice).c_str(),
            GetHandle(surface).c_str(),
            m_ptrMap[pPresentModeCount].c_str(),
            pPresentModesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());

    fprintf(file, "\n");
}

void VulkanCppConsumerBase::Generate_vkGetPhysicalDeviceQueueFamilyProperties(
    format::HandleId                                       physicalDevice,
    PointerDecoder<uint32_t>*                              pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties>* pQueueFamilyProperties)
{
    FILE* file = GetFrameFile();

    std::string pQueueFamilyPropertiesName = "NULL";
    if (pQueueFamilyProperties->GetPointer() == NULL)
    {
        const std::string pQueueFamilyPropertyCountName = "pQueueFamilyPropertyCount_" + std::to_string(getNextId());
        fprintf(file, "\tuint32_t %s;\n", pQueueFamilyPropertyCountName.c_str());
        m_ptrMap[pQueueFamilyPropertyCount] = pQueueFamilyPropertyCountName;
    }
    else
    {
        pQueueFamilyPropertiesName = "pQueueFamilyProperties_" + std::to_string(getNextId());
        fprintf(file,
                "\tVkQueueFamilyProperties %s[%s];\n",
                pQueueFamilyPropertiesName.c_str(),
                m_ptrMap[pQueueFamilyPropertyCount].c_str());
        // TODO: connect these formats to their usages? How?
    }

    fprintf(file,
            "\tvkGetPhysicalDeviceQueueFamilyProperties(%s, &%s, %s);\n",
            GetHandle(physicalDevice).c_str(),
            m_ptrMap[pQueueFamilyPropertyCount].c_str(),
            pQueueFamilyPropertiesName.c_str());

    fprintf(file, "\n");
}

void VulkanCppConsumerBase::Generate_vkGetBufferMemoryRequirements(
    format::HandleId                                    device,
    format::HandleId                                    buffer,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    FILE* file = GetFrameFile();

    std::string pMemoryRequirementsName = "pMemoryRequirements_" + std::to_string(VulkanCppConsumerBase::getNextId());
    AddKnownVariables("VkMemoryRequirements", pMemoryRequirementsName);

    fprintf(file,
            "\tvkGetBufferMemoryRequirements(%s, %s, &%s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(buffer).c_str(),
            pMemoryRequirementsName.c_str());

    m_resourceMemoryReqMap[buffer] = pMemoryRequirementsName;

    fprintf(file, "\n");
}

void VulkanCppConsumerBase::Generate_vkGetImageMemoryRequirements(
    format::HandleId                                    device,
    format::HandleId                                    image,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    FILE* file = GetFrameFile();

    std::string pMemoryRequirementsName = "pMemoryRequirements_" + std::to_string(VulkanCppConsumerBase::getNextId());
    AddKnownVariables("VkMemoryRequirements", pMemoryRequirementsName);

    fprintf(file,
            "\tvkGetImageMemoryRequirements(%s, %s, &%s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(image).c_str(),
            pMemoryRequirementsName.c_str());

    m_resourceMemoryReqMap[image] = pMemoryRequirementsName;

    fprintf(file, "\n");
}

void VulkanCppConsumerBase::Generate_vkGetBufferMemoryRequirements2(
    format::HandleId                                               device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>*           pMemoryRequirements)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    /* device */
    /* pInfo */
    std::stringstream stream_pInfo;
    std::string       pInfoStruct = GenerateStruct_VkBufferMemoryRequirementsInfo2(
        stream_pInfo, pInfo->GetPointer(), pInfo->GetMetaStructPointer(), *this);
    fprintf(file, "%s", stream_pInfo.str().c_str());
    /* pMemoryRequirements */
    std::string       pMemoryRequirementsName = "pMemoryRequirements_" + std::to_string(this->getNextId());
    std::stringstream stream_pMemoryRequirements;
    pMemoryRequirementsName = GenerateStruct_VkMemoryRequirements2(stream_pMemoryRequirements,
                                                                   pMemoryRequirements->GetPointer(),
                                                                   pMemoryRequirements->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "%s", stream_pMemoryRequirements.str().c_str());
    AddKnownVariables("VkMemoryRequirements2", pMemoryRequirementsName);
    fprintf(file,
            "\t\tvkGetBufferMemoryRequirements2(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str(),
            pMemoryRequirementsName.c_str());
    fprintf(file, "\t}\n");
    m_resourceMemoryReqMap[pInfo->GetMetaStructPointer()->buffer] = pMemoryRequirementsName;
}

void VulkanCppConsumerBase::Generate_vkGetBufferMemoryRequirements2KHR(
    format::HandleId                                               device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>*           pMemoryRequirements)
{
    return Generate_vkGetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements);
}

void VulkanCppConsumerBase::Generate_vkGetImageMemoryRequirements2(
    format::HandleId                                              device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>*          pMemoryRequirements)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    /* device */
    /* pInfo */
    std::stringstream stream_pInfo;
    std::string       pInfoStruct = GenerateStruct_VkImageMemoryRequirementsInfo2(
        stream_pInfo, pInfo->GetPointer(), pInfo->GetMetaStructPointer(), *this);
    fprintf(file, "%s", stream_pInfo.str().c_str());
    /* pMemoryRequirements */
    std::string       pMemoryRequirementsName = "pMemoryRequirements_" + std::to_string(this->getNextId());
    std::stringstream stream_pMemoryRequirements;
    pMemoryRequirementsName = GenerateStruct_VkMemoryRequirements2(stream_pMemoryRequirements,
                                                                   pMemoryRequirements->GetPointer(),
                                                                   pMemoryRequirements->GetMetaStructPointer(),
                                                                   *this);
    fprintf(file, "%s", stream_pMemoryRequirements.str().c_str());
    AddKnownVariables("VkMemoryRequirements2", pMemoryRequirementsName);
    fprintf(file,
            "\t\tvkGetImageMemoryRequirements2(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str(),
            pMemoryRequirementsName.c_str());
    fprintf(file, "\t}\n");
    m_resourceMemoryReqMap[pInfo->GetMetaStructPointer()->image] = pMemoryRequirementsName;
}

void VulkanCppConsumerBase::Generate_vkGetImageMemoryRequirements2KHR(
    format::HandleId                                              device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>*          pMemoryRequirements)
{
    return Generate_vkGetImageMemoryRequirements2(device, pInfo, pMemoryRequirements);
}

void VulkanCppConsumerBase::Generate_vkGetImageSparseMemoryRequirements(
    format::HandleId                                               device,
    format::HandleId                                               image,
    PointerDecoder<uint32_t>*                                      pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements>* pSparseMemoryRequirements)
{
    FILE* file = GetFrameFile();

    std::string pSparseMemoryRequirementCountName =
        "pSparseMemoryRequirementCount_" + std::to_string(VulkanCppConsumerBase::getNextId());
    fprintf(file, "\tuint32_t %s;\n", pSparseMemoryRequirementCountName.c_str());

    std::string pSparseMemoryRequirementsName =
        "pSparseMemoryRequirements_" + std::to_string(VulkanCppConsumerBase::getNextId());
    const uint32_t* in_pSparseMemoryRequirementCount = pSparseMemoryRequirementCount->GetPointer();

    AddKnownVariables(
        "VkSparseImageMemoryRequirements", pSparseMemoryRequirementsName, *in_pSparseMemoryRequirementCount);
    fprintf(file,
            "\tvkGetImageSparseMemoryRequirements(%s, %s, &%s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(image).c_str(),
            pSparseMemoryRequirementCountName.c_str(),
            pSparseMemoryRequirementsName.c_str());

    m_resourceMemoryReqMap[image] = pSparseMemoryRequirementsName;
}

void VulkanCppConsumerBase::Generate_vkGetFenceStatus(VkResult         returnValue,
                                                      format::HandleId device,
                                                      format::HandleId fence)
{
    if (returnValue == VK_SUCCESS)
    {
        fprintf(GetFrameFile(),
                "\twhile( vkGetFenceStatus(%s, %s) != VK_SUCCESS) { usleep(5000); }\n",
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
    std::string ppDataName = "ppData_" + std::to_string(getNextId());
    AddKnownVariables("void*", ppDataName);

    fprintf(GetFrameFile(),
            "\tVK_CALL_CHECK(vkMapMemory(%s, %s, %" PRIu64 "UL, %" PRIu64 "UL, %s, &%s), %s);\n",
            m_handleIdMap[device].c_str(),
            m_handleIdMap[memory].c_str(),
            offset,
            size,
            util::ToString<VkMemoryMapFlags>(flags).c_str(),
            ppDataName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());

    m_memoryIdMap[(uint64_t)memory] = ppDataName;
}

void VulkanCppConsumerBase::Generate_vkUnmapMemory(format::HandleId device, format::HandleId memory)
{
    fprintf(GetFrameFile(), "\tvkUnmapMemory(%s, %s);\n", m_handleIdMap[device].c_str(), m_handleIdMap[memory].c_str());

    m_memoryIdMap[(uint64_t)memory] = "<<INVALID>>";
}

void VulkanCppConsumerBase::Generate_vkAllocateMemory(VkResult                                            returnValue,
                                                      format::HandleId                                    device,
                                                      StructPointerDecoder<Decoded_VkMemoryAllocateInfo>* pAllocateInfo,
                                                      StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                                      HandlePointerDecoder<VkDeviceMemory>*                pMemory)
{
    FILE* file = GetFrameFile();

    std::stringstream stream_pAllocateInfo;
    std::string       pAllocateInfoStruct = GenerateStruct_VkMemoryAllocateInfo(stream_pAllocateInfo,
                                                                          *pMemory->GetPointer(),
                                                                          pAllocateInfo->GetPointer(),
                                                                          pAllocateInfo->GetMetaStructPointer(),
                                                                          *this);
    fprintf(file, "\n\t%s", stream_pAllocateInfo.str().c_str());
    std::string pMemoryName = "pMemory_" + std::to_string(this->getNextId());
    AddKnownVariables("VkDeviceMemory", pMemoryName, pMemory->GetPointer());
    if (returnValue == VK_SUCCESS)
    {
        this->AddHandles(pMemoryName, pMemory->GetPointer());
    }
    fprintf(file,
            "\tVK_CALL_CHECK(vkAllocateMemory(%s, &%s, %s, &%s), %s);\n",
            GetHandle(device).c_str(),
            pAllocateInfoStruct.c_str(),
            "nullptr",
            pMemoryName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
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
    for (auto& temp_memory : m_frameSplitTempMemory)
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
        temp_memory.name = "pData_" + std::to_string(this->getNextId());
        temp_memory.size = dataSize;
        m_frameSplitTempMemory.push_back(temp_memory);
        temp_memory_name = temp_memory.name;

        fprintf(file, "\tuint8_t %s[%" PRId64 "];\n", temp_memory_name.c_str(), dataSize);
    }

    if (returnValue == VK_SUCCESS)
    {
        fprintf(file,
                "\twhile( vkGetQueryPoolResults(%s, %s, %u, %u, %" PRIu64 "UL, %s, %" PRIu64
                "UL, %s) != VK_SUCCESS) { usleep(5000); }\n",
                GetHandle(device).c_str(),
                GetHandle(queryPool).c_str(),
                firstQuery,
                queryCount,
                dataSize,
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
                dataSize,
                temp_memory_name.c_str(),
                stride,
                util::ToString<VkQueryResultFlags>(flags).c_str(),
                util::ToString<VkResult>(returnValue).c_str());
    }
}

static std::vector<std::string> filterLayers(const char* const* layerArray, const uint32_t layerArrayLength)
{
    std::vector<std::string> enabledLayers;
    if (layerArrayLength == 0)
    {
        return enabledLayers;
    }

    const std::vector<std::string> layerBlacklist = {
        GFXRECON_PROJECT_LAYER_NAME,
        "VK_LAYER_LUNARG_device_simulation",
    };

    for (uint32_t idx = 0; idx < layerArrayLength; ++idx)
    {
        bool isBlacklisted = std::any_of(layerBlacklist.begin(), layerBlacklist.end(), [&](const std::string& name) {
            return name == layerArray[idx];
        });
        if (!isBlacklisted)
        {
            enabledLayers.emplace_back(layerArray[idx]);
        }
    }

    return enabledLayers;
}

static std::vector<std::string> replaceExtensions(const char* const*                        extensionArray,
                                                  const uint32_t                            extensionArrayLength,
                                                  const std::map<std::string, std::string>& remapInfo)
{
    std::vector<std::string> enabledExtensions;
    enabledExtensions.reserve(extensionArrayLength);

    for (uint32_t idx = 0; idx < extensionArrayLength; ++idx)
    {
        std::string extensionName(extensionArray[idx]);

        const auto& it = remapInfo.find(extensionName);
        if (it != remapInfo.end())
        {
            extensionName = it->second;
        }
        enabledExtensions.emplace_back(extensionName);
    }

    return enabledExtensions;
}

static void BuildInstanceCreateInfo(std::ostream&                       out,
                                    const VkInstanceCreateInfo*         structInfo,
                                    const Decoded_VkInstanceCreateInfo* metainfo,
                                    const std::string&                  varname,
                                    VulkanCppConsumerBase&              consumer)
{
    // Collect enabled layer names except the GFXReconstruct's own layer.
    const std::vector<std::string> layerNames =
        filterLayers(structInfo->ppEnabledLayerNames, structInfo->enabledLayerCount);

    std::string pNextName              = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);
    std::string pApplicationInfoStruct = "NULL";
    if (structInfo->pApplicationInfo != NULL)
    {
        pApplicationInfoStruct =
            "&" + GenerateStruct_VkApplicationInfo(
                      out, structInfo->pApplicationInfo, metainfo->pApplicationInfo->GetMetaStructPointer(), consumer);
    }

    /* Print out enabled layers if there is any */
    std::string ppEnabledLayerNamesValue = "NULL";
    if (layerNames.size() > 0)
    {
        ppEnabledLayerNamesValue = "ppEnabledLayerNames_" + std::to_string(consumer.getNextId());
        out << "\t\tconst char* " << ppEnabledLayerNamesValue
            << "[] = " << VulkanCppConsumerBase::escapeStringArray(layerNames) << ";" << std::endl;
    }

    std::vector<std::string> extensionNames;
    std::string              ppEnabledExtensionNamesValue = "NULL";
    if (structInfo->enabledExtensionCount > 0)
    {
        // The array should be setup so that the enum could be used as an index.  Just verify it
        GfxTocppPlatform cur_platform = consumer.GetPlatform();
        assert(kValidTargetPlatforms[static_cast<uint32_t>(cur_platform)].platformEnum == cur_platform);
        std::string cur_extension_name = kValidTargetPlatforms[static_cast<uint32_t>(cur_platform)].wsiSurfaceExtName;

        // Generate a map of WSI extensions to the new extension for this current platform
        std::map<std::string, std::string> replace_map;
        const uint32_t max_count = static_cast<uint32_t>(sizeof(kValidTargetPlatforms) / sizeof(PlatformTargets));
        for (uint32_t ii = 0; ii < max_count; ++ii)
        {
            replace_map[kValidTargetPlatforms[ii].wsiSurfaceExtName] = cur_extension_name;
        }

        extensionNames =
            replaceExtensions(structInfo->ppEnabledExtensionNames, structInfo->enabledExtensionCount, replace_map);

        ppEnabledExtensionNamesValue = "ppEnabledExtensionNames_" + std::to_string(consumer.getNextId());
        out << "\t\tconst char* " << ppEnabledExtensionNamesValue
            << "[] = " << VulkanCppConsumerBase::escapeStringArray(extensionNames) << ";" << std::endl;
    }

    out << "\t\tVkInstanceCreateInfo " << varname << " = {" << std::endl;
    out << "\t\t/* sType */ " << util::ToString<VkStructureType>(structInfo->sType) << "," << std::endl;
    out << "\t\t/* pNext */ " << pNextName << "," << std::endl;
    out << "\t\t/* flags */ " << util::ToString<VkInstanceCreateFlags>(structInfo->flags) << "," << std::endl;
    out << "\t\t/* pApplicationInfo */ " << pApplicationInfoStruct << "," << std::endl;
    out << "\t\t/* enabledLayerCount */ " << layerNames.size() << "," << std::endl;
    out << "\t\t/* ppEnabledLayerNames */ " << ppEnabledLayerNamesValue << "," << std::endl;
    out << "\t\t/* enabledExtensionCount */ " << extensionNames.size() << "," << std::endl;
    out << "\t\t/* ppEnabledExtensionNames */ " << ppEnabledExtensionNamesValue << "," << std::endl;
    out << "\t\t};" << std::endl;

    std::string vkInstanceCreateInfoVar = "VkInstanceCreateInfo " + varname + ";\n";
}

void VulkanCppConsumerBase::Generate_vkCreateInstance(VkResult                                             returnValue,
                                                      StructPointerDecoder<Decoded_VkInstanceCreateInfo>*  pCreateInfo,
                                                      StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                                      HandlePointerDecoder<VkInstance>*                    pInstance)
{
    FILE* file = GetFrameFile();

    std::string       pCreateInfoStruct = "pCreateInfo_" + std::to_string(getNextId());
    std::stringstream instanceCreateInfoStr;
    BuildInstanceCreateInfo(instanceCreateInfoStr,
                            pCreateInfo->GetPointer(),
                            pCreateInfo->GetMetaStructPointer(),
                            pCreateInfoStruct,
                            *this);

    std::string pInstanceName = "instance";
    AddKnownVariables("VkInstance", pInstanceName);

    fprintf(file, "\t{\n");
    fprintf(file, "%s", instanceCreateInfoStr.str().c_str());
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateInstance(&%s, %s, &%s), %s);\n",
            pCreateInfoStruct.c_str(),
            "nullptr",
            pInstanceName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());

    fprintf(file, "\t\tloadFunctions(%s);\n", pInstanceName.c_str());
    fprintf(file, "\t}\n");

    if (returnValue == VK_SUCCESS)
    {
        AddHandles(pInstanceName, pInstance->GetPointer());
    }
}

void VulkanCppConsumerBase::Intercept_vkCreateDevice(VkResult                                          returnValue,
                                                     format::HandleId                                  physicalDevice,
                                                     StructPointerDecoder<Decoded_VkDeviceCreateInfo>* pCreateInfo,
                                                     StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                                     HandlePointerDecoder<VkDevice>*                      pDevice)
{
    fprintf(GetFrameFile(), "\tQueryPhysicalDeviceMemoryProperties(%s);\n", this->GetHandle(physicalDevice).c_str());
}

void VulkanCppConsumerBase::Generate_vkCreateShaderModule(
    VkResult                                                returnValue,
    format::HandleId                                        device,
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
    HandlePointerDecoder<VkShaderModule>*                   pShaderModule)
{
    FILE* file = GetFrameFile();

    const VkShaderModuleCreateInfo* structInfo = pCreateInfo->GetPointer();

    /* emit spirv data load. */
    std::string         pCodeName = "pCode_" + std::to_string(VulkanCppConsumerBase::getNextId());
    const SavedFileInfo fileInfo  = m_spvSaver.AddFileContents((const uint8_t*)structInfo->pCode, structInfo->codeSize);

    fprintf(file, "\t{\n");

    fprintf(file, "\t\tuint8_t *%s = new uint8_t[%zu];\n\t", pCodeName.c_str(), structInfo->codeSize);
    GenerateLoadData(fileInfo.filePath, fileInfo.byteOffset, pCodeName, 0, structInfo->codeSize);

    std::string pCreateInfoStruct = "pCreateInfo_" + std::to_string(VulkanCppConsumerBase::getNextId());

    std::stringstream outStruct;
    outStruct << "\t\tVkShaderModuleCreateInfo " << pCreateInfoStruct << " = {" << std::endl;
    outStruct << "\t\t/* sType */ " << util::ToString<VkStructureType>(structInfo->sType) << "," << std::endl;
    outStruct << "\t\t/* pNext */ " << structInfo->pNext << "," << std::endl;
    outStruct << "\t\t/* flags */ " << util::ToString<VkShaderModuleCreateFlags>(structInfo->flags) << "," << std::endl;
    outStruct << "\t\t/* codeSize */ " << structInfo->codeSize << "," << std::endl;
    outStruct << "\t\t/* pCode */ (const uint32_t*)" << pCodeName << "," << std::endl;
    outStruct << "\t\t};" << std::endl;
    fprintf(file, "%s", outStruct.str().c_str());

    std::string pShaderModuleName = "pShaderModule_" + std::to_string(VulkanCppConsumerBase::getNextId());
    AddKnownVariables("VkShaderModule", pShaderModuleName, pShaderModule->GetPointer());

    if (returnValue == VK_SUCCESS)
    {
        AddHandles(pShaderModuleName, pShaderModule->GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateShaderModule(%s, &%s, %s, &%s), %s);\n",
            GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pShaderModuleName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());

    /* emit delete the allocated spv data. */
    fprintf(file, "\t\tdelete [] %s;\n\n", pCodeName.c_str());
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

    const VkPipelineCacheCreateInfo* structInfo = pCreateInfo->GetPointer();

    fprintf(file, "\t{\n");
    std::string       pCreateInfoStruct = "pCreateInfo_" + std::to_string(VulkanCppConsumerBase::getNextId());
    std::stringstream stream_pCreateInfo;

    stream_pCreateInfo << "\t\tVkPipelineCacheCreateInfo " << pCreateInfoStruct << " {" << std::endl;
    stream_pCreateInfo << "\t\t/* sType */ " << util::ToString<VkStructureType>(structInfo->sType) << "," << std::endl;
    stream_pCreateInfo << "\t\t/* pNext */ " << structInfo->pNext << "," << std::endl;
    stream_pCreateInfo << "\t\t/* flags */ " << util::ToString<VkPipelineCacheCreateFlags>(structInfo->flags) << ","
                       << std::endl;
    stream_pCreateInfo << "\t\t/* initialDataSize */ "
                       << "0"
                       << "," << std::endl;
    stream_pCreateInfo << "\t\t/* pInitialData */ "
                       << "NULL"
                       << "," << std::endl;
    stream_pCreateInfo << "\t\t};" << std::endl;
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());

    std::string pPipelineCacheName = "pPipelineCache_" + std::to_string(VulkanCppConsumerBase::getNextId());
    AddKnownVariables("VkPipelineCache", pPipelineCacheName);

    if (returnValue == VK_SUCCESS)
    {
        AddHandles(pPipelineCacheName, pPipelineCache->GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreatePipelineCache(%s, &%s, %s, &%s), %s);\n",
            GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pPipelineCacheName.c_str(),
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
    GenerateSurfaceCreation(m_platform, returnValue, instance, (void*)pCreateInfo, pSurface->GetPointer());
}

void VulkanCppConsumerBase::Generate_vkCreateMetalSurfaceEXT(
    VkResult                                                   returnValue,
    format::HandleId                                           instance,
    StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*       pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                        pSurface)
{
    GenerateSurfaceCreation(m_platform, returnValue, instance, (void*)pCreateInfo, pSurface->GetPointer());
}

void VulkanCppConsumerBase::Generate_vkCreateWaylandSurfaceKHR(
    VkResult                                                     returnValue,
    format::HandleId                                             instance,
    StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                          pSurface)
{
    GenerateSurfaceCreation(m_platform, returnValue, instance, (void*)pCreateInfo, pSurface->GetPointer());
}

void VulkanCppConsumerBase::Generate_vkCreateWin32SurfaceKHR(
    VkResult                                                   returnValue,
    format::HandleId                                           instance,
    StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*       pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                        pSurface)
{
    GenerateSurfaceCreation(m_platform, returnValue, instance, (void*)pCreateInfo, pSurface->GetPointer());
}

void VulkanCppConsumerBase::Generate_vkCreateXcbSurfaceKHR(
    VkResult                                                 returnValue,
    format::HandleId                                         instance,
    StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*     pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                      pSurface)
{
    GenerateSurfaceCreation(m_platform, returnValue, instance, (void*)pCreateInfo, pSurface->GetPointer());
}

void VulkanCppConsumerBase::Generate_vkCreateXlibSurfaceKHR(
    VkResult                                                  returnValue,
    format::HandleId                                          instance,
    StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*      pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                       pSurface)
{
    GenerateSurfaceCreation(m_platform, returnValue, instance, (void*)pCreateInfo, pSurface->GetPointer());
}

void VulkanCppConsumerBase::GenerateSurfaceCreation(GfxTocppPlatform        platform,
                                                    VkResult                returnValue,
                                                    format::HandleId        instance,
                                                    void*                   pSurfaceCreateInfo,
                                                    const format::HandleId* pSurface)
{
    FILE* file = GetFrameFile();

    std::stringstream stream_pCreateInfo;
    std::string       pSurfaceName       = "pSurface_" + std::to_string(getNextId());
    std::string       pCreateInfoStruct  = "";
    std::string       pSurfaceCreateCall = "";

    fprintf(file, "\t{\n");

    switch (m_platform)
    {
        case GfxTocppPlatform::PLATFORM_ANDROID:
        {
            VkAndroidSurfaceCreateInfoKHR         androidStructInfo = {};
            Decoded_VkAndroidSurfaceCreateInfoKHR androidMetaInfo   = {};

            if (m_platform == platform)
            {
                androidStructInfo =
                    *reinterpret_cast<StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>*>(pSurfaceCreateInfo)
                         ->GetPointer();
            }
            androidStructInfo.sType = VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR;
            pCreateInfoStruct       = GenerateStruct_VkAndroidSurfaceCreateInfoKHR(
                stream_pCreateInfo, &androidStructInfo, &androidMetaInfo, *this);
            pSurfaceCreateCall = "vkCreateAndroidSurfaceKHR";
            break;
        }
        case GfxTocppPlatform::PLATFORM_WIN32:
        {
            VkWin32SurfaceCreateInfoKHR         win32StructInfo = {};
            Decoded_VkWin32SurfaceCreateInfoKHR win32MetaInfo   = {};

            if (m_platform == platform)
            {
                win32StructInfo =
                    *reinterpret_cast<StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>*>(pSurfaceCreateInfo)
                         ->GetPointer();
            }
            win32StructInfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
            pCreateInfoStruct =
                GenerateStruct_VkWin32SurfaceCreateInfoKHR(stream_pCreateInfo, &win32StructInfo, &win32MetaInfo, *this);
            pSurfaceCreateCall = "vkCreateWin32SurfaceKHR";
            break;
        }
        case GfxTocppPlatform::PLATFORM_XCB:
        {
            VkXcbSurfaceCreateInfoKHR         xcbStructInfo = {};
            Decoded_VkXcbSurfaceCreateInfoKHR xcbMetaInfo   = {};

            if (m_platform == platform)
            {
                xcbStructInfo =
                    *reinterpret_cast<StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>*>(pSurfaceCreateInfo)
                         ->GetPointer();
            }
            xcbStructInfo.sType = VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR;
            pCreateInfoStruct =
                GenerateStruct_VkXcbSurfaceCreateInfoKHR(stream_pCreateInfo, &xcbStructInfo, &xcbMetaInfo, *this);
            pSurfaceCreateCall = "vkCreateXcbSurfaceKHR";
            break;
        }
        case GfxTocppPlatform::PLATFORM_COUNT:
        default:
        {
            assert(false);
            break;
        }
    }
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
    AddKnownVariables("VkSurfaceKHR", pSurfaceName, pSurface);
    AddHandles(pSurfaceName, pSurface);
    m_pfnLoader.AddMethodName(pSurfaceCreateCall);
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_%s(%s, &%s, %s, &%s), %s);\n",
            pSurfaceCreateCall.c_str(),
            GetHandle(instance).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pSurfaceName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());

    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::Intercept_vkCreateSwapchainKHR(
    VkResult                                                returnValue,
    format::HandleId                                        device,
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*                   pSwapchain)
{
    if (m_platform == GfxTocppPlatform::PLATFORM_ANDROID)
    {
        VkSwapchainCreateInfoKHR* structInfo = pCreateInfo->GetPointer();
        structInfo->imageExtent.width        = GetProperWindowWidth(structInfo->imageExtent.width);
        structInfo->imageExtent.height       = GetProperWindowHeight(structInfo->imageExtent.height);
    }
}

void VulkanCppConsumerBase::Intercept_vkCreateFramebuffer(
    VkResult                                               returnValue,
    format::HandleId                                       device,
    StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*   pAllocator,
    HandlePointerDecoder<VkFramebuffer>*                   pFramebuffer)
{
    if (m_platform == GfxTocppPlatform::PLATFORM_ANDROID)
    {
        VkFramebufferCreateInfo* structInfo = pCreateInfo->GetPointer();
        structInfo->width                   = GetProperWindowWidth(structInfo->width);
        structInfo->height                  = GetProperWindowHeight(structInfo->height);
    }
}

void VulkanCppConsumerBase::Intercept_vkCmdBeginRenderPass(
    format::HandleId                                     commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                                    contents)
{
    if (m_platform == GfxTocppPlatform::PLATFORM_ANDROID)
    {
        // TODO: This completely breaks desktop, especially if anti-aliasing is enabled.
        //       Leaving this in as the original drop had this code and it may be required
        //       for Android.  But it needs verification.
        VkRenderPassBeginInfo* structInfo    = pRenderPassBegin->GetPointer();
        structInfo->renderArea.extent.width  = GetProperWindowWidth(structInfo->renderArea.extent.width);
        structInfo->renderArea.extent.height = GetProperWindowHeight(structInfo->renderArea.extent.height);
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
    FILE*       file            = GetFrameFile();
    std::string pImageIndexName = "pImageIndex_" + std::to_string(getNextId());
    m_nextImageMap[swapchain].push(pImageIndexName);

    AddKnownVariables("uint32_t", pImageIndexName);

    m_pfnLoader.AddMethodName("vkAcquireNextImageKHR");
    if (returnValue == VK_SUCCESS)
    {
        fprintf(file,
                "\twhile (loaded_vkAcquireNextImageKHR(%s, %s, %" PRIu64
                "UL, %s, %s, &%s) != VK_SUCCESS) { usleep(5000); };\n",
                GetHandle(device).c_str(),
                GetHandle(swapchain).c_str(),
                timeout,
                GetHandle(semaphore).c_str(),
                GetHandle(fence).c_str(),
                pImageIndexName.c_str());
    }
    else
    {
        fprintf(file,
                "\tVK_CALL_CHECK(loaded_vkAcquireNextImageKHR(%s, %s, %" PRIu64 "UL, %s, %s, &%s), %s);\n",
                GetHandle(device).c_str(),
                GetHandle(swapchain).c_str(),
                timeout,
                GetHandle(semaphore).c_str(),
                GetHandle(fence).c_str(),
                pImageIndexName.c_str(),
                util::ToString<VkResult>(returnValue).c_str());
    }
}

void VulkanCppConsumerBase::Generate_vkAcquireNextImage2KHR(
    VkResult                                                 returnValue,
    format::HandleId                                         device,
    StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo,
    PointerDecoder<uint32_t>*                                pImageIndex)
{
    FILE*             file = GetFrameFile();
    std::stringstream stream_pAcquireInfo;
    std::string       pAcquireInfoStruct = GenerateStruct_VkAcquireNextImageInfoKHR(
        stream_pAcquireInfo, pAcquireInfo->GetPointer(), pAcquireInfo->GetMetaStructPointer(), *this);
    fprintf(file, "\n%s", stream_pAcquireInfo.str().c_str());
    std::string pImageIndexName = "pImageIndex_" + std::to_string(getNextId());
    fprintf(file, "\tuint32_t %s;\n", pImageIndexName.c_str());
    m_pfnLoader.AddMethodName("vkAcquireNextImage2KHR");

    if (returnValue == VK_SUCCESS)
    {
        fprintf(file,
                "\twhile (loaded_vkAcquireNextImage2KHR(%s, %s, &%s)) != VK_SUCCESS) { usleep(5000); };\n",
                GetHandle(device).c_str(),
                pAcquireInfoStruct.c_str(),
                pImageIndexName.c_str());
    }
    else
    {
        fprintf(file,
                "\tVK_CALL_CHECK(loaded_vkAcquireNextImage2KHR(%s, &%s, &%s), %s);\n",
                GetHandle(device).c_str(),
                pAcquireInfoStruct.c_str(),
                pImageIndexName.c_str(),
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
    std::string pFencesArray  = "NULL";
    std::string pFencesValues = toStringJoin(
        pFences->GetPointer(),
        pFences->GetPointer() + fenceCount,
        [&](const format::HandleId current) { return GetHandle(current); },
        ", ");
    if (fenceCount == 1)
    {
        pFencesArray   = "&" + pFencesValues;
        indent_tabs[0] = '\t';
        indent_tabs[1] = '\0';
    }
    else if (fenceCount > 1)
    {
        fprintf(file, "\t{\n");
        pFencesArray = "pFencesArray_" + std::to_string(getNextId());
        fprintf(file, "\t\tVkFence %s[] = { %s };\n", pFencesArray.c_str(), pFencesValues.c_str());
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
                pFencesArray.c_str(),
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
                pFencesArray.c_str(),
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
    std::string       pCreateInfoStruct;
    std::stringstream stream_pCreateInfo;
    std::string       pDescriptorUpdateTemplateName = "pDescriptorUpdateTemplate_" + std::to_string(this->getNextId());
    AddKnownVariables("VkDescriptorUpdateTemplate", pDescriptorUpdateTemplateName);
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

        auto templateHandleId = *pDescriptorUpdateTemplate->GetPointer();

        // Count the number of values of each type.
        size_t image_info_count             = 0;
        size_t buffer_info_count            = 0;
        size_t texel_buffer_view_count      = 0;
        size_t acceleration_structure_count = 0;

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

        // Track descriptor image type.
        std::vector<VkDescriptorType> image_types;

        for (auto entry = entries.begin(); entry != entries.end(); ++entry)
        {
            VkDescriptorType type = entry->descriptorType;

            m_descriptorUpdateTemplateEntryMap[templateHandleId].data.emplace_back(*entry);

            if ((type == VK_DESCRIPTOR_TYPE_SAMPLER) || (type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER) ||
                (type == VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE) || (type == VK_DESCRIPTOR_TYPE_STORAGE_IMAGE) ||
                (type == VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT))
            {
                image_types.insert(image_types.end(), entry->descriptorCount, entry->descriptorType);

                entry->stride = sizeof(VkDescriptorImageInfo);
                entry->offset = image_info_offset;
                image_info_offset += entry->descriptorCount * sizeof(VkDescriptorImageInfo);

                m_descriptorUpdateTemplateEntryMap[templateHandleId].images.emplace_back(*entry);
            }
            else if ((type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER) || (type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER) ||
                     (type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC) ||
                     (type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC))
            {
                entry->stride = sizeof(VkDescriptorBufferInfo);
                entry->offset = buffer_info_offset;
                buffer_info_offset += entry->descriptorCount * sizeof(VkDescriptorBufferInfo);

                m_descriptorUpdateTemplateEntryMap[templateHandleId].buffers.emplace_back(*entry);
            }
            else if ((type == VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER) ||
                     (type == VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER))
            {
                entry->stride = sizeof(VkBufferView);
                entry->offset = texel_buffer_view_offset;
                texel_buffer_view_offset += entry->descriptorCount * sizeof(VkBufferView);

                m_descriptorUpdateTemplateEntryMap[templateHandleId].texels.emplace_back(*entry);
            }
            else if (type == VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR)
            {
                entry->stride = sizeof(VkAccelerationStructureKHR);
                entry->offset = accel_struct_offset;
                accel_struct_offset += entry->descriptorCount * sizeof(VkAccelerationStructureKHR);

                m_descriptorUpdateTemplateEntryMap[templateHandleId].accelerations.emplace_back(*entry);
            }
            else
            {
                assert(false);
            }
        }

        override_create_info.pDescriptorUpdateEntries = entries.data();

        pCreateInfoStruct = GenerateStruct_VkDescriptorUpdateTemplateCreateInfo(
            stream_pCreateInfo, &override_create_info, pCreateInfo->GetMetaStructPointer(), *this);
    }
    else
    {
        pCreateInfoStruct = GenerateStruct_VkDescriptorUpdateTemplateCreateInfo(
            stream_pCreateInfo, pCreateInfo->GetPointer(), pCreateInfo->GetMetaStructPointer(), *this);

        auto templateHandleId = *pDescriptorUpdateTemplate->GetPointer();
        for (uint32_t idx = 0; idx < tocpp_create_info->descriptorUpdateEntryCount; idx++)
        {
            auto create_info_entry = tocpp_create_info->pDescriptorUpdateEntries[idx];
            m_descriptorUpdateTemplateEntryMap[templateHandleId].data.emplace_back(create_info_entry);
            switch (GetDescriptorBaseType(create_info_entry.descriptorType))
            {
                case DESCRIPTOR_BASE_TYPE_SAMPLER:
                case DESCRIPTOR_BASE_TYPE_IMAGE:
                case DESCRIPTOR_BASE_TYPE_COMBINED_IMAGE_SAMPLER:
                {
                    m_descriptorUpdateTemplateEntryMap[templateHandleId].images.emplace_back(create_info_entry);
                    break;
                }
                case DESCRIPTOR_BASE_TYPE_BUFFER:
                {
                    m_descriptorUpdateTemplateEntryMap[templateHandleId].buffers.emplace_back(create_info_entry);
                    break;
                }
                case DESCRIPTOR_BASE_TYPE_TEXEL:
                {
                    m_descriptorUpdateTemplateEntryMap[templateHandleId].texels.emplace_back(create_info_entry);
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
        this->AddHandles(pDescriptorUpdateTemplateName, pDescriptorUpdateTemplate->GetPointer());
    }

    fprintf(file, "%s", stream_pCreateInfo.str().c_str());
    m_pfnLoader.AddMethodName(method_name);
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_%s(%s, &%s, NULL, &%s), %s);\n",
            method_name.c_str(),
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            pDescriptorUpdateTemplateName.c_str(),
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

    uint32_t image_info_count        = static_cast<uint32_t>(decoder->GetImageInfoCount());
    uint32_t buffer_info_count       = static_cast<uint32_t>(decoder->GetBufferInfoCount());
    uint32_t texel_buffer_view_count = static_cast<uint32_t>(decoder->GetTexelBufferViewCount());
    uint32_t accel_struct_count      = static_cast<uint32_t>(decoder->GetAccelerationStructureKHRCount());

    assert(m_descriptorUpdateTemplateEntryMap.find(descriptor_update_template) !=
           m_descriptorUpdateTemplateEntryMap.end());

    // Generate template type
    const DescriptorUpdateTemplateEntries& template_entries =
        m_descriptorUpdateTemplateEntryMap[descriptor_update_template];

    // Check if the number of descriptors in pData equal the number of descriptors in the template
    uint32_t templateDescriptorCount = 0;
    for (const VkDescriptorUpdateTemplateEntry& entry : template_entries.data)
    {
        templateDescriptorCount += entry.descriptorCount;
    }
    uint32_t pDataCount = decoder->GetImageInfoCount() + decoder->GetBufferInfoCount() +
                          decoder->GetTexelBufferViewCount() + decoder->GetAccelerationStructureKHRCount();
    assert(templateDescriptorCount == pDataCount);

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

    std::string struct_type_name      = "StructDefine_" + std::to_string(getNextId());
    std::string struct_implement_name = "pData_" + std::to_string(getNextId());

    struct_define_stream << "\t\tstruct " << struct_type_name << " {\n";
    struct_implement_stream << "\t\t" << struct_type_name << " " << struct_implement_name << " {\n";
    uint32_t cur_count = 0;

    for (auto const& entry : template_entries.data)
    {
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
            default:
                break;
        }
    }

    // Sort the vairables based on the offset
    std::sort(variables.begin(), variables.end(), VariableOffsetCompare);

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
                    case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK_EXT:
                        // Not handled
                        assert(false);
                        struct_define_stream << "INLINE UNIFORM BLOCK not handled,";
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
    m_pfnLoader.AddMethodName(method_name);
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
    /* device */
    /* pipelineCache */
    /* createInfoCount */
    /* pCreateInfos */
    std::stringstream stream_pCreateInfos;
    std::string       pCreateInfosArray = "NULL";
    PointerPairContainer<decltype(pCreateInfos->GetPointer()), decltype(pCreateInfos->GetMetaStructPointer())>
                pCreateInfosPair{ pCreateInfos->GetPointer(), pCreateInfos->GetMetaStructPointer(), createInfoCount };
    std::string pCreateInfosNames = toStringJoin(
        pCreateInfosPair.begin(),
        pCreateInfosPair.end(),
        [&](auto pair) {
            return GenerateStruct_VkGraphicsPipelineCreateInfo(stream_pCreateInfos, pair.t1, pair.t2, *this);
        },
        ", ");
    fprintf(file, "\n%s", stream_pCreateInfos.str().c_str());
    if (createInfoCount == 1)
    {
        pCreateInfosArray = "&" + pCreateInfosNames;
    }
    else if (createInfoCount > 1)
    {
        pCreateInfosArray = "pCreateInfos_" + std::to_string(this->getNextId());
        fprintf(file,
                "VkGraphicsPipelineCreateInfo %s[] = { %s };\n",
                pCreateInfosArray.c_str(),
                pCreateInfosNames.c_str());
    }
    /* pAllocator */
    /* pPipelines */
    std::string pPipelinesName = "pPipelines_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_PIPELINE));
    AddKnownVariables("VkPipeline", pPipelinesName, pPipelines->GetPointer(), createInfoCount);
    if (returnValue == VK_SUCCESS)
    {
        this->AddHandles(pPipelinesName, pPipelines->GetPointer(), createInfoCount);
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateGraphicsPipelines(%s, %s, %u, %s, %s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipelineCache).c_str(),
            createInfoCount,
            pCreateInfosArray.c_str(),
            "nullptr",
            pPipelinesName.c_str(),
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
    /* device */
    /* pipelineCache */
    /* createInfoCount */
    /* pCreateInfos */
    std::stringstream stream_pCreateInfos;
    std::string       pCreateInfosArray = "NULL";
    PointerPairContainer<decltype(pCreateInfos->GetPointer()), decltype(pCreateInfos->GetMetaStructPointer())>
                pCreateInfosPair{ pCreateInfos->GetPointer(), pCreateInfos->GetMetaStructPointer(), createInfoCount };
    std::string pCreateInfosNames = toStringJoin(
        pCreateInfosPair.begin(),
        pCreateInfosPair.end(),
        [&](auto pair) {
            return GenerateStruct_VkRayTracingPipelineCreateInfoKHR(stream_pCreateInfos, pair.t1, pair.t2, *this);
        },
        ", ");
    fprintf(file, "\n%s", stream_pCreateInfos.str().c_str());
    if (createInfoCount == 1)
    {
        pCreateInfosArray = "&" + pCreateInfosNames;
    }
    else if (createInfoCount > 1)
    {
        pCreateInfosArray = "pCreateInfos_" + std::to_string(this->getNextId());
        fprintf(file,
                "VkRayTracingPipelineCreateInfoKHR %s[] = { %s };\n",
                pCreateInfosArray.c_str(),
                pCreateInfosNames.c_str());
    }
    /* pAllocator */
    /* pPipelines */
    std::string pPipelinesName = "pPipelines_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_PIPELINE));
    AddKnownVariables("VkPipeline", pPipelinesName, pPipelines->GetPointer(), createInfoCount);
    if (returnValue == VK_SUCCESS)
    {
        this->AddHandles(pPipelinesName, pPipelines->GetPointer(), createInfoCount);
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateRayTracingPipelinesKHR(%s, %s, %u, %s, %s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipelineCache).c_str(),
            createInfoCount,
            pCreateInfosArray.c_str(),
            "nullptr",
            pPipelinesName.c_str(),
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
    /* device */
    /* pipelineCache */
    /* createInfoCount */
    /* pCreateInfos */
    std::stringstream stream_pCreateInfos;
    std::string       pCreateInfosArray = "NULL";
    PointerPairContainer<decltype(pCreateInfos->GetPointer()), decltype(pCreateInfos->GetMetaStructPointer())>
                pCreateInfosPair{ pCreateInfos->GetPointer(), pCreateInfos->GetMetaStructPointer(), createInfoCount };
    std::string pCreateInfosNames = toStringJoin(
        pCreateInfosPair.begin(),
        pCreateInfosPair.end(),
        [&](auto pair) {
            return GenerateStruct_VkComputePipelineCreateInfo(stream_pCreateInfos, pair.t1, pair.t2, *this);
        },
        ", ");
    fprintf(file, "\n%s", stream_pCreateInfos.str().c_str());
    if (createInfoCount == 1)
    {
        pCreateInfosArray = "&" + pCreateInfosNames;
    }
    else if (createInfoCount > 1)
    {
        pCreateInfosArray = "pCreateInfos_" + std::to_string(this->getNextId());
        fprintf(
            file, "VkComputePipelineCreateInfo %s[] = { %s };\n", pCreateInfosArray.c_str(), pCreateInfosNames.c_str());
    }
    /* pAllocator */
    /* pPipelines */
    std::string pPipelinesName = "pPipelines_" + std::to_string(this->getNextId(VK_OBJECT_TYPE_PIPELINE));
    AddKnownVariables("VkPipeline", pPipelinesName, pPipelines->GetPointer(), createInfoCount);
    if (returnValue == VK_SUCCESS)
    {
        this->AddHandles(pPipelinesName, pPipelines->GetPointer(), createInfoCount);
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateComputePipelines(%s, %s, %u, %s, %s, %s), %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(pipelineCache).c_str(),
            createInfoCount,
            pCreateInfosArray.c_str(),
            "nullptr",
            pPipelinesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
    fprintf(file, "    }\n");
}

std::string VulkanCppConsumerBase::toEscape(const char* value)
{
    return (value != nullptr) ? std::string("\"") + value + "\"" : "NULL";
}

std::string VulkanCppConsumerBase::toEscape(const std::string& value)
{
    return std::string("\"") + value + "\"";
}

std::string VulkanCppConsumerBase::escapeStringArray(const char* const* stringArray, const uint32_t stringArrayLength)
{
    if (stringArrayLength == 0)
    {
        return std::string("{\"\"}");
    }

    std::string escapedStrings = "{";
    for (uint32_t idx = 0; idx < stringArrayLength; ++idx)
    {
        escapedStrings += toEscape(*(stringArray + idx)) + std::string(",");
    }

    // Replace the comma after the last item to a curly bracket.
    escapedStrings.back() = '}';
    return escapedStrings;
}

std::string VulkanCppConsumerBase::escapeStringArray(const std::vector<std::string>& strings)
{
    if (strings.size() == 0)
    {
        return std::string("{\"\"}");
    }

    std::string escapedStrings = "{";
    for (uint32_t idx = 0; idx < strings.size(); ++idx)
    {
        escapedStrings += toEscape(strings[idx]) + std::string(",");
    }

    // Replace the comma after the last item to a curly bracket.
    escapedStrings.back() = '}';
    return escapedStrings;
}

std::string VulkanCppConsumerBase::BuildValue(const VkClearColorValue color)
{
    float values[4];
    /* normalize the float values, to avoid inf/nan outputs */
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

const GfxTocppPlatform getGfxTocppPlatform(const std::string& format_str)
{
    for (const PlatformTargets& entry : kValidTargetPlatforms)
    {
        if (format_str == entry.platformName)
        {
            return entry.platformEnum;
        }
    }

    return GfxTocppPlatform::PLATFORM_COUNT;
}

const std::string GfxTocppPlatformToString(GfxTocppPlatform platform)
{
    for (const PlatformTargets& entry : kValidTargetPlatforms)
    {
        if (platform == entry.platformEnum)
        {
            return entry.platformName;
        }
    }

    return "<unknown platform>";
}

bool gfxTocppPlatformIsValid(const GfxTocppPlatform& platform)
{
    return platform != GfxTocppPlatform::PLATFORM_COUNT;
}

std::string VulkanCppConsumerBase::AddStruct(const std::stringstream& content, const std::string& varnamePrefix)
{
    const std::string str       = content.str();
    uint64_t          hashValue = XXHash64::hash(str.c_str(), str.size(), 0);

    std::string varname    = varnamePrefix + "_" + std::to_string(getNextId());
    m_structMap[hashValue] = varname;

    return varname;
}

void VulkanCppConsumerBase::AddKnownVariables(const std::string& type, const std::string& name)
{
    GfxToCppVariable new_var = { type, name, 0 };
    auto             found =
        std::find_if(m_var_data.begin(), m_var_data.end(), [&cur_var = new_var](const GfxToCppVariable& v) -> bool {
            return (cur_var.type == v.type && cur_var.name == v.name && cur_var.count == v.count);
        });
    if (found == m_var_data.end())
    {
        m_var_data.emplace_back(new_var);
    }
}

void VulkanCppConsumerBase::AddKnownVariables(const std::string& type, const std::string& name, uint32_t count)
{
    GfxToCppVariable new_var = { type, name, count };
    auto             found =
        std::find_if(m_var_data.begin(), m_var_data.end(), [&cur_var = new_var](const GfxToCppVariable& v) -> bool {
            return (cur_var.type == v.type && cur_var.name == v.name && cur_var.count == v.count);
        });
    if (found == m_var_data.end())
    {
        m_var_data.emplace_back(new_var);
    }
}

void VulkanCppConsumerBase::AddKnownVariables(const std::string&      type,
                                              const std::string&      name,
                                              const format::HandleId* handleId)
{
    FILE* file = GetFrameFile();

    GfxToCppVariable variable = { type, name, 0 };
    if (!m_resourceTracker->IsGlobalVariable(*handleId))
    {
        fprintf(file, "//Local var at frame: %d, handle id: %" PRIu64 "\n", m_frameNumber, *handleId);
        fprintf(file, "%s;\n", variable.str().c_str());
        return;
    }
    m_var_data.emplace_back(variable);
}

void VulkanCppConsumerBase::AddKnownVariables(const std::string&      type,
                                              const std::string&      name,
                                              const format::HandleId* handleId,
                                              uint32_t                count)
{
    bool             hasGlobal = std::any_of(handleId, handleId + count, [&](const format::HandleId handleId) {
        return m_resourceTracker->IsGlobalVariable(handleId);
    });
    GfxToCppVariable variable  = { type, name, count };

    if (!hasGlobal)
    {
        fprintf(GetFrameFile(), "//Local var at frame: %d, handle id: %" PRIu64 "\n", m_frameNumber, handleId[0]);
        fprintf(GetFrameFile(), "%s;\n", variable.str().c_str());
        return;
    }
    m_var_data.emplace_back(variable);
}

void VulkanCppConsumerBase::SetMemoryResourceMap(
    const std::map<format::HandleId, std::queue<std::pair<format::HandleId, VkDeviceSize>>> memoryImageMap)
{
    m_memoryResourceMap = memoryImageMap;
}

void VulkanCppConsumerBase::SetWindowSize(uint32_t width, uint32_t height)
{
    m_windowWidth  = width;
    m_windowHeight = height;
}

uint32_t VulkanCppConsumerBase::getNextId()
{
    return m_counters[VK_OBJECT_TYPE_UNKNOWN]++;
}

uint32_t VulkanCppConsumerBase::getNextId(VkObjectType object_type)
{
    if (m_counters.find(object_type) == m_counters.end())
    {
        m_counters[object_type] = 0;
    }
    return m_counters[object_type]++;
}

// Meta data commands

void VulkanCppConsumerBase::ProcessSetDeviceMemoryPropertiesCommand(
    format::HandleId                             physical_device_id,
    const std::vector<format::DeviceMemoryType>& memory_types,
    const std::vector<format::DeviceMemoryHeap>& memory_heaps)
{
    m_original_memory_types.push_back(memory_types);
    m_original_memory_heaps.push_back(memory_heaps);
}

void VulkanCppConsumerBase::ProcessFillMemoryCommand(uint64_t       memory_id,
                                                     uint64_t       offset,
                                                     uint64_t       size,
                                                     const uint8_t* data)
{
    const SavedFileInfo fileInfo = m_dataPacker.AddFileContents(data, size);

    auto entry = m_memoryIdMap.find(memory_id);
    if (entry != m_memoryIdMap.end())
    {
        GenerateLoadData(fileInfo.filePath, fileInfo.byteOffset, m_memoryIdMap[memory_id].c_str(), offset, size);
    }
    else if (m_androidMemoryIdMap.find(memory_id) != m_androidMemoryIdMap.end())
    {
        std::string androidHwMemName = m_androidMemoryIdMap[memory_id];
        FILE*       file             = GetFrameFile();
        fprintf(file, "#if defined(VK_USE_PLATFORM_ANDROID_KHR)\n");
        fprintf(file, "\t{\n");
        fprintf(file, "\t\tresult            = VK_SUCCESS;\n");
        fprintf(file, "\t\tvoid* buffer_data = nullptr;\n");
        fprintf(file, "\t\tint lock_result   = AHardwareBuffer_lock(\n");
        fprintf(file,
                "\t\t\t%s.hardware_buffer, AHARDWAREBUFFER_USAGE_CPU_WRITE_OFTEN, -1, nullptr, &buffer_data);\n",
                androidHwMemName.c_str());
        fprintf(file, "\t\tif (lock_result == 0)\n");
        fprintf(file, "\t\t{\n");
        fprintf(file, "\t\t\tassert(buffer_data != nullptr);\n");
        fprintf(file, "\t\t\tif (%s.plane_info.size() == 1)\n", androidHwMemName.c_str());
        fprintf(file, "\t\t\t{\n");
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size);
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, offset);
        fprintf(file, "\t\t\t\tsize_t   data_size         = static_cast<size_t>(%" PRIu64 ");\n", size);
        fprintf(file, "\t\t\t\tsize_t   data_offset       = static_cast<size_t>(%" PRIu64 ");\n", offset);
        fprintf(file,
                "\t\t\t\tsize_t   capture_row_pitch = %s.plane_info[0].capture_row_pitch;\n",
                androidHwMemName.c_str());
        fprintf(file,
                "\t\t\t\tsize_t   replay_row_pitch  = %s.plane_info[0].replay_row_pitch;\n",
                androidHwMemName.c_str());
        fprintf(file, "\t\t\t\tuint32_t height            = %s.plane_info[0].height;\n", androidHwMemName.c_str());
        fprintf(file, "\t\t\t\tcopyImageSubresourceMemory(static_cast<uint8_t*>(buffer_data),\n");
        fprintf(file, "\t\t\t\t                 data,\n");
        fprintf(file, "\t\t\t\t                 data_offset,\n");
        fprintf(file, "\t\t\t\t                 data_size,v\n");
        fprintf(file, "\t\t\t\t                 replay_row_pitch,\n");
        fprintf(file, "\t\t\t\t                 capture_row_pitch,\n");
        fprintf(file, "\t\t\t\t                 height);\n");
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
        fprintf(file, "\t\t\tlock_result = AHardwareBuffer_unlock(buffer_info.hardware_buffer, nullptr);\n");
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

    if (m_platform == GfxTocppPlatform::PLATFORM_ANDROID)
    {
        fprintf(
            file, "\tscreen.windowSetSizePreTransform(%u, %u, %u);\n", m_windowWidth, m_windowHeight, pre_transform);
    }
    else
    {
        fprintf(file, "\tUpdateWindowSize(%u, %u, %u, appdata);\n", m_windowWidth, m_windowHeight, pre_transform);
    }
}

void VulkanCppConsumerBase::ProcessCreateHardwareBufferCommand(
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
    if (m_platform == GfxTocppPlatform::PLATFORM_ANDROID)
    {
        FILE* file = GetFrameFile();

        std::string androidHwMemName = "hHwBufferMemInfo" + std::to_string(memory_id);
        AddKnownVariables("HardwareBufferMemoryInfo", androidHwMemName);
        m_androidMemoryIdMap[memory_id] = androidHwMemName;

        VulkanCppAndroidBufferInfo buffer_info;
        buffer_info.name      = "aHwBuffer" + std::to_string(buffer_id);
        buffer_info.memory_id = memory_id;
        AddKnownVariables("AHardwareBuffer*", buffer_info.name);
        m_androidBufferIdMap[buffer_id] = buffer_info;

        fprintf(file, "\t{\n");
        fprintf(file, "\t\tAHardwareBuffer_Desc desc = {};\n");
        fprintf(file, "\t\tdesc.format               = %u;\n", format);
        fprintf(file, "\t\tdesc.height               = %u;\n", height);
        fprintf(file, "\t\tdesc.layers               = %u;\n", layers);
        fprintf(file, "\t\tdesc.usage                = %" PRIu64 ";\n", usage);
        fprintf(file, "\t\tdesc.width                = %u;\n", width);
        fprintf(file, "\t\tAHardwareBuffer* buffer = nullptr;\n");
        fprintf(file, "\t\tint              ahwbuf_res = AHardwareBuffer_allocate(&desc, &buffer);\n");
        fprintf(file, "\t\tif ((ahwbuf_res == 0) && (buffer != nullptr))\n");
        fprintf(file, "\t\t{\n");
        fprintf(file, "\t\t\t%s = buffer;\n", buffer_info.name.c_str());
        fprintf(file, "\t\t\tahwbuf_res = -1;\n");
        fprintf(file, "\n");
        fprintf(file, "\t\t\tstd::vector<format::HardwareBufferPlaneInfo> replay_plane_info;\n");
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
        fprintf(file, "\t\t\t\t\t\tformat::HardwareBufferPlaneInfo ahb_plane_info;\n");
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
        fprintf(file,
                "\t\t\t\t\t\t\tprintf(\"ERROR: AHardwareBuffer_unlock failed for AHardwareBuffer object (Buffer "
                "ID = %%\" PRIu64\n");
        fprintf(file, "\t\t\t\t\t\t\t\", Memory ID = %%\" PRIu64 \")\",\n");
        fprintf(file, "\t\t\t\t\t\t\t%" PRIu64 ",\n", buffer_id);
        fprintf(file, "\t\t\t\t\t\t\t%" PRIu64 ");\n", memory_id);
        fprintf(file, "\t\t\t\t\t}\n");
        fprintf(file, "\t\t\t\t}\n");
        fprintf(file, "\t\t\t\telse\n");
        fprintf(file, "\t\t\t\t{\n");
        fprintf(file, "\t\t\t\t\tprintf(\"WARNING: AHardwareBuffer_lockPlanes failed.\");\n");
        fprintf(file, "\t\t\t\t}\n");
        fprintf(file, "\t\t\t}\n");
        fprintf(file, "#endif\n");
        fprintf(file, "\n");
        fprintf(file, "\t\t\t%s.hardware_buffer           = buffer;\n", androidHwMemName.c_str());
        fprintf(file, "\t\t\t%s.compatible_strides        = true;\n", androidHwMemName.c_str());
        fprintf(file, "\n");
        fprintf(file, "\t\t\t// Check for matching strides.\n");
        fprintf(file, "\t\t\tif (plane_info.empty() || replay_plane_info.empty())\n");
        fprintf(file, "\t\t\t{\n");
        fprintf(file, "\t\t\t\tuint32_t bpp = GetHardwareBufferFormatBpp(format);\n");
        fprintf(file, "\n");
        fprintf(file, "\t\t\t\tAHardwareBuffer_describe(buffer, &desc);\n");
        fprintf(file, "\t\t\t\tif (stride != desc.stride)\n");
        fprintf(file, "\t\t\t\t{\n");
        fprintf(file, "\t\t\t\t\t%s.compatible_strides = false;\n", androidHwMemName.c_str());
        fprintf(file, "\t\t\t\t}\n");
        fprintf(file, "\n");
        fprintf(file, "\t\t\t\t%s.plane_info.resize(1);\n", androidHwMemName.c_str());
        fprintf(file, "\t\t\t\t%s.plane_info[0].capture_offset    = 0;\n", androidHwMemName.c_str());
        fprintf(file, "\t\t\t\t%s.plane_info[0].replay_offset     = 0;\n", androidHwMemName.c_str());
        fprintf(file, "\t\t\t\t%s.plane_info[0].capture_row_pitch = bpp * stride;\n", androidHwMemName.c_str());
        fprintf(file, "\t\t\t\t%s.plane_info[0].replay_row_pitch  = bpp * desc.stride;\n", androidHwMemName.c_str());
        fprintf(file, "\t\t\t\t%s.plane_info[0].height            = height;\n", androidHwMemName.c_str());
        fprintf(file, "\t\t\t}\n");
        fprintf(file, "\t\t\telse\n");
        fprintf(file, "\t\t\t{\n");
        fprintf(file, "\t\t\t\tassert(plane_info.size() == replay_plane_info.size());\n");
        fprintf(file, "\n");
        fprintf(file, "\t\t\t\tsize_t layer_count = plane_info.size();\n");
        fprintf(file, "\n");
        fprintf(file, "\t\t\t\t%s.plane_info.resize(layer_count);\n", androidHwMemName.c_str());
        fprintf(file, "\n");
        fprintf(file, "\t\t\t\tfor (size_t i = 0; i < layer_count; ++i)\n");
        fprintf(file, "\t\t\t\t{\n");
        fprintf(
            file, "\t\t\t\t\t%s.plane_info[i].capture_offset    = plane_info[i].offset;\n", androidHwMemName.c_str());
        fprintf(file,
                "\t\t\t\t\t%s.plane_info[i].replay_offset     = replay_plane_info[i].offset;\n",
                androidHwMemName.c_str());
        fprintf(file,
                "\t\t\t\t\t%s.plane_info[i].capture_row_pitch = plane_info[i].row_pitch;\n",
                androidHwMemName.c_str());
        fprintf(file,
                "\t\t\t\t\t%s.plane_info[i].replay_row_pitch  = replay_plane_info[i].row_pitch;\n",
                androidHwMemName.c_str());
        fprintf(file, "\t\t\t\t\t%s.plane_info[i].height            = height;\n", androidHwMemName.c_str());
        fprintf(file, "\n");
        fprintf(file, "\t\t\t\t\tif ((plane_info[i].offset != replay_plane_info[i].offset) ||\n");
        fprintf(file, "\t\t\t\t\t\t(plane_info[i].row_pitch != replay_plane_info[i].row_pitch))\n");
        fprintf(file, "\t\t\t\t\t{\n");
        fprintf(file, "\t\t\t\t\t\t%s.compatible_strides = false;\n", androidHwMemName.c_str());
        fprintf(file, "\t\t\t\t\t}\n");
        fprintf(file, "\t\t\t\t}\n");
        fprintf(file, "\t\t\t}\n");
        fprintf(file, "\t\t}\n");
        fprintf(file, "\t\telse\n");
        fprintf(file, "\t\t{\n");
        fprintf(file,
                "\t\t\tprintf(\"ERROR: AHardwareBuffer_allocate failed for AHardwareBuffer object (Buffer ID = %%\" "
                "PRIu64\n");
        fprintf(file, "\t\t\t\t\t\", Memory ID = %%\" PRIu64 \")\",\n");
        fprintf(file, "\t\t\t\t\t%" PRIu64 ",\n", buffer_id);
        fprintf(file, "\t\t\t\t\t%" PRIu64 ");\n", memory_id);
        fprintf(file, "\t\t}\n");
        fprintf(file, "\t}\n");
    }
}

void VulkanCppConsumerBase::ProcessDestroyHardwareBufferCommand(uint64_t buffer_id)
{
    if (m_androidBufferIdMap.find(buffer_id) != m_androidBufferIdMap.end())
    {
        auto& buffer_info = m_androidBufferIdMap[buffer_id];
        FILE* file        = GetFrameFile();
        fprintf(file, "\t{\n");
        fprintf(file, "\t\tAHardwareBuffer_release(%s);\n", m_androidBufferIdMap[buffer_id].name.c_str());
        m_androidMemoryIdMap.erase(buffer_info.memory_id);
        m_androidBufferIdMap.erase(buffer_id);
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

    m_pfnLoader.AddMethodName("vkCmdPushDescriptorSetWithTemplateKHR");
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
    /* device */
    /* operation */
    m_pfnLoader.AddMethodName("vkDeferredOperationJoinKHR");
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
