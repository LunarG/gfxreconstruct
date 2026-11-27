/*
** Copyright (c) 2022-2025 LunarG, Inc.
** Copyright (c) 2025-2026 Arm Limited and/or its affiliates <open-source-office@arm.com>
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

#ifndef GFXRECON_DECODE_DX12_OFFSCREEN_SWAPCHAIN_H
#define GFXRECON_DECODE_DX12_OFFSCREEN_SWAPCHAIN_H

#include "decode/dx12_object_info.h"

#include <atomic>
#include <dxgi1_5.h>
#include <unordered_map>
#include <vector>
#include <wrl/client.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class Dx12OffscreenSwapchain : public IDXGISwapChain4
{
  public:
    // Constructor for Dx12OffscreenSwapchain (used with IDXGIFactory::CreateSwapChain)
    Dx12OffscreenSwapchain(ID3D12Device* device, DXGI_SWAP_CHAIN_DESC* desc);

    // Constructor for Dx12OffscreenSwapchain (used with IDXGIFactory2::CreateSwapChainForHwnd,
    // IDXGIFactory2::CreateSwapChainForComposition and IDXGIFactory2::CreateSwapChainForCoreWindow)
    Dx12OffscreenSwapchain(ID3D12Device*                    device,
                           uint64_t                         hwnd_id,
                           DXGI_SWAP_CHAIN_DESC1*           desc,
                           DXGI_SWAP_CHAIN_FULLSCREEN_DESC* fullscreen_desc);

    virtual ~Dx12OffscreenSwapchain() {}

    // Create offscreen swapchain for IDXGIFactory::CreateSwapChain
    static Microsoft::WRL::ComPtr<Dx12OffscreenSwapchain> Create(ID3D12Device* device, DXGI_SWAP_CHAIN_DESC* desc);

    // Create offscreen swapchain for IDXGIFactory2::CreateSwapChainForHwnd, CreateSwapChainForComposition and
    // IDXGIFactory2::CreateSwapChainForCoreWindow
    static Microsoft::WRL::ComPtr<Dx12OffscreenSwapchain> Create(ID3D12Device*                    device,
                                                                 uint64_t                         hwnd_id,
                                                                 DXGI_SWAP_CHAIN_DESC1*           desc,
                                                                 DXGI_SWAP_CHAIN_FULLSCREEN_DESC* fullscreen_desc);

    // IUnknown methods
    virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObject) override;
    virtual ULONG STDMETHODCALLTYPE   AddRef() override;
    virtual ULONG STDMETHODCALLTYPE   Release() override;

    // IDXGIObject methods
    virtual HRESULT STDMETHODCALLTYPE GetParent(REFIID riid, void** ppParent) override;
    virtual HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID guid, UINT* pDataSize, void* pData) override;
    virtual HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID guid, UINT DataSize, const void* pData) override;
    virtual HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(REFGUID guid, const IUnknown* pUnknown) override;

    // IDXGIDeviceSubObject methods
    virtual HRESULT STDMETHODCALLTYPE GetDevice(REFIID riid, void** ppDevice) override;

    // IDXGISwapChain methods
    virtual HRESULT STDMETHODCALLTYPE GetBuffer(UINT Buffer, REFIID riid, void** ppSurface) override;
    virtual HRESULT STDMETHODCALLTYPE GetContainingOutput(IDXGIOutput** ppOutput) override;
    virtual HRESULT STDMETHODCALLTYPE GetDesc(DXGI_SWAP_CHAIN_DESC* pDesc) override;
    virtual HRESULT STDMETHODCALLTYPE GetFrameStatistics(DXGI_FRAME_STATISTICS* pStats) override;
    virtual HRESULT STDMETHODCALLTYPE GetFullscreenState(BOOL* pFullscreen, IDXGIOutput** ppTarget) override;
    virtual HRESULT STDMETHODCALLTYPE GetLastPresentCount(UINT* pLastPresentCount) override;
    virtual HRESULT STDMETHODCALLTYPE Present(UINT SyncInterval, UINT Flags) override;
    virtual HRESULT STDMETHODCALLTYPE
    ResizeBuffers(UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags) override;
    virtual HRESULT STDMETHODCALLTYPE ResizeTarget(const DXGI_MODE_DESC* pNewTargetParameters) override;
    virtual HRESULT STDMETHODCALLTYPE SetFullscreenState(BOOL Fullscreen, IDXGIOutput* pTarget) override;

    // IDXGISwapChain1 methods
    virtual HRESULT STDMETHODCALLTYPE GetBackgroundColor(DXGI_RGBA* pColor) override;
    virtual HRESULT STDMETHODCALLTYPE GetCoreWindow(REFIID riid, void** ppUnk) override;
    virtual HRESULT STDMETHODCALLTYPE GetDesc1(DXGI_SWAP_CHAIN_DESC1* pDesc) override;
    virtual HRESULT STDMETHODCALLTYPE GetFullscreenDesc(DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pDesc) override;
    virtual HRESULT STDMETHODCALLTYPE GetHwnd(HWND* pHwnd) override;
    virtual HRESULT STDMETHODCALLTYPE GetRestrictToOutput(IDXGIOutput** ppOutput) override;
    virtual HRESULT STDMETHODCALLTYPE GetRotation(DXGI_MODE_ROTATION* pRotation) override;
    virtual BOOL STDMETHODCALLTYPE    IsTemporaryMonoSupported() override;
    virtual HRESULT STDMETHODCALLTYPE Present1(UINT                           SyncInterval,
                                               UINT                           Flags,
                                               const DXGI_PRESENT_PARAMETERS* pPresentParameters) override;
    virtual HRESULT STDMETHODCALLTYPE SetBackgroundColor(const DXGI_RGBA* pColor) override;
    virtual HRESULT STDMETHODCALLTYPE SetRotation(DXGI_MODE_ROTATION Rotation) override;

    // IDXGISwapChain2 methods
    virtual HANDLE STDMETHODCALLTYPE  GetFrameLatencyWaitableObject() override;
    virtual HRESULT STDMETHODCALLTYPE GetMatrixTransform(DXGI_MATRIX_3X2_F* pMatrix) override;
    virtual HRESULT STDMETHODCALLTYPE GetMaximumFrameLatency(UINT* pMaxLatency) override;
    virtual HRESULT STDMETHODCALLTYPE GetSourceSize(UINT* pWidth, UINT* pHeight) override;
    virtual HRESULT STDMETHODCALLTYPE SetMatrixTransform(const DXGI_MATRIX_3X2_F* pMatrix) override;
    virtual HRESULT STDMETHODCALLTYPE SetMaximumFrameLatency(UINT MaxLatency) override;
    virtual HRESULT STDMETHODCALLTYPE SetSourceSize(UINT Width, UINT Height) override;

    // IDXGISwapChain3 methods
    virtual HRESULT STDMETHODCALLTYPE CheckColorSpaceSupport(DXGI_COLOR_SPACE_TYPE ColorSpace,
                                                             UINT*                 pColorSpaceSupport) override;
    virtual UINT STDMETHODCALLTYPE    GetCurrentBackBufferIndex() override;
    virtual HRESULT STDMETHODCALLTYPE ResizeBuffers1(UINT             BufferCount,
                                                     UINT             Width,
                                                     UINT             Height,
                                                     DXGI_FORMAT      NewFormat,
                                                     UINT             SwapChainFlags,
                                                     const UINT*      pCreationNodeMask,
                                                     IUnknown* const* ppPresentQueue) override;

    virtual HRESULT STDMETHODCALLTYPE SetColorSpace1(DXGI_COLOR_SPACE_TYPE ColorSpace) override;

    // IDXGISwapChain4 methods
    virtual HRESULT STDMETHODCALLTYPE SetHDRMetaData(DXGI_HDR_METADATA_TYPE Type, UINT Size, void* pMetaData) override;

  private:
    std::atomic<ULONG> m_ref{ 1 };
    UINT               m_current_back_buffer_index{ 0 };

    // Buffer Description
    UINT                     m_width{ 0 };
    UINT                     m_height{ 0 };
    DXGI_FORMAT              m_format{ DXGI_FORMAT_UNKNOWN };
    DXGI_RATIONAL            m_refresh_rate{ 0, 1 };
    DXGI_MODE_SCANLINE_ORDER m_scanline_order{ DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED };
    DXGI_MODE_SCALING        m_scaling{ DXGI_MODE_SCALING_UNSPECIFIED };
    DXGI_SCALING             m_dxgi_scaling{ DXGI_SCALING_STRETCH }; // from DXGI_SWAP_CHAIN_DESC1::Scaling

    DXGI_SAMPLE_DESC m_sample_desc{ 1, 0 };
    DXGI_USAGE       m_buffer_usage{ DXGI_USAGE_RENDER_TARGET_OUTPUT };
    UINT             m_back_buffer_count{ 0 };
    HWND             m_orig_hwnd{ nullptr };  // Original window handle, nullptr for offscreen
    uint64_t         m_orig_hwnd_id{ 0 };     // Original window handle id, 0 if unavailable
    BOOL             m_orig_windowed{ TRUE }; // Original windowed mode
    DXGI_SWAP_EFFECT m_swap_effect{ DXGI_SWAP_EFFECT_FLIP_DISCARD };
    UINT             m_flags{ 0 };
    BOOL             m_stereo{ FALSE };
    DXGI_ALPHA_MODE  m_alpha_mode{ DXGI_ALPHA_MODE_UNSPECIFIED };

    UINT                  m_present_count{ 0 };
    DXGI_RGBA             m_background_color{ 0.0f, 0.0f, 0.0f, 1.0f };
    DXGI_MODE_ROTATION    m_rotation{ DXGI_MODE_ROTATION_UNSPECIFIED };
    DXGI_MATRIX_3X2_F     m_matrix_transform{ 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f };
    UINT                  m_max_frame_latency{ 1 };
    UINT                  m_source_width{ 0 };
    UINT                  m_source_height{ 0 };
    DXGI_COLOR_SPACE_TYPE m_color_space{ DXGI_COLOR_SPACE_RGB_FULL_G22_NONE_P709 };

    graphics::dx12::ID3D12DeviceComPtr                m_device{ nullptr };
    std::vector<graphics::dx12::ID3D12ResourceComPtr> m_back_buffers;

    // Private data and interfaces storage
    struct GuidHasher
    {
        std::size_t operator()(const GUID& guid) const
        {
            const uint64_t* data = reinterpret_cast<const uint64_t*>(&guid);
            return std::hash<uint64_t>()(data[0]) ^ std::hash<uint64_t>()(data[1]);
        }
    };
    std::unordered_map<GUID, std::vector<uint8_t>, GuidHasher>           m_private_data;
    std::unordered_map<GUID, graphics::dx12::IUnknownComPtr, GuidHasher> m_private_interfaces;

    bool CreateBackBuffers();
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_OFFSCREEN_SWAPCHAIN_H
