#!/usr/bin/python3 -i
#
# Copyright (c) 2018-2019 Valve Corporation
# Copyright (c) 2018-2019 LunarG, Inc.
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

# The content of this file was derived from the Khronos Registry cgenerator.py
# and related Python files found in the KhronosGroup/Vulkan-Headers GitHub repository.

import sys
import json
from collections import namedtuple


ValidValueTuple   = namedtuple('ValidValue',
                               [
                                   'value',
                                   'result',
                                   'description',
                                   'protect'
                               ])
SettingsDataTuple = namedtuple('SettingsData',
                               [ 'name',
                                 'mixed_name',
                                 'type',
                                 'variable_name',
                                 'variable_type',
                                 'description',
                                 'defaults',
                                 'valid_values'
                               ])

def GenerateMixedCaseSettingName(lower_name, add_space):
    mixed_name = lower_name[0].upper()
    mixed_name += lower_name[1:]
    while '_' in mixed_name:
        value_index = mixed_name.index('_')
        new_string = ''
        if value_index > 0:
            new_string = mixed_name[:value_index]
        if add_space:
            new_string += ' '

        new_char = mixed_name[value_index + 1].upper()
        new_string += new_char

        new_string += mixed_name[value_index + 2:]
        mixed_name = new_string
    return mixed_name

def WriteSourceHeader(file):
    source_header = '/*\n'
    source_header += '** Copyright (c) 2018-2019 Valve Corporation\n'
    source_header += '** Copyright (c) 2018-2019 LunarG, Inc.\n'
    source_header += '**\n'
    source_header += '** Licensed under the Apache License, Version 2.0 (the "License");\n'
    source_header += '** you may not use this file except in compliance with the License.\n'
    source_header += '** You may obtain a copy of the License at\n'
    source_header += '**\n'
    source_header += '**     http://www.apache.org/licenses/LICENSE-2.0\n'
    source_header += '**\n'
    source_header += '** Unless required by applicable law or agreed to in writing, software\n'
    source_header += '** distributed under the License is distributed on an "AS IS" BASIS,\n'
    source_header += '** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.\n'
    source_header += '** See the License for the specific language governing permissions and\n'
    source_header += '** limitations under the License.\n'
    source_header += '*/\n\n'
    source_header += '#include "encode/capture_settings.h"\n'
    source_header += '\n'
    source_header += '#include "util/file_path.h"\n'
    source_header += '#include "util/platform.h"\n'
    source_header += '\n'
    source_header += '#include <cassert>\n'
    source_header += '#include <cstdlib>\n'
    source_header += '\n'
    source_header += 'GFXRECON_BEGIN_NAMESPACE(gfxrecon)\n'
    source_header += 'GFXRECON_BEGIN_NAMESPACE(encode)\n'
    file.write(source_header)

def WriteSourceFooter(file):
    source_footer = '\n'
    source_footer += 'GFXRECON_END_NAMESPACE(encode)\n'
    source_footer += 'GFXRECON_END_NAMESPACE(gfxrecon)\n'
    file.write(source_footer)

def WriteAndroidEnvVarSetting(file, setting):
    file.write('')

def WriteAndroidEnvVarSettings(file, settings, default_capture_name, prefix):
    env_var_string  = 'const char CaptureSettings::kDefaultCaptureFileName[] = "/sdcard/%s";\n' % default_capture_name
    env_var_string += '\n'
    env_var_string += '// Android Properties\n'
    for current_setting in settings:
        env_var_prefix = 'const char k%sEnvVar[]' % current_setting.mixed_name
        while len(env_var_prefix) < 55:
            env_var_prefix += ' '
        env_var_string += '%s= "%s%s";\n' % (env_var_prefix, prefix, current_setting.name)
    file.write(env_var_string)

def WriteDesktopEnvVarSettings(file, settings, default_capture_name, prefix):
    env_var_string  = 'const char CaptureSettings::kDefaultCaptureFileName[] = "%s";\n' % default_capture_name
    env_var_string += '\n'
    env_var_string += '// Desktop Environment Variables\n'
    for current_setting in settings:
        env_var_prefix = 'const char k%sEnvVar[]' % current_setting.mixed_name
        while len(env_var_prefix) < 55:
            env_var_prefix += ' '
        env_var_string += '%s= "%s%s";\n' % (env_var_prefix, prefix, current_setting.name.upper())
    file.write(env_var_string)

