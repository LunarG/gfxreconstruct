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

#include "decode/dx12_offscreen_swapchain.h"

#include "util/logging.h"

#include <cstring>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Constructor for Dx12OffscreenSwapchain (used with IDXGIFactory::CreateSwapChain)
Dx12OffscreenSwapchain::Dx12OffscreenSwapchain(ID3D12Device* device, DXGI_SWAP_CHAIN_DESC* desc) :
    m_device(device), m_width(desc->BufferDesc.Width), m_height(desc->BufferDesc.Height),
    m_format(desc->BufferDesc.Format), m_refresh_rate(desc->BufferDesc.RefreshRate),
    m_scanline_order(desc->BufferDesc.ScanlineOrdering), m_scaling(desc->BufferDesc.Scaling),
    m_dxgi_scaling(DXGI_SCALING_STRETCH), // legacy CreateSwapChain always uses stretch
    m_sample_desc(desc->SampleDesc), m_buffer_usage(desc->BufferUsage), m_back_buffer_count(desc->BufferCount),
    m_orig_hwnd(desc->OutputWindow), m_orig_windowed(desc->Windowed), m_swap_effect(desc->SwapEffect),
    m_flags(desc->Flags), m_source_width(desc->BufferDesc.Width), m_source_height(desc->BufferDesc.Height)
{}

// Constructor for Dx12OffscreenSwapchain (used with IDXGIFactory2::CreateSwapChainForHwnd,
// IDXGIFactory2::CreateSwapChainForComposition and IDXGIFactory2::CreateSwapChainForCoreWindow)
Dx12OffscreenSwapchain::Dx12OffscreenSwapchain(ID3D12Device*                    device,
                                               uint64_t                         hwnd_id,
                                               DXGI_SWAP_CHAIN_DESC1*           desc,
                                               DXGI_SWAP_CHAIN_FULLSCREEN_DESC* fullscreen_desc) :
    m_device(device),
    m_width(desc->Width), m_height(desc->Height), m_format(desc->Format),
    m_refresh_rate(fullscreen_desc ? fullscreen_desc->RefreshRate : DXGI_RATIONAL{ 0, 1 }),
    m_scanline_order(fullscreen_desc ? fullscreen_desc->ScanlineOrdering : DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED),
    m_scaling(fullscreen_desc ? fullscreen_desc->Scaling : DXGI_MODE_SCALING_UNSPECIFIED),
    m_dxgi_scaling(desc->Scaling), m_sample_desc(desc->SampleDesc), m_buffer_usage(desc->BufferUsage),
    m_back_buffer_count(desc->BufferCount), m_orig_hwnd_id(hwnd_id),
    m_orig_windowed(fullscreen_desc ? fullscreen_desc->Windowed : TRUE), m_swap_effect(desc->SwapEffect),
    m_flags(desc->Flags), m_stereo(desc->Stereo), m_alpha_mode(desc->AlphaMode), m_source_width(desc->Width),
    m_source_height(desc->Height)
{}

