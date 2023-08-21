#!/usr/bin/python3 -i
#
# Copyright (c) 2020 Samsung
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

import json
import os
import re
import sys

from base_generator import *
from collections import Counter

'''
class VulkanCppUtilityGeneratorOptions(BaseGeneratorOptions):
    """Options for generating a utility methods for the CPP generator"""
    def __init__(self,
                 is_header_output,
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
'''

# VulkanCppConsumerBodyGenerator - subclass of BaseGenerator.
# Generates C++ member definitions for the VulkanCppConsumer class responsible for
# generating a textfile containing decoded Vulkan API call parameter data.
class VulkanCppUtilityBodyGenerator(BaseGenerator):
    """Generate a C++ class for Vulkan capture file to CPP source generation"""

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            process_cmds=True,
            process_structs=True,
            feature_break=True,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

        # { name: xmlElement, }
        self.enumGroups = dict()
        self.fakeInject = ['VkXcbSurfaceCreateFlagsKHR', 'VkAndroidSurfaceCreateFlagsKHR',]

    def writeout(self, *args, **kwargs):
        write(*args, **kwargs, file=self.outFile)

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)
        self.is_header = genOpts.filename.endswith(".h")

        if self.is_header:
            self.writeout('#include "util/defines.h"')
            self.newline()
            self.writeout('#include <string>')
            self.newline()
            self.writeout('#include "vulkan/vulkan.h"')
        else:
            self.writeout('#include "generated/generated_vulkan_cpp_utility.h"')
            self.newline()
            self.writeout('#include <iostream>')

        self.newline()
        self.writeout('GFXRECON_BEGIN_NAMESPACE(gfxrecon)')
        self.writeout('GFXRECON_BEGIN_NAMESPACE(decode)')
        self.newline()

        for name in self.fakeInject:
            if self.is_header:
                end = ';'
            else:
                end = ' { return "0"; }'

            # TODO: Use the base type of platform-depend surface creation flags (e.g. VkXcbSurfaceCreateFlagsKHR, VkAndroidSurfaceCreateFlagsKHR)
            # to ease the build for Android.
            self.writeout('std::string ToString{name}(VkFlags value){end}'.format(name=name, end=end))

    # Method override
    def endFile(self):
        self.newline()
        self.writeout('GFXRECON_END_NAMESPACE(decode)')
        self.writeout('GFXRECON_END_NAMESPACE(gfxrecon)')

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def checkDuplicates(self, enums):
        valueMap = {}
        nameMap = {}
        stripped = []
        for elem in enums:
            name = elem.get('name')
            (numVal, strVal) = self.enumToValue(elem, True)
            shouldSkip = False

            if elem.get('supported', None) == 'disabled':
                continue

            if name in nameMap:
                # Duplicate name found; check values
                (name2, numVal2, strVal2) = nameMap[name]

                # Duplicate enum values for the same name are benign. This
                # happens when defining the same enum conditionally in
                # several extension blocks.
                if (strVal2 == strVal or (numVal is not None
                                          and numVal == numVal2)):
                    True
                    # self.logMsg('info', 'checkDuplicateEnums: Duplicate enum (' + name +
                    #             ') found with the same value:' + strVal)
                else:
                    self.logMsg('warn', 'checkDuplicateEnums: Duplicate enum (' + name
                                + ') found with different values:' + strVal
                                + ' and ' + strVal2)

                shouldSkip = True
            elif numVal in valueMap:
                # Duplicate value found (such as an alias); report it, and skip
                (name2, numVal2, strVal2) = valueMap[numVal]

                msg = 'Two enums found with the same value: {} = {} = {}'.format(
                    name, name2.get('name'), strVal)
                self.logMsg('error', msg)
                shouldSkip = True
            elif elem.get('alias', None):
                shouldSkip = True

            # Track this enum to detect following duplicates
            nameMap[name] = [elem, numVal, strVal]
            if numVal is not None:
                valueMap[numVal] = [elem, numVal, strVal]

            if not shouldSkip:
                # Add this enum to the list
                stripped.append(elem)

        # TODO: move to a function?
        for alias_elem in enums:
            if alias_elem.get('alias', None):
                for alias in stripped:
                    if alias.get('name') == alias_elem.get('alias'):
                        alias.set('name', alias_elem.get('name'))

        return stripped


    def genGroup(self, groupinfo, groupName, alias):
        """ Process the Enum types and generate a ToString converter method."""
        BaseGenerator.genGroup(self, groupinfo, groupName, alias)

        # If there is an alias skip it, to avoid type re-definition errors
        if alias:
            # There is an alias, skip this
            return

        groupElem = groupinfo.elem

        # Skip the 'VkFullScreenExclusiveEXT' for now as it is a win32 specific enum
        if groupElem.get('name') in ["VkFullScreenExclusiveEXT"]:
            return

        self.enumGroups[groupName] = groupElem

        enums = groupElem.findall('enum')
        # Filter out the duplicated enum values to avoid value collision(s).
        enums = self.checkDuplicates(enums)

        # If there are no enum values, do not generate a method for it.
        if not len(enums):
            return

        # In case of header output, the method prototype is enough.
        if self.is_header:
            self.writeout("std::string ToString{name}({name} value);".format(name=groupName))
            return

        # Generate 'case' statements.
        switch_entries = []
        for elem in enums:
            name = elem.get('name')
            switch_entries.append('        case {name}: return "{name}";'.format(name=name))

        # Add a default case.
        switch_entries.append('        default: break;')

        # Build and print out the implementation.
        self.writeout('std::string ToString{name}({name} value) {{'.format(name=groupName))
        self.writeout('    switch(value) {')
        self.writeout('\n'.join(switch_entries))
        self.writeout('    }')
        self.writeout('    return std::string("({})") + std::to_string((uint32_t)value);'.format(groupName))
        self.writeout('}\n')


    def genType(self, typeinfo, name, alias):
        BaseGenerator.genType(self, typeinfo, name, alias)
        typeElem = typeinfo.elem

        category = typeElem.get('category')
        if category == 'bitmask' and 'SurfaceCreateFlags' not in name:
            targetEnum = typeElem.get('requires')
            enumEntries = self.enumGroups.get(targetEnum, [])
            self.genBitFlags(name, enumEntries)


    def genBitFlags(self, groupName, enums):
        if self.is_header:
            self.writeout('std::string ToString{name}({name} value);'.format(name=groupName))
            return

        # TODO: don't generate the loop if there are no enum values
        flag_entries = []
        for elem in enums:
            name = elem.get('name')
            (numVal, strVal) = self.enumToValue(elem, True)
            # Check if the enum value is power of two
            if numVal is None or (numVal > 0 and ((~numVal + 1) & numVal) != numVal):
                continue

            flag_entries.append('{{ "{name}", {value} }},'.format(name=name, value=numVal))

        method = '''std::string ToString{name}({name} value) {{
    struct flagEntries {{
        std::string name;
        uint32_t value;
    }} entries[] = {{
{entries}
    }};

    std::string output = "";
    std::string orOperator = "";
    for (size_t idx = 0; idx < (sizeof(entries) / sizeof(entries[0])); idx++) {{
        if ((entries[idx].value & (uint32_t)value) != 0) {{
            output += orOperator + entries[idx].name;
            orOperator = " | ";
        }}
    }}
    return output.empty() ? "0" : output;
}}
'''
        self.writeout(method.format(name=groupName, entries='\n'.join(flag_entries)))
