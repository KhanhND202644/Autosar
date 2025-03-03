#ifndef RTE_NVM_BLOCK_H
#define RTE_NVM_BLOCK_H

#include "Std_ReturnType.h"
#include "../../../ECU1_VehicleSpeed/Common/Compiler.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Read stored speed value */
extern FUNC(Std_ReturnType, RTE_CODE_ECU2) Rte_Read_RP_NvMBlock_StoredSpeed(
    P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) speed);
#define Rte_Read_StoredSpeed Rte_Read_RP_NvMBlock_StoredSpeed

/* Write speed value to NvM */
extern FUNC(Std_ReturnType, RTE_CODE_ECU2) Rte_Write_RP_NvMBlock_StoredSpeed(
    VAR(uint16, AUTOMATIC) speed);
#define Rte_Write_StoredSpeed Rte_Write_RP_NvMBlock_StoredSpeed

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* RTE_NVM_BLOCK_H */
