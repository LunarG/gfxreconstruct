#!/usr/bin/python3 -i
#
# Copyright (c) 2018 Valve Corporation
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

import sys
from vulkan_base_generator import VulkanBaseGenerator, VulkanBaseGeneratorOptions, write
from khronos_replay_frame_loop_consumer_base_header_generator import KhronosFrameLoopConsumerBaseHeaderGenerator

class VulkanFrameLoopConsumerBaseHeaderGeneratorOptions(VulkanBaseGeneratorOptions):
    """
    Class for generating C++ member declarations for the VulkanFrameLoopConsumerBase class
    """

    def __init__(
        self,
        class_name,
        base_class_header,
        constructor_args='',
        blacklists=None,      # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        extra_headers=[],
        replay_frame_loop_overrides=None
    ):
        VulkanBaseGeneratorOptions.__init__(
            self,
            blacklists,
            platform_types,
            filename,
            directory,
            prefix_text,
            protect_file,
            protect_feature,
            extra_headers=extra_headers,
            replay_frame_loop_overrides=replay_frame_loop_overrides
        )
        self.class_name = class_name
        self.base_class_header = base_class_header
        self.constructor_args = constructor_args
        self.replay_frame_loop_overrides = replay_frame_loop_overrides

        self.begin_end_file_data.specific_headers.extend((
            'decode/{}'.format(self.base_class_header),
            'util/defines.h',
        ))

        self.begin_end_file_data.namespaces.extend(('gfxrecon', 'decode'))


class VulkanFrameLoopConsumerBaseHeaderGenerator(VulkanBaseGenerator, KhronosFrameLoopConsumerBaseHeaderGenerator):
    """ - subclass of VulkanBaseGenerator.
    Generates C++ member declarations for the VulkanFrameLoopConsumerBase class
    Generate C++ class declarations for Vulkan parameter processing.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        VulkanBaseGenerator.__init__(
            self,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )


    def endFile(self):
        """Method override."""
        KhronosFrameLoopConsumerBaseHeaderGenerator.output_header_contents(
            self, self.genOpts.class_name, self.genOpts.constructor_args)

        self.newline()

        # Finish processing in superclass
        VulkanBaseGenerator.endFile(self)
