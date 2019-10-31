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
* @file  AmdDxExtCreateDeviceHp3d.h
* @brief
*    AMD CreateDevice Exension API include file for HP3D.
*    This is the main include file for apps using the CreateDevice extension for HP3D.
***************************************************************************************************
*/

#ifndef _AMDDXEXTCREATEDEVICEHP3D_H_
#define _AMDDXEXTCREATEDEVICEHP3D_H_

#include "AmdDxExtCreateDevice.h"
#include "AmdDxExtCreateDeviceExt.h"

// structure type ID, passed to AmdExtCreateDeviceInfo::amdStructureType
const unsigned int amdStructureTypeIdHp3d = 1;

struct AmdExtCreateInfo : public AmdExtCreateDeviceInfo
{
    AmdDeviceCreateFlags flags;
};

#endif //_AMDDXEXTCREATEDEVICEHP3D_H_
