#include "../Inc/Rte_NvMBlock.h"
#include "../../ASW/Inc/NvMBlockSWC.h"
#include "Std_ReturnType.h"
#include <stdio.h>

/* Store speed data in NVM */
static uint16 storedSpeed = 0;

/****************************************************************************/
//  **Read stored speed from NvM (Rte_Read)**
/****************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RP_NvMBlock_SpeedValue(P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) speed)
{
    if (speed == NULL)
    {
        printf("Error: Rte_Read_StoredSpeed - Null pointer!\n");
        return RTE_E_INVALID;
    }

    *speed = storedSpeed;
    return RTE_E_OK;
}

/****************************************************************************/
//  **Write speed to NvM (Rte_Write)**
/****************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_RP_NvMBlock_SpeedValue(VAR(uint16, AUTOMATIC) speed)
{
    storedSpeed = speed;
    return RTE_E_OK;
}
