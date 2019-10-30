/*
***************************************************************************************************
*
*  Trade secret of Advanced Micro Devices, Inc.
*  Copyright (c) 2011 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved.  This notice is intended as a precaution against inadvertent publication and
*  does not imply publication or any waiver of confidentiality.  The year included in the foregoing
*  notice is the year of creation of the work.
*
***************************************************************************************************
*/
/**
***************************************************************************************************
* @file  amddxextperfprofile.h
* @brief
*    AMD D3D Exension API include file. This is a helper include file for extensions. It 
*    provides a common base class for all extension interfaces
***************************************************************************************************
*/
#ifndef _AMDDXPERFPROFILE_H_
#define _AMDDXPERFPROFILE_H_

static const UINT   AmdDxPerfCounterAllInstances = 0xFFFFFFFFL;
static const UINT64 AmdDxPerfInvalidCounterData  = 0xFFFFFFFFFFFFFFFF;
static const UINT   AmdDxPerfInvalidSlotMap      = 0xFFFFFFFFL;
static const UINT   AmdDxPerfInvalidBufferCount  = 0xFFFFFFFFL;

// Interface return values
enum PE_RESULT
{
    PE_OK                       = 0,
    PE_ERROR_OUT_OF_RESOURCES   = 1,
    PE_ERROR_INVALID_ARGUMENT   = 2,
    PE_ERROR_FINALIZED          = 3,
    PE_ERROR_UNAVAILABLE        = 4,
    PE_ERROR_RESOURCE_BUSY      = 5,
    PE_ERROR_OUT_OF_MEMORY      = 6,
    PE_ERROR_NOT_SUPPORTED      = 7,
    PE_ERROR_GPU_NOT_FOUND      = 8,
};

// GPU capabilities flags
enum PE_GPU_CAPS
{
    // Thread trace is supported
    PE_THREAD_TRACE_CAP          = 0x00000001,
    // Thread trace counters are supported
    PE_THREAD_TRACE_COUNTERS_CAP = 0x00000002,
    // Streaming trace counters are supported
    PE_COUNTER_STREAM_TRACE_CAP  = 0x00000004,
};

// Trace types
enum PE_TRACE_TYPE
{
    PE_THREAD_TRACE             = 0,
    PE_STREAMING_COUNTER_TRACE  = 1,
};

// Trace inserted data types
enum PE_TRACE_MARKER_DATA_TYPE
{
    PE_THREAD_TRACE_USER_DATA   = 0,
    PE_THREAD_TRACE_USER_DATA_3 = 0,
    PE_THREAD_TRACE_USER_DATA_2 = 1,
};

// Trace buffer parameters
enum PE_TRACE_BUFFER_PARAM
{
    PE_PARAM_TRACE_BUFFER_SIZE          = 0,
    PE_PARAM_TRACE_BUFFER_ARRAY         = 1,
    PE_PARAM_TRACE_NEW_BUFFER_ON_SUBMIT = 2,
};

// Thread trace parameters
enum PE_THREAD_TRACE_PARAM
{
    PE_PARAM_TT_TOKEN_MASK              = 0,
    PE_PARAM_TT_REG_MASK                = 1,
    PE_PARAM_TT_TARGET_SH               = 2,
    PE_PARAM_TT_TARGET_CU               = 3,
    PE_PARAM_TT_SH0_MASK                = 4,
    PE_PARAM_TT_SH1_MASK                = 5,
    PE_PARAM_TT_SIMD_MASK               = 6,
    PE_PARAM_TT_VM_ID_MASK              = 7,
    PE_PARAM_TT_RANDOM_SEED             = 8,
    PE_PARAM_TT_THREAD_TYPE_MASK        = 9,
    PE_PARAM_TT_ISSUE_MASK              = 10,
    PE_PARAM_TT_WRAP_BUFFER             = 11,
};

// PE_PARAM_TT_TOKEN_MASK selects for SI
enum PE_TT_TOKEN_MASK_SI
{
    PE_TT_TOKEN_MASK_TIME_SI            = 0x00000001,
    PE_TT_TOKEN_MASK_TIMESTAMP_SI       = 0x00000002,
    PE_TT_TOKEN_MASK_REG_SI             = 0x00000004,
    PE_TT_TOKEN_MASK_WAVE_START_SI      = 0x00000008,
    PE_TT_TOKEN_MASK_WAVE_PS_ALLOC_SI   = 0x00000010,
    PE_TT_TOKEN_MASK_WAVE_VS_ALLOC_SI   = 0x00000020,
    PE_TT_TOKEN_MASK_WAVE_END_SI        = 0x00000040,
    PE_TT_TOKEN_MASK_EVENT_SI           = 0x00000080,
    PE_TT_TOKEN_MASK_EVENT_CS_SI        = 0x00000100,
    PE_TT_TOKEN_MASK_EVENT_GFX1_SI      = 0x00000200,
    PE_TT_TOKEN_MASK_INST_SI            = 0x00000400,
    PE_TT_TOKEN_MASK_INST_PC_SI         = 0x00000800,
    PE_TT_TOKEN_MASK_INST_USERDATA_SI   = 0x00001000,
    PE_TT_TOKEN_MASK_ISSUE_SI           = 0x00002000,
    PE_TT_TOKEN_MASK_PERF_SI            = 0x00004000,
    PE_TT_TOKEN_MASK_MISC_SI            = 0x00008000,
    PE_TT_TOKEN_MASK_ALL_SI             = 0x0000ffff,
};

