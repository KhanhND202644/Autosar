/******************************************************************************/
/* System Name : AUTOSAR Communication Hardware Abstraction (ComHwAb)         */
/* File Name   : ComHwAb_Can.h                                                */
/* Version     : v1.0.0                                                         */
/* Contents    : CAN Hardware Abstraction Layer Header for ECU2_FIControl      */
/* Author      : Generated                                                      */
/* Note        : Acts as a bridge between ComServices and CanIf                */
/******************************************************************************/

#ifndef COMHWAB_CAN_H
#define COMHWAB_CAN_H

#include "Std_Types.h"
#include "CanIf.h"

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------------------------------------------------*/
/* Macro Definitions                                                          */
/*----------------------------------------------------------------------------*/
#define COMHWAB_CODE

/*----------------------------------------------------------------------------*/
/* Function Prototypes                                                        */
/*----------------------------------------------------------------------------*/
// FUNC(Std_ReturnType, COMHWAB_CODE) ComHwAb_CanTransmit(
//     VAR(uint16, AUTOMATIC) signalID,
//     P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) data,
//     VAR(uint8, AUTOMATIC) length);

FUNC(Std_ReturnType, COMHWAB_CODE) ComHwAb_CanReceive(
    VAR(uint16, AUTOMATIC) signalID,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) length);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* COMHWAB_CAN_H */
