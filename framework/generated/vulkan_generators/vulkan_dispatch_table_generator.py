#!/usr/bin/python3 -i
#
# Copyright (c) 2019 Valve Corporation
# Copyright (c) 2019 LunarG, Inc.
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
from base_generator import BaseGenerator, BaseGeneratorOptions, write


class VulkanDispatchTableGeneratorOptions(BaseGeneratorOptions):
    """Options for generating a dispatch table for Vulkan API calls."""

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


class VulkanDispatchTableGenerator(BaseGenerator):
    """VulkanDispatchTableGenerator - subclass of BaseGenerator.
    Generates a dispatch table for Vulkan API calls.
    Generate dispatch table for Vulkan API calls.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            process_cmds=True,
            process_structs=False,
            feature_break=False,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )
        # Map of return types to default return values for no-op functions
        self.RETURN_DEFAULTS = {
            'VkResult': 'VK_SUCCESS',
            'VkBool32': 'VK_TRUE',
            'PFN_vkVoidFunction': 'nullptr',
            'VkDeviceAddress': '0',
            'VkDeviceSize': '0',
            'uint32_t': '0',
            'uint64_t': '0'
        }

        self.instance_cmd_names = dict(
        )  # Map of API call names to no-op function declarations
        self.device_cmd_names = dict(
        )  # Map of API call names to no-op function declarations

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        write('#include "format/platform_types.h"', file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        write('#include "util/logging.h"', file=self.outFile)
        self.newline()
        write('#include "vulkan/vk_layer.h"', file=self.outFile)
        self.includeVulkanHeaders(gen_opts)
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

    def endFile(self):
        """Method override."""
        self.newline()

        write('typedef const void* VulkanDispatchKey;', file=self.outFile)
        self.newline()

        write(
            '// Retrieve a dispatch key from a dispatchable handle',
            file=self.outFile
        )
        write(
            'static VulkanDispatchKey GetVulkanDispatchKey(const void* handle)',
            file=self.outFile
        )
        write('{', file=self.outFile)
        write(
            '    const VulkanDispatchKey* dispatch_key = reinterpret_cast<const VulkanDispatchKey*>(handle);',
            file=self.outFile
        )
        write('    return (*dispatch_key);', file=self.outFile)
        write('}', file=self.outFile)

        self.newline()
        self.generate_no_op_funcs()
        self.newline()

        write('struct VulkanLayerTable', file=self.outFile)
        write('{', file=self.outFile)
        write(
            '    PFN_vkCreateInstance CreateInstance{ nullptr };',
            file=self.outFile
        )
        write(
            '    PFN_vkCreateDevice CreateDevice{ nullptr };',
            file=self.outFile
        )
        write('};', file=self.outFile)

        self.newline()
        self.generate_instance_cmd_table()
        self.newline()
        self.generate_device_cmd_table()
        self.newline()

        write(
            'template <typename GetProcAddr, typename Handle, typename FuncP>',
            file=self.outFile
        )
        write(
            'static void LoadVulkanFunction(GetProcAddr gpa, Handle handle, const char* name, FuncP* funcp)',
            file=self.outFile
        )
        write('{', file=self.outFile)
        write(
            '    FuncP result = reinterpret_cast<FuncP>(gpa(handle, name));',
            file=self.outFile
        )
        write('    if (result != nullptr)', file=self.outFile)
        write('    {', file=self.outFile)
        write('        (*funcp) = result;', file=self.outFile)
        write('    }', file=self.outFile)
        write('}', file=self.outFile)

        self.newline()
        self.generate_load_instance_table_func()
        self.newline()
        self.generate_load_device_table_func()
        self.newline()

        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.feature_cmd_params:
            return True
        return False

    def generate_feature(self):
        """Performs C++ code generation for the feature."""
        for name in self.feature_cmd_params:
            # Ignore vkCreateInstance and vkCreateDevice, which are provided by the layer due to special handling requirements
            if name not in ['vkCreateInstance', 'vkCreateDevice']:
                info = self.feature_cmd_params[name]
                values = info[2]

                if values and values[0]:
                    first_param = values[0]
                    if self.is_handle(first_param.base_type):
                        return_type = info[0]
                        proto = info[1]

                        # vkSetDebugUtilsObjectNameEXT and vkSetDebugUtilsObjectTagEXT
                        # need to be probed from GetInstanceProcAddress due to a loader issue.
                        # https://github.com/KhronosGroup/Vulkan-Loader/issues/1109
                        # TODO : When loader with fix for issue is widely available, remove this
                        # special case.
                        if name in ['vkSetDebugUtilsObjectNameEXT', 'vkSetDebugUtilsObjectTagEXT']:
                            self.instance_cmd_names[name] = self.make_cmd_decl(return_type, proto, values, name)
                        elif first_param.base_type not in ['VkInstance', 'VkPhysicalDevice']:
                            self.device_cmd_names[name] = self.make_cmd_decl(return_type, proto, values, name)
                        else:
                            self.instance_cmd_names[name] = self.make_cmd_decl(return_type, proto, values, name)

    def generate_instance_cmd_table(self):
        """Generate instance dispatch table structure."""
        write('struct VulkanInstanceTable', file=self.outFile)
        write('{', file=self.outFile)

        for name in self.instance_cmd_names:
            decl = '    PFN_{} {}{{ noop::{} }};'.format(
                name, name[2:], name[2:]
            )
            write(decl, file=self.outFile)

        write('};', file=self.outFile)

    def generate_device_cmd_table(self):
        """Generate device dispatch table structure."""
        write('struct VulkanDeviceTable', file=self.outFile)
        write('{', file=self.outFile)

        for name in self.device_cmd_names:
            decl = '    PFN_{} {}{{ noop::{} }};'.format(
                name, name[2:], name[2:]
            )
            write(decl, file=self.outFile)

        write('};', file=self.outFile)

    def generate_no_op_funcs(self):
        """Generate no-op function definitions."""
        write('GFXRECON_BEGIN_NAMESPACE(noop)', file=self.outFile)
        write('// clang-format off', file=self.outFile)

        for name in self.instance_cmd_names:
            write(self.instance_cmd_names[name], file=self.outFile)

        for name in self.device_cmd_names:
            write(self.device_cmd_names[name], file=self.outFile)

        write('// clang-format on', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(noop)', file=self.outFile)

    def generate_load_instance_table_func(self):
        """Generate function to set the instance table's functions with a getprocaddress routine."""
        write(
            'static void LoadVulkanInstanceTable(PFN_vkGetInstanceProcAddr gpa, VkInstance instance, VulkanInstanceTable* table)',
            file=self.outFile
        )
        write('{', file=self.outFile)
        write('    assert(table != nullptr);', file=self.outFile)
        self.newline()

        for name in self.instance_cmd_names:
            if name == 'vkGetInstanceProcAddr':
                write(
                    '    table->GetInstanceProcAddr = gpa;', file=self.outFile
                )
            else:
                expr = '    LoadVulkanFunction(gpa, instance, "{}", &table->{});'.format(
                    name, name[2:]
                )
                write(expr, file=self.outFile)

        write('}', file=self.outFile)

    def generate_load_device_table_func(self):
        """Generate function to set the device table's functions with a getprocaddress routine."""
        write(
            'static void LoadVulkanDeviceTable(PFN_vkGetDeviceProcAddr gpa, VkDevice device, VulkanDeviceTable* table)',
            file=self.outFile
        )
        write('{', file=self.outFile)
        write('    assert(table != nullptr);', file=self.outFile)
        self.newline()

        for name in self.device_cmd_names:
            if name == 'vkGetDeviceProcAddr':
                write('    table->GetDeviceProcAddr = gpa;', file=self.outFile)
            else:
                expr = '    LoadVulkanFunction(gpa, device, "{}", &table->{});'.format(
                    name, name[2:]
                )
                write(expr, file=self.outFile)

        write('}', file=self.outFile)

    def make_full_typename(self, value):
        """Generate the full typename for the NoOp function parameters; the array types need the [] moved from the parameter name to the parameter typename."""
        if value.is_array and not value.is_dynamic:
            return '{}[{}]'.format(value.full_type, value.array_capacity)
        else:
            return value.full_type

    def make_cmd_decl(self, return_type, proto, values, name):
        """Generate a function prototype for the NoOp functions, with a parameter list that only includes types."""
        params = ', '.join(
            [self.make_full_typename(value) for value in values]
        )
        if return_type == 'void':
            return 'static {}({}) {{ GFXRECON_LOG_WARNING_ONCE("Unsupported function {} was called, resulting in no-op behavior."); }}'.format(
                proto, params, name
            )
        else:
            return_value = ''
            if return_type in self.RETURN_DEFAULTS:
                return_value = self.RETURN_DEFAULTS[return_type]
            else:
                print(
                    'Unrecognized return type {} for no-op function generation; returning a zero initialized value'
                    .format(return_type)
                )
                return_value = '{}{{}}'.format(return_type)
            return 'static {}({}) {{ GFXRECON_LOG_WARNING_ONCE("Unsupported function {} was called, resulting in no-op behavior."); return {}; }}'.format(
                proto, params, name, return_value
            )
