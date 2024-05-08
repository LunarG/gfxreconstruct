#gen_coverage_table.py
#Author: Nick Driscoll

import json
import sys
import xml.etree.ElementTree as ET


if __name__ == "__main__":

    #Early exit if we're missing our arguments
    if len(sys.argv) < 3:
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
    all_vk_funcs.sort()
    print("Done collecting vk function names...")
    
    #Process collated results file
    results_file = open(f"{root_traces_dir}/collated.db.json")
    results = json.load(results_file)
    results_file.close()

    for func in results["functions"]:
        all_vk_funcs.remove(func)
        
    
    missing_1_0 = []
    for f in all_vk_funcs:
        feature_roots = vk_xml_root.findall("feature")
        i = 0
        features_root = feature_roots[i]
        while features_root.attrib["name"] != "VK_VERSION_1_0":
            i += 1
            features_root = feature_roots[i]

        for require in features_root:
            for tag in require:
                
                print(tag.attrib["name"])


