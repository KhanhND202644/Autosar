#ifndef NVM_BLOCK_SWC_H
#define NVM_BLOCK_SWC_H

#include "../../RTE/Inc/Rte_NvM.h"
#include "../../Common/Std_ReturnType.h"
#include "../../Common/Compiler.h"


/* Memory Mapping */
#define NVMBLOCK_CODE RTE_CODE
#define NVMBLOCK_VAR RTE_VAR_NOINIT

/* Function Prototypes */
extern FUNC(void, NVMBLOCK_CODE) NvMBlockSWC_Init(VAR(void, AUTOMATIC));
extern FUNC(Std_ReturnType, NVMBLOCK_CODE) R_SaveSpeed(VAR(void, AUTOMATIC));
extern FUNC(Std_ReturnType, NVMBLOCK_CODE) R_ReadSpeedFromNVM(VAR(void, AUTOMATIC));

#endif /* NVM_BLOCK_SWC_H */
