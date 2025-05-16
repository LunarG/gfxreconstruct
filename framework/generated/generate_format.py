#!/usr/bin/env python3
#
# Copyright (c) 2018 Valve Corporation
# Copyright (c) 2018-2025 LunarG, Inc.
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
'''Generate GFXR framework/format  content
'''

import sys
import os

SCRIPT_DIR = os.path.abspath(os.path.dirname(__file__))
util_script_dir = os.path.join(SCRIPT_DIR, 'util_generators')
sys.path.append(util_script_dir)

from generate_api_call_id_strings import write_call_id_strings
framework_format_dir = os.path.normpath(os.path.join(SCRIPT_DIR, '..', '..', 'framework', 'format'))
api_call_id_h = os.path.join(framework_format_dir, 'api_call_id.h')

if __name__ == '__main__':
    # Simplest wrapper for this generator
    with open(api_call_id_h) as input_file:
        generated= os.path.join(SCRIPT_DIR, 'generated_api_call_id_string_pairs.h')
        with open(generated, 'w') as output_file:
            write_call_id_strings(input_file, output_file)