bool Dx12OffscreenSwapchain::CreateBackBuffers()
{
    if ((m_device == nullptr) || (m_back_buffer_count == 0) || (m_width == 0) || (m_height == 0))
    {
        return false;
    }

    m_back_buffers.resize(m_back_buffer_count);

    D3D12_RESOURCE_DESC back_buffer_desc = {};
    back_buffer_desc.MipLevels           = 1;
    back_buffer_desc.Format              = m_format;
    back_buffer_desc.Width               = m_width;
    back_buffer_desc.Height              = m_height;
    back_buffer_desc.Flags               = D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET;
    back_buffer_desc.DepthOrArraySize    = 1;
    back_buffer_desc.SampleDesc.Count    = 1;
    back_buffer_desc.SampleDesc.Quality  = 0;
    back_buffer_desc.Layout              = D3D12_TEXTURE_LAYOUT_UNKNOWN;
    back_buffer_desc.Dimension           = D3D12_RESOURCE_DIMENSION_TEXTURE2D;

    D3D12_HEAP_PROPERTIES heap_properties = {};
    heap_properties.Type                  = D3D12_HEAP_TYPE_DEFAULT;
    heap_properties.CPUPageProperty       = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
    heap_properties.MemoryPoolPreference  = D3D12_MEMORY_POOL_UNKNOWN;
    heap_properties.CreationNodeMask      = 1;
    heap_properties.VisibleNodeMask       = 1;

    D3D12_CLEAR_VALUE clear_value = {};
    clear_value.Format            = m_format;
    clear_value.Color[0]          = 0.0f;
    clear_value.Color[1]          = 0.0f;
    clear_value.Color[2]          = 0.0f;
    clear_value.Color[3]          = 1.0f;

    for (UINT i = 0; i < m_back_buffer_count; ++i)
    {
        HRESULT hr = m_device->CreateCommittedResource(&heap_properties,
                                                       D3D12_HEAP_FLAG_NONE,
                                                       &back_buffer_desc,
                                                       D3D12_RESOURCE_STATE_COMMON,
                                                       &clear_value,
                                                       IID_PPV_ARGS(&m_back_buffers[i]));

        if (FAILED(hr))
        {
            GFXRECON_LOG_ERROR("Failed to create back buffer %u for offscreen swapchain. HRESULT: 0x%X", i, hr);
            return false;
        }
    }

    return true;
}

// Create offscreen swapchain for IDXGIFactory::CreateSwapChain
Microsoft::WRL::ComPtr<Dx12OffscreenSwapchain> Dx12OffscreenSwapchain::Create(ID3D12Device*         device,
                                                                              DXGI_SWAP_CHAIN_DESC* desc)
{
    if ((device == nullptr) || (desc == nullptr))
    {
        return nullptr;
    }

    Microsoft::WRL::ComPtr<Dx12OffscreenSwapchain> swapchain;
    swapchain.Attach(new Dx12OffscreenSwapchain(device, desc));
    if ((swapchain != nullptr) && !swapchain->CreateBackBuffers())
    {
        return nullptr;
    }

    return swapchain;
}

// Create offscreen swapchain for IDXGIFactory2::CreateSwapChainForHwnd, IDXGIFactory2::CreateSwapChainForComposition
// and IDXGIFactory2::CreateSwapChainForCoreWindow
Microsoft::WRL::ComPtr<Dx12OffscreenSwapchain>
Dx12OffscreenSwapchain::Create(ID3D12Device*                    device,
                               uint64_t                         hwnd_id,
                               DXGI_SWAP_CHAIN_DESC1*           desc,
                               DXGI_SWAP_CHAIN_FULLSCREEN_DESC* fullscreen_desc)
{
    if ((device == nullptr) || (desc == nullptr))
    {
        return nullptr;
    }

    Microsoft::WRL::ComPtr<Dx12OffscreenSwapchain> swapchain;
    swapchain.Attach(new Dx12OffscreenSwapchain(device, hwnd_id, desc, fullscreen_desc));
    if ((swapchain != nullptr) && !swapchain->CreateBackBuffers())
    {
        return nullptr;
    }

    return swapchain;
}

HRESULT Dx12OffscreenSwapchain::QueryInterface(REFIID riid, void** ppvObject)
{
    if (!ppvObject)
    {
        return E_POINTER;
    }

    struct InterfaceEntry
    {
        REFIID riid;
        void*  interfacePtr;
    };

    InterfaceEntry interfaces[] = {
        { IID_IUnknown, static_cast<IUnknown*>(this) },
        { IID_IDXGIObject, static_cast<IDXGIObject*>(this) },
        { IID_IDXGIDeviceSubObject, static_cast<IDXGIDeviceSubObject*>(this) },
        { IID_IDXGISwapChain, static_cast<IDXGISwapChain*>(this) },
        { IID_IDXGISwapChain1, static_cast<IDXGISwapChain1*>(this) },
        { IID_IDXGISwapChain2, static_cast<IDXGISwapChain2*>(this) },
        { IID_IDXGISwapChain3, static_cast<IDXGISwapChain3*>(this) },
        { IID_IDXGISwapChain4, static_cast<IDXGISwapChain4*>(this) },
    };

    for (const auto& entry : interfaces)
    {
        if (riid == entry.riid)
        {
            *ppvObject = entry.interfacePtr;
            AddRef();
            return S_OK;
        }
    }

    *ppvObject = nullptr;
    return E_NOINTERFACE;
}

