#include "../../RTE/Inc/Rte_FIControl.h"
#include "../../BSW/Inc/Services/Dem.h"
#include <stdio.h>

/*----------------------------------------------------------------------------*/
/* Static Variables                                                           */
/*----------------------------------------------------------------------------*/
static VAR(uint8, AUTOMATIC) injectorState = 0; /* 0 = OFF, 1 = ON */
static VAR(float, AUTOMATIC) currentSpeed = 0.0F;

/*----------------------------------------------------------------------------*/
/* Runnable: Check Speed and Control Injector                                 */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, FICONTROL_CODE) R_CheckSpeed(VAR(void, AUTOMATIC))
{
    VAR(Std_ReturnType, AUTOMATIC) status;
    
    /* Read speed from CAN */
    status = Rte_Read_CanSpeed(&currentSpeed);
    if (status != E_OK)
    {
        printf("FIControlSWC: Failed to read speed from CAN. Using default.\n");
        currentSpeed = 0.0F;
    }
    else
    {
        printf("FIControlSWC: Received Speed = %.2f km/h\n", currentSpeed);
    }
    
    /* Call DEM to check for overspeed */
    Dem_CheckSpeed(currentSpeed);
    
    /* Determine injector state based on speed */
    if (currentSpeed > 120.0F)
    {
        injectorState = 0; /* Turn off injector */
    }
    else
    {
        injectorState = 1; /* Turn on injector */
    }
    
    return Rte_Write_InjectorState(injectorState);
}
