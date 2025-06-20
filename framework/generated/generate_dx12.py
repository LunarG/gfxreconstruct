#!/usr/bin/env python3
#
# Copyright (c) 2021-2025 LunarG, Inc.
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
SCRIPT_DIR = os.path.abspath(os.path.dirname(__file__))

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
    'generated_dx12_json_consumer.h',
    'generated_dx12_json_consumer.cpp',
    'generated_dx12_wrappers.h',
    'generated_dx12_wrappers.cpp',
    'generated_dx12_wrapper_creators.h',
    'generated_dx12_wrapper_creators.cpp',
    'generated_dx12_struct_unwrappers.h',
    'generated_dx12_struct_unwrappers.cpp',
    'generated_dx12_struct_object_mappers.h',
    'generated_dx12_struct_object_mappers.cpp',
    'generated_dx12_struct_wrappers.h',
    'generated_dx12_struct_wrappers.cpp',
    'generated_dx12_add_entries.h',
    'generated_dx12_state_table.h',
    'generated_dx12_command_list_util.h',
    'generated_dx12_command_list_util.cpp',
    'generated_dx12_enum_to_string.h',
    'generated_dx12_enum_to_string.cpp',
    'generated_dx12_enum_to_json.h',
    'generated_dx12_struct_decoders_to_json.h',
    'generated_dx12_struct_decoders_to_json.cpp',
    'generated_dx12_call_id_to_string.h',
]

WINDOWS_SDK_SOURCE_LIST = [
    'shared\\dxgi.h',
    'shared\\dxgi1_2.h',
    'shared\\dxgi1_3.h',
    'shared\\dxgi1_4.h',
    'shared\\dxgi1_5.h',
    'shared\\dxgi1_6.h',
    'shared\\dxgicommon.h',
    'shared\\dxgitype.h',
]

AGILITY_SDK_SOURCE_LIST = [
    'dxgiformat.h', # Use from AgilitySDK, instead of WindowsSDK.
    'd3d12.h',
    'd3dcommon.h',
    'd3d12sdklayers.h',
]

# The second value is required data. It only generates required data.
WINAPI_SOURCE_LIST = [
    ['um\\Unknwnbase.h', ['IUnknown']],
    ['shared\\guiddef.h', ['GUID']],
    ['shared\\windef.h', ['tagRECT', 'tagPOINT']],
    ['um\\minwinbase.h', ['_SECURITY_ATTRIBUTES']],
]

if __name__ == '__main__':
    env = os.environ
    env['PYTHONPATH'] = os.pathsep.join(sys.path)

    if 'WindowsSDKVersion' in env:
        WINDOWS_SDK_VERSION = env['WindowsSDKVersion']
        print('WindowsSDKVersion = "%s"' % WINDOWS_SDK_VERSION)
    else:
        print(
            'Please run in Visual Studio Developer Command Prompt to get environment variables, WindowsSDKVersion and WindowsSdkDir'
        )
        input("Press Enter to continue...")
        sys.exit()

    if 'WindowsSdkDir' in env:
        WINDOWS_SDK_DIR = env['WindowsSdkDir']

    CURRENT_DIR = os.path.dirname(os.path.abspath(sys.argv[0]))
    GENERATOR_DIR = os.path.normpath(os.path.join(CURRENT_DIR, GENERATOR_PATH))
    LIB_CPPHEADERPARSER_DIR = os.path.normpath(
        os.path.join(CURRENT_DIR, LIB_CPPHEADERPARSER_PATH)
    )

    sys.path.append(GENERATOR_DIR)
    sys.path.append(LIB_CPPHEADERPARSER_DIR)

    from gencode import GenCode
    from dx12_generators.dx12_CppHeaderParser import Dx12CppHeader, Dx12CppClass

    header_dict = {}
    # Deal with DX12 first, and then DXGI. It will include <dxgiformat.h> before include dxgi headers.
    # If include dxgi headers first, it will use WindowsSDK's dxgiformat.h, instead of AgilitySDK's.
    # Because some dxgi headers could include dxgiformat.h that is from Windows SDK.
    # After it includes Windows SDK's dxgiformat.h, it will skip AgilitySDK's.
    for source in AGILITY_SDK_SOURCE_LIST:
        source_file = os.path.join(SCRIPT_DIR, '..', '..', 'external', 'AgilitySDK', 'include', source)

        print('Parsing', source_file)
        header_dict[source[source.find('\\') + 1:]] = Dx12CppHeader(source_file)

    for source in WINDOWS_SDK_SOURCE_LIST:
        source_file = os.path.join(
            WINDOWS_SDK_DIR + 'Include\\' + WINDOWS_SDK_VERSION, source
        )
        print('Parsing', source_file)
        header_dict[source[source.find('\\') + 1:]
                    ] = Dx12CppHeader(source_file)

    for source in WINAPI_SOURCE_LIST:
        source_file = os.path.join(
            WINDOWS_SDK_DIR + 'Include\\' + WINDOWS_SDK_VERSION, source[0]
        )
        print('Parsing', source_file)
        header = Dx12CppHeader(source_file)
        header1 = Dx12CppClass()

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
    enum_dict = dict()
    class_dict = dict()
    struct_dict = dict()

    for k, v in header_dict.items():
        for class_name in list(v.classes):
            class_value = v.classes[class_name]
            if (
                class_value['declaration_method'] == 'struct'
                and class_name[-4:] != 'Vtbl'
                and class_name.find("::<anon-union-") == -1
            ):
                if class_name in struct_dict:
                    # print('WARNING:', class_name, 'is duplicated.')
                    del v.classes[class_name]
                else:
                    struct_dict[class_name] = class_value

            elif class_value['declaration_method'] == 'union':
                union_dict[class_value['name']] = class_value

            elif class_value['declaration_method'] == 'class':
                class_dict[class_name] = class_value

        for enum in v.enums:
            enum_dict[enum['name']] = enum

    source_dict = dict()
    source_dict['header_dict'] = header_dict
    source_dict['union_dict'] = union_dict
    source_dict['enum_dict'] = enum_dict
    source_dict['class_dict'] = class_dict
    source_dict['struct_dict'] = struct_dict

    for target in GENERATE_TARGETS:
        print('Generating', target)
        GenCode(
            target, source_dict, WINDOWS_SDK_VERSION[:-1], CURRENT_DIR,
            GENERATOR_DIR
        )
