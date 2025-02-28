#include "../Inc/Rte_FIControl.h"
#include "../../ASW/Inc/FIControlSWC.h"
#include "Std_ReturnType.h"
#include <stdio.h>


static uint16 lastSpeed = 0;

static uint8 lastInjectorState = 0;

/****************************************************************************/
//  **Read speed from RTE (Rte_Read)**
/****************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RP_FIControl_SpeedData(P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) speed)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = RTE_E_OK;

    if (speed == NULL)
    {
        printf("Error: Rte_Read_SpeedData - Null pointer!\n");
        return RTE_E_INVALID;
    }

    /* Read data from SpeedSensorSWC via RTE */
    ret_val = Rte_Read_SpeedData(speed);
    if (ret_val == RTE_E_OK)
    {
        lastSpeed = *speed;
    }
    else
    {
        *speed = lastSpeed; // Save last speed value
        printf("Warning: Using last speed value due to read error.\n");
    }

    return ret_val;
}

/****************************************************************************/
//  **Write injector state to RTE (Rte_Write)**
/****************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_RP_FIControl_InjectorState(VAR(uint8, AUTOMATIC) injectorState)
{
    lastInjectorState = injectorState;
    
    /* Send status to Hardware Abstraction Layer */
    return IoHwAb_FuelInjector_SetState(injectorState);
}

/****************************************************************************/
//  **Call the CheckSpeed function in SWC (Rte_Call)**
/****************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_RP_FIControlSWC_CheckSpeed(VAR(void, AUTOMATIC))
{
    return R_CheckSpeed();
}
