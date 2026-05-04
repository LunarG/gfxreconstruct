#!/usr/bin/env python3
# Copyright (c) 2022 Advanced Micro Devices, Inc. All rights reserved
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

# Helper script to perform automatic renaming of gfxrecon-optimize.exe prior to optimization


import sys
import os
import subprocess
import shutil
from os.path import exists


# Make sure we didn't leave stuff behind
def cleanup(optimizer_tool_path, optimizer_tool_path_renamed):
    if exists(optimizer_tool_path) and exists(optimizer_tool_path_renamed):
        optimizer_tool_file_size = os.path.getsize(optimizer_tool_path)
        optimizer_tool_renamed_file_size = os.path.getsize(optimizer_tool_path_renamed)
        if optimizer_tool_file_size == optimizer_tool_renamed_file_size:
            if "gfxrecon-replay.exe" not in optimizer_tool_path_renamed:
                print("Deleting: " + optimizer_tool_path_renamed)
                os.remove(optimizer_tool_path_renamed)


# Rename the optimizer
def rename_optimizer(encoded_app_executable):
    optimizer_name = os.path.join(os.path.dirname(__file__), "gfxrecon-optimize.exe")
    optimizer_name_renamed = os.path.join(os.getcwd(), encoded_app_executable)
    if exists(optimizer_name_renamed):
        print("Warning: " + encoded_app_executable +  " already exists. Reusing it.")
    else:
        shutil.copy(optimizer_name, optimizer_name_renamed)
        if not exists(capture_path):
            optimizer_name_renamed = ""
    return optimizer_name_renamed


# Run the optimizer
def run_optimizer(replay_tool_path, args):
    cmd = replay_tool_path
    cmd += " \"" + args.pop(0) + "\""
    cmd += " \"" + args.pop(0) + "\""

    for arg in args:
        cmd += " " + arg
    print("Running: " + cmd)
    print("")
    output = subprocess.check_output(cmd).decode().split("\r\n")
    for line in output:
        print(line)


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
    print("gfxrecon-optimize-renamed.py - Helper script to perform automatic renaming of gfxrecon-optimize.exe prior to optimization.")
    print()
    print("Usage:")
    print(
        "  gfxrecon-optimize-renamed.py <input-file> <output-file> [--d3d12-pso-removal] [--d3d12-resource-removal] [--dxr] [--gpu <index>]")
    print()
    print("Required arguments:")
    print("  <input-file>          The path to input GFXReconstruct capture file to be processed.")
    print("  <output-file>         The path to output GFXReconstruct capture file to be created.")    
    print()
    print("Optional arguments:")    
    print("  --d3d12-pso-removal           D3D12-only: Remove creation of unreferenced PSOs.")
    print("  --d3d12-resource-removal      D3D12-only: Remove initialization of unreferenced resources (experimental, off by default).")
    print("  --dxr                         D3D12-only: Optimize for DXR and ExecuteIndirect replay.")
    print("  --gpu <index>                 Use the specified device for the optimizer replay, where index")
    print("                                is the zero-based index to the array of physical devices")
    print("                                returned by vkEnumeratePhysicalDevices or IDXGIFactory1::EnumAdapters1.")
    print("                                The optimizer replay may fail if the specified device is not compatible with the")
    print("                                original capture devices.")
    print()    
    print("Note: running without optional arguments will instruct the optimizer to detect API and run all available optimizations.")
    print()
    print("Example manual usage (D3D12):")
    print("  gfxrecon-optimize-renamed.py my_capture.gfxr my_capture_dxr_optimized.gfxr --dxr")
    print("  gfxrecon-optimize-renamed.py my_capture.gfxr my_capture_pso_optimized.gfxr --d3d12-pso-removal")
    print()
    print("Example automatic usage (D3D12 + Vulkan):")
    print("  gfxrecon-optimize-renamed.py my_capture.gfxr my_capture_optimized.gfxr") 
    print();

# Main
if __name__ == '__main__':

    argc = len(sys.argv)

    # If valid number of params
    if argc > 2:
        # exe gfxr gfxr or exe gfxr gfxr optional
        if sys.argv[1][-4:] == "gfxr" and sys.argv[2][-4:] == "gfxr":
            capture_path = sys.argv[1]
        
            args = []
            for arg in sys.argv:
                args.append(arg)
            args.pop(0)

            optimizer_tool_path_renamed = ""

            try:
                # Verify capture exists
                if exists(capture_path):
                    optimizer_tool_path = os.path.join(os.path.dirname(__file__), "gfxrecon-optimize.exe")

                    # Verify optimizer tool exists
                    if exists(optimizer_tool_path):
                        info_tool_path = os.path.join(os.path.dirname(__file__), "gfxrecon-info.exe")

                        # Verify info tool exists
                        if exists(info_tool_path):
                            encoded_app_executable = retrieve_exe_name(info_tool_path, capture_path)

                            if encoded_app_executable:
                                optimizer_tool_path_renamed = rename_optimizer(encoded_app_executable)
                                if optimizer_tool_path_renamed:
                                    run_optimizer(optimizer_tool_path_renamed, args)
                                    cleanup(optimizer_tool_path, optimizer_tool_path_renamed)
                                else:
                                    print("Warning: Could not rename optimizer")
                                    run_optimizer(optimizer_tool_path, args)
                            else:
                                print("Warning: Did not detect captured application executable name")
                                run_optimizer(optimizer_tool_path, args)
                        else:
                            print("Error: ensure gfxrecon-info.exe lives in the same directory as this script")
                    else:
                        print("Error: ensure gfxrecon-optimize.exe lives in the same directory as this script")
                else:
                    usage()
                    print("Error: path to capture is invalid")
            except Exception as e:
                print("Error: exception occurred")
                print(e)
                cleanup(optimizer_tool_path, optimizer_tool_path_renamed)
        else:
            print("Error: path to capture is invalid")
            print("Usage: gfxrecon-optimize-renamed.py input_file.gfxr output_file.gfxr [--dxr] [--d3d12-pso-removal]")

    else:
        print("Error: missing path to capture")
        usage()
        
