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


from base_generator import *
from vulkan_cpp_consumer_body_generator import CPP_CONSUMER_ADD_EXTENSION_PAT, \
    CPP_CONSUMER_REMOVE_EXTENSION_PAT, CPP_CONSUMER_VULKAN_VERSION_PAT, \
    makeGenCall, makeGenCond, makeGenLoop, makeGen, makeParamList

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


def reverseReplace(string, oldString, newString, occurrence):
    reverseSplitString = string.rsplit(oldString, occurrence)
    return newString.join(reverseSplitString)


CPP_PRE_PROCESS_GENERATE_LIST = [
    'vkUpdateDescriptorSets',
]

CPP_PRE_PROCESS_APICALL_INTERCEPT_LIST = [
    'vkCreateSwapchainKHR',
    'vkBindImageMemory',
    'vkBindBufferMemory',
]


class VulkanCppPreProcessConsumerBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating cpp code pre processing"""

    def __init__(self,
                 blacklists = None,         # Path to JSON file listing apicalls and structs to ignore.
                 platform_types = None,      # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
                 filename = None,
                 directory = '.',
                 prefix_text = CPP_PREFIX_STRING,
                 protect_file = False,
                 protect_feature = True,
                 versions = CPP_CONSUMER_VULKAN_VERSION_PAT,
                 add_extensions = CPP_CONSUMER_ADD_EXTENSION_PAT,
                 remove_extensions = CPP_CONSUMER_REMOVE_EXTENSION_PAT):
        BaseGeneratorOptions.__init__(self, blacklists=blacklists, platform_types=platform_types,
                                      filename=filename, directory=directory, prefix_text=CPP_PREFIX_STRING,
                                      protect_file=protect_file, protect_feature=protect_feature,
                                      versions=versions, default_extensions="dis",
                                      add_extensions=add_extensions,
                                      remove_extensions=remove_extensions)


# VulkanCppPreProcessConsumerBodyGenerator - subclass of BaseGenerator.
# Generates vulkan command function definitions that add their handle ids to a handle id usage map
class VulkanCppPreProcessConsumerBodyGenerator(BaseGenerator):
    """Generates code for pre processing function calls"""

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

    def writeout(self, *args, **kwargs):
        write(*args, **kwargs, file=self.outFile)

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        self.writeout('#ifndef  GFXRECON_GENERATED_VULKAN_CPP_PRE_PROCESS_CONSUMER_EXTENSION_H')
        self.writeout('#define  GFXRECON_GENERATED_VULKAN_CPP_PRE_PROCESS_CONSUMER_EXTENSION_H')
        self.newline()

        self.writeout('#include "generated/generated_vulkan_cpp_pre_process_consumer.h"')
        self.writeout('#include "util/defines.h"')
        self.writeout('#include "vulkan/vulkan.h"')
        self.newline()
        self.writeout('GFXRECON_BEGIN_NAMESPACE(gfxrecon)')
        self.writeout('GFXRECON_BEGIN_NAMESPACE(decode)')
        self.newline()

    # Method override
    def endFile(self):

        self.newline()

        self.writeout('GFXRECON_END_NAMESPACE(decode)')
        self.writeout('GFXRECON_END_NAMESPACE(gfxrecon)')
        self.newline()
        self.writeout('#endif')

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def need_feature_generation(self):
        if self.feature_cmd_params or self.struct_names:
            return True
        return False

    def beginFeature(self, interface, emit):
        # Save feature specific data sets as the parent class resets these values
        saved_feature_struct_members = self.feature_struct_members
        saved_feature_struct_aliases = self.feature_struct_aliases

        BaseGenerator.beginFeature(self, interface, emit)

        # Restore the feature set informations
        self.feature_struct_members = saved_feature_struct_members
        self.feature_struct_aliases = saved_feature_struct_aliases

    def generate_feature(self):
        cmdnames = self.get_filtered_cmd_names()
        cmdnames.sort()

        for cmd in cmdnames:
            info = self.feature_cmd_params[cmd]
            returnType, values = info[0], info[2]

            cmddef = ''
            cmddef += self.make_consumer_func_decl(returnType, 'VulkanCppPreProcessConsumer::Process_' + cmd, values) + '\n'
            cmddef += '{\n'
            paramList = makeParamList(info, [])
            if cmd in CPP_PRE_PROCESS_APICALL_INTERCEPT_LIST:
                cmddef += makeGen('Intercept_{cmd}({paramList});', locals(), indent=4)
            if cmd in CPP_PRE_PROCESS_GENERATE_LIST:
                cmddef += makeGen('AddHandles_{cmd}({paramList});', locals(), indent=4)
            else:
                cmddef += self.makeAddHandleBody(cmd, values) or ''
            cmddef += makeGenCall('Post_APICall'.format(cmd), ['format::ApiCallId::ApiCall_' + cmd], locals(), indent=4)
            cmddef += '}'
            self.writeout(cmddef)

    def makeAddHandleBody(self, name, values):
        body = []

        for arg in values:
            if self.is_struct(arg.base_type):
                body.extend(self.makeAddStructHandleBody(arg))

            if not self.is_handle(arg.base_type):
                continue

            arguments = ['GetCurrentFrameNumber()',
                         'GetCurrentFrameSplitNumber()']

            if self.is_output_parameter(arg) or arg.is_pointer:
                argument = '{arg.name}->GetPointer()'

                if arg.is_array:
                    arguments.append(argument)
                    arguments.append(arg.array_length.replace('->', '->GetPointer()->'))
                else:
                    arguments.append('*' + argument)
            else:
                arguments.append('{arg.name}')

            body.append(makeGenCall('m_resourceTracker->AddHandleUsage', arguments, locals(), indent=4))

        return '\n'.join(body)

    def makeAddStructHandleBody(self, arg, recursivePointerAccess='', recursionDepth=1):
        body = []
        members = self.feature_struct_members.get(arg.base_type)
        if not members:
            return body

        for member in members:
            # If the struct member is a struct, recursively traverse it
            if self.is_struct(member.base_type):
                body.extend(self.makeAddStructHandleBody(member,
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
                if member.is_pointer:
                    arguments.append(argument + '.GetPointer()')
                    if member.is_array:
                        arguments.append(argument + '.GetLength()')
                elif not member.is_array and not member.is_pointer:
                    arguments.append(argument)

                # If the parent is an array iterate through it
                if arg.is_array:
                    forConditionAccess = reverseReplace(recursivePointerAccess, 'MetaStruct', '', 1)
                    body.append(makeGenLoop('idx', '{forConditionAccess}{arg.array_length}',
                                            [makeGenCall('m_resourceTracker->AddHandleUsage', arguments, locals(),
                                                         indent=4 + recursionDepth * 4)], locals(), indent=4))
                else:
                    body.append(makeGenCond('{pointerAccess} != nullptr',
                                            [makeGenCall('m_resourceTracker->AddHandleUsage', arguments, locals(),
                                                         indent=4 + recursionDepth * 4)], [], locals(), indent=4))

        return body
