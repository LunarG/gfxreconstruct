#gen_feature_db.py
#Author: Nick Driscoll
#Intended to be executed from the root of the GFXR repo

import sys
import glob
import os
import subprocess
import platform
import json
import threading
import xml.etree.ElementTree as ET
from collections.abc import Iterable

#Taken manually from framework/format/format.h
META_COMMANDS = [
    "UnknownMetaDataType",
    "DisplayMessageCommand",
    "FillMemoryCommand",
    "ResizeWindowCommand",
    "SetSwapchainImageStateCommand",
    "BeginResourceInitCommand",
    "EndResourceInitCommand",
    "InitBufferCommand",
    "InitImageCommand",
    "CreateHardwareBufferCommand_deprecated",
    "DestroyHardwareBufferCommand",
    "SetDevicePropertiesCommand",
    "SetDeviceMemoryPropertiesCommand",
    "ResizeWindowCommand2",
    "SetOpaqueAddressCommand",
    "SetRayTracingShaderGroupHandlesCommand",
    "CreateHeapAllocationCommand",
    "InitSubresourceCommand",
    "ExeFileInfoCommand",
    "InitDx12AccelerationStructureCommand",
    "FillMemoryResourceValueCommand",
    "DxgiAdapterInfoCommand",
    "DriverInfoCommand",
    "Reserved23",
    "CreateHardwareBufferCommand",
    "Reserved25",
    "Dx12RuntimeInfoCommand",
    "ParentToChildDependency"
]

#Variables to collect all vk functions across all traces
capture_funcs = set()
capture_extensions = set()
capture_features = set()
capture_structs = set()
capture_metas = set()
capture_stypes = set()
#Locks for accessing the above variables
capture_funcs_lock = threading.Lock()
capture_extensions_lock = threading.Lock()
capture_features_lock = threading.Lock()
capture_structs_lock = threading.Lock()
capture_metas_lock = threading.Lock()
capture_stypes_lock = threading.Lock()

script_name = os.path.basename(__file__)

#Returns true if running on Windows, false otherwise
def is_windows():
    '''
    Check if the system is Windows
    '''
    return 'windows' == platform.system().lower()

# Print usage instructions
def usage():
    print(f"Usage: {script_name} <root traces directory>")

#Return a list of all sTypes inside a block
def gather_stypes(block):
    sTypes = set()

    if "sType" in block:
        sTypes.add(block["sType"])

    for key in block:
        if isinstance(block[key], Iterable):
            
            #This solution doesn't feel great
            try:
                sTypes.update(gather_stypes(block[key]))
            except Exception as e:
                continue

    return sTypes

def coverage_calc(capture_data, all_data):
    missingno = 0
    for name in all_data:
        if name not in capture_data:
            missingno += 1
    return 1.0 - missingno / len(all_data)

def process_trace(in_stream, trace_path):
    features = {}
    features["sTypes"] = set()
    features["metas"] = set()
    features["functions"] = set()
    features["instance_ppEnabledExtensionNames"] = []
    features["device_ppEnabledExtensionNames"] = []
    features["pEnabledFeatures"] = []

    #Iterate over all blocks and extract the function names
    try:
        for line in in_stream:
            block = json.loads(line)
            if "function" in block:
                #Grab function's name
                fn_name = block["function"]["name"]
                if fn_name in func_alias_map:
                    features["functions"].add(func_alias_map[fn_name])
                    with capture_funcs_lock:
                        capture_funcs.add(func_alias_map[fn_name])
                else:
                    features["functions"].add(fn_name)
                    with capture_funcs_lock:
                        capture_funcs.add(fn_name)

                #Special casing vkCreateInstance and vkCreateDevice as we want to extract
                #pEnabledFeatures from vkCreateDevice ppEnabledExtensionNames from both
                #I'm also assuming that there will be exactly one call to each function
                if fn_name == "vkCreateInstance":
                    exts = block["function"]["args"]["pCreateInfo"]["ppEnabledExtensionNames"]
                    features["instance_ppEnabledExtensionNames"] = exts
                    if exts is not None:
                        with capture_extensions_lock:
                            capture_extensions.update(exts)
                elif fn_name == "vkCreateDevice":
                    exts = block["function"]["args"]["pCreateInfo"]["ppEnabledExtensionNames"]
                    features["device_ppEnabledExtensionNames"] = exts
                    if exts is not None:
                        with capture_extensions_lock:
                            capture_extensions.update(exts)

                    feats = block["function"]["args"]["pCreateInfo"]["pEnabledFeatures"]
                    features["pEnabledFeatures"] = feats
                    if feats is not None:
                        with capture_features_lock:
                            capture_features.update(feats)
                            
            elif "meta" in block:
                meta_name = block["meta"]["name"]
                if meta_name not in META_COMMANDS:
                    print("UNRECOGNIZED META COMMAND %s" % meta_name)
                    exit(-1)
                features["metas"].add(meta_name)
                with capture_metas_lock:
                    capture_metas.add(meta_name)

            #Grab the sTypes
            stypes = gather_stypes(block)
            features["sTypes"].update(stypes)
            with capture_stypes_lock:
                capture_stypes.update(stypes)
    except Exception as e:
        print(f"Error: {e}")

    #Convert sets into lists
    features["functions"] = sorted(features["functions"])
    features["metas"] = sorted(features["metas"])
    features["sTypes"] = sorted(features["sTypes"])

    #No guarantee that the following fields have anything in them
    if features["instance_ppEnabledExtensionNames"] is not None:
        features["instance_ppEnabledExtensionNames"] = sorted(features["instance_ppEnabledExtensionNames"])
    if features["device_ppEnabledExtensionNames"] is not None:
        features["device_ppEnabledExtensionNames"] = sorted(features["device_ppEnabledExtensionNames"])
    if features["pEnabledFeatures"] is not None:
        features["pEnabledFeatures"] = sorted(features["pEnabledFeatures"])

    raw_out = json.dumps(features, indent=4)
    #print(f"Writing db to {trace_path}")
    f = open(trace_path, "w")
    f.write(raw_out)
    f.close()


