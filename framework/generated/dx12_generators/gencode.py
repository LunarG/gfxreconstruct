#!/usr/bin/env python3
#
# Copyright (c) 2021-2023 LunarG, Inc.
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

# API Call Encoders
from base_generator_defines import write
from dx12_base_generator import Dx12GeneratorOptions
from dx12_api_call_encoders_header_generator import Dx12ApiCallEncodersHeaderGenerator
from dx12_api_call_encoders_body_generator import Dx12ApiCallEncodersBodyGenerator
from dx12_struct_decoders_forward_generator import Dx12StructDecodersForwardGenerator
from dx12_struct_decoders_header_generator import Dx12StructDecodersHeaderGenerator
from dx12_struct_decoders_body_generator import Dx12StructDecodersBodyGenerator
from dx12_decoder_header_generator import Dx12DecoderHeaderGenerator
from dx12_decoder_body_generator import Dx12DecoderBodyGenerator
from dx12_consumer_header_generator import Dx12ConsumerHeaderGenerator, Dx12ConsumerHeaderGeneratorOptions
from dx12_replay_consumer_header_generator import Dx12ReplayConsumerHeaderGenerator, Dx12ReplayConsumerHeaderGeneratorOptions
from dx12_replay_consumer_body_generator import Dx12ReplayConsumerBodyGenerator, Dx12ReplayConsumerBodyGeneratorOptions
from dx12_json_consumer_header_generator import Dx12JsonConsumerHeaderGenerator
from dx12_json_consumer_body_generator import Dx12JsonConsumerBodyGenerator, Dx12JsonBodyGeneratorOptions
from dx12_wrapper_header_generator import Dx12WrapperHeaderGenerator
from dx12_wrapper_body_generator import Dx12WrapperBodyGenerator, Dx12WrapperBodyGeneratorOptions
from dx12_wrapper_creators_header_generator import Dx12WrapperCreatorsHeaderGenerator
from dx12_wrapper_creators_body_generator import Dx12WrapperCreatorsBodyGenerator
from dx12_struct_unwrappers_header_generator import Dx12StructUnwrappersHeaderGenerator
from dx12_struct_unwrappers_body_generator import Dx12StructUnwrappersBodyGenerator
from dx12_struct_object_mappers_header_generator import Dx12StructObjectMappersHeaderGenerator
from dx12_struct_object_mappers_body_generator import Dx12StructObjectMappersBodyGenerator
from dx12_struct_wrapper_header_generator import Dx12StructWrapperHeaderGenerator
from dx12_struct_wrapper_body_generator import Dx12StructWrapperBodyGenerator
from dx12_add_entries_header_generator import Dx12AddEntriesHeaderGenerator
from dx12_state_table_header_generator import Dx12StateTableHeaderGenerator
from dx12_command_list_util_header_generator import Dx12CommandListUtilHeaderGenerator
from dx12_command_list_util_body_generator import Dx12CommandListUtilBodyGenerator
from dx12_enum_to_string_header_generator import Dx12EnumToStringHeaderGenerator
from dx12_enum_to_string_body_generator import Dx12EnumToStringBodyGenerator
from dx12_enum_to_json_header_generator import Dx12EnumToJsonHeaderGenerator
from dx12_call_id_to_string_header_generator import Dx12CallIdToStringHeaderGenerator
from dx12_struct_decoders_to_json_header_generator import Dx12StructDecodersToJsonHeaderGenerator
from dx12_struct_decoders_to_json_body_generator import Dx12StructDecodersToJsonBodyGenerator

# JSON files for customizing code generation
# @todo Review the file of blacklisted functions and determine if each generator
# needs a custom set in its own file.

