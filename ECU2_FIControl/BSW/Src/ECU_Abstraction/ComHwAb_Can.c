/******************************************************************************/
/* System Name : AUTOSAR Communication Hardware Abstraction (ComHwAb)         */
/* File Name   : ComHwAb_Can.c                                                */
/* Version     : v1.0.2                                                         */
/* Contents    : CAN Hardware Abstraction Layer for ECU2_FIControl            */
/* Author      : Updated                                                       */
/* Note        : Implements CAN reception from CanIf                           */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* Include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "../../Inc/ECU_Abstraction/ComHwAb_Can.h"
#include "../../Inc/MCAL/CanIf.h"
#include "Std_ReturnType.h"
#include <stdio.h>

/*----------------------------------------------------------------------------*/
/* CAN Reception Implementation                                               */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, COMHWAB_CODE) ComHwAb_CanReceive(
    VAR(uint16, AUTOMATIC) signalID,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) length)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_OK;
    VAR(CanIf_RxPduIdType, AUTOMATIC) pduId;
    VAR(uint8, AUTOMATIC) canData[CAN_MSG_DLC_SPEED];
    VAR(uint32, AUTOMATIC) speedInt;

    /* Map signalID to CAN PDU ID */
    switch (signalID)
    {
    case SIGNAL_ID_SPEED:
        pduId = CanIfConf_RxPdu_SpeedData;
        break;
    default:
        return E_NOT_OK;
    }

    /* Receive CAN data */
    ret_val = CanIf_Receive(pduId, canData);

    if (ret_val != E_OK)
    {
        printf("Warning: CAN Receive Failed for SignalID %d\n", signalID);
        return ret_val;
    }

    /* Convert CAN Data to Float */
    speedInt = ((uint32)canData[0] << 24) | ((uint32)canData[1] << 16) |
               ((uint32)canData[2] << 8) | ((uint32)canData[3]);

    *data = speedInt;
    *length = sizeof(speedInt);

    printf("Received Speed from CAN: %u\n", speedInt);
    return E_OK;
}
