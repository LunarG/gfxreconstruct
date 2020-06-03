#!/usr/bin/env python3
#
# Copyright (c) 2020 LunarG, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
#
# Utility for capturing Vulkan API calls using gfxreconstruct


import argparse
import os
import sys
import subprocess


######################
# Define a usage message.
# We use a custom usage message because Python's arg parser
# doesn't provide a very good usage message for positional arguments.
# (The default usage message for positional args is
# as an ellipse. We would rather have "<program> [<programArgs>]".)
def UsageMsg():
    msg = ('gfxrecon-capture.py [-h]' + os.linesep +
           '                           [-w dir]' + os.linesep +
           '                           [-o captureFile]' + os.linesep +
           '                           [-f captureFrames]' + os.linesep +
           '                           [--no-file-timestamp]' + os.linesep +
           '                           [--trigger {F1-F12,TAB,CTRL}]' + os.linesep +
           '                           [--compression-type {LZ4,ZLIB,ZSTD,NONE}]' + os.linesep +
           '                           [--file-flush]' + os.linesep +
           '                           [--log-level {debug,info,warn,error,fatal}]' + os.linesep +
           '                           [--log-file <file>]' + os.linesep)
    if sys.platform == 'win32':
        msg += '                           [--log-debugview]' + os.linesep
    msg += '                           [--memory-tracking-mode {page_guard,assisted,unassisted}]' + os.linesep
    msg += '                           <program> [<programArgs>]'
    return msg



######################
# SmartFormater is used by arg parser to assist in breaking arg help text into multiple lines.
# It is used whenever the help text starts with 'R|'.
class SmartFormatter(argparse.HelpFormatter):
    def _split_lines(self, text, width):
        if text.startswith('R|'):
            return text[2:].splitlines()
        return argparse.HelpFormatter._split_lines(self, text, width)


######################
# Print error message and exit with non-zero status
def PrintErrorAndExit(msg):
    print(os.path.basename(__file__) + ' error: ' + msg)
    sys.exit(1)


######################
# Remove an env variable if it is currently in environ
def DelEnvVar(env):
    if env in os.environ:
        del os.environ[env]


######################
# Parse arguments
def ParseArgs():

    triggerKeyChoices = ['F1','F2','F3','F4','F5','F6','F7','F8','F9','F10','F11','F12','TAB','CTRL']
    compressionTypeChoices = ['LZ4','ZLIB','ZSTD','NONE']
    logLevelChoices = ['debug','info','warn','error','fatal']
    memoryTrackingModeChoices = ['page_guard','assisted','unassisted']

    parser = argparse.ArgumentParser(prog=os.path.basename(sys.argv[0]), description='Create a capture of a Vulkan program.', usage=UsageMsg(), allow_abbrev=False, formatter_class=SmartFormatter)

    # Common optional args
    parser.add_argument('-w', '--working-dir', dest='workingDir', metavar='<dir>', help='Set CWD to this directory before running the program')
    parser.add_argument('-o', '--capture-file', dest='captureFile', metavar='<captureFile>', help='Name of the capture file, default is gfxrecon_capture.gfxr')
    parser.add_argument('-f', '--capture-frames', dest='captureFrames', metavar='<captureFrames>', help='List of frames to capture, default is all frames')
    parser.add_argument('--no-file-timestamp', dest='noTimestampFile', action='store_true', help='Do not add a timestamp to the capture file name')
    parser.add_argument('--trigger', dest='trigger', choices=triggerKeyChoices, help='Specify a hotkey to start/stop capture')
    parser.add_argument('--compression-type', dest='compressionType', choices=compressionTypeChoices, help='Specify the type of compression to use in the capture file, default is LZ4')
    parser.add_argument('--file-flush', dest='fileFlush', action='store_true', help='Flush output stream after each packet is written to capture file')
    parser.add_argument('--log-level', dest='logLevel', choices=logLevelChoices, help='Specify highest level message to log, default is info')
    parser.add_argument('--log-file', dest='logFile', metavar='logFile', help='Name of the log file (disable logging with empty string), default is stdout/stderr')
    if sys.platform == 'win32':
        parser.add_argument('--log-debugview', dest='logDebugView', action='store_true', help='Log messages with OutputDebugStringA')
    parser.add_argument('--memory-tracking-mode', dest='memoryTrackingMode', choices=memoryTrackingModeChoices , help=
                        'R|Method to use to track changes to memory mapped objects:' + os.linesep +
                        '   page_guard: use pageguard to track changes (default)' + os.linesep +
                        '   assisted: application will call vkFlushMappedMemoryRanges' + os.linesep +
                        '      for memory to be written to the capture file' + os.linesep +
                        '   unassisted: all mapped memory will be written to the' + os.linesep +
                        '      capture file during VkQueueSubmit and VkUnmapMemory')

    # Required args
    parser.add_argument('programAndArgs', metavar='<program> [<program args>]', nargs=argparse.REMAINDER, help='Program to capture, optionally followed by program arguments')

    return parser


