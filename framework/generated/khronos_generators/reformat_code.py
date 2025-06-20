#!/usr/bin/python3 -i
#
# Copyright (c) 2023 Valve Corporation
# Copyright (c) 2024 LunarG, Inc.
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

## @file Helpers used to clean up generated C++ code, allowing generators to be
## a little rougher in their indentation and then fix the result in post.
## For example they could use triple quote multiline string literals to
## encompass snippets of C++ and keep the C++ indented appropriately for the
## surrounding Python code for human readability rather than indented to the
## level appropriate for the final C++ output.

CPP_DEFAULT_INDENT = '    '

## Sort out the indentation of a generated chunk of C++ code that puts braces on
## their own lines. Strips wholy-whitespace lines and trailing white.
## @note It relies on the C++ code having braces on their own lines or else it
## might all go wrong.
def indent_cpp_code(code, left_level=0, indent=CPP_DEFAULT_INDENT):
    formatted_code = ""
    level = 0
    for line in code.splitlines():
        stripped = line.lstrip()
        if stripped.startswith('}'):
            level -= 1

        modified_line = (left_level + level) * indent + stripped
        modified_line = modified_line.rstrip()

        if modified_line.endswith('{'):
            level += 1

        modified_line += '\n'

        formatted_code += modified_line

    return formatted_code

def format_cpp_code(code, left_level=0, indent=CPP_DEFAULT_INDENT):
    """! Fixes the indenting of a block of code in a curlies-based language and removes
         newline characters before and after.
         If you want a newline after your code, append it.
    """
    formatted_code = indent_cpp_code(code, left_level, indent)
    formatted_code = remove_trailing_newlines(formatted_code)
    formatted_code = remove_leading_empty_lines(formatted_code)
    return formatted_code

def remove_leading_empty_lines(code):
    return code.lstrip('\n')

def remove_trailing_newlines(code):
    return code.rstrip('\n')

def remove_trailing_empty_lines(code):
    modified = code.rstrip('\n')
    if(len(modified) > 0 and code[-1] == '\n'):
        modified += '\n'
    return modified
