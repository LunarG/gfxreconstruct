#!/usr/bin/python3 -i
#
# Copyright (c) 2021 Samsung
# Copyright (c) 2023 Google
# Copyright (c) 2023 LunarG
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

import re
import sys
from vulkan_base_generator import VulkanBaseGenerator, VulkanBaseGeneratorOptions, write
from vulkan_cpp_consumer_body_generator import \
    makeSnakeCaseName, makeGen, makeGenVar, makeGenVarCall, makeGenCond, makeGenConditions, \
    makeGenLoop, makeObjectType, makeOutStructSet, printOutStream

# Copyright text prefixing all headers (list of strings).
CPP_PREFIX_STRING = [
    '/*',
    '** Copyright (c) 2021 Samsung',
    '** Copyright (c) 2023 Google',
    '** Copyright (c) 2023 LunarG, Inc.',
    '**',
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
    '** DEALINGS IN THE SOFTWARE.',
    '*/',
    '',
    '/*',
    '** This file is generated from the Khronos Vulkan XML API Registry.',
    '**',
    '*/',
    ''
]
BasicStringConversionHandledTypes = [
    'char',
    'int',
    'int32_t',
    'float',
    'double',
    'size_t',
    'uint32_t',
    'uint16_t',
    'uint64_t',
    'void',
    'VkBool32',
    'VkDeviceSize',
    'VkDeviceAddress'
]

class VulkanCppStructGeneratorOptions(VulkanBaseGeneratorOptions):
    """Options for generating a C++ class for Vulkan capture file to CPP structure generation"""

    def __init__(
        self,
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text=CPP_PREFIX_STRING,
        protect_file=False,
        protect_feature=True,
        extra_headers=[]
    ):
        VulkanBaseGeneratorOptions.__init__(
            self,
            blacklists,
            platform_types,
            filename,
            directory,
            CPP_PREFIX_STRING,
            protect_file,
            protect_feature,
            extra_headers=extra_headers
        )

        self.is_header = self.filename.endswith(".h")
        if self.is_header:
            self.begin_end_file_data.specific_headers.append('util/defines.h')
        else:
            self.begin_end_file_data.specific_headers.extend((
                'decode/vulkan_cpp_structs.h',
                'generated/generated_vulkan_cpp_structs.h',
                'generated/generated_vulkan_cpp_consumer.h',
                'generated/generated_vulkan_cpp_consumer_extension.h',
                'generated/generated_vulkan_enum_to_string.h',
            ))
            self.begin_end_file_data.common_api_headers = []

        self.begin_end_file_data.namespaces.extend(('gfxrecon', 'decode'))

