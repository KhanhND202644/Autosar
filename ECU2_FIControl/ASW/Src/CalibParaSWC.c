#include "../Inc/CalibParaSWC.h"
#include "../../RTE/Inc/Rte_CalibPara.h"
#include "BSW/Services/Dem.h"
#include <stdio.h>

/* Static Variables */
static VAR(uint16, CALIBPARA_VAR) speedThreshold = 100;

/* Initialize Calibration Parameter SWC */
FUNC(void, CALIBPARA_CODE) CalibParaSWC_Init(VAR(void, AUTOMATIC))
{
    printf("Calibration Parameter SWC Initialized.\n");
}

/* Runnable: Provide Calibration Data */
FUNC(Std_ReturnType, CALIBPARA_CODE) R_ProvideCalibrationData(VAR(void, AUTOMATIC))
{
    return Rte_Write_SpeedThreshold(speedThreshold);
}
