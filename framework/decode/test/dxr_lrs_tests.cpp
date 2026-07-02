///////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2026 LunarG, Inc.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
/// \description Unit tests for parsing local root signatures authored inside DXIL libraries.
///////////////////////////////////////////////////////////////////////////////

#include "decode/dx12_dxil_lrs_parser.h"

#include <catch2/catch.hpp>

#if defined(D3D12_SUPPORT)
#include <windows.h>

// The in-DXIL LRS tests create a WARP device and query ID3D12DeviceConfiguration1 from it. The
// ID3D12DeviceConfiguration1 interface is only present when the Agility SDK runtime is loaded, so export these values
// to load the version of the Agility SDK used by GFXR.
extern "C"
{
    __declspec(dllexport) extern const UINT D3D12SDKVersion = 618;
    __declspec(dllexport) extern const char* D3D12SDKPath   = reinterpret_cast<const char*>(u8".\\D3D12\\");
}
#endif // D3D12_SUPPORT

// These tests run GetDxilLibraryInDxilLrsInfo on real DXIL library fixtures compiled from HLSL by DXC at build time.
// The .cso files are built from framework/decode/test/dxr_lrs_fixtures/*.hlsl (see CMakeLists.txt).
// GFXRECON_TEST_DXR_LRS_FIXTURE_DIR is the build-tree directory holding them.
#if defined(GFXRECON_DXC_SUPPORT) && defined(GFXRECON_TEST_DXR_LRS_FIXTURE_DIR)

#include "graphics/dx12_util.h"

#include <d3d12.h>
#include <dxgi1_4.h>

#include <fstream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace gfxrecon;
using namespace gfxrecon::decode;

namespace
{

// ID3D12DeviceConfiguration1 is a runtime interface provided by the Agility SDK, so a WARP device exposes it--no
// physical GPU required. Create the device once and cache the queried interface.
graphics::dx12::ID3D12DeviceConfiguration1ComPtr GetDeviceConfiguration()
{
    static graphics::dx12::ID3D12DeviceConfiguration1ComPtr device_config = [] {
        graphics::dx12::ID3D12DeviceConfiguration1ComPtr               config;
        _com_ptr_t<_com_IIID<IDXGIFactory4, &__uuidof(IDXGIFactory4)>> factory;
        if (SUCCEEDED(CreateDXGIFactory2(0, IID_PPV_ARGS(&factory))))
        {
            graphics::dx12::IDXGIAdapterComPtr warp_adapter;
            if (SUCCEEDED(factory->EnumWarpAdapter(IID_PPV_ARGS(&warp_adapter))))
            {
                graphics::dx12::ID3D12DeviceComPtr device;
                if (SUCCEEDED(D3D12CreateDevice(warp_adapter, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&device))))
                {
                    device->QueryInterface(IID_PPV_ARGS(&config));
                }
            }
        }
        return config;
    }();
    return device_config;
}

struct ResolvedLrs
{
    std::set<ResourceValueInfo>                         default_infos;
    std::map<std::wstring, std::set<ResourceValueInfo>> export_infos;
};

std::vector<uint8_t> LoadFixture(const std::string& file_name)
{
    const std::string path =
        std::string(GFXRECON_TEST_DXR_LRS_FIXTURE_DIR) + gfxrecon::util::filepath::kPathSepStr + file_name;
    std::ifstream file(path, std::ios::binary);
    INFO("fixture: " << path);
    REQUIRE(file.is_open());
    return std::vector<uint8_t>(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
}

ResolvedLrs ResolveFixture(const std::string& file_name)
{
    graphics::dx12::ID3D12DeviceConfiguration1ComPtr device_config = GetDeviceConfiguration();
    REQUIRE(device_config != nullptr);

    const std::vector<uint8_t> blob = LoadFixture(file_name);
    ResolvedLrs                resolved;
    GetDxilLibraryInDxilLrsInfo(
        blob.data(), blob.size(), 0, device_config, resolved.default_infos, resolved.export_infos);
    return resolved;
}

// Narrow an ASCII export name for diagnostics on failure.
std::string Narrow(const std::wstring& wide)
{
    std::string narrow;
    for (wchar_t c : wide)
    {
        narrow.push_back(static_cast<char>(c));
    }
    return narrow;
}

// Verify an ordered set of parsed resource values matches the expected offsets and types.
void CheckResourceValues(const std::set<ResourceValueInfo>&                         infos,
                         const std::vector<std::pair<uint64_t, ResourceValueType>>& expected)
{
    REQUIRE(infos.size() == expected.size());
    size_t i = 0;
    for (const auto& info : infos)
    {
        CHECK(info.offset == expected[i].first);
        CHECK(info.type == expected[i].second);
        CHECK(info.size == 8);
        ++i;
    }
}

} // namespace

