#ifndef FI_CONTROL_SWC_H
#define FI_CONTROL_SWC_H

#include "../../RTE/Inc/Rte_FIControl.h"
#include "RTE/Std_ReturnType.h"
#include "Common/Compiler.h"

/* Memory Mapping */
#define FICONTROL_CODE RTE_CODE
#define FICONTROL_VAR RTE_VAR_NOINIT

/* Function Prototypes */
extern FUNC(void, FICONTROL_CODE) FIControlSWC_Init(VAR(void, AUTOMATIC));
extern FUNC(Std_ReturnType, FICONTROL_CODE) R_CheckSpeed(VAR(void, AUTOMATIC));
extern FUNC(Std_ReturnType, FICONTROL_CODE) R_ControlFuelInjector(VAR(void, AUTOMATIC));

#endif /* FI_CONTROL_SWC_H */
