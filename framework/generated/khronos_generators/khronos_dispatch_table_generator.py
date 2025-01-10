#!/usr/bin/python3 -i
#
# Copyright (c) 2019 Valve Corporation
# Copyright (c) 2019-2024 LunarG, Inc.
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
from khronos_base_generator import write


class KhronosDispatchTableGenerator():
    """KhronosDispatchTableGenerator
    Generates a dispatch table for Khronos API calls.
    """

    def is_instance_command(self, api_data, command, first_value):
        """ Method may be overridden. """
        return True

    def is_device_command(self, api_data, command, first_value):
        """ Method may be overridden. """
        return api_data.has_device

    def write_layer_table_manual_entries(self):
        """ Method must overridden. """
        raise NotImplementedError

    def generateDispatchTable(self, gen_dispatch_key=True):
        api_data = self.get_api_data()

        self.instance_cmd_names = dict(
        )  # Map of API call names to no-op function declarations
        self.device_cmd_names = dict(
        )  # Map of API call names to no-op function declarations

        for name in self.all_cmd_params:
            if self.is_core_create_command(name):
                continue

            info = self.all_cmd_params[name]
            values = info[2]

            if values and values[0]:
                first_param = values[0]
                if self.is_handle(first_param.base_type):
                    return_type = info[0]
                    proto = info[1]

                    if self.is_instance_command(api_data, name, first_param):
                        self.instance_cmd_names[name] = self.make_dispatch_cmd_decl(
                            return_type, proto, values, name
                        )
                    elif self.is_device_command(api_data, name, first_param):
                        self.device_cmd_names[name] = self.make_dispatch_cmd_decl(
                            return_type, proto, values, name
                        )
                    else:
                        # Unknown/unhandled command
                        assert (False)

        self.newline()

        if gen_dispatch_key:
            write(
                'typedef const void* {}DispatchKey;'.format(
                    api_data.api_class_prefix
                ),
                file=self.outFile
            )
            self.newline()

            write(
                '// Retrieve a dispatch key from a dispatchable handle',
                file=self.outFile
            )
            write(
                'static {0}DispatchKey Get{0}DispatchKey(const void* handle)'.
                format(api_data.api_class_prefix),
                file=self.outFile
            )
            write('{', file=self.outFile)
            write(
                '    const {0}DispatchKey* dispatch_key = reinterpret_cast<const {0}DispatchKey*>(handle);'
                .format(api_data.api_class_prefix),
                file=self.outFile
            )
            write('    return (*dispatch_key);', file=self.outFile)
            write('}', file=self.outFile)
            self.newline()

        self.generate_no_op_funcs()
        self.newline()

        write(
            'struct {}LayerTable'.format(api_data.api_class_prefix),
            file=self.outFile
        )
        write('{', file=self.outFile)
        self.write_layer_table_manual_entries()
        write('};', file=self.outFile)

        self.newline()
        self.generate_instance_cmd_table(api_data)
        self.newline()
        if api_data.has_device:
            self.generate_device_cmd_table(api_data)
            self.newline()

        write(
            'template <typename GetProcAddr, typename Handle, typename FuncP>',
            file=self.outFile
        )
        write(
            'static void Load{}Function(GetProcAddr gpa, Handle handle, const char* name, FuncP* funcp)'
            .format(api_data.api_class_prefix),
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
        self.generate_load_instance_table_func(api_data)
        if api_data.has_device:
            self.newline()
            self.generate_load_device_table_func(api_data)
        self.newline()

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.feature_cmd_params:
            return True
        return False

    def generate_instance_cmd_table(self, api_data):
        """Generate instance dispatch table structure."""
        write(
            'struct {}InstanceTable'.format(api_data.api_class_prefix),
            file=self.outFile
        )
        write('{', file=self.outFile)

        for name in self.instance_cmd_names:
            decl = '    PFN_{} {}{{ noop::{} }};'.format(name, name[2:], name)
            write(decl, file=self.outFile)

        write('};', file=self.outFile)

    def generate_device_cmd_table(self, api_data):
        """Generate device dispatch table structure."""
        write(
            'struct {}DeviceTable'.format(api_data.api_class_prefix),
            file=self.outFile
        )
        write('{', file=self.outFile)

        for name in self.device_cmd_names:
            decl = '    PFN_{} {}{{ noop::{} }};'.format(name, name[2:], name)
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

    def generate_load_instance_table_func(self, api_data):
        """Generate function to set the instance table's functions with a getprocaddress routine."""
        write(
            'static void Load{0}InstanceTable(PFN_{1} gpa, {2} instance, {0}InstanceTable* table)'
            .format(
                api_data.api_class_prefix, api_data.get_instance_proc_addr,
                api_data.instance_type
            ),
            file=self.outFile
        )
        write('{', file=self.outFile)
        write('    assert(table != nullptr);', file=self.outFile)
        self.newline()

        for name in self.instance_cmd_names:
            if name == api_data.get_instance_proc_addr:
                trimmed_func = api_data.get_instance_proc_addr
                trimmed_func = trimmed_func.replace(
                    api_data.command_prefix, ""
                )
                write(
                    '    table->{} = gpa;'.format(trimmed_func),
                    file=self.outFile
                )
            else:
                expr = '    Load{}Function(gpa, instance, "{}", &table->{});'.format(
                    api_data.api_class_prefix, name, name[2:]
                )
                write(expr, file=self.outFile)

        write('}', file=self.outFile)

    def generate_load_device_table_func(self, api_data):
        """Generate function to set the device table's functions with a getprocaddress routine."""
        write(
            'static void Load{0}DeviceTable(PFN_{1} gpa, {2} device, {0}DeviceTable* table)'
            .format(
                api_data.api_class_prefix, api_data.get_device_proc_addr,
                api_data.device_type
            ),
            file=self.outFile
        )
        write('{', file=self.outFile)
        write('    assert(table != nullptr);', file=self.outFile)
        self.newline()

        for name in self.device_cmd_names:
            if name == api_data.get_device_proc_addr:
                trimmed_func = api_data.get_device_proc_addr
                trimmed_func = trimmed_func.replace(
                    api_data.command_prefix, ""
                )
                write(
                    '    table->{} = gpa;'.format(trimmed_func),
                    file=self.outFile
                )
            else:
                expr = '    Load{}Function(gpa, device, "{}", &table->{});'.format(
                    api_data.api_class_prefix, name, name[2:]
                )
                write(expr, file=self.outFile)

        write('}', file=self.outFile)

    def make_full_typename(self, value):
        """Generate the full typename for the NoOp function parameters; the array types need the [] moved from the parameter name to the parameter typename."""
        if value.is_array and not value.is_dynamic:
            return '{}[{}]'.format(value.full_type, value.array_capacity)
        else:
            return value.full_type

    def make_dispatch_cmd_decl(self, return_type, proto, values, name):
        """Generate a function prototype for the NoOp functions, with a parameter list that only includes types."""
        params = ', '.join(
            [self.make_full_typename(value) for value in values]
        )
        if return_type == 'void':
            return 'inline {}({}) {{ GFXRECON_LOG_WARNING_ONCE("Unsupported function {} was called, resulting in no-op behavior."); }}'.format(
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
            return 'inline {}({}) {{ GFXRECON_LOG_WARNING_ONCE("Unsupported function {} was called, resulting in no-op behavior."); return {}; }}'.format(
                proto, params, name, return_value
            )
