/*
***************************************************************************************************
*
*  Trade secret of Advanced Micro Devices, Inc.
*  Copyright (c) 2010 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved.  This notice is intended as a precaution against inadvertent publication and
*  does not imply publication or any waiver of confidentiality.  The year included in the foregoing
*  notice is the year of creation of the work.
*
***************************************************************************************************
*/

/**
***************************************************************************************************
* @file  amddxexttteg.h
* @brief AMD D3D Thread Trace Extension include file for Evergreen.
***************************************************************************************************
*/

#ifndef _AMDDXEXTTTEG_H_
#define _AMDDXEXTTTEG_H_

#define AMDDXTTEG_VERSION_MAJOR 8
#define AMDDXTTEG_VERSION_MINOR 0

static const UINT   AmdDxTTEGMaxShaderEngines  = 2;
static const UINT16 AmdDxTTEGDefaultSIMDEn     = 0xffff;
static const UINT16 AmdDxTTEGDefaultRandomSeed = 0xffff;
static const UINT32 AmdDxTTEGDefaultEventMask  = 0xffffffff;

/**
***************************************************************************************************
* @brief
*    AmdDxTTEGWaveMask enumeration - Used to specifiy wave sampling frequency options.
*
***************************************************************************************************
*/
enum AmdDxTTEGWaveMask
{
    AmdDxTTEGWaveMask_None       = 0,
    AmdDxTTEGWaveMask_All        = 1,
    AmdDxTTEGWaveMask_1_2        = 2,
    AmdDxTTEGWaveMask_1_4        = 3,
    AmdDxTTEGWaveMask_1_8        = 4,
    AmdDxTTEGWaveMask_1_16       = 5,
    AmdDxTTEGWaveMask_1_32       = 6,
    AmdDxTTEGWaveMask_1_64       = 7,
    AmdDxTTEGWaveMask_MaxMask    = 8    // Not a wave mask option.
};

/**
***************************************************************************************************
* @brief
*    AmdDxTTEGMode enumeration - Used to specify tracing mode options.
*
***************************************************************************************************
*/
enum AmdDxTTEGMode
{
    AmdDxTTEGMode_Off            = 0,
    AmdDxTTEGMode_On             = 1,
    AmdDxTTEGMode_Random         = 2,
    AmdDxTTEGMode_MaxModes       = 3     // Not a wave mode option.
};

/**
***************************************************************************************************
* @brief
*    AmdDxTTEGEvent enumeration - Used to specify trace event types.
*
***************************************************************************************************
*/
enum AmdDxTTEGEvent
{
    AmdDxTTEGEvent_WaveStart     = 0,
    AmdDxTTEGEvent_WaveEnd       = 1,
    AmdDxTTEGEvent_WaveAlloc     = 2,
    AmdDxTTEGEvent_IssueAlu      = 3,
    AmdDxTTEGEvent_IssueTc       = 4,
    AmdDxTTEGEvent_IssueVc       = 5,
    AmdDxTTEGEvent_IssueGds      = 6,
    AmdDxTTEGEvent_IssueEx       = 7,
    AmdDxTTEGEvent_IssueSmx      = 8,
    AmdDxTTEGEvent_IssueGf       = 9,
    AmdDxTTEGEvent_IssueGws      = 10,
    AmdDxTTEGEvent_IssueOther    = 11,
    AmdDxTTEGEvent_IssueReject   = 12,
    AmdDxTTEGEvent_ExecAlu       = 13,
    AmdDxTTEGEvent_ExecAlu3      = 14,
    AmdDxTTEGEvent_ExecTc        = 15,
    AmdDxTTEGEvent_ExecVcGds     = 16,
    AmdDxTTEGEvent_ExecEx        = 17,
    AmdDxTTEGEvent_ExecSmx       = 18,
    AmdDxTTEGEvent_SyncAlu       = 19,
    AmdDxTTEGEvent_SyncAlu3      = 20,
    AmdDxTTEGEvent_Bl            = 21,
    AmdDxTTEGEvent_BlJump        = 22,
    AmdDxTTEGEvent_BlJumpOffset  = 23,
    AmdDxTTEGEvent_DoneAlu       = 24,
    AmdDxTTEGEvent_DoneTv        = 25,
    AmdDxTTEGEvent_DoneOther     = 26,
    AmdDxTTEGEvent_AckSmx        = 27,
    AmdDxTTEGEvent_Time          = 28,
    AmdDxTTEGEvent_Reg           = 29,
    AmdDxTTEGEvent_EventDone     = 30,
    AmdDxTTEGEvent_MaxEvent      = 31    // Not an event option.
};

