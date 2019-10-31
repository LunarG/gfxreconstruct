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
*    AMD CreateDevice Exension API include file.
*    This is the main include file for apps using the CreateDevice extension.
***************************************************************************************************
*/

#ifndef _AMDDXEXTCREATEDEVICE_H_
#define _AMDDXEXTCREATEDEVICE_H_

enum AmdDeviceCreateFlags
{
    AmdDeviceCreateDefault  = 0x00000000,
    AmdDeviceCreateHp3d     = 0x00000001,
};

struct AmdDeviceCreateParam
{
    AmdDeviceCreateFlags flags;
    unsigned int         reserved[15];
};

#endif //_AMDDXEXTCREATEDEVICE_H_
