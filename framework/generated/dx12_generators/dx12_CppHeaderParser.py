#!/usr/bin/env python3
#
# Copyright (c) 2021 LunarG, Inc.
# Copyright (c) 2023 Qualcomm Technologies, Inc. and/or its subsidiaries.
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

from CppHeaderParser import CppHeader, CppHeaderParser

SAL_TOKENS = [
    '__in_ecount', '__in_ecount_opt', '__RPC__deref_out',
    '__RPC__deref_out_opt', '__RPC__in', '_Always_', '_COM_Outptr_',
    '_COM_Outptr_opt_', '_COM_Outptr_opt_result_maybenull_',
    '_Field_size_bytes_full_', '_Field_size_bytes_full_opt_',
    '_Field_size_full_', '_Field_size_full_opt_', '_Field_z_', '_In_',
    '_In_opt_', '_In_range_', '_In_reads_', '_In_reads_bytes_',
    '_In_reads_bytes_opt_', '_In_reads_opt_', '_In_z_', '_Inout_',
    '_Inout_opt_', '_Inout_updates_bytes_', '_Out_', '_Out_opt_',
    '_Out_writes_', '_Out_writes_all_', '_Out_writes_all_opt_',
    '_Out_writes_bytes_', '_Out_writes_bytes_opt_', '_Out_writes_bytes_to_',
    '_Out_writes_opt_', '_Out_writes_to_opt_',
    '_Outptr_opt_result_bytebuffer_', '_Field_size_', '_In_opt_count_',
    '_In_count_'
]

original_warning_print = CppHeaderParser.warning_print


def dx12_warning_print(fmt, *args):
    """Override CppHeaderParser.warning_print."""
    # Silence warnings for unresolved SAL tokens.
    if (not fmt.startswith('WARN unresolved')) or (args[0] not in SAL_TOKENS):
        original_warning_print(fmt, *args)


CppHeaderParser.warning_print = dx12_warning_print

original_is_method_namestack = CppHeaderParser.is_method_namestack
original_is_property_namestack = CppHeaderParser.is_property_namestack


def dx12_is_method_namestack(stack):
    """Function override."""
    r = original_is_method_namestack(stack)
    # Additional check for D3D12 headers.
    if r:
        index = stack.index("(")
        # 0: return type, 1: function name
        # if "(" index is less than 2, this is a property, not a method
        if index < 2:
            r = False
    return r


def dx12_is_property_namestack(name_stack):
    """Function override."""
    r = original_is_property_namestack(name_stack)
    if not r:
        if "(" in name_stack and ")" in name_stack:
            index = name_stack.index("(")
            # if "(" index is less than 2, this is a property, not a method
            if index < 2:
                r = True
    return r

CppHeaderParser.is_method_namestack = dx12_is_method_namestack
CppHeaderParser.is_property_namestack = dx12_is_property_namestack

original_evaluate_class_stack = CppHeader._evaluate_class_stack
original_finalize = CppHeader.finalize


def dx12_evaluate_class_stack(self):
    # Initialize base class' anon union counter on first use.
    if self.anon_union_counter < self.anon_union_count:
        self.anon_union_counter = self.anon_union_count
    original_evaluate_class_stack(self)

def dx12_finalize(self):
    # Before post-parsing cleanup, store anon union counter for initializing other Dx12CppHeader objects.
    self.anon_union_count = self.anon_union_counter
    original_finalize(self)

CppHeader._evaluate_class_stack = dx12_evaluate_class_stack
CppHeader.finalize = dx12_finalize

class Dx12CppClass():
    """This struct is simliar to CppHeaderParser.CppClass. In order to add data into CppHeader manually."""

    def __init__(self):
        self.classes = {}
        self.functions = []
        self.enums = []


class Dx12CppHeader(CppHeader):

    def __init__(self, header_file_name, anon_union_count=0, encoding=None, **kwargs):
        """Method override.
           Custom CppHeader implementation to modify the content of the
           header file to remove D3D12 specific syntax before parsing
           with the CppHeader base class.
        """
        self.anon_union_count = anon_union_count
        source = ''
        with open(header_file_name, 'r') as fd:
            source = self.preprocess_file(fd.readlines())
        CppHeader.__init__(self, source, "string", encoding, **kwargs)

    def preprocess_file(self, lines):
        """Preprocess header file to remove MIDL macros and CINTERACE declarations."""
        source = ''
        interface_scope = 0
        ignore_lines = False
        enum_scope = False
        retval_param = False

        for line in lines:

            if 'DEFINE_ENUM_FLAG_OPERATORS(' in line:
                continue
            
            if interface_scope == 0:
                source += line
                enum_scope = line.startswith('typedef enum ')
                if (line.startswith('#if') and ('!defined(CINTERFACE)' in line)) or enum_scope:
                    interface_scope = 1
            else:
                if enum_scope:
                    if line.find(', *') != -1:
                        interface_scope = 0
                        ignore_lines = False
                else:
                    if line.startswith('#if'):
                        interface_scope += 1
                        
                        if 'defined(_MSC_VER) || !defined(_WIN32)' in line:
                            retval_param = True

                    elif line.startswith('#else'):
                        if interface_scope == 1:
                            ignore_lines = True

                        if retval_param is True:
                            ignore_lines = True

                    elif line.startswith('#endif'):
                        interface_scope -= 1

                        if retval_param == True:
                            ignore_lines = False

                        retval_param = False

                        if interface_scope == 0:
                            ignore_lines = False

                if not ignore_lines:
                    new_line = line
                    if enum_scope:
                        new_line = new_line.replace('#if', '//#if')
                        new_line = new_line.replace('#endif', '//#endif')

                        if new_line.find(', *') != -1:
                            new_line = new_line.replace(', *', ';//, *')
                            enum_scope = False
                    else:
                        # INTERFACE macros only appear within the !CINTERFACE
                        # scope.
                        new_line = new_line.replace(
                            'MIDL_INTERFACE', 'class //MIDL_INTERFACE'
                        )
                        new_line = new_line.replace(
                            'BEGIN_INTERFACE', '//BEGIN_INTERFACE'
                        )
                        new_line = new_line.replace(
                            'END_INTERFACE', '//END_INTERFACE'
                        )
                    source += new_line
        return source