def WriteOptionFileSettings(file, settings, prefix):
    env_var_string  = '// Settings file values\n'
    for current_setting in settings:
        option_prefix = 'const std::string kOptionKey%s' % current_setting.mixed_name
        while len(option_prefix) < 55:
            option_prefix += ' '
        env_var_string += '%s= std::string("%s%s");\n' % (option_prefix, prefix, current_setting.name)
    file.write(env_var_string)

def WriteCaptureSettingsLoadEnvVars(file, settings):
    capture_load_env_var  = 'void CaptureSettings::LoadOptionsEnvVar(OptionsMap* options)\n'
    capture_load_env_var += '{\n'
    capture_load_env_var += '    assert(options != nullptr);\n'
    for current_setting in settings:
        capture_load_env_var += '    LoadSingleOptionEnvVar(options,\n'
        capture_load_env_var += '                           k%sEnvVar,\n' % current_setting.mixed_name
        capture_load_env_var += '                           kOptionKey%s);\n' % current_setting.mixed_name
    capture_load_env_var += '}\n\n'
    file.write(capture_load_env_var)

def GenerateStringSettingFunc(file, setting):
    string_setting_func = 'static %s Parse%sString(\n' % (setting.variable_type, setting.mixed_name)
    string_setting_func += '    const std::string& value_string,\n'
    string_setting_func += '    %s default_value)\n' % setting.variable_type
    string_setting_func += '{\n'
    string_setting_func += '    %s result = default_value;\n' % setting.variable_type
    for valid_value in setting.valid_values:
        if len(valid_value.protect) > 0:
            string_setting_func += '#ifdef %s\n' % valid_value.protect
        string_setting_func += '    if (util::platform::StringCompareNoCase("%s", value_string.c_str()) == 0)\n' % valid_value.value
        string_setting_func += '    {\n'
        string_setting_func += '        result = %s;\n' % valid_value.result
        string_setting_func += '    }\n'
        if len(valid_value.protect) > 0:
            string_setting_func += '#endif // %s\n' % valid_value.protect
    string_setting_func += '    return result;\n'
    string_setting_func += '}\n\n'
    return string_setting_func

def WriteStringSettingFuncs(file, settings):
    settings_funcs = ''
    for current_setting in settings:
        if current_setting.type == 'string':
            settings_funcs += GenerateStringSettingFunc(file, current_setting)
    file.write(settings_funcs)

def FindDefaultValidValue(current_setting, default_name):
    for default_value in current_setting.valid_values:
        if default_value.value == default_name:
            return default_value
    return None

def WriteProcessOptions(file, settings):
    write_process_opt_func  = 'void CaptureSettings::ProcessOptions(OptionsMap* options, CaptureSettings* settings)\n'
    write_process_opt_func += '{\n'
    write_process_opt_func += '    assert(settings != nullptr);\n'
    for current_setting in settings:
        current_default = current_setting.variable_name
        default_count = len(current_setting.defaults)
        if current_setting.name == 'capture_file':
            current_default = 'kDefaultCaptureFileName'
        elif current_setting.type == 'bool' and default_count > 0:
            current_default = current_setting.defaults[0]
        else:
            if default_count > 0:
                current_default = '%s_default' % current_setting.name

            if default_count == 1:
                write_process_opt_func += '\n'
                write_process_opt_func += '    %s %s_default = ' % (current_setting.variable_type, current_setting.name)
                default_valid_value = FindDefaultValidValue(current_setting, current_setting.defaults[0])
                if default_valid_value == None:
                    write_process_opt_func += '"%s";\n' % current_setting.defaults[0]
                else:
                    write_process_opt_func += '%s;\n' % default_valid_value.result
            elif default_count > 1:
                write_process_opt_func += '\n'
                write_process_opt_func += '    %s %s_default;\n' % (current_setting.variable_type, current_setting.name)
                last_protect_string = ''
                wrote_protect       = False
                current_default = '%s_default' % current_setting.name
                for default_name in current_setting.defaults:
                    default_valid_value = FindDefaultValidValue(current_setting, default_name)
                    if default_valid_value == None:
                        write_process_opt_func += '    %s_default = "%s";\n' % (current_setting.name, default_name)
                    else:
                        if len(default_valid_value.protect) > 0:
                            wrote_protect = True
                            if len(last_protect_string) > 0:
                                write_process_opt_func += '#elif // %s\n' % default_valid_value.protect
                            else:
                                write_process_opt_func += '#ifdef %s\n' % default_valid_value.protect
                        elif wrote_protect:
                            write_process_opt_func += '#else\n'
                        write_process_opt_func += '    %s_default = %s;\n' % (current_setting.name, default_valid_value.result)
                        last_protect_string = default_valid_value.protect
                if wrote_protect:
                    write_process_opt_func += '#endif\n'

        write_process_opt_func += '    %s =\n' % current_setting.variable_name
        if current_setting.type == 'bool':
            write_process_opt_func += '        ParseBoolString(FindOption(options, kOptionKey%s), %s);\n' % (current_setting.mixed_name, current_default)
        elif current_setting.type == 'file_path':
            write_process_opt_func += '        FindOption(options, kOptionKey%s, %s);\n' % (current_setting.mixed_name, current_default)
        elif current_setting.type == 'string':
            write_process_opt_func += '        Parse%sString(FindOption(options, kOptionKey%s), %s);\n' % (current_setting.mixed_name, current_setting.mixed_name, current_default)
        else:
            write_process_opt_func += '        FindOption(options, kOptionKey%s, %s);\n' % (current_setting.mixed_name, current_default)
    write_process_opt_func += '}\n\n'
    file.write(write_process_opt_func)

