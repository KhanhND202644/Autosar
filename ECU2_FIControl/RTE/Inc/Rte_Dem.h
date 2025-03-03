/******************************************************************************/
/* System Name : AUTOSAR Diagnostic Event Manager (DEM)                      */
/* File Name   : Rte_DEM.h                                                    */
/* Version     : v1.0.0                                                        */
/* Contents    : DEM Header for ECU2_FIControl                                */
/* Author      : Generated                                                     */
/* Note        : Provides interface for error logging and reporting           */
/******************************************************************************/

#ifndef RTE_DEM_H
#define RTE_DEM_H

#include "Std_ReturnType.h"
#include "Compiler.h"

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

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* RTE_DEM_H */
