/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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
    if (m_platform == GfxTocppPlatform::XCB)
    {
        fprintf(m_main_file, "%s", sXcbOutputMainStart);
    }
    else if (m_platform == GfxTocppPlatform::ANDROID)
    {
        fprintf(m_main_file, "%s", sAndroidOutputDrawFunctionStart);
    }
    else
    {
        fprintf(m_main_file,
                "// Nothing to generate for unknown platform: %s\n",
                GfxTocppPlatformToString(m_platform).c_str());
    }
}

void VulkanCppConsumerBase::WriteMainFooter()
{
    if (m_platform == GfxTocppPlatform::XCB)
    {
        fprintf(m_main_file, "%s", sXcbOutputMainEnd);
    }
    else if (m_platform == GfxTocppPlatform::ANDROID)
    {
        fprintf(m_main_file, "%s", sAndroidOutputDrawFunctionEnd);
    }
    else
    {
        fprintf(m_main_file,
                "// Nothing to generate for unknown platform: %s\n",
                GfxTocppPlatformToString(m_platform).c_str());
        return;
    }
}

void VulkanCppConsumerBase::WriteGlobalHeaderFile()
{
    if (m_platform == GfxTocppPlatform::XCB)
    {
        fprintf(GetHeaderFile(),
                "%s%s%s%s",
                sXcbOutputHeadersPlatform,
                sCommonHeaderOutputHeaders,
                sXcbOutputHeader,
                sCommonOutputHeaderFunctions);
    }
    else if (m_platform == GfxTocppPlatform::ANDROID)
    {
        fprintf(GetHeaderFile(),
                "%s%s%s%s",
                sAndroidOutputHeadersPlatform,
                sCommonHeaderOutputHeaders,
                sAndroidOutputHeader,
                sCommonOutputHeaderFunctions);
    }
    else
    {
        fprintf(GetHeaderFile(),
                "// Nothing to generate for unknown platform: %s\n",
                GfxTocppPlatformToString(m_platform).c_str());
        return;
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
        fprintf(cmakeFile, "%s", sXcbCMakeFile);
        util::platform::FileClose(cmakeFile);
    }
    else
    {
        fprintf(stderr, "Error while opening file: %s\n", filename.c_str());
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
                "\nVkMemoryType originalMemoryTypes[%ld][%ld] = {\n",
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

        if (m_platform == GfxTocppPlatform::XCB)
        {
            int  size = snprintf(NULL, 0, sXcbOutputOverrideMethod, m_windowWidth, m_windowHeight);
            char formattedOutputOverrideMethod[size + 2];
            snprintf(formattedOutputOverrideMethod, size + 2, sXcbOutputOverrideMethod, m_windowWidth, m_windowHeight);
            fputs(formattedOutputOverrideMethod, globalFile);
        }
        else if (m_platform == GfxTocppPlatform::ANDROID)
        {
            fputs(sAndroidOutputGlobalSource, globalFile);
        }
        else
        {
            fprintf(m_main_file,
                    "// Nothing to generate for unknown platform: %s\n",
                    GfxTocppPlatformToString(m_platform).c_str());
            return;
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

bool VulkanCppConsumerBase::Initialize(const std::string& filename,
                                       const std::string& platform,
                                       const std::string& outputDir)
{
    bool success = false;

    if (m_main_file == nullptr)
    {
        int32_t result = util::platform::FileOpen(&m_main_file, filename.c_str(), "w");
        if (result == 0)
        {
            m_filename  = filename;
            m_platform  = getGfxTocppPlatform(platform);
            m_outDir    = outputDir;
            m_binOutDir = "bin";
            m_spvOutDir = "spv";
            m_srcOutDir = "src";
            success     = gfxTocppPlatformIsValid(m_platform);

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
            if (m_platform == GfxTocppPlatform::XCB)
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
            "loadData(\"%s\", %lu, %s, %lu, %lu, appdata);\n",
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

void VulkanCppConsumerBase::AddDescriptorUpdateTemplateEntry(format::HandleId                templateHandleId,
                                                             VkDescriptorUpdateTemplateEntry templateEntry)
{
    m_descriptorUpdateTemplateEntryMap[templateHandleId].data.emplace_back(templateEntry);
    switch (GetDescriptorBaseType(templateEntry.descriptorType))
    {
        case DESCRIPTOR_BASE_TYPE_SAMPLER:
        case DESCRIPTOR_BASE_TYPE_IMAGE:
        case DESCRIPTOR_BASE_TYPE_COMBINED_IMAGE_SAMPLER:
        {
            m_descriptorUpdateTemplateEntryMap[templateHandleId].images.emplace_back(templateEntry);
            break;
        }
        case DESCRIPTOR_BASE_TYPE_BUFFER:
        {
            m_descriptorUpdateTemplateEntryMap[templateHandleId].buffers.emplace_back(templateEntry);
            break;
        }
        case DESCRIPTOR_BASE_TYPE_TEXEL:
        {
            m_descriptorUpdateTemplateEntryMap[templateHandleId].texels.emplace_back(templateEntry);
            break;
        }
        default:
        {
            assert(false); // This should never happen
        }
    }
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
        fprintf(file, "uint32_t deviceCount = %d;\n", recorded_count);
        fprintf(file,
                "vkEnumeratePhysicalDevices(%s, &deviceCount, %s);\n",
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
        fprintf(file, "%s = new VkImage[%s];\n", pSwapchainImagesName.c_str(), m_ptrMap[pSwapchainImageCount].c_str());
        AddKnownVariables("VkImage*", pSwapchainImagesName);
        if (returnValue == VK_SUCCESS)
        {
            AddHandles(pSwapchainImagesName, pSwapchainImages->GetPointer(), pSwapchainImages->GetLength());
        }
    }

    m_pfnLoader.AddMethodName("vkGetSwapchainImagesKHR");

    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetSwapchainImagesKHR(%s, %s, &%s, %s), %s);\n",
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
        fprintf(file, "uint32_t %s;\n", pSurfaceFormatCountName.c_str());
        m_ptrMap[pSurfaceFormatCount] = pSurfaceFormatCountName;
    }
    else
    {
        pSurfaceFormatsName = "pSurfaceFormats_" + std::to_string(getNextId());
        fprintf(
            file, "VkSurfaceFormatKHR %s[%s];\n", pSurfaceFormatsName.c_str(), m_ptrMap[pSurfaceFormatCount].c_str());
        // TODO: connect these formats to their usages? How?
    }

    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceSurfaceFormatsKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPhysicalDeviceSurfaceFormatsKHR(%s, %s, &%s, %s), %s);\n",
            GetHandle(physicalDevice).c_str(),
            GetHandle(surface).c_str(),
            m_ptrMap[pSurfaceFormatCount].c_str(),
            pSurfaceFormatsName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
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
        fprintf(file, "uint32_t %s;\n", pPresentModeCountName.c_str());
        m_ptrMap[pPresentModeCount] = pPresentModeCountName;
    }
    else
    {
        pPresentModesName = "pPresentModes_" + std::to_string(getNextId());
        fprintf(file, "VkPresentModeKHR %s[%s];\n", pPresentModesName.c_str(), m_ptrMap[pPresentModeCount].c_str());
        // TODO: connect these formats to their usages? How?
    }

    m_pfnLoader.AddMethodName("vkGetPhysicalDeviceSurfacePresentModesKHR");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkGetPhysicalDeviceSurfacePresentModesKHR(%s, %s, &%s, %s), %s);\n",
            GetHandle(physicalDevice).c_str(),
            GetHandle(surface).c_str(),
            m_ptrMap[pPresentModeCount].c_str(),
            pPresentModesName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
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
        fprintf(file, "uint32_t %s;\n", pQueueFamilyPropertyCountName.c_str());
        m_ptrMap[pQueueFamilyPropertyCount] = pQueueFamilyPropertyCountName;
    }
    else
    {
        pQueueFamilyPropertiesName = "pQueueFamilyProperties_" + std::to_string(getNextId());
        fprintf(file,
                "VkQueueFamilyProperties %s[%s];\n",
                pQueueFamilyPropertiesName.c_str(),
                m_ptrMap[pQueueFamilyPropertyCount].c_str());
        // TODO: connect these formats to their usages? How?
    }

    fprintf(file,
            "vkGetPhysicalDeviceQueueFamilyProperties(%s, &%s, %s);\n",
            GetHandle(physicalDevice).c_str(),
            m_ptrMap[pQueueFamilyPropertyCount].c_str(),
            pQueueFamilyPropertiesName.c_str());
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
            "vkGetImageMemoryRequirements(%s, %s, &%s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(image).c_str(),
            pMemoryRequirementsName.c_str());

    m_resourceMemoryReqMap[image] = pMemoryRequirementsName;
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
            "vkGetBufferMemoryRequirements(%s, %s, &%s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(buffer).c_str(),
            pMemoryRequirementsName.c_str());

    m_resourceMemoryReqMap[buffer] = pMemoryRequirementsName;
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
    fprintf(file, "uint32_t %s;\n", pSparseMemoryRequirementCountName.c_str());

    std::string pSparseMemoryRequirementsName =
        "pSparseMemoryRequirements_" + std::to_string(VulkanCppConsumerBase::getNextId());
    const uint32_t* in_pSparseMemoryRequirementCount = pSparseMemoryRequirementCount->GetPointer();

    AddKnownVariables(
        "VkSparseImageMemoryRequirements", pSparseMemoryRequirementsName, *in_pSparseMemoryRequirementCount);
    fprintf(file,
            "vkGetImageSparseMemoryRequirements(%s, %s, &%s, %s);\n",
            this->GetHandle(device).c_str(),
            this->GetHandle(image).c_str(),
            pSparseMemoryRequirementCountName.c_str(),
            pSparseMemoryRequirementsName.c_str());

    m_resourceMemoryReqMap[image] = pSparseMemoryRequirementsName;
}

