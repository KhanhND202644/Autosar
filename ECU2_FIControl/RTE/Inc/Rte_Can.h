#ifndef RTE_CAN_H
#define RTE_CAN_H

#include "Std_ReturnType.h"
#include "../../../ECU1_VehicleSpeed/Common/Compiler.h"

/**
 * @brief Receive speed data from SWC via RTE to CAN
 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CANMessage(VAR(float, AUTOMATIC) speed);

#endif /* RTE_CAN_H */
