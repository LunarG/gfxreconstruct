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

    def make_replay_frame_loop_consumer_func_body(self, api_data, return_type, name, values):

        body = ''

        if name in self.REPLAY_FRAME_LOOP_RESOURCE_ALLOCATE_OVERRIDES:
           body += '    // Return if not the first time through loop\n'
           body += '    if (getFrameLoopInfo().IsRepetition())\n'
        else:
           # name in self.REPLAY_FRAME_LOOP_RESOURCE_FREE_OVERRIDES:
           body += '    // Return for all loop iterations\n'
           body += '    if (getFrameLoopInfo().IsLooping())\n'

        body += '    {\n'
        body += '        return;\n'
        body += '    }\n'
        # Output a function call to replay consumer
        body += '    VulkanReplayConsumer::Process_'+name+'('
        args=['call_info']
        if return_type != 'void':
            args.append('returnValue')
        [ args.append(value.name) for value in values ]
        body += ", ".join(args) + ');\n'
        return body

    def generate_replay_frame_loop_consumer_content(self, api_data):
        """Performs C++ code generation for the replay frame loop consumer."""
        platform_type = api_data.api_class_prefix

        self.newline()

        for cmd in self.get_all_filtered_cmd_names():

            if ((cmd not in self.REPLAY_FRAME_LOOP_RESOURCE_ALLOCATE_OVERRIDES) and
                (cmd not in self.REPLAY_FRAME_LOOP_RESOURCE_FREE_OVERRIDES)
            ):
                continue

            info = self.all_cmd_params[cmd]
            return_type = info[0]
            values = info[2]

            cmddef = '\n'
            if self.is_resource_dump_class():
                cmddef += self.make_dump_resources_func_decl(
                    return_type,
                    '{}ReplayDumpResources::Process_'.format(platform_type)
                    + cmd, values, cmd in self.DUMP_RESOURCES_OVERRIDES, cmd in self.DUMP_RESOURCES_TRANSFER_API_CALLS
                ) + '\n'
            else:
                cmddef += self.make_consumer_func_decl(
                    return_type,
                    '{}ReplayFrameLoopConsumerBase::Process_'.format(platform_type) + cmd,
                    values
                ) + '\n'
            cmddef += '{\n'
            cmddef += self.make_replay_frame_loop_consumer_func_body(api_data, return_type, cmd, values)
            cmddef += '}'

            write(cmddef, file=self.outFile)
