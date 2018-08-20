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

class ApiCallReplayConsumerDefinitionsGeneratorOptions(BaseGeneratorOptions):
    """Options for Vulkan API parameter processing C++ code generation"""
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

# ApiCallReplayConsumerDefinitionsGenerator - subclass of BaseGenerator.
# Generates C++ member definitions for the VulkanReplayConsumer class responsible for
# replaying decoded Vulkan API call parameter data.
class ApiCallReplayConsumerDefinitionsGenerator(BaseGenerator):
    """Generate API parameter processing C++ member definitions"""
    def __init__(self,
                 errFile = sys.stderr,
                 warnFile = sys.stderr,
                 diagFile = sys.stdout):
        BaseGenerator.__init__(self,
                               processCmds=True, processStructs=True, featureBreak=True,
                               errFile=errFile, warnFile=warnFile, diagFile=diagFile)
        self.structsWithHandles = dict()                   # Map of Vulkan structs containing handles to a list of handle member names.

    #
    # Method override
    def genStruct(self, typeinfo, typename, alias):
        BaseGenerator.genStruct(self, typeinfo, typename, alias)

        handles = []
        if (typename not in self.STRUCT_BLACKLIST) and not alias:
            for value in self.featureStructMembers[typename]:
                if self.isHandle(value.baseType):
                    handles.append(value)
            if handles:
                self.structsWithHandles[typename] = handles

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
            values = info[2]

            cmddef = '' if first else '\n'
            cmddef += self.makeConsumerFuncDecl(returnType, 'VulkanReplayConsumer::Process_' + cmd, values) + '\n'
            cmddef += '{\n'
            cmddef += self.makeConsumerFuncBody(returnType, cmd, values)
            cmddef += '}'

            write(cmddef, file=self.outFile)
            first = False

    #
    # Return VulkanReplayConsumer class member function definition.
    def makeConsumerFuncBody(self, returnType, name, values):
        body = ''
        args, preexpr, postexpr = self.makeBodyExpressions(name, values)
        arglist = ', '.join(args)

        if preexpr:
            body += '\n'.join(['    ' + val for val in preexpr])
            body += '\n'
            body += '\n'
        if returnType == 'VkResult':
            body += '    VkResult replay_result = Dispatcher<ApiCallId_{name}, {}, PFN_{name}>::Dispatch(this, {name}, {});\n'.format(returnType, arglist, name=name)
            body += '    CheckResult("{}", returnValue, replay_result);\n'.format(name)
        else:
            body += '    Dispatcher<ApiCallId_{name}, {}, PFN_{name}>::Dispatch(this, {name}, {});\n'.format(returnType, arglist, name=name)
        if postexpr:
            body += '\n'
            body += '\n'.join(['    ' + val for val in postexpr])
            body += '\n'

        return body

    #
    # Generating expressions for mapping decoded parameters to arguments used in the API call
    def makeBodyExpressions(self, name, values):
        # For array lengths that are stored in pointers, this will map the original parameter name
        # to the temporary parameter name that was created to store the value to be provided to the Vulkan API call.
        arrayLengths = dict()

        args = []       # List of arguments to the API call.
        preexpr = []    # Variable declarations for handle mappings, temporary output allocations, and input pointers.
        postexpr = []   # Expressions to add new handles to the handle map and delete temporary allocations.

        for value in values:
            if value.isPointer or value.isArray:
                fullType = value.fullType
                pointerCount = value.pointerCount
                isInput = self.isInputPointer(value)

                if (value.isArray and not value.isDynamic):
                    # Use dynamic pointer syntax for static arrays.
                    pointerCount = 1;
                    fullType += '*'

                # Generate temporary variable to reference a pointer value that is encapsulated within a PointerDecoder object.
                argName = 'in_' + value.name if isInput else 'out_' + value.name
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
                        # TODO: Handle mapped memory pointer case (no warning needed for this case).
                        print("WARNING: Generating replay code for function {} with an unrecognized void* parameter.".format(name))
                        expr += 'nullptr;'
                    elif value.baseType == 'VkAllocationCallbacks':
                        # The replay consumer needs to override the allocation callbacks used by the captured application.
                        expr += 'GetAllocationCallbacks({});'.format(value.name)
                    elif self.isHandle(value.baseType):
                        # We received an array of 64-bit integer IDs from the decoder.
                        # We now need to allocate memory to hold handles, which we map from the IDs.
                        expr = expr.replace('const', '').lstrip() + '{}.IsNull() ? nullptr : AllocateArray<{}>({});'.format(value.name, value.baseType, lengthName)
                        preexpr.append(expr)
                        expr = 'MapHandles<{basetype}>({paramname}.GetPointer(), {paramname}.GetLength(), {}, {}, &VulkanObjectMapper::Map{basetype});'.format(argName, lengthName, paramname=value.name, basetype=value.baseType)
                        postexpr.append('FreeArray<{}>(&{});'.format(value.baseType, argName))
                    else:
                        # TODO: We should be able to remove the reinterpret_cast when we handle VkObjectTableEntryNVX** correctly
                        expr += 'reinterpret_cast<{}>({}.GetPointer());'.format(fullType, value.name)
                        if value.baseType in self.structsWithHandles:
                            # We need to map the handles.
                            handleValues = self.structsWithHandles[value.baseType]
                            wrapperName = argName + '_wrapper'
                            deallocations = []

                            # Strip the const from the type declaration.
                            expr = expr.replace('const ', '').lstrip()
                            preexpr.append(expr)
                            expr = ''

                            # Allocate memory for handles and perform mapping when the struct array is not NULL.
                            preexpr.append('if (!{}.IsNull())'.format(value.name))
                            preexpr.append('{')
                            indent = ' ' * self.INDENT_SIZE

                            preexpr.append(indent + 'const Decoded_{}* {} = {}.GetMetaStructPointer();'.format(value.baseType, wrapperName, value.name))

                            if value.isArray:
                                # Start a for loop to process all of the structures in the array.
                                preexpr.append(indent + 'assert({} == {}.GetLength());'.format(lengthName, value.name))
                                preexpr.append(indent + 'for (size_t i = 0; i < {}; ++i)'.format(lengthName))
                                preexpr.append(indent + '{')
                                indent += ' ' * self.INDENT_SIZE

                            for handleValue in handleValues:
                                srcname = wrapperName
                                dstname = argName
                                if value.isArray:
                                    # Index the array
                                    srcname += '[i].'
                                    dstname += '[i].'
                                else:
                                    # Dereference the pointer
                                    srcname += '->'
                                    dstname += '->'

                                if handleValue.isArray:
                                    # Allocate memory for the handles.
                                    allocation_name = handleValue.name + '_memory'
                                    allocation_expr = indent + '{}* {} = '.format(handleValue.baseType, allocation_name)
                                    if handleValue.isDynamic:
                                       allocation_expr += 'AllocateArray<{}>({}{});'.format(handleValue.baseType, dstname, handleValue.arrayLength)
                                       preexpr.append(allocation_expr)
                                       preexpr.append(indent + '{}{} = {};'.format(dstname, handleValue.name, allocation_name))
                                       deallocations.append('FreeArray<{}>(&{}{});'.format(handleValue.baseType, dstname, handleValue.name))
                                    else:
                                       allocation_expr += 'const_cast<{}*>({}{});'.format(handleValue.baseType, dstname, handleValue.name)
                                       preexpr.append(allocation_expr)

                                    # Mapping an array of handles.
                                    preexpr.append(indent + 'MapHandles<{handletype}>({srcname}{handlename}.GetPointer(), {srcname}{handlename}.GetLength(), {}, {argname}{}, &VulkanObjectMapper::Map{handletype});'.format(allocation_name, handleValue.arrayLength, srcname=srcname, handlename=handleValue.name, argname=dstname, handletype=handleValue.baseType))
                                else:
                                    # Mapping a single handle.
                                    preexpr.append(indent + '{}{membername} = object_mapper_.Map{}({}{membername});'.format(dstname, handleValue.baseType, srcname, membername=handleValue.name))

                            if value.isArray:
                                # End the for loop.
                                indent = ' ' * self.INDENT_SIZE
                                preexpr.append(indent + '}')

                            preexpr.append('}')

                            # Free any temporary allocations that were made.
                            if deallocations:
                                postexpr.append('if ({} != nullptr)'.format(argName))
                                postexpr.append('{')
                                indent = ' ' * self.INDENT_SIZE

                                if value.isArray:
                                    postexpr.append(indent + 'for (size_t i = 0; i < {}; ++i)'.format(lengthName))
                                    postexpr.append(indent + '{')
                                    indent += ' ' * self.INDENT_SIZE

                                for deallocation in deallocations:
                                    postexpr.append(indent + deallocation)

                                if value.isArray:
                                    indent = ' ' * self.INDENT_SIZE
                                    postexpr.append(indent + '}')

                                postexpr.append('}')
                else:
                    # Initialize output pointer.
                    # Note on output structures with handles: These strucutres are used in queries such as
                    # VkGetPhysicalDeviceGroupProperties and VkGetPhyusicalDeviceDisplayPropertiesKHR and do not
                    # require handle mapping for replay.
                    if value.isArray:
                        if value.baseType in self.EXTERNAL_OBJECT_TYPES:
                            expr = 'uint8_t* {} = {}.IsNull() ? nullptr : AllocateArray<uint8_t>({});'.format(argName, value.name, lengthName)
                            postexpr.append('FreeArray<uint8_t>(&{});'.format(argName))
                        else:
                            expr += '{}.IsNull() ? nullptr : AllocateArray<{}>({});'.format(value.name, value.baseType, lengthName)
                            if self.isHandle(value.baseType):
                                # Add mappings for the newly created handles
                                postexpr.append('AddHandles<{basetype}>({paramname}.GetPointer(), {paramname}.GetLength(), {}, {}, &VulkanObjectMapper::Add{basetype});'.format(argName, lengthName, paramname=value.name, basetype=value.baseType))
                            postexpr.append('FreeArray<{}>(&{});'.format(value.baseType, argName))
                    else:
                        if value.baseType in self.EXTERNAL_OBJECT_TYPES:
                            # TODO: Handle mapped memory pointer case.
                            print("WARNING: Generating replay code for function {} with an unrecognized void* parameter.".format(name))
                            outval = 'out_{}_value'.format(value.name)
                            preexpr.append('void{} {} = nullptr;'.format('*' * (value.pointerCount - 1), outval))
                            expr += '&{};'.format(outval)
                        else:
                            outval = 'out_{}_value'.format(value.name)
                            if self.isArrayLen(value.name, values):
                                # If this is an array length, it is an in/out parameter and we need to assign the input value.
                                preexpr.append('{basetype} {} = {paramname}.IsNull() ? static_cast<{basetype}>(0) : *({paramname}.GetPointer());'.format(outval, basetype = value.baseType, paramname = value.name))
                                # Need to store the name of the intermediate value for use with allocating the array associated with this length.
                                arrayLengths[value.name] = outval
                            elif self.isStruct(value.baseType):
                                preexpr.append('{basetype} {} = {{}};'.format(outval, basetype=value.baseType))
                            else:
                                preexpr.append('{basetype} {} = static_cast<{basetype}>(0);'.format(outval, basetype=value.baseType))

                            expr += '&{};'.format(outval)

                            if self.isHandle(value.baseType):
                                # Add mapping for the newly created handle
                                postexpr.append('AddHandles<{basetype}>({}.GetPointer(), 1, {}, 1, &VulkanObjectMapper::Add{basetype});'.format(value.name, argName, basetype=value.baseType))
                if expr:
                    preexpr.append(expr)
            elif self.isHandle(value.baseType):
                # Handles need to be mapped.
                argName = 'in_' + value.name
                args.append(argName)
                expr = '{} {} = '.format(value.fullType, argName)
                expr += 'object_mapper_.Map{}({});'.format(value.baseType, value.name)
                preexpr.append(expr)
            elif self.isFunctionPtr(value.baseType):
                # Function pointers are encoded as a 64-bit address value.
                # TODO: Check for cases that need to be handled.
                print("WARNING: Generating replay code for a function {} with a {} parameter that is undefined.".format(name, value.baseType))
            else:
                # Only need to append the parameter name to the args list; no other expressions are necessary.
                args.append(value.name)
        return args, preexpr, postexpr
