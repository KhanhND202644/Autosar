#include "../Inc/Rte_Can.h"
#include "../../BSW/Inc/ECU_Abstraction/ComHwAb_Can.h"
#include <stdio.h>

/*----------------------------------------------------------------------------*/
/* CAN Reception Implementation                                               */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, CANCOM_CODE) Rte_Read_CanSpeed(
    P2VAR(float, AUTOMATIC, RTE_APPL_DATA) speed)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_OK;
    ret_val = ComHwAb_CanReceive(SIGNAL_ID_SPEED, speed);

    if (ret_val != E_OK)
    {
        printf("Warning: Failed to receive speed from CAN\n");
        *speed = 0.0F; /* Default value if read fails */
        return ret_val;
    }

    /* Validate received speed range */
    if (*speed < 0.0F || *speed > 300.0F)
    {
        printf("Error: Received invalid speed %.2f m/s from CAN\n", *speed);
        *speed = 0.0F; /* Reset to default if out of range */
        return E_NOT_OK;
    }

    printf("Received Speed from CAN: %.2f m/s\n", *speed);
    return E_OK;
}

#include "Rte_Can.h"

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CANMessage(VAR(float, AUTOMATIC) *speed) {
    // Giả lập dữ liệu đọc từ CAN (giá trị mặc định)
    *speed = 50.0;  // Giá trị giả lập, có thể thay đổi sau
    return E_OK;
}
