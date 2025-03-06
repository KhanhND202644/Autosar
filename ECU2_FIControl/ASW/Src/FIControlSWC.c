#include "../../RTE/Inc/Rte_FIControl.h"
#include "../../RTE/Inc/Rte_DEM.h"
#include "../../RTE/Inc/Rte_Can.h"
#include "../../RTE/Inc/Rte_NvM.h"
#include "../../RTE/Inc/Rte_WdgM.h"
#include "../../RTE/Inc/Rte_CalibPara.h"
#include <stdio.h>

/* Static Variables */
static VAR(uint8, AUTOMATIC) injectorState = 0;
static VAR(float, AUTOMATIC) currentSpeed = 0.0F;
static VAR(float, AUTOMATIC) storedSpeed = 0.0F;

/* Runnable: Initialize FIControl */
FUNC(void, FICONTROL_CODE) R_FIControl_Init(void)
{
    VAR(Std_ReturnType, AUTOMATIC) status;
    uint16 tempSpeed;
    
    /* Read stored speed from NvM */
    status = Rte_Read_NvMBlock_StoredSpeed(&tempSpeed);
    if (status == E_OK)
    {
        storedSpeed = (float)tempSpeed / 10.0F;  /* Convert to float */
        printf("FIControlSWC: Stored max speed loaded: %.2f km/h\n", storedSpeed);
    }
    else
    {
        storedSpeed = 0.0F;
        if (!Rte_Call_DEM_CheckErrorConfirmed(DTC_P1600_NVM_STORAGE_FAILURE)) {
            Rte_Call_DEM_ReportErrorStatus(DTC_P1600_NVM_STORAGE_FAILURE, DEM_EVENT_STATUS_FAILED);
        }
    }
}

/* Runnable: Check Speed and Control Injector */
FUNC(Std_ReturnType, FICONTROL_CODE) R_FIControl_CheckSpeed(void)
{
    VAR(Std_ReturnType, AUTOMATIC) status;
    VAR(uint16, AUTOMATIC) speedThreshold;
    
    /* Read speed from CAN */
    uint8 canData[4];
    uint8 dlc = 4;
    status = Rte_Read_RxSpeed_CANMessage(canData, &dlc);
    if (status != E_OK)
    {
        if (!Rte_Call_DEM_CheckErrorConfirmed(DTC_U0100_LOST_COMM)) {
            Rte_Call_DEM_ReportErrorStatus(DTC_U0100_LOST_COMM, DEM_EVENT_STATUS_FAILED);
        }
        printf("FIControlSWC: Failed to read speed from CAN. Using default.\n");
        currentSpeed = 0.0F;
    }
    
    /* Read speed threshold from RTE */
    status = Rte_Read_SpeedThreshold(&speedThreshold);
    if (status != E_OK)
    {
        speedThreshold = 120; /* Default fallback */
    }
    
    /* Compare speed with the dynamic threshold */
    if (currentSpeed > speedThreshold)
    {
        injectorState = 0; /* Turn off injector */
        if (!Rte_Call_DEM_CheckErrorConfirmed(DTC_P1220_FI_VALVE_ERROR)) {
            Rte_Call_DEM_ReportErrorStatus(DTC_P1220_FI_VALVE_ERROR, DEM_EVENT_STATUS_FAILED);
        }
    }
    else
    {
        injectorState = 1; /* Turn on injector */
    }
    
    /* Write updated injector state to RTE */
    status = Rte_Write_InjectorState(injectorState);
    if (status != E_OK)
    {
        if (!Rte_Call_DEM_CheckErrorConfirmed(DTC_P1220_FI_VALVE_ERROR)) {
            Rte_Call_DEM_ReportErrorStatus(DTC_P1220_FI_VALVE_ERROR, DEM_EVENT_STATUS_FAILED);
        }
        return E_NOT_OK;
    }
    
    /* Update max speed in NvM if current speed is higher */
    if (currentSpeed > storedSpeed)
    {
        storedSpeed = currentSpeed;
        status = Rte_Write_NvMBlock_StoredSpeed((uint16)(storedSpeed * 10));
        if (status != E_OK)
        {
            if (!Rte_Call_DEM_CheckErrorConfirmed(DTC_P1600_NVM_STORAGE_FAILURE)) {
                Rte_Call_DEM_ReportErrorStatus(DTC_P1600_NVM_STORAGE_FAILURE, DEM_EVENT_STATUS_FAILED);
            }
        }
    }
    
    /* Trigger Watchdog */
    Rte_Call_WdgIf_TriggerWatchdog();
    
    return E_OK;
}

FUNC(Std_ReturnType, FICONTROL_CODE) R_ControlFuelInjector(void) {
    VAR(uint8, AUTOMATIC) state;
    Std_ReturnType status = Rte_Read_RP_FIControl_InjectorState(&state);

    if (status == E_OK) {
        status = Rte_Write_InjectorState(state);
        if (status != E_OK) {
            return E_NOT_OK; 
        }
    } else {
        return E_NOT_OK; 
    }

    return E_OK;
}
