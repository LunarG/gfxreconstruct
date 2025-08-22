#!/usr/bin/python3 -i
#
# Copyright (c) 2018-2021 Valve Corporation
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
#
'''Generate GFXR framework/format ApiCallId string pairs

    The generated file is intended to be included with the {} of an
    aggregate (map, vector, array, etc) containing

        std::pair<ApiCallId, const char *>
'''

import re

def write_call_id_strings(in_file, out_file):
    out_file.write( '''
    // clang-format off
    /*
    ** Copyright (c) 2021-2023 LunarG, Inc.
    **
    ** Permission is hereby granted, free of charge, to any person obtaining a copy
    ** of this software and associated documentation files (the "Software"), to
    ** deal in the Software without restriction, including without limitation the
    ** rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
    ** sell copies of the Software, and to permit persons to whom the Software is
    ** furnished to do so, subject to the following conditions:
    **
    ** The above copyright notice and this permission notice shall be included in
    ** all copies or substantial portions of the Software.
    **
    ** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    ** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    ** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    ** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    ** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    ** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    ** IN THE SOFTWARE.
    */

    /*
    ** This file is generated from generate_api_call_id_strings.py.
    **
    */

    ''')

    for line in in_file:
        if re.search(r'^\s+ApiCall\S+\s+=', line):
            pair = re.sub(r'^\s+ApiCall_(\S+)\s+=.*$', r'    {ApiCall_\1, "\1"},', line)
            out_file.write(pair)

    out_file.write('    // clang-format on\n')