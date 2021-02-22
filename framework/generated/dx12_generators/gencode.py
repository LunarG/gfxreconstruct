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

import os
import sys
import threading

# API Call Encoders
from base_generator import write
from dx12_base_generator import Dx12GeneratorOptions
from dx12_api_call_encoders_header_generator import Dx12ApiCallEncodersHeaderGenerator
from dx12_api_call_encoders_body_generator import Dx12ApiCallEncodersBodyGenerator
from dx12_struct_decoders_forward_generator import Dx12StructDecodersForwardGenerator
from dx12_struct_decoders_header_generator import Dx12StructDecodersHeaderGenerator
from dx12_struct_decoders_body_generator import Dx12StructDecodersBodyGenerator
from dx12_decoder_header_generator import Dx12DecoderHeaderGenerator
from dx12_decoder_body_generator import Dx12DecoderBodyGenerator
from dx12_consumer_header_generator import Dx12ConsumerHeaderGenerator
from dx12_replay_consumer_header_generator import Dx12ReplayConsumerHeaderGenerator
from dx12_replay_consumer_body_generator import Dx12ReplayConsumerBodyGenerator
from dx12_ascii_consumer_header_generator import Dx12AsciiConsumerHeaderGenerator
from dx12_ascii_consumer_body_generator import Dx12AsciiConsumerBodyGenerator

# JSON files for customizing code generation
default_blacklists = 'blacklists.json'


def make_gen_opts(args):
    """Returns a directory of [ generator function, generator options ] indexed
    by specified short names. The generator options incorporate the following
    parameters:

    args is an parsed argument object; see below for the fields that are used.
    """
    global gen_opts
    gen_opts = {}

    # Output target directory
    directory = args.directory

    # JSON configuration files
    blacklists = os.path.join(args.configs, default_blacklists)

    # Copyright text prefixing all headers (list of strings).
    prefix_strings = [
        '/*', '** Copyright (c) 2021 LunarG, Inc.', '**',
        '** Permission is hereby granted, free of charge, to any person obtaining a copy',
        '** of this software and associated documentation files (the "Software"), to',
        '** deal in the Software without restriction, including without limitation the',
        '** rights to use, copy, modify, merge, publish, distribute, sublicense, and/or',
        '** sell copies of the Software, and to permit persons to whom the Software is',
        '** furnished to do so, subject to the following conditions:', '**',
        '** The above copyright notice and this permission notice shall be included in',
        '** all copies or substantial portions of the Software.', '**',
        '** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR',
        '** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,',
        '** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE',
        '** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER',
        '** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING',
        '** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS',
        '** IN THE SOFTWARE.', '*/', ''
    ]

    py_prefix_strings = [
        '/*', '** This file is generated from {}.', '**', '*/', ''
    ]

    # API call encoder generators
    py_prefix_strings1 = py_prefix_strings[-4]
    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_api_call_encoders_header_generator.py'
    )
    gen_opts['generated_dx12_api_call_encoders.h'] = [
        Dx12ApiCallEncodersHeaderGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_api_call_encoders.h',
            directory=directory,
            blacklists=blacklists,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=True,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_api_call_encoders_body_generator.py'
    )
    gen_opts['generated_dx12_api_call_encoders.cpp'] = [
        Dx12ApiCallEncodersBodyGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_api_call_encoders.cpp',
            directory=directory,
            blacklists=blacklists,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=False,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_struct_decoders_forward_generator.py'
    )
    gen_opts['generated_dx12_struct_decoders_forward.h'] = [
        Dx12StructDecodersForwardGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_struct_decoders_forward.h',
            directory=directory,
            blacklists=blacklists,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=True,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_struct_decoders_header_generator.py'
    )
    gen_opts['generated_dx12_struct_decoders.h'] = [
        Dx12StructDecodersHeaderGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_struct_decoders.h',
            directory=directory,
            blacklists=blacklists,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=True,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_struct_decoders_body_generator.py'
    )
    gen_opts['generated_dx12_struct_decoders.cpp'] = [
        Dx12StructDecodersBodyGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_struct_decoders.cpp',
            directory=directory,
            blacklists=blacklists,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=False,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_decoder_header_generator.py'
    )
    gen_opts['generated_dx12_decoder.h'] = [
        Dx12DecoderHeaderGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_decoder.h',
            directory=directory,
            blacklists=blacklists,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=True,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_decoder_body_generator.py'
    )
    gen_opts['generated_dx12_decoder.cpp'] = [
        Dx12DecoderBodyGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_decoder.cpp',
            directory=directory,
            blacklists=blacklists,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=False,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_consumer_header_generator.py'
    )
    gen_opts['generated_dx12_consumer.h'] = [
        Dx12ConsumerHeaderGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_consumer.h',
            directory=directory,
            blacklists=blacklists,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=True,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_replay_consumer_header_generator.py'
    )
    gen_opts['generated_dx12_replay_consumer.h'] = [
        Dx12ReplayConsumerHeaderGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_replay_consumer.h',
            directory=directory,
            blacklists=blacklists,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=True,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_replay_consumer_body_generator.py'
    )
    gen_opts['generated_dx12_replay_consumer.cpp'] = [
        Dx12ReplayConsumerBodyGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_replay_consumer.cpp',
            directory=directory,
            blacklists=blacklists,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=False,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_ascii_consumer_header_generator.py'
    )
    gen_opts['generated_dx12_ascii_consumer.h'] = [
        Dx12AsciiConsumerHeaderGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_ascii_consumer.h',
            directory=directory,
            blacklists=blacklists,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=True,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_ascii_consumer_body_generator.py'
    )
    gen_opts['generated_dx12_ascii_consumer.cpp'] = [
        Dx12AsciiConsumerBodyGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_ascii_consumer.cpp',
            directory=directory,
            blacklists=blacklists,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=False,
            protect_feature=False
        )
    ]


def gen_target(args, source_dict):
    """Generate a target based on the options in the matching gen_opts{} object.
    This is encapsulated in a function so it can be profiled and/or timed.
    The args parameter is an parsed argument object containing the following
    fields that are used:
      target - target to generate
      directory - directory to generate it in
      protect - True if re-inclusion wrappers should be created
      extensions - list of additional extensions to include in generated
      interfaces
    """
    # Create generator options with specified parameters
    make_gen_opts(args)

    if args.target in gen_opts:
        create_generator = gen_opts[args.target][0]
        options = gen_opts[args.target][1]

        # Text specific to dx12 headers
        dx12_prefix_strings = (
            "/*\n"
            "** This part is generated from {} in Windows SDK: {}\n"
            "**\n"
            "*/"
        ).format('{}', args.windows_sdk_version)

        gen = create_generator(
            source_dict, dx12_prefix_strings, diag_file=None
        )

        return (gen, options)
    else:
        write(
            'No generator options for unknown target:',
            args.target,
            file=sys.stderr
        )
        return None


class GenCode(threading.Thread):

    def __init__(
        self, target, source_dict, windows_sdk_version, directory, configs
    ):
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
        gen.gen_type(None, None, None)
        gen.generate_feature()
        gen.endFeature()
        gen.endFile()
