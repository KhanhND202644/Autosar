#ifndef OS_H
#define OS_H

#include <stdint.h>

/* Function Declarations for OS Tasks */
void StartOS(void);
void Task_ReadSpeed(void);
void Task_ControlInjector(void);
void Task_SaveSpeed(void);
void Task_ErrorHandling(void);
void Task_Watchdog(void);
void Task_CalibPara(void);
void Task_CAN_Comm(void);
void Task_NVM_Startup(void);
void Task_NVM_Logging(void);

#endif /* OS_H */
