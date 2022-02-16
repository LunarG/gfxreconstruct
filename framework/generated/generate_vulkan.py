#!/usr/bin/env python3
#
# Copyright (c) 2018 Valve Corporation
# Copyright (c) 2018 LunarG, Inc.
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
'''Generate GFXR Vulkan framework source code
'''

import argparse
import os
import sys
import subprocess

SCRIPT_DIR = os.path.abspath(os.path.dirname(__file__))
KHRONOS_REGISTRY_DIR = os.path.normpath(
    os.path.join(
        SCRIPT_DIR, '..', '..', 'external', 'Vulkan-Headers', 'registry'
    )
)
BASE_GENERATOR_DIR = os.path.join(SCRIPT_DIR, 'base_generators')
GENERATOR_DIR = os.path.join(SCRIPT_DIR, 'vulkan_generators')
VK_HEADERS_DIR = os.path.join(
    SCRIPT_DIR, '..', '..', 'external', 'Vulkan-Headers'
)

# File names to provide to the Vulkan XML Registry generator script.
generate_targets = [
    'generated_encode_pnext_struct.cpp', 'generated_vulkan_struct_encoders.h',
    'generated_vulkan_struct_encoders.cpp',
    'generated_vulkan_struct_handle_wrappers.h',
    'generated_vulkan_struct_handle_wrappers.cpp',
    'generated_vulkan_api_call_encoders.h',
    'generated_vulkan_api_call_encoders.cpp',
    'generated_vulkan_command_buffer_util.h',
    'generated_vulkan_command_buffer_util.cpp',
    'generated_vulkan_dispatch_table.h', 'generated_layer_func_table.h',
    'generated_vulkan_struct_decoders.h',
    'generated_vulkan_struct_decoders.cpp',
    'generated_vulkan_struct_decoders_forward.h', 'generated_vulkan_decoder.h',
    'generated_vulkan_decoder.cpp', 'generated_decode_pnext_struct.cpp',
    'generated_vulkan_consumer.h', 'generated_vulkan_ascii_consumer.h',
    'generated_vulkan_ascii_consumer.cpp',
    'generated_vulkan_replay_consumer.h',
    'generated_vulkan_replay_consumer.cpp',
    'generated_vulkan_referenced_resource_consumer.h',
    'generated_vulkan_referenced_resource_consumer.cpp',
    'generated_vulkan_struct_handle_mappers.h',
    'generated_vulkan_struct_handle_mappers.cpp',
    'generated_vulkan_feature_util.cpp', 'generated_vulkan_enum_to_string.h',
    'generated_vulkan_enum_to_string.cpp',
    'generated_vulkan_pnext_to_string.cpp',
    'generated_vulkan_struct_to_string.h',
    'generated_vulkan_struct_to_string.cpp',
    'generated_vulkan_object_info_table_base2.h',
    'generated_vulkan_state_table.h'
]

if __name__ == '__main__':
    arg_parser = argparse.ArgumentParser(description=__doc__)
    arg_parser.add_argument(
        '--registry-dir',
        dest='registry_dir',
        default=None,
        help='\n'.join(
            [
                'Path to a directory that holds the Vulkan registry file (vk.xml) used to generate Vulkan source.',
                'If this option is not provide the registry from the external Khronos Vulkan headers sub module will be used.'
            ]
        )
    )
    arg_parser.add_argument(
        '--headers-dir',
        dest='headers_dir',
        default=None,
        help='\n'.join(
            [
                'Path to a directory that holds additional Vulkan header files required to build.',
                'These header files are included directly after the Vulkan header in all generated files.',
                'All .h file under the given directory are assumed to be Vulkan headers.'
            ]
        )
    )
    args = arg_parser.parse_args()
    registry_dir = KHRONOS_REGISTRY_DIR
    if args.registry_dir is not None:
        registry_dir = os.path.abspath(args.registry_dir)
    registry_path = os.path.join(registry_dir, 'vk.xml')
    if not os.path.isfile(registry_path):
        raise Exception(f'Error: {registry_path} does not exist')
    BASE_GENERATOR_DIR = os.path.normpath(
        os.path.join(SCRIPT_DIR, BASE_GENERATOR_DIR)
    )
    env = os.environ.copy()
    if not 'PYTHONPATH' in env:
        env['PYTHONPATH'] = ''
    env['PYTHONPATH'] = os.pathsep.join(
        [
            KHRONOS_REGISTRY_DIR,
            BASE_GENERATOR_DIR,
            GENERATOR_DIR,
            VK_HEADERS_DIR,
        ]
    )
    for target in generate_targets:
        print('Generating', target)
        gencode_args = [
            sys.executable,
            os.path.join(GENERATOR_DIR, 'gencode.py'),
            '-o',
            SCRIPT_DIR,
            '-configs',
            GENERATOR_DIR,
            '-registry',
            registry_path,
        ]
        if args.headers_dir is not None:
            if not os.path.isdir(args.headers_dir):
                raise Exception(
                    'Error: extra headers dir', args.headers_dir,
                    'is not a directory'
                )
            gencode_args.extend(
                ['-headers-dir',
                 os.path.abspath(args.headers_dir)]
            )
        gencode_args.append(target)
        subprocess.call(
            gencode_args,
            shell=False,
            env=env,
            cwd=SCRIPT_DIR,
        )
