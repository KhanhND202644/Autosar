/******************************************************************************/
/* System Name : AUTOSAR Communication Services (ComServices)                 */
/* File Name   : ComServices_Can.h                                            */
/* Version     : v1.0.0                                                        */
/* Contents    : CAN Communication Services Header for ECU2_FIControl         */
/* Author      : Generated                                                     */
/* Note        : Provides an interface between RTE and IoHwAb_Can              */
/******************************************************************************/

#ifndef CAN_H
#define CAN_H

#include "Std_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------------------------------------------------*/
/* Macro Definitions                                                          */
/*----------------------------------------------------------------------------*/
#define COMSERVICES_CODE

/*----------------------------------------------------------------------------*/
/* Function Prototypes                                                        */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, COMSERVICES_CODE) ComServices_CanTransmit(
    VAR(uint16, AUTOMATIC) signalID,
    P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    VAR(uint8, AUTOMATIC) length);

FUNC(Std_ReturnType, COMSERVICES_CODE) ComServices_CanReceive(
    VAR(uint16, AUTOMATIC) signalID,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) length);

FUNC(Std_ReturnType, COMSERVICES_CODE) ComServices_CanProcess(VAR(void, AUTOMATIC));

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CAN_H */
