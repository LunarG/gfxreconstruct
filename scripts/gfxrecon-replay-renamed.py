#!/usr/bin/env python3
# Copyright (c) 2022-2023 Advanced Micro Devices, Inc. All rights reserved
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

# Helper script to perform automatic renaming of gfxrecon-replay.exe prior to playback


import sys
import os
import subprocess
import shutil
from os.path import exists


# Make sure we didn't leave stuff behind
def cleanup(replayer_tool_path, replayer_tool_path_renamed):
    if exists(replayer_tool_path) and exists(replayer_tool_path_renamed):
        replayer_tool_file_size = os.path.getsize(replayer_tool_path)
        replayer_tool_renamed_file_size = os.path.getsize(replayer_tool_path_renamed)
        if replayer_tool_file_size == replayer_tool_renamed_file_size:
            if "gfxrecon-replay.exe" not in replayer_tool_path_renamed:
                print("Deleting: " + replayer_tool_path_renamed)
                os.remove(replayer_tool_path_renamed)


# Rename the replayer
def rename_replayer(encoded_app_executable):
    replayer_name = os.path.join(os.path.dirname(__file__), "gfxrecon-replay.exe")
    replayer_name_renamed = os.path.join(os.getcwd(), encoded_app_executable)
    if exists(replayer_name_renamed):
        print("Warning: " + encoded_app_executable +  " already exists. Reusing it.")
    else:
        shutil.copy(replayer_name, replayer_name_renamed)
        if not exists(capture_path):
            replayer_name_renamed = ""
    return replayer_name_renamed

def run_command(command):
    try:
        subprocess.run(command, check=True)
    except subprocess.CalledProcessError as e:
        print ("subprocess returncode: ", e.returncode)

# Run the replayer
def run_replayer(replay_tool_path, args):
    cmd = replay_tool_path
    cmd += " \"" + args.pop(0) + "\""
    for arg in args:
        cmd += " " + arg
    print("Running: " + cmd)
    print("")
    run_command(cmd) 


# Run gfxrecon-info to retrieve application name from capture
def retrieve_exe_name(info_tool_path, capture_path):
    print("Retrieving captured application executable name...")
    cmd = info_tool_path + " \"" + capture_path + "\" --exe-info-only"
    output = subprocess.check_output(cmd).decode('utf-8',errors='ignore').split("\r\n")
    exe_name = ""
    for line in output:
        if "Application exe name:" in line:
            tokens = line.split(" ")
            for token in tokens:
                exe_name = token.strip()
    if ".exe" not in exe_name:
        exe_name = ""
    else:
        print("Found: " + exe_name)
    return exe_name


# Print usage instructions
def usage():
    print("gfxrecon-replay-renamed.py - Helper script to perform automatic renaming of gfxrecon-replay.exe prior to playback.")    
    print();
    print("Usage:")
    print("  gfxrecon-replay-renamed.py <file> [optional_replayer_args]")
    print();
    print("Required arguments:")
    print("  <file>                     Path to the capture file to replay.")
    print()
    print("Optional arguments:")
    print("  [optional_replayer_args]   All optional arguments exposed by gfxrecon-replay.exe")   
    print() 

# Main
if __name__ == '__main__':

    argc = len(sys.argv)

    # If valid number of params
    if argc > 1:
        capture_path = sys.argv[1]

        args = []
        for arg in sys.argv:
            args.append(arg)
        args.pop(0)

        replayer_tool_path_renamed = ""

        try:
            # Verify capture exists
            if exists(capture_path):
                replayer_tool_path = os.path.join(os.path.dirname(__file__), "gfxrecon-replay.exe")

                # Verify replayer tool exists
                if exists(replayer_tool_path):
                    info_tool_path = os.path.join(os.path.dirname(__file__), "gfxrecon-info.exe")

                    # Verify info tool exists
                    if exists(info_tool_path):
                        encoded_app_executable = retrieve_exe_name(info_tool_path, capture_path)

                        if encoded_app_executable:
                            replayer_tool_path_renamed = rename_replayer(encoded_app_executable)
                            if replayer_tool_path_renamed:
                                run_replayer(replayer_tool_path_renamed, args)
                                cleanup(replayer_tool_path, replayer_tool_path_renamed)
                            else:
                                print("Warning: Could not rename replayer")
                                run_replayer(replayer_tool_path, args)
                        else:
                            print("Warning: Did not detect captured application executable name")
                            run_replayer(replayer_tool_path, args)
                    else:
                        print("Error: ensure gfxrecon-info.exe lives in the same directory as this script")
                else:
                    print("Error: ensure gfxrecon-replay.exe lives in the same directory as this script")
            else:
                usage()
                print("Error: path to capture is invalid")
        except:
            print()
            print("Error: exception occurred")
            cleanup(replayer_tool_path, replayer_tool_path_renamed)

    else:
        usage()
        print("Error: missing path to capture")
