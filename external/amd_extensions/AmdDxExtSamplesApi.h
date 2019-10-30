/*
***************************************************************************************************
*
*  Trade secret of Advanced Micro Devices, Inc.
*  Copyright (c) 2010 Advanced Micro Devices, Inc. (unpublished)
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
* @brief
*    AMD D3D Samples Exension API include file.
*    This is the main include file for apps using the Samples extension.
***************************************************************************************************
*/

#ifndef _AMDDXEXTSAMPLESAPI_H_
#define _AMDDXEXTSAMPLESAPI_H_

#include "AmdDxExtApi.h"
#include "AmdDxExtIface.h"
#include "AmdDxExtSamples.h"

// Samples extension ID passed to IAmdDxExt::GetExtInterface()
const unsigned int AmdDxExtSamplesID = 5;

/**
***************************************************************************************************
* @brief Abstract Samples extension interface class
***************************************************************************************************
*/
class IAmdDxExtSamples : public IAmdDxExtInterface
{
public:
    virtual HRESULT ReduceSampleCount(AmdDxExtSampleCount sampleCount) = 0;
};

#endif //_AMDDXEXTSAMPLESAPI_H_