// PE_PARAM_TT_REG_MASK selects
enum PE_TT_REG_MASK_SI
{
   PE_TT_REG_MASK_EVENT_SI      = 0x00000001,
   PE_TT_REG_MASK_DRAW_SI       = 0x00000002,
   PE_TT_REG_MASK_DISPATCH_SI   = 0x00000004,
   PE_TT_REG_MASK_USERDATA_SI   = 0x00000008,
   PE_TT_REG_MASK_GFXDEC_SI     = 0x00000020,
   PE_TT_REG_MASK_SHDEC_SI      = 0x00000040,
   PE_TT_REG_MASK_OTHER_SI      = 0x00000080,
   PE_TT_REG_MASK_ALL_SI        = 0x000000ff,
};

// PE_PARAM_TT_VM_ID_MASK selects
enum PE_TT_VM_ID_MASK
{
    PE_TT_VMID_MASK_SINGLE              = 0,
    PE_TT_VMID_MASK_ALL                 = 1,
    PE_TT_VMID_MASK_SINGLE_DETAIL       = 2,
};

// PE_PARAM_TT_THREAD_TYPE_MASK selects
enum PE_TT_THREAD_TYPE_MASK
{
    PE_THREAD_MASK_PS           = 0x00000001,
    PE_THREAD_MASK_VS           = 0x00000002,
    PE_THREAD_MASK_GS           = 0x00000004,
    PE_THREAD_MASK_ES           = 0x00000008,
    PE_THREAD_MASK_HS           = 0x00000010,
    PE_THREAD_MASK_LS           = 0x00000020,
    PE_THREAD_MASK_CS           = 0x00000040,
    PE_THREAD_MASK_ALL          = 0x0000007f,
};

// PE_PARAM_TT_ISSUE_MASK selects
enum PE_TT_ISSUE_MASK
{
    PE_TT_ISSUE_MASK_ALL                   = 0,
    PE_TT_ISSUE_MASK_STALLED               = 1,
    PE_TT_ISSUE_MASK_STALLED_AND_IMMEDIATE = 2,
    PE_TT_ISSUE_MASK_IMMEDIATE             = 3, // CI only
};

// Trace counter parameters
enum PE_COUNTER_TRACE_PARAM
{
    PE_PARAM_CT_SAMPLE_INTERVAL     = 0,
};

// Shader thread type masks
enum PE_SHADER_MASK
{
    PE_SHADER_MASK_PS           = 0x00000001,
    PE_SHADER_MASK_VS           = 0x00000002,
    PE_SHADER_MASK_GS           = 0x00000004,
    PE_SHADER_MASK_ES           = 0x00000008,
    PE_SHADER_MASK_HS           = 0x00000010,
    PE_SHADER_MASK_LS           = 0x00000020,
    PE_SHADER_MASK_CS           = 0x00000040,
    PE_SHADER_MASK_ALL          = 0x0000007F,
};

// Experiment parameters
enum PE_EXPERIMENT_PARAM
{
    PE_PARAM_GLOBAL_SAMPLING                = 0,
    PE_PARAM_CACHE_FLUSH_ON_PERF_COUNTER    = 1,
    PE_PARAM_SAMPLE_INTERNAL_OPERATIONS     = 2,
    PE_PARAM_RGP_CLIENT                     = 3,
};

// Shader engine parameters
// From GFX7 forward, PE_PARAM_SQ_SHADER_MASK enum value is applied to TA/TD/TCP/TCC/TCA
// counters as well as SQ counters.
// Before GFX7, PE_PARAM_SQ_SHADER_MASK enum value is only applied to SQ counters.
enum PE_ENGINE_PARAM
{
    PE_PARAM_SQ_SHADER_MASK                 = 0,
};

// Software driver counters
enum PE_DRIVER_COUNTER
{
    PE_DRV_VID_MEM_ALLOC                    = 0,
    PE_DRV_RAW_HAZARD_COUNT                 = 1,
    PE_DRV_CB_EXPAND_COUNT                  = 2,
    PE_DRV_DB_EXPAND_COUNT                  = 3,
    PE_DRV_EXCEED_RENAME_LIMIT_COUNT        = 4,
};

