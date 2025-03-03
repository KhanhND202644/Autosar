#include "../Inc/Rte_FIControl.h"
#include <stddef.h>

/* Static Variables */
static uint16 lastSpeed = 0;
static uint8 injectorState = 0;

/****************************************************************************/
/* Read speed from CAN (Rte_Read) */
/****************************************************************************/
FUNC(Std_ReturnType, RTE_CODE_ECU2) Rte_Read_RP_FIControl_ReceiveSpeed(P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) speed)
{
    if (speed == NULL)
    {
        return RTE_E_INVALID;
    }

    *speed = lastSpeed;
    return RTE_E_OK;
}

/****************************************************************************/
/* Write Injector State (Rte_Write) */
/****************************************************************************/
FUNC(Std_ReturnType, RTE_CODE_ECU2) Rte_Write_RP_FIControl_InjectorState(VAR(uint8, AUTOMATIC) state)
{
    injectorState = state;
    return RTE_E_OK;
}