def BuildDocumentationTable(is_desktop, settings):
    doc_table = '[//]: # (BEGIN-CODE-GEN - DO NOT REMOVE THIS COMMENT, THE FOLLOWING CODE IS AUTO-GENERATED)\n'
    setting_heading = 'Environment Variable'
    setting_prefix = 'GFXRECON_'
    if not is_desktop:
        setting_heading = 'Property'
        setting_prefix = 'debug.gfxrecon.'
    doc_table += 'Option | %s | Type | Description\n' % setting_heading
    doc_table += ''
    doc_table += '------ | ------------- | ------ | -------------\n'

    for current_setting in settings:
        setting_type = current_setting.type
        if setting_type == 'file_path':
            setting_type = 'file/path'

        doc_table += '%s | ' % GenerateMixedCaseSettingName(current_setting.name, True)
        doc_table += '%s%s | ' % (setting_prefix, current_setting.name.upper() if is_desktop else current_setting.name)
        doc_table += '%s | %s' % (setting_type, current_setting.description)

        if current_setting.type == 'string':
            doc_table += 'Valid values are: '
            count = 0
            for valid_value in current_setting.valid_values:
                if count > 0:
                    doc_table += ', '
                doc_table += '"%s"' % valid_value.value
                count += 1
            doc_table += '.'
            doc_table += '<ul>'
            for valid_value in current_setting.valid_values:
                doc_table += '<li>"%s" - %s</li>' % (valid_value.value, valid_value.description)
            doc_table += '</ul>'
        doc_table += '\n'

    doc_table += '[//]: # (END-CODE-GEN - DO NOT REMOVE THIS COMMENT, THE PRECEDING CODE IS AUTO-GENERATED)\n'
    return doc_table

def ReplaceDocumentationTable(file_target, settings):
    output_desktop_settings = True
    if 'android' in file_target:
        output_desktop_settings = False

    file_contents = []

    # Read in the file into a list of strings
    input_file = open(file_target, 'r')
    try:
        delete_line = False
        for line in input_file:
            # If we're deleting this line, check first to see if it's the end tag, otherwise,
            # just skip it.
            if delete_line:
                # If it's the end tag, generate the new table, add that new table to the
                # file contents, and then start re-adding the remaining lines.
                if 'END-CODE-GEN - DO NOT REMOVE THIS COMMENT' in line:
                    delete_line = False
                    file_contents.append(BuildDocumentationTable(output_desktop_settings, settings))

                # Continue for now
                continue

            # If we detect the code-gen section, ignore it and everything else that
            # follows until the end tag.
            if 'BEGIN-CODE-GEN - DO NOT REMOVE THIS COMMENT' in line:
                delete_line = True
                continue

            file_contents.append(line)
    finally:
        input_file.close()

    # Output the modified content into the original file
    output_file = open(file_target, 'w')
    try:
        for content in file_contents:
            output_file.write(content)
    finally:
        output_file.close()
    return

file_json = json.loads(open('layer_settings.json', 'r').read())