default_blacklists = 'blacklists.json'
default_platform_types = 'platform_types.json'
default_replay_overrides = 'replay_overrides.json'
default_capture_overrides = 'capture_overrides.json'
default_json_overrides = 'json_overrides.json'


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
    platform_types = os.path.join(args.configs, default_platform_types)
    replay_overrides = os.path.join(args.configs, default_replay_overrides)
    capture_overrides = os.path.join(args.configs, default_capture_overrides)
    json_overrides = os.path.join(args.configs, default_json_overrides)
    # Structs, functions etc. to exclude from codegen for conversion to JSON features.
    json_blocklists = os.path.join(args.configs, "json_blocklists.json")
    # Structs, functions etc. to exclude from codegen of the header files for conversion to JSON.
    # (we can codegen a lot more header content than body as the function signatures are not tricky)
    json_headers_blocklists = os.path.join(
        args.configs, "json_headers_blocklists.json"
    )

    # Copyright text prefixing all headers (list of strings).
    prefix_strings = [
        '/*', '** Copyright (c) 2021-2023 LunarG, Inc.', '**',
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
            platform_types=platform_types,
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
            platform_types=platform_types,
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
            platform_types=platform_types,
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
            platform_types=platform_types,
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
            platform_types=platform_types,
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
            platform_types=platform_types,
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
            platform_types=platform_types,
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
        Dx12ConsumerHeaderGeneratorOptions(
            filename='generated_dx12_consumer.h',
            directory=directory,
            constructor_args='',
            blacklists=blacklists,
            platform_types=platform_types,
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
        Dx12ReplayConsumerHeaderGeneratorOptions(
            filename='generated_dx12_replay_consumer.h',
            directory=directory,
            constructor_args=
            'std::shared_ptr<application::Application> application, const DxReplayOptions& options',
            blacklists=blacklists,
            platform_types=platform_types,
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
        Dx12ReplayConsumerBodyGeneratorOptions(
            filename='generated_dx12_replay_consumer.cpp',
            directory=directory,
            constructor_args='',
            blacklists=blacklists,
            platform_types=platform_types,
            replay_overrides=replay_overrides,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=False,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_json_consumer_header_generator.py'
    )
    gen_opts['generated_dx12_json_consumer.h'] = [
        Dx12JsonConsumerHeaderGenerator,
        Dx12ConsumerHeaderGeneratorOptions(
            filename='generated_dx12_json_consumer.h',
            directory=directory,
            blacklists=json_headers_blocklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=True,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_json_consumer_body_generator.py'
    )
    gen_opts['generated_dx12_json_consumer.cpp'] = [
        Dx12JsonConsumerBodyGenerator,
        Dx12JsonBodyGeneratorOptions(
            filename='generated_dx12_json_consumer.cpp',
            directory=directory,
            constructor_args='',
            blacklists=json_blocklists,
            platform_types=platform_types,
            json_overrides=json_overrides,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=False,
            protect_feature=False
        )
    ]

    # Wrapper generators
    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_wrapper_header_generator.py'
    )
    gen_opts['generated_dx12_wrappers.h'] = [
        Dx12WrapperHeaderGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_wrappers.h',
            directory=directory,
            platform_types=platform_types,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=True,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_wrapper_body_generator.py'
    )
    gen_opts['generated_dx12_wrappers.cpp'] = [
        Dx12WrapperBodyGenerator,
        Dx12WrapperBodyGeneratorOptions(
            filename='generated_dx12_wrappers.cpp',
            directory=directory,
            platform_types=platform_types,
            capture_overrides=capture_overrides,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=False,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_wrapper_creators_header_generator.py'
    )
    gen_opts['generated_dx12_wrapper_creators.h'] = [
        Dx12WrapperCreatorsHeaderGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_wrapper_creators.h',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=True,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_wrapper_creators_body_generator.py'
    )
    gen_opts['generated_dx12_wrapper_creators.cpp'] = [
        Dx12WrapperCreatorsBodyGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_wrapper_creators.cpp',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=False,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_struct_unwrappers_body_generator.py'
    )
    gen_opts['generated_dx12_struct_unwrappers.h'] = [
        Dx12StructUnwrappersHeaderGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_struct_unwrappers.h',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=True,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_struct_unwrappers_body_generator.py'
    )
    gen_opts['generated_dx12_struct_unwrappers.cpp'] = [
        Dx12StructUnwrappersBodyGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_struct_unwrappers.cpp',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=False,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_struct_object_mappers_header_generator.py'
    )
    gen_opts['generated_dx12_struct_object_mappers.h'] = [
        Dx12StructObjectMappersHeaderGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_struct_object_mappers.h',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=False,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_struct_object_mappers_body_generator.py'
    )
    gen_opts['generated_dx12_struct_object_mappers.cpp'] = [
        Dx12StructObjectMappersBodyGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_struct_object_mappers.cpp',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=False,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_struct_wrapper_header_generator.py'
    )
    gen_opts['generated_dx12_struct_wrappers.h'] = [
        Dx12StructWrapperHeaderGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_struct_wrappers.h',
            directory=directory,
            platform_types=platform_types,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=True,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_struct_wrapper_body_generator.py'
    )
    gen_opts['generated_dx12_struct_wrappers.cpp'] = [
        Dx12StructWrapperBodyGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_struct_wrappers.cpp',
            directory=directory,
            platform_types=platform_types,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=False,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_add_entries_header_generator.py'
    )
    gen_opts['generated_dx12_add_entries.h'] = [
        Dx12AddEntriesHeaderGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_add_entries.h',
            directory=directory,
            platform_types=platform_types,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=True,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_state_table_header_generator.py'
    )
    gen_opts['generated_dx12_state_table.h'] = [
        Dx12StateTableHeaderGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_state_table.h',
            directory=directory,
            platform_types=platform_types,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=True,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_command_list_util_header_generator.py'
    )
    gen_opts['generated_dx12_command_list_util.h'] = [
        Dx12CommandListUtilHeaderGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_command_list_util.h',
            directory=directory,
            platform_types=platform_types,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=True,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_command_list_util_body_generator.py'
    )
    gen_opts['generated_dx12_command_list_util.cpp'] = [
        Dx12CommandListUtilBodyGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_command_list_util.cpp',
            directory=directory,
            platform_types=platform_types,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=False,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_enum_to_string_header_generator.py'
    )
    gen_opts['generated_dx12_enum_to_string.h'] = [
        Dx12EnumToStringHeaderGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_enum_to_string.h',
            directory=directory,
            platform_types=platform_types,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=True,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_enum_to_string_body_generator.py'
    )
    gen_opts['generated_dx12_enum_to_string.cpp'] = [
        Dx12EnumToStringBodyGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_enum_to_string.cpp',
            directory=directory,
            platform_types=platform_types,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=False,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_enum_to_json_header_generator.py'
    )
    gen_opts['generated_dx12_enum_to_json.h'] = [
        Dx12EnumToJsonHeaderGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_enum_to_json.h',
            directory=directory,
            blacklists=json_headers_blocklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=True,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_struct_decoders_to_json_header_generator.py'
    )
    gen_opts['generated_dx12_struct_decoders_to_json.h'] = [
        Dx12StructDecodersToJsonHeaderGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_struct_decoders_to_json.h',
            directory=directory,
            blacklists=json_headers_blocklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=True,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_struct_decoders_to_json_body_generator.py'
    )
    gen_opts['generated_dx12_struct_decoders_to_json.cpp'] = [
        Dx12StructDecodersToJsonBodyGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_struct_decoders_to_json.cpp',
            directory=directory,
            blacklists=json_blocklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=False,
            protect_feature=False
        )
    ]

    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_call_id_to_string_header_generator.py'
    )
    gen_opts['generated_dx12_call_id_to_string.h'] = [
        Dx12CallIdToStringHeaderGenerator,
        Dx12GeneratorOptions(
            filename='generated_dx12_call_id_to_string.h',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + py_prefix_strings,
            protect_file=True,
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


class GenCode():

    def __init__(
        self, target, source_dict, windows_sdk_version, directory, configs
    ):
        self.target = target
        self.source_dict = source_dict
        self.windows_sdk_version = windows_sdk_version
        self.directory = directory
        self.configs = configs

        (gen, options) = gen_target(self, self.source_dict)

        gen.beginFile(options)
        gen.beginFeature({}, False)
        gen.genType(None, None, None)
        gen.generate_feature()
        gen.endFeature()
        gen.endFile()
