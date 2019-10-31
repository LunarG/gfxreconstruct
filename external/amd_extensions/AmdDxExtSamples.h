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
* @file  amddxextsamples.h
* @brief AMD D3D Samples Extension API include file.
***************************************************************************************************
*/

#ifndef _AMDDXEXTSAMPLES_H_
#define _AMDDXEXTSAMPLES_H_

// This include file contains all the Samples extension definitions
// (structures, enums, constants) shared between the driver and the application

/**
***************************************************************************************************
* @brief
*    AmdDxExtSampleCount enumeration - Used for controlling the Sample Count.
*
***************************************************************************************************
*/
enum AmdDxExtSampleCount
{
    AmdDxExtSampleCount_All         = 0,
    AmdDxExtSampleCount_1xMsaa      = 1,
    AmdDxExtSampleCount_2xMsaa      = 2,
    AmdDxExtSampleCount_4xMsaa      = 3,
    AmdDxExtSampleCount_8xMsaa      = 4,
    AmdDxExtSampleCount_ModeCount   = 5
};

#endif //_AMDDXEXTSAMPLES_H_
