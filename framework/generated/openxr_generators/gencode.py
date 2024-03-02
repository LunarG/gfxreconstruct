#!/usr/bin/env python
#
# Copyright (c) 2018-2023 Valve Corporation
# Copyright (c) 2018-2024 LunarG, Inc.
# Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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
#
# The content of this file was derived from the Khronos Registry gencode.py
# and related Python files found in the KhronosGroup/OpenXr-Headers GitHub repository.
#
# Copyright (c) 2013-2016 The Khronos Group Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import argparse
import os
import pdb
import sys
import time
from reg import Registry, etree
from generator import write

# Utility items
from openxr_dispatch_table_generator import OpenXrDispatchTableGenerator, OpenXrDispatchTableGeneratorOptions
from openxr_layer_func_table_generator import OpenXrLayerFuncTableGenerator, OpenXrLayerFuncTableGeneratorOptions

# API Call Encoders
from openxr_api_call_encoders_body_generator import OpenXrApiCallEncodersBodyGenerator, OpenXrApiCallEncodersBodyGeneratorOptions
from openxr_api_call_encoders_header_generator import OpenXrApiCallEncodersHeaderGenerator, OpenXrApiCallEncodersHeaderGeneratorOptions

# Struct Encoders
from openxr_struct_encoders_body_generator import OpenXrStructEncodersBodyGenerator, OpenXrStructEncodersBodyGeneratorOptions
from openxr_struct_encoders_header_generator import OpenXrStructEncodersHeaderGenerator, OpenXrStructEncodersHeaderGeneratorOptions
from openxr_struct_pnext_encoders_generator import OpenXrStructPNextEncodersGenerator, OpenXrStructPNextEncodersGeneratorOptions
from openxr_struct_handle_wrappers_header_generator import OpenXrStructHandleWrappersHeaderGenerator, OpenXrStructHandleWrappersHeaderGeneratorOptions
from openxr_struct_handle_wrappers_body_generator import OpenXrStructHandleWrappersBodyGenerator, OpenXrStructHandleWrappersBodyGeneratorOptions
from openxr_struct_trackers_header_generator import OpenXrStructTrackersHeaderGenerator, OpenXrStructTrackersHeaderGeneratorOptions
from openxr_struct_trackers_body_generator import OpenXrStructTrackersBodyGenerator, OpenXrStructTrackersBodyGeneratorOptions

# To String
from openxr_enum_to_string_body_generator import OpenXrEnumToStringBodyGenerator, OpenXrEnumToStringBodyGeneratorOptions
from openxr_enum_to_string_header_generator import OpenXrEnumToStringHeaderGenerator, OpenXrEnumToStringHeaderGeneratorOptions
from openxr_state_table_header_generator import OpenXrStateTableHeaderGenerator, OpenXrStateTableHeaderGeneratorOptions

#from openxr_object_info_table_base2_header_generator import OpenXrObjectInfoTableBase2HeaderGenerator, OpenXrObjectInfoTableBase2HeaderGeneratorOptions

# Constants
#from openxr_constant_maps_generator import OpenXrConstantMapsGenerator, OpenXrConstantMapsGeneratorOptions

# Simple timer functions
start_time = None


def start_timer(timeit):
    global start_time
    if timeit:
        start_time = time.process_time()


def end_timer(timeit, msg):
    global start_time
    if timeit:
        end_time = time.process_time()
        write(msg, end_time - start_time, file=sys.stderr)
        start_time = None


# JSON files for customizing code generation
default_blacklists = 'blacklists.json'
default_platform_types = 'platform_types.json'
default_replay_overrides = 'replay_overrides.json'
default_capture_overrides = 'capture_overrides.json'


def _getExtraOpenXrHeaders(extraHeadersDir):
    '''
    Recursively get a list of extra OpenXR headers used in the generated code,
    that are included after openxr.h is included
    '''
    extraOpenXRHeaders = []
    for child in os.listdir(extraHeadersDir):
        childPath = os.path.join(extraHeadersDir, child)
        if os.path.isdir(childPath):
            extraOpenXRHeaders.extend(_getExtraOpenXrHeaders(childPath))
        else:
            extraOpenXRHeaders.append(childPath)
    return extraOpenXRHeaders


