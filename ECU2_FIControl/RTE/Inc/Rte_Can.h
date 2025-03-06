#ifndef RTE_CAN_H
#define RTE_CAN_H

#include "../../Common/Std_ReturnType.h"
#include "../../Common/Compiler.h"

/**
 * @brief Receive speed data from CAN and pass to SWC
 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RxSpeed_CANMessage(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) dlc);

#endif /* RTE_CAN_H */
