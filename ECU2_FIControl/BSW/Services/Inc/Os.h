#ifndef OS_H
#define OS_H

#include "../../../ECU1_VehicleSpeed/RTE/Std_Types.h"

/*----------------------------------------------------------------------------*/
/* Task Identifiers                                                           */
/*----------------------------------------------------------------------------*/
#define OS_TASK_INJECTOR_CONTROL     1U  /* Event-driven */
#define OS_TASK_FICONTROL            2U  /* Periodic (10ms) */
#define OS_TASK_CAN_COMM             3U  /* Periodic (5ms) */
#define OS_TASK_SENSOR_READ          4U  /* Periodic (10ms) */
#define OS_TASK_DEM                  5U  /* Event-driven */
#define OS_TASK_CALIB_PARA           6U  /* Periodic (50ms) */
#define OS_TASK_WATCHDOG             7U  /* Periodic (100ms) */
#define OS_TASK_NVM_STARTUP          8U  /* Startup */
#define OS_TASK_NVM_LOGGING          9U  /* Periodic (100ms) */

/*----------------------------------------------------------------------------*/
/* Event Identifiers                                                          */
/*----------------------------------------------------------------------------*/
#define EVT_INJECTOR_CONTROL        (1U << 0)
#define EVT_FICONTROL               (1U << 1)
#define EVT_CAN_COMM                (1U << 2)
#define EVT_SENSOR_READ             (1U << 3)
#define EVT_DEM                     (1U << 4)
#define EVT_CALIB_PARA              (1U << 5)
#define EVT_WATCHDOG                (1U << 6)
#define EVT_NVM_STARTUP             (1U << 7)
#define EVT_NVM_LOGGING             (1U << 8)

/*----------------------------------------------------------------------------*/
/* Function Prototypes                                                         */
/*----------------------------------------------------------------------------*/
extern void StartOS(void);
extern void ActivateTask(uint8 TaskID);
extern void TerminateTask(void);
extern void SetEvent(uint8 TaskID, uint32 EventMask);
extern void ClearEvent(uint32 EventMask);
extern void WaitEvent(uint32 EventMask);
extern void GetEvent(uint8 TaskID, uint32* EventMask);

#endif /* OS_H */
