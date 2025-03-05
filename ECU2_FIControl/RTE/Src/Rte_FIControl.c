#include "../Inc/Rte_FIControl.h"
#include "../../BSW/Inc/Services/Dem.h"

/* Read Injector State */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_InjectorState(VAR(uint8, AUTOMATIC) *state)
{
    return Dem_GetInjectorState(state);
}

/* Write Injector State */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_InjectorState(uint8 state)
{
    return Dem_SetInjectorState(state);
}
