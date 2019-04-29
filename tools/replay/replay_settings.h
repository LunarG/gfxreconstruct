/*
** Copyright (c) 2019 LunarG, Inc.
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

#include "util/logging.h"

#include <string>

#ifndef GFXRECON_REPLAY_SETTINGS_H
#define GFXRECON_REPLAY_SETTINGS_H

const char kApplicationName[] = "GFXReconstruct Replay";
const char kCaptureLayer[]    = "VK_LAYER_LUNARG_gfxreconstruct";

const char kSkipFailedAllocationShortOption[] = "--sfa";
const char kSkipFailedAllocationLongOption[]  = "--skip-failed-allocations";

// TODO: Make this a vector of strings.
const char kOptions[] = "--sfa|--skip-failed-allocations";

static void CheckActiveLayers(const char* env_var)
{
    std::string result = gfxrecon::util::platform::GetEnv(env_var);

    if (!result.empty())
    {
        if (result.find(kCaptureLayer) != std::string::npos)
        {
            GFXRECON_LOG_WARNING("Replay tool has detected that the capture layer is enabled");
        }
    }
}

static void PrintUsage(const char* exe_name)
{
    std::string app_name     = exe_name;
    size_t      dir_location = app_name.find_last_of("/\\");

    if (dir_location >= 0)
    {
        app_name.replace(0, dir_location + 1, "");
    }

    GFXRECON_WRITE_CONSOLE("\n%s - A tool to replay GFXReconstruct capture files.\n", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("Usage:");
    GFXRECON_WRITE_CONSOLE("\t%s [--sfa | --skip-failed-allocations] <file>\n", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("Required arguments:");
    GFXRECON_WRITE_CONSOLE("\t<file>\t\tPath to the capture file to replay");
    GFXRECON_WRITE_CONSOLE("\nOptional arguments:");
    GFXRECON_WRITE_CONSOLE("\t--sfa\t\tSkip vkAllocateMemory, vkAllocateCommandBuffers,");
    GFXRECON_WRITE_CONSOLE("\t     \t\tand vkAllocateDescriptorSets calls that failed");
    GFXRECON_WRITE_CONSOLE("\t     \t\tduring capture (same as --skip-failed-allocations)");
}

#endif // GFXRECON_REPLAY_SETTINGS_H
