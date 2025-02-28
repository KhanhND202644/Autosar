#ifndef CALIBPARA_SWC_H
#define CALIBPARA_SWC_H

#include "../../RTE/Inc/Rte_CalibPara.h"
#include "RTE/Std_ReturnType.h"
#include "Common/Compiler.h"

/* Memory Mapping */
#define CALIBPARA_CODE RTE_CODE
#define CALIBPARA_VAR RTE_VAR_NOINIT

/* Function Prototypes */
extern FUNC(void, CALIBPARA_CODE) CalibParaSWC_Init(VAR(void, AUTOMATIC));
extern FUNC(Std_ReturnType, CALIBPARA_CODE) R_ProvideCalibrationData(VAR(void, AUTOMATIC));

#endif /* CALIBPARA_SWC_H */