ULONG Dx12OffscreenSwapchain::AddRef()
{
    return ++m_ref;
}

ULONG Dx12OffscreenSwapchain::Release()
{
    ULONG ref = --m_ref;
    if (ref == 0)
    {
        delete this;
    }
    return ref;
}

HRESULT Dx12OffscreenSwapchain::GetParent(REFIID riid, void** ppParent)
{
    GFXRECON_UNREFERENCED_PARAMETER(riid);

    if (!ppParent)
    {
        return E_POINTER;
    }

    *ppParent = nullptr;

    return E_NOINTERFACE;
}

HRESULT Dx12OffscreenSwapchain::GetPrivateData(REFGUID guid, UINT* pDataSize, void* pData)
{
    if (!pDataSize)
    {
        return E_POINTER;
    }

    auto it = m_private_data.find(guid);
    if (it != m_private_data.end())
    {
        const std::vector<BYTE>& data = it->second;
        if (pData == nullptr)
        {
            *pDataSize = static_cast<UINT>(data.size());
            return S_OK;
        }
        else if (*pDataSize >= data.size())
        {
            std::memcpy(pData, data.data(), data.size());
            *pDataSize = static_cast<UINT>(data.size());
            return S_OK;
        }
        else
        {
            *pDataSize = static_cast<UINT>(data.size());
            return DXGI_ERROR_MORE_DATA;
        }
    }

    return DXGI_ERROR_NOT_FOUND;
}

HRESULT Dx12OffscreenSwapchain::SetPrivateData(REFGUID guid, UINT DataSize, const void* pData)
{
    if (!pData || (DataSize == 0))
    {
        m_private_data.erase(guid);
        return S_OK;
    }

    const auto* bytes    = static_cast<const uint8_t*>(pData);
    m_private_data[guid] = std::vector<uint8_t>(bytes, bytes + DataSize);

    return S_OK;
}

HRESULT Dx12OffscreenSwapchain::SetPrivateDataInterface(REFGUID guid, const IUnknown* pUnknown)
{
    if (pUnknown == nullptr)
    {
        m_private_interfaces.erase(guid);
        return S_OK;
    }

    graphics::dx12::IUnknownComPtr spInterface;
    spInterface                = const_cast<IUnknown*>(pUnknown);
    m_private_interfaces[guid] = spInterface;

    return S_OK;
}

HRESULT Dx12OffscreenSwapchain::GetDevice(REFIID riid, void** ppDevice)
{
    if (!ppDevice)
    {
        return E_POINTER;
    }

    return m_device->QueryInterface(riid, ppDevice);
}

HRESULT Dx12OffscreenSwapchain::GetBuffer(UINT Buffer, REFIID riid, void** ppSurface)
{
    if (Buffer >= m_back_buffer_count)
    {
        return DXGI_ERROR_INVALID_CALL;
    }

    if (!ppSurface)
    {
        return E_POINTER;
    }

    return m_back_buffers[Buffer]->QueryInterface(riid, ppSurface);
}

HRESULT Dx12OffscreenSwapchain::GetContainingOutput(IDXGIOutput** ppOutput)
{
    if (!ppOutput)
    {
        return E_POINTER;
    }

    *ppOutput = nullptr; // Offscreen swapchain does not have a containing output
    GFXRECON_LOG_INFO_ONCE("GetContainingOutput is not applicable in offscreen swapchain mode. Offscreen swapchain "
                           "does not have a containing output.");

    return S_OK;
}

