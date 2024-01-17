/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
** Copyright (c) 2022-2023 Advanced Micro Devices, Inc. All rights reserved.
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

#include "replay_settings.h"

#include "application/application.h"
#include "decode/file_processor.h"
#include "decode/vulkan_replay_options.h"
#include "decode/vulkan_tracked_object_info_table.h"
#include "generated/generated_vulkan_decoder.h"
#include "generated/generated_vulkan_replay_consumer.h"
#include "graphics/fps_info.h"
#include "util/argument_parser.h"
#include "util/logging.h"
#include "json/json.h"

#if defined(D3D12_SUPPORT)
#include "generated/generated_dx12_decoder.h"
#include "generated/generated_dx12_replay_consumer.h"
#ifdef GFXRECON_AGS_SUPPORT
#include "decode/custom_ags_consumer_base.h"
#include "decode/custom_ags_decoder.h"
#include "decode/custom_ags_replay_consumer.h"
#endif // GFXRECON_AGS_SUPPORT
#include "decode/dx12_tracking_consumer.h"
#include "graphics/dx12_util.h"
#endif

#include <exception>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include <utility>

#if defined(D3D12_SUPPORT)

extern "C"
{
    __declspec(dllexport) extern const UINT D3D12SDKVersion = 610;
}
extern "C"
{
    __declspec(dllexport) extern const char* D3D12SDKPath = u8".\\D3D12\\";
}

#include <conio.h>
void WaitForExit()
{
    DWORD process_list[2];
    DWORD result = GetConsoleProcessList(process_list, ARRAYSIZE(process_list));

    // If the process list contains a single entry, we assume that the console was created when the gfxrecon-replay.exe
    // process started, and will be destroyed when it exits.  In this case, we will wait on user input before exiting
    // and closing the console window to give the user a chance to read any console output.
    if (result <= 1)
    {
        GFXRECON_WRITE_CONSOLE("\nPress any key to close this window . . .");
        while (!_kbhit())
        {
            Sleep(250);
        }
    }
}
#else
void WaitForExit() {}
#endif

static std::string to_lower(std::string s)
{
   for (char &c: s)
   {
       c = tolower(c);
   }
   return s;
}

