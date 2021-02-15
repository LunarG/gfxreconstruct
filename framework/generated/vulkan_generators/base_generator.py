#!/usr/bin/python3 -i
#
# Copyright (c) 2018-2020 Valve Corporation
# Copyright (c) 2018-2020 LunarG, Inc.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to
# deal in the Software without restriction, including without limitation the
# rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
# sell copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
# IN THE SOFTWARE.
#
# The content of this file was derived from the Khronos Registry cgenerator.py
# and related Python files found in the KhronosGroup/Vulkan-Headers GitHub repository.
#
# Copyright (c) 2013-2016 The Khronos Group Inc.
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
from generator import (GeneratorOptions, OutputGenerator, noneStr, regSortFeatures, write)
from vkconventions import VulkanConventions


def _makeREstring(list, default = None):
    """Turn a list of strings into a regexp string matching exactly those strings.
    From Khronos genvk.py
    """
    if (len(list) > 0) or (default is None):
        return '^(' + '|'.join(list) + ')$'
    else:
        return default

# Descriptive names for various regexp patterns used to select versions and extensions.
# From Khronos genvk.py
_defaultExtensions  = 'vulkan'
_extensions         = _features         = []
_removeExtensions   = _emitExtensions   = []

# Turn lists of names/patterns into matching regular expressions.
# From Khronos genvk.py
_addExtensionsPat     = _makeREstring(_extensions)
_removeExtensionsPat  = _makeREstring(_removeExtensions)
_emitExtensionsPat    = _makeREstring(_emitExtensions, '.*')
_featuresPat          = _makeREstring(_features, '.*')


class ValueInfo():
    """ValueInfo - Class to store parameter/struct member information.
    Contains information descripting Vulkan API call parameters and struct members.

    Members:
      name - Parameter/struct member name of the value.
      base_type - Undecorated typename of the value.
      full_type - Fully qualified typename of the value.
      pointer_count - Number of '*' characters in the type declaration.
      array_length - The parameter that specifies the number of elements in an array, or None if the value is not an array.
      array_capacity - The max size of a statically allocated array, or None for a dynamically allocated array.
      array_dimension - Number of the array dimension
      platform_base_type - For platform specific type definitions, stores the original base_type declaration before platform to trace type substitution.
      platform_full_type - For platform specific type definitions, stores the original full_type declaration before platform to trace type substitution.
      is_pointer - True if the value is a pointer.
      is_array - True if the member is an array.
      is_dynamic - True if the memory for the member is an array and it is dynamically allocated.
      is_const - True if the member is a const.
    """

    def __init__(self,
                 name,
                 baseType,
                 fullType,
                 pointerCount = 0,
                 arrayLength = None,
                 arrayLengthValue = None,
                 arrayCapacity = None,
                 arrayDimension = None,
                 platformBaseType = None,
                 platformFullType = None,
                 bitfieldWidth = None,
                 isConst = False,
                 unionMembers = None,
                 is_com_outptr = False):
        self.name = name
        self.baseType = baseType
        self.fullType = fullType
        self.pointerCount = pointerCount
        self.arrayLength = arrayLength
        self.arrayLengthValue = arrayLengthValue
        self.arrayCapacity = arrayCapacity
        self.arrayDimension = arrayDimension
        self.platformBaseType = platformBaseType
        self.platformFullType = platformFullType
        self.bitfieldWidth = bitfieldWidth

        self.isPointer = True if pointerCount > 0 else False
        self.isArray = True if arrayLength else False
        self.isDynamic = True if not arrayCapacity else False
        self.isConst = isConst
        self.unionMembers = unionMembers
        self.is_com_outptr = is_com_outptr


