/******************************************************************************/
/* System Name : AUTOSAR Non-Volatile Memory Manager (NvM)                    */
/* File Name   : Rte_NvM.c                                                    */
/* Version     : v1.1.0                                                        */
/* Contents    : NvM Implementation for ECU2_FIControl                        */
/* Author      : Updated                                                       */
/* Note        : Handles storage and retrieval of critical data, merged with Rte_NvMBlock */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* Include headers                                                            */
/*----------------------------------------------------------------------------*/
// #include "Rte_NvM.h"
#include "../Inc/Rte_NvM.h"
#include <stdio.h>

/*----------------------------------------------------------------------------*/
/* Static Variables                                                           */
/*----------------------------------------------------------------------------*/
#define NVM_BLOCK_ID_SPEED    0x200U /* NvM Block ID for Speed Storage */
#define NVM_BLOCK_ID_ERRORS   0x201U /* NvM Block ID for DEM Error Storage */
#define NVM_BLOCK_ID_CALIB    0x202U /* NvM Block ID for Calibration Parameters */

static VAR(uint16, AUTOMATIC) NvM_StoredSpeed = 0;
static VAR(uint16, AUTOMATIC) NvM_StoredErrorID = 0;
static VAR(uint8, AUTOMATIC) NvM_StoredErrorStatus = 0;
static VAR(uint16, AUTOMATIC) NvM_StoredCalibration = 0;

/*----------------------------------------------------------------------------*/
/* NvM Speed Storage Implementation                                          */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, NVM_CODE) NvM_WriteSpeed(VAR(uint16, AUTOMATIC) speed)
{
    NvM_StoredSpeed = speed;
    return NvM_WriteBlock(NVM_BLOCK_ID_SPEED, &NvM_StoredSpeed);
}

FUNC(Std_ReturnType, NVM_CODE) NvM_ReadSpeed(P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) speed)
{
    return NvM_ReadBlock(NVM_BLOCK_ID_SPEED, speed);
}

/*----------------------------------------------------------------------------*/
/* NvM DEM Error Storage Implementation                                       */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, NVM_CODE) NvM_WriteError(VAR(uint16, AUTOMATIC) EventID, VAR(uint8, AUTOMATIC) EventStatus)
{
    NvM_StoredErrorID = EventID;
    NvM_StoredErrorStatus = EventStatus;
    return NvM_WriteBlock(NVM_BLOCK_ID_ERRORS, &NvM_StoredErrorID);
}

FUNC(Std_ReturnType, NVM_CODE) NvM_ReadError(P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) EventID, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) EventStatus)
{
    *EventID = NvM_StoredErrorID;
    *EventStatus = NvM_StoredErrorStatus;
    return NvM_ReadBlock(NVM_BLOCK_ID_ERRORS, EventID);
}

/*----------------------------------------------------------------------------*/
/* NvM Calibration Parameter Storage Implementation                           */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, NVM_CODE) NvM_WriteCalibration(VAR(uint16, AUTOMATIC) calibrationValue)
{
    NvM_StoredCalibration = calibrationValue;
    return NvM_WriteBlock(NVM_BLOCK_ID_CALIB, &NvM_StoredCalibration);
}

FUNC(Std_ReturnType, NVM_CODE) NvM_ReadCalibration(P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) calibrationValue)
{
    return NvM_ReadBlock(NVM_BLOCK_ID_CALIB, calibrationValue);
}
