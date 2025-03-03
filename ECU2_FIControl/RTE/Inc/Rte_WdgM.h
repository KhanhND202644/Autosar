#ifndef RTE_WDGM_H
#define RTE_WDGM_H

#include "Std_ReturnType.h"
#include "Compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------------------------------------------------*/
/* Function Prototypes                                                        */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, WDGM_CODE) R_TriggerWatchdog(VAR(void, AUTOMATIC));

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* RTE_WDGM_H */
