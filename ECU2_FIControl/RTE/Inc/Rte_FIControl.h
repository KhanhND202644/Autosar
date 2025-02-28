#ifndef RTE_FICONTROL_H
#define RTE_FICONTROL_H

#include "Std_ReturnType.h"
#include <stdint.h>

/*----------------------------------------------------------------------------*/
/* RTE APIs Prototype Declaration                                             */
/*----------------------------------------------------------------------------*/

/* Read speed data received from SpeedSensor */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RP_FIControl_SpeedData(
    P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) speed);
#define Rte_Read_SpeedData Rte_Read_RP_FIControl_SpeedData

/* Write fuel injector state */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_RP_FIControl_InjectorState(
    VAR(uint8, AUTOMATIC) injectorState);
#define Rte_Write_InjectorState Rte_Write_RP_FIControl_InjectorState

/* Call the runnable of FIControl */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_RP_FIControlSWC_CheckSpeed(
    VAR(void, AUTOMATIC));
#define Rte_Call_CheckSpeed Rte_Call_RP_FIControlSWC_CheckSpeed

#endif /* RTE_FICONTROL_H */
