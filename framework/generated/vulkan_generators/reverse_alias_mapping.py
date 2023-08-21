#!/usr/bin/python3 -i
#
# Copyright (c) 2021 Samsung
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

from base_generator import *


def recurseMap(obj):
    if isinstance(obj, list):
        for val in obj:
            yield val
        return
    if not isinstance(obj, dict):
        yield obj
        return
    for val in obj.values():
        for item in recurseMap(val):
            yield item

def getReverseAliasMap(BaseGenerator):
    reverseMap = {}

    for extension in BaseGenerator.featureDictionary:
        # key: struct name, value: extension struct name
        targetDict = {}
        feature = BaseGenerator.featureDictionary[extension]
        for key, val in feature.items():
            if key == 'command':
                targetDict = BaseGenerator.registry.cmddict
            elif key == 'enumconstant':
                targetDict = BaseGenerator.registry.enumdict
            elif key in ['union', 'struct', 'bitmask', 'handle', 'enum']:
                targetDict = BaseGenerator.registry.typedict
            elif key in ['basetype', 'include', 'define', 'funcpointer']:
                continue

            for extStruct in recurseMap(val):
                typeinfo = targetDict.get(extStruct)

                if 'alias' in typeinfo.elem.attrib:
                    typeinfo = targetDict[typeinfo.elem.attrib['alias']]
                    reverseMap[typeinfo.elem.attrib['name']] = extStruct

    return reverseMap
