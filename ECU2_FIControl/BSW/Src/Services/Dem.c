#include "Dem.h"
#include "NvM.h"
#include "Rte_FIControl.h"
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

    printf("DEM: Logged Event ID: 0x%X, Status: %d\n", EventID, EventStatus);
    return E_OK;
}

/*----------------------------------------------------------------------------*/
/* Retrieve Last Logged Error                                                 */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetLastError(
    P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) EventID,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) EventStatus)
{
    if (Dem_EventCount == 0)
    {
        printf("DEM Warning: No error events recorded. Checking NvM.\n");
        return NvM_ReadError(EventID, EventStatus);
    }

    *EventID = Dem_EventIDs[Dem_EventCount - 1];
    *EventStatus = Dem_EventStatus[Dem_EventCount - 1];

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
}

/*----------------------------------------------------------------------------*/
/* DEM Clear Error Implementation                                             */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, DEM_CODE) Dem_ClearError(
    VAR(uint16, AUTOMATIC) EventID)
{
    for (VAR(uint8, AUTOMATIC) i = 0; i < Dem_EventCount; i++)
    {
        if (Dem_EventIDs[i] == EventID)
        {
            /* Remove event by shifting array */
            for (VAR(uint8, AUTOMATIC) j = i; j < (Dem_EventCount - 1); j++)
            {
                Dem_EventIDs[j] = Dem_EventIDs[j + 1];
                Dem_EventStatus[j] = Dem_EventStatus[j + 1];
            }
            Dem_EventCount--;
            printf("DEM: Cleared Event ID: 0x%X\n", EventID);
            return E_OK;
        }
    }

    printf("DEM Warning: Event ID 0x%X not found.\n", EventID);
    return E_NOT_OK;
}
