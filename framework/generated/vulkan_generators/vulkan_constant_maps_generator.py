#!/usr/bin/python3 -i

import sys
from base_generator import BaseGenerator, BaseGeneratorOptions, write


class VulkanConstantMapsGeneratorOptions(BaseGeneratorOptions):
    """Adds the following new option:
    is_override - Specify whether the member function declarations are
                  virtual function overrides or pure virtual functions.
    Options for generating C++ class declarations for Vulkan parameter processing.
    """

    def __init__(
        self,
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        extraVulkanHeaders=[]
    ):
        BaseGeneratorOptions.__init__(
            self,
            blacklists,
            platform_types,
            filename,
            directory,
            prefix_text,
            protect_file,
            protect_feature,
            extraVulkanHeaders=extraVulkanHeaders
        )


class VulkanConstantMapsGenerator(BaseGenerator):
    """VulkanColorspaceMapGenerator - subclass of BaseGenerator.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            process_cmds=True,
            process_structs=False,
            feature_break=True,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        self.includeVulkanHeaders(gen_opts)
        self.newline()
        write('#include <unordered_map>', file=self.outFile)
        write('#include <vector>', file=self.outFile)

        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)
        self.newline()

        colorspace_extensions_names = set()
        colorspace_extension_map = dict.fromkeys(
            filter(
                lambda enum_value: 'VK_COLOR_SPACE' in enum_value,
                self.registry.enumdict
            )
        )
        colorspace_extension_map.pop(
            'VK_COLOR_SPACE_SRGB_NONLINEAR_KHR'
        )  # Remove the core provided color space from extension map
        for extension in self.registry.extensions:
            colorspace_enum = filter(
                lambda element: 'VK_COLOR_SPACE' in element.get('name'),
                extension.findall('require/enum')
            )
            colorspace_enum = map(
                lambda element: element.get('name'), colorspace_enum
            )
            for name in colorspace_enum:
                value = extension.get("name")
                colorspace_extensions_names.add(value)
                colorspace_extension_map[name] = f'"{value}"'

        write(
            'static const std::unordered_map<VkColorSpaceKHR, const char *> kColorSpaceExtensionMap = {',
            file=self.outFile
        )
        for key, value in colorspace_extension_map.items():
            write(f'{{{key}, {value}}},', file=self.outFile)
        write('};', file=self.outFile)
        self.newline()

        write(
            'static const std::vector<const char *> kColorSpaceExtensionNames = {',
            file=self.outFile
        )
        for extension_name in sorted(colorspace_extensions_names):
            write(f'"{extension_name}",', file=self.outFile)
        write('};', file=self.outFile)
        self.newline()

    def endFile(self):
        """Method override."""
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)