/**
***************************************************************************************************
* @brief
*    AmdDxTTEGEncode enumeration - Used to specify trace encoding formats.
*
***************************************************************************************************
*/
enum AmdDxTTEGEncode
{
    AmdDxTTEGEncode_WaveStart    = 0,
    AmdDxTTEGEncode_OneWave      = 1,
    AmdDxTTEGEncode_ThreeWave    = 2,
    AmdDxTTEGEncode_JumpOffset   = 3,
    AmdDxTTEGEncode_Time         = 4,
    AmdDxTTEGEncode_Reg          = 5,
    AmdDxTTEGEncode_EventDone    = 6,
    AmdDxTTEGEncode_MaxEncode    = 7    // Not an encode option.
};

/**
***************************************************************************************************
* @brief
*    AmdDxTTEGRegType enumeration - Used to specify reg-type events.
*
***************************************************************************************************
*/
enum AmdDxTTEGRegType
{
    AmdDxTTEGRegType_Event       = 0,
    AmdDxTTEGRegType_Draw        = 1,
    AmdDxTTEGRegType_Dispatch    = 2,
    AmdDxTTEGRegType_UserData    = 3,
    AmdDxTTEGRegType_MaxType     = 4    // Not a reg type option.
};

/**
***************************************************************************************************
* @brief
*    AmdDxTTEGThreadType enumeration - Used to specify wave thread types.
*
***************************************************************************************************
*/
enum AmdDxTTEGThreadType
{
    AmdDxTTEGThreadType_Ps       = 0,
    AmdDxTTEGThreadType_Vs       = 1,
    AmdDxTTEGThreadType_Gs       = 2,
    AmdDxTTEGThreadType_Es       = 3,
    AmdDxTTEGThreadType_Hs       = 4,
    AmdDxTTEGThreadType_Ls       = 5,
    AmdDxTTEGThreadType_Cs       = 6,
    AmdDxTTEGThreadType_MaxType  = 7    // Not a thread type option.
};

/**
***************************************************************************************************
* @brief
*    AmdDxTTEGInfo structure - Used to retreive system-specific information.
*
***************************************************************************************************
*/
struct AmdDxTTEGInfo
{
    UINT NumShaderEngines;
    UINT SIMDMask[AmdDxTTEGMaxShaderEngines];
    UINT64 MaxBufSize;
    UINT BufGranularity;
    UINT MaxBufArraySize;
};

/**
***************************************************************************************************
* @brief
*    AmdDxTTEGStateSelect structure - Used to selecting AmdDxTTEGState members during GetConfig and
*    SetConfig calls.
*
***************************************************************************************************
*/
union AmdDxTTEGStateSelect
{
    struct 
    {
        UINT WrapModeSelect        : 1;
        UINT ModeSelect            : 1;
        UINT MaskPsSelect          : 1;
        UINT MaskVsSelect          : 1;
        UINT MaskGsSelect          : 1;
        UINT MaskEsSelect          : 1;
        UINT MaskLsSelect          : 1;
        UINT MaskHsSelect          : 1;
        UINT MaskCsSelect          : 1;
        UINT SIMDEnSelect          : 1;
        UINT RandomSeedSelect      : 1;
        UINT EventMaskSelect       : 1;
    } bitfields, bits;

    UINT    value;
};