HRESULT Dx12OffscreenSwapchain::GetDesc(DXGI_SWAP_CHAIN_DESC* pDesc)
{
    if (!pDesc)
    {
        return E_POINTER;
    }

    pDesc->BufferCount                        = m_back_buffer_count;
    pDesc->BufferDesc.Width                   = m_width;
    pDesc->BufferDesc.Height                  = m_height;
    pDesc->BufferDesc.Format                  = m_format;
    pDesc->BufferDesc.RefreshRate.Numerator   = m_refresh_rate.Numerator;
    pDesc->BufferDesc.RefreshRate.Denominator = m_refresh_rate.Denominator;
    pDesc->BufferDesc.ScanlineOrdering        = m_scanline_order;
    pDesc->BufferDesc.Scaling                 = m_scaling;
    pDesc->SampleDesc.Count                   = m_sample_desc.Count;
    pDesc->SampleDesc.Quality                 = m_sample_desc.Quality;
    pDesc->BufferUsage                        = m_buffer_usage;
    pDesc->OutputWindow                       = nullptr;
    pDesc->Windowed                           = TRUE;
    pDesc->SwapEffect                         = m_swap_effect;
    pDesc->Flags                              = m_flags;

    return S_OK;
}

HRESULT Dx12OffscreenSwapchain::GetFrameStatistics(DXGI_FRAME_STATISTICS* pStats)
{
    if (!pStats)
    {
        return E_POINTER;
    }

    std::memset(pStats, 0, sizeof(DXGI_FRAME_STATISTICS));
    pStats->PresentCount = m_present_count;

    GFXRECON_LOG_INFO_ONCE(
        "GetFrameStatistics is partially supported in offscreen swapchain mode. Only PresentCount is available.");

    return S_OK;
}

HRESULT Dx12OffscreenSwapchain::GetFullscreenState(BOOL* pFullscreen, IDXGIOutput** ppTarget)
{
    if (pFullscreen)
    {
        *pFullscreen = FALSE; // Offscreen swapchain is not fullscreen
    }

    if (ppTarget)
    {
        *ppTarget = nullptr; // No target output
    }

    GFXRECON_LOG_INFO_ONCE("GetFullscreenState is not applicable in offscreen swapchain mode.");

    return S_OK;
}

HRESULT Dx12OffscreenSwapchain::GetLastPresentCount(UINT* pLastPresentCount)
{
    if (!pLastPresentCount)
    {
        return E_POINTER;
    }

    *pLastPresentCount = m_present_count;

    return S_OK;
}

HRESULT Dx12OffscreenSwapchain::Present(UINT SyncInterval, UINT Flags)
{
    GFXRECON_UNREFERENCED_PARAMETER(SyncInterval);
    GFXRECON_UNREFERENCED_PARAMETER(Flags);

    if (m_back_buffer_count > 0)
    {
        m_current_back_buffer_index = (m_current_back_buffer_index + 1) % m_back_buffer_count;
    }
    m_present_count++;

    return S_OK;
}

HRESULT Dx12OffscreenSwapchain::ResizeBuffers(
    UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags)
{
    // Release existing back buffers - buffers are owned by ComPtr, cleared before realloc
    m_back_buffers.clear();

    if (BufferCount == 0)
    {
        BufferCount = m_back_buffer_count;
    }

    // Since there is no real window in offscreen mode, we keep the current buffer dimensions
    // as the best available approximation of the original window size.
    if (Width == 0)
    {
        Width = m_width;
    }
    if (Height == 0)
    {
        Height = m_height;
    }
    if (NewFormat == DXGI_FORMAT_UNKNOWN)
    {
        NewFormat = m_format;
    }

    UINT        prev_count  = m_back_buffer_count;
    UINT        prev_width  = m_width;
    UINT        prev_height = m_height;
    DXGI_FORMAT prev_format = m_format;
    UINT        prev_flags  = m_flags;

    m_back_buffer_count = BufferCount;
    m_width             = Width;
    m_height            = Height;
    m_format            = NewFormat;
    m_flags             = SwapChainFlags;

    if (!CreateBackBuffers())
    {
        GFXRECON_LOG_ERROR("Failed to resize offscreen swapchain buffers.");
        m_back_buffer_count = prev_count;
        m_width             = prev_width;
        m_height            = prev_height;
        m_format            = prev_format;
        m_flags             = prev_flags;
        m_back_buffers.clear();
        return E_FAIL;
    }

    m_current_back_buffer_index = 0;
    m_source_width              = m_width;
    m_source_height             = m_height;

    return S_OK;
}

