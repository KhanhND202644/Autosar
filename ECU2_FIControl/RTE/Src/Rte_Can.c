#include "../Inc/Rte_Can.h"

/* CAN Reception Implementation */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RxSpeed_CANMessage(VAR(float, AUTOMATIC) *speed)
{
    return CanIf_ReadSpeed(speed);
}
