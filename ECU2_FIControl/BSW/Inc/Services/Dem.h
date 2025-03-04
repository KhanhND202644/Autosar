#ifndef DEM_H
#define DEM_H

#include "../../Common/Std_ReturnType.h"
#include "../../Common/Compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------------------------------------------------*/
/* Macro Definitions                                                          */
/*----------------------------------------------------------------------------*/
#define DEM_EVENT_STATUS_PASSED     0x00U
#define DEM_EVENT_STATUS_FAILED     0x01U
#define DEM_EVENT_STATUS_PREFAILED  0x02U
#define DEM_EVENT_STATUS_PREPASSED  0x03U

/*----------------------------------------------------------------------------*/
/* Function Prototypes                                                        */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, DEM_CODE) Dem_ReportErrorStatus(
    VAR(uint16, AUTOMATIC) EventID,
    VAR(uint8, AUTOMATIC) EventStatus);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetLastError(
    P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) EventID,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) EventStatus);

FUNC(Std_ReturnType, DEM_CODE) Dem_ClearError(
    VAR(uint16, AUTOMATIC) EventID);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* DEM_H */
