#!/usr/bin/python3 -i
#
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

import re

def GenerateStructureType(type_name):
    upper_type = re.sub('([a-z0-9])([A-Z])', r'\1_\2', type_name).upper()
    if upper_type.startswith('VK_'):
        type_with_prefix = re.sub('VK_', 'VK_STRUCTURE_TYPE_', upper_type)
    elif upper_type.startswith('XR_'):
        type_with_prefix = re.sub('XR_', 'XR_TYPE_', upper_type)
    if 'OPEN_GLES' in type_with_prefix:
        type_with_prefix = re.sub('OPEN_GLES', 'OPENGL_ES_', type_with_prefix)
    elif 'OPEN_GL' in type_with_prefix:
        type_with_prefix = re.sub('OPEN_GL', 'OPENGL_', type_with_prefix)
    elif 'D3_D' in type_with_prefix:
        type_with_prefix = re.sub('D3_D', 'D3D', type_with_prefix)
    return type_with_prefix

def MakeSimpleVarName(type_name):
    lower_type = re.sub('([a-z0-9])([A-Z])', r'\1_\2', type_name).lower()
    if lower_type.startswith('vk_'):
        lower_type = re.sub('vk_', '', lower_type)
    elif lower_type.startswith('xr_'):
        lower_type = re.sub('xr_', '', lower_type)
    return lower_type
