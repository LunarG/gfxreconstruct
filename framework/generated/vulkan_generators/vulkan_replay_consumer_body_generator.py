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

import os,re,sys,json
from base_generator import *

class VulkanReplayConsumerBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating a C++ class for Vulkan capture file replay"""
    def __init__(self,
                 replayOverrides = None,    # Path to JSON file listing Vulkan API calls to override on replay.
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
        self.replayOverrides = replayOverrides

# VulkanReplayConsumerBodyGenerator - subclass of BaseGenerator.
# Generates C++ member definitions for the VulkanReplayConsumer class responsible for
# replaying decoded Vulkan API call parameter data.
class VulkanReplayConsumerBodyGenerator(BaseGenerator):
    """Generate a C++ class for Vulkan capture file replay"""

    # Map of Vulkan function names to override function names.  Calls to Vulkan functions in the map
    # will be replaced by the override value.
    REPLAY_OVERRIDES = {}

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
        # Map of struct types to associated VkStructureType.
        self.sTypeValues = dict()


    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        if genOpts.replayOverrides:
            self.__loadReplayOverrides(genOpts.replayOverrides)

        write('#include "generated/generated_vulkan_replay_consumer.h"', file=self.outFile)
        self.newline()
        write('#include "decode/custom_vulkan_struct_handle_mappers.h"', file=self.outFile)
        write('#include "generated/generated_vulkan_dispatch_table.h"', file=self.outFile)
        write('#include "generated/generated_vulkan_struct_handle_mappers.h"', file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)

    # Method override
    def endFile(self):
        self.newline()
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    #
    # Method override
    def genStruct(self, typeinfo, typename, alias):
        BaseGenerator.genStruct(self, typeinfo, typename, alias)

        if not alias:
            self.checkStructMemberHandles(typename, self.structsWithHandles)

            sType = self.makeStructureTypeEnum(typeinfo, typename)
            if sType:
                self.sTypeValues[typename] = sType

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
            values = info[2]

            cmddef = '' if first else '\n'
            cmddef += self.makeConsumerFuncDecl(returnType, 'VulkanReplayConsumer::Process_' + cmd, values) + '\n'
            cmddef += '{\n'
            cmddef += self.makeConsumerFuncBody(returnType, cmd, values)
            cmddef += '}'

            write(cmddef, file=self.outFile)
            first = False

    #
    # Check for dispatchable handle types associated with the instance dispatch table.
    def useInstanceTable(self, typename):
        if typename in ['VkInstance', 'VkPhysicalDevice']:
            return True
        return False

    #
    # Return VulkanReplayConsumer class member function definition.
    def makeConsumerFuncBody(self, returnType, name, values):
        body = ''
        isOverride = name in self.REPLAY_OVERRIDES

        args, preexpr, postexpr = self.makeBodyExpressions(name, values, isOverride)
        arglist = ', '.join(args)

        dispatchfunc = ''
        if name not in ['vkCreateInstance', 'vkCreateDevice']:
            dispatchfunc = 'GetInstanceTable' if self.useInstanceTable(values[0].baseType) else 'GetDeviceTable'
            dispatchfunc += '({})->{}'.format(args[0], name[2:])

        callExpr = ''
        if isOverride:
            if name in ['vkCreateInstance', 'vkCreateDevice']:
                callExpr = '{}(returnValue, {})'.format(self.REPLAY_OVERRIDES[name], arglist)
            elif returnType == 'VkResult':
                # Override functions receive the decoded return value in addition to parameters.
                callExpr = '{}({}, returnValue, {})'.format(self.REPLAY_OVERRIDES[name], dispatchfunc, arglist)
            else:
                callExpr = '{}({}, {})'.format(self.REPLAY_OVERRIDES[name], dispatchfunc, arglist)
        else:
            callExpr = '{}({})'.format(dispatchfunc, arglist)

        if preexpr:
            body += '\n'.join(['    ' + val if val else val for val in preexpr])
            body += '\n'
            body += '\n'
        if returnType == 'VkResult':
            body += '    VkResult replay_result = {};\n'.format(callExpr)
            body += '    CheckResult("{}", returnValue, replay_result);\n'.format(name)
        else:
            body += '    {};\n'.format(callExpr)
        if postexpr:
            body += '\n'
            body += '\n'.join(['    ' + val if val else val for val in postexpr])
            body += '\n'

        return body

    #
    # Generating expressions for mapping decoded parameters to arguments used in the API call
    def makeBodyExpressions(self, name, values, isOverride):
        # For array lengths that are stored in pointers, this will map the original parameter name
        # to the temporary parameter name that was created to store the value to be provided to the Vulkan API call.
        arrayLengths = dict()

        args = []       # List of arguments to the API call.
        preexpr = []    # Variable declarations for handle mappings, temporary output allocations, and input pointers.
        postexpr = []   # Expressions to add new handles to the handle map and delete temporary allocations.

        for value in values:
            if value.isPointer or value.isArray:
                fullType = value.fullType if not value.platformFullType else value.platformFullType
                isInput = self.isInputPointer(value)

                if (value.isArray and not value.isDynamic):
                    # Use dynamic pointer syntax for static arrays.
                    fullType += '*'

                # Generate temporary variable to reference a pointer value that is encapsulated within a PointerDecoder object.
                if isInput:
                    argName = 'in_' + value.name
                else:
                    argName = 'out_' + value.name
                    if isOverride:
                        # The original value read from the file is provided to replay override functions.
                        args.append(value.name)

                args.append(argName)

                # Assign PointerDecoder pointer to temporary variable.
                expr = '{} {} = '.format(fullType, argName)

                # Determine name of variable specifying the length of an array.  An override may be required to
                # replace the original length value with a temporary pointer variable.
                lengthName = value.arrayLength
                if lengthName:
                    if lengthName in arrayLengths:
                        # Array lengths with pointer types are received by the consumer as PointerDecoder<T> objects, so
                        # an intermediate value of type T is created to hold the value that will be provided to the Vulkan
                        # API call.  The 'arrayLengths' dictionary contains a mapping of the original parameter name to the
                        # intermediate value name.  For this case, we need to use the intermediate value for array allocations.
                        lengthName = arrayLengths[lengthName]
                    elif '->' in lengthName:
                        # Some counts are members of an allocate info struct.  Similar to the above PointerDecoder<T> case,
                        # Pointers to structures are received in a StructPointerDecoder<T> object and an intermediate value is
                        # created to store the pointer encapsulated by the object.  This case also requires using the intermediate
                        # value to access the array length.  Prepending 'in_' to the 'arraylen' value is currently sufficient to
                        # handle this case.
                        lengthName = 'in_' + lengthName

                if isInput:
                    # Assign avalue to the temporary variable based on type.  Some array variables require temporary allocations.
                    if (value.baseType in self.EXTERNAL_OBJECT_TYPES) and not value.isArray:
                        # If this was an array with the 'void*' type, it was encoded as an array of bytes.
                        # If not (this case), it is a pointer to an unknown object type that was encoded as a uint64_t ID value.
                        # If possible, we will map the ID to an object previously created during replay.  Otherwise, we will
                        # need to report a warning that we may have a case that replay cannot handle.
                        if value.platformFullType:
                            expr += 'static_cast<{}>(PreProcessExternalObject({}, format::ApiCallId::ApiCall_{name}, "{name}"));'.format(value.platformFullType, value.name, name=name)
                        else:
                            expr += 'PreProcessExternalObject({}, format::ApiCallId::ApiCall_{name}, "{name}");'.format(value.name, name=name)
                    elif value.baseType == 'VkAllocationCallbacks':
                        # The replay consumer needs to override the allocation callbacks used by the captured application.
                        expr += 'GetAllocationCallbacks({});'.format(value.name)
                    elif self.isHandle(value.baseType):
                        # We received an array of 64-bit integer IDs from the decoder.
                        # We now need to allocate memory to hold handles, which we map from the IDs.
                        expr = expr.replace('const', '').lstrip() + '{}.GetHandlePointer();'.format(value.name)
                        preexpr.append(expr)
                        expr = 'MapHandles<{}Info>({paramname}.GetPointer(), {paramname}.GetLength(), {}, {}, &VulkanObjectMapper::Map{});'.format(value.baseType[2:], argName, lengthName, value.baseType, paramname=value.name)
                    else:
                        expr += '{}.GetPointer();'.format(value.name)
                        if value.baseType in self.structsWithHandles:
                            preexpr.append(expr)
                            if value.isArray:
                                expr = 'MapStructArrayHandles({name}.GetMetaStructPointer(), {name}.GetLength(), GetObjectMapper());'.format(name=value.name)
                            else:
                                expr = 'MapStructHandles({}.GetMetaStructPointer(), GetObjectMapper());'.format(value.name)
                else:
                    # Initialize output pointer.
                    # Note on output structures with handles: These structures are used in queries such as
                    # VkGetPhysicalDeviceGroupProperties and VkGetPhyusicalDeviceDisplayPropertiesKHR and do not
                    # require handle mapping for replay.
                    if value.isArray:
                        if value.baseType in self.EXTERNAL_OBJECT_TYPES:
                            expr = 'uint8_t* {} = {}.IsNull() ? nullptr : AllocateArray<uint8_t>({});'.format(argName, value.name, lengthName)
                            postexpr.append('FreeArray<uint8_t>(&{});'.format(argName))
                        elif self.isHandle(value.baseType):
                            # Add mappings for the newly created handles
                            expr += '{}.GetHandlePointer();'.format(value.name)
                            postexpr.append('AddHandles<{basetype}>({paramname}.GetPointer(), {paramname}.GetLength(), {}, {}, &VulkanObjectMapper::Add{basetype});'.format(argName, lengthName, paramname=value.name, basetype=value.baseType))
                        elif self.isStruct(value.baseType):
                            # If this is a struct with sType and pNext fields, we need to initialize them.
                            if value.baseType in self.sTypeValues:
                                # TODO: recreate pNext value read from the capture file.
                                expr += '{}.IsNull() ? nullptr : AllocateArray<{basetype}>({}, {basetype}{{ {}, nullptr }});'.format(value.name, lengthName, self.sTypeValues[value.baseType], basetype=value.baseType)
                            else:
                                expr += '{}.IsNull() ? nullptr : AllocateArray<{}>({});'.format(value.name, value.baseType, lengthName)
                            # If this is a struct with handles, we need to add replay mappings for the embedded handles
                            if value.baseType in self.structsWithHandles:
                                postexpr.append('AddStructArrayHandles<Decoded_{basetype}>({name}.GetMetaStructPointer(), {name}.GetLength(), {}, {}, GetObjectMapper());'.format(argName, lengthName, name=value.name, basetype=value.baseType))
                            postexpr.append('FreeArray<{}>(&{});'.format(value.baseType, argName))
                        else:
                            expr += '{}.IsNull() ? nullptr : AllocateArray<{}>({});'.format(value.name, value.baseType, lengthName)
                            postexpr.append('FreeArray<{}>(&{});'.format(value.baseType, argName))
                    else:
                        if value.baseType in self.EXTERNAL_OBJECT_TYPES:
                            outName = 'out_{}_value'.format(value.name)
                            outType = 'void' if not value.platformBaseType else value.platformBaseType
                            outCount = value.pointerCount if not value.platformFullType else self.getPointerCount(value.platformFullType)
                            preexpr.append('{}{} {} = nullptr;'.format(outType, '*' * (outCount - 1), outName))
                            expr += '&{};'.format(outName)

                            # Map the object ID to the new object
                            if value.platformFullType:
                                postexpr.append('PostProcessExternalObject({}, static_cast<void*>({}), format::ApiCallId::ApiCall_{name}, "{name}");'.format(value.name, outName, name=name))
                            else:
                                postexpr.append('PostProcessExternalObject({}, {}, format::ApiCallId::ApiCall_{name}, "{name}");'.format(value.name, outName, name=name))
                        elif self.isHandle(value.baseType):
                            # Add mapping for the newly created handle
                            expr += '{}.GetHandlePointer();'.format(value.name)
                            postexpr.append('AddHandles<{basetype}>({}.GetPointer(), 1, {}, 1, &VulkanObjectMapper::Add{basetype});'.format(value.name, argName, basetype=value.baseType))
                        else:
                            outName = 'out_{}_value'.format(value.name)
                            if self.isArrayLen(value.name, values):
                                # If this is an array length, it is an in/out parameter and we need to assign the input value.
                                preexpr.append('{basetype} {} = {paramname}.IsNull() ? static_cast<{basetype}>(0) : *({paramname}.GetPointer());'.format(outName, basetype = value.baseType, paramname = value.name))
                                # Need to store the name of the intermediate value for use with allocating the array associated with this length.
                                arrayLengths[value.name] = outName
                            elif self.isStruct(value.baseType):
                                # If this is a struct with sType and pNext fields, we need to initialize them.
                                if value.baseType in self.sTypeValues:
                                    # TODO: recreate pNext value read from the capture file.
                                    preexpr.append('{basetype} {} = {{ {}, nullptr }};'.format(outName, self.sTypeValues[value.baseType], basetype=value.baseType))
                                else:
                                    preexpr.append('{basetype} {} = {{}};'.format(outName, basetype=value.baseType))
                                # If this is a struct with handles, we need to add replay mappings for the embedded handles
                                if value.baseType in self.structsWithHandles:
                                    postexpr.append('AddStructHandles<Decoded_{basetype}>({name}.GetMetaStructPointer(), {}, GetObjectMapper());'.format(argName, name=value.name, basetype=value.baseType))
                            else:
                                preexpr.append('{basetype} {} = static_cast<{basetype}>(0);'.format(outName, basetype=value.baseType))

                            expr += '&{};'.format(outName)
                if expr:
                    preexpr.append(expr)
            elif self.isHandle(value.baseType):
                # Handles need to be mapped.
                argName = 'in_' + value.name
                args.append(argName)
                expr = '{} {} = '.format(value.fullType, argName)
                expr += 'MapHandle<{}Info>({}, &VulkanObjectMapper::Map{});'.format(value.baseType[2:], value.name, value.baseType)
                preexpr.append(expr)
            elif self.isFunctionPtr(value.baseType):
                # Function pointers are encoded as a 64-bit address value.
                # TODO: Check for cases that need to be handled.
                print("WARNING: Generating replay code for a function {} with a {} parameter that is undefined.".format(name, value.baseType))
            else:
                # Only need to append the parameter name to the args list; no other expressions are necessary.
                args.append(value.name)
        return args, preexpr, postexpr

    def __loadReplayOverrides(self, filename):
        overrides = json.loads(open(filename, 'r').read())
        self.REPLAY_OVERRIDES = overrides['functions']
