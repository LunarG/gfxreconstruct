/*
***************************************************************************************************
*
*  Trade secret of Advanced Micro Devices, Inc.
*  Copyright (c) 2014 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved.  This notice is intended as a precaution against inadvertent publication and
*  does not imply publication or any waiver of confidentiality.  The year included in the foregoing
*  notice is the year of creation of the work.
*
***************************************************************************************************
*/
#ifndef _AMDDXEXTMGPUAPPCONTROL_H_
#define _AMDDXEXTMGPUAPPCONTROL_H_

#define APP_CONTROL_MAX_NUM_GPUS 8

enum AmdAppControlTransferEngineId
{
    AmdAppControlTransferEngineId3D = 0,
    AmdAppControlTransferEngineIdTransfer = 1,
};

struct AmdAppControlGpuInfo
{
    UINT reserved[32];      ///< Reserved for future expansion
};

struct AmdAppControlInfo
{
    UINT                    numGpus;        ///< Number of GPUs available for control
    UINT                    maskAllGpus;    ///< GPU Mask representing all active GPUs
    UINT                    maskDisplayGpu; ///< GPU Mask representing the display GPU

    UINT                    reserved[29];   ///< Reserved for future expansion

    AmdAppControlGpuInfo    gpuInfoArray[APP_CONTROL_MAX_NUM_GPUS];
        ///< Array containing information about individual GPUs in a system
};

#endif /_AMDDXEXTMGPUAPPCONTROL_H_