static bool ends_with(std::string const &fullString, std::string const &ending)
{
    bool rval = false;
    if (fullString.length() >= ending.length())
    {
        rval = (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
    }
    return rval;
}

const char kLayerEnvVar[] = "VK_INSTANCE_LAYERS";

void parse_dump_resources_arg(gfxrecon::decode::VulkanReplayOptions &vulkan_replay_options)
{
     bool parse_error=false;

    // Check to see if dump-resource arg value is a json file.  Do this
    // by simply checking the file name extenstion.
    if (ends_with(to_lower(vulkan_replay_options.dump_resources), ".json"))
    {
        try
        {
            std::ifstream dr_json_file(vulkan_replay_options.dump_resources, std::ifstream::binary);
            Json::Value   jargs;
            dr_json_file >> jargs;

            // Transfer jargs to vectors in vulkan_replay_options
            for (int idx0=0; idx0 <jargs["BeginCommandBuffer"].size(); idx0++)
            {
                vulkan_replay_options.BeginCommandBuffer_Indices.push_back(jargs["BeginCommandBuffer"][idx0].asUInt64());
            }
            for (int idx0=0; idx0 <jargs["CmdDraw"].size(); idx0++)
            {
                vulkan_replay_options.CmdDraw_Indices.push_back(std::vector<uint64_t>());
                for (int idx1=0; idx1 <jargs["CmdDraw"][idx0].size(); idx1++)
                {
                    vulkan_replay_options.CmdDraw_Indices[idx0].push_back(jargs["CmdDraw"][idx0][idx1].asUInt64());
                }
            }
            for (int idx0=0; idx0 <jargs["RenderPass"].size(); idx0++)
            {
                vulkan_replay_options.RenderPass_Indices.push_back(std::vector<std::vector<uint64_t>>());
                for (int idx1=0; idx1 <jargs["RenderPass"][idx0].size(); idx1++)
                {
                    vulkan_replay_options.RenderPass_Indices[idx0].push_back(std::vector<uint64_t>());
                    for (int idx2=0; idx2 <jargs["RenderPass"][idx0][idx1].size(); idx2++)
                    {
                        vulkan_replay_options.RenderPass_Indices[idx0][idx1].push_back(jargs["RenderPass"][idx0][idx1][idx2].asUInt64());
                    }
                }
            }
            for (int idx0=0; idx0 <jargs["NextSubPass"].size(); idx0++)
            {
                vulkan_replay_options.NextSubPass_Indices.push_back(std::vector<std::vector<uint64_t>>());
                for (int idx1=0; idx1 <jargs["NextSubPass"][idx0].size(); idx1++)
                {
                    vulkan_replay_options.NextSubPass_Indices[idx0].push_back(std::vector<uint64_t>());
                    for (int idx2=0; idx2 <jargs["NextSubPass"][idx0][idx1].size(); idx2++)
                    {
                        jargs["NextSubPass"][idx0][idx1][idx2].asUInt64();   // DEBUG
                        vulkan_replay_options.NextSubPass_Indices[idx0][idx1].push_back(jargs["NextSubPass"][idx0][idx1][idx2].asUInt64());
                    }
                }
            }
            for (int idx0=0; idx0 <jargs["CmdDispatch"].size(); idx0++)
            {
                vulkan_replay_options.CmdDispatch_Indices.push_back(std::vector<uint64_t>());
                for (int idx1=0; idx1 <jargs["CmdDispatch"][idx0].size(); idx1++)
                {
                    vulkan_replay_options.CmdDispatch_Indices[idx0].push_back(jargs["CmdDispatch"][idx0][idx1].asUInt64());
                }
            }
            for (int idx0=0; idx0 <jargs["CmdTraceRays"].size(); idx0++)
            {
                vulkan_replay_options.CmdTraceRaysKHR_Indices.push_back(std::vector<uint64_t>());
                for (int idx1=0; idx1 <jargs["CmdTraceRays"][idx0].size(); idx1++)
                {
                    vulkan_replay_options.CmdTraceRaysKHR_Indices[idx0].push_back(jargs["CmdTraceRays"][idx0][idx1].asUInt64());
                }
            }
            for (int idx0=0; idx0 <jargs["QueueSubmit"].size(); idx0++)
            {
                vulkan_replay_options.QueueSubmit_Indices.push_back(jargs["QueueSubmit"][idx0].asUInt64());
            }

        }
        catch (...)
        {
            GFXRECON_LOG_ERROR("Error reading file %s. Bad json format?", vulkan_replay_options.dump_resources.c_str());
            exit(0);
        }
     }
     else
     {
         // Check to see if dump-resource arg value is a file. If it is, read the dump args from the file.
         // Allow either spaces or commas to separate fields in the file.
         std::ifstream infile(vulkan_replay_options.dump_resources);
         std::vector<std::string> drargs;
         if (!infile.fail())
         {
             bool err = false;
             for (std::string line; std::getline(infile, line); )
             {
                 // Remove leading and trailing spaces
                 line.erase(0, line.find_first_not_of(" "));
                 line.erase(line.find_last_not_of(" ")+1);

                 // Remove instances of multiple spaces.
                 // This is slow and inefficient, but it's compact code
                 // and the loop should be executed only a few times.
                 while (line.find("  ") != std::string::npos)
                 {
                     line.replace(line.find("  "), 2, " ");
                 }

                 // Replace spaces with commas
                 std::replace(line.begin(), line.end(), ' ', ',');

                 // Save the modified line
                 drargs.push_back(line);
             }
         }
         else
         {
             // dump-resource args are all specified on the command line
             drargs.push_back(vulkan_replay_options.dump_resources);
         }

         // Process non-json dump_resources args
         size_t apos = 0;
         for (int i=0; i<drargs.size() && !parse_error; i++)
         {
            uint64_t num;
            uint64_t BeginCommandBuffer = 0;
            uint64_t CmdDraw = 0;
            uint64_t RenderPass = 0;
            uint64_t NextSubPass = 0;
            uint64_t CmdDispatch = 0;
            uint64_t CmdTraceRays = 0;
            uint64_t QueueSubmit = 0;
            size_t fstart;
            errno=0;

            while (apos < drargs[i].length() && !parse_error)
            {
                size_t epos, cpos; // '=' and ',' positions
                char *endptr;
                // Find next '=' and next ','
                epos = drargs[i].find_first_of('=', apos);
                cpos = drargs[i].find_first_of(',', apos);
                if (cpos == std::string::npos)
                    cpos = drargs[i].length();

                // Extract number after '='
                num = strtol(drargs[i].c_str()+epos+1, &endptr, 10);
                parse_error |= ((errno != 0) || (*endptr != ',' && *endptr != 0));

                if (drargs[i].compare(apos, epos-apos,"BeginCommandBuffer") == 0)
                    BeginCommandBuffer = num;
                else if (drargs[i].compare(apos, epos-apos,"CmdDraw") == 0)
                    CmdDraw = num;
                else if (drargs[i].compare(apos, epos-apos,"RenderPass") == 0)
                    RenderPass = num;
                else if (drargs[i].compare(apos, epos-apos,"NextSubPass") ==0)
                    NextSubPass = num;
                else if (drargs[i].compare(apos, epos-apos,"CmdDispatch") == 0)
                    CmdDispatch = num;
                else if (drargs[i].compare(apos, epos-apos,"CmdTraceRays") == 0)
                    CmdTraceRays = num;
                else if (drargs[i].compare(apos, epos-apos,"QueueSubmit") == 0)
                    QueueSubmit = num;
                else
                    parse_error = true;

                apos = cpos + 1;
            }

            if (!parse_error)
            {
                vulkan_replay_options.BeginCommandBuffer_Indices.push_back(BeginCommandBuffer);

                vulkan_replay_options.CmdDraw_Indices.push_back(std::vector<uint64_t>());
                vulkan_replay_options.CmdDraw_Indices[i].push_back(CmdDraw);

                vulkan_replay_options.RenderPass_Indices.push_back(std::vector<std::vector<uint64_t>>());
                vulkan_replay_options.RenderPass_Indices[i].push_back(std::vector<uint64_t>());
                vulkan_replay_options.RenderPass_Indices[i][0].push_back(RenderPass);

                vulkan_replay_options.NextSubPass_Indices.push_back(std::vector<std::vector<uint64_t>>());
                vulkan_replay_options.NextSubPass_Indices[i].push_back(std::vector<uint64_t>());
                vulkan_replay_options.NextSubPass_Indices[i][0].push_back(NextSubPass);

                vulkan_replay_options.CmdDispatch_Indices.push_back(std::vector<uint64_t>());
                vulkan_replay_options.CmdDispatch_Indices[i].push_back(CmdDispatch);

                vulkan_replay_options.CmdTraceRaysKHR_Indices.push_back(std::vector<uint64_t>());
                vulkan_replay_options.CmdTraceRaysKHR_Indices[i].push_back(CmdTraceRays);

                vulkan_replay_options.QueueSubmit_Indices.push_back(QueueSubmit);
            }
         }

#if defined(D3D12_SUPPORT)
         // Don't print an error if dx12 is enabled and the option starts with
         // "drawcall-"  --  dx12 option parsing will handle that option.
         if (parse_error && vulkan_replay_options.dump_resources.find("drawcall-", 0 != 0))
#else
         if (parse_error)
#endif
         {
             GFXRECON_LOG_ERROR("ERROR - Ignoring invalid --dump-resources parameter: %s", vulkan_replay_options.dump_resources.c_str());
         }
    }

    // Verify required args are specified. This is not complete. Either e1 or e2 has to be met, but it's
    // possible that if only one is met, there still may be incorrect parameters. And none of the
    // nested lists are checked...
    // This could use some work.
    size_t s =  vulkan_replay_options.BeginCommandBuffer_Indices.size();
    bool e1, e2;
    e1 = (vulkan_replay_options.CmdDraw_Indices.size() < s   ||
        vulkan_replay_options.RenderPass_Indices.size() < s  ||
        vulkan_replay_options.NextSubPass_Indices.size() < s ||
        vulkan_replay_options.QueueSubmit_Indices.size() < s);

    e2 = (vulkan_replay_options.CmdDispatch_Indices.size() +
             vulkan_replay_options.CmdTraceRaysKHR_Indices.size() < s ||
        vulkan_replay_options.QueueSubmit_Indices.size() < s);
    if (e1 && e2)
    {
        parse_error = true;
        GFXRECON_LOG_ERROR("ERROR - incomplete --dump-resources parameters");
    }

     vulkan_replay_options.dump_resource_enabled = !parse_error;
     if (parse_error)
     {
        vulkan_replay_options.BeginCommandBuffer_Indices.clear();
        vulkan_replay_options.CmdDraw_Indices.clear();
        vulkan_replay_options.RenderPass_Indices.clear();
        vulkan_replay_options.NextSubPass_Indices.clear();
        vulkan_replay_options.CmdDispatch_Indices.clear();
        vulkan_replay_options.CmdTraceRaysKHR_Indices.clear();
        vulkan_replay_options.QueueSubmit_Indices.clear();
     }
}

int main(int argc, const char** argv)
{
    int return_code = 0;

    // Default initialize logging to report issues while loading settings.
    gfxrecon::util::Log::Init(gfxrecon::decode::kDefaultLogLevel);

    gfxrecon::util::ArgumentParser arg_parser(argc, argv, kOptions, kArguments);

    if (CheckOptionPrintVersion(argv[0], arg_parser) || CheckOptionPrintUsage(argv[0], arg_parser))
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
        ProcessDisableDebugPopup(arg_parser);
    }

    // Reinitialize logging with values retrieved from command line arguments
    gfxrecon::util::Log::Settings log_settings;
    GetLogSettings(arg_parser, log_settings);
    gfxrecon::util::Log::Release();
    gfxrecon::util::Log::Init(log_settings);

    try
    {
        const std::vector<std::string>& positional_arguments = arg_parser.GetPositionalArguments();
        std::string                     filename             = positional_arguments[0];

        gfxrecon::decode::FileProcessor file_processor;
        if (!file_processor.Initialize(filename))
        {
            return_code = -1;
        }
        else
        {
            // Select WSI context based on CLI
            std::string wsi_extension = GetWsiExtensionName(GetWsiPlatform(arg_parser));
            auto        application =
                std::make_shared<gfxrecon::application::Application>(kApplicationName, wsi_extension, &file_processor);

            gfxrecon::decode::VulkanTrackedObjectInfoTable tracked_object_info_table;
            gfxrecon::decode::VulkanReplayOptions          vulkan_replay_options =
                GetVulkanReplayOptions(arg_parser, filename, &tracked_object_info_table);

            // Process --dump-resources arg. We do it here so that other gfxr tools that use
            // the VulkanReplayOptions class won't have to link in the json library.
            if (!vulkan_replay_options.dump_resources.empty())
            {
                parse_dump_resources_arg(vulkan_replay_options);
            }

            uint32_t start_frame = 0;
            uint32_t end_frame   = 0;

            bool        has_mfr                            = false;
            bool        quit_after_measurement_frame_range = false;
            bool        flush_measurement_frame_range      = false;
            bool        flush_inside_measurement_range     = false;
            std::string measurement_file_name;

            if (vulkan_replay_options.enable_vulkan)
            {
                has_mfr                            = GetMeasurementFrameRange(arg_parser, start_frame, end_frame);
                quit_after_measurement_frame_range = vulkan_replay_options.quit_after_measurement_frame_range;
                flush_measurement_frame_range      = vulkan_replay_options.flush_measurement_frame_range;
                flush_inside_measurement_range     = vulkan_replay_options.flush_inside_measurement_range;
            }

            if (has_mfr)
            {
                GetMeasurementFilename(arg_parser, measurement_file_name);
            }

            gfxrecon::graphics::FpsInfo fps_info(static_cast<uint64_t>(start_frame),
                                                 static_cast<uint64_t>(end_frame),
                                                 has_mfr,
                                                 quit_after_measurement_frame_range,
                                                 flush_measurement_frame_range,
                                                 flush_inside_measurement_range,
                                                 measurement_file_name);

            gfxrecon::decode::VulkanReplayConsumer vulkan_replay_consumer(application, vulkan_replay_options);
            gfxrecon::decode::VulkanDecoder        vulkan_decoder;

            if (vulkan_replay_options.enable_vulkan)
            {
                vulkan_replay_consumer.SetFatalErrorHandler(
                    [](const char* message) { throw std::runtime_error(message); });
                vulkan_replay_consumer.SetFpsInfo(&fps_info);

                vulkan_decoder.AddConsumer(&vulkan_replay_consumer);
                file_processor.AddDecoder(&vulkan_decoder);
            }

#if defined(D3D12_SUPPORT)
            gfxrecon::decode::DxReplayOptions    dx_replay_options = GetDxReplayOptions(arg_parser, filename);
            gfxrecon::decode::Dx12ReplayConsumer dx12_replay_consumer(application, dx_replay_options);
            gfxrecon::decode::Dx12Decoder        dx12_decoder;

#ifdef GFXRECON_AGS_SUPPORT
            gfxrecon::decode::AgsReplayConsumer ags_replay_consumer;
            gfxrecon::decode::AgsDecoder        ags_decoder;
#endif // GFXRECON_AGS_SUPPORT

            if (dx_replay_options.enable_d3d12)
            {
                application->InitializeDx12WsiContext();
                if (gfxrecon::graphics::dx12::VerifyAgilitySDKRuntime() == false)
                {
                    GFXRECON_LOG_ERROR(
                        "Did not find Agility SDK runtimes. Verify \\D3D12\\D3D12Core.dll exists in the same "
                        "directory as gfxrecon-replay.exe.");
                }

                dx12_replay_consumer.SetFatalErrorHandler(
                    [](const char* message) { throw std::runtime_error(message); });
                dx12_replay_consumer.SetFpsInfo(&fps_info);

                // check for user option if first pass tracking is enabled
                if (dx_replay_options.enable_d3d12_two_pass_replay)
                {
                    gfxrecon::decode::FileProcessor              file_processor_tracking;
                    gfxrecon::decode::Dx12TrackedObjectInfoTable tracked_object_info_table;
                    auto                                         tracking_consumer =
                        new gfxrecon::decode::DX12TrackingConsumer(dx_replay_options, &tracked_object_info_table);
                    if (file_processor_tracking.Initialize(filename))
                    {
                        dx12_decoder.AddConsumer(tracking_consumer);
                        file_processor_tracking.AddDecoder(&dx12_decoder);
                        file_processor_tracking.ProcessAllFrames();
                        file_processor_tracking.RemoveDecoder(&dx12_decoder);
                        dx12_decoder.RemoveConsumer(tracking_consumer);
                    }
                }
                dx12_decoder.AddConsumer(&dx12_replay_consumer);
                file_processor.AddDecoder(&dx12_decoder);

#ifdef GFXRECON_AGS_SUPPORT
                ags_replay_consumer.AddDx12Consumer(&dx12_replay_consumer);
                ags_decoder.AddConsumer(reinterpret_cast<gfxrecon::decode::AgsConsumerBase*>(&ags_replay_consumer));

                file_processor.AddDecoder(&ags_decoder);
#endif // GFXRECON_AGS_SUPPORT
            }
#endif

            // Warn if the capture layer is active.
            CheckActiveLayers(gfxrecon::util::platform::GetEnv(kLayerEnvVar));

            fps_info.BeginFile();

            application->SetPauseFrame(GetPauseFrame(arg_parser));
            application->SetFpsInfo(&fps_info);
            application->Run();

            // XXX if the final frame ended with a Present, this would be the *next* frame
            // Add one so that it matches the trim range frame number semantic
            fps_info.EndFile(file_processor.GetCurrentFrameNumber() + 1);

            if ((file_processor.GetCurrentFrameNumber() > 0) &&
                (file_processor.GetErrorState() == gfxrecon::decode::FileProcessor::kErrorNone))
            {
                if (file_processor.GetCurrentFrameNumber() < start_frame)
                {
                    GFXRECON_LOG_WARNING(
                        "Measurement range start frame (%u) is greater than the last replayed frame (%u). "
                        "Measurements were never started, cannot calculate measurement range FPS.",
                        start_frame,
                        file_processor.GetCurrentFrameNumber());
                }
                else
                {
#if defined(D3D12_SUPPORT)
                    dx12_replay_consumer.PostReplay();
                    if (!dx_replay_options.screenshot_ranges.empty() && !file_processor.UsesFrameMarkers() &&
                        (dx12_replay_consumer.GetDXGITestPresentCount() > 0))
                    {
                        GFXRECON_LOG_WARNING_ONCE(
                            "This capture contains %" PRIu32
                            " calls to IDXGISwapChain::Present with flag DXGI_PRESENT_TEST and no frame end markers. "
                            "Screenshot frame indexing may have changed since capture.",
                            dx12_replay_consumer.GetDXGITestPresentCount());
                    }
#endif

                    fps_info.LogToConsole();
                }
            }
            else if (file_processor.GetErrorState() != gfxrecon::decode::FileProcessor::kErrorNone)
            {
                GFXRECON_WRITE_CONSOLE("A failure has occurred during replay");
                return_code = -1;
            }
            else
            {
                GFXRECON_WRITE_CONSOLE("File did not contain any frames");
            }
        }
    }
    catch (const std::runtime_error& error)
    {
        GFXRECON_WRITE_CONSOLE("Replay has encountered a fatal error and cannot continue: %s", error.what());
        return_code = -1;
    }
    catch (const std::exception& error)
    {
        GFXRECON_WRITE_CONSOLE("Replay has encountered a fatal error and cannot continue: %s", error.what());
        return_code = -1;
    }
    catch (...)
    {
        GFXRECON_WRITE_CONSOLE("Replay failed due to an unhandled exception");
        return_code = -1;
    }

    WaitForExit();

    gfxrecon::util::Log::Release();

    return return_code;
}
