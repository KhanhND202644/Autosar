#ifndef DEM_H
#define DEM_H

#include <stdint.h>
#include <stdbool.h>
#include "NvM.h"

typedef enum {
    DEM_EVENT_STATUS_PASSED = 0x00,
    DEM_EVENT_STATUS_FAILED = 0x01,
    DEM_EVENT_STATUS_PREFAILED = 0x02,
    DEM_EVENT_STATUS_PREPASSED = 0x03
} Dem_EventStatusType;

FUNC(Std_ReturnType, DEM_CODE) Dem_ReportErrorStatus(VAR(uint16, AUTOMATIC) DTC, VAR(Dem_EventStatusType, AUTOMATIC) status);

#define DTC_P1220_FI_VALVE_ERROR            0x1220  /* Fuel Injector Control Error */
#define DTC_P1234_SPEED_CALIBRATION_ERROR    0x1234  /* Speed Threshold Calibration Error */
#define DTC_P1600_NVM_STORAGE_FAILURE        0x1600  /* NVM Data Storage Failure */
#define DTC_U0100_LOST_COMM                  0x0100  /* Lost Communication Between ECUs */

bool Dem_CheckErrorConfirmed(uint16_t DTC);
void Dem_Init(void); 

#endif /* DEM_H */
