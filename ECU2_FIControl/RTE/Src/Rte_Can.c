#include "../Inc/Rte_Can.h"
#include "../../BSW/Inc/Services/Can.h"

/* CAN Reception Implementation */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RxSpeed_CANMessage(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) dlc)
{
    return Can_Receive(data, dlc);
}