######################
# PrintArgs - for debugging
def PrintArgs(args):
    print('working-dir', args.workingDir)
    print('capture-file', args.captureFile)
    print('capture-frames', args.captureFrames)
    print('no-file-timestamp', args.noTimestampFile)
    print('trigger', args.trigger)
    print('compression-type', args.compressionType)
    print('file-flush', args.fileFlush)
    print('log-level', args.logLevel)
    print('log-file', args.logFile)
    if sys.platform == 'win32':
        print('log-debugview', args.logDebugView)
    print('memory-tracking-mode', args.memoryTrackingMode)
    print('programAndArgs', args.programAndArgs)


######################
# Do validation on arguments
def ValidateArgs(args):

    # Verify workingDir exists and is a directory.
    if args.workingDir is not None:
        if (not os.path.isdir(args.workingDir)):
            PrintErrorAndExit('Working directory ' + args.workingDir + ' does not exist')

    # Make sure program was specified. arg parser doesn't allow specifying programAndArgs
    # as required.
    if len(args.programAndArgs) == 0:
        print('usage: ' + UsageMsg())
        PrintErrorAndExit('<program> must be specified')

    # Verify programName exists and is executable.
    programName=args.programAndArgs[0]
    if (os.path.isabs(programName)):
        programNamePath=programName
    else:
        if args.workingDir is not None:
            programNamePath = os.path.join(args.workingDir, programName)
        else:
            programNamePath=programName
    if (not os.path.isfile(programNamePath)):
        PrintErrorAndExit('Cannot find program ' + programNamePath + ' to execute')
    if (not os.access(programNamePath, os.X_OK)):
        PrintErrorAndExit('Program ' + programNamePath + ' does not have execute permission')

    # Program name passed to subprocess.run() needs to be an absolute
    # or relative path because subprocess.run() searches for cmd in
    # PATH if the program name path is not absolute or relative
    if not os.path.isabs(programName) and programName[0] != '.':
        programName = os.path.join('.', programName)
        args.programAndArgs[0] = programName


