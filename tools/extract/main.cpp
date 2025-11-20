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

#include PROJECT_VERSION_HEADER_FILE

#include "decode/file_processor.h"
#include "format/format.h"
#include "generated/generated_vulkan_consumer.h"
#include "generated/generated_vulkan_decoder.h"
#include "util/argument_parser.h"
#include "util/file_path.h"
#include "util/logging.h"

#include "vulkan/vulkan.h"

#include <cstdlib>
#include <string>

const char                  kHelpShortOption[]   = "-h";
const char                  kHelpLongOption[]    = "--help";
const char                  kVersionOption[]     = "--version";
const char                  kDirectoryArgument[] = "--dir";
[[maybe_unused]] const char kNoDebugPopup[]      = "--no-debug-popup";

const char kOptions[]   = "-h|--help,--version,--no-debug-popup";
const char kArguments[] = "--dir";

static void PrintUsage(const char* exe_name)
{
    std::string app_name     = exe_name;
    size_t      dir_location = app_name.find_last_of("/\\");
    if (dir_location != std::string::npos)
    {
        app_name.replace(0, dir_location + 1, "");
    }
    GFXRECON_WRITE_CONSOLE("\n%s - Extract shaders from a GFXReconstruct capture file.\n", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("Usage:");
    GFXRECON_WRITE_CONSOLE("  %s [-h | --help] [--version] [--dir <dir>] <file>\n", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("Required arguments:");
    GFXRECON_WRITE_CONSOLE("  <file>\t\tThe GFXReconstruct capture file to be processed.");
    GFXRECON_WRITE_CONSOLE("Optional arguments:");
    GFXRECON_WRITE_CONSOLE("  -h\t\t\tPrint usage information and exit (same as --help).");
    GFXRECON_WRITE_CONSOLE("  --version\t\tPrint version information and exit.");
    GFXRECON_WRITE_CONSOLE("  --dir <dir>\t\tPlace extracted shaders into directory <dir>. Otherwise");
    GFXRECON_WRITE_CONSOLE("             \t\tuse <file>.shaders in working directory. Create directory");
    GFXRECON_WRITE_CONSOLE("             \t\tif necessary. Each shader is placed in individual file");
    GFXRECON_WRITE_CONSOLE("             \t\tnamed sh<handle_id> where handle_id is handle id of the");
    GFXRECON_WRITE_CONSOLE("             \t\tCreateShaderModule call. See gfxrecon-replay --replace-shaders.");
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

        if (dir_location != std::string::npos)
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

class VulkanExtractConsumer : public gfxrecon::decode::VulkanConsumer
{
  public:
    VulkanExtractConsumer(std::string& extract_dir) : extract_dir_(extract_dir) {}

    virtual void Process_vkCreateShaderModule(
        const gfxrecon::decode::ApiCallInfo&                                                        call_info,
        VkResult                                                                                    returnValue,
        gfxrecon::format::HandleId                                                                  shaderModule,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkAllocationCallbacks>*,
        gfxrecon::decode::HandlePointerDecoder<VkShaderModule>* pShaderModule) override
    {
        if ((returnValue >= 0) && (pCreateInfo != nullptr) && !pCreateInfo->IsNull() && (pShaderModule != nullptr) &&
            !pShaderModule->IsNull())
        {
            const uint32_t* orig_code = pCreateInfo->GetPointer()->pCode;
            size_t          orig_size = pCreateInfo->GetPointer()->codeSize;
            uint64_t        handle_id = *pShaderModule->GetPointer();
            std::string     file_name = "sh" + std::to_string(handle_id);
            std::string     file_path = gfxrecon::util::filepath::Join(extract_dir_, file_name);

            FILE*   fp     = nullptr;
            int32_t result = gfxrecon::util::platform::FileOpen(&fp, file_path.c_str(), "wb");
            if (result == 0)
            {
                if (!gfxrecon::util::platform::FileWrite(orig_code, orig_size, fp))
                {
                    GFXRECON_WRITE_CONSOLE("Error while writing file %s: Could not complete", file_name.c_str());
                }
                gfxrecon::util::platform::FileClose(fp);
            }
            else
            {
                GFXRECON_WRITE_CONSOLE("Error while writing file %s: Could not open", file_name.c_str());
            }
        }
    }

    virtual void Process_vkCreateShadersEXT(
        const gfxrecon::decode::ApiCallInfo&                                                     call_info,
        VkResult                                                                                 returnValue,
        gfxrecon::format::HandleId                                                               device,
        uint32_t                                                                                 createInfoCount,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkShaderCreateInfoEXT>* pCreateInfos,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkAllocationCallbacks>* pAllocator,
        gfxrecon::decode::HandlePointerDecoder<VkShaderEXT>*                                     pShaders) override
    {
        if ((returnValue >= 0) && (pCreateInfos != nullptr) && !pCreateInfos->IsNull() && (pShaders != nullptr) &&
            !pShaders->IsNull())
        {
            for (size_t i = 0; i < createInfoCount; i++)
            {
                const void* orig_code = pCreateInfos->GetPointer()[i].pCode;
                size_t      orig_size = pCreateInfos->GetPointer()[i].codeSize;
                uint64_t    handle_id = pShaders->GetPointer()[i];
                std::string file_name = "sh" + std::to_string(handle_id);
                std::string file_path = gfxrecon::util::filepath::Join(extract_dir_, file_name);

                FILE*   fp     = nullptr;
                int32_t result = gfxrecon::util::platform::FileOpen(&fp, file_path.c_str(), "wb");
                if (result == 0)
                {
                    if (!gfxrecon::util::platform::FileWrite(orig_code, orig_size, fp))
                    {
                        GFXRECON_WRITE_CONSOLE("Error while writing file %s: Could not complete", file_name.c_str());
                    }
                    gfxrecon::util::platform::FileClose(fp);
                }
                else
                {
                    GFXRECON_WRITE_CONSOLE("Error while writing file %s: Could not open", file_name.c_str());
                }
            }
        }
    }

    virtual void Process_vkCreateGraphicsPipelines(
        const gfxrecon::decode::ApiCallInfo&                                                            call_info,
        VkResult                                                                                        returnValue,
        gfxrecon::format::HandleId                                                                      device,
        gfxrecon::format::HandleId                                                                      pipelineCache,
        uint32_t                                                                                        createInfoCount,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkAllocationCallbacks>*        pAllocator,
        gfxrecon::decode::HandlePointerDecoder<VkPipeline>* pPipelines) override
    {
        if ((returnValue >= 0) && (pCreateInfos != nullptr) && !pCreateInfos->IsNull())
        {
            for (size_t i = 0; i < createInfoCount; i++)
            {
                auto& pipeline_create_info = pCreateInfos->GetPointer()[i];
                for (size_t j = 0; j < pipeline_create_info.stageCount; j++)
                {
                    auto& stage_create_info = pipeline_create_info.pStages[i];
                    if (stage_create_info.module != VK_NULL_HANDLE)
                        continue;

                    const void* pNext = stage_create_info.pNext;
                    while (pNext != nullptr)
                    {
                        auto* base = reinterpret_cast<const VkBaseInStructure*>(pNext);
                        if (base->sType == VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO)
                        {
                            auto*       create_info = reinterpret_cast<const VkShaderModuleCreateInfo*>(base);
                            const void* orig_code   = create_info->pCode;
                            size_t      orig_size   = create_info->codeSize;
                            uint64_t    handle_id   = pPipelines->GetPointer()[i];
                            std::string file_name =
                                "sh" + std::to_string(handle_id) + "_" + std::to_string(stage_create_info.stage);
                            std::string file_path = gfxrecon::util::filepath::Join(extract_dir_, file_name);

                            FILE*   fp     = nullptr;
                            int32_t result = gfxrecon::util::platform::FileOpen(&fp, file_path.c_str(), "wb");
                            if (result == 0)
                            {
                                if (!gfxrecon::util::platform::FileWrite(orig_code, orig_size, fp))
                                {
                                    GFXRECON_WRITE_CONSOLE("Error while writing file %s: Could not complete",
                                                           file_name.c_str());
                                }
                                gfxrecon::util::platform::FileClose(fp);
                            }
                            else
                            {
                                GFXRECON_WRITE_CONSOLE("Error while writing file %s: Could not open",
                                                       file_name.c_str());
                            }
                        }
                        pNext = base->pNext;
                    }
                }
            }
        }
    }

  private:
    std::string extract_dir_;
};

int main(int argc, const char** argv)
{
    gfxrecon::util::Log::Init();

    gfxrecon::util::ArgumentParser arg_parser(argc, argv, kOptions, kArguments);

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
        std::string extract_dir = arg_parser.GetArgumentValue(kDirectoryArgument);

        // If no directory argument, use trace file name, minus path, plus .shaders suffix
        if (extract_dir.empty())
        {
            extract_dir         = input_filename;
            size_t dir_location = extract_dir.find_last_of("/\\");
            if (dir_location != std::string::npos)
            {
                extract_dir.replace(0, dir_location + 1, "");
            }
            extract_dir = extract_dir + ".shaders";
        }

        if (gfxrecon::util::filepath::Exists(extract_dir))
        {
            if (!gfxrecon::util::filepath::IsDirectory(extract_dir))
            {
                GFXRECON_WRITE_CONSOLE("Error while creating directory %s: Already exists as file",
                                       extract_dir.c_str());
                exit(-1);
            }
        }
        else
        {
            int32_t result = gfxrecon::util::platform::MakeDirectory(extract_dir.c_str());
            if (result < 0)
            {
                GFXRECON_WRITE_CONSOLE("Error while creating directory %s: Could not open", extract_dir.c_str());
                exit(-1);
            }
        }

        gfxrecon::decode::VulkanDecoder decoder;
        VulkanExtractConsumer           extract_consumer(extract_dir);

        decoder.AddConsumer(&extract_consumer);

        file_processor.AddDecoder(&decoder);
        file_processor.ProcessAllFrames();

        if (file_processor.GetErrorState() != gfxrecon::decode::BlockReadError::kErrorNone)
        {
            GFXRECON_WRITE_CONSOLE("A failure has occurred during file processing");
            gfxrecon::util::Log::Release();
            exit(-1);
        }
        else if (file_processor.GetCurrentFrameNumber() == 0)
        {
            GFXRECON_WRITE_CONSOLE("File did not contain any frames");
        }
    }

    gfxrecon::util::Log::Release();
    return 0;
}
