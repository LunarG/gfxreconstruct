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
* @file  AmdDxExtCreateDevice.h
* @brief
*    AMD CreateDeviceExt Exension API include file.
*    This is the main include file for apps using the CreateDeviceExt extension.
***************************************************************************************************
*/

#ifndef _AMDDXEXTCREATEDEVICEEXT_H_
#define _AMDDXEXTCREATEDEVICEEXT_H_

struct AmdExtCreateDeviceInfo
{
    UINT                        amdStructureType;
    AmdExtCreateDeviceInfo*     next;
};

#endif //_AMDDXEXTCREATEDEVICEEXT_H_