class BaseGeneratorOptions(GeneratorOptions):
    """BaseGeneratorOptions - subclass of GeneratorOptions.
    Options for Vulkan API parameter encoding and decoding C++ code generation.

    Adds options used by FrameworkGenerator objects during C++ language
    code generation.

    Additional members
      blacklists - Path to JSON file listing apicalls and structs to ignore.
      platform_types - Path to JSON file listing platform (WIN32, X11, etc.)
        specific types that are defined outside of the Vulkan header.

    Additional members (from Khronos Registry COptionsGenerator)
      prefix_text - list of strings to prefix generated header with
        (usually a copyright statement + calling convention macros).
      protect_file - True if multiple inclusion protection should be
        generated (based on the filename) around the entire header.
      apicall - string to use for the function declaration prefix,
        such as APICALL on Windows.
      apientry - string to use for the calling convention macro,
        in typedefs, such as APIENTRY.
      apientryp - string to use for the calling convention macro
        in function pointer typedefs, such as APIENTRYP.
      indent_func_proto - True if prototype declarations should put each
        parameter on a separate line
      indent_func_pointer - True if typedefed function pointers should put each
        parameter on a separate line
      align_func_param - if nonzero and parameters are being put on a
        separate line, align parameter names at the specified column
    """

    def __init__(self,
                 blacklists = None,         # Path to JSON file listing apicalls and structs to ignore.
                 platformTypes = None,      # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
                 # Khronos CGeneratorOptions
                 filename = None,
                 directory = '.',
                 prefixText = '',
                 protectFile = False,
                 protectFeature = True,
                 conventions = VulkanConventions(),
                 apicall = 'VKAPI_ATTR ',
                 apientry = 'VKAPI_CALL ',
                 apientryp = 'VKAPI_PTR *',
                 indentFuncProto = True,
                 alignFuncParam = 48,
                 sortProcedure = regSortFeatures,
                 apiname = 'vulkan',
                 profile = None,
                 versions = _featuresPat,
                 emitversions = _featuresPat,
                 defaultExtensions = _defaultExtensions,
                 addExtensions = _addExtensionsPat,
                 removeExtensions = _removeExtensionsPat,
                 emitExtensions = _emitExtensionsPat):
        GeneratorOptions.__init__(self,
                                  conventions=conventions,
                                  filename=filename,
                                  directory=directory,
                                  apiname=apiname,
                                  profile=profile,
                                  versions=versions,
                                  emitversions=emitversions,
                                  defaultExtensions=defaultExtensions,
                                  addExtensions=addExtensions,
                                  removeExtensions=removeExtensions,
                                  emitExtensions=emitExtensions,
                                  sortProcedure=sortProcedure)
        self.blacklists = blacklists
        self.platformTypes = platformTypes
        # Khronos CGeneratorOptions
        self.prefixText      = prefixText
        self.protectFile     = protectFile
        self.protectFeature  = protectFeature
        self.apicall         = apicall
        self.apientry        = apientry                  # NOTE: While not used in this file, apientry is expected to be defined here by the OutputGenerator base class.
        self.apientryp       = apientryp                 # NOTE: While not used in this file, apientry is expected to be defined here by the OutputGenerator base class.
        self.indentFuncProto = indentFuncProto
        self.alignFuncParam  = alignFuncParam
        self.codeGenerator   = True


