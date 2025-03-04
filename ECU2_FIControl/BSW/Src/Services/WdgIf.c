#include "../../Inc/Services/WdgIf.h"
#include "../../Inc/MCAL/WdgDrv.h"  
#include <stdio.h>

/*----------------------------------------------------------------------------*/
/* Watchdog Trigger Implementation                                           */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, WDGIF_CODE) WdgIf_TriggerWatchdog(void)
{
    printf("WdgIf: Triggering Watchdog\n");
    return WdgDrv_Trigger(); /* Calls MCAL Watchdog Driver */
}

/*----------------------------------------------------------------------------*/
/* Watchdog Mode Control Implementation                                      */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, WDGIF_CODE) WdgIf_SetMode(VAR(uint8, AUTOMATIC) mode)
{
    printf("WdgIf: Setting Watchdog Mode to %d\n", mode);
    return WdgDrv_SetMode(mode); /* Calls MCAL Watchdog Driver */
}
