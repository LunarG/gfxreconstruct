#!/usr/bin/python3 -i
#
# Copyright (c) 2021 Samsung
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
from base_generator import BaseGenerator, BaseGeneratorOptions, write
from vulkan_cpp_consumer_body_generator import \
    makeGen, makeGenVar, makeGenVarCall, makeGenCond, makeGenConditions, makeGenLoop, makeObjectType, makeOutStructSet, printOutStream

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

class VulkanCppStructGeneratorOptions(BaseGeneratorOptions):
    """Options for generating a C++ class for Vulkan capture file to CPP structure generation"""

    def __init__(
        self,
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        extraVulkanHeaders=[]
    ):
        BaseGeneratorOptions.__init__(
            self,
            blacklists,
            platform_types,
            filename,
            directory,
            prefix_text,
            protect_file,
            protect_feature,
            extraVulkanHeaders=extraVulkanHeaders
        )

class VulkanCppStructGenerator(BaseGenerator):
    """VulkanCppStructGenerator - subclass of BaseGenerator.
    Generates vulkan struct generating functions.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
     ):
        BaseGenerator.__init__(
            self,
            process_cmds=True,
            process_structs=True,
            feature_break=True,
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
            'VkXcbSurfaceCreateInfoKHR',
            'VkWaylandSurfaceCreateInfoKHR', #-> vkCreateWaylandSurfaceKHR
            'VkAndroidSurfaceCreateInfoKHR'
        ]

        self.CUSTOM_GENERATE_STRUCT = [
            'VkBaseInStructure',
            'VkBaseOutStructure',
            'SECURITY_ATTRIBUTES',
            'GUID',
            'VkInstanceCreateInfo'
            'VkMemoryAllocateInfo',
            'VkClearColorValue',
            'VkWriteDescriptorSet',
            'VkPresentInfoKHR',
            'VkDescriptorUpdateTemplateCreateInfoKHR',
            'VkDescriptorImageInfo',
            'VkDescriptorUpdateTemplateEntry',
            'VkAccelerationStructureMotionInstanceNV',
            'VkDebugUtilsMessengerCreateInfoEXT',
        ]

        self.LOCAL_STRUCT_BLACKLIST = [
            'VkBaseInStructure',
            'VkBaseOutStructure',
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
        BaseGenerator.beginFile(self, genOpts)
        self.is_header = genOpts.filename.endswith(".h")

        if self.is_header:
            self.writeout('#pragma once')
            self.newline()
            self.writeout('#include "util/defines.h"')
            self.includeVulkanHeaders(genOpts)
            self.newline()

        if not self.is_header:
            self.writeout('#include "decode/vulkan_cpp_structs.h"')
            self.writeout('#include "generated/generated_vulkan_cpp_structs.h"')
            self.writeout('#include "generated/generated_vulkan_cpp_consumer.h"')
            self.writeout('#include "generated/generated_vulkan_cpp_consumer_extension.h"')
            self.writeout('#include "generated/generated_vulkan_enum_to_string.h"')
        self.writeout('GFXRECON_BEGIN_NAMESPACE(gfxrecon)')
        self.writeout('GFXRECON_BEGIN_NAMESPACE(decode)')
        self.newline()

    # Method override
    def endFile(self):
        self.writeout('GFXRECON_END_NAMESPACE(decode)')
        self.writeout('GFXRECON_END_NAMESPACE(gfxrecon)')
        self.newline()

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def need_feature_generation(self):
        if self.struct_names:
            return True
        return False

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
        structs = self.feature_struct_members # Brainpain self.get_filtered_struct_names()

        # Insert the declaration of GenerateStruct functions.
        for structName in structs:
            if (structName in self.CUSTOM_GENERATE_STRUCT or structName in self.feature_struct_aliases or structName in self.feature_union_aliases):
                continue

            struct_string = self.makeStructGenerateFunction(structName)
            struct_string += '\n'
            self.writeout(struct_string)

    #
    # Generate the "GenerateStruct_" function for the given structure name
    def makeStructGenerateFunction(self, struct_type):
        body = f'std::string GenerateStruct_{struct_type}(std::ostream &out, const {struct_type}* structInfo, ' \
                        f'Decoded_{struct_type}* metainfo, VulkanCppConsumerBase &consumer)'
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

    def handlePNext(self, struct_prefix, indent, header, body):
        local_header = []
        local_body = []
        local_header.extend(header)
        local_body.extend(body)

        local_header.append(makeGen('std::string pNextName = GenerateExtension(out, {struct_prefix}pNext, metainfo->pNext, consumer);', locals(), indent))
        local_body.append(makeOutStructSet('pNextName', locals(), False, indent))

        return local_header, local_body

    def handleChar(self, struct_prefix, arg, indent, header, body, is_last_arg):
        local_header = []
        local_body = []
        local_header.extend(header)
        local_body.extend(body)

        if arg.is_pointer and arg.pointer_count > 1:

            handleObjectType = None
            if arg.base_type in self.handle_names:
                handleObjectType = makeObjectType(arg.base_type)

            escapedStringArrayName = '{arg.name}Var'.format(**locals())
            header_data = [
                makeGenVar(escapedStringArrayName, None, locals(), handleObjectType, indent, useThis=False),
                makeGenCond('{struct_prefix}{arg.array_length}',
                            [makeGenVar(escapedStringArrayName, '{arg.name}', handleObjectType, locals(), indent, addType=False, useThis=False),
                            printOutStream(['"const char* "',
                                            escapedStringArrayName,
                                            '"[] = "',
                                            'VulkanCppConsumerBase::escapeStringArray({struct_prefix}{arg.name}, {struct_prefix}{arg.array_length})',
                                            '";"'], locals(), indent)], [], locals(), indent)]
            local_header.append(''.join(header_data))
            local_body.append(makeOutStructSet(escapedStringArrayName, locals(), is_last_arg, indent))
        else:
            local_body.append(makeOutStructSet('VulkanCppConsumerBase::toEscape({struct_prefix}{arg.name})', locals(), is_last_arg, indent))
        return local_header, local_body

    def handleBasicPointer(self, struct_prefix, arg, num_lengths, lengths, indent, header, body, is_last_arg):
        local_header = []
        local_body = []
        local_header.extend(header)
        local_body.extend(body)

        assert arg.pointer_count == 1, "Allow only a simple array"

        # TODO: This is a hack, but according to the spec, this is correct
        if arg.name == 'pOffsetForRefFrame':
            lengths = []
            lengths.append(f'{struct_prefix}num_ref_frames_in_pic_order_cnt_cycle')
            num_lengths = 1

        handleObjectType = None
        if arg.base_type in self.handle_names:
            handleObjectType = makeObjectType(arg.base_type)

        this_header = [
            makeGenVar('{arg.name}Array', None, handleObjectType, locals(), indent, useThis=False),
            makeGenCond('{struct_prefix}{arg.name} != NULL', [
                makeGenVar('{arg.name}Array', '{arg.name}', handleObjectType, locals(), indent + 4, addType=False, useThis=False),
                printOutStream(['"{arg.base_type} "', '{arg.name}Array << "[] = "',
                                'VulkanCppConsumerBase::BuildValue({struct_prefix}{arg.name}, {lengths[0]})',
                                '";"'], locals(), indent + 4)], [], locals(), indent)]
        local_header.extend(this_header)
        local_body.append(makeOutStructSet('{arg.name}Array', locals(), is_last_arg, indent))
        return local_header, local_body

    def handleLargeUint(self, struct_prefix, arg, num_lengths, lengths, indent, header, body, is_last_arg):
        local_header = []
        local_body = []
        local_header.extend(header)
        local_body.extend(body)

        if arg.is_array:
            strArrayName = '{arg.name}Array'.format(**locals())

            handleObjectType = None
            if arg.base_type in self.handle_names:
                handleObjectType = makeObjectType(arg.base_type)

            local_header.append(makeGenVar('{strArrayName}', '{strArrayName}', handleObjectType, locals(), indent, addType=True, useThis=False)),
            local_header.append(makeGenCond('{lengths[0]} > 0', [
                makeGenVarCall('std::string', '{arg.name}Values', 'toStringJoin',
                                ['{struct_prefix}{arg.name}',
                                '{struct_prefix}{arg.name} + {lengths[0]}',
                                '[]({arg.base_type} current) {{ return std::to_string(current); }}',
                                '", "'], locals(), indent + 4),
                makeGenConditions([
                    ['{lengths[0]} == 1', [makeGen('{arg.name}Array = "&" + {arg.name}Values;', locals(), indent + 8)]],
                    ['{lengths[0]} > 1', [printOutStream(['"{arg.base_type} "', '{arg.name}Array', '"[] = {{"', '{arg.name}Values', '"}};"'], locals(), indent + 8)]],
                    # No need for else case
                ], locals(), indent + 4),
            ], [], locals(), indent))
            local_body.append(makeOutStructSet('"{{ *" << {arg.name}Array << " }}"', locals(), is_last_arg, indent))
        else:
            local_body.append(makeOutStructSet('{struct_prefix}{arg.name} << "UL"', locals(), is_last_arg, indent))

        return local_header, local_body

    def handleEnum(self, struct_prefix, arg, num_lengths, lengths, indent, header, body, is_last_arg):
        local_header = []
        local_body = []
        local_header.extend(header)
        local_body.extend(body)

        if arg.is_pointer:
            # TODO: Possibly an array of enum/flag values?
            if num_lengths > 0:
                # VkPipelineStageFlags waitStages[] = { VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT };
                # submitInfo.pWaitDstStageMask = waitStages;
                arrayName = '{arg.name}Array'.format(arg=arg)

                handleObjectType = None
                if arg.base_type in self.handle_names:
                    handleObjectType = makeObjectType(arg.base_type)

                argHandler = [
                    makeGen('std::string {arg.name}Values;', locals(), indent),
                    makeGenVar(arrayName, None, handleObjectType, locals(), indent, useThis=False),
                    makeGenCond('{struct_prefix}{arg.name} != NULL', [
                        makeGenLoop('idx', '{lengths[0]}', [
                            makeGen('{arg.name}Values += util::ToString<{arg.base_type}>({struct_prefix}{arg.name}[idx]) + ", ";', locals(), indent + 8),
                        ], locals(), indent + 4),
                        makeGenVar(arrayName, '{arg.name}', handleObjectType, locals(), indent + 4, addType=False, useThis=False),
                        printOutStream(['"{arg.base_type} "', arrayName, '"[] = {{"', '{arg.name}Values', '"}};"'], locals(), indent + 4)
                    ], [], locals(), indent),
                ]
                local_header.append(''.join(argHandler))
                local_body.append(makeOutStructSet(arrayName, locals(), is_last_arg, indent))
            else:
                local_body.append(self.generateTodoFor(arg.name + '(Enum/flag pointer)', indent))
        else:
            local_body.append(makeOutStructSet('"{arg.base_type}(" << {struct_prefix}{arg.name} << ")"', locals(), is_last_arg, indent))

        return local_header, local_body


    def handleHandle(self, struct_prefix, arg, num_lengths, lengths, indent, header, body, is_last_arg):
        local_header = []
        local_body = []
        local_header.extend(header)
        local_body.extend(body)

        if arg.is_array:
            # Generate an array of strings containing the handle id names
            strArrayName = arg.name + "Array"

            handleObjectType = None
            if arg.base_type in self.handle_names:
                handleObjectType = makeObjectType(arg.base_type)

            local_header.append(makeGenVar('{strArrayName}', None, handleObjectType, locals(), indent, useThis=False))
            local_header.append(makeGenCond('metainfo->{arg.name}.GetPointer() != NULL && {lengths[0]} > 0', [
                makeGenVar('{strArrayName}', '{strArrayName}', handleObjectType, locals(), indent + 4, addType=False, useThis=False),
                makeGenVarCall('std::string', '{arg.name}Values', 'toStringJoin',
                                ['metainfo->{arg.name}.GetPointer()',
                                'metainfo->{arg.name}.GetPointer() + {lengths[0]}',
                                '[&](const format::HandleId current) {{ return consumer.GetHandle(current); }}',
                                '", "'], locals(), indent + 4),
                makeGenConditions([
                    ['{lengths[0]} == 1', [makeGen('{arg.name}Array = "&" + {arg.name}Values;', locals(), indent + 8)]],
                    ['{lengths[0]} > 1', [printOutStream(['"{arg.base_type} "', '{arg.name}Array', '"[] = {{"', '{arg.name}Values', '"}};"'], locals(), indent + 8)]],
                    # No need for else case
                ], locals(), indent + 4),
            ], [], locals(), indent))

            local_body.append(makeOutStructSet('{strArrayName}', locals(), is_last_arg, indent))
        else:
            local_body.append(makeOutStructSet('consumer.GetHandle(metainfo->{arg.name})', locals(), is_last_arg, indent))

        return local_header, local_body

    def handleInputArray(self, struct_prefix, arg, num_lengths, lengths, indent, header, body, is_last_arg):
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
            structBuild += makeGenVar('{arg.name}Array', None, handleObjectType, locals(), indent, useThis=False)
            space = (' ' * indent)
            
            # If pointer and not just static array
            if not self.isStaticArray(lengths[0]):
                structBuild += f'{space}if ({struct_prefix}{arg.name} != NULL) {{\n'
                indent += 4
                space = (' ' * indent)

            structBuild += makeGen('std::string {arg.name}Values;', locals(), indent)

            var_suffix = ''
            for count, cur_length in enumerate(lengths):
                space = (' ' * indent)
                structBuild += f'{space}// Brainpain - handleInputArray {arg.base_type} {arg.name} {num_lengths}\n'
                structBuild += f'{space}for (uint32_t idx{count} = 0; idx{count} < {cur_length}; ++idx{count}) {{\n'
                var_suffix = var_suffix + f'[idx{count}]'
                indent = indent + 4
                if count < num_lengths - 1:
                    space = (' ' * indent)
                    structBuild += f'{space}{arg.name}Values += "{{ ";\n'

            cur_arg_value = f'{type_cast_prefix}{struct_prefix}{arg.name}{type_cast_suffix}{var_suffix}'
            structBuild += makeGen('{arg.name}Values += std::to_string({cur_arg_value}) + ", ";', locals(), indent)

            for count, cur_length in enumerate(lengths):
                if count < num_lengths - 1:
                    space = (' ' * indent)
                    structBuild += f'{space}{arg.name}Values += " }},";\n'

                indent = indent - 4
                space = (' ' * indent)
                structBuild += f'{space}}}\n'

            structBuild += makeGenVar('{arg.name}Array', '{arg.name}', handleObjectType, locals(), indent, addType=False, useThis=False)
            structBuild += printOutStream(['"{arg.base_type} "', '{arg.name}Array', '"[] = {{"', '{arg.name}Values', '"}};"'], locals(), indent)

            if not self.isStaticArray(lengths[0]):
                indent = indent - 4
                space = (' ' * indent)
                structBuild += f'{space}}}\n'

            local_header.append(''.join(structBuild))
            local_body.append(makeOutStructSet('{arg.name}Array', locals(), is_last_arg, indent))

        else:
            local_body.append(self.generateTodoFor(arg.name + '(input pointer)', indent))

        return local_header, local_body
    

    def handleOutputParam(self, struct_prefix, arg, num_lengths, lengths, indent, header, body, is_last_arg):
        local_header = []
        local_body = []
        local_header.extend(header)
        local_body.extend(body)

        handleObjectType = None
        if arg.base_type in self.handle_names:
            handleObjectType = makeObjectType(arg.base_type)

        # TODO: is the output parameter okay here?
        if not arg.is_array:
            local_body.append(self.generateTodoFor(arg.name + " (output?)", indent))
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

                local_body.append(makeOutStructSet('VulkanCppConsumerBase::BuildValue({struct_param}, {lengths[0]})', locals(), is_last_arg, indent))
            else: # arg.array_length_value
                if self.is_struct(arg.base_type):
                    innerIndent = indent + 4 if not arg.array_capacity else 4

                    arrayBuilder = [
                        makeGen('std::string {arg.name}Names;', locals(), indent=innerIndent),
                        makeGenLoop('idx', '{lengths[0]}', [
                            makeGen('std::string varName = "NULL";', indent=innerIndent + 4),
                            makeGenCond('{struct_prefix}{arg.name} + idx != NULL', [
                                makeGenVarCall(None,
                                                'varName',
                                                'GenerateStruct_{arg.base_type}',
                                                ['out',
                                                '{struct_prefix}{arg.name} + idx',
                                                'metainfo->{arg.name}->GetMetaStructPointer() + idx',
                                                'consumer'],
                                                locals(), indent=innerIndent + 8)
                            ], [], locals(), indent=innerIndent + 4),
                            makeGen('{arg.name}Names += varName + ", ";', locals(), indent=innerIndent + 4),
                        ], locals(), indent=innerIndent),
                        printOutStream(['"{arg.base_type} "', '{arg.name}Array', '"[] = {{"', '{arg.name}Names', '"}};"'],
                                        locals(), indent=innerIndent)
                    ]

                    if arg.array_capacity:
                        arrayName = makeGenVar('{arg.name}Array', arg.name, handleObjectType, locals(), indent, useThis=False)
                        arrayProcess = ''.join(arrayBuilder)
                    else:
                        arrayName = makeGenVar('{arg.name}Array', None, handleObjectType, locals(), indent, useThis=False)
                        arrayNameSet = makeGenVar('{arg.name}Array', arg.name, handleObjectType, locals(), indent + 4, addType=False, useThis=False)
                        arrayProcess = makeGenCond('{struct_prefix}{arg.name} != NULL', [arrayNameSet] + arrayBuilder, [], locals(), indent)

                    local_header.append(arrayName + arrayProcess)
                    local_body.append(makeOutStructSet('{arg.name}Array', locals(), is_last_arg, indent))
                elif self.is_enum(arg.base_type) or self.is_flags(arg.base_type):
                    argHandler = [
                        makeGenVar('{arg.name}Array', None, handleObjectType, locals(), indent, useThis=False),
                        makeGenCond('{struct_prefix}{arg.name} != NULL', [
                            makeGen('std::string {arg.name}Values;', locals(), indent + 4),
                            makeGenLoop('idx', '{lengths[0]}', [
                                makeGen('{arg.name}Values += util::ToString<{arg.base_type}>({struct_prefix}{arg.name}[idx]) + ", ";', locals(), indent + 8),
                            ], locals(), indent + 4),
                            makeGenVar('{arg.name}Array', '{arg.name}', handleObjectType, locals(), indent + 4, addType=False, useThis=False),
                            printOutStream(['"{arg.base_type} "', '{arg.name}Array', '"[] = {{"', '{arg.name}Values', '"}};"'], locals(), indent + 4)
                        ], [], locals(), indent),
                    ]
                    local_header.append(''.join(argHandler))
                    local_body.append(makeOutStructSet('{arg.name}Array', locals(), is_last_arg, indent))
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
        header.append(makeGen('std::stringstream structBody;', locals(), indent))
        struct_prefix = 'structInfo->'

        if structName in self.overrideStructs:
            body.append(makeGenVar('varname', 'override', None, locals(), indent, useThis=False))
            body.append(printOutStream(['"{structName} "', 'varname', '" {{}};"'], locals(), indent))
            body.append(printOutStream(['"Override{structName}(&"', 'varname', '", "', '"appdata"', '");"'], locals(), indent))
            body.append(makeGen('return varname;', locals(), indent))
            return body

        for arg in structMembers:
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

            body.append(makeGen('/* {arg.name} */', locals(), 0))
            isLastArg = arg == structMembers[-1]

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
                for count in range(len(lengths)):
                    if not lengths[count].isupper() and not lengths[count].isnumeric():
                        lengths[count] = struct_prefix + lengths[count]

            num_lengths = len(lengths)

            if arg.name == 'pNext':
                header, body = self.handlePNext(struct_prefix, indent, header, body)

            elif arg.base_type == 'char':
                header, body = self.handleChar(struct_prefix, arg, indent, header, body, isLastArg)

            elif arg.base_type in ['float', 'int32_t', 'uint32_t', 'VkClearValue', 'VkRect2D'] and arg.is_pointer:
                header, body = self.handleBasicPointer(struct_prefix, arg, num_lengths, lengths, indent, header, body, isLastArg)

            elif arg.base_type in vkLUType:
                header, body = self.handleLargeUint(struct_prefix, arg, num_lengths, lengths, indent, header, body, isLastArg)

            elif self.is_output_parameter(arg):
                header, body = self.handleOutputParam(struct_prefix, arg, num_lengths, lengths, indent, header, body, isLastArg)

            elif self.is_union(arg.base_type):
                if not arg.is_pointer:
                    if arg.base_type in self.feature_union_members:
                        union_members = self.feature_union_members[arg.base_type]
                        first_member = union_members[0]

                        if first_member.base_type in BasicStringConversionHandledTypes:
                            body.append(makeOutStructSet('{arg_name}.{first_member.name}', locals(), isLastArg, indent))
                        elif self.is_struct(first_member.base_type):

                            argHandler = [
                                makeGenVarCall('std::string',
                                                '{first_member.name}InfoVar',
                                                'GenerateStruct_{first_member.base_type}',
                                                ['out',
                                                '&{arg_name}.{first_member.name}',
                                                'metainfo->{arg.name}->{first_member.name}',
                                                'consumer'],
                                                locals(), indent),
                            ]
                            header.append(''.join(argHandler))

                            body.append(makeOutStructSet('{first_member.name}InfoVar', locals(), isLastArg, indent))
                        else:
                            body.append(makeOutStructSet('VulkanCppConsumerBase::BuildValue({arg_name}.{first_member.name})', locals(), isLastArg, indent))
                    else:
                        body.append(makeOutStructSet('VulkanCppConsumerBase::BuildValue({arg_name})', locals(), isLastArg, indent))
                else:
                    #if arg.base_type in ['VkClearColorValue', 'VkComponentMapping', 'VkOffset2D', 'VkExtent2D']:
                    body.append(makeGenVar('tmp{arg.name}', '{arg.name}', handleObjectType, locals(), indent, useThis=False))
                    body.append(makeOutStructSet('VulkanCppConsumerBase::BuildValue({arg_name})', locals(), isLastArg, indent + 4))
            elif self.is_struct(arg.base_type) and arg.base_type not in self.LOCAL_STRUCT_BLACKLIST:
                if not arg.is_pointer:
                    argHandler = [
                        makeGenVarCall('std::string',
                                        '{arg.name}InfoVar',
                                        'GenerateStruct_{arg.base_type}',
                                        ['out',
                                        '&{arg_name}',
                                        'metainfo->{arg.name}',
                                        'consumer'],
                                        locals(), indent),
                    ]
                    header.append(''.join(argHandler))

                    body.append(makeOutStructSet('{arg.name}InfoVar', locals(), isLastArg, indent))
                else:
                    if num_lengths > 0:
                        if num_lengths > 1:
                            indent = 4
                            structBuild = makeGenVar('{arg.name}Array', None, handleObjectType, locals(), indent, useThis=False)
                            space = (' ' * indent)
                            structBuild += f'{space}if ({arg_name} != NULL) {{\n'
                            indent = 8
                            structBuild += makeGenVar('{arg.name}Array', arg.name, handleObjectType, locals(), indent, addType=False, useThis=False)
                            structBuild += makeGen('std::string {arg.name}Names;', locals(), indent)

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

                            structBuild += makeGen('std::string varName = "NULL";', locals(), indent)
                            space = (' ' * indent)
                            
                            if still_is_pointer:
                                structBuild += f'{space}{arg_name}{var_suffix} != NULL) {{'
                                indent = indent + 4

                            structBuild += makeGenVarCall(None,
                                                    'varName',
                                                    'GenerateStruct_{arg.base_type}',
                                                    ['out',
                                                        '{member_prefix}{arg_name}{var_suffix}{member_suffix}',
                                                        '{member_prefix}metainfo->{arg.name}->GetMetaStructPointer(){var_suffix}{member_suffix}',
                                                        'consumer'], locals(), indent)
                            structBuild += makeGen('{arg.name}Names += varName + ", ";', locals(), indent)

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
                                makeGenVar('{arg.name}Array', None, handleObjectType, locals(), indent, useThis=False),
                                makeGenCond('{arg_name} != NULL', [
                                    makeGenVar('{arg.name}Array', arg.name, handleObjectType, locals(), indent + 4, addType=False, useThis=False),
                                    makeGen('std::string {arg.name}Names;', locals(), indent + 4),
                                    makeGenLoop('idx', '{lengths[0]}', [
                                        makeGen('std::string varName = "NULL";', locals(), indent + 8),
                                        makeGenCond('{arg_name} + idx != NULL', [
                                            makeGenVarCall(None,
                                                        'varName',
                                                        'GenerateStruct_{arg.base_type}',
                                                        ['out',
                                                            '{arg_name} + idx',
                                                            'metainfo->{arg.name}->GetMetaStructPointer() + idx',
                                                            'consumer'],
                                                        locals(), indent + 12),
                                        ], [], locals(), indent + 8),
                                        makeGen('{arg.name}Names += varName + ", ";', locals(), indent + 8),
                                    ], locals(), indent + 4),
                                    printOutStream(['"{arg.base_type} "', '{arg.name}Array', '"[] = {{"', '{arg.name}Names', '"}};"'], locals(), indent + 4),
                                ], [], locals(), indent)
                            ]
                        header.append(''.join(structBuild))
                        body.append(makeOutStructSet('{arg.name}Array', locals(), isLastArg, indent))
                    else:
                        prefixVar = "prefix_{arg.name}".format(**locals())
                        # Make sure if the sub struct pointer during capture processing does contain data and it is not a NULL value.
                        structBuild = [
                            makeGenVar('{arg.name}Struct', None, handleObjectType, locals(), indent, useThis=False),
                            makeGenCond('{arg_name} != NULL', [
                                makeGenVarCall(None,
                                               '{arg.name}Struct',
                                               'GenerateStruct_{arg.base_type}',
                                               ['out',
                                                '{arg_name}',
                                                'metainfo->{arg.name}->GetMetaStructPointer()',
                                                'consumer'],
                                               locals(), indent + 4),
                                makeGen('{arg.name}Struct.insert(0, "&");', locals(), indent + 4),
                            ], [], locals(), indent),
                        ]
                        header.append(''.join(structBuild))
                        body.append(makeOutStructSet('{arg.name}Struct', locals(), isLastArg, indent))
                # TODO:
                # structArguments = []
                # for subArg in self.feature_struct_members[arg.base_type]:
                #     structArguments.append('{struct_prefix}{structName}.{structMemberName}\n'.format(structName=arg.name, structMemberName=subArg.name))
                # body += '    out << varname << ".{argName} = {{ " << {structArgs}    << "}};" << std::endl;\n'.format(argName=arg.name, structArgs='    << "," << '.join(structArguments))

            elif self.is_enum(arg.base_type) or self.is_flags(arg.base_type):
                header, body = self.handleEnum(struct_prefix, arg, num_lengths, lengths, indent, header, body, isLastArg)

            elif self.is_handle(arg.base_type):
                header, body = self.handleHandle(struct_prefix, arg, num_lengths, lengths, indent, header, body, isLastArg)

            elif self.is_input_pointer(arg) and arg.is_array:
                header, body = self.handleInputArray(struct_prefix, arg, num_lengths, lengths, indent, header, body, isLastArg)

            else:
                body.append(makeOutStructSet('{arg_name}', locals(), isLastArg, indent))

        if structName in self.feature_struct_aliases:
            structName = self.feature_struct_aliases[structName]
        body.append(makeGen('std::string varname = consumer.GetExistingStruct(structBody);', locals(), indent))

        var_list = []

        # If we already have a variable we're going to overwrite, just set the variable = to the new values.
        # Otherwise, we need to define a new variable
        if structName in self.trackedStructs:
            var_list.append('varname')
            var_list.append('" = {{"')
        else:
            var_list.append(f'"{structName} "')
            var_list.append('varname')
            var_list.append('" {{"')

        # convert name: Vk<StructName> => <structName>
        # TODO: maybe improve this a bit?
        structVarName = structName
        if structVarName.startswith("Vk"):
            structVarName = structVarName[2:]

        structVarName = structVarName[0].lower() + structVarName[1:]

        # insert the header up front (where all the variables are defined)
        body.append(makeGenCond('!varname.length()', [
            makeGen('varname = consumer.AddStruct(structBody, "{structVarName}");', locals(), indent + 4),
            printOutStream(var_list, locals(), indent + 4),
            printOutStream(['structBody.str()'], locals(), indent + 4),
            printOutStream(['"}};"'], locals(), indent + 4)
        ], [], locals(), indent))
        body.append(makeGen('return varname;', locals(), indent))

        func = []
        func.extend(header)
        func.extend(body)
        return func
