#!/usr/bin/python3 -i
#
# Copyright (c) 2021 Samsung
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


from base_generator import *
from vulkan_cpp_consumer_body_generator import CPP_CONSUMER_ADD_EXTENSION_PAT, \
    CPP_CONSUMER_REMOVE_EXTENSION_PAT, CPP_CONSUMER_VULKAN_VERSION_PAT, CPP_REQUIRED_EXTENSIONS, \
    makeGen, makeGenVar, makeGenVarCall, makeGenCond, makeGenConditions, makeGenLoop, makeOutStructSet, printOutStream, \
    getExtApiStructs
from reverse_alias_mapping import getReverseAliasMap


class VulkanCppStructGeneratorOptions(BaseGeneratorOptions):
    """Options for generating structs"""

    def __init__(self,
                 blacklists = None,         # Path to JSON file listing apicalls and structs to ignore.
                 platform_types = None,      # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
                 filename = None,
                 directory = '.',
                 prefix_text = '',
                 protect_file = False,
                 protect_feature = True,
                 versions = CPP_CONSUMER_VULKAN_VERSION_PAT,
                 add_extensions = CPP_CONSUMER_ADD_EXTENSION_PAT,
                 remove_extensions = CPP_CONSUMER_REMOVE_EXTENSION_PAT):
        BaseGeneratorOptions.__init__(self, blacklists=blacklists, platform_types=platform_types,
                                      filename=filename, directory=directory, prefix_text=prefix_text,
                                      protect_file=protect_file, protect_feature=protect_feature,
                                      versions=versions, default_extensions="dis",
                                      add_extensions=add_extensions,
                                      remove_extensions=remove_extensions)


