#!/usr/bin/python3 -i
#
# Copyright (c) 2026 LunarG, Inc.
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

## @file Helpers that keep regeneration from touching generated files whose
## content is unchanged, so their timestamps (and dependent builds) are left
## alone.
##
## Usage: open the temporary output file with
## newline=existing_newline(target) so its bytes match an unchanged target
## regardless of the checkout's line ending convention (e.g. core.autocrlf),
## then finish with replace_if_changed(temp, target).

import filecmp
import os
import shutil
from pathlib import Path


def existing_newline(target_path):
    """Return the line ending used by the file at target_path, judged by its
    first line. Returns '\\n' if the file doesn't exist or has no line ending.
    """
    try:
        with open(target_path, 'rb') as f:
            return '\r\n' if f.readline().endswith(b'\r\n') else '\n'
    except FileNotFoundError:
        return '\n'


def replace_if_changed(temp_path, target_path):
    """Copy temp_path over target_path only if their bytes differ, then delete
    temp_path.
    """
    target_path = Path(target_path)
    if not target_path.exists() or not filecmp.cmp(
        temp_path, target_path, shallow=False
    ):
        target_path.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy(temp_path, target_path)
    os.remove(temp_path)
