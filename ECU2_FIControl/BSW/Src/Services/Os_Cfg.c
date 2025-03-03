/******************************************************************************/
/* System Name : AUTOSAR OSEK/OS Task Configuration                          */
/* File Name   : Os_Cfg.c                                                     */
/* Version     : v1.0.2                                                        */
/* Contents    : OS Task Implementation for ECU2_FIControl                    */
/* Author      : Updated                                                       */
/* Note        : Ensures tasks are correctly scheduled based on report        */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* Include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Os.h"
#include "Rte_FIControl.h"
#include "Rte_Can.h"
#include "Rte_DEM.h"
#include "Rte_NvM.h"
#include "Rte_WdgM.h"
#include "Rte_CalibPara.h"
#include <stdio.h>

/*----------------------------------------------------------------------------*/
/* Task Implementations                                                       */
/*----------------------------------------------------------------------------*/
TASK(FIControl_Task)
{
    WaitEvent(EVT_FICONTROL);
    ClearEvent(EVT_FICONTROL);
    R_CheckSpeed();
}

TASK(CAN_Comm_Task)
{
    WaitEvent(EVT_CANCOMM);
    ClearEvent(EVT_CANCOMM);
    VAR(float, AUTOMATIC) speed;
    if (Rte_Read_CanSpeed(&speed) == E_OK)
    {
        printf("CAN_Comm_Task: Speed received from CAN: %.2f km/h\n", speed);
    }
    else
    {
        printf("CAN_Comm_Task: Failed to receive speed from CAN\n");
    }
}

TASK(DEM_Task)
{
    WaitEvent(EVT_DEM);
    ClearEvent(EVT_DEM);
    VAR(uint16, AUTOMATIC) EventID;
    VAR(uint8, AUTOMATIC) EventStatus;
    if (Dem_GetLastError(&EventID, &EventStatus) == E_OK)
    {
        printf("DEM_Task: Last logged error - EventID: 0x%X, Status: %d\n", EventID, EventStatus);
    }
    else
    {
        printf("DEM_Task: No errors logged\n");
    }
}

TASK(WdgM_Task)
{
    WaitEvent(EVT_WATCHDOG);
    ClearEvent(EVT_WATCHDOG);
    if (R_TriggerWatchdog() == E_OK)
    {
        printf("WdgM_Task: Watchdog triggered successfully\n");
    }
    else
    {
        printf("WdgM_Task: Watchdog trigger failed\n");
    }
}

TASK(NVM_Task)
{
    WaitEvent(EVT_NVM);
    ClearEvent(EVT_NVM);
    VAR(uint16, AUTOMATIC) speed;
    if (NvM_ReadSpeed(&speed) == E_OK)
    {
        printf("NVM_Task: Retrieved stored speed: %d km/h\n", speed);
    }
    else
    {
        printf("NVM_Task: Failed to retrieve speed from NvM\n");
    }
}

TASK(CalibPara_Task)
{
    WaitEvent(EVT_CALIBPARA);
    ClearEvent(EVT_CALIBPARA);
    if (R_ProvideCalibrationData() == E_OK)
    {
        printf("CalibPara_Task: Calibration data updated successfully\n");
    }
    else
    {
        printf("CalibPara_Task: Failed to update calibration data\n");
    }
}