void VulkanCppConsumerBase::Generate_vkGetImageMemoryRequirements2KHR(
    format::HandleId                                              device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>*          pMemoryRequirements)
{
    FILE* file = GetFrameFile();

    std::stringstream stream_pInfo;
    std::string       pInfoStruct = GenerateStruct_VkImageMemoryRequirementsInfo2(
        stream_pInfo, pInfo->GetPointer(), pInfo->GetMetaStructPointer(), *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());

    std::string pMemoryRequirementsName = "pMemoryRequirements_" + std::to_string(VulkanCppConsumerBase::getNextId());
    std::stringstream stream_pMemoryRequirements;
    pMemoryRequirementsName = GenerateStruct_VkMemoryRequirements2(stream_pMemoryRequirements,
                                                                   pMemoryRequirements->GetPointer(),
                                                                   pMemoryRequirements->GetMetaStructPointer(),
                                                                   *this);
    AddKnownVariables("VkMemoryRequirements2", pMemoryRequirementsName);

    fprintf(file, "%s", stream_pMemoryRequirements.str().c_str());
    m_pfnLoader.AddMethodName("vkGetImageMemoryRequirements2KHR");
    fprintf(file,
            "loaded_vkGetImageMemoryRequirements2KHR(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str(),
            pMemoryRequirementsName.c_str());

    m_resourceMemoryReqMap[pInfo->GetMetaStructPointer()->image] = pMemoryRequirementsName + ".memoryRequirements";
}

