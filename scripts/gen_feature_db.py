import sys
import os
import subprocess
import platform
import json
import urllib.request
import xml.etree.ElementTree as ET

script_name = os.path.basename(__file__)

#Returns true if running on Windows, false otherwise
def is_windows():
    '''
    Check if the system is Windows
    '''
    return 'windows' == platform.system().lower()

# Print usage instructions
def usage():
    print("Usage for %s will go here." % script_name)
    #print("gfxrecon-optimize-renamed.py - Helper script to perform automatic renaming of gfxrecon-optimize.exe prior to optimization.")
    #print()
    #print("Usage:")
    #print("  gfxrecon-optimize-renamed.py <input-file> <output-file> [--dxr] [--d3d12-pso-removal]")
    #print()
    #print("Required arguments:")
    #print("  <input-file>          The path to input GFXReconstruct capture file to be processed.")
    #print("  <output-file>         The path to output GFXReconstruct capture file to be created.")    
    #print()
    #print("Optional arguments:")    
    #print("  --d3d12-pso-removal   D3D12-only: Remove creation of unreferenced PSOs.")
    #print("  --dxr                 D3D12-only: Optimize for DXR replay.")
    #print("  --gpu                 D3D12-only: Use the specified device for the optimizer replay, where index is the zero-based index")
    #print("                        to the array of physical devices returned by vkEnumeratePhysicalDevices or The optimizer replay")
    #print("                        may fail if the specified device is not compatible with theIDXGIFactory1::EnumAdapters1.")
    #print("                        The optimizer replay may fail if the specified device is not compatible with the original")
    #print("                        capture devices.")
    #print()    
    #print("Note: running without optional arguments will instruct the optimizer to detect API and run all available optimizations.")
    #print()
    #print("Example manual usage (D3D12):")
    #print("  gfxrecon-optimize-renamed.py my_capture.gfxr my_capture_dxr_optimized.gfxr --dxr")
    #print("  gfxrecon-optimize-renamed.py my_capture.gfxr my_capture_pso_optimized.gfxr --d3d12-pso-removal")
    #print()
    #print("Example automatic usage (D3D12 + Vulkan):")
    #print("  gfxrecon-optimize-renamed.py my_capture.gfxr my_capture_optimized.gfxr") 
    #print()

if __name__ == "__main__":

    #Early exit if we're missing our arguments
    if len(sys.argv) < 2:
        usage()
        print("Error: missing path to capture")
        exit(-1)
    capture_path = sys.argv[1]

    #Parse vk.xml
    vk_xml_path = "external/Vulkan-Headers/registry/vk.xml"
    vk_xml_root = ET.parse(vk_xml_path).getroot()
    commands_root = vk_xml_root.find("commands")

    #Collect the names of all vk functions
    print("Collection vk function names...")
    all_vk_funcs = []
    for c in commands_root:
        if "alias" not in c.attrib:
            fn_name = c.find("proto").find("name").text
            all_vk_funcs.append(fn_name)


    #Get name of gfxrecon-convert binary
    GFXR_CONVERT_NAME = "gfxrecon-convert"
    if is_windows():
        GFXR_CONVERT_NAME += ".exe"

    convert_tool_path = os.path.join(os.path.dirname(__file__), GFXR_CONVERT_NAME)

    print("Running %s..." % GFXR_CONVERT_NAME)
    #cmd = convert_tool_path + " " + capture_path
    cmd = [convert_tool_path, capture_path]
    output = subprocess.check_output(cmd).decode('utf-8',errors='ignore')
    print(output)

    #Load the json capture into a python dictionary
    json_capture_path = os.path.splitext(capture_path)[0] + ".json"
    with open(json_capture_path) as f:
        json_text = f.read()
    capture_json = json.loads(json_text)

    #Iterate over all blocks and extract the function names
    capture_funcs = set()
    for block in capture_json:
        if "function" in block:
            capture_funcs.add(block["function"]["name"])

    for fn_name in all_vk_funcs:
        if fn_name in capture_funcs:
            print("%s is accounted for" % fn_name)

    print("Done!")