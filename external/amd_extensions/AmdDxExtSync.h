/*
***************************************************************************************************
*
*  Trade secret of Advanced Micro Devices, Inc.
*  Copyright (c) 2015 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved.  This notice is intended as a precaution against inadvertent publication and
*  does not imply publication or any waiver of confidentiality.  The year included in the foregoing
*  notice is the year of creation of the work.
*
***************************************************************************************************
*/

/**
***************************************************************************************************
* @file  amddxextsync.h
* @brief AMD DX Synchronization Extension API include file.
***************************************************************************************************
*/

#ifndef _AMDDXEXTSYNC_H_
#define _AMDDXEXTSYNC_H_

// This include file contains all the extension definitions
// (structures, enums, constants) shared between the driver and the application

// A constant for application to specify current GPU index
static const UINT AmdCurrentGpuIndex = 0xffffffff;

/**
***************************************************************************************************
* @brief
*    AmdGpuEngine enumeration - Engine to signal/wait on
*
***************************************************************************************************
*/
enum AmdGpuEngine
{
    AmdGpuEngine3D  = 0,    ///< Main 3D engine
    AmdGpuEngineDMA = 1,    ///< DMA engine
};

#endif //_AMDDXEXTSYNC_H_