void VulkanCppConsumerBase::Generate_vkGetBufferMemoryRequirements2KHR(
    format::HandleId                                               device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>*           pMemoryRequirements)
{
    FILE* file = GetFrameFile();

    std::stringstream stream_pInfo;
    std::string       pInfoStruct = GenerateStruct_VkBufferMemoryRequirementsInfo2(
        stream_pInfo, pInfo->GetPointer(), pInfo->GetMetaStructPointer(), *this);
    fprintf(file, "\n%s", stream_pInfo.str().c_str());

    std::string pMemoryRequirementsName = "pMemoryRequirements_" + std::to_string(VulkanCppConsumerBase::getNextId());
    std::stringstream stream_pMemoryRequirements;
    pMemoryRequirementsName = GenerateStruct_VkMemoryRequirements2(stream_pMemoryRequirements,
                                                                   pMemoryRequirements->GetPointer(),
                                                                   pMemoryRequirements->GetMetaStructPointer(),
                                                                   *this);
    AddKnownVariables("VkMemoryRequirements2", pMemoryRequirementsName);

    fprintf(file, "%s", stream_pMemoryRequirements.str().c_str());
    m_pfnLoader.AddMethodName("vkGetBufferMemoryRequirements2KHR");
    fprintf(file,
            "loaded_vkGetBufferMemoryRequirements2KHR(%s, &%s, &%s);\n",
            this->GetHandle(device).c_str(),
            pInfoStruct.c_str(),
            pMemoryRequirementsName.c_str());

    m_resourceMemoryReqMap[pInfo->GetMetaStructPointer()->buffer] = pMemoryRequirementsName + ".memoryRequirements";
}

