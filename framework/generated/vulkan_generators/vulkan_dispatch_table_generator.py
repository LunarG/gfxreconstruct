#!/usr/bin/python3 -i
#
# Copyright (c) 2019 Valve Corporation
# Copyright (c) 2019 LunarG, Inc.
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

class VulkanDispatchTableGeneratorOptions(BaseGeneratorOptions):
    """Options for generating a dispatch table for Vulkan API calls"""
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

# VulkanDispatchTableGenerator - subclass of BaseGenerator.
# Generates a dispatch table for Vulkan API calls.
class VulkanDispatchTableGenerator(BaseGenerator):
    """Generate dispatch table for Vulkan API calls"""
    def __init__(self,
                 errFile = sys.stderr,
                 warnFile = sys.stderr,
                 diagFile = sys.stdout):
        BaseGenerator.__init__(self,
                               processCmds=True, processStructs=False, featureBreak=False,
                               errFile=errFile, warnFile=warnFile, diagFile=diagFile)
        # Map of return types to default return values for no-op functions
        self.RETURN_DEFAULTS = { 'VkResult' : 'VK_SUCCESS',
                                 'VkBool32' : 'VK_TRUE',
                                 'PFN_vkVoidFunction' : 'nullptr',
                                 'VkDeviceAddress' : '0',
                                 'uint32_t' : '0',
                                 'uint64_t' : '0' }

        self.instanceCmdNames = dict()      # Map of API call names to no-op function declarations
        self.deviceCmdNames = dict()        # Map of API call names to no-op function declarations

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        write('#include "format/platform_types.h"', file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        write('#include "vulkan/vk_layer.h"', file=self.outFile)
        write('#include "vulkan/vulkan.h"', file=self.outFile)
        self.newline()
        write('#ifdef WIN32', file=self.outFile)
        write('#ifdef CreateEvent', file=self.outFile)
        write('#undef CreateEvent', file=self.outFile)
        write('#endif', file=self.outFile)
        write('#ifdef CreateSemaphore', file=self.outFile)
        write('#undef CreateSemaphore', file=self.outFile)
        write('#endif', file=self.outFile)
        write('#endif', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)

    # Method override
    def endFile(self):
        self.newline()

        write('typedef const void* DispatchKey;', file=self.outFile)
        self.newline()

        write('// Retrieve a dispatch key from a dispatchable handle', file=self.outFile)
        write('static DispatchKey GetDispatchKey(const void* handle)', file=self.outFile)
        write('{', file=self.outFile)
        write('    const DispatchKey* dispatch_key = reinterpret_cast<const DispatchKey*>(handle);', file=self.outFile)
        write('    return (*dispatch_key);', file=self.outFile)
        write('}', file=self.outFile)

        self.newline()
        self.generateNoOpFuncs()
        self.newline()

        write('struct LayerTable', file=self.outFile)
        write('{', file=self.outFile)
        write('    PFN_vkCreateInstance CreateInstance{ nullptr };', file=self.outFile)
        write('    PFN_vkCreateDevice CreateDevice{ nullptr };', file=self.outFile)
        write('};', file=self.outFile)

        self.newline()
        self.generateInstanceCmdTable()
        self.newline()
        self.generateDeviceCmdTable()
        self.newline()

        write('template <typename GetProcAddr, typename Handle, typename FuncP>', file=self.outFile)
        write('static void LoadFunction(GetProcAddr gpa, Handle handle, const char* name, FuncP* funcp)', file=self.outFile)
        write('{', file=self.outFile)
        write('    FuncP result = reinterpret_cast<FuncP>(gpa(handle, name));', file=self.outFile)
        write('    if (result != nullptr)', file=self.outFile)
        write('    {', file=self.outFile)
        write('        (*funcp) = result;', file=self.outFile)
        write('    }', file=self.outFile)
        write('}', file=self.outFile)

        self.newline()
        self.generateLoadInstanceTableFunc()
        self.newline()
        self.generateLoadDeviceTableFunc()
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
        for name in self.featureCmdParams:
            # Ignore vkCreateInstance and vkCreateDevice, which are provided by the layer due to special handling requirements
            if name not in ['vkCreateInstance', 'vkCreateDevice']:
                info = self.featureCmdParams[name]
                values = info[2]

                if values and values[0]:
                    firstParam = values[0]
                    if self.isHandle(firstParam.baseType):
                        returnType = info[0]
                        proto = info[1]

                        if not firstParam.baseType in ['VkInstance', 'VkPhysicalDevice']:
                            self.deviceCmdNames[name] = self.makeCmdDecl(returnType, proto, values)
                        else:
                            self.instanceCmdNames[name] = self.makeCmdDecl(returnType, proto, values)

    #
    # Generate instance dispatch table structure
    def generateInstanceCmdTable(self):
        write('struct InstanceTable', file=self.outFile)
        write('{', file=self.outFile)

        for name in self.instanceCmdNames:
            decl = '    PFN_{} {}{{ noop::{} }};'.format(name, name[2:], name[2:])
            write(decl, file=self.outFile)

        write('};', file=self.outFile)

    #
    # Generate device dispatch table structure
    def generateDeviceCmdTable(self):
        write('struct DeviceTable', file=self.outFile)
        write('{', file=self.outFile)

        for name in self.deviceCmdNames:
            decl = '    PFN_{} {}{{ noop::{} }};'.format(name, name[2:], name[2:])
            write(decl, file=self.outFile)

        write('};', file=self.outFile)

    #
    # Generate no-op function definitions
    def generateNoOpFuncs(self):
        write('GFXRECON_BEGIN_NAMESPACE(noop)', file=self.outFile)
        write('// clang-format off', file=self.outFile)

        for name in self.instanceCmdNames:
            write(self.instanceCmdNames[name], file=self.outFile)

        for name in self.deviceCmdNames:
            write(self.deviceCmdNames[name], file=self.outFile)

        write('// clang-format on', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(noop)', file=self.outFile)

    #
    # Generate function to set the instance table's functions with a getprocaddress routine
    def generateLoadInstanceTableFunc(self):
        write('static void LoadInstanceTable(PFN_vkGetInstanceProcAddr gpa, VkInstance instance, InstanceTable* table)', file=self.outFile)
        write('{', file=self.outFile)
        write('    assert(table != nullptr);', file=self.outFile)
        self.newline()

        for name in self.instanceCmdNames:
            if name == 'vkGetInstanceProcAddr':
                write('    table->GetInstanceProcAddr = gpa;', file=self.outFile)
            else:
                expr = '    LoadFunction(gpa, instance, "{}", &table->{});'.format(name, name[2:])
                write(expr, file=self.outFile)

        write('}', file=self.outFile)

    #
    # Generate function to set the device table's functions with a getprocaddress routine
    def generateLoadDeviceTableFunc(self):
        write('static void LoadDeviceTable(PFN_vkGetDeviceProcAddr gpa, VkDevice device, DeviceTable* table)', file=self.outFile)
        write('{', file=self.outFile)
        write('    assert(table != nullptr);', file=self.outFile)
        self.newline()

        for name in self.deviceCmdNames:
            if name == 'vkGetDeviceProcAddr':
                write('    table->GetDeviceProcAddr = gpa;', file=self.outFile)
            else:
                expr = '    LoadFunction(gpa, device, "{}", &table->{});'.format(name, name[2:])
                write(expr, file=self.outFile)

        write('}', file=self.outFile)


    #
    # Generate the full typename for the NoOp function parameters; the array types need the [] moved from the parameter name to the parameter typename
    def makeFullTypename(self, value):
        if value.isArray and not value.isDynamic:
            return '{}[{}]'.format(value.fullType, value.arrayCapacity)
        else:
            return value.fullType

    #
    # Generate a function prototype for the NoOp functions, with a parameter list that only includes types
    def makeCmdDecl(self, returnType, proto, values):
        params = ', '.join([self.makeFullTypename(value) for value in values])
        if returnType == 'void':
            return 'static {}({}) {{}}'.format(proto, params)
        else:
            returnValue = ''
            if returnType in self.RETURN_DEFAULTS:
                returnValue = self.RETURN_DEFAULTS[returnType]
            else:
                print('Unrecognized return type {} for no-op function generation; returning a zero initialized value'.format(returnType))
                returnValue = '{}{{}}'.format(returnType)
            return 'static {}({}) {{ return {}; }}'.format(proto, params, returnValue)
