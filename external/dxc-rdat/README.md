# DXC RDAT reader

This directory holds a copy of DirectX Shader Compiler's header-only reader for a DXIL container's
`RDAT` part. GFXR uses it during D3D12/DXR replay to parse subobjects compiled into a DXIL library.

These files are in sync with the version of the DXC redistributable that `cmake/FindDXC.cmake` fetches.
The redistributable ships the public headers (`dxcapi.h`, `d3d12shader.h`, ...) but the RDAT reader
exists only in the DXC source tree, so the relevant files are vendored here.

## Provenance

- Upstream: https://github.com/microsoft/DirectXShaderCompiler
- Tag: `v1.8.2407` (commit `416fab6b5c4ba956a320d9131102304da995edfc`)

## License

University of Illinois/NCSA Open Source License (the LLVM Release License). The per-file
headers retain the upstream notice; the full text is in `LICENSE.TXT` here and is also
recorded in the repository-root `LICENSE_ThirdParty.txt` under
"DirectX Shader Compiler - all other files".

## Updating

Do not edit these files; they are vendored verbatim. Keep their version in sync with the DXC
redistributalbe--see `DXC_VERSION` in `cmake/FindDXC.cmake`. If a new DXC version adds a sibling
`RDAT_*Types.inl` to the master list in `RDAT_Macros.inl`, vendor it too (follow the `#include`s
in `RDAT_Macros.inl`).
