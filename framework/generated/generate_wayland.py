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


# Indentation of a class member, of an access specifier and of a nesting level within a
# member function body.  Generated sources use spaces only.
MEMBER_INDENT = ' ' * 4
ACCESS_INDENT = ' ' * 2
BODY_INDENT = ' ' * 4


# The types generated for the interfaces of the protocol currently being processed, keyed by
# Wayland interface name.  Interfaces that libwayland already declares (the "wl_" ones) are
# absent from this table and keep the names wayland-client.h gives them.
protocol_interface_types = dict()


def to_upper_camel_case(name: str) -> str:
    return ''.join(word[:1].upper() + word[1:] for word in name.split('_'))


def interface_to_cpp_type(interface_name: str) -> str:
    """C++ type name for a Wayland interface, generated or from wayland-client.h."""
    return protocol_interface_types.get(interface_name, interface_name)


def generated_type_name(*parts: str) -> str:
    """Name for a type generated at global scope.

    These sit next to the types declared by the Wayland protocol headers, so they carry a
    "Gfxr" prefix to keep the two from colliding when both are visible.  Types generated
    inside the gfxrecon::util namespace do not need it.
    """
    return 'Gfxr' + ''.join(to_upper_camel_case(part) for part in parts)


def generated_enum_entry_name(*parts: str) -> str:
    return '_'.join(['GFXR'] + [part.upper() for part in parts])


def protocol_table_type_name(protocol_name: str) -> str:
    """Name of the table class generated for a protocol.

    The table lives in gfxrecon::util, so unlike the global-scope types it needs no prefix.
    """
    return 'Wayland' + to_upper_camel_case(protocol_name) + 'Table'


def wayland_arg_to_cpp_type(arg: ET.Element) -> str:

    arg_type = arg.attrib['type']

    if arg_type == 'int' or arg_type == 'enum' or arg_type == 'fd':
        return 'int32_t'
    elif arg_type == 'uint':
        return 'uint32_t'
    elif arg_type == 'fixed':
        return 'wl_fixed_t'
    elif arg_type == 'object' or arg_type == 'new_id':
        return interface_to_cpp_type(arg.attrib['interface']) + '*'
    elif arg_type == 'string':
        return 'const char*'
    elif arg_type == 'array':
        return 'wl_array*'
    else:
        raise Exception(f'Unknown arg type: "{arg_type}"')


