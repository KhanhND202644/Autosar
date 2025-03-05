#include "../Inc/Rte_DEM.h"
#include "../../BSW/Inc/Services/Dem.h"

void Rte_Call_DEM_ReportErrorStatus(uint16_t EventID, Dem_EventStatusType EventStatus) {
    Dem_ReportErrorStatus(EventID, EventStatus);
}

bool Rte_Call_DEM_CheckErrorConfirmed(uint16_t EventID) {
    return Dem_CheckErrorConfirmed(EventID);
}
