#include "../Inc/Rte_Can.h"
#include "BSW/Services/Can.h"

/**
 * @brief Send speed data from SWC via RTE to CAN
 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CANMessage(VAR(float, AUTOMATIC) speed)
{
    return Can_Services_SendSpeed(speed);
}
