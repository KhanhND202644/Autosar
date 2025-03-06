#include "BSW/Inc/Services/Os.h"
#include "RTE/Inc/Rte_FIControl.h"
#include "RTE/Inc/Rte_Can.h"
#include "RTE/Inc/Rte_WdgM.h"
#include "RTE/Inc/Rte_NvM.h"
#include "RTE/Inc/Rte_Dem.h"
#include "RTE/Inc/Rte_CalibPara.h"
#include "ASW/Inc/FIControlSWC.h"
#include "ASW/Inc/NvMBlockSWC.h"
#include "ASW/Inc/CalibParaSWC.h"

#include <stdio.h>

/*----------------------------------------------------------------------------*/
/* Main Function                                                              */
/*----------------------------------------------------------------------------*/
int main(void)
{
    printf("ECU2_FIControl: System Initializing...\n");
    StartOS(); /* Initialize OS */
    
    /* Initialize core system services */
    Dem_Init(); /* Initialize Diagnostic Event Manager */
    // NvM_Init(); /* Initialize Non-Volatile Memory */
    R_CalibParaSWC_Init(); /* Initialize Calibration Parameters */
    R_FIControl_Init(); /* Initialize FIControl */
    
    /* Activate OS Tasks */
    ActivateTask(TASK_FICONTROL);
    ActivateTask(TASK_CANCOMM);
    ActivateTask(TASK_DEM);
    ActivateTask(TASK_WDGM);
    ActivateTask(TASK_NVM);
    ActivateTask(TASK_CALIBPARA);
    
    /* OS will handle all processing, main function does not interact with RTE */
    while (1)
    {
        Os_RunScheduler(); /* Run OS tasks */
    }
    
    return 0;
}
