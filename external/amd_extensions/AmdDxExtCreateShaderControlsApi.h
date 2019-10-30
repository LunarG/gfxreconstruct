/*
***************************************************************************************************
*
*  Trade secret of Advanced Micro Devices, Inc.
*  Copyright (c) 2016 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved.  This notice is intended as a precaution against inadvertent publication and
*  does not imply publication or any waiver of confidentiality.  The year included in the foregoing
*  notice is the year of creation of the work.
*
***************************************************************************************************
*/

/**
***************************************************************************************************
* @file  amddxextcreateshadercontrols.h
* @brief
*    AMD D3D Create Shader Controls API include file.
*    This is the main include file for apps using the Create Shader Controls extension.
***************************************************************************************************
*/


#ifndef _AMDDXEXTCREATESHADERCONTROLSAPI_H_
#define _AMDDXEXTCREATESHADERCONTROLSAPI_H_

#include "AmdDxExtApi.h"
#include "AmdDxExtIface.h"

const unsigned int AmdDxCreateShaderControlsMajorVersion = 1;
const unsigned int AmdDxCreateShaderControlsMinorVersion = 0;
// Extension ID passed to IAmdDxExt::GetExtInterface()
const unsigned int AmdDxExtCreateShaderControlsID = 24;

/**
***************************************************************************************************
* @brief Abstract Create Shader Controls extension interface class
*
***************************************************************************************************
*/
class IAmdDxExtCreateShaderControls : public IAmdDxExtInterface
{
public:
    virtual HRESULT GetExtensionVersion(AmdDxExtVersion* pExtVer) = 0;

    virtual HRESULT SetMaxAsyncCompileThreadCount(unsigned int threadNum) = 0;

    virtual HRESULT NumPendingAsyncCompileJobs(unsigned int* pNumJobs) = 0;

    virtual HRESULT SetDiskShaderCacheEnabled(BOOL enable) = 0;
};

#endif //_AMDDXEXTCREATESHADERCONTROLSAPI_H_
