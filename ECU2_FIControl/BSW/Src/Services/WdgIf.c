#include "../../Inc/Services/WdgIf.h"
#include "../../Inc/MCAL/WdgDrv.h"  
#include <stdio.h>

/*----------------------------------------------------------------------------*/
/* Watchdog Trigger Implementation                                           */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, WDGIF_CODE) WdgIf_TriggerWatchdog(void)
{
    return WdgDrv_Trigger(); /* Calls MCAL Watchdog Driver */
}

/*----------------------------------------------------------------------------*/
/* Watchdog Mode Control Implementation                                      */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, WDGIF_CODE) WdgIf_SetMode(VAR(uint8, AUTOMATIC) mode)
{
    return WdgDrv_SetMode(mode); /* Calls MCAL Watchdog Driver */
}
