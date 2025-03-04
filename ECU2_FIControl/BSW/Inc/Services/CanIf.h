#ifndef CANIF_H
#define CANIF_H

#include "../../../Common/Std_ReturnType.h"
#include "../../../Common/Compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------------------------------------------------*/
/* Macro Definitions                                                          */
/*----------------------------------------------------------------------------*/
#define CANIF_CODE
#define CanIfConf_RxPdu_SpeedData 0x100U  /* CAN PDU ID for Speed */

/*----------------------------------------------------------------------------*/
/* Function Prototypes                                                        */
/*----------------------------------------------------------------------------*/

/**
 * @brief Transmit CAN message
 * @param TxPduId CAN PDU ID
 * @param PduInfoPtr Pointer to CAN Data
 * @return Std_ReturnType - Status of transmission
 */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_Transmit(
    VAR(uint16, AUTOMATIC) TxPduId,
    P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) PduInfoPtr);

/**
 * @brief Receive CAN message
 * @param RxPduId CAN PDU ID
 * @param PduInfoPtr Pointer to store received data
 * @return Std_ReturnType - Status of reception
 */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_Receive(
    VAR(uint16, AUTOMATIC) RxPduId,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) PduInfoPtr);

#ifdef __cplusplus
} /* extern \"C\" */
#endif

#endif /* CANIF_H */
