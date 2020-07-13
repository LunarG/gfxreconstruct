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
                 captureOverrides = None,   # Path to JSON file listing Vulkan API calls to override on capture.
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
        self.captureOverrides = captureOverrides

# VulkanApiCallEncodersBodyGenerator - subclass of BaseGenerator.
# Generates C++ functions responsible for encoding Vulkan API call parameter data.
class VulkanApiCallEncodersBodyGenerator(BaseGenerator):
    """Generate C++ functions for Vulkan API parameter encoding"""

    # Map of Vulkan function names to override function names.  Calls to Vulkan functions in the map
    # will be replaced by the override value.
    CAPTURE_OVERRIDES = {}

    def __init__(self,
                 errFile = sys.stderr,
                 warnFile = sys.stderr,
                 diagFile = sys.stdout):
        BaseGenerator.__init__(self,
                               processCmds=True, processStructs=True, featureBreak=True,
                               errFile=errFile, warnFile=warnFile, diagFile=diagFile)

        # Map of Vulkan structs containing handles to a list values for handle members or struct members
        # that contain handles (eg. VkGraphicsPipelineCreateInfo contains a VkPipelineShaderStageCreateInfo
        # member that contains handles).
        self.structsWithHandles = dict()

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        if genOpts.captureOverrides:
            self.__loadCaptureOverrides(genOpts.captureOverrides)

        write('#include "generated/generated_vulkan_api_call_encoders.h"', file=self.outFile)
        self.newline()
        write('#include "encode/custom_encoder_commands.h"', file=self.outFile)
        write('#include "encode/parameter_encoder.h"', file=self.outFile)
        write('#include "encode/struct_pointer_encoder.h"', file=self.outFile)
        write('#include "encode/trace_manager.h"', file=self.outFile)
        write('#include "encode/vulkan_handle_wrapper_util.h"', file=self.outFile)
        write('#include "encode/vulkan_handle_wrappers.h"', file=self.outFile)
        write('#include "format/api_call_id.h"', file=self.outFile)
        write('#include "generated/generated_vulkan_command_buffer_util.h"', file=self.outFile)
        write('#include "generated/generated_vulkan_struct_handle_wrappers.h"', file=self.outFile)
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
    # Method override
    def genStruct(self, typeinfo, typename, alias):
        BaseGenerator.genStruct(self, typeinfo, typename, alias)

        if not alias:
            self.checkStructMemberHandles(typename, self.structsWithHandles)

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
        for cmd in self.getFilteredCmdNames():
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
        dispatchfunc = 'GetInstanceTable' if self.useInstanceTable(values[0].baseType) else 'GetDeviceTable'
        return '{}({})->{}({})'.format(dispatchfunc, values[0].name, name[2:], argList)

    #
    # Command definition
    def makeCmdBody(self, returnType, name, values):
        indent = ' ' * self.INDENT_SIZE
        isOverride = name in self.CAPTURE_OVERRIDES
        encodeAfter = False
        omitOutputParam = None
        hasOutputs = self.hasOutputs(returnType, values)
        argList = self.makeArgList(values)

        body = ''

        if hasOutputs or (returnType and returnType != 'void'):
            encodeAfter = True

        if hasOutputs and (returnType and returnType != 'void'):
            omitOutputParam = 'omit_output_data'
            body += indent + 'bool omit_output_data = false;\n'
            body += '\n'

        body += indent + 'CustomEncoderPreCall<format::ApiCallId::ApiCall_{}>::Dispatch(TraceManager::Get(), {});\n'.format(name, argList)

        if not encodeAfter:
            body += self.makeParameterEncoding(name, values, returnType, indent, omitOutputParam)

        body += '\n'

        if isOverride:
            # Capture overrides simply call the override function without handle unwrap/wrap
            # Construct the function call to dispatch to the next layer.
            callExpr = '{}({})'.format(self.CAPTURE_OVERRIDES[name], self.makeArgList(values))
            if returnType and returnType != 'void':
                body += indent + '{} result = {};\n'.format(returnType, callExpr)
            else:
                body += indent + '{};\n'.format(callExpr)

            if hasOutputs and (returnType and returnType != 'void'):
                body += indent + 'if (result < 0)\n'
                body += indent + '{\n'
                body += indent + '    omit_output_data = true;\n'
                body += indent + '}\n'
        else:
            # Check for handles that need unwrapping.
            unwrapExpr, unwrappedArgList, needUnwrapMemory = self.makeHandleUnwrapping(values, indent)
            if unwrapExpr:
                if needUnwrapMemory:
                    body += indent + 'auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();\n'
                body += unwrapExpr
                body += '\n'

            # Construct the function call to dispatch to the next layer.
            callExpr = self.makeLayerDispatchCall(name, values, unwrappedArgList)
            if returnType and returnType != 'void':
                body += indent + '{} result = {};\n'.format(returnType, callExpr)
            else:
                body += indent + '{};\n'.format(callExpr)

            # Wrap newly created handles.
            wrapExpr = self.makeHandleWrapping(values, indent)
            if wrapExpr:
                body += '\n'
                if returnType and returnType != 'void':
                    body += indent + 'if (result >= 0)\n'
                    body += indent + '{\n'
                    body += '    ' + wrapExpr
                    body += indent + '}\n'
                    if hasOutputs:
                        body += indent + 'else\n'
                        body += indent + '{\n'
                        body += indent + '    omit_output_data = true;\n'
                        body += indent + '}\n'
                else:
                    body += wrapExpr
            elif hasOutputs and (returnType and returnType != 'void'):
                body += indent + 'if (result < 0)\n'
                body += indent + '{\n'
                body += indent + '    omit_output_data = true;\n'
                body += indent + '}\n'

        if encodeAfter:
            body += self.makeParameterEncoding(name, values, returnType, indent, omitOutputParam)

        body += '\n'
        if returnType and returnType != 'void':
            body += '    CustomEncoderPostCall<format::ApiCallId::ApiCall_{}>::Dispatch(TraceManager::Get(), result, {});\n'.format(name, argList)
        else:
            body += '    CustomEncoderPostCall<format::ApiCallId::ApiCall_{}>::Dispatch(TraceManager::Get(), {});\n'.format(name, argList)

        cleanupExpr = self.makeHandleCleanup(name, values, indent)
        if cleanupExpr:
            body += '\n'
            body += cleanupExpr

        if returnType and returnType != 'void':
            body += '\n'
            body += '    return result;\n'

        return body

    def makeParameterEncoding(self, name, values, returnType, indent, omitOutputParam):
        body = '\n'
        body += indent + self.makeBeginApiCall(name, values)
        body += indent + 'if (encoder)\n'
        body += indent + '{\n'
        indent += ' ' * self.INDENT_SIZE

        for value in values:
            methodCall = self.makeEncoderMethodCall(value, values, '', omitOutputParam)
            body += indent + '{};\n'.format(methodCall)

        if returnType and returnType != 'void':
            methodCall = self.makeEncoderMethodCall(ValueInfo('result', returnType, returnType), [], '')
            body += indent + '{};\n'.format(methodCall)

        # Determine the appropriate end call: Create handle call, destroy handle call, or general call.
        body += indent + self.makeEndApiCall(name, values, returnType)
        indent = indent[0:-self.INDENT_SIZE]
        body += indent + '}\n'
        return body

    def makeBeginApiCall(self, name, values):
        if name.startswith('vkCreate') or name.startswith('vkAllocate') or name.startswith('vkDestroy') or name.startswith('vkFree') or self.retrievesHandles(values) or (values[0].baseType == 'VkCommandBuffer') or (name == 'vkReleasePerformanceConfigurationINTEL'):
            return 'auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_{});\n'.format(name)
        else:
            return 'auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_{});\n'.format(name)

    def getStructHandleMemberInfo(self, members):
        memberHandleType = None
        memberHandleName = None
        memberArrayLength = None

        for member in members:
            if self.isHandle(member.baseType):
                memberHandleType = member.baseType
                memberHandleName = member.name
                if member.isArray:
                    memberArrayLength = member.arrayLength
                break
            elif self.isStruct(member.baseType):
                # This can't handle the case where 'member' is an array of structs
                memberHandleType, memberHandleName, memberArrayLength = self.getStructHandleMemberInfo(self.structsWithHandles[member.baseType])
                memberHandleName = '{}.{}'.format(member.name, memberHandleName)

        return memberHandleType, memberHandleName, memberArrayLength

    def makeEndApiCall(self, name, values, returnType):
        decl = 'TraceManager::Get()->'

        if name.startswith('vkCreate') or name.startswith('vkAllocate') or self.retrievesHandles(values):
            # The handle is the last parameter.
            handle = values[-1]
            parentHandle = values[0] if self.isHandle(values[0].baseType) else None

            #  Search for the create info struct
            infoBaseType = 'void'
            infoName = 'nullptr'
            for value in values:
                if ('CreateInfo' in value.baseType) or ('AllocateInfo' in value.baseType):
                    infoBaseType = value.baseType
                    infoName = value.name
                    # Confirm array counts match
                    if value.isArray and (handle.arrayLength != value.arrayLength):
                        print('WARNING: {} has separate array counts for create info structures ({}) and handles ({})'.format(name, value.arrayLength, count))

            returnValue = 'VK_SUCCESS'
            if returnType == 'VkResult':
                returnValue = 'result'

            if handle.isArray:
                lengthName = self.makeArrayLengthExpression(handle)

                if 'pAllocateInfo->' in lengthName:
                    # This is a pool allocation call, which receives one allocate info structure that is shared by all object being allocated.
                    decl += 'EndPoolCreateApiCallTrace<{}, {}Wrapper, {}>({}, {}, {}, {}, {}, encoder)'.format(parentHandle.baseType, handle.baseType[2:], infoBaseType, returnValue, parentHandle.name, lengthName, handle.name, infoName)
                else:
                    # This is a multi-object creation call (e.g. pipeline creation, or swapchain image retrieval), which receives
                    # separate create info structures for each object being created. Many multi-object creation calls receive a
                    # handle as their second parameter, which is of interest to the state tracker (e.g. the VkPipelineCache handle
                    # from vkCreateGraphicsPipelines or the vkSwapchain handle from vkGetSwapchainImagesKHR). For api calls that do
                    # not receive a handle as the second parameter (e.g. vkEnumeratePhysicalDevices), the handle type is set to 'void*'.
                    if handle.baseType in self.structNames:
                        # "handle" is actually a struct with embedded handles
                        unwrapHandleDef = 'nullptr'
                        memberHandleType, memberHandleName, memberArrayLength = self.getStructHandleMemberInfo(self.structsWithHandles[handle.baseType])

                        if not memberArrayLength:
                            unwrapHandleDef = '[]({}* handle_struct)->{wrapper}Wrapper* {{ return reinterpret_cast<{wrapper}Wrapper*>(handle_struct->{}); }}'.format(handle.baseType, memberHandleName, wrapper=memberHandleType[2:])

                        decl += 'EndStructGroupCreateApiCallTrace<{}, {}Wrapper, {}>({}, {}, {}, {}, {}, encoder)'.format(parentHandle.baseType, memberHandleType[2:], handle.baseType, returnValue, parentHandle.name, lengthName, handle.name, unwrapHandleDef)
                    elif self.isHandle(values[1].baseType):
                        secondHandle = values[1]
                        decl += 'EndGroupCreateApiCallTrace<{}, {}, {}Wrapper, {}>({}, {}, {}, {}, {}, {}, encoder)'.format(parentHandle.baseType, secondHandle.baseType, handle.baseType[2:], infoBaseType, returnValue, parentHandle.name, secondHandle.name, lengthName, handle.name, infoName)
                    else:
                        decl += 'EndGroupCreateApiCallTrace<{}, void*, {}Wrapper, {}>({}, {}, nullptr, {}, {}, {}, encoder)'.format(parentHandle.baseType, handle.baseType[2:], infoBaseType, returnValue, parentHandle.name, lengthName, handle.name, infoName)

            else:
                if handle.baseType in self.structNames:
                    # TODO: No cases in current Vulkan spec of handle inside non-array output structure
                    raise NotImplementedError
                elif parentHandle:
                    decl += 'EndCreateApiCallTrace<{}, {}Wrapper, {}>({}, {}, {}, {}, encoder)'.format(parentHandle.baseType, handle.baseType[2:], infoBaseType, returnValue, parentHandle.name, handle.name, infoName)
                else:
                    # Instance creation does not have a parent handle; set the parent handle type to 'void*'.
                    decl += 'EndCreateApiCallTrace<const void*, {}Wrapper, {}>({}, nullptr, {}, {}, encoder)'.format(handle.baseType[2:], infoBaseType, returnValue, handle.name, infoName)

        elif name.startswith('vkDestroy') or name.startswith('vkFree') or (name == 'vkReleasePerformanceConfigurationINTEL'):
            handle = None
            if name in ['vkDestroyInstance', 'vkDestroyDevice']:
                # Instance/device destroy calls are special case where the target handle is the first parameter
                handle = values[0]
            else:
                # The destroy target is the second parameter, except for pool based allocations where it is the last parameter.
                handle = values[1]
                if ("Pool" in handle.baseType) and name.startswith('vkFree'):
                    handle = values[3]

            if handle.isArray:
                decl += 'EndDestroyApiCallTrace<{}Wrapper>({}, {}, encoder)'.format(handle.baseType[2:], handle.arrayLength, handle.name)
            else:
                decl += 'EndDestroyApiCallTrace<{}Wrapper>({}, encoder)'.format(handle.baseType[2:], handle.name)

        elif values[0].baseType == 'VkCommandBuffer':
            getHandlesExpr = self.makeGetCommandHandlesExpr(name, values[1:])
            if getHandlesExpr:
                decl += 'EndCommandApiCallTrace({}, encoder, {})'.format(values[0].name, getHandlesExpr)
            else:
                decl += 'EndCommandApiCallTrace({}, encoder)'.format(values[0].name)
        else:
            decl += 'EndApiCallTrace(encoder)'

        decl += ';\n'
        return decl

    def makeHandleWrapping(self, values, indent):
        expr = ''
        for value in values:
            if self.isOutputParameter(value) and (self.isHandle(value.baseType) or (self.isStruct(value.baseType) and (value.baseType in self.structsWithHandles))):
                # The VkInstance handle does not have parent, so the 'unused'
                # values will be provided to the wrapper creation function.
                parentType = 'NoParentWrapper'
                parentValue = 'NoParentWrapper::kHandleValue'
                if self.isHandle(values[0].baseType):
                    parentType = values[0].baseType[2:] + 'Wrapper'
                    parentValue = values[0].name

                # Some handles have two parent handles, such as swapchain images and display modes,
                # or command buffers and descriptor sets allocated from pools.
                coParentType = 'NoParentWrapper'
                coParentValue = 'NoParentWrapper::kHandleValue'
                if self.isHandle(values[1].baseType):
                    coParentType = values[1].baseType[2:] + 'Wrapper'
                    coParentValue = values[1].name
                elif values[1].baseType.endswith('AllocateInfo') and value.isArray and ('->' in value.arrayLength):
                    # An array of handles with length specified by an AllocateInfo structure (there is a -> in the length name) is a pool allocation.
                    # Extract the pool handle from the AllocateInfo structure, which is currently the first and only handle member.
                    members = self.structsWithHandles[values[1].baseType]
                    for member in members:
                        if self.isHandle(member.baseType):
                            coParentType = member.baseType[2:] + 'Wrapper'
                            coParentValue = values[1].name + '->' + member.name
                            break

                if value.isArray:
                    lengthName = value.arrayLength
                    for len in values:
                        if (len.name == lengthName) and len.isPointer:
                            lengthName = '({name} != nullptr) ? (*{name}) : 0'.format(name=lengthName)
                            break
                    if self.isHandle(value.baseType):
                        expr += indent + 'CreateWrappedHandles<{}, {}, {}Wrapper>({}, {}, {}, {}, TraceManager::GetUniqueId);\n'.format(parentType, coParentType, value.baseType[2:], parentValue, coParentValue, value.name, lengthName)
                    elif self.isStruct(value.baseType) and (value.baseType in self.structsWithHandles):
                        expr += indent + 'CreateWrappedStructArrayHandles<{}, {}, {}>({}, {}, {}, {}, TraceManager::GetUniqueId);\n'.format(parentType, coParentType, value.baseType, parentValue, coParentValue, value.name, lengthName)
                else:
                    if self.isHandle(value.baseType):
                        expr += indent + 'CreateWrappedHandle<{}, {}, {}Wrapper>({}, {}, {}, TraceManager::GetUniqueId);\n'.format(parentType, coParentType, value.baseType[2:], parentValue, coParentValue, value.name)
                    elif self.isStruct(value.baseType) and (value.baseType in self.structsWithHandles):
                        expr += indent + 'CreateWrappedStructHandles<{}, {}>({}, {}, {}, TraceManager::GetUniqueId);\n'.format(parentType, coParentType, parentValue, coParentValue, value.name)
        return expr

    def makeHandleUnwrapping(self, values, indent):
        args = []
        expr = ''
        needUnwrapMemory = False
        for value in values:
            argName = value.name
            if value.isPointer or value.isArray:
                if self.isInputPointer(value):
                    if self.isHandle(value.baseType):
                        needUnwrapMemory = True
                        argName += '_unwrapped'
                        arrayLength = value.arrayLength if value.isArray else 1  # At this time, all pointer unwrap cases are arrays
                        expr += indent + '{} {name}_unwrapped = UnwrapHandles<{}>({name}, {}, handle_unwrap_memory);\n'.format(value.fullType, value.baseType, arrayLength, name=value.name)
                    elif value.baseType in self.structsWithHandles:
                        needUnwrapMemory = True
                        argName += '_unwrapped'
                        if value.isArray:
                            expr += indent + '{} {name}_unwrapped = UnwrapStructArrayHandles({name}, {}, handle_unwrap_memory);\n'.format(value.fullType, value.arrayLength, name=value.name)
                        else:
                            expr += indent + '{} {name}_unwrapped = UnwrapStructPtrHandles({name}, handle_unwrap_memory);\n'.format(value.fullType, name=value.name)
            elif self.isHandle(value.baseType):
                argName += '_unwrapped'
                expr += indent + '{type} {name}_unwrapped = GetWrappedHandle<{type}>({name});\n'.format(type=value.baseType, name=value.name)
            args.append(argName)
        return expr, ', '.join(args), needUnwrapMemory

    def makeHandleCleanup(self, name, values, indent):
        expr = ''
        if name.startswith('vkDestroy') or name.startswith('vkFree') or (name == 'vkReleasePerformanceConfigurationINTEL'):
            handle = None
            if name in ['vkDestroyInstance', 'vkDestroyDevice']:
                # Instance/device destroy calls are special case where the target handle is the first parameter
                handle = values[0]
            else:
                # The destroy target is the second parameter, except for pool based allocations where it is the last parameter.
                handle = values[1]
                if ("Pool" in handle.baseType) and name.startswith('vkFree'):
                    handle = values[3]

            if handle.isArray:
                expr += indent + 'DestroyWrappedHandles<{}Wrapper>({}, {});\n'.format(handle.baseType[2:], handle.name, handle.arrayLength)
            else:
                expr += indent + 'DestroyWrappedHandle<{}Wrapper>({});\n'.format(handle.baseType[2:], handle.name)
        return expr

    #
    # Create list of parameters that have handle types or are structs that contain handles.
    def getParamListHandles(self, values):
        handles = []
        for value in values:
            if self.isHandle(value.baseType):
                handles.append(value)
            elif self.isStruct(value.baseType) and (value.baseType in self.structsWithHandles):
                handles.append(value)
        return handles

    #
    # Generate an expression for a get command buffer handles utility function.
    def makeGetCommandHandlesExpr(self, cmd, values):
        handleParams = self.getParamListHandles(values)
        if handleParams:
            args = []
            for value in handleParams:
                if value.arrayLength:
                    args.append(value.arrayLength)
                args.append(value.name)
            return 'Track{}Handles, {}'.format(cmd[2:], ', '.join(args))
        else:
            return None

    # Determine if an API call indirectly creates handles by retrieving them (e.g. vkEnumeratePhysicalDevices, vkGetRandROutputDisplayEXT)
    def retrievesHandles(self, values):
        for value in values:
            if self.isOutputParameter(value) and (self.isHandle(value.baseType) or (value.baseType in self.structsWithHandles)):
                return True
        return False

    def hasOutputs(self, returnValue, parameterValues):
        for value in parameterValues:
            if self.isOutputParameter(value):
                return True
        return False

    def __loadCaptureOverrides(self, filename):
        overrides = json.loads(open(filename, 'r').read())
        self.CAPTURE_OVERRIDES = overrides['functions']
