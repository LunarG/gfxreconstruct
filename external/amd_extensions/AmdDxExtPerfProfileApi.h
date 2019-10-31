/*
***************************************************************************************************
*
*  Trade secret of Advanced Micro Devices, Inc.
*  Copyright (c) 2011 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved. This notice is intended as a precaution against inadvertent publication and
*  does not imply publication or any waiver of confidentiality.  The year included in the foregoing
*  notice is the year of creation of the work.
*
***************************************************************************************************
*/

/**
***************************************************************************************************
* @file  amddxextperfprofileapi.h
* @brief
*    AMD D3D Perf Profile Exension API include file.
*    This is the main include file for apps using perf profile extension.
***************************************************************************************************
*/

#ifndef _AMDDXEXTPERFPROFILEAPI_H_
#define _AMDDXEXTPERFPROFILEAPI_H_

#include "AmdDxExtApi.h"
#include "AmdDxExtIface.h"
#include "AmdDxExtPerfProfile.h"

// Perf Profile extension ID passed to IAmdDxExt::GetExtInterface()
const unsigned int AmdDxExtPerfProfileID = 8;

class IAmdDxExtPerfExperiment;
class IAmdDxExtDriverStats;

/**
***************************************************************************************************
* @brief Abstract perf profile extension interface class
***************************************************************************************************
*/
class IAmdDxExtPerfProfile : public IAmdDxExtInterface
{
public:
    // Get information about feature support and HW capabilities.
    virtual PE_RESULT GetGpuCaps(UINT gpuId, PE_CAPS_INFO* pCaps) = 0;

    // Get information about profiling counter for a particular HW block.
    virtual PE_RESULT GetBlockCounterInfo(UINT gpuId, PE_BLOCK_ID block,
        PE_BLOCK_COUNTER_INFO* pBlockInfo) = 0;

    /// Create empty performance experiment container.
    virtual IAmdDxExtPerfExperiment* CreateExperiment() = 0;

    // Get driver stats container.
    virtual IAmdDxExtDriverStats* GetDriverStats(UINT gpuId) = 0;

    /// Performance experiment container for CFX support
    virtual IAmdDxExtPerfExperiment* CreateExperimentEx(UINT gpuId) = 0;

    // Test if performance experiments can be performed on the given GPU
    virtual PE_RESULT IsGpuProfileable(UINT gpuId, BOOL* pProfileable) = 0;

    // Set the clock mode to the input type and return the current clock rates
    virtual PE_RESULT SetClockMode(PE_CLOCK_MODE mode, PE_SET_CLOCK_MODE_OUTPUT* pOutput) = 0;
};


/**
***************************************************************************************************
* @brief Abstract perf profile extension perf counter interface class
***************************************************************************************************
*/
class IAmdDxExtPerfCounter
{
public:
    // Set summary counter parameter.
    virtual PE_RESULT SetParam(PE_COUNTER_PARAM param, UINT data) = 0;

    // Get summary counter data.
    virtual UINT64 GetData() = 0;

    // Basic constructor
    IAmdDxExtPerfCounter() {};
    virtual ~IAmdDxExtPerfCounter() = 0 {};
};


/**
***************************************************************************************************
* @brief Abstract perf profile extension trace counter interface class
***************************************************************************************************
*/
class IAmdDxExtTraceCounter
{
public:
    // Set trace counter parameter.
    virtual PE_RESULT SetParam(PE_COUNTER_PARAM param, UINT data) = 0;

    // Get trace counter slot.
    virtual UINT GetSlotMapping() = 0;

    // Basic constructor
    IAmdDxExtTraceCounter() {};
    virtual ~IAmdDxExtTraceCounter() = 0 {};
};

/**
***************************************************************************************************
* @brief Abstract perf profile extension trace counter interface class
***************************************************************************************************
*/
class IAmdDxExtStreamingCounter
{
public:
    // Set trace counter parameter.
    virtual PE_RESULT SetParam(PE_COUNTER_PARAM param, UINT data) = 0;

    // Get trace counter slot.
    virtual UINT GetSlotMapping() = 0;

    // Basic constructor
    IAmdDxExtStreamingCounter() {};
    virtual ~IAmdDxExtStreamingCounter() = 0 {};
};

/**
***************************************************************************************************
* @brief Abstract perf profile extension trace base interface class
***************************************************************************************************
*/
class IAmdDxExtTrace
{
public:
    // Set trace buffer parameter.
    virtual PE_RESULT SetBufferParam(PE_TRACE_BUFFER_PARAM param, UINT data) = 0;

    // Get number of trace buffers which have completed collecting data.
    virtual UINT GetCollectedBufferCount() = 0;