HRESULT Dx12OffscreenSwapchain::ResizeTarget(const DXGI_MODE_DESC* pNewTargetParameters)
{
    GFXRECON_UNREFERENCED_PARAMETER(pNewTargetParameters);

    // Resize target parameters are not applicable for offscreen swapchain
    GFXRECON_LOG_INFO_ONCE("ResizeTarget is ignored in offscreen swapchain mode. This operation is not supported for "
                           "offscreen rendering.");

    return S_OK;
}

HRESULT Dx12OffscreenSwapchain::SetFullscreenState(BOOL Fullscreen, IDXGIOutput* pTarget)
{
    GFXRECON_UNREFERENCED_PARAMETER(Fullscreen);
    GFXRECON_UNREFERENCED_PARAMETER(pTarget);

    // Offscreen swapchain does not support fullscreen
    GFXRECON_LOG_INFO_ONCE("SetFullscreenState is ignored in offscreen swapchain mode. Fullscreen mode is not "
                           "supported for offscreen rendering.");

    return S_OK;
}

HRESULT Dx12OffscreenSwapchain::GetBackgroundColor(DXGI_RGBA* pColor)
{
    if (!pColor)
    {
        return E_POINTER;
    }

    *pColor = m_background_color;
    GFXRECON_LOG_INFO_ONCE("GetBackgroundColor is not applicable in offscreen swapchain mode. Returning the current "
                           "background color setting.");

    return S_OK;
}

HRESULT Dx12OffscreenSwapchain::GetCoreWindow(REFIID riid, void** ppUnk)
{
    GFXRECON_UNREFERENCED_PARAMETER(riid);

    if (!ppUnk)
    {
        return E_POINTER;
    }

    *ppUnk = nullptr; // Offscreen swapchain does not have a core window
    GFXRECON_LOG_INFO_ONCE("GetCoreWindow is not applicable in offscreen swapchain mode. Offscreen swapchain does not "
                           "have a core window.");

    return E_NOINTERFACE;
}

HRESULT Dx12OffscreenSwapchain::GetDesc1(DXGI_SWAP_CHAIN_DESC1* pDesc)
{
    if (!pDesc)
    {
        return E_POINTER;
    }

    pDesc->Width       = m_width;
    pDesc->Height      = m_height;
    pDesc->Format      = m_format;
    pDesc->Stereo      = m_stereo;
    pDesc->SampleDesc  = m_sample_desc;
    pDesc->BufferUsage = m_buffer_usage;
    pDesc->BufferCount = m_back_buffer_count;
    pDesc->Scaling     = m_dxgi_scaling;
    pDesc->SwapEffect  = m_swap_effect;
    pDesc->AlphaMode   = m_alpha_mode;
    pDesc->Flags       = m_flags;

    return S_OK;
}

HRESULT Dx12OffscreenSwapchain::GetFullscreenDesc(DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pDesc)
{
    if (!pDesc)
    {
        return E_POINTER;
    }

    pDesc->RefreshRate.Numerator   = m_refresh_rate.Numerator;
    pDesc->RefreshRate.Denominator = m_refresh_rate.Denominator;
    pDesc->ScanlineOrdering        = m_scanline_order;
    pDesc->Scaling                 = m_scaling;
    pDesc->Windowed                = TRUE; // Offscreen swapchain is always windowed
    GFXRECON_LOG_INFO_ONCE("GetFullscreenDesc is not applicable in offscreen swapchain mode. Returning the original "
                           "fullscreen description values used during creation.");

    return S_OK;
}

