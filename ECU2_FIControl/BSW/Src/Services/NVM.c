#include "../../Inc/Services/NvM.h"
#include "../../Inc/Services/MemIf.h"


VAR(uint16, AUTOMATIC) NvM_StoredSpeed;
VAR(uint16, AUTOMATIC) NvM_StoredErrorID;
VAR(uint8, AUTOMATIC) NvM_StoredErrorStatus;
VAR(uint16, AUTOMATIC) NvM_StoredCalibration;


Std_ReturnType NvM_WriteBlock(uint16 speed) {
    NvM_StoredSpeed = speed;
    return MemIf_Write(MEMIF_FLASH, NVM_BLOCK_ID_SPEED * 0x100, (const uint8*)&speed, sizeof(speed)) ? E_OK : E_NOT_OK;
}

Std_ReturnType NvM_ReadBlock(uint16* speed) {
    return MemIf_Read(MEMIF_FLASH, NVM_BLOCK_ID_SPEED * 0x100, (uint8*)speed, sizeof(*speed)) ? E_OK : E_NOT_OK;
}

Std_ReturnType NvM_WriteCalibration(uint16 calibrationValue) {
    NvM_StoredCalibration = calibrationValue;
    return MemIf_Write(MEMIF_FLASH, NVM_BLOCK_ID_CALIB * 0x100, (const uint8*)&calibrationValue, sizeof(calibrationValue)) ? E_OK : E_NOT_OK;
}

Std_ReturnType NvM_ReadCalibration(uint16* calibrationValue) {
    return MemIf_Read(MEMIF_FLASH, NVM_BLOCK_ID_CALIB * 0x100, (uint8*)calibrationValue, sizeof(*calibrationValue)) ? E_OK : E_NOT_OK;
}