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

#if defined(BUILD_ANDROID_APP)
struct android_app;
#endif

#include "replay_feature.h"
#include "tool_feature_version.h"

#include "application/application.h"
#include "decode/file_processor.h"
#include "util/argument_parser.h"

#include <functional>
#include <memory>
#include <string>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

GFXRECON_BEGIN_NAMESPACE(util)
class RemoteChannel;
GFXRECON_END_NAMESPACE(util)

GFXRECON_BEGIN_NAMESPACE(replay)

// Outcome of attempting to establish a remote-controller connection.
enum class RemoteSetupResult
{
    kNotRequested, // --remote-connect was not specified; the channel is unused.
    kConnected,    // Connected and handshake succeeded; arg_parser now holds the controller's settings.
    kFailed        // --remote-connect was given but the connection or handshake failed (a fatal message was logged).
};

// If arg_parser has --remote-connect set, connect channel to the controller, perform the handshake, replace arg_parser
// with the controller-provided settings, and begin relaying log output to the controller. On failure the specific
// reason is logged (by RemoteChannel) and kFailed is returned; the caller decides how to abort. Does nothing and
// returns kNotRequested when --remote-connect is absent.
// options and arguments are the tool's name lists with every loaded Feature's entries already
// appended, the same lists the command-line parser was built from. Remote settings are parsed
// against them so a Feature option means the same thing from a controller as from the command line.
RemoteSetupResult SetupRemoteChannel(util::RemoteChannel&  channel,
                                     util::ArgumentParser& arg_parser,
                                     const std::string&    options,
                                     const std::string&    arguments);

// Stop relaying log output, then notify the controller that replay finished. Both steps are no-ops when channel is not
// connected, so this is safe to call unconditionally.
void ShutdownRemoteChannel(util::RemoteChannel& channel, bool success);

// Populate features from the module registry.
void LoadFeatures(std::vector<std::unique_ptr<ReplayFeatureBase>>& features);

// Gives the list that the last LoadFeatures() call filled. The usage function of the tool
// cannot receive the list as a parameter, because tool_command_line.h declares that function
// with a fixed signature. The usage function reads the list here to build the part of the
// synopsis that the Features contribute. The list is empty before the first LoadFeatures() call.
const std::vector<std::unique_ptr<ReplayFeatureBase>>& GetLoadedFeatures();

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
// make_application    Platform factory called with the new FileProcessor
//                     pointer; should return a fully constructed Application.
bool RunReplay(std::unique_ptr<decode::FileProcessor>&                                          file_processor_out,
               std::vector<std::unique_ptr<ReplayFeatureBase>>&                                 features,
               util::ArgumentParser&                                                            arg_parser,
               const std::string&                                                               filename,
               std::function<std::shared_ptr<application::Application>(decode::FileProcessor*)> make_application);

GFXRECON_END_NAMESPACE(replay)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_REPLAY_MAIN_COMMON_H
