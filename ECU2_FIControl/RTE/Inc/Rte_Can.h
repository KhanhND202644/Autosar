#ifndef RTE_CAN_H
#define RTE_CAN_H

#include "Std_ReturnType.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------------------------------------------------*/
/* RTE API Prototype Declarations                                             */
/*----------------------------------------------------------------------------*/

/* Transmit Speed Data via CAN */
extern FUNC(Std_ReturnType, RTE_CODE_ECU2) Rte_Write_RP_CanCom_TransmitSpeedData(
    VAR(uint16, AUTOMATIC) speed);
#define Rte_Write_TransmitSpeedData Rte_Write_RP_CanCom_TransmitSpeedData

/* Receive Speed Data via CAN */
extern FUNC(Std_ReturnType, RTE_CODE_ECU2) Rte_Read_RP_CanCom_ReceiveSpeedData(
    P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) speed);
#define Rte_Read_ReceiveSpeedData Rte_Read_RP_CanCom_ReceiveSpeedData

/* Call the CAN communication processing function */
extern FUNC(Std_ReturnType, RTE_CODE_ECU2) Rte_Call_RP_CanCom_Process(
    VAR(void, AUTOMATIC));
#define Rte_Call_CanComProcess Rte_Call_RP_CanCom_Process

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* RTE_CANCOM_H */
