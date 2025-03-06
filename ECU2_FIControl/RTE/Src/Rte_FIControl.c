#include "../Inc/Rte_FIControl.h"
#include "../../BSW/Inc/Services/Dem.h"
#include "../../BSW/Inc/InjectorCDD.h"
#include "../Inc/Rte_DEM.h"

/* Read Injector State */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_InjectorState(VAR(uint8, AUTOMATIC) *state)
{
    return InjectorCDD_GetState(state);
}


FUNC(Std_ReturnType, RTE_CODE) Rte_Write_InjectorState(uint8 state)
{
    return InjectorCDD_SetState(state);
}
