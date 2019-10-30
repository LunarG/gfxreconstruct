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
* @file  amddxextsrbslapi.h
* @brief
*    AMD SRBSL (Scale Resolution by Screen Location) Exension API include file.
*    This is the main include file for apps using the SRBSL extension.
***************************************************************************************************
*/

#ifndef _AMDDXEXTSRBSLAPI_H_
#define _AMDDXEXTSRBSLAPI_H_

#include "AmdDxExtApi.h"
#include "AmdDxExtIface.h"
#include "AmdDxExtSrbsl.h"

const unsigned int AmdDxSrbslMajorVersion = 1;
const unsigned int AmdDxSrbslMinorVersion = 0;
// AMD extension ID passed to IAmdDxExt::GetExtInterface()
const unsigned int AmdDxExtSrbslID = 25;

class IAmdDxExtSrbsl : public IAmdDxExtInterface
{
public:
    // Extension version
    virtual HRESULT GetExtensionVersion(AmdDxExtVersion* pExtVer) = 0;

    // Set regions
    virtual HRESULT SetSrbslRegions(const AmdDxSrbslRegions* pRegions) = 0;
    // Set left/right eye targets for draw
    virtual HRESULT SetDrawEyeTargetMask(UINT targetMask) = 0;
};

#endif // _AMDDXEXTSRBSLAPI_H_