#!/usr/bin/env python3
#
# Copyright (c) 2024 LunarG, Inc.
# Copyright (c) 2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# DEALINGS IN THE SOFTWARE.


from io import TextIOWrapper
import itertools
import os
import subprocess
import xml.etree.ElementTree as ET


SCRIPT_DIR = os.path.abspath(os.path.dirname(__file__))
PROTOCOLS_DIR = os.path.normpath(
    os.path.join(SCRIPT_DIR, '..', '..', 'external', 'wayland-protocols')
)


COPYRIGHT = '''/*
** Copyright (c) 2024 LunarG, Inc.
** Copyright (c) 2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/
'''


def wayland_arg_to_cpp_type(arg: ET.Element) -> str:

    arg_type = arg.attrib['type']

    if arg_type == 'int' or arg_type == 'enum' or arg_type == 'fd':
        return 'int32_t'
    elif arg_type == 'uint':
        return 'uint32_t'
    elif arg_type == 'fixed':
        return 'wl_fixed'
    elif arg_type == 'object' or arg_type == 'new_id':
        return arg.attrib['interface'] + '*'
    elif arg_type == 'string':
        return 'const char*'
    elif arg_type == 'array':
        return 'wl_array*'
    else:
        raise Exception(f'Unknown arg type: "{arg_type}"')


def generate_request(file: TextIOWrapper, interface_name: str, request: ET.Element, opcode: int) -> None:

    return_type = 'void'
    args = list()

    for arg in request.findall('arg'):
        if arg.attrib['type'] == 'new_id':
            if return_type != 'void':
                raise Exception('Two objects created by the same request: Case not handled.')
            return_type = wayland_arg_to_cpp_type(arg)
        else:
            args.append((wayland_arg_to_cpp_type(arg), arg.attrib['name']))

    func_name = interface_name + '_' + request.attrib["name"]

    file.write(f'\t\t{return_type} {func_name}({interface_name}* self{", ".join([""] + [arg[0] + " " + arg[1] for arg in args])}) const\n')
    file.write('\t\t{\n')

    if return_type != 'void':

        params = [
            'reinterpret_cast<wl_proxy*>(self)',
            str(opcode),
            f'&{return_type[:-1]}_interface',
            'NULL'
        ]

        params.extend(arg[1] for arg in args)

        file.write(f'\t\t\treturn reinterpret_cast<{return_type}>(_wl->proxy_marshal_constructor({", ".join(params)}));\n')
    
    else:

        params = [
            'reinterpret_cast<wl_proxy*>(self)',
            str(opcode)
        ]

        params.extend(arg[1] for arg in args)

        file.write(f'\t\t\t_wl->proxy_marshal({", ".join(params)});\n')

        if request.attrib["name"] == 'destroy':
            file.write('\t\t\t_wl->proxy_destroy(reinterpret_cast<wl_proxy*>(self));\n')


    file.write('\t\t}\n')
    file.write('\n')


def get_message_interface_name(interface: str) -> str:
    if interface[:3] == 'wl_':
        return f'_wl->{interface[3:]}_interface'
    else:
        return f'&{interface}_interface'


