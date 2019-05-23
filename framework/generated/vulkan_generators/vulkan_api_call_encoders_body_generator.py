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
                               processCmds=True, processStructs=True, featureBreak=True,
                               errFile=errFile, warnFile=warnFile, diagFile=diagFile)

        # Map of Vulkan structs containing handles to a list values for handle members or struct members
        # that contain handles (eg. VkGraphicsPipelineCreateInfo contains a VkPipelineShaderStageCreateInfo
        # member that contains handles).
        self.structsWithHandles = dict()

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

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

        # Check for handles that need unwrapping.
        unwrapExpr, needStore, needArrayStore = self.makeHandleUnwrapping(values, indent)
        if unwrapExpr:
            if needStore:
                body += indent + 'auto handle_store = TraceManager::Get()->GetHandleStore();\n'
            if needArrayStore:
                body += indent + 'auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();\n'
                body += indent + 'auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();\n'
            body += unwrapExpr
            body += '\n'

        # Construct the function call to dispatch to the next layer.
        callExpr = self.makeLayerDispatchCall(name, values, argList)
        if returnType and returnType != 'void':
            body += indent + '{} result = {};\n'.format(returnType, callExpr)
        else:
            body += indent + '{};\n'.format(callExpr)

        # Re-wrap handles.
        if unwrapExpr:
            body += '\n'
            if needStore:
                body += indent + 'auto handle_store_iter = handle_store->cbegin();\n'
            if needArrayStore:
                body += indent + 'auto handle_array_store_iter = handle_array_store->cbegin();\n'
            body += self.makeHandleRewrapping(values, indent)

        # Wrap newly created handles.
        wrapExpr = self.makeHandleWrapping(values, indent)
        if wrapExpr:
            body += '\n'
            if returnType and returnType != 'void':
                body += indent + 'if (result == VK_SUCCESS)\n'
                body += indent + '{\n'
                body += '    ' + self.makeHandleWrapping(values, indent)
                body += indent + '}\n'
            else:
                body += self.makeHandleWrapping(values, indent)

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
        body += indent + self.makeBeginApiCall(name, values)
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
        body += indent + self.makeEndApiCall(name, values, returnType)
        indent = indent[0:-self.INDENT_SIZE]
        body += indent + '}\n'
        return body

    def makeBeginApiCall(self, name, values):
        if name.startswith('vkCreate') or name.startswith('vkAllocate') or name.startswith('vkDestroy') or name.startswith('vkFree') or self.retrievesHandles(values) or (values[0].baseType == 'VkCommandBuffer'):
            return 'auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_{});\n'.format(name)
        else:
            return 'auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_{});\n'.format(name)

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
                lengthName = handle.arrayLength
                for value in values:
                    if (value.name == lengthName) and value.isPointer:
                        lengthName = '({name} != nullptr) ? (*{name}) : 0'.format(name=lengthName)
                        break

                if '->' in lengthName:
                    # This is a pool allocation call, which receives one allocate info structure that is shared by all object being allocated.
                    decl += 'EndPoolCreateApiCallTrace<{}, {}Wrapper, {}>({}, {}, {}, {}, {}, encoder)'.format(parentHandle.baseType, handle.baseType[2:], infoBaseType, returnValue, parentHandle.name, lengthName, handle.name, infoName)
                else:
                    # This is a multi-object creation call (e.g. pipeline creation, or swapchain image retrieval), which receives
                    # separate create info structures for each object being created. Many multi-object creation calls receive a
                    # handle as their second parameter, which is of interest to the state tracker (e.g. the VkPipelineCache handle
                    # from vkCreateGraphicsPipelines or the vkSwapchain handle from vkGetSwapchainImagesKHR). For api calls that do
                    # not receive a handle as the second parameter (e.g. vkEnumeratePhysicalDevices), the handle type is set to 'void*'.
                    if self.isHandle(values[1].baseType):
                        secondHandle = values[1]
                        decl += 'EndGroupCreateApiCallTrace<{}, {}, {}Wrapper, {}>({}, {}, {}, {}, {}, {}, encoder)'.format(parentHandle.baseType, secondHandle.baseType, handle.baseType[2:], infoBaseType, returnValue, parentHandle.name, secondHandle.name, lengthName, handle.name, infoName)
                    else:
                        decl += 'EndGroupCreateApiCallTrace<{}, void*, {}Wrapper, {}>({}, {}, nullptr, {}, {}, {}, encoder)'.format(parentHandle.baseType, handle.baseType[2:], infoBaseType, returnValue, parentHandle.name, lengthName, handle.name, infoName)

            else:
                if parentHandle:
                    decl += 'EndCreateApiCallTrace<{}, {}Wrapper, {}>({}, {}, {}, {}, encoder)'.format(parentHandle.baseType, handle.baseType[2:], infoBaseType, returnValue, parentHandle.name, handle.name, infoName)
                else:
                    # Instance creation does not have a parent handle; set the parent handle type to 'void*'.
                    decl += 'EndCreateApiCallTrace<const void*, {}Wrapper, {}>({}, nullptr, {}, {}, encoder)'.format(handle.baseType[2:], infoBaseType, returnValue, handle.name, infoName)

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

        elif values[0].baseType == 'VkCommandBuffer':
            getHandlesExpr = self.makeGetCommandHandlesExpr(name, values[1:])
            if getHandlesExpr:
                decl += 'EndCommandApiCallTrace({}, encoder, {})'.format(values[0].name, getHandlesExpr)
            else:
                decl += 'EndCommandApiCallTrace({}, encoder)'.format(values[0].name)
        else:
            if name in ['vkGetPhysicalDeviceDisplayPropertiesKHR']:
                # TODO: Handle vkEnumeratePhysicalDevices and vkGetPhysicalDeviceDisplayProprtiesKHR
                print('WARNING: Skipping special case "create" tracking for', name)

            decl += 'EndApiCallTrace(encoder)'

        decl += ';\n'
        return decl

    def makeHandleWrapping(self, values, indent):
        expr = ''
        for value in values:
            if self.isOutputParameter(value):
                parentType = 'InstanceWrapper'
                parentValue = 'VK_NULL_HANDLE'
                if self.isHandle(values[0].baseType):
                    parentType = values[0].baseType[2:] + 'Wrapper'
                    parentValue = values[0].name

                if value.isArray:
                    lengthName = value.arrayLength
                    for len in values:
                        if (len.name == lengthName) and len.isPointer:
                            lengthName = '({name} != nullptr) ? (*{name}) : 0'.format(name=lengthName)
                            break
                    if self.isHandle(value.baseType):
                        expr += indent + 'CreateWrappedHandles<{}, {}Wrapper>({}, {}, {}, TraceManager::GetUniqueId);\n'.format(parentType, value.baseType[2:], parentValue, value.name, lengthName)
                    elif self.isStruct(value.baseType) and (value.baseType in self.structsWithHandles):
                        expr += indent + 'CreateWrappedStructArrayHandles<{}, {}>({}, {}, {}, TraceManager::GetUniqueId);\n'.format(parentType, value.baseType, parentValue, value.name, lengthName)
                else:
                    if self.isHandle(value.baseType):
                        expr += indent + 'CreateWrappedHandle<{}, {}Wrapper>({}, {}, TraceManager::GetUniqueId);\n'.format(parentType, value.baseType[2:], parentValue, value.name)
                    elif self.isStruct(value.baseType) and (value.baseType in self.structsWithHandles):
                        expr += indent + 'CreateWrappedStructHandles<{}>({}, {}, TraceManager::GetUniqueId);\n'.format(parentType, parentValue, value.name)
        return expr

    def makeHandleUnwrapping(self, values, indent):
        expr = ''
        needStore = False
        needArrayStore = False
        for value in values:
            if value.isPointer or value.isArray:
                if self.isInputPointer(value):
                    lengthName = value.arrayLength
                    if self.isHandle(value.baseType):
                        if value.isArray:
                            needArrayStore = True
                            expr += indent + 'UnwrapHandles<{}Wrapper>(&{}, {}, handle_array_store, handle_unwrap_memory);\n'.format(value.baseType[2:], value.name, lengthName)
                        else:
                            needStore = True
                            expr += indent + 'UnwrapHandle<{}Wrapper>({}, handle_store);\n'.format(value.baseType[2:], value.name)
                    elif value.baseType in self.structsWithHandles:
                        needStore = True
                        needArrayStore = True
                        if value.isArray:
                            expr += indent + 'UnwrapStructArrayHandles({}, {}, handle_store, handle_array_store, handle_unwrap_memory);\n'.format(value.name, lengthName)
                        else:
                            expr += indent + 'UnwrapStructHandles({}, handle_store, handle_array_store, handle_unwrap_memory);\n'.format(value.name)
            elif self.isHandle(value.baseType):
                needStore = True
                expr += indent + 'UnwrapHandle<{}Wrapper>(&{}, handle_store);\n'.format(value.baseType[2:], value.name)
        return expr, needStore, needArrayStore

    def makeHandleRewrapping(self, values, indent):
        expr = ''
        for value in values:
            if value.isPointer or value.isArray:
                if self.isInputPointer(value):
                    lengthName = value.arrayLength
                    if self.isHandle(value.baseType):
                        if value.isArray:
                            expr += indent + 'RewrapHandles<{}Wrapper>(&{}, {}, &handle_array_store_iter);\n'.format(value.baseType[2:], value.name, lengthName)
                        else:
                            expr += indent + 'RewrapHandle<{}Wrapper>({}, &handle_store_iter);\n'.format(value.baseType[2:], value.name)
                    elif value.baseType in self.structsWithHandles:
                        if value.isArray:
                            expr += indent + 'RewrapStructArrayHandles({}, {}, &handle_store_iter, &handle_array_store_iter);\n'.format(value.name, lengthName)
                        else:
                            expr += indent + 'RewrapStructHandles({}, &handle_store_iter, &handle_array_store_iter);\n'.format(value.name)
            elif self.isHandle(value.baseType):
                expr += indent + 'RewrapHandle<{}Wrapper>(&{}, &handle_store_iter);\n'.format(value.baseType[2:], value.name)
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
            if self.isOutputParameter(value) and self.isHandle(value.baseType):
                return True
        return False

    def hasOutputs(self, returnValue, parameterValues):
        if returnValue != 'void':
            return True
        else:
            for value in parameterValues:
                if self.isOutputParameter(value):
                    return True
        return False
