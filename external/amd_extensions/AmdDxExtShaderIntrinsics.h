/*
***************************************************************************************************
*
*  Trade secret of Advanced Micro Devices, Inc.
*  Copyright (c) 2016 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved.  This notice is intended as a precaution against inadvertent publication and
*  does not imply publication or any waiver of confidentiality.  The year included in the foregoing
*  notice is the year of creation of the work.
*
***************************************************************************************************
*/

/**
***************************************************************************************************
* @file  amddxextshaderintrinsics.h
* @brief
*    AMD D3D Shader Intrinsics API include file.
*    This include file contains the Shader Intrinsics definitions (structures, enums, constant)
*    shared between the driver and the application.
*
***************************************************************************************************
*/

#ifndef _AMDDXEXTSHADERINTRINSICS_H_
#define _AMDDXEXTSHADERINTRINSICS_H_


/**
***************************************************************************************************
* @brief
*    AmdDxExtShaderIntrinsicsInfo structure that defines various support levels by the ASIC
*    for shader instrinsics extension.
***************************************************************************************************
*/
struct AmdDxExtShaderIntrinsicsInfo
{
    unsigned int waveSize;
};

/**
***************************************************************************************************
* @brief
*    Default UAV slot used for encoding intrinsic instructions.
***************************************************************************************************
*/
const unsigned int AmdDxExtShaderIntrinsicsUavSlot      = 7;

/**
***************************************************************************************************
* @brief
*    AmdDxExtShaderIntrinsics instruction encoding
*    [07:00] Instruction opcode               (AmdDxExtShaderIntrinsicsOpcode)
*    [23:08] Opcode-specific data
*    [25:24] Opcode phase
*    [27:26] Reserved
*    [31:28] Shader intrinsics magic code     (AmdDxExtShaderIntrinsics_MagicCode)
*
***************************************************************************************************
*/
const unsigned int AmdDxExtShaderIntrinsics_MagicCodeShift   = 28;
const unsigned int AmdDxExtShaderIntrinsics_MagicCodeMask    = 0xf;
const unsigned int AmdDxExtShaderIntrinsics_OpcodePhaseShift = 24;
const unsigned int AmdDxExtShaderIntrinsics_OpcodePhaseMask  = 0x3;
const unsigned int AmdDxExtShaderIntrinsics_DataShift        = 8;
const unsigned int AmdDxExtShaderIntrinsics_DataMask         = 0xffff;
const unsigned int AmdDxExtShaderIntrinsics_OpcodeShift      = 0;
const unsigned int AmdDxExtShaderIntrinsics_OpcodeMask       = 0xff;


/**
***************************************************************************************************
* @brief
*    AmdDxExtShaderIntrinsics_MagicCode
***************************************************************************************************
*/
const unsigned int AmdDxExtShaderIntrinsics_MagicCode      = 0x5;


/**
***************************************************************************************************
* @brief
*    AmdDxExtShaderIntrinsicsOpcode enumeration
***************************************************************************************************
*/
enum AmdDxExtShaderIntrinsicsOpcode
{
    AmdDxExtShaderIntrinsicsOpcode_Readfirstlane   = 0x01,
    AmdDxExtShaderIntrinsicsOpcode_Readlane        = 0x02,
    AmdDxExtShaderIntrinsicsOpcode_LaneId          = 0x03,
    AmdDxExtShaderIntrinsicsOpcode_Swizzle         = 0x04,
    AmdDxExtShaderIntrinsicsOpcode_Ballot          = 0x05,
    AmdDxExtShaderIntrinsicsOpcode_MBCnt           = 0x06,
    AmdDxExtShaderIntrinsicsOpcode_Min3U           = 0x08,
    AmdDxExtShaderIntrinsicsOpcode_Min3F           = 0x09,
    AmdDxExtShaderIntrinsicsOpcode_Med3U           = 0x0a,
    AmdDxExtShaderIntrinsicsOpcode_Med3F           = 0x0b,
    AmdDxExtShaderIntrinsicsOpcode_Max3U           = 0x0c,
    AmdDxExtShaderIntrinsicsOpcode_Max3F           = 0x0d,
    AmdDxExtShaderIntrinsicsOpcode_BaryCoord       = 0x0e,
    AmdDxExtShaderIntrinsicsOpcode_VtxParam        = 0x0f,
    AmdDxExtShaderIntrinsicsOpcode_ViewportIndex   = 0x10,
    AmdDxExtShaderIntrinsicsOpcode_RtArraySlice    = 0x11,
    AmdDxExtShaderIntrinsicsOpcode_WaveReduce      = 0x12,
    AmdDxExtShaderIntrinsicsOpcode_WaveScan        = 0x13,
    AmdDxExtShaderIntrinsicsOpcode_LastValidOpcode = 0x13,
};

/**
***************************************************************************************************
* @brief
*    AmdDxExtShaderIntrinsicsOpcodePhase enumeration
***************************************************************************************************
*/
enum AmdDxExtShaderIntrinsicsOpcodePhase
{
    AmdDxExtShaderIntrinsicsOpcodePhase_0   = 0x0,
    AmdDxExtShaderIntrinsicsOpcodePhase_1   = 0x1,
    AmdDxExtShaderIntrinsicsOpcodePhase_2   = 0x2,
    AmdDxExtShaderIntrinsicsOpcodePhase_3   = 0x3,
};

