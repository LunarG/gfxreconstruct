# CLAUDE.md

## Architectural Principles

`docs/GFXReconstruct Architectural Principles.md` defines the project's design principles and should dictate the approach to any change at a high level. Key points:

- **RECONSTRUCT/PRESERVE**: Capture files must preserve the application's original, unmodified API calls. Information added for replay goes in metadata command blocks, not by altering the recorded calls. Capture should pass calls to the driver with as little modification as possible.
- **REPLAY/REPRODUCE/GPU WORKLOAD**: Replay in the same environment as capture must work without user intervention, and the replayed command sequence and GPU workload should match capture as closely as possible unless the user requests otherwise (avoid added draws, synchronization, or queue submissions).
- **PERFORMANCE**: Especially in the capture layer, avoid locks and repeated small allocations.
- **Backward compatibility**: Existing capture files stay readable (deprecate block IDs, never repurpose them), frozen Consumer/base-class and `framework/util` interfaces keep their signatures, existing environment variables and command-line options are never deleted, default tool behavior does not change, and convert's JSON key names/value types are not changed.

If a change must conflict with a principle, explain the reason in the commit message and PR description.

## Build

Standard CMake. Common options:
- `-DD3D12_SUPPORT=OFF`
- `-DGFXRECON_ENABLE_OPENXR=OFF`
- `-DGFXRECON_INCLUDE_TEST_APPS=ON`

### Running tests
Run `./gfxrecon-testapp-runner` from the `install/test` directory after build (all GTest cases). Each test in `test/test_cases` captures and replays a small Vulkan app.

## Code Generation

**Never hand-edit** files in `framework/generated/`. Instead, edit the Python generator scripts and regenerate:

```bash
cd framework/generated
python3 generate_vulkan.py
python3 generate_dx12.py
python3 generate_openxr.py
```

Generator hierarchy: `base_generators/` -> `khronos_generators/` -> API-specific (`khronos_generators/{vulkan,openxr}_generators/`, `dx12_generators/`).

Changes to `base_generators/` or shared `khronos_generators/` code affect both Vulkan and OpenXR — regenerate and commit both.

## Architecture

### Capture path (encode)
- `layer/` - Vulkan layer (`VK_LAYER_LUNARG_gfxreconstruct`) and D3D12 capture DLLs
- `framework/encode/` - Serializes API calls into the binary capture format. Contains `capture_manager`, API call encoders, struct encoders/unwrappers, and state tracking wrappers
- `framework/format/` - Binary capture file format definitions and utilities

### Replay path (decode)
- `framework/decode/` - Deserializes capture files. Contains decoders, consumers, and struct decoders
- `framework/application/` - Windowing system abstraction for replay
- `framework/graphics/` - Graphics utility code (Vulkan/D3D12 helpers)

### Consumer pattern
`Decoder` reads blocks from the capture file and dispatches to `Consumer` implementations: `VulkanReplayConsumer` / `Dx12ReplayConsumer`, `VulkanJsonConsumer` / `Dx12JsonConsumer` (convert), `VulkanCppConsumer` (tocpp, generates C++ replay code).

### Tools (`tools/`)
Multi-API tools (`replay`, `convert`, `info`, `extract`, `optimize`) split API-specific functionality into per-API "feature" modules (e.g. `tools/optimize/optimize_vulkan_feature.cpp`) behind a common feature interface, keeping `main.cpp` API-agnostic. New API-specific tool functionality should follow this pattern.

## Coding Conventions

- Use `GFXRECON_ASSERT` instead of `assert`
- Explicitly compare pointers against `nullptr`
- Formatting: ClangFormat 14 (`.clang-format`) for C++, yapf (`.style.yapf`) for Python
- C++20 standard
- Avoid editing code unrelated to the change — commits should be cleanly revertible
- PRs target the `dev` branch
- Keep PRs small and single-purpose: no unrelated bug fixes or style changes; separate refactors from bug fixes
- Branch names describe the fix (e.g. `fix-createinstance-crash`, not `fix-1234`); put "Fixes #1234" in the PR description or final commit message

### Changing capture file blocks

Do not alter existing capture file block structs or IDs. Instead:
1. Add a new metacommand to `format.h` (e.g. `kCreateHardwareBufferCommand2`)
2. Change capture to write the new metacommand
3. Rename the old metacommand with a `_deprecated` suffix (so code writing it fails to compile) and document the change at the deprecated name
4. Handle the new metacommand on replay
5. Log a note when replaying the deprecated metacommand if it implies limited or incorrect operation

### Commits

- Run `git clang-format-14` and commit the formatting before pushing (CI fails otherwise)
- Prefer clarity over pedantically staying under conventional message-length limits
- Never mention game/application names or specific companies in commit messages (fixes should not be app-specific anyway)
- Squash noise commits ("apply clang-format", "clean up", change+revert pairs); multiple meaningful commits per PR are encouraged when they represent distinct sub-steps
- Describe the problem and rationale before the changes themselves; call out signature changes, moved/added/deleted functions, and new files
- State how the change was tested

### Testing expectations for new code

- New features need automated tests; new flags, env vars, or properties need tests that exercise them (or at least a written test procedure)
- Functionality testable without a GPU gets a unit test in `framework/<facility>/test` or `layer/test`
- New Vulkan functionality gets a test program in `test_apps`; if it runs on the Mock ICD (no real hardware), add a test case and reference file in `test/test_cases`
