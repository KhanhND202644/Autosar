#include "../../Inc/Services/Os.h"
#include "../../../RTE/Inc/Rte_Can.h"
#include "../../../RTE/Inc/Rte_WdgM.h"
#include "../../../RTE/Inc/Rte_NvM.h"
#include "../../../RTE/Inc/Rte_DEM.h"
#include "../../../RTE/Inc/Rte_CalibPara.h"
#include "../../../RTE/Inc/Rte_FIControl.h"
#include <stdio.h>

/* Task declarations */
void Task_ReadSpeed(void);
void Task_ControlInjector(void);
void Task_SaveSpeed(void);
void Task_ErrorHandling(void);
void Task_Watchdog(void);
void Task_CalibPara(void);
void Task_CAN_Comm(void);
void Task_NVM_Startup(void);
void Task_NVM_Logging(void);

/* OS Scheduler */
void StartOS(void) {
    Task_NVM_Startup();
    Task_CalibPara();
    while (1) {
        Task_CAN_Comm();
        Task_ReadSpeed();
        Task_ControlInjector();
        if (/* 100ms condition */) {
            Task_SaveSpeed();
            Task_ErrorHandling();
            Task_NVM_Logging();
        }
        if (/* 50ms condition */) {
            Task_Watchdog();
        }
    }
}

/* Task implementations */
void Task_ReadSpeed(void) {
    uint8 canData[8];
    uint8 dlc;
    Rte_Read_RxSpeed_CANMessage(canData, &dlc);
}

void Task_ControlInjector(void) {
    uint16 speed, threshold;
    Rte_Read_NvMBlock_StoredSpeed(&speed);
    Rte_Read_SpeedThreshold(&threshold);
    if (speed < threshold) {
        Rte_Write_InjectorState(1);
    } else {
        Rte_Write_InjectorState(0);
    }
}

void Task_SaveSpeed(void) {
    uint16 storedSpeed;
    Rte_Read_NvMBlock_StoredSpeed(&storedSpeed);
    Rte_Write_NvMBlock_StoredSpeed(storedSpeed);
}

void Task_ErrorHandling(void) {
    if (!/* CAN valid */) {
        Rte_Call_DEM_ReportErrorStatus(/* DTC_CAN_ERROR */, DEM_EVENT_STATUS_FAILED);
    }
}

void Task_Watchdog(void) {
    WdgIf_TriggerWatchdog();
}

void Task_CalibPara(void) {
    uint16 threshold;
    Rte_Read_SpeedThreshold(&threshold);
}

void Task_CAN_Comm(void) {
    uint8 canData[8];
    uint8 dlc;
    Rte_Read_RxSpeed_CANMessage(canData, &dlc);
}

void Task_NVM_Startup(void) {
    uint16 storedSpeed;
    Rte_Read_NvMBlock_StoredSpeed(&storedSpeed);
}

void Task_NVM_Logging(void) {
    // Log system state into Flash
}
