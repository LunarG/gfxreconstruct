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

# File names to provide to the Vulkan XML Registry generator script.
generate_targets = [
    'generated_encode_pnext_struct.inc',
    'generated_struct_encoders.inc',
    'generated_api_call_encoders.inc',
    'generated_layer_func_table.inc',
    'generated_decoded_struct_types.inc',
    'generated_struct_decoders.inc',
    'generated_struct_decoder_declarations.inc',
    'generated_api_call_decoders.inc',
    'generated_api_call_decoder_declarations.inc',
    'generated_api_call_decode_cases.inc',
    'generated_decode_pnext_struct.inc',
    'generated_api_call_consumer_declarations.inc',
    'generated_api_call_ascii_consumer_declarations.inc',
    'generated_api_call_ascii_consumer_definitions.inc'
]

if __name__ == '__main__':
    script_path = os.path.abspath(sys.argv[0])
    script_dir = os.path.dirname(script_path)
    registry_dir = os.path.normpath(os.path.join(script_dir, registry_path))

    sys.path.append(registry_dir)

    env = os.environ
    env['PYTHONPATH'] = os.pathsep.join(sys.path)

    for target in generate_targets:
        print('\nGenerating', target)
        subprocess.call([sys.executable, os.path.join(script_dir, 'genlayer.py'), '-registry', os.path.join(registry_dir, 'vk.xml'), target], shell=False, env=env)
