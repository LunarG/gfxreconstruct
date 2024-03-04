import sys
import os
import subprocess
import json
import urllib.request

script_name = os.path.basename(__file__)
GFXR_CONVERT_NAME = "gfxrecon-convert.exe"
VK_XML_URL = "https://github.com/KhronosGroup/Vulkan-Docs/raw/main/xml/vk.xml"

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

    #Download current vk.xml
    (tmp_xml_path, _) = urllib.request.urlretrieve(VK_XML_URL)
    print(tmp_xml_path)

    capture_path = sys.argv[1]
    convert_tool_path = os.path.join(os.path.dirname(__file__), GFXR_CONVERT_NAME)

    print("Running %s..." % GFXR_CONVERT_NAME)
    cmd = convert_tool_path + " " + capture_path
    output = subprocess.check_output(cmd).decode('utf-8',errors='ignore')
    #output = subprocess.Popen(cmd, )
    print(output)



    print("Done!")