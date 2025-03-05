#include "../Inc/CalibParaSWC.h"
#include "../../RTE/Inc/Rte_CalibPara.h"
#include "../../RTE/Inc/Rte_DEM.h"
#include "../../RTE/Inc/Rte_NvM.h"
#include <stdio.h>

/* Static Variables */
static VAR(uint16, CALIBPARA_VAR) speedThreshold = 100;

/* Initialize Calibration Parameter SWC */
FUNC(void, CALIBPARA_CODE) R_CalibParaSWC_Init(void)
{
    VAR(Std_ReturnType, AUTOMATIC) status;
    
    /* Read calibration from NvM */
    status = Rte_Read_NvMBlock_Calibration(&speedThreshold);
    if (status != E_OK)
    {
        speedThreshold = 100; /* Default value */
    }
    printf("Calibration Parameter SWC Initialized.\n");
}

/* Runnable: Provide Calibration Data */
FUNC(Std_ReturnType, CALIBPARA_CODE) R_ProvideCalibrationData(void)
{
    Std_ReturnType status = Rte_Write_SpeedThreshold(speedThreshold);
    if (status != E_OK)
    {
        if (!Rte_Call_DEM_CheckErrorConfirmed(DTC_P1234_SPEED_CALIBRATION_ERROR)) {
            Rte_Call_Dem_ReportErrorStatus(DTC_P1234_SPEED_CALIBRATION_ERROR, DEM_EVENT_STATUS_FAILED);
        }
        return E_NOT_OK;
    }
    return E_OK;
}