def message_from_func(message_args: list, func: ET.Element) -> list:
    
    message = [func.attrib['name'], '', 0]

    if 'since' in func.attrib:
        message[1] += func.attrib['since']

    current_args = list()
    for arg in func.findall('arg'):

        arg_type = arg.attrib['type']

        if arg_type == 'int':
            message[1] += 'i'
            current_args.append('nullptr')
        elif arg_type == 'uint':
            message[1] += 'u'
            current_args.append('nullptr')
        elif arg_type == 'fixed':
            message[1] += 'f'
            current_args.append('nullptr')
        elif arg_type == 'object':
            message[1] += 'o'
            current_args.append(get_message_interface_name(arg.attrib["interface"]))
        elif arg_type == 'new_id':
            message[1] += 'n'
            current_args.append(get_message_interface_name(arg.attrib["interface"]))
        elif arg_type == 'string':
            message[1] += 's'
            current_args.append('nullptr')
        elif arg_type == 'array':
            message[1] += 'a'
            current_args.append('nullptr')
        elif arg_type == 'fd':
            message[1] += 'h'
            current_args.append('nullptr')
        elif arg_type == 'enum':
            message[1] += 'i'
            current_args.append('nullptr')
        else:
            raise Exception(f'Unknown arg type: "{arg_type}"')
        
        if 'allow-null' in arg.attrib and arg.attrib['allow-null'] == 'true':
            message[1] += '?'
    
    if len(current_args) == 0:
        return message
    
    for m in range(len(message_args) - len(current_args)):
        
        found = True
        for c, c_arg in enumerate(current_args):
            if message_args[m + c] != c_arg:
                found = False
                break
        
        if found:
            message[2] = m
            return message

    
    for i in range(len(message_args) - len(current_args), len(message_args)):
        if message_args[i:] == current_args[:len(message_args) - i]:
            message_args.extend(current_args[len(message_args) - i:])
            message[2] = i
            return message
        
    message[2] = len(message_args)
    message_args.extend(current_args)

    return message


