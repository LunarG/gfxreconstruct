# RenderDoc Integration in GFXReconstruct Replayer

This document describes the changes made to the GFXReconstruct (GFXR) repository to integrate programmatic RenderDoc capture support during replay on Android.

## Overview
The integration allows GFXR to dynamically load the RenderDoc capture layer, trigger frame captures programmatically at specific frames, and save the resulting `.rdc` files to a designated directory on the device.

---

## Version Selection Strategy

### Proposal (Currently Used)

We propose using the **Official RenderDoc v1.43** layer for the integration.

#### Rationale
*   **Compatibility**: Captures generated with v1.43 format can be opened by v1.43 (both Official and Arm Performance Studio versions) and v1.44 desktop clients, providing the widest usability.
*   **Standard Layer Name**: It registers as `VK_LAYER_RENDERDOC_Capture`, which is the standard name. This avoids the need for custom configurations in the plugin (unlike the ARM version).

#### Components & Sources
*   **`libVkLayer_GLES_RenderDoc.so` (v1.43)**: Extracted from the official RenderDoc v1.43 Android release (`renderdoccmd.arm64.apk`).
    *   *Source*: Downloaded from `https://renderdoc.org/stable/1.43/renderdoc_1.43.tar.gz` (inside `share/renderdoc/plugins/android/org.renderdoc.renderdoccmd.arm64.apk`).
*   **`renderdoc_app.h` (API v1.7.0)**: Copied from the official RenderDoc repository.
    *   *Source*: `https://raw.githubusercontent.com/baldurk/renderdoc/master/renderdoc/api/app/renderdoc_app.h`

---

### Alternatives Considered

#### Alternative 1: Official RenderDoc v1.44
*   **Pros**: Newer version, matches the latest standalone desktop client installed on some developer machines.
*   **Cons**: Captures generated in v1.44 format cannot be opened by older v1.43 desktop clients (e.g., the one integrated in Arm Performance Studio), limiting compatibility.

#### Alternative 2: ARM RenderDoc v1.43 (from Arm Performance Studio)
*   **Pros**: Matches the version bundled with Arm Performance Studio.
*   **Cons**: Registers with a custom Vulkan layer name (`VK_LAYER_RENDERDOC_ARM_Capture`). This breaks the standard plugin integration which expects the standard name, and makes it incompatible with official (non-ARM) RenderDoc desktop clients for remote replay.

---

## Version Control & Dependency Management

### Hermeticity & Checked-in Prebuilts
To ensure the GFXR build is hermetic and does not rely on external network requests during compilation, we check the prebuilt binaries and headers directly into the source tree:
*   `libVkLayer_GLES_RenderDoc.so` is checked in at `android/tools/replay/src/main/jniLibs/arm64-v8a/`.
*   `renderdoc_app.h` is checked in at `framework/decode/`.

This guarantees that:
1.  The build is reproducible and independent of external server availability.
2.  The version of RenderDoc used for capture is pinned and controlled, preventing accidental upgrades that could break compatibility.

### Propagation to Sherlock Plugin
The GFXR Replayer is packaged into `replay-debug.apk` when GFXR is built. This APK is then copied to the `studio-main` repository at `prebuilts/tools/sherlock/gfxreconstruct/replay-debug.apk`. 
This allows the Sherlock plugin to deploy the replayer with the correct integrated RenderDoc version without needing to build GFXR from source during plugin development.

---

## Detailed Changes

### 1. RenderDoc Vulkan Layer Packaging
To avoid requiring the RenderDoc layer to be globally installed on the device (which requires root or specific debug settings), the RenderDoc Vulkan layer is packaged directly inside the GFXR Replayer APK.

*   **File Added**: `android/tools/replay/src/main/jniLibs/arm64-v8a/libVkLayer_GLES_RenderDoc.so` (containing the official v1.43 layer).