class VulkanCppStructGenerator(VulkanBaseGenerator):
    """VulkanCppStructGenerator - subclass of VulkanBaseGenerator.
    Generates vulkan struct generating functions.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
     ):
        VulkanBaseGenerator.__init__(
            self,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

        # Some structs are tracked like handles in the globalVar source so we only
        # need to properly initialize them, not define them.
        self.trackedStructs = [
            'VkMemoryRequirements2'
        ]

        self.overrideStructs = [
            'VkAndroidSurfaceCreateInfoKHR', # vkCreateAndroidSurfaceKHR, VK_KHR_ANDROID_SURFACE_EXTENSION_NAME
            'VkMetalSurfaceCreateInfoEXT',   # vkCreateMetalSurfaceEXT, VK_EXT_METAL_SURFACE_EXTENSION_NAME
            'VkWaylandSurfaceCreateInfoKHR', # vkCreateWaylandSurfaceKHR, VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME
            'VkWin32SurfaceCreateInfoKHR',   # vkCreateWin32SurfaceKHR, VK_KHR_WIN32_SURFACE_EXTENSION_NAME
            'VkXcbSurfaceCreateInfoKHR',     # vkCreateXcbSurfaceKHR, VK_KHR_XCB_SURFACE_EXTENSION_NAME
            'VkXlibSurfaceCreateInfoKHR',    # vkCreateXlibSurfaceKHR, VK_KHR_XLIB_SURFACE_EXTENSION_NAME
        ]

        self.CUSTOM_GENERATE_STRUCT = [
            # Core API - Alphabetical
            'VkBaseInStructure',
            'VkBaseOutStructure',
            'VkBindSparseInfo',
            'VkClearColorValue',
            'VkDescriptorImageInfo',
            'VkDescriptorUpdateTemplateCreateInfoKHR',
            'VkDescriptorUpdateTemplateEntry',
            'VkInstanceCreateInfo',
            'VkMemoryAllocateFlagsInfo',
            'VkMemoryAllocateInfo',
            'VkPresentInfoKHR',
            'VkSubmitInfo',
            'VkSubmitInfo2',
            'VkSwapchainCreateInfoKHR',
            'VkWriteDescriptorSet',

            # EXT
            'VkDebugUtilsMessengerCreateInfoEXT',
            'VkImportMemoryHostPointerInfoEXT',

            # Other extensions
            'VkAccelerationStructureMotionInstanceNV',
            'VkImportAndroidHardwareBufferInfoANDROID',
        ]

        self.LOCAL_STRUCT_BLACKLIST = [
            'SECURITY_ATTRIBUTES',
            'GUID'
        ]

        self.next_index = 0

    def writeout(self, *args, **kwargs):
        write(*args, **kwargs, file=self.outFile)

    def newline(self):
        write('', file=self.outFile)

    def generateTodoFor(self, argName, indent):
        return printOutStream(['"// TODO: Support {argName} argument."'], locals(), indent=indent)

    # Method override
    def beginFile(self, genOpts):
        VulkanBaseGenerator.beginFile(self, genOpts)
        self.is_header = genOpts.is_header
        self.newline()

    def is_union(self, value):
        if value not in self.registry.typedict:
            return False
        typeinfo = self.registry.typedict[value]
        type_elem = typeinfo.elem
        category = type_elem.get('category')
        if category == 'union':
            return True
        return False

    def generate_feature(self):
        structnames = self.get_filtered_struct_names()
        structnames.sort()

        # Insert the declaration of GenerateStruct functions.
        for structName in structnames:
            if (structName in self.CUSTOM_GENERATE_STRUCT or structName in self.feature_struct_aliases or structName in self.feature_union_aliases):
                continue

            struct_string = self.makeStructGenerateFunction(structName)
            struct_string += '\n'
            self.writeout(struct_string)

    #
    # Generate the "GenerateStruct_" function for the given structure name
    def makeStructGenerateFunction(self, struct_type):
        body = f'std::string GenerateStruct_{struct_type}(std::ostream &out, const {struct_type}* structInfo, ' \
                        f'Decoded_{struct_type}* metaInfo, VulkanCppConsumerBase &consumer)'
        if self.is_header:
            body += ';'
        else:
            body += '{\n'
            body += ''.join(self.makeStructDeclBody(struct_type))
            body += '}\n'
        return body

    def isStaticArray(self, array_length):
        if array_length[0].isupper() or array_length[0].isnumeric():
            return True
        else:
            return False

    def handlePNext(self, struct_prefix, indent, header, body, isFirstArg, isLastArg):
        local_header = []
        local_body = []
        local_header.extend(header)
        local_body.extend(body)

        local_header.append(makeGen(f'std::string pnext_name = GenerateExtension(out, {struct_prefix}pNext, metaInfo->pNext, consumer);', locals(), indent))
        local_body.append(makeOutStructSet('pnext_name', locals(), isFirstArg, isLastArg, indent))

        return local_header, local_body

    def handleChar(self, struct_prefix, arg, indent, header, body, isFirstArg, isLastArg):
        local_header = []
        local_body = []
        local_header.extend(header)
        local_body.extend(body)

        if arg.is_pointer and arg.pointer_count > 1:

            handleObjectType = None
            if arg.base_type in self.handle_names:
                handleObjectType = makeObjectType(arg.base_type)

            escapedStringArrayName = makeSnakeCaseName(f'{arg.name}Var'.format(**locals()))
            header_data = [
                makeGenVar(escapedStringArrayName, None, locals(), handleObjectType, indent, useThis=False),
                makeGenCond('{struct_prefix}{arg.array_length}',
                            [makeGenVar(escapedStringArrayName, '{arg.name}', handleObjectType, locals(), indent, addType=False, useThis=False),
                            printOutStream(['"const char* "',
                                            escapedStringArrayName,
                                            '"[] = "',
                                            f'VulkanCppConsumerBase::EscapeStringArray({struct_prefix}{arg.name}, {struct_prefix}{arg.array_length})',
                                            '";"'], locals(), indent)], [], locals(), indent)]
            local_header.append(''.join(header_data))
            local_body.append(makeOutStructSet(escapedStringArrayName, locals(), isFirstArg, isLastArg, indent))
        else:
            local_body.append(makeOutStructSet('VulkanCppConsumerBase::ToEscape({struct_prefix}{arg.name})', locals(), isFirstArg, isLastArg, indent))
        return local_header, local_body

    def handleBasicPointer(self, struct_prefix, arg, num_lengths, lengths, indent, header, body, isFirstArg, isLastArg):
        local_header = []
        local_body = []
        local_header.extend(header)
        local_body.extend(body)

        assert arg.pointer_count == 1, "Allow only a simple array"

        # ex: pDepthInputAttachmentIndex of VkRenderingInputAttachmentIndexInfoKHR has no count.
        if num_lengths == 0:
            return local_header, local_body

        # TODO: This is a hack, but according to the spec, this is correct
        if arg.name == 'pOffsetForRefFrame':
            lengths = []
            lengths.append(f'{struct_prefix}num_ref_frames_in_pic_order_cnt_cycle')
            num_lengths = 1

        handleObjectType = None
        if arg.base_type in self.handle_names:
            handleObjectType = makeObjectType(arg.base_type)

        variable_name = makeSnakeCaseName(arg.name + 'Array')

        this_header = [
            makeGenVar(variable_name, None, handleObjectType, locals(), indent, useThis=False),
            makeGenCond(f'{struct_prefix}{arg.name} != NULL', [
                makeGenVar(variable_name, arg.name, handleObjectType, locals(), indent + 4, addType=False, useThis=False),
                printOutStream([f'"{arg.base_type} "', '{variable_name} << "[] = "',
                                f'VulkanCppConsumerBase::BuildValue({struct_prefix}{arg.name}, {lengths[0]})',
                                '";"'], locals(), indent + 4)], [], locals(), indent)]
        local_header.extend(this_header)
        local_body.append(makeOutStructSet(variable_name, locals(), isFirstArg, isLastArg, indent))
        return local_header, local_body

    def handleLargeUint(self, struct_prefix, arg, num_lengths, lengths, indent, header, body, isFirstArg, isLastArg):
        local_header = []
        local_body = []
        local_header.extend(header)
        local_body.extend(body)

        if arg.is_array:
            strArrayName = makeSnakeCaseName(f'{arg.name}Array'.format(**locals()))
            strArrayValuesName = makeSnakeCaseName(f'{arg.name}Values'.format(**locals()))

            handleObjectType = None
            if arg.base_type in self.handle_names:
                handleObjectType = makeObjectType(arg.base_type)

            local_header.append(makeGenVar(strArrayName, strArrayName, handleObjectType, locals(), indent, addType=True, useThis=False)),
            local_header.append(makeGenCond('{lengths[0]} > 0', [
                makeGenVarCall('std::string', strArrayValuesName, 'toStringJoin',
                                [f'{struct_prefix}{arg.name}',
                                f'{struct_prefix}{arg.name} + {lengths[0]}',
                                f'[]({arg.base_type} current) {{{{ return std::to_string(current); }}}}',
                                '", "'], locals(), indent + 4),
                makeGenConditions([
                    ['{lengths[0]} == 1', [makeGen(f'{strArrayName} = "&" + {strArrayValuesName};', locals(), indent + 8)]],
                    ['{lengths[0]} > 1', [printOutStream([f'"{arg.base_type} "', strArrayName, '"[] = {{"', strArrayValuesName, '"}};"'], locals(), indent + 8)]],
                    # No need for else case
                ], locals(), indent + 4),
            ], [], locals(), indent))
            local_body.append(makeOutStructSet(f'"{{{{ *" << {strArrayName} << " }}}}"', locals(), isFirstArg, isLastArg, indent))
        else:
            local_body.append(makeOutStructSet(f'{struct_prefix}{arg.name} << "UL"', locals(), isFirstArg, isLastArg, indent))

        return local_header, local_body

    def handleEnum(self, struct_prefix, arg, num_lengths, lengths, indent, header, body, isFirstArg, isLastArg):
        local_header = []
        local_body = []
        local_header.extend(header)
        local_body.extend(body)

        if arg.is_pointer:
            # TODO: Possibly an array of enum/flag values?
            if num_lengths > 0:
                strArrayName = makeSnakeCaseName(f'{arg.name}Array'.format(**locals()))
                strArrayValuesName = makeSnakeCaseName(f'{arg.name}Values'.format(**locals()))

                handleObjectType = None
                if arg.base_type in self.handle_names:
                    handleObjectType = makeObjectType(arg.base_type)

                argHandler = [
                    makeGen(f'std::string {strArrayValuesName};', locals(), indent),
                    makeGenVar(strArrayName, None, handleObjectType, locals(), indent, useThis=False),
                    makeGenCond(f'{struct_prefix}{arg.name} != NULL', [
                        makeGenLoop('idx', '{lengths[0]}', [
                            makeGen(f'{strArrayValuesName} += util::ToString<{arg.base_type}>({struct_prefix}{arg.name}[idx]) + ", ";', locals(), indent + 8),
                        ], locals(), indent + 4),
                        makeGenVar(strArrayName, arg.name, handleObjectType, locals(), indent + 4, addType=False, useThis=False),
                        printOutStream([f'"{arg.base_type} "', strArrayName, '"[] = {{"', strArrayValuesName, '"}};"'], locals(), indent + 4)
                    ], [], locals(), indent),
                ]
                local_header.append(''.join(argHandler))
                local_body.append(makeOutStructSet(strArrayName, locals(), isFirstArg, isLastArg, indent))
            else:
                local_body.append(self.generateTodoFor(arg.name + '(Enum/flag pointer)', indent))
        else:
            local_body.append(makeOutStructSet(f'"{arg.base_type}(" << {struct_prefix}{arg.name} << ")"', locals(), isFirstArg, isLastArg, indent))

        return local_header, local_body


    def handleHandle(self, struct_prefix, arg, num_lengths, lengths, indent, header, body, isFirstArg, isLastArg):
        local_header = []
        local_body = []
        local_header.extend(header)
        local_body.extend(body)

        if arg.is_array:
            # Generate an array of strings containing the handle id names
            strArrayName = makeSnakeCaseName(arg.name + "Array")
            strArrayValuesName = makeSnakeCaseName(arg.name + "Values")

            handleObjectType = None
            if arg.base_type in self.handle_names:
                handleObjectType = makeObjectType(arg.base_type)

            local_header.append(makeGenVar(strArrayName, None, handleObjectType, locals(), indent, useThis=False))
            local_header.append(makeGenCond(f'metaInfo->{arg.name}.GetPointer() != NULL && {lengths[0]} > 0', [
                makeGenVar(strArrayName, strArrayName, handleObjectType, locals(), indent + 4, addType=False, useThis=False),
                makeGenVarCall('std::string', strArrayValuesName, 'toStringJoin',
                                [f'metaInfo->{arg.name}.GetPointer()',
                                f'metaInfo->{arg.name}.GetPointer() + {lengths[0]}',
                                '[&](const format::HandleId current) {{ return consumer.GetHandle(current); }}',
                                '", "'], locals(), indent + 4),
                makeGenConditions([
                    ['{lengths[0]} == 1', [makeGen(f'{strArrayName} = "&" + {strArrayValuesName};', locals(), indent + 8)]],
                    ['{lengths[0]} > 1', [printOutStream([f'"{arg.base_type} "', strArrayName, '"[] = {{"', strArrayValuesName, '"}};"'], locals(), indent + 8)]],
                    # No need for else case
                ], locals(), indent + 4),
            ], [], locals(), indent))

            local_body.append(makeOutStructSet(strArrayName, locals(), isFirstArg, isLastArg, indent))
        else:
            local_body.append(makeOutStructSet(f'consumer.GetHandle(metaInfo->{arg.name})', locals(), isFirstArg, isLastArg, indent))

        return local_header, local_body

    def handleInputArray(self, struct_prefix, arg, num_lengths, lengths, indent, header, body, isFirstArg, isLastArg):
        local_header = []
        local_body = []
        local_header.extend(header)
        local_body.extend(body)

        structBuild = []
        type_cast_prefix = ''
        type_cast_suffix = ''
        if arg.base_type == 'void':
            arg.base_type = 'uint8_t'
            type_cast_prefix = 'reinterpret_cast<const uint8_t*>('
            type_cast_suffix = ')'

        handleObjectType = None
        if arg.base_type in self.handle_names:
            handleObjectType = makeObjectType(arg.base_type)

        if num_lengths > 0:
            strArrayName = makeSnakeCaseName(arg.name + "Array")
            strArrayValuesName = makeSnakeCaseName(arg.name + "Values")

            structBuild += makeGenVar(strArrayName, None, handleObjectType, locals(), indent, useThis=False)
            space = (' ' * indent)

            # If pointer and not just static array
            if not self.isStaticArray(lengths[0]):
                structBuild += f'{space}if ({struct_prefix}{arg.name} != NULL) {{\n'
                indent += 4
                space = (' ' * indent)

            structBuild += makeGen('std::string {strArrayValuesName};', locals(), indent)

            var_suffix = ''
            for count, cur_length in enumerate(lengths):
                space = (' ' * indent)
                structBuild += f'{space}for (uint32_t idx{count} = 0; idx{count} < {cur_length}; ++idx{count}) {{\n'
                var_suffix = var_suffix + f'[idx{count}]'
                indent = indent + 4
                if count < num_lengths - 1:
                    space = (' ' * indent)
                    structBuild += f'{space}{strArrayValuesName} += "{{ ";\n'

            cur_arg_value = f'{type_cast_prefix}{struct_prefix}{arg.name}{type_cast_suffix}{var_suffix}'
            structBuild += makeGen(f'{strArrayValuesName} += std::to_string({cur_arg_value}) + ", ";', locals(), indent)

            for count, cur_length in enumerate(lengths):
                if count < num_lengths - 1:
                    space = (' ' * indent)
                    structBuild += f'{space}{strArrayValuesName} += " }},";\n'

                indent = indent - 4
                space = (' ' * indent)
                structBuild += f'{space}}}\n'

            structBuild += makeGenVar(strArrayName, arg.name, handleObjectType, locals(), indent, addType=False, useThis=False)
            structBuild += printOutStream([f'"{arg.base_type} "', strArrayName, '"[] = {{"', strArrayValuesName, '"}};"'], locals(), indent)

            if not self.isStaticArray(lengths[0]):
                indent = indent - 4
                space = (' ' * indent)
                structBuild += f'{space}}}\n'

            local_header.append(''.join(structBuild))
            local_body.append(makeOutStructSet(strArrayName, locals(), isFirstArg, isLastArg, indent))

        else:
            local_body.append(self.generateTodoFor(arg.name + '(input pointer)', indent))

        return local_header, local_body

    def handlePointer(self, struct_prefix, arg, num_lengths, lengths, indent, header, body, isFirstArg, isLastArg):
        local_header = []
        local_body = []
        local_header.extend(header)
        local_body.extend(body)
        arg_name = struct_prefix + arg.name
        struct_arg = None
        if arg.platform_full_type == 'LPCWSTR':
            struct_arg = f'"reinterpret_cast<{arg.platform_full_type}>(" << util::strings::convert_wstring_to_utf8({arg_name}) << ")"'
        else:
            struct_arg = f'"reinterpret_cast<{arg.platform_full_type}>(" << {arg_name} << ")"'
        local_body.append(makeOutStructSet(struct_arg, locals(), isFirstArg, isLastArg, indent))

        return local_header, local_body

    def handleOutputParam(self, struct_prefix, arg, num_lengths, lengths, indent, header, body, isFirstArg, isLastArg):
        local_header = []
        local_body = []
        local_header.extend(header)
        local_body.extend(body)

        handleObjectType = None
        if arg.base_type in self.handle_names:
            handleObjectType = makeObjectType(arg.base_type)

        if not arg.is_array:
            if self.is_struct(arg.base_type):
                varName = makeSnakeCaseName(arg.name + "Name")
                header = makeGenVar(varName, None, handleObjectType, locals(), indent, useThis=False)
                header += makeGenCond(f'{struct_prefix}{arg.name} != NULL', [
                    makeGenVarCall(None,
                                   varName,
                                   f'GenerateStruct_{arg.base_type}',
                                   ['out',
                                    f'{struct_prefix}{arg.name}',
                                    f'metaInfo->{arg.name}->GetMetaStructPointer()',
                                    'consumer'],
                                   locals(), indent=indent + 4),
                    makeGen('{varName}.insert(0, "&");', locals(), indent + 4),
                ], [], locals(), indent=indent)
                local_header.append(header)
                local_body.append(makeOutStructSet(varName, locals(), isFirstArg, isLastArg, indent))
            else:
                # TODO: non-struct output parameters
                local_body.append(self.generateTodoFor(arg.name + " (non-struct output)", indent))

        else:
            if arg.array_length_value is None:
                if lengths[0].isnumeric() or lengths[0].isupper():
                    if len(lengths):
                        param_prefix = '&'
                        param_suffix = '[0]' * len(lengths)
                        struct_param = f'reinterpret_cast<const {arg.base_type}*>({param_prefix}{struct_prefix}{arg.name}{param_suffix})'
                    else:
                        struct_param = f'reinterpret_cast<const {arg.base_type}*>({struct_prefix}{arg.name})'
                else:
                    struct_param = f'{struct_prefix}{arg.name}'

                local_body.append(makeOutStructSet(f'VulkanCppConsumerBase::BuildValue({struct_param}, {lengths[0]})', locals(), isFirstArg, isLastArg, indent))
            else: # arg.array_length_value
                if self.is_struct(arg.base_type):
                    innerIndent = indent + 4 if not arg.array_capacity else 4

                    varName = makeSnakeCaseName(arg.name + "Names")
                    arrayVarName = makeSnakeCaseName(arg.name + "Array")
                    valuesVarName = makeSnakeCaseName(arg.name + "Values")

                    arrayBuilder = [
                        makeGen(f'std::string {varName};', locals(), indent=innerIndent),
                        makeGenLoop('idx', f'{lengths[0]}', [
                            makeGen('std::string variable_name = "NULL";', indent=innerIndent + 4),
                            makeGenCond(f'{struct_prefix}{arg.name} + idx != NULL', [
                                makeGenVarCall(None,
                                                'variable_name',
                                                f'GenerateStruct_{arg.base_type}',
                                                ['out',
                                                f'{struct_prefix}{arg.name} + idx',
                                                f'metaInfo->{arg.name}->GetMetaStructPointer() + idx',
                                                'consumer'],
                                                locals(), indent=innerIndent + 8)
                            ], [], locals(), indent=innerIndent + 4),
                            makeGen('{varName} += variable_name + ", ";', locals(), indent=innerIndent + 4),
                        ], locals(), indent=innerIndent),
                        printOutStream([f'"{arg.base_type} "', arrayVarName, '"[] = {{"', varName, '"}};"'],
                                        locals(), indent=innerIndent)
                    ]

                    if arg.array_capacity:
                        local_body.append('\tstruct_body << "\\t\\t\\t{}," << std::endl;\n')
                    else:
                        arrayName = makeGenVar(arrayVarName, None, handleObjectType, locals(), indent, useThis=False)
                        arrayNameSet = makeGenVar(arrayVarName, arg.name, handleObjectType, locals(), indent + 4, addType=False, useThis=False)
                        arrayProcess = makeGenCond(f'{struct_prefix}{arg.name} != NULL', [arrayNameSet] + arrayBuilder, [], locals(), indent)

                        local_header.append(arrayName + arrayProcess)
                        local_body.append(makeOutStructSet(arrayVarName, locals(), isFirstArg, isLastArg, indent))
                elif self.is_enum(arg.base_type) or self.is_flags(arg.base_type):
                    arrayVarName = makeSnakeCaseName(arg.name + "Array")
                    valuesVarName = makeSnakeCaseName(arg.name + "Values")

                    argHandler = [
                        makeGenVar(arrayVarName, None, handleObjectType, locals(), indent, useThis=False),
                        makeGenCond(f'{struct_prefix}{arg.name} != NULL', [
                            makeGen(f'std::string {valuesVarName};', locals(), indent + 4),
                            makeGenLoop('idx', '{lengths[0]}', [
                                makeGen(f'{valuesVarName} += util::ToString<{arg.base_type}>({struct_prefix}{arg.name}[idx]) + ", ";', locals(), indent + 8),
                            ], locals(), indent + 4),
                            makeGenVar(arrayVarName, '{arg.name}', handleObjectType, locals(), indent + 4, addType=False, useThis=False),
                            printOutStream([f'"{arg.base_type} "', arrayVarName, '"[] = {{"', valuesVarName, '"}};"'], locals(), indent + 4)
                        ], [], locals(), indent),
                    ]
                    local_header.append(''.join(argHandler))
                    local_body.append(makeOutStructSet(arrayVarName, locals(), isFirstArg, isLastArg, indent))
                else:
                    local_body.append(self.generateTodoFor(arg.name + " (output with array length value?)", indent))

        return local_header, local_body

    #
    # Generate structure declaration body.
    def makeStructDeclBody(self, structName):
        structMembers = self.feature_struct_members[structName]
        vkLUType = ['VkDeviceSize', 'VkDeviceAddress', 'uint64_t']
        indent = 4
        body = []
        header = []
        header.append(makeGen('std::stringstream struct_body;', locals(), indent))
        struct_prefix = 'structInfo->'

        for arg in structMembers:
            isFirstArg = (arg == structMembers[0])
            isLastArg = (arg == structMembers[-1])

            if arg.base_type == 'VkDescriptorUpdateTemplateEntryKHR':
                print(f'   {arg.name} was struct base type {arg.base_type} should have an alias')

            if arg.base_type in self.feature_struct_aliases:
                print(f'   {arg.name} was struct base type {arg.base_type} but aliased to {self.feature_struct_aliases[arg.base_type]}')
                arg.base_type = self.feature_struct_aliases[arg.base_type]
            elif arg.base_type in self.feature_union_aliases:
                print(f'   {arg.name} was union base type {arg.base_type} but aliased to {self.feature_union_aliases[arg.base_type]}')
                arg.base_type = self.feature_union_aliases[arg.base_type]

            handleObjectType = None
            if arg.base_type in self.handle_names:
                handleObjectType = makeObjectType(arg.base_type)

            arg_name = struct_prefix + arg.name

            lengths = []
            if arg.array_length_value is not None:
                loopCondition = '{arg.array_length}'.format(**locals())
                varNameArrayLength = getattr(arg.array_length_value, 'name', None)
                # Substitute the variable occurrence with the proper variable reference.
                # This is required if the size of the array is an expression.
                if varNameArrayLength:
                    loopCondition = re.sub(varNameArrayLength, '{struct_prefix}{varNameArrayLength}'.format(**locals()), loopCondition)
                    lengths = re.split(',', loopCondition)
            elif arg.array_length is not None:
                lengths = re.split(',', arg.array_length)
                for index, length in enumerate(lengths):
                    if not (length.isupper() or length.isnumeric()):
                        lengths[index] = struct_prefix + length

            num_lengths = len(lengths)

            if arg.name == 'pNext':
                header, body = self.handlePNext(struct_prefix, indent, header, body, isFirstArg, isLastArg)

            elif arg.base_type == 'char':
                header, body = self.handleChar(struct_prefix, arg, indent, header, body, isFirstArg, isLastArg)

            elif arg.base_type in ['float', 'int32_t', 'uint32_t', 'VkClearValue', 'VkRect2D'] and arg.is_pointer:
                header, body = self.handleBasicPointer(struct_prefix, arg, num_lengths, lengths, indent, header, body, isFirstArg, isLastArg)

            elif arg.base_type in vkLUType:
                header, body = self.handleLargeUint(struct_prefix, arg, num_lengths, lengths, indent, header, body, isFirstArg, isLastArg)

            elif self.is_output_parameter(arg):
                header, body = self.handleOutputParam(struct_prefix, arg, num_lengths, lengths, indent, header, body, isFirstArg, isLastArg)

            elif self.is_union(arg.base_type):
                if not arg.is_pointer:
                    if arg.base_type in ['VkClearValue', 'VkClearColorValue', 'VkComponentMapping', 'VkOffset2D', 'VkExtent2D']:
                        body.append(makeOutStructSet('VulkanCppConsumerBase::BuildValue({arg_name})', locals(), isFirstArg, isLastArg, indent))
                    elif arg.base_type in self.feature_union_members:
                        union_members = self.feature_union_members[arg.base_type]
                        first_member = union_members[0]

                        if first_member.base_type in BasicStringConversionHandledTypes:
                            body.append(makeOutStructSet(f'{arg_name}.{first_member.name}', locals(), isFirstArg, isLastArg, indent))
                        elif self.is_struct(first_member.base_type):
                            varName = makeSnakeCaseName(first_member.name + "InfoVar")

                            argHandler = [
                                makeGenVarCall('std::string',
                                                varName,
                                                f'GenerateStruct_{first_member.base_type}',
                                                ['out',
                                                f'&{arg_name}.{first_member.name}',
                                                f'metaInfo->{arg.name}->{first_member.name}',
                                                'consumer'],
                                                locals(), indent),
                            ]
                            header.append(''.join(argHandler))

                            body.append(makeOutStructSet(varName, locals(), isFirstArg, isLastArg, indent))
                        else:
                            body.append(makeOutStructSet('VulkanCppConsumerBase::BuildValue({arg_name}.{first_member.name})', locals(), isFirstArg, isLastArg, indent))
                    else:
                        body.append(makeOutStructSet('VulkanCppConsumerBase::BuildValue({arg_name})', locals(), isFirstArg, isLastArg, indent))
                else:
                    #if arg.base_type in ['VkClearColorValue', 'VkComponentMapping', 'VkOffset2D', 'VkExtent2D']:
                    body.append(makeGenVar(f'tmp{arg.name}', arg.name, handleObjectType, locals(), indent, useThis=False))
                    body.append(makeOutStructSet('VulkanCppConsumerBase::BuildValue({arg_name})', locals(), isFirstArg, isLastArg, indent + 4))
            elif self.is_struct(arg.base_type) and arg.base_type not in self.LOCAL_STRUCT_BLACKLIST:
                if not arg.is_pointer:
                    varName = makeSnakeCaseName(arg.name + "InfoVar")
                    argHandler = [
                        makeGenVarCall('std::string',
                                        varName,
                                        f'GenerateStruct_{arg.base_type}',
                                        ['out',
                                        f'&{arg_name}',
                                        f'metaInfo->{arg.name}',
                                        'consumer'],
                                        locals(), indent),
                    ]
                    header.append(''.join(argHandler))

                    body.append(makeOutStructSet(varName, locals(), isFirstArg, isLastArg, indent))
                else:
                    if num_lengths > 0:
                        arrayVarName = makeSnakeCaseName(arg.name + "Array")
                        namesVarName = makeSnakeCaseName(arg.name + "Names")

                        if num_lengths > 1:

                            indent = 4
                            structBuild = makeGenVar(arrayVarName, None, handleObjectType, locals(), indent, useThis=False)
                            space = (' ' * indent)
                            structBuild += f'{space}if ({arg_name} != NULL) {{\n'
                            indent = 8
                            structBuild += makeGenVar(arrayVarName, arg.name, handleObjectType, locals(), indent, addType=False, useThis=False)
                            structBuild += makeGen(f'std::string {namesVarName};', locals(), indent)

                            member_prefix = '&('
                            member_suffix = ')'
                            still_is_pointer = False
                            if arg.pointer_count > len(lengths):
                                still_is_pointer = True
                                member_prefix = ''
                                member_suffix = ''

                            var_suffix = ''
                            for count, cur_length in enumerate(lengths):
                                space = (' ' * indent)
                                structBuild += f'{space}for (uint32_t idx{count} = 0; idx{count} < {cur_length}; ++idx{count}) {{\n'
                                var_suffix = var_suffix + f'[idx{count}]'
                                indent = indent + 4

                            structBuild += makeGen('std::string variable_name = "NULL";', locals(), indent)
                            space = (' ' * indent)

                            if still_is_pointer:
                                structBuild += f'{space}{arg_name}{var_suffix} != NULL) {{'
                                indent = indent + 4

                            structBuild += makeGenVarCall(None,
                                                    'variable_name',
                                                    f'GenerateStruct_{arg.base_type}',
                                                    ['out',
                                                        f'{member_prefix}{arg_name}{var_suffix}{member_suffix}',
                                                        f'{member_prefix}metaInfo->{arg.name}->GetMetaStructPointer(){var_suffix}{member_suffix}',
                                                        'consumer'], locals(), indent)
                            structBuild += makeGen(f'{namesVarName} += variable_name + ", ";', locals(), indent)

                            if still_is_pointer:
                                indent = indent - 4
                                space = (' ' * indent)
                                structBuild += f'{space}}}\n'

                            for count, cur_length in enumerate(lengths):
                                indent = indent - 4
                                space = (' ' * indent)
                                structBuild += f'{space}}}\n'

                            indent = indent - 4
                            space = (' ' * indent)
                            structBuild += f'{space}}}\n'
                        else:
                            structBuild = [
                                makeGenVar(arrayVarName, None, handleObjectType, locals(), indent, useThis=False),
                                makeGenCond(f'{arg_name} != NULL', [
                                    makeGenVar(arrayVarName, arg.name, handleObjectType, locals(), indent + 4, addType=False, useThis=False),
                                    makeGen(f'std::string {namesVarName};', locals(), indent + 4),
                                    makeGenLoop('idx', f'{lengths[0]}', [
                                        makeGen('std::string variable_name = "NULL";', locals(), indent + 8),
                                        makeGenCond(f'{arg_name} + idx != NULL', [
                                            makeGenVarCall(None,
                                                        'variable_name',
                                                        f'GenerateStruct_{arg.base_type}',
                                                        ['out',
                                                            f'{arg_name} + idx',
                                                            f'metaInfo->{arg.name}->GetMetaStructPointer() + idx',
                                                            'consumer'],
                                                        locals(), indent + 12),
                                        ], [], locals(), indent + 8),
                                        makeGen(f'{namesVarName} += variable_name + ", ";', locals(), indent + 8),
                                    ], locals(), indent + 4),
                                    printOutStream([f'"{arg.base_type} "', arrayVarName, '"[] = {{"', namesVarName, '"}};"'], locals(), indent + 4),
                                ], [], locals(), indent)
                            ]
                        header.append(''.join(structBuild))
                        body.append(makeOutStructSet(arrayVarName, locals(), isFirstArg, isLastArg, indent))
                    else:
                        varName = makeSnakeCaseName(arg.name + "Struct")

                        prefixVar = f'prefix_{arg.name}'
                        # Make sure if the sub struct pointer during capture processing does contain data and it is not a NULL value.
                        structBuild = [
                            makeGenVar(varName, None, handleObjectType, locals(), indent, useThis=False),
                            makeGenCond('{arg_name} != NULL', [
                                makeGenVarCall(None,
                                               varName,
                                               f'GenerateStruct_{arg.base_type}',
                                               ['out',
                                                f'{arg_name}',
                                                f'metaInfo->{arg.name}->GetMetaStructPointer()',
                                                'consumer'],
                                               locals(), indent + 4),
                                makeGen('{varName}.insert(0, "&");', locals(), indent + 4),
                            ], [], locals(), indent),
                        ]
                        header.append(''.join(structBuild))
                        body.append(makeOutStructSet(varName, locals(), isFirstArg, isLastArg, indent))
                # TODO:
                # structArguments = []
                # for subArg in self.feature_struct_members[arg.base_type]:
                #     structArguments.append('{struct_prefix}{structName}.{structMemberName}\n'.format(structName=arg.name, structMemberName=subArg.name))
                # body += '    out << varname << ".{argName} = {{ " << {structArgs}    << "}};" << std::endl;\n'.format(argName=arg.name, structArgs='    << "," << '.join(structArguments))

            elif self.is_enum(arg.base_type) or self.is_flags(arg.base_type):
                header, body = self.handleEnum(struct_prefix, arg, num_lengths, lengths, indent, header, body, isFirstArg, isLastArg)

            elif self.is_handle(arg.base_type):
                header, body = self.handleHandle(struct_prefix, arg, num_lengths, lengths, indent, header, body, isFirstArg, isLastArg)

            elif self.is_input_pointer(arg) and arg.is_array:
                header, body = self.handleInputArray(struct_prefix, arg, num_lengths, lengths, indent, header, body, isFirstArg, isLastArg)

            elif arg.platform_full_type is not None and arg.pointer_count > 0:
                header, body = self.handlePointer(struct_prefix, arg, num_lengths, lengths, indent, header, body, isFirstArg, isLastArg)

            else:
                struct_arg = arg_name
                if 'int8_t' in arg.base_type:
                    struct_arg = f'std::to_string({arg_name})'
                body.append(makeOutStructSet(struct_arg, locals(), isFirstArg, isLastArg, indent))

        if structName in self.feature_struct_aliases:
            structName = self.feature_struct_aliases[structName]

        var_list = []

        # If we already have a variable we're going to overwrite, just set the variable = to the new values.
        # Otherwise, we need to define a new variable
        if structName in self.trackedStructs:
            var_list.append('variable_name')
            var_list.append('" = {{"')
        else:
            var_list.append(f'"{structName} "')
            var_list.append('variable_name')
            var_list.append('" {{"')

        # convert name: Vk<StructName> => <structName>
        # TODO: maybe improve this a bit?
        structVarName = structName
        if structVarName.startswith("Vk"):
            structVarName = structVarName[2:]

        structVarName = structVarName[0].lower() + structVarName[1:]

        # insert the header up front (where all the variables are defined)
        body.append(makeGen(f'std::string variable_name = consumer.AddStruct(struct_body, "{structVarName}");', locals(), indent))
        body.append(printOutStream(var_list, locals(), indent))
        body.append(printOutStream(['struct_body.str()'], locals(), indent))
        body.append(printOutStream(['"}};"'], locals(), indent))

        if structName in self.overrideStructs:
            body.append(printOutStream(['"Override{structName}(&"', 'variable_name', '", "', '"appdata"', '");"'], locals(), indent))

        body.append(makeGen('return variable_name;', locals(), indent))

        func = []
        func.extend(header)
        func.extend(body)
        return func
