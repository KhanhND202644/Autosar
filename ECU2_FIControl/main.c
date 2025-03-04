#include "Os.h"
#include "Rte_FIControl.h"
#include "Rte_Can.h"
#include "Rte_DEM.h"
#include "Rte_NvM.h"
#include "Rte_WdgM.h"
#include "Rte_CalibPara.h"
#include <stdio.h>
#include <unistd.h>  /* For sleep function */

/*----------------------------------------------------------------------------*/
/* Main Function                                                              */
/*----------------------------------------------------------------------------*/
int main(void)
{
    printf("ECU2_FIControl: System Initializing...\n");
    StartOS(); /* Initialize OS */
    
    /* Simulated system loop */
    for (int cycle = 0; cycle < 10; cycle++)
    {
        printf("\n[Cycle %d]\n", cycle);
        Os_RunScheduler(); /* Run OS tasks */

        /* Simulate CAN message reception */
        VAR(float, AUTOMATIC) speed = 80.0F + cycle * 5; /* Increasing speed */
        printf("Simulating CAN reception: Speed = %.2f km/h\n", speed);
        Rte_Write_CanSpeed(speed);
        
        /* Run FIControlSWC processing */
        R_CheckSpeed();
        
        /* Check if overspeed occurs */
        if (speed > 120.0F)
        {
            Dem_ReportErrorStatus(0x1234, DEM_EVENT_STATUS_FAILED);
        }
        
        /* Save speed to NvM */
        NvM_WriteSpeed((uint16)speed);
        
        /* Trigger Watchdog */
        R_TriggerWatchdog();
        
        /* Simulate system delay */
        sleep(1);
    }
    
    printf("ECU2_FIControl: System shutting down.\n");
    return 0;
}
