#include "../Inc/Rte_CalibPara.h"
#include "../../BSW/Inc/Services/NvM.h"

/* Provide Calibration Data (Rte_Write) */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SpeedThreshold(uint16 threshold)
{
    return NvM_WriteBlock(NVM_BLOCK_ID_CALIB, &threshold);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SpeedThreshold(uint16* threshold)
{
    return NvM_ReadBlock(NVM_BLOCK_ID_CALIB, &threshold);
}