def generate_request(file: TextIOWrapper, interface_name: str, request: ET.Element, opcode: int) -> None:

    return_type = 'void'
    return_interface = None
    args = list()

    for arg in request.findall('arg'):
        if arg.attrib['type'] == 'new_id':
            if return_interface is not None:
                raise Exception('Two objects created by the same request: Case not handled.')
            return_interface = arg.attrib['interface']
            return_type = wayland_arg_to_cpp_type(arg)
        else:
            args.append((wayland_arg_to_cpp_type(arg), arg.attrib['name']))

    func_name = interface_name + '_' + request.attrib["name"]
    self_type = interface_to_cpp_type(interface_name)

    file.write(f'{MEMBER_INDENT}{return_type} {func_name}({self_type}* self{", ".join([""] + [arg[0] + " " + arg[1] for arg in args])}) const\n')
    file.write(f'{MEMBER_INDENT}{{\n')

    if return_interface is not None:

        params = [
            'reinterpret_cast<wl_proxy*>(self)',
            str(opcode),
            f'&{return_interface}_interface',
            'NULL'
        ]

        params.extend(arg[1] for arg in args)

        file.write(f'{MEMBER_INDENT}{BODY_INDENT}return reinterpret_cast<{return_type}>(_wl->proxy_marshal_constructor({", ".join(params)}));\n')

    else:

        params = [
            'reinterpret_cast<wl_proxy*>(self)',
            str(opcode)
        ]

        params.extend(arg[1] for arg in args)

        file.write(f'{MEMBER_INDENT}{BODY_INDENT}_wl->proxy_marshal({", ".join(params)});\n')

        if request.attrib["name"] == 'destroy':
            file.write(f'{MEMBER_INDENT}{BODY_INDENT}_wl->proxy_destroy(reinterpret_cast<wl_proxy*>(self));\n')

    file.write(f'{MEMBER_INDENT}}}\n')
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

    global protocol_interface_types
    protocol_interface_types = {
        interface.attrib['name']: generated_type_name(interface.attrib['name'])
        for interface in root.findall('interface')
    }

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
            file.write(f'struct {interface_to_cpp_type(interface.attrib["name"])};\n')

        file.write('\n')

        for interface in root.findall('interface'):

            interface_name = interface.attrib['name']
            interface_type = interface_to_cpp_type(interface_name)

            file.write(f'// {interface_name} static declarations\n')
            file.write('\n')

            # Enums

            for enum in interface.findall('enum'):
                file.write(f'enum {generated_type_name(interface_name, enum.attrib["name"])}\n')
                file.write('{\n')
                for entry in enum.findall('entry'):
                    entry_name = generated_enum_entry_name(interface_name, enum.attrib['name'], entry.attrib['name'])
                    file.write(f'{MEMBER_INDENT}{entry_name} = {entry.attrib["value"]},\n')
                file.write('};\n')
                file.write('\n')

            # Listeners

            if interface.find('event') is not None:

                file.write(f'struct {generated_type_name(interface_name, "listener")}\n')
                file.write('{\n')

                for event in interface.findall('event'):
                    file.write(f'{MEMBER_INDENT}void (*{event.attrib["name"]})(void* data, {interface_type}* object')

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
        file.write(f'class {protocol_table_type_name(protocol_name)}\n')
        file.write('{\n')
        file.write(f'{ACCESS_INDENT}private:\n')
        file.write('\n')
        file.write(f'{MEMBER_INDENT}const WaylandLoader::FunctionTable* _wl;\n')
        file.write(f'{MEMBER_INDENT}std::vector<wl_message> _messages;\n')
        file.write(f'{MEMBER_INDENT}std::vector<const wl_interface*> _messageArgs;\n')
        file.write('\n')
        file.write(f'{ACCESS_INDENT}public:\n')
        file.write('\n')

        # Per-interface dynamic declarations

        for interface in root.findall('interface'):

            interface_name = interface.attrib['name']
            interface_type = interface_to_cpp_type(interface_name)

            file.write(f'{MEMBER_INDENT}// {interface_name} dynamic declarations\n')
            file.write('\n')

            # Interfaces

            file.write(f'{MEMBER_INDENT}wl_interface {interface_name}_interface;\n')
            file.write('\n')

            # Listeners

            if interface.find('event') is not None:

                listener_type = generated_type_name(interface_name, 'listener')

                file.write(f'{MEMBER_INDENT}int {interface_name}_add_listener({interface_type}* self, {listener_type}* listener, void* data) const\n')
                file.write(f'{MEMBER_INDENT}{{\n')
                file.write(f'{MEMBER_INDENT}{BODY_INDENT}return _wl->proxy_add_listener(reinterpret_cast<wl_proxy*>(self), reinterpret_cast<void (**)(void)>(listener), data);\n')
                file.write(f'{MEMBER_INDENT}}}\n')
                file.write('\n')

            # Requests

            destroy_found = False
            for opcode, request in enumerate(interface.findall('request')):
                generate_request(file, interface_name, request, opcode)
                if request.attrib['name'] == 'destroy':
                    destroy_found = True

            if not destroy_found:
                file.write(f'{MEMBER_INDENT}void {interface_name}_destroy({interface_type}* self) const\n')
                file.write(f'{MEMBER_INDENT}{{\n')
                file.write(f'{MEMBER_INDENT}{BODY_INDENT}_wl->proxy_destroy(reinterpret_cast<wl_proxy*>(self));\n')
                file.write(f'{MEMBER_INDENT}}}\n')
                file.write('\n')

        # Initialize func

        file.write(f'{MEMBER_INDENT}// Call this once libwayland-client is successfully loaded\n')
        file.write('\n')
        file.write(f'{MEMBER_INDENT}void initialize(const WaylandLoader* waylandLoader)\n')
        file.write(f'{MEMBER_INDENT}{{\n')

        file.write(f'{MEMBER_INDENT}{BODY_INDENT}_wl = &waylandLoader->GetFunctionTable();\n')
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

        file.write(f'{MEMBER_INDENT}{BODY_INDENT}_messageArgs = {{\n')
        for arg in message_args:
            file.write(f'{MEMBER_INDENT}{BODY_INDENT * 2}{arg},\n')
        file.write(f'{MEMBER_INDENT}{BODY_INDENT}}};\n')
        file.write('\n')

        file.write(f'{MEMBER_INDENT}{BODY_INDENT}_messages = {{\n')
        for interface in root.findall('interface'):
            for message in itertools.chain(messages[interface.attrib['name']][0], messages[interface.attrib['name']][1]):
                file.write(f'{MEMBER_INDENT}{BODY_INDENT * 2}{{ "{message[0]}", "{message[1]}", _messageArgs.data() + {message[2]} }},\n')

        file.write(f'{MEMBER_INDENT}{BODY_INDENT}}};\n')
        file.write('\n')

        counter = 0
        for interface in root.findall('interface'):

            interface_name = interface.attrib["name"]
            request_count = len(messages[interface_name][0])
            event_count = len(messages[interface_name][1])

            file.write(f'{MEMBER_INDENT}{BODY_INDENT}{interface_name}_interface = {{ "{interface_name}", {interface.attrib["version"]},')
            file.write(f' {request_count}, _messages.data() + {counter},')
            counter += request_count
            file.write(f' {event_count}, _messages.data() + {counter} }};\n')
            counter += event_count

        file.write(f'{MEMBER_INDENT}}}\n')
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
    # viewporter and fractional-scale together let a window size itself correctly on a
    # fractionally scaled output, which wl_surface::set_buffer_scale cannot express.
    generate(os.path.join(PROTOCOLS_DIR, 'stable', 'viewporter', 'viewporter.xml'))
    generate(os.path.join(PROTOCOLS_DIR, 'staging', 'fractional-scale', 'fractional-scale-v1.xml'))


if __name__ == '__main__':
    main()
