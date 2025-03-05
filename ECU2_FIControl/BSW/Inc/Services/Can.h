#ifndef CAN_H
#define CAN_H

#include "../../Inc/ECU_Abstraction/ComHwAb_Can.h"
#include "../../../RTE/Inc/Rte_Can.h"
#include "../../../Common/Std_ReturnType.h"

/* Define CAN ID for Speed Data */
#define CAN_ID_SPEED_DATA 0x100U
#define CAN_DLC_SPEED_DATA 4U

/* Function prototype for Can_Receive */
FUNC(Std_ReturnType, CAN_CODE) Can_Receive(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) dlc);

#endif /* CAN_H */