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
from base_generator import BaseGenerator, BaseGeneratorOptions, write

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

# TODO: Copied from base_generator.py.
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


class VulkanStructPacketsHeaderGeneratorOptions(BaseGeneratorOptions):
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
        extraVulkanHeaders=[]
    ):
        BaseGeneratorOptions.__init__(
            self,
            blacklists,
            platform_types,
            filename,
            directory,
            CPP_PREFIX_STRING,
            protect_file,
            protect_feature,
            extraVulkanHeaders=extraVulkanHeaders
        )


class VulkanStructPacketsHeaderGenerator(BaseGenerator):
    """VulkanStructPacketsHeaderGenerator - subclass of BaseGenerator.
    Generates C++ member definitions for the VulkanCppConsumer class responsible for
    generating a textfile containing decoded Vulkan API call parameter data.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
     ):
        BaseGenerator.__init__(
            self,
            process_cmds=True,
            process_structs=True,
            feature_break=False,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

        # The generation of these functions are suspended for a while.
        self.skippedApiFuncs = [
            'vkGetPipelineCacheData',
            'vkGetPhysicalDeviceXcbPresentationSupportKHR',
        ]

        # # TODO: Don't currently support Nvidia raytracing entrypoints
        # self.APICALL_BLACKLIST = [
        #     'vkCmdBuildAccelerationStructureNV',
        #     'vkCmdTraceRaysNV',
        #     'vkCreateAccelerationStructureNV'
        # ]

        self.stype_values = dict()
        self.structs_with_handle_ptrs = []
        self.structs_with_handles = dict()

    def writeout(self, *args, **kwargs):
        write(*args, **kwargs, file=self.outFile)

    def genStruct(self, typeinfo, typename, alias):
        """
        Process struct information

        Note: Using method from replay consumer generator
        """
        BaseGenerator.genStruct(self, typeinfo, typename, alias)

        if not alias:
            self.check_struct_member_handles(
                typename, self.structs_with_handles,
                self.structs_with_handle_ptrs
            )

            stype = self.make_structure_type_enum(typeinfo, typename)
            if stype:
                self.stype_values[typename] = stype

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        self.writeout('#include "generated/generated_vulkan_cpp_consumer.h"')
        self.newline()
        self.writeout('#include "decode/vulkan_cpp_consumer_base.h"')
        self.writeout('#include "decode/vulkan_cpp_structs.h"')
        self.writeout('#include "generated/generated_vulkan_cpp_structs.h"')
        self.writeout('#include "generated/generated_vulkan_enum_to_string.h"')
        self.writeout('#include "generated/generated_vulkan_cpp_consumer_extension.h"')
        self.writeout('#include "decode/handle_pointer_decoder.h"')
        self.writeout('#include "decode/pointer_decoder.h"')
        self.writeout('#include "decode/string_decoder.h"')
        self.writeout('#include "decode/struct_pointer_decoder.h"')
        self.writeout('#include "decode/custom_vulkan_struct_handle_mappers.h"')
        self.writeout('#include "generated/generated_vulkan_struct_decoders.h"')
        self.writeout('#include "util/defines.h"')
        self.writeout('#include "format/packet_call_id.h"')
        self.includeVulkanHeaders(gen_opts)
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
        BaseGenerator.endFile(self)

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
            cmddef += self.make_packet(
                return_type,
                cmd,
                values
            ) + '\n'

            write(cmddef, file=self.outFile)
            first = False

    def make_packet(self, return_type, name, values):
        """make_packet - return Packet struct.
        Generate packet for Vulkan only.
        """
        struct_members = []
        struct_member = self.make_aligned_param_decl(
            'format::PacketCallId', 'packet_id', self.INDENT_SIZE,
            self.genOpts.align_func_param
        )
        struct_members.append(struct_member)

        struct_member = self.make_aligned_param_decl(
            'ApiCallInfo', 'call_info', self.INDENT_SIZE,
            self.genOpts.align_func_param
        )
        struct_members.append(struct_member)

        if return_type and return_type != 'void':
            struct_member = self.make_aligned_param_decl(
                return_type, 'return_value', self.INDENT_SIZE,
                self.genOpts.align_func_param
            )
            struct_members.append(struct_member)

        for value in values:
            param_type = self.make_decoded_param_type(value)
            if 'Decoder' in param_type:
                param_type = '{}'.format(param_type)
            struct_member = self.make_aligned_param_decl(
                param_type, value.name, self.INDENT_SIZE,
                self.genOpts.align_func_param
            )
            struct_members.append(struct_member)

        if struct_members:
            return 'struct Packet_{}\n{{\n{};\n}};'.format(name, ';\n'.join(struct_members))