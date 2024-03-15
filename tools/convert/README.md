# Convert

The `gfxrecon-convert` tool converts a capture file into a series of JSON
documents, one per line following the
[JSON Lines standard](https://jsonlines.org/).
The text output is written by default to a .jsonl file in the directory of the
specified GFXReconstruct capture file. Use `--output` to override the default
filename for the output.


```text
gfxrecon-convert - A tool to convert GFXReconstruct capture files to text.

Usage:
  gfxrecon-convert [-h | --help] [--version] <file>

Required arguments:
  <file>                Path to the GFXReconstruct capture file to be converted
                        to text.

Optional arguments:
  -h                    Print usage information and exit (same as --help).
  --version             Print version information and exit.
  --output filename     'stdout' or a path to a file to write JSON output
                        to. Default is the input filepath with "gfxr" replaced
                        by "jsonl".
  --format <format>     JSON format to write.
           json         Standard JSON format (indented)
           jsonl        JSON lines format (every object in a single line)
  --include-binaries    Dump binaries from Vulkan traces in a separate file with an unique name. The main JSON file
                        will include a reference with the file name. The binary files are dumped in a subdirectory
  --expand-flags        Print flags values from Vulkan traces with its correspondent symbolic representation. Otherwise,
                        the flags are printed as hexadecimal value.
  --file-per-frame      Creates a new file for every frame processed. Frame number is added as a suffix
                        to the output file name.
  --no-debug-popup      Disable the 'Abort, Retry, Ignore' message box
                        displayed when abort() is called (Windows debug only).
```


The JSON document on each line is designed to be parsed by tools such as simple
Python scripts as well as being useful for inspecting by eye after pretty
printing, for example by piping through a command-line tool such as
[`jq`](https://stedolan.github.io/jq/).
For these post-processing use cases, `gfxrecon-convert` can be used to stream
from binary captures directly, without
having to save the intermediate JSON files to storage.
Because each JSON object is on its own line, line oriented tools such as
grep, sed, head, and split can be applied ahead of JSON-aware ones which
are heavier-weight to reduce their workload on large captures.


## JSON Structure

The tool's output is an ordered list of strings, one per line, each line a valid
JSON document (JSON Lines). Below are the first few lines from a capture of vkcube, truncated to 200 columns.

```json
{"header":{"source-path":"vkcube.f1.gfxr","json-version":"0.8.0","gfxrecon-version":"0.9.15-dev","vulkan-version":"1.3.224"}}
{"index":0,"vkFunc":{"name":"vkCreateInstance","return":"VK_SUCCESS","args":{"pCreateInfo":{"sType":"VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO","pNext":null,"flags":1,"pApplicationInfo":{"sType":"VK_S...
{"index":1,"vkFunc":{"name":"vkEnumeratePhysicalDevices","return":"VK_SUCCESS","args":{"instance":1,"pPhysicalDeviceCount":3,"pPhysicalDevices":null}}}
{"index":2,"vkFunc":{"name":"vkEnumeratePhysicalDevices","return":"VK_SUCCESS","args":{"instance":1,"pPhysicalDeviceCount":3,"pPhysicalDevices":[2,3,4]}}}
{"index":3,"vkFunc":{"name":"vkGetPhysicalDeviceProperties","args":{"physicalDevice":2,"pProperties":{"apiVersion":4206786,"driverVersion":2140487808,"vendorID":4318,"deviceID":9568,"deviceType":"V...
{"index":4,"vkFunc":{"name":"vkGetPhysicalDeviceProperties","args":{"physicalDevice":3,"pProperties":{"apiVersion":4206796,"driverVersion":92274693,"vendorID":32902,"deviceID":18086,"deviceType":"V...
{"index":5,"vkFunc":{"name":"vkGetPhysicalDeviceProperties","args":{"physicalDevice":4,"pProperties":{"apiVersion":4202700,"driverVersion":1,"vendorID":65541,"deviceID":0,"deviceType":"VK_PHYSICAL_...
{"index":6,"vkFunc":{"name":"vkEnumeratePhysicalDevices","return":"VK_SUCCESS","args":{"instance":1,"pPhysicalDeviceCount":3,"pPhysicalDevices":null}}}
{"index":7,"vkFunc":{"name":"vkEnumeratePhysicalDevices","return":"VK_SUCCESS","args":{"instance":1,"pPhysicalDeviceCount":3,"pPhysicalDevices":[2,3,4]}}}

```

The file begins with a header object containing some metadata, followed by a
series of objects representing the sequence of Vulkan calls stored in the
capture. Below are some examples generated from the same capture of `vkcube`
listed above but pretty-printed with
`gfxrecon-convert --output stdout vkcube.f1.gfxr | jq`.

The first line is a header identifying the source capture file,
the version of the file format,
the version of GFXReconstruct used to generate the file,
and the version of the Vulkan headers used to build that GFXReconstruct version.
This header may be expanded in the future but these fields will remain.

```json
{
  "header": {
    "source-path": "vkcube.f1.gfxr",
    "json-version": "0.8.0",
    "gfxrecon-version": "0.9.15-dev",
    "vulkan-version": "1.3.224"
  }
}
```

The first Vulkan function of the capture follows the header.
Of note are the fields `"vkFunc"` which identifies the line as Vulkan function
call, and `"index"` which is a monotonically increasing positive integer
representing the position of the call in the sequence recorded in the capture.

```json
{
  "index": 0,
  "vkFunc": {
    "name": "vkCreateInstance",
    "return": "VK_SUCCESS",
    "args": {
      "pCreateInfo": {
        "sType": "VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO",
        "pNext": null,
        "flags": 1,
        "pApplicationInfo": {
          "sType": "VK_STRUCTURE_TYPE_APPLICATION_INFO",
          "pNext": null,
          "pApplicationName": "vkcube",
          "applicationVersion": 0,
          "pEngineName": "vkcube",
          "engineVersion": 0,
          "apiVersion": 4194304
        },
        "enabledLayerCount": 0,
        "ppEnabledLayerNames": null,
        "enabledExtensionCount": 4,
        "ppEnabledExtensionNames": [
          "VK_KHR_get_physical_device_properties2",
          "VK_KHR_surface",
          "VK_KHR_xcb_surface",
          "VK_KHR_portability_enumeration"
        ]
      },
      "pAllocator": null,
      "pInstance": 1
    }
  }
}

```

### Type Mapping of Values

Values in the file such as function arguments, function return values, and
structure members are mapped to the following JSON representations.

#### Scalar Numeric Types

`int`, `float`, `double`, and related types and aliases are represented with
the JSON number type.
The output is additionally constrained to match the underlying C type, so a
value like `1.1` will never be output where the C type is an integer, despite
that being a valid JSON number.

#### Handles

Handles in capture files are represented by integers.
I.e., the _ith_ handle allocation will be stored as the integer _i_, counting
from one.
Convert shows those integers as the JSON number type, constrained to
be positive integers.

#### Strings

`const char*` strings from the C-API are represented as JSON strings.

#### Enumerations

Single enumerator values (as opposed to the result of ORing together several
flags defined by an enumeration) such as `VkResult`'s `VK_SUCCESS` and
`VK_INCOMPLETE` are represented by JSON strings holding the exact character
sequence used in the C-API enumerator, so `"VK_SUCCESS"` and `"VK_INCOMPLETE"`
in the preceding examples.

#### Masks / Flag Sets

Theses are currently output as JSON numbers with their bit patterns
interpreted as an unsigned decimal integer.
Tools written now should test whether masks are represented as JSON numbers and
fail gracefully if not as some changes are anticipated to this aspect of the
JSON Lines file format.

#### Void Pointers

Pointers to void and pointers to pointers to void are represented as strings
with the hexadecimal integer value of the address in the capture file encoded
within them. For example `"0x55f5aa64d2f0"`.

#### Structures

Structures are represented as JSON objects.
The names of their fields become element keys and their values are translated
as described for any value in this section and the resulting JSON text is used
as element values.

#### Pointers to Structures

Where a pointer is to a single struct, as is the case for `pCreateInfo` and
`pNext` struct pointers, the representation of the pointed-to type is nested
within the JSON file at that point.
If the pointer is null, the json type `null` will be used.
The output does not preserve the identity of pointed-to structs.
If the same struct with the same values was pointed-to a thousand times by an
application during capture, the JSON representation will show its full,
recursively expanded structure at each of those points of use.
There is no mechanism to refer back to previously defined sub-trees of structs.

#### Arrays

Arrays, whether embedded directly in a struct, or pointed-to, are represented as
a JSON array type.
Each element of an array is represented by converting its type according to the
appropriate rules.
When a variable length array is represented in the C-API by adjacent
`{count, pointer}` arguments or members, the JSON representation retains
the explicit `count` even though that is duplicated in the length of the
JSON array which inherits the name of the pointer in the pair.
If an application assigns a null pointer to a pointer-to-array argument or
struct member, it will be represented in the JSON as the `null` type.
If a non-zero address is assigned to a pointer but a zero count is used,
the representation will be an empty array: `[]`.

### Top Level Structure

All current and future lines have a top-level JSON object with a key that
identifies the type of the line and a value that is a nested object holding
the data for the line, possibly in further nested structure.
The currently-defined three keys are `"header"`, `"vkFunc"`, and `"meta"`.
A line can hold _exactly one of_ a nested `"header"`, nested `"vkFunc"`, or nested `"meta"`, not more.
A tool can work out what kind of JSON document each line contains by checking
for the presence of the keys in the top-level object.
In pseudocode that could look something like this:

```
for line in input_lines:
  doc = json.parse(line)
  if doc.contains("vkFunc"):
      process Vulkan API Call document
  else if doc.contains("header"):
      process header document
  else if doc.contains("meta"):
      process meta command block
  else:
      warning: unknown JSON line
```

### Header Objects

All values of a header are strings.

* `"source-path"`: The path to the gfxr file which was the source for
  conversion. The exact string passed to the application is stored, whether
  it is a relative or absolute path.
* `"json-version"`: The version of the Convert JSON Lines file format used by
  the current file.
* `"gfxrecon-version"`: The release or build of GFXReconstruct used to do the
  conversion of the file.
* `"vulkan-version"`: The version of the Vulkan headers that the GFXReconstruct
  used for conversion was built against.

### Meta Objects
Meta command objects contain `"index"` at the top level, which is a
JSON number representing the position of the call in the sequence of
successfully-decoded blocks in the original binary capture file,
and a nested object under the key `"meta"` which contains the data captured
from a meta command.

Examples of meta commands include host memory allocation,
filling buffers and images, and resizing the application window. 

### vkFunc Objects

Vulkan function objects contain `"index"` at the top level, which is a
JSON number representing the position of the call in the sequence of
successfully-decoded blocks in the original binary capture file,
and a nested object under the key `"vkFunc"` which contains the data captured
from a Vulkan call.

```json
{
  "index": 0,
  "vkFunc": {
    "name": "vkCreateInstance",
    "return": "VK_SUCCESS",
    "args": {
      ... details omitted ...
    }
  }
}
```

When debugging during replay, the value of the `"index"` field can be matched
to the value of the GFXReconstruct `FileProcessor::block_index_` member
variable.
This allows a developer to see the history of calls in JSON form up to the point
of interest in their debugger.

Within the nested object are several elements.

* `"name"`: A JSON string which identifies the function that was called
  with the name defined in the C-API.
* `"return"`: An optional element whose value represents what was returned from Vulkan at capture time translated to JSON according to the C-API type as detailed above in section _Type Mapping of Values_.
* `"args"`: A nested object with a set of key:value pairs, one for each
  argument passed to the function.
  The arguments are output in the same order as defined by the C-API although
  JSON tools may reorder them arbitrarily after further processing.
  The value of each element is translated from the corresponding argument in the
  capture file as detailed above in section _Type Mapping of Values_.

#### Function Arguments

Arguments are delivered in a nested JSON object with the key `"args"`.
The key for each field of the object is the name it has in the Vulkan C-API.
The value of a field could be any JSON type, constrained to be appropriate to
the C argument's type as detailed above in section _Type Mapping of Values_.

In this example of `"vkUnmapMemory"`, the values are the integer mappings of
handles as stored in the capture file.

```json
    "args": {
      "device": 6,
      "memory": 27
    }
```

A more complex example is illustrated by `vkCmdSetScissor`.
Here we see the pointer to a variable number of entries from the C-API,
`pScissors`, represented as a nested JSON array.
Each element in that array is a JSON object for the corresponding C struct.

```json
"args": {
    "commandBuffer": 43,
    "firstScissor": 0,
    "scissorCount": 1,
    "pScissors": [
      {
        "offset": {
          "x": 0,
          "y": 0
        },
        "extent": {
          "width": 256,
          "height": 192
        }
      }
    ]
  }
```

### JSON Lines to JSON

Because every line is a separate JSON object, the output as a whole is not
valid JSON.
It can, however, be trivially transformed into a valid JSON array by
appending a comma to each line and topping and tailing with square brackets.


### Caveats and Gotchas

#### 64 Bit Integers
64 bit integers in the capture are output as the JSON number type.
Parsers which strictly adhere to the standard should have no problem with that,
including some fast native parsers like
[RapidJSON](https://github.com/Tencent/rapidjson),
but some may choose to represent all numbers as 64 bit double precision floating
point. This representation will not be able to represent all possible 64 bit
integers.
Javascript JSON parsers have been known to do that, as can be confirmed with the
following Javascript snippet which fails to print `2^60` correctly.

```javascript
const json = '{"result":true, "count":1152921504606846976}';
const obj = JSON.parse(json);
console.log(obj.count);
// Expected output: 1152921504606846976
// Actual output:   1152921504606847000
```

#### Omitted Values

Captures don't store output structs or values for calls that failed, so some
structs will be `null` (Python `None`) even though the app passed in something.


## Recipes

Once the JSON has been emitted, the the next step is to do something with it.
Below are some example usages of the output, tested in Bash.
These are presented using a file called `vkcube.f1.gfxr`, a capture of the first
frame of `vkcube`, and `vkcube.f1-10.gfxr`, a capture of its first ten frames,
which you can easily reproduce locally using the GFXReconstruct capture layer.

When composing pipelines for interactive use it is usually worthwhile to have
each tool use unbuffered IO so results make it through to printing to the
console as soon as possible.
The switches for that are `--line-buffered` for `grep` and `--unbuffered` for
`jq`.

### Grep for Functions

We can limit output to functions of particular interest easily with a pipeline.

```bash
gfxrecon-convert --output stdout vkcube.f1-10.gfxr | fgrep --line-buffered "vkQueuePresent"
```

We use `--line-buffered` to keep results flowing.
As soon as a new JSON Lines line is matched, it is passed to the next stage,
in this case being displayed.
In this example we see the `pImageIndices` index being cycled through:

```json
{"index":137,"vkFunc":{"name":"vkQueuePresentKHR","return":"VK_SUCCESS","args":{"queue":7,"pPresentInfo":{"sType":"VK_STRUCTURE_TYPE_PRESENT_INFO_KHR","pNext":null,"waitSemaphoreCount":1,"pWaitSemaphores":[10],"swapchainCount":1,"pSwapchains":[14],"pImageIndices":[0],"pResults":null}}}}
{"index":142,"vkFunc":{"name":"vkQueuePresentKHR","return":"VK_SUCCESS","args":{"queue":7,"pPresentInfo":{"sType":"VK_STRUCTURE_TYPE_PRESENT_INFO_KHR","pNext":null,"waitSemaphoreCount":1,"pWaitSemaphores":[13],"swapchainCount":1,"pSwapchains":[14],"pImageIndices":[1],"pResults":null}}}}
{"index":147,"vkFunc":{"name":"vkQueuePresentKHR","return":"VK_SUCCESS","args":{"queue":7,"pPresentInfo":{"sType":"VK_STRUCTURE_TYPE_PRESENT_INFO_KHR","pNext":null,"waitSemaphoreCount":1,"pWaitSemaphores":[10],"swapchainCount":1,"pSwapchains":[14],"pImageIndices":[2],"pResults":null}}}}
{"index":152,"vkFunc":{"name":"vkQueuePresentKHR","return":"VK_SUCCESS","args":{"queue":7,"pPresentInfo":{"sType":"VK_STRUCTURE_TYPE_PRESENT_INFO_KHR","pNext":null,"waitSemaphoreCount":1,"pWaitSemaphores":[13],"swapchainCount":1,"pSwapchains":[14],"pImageIndices":[0],"pResults":null}}}}
{"index":157,"vkFunc":{"name":"vkQueuePresentKHR","return":"VK_SUCCESS","args":{"queue":7,"pPresentInfo":{"sType":"VK_STRUCTURE_TYPE_PRESENT_INFO_KHR","pNext":null,"waitSemaphoreCount":1,"pWaitSemaphores":[10],"swapchainCount":1,"pSwapchains":[14],"pImageIndices":[1],"pResults":null}}}}
{"index":162,"vkFunc":{"name":"vkQueuePresentKHR","return":"VK_SUCCESS","args":{"queue":7,"pPresentInfo":{"sType":"VK_STRUCTURE_TYPE_PRESENT_INFO_KHR","pNext":null,"waitSemaphoreCount":1,"pWaitSemaphores":[13],"swapchainCount":1,"pSwapchains":[14],"pImageIndices":[2],"pResults":null}}}}
...
```

### Pretty Print JSON

There are many tools that will pretty-print JSON Lines.
A common one on many platforms, written in C, and with no dependencies is `jq`.
Here we output to stdout and pipe through them to `jq`:

```bash
gfxrecon-convert --output stdout vkcube.f1.gfxr | jq
```

The result (abbreviated below) is nicely formatted for human comprehension and preserves the
ordering of function arguments, to match the C-API.

```json

{
  "index": 102,
  "vkFunc": {
    "name": "vkCmdBindPipeline",
    "args": {
      "commandBuffer": 43,
      "pipelineBindPoint": "VK_PIPELINE_BIND_POINT_GRAPHICS",
      "pipeline": 42
    }
  }
}
{
  "index": 107,
  "vkFunc": {
    "name": "vkCmdEndRenderPass",
    "args": {
      "commandBuffer": 43
    }
  }
}
...
```

### Pretty Print YAML

The [yq](https://github.com/mikefarah/yq) YAML processor can give a cleaner
pretty print.
We pipe our output into it after adding a line with the YAML separator `---`
between each JSON line.

```bash
gfxrecon-convert --output stdout vkcube.f1.gfxr | sed -s "s/$/\n---\n/" | yq -P
```

The same excerpt as shown for the JSON pretty print above:

```yaml
index: 102
vkFunc:
  name: vkCmdBindPipeline
  args:
    commandBuffer: 43
    pipelineBindPoint: VK_PIPELINE_BIND_POINT_GRAPHICS
    pipeline: 42
---
index: 107
vkFunc:
  name: vkCmdEndRenderPass
  args:
    commandBuffer: 43
---
```

### List of Functions Used in a Capture

One useful thing to do with a capture is to generate a summary of the Vulkan
functions used within it.
Given a large set of diverse captures, generating this summary once for each
capture ahead of time allows later recursive greps to find all the files that
use a particular function rapidly.
This would be useful when collecting a set of existing traces to reproduce a bug
somewhere in the graphics stack for which that function was implicated.

```bash
gfxrecon-convert --output stdout vkcube.f1.gfxr | sed "s/.*\"name\":\"vk\([^\"]*\).*/vk\1/" | sort | uniq | egrep -v "{\"header\""
```
Output:
```
vkAcquireNextImageKHR
vkAllocateCommandBuffers
vkAllocateDescriptorSets
vkAllocateMemory
vkBeginCommandBuffer
vkBindBufferMemory
vkBindImageMemory
...
vkUnmapMemory
vkUpdateDescriptorSets
vkWaitForFences
```

Splitting the `sed` command in two should execute several times faster:

```bash
gfxrecon-convert --output stdout vkcube.f1.gfxr | sed "s/.*\"name\":\"vk/vk/" | sed "s/\",.*//" | sort | uniq | egrep -v "{\"header\""
```

For large captures, screening out runs of duplicate function names before the sort can be a little faster still:

```bash
gfxrecon-convert --output stdout vkcube.f1.gfxr | sed "s/.*\"name\":\"vk/vk/" | sed "s/\",.*//" | uniq | sort | uniq | egrep -v "{\"header\""
```

### Transform Arguments to Positional Array Form

While the JSON format for functions represents arguments as a JSON object,
it is straightforward to transform that to an array that bakes in the argument
ordering.
This substitution in `jq` turns each argument into its own JSON object with name
and value fields, and orders them all in an array.

```bash
gfxrecon-convert --output stdout vkcube.f1.gfxr | egrep -v "^{\"header\":{\"" | jq '.vkFunc.args = (.vkFunc.args | to_entries | map_values({"name":(.key), "value":(.value)}))'
```

```json
{
  "index": 76,
  "vkFunc": {
    "name": "vkMapMemory",
    "return": "VK_SUCCESS",
    "args": [
      {
        "name": "device",
        "value": 6
      },
      {
        "name": "memory",
        "value": 35
      },
      {
        "name": "offset",
        "value": 0
      },
      {
        "name": "size",
        "value": 18446744073709552000
      },
      {
        "name": "flags",
        "value": 0
      },
      {
        "name": "ppData",
        "value": "0x55f5aa64d380"
      }
    ]
  }
}
```

This can be stripped-down to just the values:

```bash
gfxrecon-convert --output stdout vkcube.f1.gfxr | egrep -v "^{\"header\":{\"" | jq -c '.vkFunc.args = (.vkFunc.args | to_entries | map_values(.value))'
```

Note the `-c` option to `jq` preserves the JSON Lines output rather than
pretty-printing indented JSON.

```json
{"index":72,"vkFunc":{"name":"vkBindBufferMemory","return":"VK_SUCCESS","args":[6,32,33,0]}}
{"index":73,"vkFunc":{"name":"vkCreateBuffer","return":"VK_SUCCESS","args":[6,{"sType":"VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO","pNext":null,"flags":0,"size":1216,"usage":16,"sharingMode":"VK_SHARING_MODE_EXCLUSIVE","queueFamilyIndexCount":0,"pQueueFamilyIndices":null},null,34]}}
{"index":74,"vkFunc":{"name":"vkGetBufferMemoryRequirements","args":[6,34,{"size":1280,"alignment":256,"memoryTypeBits":1921}]}}
{"index":75,"vkFunc":{"name":"vkAllocateMemory","return":"VK_SUCCESS","args":[6,{"sType":"VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO","pNext":null,"allocationSize":1280,"memoryTypeIndex":8},null,35]}}
{"index":76,"vkFunc":{"name":"vkMapMemory","return":"VK_SUCCESS","args":[6,35,0,18446744073709552000,0,"0x55f5aa64d380"]}}
{"index":77,"vkFunc":{"name":"vkBindBufferMemory","return":"VK_SUCCESS","args":[6,34,35,0]}}
```


### All Unique Argument Names

This pipeline summarizes the names of function arguments and struct member names
recursively included from arguments into a json array on each line.
These might be useful to keep beside a set of multi-gigabyte binary traces to
allow fast grepping when looking for traces that use particular named arguments.

```bash
gfxrecon-convert --output stdout vkcube.f1.gfxr | jq  -c "[.. | objects | keys[]] | unique" | sed "s/\"args\",//" | sed "s/\"index\",//" | sed "s/\"name\",//" | sed "s/\"return\",//" | sed "s/,\"vkFunc\"//" | sort | uniq
```

Output:

```json
...
["alignment","buffer","device","memoryTypeBits","pMemoryRequirements","size"]
["alignment","device","image","memoryTypeBits","pMemoryRequirements","size"]
["allocationSize","device","memoryTypeIndex","pAllocateInfo","pAllocator","pMemory","pNext","sType"]
...
```

### Truncate at Match
When looking at a multi-gigabyte capture file, it can be useful to limit the
output of conversion, ending it early, for example to concentrate on the first
frame.
A little Python script can enable that.

`stop-after-match.py`:
```python
#! /usr/bin/python3
import sys
import argparse
parser = argparse.ArgumentParser(description='Pass through input until match')
parser.add_argument('match', help='The string to stop after seeing on a line')
args = parser.parse_args()
match = args.match

for l in sys.stdin:
    # Print out long lines:
    print(l,  end = '', flush=True)
    if match in l:
        exit(0)
```
As an example, let's use that to see all the submits in the first frame:

```bash
gfxrecon-convert --output stdout bigcapture.gfxr | stop-after-match.py vkQueuePresent | fgrep --line-buffered vkQueueSubmit
```

For one particular 33GB capture, the above pipeline runs in around a second on a
laptop because conversion ends at the match.
In the output we see 301 single command buffer single submits to get to the first
frame which would give the developer inspiration to look into merging some of
them if possible.

```json
{"index":168,"vkFunc":{"name":"vkQueueSubmit","return":"VK_SUCCESS","args":{"queue":68,"submitCount":1,"pSubmits":[{"sType":"VK_STRUCTURE_TYPE_SUBMIT_INFO","pNext":null,"waitSemaphoreCount":0,"pWaitSemaphores":null,"pWaitDstStageMask":null,"commandBufferCount":1,"pCommandBuffers":[91],"signalSemaphoreCount":0,"pSignalSemaphores":null}],"fence":89}}}
{"index":337,"vkFunc":{"name":"vkQueueSubmit","return":"VK_SUCCESS","args":{"queue":96,"submitCount":1,"pSubmits":[{"sType":"VK_STRUCTURE_TYPE_SUBMIT_INFO","pNext":null,"waitSemaphoreCount":0,"pWaitSemaphores":null,"pWaitDstStageMask":null,"commandBufferCount":1,"pCommandBuffers":[98],"signalSemaphoreCount":0,"pSignalSemaphores":null}],"fence":99}}}
... skip hundreds of similar calls ...
{"index":6580,"vkFunc":{"name":"vkQueueSubmit","return":"VK_SUCCESS","args":{"queue":96,"submitCount":1,"pSubmits":[{"sType":"VK_STRUCTURE_TYPE_SUBMIT_INFO","pNext":null,"waitSemaphoreCount":0,"pWaitSemaphores":null,"pWaitDstStageMask":null,"commandBufferCount":1,"pCommandBuffers":[128],"signalSemaphoreCount":0,"pSignalSemaphores":null}],"fence":129}}}
{"index":6585,"vkFunc":{"name":"vkQueueSubmit","return":"VK_SUCCESS","args":{"queue":96,"submitCount":1,"pSubmits":[{"sType":"VK_STRUCTURE_TYPE_SUBMIT_INFO","pNext":null,"waitSemaphoreCount":0,"pWaitSemaphores":null,"pWaitDstStageMask":null,"commandBufferCount":1,"pCommandBuffers":[131],"signalSemaphoreCount":0,"pSignalSemaphores":null}],"fence":132}}}
{"index":6755,"vkFunc":{"name":"vkQueueSubmit","return":"VK_SUCCESS","args":{"queue":68,"submitCount":1,"pSubmits":[{"sType":"VK_STRUCTURE_TYPE_SUBMIT_INFO","pNext":null,"waitSemaphoreCount":0,"pWaitSemaphores":null,"pWaitDstStageMask":null,"commandBufferCount":2,"pCommandBuffers":[1894,1895],"signalSemaphoreCount":0,"pSignalSemaphores":null}],"fence":1896}}}
{"index":6757,"vkFunc":{"name":"vkQueueSubmit","return":"VK_SUCCESS","args":{"queue":68,"submitCount":1,"pSubmits":[{"sType":"VK_STRUCTURE_TYPE_SUBMIT_INFO","pNext":null,"waitSemaphoreCount":0,"pWaitSemaphores":null,"pWaitDstStageMask":null,"commandBufferCount":2,"pCommandBuffers":[1912,1913],"signalSemaphoreCount":0,"pSignalSemaphores":null}],"fence":1897}}}
{"index":6812,"vkFunc":{"name":"vkQueueSubmit","return":"VK_SUCCESS","args":{"queue":68,"submitCount":1,"pSubmits":[{"sType":"VK_STRUCTURE_TYPE_SUBMIT_INFO","pNext":null,"waitSemaphoreCount":0,"pWaitSemaphores":null,"pWaitDstStageMask":null,"commandBufferCount":1,"pCommandBuffers":[2120],"signalSemaphoreCount":0,"pSignalSemaphores":null}],"fence":"VK_NULL_HANDLE"}}}
{"index":6814,"vkFunc":{"name":"vkQueueSubmit","return":"VK_SUCCESS","args":{"queue":68,"submitCount":1,"pSubmits":[{"sType":"VK_STRUCTURE_TYPE_SUBMIT_INFO","pNext":null,"waitSemaphoreCount":1,"pWaitSemaphores":[867],"pWaitDstStageMask":[65536],"commandBufferCount":1,"pCommandBuffers":[2167],"signalSemaphoreCount":1,"pSignalSemaphores":[878]}],"fence":877}}}
```

Similar line-oriented scripts could extend this idea to outputting the first n
frames or an arbitrary single frame without needing to parse the JSON.

## FAQ
* Where is the type information?
  * Type information is defined by the xml of the Vulkan specification.
    Applications using the format are required to derive type information from
    there when introspecting on the output or from their programmers' reading of
    the specification.
    Annotating every value with its type as done by some other tools such as the
    API Dump layer was a tradeoff not taken based on anticipated uses for this
    format.
* Can I rely on the ordering of `args` object `key:value` pairs?
  - Convert will output fields in the same order as they appear in the parameter
    lists of the corresponding C API.
    While that order is not guaranteed to be preserved by all JSON parsers,
    many do preserve it by default or can be configured to do so.
    The JSON module in Python can
    [use an `OrderedDict`](https://stackoverflow.com/a/6921760) for example.
    To bake the order in, args may be transformed into an array with `jq` as
    shown in the section
    [Transform Arguments to Positional Array Form](#transform-arguments-to-positional-array-form).