if 'layer_settings' in file_json:
    # Grab prefixes
    settings_file_prefix    = ''
    android_property_prefix = ''
    desktop_envvar_prefix   = ''
    default_capture_name    = 'gfxrecon_capture.gfxr'
    if 'prefixes' not in file_json['layer_settings']:
        print('ERROR: Require \'prefixes\' value to identify individual settings')
        sys.exit(-1)
    for target,prefix in file_json['layer_settings']['prefixes'].items():
        if target == 'settings_file_entry_prefix':
            settings_file_prefix = prefix
        elif target == 'android_property_prefix':
            android_property_prefix = prefix
        elif target == 'desktop_envvar_prefix':
            desktop_envvar_prefix = prefix
        else:
            print('WARNING: Unknown target \'%s\' in \'prefix\' section' % target)

    # Loop through settings
    settings = []
    if 'settings' not in file_json['layer_settings']:
        print('ERROR: Require \'settings\' value to identify individual settings')
        sys.exit(-1)
    for current_settings in file_json['layer_settings']['settings']:
        if 'name' not in current_settings:
            print('ERROR: Setting is missing \'name\' key')
            continue
        if 'type' not in current_settings:
            print('ERROR: Setting \'%s\' is missing \'type\' key' % current_settings['name'])
            continue
        if 'var_name' not in current_settings:
            print('ERROR: Setting \'%s\' is missing \'var_name\' key' % current_settings['name'])
            continue

        settings_name        = current_settings['name']
        settings_type        = current_settings['type'].lower()
        settings_var_name    = current_settings['var_name']
        settings_defaults    = []
        settings_description = ''
        if 'defaults' in current_settings:
            settings_defaults = current_settings['defaults']
        if 'description' in current_settings:
            settings_description = current_settings['description']

        # Save some time and record the default capture file name
        if settings_name.lower == 'capture_file' and len(settings_defaults[0]) > 0:
            default_capture_name = settings_defaults[0]

        settings_var_type = ''
        if 'var_type' not in current_settings:
            if settings_type == 'bool':
                settings_var_type = 'bool'
            elif settings_type == 'file_path':
                settings_var_type = 'std::string'
            elif settings_type == 'string':
                settings_var_type = 'std::string'
            else:
                print('ERROR: Require \'var_type\' for type \'%s\' in setting \'%s\'' % (settings_type, settings_name))
                continue
        else :
            settings_var_type = current_settings['var_type']

        # If there are valid values, loop through those
        valid_values = []
        if (settings_type != 'bool' and settings_type != 'file_path' and
            'valid_values' in current_settings):
            for current_valid_value in current_settings['valid_values']:
                if 'value' not in current_valid_value:
                    print('ERROR: Setting is missing \'value\' key in settings \'%s\'' % settings_name)
                    continue
                if 'result' not in current_valid_value:
                    print('ERROR: Setting is missing \'result\' key in settings \'%s\'' % settings_name)
                    continue
                valid_values.append(ValidValueTuple(value = current_valid_value['value'],
                                                    result = current_valid_value['result'],
                                                    description = current_valid_value['description'] if ('description' in current_valid_value) else '',
                                                    protect = current_valid_value['protect'] if ('protect' in current_valid_value) else ''))

        # Append all settings to a list
        settings.append(SettingsDataTuple(name = settings_name,
                                          mixed_name = GenerateMixedCaseSettingName(settings_name, False),
                                          type = settings_type,
                                          variable_name = settings_var_name,
                                          variable_type = settings_var_type,
                                          description = settings_description,
                                          defaults = settings_defaults,
                                          valid_values = valid_values))

    if len(settings) == 0:
        print('ERROR: No valid \'settings\' values found!')
        sys.exit(-1)

    # Create the settings source file
    f = open('../generated_capture_settings.cpp','w')
    WriteSourceHeader(f)
    f.write('// clang-format off\n')
    f.write('#if defined(__ANDROID__)\n')
    WriteAndroidEnvVarSettings(f, settings, default_capture_name, android_property_prefix)
    f.write('#else // !__ANDROID__\n')
    WriteDesktopEnvVarSettings(f, settings, default_capture_name, desktop_envvar_prefix)
    f.write('#endif\n\n')
    WriteOptionFileSettings(f, settings, settings_file_prefix)
    f.write('\n')
    WriteStringSettingFuncs(f, settings)
    WriteCaptureSettingsLoadEnvVars(f, settings)
    WriteProcessOptions(f, settings)
    f.write('// clang-format on\n')
    WriteSourceFooter(f)
    f.close()

    ReplaceDocumentationTable('../../../layer/USAGE_android.md', settings)
    ReplaceDocumentationTable('../../../layer/USAGE_desktop.md', settings)
