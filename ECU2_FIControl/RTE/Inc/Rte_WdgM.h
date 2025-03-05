#ifndef RTE_WDGM_H
#define RTE_WDGM_H

#include "../../Common/Std_ReturnType.h"
#include "../../Common/Compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------------------------------------------------*/
/* Function Prototypes                                                        */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, WDGM_CODE) R_TriggerWatchdog(VAR(void, AUTOMATIC));
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_WdgIf_TriggerWatchdog(void);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* RTE_WDGM_H */
