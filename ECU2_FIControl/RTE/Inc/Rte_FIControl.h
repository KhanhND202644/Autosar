#ifndef RTE_FICONTROL_H
#define RTE_FICONTROL_H

#include "../../Common/Std_ReturnType.h"
#include "../../Common/Compiler.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------------------------------------------------*/
/* Function Prototype Declarations                                             */
/*----------------------------------------------------------------------------*/

/* Read speed data from CAN */
extern FUNC(Std_ReturnType, RTE_CODE_ECU2) Rte_Read_RP_FIControl_ReceiveSpeed(
    P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) speed);
#define Rte_Read_ReceiveSpeed Rte_Read_RP_FIControl_ReceiveSpeed

/* Write injector state */
extern FUNC(Std_ReturnType, RTE_CODE_ECU2) Rte_Write_RP_FIControl_InjectorState(
    VAR(uint8, AUTOMATIC) state);
#define Rte_Write_InjectorState Rte_Write_RP_FIControl_InjectorState

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* RTE_FICONTROL_H */
