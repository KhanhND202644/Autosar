/******************************************************************************/
/* System Name : AUTOSAR Communication Hardware Abstraction (ComHwAb)         */
/* File Name   : ComHwAb_Can.h                                                */
/* Version     : v1.0.3                                                        */
/* Contents    : CAN Hardware Abstraction Layer Header for ECU2_FIControl      */
/* Author      : Updated                                                       */
/* Note        : Defines interface for CAN reception between ComServices and CanIf */
/******************************************************************************/

#ifndef COMHWAB_CAN_H
#define COMHWAB_CAN_H

#include "../../../Common/Std_ReturnType.h"
#include "../Services/CanIf.h"

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------------------------------------------------*/
/* Macro Definitions                                                          */
/*----------------------------------------------------------------------------*/
#define COMHWAB_CODE
#define CAN_MSG_DLC_SPEED 4U  /* Data Length Code for Speed Message */
#define SIGNAL_ID_SPEED 0x100U  /* CAN Message ID for Speed */

/*----------------------------------------------------------------------------*/
/* Type Definitions                                                           */
/*----------------------------------------------------------------------------*/
typedef uint16 CanIf_RxPduIdType; /* Define CanIf_RxPduIdType if not in CanIf.h */

/*----------------------------------------------------------------------------*/
/* Function Prototypes                                                        */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, COMHWAB_CODE) ComHwAb_CanReceive(
    VAR(uint16, AUTOMATIC) signalID,
    P2VAR(float, AUTOMATIC, RTE_APPL_DATA) speed);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* COMHWAB_CAN_H */
