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
* @file  amddxextshaderintrinsicsapi.h
* @brief
*    AMD D3D Shader Intrinsics API include file.
*    This is the main include file for apps using the Shader Intrinsics extension.
***************************************************************************************************
*/


#ifndef _AMDDXEXTSHADERINTRINSICSAPI_H_
#define _AMDDXEXTSHADERINTRINSICSAPI_H_

#include "AmdDxExtApi.h"
#include "AmdDxExtIface.h"
#include "AmdDxExtShaderIntrinsics.h"

const unsigned int AmdDxShaderIntrinsicsMajorVersion = 2;
const unsigned int AmdDxShaderIntrinsicsMinorVersion = 8;
// Extension ID passed to IAmdDxExt::GetExtInterface()
const unsigned int AmdDxExtShaderIntrinsicsID = 21;

/**
***************************************************************************************************
* @brief Abstract Shader Intrinsics extension interface class
*
***************************************************************************************************
*/
class IAmdDxExtShaderIntrinsics : public IAmdDxExtInterface
{
public:
    virtual HRESULT GetExtensionVersion(AmdDxExtVersion* pExtVer) = 0;

    virtual HRESULT GetInfo(AmdDxExtShaderIntrinsicsInfo* pIntrinsicsInfo, size_t infoSize) = 0;

    virtual HRESULT CheckSupport(AmdDxExtShaderIntrinsicsSupport opcode) = 0;

    virtual HRESULT Enable() = 0;

    virtual HRESULT SetUAVSlot(unsigned int uavSlot) = 0;
};

#endif //_AMDDXEXTSHADERINTRINSICSAPI_H_
