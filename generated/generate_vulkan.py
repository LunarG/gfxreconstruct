#!/usr/bin/env python
#
# Copyright (c) 2018 LunarG, Inc.
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

import os
import sys
import subprocess

# Relative path from code generators to directory containing the Vulkan XML Registry.
registry_path = '../external/Vulkan-Headers/registry'

# Relative path to vulkan code generators for trace encode/decode.
generator_path = './vulkan_generators'

# File names to provide to the Vulkan XML Registry generator script.
generate_targets = [
    'generated_encode_pnext_struct.cpp',
    'generated_struct_encoders.h',
    'generated_struct_encoders.cpp',
    'generated_api_call_encoders.h',
    'generated_api_call_encoders.cpp',
    'generated_layer_func_table.h',
    'generated_struct_decoders.h',
    'generated_struct_decoders.cpp',
    'generated_struct_decoders_forward.h',
    'generated_vulkan_decoder.h',
    'generated_vulkan_decoder.cpp',
    'generated_decode_pnext_struct.cpp',
    'generated_vulkan_consumer.h',
    'generated_vulkan_ascii_consumer.h',
    'generated_vulkan_replay_consumer.h',
    'generated_vulkan_ascii_consumer.cpp',
    'generated_vulkan_replay_consumer.cpp'
]

if __name__ == '__main__':
    current_dir = os.path.dirname(os.path.abspath(sys.argv[0]))
    generator_dir = os.path.normpath(os.path.join(current_dir, generator_path))
    registry_dir = os.path.normpath(os.path.join(current_dir, registry_path))

    sys.path.append(generator_dir)
    sys.path.append(registry_dir)

    env = os.environ
    env['PYTHONPATH'] = os.pathsep.join(sys.path)

    for target in generate_targets:
        print('\nGenerating', target)
        subprocess.call([sys.executable, os.path.join(generator_dir, 'gencode.py'), '-o', current_dir, '-configs', generator_dir, '-registry', os.path.join(registry_dir, 'vk.xml'), target], shell=False, env=env)