######################
# Set env variables for trace layer
def SetEnvVars(args):

    # Set VK_INSTANCE_LAYERS
    # If gfxr layer is not already in VK_INSTANCE_LAYER, append gfxr layer to VK_INSTANCE_LAYERS
    if os.getenv('VK_INSTANCE_LAYERS') is None:
        os.environ['VK_INSTANCE_LAYERS'] = 'VK_LAYER_LUNARG_gfxreconstruct'
    elif (not ('VK_LAYER_LUNARG_gfxreconstruct' in os.getenv('VK_INSTANCE_LAYERS'))):
        os.environ['VK_INSTANCE_LAYERS'] = os.environ['VK_INSTANCE_LAYERS'] + os.pathsep + 'VK_LAYER_LUNARG_gfxreconstruct'

    # Set GFXRECON_CAPTURE_FILE
    # We don't verify that we can write the captureFile.
    # The trace layer will generate an error if it is unable to write the file.
    if args.captureFile is not None:
        os.environ['GFXRECON_CAPTURE_FILE'] = args.captureFile
    else:
        DelEnvVar('GFXRECON_CAPTURE_FILE')

    # Set GFXRECON_CAPTURE_FRAMES
    if args.captureFrames is not None:
        os.environ['GFXRECON_CAPTURE_FRAMES'] = args.captureFrames
    else:
        DelEnvVar('GFXRECON_CAPTURE_FRAMES')

    # Set GFXRECON_CAPTURE_FILE_TIMESTAMP
    if args.noTimestampFile:
        os.environ['GFXRECON_CAPTURE_FILE_TIMESTAMP'] = 'false'
    else:
        DelEnvVar('GFXRECON_CAPTURE_FILE_TIMESTAMP')

    # Set GFXRECON_CAPTURE_TRIGGER
    if args.trigger is not None:
        os.environ['GFXRECON_CAPTURE_TRIGGER'] = args.trigger
    else:
        DelEnvVar('GFXRECON_CAPTURE_TRIGGER')

    # Set GFXRECON_CAPTURE_COMPRESSION_TYPE
    if args.compressionType is not None:
        os.environ['GFXRECON_CAPTURE_COMPRESSION_TYPE'] = args.compressionType
    else:
        DelEnvVar('GFXRECON_CAPTURE_COMPRESSION_TYPE')

    # Set GFXRECON_CAPTURE_FILE_FLUSH
    os.environ['GFXRECON_CAPTURE_FILE_FLUSH'] = str(args.fileFlush)

    # Set GFXRECON_LOG_LEVEL
    if args.logLevel is not None:
        os.environ['GFXRECON_LOG_LEVEL'] = args.logLevel
    else:
        DelEnvVar('GFXRECON_LOG_LEVEL')

    # Set GFXRECON_LOG_FILE
    if args.logFile is not None:
        os.environ['GFXRECON_LOG_FILE'] = args.logFile
    else:
        DelEnvVar('GFXRECON_LOG_FILE')

    # Set GFXRECON_LOG_OUTPUT_TO_OS_DEBUG_STRING
    if sys.platform == 'win32':
        os.environ['GFXRECON_LOG_OUTPUT_TO_OS_DEBUG_STRING'] = str(args.logDebugView)
    else:
        DelEnvVar('GFXRECON_LOG_OUTPUT_TO_OS_DEBUG_STRING')

    # Set GFXRECON_MEMORY_TRACKING_MODE
    if args.memoryTrackingMode is not None:
        os.environ['GFXRECON_MEMORY_TRACKING_MODE'] = args.memoryTrackingMode


######################
# PrintEnvVar - for debugging
# print a single env var
def PrintEnvVar(envVar):
    if envVar in os.environ:
        print(envVar, os.environ[envVar])
    else:
        print(envVar, 'None')


######################
# PrintLayerEnv - for debugging
# print all env vars used by layer that are set by this script
def PrintLayerEnv():
    PrintEnvVar('GFXRECON_CAPTURE_COMPRESSION_TYPE')
    PrintEnvVar('GFXRECON_CAPTURE_FILE')
    PrintEnvVar('GFXRECON_CAPTURE_FILE_FLUSH')
    PrintEnvVar('GFXRECON_CAPTURE_FILE_TIMESTAMP')
    PrintEnvVar('GFXRECON_CAPTURE_FRAMES')
    PrintEnvVar('GFXRECON_CAPTURE_TRIGGER')
    PrintEnvVar('GFXRECON_LOG_FILE')
    PrintEnvVar('GFXRECON_LOG_LEVEL')
    PrintEnvVar('GFXRECON_LOG_OUTPUT_TO_OS_DEBUG_STRING')
    PrintEnvVar('GFXRECON_MEMORY_TRACKING_MODE')
    PrintEnvVar('VK_INSTANCE_LAYERS')


if __name__ == '__main__':

    # We don't support running under Cygwin Python
    if sys.platform == 'cygwin':
        PrintErrorAndExit("Cygwin Python not supported")

    # Get and validate args
    parser = ParseArgs()
    args = parser.parse_args()
    #PrintArgs(args)   # For debugging
    ValidateArgs(args)

    # Set up environment
    SetEnvVars(args)
    #PrintLayerEnv()    # For debugging

    # If workingDir was specified, make it the cwd
    if args.workingDir is not None:
        os.chdir(args.workingDir)

    # Run the program and and exit with the exit status of the program
    result = subprocess.run(args.programAndArgs)
    sys.exit(result.returncode)
