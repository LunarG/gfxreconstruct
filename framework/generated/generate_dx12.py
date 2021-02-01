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

# Relative path to dxgi code generators for trace encode/decode.
GENERATOR_PATH = './dx12_generators'
LIB_CPPHEADERPARSER_PATH = '../../external'
LIB_REGISTRY_PATH = '../../external/Vulkan-Headers/registry'
VULKAN_GENERATOR_PATH = './vulkan_generators'
BASE_GENERATOR_PATH = './base_generators'

# File names to provide to the dxgi generator script.
GENERATE_TARGETS = [
    'generated_dx12_api_call_encoders.h',
    'generated_dx12_api_call_encoders.cpp',
    'generated_dx12_decoder.h',
    'generated_dx12_decoder.cpp',
    'generated_dx12_struct_decoders_forward.h',
    'generated_dx12_struct_decoders.h',
    'generated_dx12_struct_decoders.cpp',
    'generated_dx12_consumer.h',
    'generated_dx12_replay_consumer.h',
    'generated_dx12_replay_consumer.cpp',
    'generated_dx12_ascii_consumer.h',
    'generated_dx12_ascii_consumer.cpp',
]

DX12_SOURCE_LIST = [
    'shared\\dxgi.h',
    'shared\\dxgi1_2.h',
    'shared\\dxgi1_3.h',
    'shared\\dxgi1_4.h',
    'shared\\dxgi1_5.h',
    'shared\\dxgi1_6.h',
    'shared\\dxgicommon.h',
    'shared\\dxgiformat.h',
    'shared\\dxgitype.h',
    'um\\d3d12.h',
    'um\\d3dcommon.h',
]

# The second value is required data. It only generates required data.
WINAPI_SOURCE_LIST = [
    ['um\\Unknwnbase.h', ['IUnknown']],
    ['shared\\guiddef.h', ['GUID']],
    ['shared\\windef.h', ['tagRECT', 'tagPOINT']],
    ['um\\minwinbase.h', ['_SECURITY_ATTRIBUTES']],
]


class CppHeader():
    def __init__(self):
        self.classes = {}
        self.functions = []
        self.enums = []


if __name__ == '__main__':
    env = os.environ
    env['PYTHONPATH'] = os.pathsep.join(sys.path)

    if 'WindowsSDKVersion' in env:
        WINDOWS_SDK_VERSION = env['WindowsSDKVersion']
    else:
        print('Please run in Visual Studio Developer Command Prompt to get environment variables, WindowsSDKVersion and WindowsSdkDir')  # noqa
        input("Press Enter to continue...")
        sys.exit()

    if 'WindowsSdkDir' in env:
        WINDOWS_SDK_DIR = env['WindowsSdkDir']

    CURRENT_DIR = os.path.dirname(os.path.abspath(sys.argv[0]))
    GENERATOR_DIR = os.path.normpath(os.path.join(CURRENT_DIR, GENERATOR_PATH))
    BASE_GENERATOR_DIR = os.path.normpath(
        os.path.join(CURRENT_DIR, BASE_GENERATOR_PATH))
    VULKAN_GENERATOR_DIR = os.path.normpath(
        os.path.join(CURRENT_DIR, VULKAN_GENERATOR_PATH))
    LIB_REGISTRY_DIR = os.path.normpath(
        os.path.join(CURRENT_DIR, LIB_REGISTRY_PATH))
    LIB_CPPHEADERPARSER_DIR = os.path.normpath(
        os.path.join(CURRENT_DIR, LIB_CPPHEADERPARSER_PATH))

    sys.path.append(GENERATOR_DIR)
    sys.path.append(BASE_GENERATOR_DIR)
    sys.path.append(VULKAN_GENERATOR_DIR)
    sys.path.append(LIB_REGISTRY_DIR)
    sys.path.append(LIB_CPPHEADERPARSER_DIR)

    from gencode import GenCode
    from dx12_generators.dx12_CppHeaderParser import DX12CppHeader

    header_dict = {}
    for source in DX12_SOURCE_LIST:
        source_file = os.path.join(WINDOWS_SDK_DIR + 'Include\\'
                                   + WINDOWS_SDK_VERSION, source)
        print('Parsing', source_file)
        header_dict[source[source.find('\\') +
                           1:]] = DX12CppHeader(source_file)

    for source in WINAPI_SOURCE_LIST:
        source_file = os.path.join(WINDOWS_SDK_DIR + 'Include\\'
                                   + WINDOWS_SDK_VERSION, source[0])
        print('Parsing', source_file)
        header = DX12CppHeader(source_file)
        header1 = CppHeader()

        for k, v in header.classes.items():
            if k in source[1]:
                # print('    Find out', k)
                header1.classes[k] = v

        for enum in header.enums:
            if enum['name'] in source[1]:
                # print('    Find out', enum['name'])
                header1.enums.append(enum)

        header_dict[source[0][source[0].find('\\') + 1:]] = header1

    union_dict = dict()
    enum_set = set()
    class_list = list()
    struct_list = list()

    for k, v in header_dict.items():
        for k2 in list(v.classes):
            v2 = v.classes[k2]
            if v2['declaration_method'] == 'struct' and k2[-4:] != 'Vtbl'\
               and k2.find("::<anon-union-") == -1:
                if k2 in struct_list:
                    # print('WARNING:', k2, 'is duplicated.')
                    del v.classes[k2]
                else:
                    struct_list.append(k2)

            elif v2['declaration_method'] == 'union':
                union_dict[v2['name']] = v2

            elif v2['declaration_method'] == 'class':
                class_list.append(k2)

        for enum in v.enums:
            enum_set.add(enum['name'])

    source_dict = dict()
    source_dict['header_dict'] = header_dict
    source_dict['union_dict'] = union_dict
    source_dict['enum_set'] = enum_set
    source_dict['class_list'] = class_list
    source_dict['struct_list'] = struct_list

    for target in GENERATE_TARGETS:
        print('Generating', target)
        thread = GenCode(target, source_dict, WINDOWS_SDK_VERSION[:-1],
                         CURRENT_DIR, GENERATOR_DIR)
        thread.start()
