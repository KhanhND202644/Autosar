#ifndef OS_H
#define OS_H

#include "Std_ReturnType.h"
#include "Compiler.h"

/*----------------------------------------------------------------------------*/
/* OS Configuration Constants                                                 */
/*----------------------------------------------------------------------------*/

/* Task Identifiers */
typedef enum
{
    TASK_FICONTROL,
    TASK_CANCOMM,
    TASK_DEM,
    TASK_WDGM,
    TASK_NVM,
    TASK_CALIBPARA,
    NUM_OF_TASKS /* Number of Tasks in the system */
} TaskType;

/* Event Mask definitions */
typedef uint32 EventMaskType;

/* Status Types */
#define STATUS_OK 0
#define STATUS_ERROR 1

/*----------------------------------------------------------------------------*/
/* Function Prototypes for OS API                                             */
/*----------------------------------------------------------------------------*/

/**
 * @brief Starts the operating system
 */
extern void StartOS(void);

/**
 * @brief Activate a Task
 * @param TaskID ID of the Task to activate
 */
extern void ActivateTask(TaskType TaskID);

/**
 * @brief Terminate a running Task
 */
extern void TerminateTask(void);

/**
 * @brief Wait for an event (Task will be blocked until the event occurs)
 * @param EventMask ID of the event to wait for
 */
extern void WaitEvent(EventMaskType EventMask);

/**
 * @brief Get the current event of the Task
 * @param TaskID ID of the Task
 * @param EventMask Pointer to store the received event value
 */
extern void GetEvent(TaskType TaskID, EventMaskType *EventMask);

/**
 * @brief Delete a processed event
 * @param EventMask ID of the event to delete
 */
extern void ClearEvent(EventMaskType EventMask);

/* Define the DeclareTask macro */
#define DeclareTask(TaskName) void TaskName(void)

/* Define the TASK macro */
#define TASK(TaskName) void TaskName(void)

#endif /* OS_H */
