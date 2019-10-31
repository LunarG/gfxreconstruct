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
* @file  amddxexttt.h
* @brief AMD D3D Thread Trace Extension API include file.
***************************************************************************************************
*/

#ifndef _AMDDXEXTTT_H_
#define _AMDDXEXTTT_H_

#include "AmdDxExtTTEG.h"

#define AMDDX_TT_LOCK_FLAG_FLUSH    0x00000000L    // flush buffer if data not ready in LockBuffer
#define AMDDX_TT_LOCK_FLAG_NOFLUSH  0x00000001L    // do not flush buffer if data not ready

/**
***************************************************************************************************
* @brief
*    AmdDxTTTraceStatus enumeration - Used for indicating tracing status of trace buffers.
*
***************************************************************************************************
*/
enum AmdDxTTTraceStatus
{
    AmdDxTTTraceStatus_Inactive     = 0,    // buffer is not in use
    AmdDxTTTraceStatus_Building     = 1,    // buffer is building a trace
    AmdDxTTTraceStatus_IssuedEnd    = 2,    // trace ended because of EndTrace call
    AmdDxTTTraceStatus_IssuedSubmit = 3,    // trace ended because of command buffer submit
    AmdDxTTTraceStatus_Signaled     = 4,    // buffer is locked and readable
    AmdDxTTTraceStatus_Collected    = 5,    // buffer is unlocked: trace is considered collected
    AmdDxTTTraceStatus_MaxModes     = 6     // Not a trace state option.
};

/**
***************************************************************************************************
* @brief
*    AmdDxTTVersion structure - Used to provide version labelling for interface changes.
*
***************************************************************************************************
*/
struct AmdDxTTVersion
{
    UINT16 Major;
    UINT16 Minor;
};

/**
***************************************************************************************************
* @brief
*    AmdDxTTInfo structure - Used to provide system-specific information.
*
***************************************************************************************************
*/
struct AmdDxTTInfo
{
    AmdDxTTVersion Version;
    union
    {
        AmdDxTTEGInfo EGInfo;    // Evergreen run-time thread trace system info
    } Info;
};


/**
***************************************************************************************************
* @brief
*    AmdDxTTConfig structure - Used to retreive and set thread trace state settings.
*
***************************************************************************************************
*/
struct AmdDxTTConfig
{
    AmdDxTTVersion Version;
    union
    {
        AmdDxTTEGStateSelect EGSelect[AmdDxTTEGMaxShaderEngines];    // select mask for State
    } Select;
    union
    {
        AmdDxTTEGState EGState[AmdDxTTEGMaxShaderEngines];           // states to be set/retreived
    } State;
};


/**
***************************************************************************************************
* @brief
*    AmdDxTTBufDesc structure - Used to describe attributes for thread trace buffer allocation.
*
***************************************************************************************************
*/
struct AmdDxTTBufDesc
{
    UINT ShaderEngineId;    // 0-based index of shader engine to allocate buffers for
    UINT BufSizeInBytes;    // size in bytes of buffers to be allocated
    UINT ArrayCount;        // number of buffers to allocate
};


/**
***************************************************************************************************
* @brief
*    AmdDxTTBufInfo structure - used to return thread trace buffer pointers during lock calls.
*
***************************************************************************************************
*/
struct AmdDxTTLockInfo
{
    BYTE* BaseAddress;        // base address of thread trace buffer
    UINT EndDataOffset;       // offset in bytes to end of trace data
    BOOL BufferFullFlag;      // trace buffer full flag
};


/**
***************************************************************************************************
* @brief
*    AmdDxTTData structure - Used to give access to thread trace buffer data.
*    
*
***************************************************************************************************
*/
struct AmdDxTTData
{

    AmdDxTTVersion Version;
    UINT Flags;                  // lock flags
    UINT ShaderEngineId;         // ID if shader engine for buffer to be locked
    UINT BufferIndex;            // index of buffer in array to be locked
    AmdDxTTLockInfo LockInfo;    // buffer lock data
};

/**
***************************************************************************************************
* @brief
*    AmdDxTTTraceStatus structure - Used to return buffer trace stage status.
*
***************************************************************************************************
*/
struct AmdDxTTStatus
{
    AmdDxTTVersion Version;
    union
    {
        UINT EGBufferIndex[AmdDxTTEGMaxShaderEngines];             // buffer index to query
    } Select;
    union
    {
        AmdDxTTTraceStatus EGStatus[AmdDxTTEGMaxShaderEngines];    // tracing status of buffer
    } Status;
};


/**
***************************************************************************************************
* @brief
*    AmdDxTTTraceIndex structure - Used to return array indices of currently building buffers.
*
***************************************************************************************************
*/
struct AmdDxTTTraceIndex
{
    AmdDxTTVersion Version;
    union
    {
        UINT EGTraceIndex[AmdDxTTEGMaxShaderEngines];    // array index of buffer bound for 
    } TraceIndex;                                        // current trace (returned by BeginTrace)
};


#endif // _AMDDXEXTTT_H_
