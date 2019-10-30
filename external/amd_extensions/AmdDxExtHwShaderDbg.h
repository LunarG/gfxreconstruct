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
* @file  AmdDxExtHwShaderDbg.h
* @brief
*    AMD D3D Hardware Shader Debugger extension API include file.
*    This is the main include file for apps using the hardware shader debugger extension.
***************************************************************************************************
*/

#ifndef _AMDDXEXTHWSHADERDBG_H_
#define _AMDDXEXTHWSHADERDBG_H_

struct ID3D11Buffer;
struct ID3D11Resource;

/*
***************************************************************************************************
* @brief AmdDxExtHwShaderDbgPm4Ring enumeration
***************************************************************************************************
*/
enum AmdDxExtHwShaderDbgPm4Ring
{
    Pm4RingGraphics = 0,
    Pm4RingCompute  = 1,
};

/*
***************************************************************************************************
* @brief The AmdDxExtHwShaderDbgShaderType enumeration
***************************************************************************************************
*/
enum AmdDxExtHwShaderDbgShaderType
{
    ShaderTypeCompute  = 0,
    ShaderTypeVertex   = 1,
    ShaderTypeGeometry = 2,
    ShaderTypePixel    = 3,
    ShaderTypeHull     = 4,
    ShaderTypeDomain   = 5,
    ShaderTypeMax      = 6
};

/*
***************************************************************************************************
* @brief BeginDebug input structure
***************************************************************************************************
*/
struct AmdDxExtHwShaderDbgBeginDebugIn
{
    struct
    {
        unsigned int sqDebugMode: 1;
        unsigned int reservedFlags: 31;
    } flags;
    AmdDxExtHwShaderDbgPm4Ring pm4Ring;
    unsigned int               reserved[14];
};

/*
***************************************************************************************************
* @brief SetTrapHandlers input structure
***************************************************************************************************
*/
struct AmdDxExtHwShaderDbgSetTrapHandlersIn
{
    ID3D11Buffer* pTrapHandlers[ShaderTypeMax];
    ID3D11Buffer* pTrapBuffers[ShaderTypeMax];
    unsigned int  reserved[4];
};

/*
***************************************************************************************************
* @brief BeginDebug output structure
***************************************************************************************************
*/
struct AmdDxExtHwShaderDbgBeginDebugOut
{
    unsigned int reserved[16];
};


/*
***************************************************************************************************
* @brief The AmdDxExtHwShaderDbgSqWaveAddr structure
***************************************************************************************************
*/
struct AmdDxExtHwShaderDbgSqWaveAddr
{
    unsigned int shaderEngine;
    unsigned int shaderArray;
    unsigned int computeUnit;
    unsigned int simd;
    unsigned int waveSlot;
    unsigned int reserved[11];
};

/*
***************************************************************************************************
* @brief The AmdDxExtHwShaderDbgSqCmdOp enumeration.  These enums don't start at 0 so they'll
*        match the values expected to be written to the SQ_IND_CMD register.
***************************************************************************************************
*/
enum AmdDxExtHwShaderDbgSqCmdOp
{
    AmdDxSqCmdOpHalt   = 1,
    AmdDxSqCmdOpResume = 2,
    AmdDxSqCmdOpKill   = 3,
    AmdDxSqCmdOpDebug  = 4,
    AmdDxSqCmdOpTrap   = 5,
};

/*
***************************************************************************************************
* @brief The AmdDxExtHwShaderDbgSqCmdMode enumeration
***************************************************************************************************
*/
enum AmdDxExtHwShaderDbgSqCmdMode
{
    AmdDxSqCmdModeSingle            = 0,
    AmdDxSqCmdModeBroadcastVmId     = 1,
    AmdDxSqCmdModeBroadcastVmIdToCu = 2
};

