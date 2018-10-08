#!/usr/bin/python3 -i
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

import os,re,sys
from base_generator import *

class ApiCallEncodersGeneratorOptions(BaseGeneratorOptions):
    """Options for Vulkan API parameter encoding C++ code generation"""
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

# APICallEncodersGenerator - subclass of BaseGenerator.
# Generates C++ functions responsible for encoding Vulkan API call parameter data.
class ApiCallEncodersGenerator(BaseGenerator):
    """Generate API parameter encoding C++ code"""
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

        write('#include <mutex>', file=self.outFile)
        self.newline()
        write('#include "vulkan/vulkan.h"', file=self.outFile)
        self.newline()
        write('#include "util/defines.h"', file=self.outFile)
        write('#include "format/api_call_id.h"', file=self.outFile)
        write('#include "format/custom_encoder_commands.h"', file=self.outFile)
        write('#include "format/trace_manager.h"', file=self.outFile)
        write('#include "format/parameter_encoder.h"', file=self.outFile)
        write('#include "layer/custom_api_call_encoders.h"', file=self.outFile)
        self.newline()
        write('BRIMSTONE_BEGIN_NAMESPACE(brimstone)', file=self.outFile)

    # Method override
    def endFile(self):
        self.newline()
        write('BRIMSTONE_END_NAMESPACE(brimstone)', file=self.outFile)

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
            return 'dispatch_CreateInstance({})'.format(argList)
        elif name == 'vkCreateDevice':
            # CreateDevice requires special processing for VkLayerDeviceCreateInfo.
            return 'dispatch_CreateDevice({})'.format(argList)

        dispatchfunc = 'get_instance_table' if self.useInstanceTable(values[0].baseType) else 'get_device_table'
        return '{}({})->{}({})'.format(dispatchfunc, values[0].name, name[2:], argList)

    #
    # Command definition
    def makeCmdBody(self, returnType, name, values):
        is_create_destroy = False
        indent = ' ' * self.INDENT_SIZE

        argList = self.makeArgList(values)

        body = ''

        if name.startswith('vkCreate') or name.startswith('vkAllocate') or name.startswith('vkDestroy') or name.startswith('vkFree'):
            is_create_destroy = True

            # Need to delcare the return type outside of the lock scope.
            if returnType and returnType != 'void':
                body += indent + '{} result;\n'.format(returnType)
                body += '\n'

        body += indent + 'format::CustomEncoderPreCall<format::ApiCallId_{}>::Dispatch(get_trace_manager(), {});\n'.format(name, argList)
        body += '\n'

        # Add a resource create/destroy lock
        if is_create_destroy:
            body += indent + '{\n'
            indent += ' ' * self.INDENT_SIZE
            body += indent + 'std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);\n'
            body += '\n'

        # Construct the function call to dispatch to the next layer.
        callExpr = self.makeLayerDispatchCall(name, values, argList)
        if returnType and returnType != 'void':
            if not is_create_destroy:
                body += indent + '{} result = {};\n'.format(returnType, callExpr)
            else:
                body += indent + 'result = {};\n'.format(callExpr)
        else:
            body += indent + '{};\n'.format(callExpr)

        body += '\n'
        body += indent + 'auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_{});\n'.format(name)
        body += indent + 'if (encoder)\n'
        body += indent + '{\n'
        indent += ' ' * self.INDENT_SIZE

        for value in values:
            methodCall = self.makeEncoderMethodCall(value, values, '')
            body += indent + '{};\n'.format(methodCall)

        if returnType and returnType != 'void':
            body += indent + 'encoder->EncodeEnumValue(result);\n'

        body += indent + 'get_trace_manager()->EndApiCallTrace(encoder);\n'
        indent = indent[0:-self.INDENT_SIZE]
        body += indent + '}\n'

        if is_create_destroy:
            indent = indent[0:-self.INDENT_SIZE]
            body += indent + '}\n'

        body += '\n'
        if returnType and returnType != 'void':
            body += '    format::CustomEncoderPostCall<format::ApiCallId_{}>::Dispatch(get_trace_manager(), result, {});\n'.format(name, argList)
            body += '\n'
            body += '    return result;\n'
        else:
            body += '    format::CustomEncoderPostCall<format::ApiCallId_{}>::Dispatch(get_trace_manager(), {});\n'.format(name, argList)

        return body


