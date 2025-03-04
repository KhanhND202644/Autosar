#include "BSW/Inc/Services/Os.h"
#include "RTE/Inc/Rte_FIControl.h"
#include "RTE/Inc/Rte_Can.h"
#include "RTE/Inc/Rte_WdgM.h"
#include "RTE/Inc/Rte_NvM.h"
#include "RTE/Inc/Rte_Dem.h"
#include "RTE/Inc/Rte_CalibPara.h"

#include <stdio.h>
#include <unistd.h>  /* For sleep function */

/*----------------------------------------------------------------------------*/
/* Main Function                                                              */
/*----------------------------------------------------------------------------*/
int main(void)
{
    printf("ECU2_FIControl: System Initializing...\n");
    StartOS(); /* Initialize OS */
    
    /* Restore last stored speed from NvM */
    VAR(uint16, AUTOMATIC) restoredSpeed = 0;
    NvM_ReadSpeed(&restoredSpeed);
    printf("Restored Speed from NvM: %u km/h\n", restoredSpeed);
    
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
        
        /* Save speed to NvM (Flash Memory) */
        NvM_WriteSpeed((uint16)speed);
        
        /* Read back speed from NvM for verification */
        VAR(uint16, AUTOMATIC) flashSpeed = 0;
        NvM_ReadSpeed(&flashSpeed);
        printf("Verified Speed in NvM: %u km/h\n", flashSpeed);
        
        /* Trigger Watchdog */
        R_TriggerWatchdog();
        
        /* Simulate system delay */
        sleep(1);
    }
    
    printf("ECU2_FIControl: System shutting down.\n");
    return 0;
}