def getExtraOpenXrHeaders(extraHeadersDir):
    '''
    Get a list of extra OpenXR headers used in the generated code, that are
    included after openxr.h is included
    '''
    return [
        os.path.relpath(header, extraHeadersDir)
        for header in _getExtraOpenXrHeaders(extraHeadersDir)
    ]


def extend_xml(dest_tree, src_xml, debug=False):
    '''Extend the parsed xr.xml registry tree with content from another xml file'''

    def merge(dest, src):
        '''Perform a recursive merge of src into dest'''
        leaf_tags = (
            'command', 'enums', 'extension', 'feature', 'format', 'platform',
            'spirvcapability', 'spirvextension', 'tag', 'type'
        )
        for src_child in src:
            dest_child = dest.find(src_child.tag)
            if (src_child.tag in leaf_tags) or (dest_child is not None):
                # stop descent and copy if the heirarchy diverges or we reach a leaf tag
                dest.append(src_child)
            else:
                merge(dest_child, src_child)

    merge(dest_tree.getroot(), etree.parse(src_xml).getroot())
    if debug:
        dest_tree.write(os.path.splitext(src_xml)[0] + '_merged.xml')


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

    # Copyright text prefixing all headers (list of strings).
    prefix_strings = [
        '/*', '** Copyright (c) 2018-2023 Valve Corporation',
        '** Copyright (c) 2018-2024 LunarG, Inc.',
        '** Copyright (c) 2023 Advanced Micro Devices, Inc.', '**',
        '** Permission is hereby granted, free of charge, to any person obtaining a',
        '** copy of this software and associated documentation files (the "Software"),',
        '** to deal in the Software without restriction, including without limitation',
        '** the rights to use, copy, modify, merge, publish, distribute, sublicense,',
        '** and/or sell copies of the Software, and to permit persons to whom the',
        '** Software is furnished to do so, subject to the following conditions:',
        '**',
        '** The above copyright notice and this permission notice shall be included in',
        '** all copies or substantial portions of the Software.', '**',
        '** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR',
        '** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,',
        '** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE',
        '** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER',
        '** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING',
        '** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER',
        '** DEALINGS IN THE SOFTWARE.', '*/', ''
    ]

    # Text specific to OpenXr headers
    xr_prefix_strings = [
        '/*',
        '** This file is generated from the Khronos OpenXR XML API Registry.',
        '**', '*/', ''
    ]

    extraOpenXrHeaders = []
    if args.headers_dir is not None:
        extraOpenXrHeaders = getExtraOpenXrHeaders(args.headers_dir)

    #
    # Utility items
    gen_opts['generated_openxr_dispatch_table.h'] = [
        OpenXrDispatchTableGenerator,
        OpenXrDispatchTableGeneratorOptions(
            filename='generated_openxr_dispatch_table.h',
            directory=directory,
            prefix_text=prefix_strings + xr_prefix_strings,
            protect_file=True,
            protect_feature=False,
            extraOpenXrHeaders=extraOpenXrHeaders
        )
    ]

    gen_opts['generated_openxr_layer_func_table.h'] = [
        OpenXrLayerFuncTableGenerator,
        OpenXrLayerFuncTableGeneratorOptions(
            filename='generated_openxr_layer_func_table.h',
            directory=directory,
            prefix_text=prefix_strings + xr_prefix_strings,
            protect_file=True,
            protect_feature=False,
            extraOpenXrHeaders=extraOpenXrHeaders
        )
    ]

    #
    # API call encoder generators
    gen_opts['generated_openxr_api_call_encoders.h'] = [
        OpenXrApiCallEncodersHeaderGenerator,
        OpenXrApiCallEncodersHeaderGeneratorOptions(
            filename='generated_openxr_api_call_encoders.h',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + xr_prefix_strings,
            protect_file=True,
            protect_feature=False,
            extraOpenXrHeaders=extraOpenXrHeaders
        )
    ]

    gen_opts['generated_openxr_api_call_encoders.cpp'] = [
        OpenXrApiCallEncodersBodyGenerator,
        OpenXrApiCallEncodersBodyGeneratorOptions(
            filename='generated_openxr_api_call_encoders.cpp',
            directory=directory,
            blacklists=blacklists,
            capture_overrides=capture_overrides,
            platform_types=platform_types,
            prefix_text=prefix_strings + xr_prefix_strings,
            protect_file=False,
            protect_feature=False,
            extraOpenXrHeaders=extraOpenXrHeaders
        )
    ]

    #
    # Struct encoder/wrapper/tracker generators
    gen_opts['generated_openxr_struct_encoders.cpp'] = [
        OpenXrStructEncodersBodyGenerator,
        OpenXrStructEncodersBodyGeneratorOptions(
            filename='generated_openxr_struct_encoders.cpp',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + xr_prefix_strings,
            protect_file=False,
            protect_feature=False,
            extraOpenXrHeaders=extraOpenXrHeaders
        )
    ]

    gen_opts['generated_openxr_struct_encoders.h'] = [
        OpenXrStructEncodersHeaderGenerator,
        OpenXrStructEncodersHeaderGeneratorOptions(
            filename='generated_openxr_struct_encoders.h',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + xr_prefix_strings,
            protect_file=True,
            protect_feature=False,
            extraOpenXrHeaders=extraOpenXrHeaders
        )
    ]

    gen_opts['generated_openxr_struct_pnext_encoder.cpp'] = [
        OpenXrStructPNextEncodersGenerator,
        OpenXrStructPNextEncodersGeneratorOptions(
            filename='generated_openxr_struct_pnext_encoder.cpp',
            directory=directory,
            prefix_text=prefix_strings + xr_prefix_strings,
            protect_file=False,
            protect_feature=False,
            extraOpenXrHeaders=extraOpenXrHeaders
        )
    ]

    gen_opts['generated_openxr_struct_handle_wrappers.h'] = [
        OpenXrStructHandleWrappersHeaderGenerator,
        OpenXrStructHandleWrappersHeaderGeneratorOptions(
            filename='generated_openxr_struct_handle_wrappers.h',
            directory=directory,
            blacklists=blacklists,
            prefix_text=prefix_strings + xr_prefix_strings,
            protect_file=True,
            protect_feature=False,
            extraOpenXrHeaders=extraOpenXrHeaders
        )
    ]

    gen_opts['generated_openxr_struct_handle_wrappers.cpp'] = [
        OpenXrStructHandleWrappersBodyGenerator,
        OpenXrStructHandleWrappersBodyGeneratorOptions(
            filename='generated_openxr_struct_handle_wrappers.cpp',
            directory=directory,
            blacklists=blacklists,
            prefix_text=prefix_strings + xr_prefix_strings,
            protect_file=False,
            protect_feature=False,
            extraOpenXrHeaders=extraOpenXrHeaders
        )
    ]

    gen_opts['generated_openxr_struct_trackers.h'] = [
        OpenXrStructTrackersHeaderGenerator,
        OpenXrStructTrackersHeaderGeneratorOptions(
            filename='generated_openxr_struct_trackers.h',
            directory=directory,
            blacklists=blacklists,
            prefix_text=prefix_strings + xr_prefix_strings,
            protect_file=False,
            protect_feature=False,
            extraOpenXrHeaders=extraOpenXrHeaders
        )
    ]

    gen_opts['generated_openxr_struct_trackers.cpp'] = [
        OpenXrStructTrackersBodyGenerator,
        OpenXrStructTrackersBodyGeneratorOptions(
            filename='generated_openxr_struct_trackers.cpp',
            directory=directory,
            blacklists=blacklists,
            prefix_text=prefix_strings + xr_prefix_strings,
            protect_file=False,
            protect_feature=False,
            extraOpenXrHeaders=extraOpenXrHeaders
        )
    ]

    #
    # To string generators
    gen_opts['generated_openxr_enum_to_string.h'] = [
        OpenXrEnumToStringHeaderGenerator,
        OpenXrEnumToStringHeaderGeneratorOptions(
            filename='generated_openxr_enum_to_string.h',
            directory=directory,
            blacklists=blacklists,
            platformTypes=platform_types,
            prefixText=prefix_strings + xr_prefix_strings,
            protectFile=True,
            protectFeature=False,
            extraOpenXrHeaders=extraOpenXrHeaders
        )
    ]

    gen_opts['generated_openxr_enum_to_string.cpp'] = [
        OpenXrEnumToStringBodyGenerator,
        OpenXrEnumToStringBodyGeneratorOptions(
            filename='generated_openxr_enum_to_string.cpp',
            directory=directory,
            blacklists=blacklists,
            platformTypes=platform_types,
            prefixText=prefix_strings + xr_prefix_strings,
            protectFile=False,
            protectFeature=False,
            extraOpenXrHeaders=extraOpenXrHeaders
        )
    ]

    gen_opts['generated_openxr_state_table.h'] = [
        OpenXrStateTableHeaderGenerator,
        OpenXrStateTableHeaderGeneratorOptions(
            filename='generated_openxr_state_table.h',
            directory=directory,
            blacklists=blacklists,
            platformTypes=platform_types,
            prefixText=prefix_strings + xr_prefix_strings,
            protectFile=True,
            protectFeature=False,
            extraOpenXrHeaders=extraOpenXrHeaders
        )
    ]

    #    #
    #    # API call decoder generators
    #    gen_opts['generated_openxr_decoder.cpp'] = [
    #        OpenXrDecoderBodyGenerator,
    #        OpenXrDecoderBodyGeneratorOptions(
    #            filename='generated_openxr_decoder.cpp',
    #            directory=directory,
    #            blacklists=blacklists,
    #            platform_types=platform_types,
    #            prefix_text=prefix_strings + xr_prefix_strings,
    #            protect_file=False,
    #            protect_feature=False,
    #            extraOpenXrHeaders=extraOpenXrHeaders
    #        )
    #    ]
    #
    #    gen_opts['generated_openxr_decoder.h'] = [
    #        OpenXrDecoderHeaderGenerator,
    #        OpenXrDecoderHeaderGeneratorOptions(
    #            filename='generated_openxr_decoder.h',
    #            directory=directory,
    #            blacklists=blacklists,
    #            platform_types=platform_types,
    #            prefix_text=prefix_strings + xr_prefix_strings,
    #            protect_file=True,
    #            protect_feature=False,
    #            extraOpenXrHeaders=extraOpenXrHeaders
    #        )
    #    ]
    #
    #    #
    #    # Struct decoder generators
    #    gen_opts['generated_openxr_struct_decoders.cpp'] = [
    #        OpenXrStructDecodersBodyGenerator,
    #        OpenXrStructDecodersBodyGeneratorOptions(
    #            filename='generated_openxr_struct_decoders.cpp',
    #            directory=directory,
    #            blacklists=blacklists,
    #            platform_types=platform_types,
    #            prefix_text=prefix_strings + xr_prefix_strings,
    #            protect_file=False,
    #            protect_feature=False,
    #            extraOpenXrHeaders=extraOpenXrHeaders
    #        )
    #    ]
    #
    #    gen_opts['generated_openxr_struct_decoders_forward.h'] = [
    #        OpenXrStructDecodersForwardGenerator,
    #        OpenXrStructDecodersForwardGeneratorOptions(
    #            filename='generated_openxr_struct_decoders_forward.h',
    #            directory=directory,
    #            blacklists=blacklists,
    #            platform_types=platform_types,
    #            prefix_text=prefix_strings + xr_prefix_strings,
    #            protect_file=True,
    #            protect_feature=False,
    #            extraOpenXrHeaders=extraOpenXrHeaders
    #        )
    #    ]
    #
    #    gen_opts['generated_openxr_struct_decoders.h'] = [
    #        OpenXrStructDecodersHeaderGenerator,
    #        OpenXrStructDecodersHeaderGeneratorOptions(
    #            filename='generated_openxr_struct_decoders.h',
    #            directory=directory,
    #            blacklists=blacklists,
    #            platform_types=platform_types,
    #            prefix_text=prefix_strings + xr_prefix_strings,
    #            protect_file=True,
    #            protect_feature=False,
    #            extraOpenXrHeaders=extraOpenXrHeaders
    #        )
    #    ]
    #
    #    gen_opts['generated_decode_pnext_struct.cpp'] = [
    #        DecodePNextStructGenerator,
    #        DecodePNextStructGeneratorOptions(
    #            filename='generated_decode_pnext_struct.cpp',
    #            directory=directory,
    #            prefix_text=prefix_strings + xr_prefix_strings,
    #            protect_file=False,
    #            protect_feature=False,
    #            extraOpenXrHeaders=extraOpenXrHeaders
    #        )
    #    ]
    #
    #    #
    #    # Consumer generation
    #    gen_opts['generated_openxr_consumer.h'] = [
    #        OpenXrConsumerHeaderGenerator,
    #        OpenXrConsumerHeaderGeneratorOptions(
    #            class_name='OpenXrConsumer',
    #            base_class_header='openxr_consumer_base.h',
    #            is_override=False,
    #            filename='generated_openxr_consumer.h',
    #            directory=directory,
    #            blacklists=blacklists,
    #            platform_types=platform_types,
    #            prefix_text=prefix_strings + xr_prefix_strings,
    #            protect_file=True,
    #            protect_feature=False,
    #            extraOpenXrHeaders=extraOpenXrHeaders
    #        )
    #    ]
    #
    #    gen_opts['generated_openxr_referenced_resource_consumer.h'] = [
    #        OpenXrReferencedResourceHeaderGenerator,
    #        OpenXrReferencedResourceHeaderGeneratorOptions(
    #            filename='generated_openxr_referenced_resource_consumer.h',
    #            directory=directory,
    #            blacklists=blacklists,
    #            platform_types=platform_types,
    #            prefix_text=prefix_strings + xr_prefix_strings,
    #            protect_file=False,
    #            protect_feature=False,
    #            extraOpenXrHeaders=extraOpenXrHeaders
    #        )
    #    ]
    #
    #    gen_opts['generated_openxr_replay_consumer.h'] = [
    #        OpenXrConsumerHeaderGenerator,
    #        OpenXrConsumerHeaderGeneratorOptions(
    #            class_name='OpenXrReplayConsumer',
    #            base_class_header='openxr_replay_consumer_base.h',
    #            is_override=True,
    #            constructor_args=
    #            'std::shared_ptr<application::Application> application, const OpenXrReplayOptions& options',
    #            filename='generated_openxr_replay_consumer.h',
    #            directory=directory,
    #            blacklists=blacklists,
    #            platform_types=platform_types,
    #            prefix_text=prefix_strings + xr_prefix_strings,
    #            protect_file=True,
    #            protect_feature=False,
    #            extraOpenXrHeaders=extraOpenXrHeaders
    #        )
    #    ]
    #
    #    gen_opts['generated_openxr_replay_consumer.cpp'] = [
    #        OpenXrReplayConsumerBodyGenerator,
    #        OpenXrReplayConsumerBodyGeneratorOptions(
    #            filename='generated_openxr_replay_consumer.cpp',
    #            directory=directory,
    #            blacklists=blacklists,
    #            replay_overrides=replay_overrides,
    #            platform_types=platform_types,
    #            prefix_text=prefix_strings + xr_prefix_strings,
    #            protect_file=False,
    #            protect_feature=False,
    #            extraOpenXrHeaders=extraOpenXrHeaders
    #        )
    #    ]
    #
    #    gen_opts['generated_openxr_referenced_resource_consumer.cpp'] = [
    #        OpenXrReferencedResourceBodyGenerator,
    #        OpenXrReferencedResourceBodyGeneratorOptions(
    #            filename='generated_openxr_referenced_resource_consumer.cpp',
    #            directory=directory,
    #            blacklists=blacklists,
    #            platform_types=platform_types,
    #            prefix_text=prefix_strings + xr_prefix_strings,
    #            protect_file=False,
    #            protect_feature=False,
    #            extraOpenXrHeaders=extraOpenXrHeaders
    #        )
    #    ]


