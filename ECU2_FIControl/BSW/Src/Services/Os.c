#include "../../Inc/Service/Os.h"
#include "../../../RTE/Src/Rte_Partition.c"

/*----------------------------------------------------------------------------*/
/* OS Kernel Simulation (Stub)                                                */
/*----------------------------------------------------------------------------*/
void StartOS(void) {
    /* Run OS */
}

void ActivateTask(uint8 TaskID) {
    /* Activate TaskID */
}

void TerminateTask(void) {
    /* End task */
}

void SetEvent(uint8 TaskID, uint32 EventMask) {
    /* Send event to Task */
}

void ClearEvent(uint32 EventMask) {
    /* Clear event  */
}

void WaitEvent(uint32 EventMask) {
    /* Wait event */
}

void GetEvent(uint8 TaskID, uint32* EventMask) {
    /* Lấy sự kiện của Task */
}

/*----------------------------------------------------------------------------*/
/* Task Implementations                                                       */
/*----------------------------------------------------------------------------*/

/*------------------------------------------------*/
/* TASK: Injector_Control_Task (Event-driven)     */
/*------------------------------------------------*/
TASK (Injector_Control_Task) {
    WaitEvent(EVT_INJECTOR_CONTROL);
    ClearEvent(EVT_INJECTOR_CONTROL);
    Rte_Call_RP_FIControlSWC_ControlFuelInjector();
}

/*------------------------------------------------*/
/* TASK: FIControl_Task (10ms)                     */
/*------------------------------------------------*/
TASK (FIControl_Task) {
    WaitEvent(EVT_FICONTROL);
    ClearEvent(EVT_FICONTROL);
    Rte_Call_RP_FIControlSWC_CheckSpeed();
}

/*------------------------------------------------*/
/* TASK: CAN_Comm_Task (5ms)                      */
/*------------------------------------------------*/
TASK (CAN_Comm_Task) {
    WaitEvent(EVT_CAN_COMM);
    ClearEvent(EVT_CAN_COMM);
    Rte_Call_RP_CAN_Comm_Process();
}

/*------------------------------------------------*/
/* TASK: Sensor_Read_Task (10ms)                  */
/*------------------------------------------------*/
TASK (Sensor_Read_Task) {
    WaitEvent(EVT_SENSOR_READ);
    ClearEvent(EVT_SENSOR_READ);
    Rte_Call_RP_SpeedSensorSWC_ReadSpeed();
}

/*------------------------------------------------*/
/* TASK: DEM_Task (Event-driven)                  */
/*------------------------------------------------*/
TASK (DEM_Task) {
    WaitEvent(EVT_DEM);
    ClearEvent(EVT_DEM);
    Rte_Call_RP_FIControlSWC_SendDiagnostics();
}

/*------------------------------------------------*/
/* TASK: CalibPara_Task (50ms)                    */
/*------------------------------------------------*/
TASK (CalibPara_Task) {
    WaitEvent(EVT_CALIB_PARA);
    ClearEvent(EVT_CALIB_PARA);
    Rte_Call_RP_CalibParaSWC_ProvideCalibrationData();
}

/*------------------------------------------------*/
/* TASK: Watchdog_Task (100ms)                    */
/*------------------------------------------------*/
TASK (Watchdog_Task) {
    WaitEvent(EVT_WATCHDOG);
    ClearEvent(EVT_WATCHDOG);
    Rte_Call_RP_FIControlSWC_TriggerWatchdog();
}

/*------------------------------------------------*/
/* TASK: NVM_Startup_Task (Startup)               */
/*------------------------------------------------*/
TASK (NVM_Startup_Task) {
    WaitEvent(EVT_NVM_STARTUP);
    ClearEvent(EVT_NVM_STARTUP);
    Rte_Call_RP_NVBlockSWC_ReadSpeedFromNVM();
}

/*------------------------------------------------*/
/* TASK: NVM_Logging_Task (100ms)                 */
/*------------------------------------------------*/
TASK (NVM_Logging_Task) {
    WaitEvent(EVT_NVM_LOGGING);
    ClearEvent(EVT_NVM_LOGGING);
    Rte_Call_RP_NVBlockSWC_SaveSpeed();
}
