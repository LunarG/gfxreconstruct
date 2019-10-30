/*
***************************************************************************************************
*
*  Trade secret of Advanced Micro Devices, Inc.
*  Copyright (c) 2015 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved.  This notice is intended as a precaution against inadvertent publication and
*  does not imply publication or any waiver of confidentiality.  The year included in the foregoing
*  notice is the year of creation of the work.
*
***************************************************************************************************
*/
#ifndef _AMDDXEXTAFRCONTROL_H_
#define _AMDDXEXTAFRCONTROL_H_

/**
***************************************************************************************************
* @file  AmdDxExtAfrControl.h
* @brief AMD AFR Control Extension include file
***************************************************************************************************
*/

enum AmdAfrTransferType
{
    AmdAfrTransferDefault               = 0, // driver resource tracking
    AmdAfrTransferDisable               = 1, // turn off driver resource tracking
    AmdAfrTransferApp1StepP2P           = 2, // app controlled GPU to next GPU transfer
    AmdAfrTransferApp2StepNoBroadcast   = 3, // app controlled GPU to next GPU transfer using
                                             // intermediate system memory
    AmdAfrTransferApp2StepWithBroadcast = 4, // app controlled GPU to all render GPUs transfer
                                             // using intermediate system memory
};

enum AmdAfrTransferEngine
{
    AmdAfrTransferEngineDefault         = 0, // use default engine for Crossfire API transfers
    AmdAfrTransferEngine3D              = 1, // use 3D engine for Crossfire API transfers
    AmdAfrTransferEngineCopy            = 2, // use Copy engine for Crossfire API transfers
};

enum AmdCrossfireVisualConfirmationMode
{
    AmdCrossfireVisualConfirmationModeNone      = 0, // Turn off Visual Confirm
    AmdCrossfireVisualConfirmationModeFull      = 1, // Display GPU/Back Buffer Grid + Text
    AmdCrossfireVisualConfirmationModeSimple    = 2, // Display GPU/Back Buffer Grid only
    AmdCrossfireVisualConfirmationModeAfrTall   = 3, // Display GPU/Back Buffer Grid only using
                                                     // tall icons (AFR only)
};

// Properties used to identify unfriendly resources
struct AmdAfrResourceXferInfo
{
    UINT64                      resourceId; // uniquely identifies resource during app's execution
    UINT                        numTransfers; // running total of transfers for this resource
    UINT                        width;
    UINT                        height;
    UINT                        depth;
    UINT                        arraySize;
    UINT                        mipLevels;
    DXGI_FORMAT                 dxgiFormat;
    D3D11_USAGE                 usage;
    UINT                        bindFlags;  // Combination of values in D3D11_BIND_FLAG
    UINT                        cpuAccess;  // Combination of values in D3D11_CPU_ACCESS_FLAG
    UINT                        miscFlags;  // Combination of values in D3D10_DDI_RESOURCE_MISC_FLAG
    AmdAfrTransferType          transferType; // Specifies how this resource is transferred
};

#endif // _AMDDXEXTAFRCONTROL_H_
