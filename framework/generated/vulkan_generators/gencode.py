#!/usr/bin/env python
#
# Copyright (c) 2013-2016 The Khronos Group Inc.
# Copyright (c) 2018-2020 Valve Corporation
# Copyright (c) 2018-2020 LunarG, Inc.
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

import argparse, cProfile, pdb, os, string, sys, time
from reg import *
from generator import write

# API Call Decoders
from vulkan_decoder_body_generator import VulkanDecoderBodyGenerator,VulkanDecoderBodyGeneratorOptions
from vulkan_decoder_header_generator import VulkanDecoderHeaderGenerator,VulkanDecoderHeaderGeneratorOptions

# Struct Decoders
from vulkan_struct_decoders_body_generator import VulkanStructDecodersBodyGenerator,VulkanStructDecodersBodyGeneratorOptions
from vulkan_struct_decoders_forward_generator import VulkanStructDecodersForwardGenerator,VulkanStructDecodersForwardGeneratorOptions
from vulkan_struct_decoders_header_generator import VulkanStructDecodersHeaderGenerator,VulkanStructDecodersHeaderGeneratorOptions
from decode_pnext_struct_generator import DecodePNextStructGenerator,DecodePNextStructGeneratorOptions

# Consumers
from vulkan_consumer_header_generator import VulkanConsumerHeaderGenerator,VulkanConsumerHeaderGeneratorOptions
from vulkan_ascii_consumer_body_generator import VulkanAsciiConsumerBodyGenerator,VulkanAsciiConsumerBodyGeneratorOptions
from vulkan_replay_consumer_body_generator import VulkanReplayConsumerBodyGenerator,VulkanReplayConsumerBodyGeneratorOptions
from vulkan_struct_handle_mappers_header_generator import VulkanStructHandleMappersHeaderGenerator,VulkanStructHandleMappersHeaderGeneratorOptions
from vulkan_struct_handle_mappers_body_generator import VulkanStructHandleMappersBodyGenerator,VulkanStructHandleMappersBodyGeneratorOptions

# API Call Encoders
from vulkan_api_call_encoders_body_generator import VulkanApiCallEncodersBodyGenerator,VulkanApiCallEncodersBodyGeneratorOptions
from vulkan_api_call_encoders_header_generator import VulkanApiCallEncodersHeaderGenerator,VulkanApiCallEncodersHeaderGeneratorOptions
from vulkan_command_buffer_util_body_generator import VulkanCommandBufferUtilBodyGenerator,VulkanCommandBufferUtilBodyGeneratorOptions
from vulkan_command_buffer_util_header_generator import VulkanCommandBufferUtilHeaderGenerator,VulkanCommandBufferUtilHeaderGeneratorOptions
from vulkan_dispatch_table_generator import VulkanDispatchTableGenerator, VulkanDispatchTableGeneratorOptions
from layer_func_table_generator import LayerFuncTableGenerator,LayerFuncTableGeneratorOptions

# Struct Encoders
from vulkan_struct_encoders_body_generator import VulkanStructEncodersBodyGenerator,VulkanStructEncodersBodyGeneratorOptions
from vulkan_struct_encoders_header_generator import VulkanStructEncodersHeaderGenerator,VulkanStructEncodersHeaderGeneratorOptions
from encode_pnext_struct_generator import EncodePNextStructGenerator,EncodePNextStructGeneratorOptions
from vulkan_struct_handle_wrappers_header_generator import VulkanStructHandleWrappersHeaderGenerator,VulkanStructHandleWrappersHeaderGeneratorOptions
from vulkan_struct_handle_wrappers_body_generator import VulkanStructHandleWrappersBodyGenerator,VulkanStructHandleWrappersBodyGeneratorOptions

# Simple timer functions
startTime = None

def startTimer(timeit):
    global startTime
    if timeit:
        startTime = time.process_time()

def endTimer(timeit, msg):
    global startTime
    if timeit:
        endTime = time.process_time()
        write(msg, endTime - startTime, file=sys.stderr)
        startTime = None

# JSON files for customizing code generation
defaultBlacklists = 'blacklists.json'
defaultPlatformTypes = 'platform_types.json'
defaultReplayOverrides = 'replay_overrides.json'
defaultCaptureOverrides = 'capture_overrides.json'