def gen_target(args):
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

        if not args.quiet:
            write('* Building', options.filename, file=sys.stderr)
            write(
                '* options.versions          =',
                options.versions,
                file=sys.stderr
            )
            write(
                '* options.emitversions      =',
                options.emitversions,
                file=sys.stderr
            )
            write(
                '* options.defaultExtensions =',
                options.defaultExtensions,
                file=sys.stderr
            )
            write(
                '* options.addExtensions     =',
                options.addExtensions,
                file=sys.stderr
            )
            write(
                '* options.removeExtensions  =',
                options.removeExtensions,
                file=sys.stderr
            )
            write(
                '* options.emitEtensions    =',
                options.emitExtensions,
                file=sys.stderr
            )

        gen = create_generator(
            err_file=err_warn, warn_file=err_warn, diag_file=diag
        )

        return (gen, options)
    else:
        write(
            'No generator options for unknown target:',
            args.target,
            file=sys.stderr
        )
        return None


# -feature name
# -extension name
# For both, "name" may be a single name, or a space-separated list
# of names, or a regular expression.
if __name__ == '__main__':
    parser = argparse.ArgumentParser()

    parser.add_argument('-debug', action='store_true', help='Enable debugging')
    parser.add_argument(
        '-dump', action='store_true', help='Enable dump to stderr'
    )
    parser.add_argument(
        '-diagfile',
        action='store',
        default=None,
        help='Write diagnostics to specified file'
    )
    parser.add_argument(
        '-errfile',
        action='store',
        default=None,
        help='Write errors and warnings to specified file instead of stderr'
    )
    parser.add_argument(
        '-noprotect',
        dest='protect',
        action='store_false',
        help='Disable inclusion protection in output headers'
    )
    parser.add_argument(
        '-profile', action='store_true', help='Enable profiling'
    )
    parser.add_argument(
        '-registry',
        action='store',
        default='xr.xml',
        help='Use specified registry file'
    )
    parser.add_argument(
        '-scripts',
        action='store',
        default=None,
        help='Use specified registry scripts directory'
    )
    parser.add_argument(
        '-headers-dir',
        dest='headers_dir',
        action='store',
        default=None,
        help='\n'.join(
            [
                'Path to a directory that holds additional OpenXr header files required to build.',
                'These header files are included directly after the OpenXr header in all generated files.'
            ]
        )
    )
    parser.add_argument('-time', action='store_true', help='Enable timing')
    parser.add_argument(
        '-validate', action='store_true', help='Enable group validation'
    )
    parser.add_argument(
        '-o',
        action='store',
        dest='directory',
        default='.',
        help='Create target and related files in specified directory'
    )
    parser.add_argument(
        'target', metavar='target', nargs='?', help='Specify target'
    )
    parser.add_argument(
        '-quiet',
        action='store_true',
        default=True,
        help='Suppress script output during normal execution.'
    )
    parser.add_argument(
        '-verbose',
        action='store_false',
        dest='quiet',
        default=True,
        help='Enable script output during normal execution.'
    )
    parser.add_argument(
        '-configs',
        action='store',
        dest='configs',
        default='.',
        help=
        'Specify directory containing JSON configuration files for generators'
    )

    args = parser.parse_args()

    # create error/warning & diagnostic files
    if (args.errfile):
        err_warn = open(args.errfile, 'w', encoding='utf-8')
    else:
        err_warn = sys.stderr

    if (args.diagfile):
        diag = open(args.diagfile, 'w', encoding='utf-8')
    else:
        diag = None

    (gen, options) = gen_target(args)

    reg = Registry(gen, options)

    ## @note We parse vk.xml to an in-memory element tree and then extract the info we need
    ## from that into the Registry object once per output file we generate rather than once
    ## per run of the top-level generation script.
    start_timer(args.time)
    tree = etree.parse(args.registry)
    end_timer(args.time, '* Time to make ElementTree =')

    # Extend the xr.xml tree with XML files from the config dir
    for filename in os.listdir(args.configs):
        if filename.endswith('.xml'):
            extend_xml(tree, os.path.join(args.configs, filename))

    start_timer(args.time)
    reg.loadElementTree(tree)
    end_timer(args.time, '* Time to parse ElementTree =')

    if (args.validate):
        reg.validateGroups()

    if (args.dump):
        write('* Dumping registry to regdump.txt', file=sys.stderr)
        reg.dumpReg(filehandle=open('regdump.txt', 'w', encoding='utf-8'))

    if (args.debug):
        pdb.run('reg.api_gen()')
    else:
        start_timer(args.time)
        reg.apiGen()
        end_timer(args.time, '* Time to generate ' + options.filename + ' =')

    if not args.quiet:
        write('* Generated', options.filename, file=sys.stderr)