/**
***************************************************************************************************
* @brief
*    AmdDxExtShaderIntrinsicsSupport enumeration used to check the opcode type supported by the
*    extension.
***************************************************************************************************
*/
enum AmdDxExtShaderIntrinsicsSupport
{
    AmdDxExtShaderIntrinsicsSupport_Readfirstlane    = 0x01,
    AmdDxExtShaderIntrinsicsSupport_Readlane         = 0x02,
    AmdDxExtShaderIntrinsicsSupport_LaneId           = 0x03,
    AmdDxExtShaderIntrinsicsSupport_Swizzle          = 0x04,
    AmdDxExtShaderIntrinsicsSupport_Ballot           = 0x05,
    AmdDxExtShaderIntrinsicsSupport_MBCnt            = 0x06,
    AmdDxExtShaderIntrinsicsSupport_Compare3         = 0x08,
    AmdDxExtShaderIntrinsicsSupport_Barycentrics     = 0x09,
    AmdDxExtShaderIntrinsicsSupport_MultiViewIndices = 0x0a,
    AmdDxExtShaderIntrinsicsSupport_WaveReduce       = 0x0b,
    AmdDxExtShaderIntrinsicsSupport_WaveScan         = 0x0c,
};

/**
***************************************************************************************************
* @brief
*    AmdDxExtShaderIntrinsicsBarycentric enumeration to specify the interpolation mode
***************************************************************************************************
*/
enum AmdDxExtShaderIntrinsicsBarycentric
{
    AmdDxExtShaderIntrinsicsBarycentric_LinearCenter   = 0x1,
    AmdDxExtShaderIntrinsicsBarycentric_LinearCentroid = 0x2,
    AmdDxExtShaderIntrinsicsBarycentric_LinearSample   = 0x3,
    AmdDxExtShaderIntrinsicsBarycentric_PerspCenter    = 0x4,
    AmdDxExtShaderIntrinsicsBarycentric_PerspCentroid  = 0x5,
    AmdDxExtShaderIntrinsicsBarycentric_PerspSample    = 0x6,
    AmdDxExtShaderIntrinsicsBarycentric_PerspPullModel = 0x7,
};

/**
***************************************************************************************************
* @brief
*    Shifts and masks for the arguments required to reference a vertex parameter
*
*    Encoding:
*    [04:00] Parameter
*    [06:05] Vertex
*    [08:07] Component
*
***************************************************************************************************
*/
const unsigned int AmdDxExtShaderIntrinsicsBarycentric_ParamShift     = 0;
const unsigned int AmdDxExtShaderIntrinsicsBarycentric_ParamMask      = 0x1f;
const unsigned int AmdDxExtShaderIntrinsicsBarycentric_VtxShift       = 0x5;
const unsigned int AmdDxExtShaderIntrinsicsBarycentric_VtxMask        = 0x3;
const unsigned int AmdDxExtShaderIntrinsicsBarycentric_ComponentShift = 0x7;
const unsigned int AmdDxExtShaderIntrinsicsBarycentric_ComponentMask  = 0x3;

/**
***************************************************************************************************
* @brief
*    AmdDxExtShaderIntrinsicsWaveOp enumeration to specify the wave operation
***************************************************************************************************
*/
enum AmdDxExtShaderIntrinsicsWaveOp
{
    AmdDxExtShaderIntrinsicsWaveOp_AddF = 0x01,
    AmdDxExtShaderIntrinsicsWaveOp_AddI = 0x02,
    AmdDxExtShaderIntrinsicsWaveOp_AddU = 0x03,
    AmdDxExtShaderIntrinsicsWaveOp_MulF = 0x04,
    AmdDxExtShaderIntrinsicsWaveOp_MulI = 0x05,
    AmdDxExtShaderIntrinsicsWaveOp_MulU = 0x06,
    AmdDxExtShaderIntrinsicsWaveOp_MinF = 0x07,
    AmdDxExtShaderIntrinsicsWaveOp_MinI = 0x08,
    AmdDxExtShaderIntrinsicsWaveOp_MinU = 0x09,
    AmdDxExtShaderIntrinsicsWaveOp_MaxF = 0x0a,
    AmdDxExtShaderIntrinsicsWaveOp_MaxI = 0x0b,
    AmdDxExtShaderIntrinsicsWaveOp_MaxU = 0x0c,
    AmdDxExtShaderIntrinsicsWaveOp_And  = 0x0d,
    AmdDxExtShaderIntrinsicsWaveOp_Or   = 0x0e,
    AmdDxExtShaderIntrinsicsWaveOp_Xor  = 0x0f,
};

/**
***********************************************************************************************************************
* @brief
*    Shifts and masks for the arguments required for WaveOps
*
*    Encoding:
*    [07:00] Wave Opcode (AmdDxExtShaderIntrinsicsWaveOp)
*    [15:08] Flag
*
***********************************************************************************************************************
*/
const unsigned int AmdDxExtShaderIntrinsicsWaveOp_OpcodeShift = 0;
const unsigned int AmdDxExtShaderIntrinsicsWaveOp_OpcodeMask  = 0xff;
const unsigned int AmdDxExtShaderIntrinsicsWaveOp_FlagShift   = 8;
const unsigned int AmdDxExtShaderIntrinsicsWaveOp_FlagMask    = 0xff;
const unsigned int AmdDxExtShaderIntrinsicsWaveOp_Inclusive   = 0x01;
const unsigned int AmdDxExtShaderIntrinsicsWaveOp_Exclusive   = 0x02;


#endif //_AMDDXEXTSHADERINTRINSICS_H_
