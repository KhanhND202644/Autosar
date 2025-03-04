#include "../../Inc/Services/Os.h"
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
FUNC(void, OS_CODE) StartOS(void)
{
    printf("OS: System Started\n");
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
    Os_Time++;

    /* Run Tasks based on schedule */
    if (Os_Time % 10 == 0) ActivateTask(TASK_FICONTROL);
    if (Os_Time % 5 == 0) ActivateTask(TASK_CANCOMM);
    if (Os_Time % 50 == 0) ActivateTask(TASK_DEM);
    if (Os_Time % 100 == 0) ActivateTask(TASK_NVM);
    if (Os_Time % 100 == 0) ActivateTask(TASK_WDGM);
    if (Os_Time % 100 == 0) ActivateTask(TASK_CALIBPARA);
}
