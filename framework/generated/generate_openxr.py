#!/usr/bin/env python3
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
'''Generate GFXR OpenXR framework source code
'''

import argparse
import os
import sys
import subprocess

SCRIPT_DIR = os.path.abspath(os.path.dirname(__file__))
XR_REGISTRY_DIR = os.path.normpath(
    os.path.join(
        SCRIPT_DIR, '..', '..', 'external', 'OpenXR-SDK', 'specification',
        'registry'
    )
)
XR_REGISTRY_SCRIPTS_DIR = os.path.normpath(
    os.path.join(
        SCRIPT_DIR, '..', '..', 'external', 'OpenXR-Docs', 'specification',
        'scripts'
    )
)
BASE_GENERATOR_DIR = os.path.join(SCRIPT_DIR, 'base_generators')
GENERATOR_DIR = os.path.join(SCRIPT_DIR, 'openxr_generators')
XR_HEADERS_DIR = os.path.join(SCRIPT_DIR, '..', '..', 'external', 'OpenXR-SDK')

# File names to provide to the OpenXR XML Registry generator script.
generate_targets = [
    'generated_openxr_dispatch_table.h',
    'generated_openxr_layer_func_table.h',
    'generated_openxr_api_call_encoders.h',
    'generated_openxr_api_call_encoders.cpp',
    'generated_openxr_enum_to_string.h',
    'generated_openxr_enum_to_string.cpp',
    'generated_openxr_state_table.h',
    'generated_openxr_struct_encoders.h',
    'generated_openxr_struct_encoders.cpp',
    'generated_openxr_struct_decoders.h',
    'generated_openxr_struct_decoders.cpp',
    'generated_openxr_struct_decoders_forward.h',
    'generated_openxr_struct_handle_wrappers.h',
    'generated_openxr_struct_handle_wrappers.cpp',
    'generated_openxr_struct_next_decoder.cpp',
    'generated_openxr_struct_next_encoder.cpp',
    'generated_openxr_struct_trackers.h',
    'generated_openxr_struct_trackers.cpp',
    'generated_openxr_type_util.h',
]

if __name__ == '__main__':
    arg_parser = argparse.ArgumentParser(description=__doc__)
    arg_parser.add_argument(
        '--registry-dir',
        dest='registry_dir',
        default=None,
        help='\n'.join(
            [
                'Path to a directory that holds the OpenXR registry file (xr.xml) used to generate OpenXR source.',
                'If this option is not provided the registry from the external Khronos OpenXR-SDK sub module will be used.'
            ]
        )
    )
    arg_parser.add_argument(
        '--registry-scripts-dir',
        dest='registry_scripts_dir',
        default=None,
        help='\n'.join(
            [
                'Path to a directory that holds the KhronosGroup scripts to process the OpenXRregistry file (xr.xml.',
                'If this option is not provided the registry from the external Khronos OpenXR-Docs sub module will be used.'
            ]
        )
    )
    arg_parser.add_argument(
        '--headers-dir',
        dest='headers_dir',
        default=None,
        help='\n'.join(
            [
                'Path to a directory that holds additional OpenXr header files required to build.',
                'These header files are included directly after the OpenXr header in all generated files.',
                'All .h file under the given directory are assumed to be OpenXr headers.'
            ]
        )
    )
    args = arg_parser.parse_args()

    registry_dir = XR_REGISTRY_DIR
    if args.registry_dir is not None:
        registry_dir = os.path.abspath(args.registry_dir)
    registry_path = os.path.join(registry_dir, 'xr.xml')
    if not os.path.isfile(registry_path):
        raise Exception(f'Error: {registry_path} does not exist')

    registry_scripts_dir = XR_REGISTRY_SCRIPTS_DIR
    if args.registry_scripts_dir is not None:
        registry_scripts_dir = os.path.abspath(args.registry_scripts_dir)
    script_file = os.path.join(registry_scripts_dir, 'reg.py')
    if not os.path.isfile(script_file):
        raise Exception(f'Error: {script_file} does not exist')

    BASE_GENERATOR_DIR = os.path.normpath(
        os.path.join(SCRIPT_DIR, BASE_GENERATOR_DIR)
    )
    env = os.environ.copy()
    if not 'PYTHONPATH' in env:
        env['PYTHONPATH'] = ''
    env['PYTHONPATH'] = os.pathsep.join(
        [
            registry_scripts_dir,
            BASE_GENERATOR_DIR,
            GENERATOR_DIR,
            XR_HEADERS_DIR,
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
            '-scripts',
            registry_scripts_dir,
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
