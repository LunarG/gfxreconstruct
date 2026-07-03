# Replay Dump

## Generate the Known-Good Dump

Use the same loader, implicit-layer, display, SDK, and ICD settings when regenerating
the known-good dump:

```sh
VK_LOADER_LAYERS_DISABLE='~implicit~' DISPLAY=:0 SDK_DIR_2=/media/nas/smb_traces/sdks TARGET_DRIVER=/etc/vulkan/icd.d/nvidia_icd.json GFXRECON_REPLAY=$(pwd)/gfxrecon-replay python3 ./replay_dump.py /media/nas/smb_traces/vulkan/GFXR/aurelia-nvidia/vkcube/vkcube_20190306T155300.gfxr --output $(pwd)/output_dump_headless.json
```
