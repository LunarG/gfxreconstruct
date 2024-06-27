#!/usr/bin/env python
#
# Copyright (c) 2018-2023 Valve Corporation
# Copyright (c) 2018-2023 LunarG, Inc.
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
# and related Python files found in the KhronosGroup/Vulkan-Headers GitHub repository.
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
from registry.reg import Registry, etree
from generator import write

# API Call Decoders
from vulkan_decoder_body_generator import VulkanDecoderBodyGenerator, VulkanDecoderBodyGeneratorOptions
from vulkan_decoder_header_generator import VulkanDecoderHeaderGenerator, VulkanDecoderHeaderGeneratorOptions

# Struct Decoders
from vulkan_struct_decoders_body_generator import VulkanStructDecodersBodyGenerator, VulkanStructDecodersBodyGeneratorOptions
from vulkan_struct_decoders_forward_generator import VulkanStructDecodersForwardGenerator, VulkanStructDecodersForwardGeneratorOptions
from vulkan_struct_decoders_header_generator import VulkanStructDecodersHeaderGenerator, VulkanStructDecodersHeaderGeneratorOptions
from decode_pnext_struct_generator import DecodePNextStructGenerator, DecodePNextStructGeneratorOptions

# Consumers
from vulkan_consumer_header_generator import VulkanConsumerHeaderGenerator, VulkanConsumerHeaderGeneratorOptions
from vulkan_cpp_consumer_body_generator import VulkanCppConsumerBodyGenerator,VulkanCppConsumerBodyGeneratorOptions
from vulkan_cpp_consumer_header_generator import VulkanCppConsumerHeaderGenerator, VulkanCppConsumerHeaderGeneratorOptions
from vulkan_json_consumer_header_generator import VulkanExportJsonConsumerHeaderGenerator, VulkanExportJsonConsumerHeaderGeneratorOptions
from vulkan_json_consumer_body_generator import VulkanExportJsonConsumerBodyGenerator, VulkanExportJsonConsumerBodyGeneratorOptions
from vulkan_replay_consumer_body_generator import VulkanReplayConsumerBodyGenerator, VulkanReplayConsumerBodyGeneratorOptions
from vulkan_replay_dump_resources_body_generator import VulkanReplayDumpResourcesBodyGenerator, VulkanReplayDumpResourcesBodyGeneratorOptions
from vulkan_replay_dump_resources_header_generator import VulkanReplayDumpResourcesHeaderGenerator, VulkanReplayDumpResourcesHeaderGeneratorOptions
from vulkan_referenced_resource_consumer_header_generator import VulkanReferencedResourceHeaderGenerator, VulkanReferencedResourceHeaderGeneratorOptions
from vulkan_referenced_resource_consumer_body_generator import VulkanReferencedResourceBodyGenerator, VulkanReferencedResourceBodyGeneratorOptions
from vulkan_struct_handle_mappers_header_generator import VulkanStructHandleMappersHeaderGenerator, VulkanStructHandleMappersHeaderGeneratorOptions
from vulkan_struct_handle_mappers_body_generator import VulkanStructHandleMappersBodyGenerator, VulkanStructHandleMappersBodyGeneratorOptions
from vulkan_feature_util_body_generator import VulkanFeatureUtilBodyGenerator, VulkanFeatureUtilBodyGeneratorOptions

# API Call Encoders
from vulkan_api_call_encoders_body_generator import VulkanApiCallEncodersBodyGenerator, VulkanApiCallEncodersBodyGeneratorOptions
from vulkan_api_call_encoders_header_generator import VulkanApiCallEncodersHeaderGenerator, VulkanApiCallEncodersHeaderGeneratorOptions
from vulkan_command_buffer_util_body_generator import VulkanCommandBufferUtilBodyGenerator, VulkanCommandBufferUtilBodyGeneratorOptions
from vulkan_command_buffer_util_header_generator import VulkanCommandBufferUtilHeaderGenerator, VulkanCommandBufferUtilHeaderGeneratorOptions
from vulkan_dispatch_table_generator import VulkanDispatchTableGenerator, VulkanDispatchTableGeneratorOptions
from layer_func_table_generator import LayerFuncTableGenerator, LayerFuncTableGeneratorOptions

