#!/usr/bin/env python3
#
# Copyright (c) 2021 LunarG, Inc.
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
import threading


# API Call Encoders
from dx12_base_generator\
    import DX12GeneratorOptions, write
from dx12_api_call_encoders_header_generator\
    import DX12ApiCallEncodersHeaderGenerator
from dx12_api_call_encoders_body_generator\
    import DX12ApiCallEncodersBodyGenerator
from dx12_decoder_header_generator import DX12DecoderHeaderGenerator


# Returns a directory of [ generator function, generator options ] indexed
# by specified short names. The generator options incorporate the following
# parameters:
#
# args is an parsed argument object; see below for the fields that are used.
def make_gen_opts(args):
    global gen_opts
    gen_opts = {}

    # Output target directory
    directory = args.directory

    # Copyright text prefixing all headers (list of strings).
    prefix_strings = [
        '/*',
        '** Copyright (c) 2021 LunarG, Inc.',
        '**',
        '** Permission is hereby granted, free of charge, to any person obtaining a copy',  # noqa
        '** of this software and associated documentation files (the "Software"), to',      # noqa
        '** deal in the Software without restriction, including without limitation the',    # noqa
        '** rights to use, copy, modify, merge, publish, distribute, sublicense, and/or',   # noqa
        '** sell copies of the Software, and to permit persons to whom the Software is',    # noqa
        '** furnished to do so, subject to the following conditions:',
        '**',
        '** The above copyright notice and this permission notice shall be included in',    # noqa
        '** all copies or substantial portions of the Software.',
        '**',
        '** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR',    # noqa
        '** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,',      # noqa
        '** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE',   # noqa
        '** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER',        # noqa
        '** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING',       # noqa
        '** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS',  # noqa
        '** IN THE SOFTWARE.',
        '*/',
        ''
    ]

    py_prefix_strings = [
        '/*',
        '** This file is generated from {}.',
        '**',
        '*/',
        ''
    ]

    # API call encoder generators
    py_prefix_strings1 = py_prefix_strings[-4]
    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_api_call_encoders_header_generator.py')
    gen_opts['generated_dx12_api_call_encoders.h'] = [
        DX12ApiCallEncodersHeaderGenerator,
        DX12GeneratorOptions(
            filename='generated_dx12_api_call_encoders.h',
            directory=directory,
            prefixText=prefix_strings + py_prefix_strings,
            protectFile=True,
            protectFeature=False)
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_api_call_encoders_body_generator.py')
    gen_opts['generated_dx12_api_call_encoders.cpp'] = [
        DX12ApiCallEncodersBodyGenerator,
        DX12GeneratorOptions(
            filename='generated_dx12_api_call_encoders.cpp',
            directory=directory,
            prefixText=prefix_strings + py_prefix_strings,
            protectFile=False,
            protectFeature=False)
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_decoder_header_generator.py')
    gen_opts['generated_dx12_decoder.h'] = [
        DX12DecoderHeaderGenerator,
        DX12GeneratorOptions(
            filename='generated_dx12_decoder.h',
            directory=directory,
            prefixText=prefix_strings + py_prefix_strings,
            protectFile=True,
            protectFeature=False)
    ]


# Generate a target based on the options in the matching genOpts{} object.
# This is encapsulated in a function so it can be profiled and/or timed.
# The args parameter is an parsed argument object containing the following
# fields that are used:
#   target - target to generate
#   directory - directory to generate it in
#   protect - True if re-inclusion wrappers should be created
#   extensions - list of additional extensions to include in generated
#   interfaces
def gen_target(args, source_dict):
    # Create generator options with specified parameters
    make_gen_opts(args)

    if args.target in gen_opts:
        create_generator = gen_opts[args.target][0]
        options = gen_opts[args.target][1]

        # Text specific to dx12 headers
        dx12_prefix_strings = ("/*\n"
                               "** This part is generated from {} in Windows SDK: {}\n"  # noqa
                               "**\n"
                               "*/").format('{}', args.windows_sdk_version)

        gen = create_generator(
            source_dict,
            dx12_prefix_strings,
            diagFile=None)

        return (gen, options)
    else:
        write(
            'No generator options for unknown target:',
            args.target,
            file=sys.stderr)
        return None


class GenCode (threading.Thread):
    def __init__(self, target, source_dict,
                 windows_sdk_version, directory, configs):
        threading.Thread.__init__(self)
        self.target = target
        self.source_dict = source_dict
        self.windows_sdk_version = windows_sdk_version
        self.directory = directory
        self.configs = configs

    def run(self):
        (gen, options) = gen_target(self, self.source_dict)

        gen.beginFile(options)
        gen.beginFeature({}, False)
        gen.genType(None, None, None)
        gen.generateFeature()
        gen.endFeature()
        gen.endFile()
