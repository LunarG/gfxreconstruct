#!/usr/bin/env python
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

import os
import sys
import subprocess

# Relative path from code generators to directory containing the Vulkan XML Registry.
registry_path = '../../external/Vulkan-Headers/registry'

# Relative path to vulkan code generators for trace encode/decode.
generator_path = './vulkan_generators'

base_generator_path = './base_generators'

# File names to provide to the Vulkan XML Registry generator script.
generate_targets = [
    'generated_encode_pnext_struct.cpp',
    'generated_vulkan_struct_encoders.h',
    'generated_vulkan_struct_encoders.cpp',
    'generated_vulkan_struct_handle_wrappers.h',
    'generated_vulkan_struct_handle_wrappers.cpp',
    'generated_vulkan_api_call_encoders.h',
    'generated_vulkan_api_call_encoders.cpp',
    'generated_vulkan_command_buffer_util.h',
    'generated_vulkan_command_buffer_util.cpp',
    'generated_vulkan_dispatch_table.h',
    'generated_layer_func_table.h',
    'generated_vulkan_struct_decoders.h',
    'generated_vulkan_struct_decoders.cpp',
    'generated_vulkan_struct_decoders_forward.h',
    'generated_vulkan_decoder.h',
    'generated_vulkan_decoder.cpp',
    'generated_decode_pnext_struct.cpp',
    'generated_vulkan_consumer.h',
    'generated_vulkan_ascii_consumer.h',
    'generated_vulkan_ascii_consumer.cpp',
    'generated_vulkan_replay_consumer.h',
    'generated_vulkan_replay_consumer.cpp',
    'generated_vulkan_referenced_resource_consumer.h',
    'generated_vulkan_referenced_resource_consumer.cpp',
    'generated_vulkan_struct_handle_mappers.h',
    'generated_vulkan_struct_handle_mappers.cpp',
    'generated_vulkan_feature_util.cpp'
]

if __name__ == '__main__':
    current_dir = os.path.dirname(os.path.abspath(sys.argv[0]))
    generator_dir = os.path.normpath(os.path.join(current_dir, generator_path))
    registry_dir = os.path.normpath(os.path.join(current_dir, registry_path))

    base_generator_dir = os.path.normpath(
        os.path.join(current_dir, base_generator_path))

    sys.path.append(base_generator_dir)

    sys.path.append(generator_dir)
    sys.path.append(registry_dir)

    env = os.environ
    env['PYTHONPATH'] = os.pathsep.join(sys.path)

    for target in generate_targets:
        print('Generating', target)
        subprocess.call([sys.executable, os.path.join(generator_dir, 'gencode.py'), '-o', current_dir, '-configs', generator_dir, '-registry', os.path.join(registry_dir, 'vk.xml'), target], shell=False, env=env)

