/*
***************************************************************************************************
*
*  Trade secret of Advanced Micro Devices, Inc.
*  Copyright (c) 2012 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved.  This notice is intended as a precaution against inadvertent publication and
*  does not imply publication or any waiver of confidentiality.  The year included in the foregoing
*  notice is the year of creation of the work.
*
***************************************************************************************************
*/

/**
***************************************************************************************************
* @file  AmdDxExtHwShaderDbgApi.h
* @brief
*    AMD D3D Hardware Shader Debugger Extension API include file.
*    This is the main include file for apps using the Hardware Shader Debugger extension.
***************************************************************************************************
*/

#ifndef _AMDDXEXTHWSHADERDBGAPI_H_
#define _AMDDXEXTHWSHADERDBGAPI_H_

#include "AmdDxExtApi.h"
#include "AmdDxExtIface.h"
#include "AmdDxExtHwShaderDbg.h"

// Extended map extension ID passed to IAmdDxExt::GetExtInterface()
const unsigned int AmdDxExtHwShaderDbgID = 10;

/**
***************************************************************************************************
* @brief Abstract hardware shader debugger extension interface class
*
***************************************************************************************************
*/
class IAmdDxExtHwShaderDbg11 : public IAmdDxExtInterface
{
public:
    virtual HRESULT BeginDebug(const AmdDxExtHwShaderDbgBeginDebugIn* pIn,
                               AmdDxExtHwShaderDbgBeginDebugOut*      pOut)         = 0;
    virtual HRESULT SetTrapHandlers(const AmdDxExtHwShaderDbgSetTrapHandlersIn* pIn) = 0;
    virtual HRESULT SetWatchAddresses(const AmdDxExtHwShaderDbgSetWatchAddressesIn* pIn) = 0;
    virtual HRESULT QueryWatchAddresses(AmdDxExtHwShaderDbgQueryWatchAddressesOut* pOut) = 0;
    virtual void EndDebug()                                                         = 0;
    virtual void ExecuteSqCommand(const AmdDxExtHwShaderDbgExecuteSqCommandIn* pIn) = 0;
    virtual HRESULT MapBoundHardwareShader(
                     const AmdDxExtHwShaderDbgMapBoundHardwareShaderIn* pIn,
                     AmdDxExtHwShaderDbgMapBoundHardwareShaderOut*      pOut)       = 0;
    virtual HRESULT MapScratchRing(
                    const AmdDxExtHwShaderDbgMapScratchRingIn* pIn,
                    AmdDxExtHwShaderDbgMapScratchRingOut*      pOut)                = 0;
    virtual HRESULT UnmapBoundHardwareShader(
                     const AmdDxExtHwShaderDbgUnmapBoundHardwareShaderIn* pIn)      = 0;
    virtual HRESULT UnmapScratchRing(
                    const AmdDxExtHwShaderDbgUnmapScratchRingIn* pIn)               = 0;
    virtual void CreateDebuggableComputeShader(
                     const void*                     pShaderBytecode,
                     size_t                          bytecodeLength,
                     ID3D11ClassLinkage*             pClassLinkage,
                     AmdDxExtHwShaderDbgCompileFlags flags,
                     ID3D11ComputeShader**           ppComputeShader)               = 0;
    virtual HRESULT GetBoundShaderBinary(
                     const AmdDxExtHwShaderDbgGetBoundShaderBinaryIn* pIn,
                     AmdDxExtHwShaderDbgGetBoundShaderBinaryOut*      pOut)         = 0;
    virtual void ReleaseShaderBinary(void* pShaderBinary)                           = 0;
    virtual HRESULT RegisterDebugger(const AmdDxExtHwShaderDbgRegisterDebuggerIn* pIn) = 0;
    virtual HRESULT QueryShaderState(
                     const AmdDxExtHwShaderDbgQueryShaderStateIn* pIn,
                     AmdDxExtHwShaderDbgQueryShaderStateOut*      pOut)             = 0;
    virtual HRESULT FlushAndInvalidateGpuCaches(
                        const AmdDxExtHwShaderDbgFlushAndInvalidateGpuCachesIn* pIn) = 0;
};

#endif // _AMDDXHWSHADERDBGAPI_H_
