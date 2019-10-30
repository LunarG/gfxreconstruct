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
* @file  amddxextflgl.h
* @brief
*    AMD D3D FrameLock / GenLock include file.
*    This is the enum include file for applications using the FL/GL extension.
***************************************************************************************************
*/

#ifndef _AMDDXEXTFLGL_H_
#define _AMDDXEXTFLGL_H_

// FL/GL support state enum
enum AmdDxFlglSupport
{
    // FL/GL not supported by the GPU
    AmdFlglSupportNotAvailable  = 0,
    // FL/GL support available in the GPU, but is not connected to a GLSync board
    AmdFlglSupportNotConnected  = 1,
    // FL/GL support available and connected
    AmdFlglSupportAvailable     = 2,

    AmdFlglSupportMaxValue      = 3,
    AmdFlglSupportUninitialized = 0xffffffff
};

// Container structure for FL/GL state.
struct AmdDxFlglState
{
    union
    {
        struct
        {
            // True if the respective field in the structure is valid
            UINT genLockEnabledValid            : 1;
            // True if the respective field in the structure is valid
            UINT frameLockEnabledValid          : 1;
            // True if the respective field in the structure is valid
            UINT isTimingMasterValid            : 1;
            // True if the respective field in the structure is valid
            UINT supportValid                   : 1;
            // True if the respective field in the structure is valid
            UINT firmwareVersionValid           : 1;
            UINT reserved : 27;
        };
        UINT u32All;
    } flags;

    union
    {
        struct
        {
            // True if genlock is currently enabled
            UINT genLockEnabled                 : 1;
            // True if framelock is currently enabled
            UINT frameLockEnabled               : 1;
            // True if the display being driven by the current adapter is the timing master
            // in a genlock configuration
            UINT isTimingMaster                 : 1;

            UINT reserved                       : 29;
        };
        UINT32 u32All;
    } state;

    // The state of the FLGL support in current adapter
    AmdDxFlglSupport support;

    // Firmware version number of the GLSync hardware (S400 board), if available
    UINT32 firmwareVersion;

    UINT32 reserved[13];
};

#endif // _AMDDXEXTFLGL_H_