TEST_CASE("In-DXIL LRS resolver treats an unassociated local root signature as the default", "[dxr][lrs][rdat]")
{
    auto resolved = ResolveFixture("default_lrs.cso");
    CHECK(resolved.export_infos.empty());
    CheckResourceValues(resolved.default_infos,
                        { { 0, ResourceValueType::kGpuVirtualAddress }, { 8, ResourceValueType::kGpuVirtualAddress } });
}

TEST_CASE("In-DXIL LRS resolver maps a mix of descriptor tables and root descriptors", "[dxr][lrs][rdat]")
{
    auto resolved = ResolveFixture("mixed_lrs.cso");
    CHECK(resolved.export_infos.empty());
    CheckResourceValues(resolved.default_infos,
                        { { 0, ResourceValueType::kGpuDescriptorHandle },
                          { 8, ResourceValueType::kGpuVirtualAddress },
                          { 16, ResourceValueType::kGpuDescriptorHandle },
                          { 24, ResourceValueType::kGpuVirtualAddress } });
}

TEST_CASE("In-DXIL LRS resolver binds an explicitly associated local root signature to its export", "[dxr][lrs][rdat]")
{
    auto resolved = ResolveFixture("associated_lrs.cso");

    std::string keys;
    for (const auto& entry : resolved.export_infos)
    {
        keys += Narrow(entry.first) + " ";
    }
    INFO("export keys: " << keys);

    CHECK(resolved.default_infos.empty());
    REQUIRE(resolved.export_infos.size() == 1);
    REQUIRE(resolved.export_infos.count(L"RayGen") == 1);
    CheckResourceValues(resolved.export_infos.at(L"RayGen"),
                        { { 0, ResourceValueType::kGpuVirtualAddress }, { 8, ResourceValueType::kGpuVirtualAddress } });
}

TEST_CASE("In-DXIL LRS resolver handles an associated and a default local root signature together", "[dxr][lrs][rdat]")
{
    auto resolved = ResolveFixture("two_lrs.cso");
    // DefaultLRS: two SRVs.
    CheckResourceValues(resolved.default_infos,
                        { { 0, ResourceValueType::kGpuVirtualAddress }, { 8, ResourceValueType::kGpuVirtualAddress } });
    REQUIRE(resolved.export_infos.count(L"RayGen") == 1);
    // AssociatedLRS: one SRV.
    CheckResourceValues(resolved.export_infos.at(L"RayGen"), { { 0, ResourceValueType::kGpuVirtualAddress } });
}

TEST_CASE("In-DXIL LRS resolver ignores a global root signature subobject", "[dxr][lrs][rdat]")
{
    auto resolved = ResolveFixture("global_and_local.cso");
    CHECK(resolved.export_infos.empty());
    CheckResourceValues(resolved.default_infos, { { 0, ResourceValueType::kGpuVirtualAddress } });
}

TEST_CASE("In-DXIL LRS resolver yields nothing for a library without subobjects", "[dxr][lrs][rdat]")
{
    auto resolved = ResolveFixture("no_subobjects.cso");
    CHECK(resolved.default_infos.empty());
    CHECK(resolved.export_infos.empty());
}

#endif // GFXRECON_DXC_SUPPORT && GFXRECON_TEST_DXR_LRS_FIXTURE_DIR