// Counter block types
// SDMA and CPF are the CI "replacements" for DRMDMA and CP. They are placed
// at a lesser value than PE_BLOCK_MAX_SI so as to keep the same values as on SI
enum PE_BLOCK_ID : UINT
{
    PE_BLOCK_UNKNOWN = 0,
    PE_BLOCK_DRMDMA,
    PE_BLOCK_SDMA = PE_BLOCK_DRMDMA,
    PE_BLOCK_SRBM,
    PE_BLOCK_CP,
    PE_BLOCK_CPF = PE_BLOCK_CP,
    PE_BLOCK_CB,
    PE_BLOCK_DB,
    PE_BLOCK_GRBM,
    PE_BLOCK_GRBMSE,
    PE_BLOCK_RLC,
    PE_BLOCK_PA,
    PE_BLOCK_SC,
    PE_BLOCK_SX,
    PE_BLOCK_SPI,
    PE_BLOCK_SQ,
    PE_BLOCK_TA,
    PE_BLOCK_TD,
    PE_BLOCK_TCP,
    PE_BLOCK_TCC,
    PE_BLOCK_TCA,
    PE_BLOCK_GDS,
    PE_BLOCK_IA,
    PE_BLOCK_VGT,
    PE_BLOCK_MC,
    PE_BLOCK_MAX_SI,
    PE_BLOCK_CPG,
    PE_BLOCK_CPC,
    PE_BLOCK_WD,
    PE_BLOCK_TCS,
    PE_BLOCK_MAX_CI,
    PE_BLOCK_MCVML2,
    PE_BLOCK_ATC,
    PE_BLOCK_ATCL2,
    PE_BLOCK_RPB,
    PE_BLOCK_EA,
    PE_BLOCK_RMI,
    PE_BLOCK_MAX_GFX9,
    PE_BLOCK_CHA,
    PE_BLOCK_CHC,
    PE_BLOCK_CHCG,
    PE_BLOCK_GCR,
    PE_BLOCK_GE,
    PE_BLOCK_GL1A,
    PE_BLOCK_GL1C,
    PE_BLOCK_GL1CG,
    PE_BLOCK_GL2A,
    PE_BLOCK_GL2C,
    PE_BLOCK_GUS,
    PE_BLOCK_PH,
    PE_BLOCK_UTCL1,
    PE_BLOCK_MAX_GFX10,
};

// Counter parameters
enum PE_COUNTER_PARAM
{
    // SQ counter specific parameters
    PE_COUNTER_SQ_SIMD_MASK  = 1000,
    PE_COUNTER_SQ_SQC_BANK_MASK_CI,
    PE_COUNTER_SQ_SQC_CLIENT_MASK_CI,
};

struct PE_CAPS_INFO
{
    // Extension version
    UINT version;
    // Gpu Caps
    PE_GPU_CAPS gpuCaps;
};

struct PE_BLOCK_COUNTER_INFO
{
    // Number of block instances in a group
    UINT instanceCount;
    // Total number of HW counters available
    UINT totalCounters;
    // Number of counters that could be used as "summary" counters
    UINT summaryOnlyCounters;
    // Max number of streaming counters in the block
    UINT maxStreamingCounters;
    // Max counter event ID
    UINT maxEventId;
    // "Summary" counter data size in bytes (4, 8 bytes)
    UINT summaryDataSize;
    // Block counters can be configured with additional filters
    BOOL hasFilters;
};

struct PE_BUFFER_LOCK_DATA
{
    // Buffer size in bytes
    UINT bufferSize;
    // Current write pointer offset from beginning of the buffer
    UINT wptrOffset;
    // Flag that buffer might have wrapped
    BOOL wrapped;
    // If buffer has wrapped, this could indicate approximate
    // amount of data that was dumpued in the trace buffer
    UINT dataSizeEstimate;
    // Buffer data pointer
    void* pData;
};

enum PE_CLOCK_MODE
{
    // Device clocks and other power settings are restored to default.
    PE_CLOCK_MODE_DEFAULT       = 0,
    // Queries the current device clock ratios. Leaves the clock mode of the device unchanged.
    PE_CLOCK_MODE_QUERY         = 1,
    // Scale down from peak ratio. Clocks are set to a constant amount which is
    // known to be power and thermal sustainable. The engine/memory clock ratio
    // will be kept the same as much as possible.
    PE_CLOCK_MODE_PROFILING     = 2,
    // Memory clock is set to the lowest available level. Engine clock is set to
    // thermal and power sustainable level.
    PE_CLOCK_MODE_MIN_MEMORY    = 3,
    // Engine clock is set to the lowest available level. Memory clock is set to
    // thermal and power sustainable level.
    PE_CLOCK_MODE_MIN_ENGINE    = 4,
    // Clocks set to maximum when possible. Fan set to maximum. Note: Under power
    // and thermal constraints device will clock down.
    PE_CLOCK_MODE_PEAK          = 5,
};

struct PE_SET_CLOCK_MODE_OUTPUT
{
    float memoryClockRatioToPeak;  ///< Ratio of current mem clock to peak clock
    float engineClockRatioToPeak;  ///< Ratio of current gpu core clock to peak clock
};

#endif // _AMDDXPERF_H_