# Struct Encoders
from vulkan_struct_encoders_body_generator import VulkanStructEncodersBodyGenerator, VulkanStructEncodersBodyGeneratorOptions
from vulkan_struct_encoders_header_generator import VulkanStructEncodersHeaderGenerator, VulkanStructEncodersHeaderGeneratorOptions
from encode_pnext_struct_generator import EncodePNextStructGenerator, EncodePNextStructGeneratorOptions
from vulkan_struct_handle_wrappers_header_generator import VulkanStructHandleWrappersHeaderGenerator, VulkanStructHandleWrappersHeaderGeneratorOptions
from vulkan_struct_handle_wrappers_body_generator import VulkanStructHandleWrappersBodyGenerator, VulkanStructHandleWrappersBodyGeneratorOptions
from vulkan_struct_trackers_header_generator import VulkanStructTrackersHeaderGenerator, VulkanStructTrackersHeaderGeneratorOptions
from vulkan_struct_trackers_body_generator import VulkanStructTrackersBodyGenerator, VulkanStructTrackersBodyGeneratorOptions

# To String
from vulkan_enum_to_string_body_generator import VulkanEnumToStringBodyGenerator, VulkanEnumToStringBodyGeneratorOptions
from vulkan_enum_to_string_header_generator import VulkanEnumToStringHeaderGenerator, VulkanEnumToStringHeaderGeneratorOptions

from vulkan_object_info_table_base2_header_generator import VulkanObjectInfoTableBase2HeaderGenerator, VulkanObjectInfoTableBase2HeaderGeneratorOptions
from vulkan_state_table_header_generator import VulkanStateTableHeaderGenerator, VulkanStateTableHeaderGeneratorOptions

from vulkan_enum_to_json_body_generator import VulkanEnumToJsonBodyGenerator, VulkanEnumToJsonBodyGeneratorOptions
from vulkan_enum_to_json_header_generator import VulkanEnumToJsonHeaderGenerator, VulkanEnumToJsonHeaderGeneratorOptions
from vulkan_struct_to_json_header_generator import VulkanStructToJsonHeaderGenerator, VulkanStructToJsonHeaderGeneratorOptions
from vulkan_struct_to_json_body_generator import VulkanStructToJsonBodyGenerator, VulkanStructToJsonBodyGeneratorOptions

# Constants
from vulkan_constant_maps_generator import VulkanConstantMapsGenerator, VulkanConstantMapsGeneratorOptions
from vulkan_stype_util_generator import VulkanSTypeUtilGenerator, VulkanSTypeUtilGeneratorOptions

# ToCpp
from vulkan_cpp_struct_generator import VulkanCppStructGenerator, VulkanCppStructGeneratorOptions
from vulkan_cpp_consumer_extension_generator import VulkanCppConsumerExtensionGenerator, VulkanCppConsumerExtensionGeneratorOptions

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
default_dump_resources_overrides = 'dump_resources_overrides.json'
default_capture_overrides = 'capture_overrides.json'


def _getExtraVulkanHeaders(extraHeadersDir):
    '''
    Recursively get a list of extra Vulkan headers used in the generated code,
    that are included after vulkan/vulkan.h is included
    '''
    extraVulkanHeaders = []
    for child in os.listdir(extraHeadersDir):
        childPath = os.path.join(extraHeadersDir, child)
        if os.path.isdir(childPath):
            extraVulkanHeaders.extend(_getExtraVulkanHeaders(childPath))
        else:
            extraVulkanHeaders.append(childPath)
    return extraVulkanHeaders


def getExtraVulkanHeaders(extraHeadersDir):
    '''
    Get a list of extra Vulkan headers used in the generated code, that are
    included after vulkan/vulkan.h is included
    '''
    return [
        os.path.relpath(header, extraHeadersDir)
        for header in _getExtraVulkanHeaders(extraHeadersDir)
    ]


