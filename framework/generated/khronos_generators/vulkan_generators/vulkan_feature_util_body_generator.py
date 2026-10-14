#!/usr/bin/python3 -i
#
# Copyright (c) 2020 LunarG, Inc.
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

import sys
from collections import defaultdict
from vulkan_base_generator import VulkanBaseGenerator, VulkanBaseGeneratorOptions, write


class VulkanFeatureUtilBodyGeneratorOptions(VulkanBaseGeneratorOptions):
    """Options for generating C++ code to alter Vulkan device createtion features."""

    def __init__(
        self,
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        extra_headers=[]
    ):
        VulkanBaseGeneratorOptions.__init__(
            self,
            platform_types=platform_types,
            filename=filename,
            directory=directory,
            prefix_text=prefix_text,
            protect_file=protect_file,
            protect_feature=protect_feature,
            extra_headers=extra_headers
        )

        self.begin_end_file_data.specific_headers.extend((
            'graphics/vulkan_feature_util.h',
            'graphics/vulkan_struct_get_pnext.h',
            '',
            'util/logging.h',
            '',
            'format/platform_types.h',
        ))
        self.begin_end_file_data.namespaces.extend((
            'gfxrecon',
            'graphics',
            'feature_util',
        ))
        self.begin_end_file_data.common_api_headers = []

