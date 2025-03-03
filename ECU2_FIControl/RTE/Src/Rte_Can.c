
/*----------------------------------------------------------------------------*/
/* Include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte_Can.h"
#include "ComHwAb_Can.h"
#include <stdio.h>

/*----------------------------------------------------------------------------*/
/* CAN Reception Implementation                                               */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, CANCOM_CODE) Rte_Read_CanSpeed(
    P2VAR(float, AUTOMATIC, RTE_APPL_DATA) speed)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_OK;
    ret_val = ComHwAb_CanReceive(SIGNAL_ID_SPEED, speed);

    if (ret_val != E_OK)
    {
        printf("Warning: Failed to receive speed from CAN\n");
        *speed = 0.0F; /* Default value if read fails */
    }
    else
    {
        printf("Received Speed from CAN: %.2f m/s\n", *speed);
    }

    return ret_val;
}
