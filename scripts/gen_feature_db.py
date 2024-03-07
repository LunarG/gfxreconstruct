#gen_feature_db.py
#Author: Nick Driscoll
#Intended to be executed from the root of the GFXR repo

import sys
import os
import subprocess
import platform
import json
import json_stream
import abc
import xml.etree.ElementTree as ET
from io import StringIO
from collections.abc import Iterable
import time

script_name = os.path.basename(__file__)

#Returns true if running on Windows, false otherwise
def is_windows():
    '''
    Check if the system is Windows
    '''
    return 'windows' == platform.system().lower()

# Print usage instructions
def usage():
    print("Usage: %s <root traces directory>" % script_name)

def load_json(path):
    f = open(path)
    return json_stream.load(f)

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

if __name__ == "__main__":

    #Early exit if we're missing our arguments
    if len(sys.argv) < 2:
        usage()
        print("Error: missing path to capture directory")
        exit(-1)
    root_traces_dir = sys.argv[1]

    #Parse vk.xml
    vk_xml_path = "external/Vulkan-Headers/registry/vk.xml"
    vk_xml_root = ET.parse(vk_xml_path).getroot()

    #Collect the names of all vk functions
    all_vk_funcs = []
    alias_map = {}      #Map of function aliases to their "true" names

    print("Collecting vk function names...")
    commands_root = vk_xml_root.find("commands")
    for c in commands_root:
        if "alias" not in c.attrib:
            fn_name = c.find("proto").find("name").text
            all_vk_funcs.append(fn_name)
        else:
            alias_map[c.attrib["name"]] = c.attrib["alias"]
    
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
    if is_windows():
        GFXR_CONVERT_NAME += ".exe"
    convert_tool_path = os.path.join(os.path.dirname(__file__), GFXR_CONVERT_NAME)

    #Variables to collect all vk functions across all traces
    capture_funcs = set()
    capture_extensions = set()
    capture_features = set()
    capture_structs = set()
    capture_metas = set()
    capture_stypes = set()

    #We expect to find commit-suite.json and extended-suite.json
    #suite_jsons = ["commit-suite.json", "extended-suite.json"]
    suite_jsons = ["commit-suite.json"]
    convert_processes = []
    trace_paths = []
    json_paths = []
    for file in os.listdir(root_traces_dir):
        for suite_json in suite_jsons:
            if os.path.isfile(root_traces_dir + "/" + file + "/" + suite_json):
                full_suite_json_path = root_traces_dir + "/" + file + "/" + suite_json
                suite = load_json(full_suite_json_path)

                for trace in suite["traces"].persistent():
                    #Skip non-vulkan traces
                    if "api" in trace and trace["api"] != "vulkan":
                        continue

                    trace_dir = root_traces_dir + "/" + file + "/" + trace["directory"]
                    trace_paths.append(trace_dir)
                    for trace_file in os.listdir(trace_dir):
                        filename = os.fsdecode(trace_file)
                        if not filename.endswith(".gfxr"):
                            continue

                        print("Launching gfxr-convert on %s..." % filename)
                        full_trace_path = trace_dir + "/" + filename
                        #out_json_path = os.path.splitext(full_trace_path)[0] + ".json"
                        out_json_path = "/tmp/" + os.path.splitext(os.path.basename(full_trace_path))[0] + ".json"
                        json_paths.append(out_json_path)
                        cmd = [convert_tool_path, "--output", out_json_path, full_trace_path]
                        p = subprocess.Popen(cmd)
                        convert_processes.append(p)


    #Wait for the conversions to complete
    print("Waiting for convert jobs to finish...")
    for p in convert_processes:
        p.wait()
    print("SLEEPING 30s TO PREVENT FLUSH ISSUE. NEED TO FIX")
    time.sleep(30)

    #Extract desired data from each of the new JSON captures
    print("Processing json captures...")
    for (json_path, trace_path) in zip(json_paths, trace_paths):
        features = {}
        features["sTypes"] = set()
        features["metas"] = set()
        features["functions"] = set()

        print("Analyzing %s..." % json_path)
        capture_json = load_json(json_path)

        #Iterate over all blocks and extract the function names
        for block in capture_json.persistent():
            if "function" in block:
                #Grab function's name
                fn_name = block["function"]["name"]
                if fn_name in alias_map:
                    features["functions"].add(alias_map[fn_name])
                    capture_funcs.add(alias_map[fn_name])
                else:
                    features["functions"].add(fn_name)
                    capture_funcs.add(fn_name)

                #Special casing vkCreateInstance and vkCreateDevice as we want to extract
                #pEnabledFeatures from vkCreateDevice ppEnabledExtensionNames from both
                #I'm also assuming that there will be exactly one call to each function
                if fn_name == "vkCreateInstance":
                    exts = block["function"]["args"]["pCreateInfo"]["ppEnabledExtensionNames"]
                    features["instance_ppEnabledExtensionNames"] = exts
                    if exts is not None:
                        capture_extensions.update(exts)
                elif fn_name == "vkCreateDevice":
                    exts = block["function"]["args"]["pCreateInfo"]["ppEnabledExtensionNames"]
                    features["device_ppEnabledExtensionNames"] = exts
                    if exts is not None:
                        capture_extensions.update(exts)

                    feats = block["function"]["args"]["pCreateInfo"]["pEnabledFeatures"]
                    features["pEnabledFeatures"] = feats
                    if feats is not None:
                        capture_features.update(feats)
                    
            elif "meta" in block:
                meta_name = block["meta"]["name"]
                features["metas"].add(meta_name)
                capture_metas.add(meta_name)

            #Grab the sTypes
            stypes = gather_stypes(block)
            features["sTypes"].update(stypes)
            capture_stypes.update(stypes)

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
        db_path = trace_path + "/" + os.path.splitext(os.path.basename(json_path))[0] + ".db.json"
        print("Writing db to %s" % db_path)
        f = open(db_path, "w")
        f.write(raw_out)
        f.close()

    #Report the results
    print("Function coverage rate: %f%%" % (100.0 * coverage_calc(capture_funcs, all_vk_funcs)))
    print("sType coverage rate: %f%%" % (100.0 * coverage_calc(capture_stypes, all_vk_stypes)))
    print("Extension coverage rate: %f%%" % (100.0 * coverage_calc(capture_extensions, all_vk_extensions)))

    print("Done!")