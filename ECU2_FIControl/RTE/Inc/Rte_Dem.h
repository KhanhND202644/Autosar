#ifndef RTE_DEM_H
#define RTE_DEM_H

#include "../../Common/Std_ReturnType.h"
#include "../../Common/Compiler.h"
#include "../../BSW/Inc/Services/Dem.h"

void Rte_Call_DEM_ReportErrorStatus(uint16_t EventID, Dem_EventStatusType EventStatus);

bool Rte_Call_DEM_CheckErrorConfirmed(uint16_t EventID);

#endif /* RTE_DEM_H */
