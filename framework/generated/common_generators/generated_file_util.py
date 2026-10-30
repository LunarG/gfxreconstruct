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

## @file Helper that keeps regeneration from touching a generated file whose
## content is unchanged, so its timestamp (and dependent builds) is left alone.
## The temporary output must be written with newline='\n' to match the LF
## line endings .gitattributes gives the checked-out generated sources.

import filecmp
import os
import shutil
import sys
from pathlib import Path


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


def finish_output_file(generator):
    """OutputGenerator.endFile from the registry's generator.py, with two lines
    changed: the target is replaced only when its content changed, and the
    missing-options error is a plain RuntimeError because each generator family
    defines its own MissingGeneratorOptionsError.
    """
    if generator.errFile:
        generator.errFile.flush()
    if generator.warnFile:
        generator.warnFile.flush()
    if generator.diagFile:
        generator.diagFile.flush()
    if generator.outFile:
        generator.outFile.flush()
        if generator.outFile != sys.stdout and generator.outFile != sys.stderr:
            generator.outFile.close()

        if generator.genOpts is None:
            raise RuntimeError('generator options missing at endFile')

        # On successfully generating output, move the temporary file to the
        # target file if its content changed.
        if generator.genOpts.filename is not None:
            replace_if_changed(generator.outFile.name, Path(generator.genOpts.directory) / generator.genOpts.filename)
    generator.genOpts = None