def generate(protocol_path: str) -> None:

    print(f'Generating protocol sources for "{protocol_path}"')

    tree = ET.parse(protocol_path)
    root = tree.getroot()

    protocol_name = root.attrib['name']
    generated_filename = os.path.join(SCRIPT_DIR, f'generated_wayland_{protocol_name}.h')

    with open(generated_filename, 'w') as file:
        
        # Header of file

        file.write(COPYRIGHT)
        file.write('\n')
        file.write(f'#ifndef GFXRECON_GENERATED_WAYLAND_{protocol_name.upper()}_H\n')
        file.write(f'#define GFXRECON_GENERATED_WAYLAND_{protocol_name.upper()}_H\n')
        file.write('\n')
        file.write('#include <vector>\n')
        file.write('\n')
        file.write('#include <wayland-client.h>\n')
        file.write('\n')
        file.write('#include "util/defines.h"\n')
        file.write('#include "util/wayland_loader.h"\n')
        file.write('\n')

        # Static declarations

        for interface in root.findall('interface'):
            file.write(f'struct {interface.attrib["name"]};\n')

        file.write('\n')

        for interface in root.findall('interface'):

            interface_name = interface.attrib['name']

            file.write(f'// {interface_name} static declarations\n')
            file.write('\n')

            # Enums

            for enum in interface.findall('enum'):
                file.write(f'enum {interface_name}_{enum.attrib["name"]}\n')
                file.write('{\n')
                for entry in enum.findall('entry'):
                    file.write(f'\t{interface_name}_{enum.attrib["name"]}_{entry.attrib["name"]} = {entry.attrib["value"]},\n'.upper())
                file.write('};\n')
                file.write('\n')
        
            # Listeners

            if interface.find('event') is not None:

                file.write(f'struct {interface_name}_listener\n')
                file.write('{\n')

                for event in interface.findall('event'):
                    file.write(f'\tvoid (*{event.attrib["name"]})(void* data, {interface_name}* object')

                    for arg in event.findall('arg'):
                        file.write(f', {wayland_arg_to_cpp_type(arg)} {arg.attrib["name"]}')
                    
                    file.write(');\n')

                file.write('};\n')
                file.write('\n')

        # Protocol table
                
        file.write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)\n')
        file.write('GFXRECON_BEGIN_NAMESPACE(util)\n')
        file.write('\n')
        file.write(f'// Global to {protocol_name}\n')
        file.write('\n')
        file.write(f'class wayland_{protocol_name}_table\n')
        file.write('{\n')
        file.write('\tprivate:\n')
        file.write('\n')
        file.write('\t\tconst WaylandLoader::FunctionTable* _wl;\n')
        file.write('\t\tstd::vector<wl_message> _messages;\n')
        file.write('\t\tstd::vector<const wl_interface*> _messageArgs;\n')
        file.write('\n')
        file.write('\tpublic:\n')
        file.write('\n')

        # Per-interface dynamic declarations

        for interface in root.findall('interface'):

            interface_name = interface.attrib['name']

            file.write(f'\t\t// {interface_name} dynamic declarations\n')
            file.write('\n')

            # Interfaces
            
            file.write(f'\t\twl_interface {interface.attrib["name"]}_interface;\n')
            file.write('\n')

            # Listeners

            if interface.find('event') is not None:
                
                file.write(f'\t\tint {interface_name}_add_listener({interface_name}* self, {interface_name}_listener* listener, void* data) const\n')
                file.write('\t\t{\n')
                file.write('\t\t\treturn _wl->proxy_add_listener(reinterpret_cast<wl_proxy*>(self), reinterpret_cast<void (**)(void)>(listener), data);\n')
                file.write('\t\t}\n')
                file.write('\n')

            # Requests
        
            destroy_found = False
            for opcode, request in enumerate(interface.findall('request')):
                generate_request(file, interface_name, request, opcode)
                if request.attrib['name'] == 'destroy':
                    destroy_found = True
            
            if not destroy_found:
                file.write(f'\t\tvoid {interface_name}_destroy({interface_name}* self) const\n')
                file.write('\t\t{\n')
                file.write('\t\t\t_wl->proxy_destroy(reinterpret_cast<wl_proxy*>(self));\n')
                file.write('\t\t}\n')
                file.write('\n')

        # Initialize func

        file.write('\t\t// Call this once libwayland-client is successfully loaded\n')
        file.write('\n')
        file.write('\t\tvoid initialize(const WaylandLoader* waylandLoader)\n')
        file.write('\t\t{\n')

        file.write('\t\t\t_wl = &waylandLoader->GetFunctionTable();\n')
        file.write('\n')

        messages = dict()
        message_args = list()
        for interface in root.findall('interface'):
            interface_name = interface.attrib['name']
            messages[interface_name] = [list(), list()]
            for request in interface.findall('request'):
                messages[interface_name][0].append(message_from_func(message_args, request))
            for event in interface.findall('event'):
                messages[interface_name][1].append(message_from_func(message_args, event))

        file.write('\t\t\t_messageArgs = {\n')
        for arg in message_args:
            file.write(f'\t\t\t\t{arg},\n')
        file.write('\t\t\t};\n')
        file.write('\n')

        file.write('\t\t\t_messages = {\n')
        for interface in root.findall('interface'):
            for message in itertools.chain(messages[interface.attrib['name']][0], messages[interface.attrib['name']][1]):
                file.write(f'\t\t\t\t{{ "{message[0]}", "{message[1]}", _messageArgs.data() + {message[2]} }},\n')

        file.write('\t\t\t};\n')
        file.write('\n')

        counter = 0
        for interface in root.findall('interface'):

            interface_name = interface.attrib["name"]
            request_count = len(messages[interface_name][0])
            event_count = len(messages[interface_name][1])

            file.write(f'\t\t\t{interface_name}_interface = {{ "{interface_name}", {interface.attrib["version"]},')
            file.write(f' {request_count}, _messages.data() + {counter},')
            counter += request_count
            file.write(f' {event_count}, _messages.data() + {counter} }};\n')
            counter += event_count

        file.write('\t\t}\n')
        file.write('};\n')
        file.write('\n')

        # Footer of file

        file.write('GFXRECON_END_NAMESPACE(util)\n')
        file.write('GFXRECON_END_NAMESPACE(gfxrecon)\n')
        file.write('\n')
        file.write(f'#endif // GFXRECON_GENERATED_WAYLAND_{protocol_name.upper()}_H\n')


def clone_wayland_protocols():

    print('Cloning/Pulling wayland-protocols git repository...')

    if os.path.exists(PROTOCOLS_DIR):
        subprocess.run(['git', 'pull'], cwd=PROTOCOLS_DIR)
    else:
        subprocess.run(['git', 'clone', 'https://gitlab.freedesktop.org/wayland/wayland-protocols.git', PROTOCOLS_DIR])


def main():
    clone_wayland_protocols()
    generate(os.path.join(PROTOCOLS_DIR, 'stable', 'xdg-shell', 'xdg-shell.xml'))


if __name__ == '__main__':
    main()