### 2. ABI-Compliant API Header Integration
To interact with the RenderDoc layer, GFXR uses the RenderDoc In-Application API. We integrated the official header to prevent ABI mismatches.

*   **File Added**: `framework/decode/renderdoc_app.h`
*   **Source**: Copied from the official RenderDoc repository on GitHub:
    `https://raw.githubusercontent.com/baldurk/renderdoc/master/renderdoc/api/app/renderdoc_app.h`
    (Defined as v1.7.0 compatible, which is backward-compatible and provides the correct structure layout for `RENDERDOC_API_1_0_0`).
*   **File Modified**: `framework/decode/renderdoc_capture.h`
    *   Removed the custom, incomplete `RENDERDOC_API_1_0_0` struct definition which was causing offset mismatches (e.g., calling `SetCaptureOptionU32` instead of `SetCaptureFilePathTemplate`).
    *   Included the official `renderdoc_app.h` instead.

### 3. Replay Capture Logic
Updated the replayer state machine to correctly trigger captures.

*   **File Modified**: `framework/decode/file_processor.cpp`
    *   Updated the `StartFrameCapture` call to match the official `void` return type signature.
    *   Added a call to `IsFrameCapturing()` to verify that the capture session started successfully before setting the internal capturing state.

### 4. Build System Updates
Updated CMake configurations to include the new header.

*   **File Modified**: `framework/decode/CMakeLists.txt`
    *   Added `renderdoc_app.h` to the target sources for both Android and stub implementations to ensure correct dependency tracking.
*   **File Modified**: `android/framework/decode/CMakeLists.txt`
    *   Ensured the Android-specific build config includes the new files.

---

## Compatibility & ABI Stability

### ABI Compatibility Guarantee
RenderDoc's In-Application API is designed to maintain backward compatibility across minor and patch versions. This is documented in `renderdoc_app.h`:

> // RenderDoc uses semantic versioning (http://semver.org/).
> // MAJOR version is incremented when incompatible API changes happen.
> // MINOR version is incremented when functionality is added in a backwards-compatible manner.
> // PATCH version is incremented when backwards-compatible bug fixes happen.

Since the Major version remains `1` for the header (v1.7.0 API) and the loaded library (v1.44, which implements ~v1.4.1 API), they are binary compatible.

### Struct Layout Evolution
In C/C++, ABI compatibility for the API structure is maintained by **only appending** new function pointers to the end of the `RENDERDOC_API_1_X_Y` structure.
*   Functions introduced in 1.0.0 (like `StartFrameCapture`, `EndFrameCapture`, `SetCaptureFilePathTemplate`) remain at their original offsets.
*   GFXR requests the `1.0.0` version: `RENDERDOC_GetAPI(eRENDERDOC_API_Version_1_0_0, ...)`.
*   The library (v1.44) returns a structure that contains all 1.0.0 functions at the expected offsets.
*   Even though GFXR compiles against a newer header (v1.7.0) defining more fields at the end, it only accesses the 1.0.0 fields at the beginning of the struct, making it safe to use with the older v1.44 library.

## Managing Replay Agent Versions (Remote Replay)

When switching between different RenderDoc Desktop UI versions (e.g., from Official 1.43 to ARM 1.43 or Official 1.44), you must ensure the matching version of the Replay Agent is installed on the device.

If you encounter an "Incompatible version" error:
1.  **Uninstall the existing agent** from the device:
    ```bash
    adb uninstall org.renderdoc.renderdoccmd.arm64
    ```
2.  **Trigger auto-installation**: Open the `.rdc` file in the desired RenderDoc Desktop UI and attempt to connect to the remote host. The Desktop UI will automatically detect the missing agent and prompt to install the correct version.
3.  **Bypass Play Protect**: During the automatic installation, check your phone. You may need to manually interact with the device to bypass the "Unsafe app blocked" (Play Protect) warning by selecting **"More details" -> "Install anyway"**.
