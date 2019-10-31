/*
***************************************************************************************************
*
*  Trade secret of Advanced Micro Devices, Inc.
*  Copyright (c) 2017 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved.  This notice is intended as a precaution against inadvertent publication and
*  does not imply publication or any waiver of confidentiality.  The year included in the foregoing
*  notice is the year of creation of the work.
*
***************************************************************************************************
*/

/**
***************************************************************************************************
* @file  amddxextpip.h
* @brief
*   enums / structs for PIP (Picture-in-Picture) extension
***************************************************************************************************
*/

#ifndef _AMDDXEXTPIP_H_
#define _AMDDXEXTPIP_H_

// PIP capability bits
enum AmdDxPipCapFlags
{
    AmdDxPipCap_Supported        = 1 << 0, // Pip is supported by current device
    AmdDxPipCap_Scaling          = 1 << 1, // Scaling is supported
    AmdDxPipCap_GlobalAlpha      = 1 << 2, // Global (uniform) transparency is supported
    AmdDxPipCap_PerPixelAlpha    = 1 << 3, // Per-pixel transparency is supported
    AmdDxPipCap_PresentIntervals = 1 << 4, // Present-Interval value is supported
    AmdDxPipCap_ForceDword       = 0x7fffffff,
};

// PIP SwapChain buffer format support bits
enum AmdDxPipSurfaceFormats
{
    AmdDxPipSurfaceFormat_R8G8B8A8_UNORM     = 1 << 0, // DXGI_R8G8B8A8_UNORM is supported
    AmdDxPipSurfaceFormat_B8G8R8A8_UNORM     = 1 << 1, // DXGI_B8G8R8A8_UNORM is supported
    AmdDxPipSurfaceFormat_R10G10B10A2_UNORM  = 1 << 2, // DXGI_R10G10B10A2_UNORM is supported
    AmdDxPipSurfaceFormat_R16G16B16A16_FLOAT = 1 << 3, // DXGI_R16G16B16A16_FLOAT is supported
    AmdDxPipSurfaceFormat_ForceDword         = 0x7fffffff,
};

// Struct of PIP capability data
struct AmdDxPipDisplayCaps
{
    UINT                   maximumWidth;       // Maximum width of the PIP SwapChain
    UINT                   maximumHeight;      // Maximum height of the PIP SwapChain
    UINT                   maximumBufferCount; // Maximum number of buffers in the SwapChain
    AmdDxPipSurfaceFormats formats;            // Supported SwapChain buffer formats
    AmdDxPipCapFlags       capFlags;           // Supported capabilities
    UINT                   reserved[3];        // Reserved space, do not use.
};

// PIP SawpChain creation option flags
enum AmdDxPipSwapChainFlags
{
    // Use global uniform alpha. If set, Per-pixel alpha is ignored.
    // Can not be used with AmdDxPipSwapChain_UsePerPixelAlpha.
    // Only valid if AmdDxPipCap_GlobalAlpha bit is set from the caps.
    AmdDxPipSwapChain_UseGlobalAlpha             = 1 << 0,

    // Use per-pixel alpha. Global alpha is ignored.
    // Can not be used with AmdDxPipSwapChain_UseGlobalAlpha
    // Only valid if AmdDxPipCap_PerPixelAlpha bit is set from the caps.
    AmdDxPipSwapChain_UsePerPixelAlpha           = 1 << 1,

    // Create SwapChain buffer with bind flag D3D11_BIND_RENDER_TARGET
    AmdDxPipSwapChain_BufferUsageRenderTarget    = 1 << 8,

    // Create SwapChain buffer with bind flag D3D11_BIND_UNORDERED_ACCESS
    AmdDxPipSwapChain_BufferUsageUnorderedAccess = 1 << 9,

    // Create SwapChain buffer with bind flag D3D11_BIND_SHADER_RESOURCE
    AmdDxPipSwapChain_BufferUsageShaderResource  = 1 << 10,

    // Create SwapChain buffer with misc flag D3D11_RESOURCE_MISC_SHARED
    AmdDxPipSwapChain_SharedResource             = 1 << 16,

    // Default value: RenderTarget + Per-Pixel alpha
    AmdDxPipSwapChain_Default                    = AmdDxPipSwapChain_BufferUsageRenderTarget |
                                                   AmdDxPipSwapChain_UsePerPixelAlpha,

    AmdDxPipSwapChain_ForceDword = 0x7fffffff,
};

// PIP SwapChain description data
struct AmdDxPipSwapChainDesc
{
    // Width of the PIP SwapChain buffer
    UINT        width;

    // Height of the PIP SwapChain buffer
    UINT        height;

    // Format of the PIP SwapChain buffer
    DXGI_FORMAT format;

    // Number of buffers,
    // The Minimum value is 2, the maximum value is AmdDxPipDisplayCaps::maximumBufferCount
    UINT        bufferCount;

    // Creation flags, bitwise combination of AmdDxPipSwapChainFlags
    UINT        flags;
};

// PIP SwapChain present flags
enum AmdDxPipPresentFlags
{
    AmdDxPipPresent_Default    = 0,      // Default, present the current back buffer
    AmdDxPipPresent_Hide       = 1 << 0, // Hide the PIP overlay
    AmdDxPipPresent_Test       = 1 << 1, // Test the SwapChain to check PIP availability status
    AmdDxPipPresent_ForceDword = 0x7fffffff,
};

// PIP SwapChain present info
struct AmdDxPipPresentInfo
{
    // Present interval:
    //  0   - Immediate flip
    //  1~4 - Synchronize presentation after the nth vertical blank
    // Only used if AmdDxPipCap_PresentIntervals bit was set from the caps. Otherwise,
    // the extension only supports VSync flip as if presentInterval is always 1.
    UINT    presentInterval;

    // Bitwise combination of AmdDxPipPresentFlags
    UINT    flags;

    // The global transparency. Valid range is [0.0f, 1.0f].
    // Only used if the SwapChain is created with AmdDxPipSwapChain_UseGlobalAlpha flag.
    FLOAT   globalAlpha;

    // Optional, source rectangle
    RECT*   pSrcRect;

    // Optional, destination rectangle
    RECT*   pDestRect;
};

// In case application is using older windows SDK where DXGI_ERROR_NOT_CURRENT is not defined.
enum AmdDxPipPresentError
{
#ifdef DXGI_ERROR_NOT_CURRENT
    AmdDxPipPresentError_NotCurrent = DXGI_ERROR_NOT_CURRENT,
#else
    AmdDxPipPresentError_NotCurrent = 0x887A002EL,
#endif
    AmdDxPipPresentError_ForceDword = 0x7fffffff,
};

#endif // _AMDDXEXTPIP_H_
