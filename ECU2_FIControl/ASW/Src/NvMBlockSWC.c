#include "../Inc/NvMBlockSWC.h"
#include "../../RTE/Inc/Rte_NvM.h"
#include "../../RTE/Inc/Rte_DEM.h"

#include <stdio.h>

/* Static Variable */
static VAR(float, AUTOMATIC) storedSpeed = 0;

/* Runnable: Save Speed to NVM */
FUNC(Std_ReturnType, NVMBLOCK_CODE) R_SaveSpeed(void)
{
    Std_ReturnType status = Rte_Write_NvMBlock_StoredSpeed(storedSpeed);
    if (status != E_OK)
    {
        Rte_Call_DEM_ReportErrorStatus(DTC_P1600_NVM_STORAGE_FAILURE, DEM_EVENT_STATUS_FAILED);
        return E_NOT_OK;
    }
    return E_OK;
}

/* Runnable: Read Speed from NVM */
FUNC(Std_ReturnType, NVMBLOCK_CODE) R_ReadSpeedFromNVM(void)
{
    uint16 tempSpeed;
    Std_ReturnType status = Rte_Read_NvMBlock_StoredSpeed(&tempSpeed);
    storedSpeed = (float)tempSpeed / 10.0F;  // Convert to float
    
    if (status != E_OK)
    {
        Rte_Call_DEM_ReportErrorStatus(DTC_P1600_NVM_STORAGE_FAILURE, DEM_EVENT_STATUS_FAILED);
        storedSpeed = 0.0F; // Safe fallback value
        return E_NOT_OK;
    }
    return E_OK;
}