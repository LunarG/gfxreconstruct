# Settings File Generation

This directory contains all the tools necessary to define common settings,
and generate the supporting code sections and documentation for those
settings.
These settings are now commmonly defined in the [settings.json](./settings.json) JSON
file found in this directory.
Additionally, a Schema to verify the contents of the `settings.json`
file is defined in the [settings_schema.json](./settings_schema.json) file.
This schema is actually used during settings generation prior to
attempting to parse the contents of the `settings.json` file.


## Dependencies

In order to generate the settings content, you will need to install
Python3 and then install the appropriate "jsonschema" package.

```bash
pip install jsonschema
```

## Generating the contents

Once all dependencies are installed, simply execute the
[generate_settings.py](./generate_settings.py) Python
script in this folder by calling:

```bash
python3 generate_settings.py
```

This will update the settings in the following locations:

 - [layer/json/VkLayer_gfxreconstruct.json.in](../layer/json/VkLayer_gfxreconstruct.json.in)
 - [layer/vk_layer_settings.txt](../layer/vk_layer_settings.txt)


## Setting File Format

Settings are defined using a JSON format similar to that used by
the [VkConfig](https://github.com/LunarG/VulkanTools/tree/main/vkconfig_gui).
From now on, all new settings should be added to the `settings.json` file
in the current folder which will then place the appropriate sections in
the appropriate files during generation.

Here are a couple of examples for settings in the `settings.json` file:

```json
        {
            "key": "screenshot_dir",
            "label": "Screenshot Directory",
            "description": "Path to use when saving generated screenshots to the system.",
            "tools" : [ "CAPTURE" ],
            "parent" : {
                "key" : "screenshot"
            },
            "type": {
                "primitive": "SAVE_FOLDER",
                "default": ""
            }
        },
        {
            "key": "screenshot_frames",
            "label": "Screenshot Specific Frames",
            "description": "Specify one or more comma-separated frame ranges to screenshot. Each range will be written to its own file. A frame range can be specified as a single value, to specify a single frame to capture, or as two hyphenated values, to specify the first and last frame to capture. Frame ranges should be specified in ascending order and cannot overlap. Note that frame numbering is 1-based (i.e. the first frame is frame 1).",
            "tools" : [ "CAPTURE" ],
            "parent" : {
                "key" : "screenshot"
            },
            "type": {
                "primitive": "STRING",
                "default": ""
            }
        },
        {
            "key": "skip_threads_with_invalid_data",
            "label": "Skip Threads With Invalid Data",
            "description": "[OpenXR Only] When a thread is encountered which contains data that is unexpected, skip the data and mark the thread as skippable.  This is important especially in OpenXR where other API commands (such as Vulkan) may be generated inside of the OpenXR commands, but may still be referenced in some fashion outside of the OpenXR commands.  This results in issues during replay.  So, this option prevents those commands, and the threads containing those commands from being recorded to the capture file.",
            "tools" : [ "CAPTURE" ],
            "apis" : [ "OPENXR" ],
            "type": {
                "primitive": "BOOL",
                "default": false
            }
        }
```

The main components are:
 * Key
 * Label
 * Description
 * Type

Additional information may also be defined

### Key

The "key" field is used to identify this property in a unique way
and should be formatted as a lower-snake-case variable name.
It is used to generate the name of the corresponding environment
variable as well as the name of the Android property used to
set the corresponding setting.

The key **must not** have spaces.

For example:

```json
 "key" : "my_new_setting",
 ```

### Label

The "label" is to be formatted as a short description of the functionality
enabled by this setting.
It may be used as a label for the option when/if it shows up in
the VkConfig GUI section for options related to GFXReconstruct.

For example:

```json
 "label" : "My New Setting To Rule Them All",
 ```

### Description

The "description" is used to provide a detailed description of what the
setting is intended to do.
It **should not** include a statement about what is default (that is code
generated into the appropriate places).
This detailed description may be used for hover-over text dialogs
for the option when inside of VkConfig.

For example:

```json
 "description" : "A setting like the ring to rule all, but this setting is better than that.",
 ```

### Type

The "type" object contains details about the primitive type as well as potentially
default values this setting may have.

The primary data type for this setting is defined as a key within the "type" object
labeled `primitive`.

Supported Primitive types include:
- BOOL : Standard boolean type (true/false)
- ENUM : An enumeration type, requires additional FLAG definitions
- FLOAT : Standard float type
- GROUP : This is really a group container type with one or more children
- INT : Standard int type
- LIST : A list of items (usually a string)
- SAVE_FILE : the type is a file that is used to save results somewhere
- SAVE_FOLDER : the type is a folder that will be used to generate data to
- STRING : Standard string type

#### Default

The "default" key is optional and defines what the default value is.
It's value must correspond to the stated `primitive` type.

This is NOT a valid field if `primitive` type is "GROUP"

#### Enumerations

If `primitive` type is "ENUM" then the type data must also include definitions
of the valid elements for the enumeration:

For example:

```json
            "type": {
                "primitive": "ENUM",
                "flags": [
                    {
                        "key": "BMP",
                        "label": "BMP",787acc6470f35f520a0bc25a0efff0469102a2fe
                        "description": "Bitmap File Format."
                    },
                    {
                        "key": "PNG",
                        "label": "PNG",
                        "description": "Portable Network Graphics Format."
                    }
                ],
                "default": "BMP"
            }
```

### Additional Fields

The following are optional fields that may be used to help define and
organize the settings.

#### Tools

"tools" is a list type that identifies all the tools this setting is valid for.
If it is not set, then it implies that the setting is valid for all tools.

Examples of a tool might be "CAPTURE" for the capture layer, or "REPLAY"
for the replay tool.

#### APIs

"apis" is a list type that identifies all the APIs this setting is valid for.
If it is not set, then it implies that the setting is valid for all APIs
GFXReconstruct supports.

Examples of a tool might be "D3D12", "VULKAN" or "OPENXR.

#### Parent

Some settings may be related to another setting, such as the setting is
only valid if another setting has a certain value.
Or, the setting may want to be nested in a GUI underneath another setting
or in a GROUP.
To do this, use the "parent" object.

Here is an example parent object definition:

```json
    "parent" : {
        "key" : "rv_annotation_experimental",
        "value" : true
    },
```

In this case, "key" is the "key" of the parent setting.
"value" is optional, but if defined, it indicates that this setting is
only valid if the parent setting is set to the defined value.

#### Additional Dependencies

Sometimes, settings may be related to other settings.
These other settings may not be a parent, but perhaps
a sibling that can also affect a settings behavior.
To define them use an "additional_dependencies" object defined
in an array.

For example:

```json
    "additional_dependencies" : [
        {
            "key": "page_guard_external_memory",
            "value": false
        }
    ],
```

These fields are similar to "parent" and mean the same thing.
However, you can see that this allows you to define multiple
additional settings that are related to this setting.