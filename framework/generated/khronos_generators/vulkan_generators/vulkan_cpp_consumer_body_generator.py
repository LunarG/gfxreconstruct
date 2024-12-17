#!/usr/bin/python3 -i
#
# Copyright (c) 2020 Samsung
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

import sys
from vulkan_base_generator import VulkanBaseGenerator, VulkanBaseGeneratorOptions, write

# Copyright text prefixing all headers (list of strings).
CPP_PREFIX_STRING = [
    '/*',
    '** Copyright (c) 2020 Samsung',
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

# TODO: Copied from vulkan_base_generator.py.
def makeREstring(argList, defaultValue = None):
    if (len(argList) > 0) or (defaultValue is None):
        return '^(' + '|'.join(argList) + ')$'
    else:
        return defaultValue

def getExtApiStructs(featureDictionary):
    extApiStructs = []
    for extension in CPP_REQUIRED_EXTENSIONS:
        extDict = featureDictionary[extension]
        extStructs = list(extDict['struct'].values())
        extApiStructs.extend([item for subList in extStructs for item in subList if item is not None])
    extApiStructs = [item.split(',') for item in extApiStructs]
    return [item for subList in extApiStructs for item in subList]

CPP_REQUIRED_EXTENSIONS = [
    'VK_EXT_inline_uniform_block',
    'VK_EXT_memory_budget',
    'VK_EXT_separate_stencil_usage',
    'VK_KHR_android_surface',
    'VK_KHR_create_renderpass2',
    'VK_KHR_descriptor_update_template',
    'VK_KHR_draw_indirect_count',
    'VK_KHR_get_memory_requirements2',
    'VK_KHR_get_physical_device_properties2',
    'VK_KHR_image_format_list',
    'VK_KHR_maintenance1',
    'VK_KHR_maintenance2',
    'VK_KHR_multiview',
    'VK_KHR_surface',
    'VK_KHR_swapchain',
    'VK_KHR_swapchain_mutable_format',
    'VK_KHR_wayland_surface',
    'VK_KHR_xcb_surface',
]

# Extensions can be enabled by specifying them in this list
CPP_OPTIONAL_EXTENSIONS = []

CPP_CONSUMER_ADD_EXTENSION_PAT = makeREstring(CPP_REQUIRED_EXTENSIONS + CPP_OPTIONAL_EXTENSIONS)
CPP_CONSUMER_ADD_OPTIONAL_EXTENSION_PAT = makeREstring(CPP_OPTIONAL_EXTENSIONS)

CPP_CONSUMER_REMOVE_EXTENSION_PAT = None  # makeREstring(['.*'])
CPP_CONSUMER_VULKAN_VERSION = ['VK_VERSION_1_0']

CPP_CONSUMER_VULKAN_VERSION_PAT = makeREstring(CPP_CONSUMER_VULKAN_VERSION)

# These functions have the majority of functionality that is manually generated
CPP_APICALL_GENERATE = [
    # Core functionality - Alphabetical
    'vkAllocateMemory',
    'vkCreateBuffer',
    'vkCreateComputePipelines',
    'vkCreateDescriptorUpdateTemplate',
    'vkCreateDevice',
    'vkCreateGraphicsPipelines',
    'vkCreateInstance',
    'vkCreatePipelineCache',
    'vkCreateShaderModule',
    'vkDestroyDevice',
    'vkEnumeratePhysicalDevices',
    'vkGetBufferMemoryRequirements',
    'vkGetBufferMemoryRequirements2',
    'vkGetDeviceQueue',
    'vkGetFenceStatus',
    'vkGetImageMemoryRequirements',
    'vkGetImageMemoryRequirements2',
    'vkGetImageSparseMemoryRequirements',
    'vkGetPhysicalDeviceQueueFamilyProperties',
    'vkGetPhysicalDeviceSurfaceFormatsKHR',
    'vkGetPhysicalDeviceSurfacePresentModesKHR',
    'vkGetQueryPoolResults',
    'vkMapMemory',
    'vkQueueBindSparse',
    'vkQueueSubmit',
    'vkQueueSubmit2',
    'vkUnmapMemory',
    'vkWaitForFences',

    # KHR functionality - Alphabetical
    'vkAcquireNextImageKHR',
    'vkAcquireNextImage2KHR',
    'vkCreateAndroidSurfaceKHR',
    'vkCreateDescriptorUpdateTemplateKHR',
    'vkCreateSwapchainKHR',
    'vkDestroySwapchainKHR',
    'vkCreateWaylandSurfaceKHR',
    'vkCreateWin32SurfaceKHR',
    'vkCreateXcbSurfaceKHR',
    'vkCreateXlibSurfaceKHR',
    'vkGetBufferMemoryRequirements2KHR',
    'vkGetImageMemoryRequirements2KHR',
    'vkGetSemaphoreFdKHR',
    'vkGetSemaphoreWin32HandleKHR',
    'vkGetSwapchainImagesKHR',
    'vkImportSemaphoreFdKHR',
    'vkImportSemaphoreWin32HandleKHR',
    'vkQueuePresentKHR',
    'vkQueueSubmit2KHR',

    # EXT functionality - Alphabetical
    'vkCreateMetalSurfaceEXT',
    'vkDebugMarkerSetObjectNameEXT',
    'vkDebugMarkerSetObjectTagEXT',
    'vkSetDebugUtilsObjectNameEXT',
    'vkSetDebugUtilsObjectTagEXT',

    # Other extension functionality - Alphabetical
    'vkGetAndroidHardwareBufferPropertiesANDROID',
    'vkGetMemoryAndroidHardwareBufferANDROID',
]

CPP_APICALL_INTERCEPT_LIST = [
    'vkBindBufferMemory',
    'vkBindBufferMemory2',
    'vkBindImageMemory',
    'vkBindImageMemory2',
    'vkCmdBeginRenderPass',
    'vkCreateFramebuffer',
    'vkDestroySemaphore',

    'vkBindImageMemory2KHR',
    'vkBindBufferMemory2KHR',
]

# Disabled wrapping function call into the 'VK_CALL_CHECK' macro call
CPP_APICALL_DO_NOT_CHECK = ['vkGetPhysicalDeviceImageFormatProperties']

def makeSnakeCaseName(camelCaseString):
    new_string = ''.join(['_' + char.lower() if char.isupper() else char for char in camelCaseString]).lstrip('_')
    if new_string.startswith('p_'):
        new_string = new_string.replace('p_', 'p', 1)
    return new_string.replace('_p_', '_p')

def makeGenCall(method, args, arguments=None, indent=4, **kwargs):
    """
    Output a method call into the CPP generator.

    :param method: the name of the method to invoke in the CPP generator.
    :param args: list of arguments used for the method call.
    :param arguments: dictionary containing the key-values used for the string formatting.
    :param indent: indentation size.

    :returns: string representation of the method call which can be inserted into the CPP generator.
    """
    return makeGenVarCall(None, None, method, args, arguments=arguments, indent=indent, **kwargs)


def makeGenVarCall(typeToUse, genName, method, methodArgs, arguments=None, indent=4, **kwargs):
    """
    Output a variable initialization with a method call into the CPP generator.

    :param typeToUse type  (same type as the return value of the given method). Can be None so no type name is added.
    :param genName: the name of the std::string variable used in the CPP generator. Can be None so no assignment is generated.
    :param method: a non void method name.
    :param methodArgs: list of target method arguments.
    :param arguments: dictionary containing the key-values used for the string formatting.
    :param indent: indentation size.

    :returns: method call assigning the value to the 'genName'
    """
    if not arguments:
        arguments = {}

    assignment = ''
    if genName:
        if typeToUse:
            assignment = '{} {} = '.format(typeToUse, genName).format(**arguments, **kwargs)
        else:
            assignment = '{} = '.format(genName).format(**arguments, **kwargs)

    arg_indent = ',\n' + ' ' * (indent + len(method) + 1 + len(assignment))
    padded_args = arg_indent.join(methodArgs)

    return (' ' * indent) + ('%s%s(%s);\n' % (assignment, method, padded_args)).format(**arguments, **kwargs)


def makeGenVar(genName, cppName, handleObjectType=None, arguments=None, indent=4, addType=True, useThis=True):
    """
    Output a usable variable name into the CPP generator.

    :param genName: the name of the std::string variable used in the CPP generator.
    :param cppName: the name of the variable which will be used in the resulting CPP file. If None is passed a "NULL" value will be inserted.
    :param arguments: dictionary containing the key-values used for the string formatting.
    :param indent: indentation size.
    :param addType: if True the 'std::string' type will be added into the output string, otherwise it is a simple assignment.
    :param useThis: use 'this' pointer if True, otherwise access attributes with the object of class.

    :returns: string representation of the std::string variable which can be inserted into the CPP generator.
    """
    typeToUse = ''
    object = 'consumer.'

    if not arguments:
        arguments = {}
    if addType:
        typeToUse = 'std::string ' # note the space!
    if cppName is None:
        return '{}{}{} = "NULL";\n'.format(' ' * indent, typeToUse, genName).format(**arguments)
    if useThis:
        object = 'this->'

    if handleObjectType is None or '_VIEW' in handleObjectType:
        return '{}{}{} = "{}_" + std::to_string({}GetNextId());\n'.format(' ' * indent, typeToUse, genName, cppName, object).format(**arguments)
    else:
        return '{}{}{} = "{}_" + std::to_string({}GetNextId({}));\n'.format(' ' * indent, typeToUse, genName, cppName, object, handleObjectType).format(**arguments)


def makeGenCastVar(cast_type, type_name, target_var_name, source_var_name, use_auto=False, indent=4):
    """
    Create a variable cast in the CPP generator.

    :param cast_type: type of the cast to perform
    :param type_name: name of the type to cast to
    :param target_var_name: name of the variable to cast to
    :param source_var_name: name of the variable to cast from
    :param use_auto: bool whether to use the auto keyword instead
    :param indent: indentation size
    :return:
    """
    if use_auto:
        return ' ' * indent + 'auto %s = %s<%s>(%s);\n' % (target_var_name, cast_type, type_name, source_var_name)
    return ' ' * indent + '%s %s = %s<%s>(%s);\n' % (
        type_name, target_var_name, cast_type, type_name, source_var_name)


def makeGen(statement, arguments=None, indent=4, **kwargs):
    """
    Output a single line into the CPP generator.

    :param genName: statement to format and write out.
    :param arguments: dictionary containing the key-values used for the string formatting.
    :param indent: indentation size.

    :returns: string representation of the statment which can be inserted into the CPP generator.
    """
    if not arguments:
        arguments = {}
    return (' ' * indent) + statement.format(**arguments, **kwargs) + '\n'


def makeCppOutputStream(streamName, indent=4):
    """
    Create a function call to write out contents of a stream into the resulting CPP file.

    :param streamName: the name of the std::stringstream to write its contents into the final CPP.
    :param indent: indentation size.

    :returns:
    """
    return (' ' * indent) + 'fprintf(file, "%s", {streamName}.str().c_str());\n'.format(streamName=streamName)


def makeCppArray(type, name, values, arguments=None, indent=4):
    """
    Create an Array definition in the resulting CPP file.

    :param type: type of the array.
    :param name: name of the array.
    :param values: the array contents for the initializer.
    :param arguments: dictionary containing the key-values used for the string formatting.
    :param indent: indentation size.

    :returns:
    """
    if not arguments:
        arguments = {}
    return (' ' * indent) + (
        'fprintf(file, "\\t\\t{} %s[] = {{{{ %s }}}};\\n", {}.c_str(), {}.c_str());\n'.format(type, name, values).format(**arguments))


def makeGenLoop(loopIdx, max_count, contents, arguments=None, indent=4):
    """
    Create a loop statement in the CPP generator.

    :param loopIdx: loop control variable.
    :param max_count: Maximum count of the loop
    :param contents: list of code lines inside loop body.
    :param arguments: dictionary containing the key-values used for the string formatting.
    :param indent: indentation size.

    :return:
    """
    if not arguments:
        arguments = {}

    lines = [(' ' * indent) + ('for (uint32_t %s = 0; %s < %s; %s++) {{\n' % (loopIdx, loopIdx, max_count, loopIdx)).format(**arguments)] \
            + contents + [(' ' * indent) + '}\n']

    return ''.join(lines)


# TODO: replace this with makeGenConditions?
def makeGenCond(condition, contents_if, contents_else=None, arguments=None, indent=4):
    """
    Create an if/else  statement in the CPP generator.


    :param condition: condition of if/else statement.
    :param contents_if: list of code lines inside if body.
    :param contents_else: list of code lines inside else body.
    :param arguments: dictionary containing the key-values used for the string formatting.
    :param indent: indentation size.

    :return:
    """
    else_cont = [(' ' * indent) + '} else {\n'] + contents_else + [(' ' * indent) + '}\n'] if contents_else else [(' ' * indent) + '}\n']
    lines = [(' ' * indent) + ('if (%s) {\n' % (condition).format(**arguments))] + contents_if + else_cont

    return ''.join(lines)


def makeGenConditions(cases, arguments=None, indent=4):
    """

    :param cases: list of tuples. Each tuple has the (condition, body) format.

    :param arguments: dictionary containing the key-values used for the string formatting.
    :param indent: indentation size.
    :return: formatted cpp code
    """

    indent_str = ' ' * indent

    lines = []
    for idx, case in enumerate(cases):
        # case[0] -> condition
        # case[1] -> body (list)
        if case[0]:
            if idx == 0:
                start = indent_str + 'if'
            else:
                start = ' else if'

            condition = '%s (%s)' % (start, case[0].format(**arguments))
        else:
            condition = ' else'

        lines.append(condition)
        lines.append(' {\n')
        lines.extend(case[1])
        lines.append(indent_str + '}')

    assert len(lines) >= 4, "a single entry should be in the condition"
    lines[-1] += '\n'

    return ''.join(lines)


def makeGenSwitch(condition, cases, case_contents, default_content, indent=4):
    """
    Create a switch statement in the CPP generator.

    :param condition: condition of the switch statement
    :param cases: list of the enum labels
    :param case_contents:  list of list of strings containing the body of each case by line
    :param default_content: list of list of strings containing the body of the default case
    :param indent: indentation size
    :return:
    """
    switch = []
    indentation = ' ' * indent
    switch.append(2 * indentation + 'switch (%s) {\n' % condition)

    for case, case_content in zip(cases, case_contents):
        switch.append(3 * indentation + 'case %s: {\n' % case)
        for line in case_content:
            switch.append(4 * indentation + line)
        switch.append(3 * indentation + '}\n')

    switch.append(3 * indentation + 'default: {\n')
    for line in default_content:
        switch.append(4 * indentation + line)
    switch.append(3 * indentation + '}\n')
    switch.append(2 * indentation + '}\n')

    return ''.join(switch)

def makeObjectType(handle_value):
    return_string='VK_OBJECT_TYPE_'
    value=''

    # Save the extension and get rid of it so we don't parse it out
    extension = ''
    if handle_value.endswith('KHR'):
        extension = '_KHR'
        value = handle_value[2:-3]
    elif handle_value.endswith('EXT'):
        extension = '_EXT'
        value = handle_value[2:-3]
    elif handle_value.endswith('AMD'):
        extension = '_AMD'
        value = handle_value[2:-3]
    elif handle_value.endswith('NVX'):
        extension = '_NVX'
        value = handle_value[2:-3]
    elif handle_value.endswith('NV'):
        extension = '_NV'
        value = handle_value[2:-2]
    elif handle_value.endswith('INTEL'):
        extension = '_INTEL'
        value = handle_value[2:-5]
    elif handle_value.endswith('FUCHSIA'):
        extension = '_FUCHSIA'
        value = handle_value[2:-7]
    else:
        value = handle_value[2:]

    for index, cur_char in enumerate(value):
        if index > 0 and cur_char.isupper():
            return_string += '_'
        return_string += cur_char

    if len(extension) > 0:
        return_string += extension

    return return_string.upper()

def makeOutStructSet(value, arguments=None, isFirstArg=False, isLastArg=False, indent=4):
    """
    Create a structure element setting for the vulkan application.

    :param value: contents of the structure member for the initializer.
    :param arguments: dictionary containing the key-values used for the string formatting.
    :param isLastArg: boolean value if the line should be ended
    :param indent: indentation size.

    :return:
    """
    if not arguments:
        arguments = {}
    lineEnding = '' if isLastArg else ' << std::endl'
    tabs = '\\t' if isFirstArg else '\\t\\t\\t'
    return ((' ' * indent) + 'struct_body << "%s" << %s << ","%s;\n'.format(**arguments) % (tabs, value, lineEnding)).format(**arguments)


def printOutStream(values, arguments=None, indent=4):
    """
    Output a single line into the CPP consumer.


    :param values: list of contents to print the out stream.
    :param arguments: dictionary containing the key-values used for the string formatting.
    :param indent: indentation size.

    :return:
    """
    if not arguments:
        arguments = {}
    return (' ' * indent) + 'out << "\\t\\t" << %s << std::endl;\n' % ' << '.join(values).format(**arguments)

def replacePointerInLength(inString):
    if inString == '':
        return ''
    if inString[:2] == '->':
        new_string = '->GetPointer()->'
        next_index = 2
    else:
        new_string = inString[0]
        next_index = 1
    return new_string + replacePointerInLength(inString[next_index:])

def makeParamList(cmdInfo, additionalParams):
    paramList = [param.name for param in cmdInfo[2]]
    if cmdInfo[0] != 'void':
        paramList.insert(0, 'returnValue')
    paramList.extend(additionalParams)
    return ', '.join(paramList)


class VulkanCppConsumerBodyGeneratorOptions(VulkanBaseGeneratorOptions):
    """Options for generating a C++ class for Vulkan capture file to CPP source generation"""

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


class VulkanCppConsumerBodyGenerator(VulkanBaseGenerator):
    """VulkanCppConsumerBodyGenerator - subclass of VulkanBaseGenerator.
    Generates C++ member definitions for the VulkanCppConsumer class responsible for
    generating a textfile containing decoded Vulkan API call parameter data.
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

        # The generation of these functions are suspended for a while.
        self.skippedApiFuncs = [
            'vkGetPipelineCacheData',
            'vkGetPhysicalDeviceXcbPresentationSupportKHR',
        ]

        # TODO: Don't currently support Nvidia raytracing entrypoints
        self.APICALL_BLACKLIST = [
            'vkCmdBuildAccelerationStructureNV',
            'vkCmdTraceRaysNV',
            'vkCreateAccelerationStructureNV'
        ]

    def writeout(self, *args, **kwargs):
        write(*args, **kwargs, file=self.outFile)

    def beginFile(self, gen_opts):
        """Method override."""
        VulkanBaseGenerator.beginFile(self, gen_opts)

        self.writeout('#include "generated/generated_vulkan_cpp_consumer.h"')
        self.newline()
        self.writeout('#include "decode/vulkan_cpp_consumer_base.h"')
        self.writeout('#include "decode/vulkan_cpp_structs.h"')
        self.writeout('#include "generated/generated_vulkan_cpp_structs.h"')
        self.writeout('#include "generated/generated_vulkan_enum_to_string.h"')
        self.writeout('#include "generated/generated_vulkan_cpp_consumer_extension.h"')
        self.writeout('#include "util/defines.h"')
        self.write_includes_of_common_api_headers(gen_opts)
        self.newline()
        self.writeout('#include <iostream>')
        self.writeout('#include <sstream>')
        self.newline()
        self.writeout('GFXRECON_BEGIN_NAMESPACE(gfxrecon)')
        self.writeout('GFXRECON_BEGIN_NAMESPACE(decode)')
        self.newline()

    def endFile(self):
        """Method override."""
        self.newline()
        self.writeout('GFXRECON_END_NAMESPACE(decode)')
        self.writeout('GFXRECON_END_NAMESPACE(gfxrecon)')

        # Finish processing in superclass
        VulkanBaseGenerator.endFile(self)

    #
    # Indicates that the current feature has C++ code to generate.
    def need_feature_generation(self):
        if self.feature_cmd_params or self.struct_names:
            return True
        return False

    #
    # Performs C++ code generation for the feature.
    def generate_feature(self):
        """Performs C++ code generation for the feature."""
        platform_type = 'Vulkan'

        first = True
        cmdnames = self.get_filtered_cmd_names()
        cmdnames.sort()

        for cmd in cmdnames:
            info = self.feature_cmd_params[cmd]
            return_type = info[0]
            values = info[2]

            cmddef = '' if first else '\n'
            cmddef += self.make_consumer_func_decl(
                return_type,
                '{}CppConsumer::Process_'.format(platform_type) + cmd,
                values
            ) + '\n'
            cmddef += '{\n'

            # If we need to intercept the function early and store some specific data or make a
            # certain API call before the rest of the function continues, do so.
            if cmd in CPP_APICALL_INTERCEPT_LIST:
                paramList = makeParamList(info, [])
                cmddef += makeGen('Intercept_{cmd}({paramList});', locals(), indent=4)


            # If we have a manually generated function, use that, otherwise generate the appropriate
            # information.
            if cmd in CPP_APICALL_GENERATE:
                paramList = makeParamList(info, [])
                cmddef += makeGen('Generate_{cmd}({paramList});', locals(), indent=4)
            else:
                cmddef += makeGen("FILE* file = GetFrameFile();", indent=4)

                #if cmd.startswith('vkCreate'):
                cmddef += '    fprintf(file, "\\t{\\n");\n'

                cmddef += self.makeConsumerFuncBody(return_type, cmd, values)

                #if cmd.startswith('vkCreate'):
                cmddef += '    fprintf(file, "\\t}\\n");\n'

            cmddef += makeGenCall('Post_APICall'.format(cmd), ['format::ApiCallId::ApiCall_' + cmd], locals(), indent=4)

            cmddef += '}'

            write(cmddef, file=self.outFile)
            first = False

    def buildInputArray(self, arg, valueSuffix='', indent=0):
        """
        Build an array of values collection in the CPP consumer for a given argument.

        :param arg: argumentum to read/process.
        :param valueSuffix: suffix characters to use when building the value list (eg.: "UL")
        :param indent: indentation.

        :return: a tuple of (code to insert into CPP consumer, argument for the vk* method invocation, placeholder for fprintf).
        """
        arrayElementType = 'uint8_t' if arg.base_type == 'void' else arg.base_type

        if '->' in arg.array_length:
            new_array_length = replacePointerInLength(arg.array_length)
            arg.array_length = new_array_length

        to_string_type = 'current'
        if arg.is_pointer and arg.pointer_count > 1:
            to_string_type = 'reinterpret_cast<const VkDeviceSize>(current)'

        handleObjectType = None
        if arg.base_type in self.handle_names:
            handleObjectType = makeObjectType(arg.base_type)

        conditional_arg = f'{arg.array_length} > 0'
        if arg.is_optional:
            conditional_arg += f' && {arg.name}->GetPointer() != nullptr'

        arrayVarName = makeSnakeCaseName(arg.name + 'Array')
        valuesVarName = makeSnakeCaseName(arg.name + 'Values')

        output = [
            makeGenVar(arrayVarName, arg.name, handleObjectType, locals(), indent=indent),
            makeGenCond('{conditional_arg}', [
                    makeGenVarCall('std::string', valuesVarName, 'toStringJoin',
                                [f'{arg.name}->GetPointer()', '{arg.name}->GetPointer() + {arg.array_length}',
                                    f'[&](const auto current) {{{{ return std::to_string({to_string_type}) + "{valueSuffix}"; }}}}',
                                    '", "'], locals(), indent=indent+4),
                    makeCppArray('{arrayElementType}', arrayVarName, valuesVarName, locals(), indent=indent + 4)
                ],
                [makeGen(f'{arrayVarName} = "NULL";', locals(), indent=indent+4)],
                locals(), indent=indent),
        ]

        callArg = f'{arrayVarName}.c_str()'
        callTemplate = '%s'

        return ''.join(output), callArg, callTemplate


    #
    # Return VulkanCppConsumer class member function definition.
    def makeConsumerFuncBody(self, returnType, name, values):
        # Add a TODO into the final generated source for skipped functions.
        if name in self.skippedApiFuncs:
            return '    fprintf(file, "// TODO: Support {name} function.\\n");\n'.format(**locals())

        needsToBeLoaded = False
        if not self.featureName.startswith('VK_VERSION_'):
            needsToBeLoaded = True

        valueFormatDict = {
            'char': '%s',
            'int16_t': '%d',
            'uint16_t': '%u',
            'int': '%d',
            'int32_t': '%d',
            'uint32_t': '%u',
            'size_t': '%" PRIu64 "',
            'int64_t': '%" PRId64 "',
            'uint64_t': '%" PRIu64 "',
            'float': '%f',
            'double': '%lf',
            'void': '',
            'VkBool32': '%u',
            'VkDeviceSize': '%" PRIu64 "',
            'VkDeviceAddress': '%" PRIu64 "',
        }
        valueSuffixDict = {
            'VkDeviceSize': 'UL',
            'VkDeviceAddress': 'UL',
            'uint64_t': 'UL',
        }

        body = ''
        callArgs = []
        callTempl = []

        for arg in values:
            originalBaseType = arg.base_type
            if arg.base_type in self.feature_struct_aliases:
                arg.base_type = self.feature_struct_aliases[arg.base_type]

            handleObjectType = None
            if arg.base_type in self.handle_names:
                handleObjectType = makeObjectType(arg.base_type)

            if arg.is_pointer and self.is_struct(arg.base_type) and self.is_input_pointer(arg):
                if arg.base_type == 'VkAllocationCallbacks':
                    callArgs.append('"nullptr"')
                    callTempl.append('%s')
                    continue

                streamName = makeSnakeCaseName(f'stream_{arg.name}')

                body += makeGen('std::stringstream {streamName};', locals(), indent=4)

                if arg.is_array:
                    arrayVarName = makeSnakeCaseName(arg.name + 'Array')
                    pairName = makeSnakeCaseName(arg.name + 'Pair')
                    arrayElementNames = makeSnakeCaseName(arg.name + 'Names')

                    #body += makeGen('std::string {arg.name}Names;', locals(), indent=4)
                    body += makeGenVar('{arrayVarName}', None, handleObjectType, locals(), indent=4)

                    pair_string = "pair.t1, pair.t2"
                    if arg.pointer_count > 1:
                        pair_string = "*pair.t1, *pair.t2"

                    # TODO: maybe only do this if there is any contents to process in the cpp:
                    body += makeGen(f'PointerPairContainer<decltype({arg.name}->GetPointer()), decltype({arg.name}->GetMetaStructPointer())> {pairName}{{{{ {arg.name}->GetPointer(), {arg.name}->GetMetaStructPointer(), {arg.array_length} }}}};', locals(), indent=4)
                    body += makeGenVarCall('std::string', arrayElementNames, 'toStringJoin',
                                           [f'{pairName}.begin()',
                                            f'{pairName}.end()',
                                            '[&](auto pair) {{{{ return GenerateStruct_{arg.base_type}({streamName}, {pair_string}, *this); }}}}',
                                            '", "'], locals(), indent=4)

                    body += makeGenCond(f'{streamName}.str().length() > 0', [
                                        makeCppOutputStream(streamName, indent=8),
                                        makeGenConditions([
                                                [f'{arg.array_length} == 1', [makeGen('{arrayVarName} = "&" + {arrayElementNames};', locals(), indent=12)]],
                                                [f'{arg.array_length} > 1', [
                                                    makeGenVar(arrayVarName, arg.name, None, locals(), indent=12, addType=False), # generate the CPP name
                                                    makeCppArray(arg.base_type, arrayVarName, arrayElementNames, locals(), indent=12)]],
                                        ], locals(), indent=8)
                            ], [], locals(), indent=4)

                    callArgs.append(f'{arrayVarName}.c_str()')
                    callTempl.append('%s')
                else:
                    structVarName = makeSnakeCaseName(arg.name + 'Struct')

                    body += makeGenVarCall('std::string', structVarName,
                                           f'GenerateStruct_{arg.base_type}',
                                           [streamName,
                                            f'{arg.name}->GetPointer()',
                                            f'{arg.name}->GetMetaStructPointer()',
                                            '*this'],
                                           locals(), indent=4)
                    body += makeCppOutputStream(streamName)

                    callArgs.append(f'{structVarName}.c_str()')
                    callTempl.append('&%s')

            elif arg.is_pointer and self.is_handle(arg.base_type) and self.is_output_parameter(arg):
                assert values.index(arg) == (len(values) - 1), "The handle output pointer should be the last argument"

                varName = makeSnakeCaseName(f'{arg.name}Name')
                body += makeGenVar(varName, arg.name, handleObjectType, locals(), indent=4)
                if arg.is_array:
                    callTempl.append('%s')
                    arrayInfo = '[%d]'
                    arrayFuncDelimiter = ', '
                    count_arg = next(filter(lambda x : x.name == arg.array_length, values), None)
                    if '->' in arg.array_length:
                        arrayValue = arg.array_length.replace('->', '->GetPointer()->')
                    elif count_arg is not None and count_arg.is_pointer:
                        arrayValue = '*' + arg.array_length + '->GetPointer()'
                    else:
                        arrayValue = arg.array_length
                else:
                    callTempl.append('&%s')
                    arrayInfo = ''
                    arrayValue = ''
                    arrayFuncDelimiter = ''
                body += self.printKnownVariables(arg, varName, arrayValue, useThis=False, indent=4)

                callArgs.append(varName + '.c_str()')

                if returnType == 'VkResult':
                    # TODO: This also needs to consider scenarios where VK_INCOMPLETE or other non-Error codes are used
                    body += makeGenCond('returnValue == VK_SUCCESS', [
                                makeGenCall('this->AddHandles', [varName, f'{arg.name}->GetPointer(){arrayFuncDelimiter}{arrayValue}'], locals(), indent=8),
                            ], [],
                            locals(), indent=4)
                else:
                    body += makeGenCall('this->AddHandles', [varName, f'{arg.name}->GetPointer(){arrayFuncDelimiter}{arrayValue}'], locals(), indent=4)

            # TODO: Create a separate function for common parts.
            elif arg.is_pointer and self.is_output_parameter(arg):
                varName = makeSnakeCaseName(arg.name + 'Name')
                streamName = makeSnakeCaseName('stream_' + arg.name)
                varType = 'uint8_t' if arg.base_type == 'void' else arg.base_type
                if arg.pointer_count > 1:
                    varType += '*' * (arg.pointer_count - 1)

                varDef = []
                if arg.is_array:
                    arrayValue = f', {arg.array_length}'
                    if arg.array_length_value.base_type == 'size_t':
                        arrayInfo = '[%" PRIu64 "]'
                    else:
                        arrayInfo = '[%d]'

                    if arg.array_length_value.is_pointer:
                        arrayLenVarName = makeSnakeCaseName(f'in_{arg.array_length_value.name}')
                        if arg.array_length_value.base_type != 'size_t':
                            varDef += makeGen(f'const uint32_t* {arrayLenVarName} = {arg.array_length_value.name}->GetPointer();',locals(), indent=8)
                            arrayValue = f', *{arrayLenVarName}'
                        else:
                            varDef += makeGen(f'size_t* {arrayLenVarName} = {arg.array_length_value.name}->GetPointer();',locals(), indent=8)
                            arrayValue = f', util::platform::SizeTtoUint64(*{arrayLenVarName})'
                    else:
                        if arg.array_length_value.base_type == 'size_t':
                            arrayValue = f', util::platform::SizeTtoUint64({arg.array_length_value.name})'
                        else:
                            arrayValue = f', {arg.array_length_value.name}'

                    varDef += makeGenVar(varName, arg.name, handleObjectType, locals(), indent=8, addType=False)
                    # zero-initialize array in case it contains pointers
                    # TODO: It may be necessary to initialize it using the capture value in the future
                    varDef += makeGen(f'fprintf(file, "\\t\\t{varType} %s{arrayInfo} = {{{{}}}};\\n", {varName}.c_str(){arrayValue});', locals(), indent=8)
                else:
                    varDef += makeGenVar(varName, arg.name, handleObjectType, locals(), indent=8, addType=False)
                    if self.is_struct(arg.base_type):
                        # zero-initialize struct in case it contains pointers
                        # TODO: It may be necessary to initialize it using the capture value in the future
                        varDef += makeGen(f'fprintf(file, "\\t\\t{varType} %s = {{{{}}}};\\n", {varName}.c_str());', locals(), indent=8)
                    else:
                        # scalar output args are often in+out (vkGet*, vkEnum*) so initialize them using the capture value
                        varDef += makeGen(f'fprintf(file, "\\t\\t{varType} %s = %s;\\n", {varName}.c_str(), util::ToString(*{arg.name}->GetPointer()).c_str());', locals(), indent=8)
                    varDef += makeGen('{varName}.insert(0, "&");', locals(), indent=8)

                # only define a local output variable if the captured pointer is non-null
                body += makeGenVar(varName, None, handleObjectType, locals(), indent=4)
                body += makeGenCond(f'!{arg.name}->IsNull()',varDef, [], locals(), indent=4)

                callTempl.append('%s')
                callArgs.append(f'{varName}.c_str()')

            elif self.is_handle(arg.base_type):
                if arg.is_array:
                    # Generate an array of strings containing the handle id names
                    strArrayVarName = makeSnakeCaseName(arg.name + 'Array')
                    strValuesVarName = makeSnakeCaseName(arg.name + 'Values')

                    body += makeGenVar(strArrayVarName, None, handleObjectType, locals(), indent=4)
                    body += makeGenVarCall('std::string', strValuesVarName, 'toStringJoin',
                                           [f'{arg.name}->GetPointer()',
                                            f'{arg.name}->GetPointer() + {arg.array_length}',
                                            '[&](const format::HandleId current) {{ return this->GetHandle(current); }}',
                                            '", "'], locals(), indent=4)

                    body += makeGenConditions([
                                ['{arg.array_length} == 1 && {strValuesVarName} != "VK_NULL_HANDLE"', [makeGen('{strArrayVarName} = "&" + {strValuesVarName};', locals(), indent=8)]],
                                ['{arg.array_length} > 1', [
                                    makeGenVar(strArrayVarName, strArrayVarName, None, locals(), indent=8, addType=False), # generate the CPP name
                                    makeCppArray(arg.base_type, strArrayVarName, strValuesVarName, locals(), indent=8)]],
                            ], locals(), indent=4)

                    callArgs.append('{0}.c_str()'.format(strArrayVarName))
                    callTempl.append('%s')
                else:
                    callArgs.append(f'this->GetHandle({arg.name}).c_str()')
                    callTempl.append('%s')
            elif self.is_enum(arg.base_type) or self.is_flags(arg.base_type):
                if arg.is_array:
                    strArrayVarName = makeSnakeCaseName(arg.name + 'Array')
                    strValuesVarName = makeSnakeCaseName(arg.name + 'Values')

                    body += makeGenVar(strArrayVarName, strArrayVarName, handleObjectType, locals(), indent=4)
                    body += makeGenVarCall('std::string', strValuesVarName, 'toStringJoin',
                                           [f'{arg.name}->GetPointer()',
                                            f'{arg.name}->GetPointer() + {arg.array_length}',
                                            '[&](const {arg.base_type} current) {{ return util::ToString(current); }}',
                                            '", "'], locals(), indent=4)
                    if arg.array_length.isnumeric() or arg.array_length.isupper():
                        body += makeCppArray(arg.base_type, strArrayVarName, strValuesVarName, locals(), indent=4)
                    else:
                        body += makeGenConditions([
                                    ['{arg.array_length} == 1', [makeGen('{strArrayVarName} = "&" + {strValuesVarName};', locals(), indent=8)]],
                                    ['{arg.array_length} > 1', [
                                        makeGenVar(strArrayVarName, strArrayVarName, None, locals(), indent=8, addType=False), # generate the CPP name
                                        makeCppArray(arg.base_type, strArrayVarName, strValuesVarName, locals(), indent=8)]],
                                ], locals(), indent=4)

                    callArgs.append('{0}.c_str()'.format(strArrayVarName))
                    callTempl.append('%s')
                else:
                    callArgs.append(f'util::ToString<{arg.base_type}>({arg.name}).c_str()')
                    callTempl.append('%s')

            elif self.is_input_pointer(arg):
                varName = makeSnakeCaseName(f'{arg.name}Name')

                # There should be only primitive types here
                valueSuffix = valueSuffixDict.get(arg.base_type, '')

                if arg.is_array:
                    newArray, callArg, callTemplate = self.buildInputArray(arg, valueSuffix=valueSuffix, indent=4)
                    body += newArray
                elif arg.base_type != 'void':
                    callArg = f'{arg.name}->GetPointer()'
                    callTemplate = "%p"
                else:
                    # encoding void* inputs is tricky at the moment, hope for the best
                    body += makeGenVar(varName, arg.name, handleObjectType, locals(), indent=4)
                    body += makeGen(f'fprintf(file, "\\t\\tvoid* %s;\\n", {varName}.c_str());', locals(), indent=4)

                    callArg = f'{varName}.c_str()'
                    callTemplate = '%s'

                callArgs.append(callArg)
                callTempl.append(callTemplate)
            elif arg.is_pointer:
                assert self.is_output_parameter(arg)
                body += makeGenVar(varName, arg.name, handleObjectType, locals(), indent=4)
                body += makeGen(f'fprintf(file, "\\t\\t{arg.base_type} %s;\\n", {varName}.c_str());', locals(), indent=4)

                callArgs.append(f'{varName}.c_str()')
                callTempl.append('&%s')
            else:
                # simple input argument (float, etc..)
                valueSuffix = valueSuffixDict.get(arg.base_type, '')
                valueFormat = valueFormatDict[arg.base_type]
                if arg.base_type == "size_t":
                    callArgs.append(f'util::platform::SizeTtoUint64({arg.name})')
                else:
                    callArgs.append(f'{arg.name}')
                callTempl.append(valueFormat + valueSuffix)

        # Build the vk* function call with arguments
        if needsToBeLoaded:
            body += makeGen('pfn_loader_.AddMethodName("{}");'.format(name), locals(), indent=4)
            functionCall = 'loaded_{}({})'.format(name, ', '.join(callTempl))
        else:
            functionCall = '{}({})'.format(name, ', '.join(callTempl)) # vk function call

        if returnType == 'VkResult':
            if name in CPP_APICALL_DO_NOT_CHECK:
                functionCall = '{}'.format(functionCall)
            else:
                # wrap function call into a macro call
                functionCall = 'VK_CALL_CHECK({}, %s)'.format(functionCall)  # '%s' is the captured 'VkResult returnValue'
                callArgs.append('util::ToString<VkResult>(returnValue).c_str()')

        fprintfArgs = [
            'file',
            '"\\t\\t{};\\n"'.format(functionCall), # double quote is intended to make sure this is a string in the cpp
        ]
        fprintfArgs.extend(callArgs)
        body += makeGenCall('fprintf', fprintfArgs, locals(), indent=4)

        return body

    def nextVarId(self, varName, separator=''):
        varname = varName + separator + str(self.variableMap[varName])
        self.variableMap[varName] += 1
        return varname

    def printKnownVariables(self, arg, varName, arrayValue, useThis=True, indent=4):
        """
        Output the `AddKnownVariables()` function call into the CPP consumer.

        :param arg: object that describes the variable
        :param varName: the name of the variable in the generated code
        :param arrayValue: if the variable is an array, arrayValue will contain the pointer to it.
        :param useThis: use 'consumer.' if True, otherwise access attributes with the object of class.
        :param indent: indentation size.

        :return:
        """
        object = ''

        if useThis:
            object = 'consumer.'

        assert(self.is_handle(arg.base_type))
        params = [
            '"%s"' % arg.base_type,
            varName,
        ]

        if self.is_output_parameter(arg) or arg.is_pointer:
            params.append('%s->GetPointer()' % arg.name)
            if arg.is_array:
                params.append(arrayValue)
        else:
            params.append(arg.name)

        return (' ' * indent) + object + 'AddKnownVariables(%s);\n' % ', '.join(params)

    def reverseReplace(self, string, oldString, newString, occurrence):
        reverseSplitString = string.rsplit(oldString, occurrence)
        return newString.join(reverseSplitString)

    def makeAddStructHandleBody(self, arg, array_len_arg, recursivePointerAccess='', recursionDepth=1):
        body = []

        members = self.feature_struct_members.get(arg.base_type)
        if not members:
            return body

        for member in members:
            # If the struct member is a struct, recursively traverse it
            if self.is_struct(member.base_type):
                member_array_len_arg = None
                if member.array_length is not None:
                    member_array_len_arg = next((x for x in members if x.name == member.array_length), None)

                body.extend(self.makeAddStructHandleBody(member,
                                                         member_array_len_arg,
                                                         recursivePointerAccess + arg.name + '->GetMetaStructPointer()->',
                                                         recursionDepth + 1))
            if self.is_handle(member.base_type):
                # Resolve how the handle is accessed through pointers
                pointerAccess = recursivePointerAccess + arg.name
                if arg.is_array:
                    pointerAccess += '->GetMetaStructPointer()[idx]'
                    argument = '%s.%s' % (pointerAccess, member.name)
                elif not arg.is_pointer and arg.is_dynamic:
                    argument = '%s->%s' % (pointerAccess, member.name)
                else:
                    pointerAccess += '->GetMetaStructPointer()'
                    argument = '%s->%s' % (pointerAccess, member.name)

                arguments = ['GetCurrentFrameNumber()',
                             'GetCurrentFrameSplitNumber()',]
                if member.is_pointer or member.is_array:
                    arguments.append(argument + '.GetPointer()')
                    if member.is_array:
                        arguments.append(argument + '.GetLength()')
                else: # elif not member.is_array and not member.is_pointer:
                    arguments.append(argument)

        return body
