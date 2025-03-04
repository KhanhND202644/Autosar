#include "../Inc/NvMBlockSWC.h"
#include "../../RTE/Inc/Rte_NvM.h"
#include <stdio.h>

/* Static Variables */
static VAR(uint16, NVMBLOCK_VAR) storedSpeed = 0;

/* Initialize NvM Block SWC */
FUNC(void, NVMBLOCK_CODE) NvMBlockSWC_Init(VAR(void, AUTOMATIC))
{
    printf("NvM Block SWC Initialized.\n");
}

/* Runnable: Save Speed to NVM */
FUNC(Std_ReturnType, NVMBLOCK_CODE) R_SaveSpeed(VAR(void, AUTOMATIC))
{
    return Rte_Write_StoredSpeed(storedSpeed);
}

/* Runnable: Read Speed from NVM */
FUNC(Std_ReturnType, NVMBLOCK_CODE) R_ReadSpeedFromNVM(VAR(void, AUTOMATIC))
{
    return Rte_Read_StoredSpeed(&storedSpeed);
}
