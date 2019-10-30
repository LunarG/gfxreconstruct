/*
***************************************************************************************************
*
*  Trade secret of Advanced Micro Devices, Inc.
*  Copyright (c) 2017 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved.  This notice is intended as a precaution against inadvertent publication and
*  does not imply publication or any waiver of confidentiality.  The year included in the foregoing
*  notice is the year of creation of the work.
*
***************************************************************************************************
*/

/**
***************************************************************************************************
* @file  amddxextsrbsl.h
* @brief
*    AMD SRBSL (Scale Resolution by Screen Location) Exension API include file.
*    This is the main include file for apps using the SRBSL extension.
***************************************************************************************************
*/

#ifndef _AMDDXEXTSRBSL_H_
#define _AMDDXEXTSRBSL_H_

#include <windows.h>

enum AmdDxEyeTarget
{
    EyeTargetLeft  = 0,
    EyeTargetRight = 1,
};

enum AmdDxEyeTargetMask
{
    EyeTargetMaskDisable = 0, // Disable eye target mask, allows other methods to select RT index.
    EyeTargetMaskLeft    = 1 << EyeTargetLeft,
    EyeTargetMaskRight   = 1 << EyeTargetRight,
};

struct AmdDxSrbslRegions
{
    // All below are specified in pixels in screen.
    struct
    {
        // Half res horizontal bounds.
        // X coord > leftQuaterRes and <= leftHalfRes are rendered in 1/2 resolution.
        UINT leftHalfRes;
        // X coord >= rightHalftRes and < leftQuarterRes are rendered in 1/2 resolution.
        UINT rightHalfRes;
        // Quarter res horizontal bounds.
        // X coord < leftQuaterRes are rendered in 1/4 resolution.
        UINT leftQuarterRes;
        // X coord >= rightQuarterRes are rendered in 1/4 resolution.
        UINT rightQuarterRes;
        // Optional full res region horizontal override
        // X coord > leftFullRes and <= rightFullRes are rendered in full resolution which overrides
        // settings above.
        UINT leftFullRes;
        UINT rightFullRes;
    } eyeHorizBounds[2];

    // Half res vertical bounds.
    // Y coord > topQuarterRes and <= topHalfRes are rendered in 1/2 resolution.
    UINT topHalfRes;
    // Y coord >= bottomQuarterRes and < bottomHalfRes are rendered in 1/2 resolution.
    UINT bottomHalfRes;
    // Quarter res vertical bounds.
    UINT topQuarterRes;
    // Y coord < topQuarterRes are rendered in 1/2 resolution.
    UINT bottomQuarterRes;
    // Optional full res region vertical override.
    // Y coord > topFullRes and <= bottomFullRes are rendered in full resolution which overrides
    // settings above.
    UINT topFullRes;
    UINT bottomFullRes;

    // Viewport index selection for left/right eyes.
    UINT eyeViewport[2];
};

#endif //_AMDDXEXTSRBSL_H_