HRESULT Dx12OffscreenSwapchain::GetHwnd(HWND* pHwnd)
{
    if (!pHwnd)
    {
        return E_POINTER;
    }

    *pHwnd = m_orig_hwnd;
    GFXRECON_LOG_INFO_ONCE("GetHwnd is not applicable in offscreen swapchain mode. Returning the original HWND value "
                           "used during creation.");

    return S_OK;
}

HRESULT Dx12OffscreenSwapchain::GetRestrictToOutput(IDXGIOutput** ppOutput)
{
    if (!ppOutput)
    {
        return E_POINTER;
    }

    *ppOutput = nullptr; // Offscreen swapchain does not restrict to any output
    GFXRECON_LOG_INFO_ONCE("GetRestrictToOutput is not applicable in offscreen swapchain mode. Offscreen swapchain "
                           "does not restrict to any output.");

    return S_OK;
}

HRESULT Dx12OffscreenSwapchain::GetRotation(DXGI_MODE_ROTATION* pRotation)
{
    if (!pRotation)
    {
        return E_POINTER;
    }

    *pRotation = m_rotation;
    GFXRECON_LOG_INFO_ONCE("GetRotation is not applicable in offscreen swapchain mode. Returning the original rotation "
                           "value used during creation.");

    return S_OK;
}

BOOL Dx12OffscreenSwapchain::IsTemporaryMonoSupported()
{
    GFXRECON_LOG_INFO_ONCE("IsTemporaryMonoSupported is not applicable in offscreen swapchain mode. Returning FALSE.");

    return FALSE;
}

HRESULT
Dx12OffscreenSwapchain::Present1(UINT SyncInterval, UINT Flags, const DXGI_PRESENT_PARAMETERS* pPresentParameters)
{
    GFXRECON_UNREFERENCED_PARAMETER(pPresentParameters);

    return Present(SyncInterval, Flags);
}

HRESULT Dx12OffscreenSwapchain::SetBackgroundColor(const DXGI_RGBA* pColor)
{
    if (!pColor)
    {
        return E_POINTER;
    }

    m_background_color = *pColor;
    GFXRECON_LOG_INFO_ONCE("SetBackgroundColor is ignored in offscreen swapchain mode. Background color setting is not "
                           "applicable for offscreen rendering.");

    return S_OK;
}

HRESULT Dx12OffscreenSwapchain::SetRotation(DXGI_MODE_ROTATION Rotation)
{
    m_rotation = Rotation;
    GFXRECON_LOG_INFO_ONCE("SetRotation is ignored in offscreen swapchain mode. Rotation setting is not applicable for "
                           "offscreen rendering.");

    return S_OK; // Rotation setting is not implemented for offscreen swapchain
}

HANDLE Dx12OffscreenSwapchain::GetFrameLatencyWaitableObject()
{
    GFXRECON_LOG_INFO_ONCE("GetFrameLatencyWaitableObject is not applicable in offscreen swapchain mode.");

    return nullptr;
}

HRESULT Dx12OffscreenSwapchain::GetMatrixTransform(DXGI_MATRIX_3X2_F* pMatrix)
{
    if (!pMatrix)
    {
        return E_POINTER;
    }

    *pMatrix = m_matrix_transform;
    GFXRECON_LOG_INFO_ONCE(
        "GetMatrixTransform is not applicable in offscreen swapchain mode. Matrix transform setting is "
        "not applicable for offscreen rendering.");

    return S_OK;
}

HRESULT Dx12OffscreenSwapchain::GetMaximumFrameLatency(UINT* pMaxLatency)
{
    if (!pMaxLatency)
    {
        return E_POINTER;
    }

    *pMaxLatency = m_max_frame_latency;
    GFXRECON_LOG_INFO_ONCE(
        "GetMaximumFrameLatency is not applicable in offscreen swapchain mode. Returning the current "
        "maximum frame latency setting.");

    return S_OK;
}

