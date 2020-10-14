#!/usr/bin/python3 -i
#
# Copyright (c) 2020 LunarG, Inc.
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

class VulkanFeatureUtilBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating C++ code to alter Vulkan device createtion features"""
    def __init__(self,
                 platformTypes = None,      # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
                 filename = None,
                 directory = '.',
                 prefixText = '',
                 protectFile = False,
                 protectFeature = True):
        BaseGeneratorOptions.__init__(self,
                                      platformTypes=platformTypes,
                                      filename=filename,
                                      directory=directory,
                                      prefixText=prefixText,
                                      protectFile=protectFile,
                                      protectFeature=protectFeature)

# VulkanFeatureUtilBodyGenerator - subclass of BaseGenerator.
# Generates C++ functions to alter Vulkan device creation features.
class VulkanFeatureUtilBodyGenerator(BaseGenerator):
    """Generate C++ code to alter Vulkan device creation features"""

    def __init__(self,
                 errFile = sys.stderr,
                 warnFile = sys.stderr,
                 diagFile = sys.stdout):
        BaseGenerator.__init__(self,
                               processCmds=False, processStructs=True, featureBreak=True,
                               errFile=errFile, warnFile=warnFile, diagFile=diagFile)

        self.physicalDeviceFeatures2sTypes = dict()
        # List of 1.0 features
        self.physicalDeviceFeatures = []

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        write('#include "decode/vulkan_feature_util.h"', file=self.outFile)
        self.newline()
        write('#include "util/logging.h"', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(feature_util)', file=self.outFile)

    # Method override
    def endFile(self):
        self.newline()
        write(self.makeFeatureHelper(), file=self.outFile)
        self.newline()
        write('GFXRECON_END_NAMESPACE(feature_util)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    #
    # Method override
    def genStruct(self, typeinfo, typename, alias):
        BaseGenerator.genStruct(self, typeinfo, typename, alias)

        if not alias:
            # Track this struct if it can be present in a pNext chain for features
            parentStructs = typeinfo.elem.get('structextends')
            if parentStructs:
                if "VkPhysicalDeviceFeatures2" in parentStructs:
                    # Build list of all boolean members which are the feature bits
                    members = []
                    for member in self.featureStructMembers[typename]:
                        if member.baseType == "VkBool32":
                            members.append(member.name)
                    self.physicalDeviceFeatures2sTypes[typename] = {
                        'sType' : self.makeStructureTypeEnum(typeinfo, typename),
                        'members' : members
                    }

            #  Get all core 1.0 features
            if typename == "VkPhysicalDeviceFeatures":
                for member in self.featureStructMembers[typename]:
                    self.physicalDeviceFeatures.append(member.name)

    #
    # Indicates that the current feature has C++ code to generate.
    def needFeatureGeneration(self):
        return False

    #
    # Generate help function for features on replaying at device creation time
    def makeFeatureHelper(self):
        result = 'void RemoveUnsupportedFeatures(VkPhysicalDevice physicalDevice, PFN_vkGetPhysicalDeviceFeatures GetPhysicalDeviceFeatures, PFN_vkGetPhysicalDeviceFeatures2 GetPhysicalDeviceFeatures2, const void* pNext, const VkPhysicalDeviceFeatures* pEnabledFeatures)\n'
        result += '{\n'
        result += '    // If the pNext chain includes a VkPhysicalDeviceFeatures2 structure, then pEnabledFeatures must be NULL\n'
        result += '    const VkPhysicalDeviceFeatures* physicalDeviceFeatures = nullptr;\n'
        result += '    if (pEnabledFeatures != nullptr)\n'
        result += '    {\n'
        result += '        physicalDeviceFeatures = pEnabledFeatures;\n'
        result += '    }\n\n'

        result += '    if (GetPhysicalDeviceFeatures2 != nullptr)\n'
        result += '    {\n'
        result += '        VkPhysicalDeviceFeatures2 physicalDeviceFeatures2 = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2, nullptr };\n'
        result += '        const VkDeviceCreateInfo* next = reinterpret_cast<const VkDeviceCreateInfo*>(pNext);\n'
        result += '        while (next != nullptr)\n'
        result += '        {\n'
        result += '            switch (next->sType)\n'
        result += '            {\n'
        result += '            // Special case to set VkPhysicalDeviceFeatures if passed in pNext\n'
        result += '            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:\n'
        result += '                physicalDeviceFeatures = &reinterpret_cast<const VkPhysicalDeviceFeatures2*>(next)->features;\n'
        result += '                break;\n'

        for typename, info in self.physicalDeviceFeatures2sTypes.items():

            result += '            case {}:\n'.format(info['sType'])
            result += '            {\n'
            result += '                const {}* currentNext = reinterpret_cast<const {}*>(next);\n'.format(typename, typename)
            result += '                {} query = {{ {}, nullptr }};\n'.format(typename, info['sType'])
            result += '                physicalDeviceFeatures2.pNext = &query;\n'
            result += '                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);\n'
            for member in info['members']:
                result += '                if ((currentNext->{} == VK_TRUE) && (query.{} == VK_FALSE))\n'.format(member, member)
                result += '                {\n'
                result += '                    GFXRECON_LOG_WARNING("Feature {}, which is not supported by the replay device, will not be enabled");\n'.format(member)
                result += '                    const_cast<{}*>(currentNext)->{} = VK_FALSE;\n'.format(typename, member)
                result += '                }\n'
            result += '                break;\n'
            result += '             }\n'

        result += '             default:\n'
        result += '                break;\n'
        result += '            }\n'
        result += '            next = reinterpret_cast<const VkDeviceCreateInfo*>(next->pNext);\n'
        result += '        }\n'
        result += '    }\n\n'

        result += '    if ((GetPhysicalDeviceFeatures != nullptr) && (physicalDeviceFeatures != nullptr))\n'
        result += '    {\n'
        result += '        VkPhysicalDeviceFeatures query = {};\n'
        result += '        GetPhysicalDeviceFeatures(physicalDevice, &query);\n'
        for feature in self.physicalDeviceFeatures:
            result += '        if ((physicalDeviceFeatures->{} == VK_TRUE) && (query.{} == VK_FALSE))\n'.format(feature, feature)
            result += '        {\n'
            result += '            GFXRECON_LOG_WARNING("Feature {}, which is not supported by the replay device, will not be enabled");\n'.format(feature)
            result += '            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->{} = VK_FALSE;\n'.format(feature)
            result += '        }\n'
        result += '    }\n'
        result += '}'
        return result