# Returns a directory of [ generator function, generator options ] indexed
# by specified short names. The generator options incorporate the following
# parameters:
#
# args is an parsed argument object; see below for the fields that are used.
def makeGenOpts(args):
    global genOpts
    genOpts = {}

    # Output target directory
    directory = args.directory

    # JSON configuration files
    blacklists = os.path.join(args.configs, defaultBlacklists)
    platformTypes = os.path.join(args.configs, defaultPlatformTypes)
    replayOverrides = os.path.join(args.configs, defaultReplayOverrides)
    captureOverrides = os.path.join(args.configs, defaultCaptureOverrides)

    # Copyright text prefixing all headers (list of strings).
    prefixStrings = [
        '/*',
        '** Copyright (c) 2018-2020 Valve Corporation',
        '** Copyright (c) 2018-2020 LunarG, Inc.',
        '**',
        '** Licensed under the Apache License, Version 2.0 (the "License");',
        '** you may not use this file except in compliance with the License.',
        '** You may obtain a copy of the License at',
        '**',
        '**     http://www.apache.org/licenses/LICENSE-2.0',
        '**',
        '** Unless required by applicable law or agreed to in writing, software',
        '** distributed under the License is distributed on an "AS IS" BASIS,',
        '** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.',
        '** See the License for the specific language governing permissions and',
        '** limitations under the License.',
        '*/',
        ''
    ]

    # Text specific to Vulkan headers
    vkPrefixStrings = [
        '/*',
        '** This file is generated from the Khronos Vulkan XML API Registry.',
        '**',
        '*/',
        ''
    ]

    #
    # API call decoder generators
    genOpts['generated_vulkan_decoder.cpp'] = [
          VulkanDecoderBodyGenerator,
          VulkanDecoderBodyGeneratorOptions(
            filename          = 'generated_vulkan_decoder.cpp',
            directory         = directory,
            blacklists        = blacklists,
            platformTypes     = platformTypes,
            prefixText        = prefixStrings + vkPrefixStrings,
            protectFile       = False,
            protectFeature    = False)
        ]

    genOpts['generated_vulkan_decoder.h'] = [
          VulkanDecoderHeaderGenerator,
          VulkanDecoderHeaderGeneratorOptions(
            filename          = 'generated_vulkan_decoder.h',
            directory         = directory,
            blacklists        = blacklists,
            platformTypes     = platformTypes,
            prefixText        = prefixStrings + vkPrefixStrings,
            protectFile       = True,
            protectFeature    = False)
        ]

    #
    # Struct decoder generators
    genOpts['generated_vulkan_struct_decoders.cpp'] = [
          VulkanStructDecodersBodyGenerator,
          VulkanStructDecodersBodyGeneratorOptions(
            filename          = 'generated_vulkan_struct_decoders.cpp',
            directory         = directory,
            blacklists        = blacklists,
            platformTypes     = platformTypes,
            prefixText        = prefixStrings + vkPrefixStrings,
            protectFile       = False,
            protectFeature    = False)
        ]

    genOpts['generated_vulkan_struct_decoders_forward.h'] = [
          VulkanStructDecodersForwardGenerator,
          VulkanStructDecodersForwardGeneratorOptions(
            filename          = 'generated_vulkan_struct_decoders_forward.h',
            directory         = directory,
            blacklists        = blacklists,
            platformTypes     = platformTypes,
            prefixText        = prefixStrings + vkPrefixStrings,
            protectFile       = True,
            protectFeature    = False)
        ]

    genOpts['generated_vulkan_struct_decoders.h'] = [
          VulkanStructDecodersHeaderGenerator,
          VulkanStructDecodersHeaderGeneratorOptions(
            filename          = 'generated_vulkan_struct_decoders.h',
            directory         = directory,
            blacklists        = blacklists,
            platformTypes     = platformTypes,
            prefixText        = prefixStrings + vkPrefixStrings,
            protectFile       = True,
            protectFeature    = False)
        ]

    genOpts['generated_decode_pnext_struct.cpp'] = [
          DecodePNextStructGenerator,
          DecodePNextStructGeneratorOptions(
            filename          = 'generated_decode_pnext_struct.cpp',
            directory         = directory,
            prefixText        = prefixStrings + vkPrefixStrings,
            protectFile       = False,
            protectFeature    = False)
        ]

    #
    # Consumer generation
    genOpts['generated_vulkan_consumer.h'] = [
        VulkanConsumerHeaderGenerator,
        VulkanConsumerHeaderGeneratorOptions(
        className         = 'VulkanConsumer',
        baseClassHeader   = 'vulkan_consumer_base.h',
        isOverride        = False,
        filename          = 'generated_vulkan_consumer.h',
        directory         = directory,
        blacklists        = blacklists,
        platformTypes     = platformTypes,
        prefixText        = prefixStrings + vkPrefixStrings,
        protectFile       = True,
        protectFeature    = False)
    ]

    genOpts['generated_vulkan_ascii_consumer.h'] = [
        VulkanConsumerHeaderGenerator,
        VulkanConsumerHeaderGeneratorOptions(
        className         = 'VulkanAsciiConsumer',
        baseClassHeader   = 'vulkan_ascii_consumer_base.h',
        isOverride        = True,
        filename          = 'generated_vulkan_ascii_consumer.h',
        directory         = directory,
        blacklists        = blacklists,
        platformTypes     = platformTypes,
        prefixText        = prefixStrings + vkPrefixStrings,
        protectFile       = True,
        protectFeature    = False)
    ]

    genOpts['generated_vulkan_replay_consumer.h'] = [
        VulkanConsumerHeaderGenerator,
        VulkanConsumerHeaderGeneratorOptions(
        className         = 'VulkanReplayConsumer',
        baseClassHeader   = 'vulkan_replay_consumer_base.h',
        isOverride        = True,
        constructorArgs   = 'WindowFactory* window_factory, const ReplayOptions& options',
        filename          = 'generated_vulkan_replay_consumer.h',
        directory         = directory,
        blacklists        = blacklists,
        platformTypes     = platformTypes,
        prefixText        = prefixStrings + vkPrefixStrings,
        protectFile       = True,
        protectFeature    = False)
    ]

    genOpts['generated_vulkan_ascii_consumer.cpp'] = [
        VulkanAsciiConsumerBodyGenerator,
        VulkanAsciiConsumerBodyGeneratorOptions(
        filename          = 'generated_vulkan_ascii_consumer.cpp',
        directory         = directory,
        blacklists        = blacklists,
        platformTypes     = platformTypes,
        prefixText        = prefixStrings + vkPrefixStrings,
        protectFile       = False,
        protectFeature    = False)
    ]

    genOpts['generated_vulkan_replay_consumer.cpp'] = [
        VulkanReplayConsumerBodyGenerator,
        VulkanReplayConsumerBodyGeneratorOptions(
        filename          = 'generated_vulkan_replay_consumer.cpp',
        directory         = directory,
        blacklists        = blacklists,
        replayOverrides   = replayOverrides,
        platformTypes     = platformTypes,
        prefixText        = prefixStrings + vkPrefixStrings,
        protectFile       = False,
        protectFeature    = False)
    ]

    genOpts['generated_vulkan_struct_handle_mappers.h'] = [
          VulkanStructHandleMappersHeaderGenerator,
          VulkanStructHandleMappersHeaderGeneratorOptions(
            filename          = 'generated_vulkan_struct_handle_mappers.h',
            directory         = directory,
            blacklists        = blacklists,
            prefixText        = prefixStrings + vkPrefixStrings,
            protectFile       = True,
            protectFeature    = False)
        ]

    genOpts['generated_vulkan_struct_handle_mappers.cpp'] = [
          VulkanStructHandleMappersBodyGenerator,
          VulkanStructHandleMappersBodyGeneratorOptions(
            filename          = 'generated_vulkan_struct_handle_mappers.cpp',
            directory         = directory,
            blacklists        = blacklists,
            prefixText        = prefixStrings + vkPrefixStrings,
            protectFile       = False,
            protectFeature    = False)
        ]

    #
    # API call encoder generators
    genOpts['generated_vulkan_api_call_encoders.h'] = [
          VulkanApiCallEncodersHeaderGenerator,
          VulkanApiCallEncodersHeaderGeneratorOptions(
            filename          = 'generated_vulkan_api_call_encoders.h',
            directory         = directory,
            blacklists        = blacklists,
            platformTypes     = platformTypes,
            prefixText        = prefixStrings + vkPrefixStrings,
            protectFile       = True,
            protectFeature    = False)
        ]

    genOpts['generated_vulkan_api_call_encoders.cpp'] = [
          VulkanApiCallEncodersBodyGenerator,
          VulkanApiCallEncodersBodyGeneratorOptions(
            filename          = 'generated_vulkan_api_call_encoders.cpp',
            directory         = directory,
            blacklists        = blacklists,
            captureOverrides  = captureOverrides,
            platformTypes     = platformTypes,
            prefixText        = prefixStrings + vkPrefixStrings,
            protectFile       = False,
            protectFeature    = False)
        ]

    genOpts['generated_vulkan_command_buffer_util.h'] = [
          VulkanCommandBufferUtilHeaderGenerator,
          VulkanCommandBufferUtilHeaderGeneratorOptions(
            filename          = 'generated_vulkan_command_buffer_util.h',
            directory         = directory,
            blacklists        = blacklists,
            platformTypes     = platformTypes,
            prefixText        = prefixStrings + vkPrefixStrings,
            protectFile       = True,
            protectFeature    = False)
        ]

    genOpts['generated_vulkan_command_buffer_util.cpp'] = [
          VulkanCommandBufferUtilBodyGenerator,
          VulkanCommandBufferUtilBodyGeneratorOptions(
            filename          = 'generated_vulkan_command_buffer_util.cpp',
            directory         = directory,
            blacklists        = blacklists,
            platformTypes     = platformTypes,
            prefixText        = prefixStrings + vkPrefixStrings,
            protectFile       = False,
            protectFeature    = False)
        ]

    genOpts['generated_vulkan_dispatch_table.h'] = [
            VulkanDispatchTableGenerator,
            VulkanDispatchTableGeneratorOptions(
            filename          = 'generated_vulkan_dispatch_table.h',
            directory         = directory,
            prefixText        = prefixStrings + vkPrefixStrings,
            protectFile       = True,
            protectFeature    = False)
        ]

    genOpts['generated_layer_func_table.h'] = [
          LayerFuncTableGenerator,
          LayerFuncTableGeneratorOptions(
            filename          = 'generated_layer_func_table.h',
            directory         = directory,
            prefixText        = prefixStrings + vkPrefixStrings,
            protectFile       = True,
            protectFeature    = False)
        ]

    #
    # Struct encoder generators
    genOpts['generated_vulkan_struct_encoders.cpp'] = [
          VulkanStructEncodersBodyGenerator,
          VulkanStructEncodersBodyGeneratorOptions(
            filename          = 'generated_vulkan_struct_encoders.cpp',
            directory         = directory,
            blacklists        = blacklists,
            platformTypes     = platformTypes,
            prefixText        = prefixStrings + vkPrefixStrings,
            protectFile       = False,
            protectFeature    = False)
        ]

    genOpts['generated_vulkan_struct_encoders.h'] = [
          VulkanStructEncodersHeaderGenerator,
          VulkanStructEncodersHeaderGeneratorOptions(
            filename          = 'generated_vulkan_struct_encoders.h',
            directory         = directory,
            blacklists        = blacklists,
            platformTypes     = platformTypes,
            prefixText        = prefixStrings + vkPrefixStrings,
            protectFile       = True,
            protectFeature    = False)
        ]

    genOpts['generated_encode_pnext_struct.cpp'] = [
          EncodePNextStructGenerator,
          EncodePNextStructGeneratorOptions(
            filename          = 'generated_encode_pnext_struct.cpp',
            directory         = directory,
            prefixText        = prefixStrings + vkPrefixStrings,
            protectFile       = False,
            protectFeature    = False)
        ]

    genOpts['generated_vulkan_struct_handle_wrappers.h'] = [
          VulkanStructHandleWrappersHeaderGenerator,
          VulkanStructHandleWrappersHeaderGeneratorOptions(
            filename          = 'generated_vulkan_struct_handle_wrappers.h',
            directory         = directory,
            blacklists        = blacklists,
            prefixText        = prefixStrings + vkPrefixStrings,
            protectFile       = True,
            protectFeature    = False)
        ]

    genOpts['generated_vulkan_struct_handle_wrappers.cpp'] = [
          VulkanStructHandleWrappersBodyGenerator,
          VulkanStructHandleWrappersBodyGeneratorOptions(
            filename          = 'generated_vulkan_struct_handle_wrappers.cpp',
            directory         = directory,
            blacklists        = blacklists,
            prefixText        = prefixStrings + vkPrefixStrings,
            protectFile       = False,
            protectFeature    = False)
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
def genTarget(args):
    # Create generator options with specified parameters
    makeGenOpts(args)

    if args.target in genOpts:
        createGenerator = genOpts[args.target][0]
        options = genOpts[args.target][1]

        if not args.quiet:
            write('* Building', options.filename, file=sys.stderr)
            write('* options.versions          =', options.versions, file=sys.stderr)
            write('* options.emitversions      =', options.emitversions, file=sys.stderr)
            write('* options.defaultExtensions =', options.defaultExtensions, file=sys.stderr)
            write('* options.addExtensions     =', options.addExtensions, file=sys.stderr)
            write('* options.removeExtensions  =', options.removeExtensions, file=sys.stderr)
            write('* options.emitExtensions    =', options.emitExtensions, file=sys.stderr)

        gen = createGenerator(errFile=errWarn,
                              warnFile=errWarn,
                              diagFile=diag)

        return (gen, options)
    else:
        write('No generator options for unknown target:',
              args.target, file=sys.stderr)
        return None

# -feature name
# -extension name
# For both, "name" may be a single name, or a space-separated list
# of names, or a regular expression.
if __name__ == '__main__':
    parser = argparse.ArgumentParser()

    parser.add_argument('-debug', action='store_true',
                        help='Enable debugging')
    parser.add_argument('-dump', action='store_true',
                        help='Enable dump to stderr')
    parser.add_argument('-diagfile', action='store',
                        default=None,
                        help='Write diagnostics to specified file')
    parser.add_argument('-errfile', action='store',
                        default=None,
                        help='Write errors and warnings to specified file instead of stderr')
    parser.add_argument('-noprotect', dest='protect', action='store_false',
                        help='Disable inclusion protection in output headers')
    parser.add_argument('-profile', action='store_true',
                        help='Enable profiling')
    parser.add_argument('-registry', action='store',
                        default='vk.xml',
                        help='Use specified registry file instead of vk.xml')
    parser.add_argument('-time', action='store_true',
                        help='Enable timing')
    parser.add_argument('-validate', action='store_true',
                        help='Enable group validation')
    parser.add_argument('-o', action='store', dest='directory',
                        default='.',
                        help='Create target and related files in specified directory')
    parser.add_argument('target', metavar='target', nargs='?',
                        help='Specify target')
    parser.add_argument('-quiet', action='store_true', default=True,
                        help='Suppress script output during normal execution.')
    parser.add_argument('-verbose', action='store_false', dest='quiet', default=True,
                        help='Enable script output during normal execution.')
    parser.add_argument('-configs', action='store', dest='configs',
                        default='.',
                        help='Specify directory containing JSON configuration files for generators')

    args = parser.parse_args()

    # create error/warning & diagnostic files
    if (args.errfile):
        errWarn = open(args.errfile, 'w', encoding='utf-8')
    else:
        errWarn = sys.stderr

    if (args.diagfile):
        diag = open(args.diagfile, 'w', encoding='utf-8')
    else:
        diag = None

    (gen, options) = genTarget(args)

    reg = Registry(gen, options)

    startTimer(args.time)
    tree = etree.parse(args.registry)
    endTimer(args.time, '* Time to make ElementTree =')

    startTimer(args.time)
    reg.loadElementTree(tree)
    endTimer(args.time, '* Time to parse ElementTree =')

    if (args.validate):
        reg.validateGroups()

    if (args.dump):
        write('* Dumping registry to regdump.txt', file=sys.stderr)
        reg.dumpReg(filehandle = open('regdump.txt', 'w', encoding='utf-8'))

    if (args.debug):
        pdb.run('reg.apiGen()')
    else:
        startTimer(args.time)
        reg.apiGen()
        endTimer(args.time, '* Time to generate ' + options.filename + ' =')

    if not args.quiet:
        write('* Generated', options.filename, file=sys.stderr)
