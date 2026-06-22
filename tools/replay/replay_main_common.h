/*
** Copyright (c) 2026 LunarG, Inc.
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

#ifndef GFXRECON_REPLAY_MAIN_COMMON_H
#define GFXRECON_REPLAY_MAIN_COMMON_H

#if defined(__ANDROID__)
struct android_app;
#endif

#include "replay_feature.h"

#include "application/application.h"
#include "decode/file_processor.h"
#include "util/argument_parser.h"

#include <functional>
#include <memory>
#include <string>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(replay)

// Populate features from the module registry.
void LoadFeatures(std::vector<std::unique_ptr<ReplayFeatureBase>>& features);

// Run a pre-processing pass over filename using all features that opt in.
void RunPreProcessConsumer(const std::string& filename, std::vector<std::unique_ptr<ReplayFeatureBase>>& features);

// Run the full replay loop.
//
// Creates and initialises the file processor, drives all feature loops,
// and calls application->Run().  Returns true on success, false when the
// file fails to initialise or the replay ends in an error state.  Any
// exception thrown during replay propagates to the caller.
//
// file_processor_out  Receives the constructed FileProcessor; Android keeps a
//                     global reference so the extern "C" query callbacks work.
// active_layers_value String forwarded verbatim to CheckActiveLayers().
// make_application    Platform factory called with the new FileProcessor
//                     pointer; should return a fully constructed Application.
bool RunReplay(std::unique_ptr<decode::FileProcessor>&                                          file_processor_out,
               std::vector<std::unique_ptr<ReplayFeatureBase>>&                                 features,
               util::ArgumentParser&                                                            arg_parser,
               const std::string&                                                               filename,
               const std::string&                                                               active_layers_value,
               std::function<std::shared_ptr<application::Application>(decode::FileProcessor*)> make_application);

GFXRECON_END_NAMESPACE(replay)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_REPLAY_MAIN_COMMON_H