/*
***************************************************************************************************
* @brief The AmdDxExtHwShaderDbgExecuteSqCommandIn structure
***************************************************************************************************
*/
struct AmdDxExtHwShaderDbgExecuteSqCommandIn
{
    AmdDxExtHwShaderDbgSqCmdOp    op;
    AmdDxExtHwShaderDbgSqCmdMode  mode;
    unsigned int                  trapId;
    AmdDxExtHwShaderDbgSqWaveAddr waveAddr;
    unsigned int                  reserved[12];
};

/*
***************************************************************************************************
* @brief The AmdDxExtHwShaderDbgFlushAndInvalidateGpuCachesIn union
***************************************************************************************************
*/
union AmdDxExtHwShaderDbgFlushAndInvalidateGpuCachesIn
{
    struct
    {
        unsigned int sqICache :  1;
        unsigned int sqKCache :  1;
        unsigned int tcL1     :  1;
        unsigned int tcL2     :  1;
        unsigned int reserved : 28;
    } si;
};

/*
***************************************************************************************************
* @brief The AmdDxExtHwShaderDbgSetTrapHandlerIn structure
***************************************************************************************************
*/
struct AmdDxExtHwShaderDbgSetTrapHandlerIn
{
    AmdDxExtHwShaderDbgShaderType shaderType;
    ID3D11Buffer*                 pTrapHandler;
    ID3D11Buffer*                 pTrapBuffer;
    unsigned int                  reserved[11];
};

/*
***************************************************************************************************
* @brief The AmdDxExtHwShaderDbgCompileFlags structure
***************************************************************************************************
*/
union AmdDxExtHwShaderDbgCompileFlags
{
    struct
    {
        unsigned int generateSymbols      :  1;
        unsigned int disableOptimizations :  1;
        unsigned int remapRegsToScratch   :  1;
        unsigned int disableTcL1          :  1;
        unsigned int reserved             : 28;
    };
    unsigned int val;
};

/*
***************************************************************************************************
* @brief The AmdDxExtHwShaderDbgScratchRingType structure
***************************************************************************************************
*/
enum AmdDxExtHwShaderDbgScratchRingType
{
    ScratchRingTypeCompute  = 0,
    ScratchRingTypeGraphics = 1,
};

/*
***************************************************************************************************
* @brief The AmdDxExtHwShaderDbgMapScratchRingIn structure
***************************************************************************************************
*/
struct AmdDxExtHwShaderDbgMapScratchRingIn
{
    AmdDxExtHwShaderDbgScratchRingType scratchRingType;
    unsigned int                       reserved[15];
};

/*
***************************************************************************************************
* @brief The AmdDxExtHwShaderDbgScratchRingOut structure
***************************************************************************************************
*/
struct AmdDxExtHwShaderDbgMapScratchRingOut
{
    void*        pScratchRing;
    SIZE_T       scratchRingSize;
    unsigned int reserved[12];
};

/*
***************************************************************************************************
* @brief The AmdDxExtHwShaderDbgMapBoundHardwareShaderIn structure
***************************************************************************************************
*/
struct AmdDxExtHwShaderDbgMapBoundHardwareShaderIn
{
    AmdDxExtHwShaderDbgShaderType shaderType;
    unsigned int                  reserved[15];
};

/*
***************************************************************************************************
* @brief The AmdDxExtHwShaderDbgMapBoundHardwareShaderOut structure
***************************************************************************************************
*/
struct AmdDxExtHwShaderDbgMapBoundHardwareShaderOut
{
    void*        pShaderMem;
    SIZE_T       shaderMemSize;
    unsigned int reserved[12];
};

/*
***************************************************************************************************
* @brief The AmdDxExtHwShaderDbgUnmapScratchRingIn structure
***************************************************************************************************
*/
struct AmdDxExtHwShaderDbgUnmapScratchRingIn
{
    AmdDxExtHwShaderDbgScratchRingType scratchRingType;
};

/*
***************************************************************************************************
* @brief The AmdDxExtHwShaderDbgUnmapBoundHardwareShaderIn structure
***************************************************************************************************
*/
struct AmdDxExtHwShaderDbgUnmapBoundHardwareShaderIn
{
    AmdDxExtHwShaderDbgShaderType shaderType;
    unsigned int                  reserved[15];
};

