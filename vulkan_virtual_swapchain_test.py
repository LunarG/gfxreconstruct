#!/usr/bin/python3 -i
#
# Copyright (c) 2022 LunarG, Inc.
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

import argparse
import filecmp
import json
import os
import subprocess
import time

def get_options():
    parser = argparse.ArgumentParser(description='TODO : Description')
    parser.add_argument('--application', type=str, default=vkcube)
    parser.add_argument('--gfxrjson', type=str)
    parser.add_argument('--directory', type=str, default=os.getcwd())
    parser.add_argument('--vulkansdk', type=str, default=vulkansdk)
    parser.add_argument('--duration', type=int, default=5)
    args = parser.parse_args()

def set_env_var(key, value):
    if value is not None:
        os.environ[key] = value
    elif key in os.environ:
        del os.environ[key]

def main():
    vulkansdk = os.getenv('VULKAN_SDK')
    vkcube = os.path.join(vulkansdk, 'bin/vkcube.exe')

    parser = argparse.ArgumentParser(description='TODO : Description')
    parser.add_argument('--application', type=str, default=vkcube)
    parser.add_argument('--gfxrjson', type=str)
    parser.add_argument('--directory', type=str, default=os.getcwd())
    parser.add_argument('--vulkansdk', type=str, default=vulkansdk)
    parser.add_argument('--duration', type=int, default=5)
    args = parser.parse_args()

    # Enable gfxreconstruct and screenshot layers...
    vk_instance_layers = 'VK_LAYER_LUNARG_gfxreconstruct' + os.pathsep + 'VK_LAYER_LUNARG_screenshot'
    os.environ['VK_INSTANCE_LAYERS'] = vk_instance_layers
    # if os.getenv('VK_INSTANCE_LAYERS') is None:
    #     os.environ['VK_INSTANCE_LAYERS'] = vk_instance_layers
    # elif not 'VK_LAYER_LUNARG_gfxreconstruct' in os.getenv('VK_INSTANCE_LAYERS'):
    #     os.environ['VK_INSTANCE_LAYERS'] = vk_instance_layers # os.environ['VK_INSTANCE_LAYERS'] + os.pathsep + vk_instance_layers

    # Configure gfxreconstruct and screenshot layers...
    capture_results = os.path.join(args.directory, 'capture_results')
    os.makedirs(capture_results, exist_ok=True)
    gfxr_file_name = 'gfxrecon_capture'
    gfxr_file_path = os.path.join(capture_results, gfxr_file_name + '.gfxr')
    set_env_var('GFXRECON_CAPTURE_FILE', gfxr_file_path)
    set_env_var('GFXRECON_CAPTURE_FRAMES', None)
    set_env_var('GFXRECON_CAPTURE_FILE_TIMESTAMP', '0')
    set_env_var('VK_SCREENSHOT_DIR', capture_results)
    set_env_var('VK_SCREENSHOT_FRAMES', '8,16')

    # Capture .gfxr and .ppm files...
    capture = subprocess.Popen(args.application, creationflags=subprocess.DETACHED_PROCESS)
    time.sleep(args.duration)
    capture.terminate()

    # Disable gfxreconstruct layer...
    vk_instance_layers = 'VK_LAYER_LUNARG_screenshot'
    os.environ['VK_INSTANCE_LAYERS'] = vk_instance_layers
    # if os.getenv('VK_INSTANCE_LAYERS') is None:
    #     os.environ['VK_INSTANCE_LAYERS'] = vk_instance_layers
    # elif not 'VK_LAYER_LUNARG_gfxreconstruct' in os.getenv('VK_INSTANCE_LAYERS'):
    #     os.environ['VK_INSTANCE_LAYERS'] = vk_instance_layers # os.environ['VK_INSTANCE_LAYERS'] + os.pathsep + vk_instance_layers

    # Configure screenshot layer...
    replay_results = os.path.join(args.directory, 'replay_results')
    os.makedirs(replay_results, exist_ok=True)
    set_env_var('VK_SCREENSHOT_DIR', replay_results)
    set_env_var('VK_SCREENSHOT_FRAMES', '8,16')

    # Replay .gfxr and take screenshots at the same frame indices as capture time...
    gfxr_replay = os.path.join(vulkansdk, 'bin/gfxrecon-replay.exe')
    
    time.sleep(1)
    subprocess.run([gfxr_replay, gfxr_file_path])
    time.sleep(1)

    # Diff the screenshots from capture and replay...
    match, mismatch, errors = filecmp.cmpfiles(capture_results, replay_results, ['8.ppm', '16.ppm'], shallow=True)
    print('\n\n================================================================================')
    print('match:', match)
    print('mismatch:', mismatch)
    print('errors:', errors)

if __name__ == "__main__":
    main()
