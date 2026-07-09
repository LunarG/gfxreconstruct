# CLAUDE.md

## Project Overview

GFXReconstruct is a set of tools for capturing and replaying graphics API calls (Vulkan, D3D12, OpenXR). It records graphics commands to a `.gfxr` capture file that can be replayed later.

## Architectural Principles

`docs/GFXReconstruct Architectural Principles.md` defines the project's design principles and should dictate the approach to any change at a high level. Key points:

- **RECONSTRUCT/PRESERVE**: Capture files must preserve the application's original, unmodified API calls. Information added for replay goes in metadata command blocks, not by altering the recorded calls. Capture should pass calls to the driver with as little modification as possible.
- **REPLAY/REPRODUCE/GPU WORKLOAD**: Replay in the same environment as capture must work without user intervention, and the replayed command sequence and GPU workload should match capture as closely as possible unless the user requests otherwise (avoid added draws, synchronization, or queue submissions).
- **PERFORMANCE**: Especially in the capture layer, avoid locks and repeated small allocations.
- **Backward compatibility**: Existing capture files stay readable (deprecate block IDs, never repurpose them), frozen Consumer/base-class and `framework/util` interfaces keep their signatures, existing environment variables and command-line options are never deleted, default tool behavior does not change, and convert's JSON key names/value types are not changed.

If a change must conflict with a principle, explain the reason in the commit message and PR description.

## Build Commands

### Quick build (Windows)
```bash
python scripts/build.py --skip-check-code-style --skip-tests
```

### Parallel build
```bash
CMAKE_BUILD_PARALLEL_LEVEL=8 python scripts/build.py --skip-check-code-style --skip-tests
```

### Build script options
- `-c {release,debug}` - configuration (default: release)
- `--skip-d3d12-support` - omit D3D12 components
- `--test-apps` - build test apps

Run `python scripts/build.py --help` for the full option list.

Build output goes to `build/windows/x64/cmake_output` (release) or `dbuild/...` (debug).

### Manual CMake (Windows)
```bash
cmake . -Bbuild -G "Visual Studio 17 2022"
cmake --build build --config Release
```

D3D12 build requires Windows SDK 10.0.26100.0. Use `-DD3D12_SUPPORT=OFF` to disable. Vulkan support can be disabled with `-DGFXRECON_ENABLE_VULKAN=OFF` (experimental; default ON).

### Running tests
Tests use GoogleTest. After building with test apps:
```bash
# From the install/test directory after build:
./gfxrecon-testapp-runner   # runs all GTest cases
```
Test cases live in `test/test_cases/`. Each test captures and replays a small Vulkan app.

## Code Generation

Files in `framework/generated/` are auto-generated. **Never hand-edit them.** Instead, edit the Python generator scripts and regenerate:

```bash
cd framework/generated
python3 generate_vulkan.py   # Vulkan sources
python3 generate_dx12.py     # D3D12 sources
python3 generate_openxr.py   # OpenXR sources
```

Generator hierarchy: `base_generators/` -> `khronos_generators/` -> API-specific generators (`khronos_generators/vulkan_generators/`, `khronos_generators/openxr_generators/`, `dx12_generators/`).

Changes to shared Khronos generator code (`khronos_generators/` or `base_generators/`) affect both Vulkan and OpenXR — regenerate and commit both.

## Architecture

### Capture path (encode)
- `layer/` - Vulkan layer (`VK_LAYER_LUNARG_gfxreconstruct`) and D3D12 capture DLLs
- `framework/encode/` - Serializes API calls into the binary capture format. Contains `capture_manager`, API call encoders, struct encoders/unwrappers, and state tracking wrappers
- `framework/format/` - Binary capture file format definitions and utilities

### Replay path (decode)
- `framework/decode/` - Deserializes capture files. Contains decoders, consumers (replay, JSON, etc.), and struct decoders
- `framework/application/` - Windowing system abstraction for replay
- `framework/graphics/` - Graphics utility code (Vulkan/D3D12 helpers)

### Consumer pattern
Decoding uses a consumer pattern: `Decoder` reads blocks from the capture file and dispatches to `Consumer` implementations. Key consumers:
- `VulkanReplayConsumer` / `Dx12ReplayConsumer` - replays API calls
- `VulkanJsonConsumer` / `Dx12JsonConsumer` - converts to JSON
- `VulkanCppConsumer` - generates C++ replay code (tocpp)

### Tools (`tools/`)
Multi-API tools (`replay`, `convert`, `info`, `extract`, `optimize`) split API-specific functionality into per-API "feature" modules (e.g. `tools/optimize/optimize_vulkan_feature.cpp`, `optimize_dx12_feature.cpp`) behind a common feature interface, keeping `main.cpp` API-agnostic. New API-specific tool functionality should follow this pattern.

## Coding Conventions

- Use `GFXRECON_ASSERT` instead of `assert`
- Explicitly compare pointers against `nullptr` (e.g., `if (ptr == nullptr)`)
- C++ style: Google C++ Style Guide with ClangFormat 14 (`.clang-format` at repo root)
- Python style: PEP 8 with yapf (`.style.yapf` at repo root)
- C++20 standard
- Avoid editing code unrelated to the change — commits should be cleanly revertible
- PRs target the `dev` branch
- Keep PRs small and single-purpose: no unrelated bug fixes or style changes; separate refactors from bug fixes
- Branch names describe the fix (e.g. `fix-createinstance-crash`, not `fix-1234`); put "Fixes #1234" in the PR description or final commit message so the issue auto-closes on merge

### Changing capture file blocks

Do not alter existing capture file block structs or IDs. Instead:
1. Add a new metacommand to `format.h` (e.g. `kCreateHardwareBufferCommand2`)
2. Change capture to write the new metacommand
3. Rename the old metacommand with a `_deprecated` suffix (so code writing it fails to compile) and document the change at the deprecated name
4. Handle the new metacommand on replay
5. Log a note when replaying the deprecated metacommand if it implies limited or incorrect operation

The other backward compatibility guarantees also apply (see Architectural Principles above).

### Commits

- Run `git clang-format-14` and commit the formatting before pushing (CI fails otherwise)
- 50-char summary line, 72-char body wrap, imperative mood — but prefer clarity over pedantically staying under limits
- Never mention game/application names or specific companies in commit messages (fixes should not be app-specific anyway)
- Squash noise commits ("apply clang-format", "clean up", change+revert pairs); multiple meaningful commits per PR are encouraged when they represent distinct sub-steps
- Describe the problem and rationale before the changes themselves; call out signature changes, moved/added/deleted functions, and new files
- State how the change was tested

### Testing expectations for new code

- New features need automated tests; new flags, env vars, or properties need tests that exercise them (or at least a written test procedure)
- Functionality testable without a GPU gets a unit test in `framework/<facility>/test` or `layer/test`
- New Vulkan functionality gets a test program in `test_apps`; if it runs on the Mock ICD (no real hardware), add a test case and reference file in `test/test_cases`
