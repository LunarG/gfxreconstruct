//=============================================================================
/// Copyright (c) 2019 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file   replay_settings.cpp
/// \brief  source file contains all replay setting arguments
//=============================================================================

#include "replay_settings.h"

const char Arguments::kApplicationName[] = "GFXReconstruct Replay";
const char Arguments::kCaptureLayer[]    = "VK_LAYER_LUNARG_gfxreconstruct";

const char Arguments::kVersionOption[]                    = "--version";
const char Arguments::kOverrideGpuArgument[]              = "--gpu";
const char Arguments::kPausedOption[]                     = "--paused";
const char Arguments::kPauseFrameArgument[]               = "--pause-frame";
const char Arguments::kSkipFailedAllocationShortOption[]  = "--sfa";
const char Arguments::kSkipFailedAllocationLongOption[]   = "--skip-failed-allocations";
const char Arguments::kOmitPipelineCacheDataShortOption[] = "--opcd";
const char Arguments::kOmitPipelineCacheDataLongOption[]  = "--omit-pipeline-cache-data";

const char Arguments::kIPAddArgument[]     = "--ip-address";
const char Arguments::kPortArgument[]      = "--port";
const char Arguments::kWinWidthArgument[]  = "--win-width";
const char Arguments::kWinHeightArgument[] = "--win-height";

// TODO: Make this a vector of strings.
const char Arguments::kOptions[]   = "--version,--paused,--sfa|--skip-failed-allocations,--opcd|--omit-pipeline-cache-data";
const char Arguments::kArguments[] = "--pause-frame,--ip-address,--port,--win-width,--win-height";