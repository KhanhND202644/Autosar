#include "../../Inc/ECU_Abstraction/ComHwAb_Can.h"
#include "../../Inc/Services/Can.h"


FUNC(Std_ReturnType, CAN_CODE) Can_Receive(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) dlc)
{
    /* Mock receive implementation */
    if (*dlc != CAN_DLC_SPEED_DATA)
    {
        return E_NOT_OK;
    }
    /* Call communication module to process received data */
    float speedValue;
    memcpy(&speedValue, data, sizeof(float));  // Chuyển đổi dữ liệu từ uint8* sang float
    return ComHwAb_CanReceive(CAN_ID_SPEED_DATA, &speedValue);
    
    
}


