#include "../Inc/Rte_Dem.h"
#include "../../BSW/Inc/Services/Dem.h"
#include <stdio.h>

/*----------------------------------------------------------------------------*/
/* Static Variables                                                           */
/*----------------------------------------------------------------------------*/
#define MAX_DEM_EVENTS 10  /* Maximum number of stored diagnostic events */

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
        printf("DEM Warning: No error events recorded.\n");
        return E_NOT_OK;
    }

    *EventID = Dem_EventIDs[Dem_EventCount - 1];
    *EventStatus = Dem_EventStatus[Dem_EventCount - 1];

    return E_OK;
}