    // Lock trace buffer to access trace data.
    virtual PE_RESULT Lock(UINT bufferId, PE_BUFFER_LOCK_DATA* pLockData) = 0;

    // Unlock trace buffer.
    virtual void Unlock(UINT bufferId) = 0;

    // Basic constructor
    IAmdDxExtTrace() {};
    virtual ~IAmdDxExtTrace() = 0 {};
};


/**
***************************************************************************************************
* @brief Abstract perf profile extension thread trace interface class
***************************************************************************************************
*/
class IAmdDxExtThreadTrace : public IAmdDxExtTrace
{
public:
    // Set thread trace parameter.
    virtual PE_RESULT SetParam(PE_THREAD_TRACE_PARAM param, UINT data) = 0;

    // Add a trace counter to the thread trace.
    virtual PE_RESULT AddCounter(UINT eventId, IAmdDxExtTraceCounter** ppCounter) = 0;

    // Basic constructor
    IAmdDxExtThreadTrace() {};
    virtual ~IAmdDxExtThreadTrace() = 0 {};

    // Method to get maximum allocated buffer size for thread trace buffer
    virtual unsigned long long GetMaxThreadTraceBufferSize() = 0;

};


/**
***************************************************************************************************
* @brief Abstract perf profile extension counter stream trace interface class
***************************************************************************************************
*/
class IAmdDxExtCounterStreamTrace : public IAmdDxExtTrace
{
public:
    // Set counter stream trace parameter.
    virtual PE_RESULT SetParam(PE_COUNTER_TRACE_PARAM param, UINT data) = 0;

    // Add a trace counter to the counter stream trace.
    virtual PE_RESULT AddCounter(PE_BLOCK_ID block, UINT instanceId, UINT eventId,
        IAmdDxExtStreamingCounter** ppCounter) = 0;

    // Get the number of bytes of data per output cycle.
    virtual UINT GetByteStride() = 0;

    // Basic constructor
    IAmdDxExtCounterStreamTrace() {};
    virtual ~IAmdDxExtCounterStreamTrace() = 0 {};
};


/**
***************************************************************************************************
* @brief Abstract perf profile extension experiment container interface class
***************************************************************************************************
*/
class IAmdDxExtPerfExperiment
{
public:
    // Set experiment parameters
    virtual PE_RESULT SetParam(PE_EXPERIMENT_PARAM param, UINT data) = 0;

    // Set per engine parameters
    virtual PE_RESULT SetEngineParam(UINT engineId, PE_ENGINE_PARAM param, UINT data) = 0;

    // Add trace to experiment
    virtual PE_RESULT AddTrace(UINT engineId, PE_TRACE_TYPE traceType,
        IAmdDxExtTrace** ppTrace) = 0;

    // Add counter to experiment
    virtual PE_RESULT AddCounter(PE_BLOCK_ID blockId, UINT instanceId, UINT eventId,
        IAmdDxExtPerfCounter** ppCounter) = 0;

    // Build and finalize experiment
    virtual PE_RESULT Finalize() = 0;

    // Run experiment
    virtual PE_RESULT Begin() = 0;

    // Stop experiment
    virtual void End() = 0;

    // Insert data into thread traces.
    virtual PE_RESULT InsertData(PE_TRACE_MARKER_DATA_TYPE param, UINT data) = 0;

    // Waits for the experiment completion
    virtual BOOL WaitCompletion(UINT milliseconds) = 0;

    // Sync with MT worker thread and check how many CB submits ocurred
    virtual UINT GetSubmitCount() = 0;

    // Free internal experiment resources
    virtual void ReleaseResources() = 0;

    // Destroy experiment
    virtual void Destroy() = 0;

    // Basic constructor
    IAmdDxExtPerfExperiment() {};
    virtual ~IAmdDxExtPerfExperiment() = 0 {};

    // Insert thread trace markers.
    virtual void InsertThreadTraceMarker() = 0;

    // Get the count of shader engine
    virtual unsigned int GetNumShaderEngines() = 0;
};


/**
***************************************************************************************************
* @brief Abstract perf profile extension driver statistics interface class
***************************************************************************************************
*/
class IAmdDxExtDriverStats
{
public:
    // Start counting driver profiling events
    virtual void Begin() = 0;

    // Start counting driver profiling events
    virtual void End() = 0;

    // Reset statistics
    virtual void Reset() = 0;

    // Get statistics for the driver event
    virtual PE_RESULT GetEventData(PE_DRIVER_COUNTER counterId, UINT64* pData) = 0;

    // Basic constructor
    IAmdDxExtDriverStats() {};
    virtual ~IAmdDxExtDriverStats() = 0 {};
};

#endif // _AMDDXEXTPERFPROFILEAPI_H_

