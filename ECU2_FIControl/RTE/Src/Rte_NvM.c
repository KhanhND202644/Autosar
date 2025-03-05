#include "../Inc/Rte_NvM.h"
#include "../../BSW/Inc/Services/NvM.h"

/* Save Speed to NvM */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NvMBlock_StoredSpeed(uint16 speed)
{
    return NvM_WriteBlock(NVM_BLOCK_ID_SPEED, &speed);
}

/* Read Speed from NvM */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NvMBlock_StoredSpeed(VAR(uint16, AUTOMATIC) *speed)
{
    return NvM_ReadBlock(NVM_BLOCK_ID_SPEED, speed);
}