HRESULT Dx12OffscreenSwapchain::GetSourceSize(UINT* pWidth, UINT* pHeight)
{
    if (!pWidth || !pHeight)
    {
        return E_POINTER;
    }

    *pWidth  = m_source_width;
    *pHeight = m_source_height;
    GFXRECON_LOG_INFO_ONCE(
        "GetSourceSize is not applicable in offscreen swapchain mode. Returning the current source size setting.");

    return S_OK;
}

HRESULT Dx12OffscreenSwapchain::SetMatrixTransform(const DXGI_MATRIX_3X2_F* pMatrix)
{
    if (!pMatrix)
    {
        return E_POINTER;
    }

    m_matrix_transform = *pMatrix;
    GFXRECON_LOG_INFO_ONCE("SetMatrixTransform is ignored in offscreen swapchain mode. Matrix transform setting is "
                           "not applicable for offscreen rendering.");

    return S_OK;
}

HRESULT Dx12OffscreenSwapchain::SetMaximumFrameLatency(UINT MaxLatency)
{
    m_max_frame_latency = MaxLatency;
    GFXRECON_LOG_INFO_ONCE(
        "SetMaximumFrameLatency is ignored in offscreen swapchain mode. Maximum frame latency setting is "
        "not applicable for offscreen rendering.");

    return S_OK;
}

HRESULT Dx12OffscreenSwapchain::SetSourceSize(UINT Width, UINT Height)
{
    m_source_width  = Width;
    m_source_height = Height;
    GFXRECON_LOG_INFO_ONCE("SetSourceSize is ignored in offscreen swapchain mode. Source size setting is not "
                           "applicable for offscreen rendering.");

    return S_OK;
}

HRESULT Dx12OffscreenSwapchain::CheckColorSpaceSupport(DXGI_COLOR_SPACE_TYPE ColorSpace, UINT* pColorSpaceSupport)
{
    GFXRECON_UNREFERENCED_PARAMETER(ColorSpace);

    if (!pColorSpaceSupport)
    {
        return E_POINTER;
    }

    *pColorSpaceSupport = 0;
    GFXRECON_LOG_INFO_ONCE("CheckColorSpaceSupport is not applicable in offscreen swapchain mode. No color space "
                           "support is available for offscreen rendering.");

    return S_OK;
}

UINT Dx12OffscreenSwapchain::GetCurrentBackBufferIndex()
{
    return m_current_back_buffer_index;
}

HRESULT Dx12OffscreenSwapchain::ResizeBuffers1(UINT             BufferCount,
                                               UINT             Width,
                                               UINT             Height,
                                               DXGI_FORMAT      NewFormat,
                                               UINT             SwapChainFlags,
                                               const UINT*      pCreationNodeMask,
                                               IUnknown* const* ppPresentQueue)
{
    if (!pCreationNodeMask || !ppPresentQueue)
    {
        return E_POINTER;
    }

    return ResizeBuffers(BufferCount, Width, Height, NewFormat, SwapChainFlags);
}

HRESULT Dx12OffscreenSwapchain::SetColorSpace1(DXGI_COLOR_SPACE_TYPE ColorSpace)
{
    // only store the value, as there is no real swapchain
    m_color_space = ColorSpace;
    GFXRECON_LOG_INFO_ONCE("SetColorSpace1 is ignored in offscreen swapchain mode. Color space setting is not "
                           "applicable for offscreen rendering.");

    return S_OK;
}

HRESULT Dx12OffscreenSwapchain::SetHDRMetaData(DXGI_HDR_METADATA_TYPE Type, UINT Size, void* pMetaData)
{
    GFXRECON_UNREFERENCED_PARAMETER(Type);
    GFXRECON_UNREFERENCED_PARAMETER(Size);
    GFXRECON_UNREFERENCED_PARAMETER(pMetaData);

    // No HDR metadata support in offscreen swapchain
    GFXRECON_LOG_INFO_ONCE("SetHDRMetaData is ignored in offscreen swapchain mode. HDR metadata setting is not "
                           "applicable for offscreen rendering.");

    return S_OK;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