class VulkanFeatureUtilBodyGenerator(VulkanBaseGenerator):
    """VulkanFeatureUtilBodyGenerator - subclass of VulkanBaseGenerator.
    Generates C++ functions to alter Vulkan device creation features.
    Generate C++ code to alter Vulkan device creation features.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        VulkanBaseGenerator.__init__(
            self,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

        self.physical_device_features2_stypes = dict()
        # List of 1.0 features
        self.physical_device_features = []
        self.feature_struct_stypes = dict()
        self.struct_aliases = dict()
        self.extension_required_types = defaultdict(set)
        self.core_required_types = set()

    def beginFeature(self, interface, emit):
        """Method override. Start processing in superclass."""
        VulkanBaseGenerator.beginFeature(self, interface, emit)
        is_extension = (interface.tag == 'extension')
        for req in interface.findall('require'):
            for t in req.findall('type'):
                tname = t.get('name')
                if is_extension:
                    self.extension_required_types[self.featureName].add(tname)
                else:
                    self.core_required_types.add(tname)

    def endFile(self):
        """Method override."""
        self.newline()
        write(self.make_feature_helper(), file=self.outFile)
        self.newline()

        # Finish processing in superclass
        VulkanBaseGenerator.endFile(self)

    def genStruct(self, typeinfo, typename, alias):
        """Method override."""
        VulkanBaseGenerator.genStruct(self, typeinfo, typename, alias)

        if alias:
            self.struct_aliases[typename] = alias
        else:
            # Track this struct if it can be present in a pNext chain for features
            parent_structs = typeinfo.elem.get('structextends')
            if parent_structs:
                if "VkPhysicalDeviceFeatures2" in parent_structs:
                    stype = self.make_structure_type_enum(typeinfo, typename)
                    self.feature_struct_stypes[typename] = stype

                    # Build list of all boolean members which are the feature bits
                    members = []
                    for member in self.feature_struct_members[typename]:
                        if member.base_type == "VkBool32":
                            members.append(member.name)
                    self.physical_device_features2_stypes[typename] = {
                        'sType': stype,
                        'members': members,
                    }

            #  Get all core 1.0 features
            if typename == "VkPhysicalDeviceFeatures":
                for member in self.feature_struct_members[typename]:
                    self.physical_device_features.append(member.name)

    def genType(self, typeinfo, typename, alias):
        """Method override."""
        VulkanBaseGenerator.genType(self, typeinfo, typename, alias)
        if alias:
            self.struct_aliases[typename] = alias

    def get_stype_extension_mappings(self):
        """Returns list of (sType, structName, [extensionNames]) for feature structures."""
        # Resolve all aliases for feature structs
        full_stype_map = dict(self.feature_struct_stypes)
        for name, alias in self.struct_aliases.items():
            target = alias
            while target in self.struct_aliases:
                target = self.struct_aliases[target]
            if target in self.feature_struct_stypes:
                full_stype_map[name] = self.feature_struct_stypes[target]

        # Identify sTypes belonging to core Vulkan versions
        core_stypes = set()
        for tname in self.core_required_types:
            if tname in full_stype_map:
                core_stypes.add(full_stype_map[tname])

        # Map sType -> set of extension names (excluding core structs)
        stype_to_extensions = defaultdict(set)
        for ext_name, types in self.extension_required_types.items():
            for tname in types:
                if tname in full_stype_map:
                    stype = full_stype_map[tname]
                    if stype not in core_stypes:
                        stype_to_extensions[stype].add(ext_name)

        mappings = []
        for typename, info in self.physical_device_features2_stypes.items():
            stype = info['sType']
            if stype in stype_to_extensions:
                exts = sorted(stype_to_extensions[stype])
                mappings.append((stype, typename, exts))
        return mappings

    def make_feature_helper(self):
        """Generate help function for features on replaying at device creation time."""
        result = 'void CheckUnsupportedFeatures(VkPhysicalDevice physicalDevice,\n'
        result += '                             PFN_vkGetPhysicalDeviceFeatures  GetPhysicalDeviceFeatures,\n'
        result += '                             PFN_vkGetPhysicalDeviceFeatures2 GetPhysicalDeviceFeatures2,\n'
        result += '                             const void*                      pNext,\n'
        result += '                             const VkPhysicalDeviceFeatures*  pEnabledFeatures,\n'
        result += '                             bool                             remove_unsupported)\n'
        result += '{\n'
        result += '    // If the pNext chain includes a VkPhysicalDeviceFeatures2 structure, then pEnabledFeatures must be NULL\n'
        result += '    const VkPhysicalDeviceFeatures* physicalDeviceFeatures = nullptr;\n'
        result += '    if (pEnabledFeatures != nullptr)\n'
        result += '    {\n'
        result += '        physicalDeviceFeatures = pEnabledFeatures;\n'
        result += '    }\n\n'

        result += '    bool found_unsupported = false;\n'
        result += '    const char* warn_message =\n'
        result += '        remove_unsupported ? "requested at capture is not supported by the replay device and it will not be enabled."\n'
        result += '                           : "requested at capture is not supported by the replay device.";\n\n'

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

        for typename, info in self.physical_device_features2_stypes.items():

            result += '            case {}:\n'.format(info['sType'])
            result += '            {\n'
            result += '                const {}* currentNext = reinterpret_cast<const {}*>(next);\n'.format(
                typename, typename
            )
            result += '                {} query = {{ {}, nullptr }};\n'.format(
                typename, info['sType']
            )
            result += '                physicalDeviceFeatures2.pNext = &query;\n'
            result += '                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);\n'
            for member in info['members']:
                result += '                if ((currentNext->{} == VK_TRUE) && (query.{} == VK_FALSE))\n'.format(
                    member, member
                )
                result += '                {\n'
                result += '                    GFXRECON_LOG_WARNING("Feature {} %s", warn_message);\n'.format(
                    member
                )
                result += '                    found_unsupported = true;\n'
                result += '                    const_cast<{}*>(currentNext)->{} =\n'.format(
                    typename, member
                )
                result += '                        remove_unsupported ? VK_FALSE : VK_TRUE;\n'
                result += '                }\n'
            result += '                break;\n'
            result += '            }\n'

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
        for feature in self.physical_device_features:
            result += '        if ((physicalDeviceFeatures->{} == VK_TRUE) && (query.{} == VK_FALSE))\n'.format(
                feature, feature
            )
            result += '        {\n'
            result += '            GFXRECON_LOG_WARNING("Feature {} %s", warn_message);\n'.format(
                feature
            )
            result += '            found_unsupported = true;\n'
            result += '            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->{} =\n'.format(
                feature
            )
            result += '                remove_unsupported ? VK_FALSE : VK_TRUE;\n'
            result += '        }\n'
        result += '    }\n\n'

        result += '    if (!remove_unsupported && found_unsupported)\n'
        result += '    {\n'
        result += '        GFXRECON_LOG_WARNING("Unsupported features were requested. This might cause vkCreateDevice to fail. Try \\"--remove-unsupported\\" option to remove those features at replay.");\n'
        result += '    }\n'
        result += '}\n\n'

        result += 'struct FeatureExtensionMapping {\n'
        result += '    VkStructureType          sType;\n'
        result += '    std::vector<const char*> extensionNames;\n'
        result += '    const char*              structName;\n'
        result += '};\n\n'

        result += 'static const FeatureExtensionMapping kFeatureExtensionMappings[] = {\n'
        mappings = self.get_stype_extension_mappings()
        for stype, sname, exts in mappings:
            ext_list_str = ', '.join('"{}"'.format(ext) for ext in exts)
            result += '    {{ {}, {{ {} }}, "{}" }},\n'.format(stype, ext_list_str, sname)
        result += '};\n\n'

        result += 'void FilterPNextFeatures(VkDeviceCreateInfo* createInfo,\n'
        result += '                         const std::vector<const char*>& enabled_extensions)\n'
        result += '{\n'
        result += '    if (createInfo == nullptr) return;\n\n'
        result += '    for (const auto& mapping : kFeatureExtensionMappings)\n'
        result += '    {\n'
        result += '        bool is_supported = false;\n'
        result += '        for (const char* ext_name : mapping.extensionNames)\n'
        result += '        {\n'
        result += '            if (IsSupportedExtension(enabled_extensions, ext_name))\n'
        result += '            {\n'
        result += '                is_supported = true;\n'
        result += '                break;\n'
        result += '            }\n'
        result += '        }\n'
        result += '        if (!is_supported)\n'
        result += '        {\n'
        result += '            if (vulkan_struct_remove_pnext_by_stype(createInfo, mapping.sType) != nullptr)\n'
        result += '            {\n'
        result += '                GFXRECON_LOG_INFO("Removed %s from pNext because none of its required extensions are enabled.", mapping.structName);\n'
        result += '            }\n'
        result += '        }\n'
        result += '    }\n'
        result += '}'
        return result
