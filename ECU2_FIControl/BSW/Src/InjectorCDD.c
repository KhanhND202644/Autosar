#include "../Inc/InjectorCDD.h"
#include "stddef.h"
// #include "Dio.h"  // MCAL DIO driver

#define INJECTOR_GPIO_CHANNEL DIO_CHANNEL_5 

FUNC(Std_ReturnType, CDD_CODE) InjectorCDD_SetState(VAR(uint8, AUTOMATIC) state) {
    if (state != 0 && state != 1) {
        return E_NOT_OK; 
    }
    Dio_WriteChannel(INJECTOR_GPIO_CHANNEL, state);
    return E_OK;
}

FUNC(Std_ReturnType, CDD_CODE) InjectorCDD_GetState(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) state) {
    if (state == NULL) {
        return E_NOT_OK;
    }

    *state = InjectorState;
    return E_OK;
}