/**
***************************************************************************************************
* @brief
*    AmdDxTTEGState structure - Used to set or get thread trace states in GetConfig and 
*    SetConfig calls.
*
***************************************************************************************************
*/
struct AmdDxTTEGState
{
    BOOL WrapMode;
    AmdDxTTEGMode Mode;
    AmdDxTTEGWaveMask MaskPs;
    AmdDxTTEGWaveMask MaskVs;
    AmdDxTTEGWaveMask MaskGs;
    AmdDxTTEGWaveMask MaskEs;
    AmdDxTTEGWaveMask MaskHs;
    AmdDxTTEGWaveMask MaskLs;
    AmdDxTTEGWaveMask MaskCs;
    UINT16 SIMDEn;
    UINT16 RandomSeed;
    UINT32 EventMask;
};

/**
***************************************************************************************************
* @brief
*    AmdDxEGEncodeWaveStart union - used to encode WAVE_START trace packet.
*
***************************************************************************************************
*/
union AmdDxEGEncodeWaveStart
{
    struct
    {
        UINT eventId               : 5;
        UINT timeDelta             : 3;
        UINT wave                  : 8;
        UINT type                  : 3;
        UINT vsNoAlloc             : 1;
        UINT state                 : 3;
        UINT count                 : 5;
        UINT SIMD                  : 4;
    } bits;
    UINT    value;
};

/**
***************************************************************************************************
* @brief
*    AmdDxEGEncodeOneWave union - used to encode ONE_WAVE trace packet.
*
***************************************************************************************************
*/
union AmdDxEGEncodeOneWave
{
    struct
    {
        UINT16 eventId             : 5;
        UINT16 timeDelta           : 3;
        UINT16 wave                : 8;
    } bits;
    UINT16    value;
};


/**
***************************************************************************************************
* @brief
*    AmdDxEGEncodeThreeWave union - used to encode THREE_WAVE trace packet.
*
***************************************************************************************************
*/
union AmdDxEGEncodeThreeWave
{
    struct
    {
        UINT eventId               : 5;
        UINT timeDelta             : 3;
        UINT wave0                 : 8;
        UINT wave1                 : 8;
        UINT wave2                 : 8;
    } bits;
    UINT    value;
};

/**
***************************************************************************************************
* @brief
*    AmdDxEGEncodeJumpOffset union - used to encode JUMP_OFFSET trace packet.
*
***************************************************************************************************
*/
union AmdDxEGEncodeJumpOffset
{
    struct
    {
        UINT eventId               : 5;
        UINT timeDelta             : 3;
        UINT wave                  : 8;
        UINT pcOffset              : 8;
        UINT                       : 8;
    } bits;
    UINT    value;
};

/**
***************************************************************************************************
* @brief
*    AmdDxEGEncodeTime union - used to encode TIME trace packet.
*
***************************************************************************************************
*/
union AmdDxEGEncodeTime
{
    struct
    {
        UINT16 eventId             : 5;
        UINT16 timeDelta           : 9;
        UINT16 timeReset           : 1;
        UINT16 packetLost          : 1;
    } bits;
    UINT16    value;
};

/**
***************************************************************************************************
* @brief
*    AmdDxEGEncodeReg union - used to encode REG trace packet.
*
***************************************************************************************************
*/
union AmdDxEGEncodeReg
{
    struct
    {
        UINT16 eventId             : 5;
        UINT16 state               : 3;
        UINT16 data                : 6;
        UINT16 regType             : 2;
    } bits;
    UINT16    value;
};

/**
***************************************************************************************************
* @brief
*    AmdDxEGEncodeEventDone union - used to encode EVENT_DONE trace packet.
*
***************************************************************************************************
*/
union AmdDxEGEncodeEventDone
{
    struct
    {
        UINT16 eventId             : 5;
        UINT16 state               : 3;
        UINT16 data                : 6;
        UINT16 regType             : 2;
    } bits;
    UINT16    value;
};

#endif // _AMDDXEXTTTEG_H_
