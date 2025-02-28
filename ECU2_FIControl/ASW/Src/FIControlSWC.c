#include "../Inc/FIControlSWC.h"
#include "../../RTE/Inc/Rte_FIControl.h"
#include "BSW/Services/Dem.h"
#include <stdio.h>

/* Static Variables */
static VAR(uint16, FICONTROL_VAR) currentSpeed = 0;
static VAR(uint8, FICONTROL_VAR) injectorState = 0;

/* Initialize FIControl SWC */
FUNC(void, FICONTROL_CODE) FIControlSWC_Init(VAR(void, AUTOMATIC))
{
    printf("FIControl SWC Initialized.\n");
}

/* Runnable: Check Speed and Decide Fuel Injection */
FUNC(Std_ReturnType, FICONTROL_CODE) R_CheckSpeed(VAR(void, AUTOMATIC))
{
    VAR(Std_ReturnType, AUTOMATIC) status = Rte_Read_ReceiveSpeed(&currentSpeed);
    
    if (status == RTE_E_OK)
    {
        printf("Received Speed: %d km/h\n", currentSpeed);
        
        if (currentSpeed > 120)
        {
            injectorState = 0; // Turn off injector
            Rte_Dem_ReportError(DTC_SPEED_LIMIT_EXCEEDED, DEM_EVENT_STATUS_FAILED);
        }
        else
        {
            injectorState = 1; // Turn on injector
            Rte_Dem_ReportError(DTC_SPEED_LIMIT_EXCEEDED, DEM_EVENT_STATUS_PASSED);
        }

        return Rte_Write_InjectorState(injectorState);
    }
    else
    {
        printf("Error: Unable to read speed (Error Code: %d)\n", status);
        return status;
    }
}

/* Runnable: Control Fuel Injector */
FUNC(Std_ReturnType, FICONTROL_CODE) R_ControlFuelInjector(VAR(void, AUTOMATIC))
{
    return Rte_Write_InjectorState(injectorState);
}
