#include "../../Inc/Services/Os.h"
#include "../../../RTE/Inc/Rte_FIControl.h"
#include "../../../RTE/Inc/Rte_Can.h"
#include "../../../RTE/Inc/Rte_DEM.h"
#include "../../../RTE/Inc/Rte_NvM.h"
#include "../../../RTE/Inc/Rte_WdgM.h"
#include "../../../RTE/Inc/Rte_CalibPara.h"
#include <stdio.h>

/*----------------------------------------------------------------------------*/
/* Static Variables                                                           */
/*----------------------------------------------------------------------------*/
static VAR(uint8, AUTOMATIC) TaskStatus[NUM_OF_TASKS] = {0}; /* Stores active tasks */
static VAR(uint8, AUTOMATIC) EventStatus[NUM_OF_TASKS] = {0}; /* Stores event flags */
static VAR(uint32, AUTOMATIC) Os_Time = 0; /* System time */

/*----------------------------------------------------------------------------*/
/* OS Initialization                                                          */
/*----------------------------------------------------------------------------*/
FUNC(void, OS_CODE) Os_RunScheduler(void); /* Ensure function is declared before use */

FUNC(void, OS_CODE) StartOS(void) {
    /* OS Initialization Code */
    Os_RunScheduler();
}


/*----------------------------------------------------------------------------*/
/* Activate Task                                                              */
/*----------------------------------------------------------------------------*/
FUNC(void, OS_CODE) ActivateTask(TaskType TaskID)
{
    if (TaskID < NUM_OF_TASKS)
    {
        TaskStatus[TaskID] = 1;
        printf("OS: Task %d Activated\n", TaskID);
    }
}

/*----------------------------------------------------------------------------*/
/* Terminate Task                                                             */
/*----------------------------------------------------------------------------*/
FUNC(void, OS_CODE) TerminateTask(void)
{
    printf("OS: Task Terminated\n");
}

/*----------------------------------------------------------------------------*/
/* Set Event for Task                                                         */
/*----------------------------------------------------------------------------*/
FUNC(void, OS_CODE) SetEvent(TaskType TaskID, EventMaskType EventMask)
{
    if (TaskID < NUM_OF_TASKS)
    {
        EventStatus[TaskID] |= EventMask;
        printf("OS: Event %d set for Task %d\n", EventMask, TaskID);
    }
}

/*----------------------------------------------------------------------------*/
/* Clear Event                                                                */
/*----------------------------------------------------------------------------*/
FUNC(void, OS_CODE) ClearEvent(EventMaskType EventMask)
{
    printf("OS: Event %d Cleared\n", EventMask);
}

/*----------------------------------------------------------------------------*/
/* OS Scheduler (Runs in a loop)                                              */
/*----------------------------------------------------------------------------*/
FUNC(void, OS_CODE) Os_RunScheduler(void)
{
    while (1) /* Infinite loop to simulate real-time OS behavior */
    {
        Os_Time++;

        /* Run Tasks based on schedule */
        if (Os_Time % 10 == 0) ActivateTask(TASK_FICONTROL);
        if (Os_Time % 5 == 0) ActivateTask(TASK_CANCOMM);
        if (Os_Time % 50 == 0) ActivateTask(TASK_DEM);
        if (Os_Time % 100 == 0) ActivateTask(TASK_NVM);
        if (Os_Time % 100 == 0) ActivateTask(TASK_WDGM);
        if (Os_Time % 100 == 0) ActivateTask(TASK_CALIBPARA);
    }
}
