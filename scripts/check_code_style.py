#!/usr/bin/env python3

# Copyright (c) 2019 Advanced Micro Devices, Inc. All rights reserved
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at:
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

'''
GFX reconstruct check code style script
'''

import subprocess
import sys
import argparse

def check_code_style(file):
    """
    Run clang format diff on the changed source file(s)
    against current branch. If branch retrieved failed, 
    fall back to diff against master branch.
    :raises Exception: when formatting errors found
    """
    git_branch = subprocess.check_output(["git", "rev-parse", "--abbrev-ref", "HEAD"]).strip()
    if git_branch == b'':
        git_branch = "master"
    cmd = ["git", "diff", "-U0", str(git_branch, 'utf-8'),
           "--"] + file + ["|", "python", "clang-format-diff.py","-p1","-style=file"]
    try:
        cmd_output = subprocess.check_output(cmd)
        if cmd_output != b'':
            raise Exception("FORMATTING ERROR!\n" + str(cmd_output, 'utf-8'))
    except subprocess.CalledProcessError as e:
        print("ERROR calling clang-format-diff.py [{}]".format(e))
        sys.exit(1)

# Main entry point
if '__main__' == __name__:
    # parse params and run check code style function
    parser = argparse.ArgumentParser(prog='check_code_style',
                                     description='Checks if file match the code style specification')
    parser.add_argument('--sourcefile', nargs='+', dest='file', help="The source file(s)")
    args = parser.parse_args()
    check_code_style(args.file)
    sys.exit(0)