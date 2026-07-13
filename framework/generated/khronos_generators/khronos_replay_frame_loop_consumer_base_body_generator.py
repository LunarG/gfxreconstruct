#!/usr/bin/python3 -i
#
# Copyright (c) 2018-2020 Valve Corporation
# Copyright (c) 2018-2024 LunarG, Inc.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to
# deal in the Software without restriction, including without limitation the
# rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
# sell copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
# IN THE SOFTWARE.

from khronos_base_generator import write

class KhronosReplayFrameLoopConsumerBaseBodyGenerator():
    """Base class for generating replay frame loop consumers body code."""

    def skip_generating_command(self, command):
        return (command not in
                (self.REPLAY_FRAME_LOOP_RESOURCE_ALLOCATE_SINGLE_HANDLE_OVERRIDES +
                 self.REPLAY_FRAME_LOOP_RESOURCE_ALLOCATE_MULTIPLE_HANDLES_OVERRIDES +
                 self.REPLAY_FRAME_LOOP_RESOURCE_FREE_SINGLE_HANDLE_OVERRIDES +
                 self.REPLAY_FRAME_LOOP_RESOURCE_ALLOCATE_NOT_FULLY_IMPLEMENTED +
                 self.REPLAY_FRAME_LOOP_RESOURCE_FREE_NOT_FULLY_IMPLEMENTED))

    def genCallReplayConsumer(self, return_type, name, values):
        return f'{self.platform_type}ReplayConsumer::Process_{name}(call_info, args);\n'

    def make_replay_frame_loop_consumer_func_body(self, api_data, return_type, name, values):

        body = ''

        if name in self.REPLAY_FRAME_LOOP_RESOURCE_ALLOCATE_SINGLE_HANDLE_OVERRIDES:

            body += '    // Check for null cases\n'
            body += '    if (' + values[-1].prefixed_name + '.IsNull())\n'
            body += '    {\n'
            body += '        return;\n'
            body += '    }\n'
            body += '    format::HandleId handle = *' + values[-1].prefixed_name + '.GetPointer();\n\n'
            body += '    // Pass the call along if we are not looping or\n'
            body += '    // if we are looping and the handle is not in allocatedLoopResources\n'
            body += '    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))\n'
            body += '    {\n'
            body += '        ' + self.genCallReplayConsumer(return_type, name, values)
            body += '        // If we are looping, save the handle in allocatedLoopResources\n'
            body += '        if (getFrameLoopInfo().IsLooping())\n'
            body += '        {\n'
            body += '            allocatedLoopResources.insert(handle);\n'
            body += '        }\n'
            body += '    }\n'

        elif name in self.REPLAY_FRAME_LOOP_RESOURCE_ALLOCATE_MULTIPLE_HANDLES_OVERRIDES:

            body += '    // Pass the call along if we are not looping or if all the handles are not in allocatedLoopResources.\n'
            body += '    bool doReplay = false;\n'
            body += '    if (!getFrameLoopInfo().IsLooping())\n'
            body += '    {\n'
            body += '        doReplay = true;\n'
            body += '    }\n'
            body += '    else\n'
            body += '    {\n'
            body += '        for (uint32_t i=0; i < '+values[-4].prefixed_name+'; i++)\n'
            body += '        {\n'
            body += '            format::HandleId handle = '+values[-1].prefixed_name+'.GetPointer()[i];\n'
            body += '            if (!allocatedLoopResources.contains(handle))\n'
            body += '            {\n'
            body += '                doReplay = true;\n'
            body += '                break;\n'
            body += '            }\n'
            body += '        }\n'
            body += '    }\n'
            body += '    if (doReplay)\n'
            body += '    {\n'
            body += '        ' + self.genCallReplayConsumer(return_type, name, values)
            body += '        // If we are looping, save the handles in allocatedLoopResources\n'
            body += '        if (getFrameLoopInfo().IsLooping())\n'
            body += '        {\n'
            body += '            for (uint32_t i=0; i < '+values[-4].prefixed_name+'; i++)\n'
            body += '            {\n'
            body += '                format::HandleId handle = '+values[-1].prefixed_name+'.GetPointer()[i];\n'
            body += '                allocatedLoopResources.insert(handle);\n'
            body += '            }\n'
            body += '        }\n'
            body += '    }\n'

        elif name in self.REPLAY_FRAME_LOOP_RESOURCE_FREE_SINGLE_HANDLE_OVERRIDES:

            body += '    // Skip for loop iterations 1-(n-1).\n'
            body += '    // Skip if looping and if not final iteration\n'
            body += '    // Execute if ' + values[-2].prefixed_name + ' is in allocatedLoopResources\n\n'
            body += '    // Call Process_' + name + ' if:\n'
            body += '    //    We are not looping\n'
            body += '    //    We are looping and ' + values[-2].prefixed_name + ' is in allocatedLoopResources\n'
            body += '    //    We are looping and this is the last iteration\n'

            body += '    if (!getFrameLoopInfo().IsLooping())\n'
            body += '    {\n'
            body += '        GFXRECON_ASSERT(!allocatedLoopResources.contains(' + values[-2].prefixed_name + '))\n'
            body += '        ' + self.genCallReplayConsumer(return_type, name, values)
            body += '    }\n'
            body += '    else if (allocatedLoopResources.contains(' + values[-2].prefixed_name + '))\n'
            body += '    {\n'
            body += '        // Looping special case:\n'
            body += '        // This resource has been allocated WITHIN the loop range.\n'
            body += '        ' + self.genCallReplayConsumer(return_type, name, values)
            body += '        allocatedLoopResources.erase(' + values[-2].prefixed_name + ');\n'
            body += '    }\n'
            body += '    else if (getFrameLoopInfo().IsFinalIteration())\n'
            body += '    {\n'
            body += '        // Looping special case:\n'
            body += '        // This resource has been allocated BEFORE the loop range.\n'
            body += '        // Since it might still be in use during the loop range, ONLY free it in the last iteration.\n'
            body += '        ' + self.genCallReplayConsumer(return_type, name, values)
            body += '    }\n'

        elif name in self.REPLAY_FRAME_LOOP_RESOURCE_ALLOCATE_NOT_FULLY_IMPLEMENTED:

            body += '    // Return if not the first time through loop\n'
            body += '    if (getFrameLoopInfo().IsRepetition())\n'
            body += '    {\n'
            body += '        return;\n'
            body += '    }\n'
            body += '    ' + self.genCallReplayConsumer(return_type, name, values)

        elif name in self.REPLAY_FRAME_LOOP_RESOURCE_FREE_NOT_FULLY_IMPLEMENTED:

            body += '    if (getFrameLoopInfo().IsLooping() && !getFrameLoopInfo().IsFinalIteration())\n'
            body += '    {\n'
            body += '        return;\n'
            body += '    }\n'
            body += '    ' + self.genCallReplayConsumer(return_type, name, values)

        else:
            assert False, "Bad function name in make_replay_frame_loop_consumer_func_body"

        return body


    def generate_replay_frame_loop_consumer_content(self, api_data):
        """Performs C++ code generation for the replay frame loop consumer."""
        self.platform_type = api_data.api_class_prefix

        self.newline()

        for cmd in self.get_all_filtered_cmd_names():

            if self.skip_generating_command(cmd):
                continue

            info = self.all_cmd_params[cmd]
            return_type = info[0]
            values = info[2]

            cmddef = '\n'
            cmddef += self.make_consumer_func_decl(
                        return_type,
                        '{}ReplayFrameLoopConsumerBase::Process_'.format(self.platform_type) + cmd,
                        values
                        ) + '\n'
            cmddef += '{\n'
            cmddef += self.make_replay_frame_loop_consumer_func_body(api_data, return_type, cmd, values)
            cmddef += '}'

            write(cmddef, file=self.outFile)
