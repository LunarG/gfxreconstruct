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
* @file  AmdDxExtCreateDeviceAppReg.h
* @brief
*    AMD CreateDevice Exension API include file for App Registration.
*    This is the main include file for apps using the CreateDevice extension for App Registration.
***************************************************************************************************
*/

#ifndef _AMDDXEXTCREATEDEVICEAPPREG_H_
#define _AMDDXEXTCREATEDEVICEAPPREG_H_

#include "AmdDxExtApi.h"
#include "AmdDxExtIface.h"
#include "AmdDxExtCreateDeviceExt.h"

#define AMD_MAKE_VERSION(major,minor,patch) ((major << 22) | (minor << 12) | patch)
#define AMD_UNSPECIFIED_VERSION 0xFFFFAD00

// structure type ID, passed to AmdExtCreateDeviceInfo::amdStructureType
const unsigned int amdStructureTypeIdAppReg = 2;

struct AmdExtAppRegInfo : public AmdExtCreateDeviceInfo
{
    const WCHAR*    pAppName;          // application name
    UINT            appVersion;        // application version
    const WCHAR*    pEngineName;       // engine name
    UINT            engineVersion;     // engine version
};


#endif //_AMDDXEXTCREATEDEVICEAPPREG_H_
