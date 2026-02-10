#!/usr/bin/env python3

# Copyright (c) 2019 Advanced Micro Devices, Inc. All rights reserved
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

'''
GFXReconstruct check code style script
'''

import subprocess
import sys
import argparse
import os

def check_code_style(file_list, compare_base, style_script=None, style_config_dir=None):
    """
    Run clang format diff on the changed source file(s)
    against current branch. If branch retrieved failed, 
    fall back to diff against master branch.
    :raises Exception: when formatting errors found
    """
    git_branch = subprocess.check_output(["git", "rev-parse", "--abbrev-ref", compare_base]).strip()
    if git_branch == b'':
        git_branch = "master"
    if not style_script:
        # Look for the clang-format-diff.py script in the same directory as the calling script
        style_script = os.path.join(os.path.dirname(os.path.realpath(sys.argv[0])), "clang-format-diff.py")
    if not style_config_dir:
        # Use the script directory's parent directory as the .clang-format file location
        style_config_dir = os.path.join(os.path.dirname(style_script), os.pardir)

    # Ignore code style of generated files
    file_list = [f for f in file_list if 'generated' not in f]

    diff_cmd = ["git", "diff", "-U0", str(git_branch, 'utf-8'), "--"] + file_list
    style_cmd = [sys.executable, style_script,"-p1","-style=file"]
    try:
        diff_process = subprocess.Popen(diff_cmd, stdout=subprocess.PIPE)
        style_output = subprocess.check_output(style_cmd, stdin=diff_process.stdout, cwd=style_config_dir)

        if style_output != b'':
            raise Exception("FORMATTING ERROR!\n" + str(style_output, 'utf-8'))
    except subprocess.CalledProcessError as e:
        print("ERROR calling clang-format-diff.py [{}]".format(e))
        sys.exit(1)

# Main entry point
if '__main__' == __name__:
    # parse params and run check code style function
    parser = argparse.ArgumentParser(prog='check_code_style',
                                     description='Checks if file match the code style specification')
    parser.add_argument('--sourcefile', nargs='+', dest='file_list', help="The source file(s)")
    parser.add_argument('--base', dest='compare_base', metavar='BASE', action='store', default='HEAD',
        help='Git branch name or commit ID to use as the base for C++ code style comparison')
    args = parser.parse_args()
    check_code_style(args.file_list, args.compare_base)
    sys.exit(0)
