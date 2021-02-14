#!/usr/bin/env python3
#
# Copyright (c) 2021 LunarG, Inc.
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

from dx12_base_generator import *
from dx12_replay_consumer_header_generator\
    import Dx12ReplayConsumerHeaderGenerator
from base_replay_consumer_body_generator import *


# Generates C++ functions responsible for consuming Dx12 API calls
class Dx12ReplayConsumerBodyGenerator(
        BaseReplayConsumerBodyGenerator, Dx12ReplayConsumerHeaderGenerator):

    # Override
    REPLAY_OVERRIDES = {}
    # Override
    structsWithHandles = dict()
    # Override
    sTypeValues = dict()

    # Method override
    def write_include(self):
        write('#include "generated_dx12_replay_consumer.h"', file=self.outFile)

    # Method override
    def generateFeature(self):
        Dx12BaseGenerator.generateFeature(self)
        BaseReplayConsumerBodyGenerator.generate_feature(self, 'Dx12')
        self.generate_dx12_method_feature()

    def generate_dx12_method_feature(self):
        first = True
        for method in self.getFilteredMethodNames():
            info = self.featureMethodParams[method]
            return_type = info[0]
            values = info[2]

            cmddef = '' if first else '\n'
            cmddef += self.makeConsumerFuncDecl(return_type,
                                                'Dx12ReplayConsumer::Process_'
                                                + method,
                                                values,
                                                True) + '\n'
            cmddef += '{\n'

            class_name = method[:method.find('_')]
            cmddef += ("    auto replay_object = MapObject<{}>(object_id);\n"
                       "    if (replay_object != nullptr)\n"
                       "    {{\n".format(class_name))

            body = self.makeConsumerFuncBody(return_type, method, values)
            code_list = body.split('\n')
            for code in code_list:
                if len(code) > 0:
                    cmddef += ('    ' + code + '\n')

            cmddef += '    }\n'\
                      '}'

            write(cmddef, file=self.outFile)
            first = False

    # Method override
    def makeConsumerFuncBody(self, return_type, name, values):
        if name == 'IUnknown_AddRef':
            return '    replay_object->AddRef();\n'
        elif name == 'IUnknown_Release':
            return ("    auto replay_count = replay_object->Release();\n"
                    "    if (replay_count == 0)\n"
                    "    {\n"
                    "        RemoveObject(object_id);\n"
                    "        GFXRECON_LOG_INFO(\"Object with ID %\" PRIu64 \" has been destroyed\", object_id);\n"  # noqa
                    "    }\n")

        code = ''
        for value in values:
            if self.is_tracking_data(value):
                array_length = None
                if value.isArray:
                    # TODO: There are currently no output array parameters,
                    # so just print a warning for now.
                    print(
                        'WARNING: Skipping code generation for unsupported output array parameter',
                        name,
                        '::',
                        value.name)
                else:
                    array_length = 1
                code += '    if(!{0}->IsNull()) {0}->SetHandleLength({1});\n'\
                        '    auto _out_p_{0}    = {0}->GetPointer();\n'\
                        '    auto _out_hp_{0}   = {0}->GetHandlePointer();\n'\
                        .format(value.name, array_length)

        is_object = True if name.find('_') != -1 else False
        function_name = name if not is_object else name[name.find('_') + 1:]
        indent_length = len(code)
        code += '    '
        if return_type != 'void':
            code += 'auto replay_result = '

        if is_object:
            code += 'replay_object->'

        code += function_name + '('
        indent_length = len(code) - indent_length
        first = True
        for value in values:
            if not first:
                code += ',\n{}'.format(' ' * indent_length)
            first = False

            value_name = None
            if self.is_tracking_data(value):
                if value.fullType.find('void') != -1:
                    value_name = 'reinterpret_cast<void**>(_out_hp_{})'\
                        .format(value.name)
                else:
                    value_name = '_out_hp_{}'.format(value.name)
            else:
                if value.pointerCount > 0 or value.isArray:
                    if self.isClass(value):
                        if value.pointerCount == 2:
                            value_name = 'MapObject<{}*>(*{}->GetPointer())'\
                                         .format(value.baseType, value.name)
                        elif value.pointerCount == 1:
                            value_name = 'MapObject<{}>(*{}->GetPointer())'\
                                         .format(value.baseType, value.name)
                    elif self.isStruct(value.baseType)\
                            and value.pointerCount == 2\
                            and value.isConst:
                        value_name = ('const_cast<const {}**>({}->GetPointer())'  # noqa
                                      .format(value.baseType, value.name))
                    elif value.baseType == 'void':
                        if value.pointerCount == 1:
                            value_name = 'reinterpret_cast<void*>({})'.format(
                                value.name)
                        elif value.pointerCount == 2:
                            value_name = value.name + '->GetOutputPointer()'
                    else:
                        value_name = value.name + '->GetPointer()'

                else:
                    if self.isStruct(value.baseType):
                        value_name = '*' + value.name + '.decoded_value'
                    elif self.isHandle(value.baseType):
                        value_name = 'MapHandle<{}>({})'.format(
                            value.baseType, value.name)
                    elif value.baseType == 'PFN_DESTRUCTION_CALLBACK':
                        value_name = ('reinterpret_cast<PFN_DESTRUCTION_CALLBACK>({})'  # noqa
                                      .format(value.name))

            if not value_name:
                value_name = value.name
            code += value_name
        code += ');\n'

        if return_type == 'HRESULT' and len(values):
            code += ("    if (SUCCEEDED(replay_result))\n"
                     "    {\n")
            for value in values:
                if self.is_tracking_data(value):
                    if self.isClass(value):
                        code += ('        AddObject(_out_p_{0}, _out_hp_{0});\n'  # noqa
                                 .format(value.name))
                    elif self.isHandle(value.baseType):
                        code += ('        AddHandle(_out_p_{0}, _out_hp_{0});\n'  # noqa
                                 .format(value.name))
            code += "    }\n"
            code += ('    CheckReplayResult("{}", returnValue, replay_result);\n'  # noqa
                     .format(name))
        return code

    def is_tracking_data(self, value):
        if value.fullType.find('_Out') != -1\
            and (self.isClass(value)
                 or self.isHandle(value.baseType)):
            return True
        return False