/*
***************************************************************************************************
* @brief The AmdDxExtHwShaderDbgGetBoundShaderBinaryIn structure
***************************************************************************************************
*/
struct AmdDxExtHwShaderDbgGetBoundShaderBinaryIn
{
    AmdDxExtHwShaderDbgShaderType shaderType;
    unsigned int                  reserved[15];
};

/*
***************************************************************************************************
* @brief The AmdDxExtHwShaderDbgGetBoundShaderBinaryOut structure
***************************************************************************************************
*/
struct AmdDxExtHwShaderDbgGetBoundShaderBinaryOut
{
    const void*  pShaderBinary;
    size_t       shaderBinarySize;
    unsigned int reserved[12];
};

/*
***************************************************************************************************
* @brief The AmdDxExtHwShaderDbgRegisterDebuggerIn structure
***************************************************************************************************
*/
struct AmdDxExtHwShaderDbgRegisterDebuggerIn
{
    volatile void* pDbgMessages;
    HANDLE         hGpuEventObject;
    unsigned int   reserved[12];
};

/*
***************************************************************************************************
* @brief The AmdDxExtHwShaderDbgQueryShaderState enumeration
***************************************************************************************************
*/
enum AmdDxExtHwShaderDbgQueryShaderState
{
    ShaderStateShaderResourceViewSrd          = 0,
    ShaderStateSamplerSrd                     = 1,
    ShaderStateConstBufSrd                    = 2,
    ShaderStateUavSrd                         = 3,
    ShaderStateScratchBufferSrd               = 4,
};

/*
***************************************************************************************************
* @brief The AmdDxExtHwShaderDbgQueryShaderStateIn structure
***************************************************************************************************
*/
struct AmdDxExtHwShaderDbgQueryShaderStateIn
{
    AmdDxExtHwShaderDbgShaderType       shaderType;
    AmdDxExtHwShaderDbgQueryShaderState state;
    unsigned int                        stateIndex;
    unsigned int                        reserved[13];
};

/*
***************************************************************************************************
* @brief The AmdDxExtHwShaderDbgQueryShaderStateOut structure
***************************************************************************************************
*/
struct AmdDxExtHwShaderDbgQueryShaderStateOut
{
    unsigned int dwordCnt;
    unsigned int result[63];
};

/*
***************************************************************************************************
* @brief Watch modes to be used with SetWatchAddress.
***************************************************************************************************
*/
enum AmdDxExtHwShaderDbgWatchMode
{
    AmdDxExtWatchModeRead    = 0,
    AmdDxExtWatchModeNonread = 1,
    AmdDxExtWatchModeAtomic  = 2,
    AmdDxExtWatchModeAll     = 3
};

/*
***************************************************************************************************
* @brief An individual watch address.
***************************************************************************************************
*/
struct AmdDxExtHwShaderDbgWatchAddress
{
    ID3D11Resource*              pResource; // The resource containing the address to reference
    unsigned long long           offsetX;   // X-offset in the resource
    unsigned long long           offsetY;   // Y-offset in the resource
    unsigned long long           offsetZ;   // Z-offset in the resource
    unsigned int                 mipLevel;  // The mipLevel of the resource to watch
    unsigned int                 watchMask; // A mask to AND with the address
    AmdDxExtHwShaderDbgWatchMode watchMode; // The watch mode for this watch
};

/*
***************************************************************************************************
* @brief List of watch addressses. Input to SetWatchAddress.
***************************************************************************************************
*/
struct AmdDxExtHwShaderDbgSetWatchAddressesIn
{
    AmdDxExtHwShaderDbgWatchAddress* pWatchAddresses;
    unsigned int                     numWatchAddresses;
};

/*
***************************************************************************************************
* @brief Output of QueryWatchAddresses.
***************************************************************************************************
*/
struct AmdDxExtHwShaderDbgQueryWatchAddressesOut
{
    unsigned int numAvailableWatchAddresses;
};


#endif // _AMDDXHWSHADERDBG_H_
