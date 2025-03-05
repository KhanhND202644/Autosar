#include "../../Inc/MCAL/CanDrv.h"
#include <stdio.h>


Std_ReturnType Hardware_CAN_Receive(uint16* speed) {
    *speed = 50; 
    printf("[SIM] CAN Message Received: Speed = %d km/h\n", *speed);
    return E_OK;
}
