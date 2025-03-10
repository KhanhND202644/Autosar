#ifndef RTE_CALIBPARA_H
#define RTE_CALIBPARA_H

#include "../../Common/Std_ReturnType.h"
#include "../../Common/Compiler.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Provide calibration data */
extern FUNC(Std_ReturnType, RTE_CODE_ECU2) Rte_Write_RP_CalibPara_SpeedThreshold(
    VAR(uint16, AUTOMATIC) threshold);
#define Rte_Write_SpeedThreshold Rte_Write_RP_CalibPara_SpeedThreshold

extern FUNC(Std_ReturnType, RTE_CODE_ECU2) Rte_Read_RP_CalibPara_SpeedThreshold(
    VAR(uint16*, AUTOMATIC) threshold);
#define Rte_Read_SpeedThreshold Rte_Read_RP_CalibPara_SpeedThreshold

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* RTE_CALIBPARA_H */
