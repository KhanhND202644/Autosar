#include "../../Inc/ECU_Abstraction/ComHwAb_Can.h"
#include "../../Inc/Services/Can.h"
#include<string.h>


FUNC(Std_ReturnType, CAN_CODE) Can_Receive(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) dlc)
{
    if (data == NULL || dlc == NULL)
    {
        return E_NOT_OK;
    }

    if (*dlc < sizeof(float) || *dlc != CAN_DLC_SPEED_DATA)
    {
        return E_NOT_OK;
    }

    float speedValue;
    memcpy(&speedValue, data, sizeof(float)); 

    Std_ReturnType status = ComHwAb_CanReceive(CAN_ID_SPEED_DATA, &speedValue);

    if (status != E_OK)
    {
        return E_NOT_OK;
    }

    return E_OK;
}