class BaseGenerator(OutputGenerator):
    """BaseGenerator - subclass of OutputGenerator.
    Base class providing common operations used to generate C++-language code for framework
      components that encode and decode Vulkan API parameters.
    Base class for Vulkan API parameter encoding and decoding generators.
    """

    # These API calls should not be processed by the code generator.  They require special implementations.
    APICALL_BLACKLIST = []

    # These structures should not be processed by the code generator.  They require special implementations.
    STRUCT_BLACKLIST = []

    # Platform specific basic types that have been defined extarnally to the Vulkan header.
    PLATFORM_TYPES = {}

    # Platform specific structure types that have been defined extarnally to the Vulkan header.
    PLATFORM_STRUCTS = []

    GENERIC_HANDLE_APICALLS = {'vkDebugReportMessageEXT' : {'object' : 'objectType' },
                               'vkSetPrivateDataEXT' : {'objectHandle' : 'objectType' },
                               'vkGetPrivateDataEXT' : {'objectHandle' : 'objectType' }}

    GENERIC_HANDLE_STRUCTS = {'VkDebugMarkerObjectNameInfoEXT' : {'object' : 'objectType' },
                              'VkDebugMarkerObjectTagInfoEXT' : {'object' : 'objectType' },
                              'VkDebugUtilsObjectNameInfoEXT' : {'objectHandle' : 'objectType' },
                              'VkDebugUtilsObjectTagInfoEXT' : {'objectHandle' : 'objectType' }}

    # These types represent pointers to non-Vulkan objects that were written as 64-bit address IDs.
    EXTERNAL_OBJECT_TYPES = ['void', 'Void']

    # Dispatchable handle types.
    DISPATCHABLE_HANDLE_TYPES = ['VkInstance', 'VkPhysicalDevice', 'VkDevice', 'VkQueue', 'VkCommandBuffer']

    # Default C++ code indentation size.
    INDENT_SIZE = 4

    def __init__(self,
                 processCmds,
                 processStructs,
                 featureBreak = True,
                 errFile = sys.stderr,
                 warnFile = sys.stderr,
                 diagFile = sys.stdout):
        OutputGenerator.__init__(self, errFile, warnFile, diagFile)

        # Typenames
        self.structNames = set()                          # Set of Vulkan struct typenames
        self.handleNames = set()                          # Set of Vulkan handle typenames
        self.flagsNames = set()                           # Set of bitmask (flags) typenames
        self.enumNames = set()                            # Set of Vulkan enumeration typenames

        # Type processing options
        self.processCmds = processCmds                    # Populate the featureCmdParams map
        self.processStructs = processStructs              # Populate the featureStructMembers map
        self.featureBreak = featureBreak                  # Insert a line break between features

        # Command parameter and struct member data for the current feature
        if self.processStructs:
            self.featureStructMembers = dict()            # Map of struct names to lists of per-member ValueInfo
            self.featureStructAliases = dict()            # Map of struct names to aliases
            self.extensionStructsWithHandles = dict()     # Map of extension struct names to a Boolean value indicating that a struct member has a handle type
            self.extensionStructsWithHandlePtrs = dict()  # Map of extension struct names to a Boolean value indicating that a struct member with a handle type is a pointer
        if self.processCmds:
            self.featureCmdParams = dict()                # Map of cmd names to lists of per-parameter ValueInfo

    def needFeatureGeneration(self):
        """Indicates that the current feature has C++ code to generate.
        The subclass should override this method."""
        return False

    def generateFeature(self):
        """Performs C++ code generation for the feature.
        The subclass should override this method."""
        pass

    def beginFile(self, genOpts):
        """Method override."""
        OutputGenerator.beginFile(self, genOpts)

        if genOpts.blacklists:
            self.__loadBlacklists(genOpts.blacklists)
        if genOpts.platformTypes:
            self.__loadPlatformTypes(genOpts.platformTypes)

            # Platform defined struct processing must be implemented manually,
            # so these structs will be added to the blacklist.
            self.STRUCT_BLACKLIST += self.PLATFORM_STRUCTS

        # User-supplied prefix text, if any (list of strings)
        if (genOpts.prefixText):
            for s in genOpts.prefixText:
                write(s, file=self.outFile)

        # Multiple inclusion protection & C++ wrappers.
        if (genOpts.protectFile and self.genOpts.filename):
            headerSym = 'GFXRECON_' + re.sub('\.h', '_H', os.path.basename(self.genOpts.filename)).upper()
            write('#ifndef ', headerSym, file=self.outFile)
            write('#define ', headerSym, file=self.outFile)
            self.newline()

    def endFile(self):
        """Method override."""
        # Finish C++ wrapper and multiple inclusion protection
        if (self.genOpts.protectFile and self.genOpts.filename):
            self.newline()
            write('#endif', file=self.outFile)

        # Finish processing in superclass
        OutputGenerator.endFile(self)

    def beginFeature(self, interface, emit):
        """Method override. Start processing in superclass."""
        OutputGenerator.beginFeature(self, interface, emit)

        # Reset feature specific data sets
        if self.processStructs:
            self.featureStructMembers = dict()
            self.featureStructAliases = dict()
        if self.processCmds:
            self.featureCmdParams = dict()

        # Some generation cases require that extra feature protection be suppressed
        if self.genOpts.protectFeature:
            self.featureExtraProtect = self.__getFeatureProtect(interface)

    def endFeature(self):
        """Method override. Generate code for the feature."""
        if self.emit and self.needFeatureGeneration():
            if self.featureBreak:
                self.newline()

            if (self.featureExtraProtect is not None):
                write('#ifdef', self.featureExtraProtect, file=self.outFile)

            self.generateFeature()

            if (self.featureExtraProtect is not None):
                write('#endif /*', self.featureExtraProtect, '*/', file=self.outFile)

        # Finish processing in superclass
        OutputGenerator.endFeature(self)

    def genType(self, typeinfo, name, alias):
        """Method override. Type generation."""
        OutputGenerator.genType(self, typeinfo, name, alias)
        typeElem = typeinfo.elem
        # If the type is a struct type, traverse the imbedded <member> tags
        # generating a structure. Otherwise, emit the tag text.
        category = typeElem.get('category')
        if (category == 'struct' or category == 'union'):
            self.structNames.add(name)
            # Skip code generation for union encode/decode functions.
            if category == 'struct':
                self.genStruct(typeinfo, name, alias)
        elif (category == 'handle'):
            self.handleNames.add(name)
        elif (category == 'bitmask'):
            self.flagsNames.add(name)

    def genStruct(self, typeinfo, typename, alias):
        """Method override.
        Struct (e.g. C "struct" type) generation.
        This is a special case of the <type> tag where the contents are
        interpreted as a set of <member> tags instead of freeform C
        C type declarations. The <member> tags are just like <param>
        tags - they are a declaration of a struct or union member.
        """
        OutputGenerator.genStruct(self, typeinfo, typename, alias)
        # For structs, we ignore the alias because it is a typedef.  Not ignoring the alias
        # would produce multiple definition errors for functions with struct parameters.
        if self.processStructs:
            if not alias:
                self.featureStructMembers[typename] = self.makeValueInfo(typeinfo.elem.findall('.//member'))
            else:
                self.featureStructAliases[typename] = alias

    def genGroup(self, groupinfo, groupName, alias):
        """Method override.
        Group (e.g. C "enum" type) generation.
        These are concatenated together with other types.
        """
        OutputGenerator.genGroup(self, groupinfo, groupName, alias)
        self.enumNames.add(groupName)

    def genEnum(self, enuminfo, name, alias):
        """Method override.
        Enumerant generation
        <enum> tags may specify their values in several ways, but are usually
        just integers.
        """
        OutputGenerator.genEnum(self, enuminfo, name, alias)

    def genCmd(self, cmdinfo, name, alias):
        """Method override. Command generation."""
        OutputGenerator.genCmd(self, cmdinfo, name, alias)
        if self.processCmds:
            # Create the declaration for the function prototype
            proto = cmdinfo.elem.find('proto')
            protoDecl = self.genOpts.apicall + noneStr(proto.text)
            for elem in proto:
                text = noneStr(elem.text)
                tail = noneStr(elem.tail)
                if (elem.tag == 'name'):
                    if text.startswith('vk'):
                        text = text[2:]
                    protoDecl += self.makeProtoName(text, tail)
                else:
                    protoDecl += text + tail

            returnType = noneStr(proto.text) + noneStr(proto.find('type').text)

            # TODO: Define a class or namedtuple for the dictionary entry
            self.featureCmdParams[name] = (returnType, protoDecl, self.makeValueInfo(cmdinfo.elem.findall('param')))

    def makeValueInfo(self, params):
        """Generate a list of ValueInfo objects from a list of <param> or <member> tags
         params - list of <param> or <member> tags to process
        """
        values = []
        for param in params:
            # Get name
            elem = param.find('name')
            name = noneStr(elem.text)
            nameTail = noneStr(elem.tail)

            # Get type info
            elem = param.find('type')
            baseType = noneStr(elem.text)
            fullType = (noneStr(param.text) + baseType + noneStr(elem.tail)).strip()

            # Check for platform specific type definitions that need to be converted to a recognized trace format type.
            platformBaseType = None
            platformFullType = None
            if baseType in self.PLATFORM_TYPES:
                typeInfo = self.PLATFORM_TYPES[baseType]
                platformBaseType = baseType
                platformFullType = fullType
                fullType = fullType.replace(baseType, typeInfo['replaceWith'])
                baseType = typeInfo['baseType']

            # Get array length, always use altlen when available to avoid parsing latexmath
            if 'altlen' in param.attrib:
                arrayLength =  param.attrib.get('altlen')
            else:
                arrayLength = self.getArrayLen(param)

            arrayCapacity = None
            if self.isStaticArray(param):
                arrayCapacity = arrayLength
                arrayLength = self.getStaticArrayLen(name, params, arrayCapacity)

            # Get bitfield width
            bitfieldWidth = None
            if ':' in nameTail:
                bitfieldWidth = nameTail

            values.append(ValueInfo(
                name = name,
                baseType = baseType,
                fullType = fullType,
                pointerCount = self.getPointerCount(fullType),
                arrayLength = arrayLength,
                arrayCapacity = arrayCapacity,
                platformBaseType = platformBaseType,
                platformFullType = platformFullType,
                bitfieldWidth = bitfieldWidth))

        # Link array values to their corresponding length values
        for arrayValue in [v for v in values if v.arrayLength]:
            for v in values:
                if re.search(r'\b{}\b'.format(v.name), arrayValue.arrayLength):
                    arrayValue.arrayLengthValue = v
                    break

        return values

    def isStruct(self, baseType):
        """Check for struct type."""
        if (baseType in self.structNames) or (baseType in self.PLATFORM_STRUCTS):
            return True
        return False

    def isClass(self, value):
        return False

    def isHandle(self, baseType):
        """Check for handle type."""
        if baseType in self.handleNames:
            return True
        return False

    def isDispatchableHandle(self, baseType):
        """Check for dispatchable handle type."""
        if baseType in self.DISPATCHABLE_HANDLE_TYPES:
            return True
        return False

    def isEnum(self, baseType):
        """Check for enum type."""
        if baseType in self.enumNames:
            return True
        return False

    def isFlags(self, baseType):
        """Check for flags (bitmask) type."""
        if baseType in self.flagsNames:
            return True
        return False

    def isFunctionPtr(self, baseType):
        """Check for function pointer type."""
        if baseType[:4] == 'PFN_':
            return True
        return False

    def isArrayLen(self, name, values):
        """Determine if the value name specifies an array length."""
        for value in values:
            if name == value.arrayLength:
                return True
        return False

    def getPointerCount(self, fullType):
        """Return the number of '*' in a type declaration."""
        return fullType.count('*')

    def isInputPointer(self, value):
        """Determine if a pointer parameter is an input parameter."""
        if 'const' in value.fullType:
            # Vulkan seems to follow a pattern where input pointers will be const and output pointers will not be const.
            return True
        elif value.platformBaseType and value.baseType == 'void' and value.pointerCount == 1:
            # For some extensions, platform specific handles are mapped to the 'void*' type without a const qualifier,
            # but need to be treated as an input (eg. if HANDLE is mapped to void*, it should not be treated as an output).
            return True
        return False

    def isOutputParameter(self, value):
        """Determine if a parameter is an output parameter."""
        # Check for an output pointer/array or an in-out pointer.
        if (value.isPointer or value.isArray) and not self.isInputPointer(value):
            return True
        return False

    def getArrayLen(self, param):
        """Retrieve the length of an array defined by a <param> or <member> element."""
        result = None
        len = param.attrib.get('len')
        if len:
            # Check for a string or array of strings
            if 'null-terminated' in len:
                # Strings are ignored, but string arrays are checked for a length value.
                # For string arrays, 'len' can look like 'count,null-terminated', indicating that we have an array of null terminated
                # strings.  We strip the null-terminated substring from the 'len' field and only return the parameter specifying the string count.
                if len != 'null-terminated':
                    result = len.split(',')[0]
            else:
                result = len
            if result:
                result = str(result).replace('::', '->')
        else:
            # Check for a static array
            paramname = param.find('name')
            if (paramname.tail is not None) and ('[' in paramname.tail):
                paramenumsize = param.find('enum')
                if paramenumsize is not None:
                    result = paramenumsize.text
                else:
                    paramsizes = paramname.tail[1:-1].split('][')
                    sizetokens = []
                    for paramsize in paramsizes:
                        sizetokens.append(paramsize)
                    result = ', '.join(sizetokens)
        return result

    def isStaticArray(self, param):
        """Check for a static array."""
        name = param.find('name')
        if (name.tail is not None) and ('[' in name.tail):
            return True
        return False

    def getStaticArrayLen(self, name, params, capacity):
        """Determine the length value of a static array (get_array_len() returns the total capacity, not the actual length)."""
        # The XML registry does not provide a direct method for determining if a parameter provides the length
        # of a static array, but the parameter naming follows a pattern of array name = 'values' and length
        # name = 'valueCount'.  We will search the parameter list for a length parameter using this pattern.
        lengthName = name[:-1] + 'Count'
        for param in params:
            if lengthName == noneStr(param.find('name').text):
                return lengthName

        # Not all static arrays have an associated length parameter. These will use capacity as length.
        return capacity

    def isStructBlackListed(self, typename):
        """Determines if a struct with the specified typename is blacklisted."""
        if typename in self.STRUCT_BLACKLIST:
            return True
        return False

    def isCmdBlackListed(self, name):
        """Determines if a struct with the specified typename is blacklisted."""
        if name in self.APICALL_BLACKLIST:
            return True
        return False

    def getFilteredStructNames(self):
        """Retrieves a filtered list of keys from self.feature_struct_memebers with blacklisted items removed."""
        return [key for key in self.featureStructMembers if not self.isStructBlackListed(key)]

    def getFilteredCmdNames(self):
        """Retrieves a filtered list of keys from self.feature_cmd_params with blacklisted items removed."""
        return [key for key in self.featureCmdParams if not self.isCmdBlackListed(key)]

    def checkStructPNextHandles(self, typename):
        """Determines if the specified struct type can reference pNext extension structs that contain handles."""
        foundHandles = False
        foundHandlePtrs = False
        validExtensionStructs = self.registry.validextensionstructs.get(typename)
        if validExtensionStructs:
            # Need to search the XML tree for pNext structures that have not been processed yet.
            for structName in validExtensionStructs:
                # Check for cached results from a previous check for this struct
                if structName in self.extensionStructsWithHandles:
                    if self.extensionStructsWithHandles[structName]:
                        foundHandles = True
                    if self.extensionStructsWithHandlePtrs[structName]:
                        foundHandlePtrs = True
                else:
                    # If a pre-existing result was not found, check the XML registry for the struct
                    hasHandles = False
                    hasHandlePtrs = False
                    typeInfo = self.registry.lookupElementInfo(structName, self.registry.typedict)
                    if typeInfo:
                        memberInfos = [member for member in typeInfo.elem.findall('.//member/type')]
                        if memberInfos:
                            for memberInfo in memberInfos:
                                found = self.registry.tree.find("types/type/[name='" + memberInfo.text + "'][@category='handle']")
                                if found:
                                    hasHandles = True
                                    self.extensionStructsWithHandles[structName] = True
                                    if memberInfo.tail and ('*' in memberInfo.tail):
                                        self.extensionStructsWithHandlePtrs[structName] = True
                                        hasHandlePtrs = True
                                    else:
                                        self.extensionStructsWithHandlePtrs[structName] = False

                    if hasHandles:
                        foundHandles = True
                        if hasHandlePtrs:
                            fountHandlePtrs = True
                    else:
                        self.extensionStructsWithHandles[structName] = False
                        self.extensionStructsWithHandlePtrs[structName] = False

        return foundHandles, foundHandlePtrs

    def checkStructMemberHandles(self, typename, structsWithHandles, structsWithHandlePtrs = None):
        """Determines if the specified struct type contains members that have a handle type or are structs that contain handles.
        Structs with member handles are added to a dictionary, where the key is the structure type and the value is a list of the handle members.
        An optional list of structure types that contain handle members with pointer types may also be generated.
        """
        handles = []
        hasHandlePointer = False
        for value in self.featureStructMembers[typename]:
            if self.isHandle(value.baseType):
                # The member is a handle.
                handles.append(value)
                if (not structsWithHandlePtrs is None) and (value.isPointer or value.isArray):
                    hasHandlePointer = True
            elif self.isStruct(value.baseType) and (value.baseType in structsWithHandles):
                # The member is a struct that contains a handle.
                handles.append(value)
                if (not structsWithHandlePtrs is None)  and (value.name in structsWithHandlePtrs):
                    hasHandlePointer = True
            elif 'pNext' in value.name:
                # The pNext chain may include a struct with handles.
                hasPNextHandles, hasPNextHandlePtrs = self.checkStructPNextHandles(typename)
                if hasPNextHandles:
                    handles.append(value)
                    if (not structsWithHandlePtrs is None) and hasPNextHandlePtrs:
                        hasHandlePointer = True
        if handles:
            structsWithHandles[typename] = handles
            if (not structsWithHandlePtrs is None) and hasHandlePointer:
                structsWithHandlePtrs.append(typename)
            return True
        return False

    def getGenericStructHandleTypeValue(self, structName, memberName):
        """For a struct member that contains a generic handle value, retrieve the struct member
        containing an enum value defining the specific handle type.  Generic handles have an
        integer type such as uint64_t, with an associated enum value defining the specific
        type such as VkObjectType.
        """
        if structName in self.GENERIC_HANDLE_STRUCTS:
            structEntry = self.GENERIC_HANDLE_STRUCTS[structName]
            if memberName in structEntry:
                return structEntry[memberName]
        return None

    def getGenericCmdHandleTypeValue(self, cmdName, paramName):
        """For an API call parameter that contains a generic handle value, retrieve the parameter
        containing an enum value defining the specific handle type.  Generic handles have an
        integer type such as uint64_t, with an associated enum value defining the specific
        type such as VkObjectType.
        """
        if cmdName in self.GENERIC_HANDLE_APICALLS:
            cmdEntry = self.GENERIC_HANDLE_APICALLS[cmdName]
            if paramName in cmdEntry:
                return cmdEntry[paramName]
        return None

    def isGenericStructHandleValue(self, structName, memberName):
        """Determine if a struct member contains a generic handle value.  Generic handles have an
        integer type such as uint64_t, with an associated enum value defining the specific
        type such as VkObjectType.
        """
        if self.getGenericStructHandleTypeValue(structName, memberName):
            return True
        return False

    def isGenericCmdHandleValue(self, cmdName, paramName):
        """Determine if an API call parameter contains a generic handle value.  Generic handles have an
        integer type such as uint64_t, with an associated enum value defining the specific
        type such as VkObjectType.
        """
        if self.getGenericCmdHandleTypeValue(cmdName, paramName):
            return True
        return False

    def indent(self, value, spaces):
        """Indent all lines in a string.
        value - String to indent.
        spaces - Number of spaces to indent.
        """
        prefix = ' ' * spaces
        return '\n'.join([prefix + v if v else v for v in value.split('\n')])

    def makeArgList(self, values):
        """Create a string containing a comma separated argument list from a list of ValueInfo values.
        values - List of ValueInfo objects providing the parameter names for the argument list.
        """
        return ', '.join([value.name for value in values])

    def makeAlignedParamDecl(self, paramType, paramName, indentColumn, alignColumn):
        """make_aligned_param_decl - return an indented parameter declaration string with the parameter
        name aligned to the specified column.
        """
        paramDecl = ' ' * indentColumn
        paramDecl += paramType

        if alignColumn:
            paramDecl = paramDecl.ljust(alignColumn - 1)

        paramDecl += ' '
        paramDecl += paramName

        return paramDecl

    def makeInvocationTypeName(self, baseType):
        """Convert a type name to a string to be used as part of an encoder/decoder function/method name."""
        if self.isStruct(baseType):
            return baseType
        elif self.isHandle(baseType):
            return 'Handle'
        elif self.isFlags(baseType):
            return 'Flags'
        elif self.isEnum(baseType):
            return 'Enum'
        elif baseType == 'wchar_t':
            return 'WString'
        elif baseType == 'char':
            return 'String'
        elif self.isFunctionPtr(baseType):
            return 'FunctionPtr'
        elif baseType == 'size_t':
            return 'SizeT'
        elif baseType == 'int':
            # Extensions use the int type when dealing with file descriptors
            return 'Int32'
        elif baseType.endswith('_t'):
            if baseType[0] == 'u':
                # For unsigned types, capitalize the first two characters.
                return baseType[0].upper() + baseType[1].upper() + baseType[2:-2]
            else:
                return baseType[:-2].title()
        elif baseType[0].islower():
            return baseType.title()

        return baseType

    def makeDecodedParamType(self, value):
        """Create a type to use for a decoded parameter, using the decoder wrapper types for pointers."""
        typeName = value.baseType

        # isPointer will be False for static arrays.
        if value.isPointer or value.isArray:
            count = value.pointerCount

            if self.isStruct(typeName):
                if count > 1:
                    typeName = 'StructPointerDecoder<Decoded_{}*>'.format(typeName)
                else:
                    typeName = 'StructPointerDecoder<Decoded_{}>'.format(typeName)
            elif self.isClass(value):
                typeName = 'HandlePointerDecoder<{}*>'.format(typeName)
            elif typeName == 'wchar_t':
                if count > 1:
                    typeName = 'WStringArrayDecoder'
                else:
                    typeName = 'WStringDecoder'
            elif typeName == 'char':
                if count > 1:
                    typeName = 'StringArrayDecoder'
                else:
                    typeName = 'StringDecoder'
            elif typeName == 'void':
                if value.isArray:
                    # If this was an array (void*) it was encoded as an array of bytes.
                    typeName = 'PointerDecoder<uint8_t>'
                elif count > 1:
                    # If this was a pointer to a pointer to an unknown object (void**), it was encoded as a pointer to a 64-bit address value.
                    # So, we specify uint64_t as the decode type and void* as the type to be used for Vulkan API call output parameters.
                    typeName = 'PointerDecoder<uint64_t, void*>'
                else:
                    # If this was a pointer to an unknown object (void*), it was encoded as a 64-bit address value.
                    typeName = 'uint64_t'
            elif self.isHandle(typeName):
                typeName = 'HandlePointerDecoder<{}>'.format(typeName)
            else:
                if count > 1:
                    typeName = 'PointerDecoder<{}*>'.format(typeName)
                else:
                    typeName = 'PointerDecoder<{}>'.format(typeName)
        elif self.isFunctionPtr(typeName):
            # Function pointers are encoded as a 64-bit address value.
            typeName ='uint64_t'
        elif self.isStruct(typeName):
            typeName = 'Decoded_{}'.format(typeName)
        elif self.isHandle(typeName):
            typeName = 'format::HandleId'
        else:
            typeName = '{}'.format(typeName)

        return typeName

    def makeConsumerFuncDecl(self, returnType, name, values, dx12_method = False):
        """make_consumer_decl - return VulkanConsumer class member function declaration.
        Generate VulkanConsumer class member function declaration.
        """
        paramDecls = []

        if dx12_method:
            paramDecl = self.makeAlignedParamDecl('format::HandleId', 'object_id', self.INDENT_SIZE, self.genOpts.alignFuncParam)
            paramDecls.append(paramDecl)

        if returnType != 'void':
            if dx12_method:
                return_value = self.get_return_value_info('returnValue', returnType)
                rtnType1 = self.makeDecodedParamType(return_value)
                if rtnType1.find('Decoder') != -1:
                    rtnType1 += '*'
                paramDecl = self.makeAlignedParamDecl(rtnType1, 'returnValue', self.INDENT_SIZE, self.genOpts.alignFuncParam)
            else:
                paramDecl = self.makeAlignedParamDecl(returnType, 'returnValue', self.INDENT_SIZE, self.genOpts.alignFuncParam)
            paramDecls.append(paramDecl)

        for value in values:
            paramType = self.makeDecodedParamType(value)

            if 'Decoder' in paramType:
                paramType = '{}*'.format(paramType)

            paramDecl = self.makeAlignedParamDecl(paramType, value.name, self.INDENT_SIZE, self.genOpts.alignFuncParam)
            paramDecls.append(paramDecl)

        if paramDecls:
            return 'void {}(\n{})'.format(name, ',\n'.join(paramDecls))

        return 'void {}()'.format(name)

    def makeStructureTypeEnum(self, typeinfo, typename):
        """Generate the VkStructreType enumeration value for the specified structure type."""
        members = typeinfo.elem.findall('.//member')

        for member in members:
            membername = noneStr(member.find('name').text)

            # We only care about structures with an sType, which can be included in a pNext chain.
            if membername == 'sType':
                # Check for value in the XML element.
                values = member.attrib.get('values')

                if values:
                    return values
                else:
                    # If the value was not specified by the XML element, process the struct type to create it.
                    stype = re.sub('([a-z0-9])([A-Z])', r'\1_\2', typename)
                    stype = stype.replace('D3_D12', 'D3D12')
                    stype = stype.replace('Device_IDProp', 'Device_ID_Prop')
                    stype = stype.upper()
                    return re.sub('VK_', 'VK_STRUCTURE_TYPE_', stype)
        return None

    def makeArrayLengthExpression(self, value, prefix=''):
        """Generate an expression for the length of a given array value."""
        lengthExpr = value.arrayLength
        lengthValue = value.arrayLengthValue

        if lengthValue:
            if lengthValue.isPointer:
                # Add implicit dereference when length expr == pointer name
                if lengthValue.name == lengthExpr:
                    lengthExpr = '*' + lengthExpr
                # Add null check to length value behind pointer
                lengthExpr = '({lengthValue.name} != nullptr) ? ({lengthExpr}) : 0'.format(
                    lengthValue=lengthValue, lengthExpr=lengthExpr)
            elif lengthValue.baseType == 'VkDeviceSize':
                # Static cast 64-bit length expression to eliminate warning in 32-bit builds
                lengthExpr = 'static_cast<size_t>({})'.format(lengthExpr)
            # Add prefix to parameter in the length expression
            lengthExpr = lengthExpr.replace(lengthValue.name, prefix + lengthValue.name)

        return lengthExpr

    def makeArray2DLengthExpression(self, value, values, prefix=''):
        lengthExprs = value.arrayLength.split(',')
        if len(lengthExprs) == value.pointerCount:
            # All dimensions are provided in the xml
            lengths = []
            for lengthExpr in lengthExprs:
                # Prefix members
                for v in values:
                    lengthExpr = re.sub(r'\b({})\b'.format(v.name), r'{}\1'.format(prefix), lengthExpr)
                lengths.append(lengthExpr)
            return lengths
        else:
            # XML does not provide lengths for all dimensions, instantiate a specialization of ArraySize2D to fetch the sizes
            type_list = ', '.join([v.fullType for v in values])
            arg_list = ', '.join([v.name for v in values])
            return ['ArraySize2D<{}>({})'.format(type_list, arg_list)]

    def makeEncoderMethodCall(self, name, value, values, prefix, omitOutputParam=None):
        """Generate a parameter encoder method call invocation."""
        argName = prefix + value.name
        if self.isGenericStructHandleValue(name, value.name) or self.isGenericCmdHandleValue(name, value.name):
            handleTypeName = prefix
            if self.isGenericStructHandleValue(name, value.name):
                handleTypeName += self.getGenericStructHandleTypeValue(name, value.name)
            else:
                handleTypeName += self.getGenericCmdHandleTypeValue(name, value.name)
            argName = 'GetWrappedId({}, {})'.format(argName, handleTypeName)

        args = [argName]

        isStruct = False
        isString = False
        isFuncp = False

        typeName = self.makeInvocationTypeName(value.baseType)

        if self.isStruct(typeName):
            args = ['encoder'] + args
            isStruct = True
            methodCall = 'EncodeStruct'
        else:
            if typeName in ['String', 'WString']:
                isString = True
            elif typeName == 'FunctionPtr':
                isFuncp = True

            methodCall = 'encoder->Encode' + typeName

        if isString:
            if value.isArray and value.isDynamic:
                methodCall += 'Array'
                args.append(self.makeArrayLengthExpression(value, prefix))
        elif value.isArray:
            if value.pointerCount > 1:
                methodCall += 'Array{}D'.format(value.pointerCount)
                args.extend(self.makeArray2DLengthExpression(value, values, prefix))
            elif ',' in value.arrayLength:
                methodCall += '{}DMatrix'.format(value.arrayLength.count(',') + 1)
                args.append(self.makeArrayLengthExpression(value, prefix))
            else:
                methodCall += 'Array'
                args.append(self.makeArrayLengthExpression(value, prefix))
        elif isStruct:
            if value.isPointer:
                methodCall += 'Ptr'
        elif not (isString or isFuncp):
            # Ignore string and function names, which do not use the Ptr/Value suffix
            if value.isPointer:
                methodCall += 'Ptr' * value.pointerCount
            else:
                methodCall += 'Value'

        if self.isOutputParameter(value) and omitOutputParam:
            args.append(omitOutputParam)

        return '{}({})'.format(methodCall, ', '.join(args))

    def __getFeatureProtect(self, interface):
        """Return appropriate feature protect string from 'platform' tag on feature.
        From Vulkan-ValidationLayers common_codegen.py.
        """
        # TODO: This should probably be in a JSON file.
        platform_dict = {
            'android' : 'VK_USE_PLATFORM_ANDROID_KHR',
            'fuchsia' : 'VK_USE_PLATFORM_FUCHSIA',
            'ios' : 'VK_USE_PLATFORM_IOS_MVK',
            'macos' : 'VK_USE_PLATFORM_MACOS_MVK',
            'mir' : 'VK_USE_PLATFORM_MIR_KHR',
            'vi' : 'VK_USE_PLATFORM_VI_NN',
            'wayland' : 'VK_USE_PLATFORM_WAYLAND_KHR',
            'win32' : 'VK_USE_PLATFORM_WIN32_KHR',
            'xcb' : 'VK_USE_PLATFORM_XCB_KHR',
            'xlib' : 'VK_USE_PLATFORM_XLIB_KHR',
            'xlib_xrandr' : 'VK_USE_PLATFORM_XLIB_XRANDR_EXT',
            'ggp' : 'VK_USE_PLATFORM_GGP',
            'directfb' : 'VK_USE_PLATFORM_DIRECTFB_EXT'
        }

        platform = interface.get('platform')
        if platform and platform in platform_dict:
            return platform_dict[platform]
        return None

    def __loadBlacklists(self, filename):
        lists = json.loads(open(filename, 'r').read())
        self.APICALL_BLACKLIST += lists['functions']
        self.STRUCT_BLACKLIST += lists['structures']

    def __loadPlatformTypes(self, filename):
        platforms = json.loads(open(filename, 'r').read())
        for platform_name in platforms:
            platform = platforms[platform_name]
            platform_types = platform['types']

            for type in platform_types:
                self.PLATFORM_TYPES[type] = platform_types[type]

            platform_structs = platform['structs']
            if platform_structs:
                self.PLATFORM_STRUCTS += platform_structs
