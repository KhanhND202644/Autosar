#include "../../Inc/MCAL/CanIf.h"
#include <stdio.h>


/**
 * @brief Receive CAN message
 */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_Receive(
    VAR(uint16, AUTOMATIC) RxPduId,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) PduInfoPtr)
{
    /* Simulated CAN Reception */
    if (RxPduId == CanIfConf_RxPdu_SpeedData)
    {
        PduInfoPtr[0] = 0x00;
        PduInfoPtr[1] = 0x01;
        PduInfoPtr[2] = 0x86;
        PduInfoPtr[3] = 0xA0;  /* 100000 in hex = 1000.00 when divided by 100 */
        printf("CAN Receive: PDU ID: 0x%X, Data: [%02X %02X %02X %02X]\n",
               RxPduId, PduInfoPtr[0], PduInfoPtr[1], PduInfoPtr[2], PduInfoPtr[3]);
        return E_OK;
    }

    printf("CAN Receive: No valid data for PDU ID: 0x%X\n", RxPduId);
    return E_NOT_OK;
}
