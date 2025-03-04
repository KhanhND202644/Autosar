#include "../../Inc/Services/CanIf.h"
#include "../../Inc/MCAL/CanDrv.h" 
#include <stdio.h>

/*----------------------------------------------------------------------------*/
/* CAN Transmission Implementation                                           */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_Transmit(
    VAR(uint16, AUTOMATIC) TxPduId,
    P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) PduInfoPtr)
{
    printf("CanIf: Transmitting CAN PDU ID: %d\n", TxPduId);
    return CanDrv_Transmit(TxPduId, PduInfoPtr); /* Calls MCAL CAN Driver */
}

/*----------------------------------------------------------------------------*/
/* CAN Reception Implementation                                              */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_Receive(
    VAR(uint16, AUTOMATIC) RxPduId,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) PduInfoPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) status;
    VAR(uint8, AUTOMATIC) ReceivedData[8]; /* Buffer for received CAN data */
    
    status = CanDrv_Receive(RxPduId, ReceivedData); /* Calls MCAL CAN Driver */
    if (status == E_OK)
    {
        /* Copy received data to output buffer */
        for (VAR(uint8, AUTOMATIC) i = 0; i < 8; i++)
        {
            PduInfoPtr[i] = ReceivedData[i];
        }
        printf("CanIf: Successfully received CAN PDU ID: %d\n", RxPduId);
    }
    else
    {
        printf("CanIf: Failed to receive CAN PDU ID: %d\n", RxPduId);
    }
    return status;
}
