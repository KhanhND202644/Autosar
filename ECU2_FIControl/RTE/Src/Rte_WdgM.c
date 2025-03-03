#include "../Inc/Rte_WdgM.h"
#include <stdio.h>

/*----------------------------------------------------------------------------*/
/* Watchdog Trigger Implementation                                           */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, WDGM_CODE) R_TriggerWatchdog(VAR(void, AUTOMATIC))
{
    printf("WdgM: Triggering Watchdog\n");
    /* Trigger watchdog hardware here if needed */
    return E_OK;
}
