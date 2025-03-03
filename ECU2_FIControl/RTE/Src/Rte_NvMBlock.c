#include "../Inc/Rte_NvMBlock.h"
#include <stddef.h>

/* Static Variables */
static uint16 storedSpeed = 0;

/****************************************************************************/
/* Read stored speed from NvM (Rte_Read) */
/****************************************************************************/
FUNC(Std_ReturnType, RTE_CODE_ECU2) Rte_Read_RP_NvMBlock_StoredSpeed(P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) speed)
{
    if (speed == NULL)
    {
        return RTE_E_INVALID;
    }

    *speed = storedSpeed;
    return RTE_E_OK;
}

/****************************************************************************/
/* Write stored speed to NvM (Rte_Write) */
/****************************************************************************/
FUNC(Std_ReturnType, RTE_CODE_ECU2) Rte_Write_RP_NvMBlock_StoredSpeed(VAR(uint16, AUTOMATIC) speed)
{
    storedSpeed = speed;
    return RTE_E_OK;
}
