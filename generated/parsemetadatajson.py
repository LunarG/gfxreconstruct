#!/usr/bin/python3 -i
#
# Copyright (c) 2018 LunarG, Inc
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

import sys, getopt
import json
from collections import namedtuple

class MetadataJson:
    def __init__(self, file_name):
        self.entrypoints = []
        self.ActionInfo = namedtuple('ActionInfo', ['name', 'type', 'purpose'])
        self.EntryPointActions = namedtuple('EntryPointActions', ['name', 'actions'])

        # Attempt to open the provided file
        try:
            json_file_desc = open(file_name)
        except OSError:
            print('Error: Input file "%s" can not be opened' % file_name)
            exit(-1)

        # Attempt to read from the provided file
        json_file_string = json_file_desc.read()
        if 0 == len(json_file_string):
            print('Error: Input file "%s" is empty' % file_name)
            exit(-1)

        # Parse the JSON contents
        json_contents = json.loads(json_file_string)

        try:
            # The important items are in the metadata block
            metadata_block = json_contents["metadata"]

            # Each block under the metadata block should contain information about one
            # Vulkan entrypoint of interest
            for entry_point_block in metadata_block:
                # We should only have one per block, but just make sure we can support more than
                # one.
                for entry_point in entry_point_block:
                    cur_entry_point_block = entry_point_block[entry_point]

                    # Go through each of the possible descriptions
                    actions = []
                    for action_description in cur_entry_point_block:
                        if (action_description != 'recording' and
                            action_description != 'pre-playback' and
                            action_description != 'post-playback'):
                            raise KeyError(action_description)

                        action_block = cur_entry_point_block[action_description]
                        type_string = ''
                        purpose_string = ''
                        for action_section in action_block:
                            if action_section == 'type':
                                type_string = action_block[action_section]
                            elif action_section == 'purpose':
                                purpose_string = action_block[action_section]
                        actions.append(self.ActionInfo(name=action_description,
                                                       type=type_string,
                                                       purpose=purpose_string))
                    self.entrypoints.append(self.EntryPointActions(name=entry_point,
                                                                   actions=actions))

        except KeyError as k:
            print('Error: Input file "%s" invalid or missing JSON Key "%s"' % (file_name, k))
            exit(-1)
        except ValueError as e:
            print('Error: Input file "%s" missing required JSON Value "%s"' % (file_name, e))
            exit(-1)

    def HasRecordingAction(self, entrypoint_name):
        for entrypoint_item in self.entrypoints:
            if entrypoint_item.name == entrypoint_name:
                for action_item in entrypoint_item.actions:
                    if action_item.name == 'recording':
                        return True
                break
        return False

    def GetRecordingAction(self, entrypoint_name):
        for entrypoint_item in self.entrypoints:
            if entrypoint_item.name == entrypoint_name:
                for action_item in entrypoint_item.actions:
                    if action_item.name == 'recording':
                        return action_item.type, action_item.purpose
                break
        return '', ''

    def HasPrePlaybackAction(self, entrypoint_name):
        for entrypoint_item in self.entrypoints:
            if entrypoint_item.name == entrypoint_name:
                for action_item in entrypoint_item.actions:
                    if action_item.name == 'pre-playback':
                        return True
                break
        return False

    def GetPrePlaybackAction(self, entrypoint_name):
        for entrypoint_item in self.entrypoints:
            if entrypoint_item.name == entrypoint_name:
                for action_item in entrypoint_item.actions:
                    if action_item.name == 'pre-playback':
                        return action_item.type, action_item.purpose
                break
        return '', ''

    def HasPostPlaybackAction(self, entrypoint_name):
        for entrypoint_item in self.entrypoints:
            if entrypoint_item.name == entrypoint_name:
                for action_item in entrypoint_item.actions:
                    if action_item.name == 'post-playback':
                        return True
                break
        return False

    def GetPostPlaybackAction(self, entrypoint_name):
        for entrypoint_item in self.entrypoints:
            if entrypoint_item.name == entrypoint_name:
                for action_item in entrypoint_item.actions:
                    if action_item.name == 'post-playback':
                        return action_item.type, action_item.purpose
                break
        return '', ''

def PrintUsage():
    print('parsemetadatajson.py')
    print('    -i <input_file>    Parse the provided input file as a JSON file containing')
    print('                       information on which entrypoints require various types of')
    print('                       Metadata function calls.')
    print('    -h                 Print out this help')
    exit(-1)

def main(argv):
    input_file = ''
    try:
        opts, args = getopt.getopt(argv, "hi:")
    except getopt.GetoptError:
        PrintUsage()
    for opt, arg in opts:
        if opt == '-h':
            PrintUsage()
        elif opt == '-i':
            input_file = arg
    if len(input_file) == 0:
        PrintUsage()

    x = MetadataJson(input_file)

if __name__ == "__main__":
    main(sys.argv[1:])