#include "../../Inc/Services/NVM.h"
#include "../../Inc/Services/MemIf.h"
#include <stdio.h>

/*----------------------------------------------------------------------------*/
/* Static Variables                                                           */
/*----------------------------------------------------------------------------*/
VAR(uint16, AUTOMATIC) NvM_StoredSpeed = 0;
VAR(uint16, AUTOMATIC) NvM_StoredErrorID = 0;
VAR(uint8, AUTOMATIC) NvM_StoredErrorStatus = 0;
VAR(uint16, AUTOMATIC) NvM_StoredCalibration = 0;

/*----------------------------------------------------------------------------*/
/* NvM Speed Storage Implementation                                          */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, NVM_CODE) NvM_WriteSpeed(VAR(uint16, AUTOMATIC) speed)
{
    NvM_StoredSpeed = speed;
    return MemIf_Write(NVM_BLOCK_ID_SPEED, (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA))&NvM_StoredSpeed, sizeof(NvM_StoredSpeed), NULL);
}

FUNC(Std_ReturnType, NVM_CODE) NvM_ReadSpeed(P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) speed)
{
    return MemIf_Read(NVM_BLOCK_ID_SPEED, (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA))speed, sizeof(*speed), NULL);
}

/*----------------------------------------------------------------------------*/
/* NvM DEM Error Storage Implementation                                       */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, NVM_CODE) NvM_WriteError(VAR(uint16, AUTOMATIC) EventID, VAR(uint8, AUTOMATIC) EventStatus)
{
    NvM_StoredErrorID = EventID;
    NvM_StoredErrorStatus = EventStatus;
    return MemIf_Write(NVM_BLOCK_ID_ERRORS, (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA))&NvM_StoredErrorID, sizeof(NvM_StoredErrorID), NULL);
}

FUNC(Std_ReturnType, NVM_CODE) NvM_ReadError(P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) EventID, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) EventStatus)
{
    return MemIf_Read(NVM_BLOCK_ID_ERRORS, (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA))EventID, sizeof(*EventID), NULL);
}

/*----------------------------------------------------------------------------*/
/* NvM Calibration Parameter Storage Implementation                           */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, NVM_CODE) NvM_WriteCalibration(VAR(uint16, AUTOMATIC) calibrationValue)
{
    NvM_StoredCalibration = calibrationValue;
    return MemIf_Write(NVM_BLOCK_ID_CALIB, (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA))&NvM_StoredCalibration, sizeof(NvM_StoredCalibration),NULL);
}

FUNC(Std_ReturnType, NVM_CODE) NvM_ReadCalibration(P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) calibrationValue)
{
    return MemIf_Read(NVM_BLOCK_ID_CALIB, (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA))calibrationValue, sizeof(*calibrationValue), NULL);
}
