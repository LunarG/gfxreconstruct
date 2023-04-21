#!/usr/bin/python3 -i
#
# Copyright (c) 2023 Valve Corporation
# Copyright (c) 2023 LunarG, Inc.
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


class VulkanCapturePluginsFuncTablePreGeneratorOptions(BaseGeneratorOptions):
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


class VulkanCapturePluginsFuncTablePreGenerator(BaseGenerator):
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

        self.func_argument_decl = dict()

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        write('#ifndef GFXRECON_PLUGINS_CAPTURE_FUNC_TABLE_PRE_H',file=self.outFile)
        write('#define GFXRECON_PLUGINS_CAPTURE_FUNC_TABLE_PRE_H',file=self.outFile)
        self.newline()

        write('#include "format/platform_types.h"', file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        write('#include "util/platform.h"', file=self.outFile)
        self.newline()
        write('#include "vulkan/vk_layer.h"', file=self.outFile)
        self.includeVulkanHeaders(gen_opts)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(plugins)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(capture)', file=self.outFile)
        self.newline()
        write('// clang-format off', file=self.outFile)

    def endFile(self):
        """Method override."""
        self.newline()
        self.generate_func_pointer_decls()
        self.newline()

        self.newline()
        self.generate_no_op_funcs()
        self.newline()

        write('struct plugin_func_table_pre', file=self.outFile)
        write('{', file=self.outFile)
        self.generate_struct_entries()
        write('};', file=self.outFile)
        self.newline()

        write('template <typename FuncP>', file=self.outFile)
        write('static void LoadPreFunction(util::platform::GetProcAddress_t gpa, util::platform::LibraryHandle handle, const char* name, FuncP* funcp)', file=self.outFile)
        write('{', file=self.outFile)
        write('    FuncP result = reinterpret_cast<FuncP>(gpa(handle, name));', file=self.outFile)
        write('    if (result)', file=self.outFile)
        write('    {', file=self.outFile)
        write('        *funcp = result;', file=self.outFile)
        write('    }', file=self.outFile)
        write('}', file=self.outFile)
        self.newline()

        write('static void LoadPreFunctionTable(util::platform::GetProcAddress_t gpa, util::platform::LibraryHandle handle, plugin_func_table_pre *table)', file=self.outFile)
        write('{', file=self.outFile)
        write('    assert(gpa);', file=self.outFile)
        write('    assert(handle);', file=self.outFile)
        write('    assert(table);', file=self.outFile)
        self.newline()
        self.generate_load_function()
        write('}', file=self.outFile)
        self.newline()
        write('// clang-format on', file=self.outFile)
        self.newline()

        write('GFXRECON_END_NAMESPACE(capture)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(plugins)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)
        self.newline()
        write('#endif // GFXRECON_PLUGINS_CAPTURE_FUNC_TABLE_PRE_H', file=self.outFile)
        self.newline()

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def need_feature_generation(self):
        if self.feature_cmd_params:
            return True
        return False

    def generate_feature(self):
        for name in self.get_filtered_cmd_names():
            info = self.feature_cmd_params[name]
            values = info[2]

            self.func_argument_decl[name] = self.get_func_argument_decl(values)

    def get_func_argument_decl(self, values):
        param_decls = []

        for value in values:
            value_name = value.name
            value_type = value.full_type if not value.platform_full_type else value.platform_full_type

            if value.is_array and not value.is_dynamic:
                value_name += '[{}]'.format(value.array_capacity)

            param_decl = value_type + ' ' + value_name
            param_decls.append(param_decl)

        return 'uint64_t block_index, {}'.format(', '.join(param_decls))

    def generate_func_pointer_decls(self):
        for name in self.func_argument_decl:
            decl = 'typedef void (VKAPI_PTR *PFN_{}_PreCall)({});'.format(name[2:], self.func_argument_decl[name])
            write(decl, file=self.outFile)

    def generate_no_op_funcs(self):
        write('GFXRECON_BEGIN_NAMESPACE(noop)', file=self.outFile)

        for name in self.func_argument_decl:
            decl = 'static VKAPI_ATTR void VKAPI_CALL {}_PreCall({}) {}'.format(name[2:], self.func_argument_decl[name], "{ }")
            write(decl, file=self.outFile)

        write('GFXRECON_END_NAMESPACE(noop)', file=self.outFile)

    def generate_struct_entries(self):
        indent = ' ' * self.INDENT_SIZE
        for name in self.func_argument_decl:
            decl = indent + 'PFN_{}_PreCall {}_PreCall {} noop::{}_PreCall {};'.format(name[2:], name[2:], "{", name[2:], "}")
            write(decl, file=self.outFile)

    def generate_load_function(self):
        indent = ' ' * self.INDENT_SIZE
        for name in self.func_argument_decl:
            decl = indent +     'LoadPreFunction(gpa, handle, "{}_PreCall", &table->{}_PreCall);'.format(name[2:], name[2:])
            write(decl, file=self.outFile)