def extend_xml(dest_tree, src_xml, debug=False):
    '''Extend the parsed vk.xml registry tree with content from another xml file'''
    def merge(dest, src):
        '''Perform a recursive merge of src into dest'''
        leaf_tags = ('command', 'enums', 'extension', 'feature', 'format',
                     'platform', 'spirvcapability', 'spirvextension', 'tag', 'type')
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
    dump_resources_overrides = os.path.join(args.configs, default_dump_resources_overrides)
    capture_overrides = os.path.join(args.configs, default_capture_overrides)

    # Copyright text prefixing all headers (list of strings).
    prefix_strings = [
        '/*', '** Copyright (c) 2018-2023 Valve Corporation',
        '** Copyright (c) 2018-2023 LunarG, Inc.',
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

    # Text specific to Vulkan headers
    vk_prefix_strings = [
        '/*',
        '** This file is generated from the Khronos Vulkan XML API Registry.',
        '**', '*/', ''
    ]

    extraVulkanHeaders = []
    if args.headers_dir is not None:
        extraVulkanHeaders = getExtraVulkanHeaders(args.headers_dir)

    #
    # API call decoder generators
    gen_opts['generated_vulkan_decoder.cpp'] = [
        VulkanDecoderBodyGenerator,
        VulkanDecoderBodyGeneratorOptions(
            filename='generated_vulkan_decoder.cpp',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=False,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_decoder.h'] = [
        VulkanDecoderHeaderGenerator,
        VulkanDecoderHeaderGeneratorOptions(
            filename='generated_vulkan_decoder.h',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=True,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    #
    # Struct decoder generators
    gen_opts['generated_vulkan_struct_decoders.cpp'] = [
        VulkanStructDecodersBodyGenerator,
        VulkanStructDecodersBodyGeneratorOptions(
            filename='generated_vulkan_struct_decoders.cpp',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=False,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_struct_decoders_forward.h'] = [
        VulkanStructDecodersForwardGenerator,
        VulkanStructDecodersForwardGeneratorOptions(
            filename='generated_vulkan_struct_decoders_forward.h',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=True,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_struct_decoders.h'] = [
        VulkanStructDecodersHeaderGenerator,
        VulkanStructDecodersHeaderGeneratorOptions(
            filename='generated_vulkan_struct_decoders.h',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=True,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_decode_pnext_struct.cpp'] = [
        DecodePNextStructGenerator,
        DecodePNextStructGeneratorOptions(
            filename='generated_decode_pnext_struct.cpp',
            directory=directory,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=False,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    #
    # Consumer generation
    gen_opts['generated_vulkan_consumer.h'] = [
        VulkanConsumerHeaderGenerator,
        VulkanConsumerHeaderGeneratorOptions(
            class_name='VulkanConsumer',
            base_class_header='vulkan_consumer_base.h',
            is_override=False,
            filename='generated_vulkan_consumer.h',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=True,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_cpp_consumer.h'] = [
        VulkanConsumerHeaderGenerator,
        VulkanConsumerHeaderGeneratorOptions(
        class_name         = 'VulkanCppConsumer',
        base_class_header   = 'vulkan_cpp_consumer_base.h',
        is_override        = True,
        filename          = 'generated_vulkan_cpp_consumer.h',
        directory         = directory,
        blacklists        = blacklists,
        platform_types     = platform_types,
        prefix_text        = prefix_strings + vk_prefix_strings,
        protect_file       = True,
        protect_feature    = False)
    ]

    gen_opts['generated_vulkan_referenced_resource_consumer.h'] = [
        VulkanReferencedResourceHeaderGenerator,
        VulkanReferencedResourceHeaderGeneratorOptions(
            filename='generated_vulkan_referenced_resource_consumer.h',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=True,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_replay_consumer.h'] = [
        VulkanConsumerHeaderGenerator,
        VulkanConsumerHeaderGeneratorOptions(
            class_name='VulkanReplayConsumer',
            base_class_header='vulkan_replay_consumer_base.h',
            is_override=True,
            constructor_args=
            'std::shared_ptr<application::Application> application, const VulkanReplayOptions& options',
            filename='generated_vulkan_replay_consumer.h',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=True,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_cpp_consumer.h'] = [
        VulkanCppConsumerHeaderGenerator,
        VulkanCppConsumerHeaderGeneratorOptions(
        class_name         = 'VulkanCppConsumer',
        base_class_header  = 'vulkan_cpp_consumer_base.h',
        is_override        = True,
        filename           = 'generated_vulkan_cpp_consumer.h',
        directory          = directory,
        blacklists         = blacklists,
        platform_types     = platform_types,
        prefix_text        = prefix_strings + vk_prefix_strings,
        protect_file       = True,
        protect_feature    = False)
    ]

    gen_opts['generated_vulkan_cpp_consumer.cpp'] = [
        VulkanCppConsumerBodyGenerator,
        VulkanCppConsumerBodyGeneratorOptions(
            filename           = 'generated_vulkan_cpp_consumer.cpp',
            directory          = directory,
            blacklists         = blacklists,
            platform_types     = platform_types,
            prefix_text        = prefix_strings + vk_prefix_strings,
            protect_file       = False,
            protect_feature    = False,
            extraVulkanHeaders=extraVulkanHeaders)
    ]

    gen_opts['generated_vulkan_cpp_structs.h'] = [
        VulkanCppStructGenerator,
        VulkanCppStructGeneratorOptions(
            filename           = 'generated_vulkan_cpp_structs.h',
            directory          = directory,
            blacklists         = blacklists,
            platform_types     = platform_types,
            prefix_text        = prefix_strings + vk_prefix_strings,
            protect_file       = True,
            protect_feature    = False)
    ]

    gen_opts['generated_vulkan_cpp_structs.cpp'] = [
        VulkanCppStructGenerator,
        VulkanCppStructGeneratorOptions(
            filename          = 'generated_vulkan_cpp_structs.cpp',
            directory         = directory,
            blacklists        = blacklists,
            platform_types     = platform_types,
            prefix_text        = prefix_strings + vk_prefix_strings,
            protect_file       = False,
            protect_feature    = False)
    ]

    gen_opts['generated_vulkan_cpp_consumer_extension.h'] = [
        VulkanCppConsumerExtensionGenerator,
        VulkanCppConsumerExtensionGeneratorOptions(
            filename          = 'generated_vulkan_cpp_consumer_extension.h',
            directory         = directory,
            blacklists        = blacklists,
            platform_types     = platform_types,
            prefix_text        = prefix_strings + vk_prefix_strings,
            protect_file       = True,
            protect_feature    = False)
    ]

    gen_opts['generated_vulkan_cpp_consumer_extension.cpp'] = [
        VulkanCppConsumerExtensionGenerator,
        VulkanCppConsumerExtensionGeneratorOptions(
            filename          = 'generated_vulkan_cpp_consumer_extension.cpp',
            directory         = directory,
            blacklists        = blacklists,
            platform_types     = platform_types,
            prefix_text        = prefix_strings + vk_prefix_strings,
            protect_file       = False,
            protect_feature    = False)
    ]

    gen_opts['generated_vulkan_replay_consumer.cpp'] = [
        VulkanReplayConsumerBodyGenerator,
        VulkanReplayConsumerBodyGeneratorOptions(
            filename='generated_vulkan_replay_consumer.cpp',
            directory=directory,
            blacklists=blacklists,
            replay_overrides=replay_overrides,
            dump_resources_overrides=dump_resources_overrides,
            platform_types=platform_types,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=False,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_replay_dump_resources.cpp'] = [
        VulkanReplayDumpResourcesBodyGenerator,
        VulkanReplayDumpResourcesBodyGeneratorOptions(
            filename='generated_vulkan_replay_dump_resources.cpp',
            directory=directory,
            blacklists=None,
            dump_resources_overrides=dump_resources_overrides,
            platform_types=platform_types,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=False,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_replay_dump_resources.h'] = [
        VulkanReplayDumpResourcesHeaderGenerator,
        VulkanReplayDumpResourcesHeaderGeneratorOptions(
            class_name='VulkanReplayDumpResources',
            base_class_header='vulkan_replay_dump_resources.h',
            is_override=True,
            constructor_args=
            'const VulkanReplayOptions& options, CommonObjectInfoTable& object_info_table',
            filename='generated_vulkan_replay_dump_resources.h',
            directory=directory,
            blacklists=None,
            dump_resources_overrides=dump_resources_overrides,
            platform_types=platform_types,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=True,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_referenced_resource_consumer.cpp'] = [
        VulkanReferencedResourceBodyGenerator,
        VulkanReferencedResourceBodyGeneratorOptions(
            filename='generated_vulkan_referenced_resource_consumer.cpp',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=False,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_struct_handle_mappers.h'] = [
        VulkanStructHandleMappersHeaderGenerator,
        VulkanStructHandleMappersHeaderGeneratorOptions(
            filename='generated_vulkan_struct_handle_mappers.h',
            directory=directory,
            blacklists=blacklists,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=True,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_struct_handle_mappers.cpp'] = [
        VulkanStructHandleMappersBodyGenerator,
        VulkanStructHandleMappersBodyGeneratorOptions(
            filename='generated_vulkan_struct_handle_mappers.cpp',
            directory=directory,
            blacklists=blacklists,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=False,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_feature_util.cpp'] = [
        VulkanFeatureUtilBodyGenerator,
        VulkanFeatureUtilBodyGeneratorOptions(
            filename='generated_vulkan_feature_util.cpp',
            directory=directory,
            platform_types=platform_types,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=False,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    #
    # API call encoder generators
    gen_opts['generated_vulkan_api_call_encoders.h'] = [
        VulkanApiCallEncodersHeaderGenerator,
        VulkanApiCallEncodersHeaderGeneratorOptions(
            filename='generated_vulkan_api_call_encoders.h',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=True,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_api_call_encoders.cpp'] = [
        VulkanApiCallEncodersBodyGenerator,
        VulkanApiCallEncodersBodyGeneratorOptions(
            filename='generated_vulkan_api_call_encoders.cpp',
            directory=directory,
            blacklists=blacklists,
            capture_overrides=capture_overrides,
            platform_types=platform_types,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=False,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_command_buffer_util.h'] = [
        VulkanCommandBufferUtilHeaderGenerator,
        VulkanCommandBufferUtilHeaderGeneratorOptions(
            filename='generated_vulkan_command_buffer_util.h',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=True,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_command_buffer_util.cpp'] = [
        VulkanCommandBufferUtilBodyGenerator,
        VulkanCommandBufferUtilBodyGeneratorOptions(
            filename='generated_vulkan_command_buffer_util.cpp',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=False,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_dispatch_table.h'] = [
        VulkanDispatchTableGenerator,
        VulkanDispatchTableGeneratorOptions(
            filename='generated_vulkan_dispatch_table.h',
            directory=directory,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=True,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_layer_func_table.h'] = [
        LayerFuncTableGenerator,
        LayerFuncTableGeneratorOptions(
            filename='generated_layer_func_table.h',
            directory=directory,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=True,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    #
    # Struct encoder generators
    gen_opts['generated_vulkan_struct_encoders.cpp'] = [
        VulkanStructEncodersBodyGenerator,
        VulkanStructEncodersBodyGeneratorOptions(
            filename='generated_vulkan_struct_encoders.cpp',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=False,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_struct_encoders.h'] = [
        VulkanStructEncodersHeaderGenerator,
        VulkanStructEncodersHeaderGeneratorOptions(
            filename='generated_vulkan_struct_encoders.h',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=True,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_encode_pnext_struct.cpp'] = [
        EncodePNextStructGenerator,
        EncodePNextStructGeneratorOptions(
            filename='generated_encode_pnext_struct.cpp',
            directory=directory,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=False,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_struct_handle_wrappers.h'] = [
        VulkanStructHandleWrappersHeaderGenerator,
        VulkanStructHandleWrappersHeaderGeneratorOptions(
            filename='generated_vulkan_struct_handle_wrappers.h',
            directory=directory,
            blacklists=blacklists,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=True,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_struct_handle_wrappers.cpp'] = [
        VulkanStructHandleWrappersBodyGenerator,
        VulkanStructHandleWrappersBodyGeneratorOptions(
            filename='generated_vulkan_struct_handle_wrappers.cpp',
            directory=directory,
            blacklists=blacklists,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=False,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_struct_trackers.h'] = [
        VulkanStructTrackersHeaderGenerator,
        VulkanStructTrackersHeaderGeneratorOptions(
            filename='generated_vulkan_struct_trackers.h',
            directory=directory,
            blacklists=blacklists,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=False,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_struct_trackers.cpp'] = [
        VulkanStructTrackersBodyGenerator,
        VulkanStructTrackersBodyGeneratorOptions(
            filename='generated_vulkan_struct_trackers.cpp',
            directory=directory,
            blacklists=blacklists,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=False,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    #
    # To string generators
    gen_opts['generated_vulkan_enum_to_string.h'] = [
        VulkanEnumToStringHeaderGenerator,
        VulkanEnumToStringHeaderGeneratorOptions(
            filename='generated_vulkan_enum_to_string.h',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=True,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_enum_to_string.cpp'] = [
        VulkanEnumToStringBodyGenerator,
        VulkanEnumToStringBodyGeneratorOptions(
            filename='generated_vulkan_enum_to_string.cpp',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=False,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_object_info_table_base2.h'] = [
        VulkanObjectInfoTableBase2HeaderGenerator,
        VulkanObjectInfoTableBase2HeaderGeneratorOptions(
            filename='generated_vulkan_object_info_table_base2.h',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=True,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_state_table.h'] = [
        VulkanStateTableHeaderGenerator,
        VulkanStateTableHeaderGeneratorOptions(
            filename='generated_vulkan_state_table.h',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=True,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_json_consumer.h'] = [
        VulkanExportJsonConsumerHeaderGenerator,
        VulkanExportJsonConsumerHeaderGeneratorOptions(
            class_name='VulkanExportJsonConsumer',
            base_class_header='vulkan_json_consumer_base.h',
            is_override=True,
            filename='generated_vulkan_json_consumer.h',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=True,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_json_consumer.cpp'] = [
        VulkanExportJsonConsumerBodyGenerator,
        VulkanExportJsonConsumerBodyGeneratorOptions(
            filename='generated_vulkan_json_consumer.cpp',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=False,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_struct_to_json.h'] = [
        VulkanStructToJsonHeaderGenerator,
        VulkanStructToJsonHeaderGeneratorOptions(
            filename='generated_vulkan_struct_to_json.h',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=True,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_struct_to_json.cpp'] = [
        VulkanStructToJsonBodyGenerator,
        VulkanStructToJsonBodyGeneratorOptions(
            filename='generated_vulkan_struct_to_json.cpp',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=False,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_enum_to_json.h'] = [
        VulkanEnumToJsonHeaderGenerator,
        VulkanEnumToJsonHeaderGeneratorOptions(
            filename='generated_vulkan_enum_to_json.h',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefixText=prefix_strings + vk_prefix_strings,
            protectFile=True,
            protectFeature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_enum_to_json.cpp'] = [
        VulkanEnumToJsonBodyGenerator,
        VulkanEnumToJsonBodyGeneratorOptions(
            filename='generated_vulkan_enum_to_json.cpp',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefixText=prefix_strings + vk_prefix_strings,
            protectFile=False,
            protectFeature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_constant_maps.h'] = [
        VulkanConstantMapsGenerator,
        VulkanConstantMapsGeneratorOptions(
            filename='generated_vulkan_constant_maps.h',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=True,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

    gen_opts['generated_vulkan_stype_util.h'] = [
        VulkanSTypeUtilGenerator,
        VulkanSTypeUtilGeneratorOptions(
            filename='generated_vulkan_stype_util.h',
            directory=directory,
            blacklists=blacklists,
            platform_types=platform_types,
            prefix_text=prefix_strings + vk_prefix_strings,
            protect_file=True,
            protect_feature=False,
            extraVulkanHeaders=extraVulkanHeaders
        )
    ]

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
        default='vk.xml',
        help='Use specified registry file instead of vk.xml'
    )
    parser.add_argument(
        '-video',
        action='store',
        default='video.xml',
        help='Use specified video file instead of video.xml'
    )
    parser.add_argument(
        '-headers-dir',
        dest='headers_dir',
        action='store',
        default=None,
        help='\n'.join(
            [
                'Path to a directory that holds additional Vulkan header files required to build.',
                'These header files are included directly after the Vulkan header in all generated files.'
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
    gen.VIDEO_TREE = etree.parse(args.video)
    end_timer(args.time, '* Time to make ElementTree =')

    # Apply any temporary patches to the xml to allow correct code generation
    # from it. These should be reviewed and removed when the xml is fixed upstream.
    start_timer(args.time)
    # There are no current patches needed, but here is an example of how to patch the XML
    # after parsing to add a missing single attribute:
    # Workaround 1.3.264 VkFrameBoundaryEXT.pTag lacking len field:
    # <https://github.com/KhronosGroup/Vulkan-Docs/pull/2240>
    # if ptag_member := tree.find('types/type[@name="VkFrameBoundaryEXT"]/member[name="pTag"]'):
    #    ptag_member.set('len', 'tagSize')
    end_timer(args.time, '* Time to patch ElementTree =')

    # Extend the vk.xml tree with XML files from the config dir
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
