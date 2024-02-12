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
#include "util/logging.h"
#include "json/json.h"

#include <string>
#include <vector>
#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(parse_dump_resources)

static std::string to_lower(std::string s)
{
    for (char& c : s)
    {
        c = tolower(c);
    }
    return s;
}

static bool ends_with(std::string const& fullString, std::string const& ending)
{
    bool rval = false;
    if (fullString.length() >= ending.length())
    {
        rval = (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
    }
    return rval;
}

static bool AreIndicesSorted(const std::vector<uint64_t>& indices)
{
    if (indices.size() == 1)
    {
        return true;
    }

    for (size_t i = 1; i < indices.size(); ++i)
    {
        if (indices[i] <= indices[i - 1])
        {
            return false;;
        }
    }

    return true;
}

static bool CheckIndicesForErrors(const gfxrecon::decode::VulkanReplayOptions& vulkan_replay_options)
{
    // Indices should be provided sorted
    if (vulkan_replay_options.BeginCommandBuffer_Indices.size() > 1)
    {
        if (!AreIndicesSorted(vulkan_replay_options.BeginCommandBuffer_Indices))
        {
            GFXRECON_LOG_ERROR("ERROR - incomplete --dump-resources parameters");
            GFXRECON_LOG_ERROR("BeginCommandBuffer indices are not sorted")
            return true;
        }
    }

    if (vulkan_replay_options.Draw_Indices.size())
    {
        for (const auto& indices : vulkan_replay_options.Draw_Indices)
        {
            if (!AreIndicesSorted(indices))
            {
                GFXRECON_LOG_ERROR("ERROR - incomplete --dump-resources parameters");
                GFXRECON_LOG_ERROR("DrawCall indices are not sorted")
                return true;
            }
        }
    }

    if (vulkan_replay_options.RenderPass_Indices.size())
    {
        for (const auto& indices0 : vulkan_replay_options.RenderPass_Indices)
        {
            for (const auto& indices1 : indices0)
            {
                if (!AreIndicesSorted(indices1))
                {
                    GFXRECON_LOG_ERROR("ERROR - incomplete --dump-resources parameters");
                    GFXRECON_LOG_ERROR("Render pass indices are not sorted")
                    return true;
                }
            }
        }
    }

    if (vulkan_replay_options.Dispatch_Indices.size())
    {
        for (const auto& indices : vulkan_replay_options.Dispatch_Indices)
        {
            if (!AreIndicesSorted(indices))
            {
                GFXRECON_LOG_ERROR("ERROR - incomplete --dump-resources parameters");
                GFXRECON_LOG_ERROR("Dispatch indices are not sorted")
                return true;
            }
        }
    }

    if (vulkan_replay_options.TraceRays_Indices.size())
    {
        for (const auto& indices : vulkan_replay_options.TraceRays_Indices)
        {
            if (!AreIndicesSorted(indices))
            {
                GFXRECON_LOG_ERROR("ERROR - incomplete --dump-resources parameters");
                GFXRECON_LOG_ERROR("TraceRays indices are not sorted")
                return true;
            }
        }
    }

    if (vulkan_replay_options.QueueSubmit_Indices.size() > 1)
    {
        if (!AreIndicesSorted(vulkan_replay_options.QueueSubmit_Indices))
        {
            GFXRECON_LOG_ERROR("ERROR - incomplete --dump-resources parameters");
            GFXRECON_LOG_ERROR("QueueSubmit indices are not sorted")
            return true;
        }
    }

    // Do some further logical assertions on the indices
    if ((vulkan_replay_options.BeginCommandBuffer_Indices.size() == 0 &&
         vulkan_replay_options.QueueSubmit_Indices.size() == 0) ||
        ((vulkan_replay_options.BeginCommandBuffer_Indices.size() ||
          vulkan_replay_options.QueueSubmit_Indices.size()) &&
         (vulkan_replay_options.BeginCommandBuffer_Indices.size() != vulkan_replay_options.QueueSubmit_Indices.size())))
    {
        GFXRECON_LOG_ERROR("ERROR - incomplete --dump-resources parameters");
        GFXRECON_LOG_ERROR("Number of BeginCommandBuffer and QueueSubmit indices must be equal and greater than "
                           "zero (%zu and %zu respectively)",
                           vulkan_replay_options.BeginCommandBuffer_Indices.size(),
                           vulkan_replay_options.QueueSubmit_Indices.size())
        return true;
    }

    if (vulkan_replay_options.Draw_Indices.size() && !vulkan_replay_options.RenderPass_Indices.size())
    {
        GFXRECON_LOG_ERROR("ERROR - incomplete --dump-resources parameters");
        GFXRECON_LOG_ERROR("DrawCall indices must always be acompanied by render pass indices");
        return true;
    }

    if (vulkan_replay_options.Draw_Indices.size() == 0 && vulkan_replay_options.Dispatch_Indices.size() == 0 &&
        vulkan_replay_options.TraceRays_Indices.size() == 0)
    {
        GFXRECON_LOG_ERROR("ERROR - incomplete --dump-resources parameters");
        GFXRECON_WRITE_CONSOLE(
            "No DrawCall, Dispatch or TraceRays indices were specified. At least one of these must be provided");
        return true;
    }

    return false;
}

// Function to parse the --dump-resoures argument, specifically vulkan_replay_options.dump_resources.
// If the text of the argument looks like it is for DX12 dump resources, it quietly returns.

bool parse_dump_resources_arg(gfxrecon::decode::VulkanReplayOptions& vulkan_replay_options)
{
    bool parse_error  = false;
    bool d3d12enabled = false;

#if defined(D3D12_SUPPORT)
    d3d12enabled = true;
#endif

    if (vulkan_replay_options.dump_resources.length() == 0 ||
        (d3d12enabled && (vulkan_replay_options.dump_resources.find("drawcall-", 0) == 0)))
    {
        // Clear dump resources indices and return if arg is either null or intended for d3d12
        vulkan_replay_options.BeginCommandBuffer_Indices.clear();
        vulkan_replay_options.Draw_Indices.clear();
        vulkan_replay_options.RenderPass_Indices.clear();
        vulkan_replay_options.Dispatch_Indices.clear();
        vulkan_replay_options.TraceRays_Indices.clear();
        vulkan_replay_options.QueueSubmit_Indices.clear();
        return true;
    }

    if (ends_with(to_lower(vulkan_replay_options.dump_resources), ".json"))
    {
        // dump-resource arg value is a json file. Read and parse the json file.
        try
        {
            std::ifstream dr_json_file(vulkan_replay_options.dump_resources, std::ifstream::binary);
            Json::Value   jargs;
            dr_json_file >> jargs;

            // Transfer jargs to vectors in vulkan_replay_options
            for (int idx0 = 0; idx0 < jargs["BeginCommandBuffer"].size(); idx0++)
            {
                vulkan_replay_options.BeginCommandBuffer_Indices.push_back(
                    jargs["BeginCommandBuffer"][idx0].asUInt64());
            }

            for (int idx0 = 0; idx0 < jargs["Draw"].size(); idx0++)
            {
                vulkan_replay_options.Draw_Indices.push_back(std::vector<uint64_t>());
                for (int idx1 = 0; idx1 < jargs["Draw"][idx0].size(); idx1++)
                {
                    vulkan_replay_options.Draw_Indices[idx0].push_back(jargs["Draw"][idx0][idx1].asUInt64());
                }
            }

            for (int idx0 = 0; idx0 < jargs["RenderPass"].size(); idx0++)
            {
                vulkan_replay_options.RenderPass_Indices.push_back(std::vector<std::vector<uint64_t>>());
                for (int idx1 = 0; idx1 < jargs["RenderPass"][idx0].size(); idx1++)
                {
                    vulkan_replay_options.RenderPass_Indices[idx0].push_back(std::vector<uint64_t>());
                    for (int idx2 = 0; idx2 < jargs["RenderPass"][idx0][idx1].size(); idx2++)
                    {
                        vulkan_replay_options.RenderPass_Indices[idx0][idx1].push_back(
                            jargs["RenderPass"][idx0][idx1][idx2].asUInt64());
                    }
                }
            }

            for (int idx0 = 0; idx0 < jargs["TraceRays"].size(); idx0++)
            {
                vulkan_replay_options.TraceRays_Indices.push_back(std::vector<uint64_t>());
                for (int idx1 = 0; idx1 < jargs["TraceRays"][idx0].size(); idx1++)
                {
                    vulkan_replay_options.TraceRays_Indices[idx0].push_back(jargs["TraceRays"][idx0][idx1].asUInt64());
                }
            }

            for (int idx0 = 0; idx0 < jargs["Dispatch"].size(); idx0++)
            {
                vulkan_replay_options.Dispatch_Indices.push_back(std::vector<uint64_t>());
                for (int idx1 = 0; idx1 < jargs["Dispatch"][idx0].size(); idx1++)
                {
                    vulkan_replay_options.Dispatch_Indices[idx0].push_back(jargs["Dispatch"][idx0][idx1].asUInt64());
                }
            }

            for (int idx0 = 0; idx0 < jargs["QueueSubmit"].size(); idx0++)
            {
                vulkan_replay_options.QueueSubmit_Indices.push_back(jargs["QueueSubmit"][idx0].asUInt64());
            }
        }
        catch (...)
        {
            GFXRECON_LOG_ERROR("Error reading file %s. Bad json format?", vulkan_replay_options.dump_resources.c_str());
            parse_error = true;
        }
    }
    else
    {
        // Check to see if dump-resource arg value is a file. If it is, read the dump args from the file.
        // Allow either spaces or commas to separate fields in the file.
        std::ifstream            infile(vulkan_replay_options.dump_resources);
        std::vector<std::string> drargs;
        if (!infile.fail())
        {
            bool err = false;
            for (std::string line; std::getline(infile, line);)
            {
                // Remove leading and trailing spaces
                line.erase(0, line.find_first_not_of(" "));
                line.erase(line.find_last_not_of(" ") + 1);

                // Remove instances of multiple spaces.
                // This is slow and inefficient, but it's compact code
                // and the loop should be executed only a few times.
                while (line.find("  ") != std::string::npos)
                {
                    line.replace(line.find("  "), 2, " ");
                }

                // Replace spaces with commas
                std::replace(line.begin(), line.end(), ' ', ',');

                // Save the modified line if it is non-blank
                if (line.length())
                {
                    drargs.push_back(line);
                }
            }
        }
        else
        {
            // dump-resource args are all specified on the command line
            drargs.push_back(vulkan_replay_options.dump_resources);
        }

        // Process non-json dump_resources args
        int i;
        for (int i = 0; i < drargs.size() && !parse_error; i++)
        {
            uint64_t              num;
            uint64_t              BeginCommandBuffer = 0;
            uint64_t              Draw               = 0;
            uint64_t              BeginRenderPass    = 0;
            std::vector<uint64_t> NextSubPass;
            uint64_t              EndRenderPass = 0;
            uint64_t              Dispatch      = 0;
            uint64_t              TraceRays     = 0;
            uint64_t              QueueSubmit   = 0;
            size_t                apos          = 0;
            errno                               = 0;

            while (apos < drargs[i].length() && !parse_error)
            {
                size_t epos, cpos; // '=' and ',' positions
                char*  endptr;
                // Find next '=' and next ','
                epos = drargs[i].find_first_of('=', apos);
                cpos = drargs[i].find_first_of(',', apos);
                if (cpos == std::string::npos)
                    cpos = drargs[i].length();

                // Extract number after '='
                num = strtol(drargs[i].c_str() + epos + 1, &endptr, 10);
                parse_error |= ((errno != 0) || (*endptr != ',' && *endptr != 0));

                if (drargs[i].compare(apos, epos - apos, "BeginCommandBuffer") == 0)
                    BeginCommandBuffer = num;
                else if (drargs[i].compare(apos, epos - apos, "Draw") == 0)
                    Draw = num;
                else if (drargs[i].compare(apos, epos - apos, "BeginRenderPass") == 0)
                    BeginRenderPass = num;
                else if (drargs[i].compare(apos, epos - apos, "NextSubPass") == 0)
                    NextSubPass.push_back(num);
                else if (drargs[i].compare(apos, epos - apos, "EndRenderPass") == 0)
                    EndRenderPass = num;
                else if (drargs[i].compare(apos, epos - apos, "Dispatch") == 0)
                    Dispatch = num;
                else if (drargs[i].compare(apos, epos - apos, "TraceRays") == 0)
                    TraceRays = num;
                else if (drargs[i].compare(apos, epos - apos, "QueueSubmit") == 0)
                    QueueSubmit = num;
                else
                    parse_error = true;

                apos = cpos + 1;
            }

            if (!parse_error)
            {
                vulkan_replay_options.BeginCommandBuffer_Indices.push_back(BeginCommandBuffer);

                vulkan_replay_options.Draw_Indices.push_back(std::vector<uint64_t>());
                if (Draw)
                {
                    vulkan_replay_options.Draw_Indices[i].push_back(Draw);
                }

                vulkan_replay_options.RenderPass_Indices.push_back(std::vector<std::vector<uint64_t>>());
                vulkan_replay_options.RenderPass_Indices[i].push_back(std::vector<uint64_t>());
                if (BeginRenderPass || NextSubPass.size() || EndRenderPass)
                {
                    vulkan_replay_options.RenderPass_Indices[i][0].push_back(BeginRenderPass);

                    vulkan_replay_options.RenderPass_Indices[i][0].insert(
                        vulkan_replay_options.RenderPass_Indices[i][0].end(), NextSubPass.begin(), NextSubPass.end());

                    vulkan_replay_options.RenderPass_Indices[i][0].push_back(EndRenderPass);
                }

                vulkan_replay_options.Dispatch_Indices.push_back(std::vector<uint64_t>());
                if (Dispatch)
                {
                    vulkan_replay_options.Dispatch_Indices[i].push_back(Dispatch);
                }

                vulkan_replay_options.TraceRays_Indices.push_back(std::vector<uint64_t>());
                if (TraceRays)
                {
                    vulkan_replay_options.TraceRays_Indices[i].push_back(TraceRays);
                }

                vulkan_replay_options.QueueSubmit_Indices.push_back(QueueSubmit);
            }
        }

        if (parse_error)
        {
            GFXRECON_LOG_ERROR("ERROR - Ignoring invalid --dump-resources parameter: %s",
                               vulkan_replay_options.dump_resources.c_str());
        }
    }

    // Perform some sanity checks on the provided indices
    if (!parse_error)
    {
        parse_error = CheckIndicesForErrors(vulkan_replay_options);
    }

    vulkan_replay_options.dumping_resources = !parse_error;
    if (parse_error)
    {
        vulkan_replay_options.BeginCommandBuffer_Indices.clear();
        vulkan_replay_options.Draw_Indices.clear();
        vulkan_replay_options.RenderPass_Indices.clear();
        vulkan_replay_options.Dispatch_Indices.clear();
        vulkan_replay_options.TraceRays_Indices.clear();
        vulkan_replay_options.QueueSubmit_Indices.clear();
    }

    return !parse_error;
}

GFXRECON_END_NAMESPACE(parse_dump_resources)
GFXRECON_END_NAMESPACE(gfxrecon)
