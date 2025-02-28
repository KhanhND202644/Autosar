#ifndef RTE_NVM_BLOCK_H
#define RTE_NVM_BLOCK_H

#include "Std_ReturnType.h"
#include <stdint.h>

/*----------------------------------------------------------------------------*/
/* RTE APIs Prototype Declaration                                             */
/*----------------------------------------------------------------------------*/

/* Read stored speed value from NvM */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RP_NvMBlock_SpeedValue(
    P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) speed);
#define Rte_Read_StoredSpeed Rte_Read_RP_NvMBlock_SpeedValue

/* Write speed value to NvM */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_RP_NvMBlock_SpeedValue(
    VAR(uint16, AUTOMATIC) speed);
#define Rte_Write_StoredSpeed Rte_Write_RP_NvMBlock_SpeedValue

#endif /* RTE_NVM_BLOCK_H */