# VulkanCppStructGenerator - subclass of BaseGenerator.
# Generates vulkan struct generating functions
class VulkanCppStructGenerator(BaseGenerator):
    """Generates code for generating structs"""

    def __init__(
        self, err_file = sys.stderr, warn_file = sys.stderr, diag_file = sys.stdout
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

        self.overrideStructs = [
            'VkXcbSurfaceCreateInfoKHR',
            'VkWaylandSurfaceCreateInfoKHR', #-> vkCreateWaylandSurfaceKHR
            'VkAndroidSurfaceCreateInfoKHR',
        ]

        # The generation of these structs are managed by manually.
        self.STRUCT_BLACKLIST = [
            'VkPresentInfoKHR',
            'VkAllocationCallbacks',
            'VkApplicationInfo',
            'VkInstanceCreateInfo',
            'VkShaderModuleCreateInfo',
            'VkPipelineCacheCreateInfo',
            'VkDescriptorUpdateTemplateCreateInfo',
            'VkDescriptorImageInfo',
            'VkMemoryAllocateInfo',
            'VkDescriptorUpdateTemplateEntry'
        ]

        self.structDeclHeaders = []
        self.extApiStructs = []
        self.reverseAliasMap = {}

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
        self.reverseAliasMap = getReverseAliasMap(self)
        self.extApiStructs = getExtApiStructs(self.featureDictionary)

        if self.is_header:
            self.writeout('#ifndef  GFXRECON_GENERATED_VULKAN_CPP_STRUCT')
            self.writeout('#define  GFXRECON_GENERATED_VULKAN_CPP_STRUCT')
            self.newline()
            self.writeout('#include "util/defines.h"')
            self.writeout('#include "vulkan/vulkan.h"')
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
        if self.is_header:
            self.writeout('#endif')

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def need_feature_generation(self):
        if self.struct_names:
            return True
        return False

    def generate_feature(self):
        structnames = self.get_filtered_struct_names()
        structnames.sort()

        # Insert the declaration of GenerateStruct functions.
        for structName in structnames:
            # TODO(tkeri): hack to skip structures from `video.xml`.
            if 'Video' in structName:
                continue
            structAlias = structName
            if structName in self.reverseAliasMap:
                structAlias = self.reverseAliasMap[structName]
            structdef = 'std::string GenerateStruct_{structName}(std::ostream &out, const {structName}* structInfo, ' \
                         'Decoded_{structName}* metainfo, ' \
                         'VulkanCppConsumerBase &consumer)'.format(structName=structAlias)
            if self.is_header:
                structdef += ';'
            else:
                structdef += '{\n'
                structdef += ''.join(self.makeStructDeclBody(structName))
                structdef += '}\n'
            self.writeout(structdef)

    #
    # Generate structure declaration body.
    def makeStructDeclBody(self, structName):
        structMembers = self.feature_struct_members[structName]
        vkLUType = ['VkDeviceSize', 'uint64_t']
        body = []
        body.append(makeGen('std::stringstream structBody;', locals(), indent=4))

        if structName in self.overrideStructs:
            body.append(makeGenVar('varname', 'override', locals(), indent=4, useThis=False))
            body.append(printOutStream(['"{structName} "', 'varname', '" {{}};"'], locals(), indent=4))
            body.append(printOutStream(['"Override{structName}(&"', 'varname', '", "', '"appdata"', '");"'], locals(), indent=4))
            body.append(makeGen('return varname;', locals(), indent=4))

            return body

        # convert name: Vk<StructName> => <structName>
        # TODO: maybe improve this a bit?
        structVarName = structName
        if structVarName.startswith("Vk"):
            structVarName = structVarName[2:]

        structVarName = structVarName[0].lower() + structVarName[1:]

        for arg in structMembers:
            originalBaseType = arg.base_type
            if arg.base_type in self.reverseAliasMap:
                arg.base_type = self.reverseAliasMap[arg.base_type]
            body.append(makeGen('/* {arg.name} */', locals(), indent=0))
            isLastArg = arg == structMembers[-1]

            if arg.name == 'pNext':
                body.append(makeGen('std::string pNextName = GenerateExtension(out, structInfo->pNext, metainfo->pNext, consumer);', indent=4))
                body.append(makeOutStructSet('pNextName', locals(), isLastArg, indent=4))
            elif arg.base_type in ['char']:
                if arg.is_pointer and arg.pointer_count > 1:
                    escapedStringArrayName = '{arg.name}Var'.format(**locals())
                    header = [
                        makeGenVar(escapedStringArrayName, None, locals(), indent=4, useThis=False),
                        makeGenCond('structInfo->{arg.array_length}',
                                    [makeGenVar(escapedStringArrayName, '{arg.name}', locals(), indent=8, addType=False, useThis=False),
                                     printOutStream(['"const char* "',
                                                     escapedStringArrayName,
                                                     '"[] = "',
                                                     'VulkanCppConsumerBase::escapeStringArray(structInfo->{arg.name}, structInfo->{arg.array_length})',
                                                     '";"'], locals(), indent=8)], [], locals(), indent=4)]
                    body.insert(0, ''.join(header))
                    body.append(makeOutStructSet(escapedStringArrayName, locals(), isLastArg, indent=4))
                else:
                    body.append(makeOutStructSet('VulkanCppConsumerBase::toEscape(structInfo->{arg.name})', locals(), isLastArg, indent=4))

            elif arg.base_type in ['float', 'int32_t', 'uint32_t', 'VkClearValue', 'VkRect2D'] and arg.is_pointer:
                assert arg.pointer_count == 1, "Allow only a simple array"
                argHandler = [
                    makeGenVar('{arg.name}Array', None, locals(), indent=4, useThis=False),
                    makeGenCond('structInfo->{arg.name} != NULL', [
                        makeGenVar('{arg.name}Array', '{arg.name}', locals(), indent=8, addType=False, useThis=False),
                        printOutStream(['"{arg.base_type} "', '{arg.name}Array << "[] = "',
                                        'VulkanCppConsumerBase::BuildValue(structInfo->{arg.name}, structInfo->{arg.array_length})',
                                        '";"'], locals(), indent=8)], [], locals(), indent=4)]
                body.insert(0, ''.join(argHandler))
                body.append(makeOutStructSet('{arg.name}Array', locals(), isLastArg, indent=4))

            elif arg.base_type in vkLUType:
                if arg.is_array:
                    strArrayName = '{arg.name}Array'.format(**locals())

                    body.insert(0, makeGenVar('{strArrayName}', '{strArrayName}', locals(), indent=4, addType=True, useThis=False)),
                    body.insert(1, makeGenCond('{arg.array_length} > 0', [
                        makeGenVarCall('std::string', '{arg.name}Values', 'toStringJoin',
                                       ['structInfo->{arg.name}',
                                        'structInfo->{arg.name} + {arg.array_length}',
                                        '[]({arg.base_type} current) {{ return std::to_string(current); }}',
                                        '", "'], locals(), indent=8),
                        makeGenConditions([
                            ['{arg.array_length} == 1', [makeGen('{arg.name}Array = "&" + {arg.name}Values;', locals(), indent=12)]],
                            ['{arg.array_length} > 1', [printOutStream(['"{arg.base_type} "', '{arg.name}Array', '"[] = {{"', '{arg.name}Values', '"}};"'], locals(), indent=12)]],
                            # No need for else case
                        ], locals(), indent=8),
                    ], [], locals(), indent=4))
                    body.append(makeOutStructSet('"{{ *" << {arg.name}Array << " }}"', locals(), isLastArg, indent=4))
                else:
                    body.append(makeOutStructSet('structInfo->{arg.name} << "UL"', locals(), isLastArg, indent=4))

            elif self.is_output_parameter(arg):
                # TODO: is the output parameter okay here?
                if not arg.is_array:
                    body.append(self.generateTodoFor(arg.name + " (output?)", indent=4))
                else:
                    if arg.array_length_value is None:
                        body.append(makeOutStructSet('VulkanCppConsumerBase::BuildValue(structInfo->{arg.name}, {arg.array_length})', locals(), isLastArg, indent=4))
                    else: # arg.array_length_value
                        if self.is_struct(arg.base_type):
                            innerIndent = 8 if not arg.array_capacity else 4

                            arrayBuilder = [
                                makeGen('std::string {arg.name}Names;', locals(), indent=innerIndent),
                                makeGenLoop('idx', 'idx < structInfo->{arg.array_length}', [
                                    makeGen('std::string varName = "NULL";', indent=innerIndent + 4),
                                    makeGenCond('structInfo->{arg.name} + idx != NULL', [
                                        makeGenVarCall(None,
                                                       'varName',
                                                       'GenerateStruct_{arg.base_type}',
                                                       ['out',
                                                        'structInfo->{arg.name} + idx',
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
                                arrayName = makeGenVar('{arg.name}Array', arg.name, locals(), indent=4, useThis=False)
                                arrayProcess = ''.join(arrayBuilder)
                            else:
                                arrayName = makeGenVar('{arg.name}Array', None, locals(), indent=4, useThis=False)
                                arrayNameSet = makeGenVar('{arg.name}Array', arg.name, locals(), indent=8, addType=False, useThis=False)
                                arrayProcess = makeGenCond('structInfo->{arg.name} != NULL', [arrayNameSet] + arrayBuilder, [], locals(), indent=4)

                            body.insert(0, arrayName + arrayProcess)
                            body.append(makeOutStructSet('{arg.name}Array', locals(), isLastArg, indent=4))
                        elif self.is_enum(arg.base_type) or self.is_flags(arg.base_type):
                            argHandler = [
                                makeGenVar('{arg.name}Array', None, locals(), indent=4, useThis=False),
                                makeGenCond('structInfo->{arg.name} != NULL', [
                                    makeGen('std::string {arg.name}Values;', locals(), indent=8),
                                    makeGenLoop('idx', 'idx < structInfo->{arg.array_length}', [
                                        makeGen('{arg.name}Values += util::ToString<{originalBaseType}>(structInfo->{arg.name}[idx]) + ", ";', locals(), indent=12),
                                    ], locals(), indent=8),
                                    makeGenVar('{arg.name}Array', '{arg.name}', locals(), indent=8, addType=False, useThis=False),
                                    printOutStream(['"{arg.base_type} "', '{arg.name}Array', '"[] = {{"', '{arg.name}Values', '"}};"'], locals(), indent=8)
                                ], [], locals(), indent=4),
                            ]
                            body.insert(0, ''.join(argHandler))
                            body.append(makeOutStructSet('{arg.name}Array', locals(), isLastArg, indent=4))
                        else:
                            body.append(self.generateTodoFor(arg.name + " (output with array length value?)", indent=4))

            elif self.is_struct(arg.base_type):
                if not arg.is_pointer:
                    # The clear colors are handled in special ways as they are unions
                    if arg.base_type in ['VkClearValue', 'VkClearColorValue', 'VkComponentMapping', 'VkOffset2D', 'VkOffset3D','VkExtent2D', 'VkRect2D',
                                        'VkExtent3D', 'VkImageSubresourceRange', 'VkImageSubresourceLayers', 'VkStencilOpState']:
                        body.append(makeOutStructSet('VulkanCppConsumerBase::BuildValue(structInfo->{arg.name})', locals(), isLastArg, indent=4))
                        continue
                    else:
                        if structName not in self.extApiStructs:
                            argHandler = [
                                makeGenVarCall('std::string',
                                               '{arg.name}InfoVar',
                                               'GenerateStruct_{arg.base_type}',
                                               ['out',
                                                '&structInfo->{arg.name}',
                                                'metainfo->{arg.name}',
                                                'consumer'],
                                               locals(), indent=4),
                            ]
                            body.insert(0, ''.join(argHandler))

                            body.append(makeOutStructSet('{arg.name}InfoVar', locals(), isLastArg, indent=4))
                        else:
                            infoVarName = "{arg.name}".format(**locals())
                            body.append(makeGenVar('{arg.name}InfoVar', '{infoVarName}', locals(), indent=4, addType=True, useThis=False))
                            body.append(makeGen('out << "{arg.full_type} " << {arg.name}InfoVar + ";" << std::endl;', locals(), indent=4))

                            body.append(makeOutStructSet('{arg.name}InfoVar', locals(), isLastArg, indent=4))

                elif arg.is_pointer:
                    # TODO(tkeri): What case is TRUE?
                    if arg.base_type in ['VkClearColorValue', 'VkComponentMapping', 'VkOffset2D', 'VkExtent2D']:
                        body.append(makeGenVar('tmp{arg.name}', '{arg.name}', locals(), indent=4, useThis=False))
                        body.append(makeOutStructSet('VulkanCppConsumerBase::BuildValue(structInfo->{arg.name})', locals(), isLastArg, indent=8))
                        continue

                if arg.is_pointer:
                    if arg.array_length:
                        structBuild = [
                            makeGenVar('{arg.name}Array', None, locals(), indent=4, useThis=False),
                            makeGenCond('structInfo->{arg.name} != NULL', [
                                makeGenVar('{arg.name}Array', arg.name, locals(), indent=8, addType=False, useThis=False),
                                makeGen('std::string {arg.name}Names;', locals(), indent=8),
                                makeGenLoop('idx', 'idx < structInfo->{arg.array_length}', [
                                    makeGen('std::string varName = "NULL";', indent=12),
                                    makeGenCond('structInfo->{arg.name} + idx != NULL', [
                                        makeGenVarCall(None,
                                                       'varName',
                                                       'GenerateStruct_{arg.base_type}',
                                                       ['out',
                                                        'structInfo->{arg.name} + idx',
                                                        'metainfo->{arg.name}->GetMetaStructPointer() + idx',
                                                        'consumer'],
                                                       locals(), indent=16),
                                    ], [], locals(), indent=12),
                                    makeGen('{arg.name}Names += varName + ", ";', locals(), indent=12),
                                ], locals(), indent=8),
                                printOutStream(['"{arg.base_type} "', '{arg.name}Array', '"[] = {{"', '{arg.name}Names', '"}};"'], locals(), indent=8),
                            ], [], locals(), indent=4)
                        ]
                        body.insert(0, ''.join(structBuild))
                        body.append(makeOutStructSet('{arg.name}Array', locals(), isLastArg, indent=4))
                    else:
                        prefixVar = "prefix_{arg.name}".format(**locals())
                        # Make sure if the sub struct pointer during capture processing does contain data and it is not a NULL value.
                        structBuild = [
                            makeGenVar('{arg.name}Struct', None, locals(), indent=4, useThis=False),
                            makeGenCond('structInfo->{arg.name} != NULL', [
                                makeGenVarCall(None,
                                               '{arg.name}Struct',
                                               'GenerateStruct_{arg.base_type}',
                                               ['out',
                                                'structInfo->{arg.name}',
                                                'metainfo->{arg.name}->GetMetaStructPointer()',
                                                'consumer'],
                                               locals(), indent=8),
                                makeGen('{arg.name}Struct.insert(0, "&");', locals(), indent=8),
                            ], [], locals(), indent=4),
                        ]
                        body.insert(0, ''.join(structBuild))
                        body.append(makeOutStructSet('{arg.name}Struct', locals(), isLastArg, indent=4))
                # TODO:
                # structArguments = []
                # for subArg in self.feature_struct_members[arg.base_type]:
                #     structArguments.append('structInfo->{structName}.{structMemberName}\n'.format(structName=arg.name, structMemberName=subArg.name))
                # body += '    out << varname << ".{argName} = {{ " << {structArgs}    << "}};" << std::endl;\n'.format(argName=arg.name, structArgs='    << "," << '.join(structArguments))

            elif self.is_enum(arg.base_type) or self.is_flags(arg.base_type):
                if arg.is_pointer:
                    # TODO: Possibly an array of enum/flag values?
                    if arg.array_length:
                        # VkPipelineStageFlags waitStages[] = { VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT };
                        # submitInfo.pWaitDstStageMask = waitStages;
                        arrayName = '{arg.name}Array'.format(arg=arg)

                        argHandler = [
                            makeGen('std::string {arg.name}Values;', locals(), indent=4),
                            makeGenVar(arrayName, None, locals(), indent=4, useThis=False),
                            makeGenCond('structInfo->{arg.name} != NULL', [
                                makeGenLoop('idx', 'idx < structInfo->{arg.array_length}', [
                                    makeGen('{arg.name}Values += util::ToString<{originalBaseType}>(structInfo->{arg.name}[idx]) + ", ";', locals(), indent=12),
                                ], locals(), indent=8),
                                makeGenVar(arrayName, '{arg.name}', locals(), indent=8, addType=False, useThis=False),
                                printOutStream(['"{arg.base_type} "', arrayName, '"[] = {{"', '{arg.name}Values', '"}};"'], locals(), indent=8)
                            ], [], locals(), indent=4),
                        ]
                        body.insert(0, ''.join(argHandler))
                        body.append(makeOutStructSet(arrayName, locals(), isLastArg, indent=4))
                    else:
                        body.append(self.generateTodoFor(arg.name + '(Enum/flag pointer)', indent=4))
                else:
                    body.append(makeOutStructSet('"{arg.base_type}(" << structInfo->{arg.name} << ")"', locals(), isLastArg, indent=4))

            elif self.is_handle(arg.base_type):
                if arg.is_array:
                    # Generate an array of strings containing the handle id names
                    strArrayName = arg.name + "Array"

                    body.insert(0, makeGenCond('metainfo->{arg.name}.GetPointer() != NULL && structInfo->{arg.array_length} > 0', [
                        makeGenVar('{strArrayName}', '{strArrayName}', locals(), indent=8, addType=False, useThis=False),
                        makeGenVarCall('std::string', '{arg.name}Values', 'toStringJoin',
                                       ['metainfo->{arg.name}.GetPointer()',
                                        'metainfo->{arg.name}.GetPointer() + structInfo->{arg.array_length}',
                                        '[&](const format::HandleId current) {{ return consumer.GetHandle(current); }}',
                                        '", "'], locals(), indent=8),
                        makeGenConditions([
                            ['structInfo->{arg.array_length} == 1', [makeGen('{arg.name}Array = "&" + {arg.name}Values;', locals(), indent=12)]],
                            ['structInfo->{arg.array_length} > 1', [printOutStream(['"{arg.base_type} "', '{arg.name}Array', '"[] = {{"', '{arg.name}Values', '"}};"'], locals(), indent=12)]],
                            # No need for else case
                        ], locals(), indent=8),
                    ], [], locals(), indent=4))

                    body.insert(0, makeGenVar('{strArrayName}', None, locals(), indent=4, useThis=False))
                    body.append(makeOutStructSet('{strArrayName}', locals(), isLastArg, indent=4))
                else:
                    body.append(makeOutStructSet('consumer.GetHandle(metainfo->{arg.name})', locals(), isLastArg, indent=4))
            elif self.is_input_pointer(arg) and arg.is_array:
                if arg.array_length:
                    arrayElementType = 'uint8_t' if arg.base_type == 'void' else arg.base_type

                    loopCondition = '{arg.array_length}'.format(**locals())
                    varNameArrayLength = getattr(arg.array_length_value, 'name', None)
                    # Substitute the variable occurrence with the proper variable reference.
                    # This is required if the size of the array is an expression.
                    if varNameArrayLength:
                        loopCondition = re.sub(varNameArrayLength, 'structInfo->{varNameArrayLength}'.format(**locals()), loopCondition)

                    argHandler = [
                        makeGenVar('{arg.name}Array', None, locals(), indent=4, useThis=False),
                        makeGenCond('structInfo->{arg.name} != NULL', [
                            makeGen('std::string {arg.name}Values;', locals(), indent=8),
                            makeGen('const {arrayElementType}* {arg.name}Pointer = ({arrayElementType}*)structInfo->{arg.name};', locals(), indent=8, addType=False),
                            makeGenLoop('idx', 'idx < {loopCondition}', [
                                makeGen('{arg.name}Values += std::to_string({arg.name}Pointer[idx]) + ", ";', locals(), indent=12),
                            ], locals(), indent=8),
                            makeGenVar('{arg.name}Array', '{arg.name}', locals(), indent=8, addType=False, useThis=False),
                            printOutStream(['"{arrayElementType} "', '{arg.name}Array', '"[] = {{"', '{arg.name}Values', '"}};"'], locals(), indent=8)
                        ], [], locals(), indent=4),
                    ]
                    body.insert(0, ''.join(argHandler))
                    body.append(makeOutStructSet('{arg.name}Array', locals(), isLastArg, indent=4))
                else:
                    body.append(self.generateTodoFor(arg.name + '(input pointer)', indent=4))
            else:
                body.append(makeOutStructSet('structInfo->{arg.name}', locals(), isLastArg, indent=4))

        if structName in self.reverseAliasMap:
            structName = self.reverseAliasMap[structName]
        body.append(makeGen('std::string varname = consumer.GetExistingStruct(structBody);', locals(), indent=4))
        body.append(makeGenCond('!varname.length()', [
            makeGen('varname = consumer.AddStruct(structBody, "{structVarName}");', locals(), indent=8),
            printOutStream(['"{structName} "', 'varname', '" {{"'], locals(), indent=8),
            printOutStream(['structBody.str()'], locals(), indent=8),
            printOutStream(['"}};"'], locals(), indent=8)
        ], [], locals(), indent=4))
        body.append(makeGen('return varname;', locals(), indent=4))

        return body
