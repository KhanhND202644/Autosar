/******************************************************************************/
/* System Name : AUTOSAR Communication Hardware Abstraction (ComHwAb)         */
/* File Name   : ComHwAb_Can.c                                                */
/* Version     : v1.0.3                                                         */
/* Contents    : CAN Hardware Abstraction Layer for ECU2_FIControl            */
/* Author      : Updated                                                       */
/* Note        : Implements CAN reception from CanIf                           */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* Include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "../../Inc/ECU_Abstraction/ComHwAb_Can.h"
#include "../../Inc/Services/CanIf.h"
#include "Std_ReturnType.h"
#include <stdio.h>

/*----------------------------------------------------------------------------*/
/* CAN Reception Implementation                                               */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, COMHWAB_CODE) ComHwAb_CanReceive(
    VAR(uint16, AUTOMATIC) signalID,
    P2VAR(float, AUTOMATIC, RTE_APPL_DATA) speed)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_OK;
    VAR(CanIf_RxPduIdType, AUTOMATIC) pduId;
    VAR(uint8, AUTOMATIC) data[CAN_MSG_DLC_SPEED];
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
    ret_val = CanIf_Receive(pduId, data);

    if (ret_val != E_OK)
    {
        printf("Warning: CAN Receive Failed for SignalID %d\n", signalID);
        return ret_val;
    }

    /* Convert CAN Data to Float */
    speedInt = ((uint32)data[0] << 24) | ((uint32)data[1] << 16) |
               ((uint32)data[2] << 8) | ((uint32)data[3]);

    *speed = (float)speedInt / 100.0F;  /* Chuyển đổi lại về float */

    printf("Received Speed from CAN: %.2f m/s\n", *speed);
    return E_OK;
}
