#ifndef RTE_NVM_H
#define RTE_NVM_H

#include "../../Common/Std_ReturnType.h"
#include "../../Common/Compiler.h"
#include <stdint.h>

/*----------------------------------------------------------------------------*/
/**  @brief RTE APIs Prototype Declaration                                    */
/*----------------------------------------------------------------------------*/

/**  @brief Write speed to NvM */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NvMBlock_StoredSpeed(uint16 speed);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NvMBlock_StoredSpeed(VAR(uint16*, AUTOMATIC) speed);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NvMBlock_Calibration(VAR(uint16*, AUTOMATIC) calibrationValue);



#endif /* RTE_NVM_H */
