#!/usr/bin/python3 -i
#
# Copyright (c) 2018-2019 Valve Corporation
# Copyright (c) 2018-2019 LunarG, Inc.
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

import os,re,sys
from base_generator import *

class VulkanApiCallEncodersBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating C++ functions for Vulkan API parameter encoding"""
    def __init__(self,
                 blacklists = None,         # Path to JSON file listing apicalls and structs to ignore.
                 platformTypes = None,      # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
                 filename = None,
                 directory = '.',
                 prefixText = '',
                 protectFile = False,
                 protectFeature = True):
        BaseGeneratorOptions.__init__(self, blacklists, platformTypes,
                                      filename, directory, prefixText,
                                      protectFile, protectFeature)

# VulkanApiCallEncodersBodyGenerator - subclass of BaseGenerator.
# Generates C++ functions responsible for encoding Vulkan API call parameter data.
class VulkanApiCallEncodersBodyGenerator(BaseGenerator):
    """Generate C++ functions for Vulkan API parameter encoding"""
    def __init__(self,
                 errFile = sys.stderr,
                 warnFile = sys.stderr,
                 diagFile = sys.stdout):
        BaseGenerator.__init__(self,
                               processCmds=True, processStructs=False, featureBreak=True,
                               errFile=errFile, warnFile=warnFile, diagFile=diagFile)

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        write('#include "generated/generated_vulkan_api_call_encoders.h"', file=self.outFile)
        self.newline()
        write('#include "encode/custom_encoder_commands.h"', file=self.outFile)
        write('#include "encode/parameter_encoder.h"', file=self.outFile)
        write('#include "encode/struct_pointer_encoder.h"', file=self.outFile)
        write('#include "encode/trace_manager.h"', file=self.outFile)
        write('#include "encode/vulkan_handle_wrappers.h"', file=self.outFile)
        write('#include "format/api_call_id.h"', file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        write('#include "vulkan/vulkan.h"', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)

    # Method override
    def endFile(self):
        self.newline()
        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    #
    # Indicates that the current feature has C++ code to generate.
    def needFeatureGeneration(self):
        if self.featureCmdParams:
            return True
        return False

    #
    # Performs C++ code generation for the feature.
    def generateFeature(self):
        first = True
        for cmd in self.featureCmdParams:
            info = self.featureCmdParams[cmd]
            returnType = info[0]
            proto = info[1]
            values = info[2]

            cmddef = '' if first else '\n'
            cmddef += self.makeCmdDecl(proto, values)
            cmddef += '{\n'
            cmddef += self.makeCmdBody(returnType, cmd, values)
            cmddef += '}'

            write(cmddef, file=self.outFile)
            first = False

    #
    # Generate function declaration for a command
    def makeCmdDecl(self, proto, values):
        paramDecls = []

        for value in values:
            valueName = value.name
            valueType = value.fullType if not value.platformFullType else value.platformFullType

            if value.isArray and not value.isDynamic:
                valueName += '[{}]'.format(value.arrayCapacity)

            paramDecl = self.makeAlignedParamDecl(valueType, valueName, self.INDENT_SIZE, self.genOpts.alignFuncParam)
            paramDecls.append(paramDecl)

        if paramDecls:
            return '{}(\n{})\n'.format(proto, ',\n'.join(paramDecls))

        return '{}()\n'.format(proto)

    #
    # Check for dispatchable handle types associated with the instance dispatch table.
    def useInstanceTable(self, typename):
        if typename in ['VkInstance', 'VkPhysicalDevice']:
            return True
        return False

    #
    # Generate the layer dispatch call invocation.
    def makeLayerDispatchCall(self, name, values, argList):
        if name == 'vkCreateInstance':
            # CreateInstance requires special processing for VkLayerInstanceCreateInfo.
            return 'TraceManager::GetLayerTable()->CreateInstance({})'.format(argList)
        elif name == 'vkCreateDevice':
            # CreateDevice requires special processing for VkLayerDeviceCreateInfo.
            return 'TraceManager::GetLayerTable()->CreateDevice({})'.format(argList)

        dispatchfunc = 'TraceManager::Get()->GetInstanceTable' if self.useInstanceTable(values[0].baseType) else 'TraceManager::Get()->GetDeviceTable'
        return '{}({})->{}({})'.format(dispatchfunc, values[0].name, name[2:], argList)

    #
    # Command definition
    def makeCmdBody(self, returnType, name, values):
        encodeAfter = self.hasOutputs(returnType, values)
        indent = ' ' * self.INDENT_SIZE

        argList = self.makeArgList(values)

        body = ''

        body += indent + 'CustomEncoderPreCall<format::ApiCallId::ApiCall_{}>::Dispatch(TraceManager::Get(), {});\n'.format(name, argList)

        if not encodeAfter:
            body += self.makeParameterEncoding(name, values, returnType, indent)

        body += '\n'

        # Construct the function call to dispatch to the next layer.
        callExpr = self.makeLayerDispatchCall(name, values, argList)
        if returnType and returnType != 'void':
            body += indent + '{} result = {};\n'.format(returnType, callExpr)
        else:
            body += indent + '{};\n'.format(callExpr)

        if encodeAfter:
            body += self.makeParameterEncoding(name, values, returnType, indent)

        body += '\n'
        if returnType and returnType != 'void':
            body += '    CustomEncoderPostCall<format::ApiCallId::ApiCall_{}>::Dispatch(TraceManager::Get(), result, {});\n'.format(name, argList)
            body += '\n'
            body += '    return result;\n'
        else:
            body += '    CustomEncoderPostCall<format::ApiCallId::ApiCall_{}>::Dispatch(TraceManager::Get(), {});\n'.format(name, argList)

        return body

    def makeParameterEncoding(self, name, values, returnType, indent):
        body = '\n'
        body += indent + self.makeBeginApiCall(name)
        body += indent + 'if (encoder)\n'
        body += indent + '{\n'
        indent += ' ' * self.INDENT_SIZE

        for value in values:
            methodCall = self.makeEncoderMethodCall(value, values, '')
            body += indent + '{};\n'.format(methodCall)

        if returnType and returnType != 'void':
            methodCall = self.makeEncoderMethodCall(ValueInfo('result', returnType, returnType), [], '')
            body += indent + '{};\n'.format(methodCall)

        # Determine the appropriate end call: Create handle call, destroy handle call, or general call.
        body += indent + self.makeEndApiCall(name, values)
        indent = indent[0:-self.INDENT_SIZE]
        body += indent + '}\n'
        return body

    def makeBeginApiCall(self, name):
        if name.startswith('vkCreate') or name.startswith('vkAllocate') or name.startswith('vkDestroy') or name.startswith('vkFree'):
            return 'auto encoder = TraceManager::Get()->BeginCreateDestroyApiCallTrace(format::ApiCallId::ApiCall_{});\n'.format(name)
        else:
            return 'auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_{});\n'.format(name)

    def makeEndApiCall(self, name, values):
        decl = 'TraceManager::Get()->'

        if name.startswith('vkCreate') or name.startswith('vkAllocate'):
            # The handle is the last parameter.
            handle = values[-1]

            #  Search for the create info struct
            info = None
            for value in values:
                if ('CreateInfo' in value.baseType) or ('AllocateInfo' in value.baseType):
                    info = value
                    # Confirm array counts match
                    if info.isArray and (handle.arrayLength != info.arrayLength):
                        print('WARNING: {} has separate array counts for create info structures ({}) and handles ({})'.format(name, info.arrayLength, count))

            if handle.isArray:
                decl += 'EndCreateApiCallTrace<{}Wrapper, {}>(result, {}, {}, {}, encoder)'.format(handle.baseType[2:], info.baseType, handle.arrayLength, handle.name, info.name)
            else:
                decl += 'EndCreateApiCallTrace<{}Wrapper, {}>(result, {}, {}, encoder)'.format(handle.baseType[2:], info.baseType, handle.name, info.name)

        elif name.startswith('vkDestroy') or name.startswith('vkFree'):
            handle = None
            if name in ['vkDestroyInstance', 'vkDestroyDevice']:
                # Instance/device destroy calls are special case where the target handle is the first parameter
                handle = values[0]
            else:
                # The destroy target is the second parameter, exceppt for pool based allocations where it is the last parameter.
                handle = values[1]
                if ("Pool" in handle.baseType) and name.startswith('vkFree'):
                    handle = values[3]

            if handle.isArray:
                decl += 'EndDestroyApiCallTrace<{}Wrapper>({}, {}, encoder)'.format(handle.baseType[2:], handle.arrayLength, handle.name)
            else:
                decl += 'EndDestroyApiCallTrace<{}Wrapper>({}, encoder)'.format(handle.baseType[2:], handle.name)

        else:
            if name in ['vkEnumeratePhysicalDevices', 'vkGetPhysicalDeviceDisplayPropertiesKHR', 'vkGetRandROutputDisplayEXT']:
                # TODO: Handle vkEnumeratePhysicalDevices and vkGetPhysicalDeviceDisplayProprtiesKHR
                print('WARNING: Skipping special case "create" tracking for VkPhysicalDeviceKHR and VkDisplayKHR')

            decl += 'EndApiCallTrace(encoder)'

        decl += ';\n'
        return decl

    def isOutputParameter(self, value, values):
        # Check for an output pointer/array or an in-out pointer.
        if (value.isPointer or value.isArray) and not self.isInputPointer(value):
            return True
        return False

    def hasOutputs(self, returnValue, parameterValues):
        if returnValue != 'void':
            return True
        else:
            for value in parameterValues:
                if self.isOutputParameter(value, parameterValues):
                    return True
        return False
