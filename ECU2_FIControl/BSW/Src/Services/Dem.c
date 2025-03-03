#include "Dem.h"
#include "NvM.h"
#include "../../RTE/Inc/Rte_WdgM.h"
#include <stdio.h>

/*----------------------------------------------------------------------------*/
/* Static Variables                                                           */
/*----------------------------------------------------------------------------*/
#define MAX_DEM_EVENTS 10  /* Maximum number of stored diagnostic events */
#define DTC_OVERSPEED 0x1234U /* Example DTC for overspeed */

static VAR(uint8, AUTOMATIC) Dem_EventStatus[MAX_DEM_EVENTS];
static VAR(uint16, AUTOMATIC) Dem_EventIDs[MAX_DEM_EVENTS];
static VAR(uint8, AUTOMATIC) Dem_EventCount = 0;

/*----------------------------------------------------------------------------*/
/* DEM Event Reporting Implementation                                         */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, DEM_CODE) Dem_ReportErrorStatus(
    VAR(uint16, AUTOMATIC) EventID,
    VAR(uint8, AUTOMATIC) EventStatus)
{
    if (Dem_EventCount >= MAX_DEM_EVENTS)
    {
        printf("DEM Error: Event buffer full!\n");
        return E_NOT_OK;
    }

    /* Store the event */
    Dem_EventIDs[Dem_EventCount] = EventID;
    Dem_EventStatus[Dem_EventCount] = EventStatus;
    Dem_EventCount++;

    /* Store in NvM */
    if (NvM_WriteError(EventID, EventStatus) != E_OK)
    {
        printf("DEM Warning: Failed to save error to NvM!\n");
    }

    /* Trigger Watchdog Manager to confirm ECU is alive */
    if (R_TriggerWatchdog() != E_OK)
    {
        printf("DEM Warning: Failed to trigger watchdog!\n");
    }

    printf("DEM: Logged Event ID: 0x%X, Status: %d\n", EventID, EventStatus);
    return E_OK;
}

/*----------------------------------------------------------------------------*/
/* DEM Integration with FIControlSWC                                          */
/*----------------------------------------------------------------------------*/
FUNC(void, DEM_CODE) Dem_CheckSpeed(VAR(float, AUTOMATIC) currentSpeed)
{
    if (currentSpeed > 120.0F) /* Example threshold */
    {
        printf("DEM: Overspeed detected (%.2f km/h), logging error.\n", currentSpeed);
        Dem_ReportErrorStatus(DTC_OVERSPEED, DEM_EVENT_STATUS_FAILED);
    }
    else
    {
        printf("DEM: Speed is within safe limits (%.2f km/h).\n", currentSpeed);
        Dem_ReportErrorStatus(DTC_OVERSPEED, DEM_EVENT_STATUS_PASSED);
    }
}
