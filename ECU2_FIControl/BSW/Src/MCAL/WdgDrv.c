#include "../../Inc/MCAL/WdgDrv.h"
#include <stdio.h>



Std_ReturnType WdgDrv_Trigger(void) {
    printf("[SIM] Watchdog Triggered\n");
    return E_OK;
}


Std_ReturnType WdgDrv_SetMode(uint8 mode) {
    printf("[SIM] Watchdog Mode Set: %d\n", mode);
    return E_OK;
}