if __name__ == "__main__":

    #Early exit if we're missing our arguments
    if len(sys.argv) < 2:
        usage()
        print("usage: %s path-to-vk.xml path-to-captures-root/" % sys.argv[0])
        exit(-1)
    vk_xml_path = sys.argv[1]
    root_traces_dir = sys.argv[2]

    vk_xml_root = ET.parse(vk_xml_path).getroot()

    #Collect the names of all vk functions
    all_vk_funcs = []
    func_alias_map = {}      #Map of function aliases to their "true" names

    print("Collecting vk function names...")
    commands_root = vk_xml_root.find("commands")
    for c in commands_root:
        if "alias" not in c.attrib:
            fn_name = c.find("proto").find("name").text
            all_vk_funcs.append(fn_name)
        else:
            func_alias_map[c.attrib["name"]] = c.attrib["alias"]
    
    print("Collecting vk extensions...")
    all_vk_extensions = []
    extensions_root = vk_xml_root.find("extensions")
    for e in extensions_root:
        all_vk_extensions.append(e.attrib["name"])

    print("Collecting vk features...")
    all_vk_features = []
    types_root = vk_xml_root.find("types")
    for ty in types_root:
        if "name" in ty.attrib and "Features" in ty.attrib["name"]:
            for member in ty:
                blacklist = ["sType", "pNext"]
                name = member.find("name").text
                if name not in blacklist:
                    all_vk_features.append(name)

    print("Collecting vk sTypes...")
    all_vk_stypes = []
    types_root = vk_xml_root.find("types")
    for t in types_root:
        if "category" in t.attrib and t.attrib["category"] == "struct":
            for member in t:
                if "values" in member.attrib and member.find("type").text == "VkStructureType":
                    all_vk_stypes.append(member.attrib["values"])

    #Get name of gfxrecon-convert binary
    GFXR_CONVERT_NAME = "gfxrecon-convert"
    # if is_windows():
        # GFXR_CONVERT_NAME += ".exe"
    convert_tool_path = GFXR_CONVERT_NAME # os.path.join(os.path.dirname(__file__), GFXR_CONVERT_NAME)

    #We expect to find commit-suite.json and extended-suite.json
    suite_jsons = ["commit-suite.json", "extended-suite.json"]

    for traces_dir in os.listdir(root_traces_dir):
        for suite_json in suite_jsons:
            full_suite_json_path = root_traces_dir + "/" + traces_dir + "/" + suite_json
            if not os.path.isfile(full_suite_json_path):
                continue
                
            suite = json.load(open(full_suite_json_path))
            #Count how many traces there are
            #I hate that I can't just say len(persistent_traces)
            trace_dir_count = len(suite["traces"])

            traces = suite["traces"]

            thread_count = int(os.cpu_count() / 2)
            convert_processes = []
            threads = []
            seen_traces = []
            trace_dirs_processed = 0

            for trace in traces:
                trace_dir = root_traces_dir + "/" + traces_dir + "/" + trace["directory"]
                full_trace_path = glob.glob(trace_dir + "/*.gfxr")[0]

                if trace_dir in seen_traces:
                    print("Saw trace %s already" % (full_trace_path))
                    continue
                seen_traces.append(trace_dir)
                
                if "api" in trace and trace["api"] != "vulkan":
                    continue

                temporary_jsonl_output = "/tmp/q.jsonl"


                #Convert process
                convert_cmd = [convert_tool_path, "--format", "jsonl", "--output", temporary_jsonl_output, full_trace_path]
                print("%s" % full_trace_path)
                result = subprocess.run(convert_cmd)
                print("completed \"%s\"" % (" ".join(convert_cmd)))

                db_output_path = os.path.splitext(full_trace_path)[0] + ".db.json"
                with open(temporary_jsonl_output) as in_stream:
                    process_trace(in_stream, db_output_path)

    #Output collated results
    collated = {}
    collated["functions"] = sorted(capture_funcs)
    collated["sTypes"] = sorted(capture_stypes)
    collated["metas"] = sorted(capture_metas)
    collated["ppEnabledExtensionNames"] = sorted(capture_extensions)
    collated["pEnabledFeatures"] = sorted(capture_features)
    f = open(root_traces_dir + "/collated.db.json", "w")
    f.write(json.dumps(collated, indent=4))
    f.close()

    #Report the results
    print("Function coverage rate: %f%%" % (100.0 * coverage_calc(capture_funcs, all_vk_funcs)))
    print("sType coverage rate: %f%%" % (100.0 * coverage_calc(capture_stypes, all_vk_stypes)))
    print("Extension coverage rate: %f%%" % (100.0 * coverage_calc(capture_extensions, all_vk_extensions)))
    print("Feature coverage rate: %f%%" % (100.0 * coverage_calc(capture_features, all_vk_features)))
    print("Meta command coverage rate: %f%%" % (100.0 * coverage_calc(capture_metas, META_COMMANDS)))

    print("Done!")
