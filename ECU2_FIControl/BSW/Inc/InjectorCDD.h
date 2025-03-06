#ifndef INJECTOR_CDD_H
#define INJECTOR_CDD_H

#include "../../Common/Std_ReturnType.h"
#include "../../Common/Compiler.h"


FUNC(Std_ReturnType, CDD_CODE) InjectorCDD_SetState(VAR(uint8, AUTOMATIC) state);
FUNC(Std_ReturnType, CDD_CODE) InjectorCDD_GetState(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) state);

#endif /* INJECTOR_CDD_H */
