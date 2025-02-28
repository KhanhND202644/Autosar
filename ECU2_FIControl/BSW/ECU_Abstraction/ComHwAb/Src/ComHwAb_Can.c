/******************************************************************************/
/* System Name : AUTOSAR Communication Hardware Abstraction (ComHwAb)         */
/* File Name   : IoHwAb_Can.c                                                  */
/* Version     : v1.0.0                                                         */
/* Contents    : CAN Hardware Abstraction Layer for ECU2_FIControl             */
/* Author      : Generated                                                      */
/* Note        : Acts as a bridge between ComServices and ComDriver            */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* Include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "../Inc/ComHwAb_Can.h"
#include "../../../Services/Inc/Can.h"
#include "../../../MCAL/CANDriver/Inc/CanIf.h"
#include "Std_ReturnType.h"
#include <stdio.h>

/*----------------------------------------------------------------------------*/
/* CAN Transmission Implementation                                            */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, COMHWAB_CODE) ComHwAb_CanTransmit(
    VAR(uint16, AUTOMATIC) signalID,
    P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    VAR(uint8, AUTOMATIC) length)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_OK;
    VAR(CanIf_TxPduIdType, AUTOMATIC) pduId;

    /* Map signalID to CAN PDU ID (This should be configured in a lookup table) */
    switch (signalID)
    {
    case SIGNAL_ID_SPEED:
        pduId = CanIfConf_TxPdu_SpeedData;
        break;
    default:
        return E_NOT_OK; /* Unsupported signal ID */
    }

    /* Transmit CAN data */
    ret_val = CanIf_Transmit(pduId, data, length);

    if (ret_val != E_OK)
    {
        printf("Error: CAN Transmission Failed for SignalID %d\n", signalID);
    }
    return ret_val;
}

/*----------------------------------------------------------------------------*/
/* CAN Reception Implementation                                               */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_CanReceive(
    VAR(uint16, AUTOMATIC) signalID,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) length)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_OK;
    VAR(CanIf_RxPduIdType, AUTOMATIC) pduId;

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
    ret_val = CanIf_Receive(pduId, data, length);

    if (ret_val != E_OK)
    {
        printf("Warning: CAN Receive Failed for SignalID %d\n", signalID);
    }
    return ret_val;
}