void VulkanCppConsumerBase::Generate_vkGetFenceStatus(VkResult         returnValue,
                                                      format::HandleId device,
                                                      format::HandleId fence)
{
    if (returnValue == VK_SUCCESS)
    {
        fprintf(GetFrameFile(),
                "while( vkGetFenceStatus(%s, %s) != VK_SUCCESS) { usleep(5000); }\n",
                this->GetHandle(device).c_str(),
                this->GetHandle(fence).c_str());
    }
    else
    {
        fprintf(GetFrameFile(),
                "VK_CALL_CHECK(vkGetFenceStatus(%s, %s), %s);\n",
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
            "VK_CALL_CHECK(vkMapMemory(%s, %s, %luUL, %luUL, %s, &%s), %s);\n",
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
    fprintf(GetFrameFile(), "vkUnmapMemory(%s, %s);\n", m_handleIdMap[device].c_str(), m_handleIdMap[memory].c_str());

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
    fprintf(file, "\n%s", stream_pAllocateInfo.str().c_str());
    std::string pMemoryName = "pMemory_" + std::to_string(this->getNextId());
    AddKnownVariables("VkDeviceMemory", pMemoryName, pMemory->GetPointer());
    if (returnValue == VK_SUCCESS)
    {
        this->AddHandles(pMemoryName, pMemory->GetPointer());
    }
    fprintf(file,
            "VK_CALL_CHECK(vkAllocateMemory(%s, &%s, %s, &%s), %s);\n",
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

        fprintf(file, "uint8_t %s[%ld];\n", temp_memory_name.c_str(), dataSize);
    }

    if (returnValue == VK_SUCCESS)
    {
        fprintf(file,
                "while( vkGetQueryPoolResults(%s, %s, %u, %u, %lu, %s, %luUL, %s) != VK_SUCCESS) { usleep(5000); }\n",
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
                "VK_CALL_CHECK(vkGetQueryPoolResults(%s, %s, %u, %u, %lu, %s, %luUL, %s), %s);\n",
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
        pApplicationInfoStruct = "&" + GenerateStruct_VkApplicationInfo(
            out, structInfo->pApplicationInfo, metainfo->pApplicationInfo->GetMetaStructPointer(), consumer);
    }

    /* Print out enabled layers if there is any */
    std::string ppEnabledLayerNamesValue = "NULL";
    if (layerNames.size() > 0)
    {
        ppEnabledLayerNamesValue = "ppEnabledLayerNames_" + std::to_string(consumer.getNextId());
        out << "const char* " << ppEnabledLayerNamesValue
            << "[] = " << VulkanCppConsumerBase::escapeStringArray(layerNames) << ";" << std::endl;
    }

    std::vector<std::string> extensionNames;
    std::string              ppEnabledExtensionNamesValue = "NULL";
    if (structInfo->enabledExtensionCount > 0)
    {
        extensionNames = replaceExtensions(structInfo->ppEnabledExtensionNames,
                                           structInfo->enabledExtensionCount,
                                           GetWSIRemapInfo(consumer.GetPlatform()));

        ppEnabledExtensionNamesValue = "ppEnabledExtensionNames_" + std::to_string(consumer.getNextId());
        out << "const char* " << ppEnabledExtensionNamesValue
            << "[] = " << VulkanCppConsumerBase::escapeStringArray(extensionNames) << ";" << std::endl;
    }

    out << "VkInstanceCreateInfo " << varname << " = {" << std::endl;
    out << "/* sType */ " << util::ToString<VkStructureType>(structInfo->sType) << "," << std::endl;
    out << "/* pNext */ " << pNextName << "," << std::endl;
    out << "/* flags */ " << util::ToString<VkInstanceCreateFlags>(structInfo->flags) << "," << std::endl;
    out << "/* pApplicationInfo */ " << pApplicationInfoStruct << "," << std::endl;
    out << "/* enabledLayerCount */ " << layerNames.size() << "," << std::endl;
    out << "/* ppEnabledLayerNames */ " << ppEnabledLayerNamesValue << "," << std::endl;
    out << "/* enabledExtensionCount */ " << extensionNames.size() << "," << std::endl;
    out << "/* ppEnabledExtensionNames */ " << ppEnabledExtensionNamesValue << "," << std::endl;
    out << "};" << std::endl;

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

    fprintf(file, "{\n");
    fprintf(file, "%s", instanceCreateInfoStr.str().c_str());
    fprintf(file,
            "VK_CALL_CHECK(vkCreateInstance(&%s, %s, &%s), %s);\n",
            pCreateInfoStruct.c_str(),
            "nullptr",
            pInstanceName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());

    fprintf(file, "loadFunctions(%s);\n", pInstanceName.c_str());
    fprintf(file, "}\n");

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
    fprintf(GetFrameFile(), "QueryPhysicalDeviceMemoryProperties(%s);\n", this->GetHandle(physicalDevice).c_str());
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

    fprintf(file, "uint8_t *%s = new uint8_t[%zu];\n", pCodeName.c_str(), structInfo->codeSize);
    GenerateLoadData(fileInfo.filePath, fileInfo.byteOffset, pCodeName, 0, structInfo->codeSize);

    std::string pCreateInfoStruct = "pCreateInfo_" + std::to_string(VulkanCppConsumerBase::getNextId());

    std::stringstream outStruct;
    outStruct << "VkShaderModuleCreateInfo " << pCreateInfoStruct << " = {" << std::endl;
    outStruct << "/* sType */ " << util::ToString<VkStructureType>(structInfo->sType) << "," << std::endl;
    outStruct << "/* pNext */ " << structInfo->pNext << "," << std::endl;
    outStruct << "/* flags */ " << util::ToString<VkShaderModuleCreateFlags>(structInfo->flags) << "," << std::endl;
    outStruct << "/* codeSize */ " << structInfo->codeSize << "," << std::endl;
    outStruct << "/* pCode */ (const uint32_t*)" << pCodeName << "," << std::endl;
    outStruct << "};" << std::endl;
    fprintf(file, "%s", outStruct.str().c_str());

    std::string pShaderModuleName = "pShaderModule_" + std::to_string(VulkanCppConsumerBase::getNextId());
    AddKnownVariables("VkShaderModule", pShaderModuleName, pShaderModule->GetPointer());

    if (returnValue == VK_SUCCESS)
    {
        AddHandles(pShaderModuleName, pShaderModule->GetPointer());
    }
    fprintf(file,
            "VK_CALL_CHECK(vkCreateShaderModule(%s, &%s, %s, &%s), %s);\n",
            GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pShaderModuleName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());

    /* emit delete the allocated spv data. */
    fprintf(file, "delete [] %s;\n\n", pCodeName.c_str());
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

    std::string       pCreateInfoStruct = "pCreateInfo_" + std::to_string(VulkanCppConsumerBase::getNextId());
    std::stringstream stream_pCreateInfo;

    stream_pCreateInfo << "VkPipelineCacheCreateInfo " << pCreateInfoStruct << " {" << std::endl;
    stream_pCreateInfo << "/* sType */ " << util::ToString<VkStructureType>(structInfo->sType) << "," << std::endl;
    stream_pCreateInfo << "/* pNext */ " << structInfo->pNext << "," << std::endl;
    stream_pCreateInfo << "/* flags */ " << util::ToString<VkPipelineCacheCreateFlags>(structInfo->flags) << ","
                       << std::endl;
    stream_pCreateInfo << "/* initialDataSize */ "
                       << "0"
                       << "," << std::endl;
    stream_pCreateInfo << "/* pInitialData */ "
                       << "NULL"
                       << "," << std::endl;
    stream_pCreateInfo << "};" << std::endl;
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());

    std::string pPipelineCacheName = "pPipelineCache_" + std::to_string(VulkanCppConsumerBase::getNextId());
    AddKnownVariables("VkPipelineCache", pPipelineCacheName);

    if (returnValue == VK_SUCCESS)
    {
        AddHandles(pPipelineCacheName, pPipelineCache->GetPointer());
    }
    fprintf(file,
            "VK_CALL_CHECK(vkCreatePipelineCache(%s, &%s, %s, &%s), %s);\n",
            GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pPipelineCacheName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
}

void VulkanCppConsumerBase::Generate_vkCreateXcbSurfaceKHR(
    VkResult                                                 returnValue,
    format::HandleId                                         instance,
    StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*     pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                      pSurface)
{
    GenerateSurfaceCreation(GfxTocppPlatform::XCB, returnValue, instance, (void*)pCreateInfo, pSurface->GetPointer());
}

void VulkanCppConsumerBase::Generate_vkCreateWaylandSurfaceKHR(
    VkResult                                                     returnValue,
    format::HandleId                                             instance,
    StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                          pSurface)
{
    GenerateSurfaceCreation(GfxTocppPlatform::XCB, returnValue, instance, (void*)pCreateInfo, pSurface->GetPointer());
}

void VulkanCppConsumerBase::Generate_vkCreateAndroidSurfaceKHR(
    VkResult                                                     returnValue,
    format::HandleId                                             instance,
    StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                          pSurface)
{
    GenerateSurfaceCreation(
        GfxTocppPlatform::ANDROID, returnValue, instance, (void*)pCreateInfo, pSurface->GetPointer());
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

    switch (m_platform)
    {
        case GfxTocppPlatform::XCB:
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
        case GfxTocppPlatform::ANDROID:
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
        case GfxTocppPlatform::NONE:
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
            "VK_CALL_CHECK(loaded_%s(%s, &%s, %s, &%s), %s);\n",
            pSurfaceCreateCall.c_str(),
            GetHandle(instance).c_str(),
            pCreateInfoStruct.c_str(),
            "nullptr",
            pSurfaceName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
}

void VulkanCppConsumerBase::Intercept_vkCreateSwapchainKHR(
    VkResult                                                returnValue,
    format::HandleId                                        device,
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*                   pSwapchain)
{
    VkSwapchainCreateInfoKHR* structInfo = pCreateInfo->GetPointer();
    structInfo->imageExtent.width        = GetProperWindowWidth(structInfo->imageExtent.width);
    structInfo->imageExtent.height       = GetProperWindowHeight(structInfo->imageExtent.height);
}

void VulkanCppConsumerBase::Intercept_vkCreateFramebuffer(
    VkResult                                               returnValue,
    format::HandleId                                       device,
    StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*   pAllocator,
    HandlePointerDecoder<VkFramebuffer>*                   pFramebuffer)
{
    VkFramebufferCreateInfo* structInfo = pCreateInfo->GetPointer();
    structInfo->width                   = GetProperWindowWidth(structInfo->width);
    structInfo->height                  = GetProperWindowHeight(structInfo->height);
}

void VulkanCppConsumerBase::Intercept_vkCmdBeginRenderPass(
    format::HandleId                                     commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                                    contents)
{
    VkRenderPassBeginInfo* structInfo    = pRenderPassBegin->GetPointer();
    structInfo->renderArea.extent.width  = GetProperWindowWidth(structInfo->renderArea.extent.width);
    structInfo->renderArea.extent.height = GetProperWindowHeight(structInfo->renderArea.extent.height);
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
                "while (loaded_vkAcquireNextImageKHR(%s, %s, %luUL, %s, %s, &%s) != VK_SUCCESS) { usleep(5000); };\n",
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
                "VK_CALL_CHECK(loaded_vkAcquireNextImageKHR(%s, %s, %luUL, %s, %s, &%s), %s);\n",
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
    fprintf(file, "uint32_t %s;\n", pImageIndexName.c_str());
    m_pfnLoader.AddMethodName("vkAcquireNextImage2KHR");

    if (returnValue == VK_SUCCESS)
    {
        fprintf(file,
                "while (loaded_vkAcquireNextImage2KHR(%s, %s, &%s)) != VK_SUCCESS) { usleep(5000); };\n",
                GetHandle(device).c_str(),
                pAcquireInfoStruct.c_str(),
                pImageIndexName.c_str());
    }
    else
    {
        fprintf(file,
                "VK_CALL_CHECK(loaded_vkAcquireNextImage2KHR(%s, &%s, &%s), %s);\n",
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
    FILE*       file          = GetFrameFile();
    std::string pFencesArray  = "NULL";
    std::string pFencesValues = toStringJoin(
        pFences->GetPointer(),
        pFences->GetPointer() + fenceCount,
        [&](const format::HandleId current) { return GetHandle(current); },
        ", ");
    fprintf(file, "{");
    if (fenceCount == 1)
    {
        pFencesArray = "&" + pFencesValues;
    }
    else if (fenceCount > 1)
    {
        pFencesArray = "pFencesArray_" + std::to_string(getNextId());
        fprintf(file, "\tVkFence %s[] = { %s };\n", pFencesArray.c_str(), pFencesValues.c_str());
    }
    if (returnValue == VK_SUCCESS)
    {
        fprintf(file,
                "\twhile (vkWaitForFences(%s, %u, %s, %u, %luUL) != VK_SUCCESS) { usleep(5000); };\n",
                GetHandle(device).c_str(),
                fenceCount,
                pFencesArray.c_str(),
                waitAll,
                timeout);
    }
    else
    {
        fprintf(file,
                "\tVK_CALL_CHECK(vkWaitForFences(%s, %u, %s, %u, %luUL), %s);\n",
                GetHandle(device).c_str(),
                fenceCount,
                pFencesArray.c_str(),
                waitAll,
                timeout,
                util::ToString<VkResult>(returnValue).c_str());
    }
    fprintf(file, "}");
}

void VulkanCppConsumerBase::Generate_vkCreateDescriptorUpdateTemplate(
    VkResult                                                            returnValue,
    format::HandleId                                                    device,
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*                pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>*                   pDescriptorUpdateTemplate)
{
    FILE*             file = GetFrameFile();
    std::stringstream stream_pCreateInfo;
    std::string       pCreateInfoStruct = GenerateStruct_VkDescriptorUpdateTemplateCreateInfo(
        stream_pCreateInfo, pCreateInfo->GetPointer(), pCreateInfo->GetMetaStructPointer(), *this);
    fprintf(file, "\n%s", stream_pCreateInfo.str().c_str());
    std::string pDescriptorUpdateTemplateName = "pDescriptorUpdateTemplate_" + std::to_string(this->getNextId());
    AddKnownVariables("VkDescriptorUpdateTemplate", pDescriptorUpdateTemplateName);

    VkDescriptorUpdateTemplateCreateInfo* templateCreateInfo = pCreateInfo->GetPointer();
    for (uint32_t idx = 0; idx < templateCreateInfo->descriptorUpdateEntryCount; idx++)
    {
        AddDescriptorUpdateTemplateEntry(*pDescriptorUpdateTemplate->GetPointer(),
                                         templateCreateInfo->pDescriptorUpdateEntries[idx]);
    }

    if (returnValue == VK_SUCCESS)
    {
        this->AddHandles(pDescriptorUpdateTemplateName, pDescriptorUpdateTemplate->GetPointer());
    }

    m_pfnLoader.AddMethodName("vkCreateDescriptorUpdateTemplate");
    fprintf(file,
            "VK_CALL_CHECK(loaded_vkCreateDescriptorUpdateTemplate(%s, &%s, NULL, &%s), %s);\n",
            this->GetHandle(device).c_str(),
            pCreateInfoStruct.c_str(),
            pDescriptorUpdateTemplateName.c_str(),
            util::ToString<VkResult>(returnValue).c_str());
}

void VulkanCppConsumerBase::Generate_vkUpdateDescriptorSetWithTemplate(format::HandleId device,
                                                                          format::HandleId descriptorSet,
                                                                          format::HandleId descriptorUpdateTemplate,
                                                                          DescriptorUpdateTemplateDecoder* pData)
{
    FILE* file = GetFrameFile();

    assert(m_descriptorUpdateTemplateEntryMap.find(descriptorUpdateTemplate) != m_descriptorUpdateTemplateEntryMap.end());

    // Generate template type
    const DescriptorUpdateTemplateEntries& templateEntries =
        m_descriptorUpdateTemplateEntryMap[descriptorUpdateTemplate];

    // Check if the number of descriptors in pData equal the number of descriptors in the template
    uint32_t templateDescriptorCount = 0;
    for (const VkDescriptorUpdateTemplateEntry& entry : templateEntries.data)
    {
        templateDescriptorCount += entry.descriptorCount;
    }
    uint32_t pDataCount = pData->GetImageInfoCount() + pData->GetBufferInfoCount() + pData->GetTexelBufferViewCount();
    assert(templateDescriptorCount == pDataCount);

    std::string       templateTypeName = "TemplateType_" + std::to_string(getNextId());
    std::stringstream templateMembersStream;

    for (auto const& imageEntry : templateEntries.data)
    {
        std::string createInfoType = DescriptorCreateInfoTypeToString(imageEntry.descriptorType);
        templateMembersStream << "\t" << createInfoType << " " << createInfoType << "_" << getNextId() << "["
                              << imageEntry.descriptorCount << "];" << std::endl;
    }

    // Print the generated type
    fprintf(file, "struct %s {\n%s};", templateTypeName.c_str(), templateMembersStream.str().c_str());

    std::vector<std::string> pDescriptorInfoValues;
    if (pData->GetImageInfoPointer() != nullptr && pData->GetImageInfoCount())
    {
        std::stringstream stream_pDescriptorImageInfos;

        uint32_t templateIdx     = 0;
        uint32_t descriptorCount = templateEntries.images.front().descriptorCount;

        for (uint32_t idx = 0; idx < pData->GetImageInfoCount(); idx++)
        {
            // Only use the next template if every descriptor has been generated for the current template
            if (idx == descriptorCount)
            {
                templateIdx++;
                descriptorCount += templateEntries.images[templateIdx].descriptorCount;
            }

            std::string varName = GenerateStruct_VkDescriptorImageInfo(stream_pDescriptorImageInfos,
                                                                       templateEntries.images[templateIdx],
                                                                       pData->GetImageInfoPointer() + idx,
                                                                       pData->GetImageInfoMetaStructPointer() + idx,
                                                                       *this);
            pDescriptorInfoValues.emplace_back(varName);
        }
        fprintf(file, "\n%s", stream_pDescriptorImageInfos.str().c_str());
    }

    if (pData->GetBufferInfoPointer() != nullptr)
    {
        std::stringstream stream_pDescriptorBufferInfos;

        for (uint32_t idx = 0; idx < pData->GetBufferInfoCount(); idx++)
        {
            std::string varName = GenerateStruct_VkDescriptorBufferInfo(stream_pDescriptorBufferInfos,
                                                                        pData->GetBufferInfoPointer() + idx,
                                                                        pData->GetBufferInfoMetaStructPointer() + idx,
                                                                        *this);
            pDescriptorInfoValues.emplace_back(varName);
        }
        fprintf(file, "\n%s", stream_pDescriptorBufferInfos.str().c_str());
    }

    // TODO: Due to a lack of test examples using texel buffer views, this part requires more testing
    if (pData->GetTexelBufferViewPointer() != nullptr)
    {
        for (uint32_t idx = 0; idx < pData->GetTexelBufferViewCount(); idx++)
        {
            pDescriptorInfoValues.emplace_back(GetHandle(pData->GetTexelBufferViewHandleIdsPointer()[idx]));
        }
    }

    std::string       pDataStructName = "pData_" + std::to_string(getNextId());
    std::stringstream pDataStructStream;
    pDataStructStream << templateTypeName << " " << pDataStructName << " {" << std::endl;
    uint32_t counter = 0;
    for (auto const& entry : templateEntries.data)
    {
        std::string createInfoType = DescriptorCreateInfoTypeToString(entry.descriptorType);

        pDataStructStream << "\t"
                          << "{ ";
        for (uint32_t jdx = 0; jdx < entry.descriptorCount; jdx++)
        {
            pDataStructStream << pDescriptorInfoValues[counter] << ", ";
            counter++;
        }
        pDataStructStream << "}," << std::endl;
    }
    pDataStructStream << "};";
    fprintf(file, "%s\n", pDataStructStream.str().c_str());

    m_pfnLoader.AddMethodName("vkUpdateDescriptorSetWithTemplate");
    fprintf(file,
            "loaded_vkUpdateDescriptorSetWithTemplate%s(%s, %s, %s, &%s);\n",
            GetHandle(device).c_str(),
            GetHandle(descriptorSet).c_str(),
            GetHandle(descriptorUpdateTemplate).c_str(),
            pDataStructName.c_str());
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
    GenerateLoadData(fileInfo.filePath, fileInfo.byteOffset, m_memoryIdMap[memory_id].c_str(), offset, size);
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

    if (m_platform == GfxTocppPlatform::ANDROID)
    {
        fprintf(file, "screen.windowSetSizePreTransform(%u, %u, %u);\n", m_windowWidth, m_windowHeight, pre_transform);
    }
    else
    {
        fprintf(file, "UpdateWindowSize(%u, %u, %u, appdata);\n", m_windowWidth, m_windowHeight, pre_transform);
    }
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

std::string VulkanCppConsumerBase::BuildValue(const VkClearValue* clearValue)
{
    std::stringstream output;
    output << "{ (VkClearColorValue)" << BuildValue(clearValue->color) << " }";
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
    output << "(VkFragmentShadingRateCombinerOpKHR){ " << util::ToString<VkFragmentShadingRateCombinerOpKHR>(value) << " }";
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

static GfxTocppPlatformMap GfxTocppPlatformMapping[] = {
    { GfxTocppPlatform::ANDROID, "android" },
    { GfxTocppPlatform::XCB, "xcb" },
};

const GfxTocppPlatform getGfxTocppPlatform(const std::string& format_str)
{
    for (const GfxTocppPlatformMap& entry : GfxTocppPlatformMapping)
    {
        if (format_str == entry.platform_str)
        {
            return entry.platform;
        }
    }

    return GfxTocppPlatform::NONE;
}

const std::string GfxTocppPlatformToString(GfxTocppPlatform platform)
{
    for (const GfxTocppPlatformMap& entry : GfxTocppPlatformMapping)
    {
        if (platform == entry.platform)
        {
            return entry.platform_str;
        }
    }

    return "<unknown platform>";
}

bool gfxTocppPlatformIsValid(const GfxTocppPlatform& platform)
{
    return platform != GfxTocppPlatform::NONE;
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
        fprintf(file, "//Local var at frame: %d, handle id: %lu\n", m_frameNumber, *handleId);
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
        fprintf(GetFrameFile(), "//Local var at frame: %d, handle id: %lu\n", m_frameNumber, handleId[0]);
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
    if (m_counters.find(object_type) == m_counters.end()) {
        m_counters[object_type] = 0;
    }
    return m_counters[object_type]++;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
