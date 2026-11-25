#!/usr/bin/python3 -i
#
# Copyright (c) 2026 LunarG, Inc.
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

"""Generates the Vulkan stage command buffer header."""

from vulkan_base_generator import write
from vulkan_consumer_stage_header_generator import VulkanConsumerStageHeaderGenerator


class VulkanStageCommandBufferHeaderGenerator(VulkanConsumerStageHeaderGenerator):
    """Generates the Vulkan stage command buffer header."""

    def write_class_contents(self):
        """Method override."""
        for cmd in self.get_all_filtered_cmd_names():
            if not cmd.startswith('vkCmd'):
                continue

            info = self.all_cmd_params[cmd]
            return_type = info[0]
            values = info[2]

            decl = self.make_consumer_func_decl(
                return_type, 'Process_' + cmd, values
            )

            cmddef = '\n' + self.indent(
                decl + ' override { ProcessCommand(call_info, args); }',
                self.INDENT_SIZE
            )

            write(cmddef, file=self.outFile)
