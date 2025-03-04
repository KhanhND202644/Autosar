#ifndef CAN_DRV_H
#define CAN_DRV_H

#include "Std_ReturnType.h"
#include "Compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------------------------------------------------*/
/* Macro Definitions                                                          */
/*----------------------------------------------------------------------------*/
#define CAN_DRV_CODE

/*----------------------------------------------------------------------------*/
/* Function Prototypes                                                        */
/*----------------------------------------------------------------------------*/
/**
 * @brief Transmit a CAN message
 * @param TxPduId ID of the PDU to be transmitted
 * @param PduInfoPtr Pointer to the CAN message data
 * @return Std_ReturnType - E_OK if successful, E_NOT_OK if transmission failed
 */
FUNC(Std_ReturnType, CAN_DRV_CODE) CanDrv_Transmit(
    VAR(uint16, AUTOMATIC) TxPduId,
    P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) PduInfoPtr);

/**
 * @brief Receive a CAN message
 * @param RxPduId ID of the PDU to be received
 * @param PduInfoPtr Pointer to store received CAN message data
 * @return Std_ReturnType - E_OK if successful, E_NOT_OK if reception failed
 */
FUNC(Std_ReturnType, CAN_DRV_CODE) CanDrv_Receive(
    VAR(uint16, AUTOMATIC) RxPduId,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) PduInfoPtr);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CAN_DRV_H */
