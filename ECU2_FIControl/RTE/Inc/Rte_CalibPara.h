#ifndef RTE_CALIBPARA_H
#define RTE_CALIBPARA_H

#include "Std_ReturnType.h"
#include <stdint.h>

/*----------------------------------------------------------------------------*/
/* RTE APIs Prototype Declaration                                             */
/*----------------------------------------------------------------------------*/

/* Read calibration parameter (e.g., speed threshold) */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RP_CalibPara_SpeedThreshold(
    P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) threshold);
#define Rte_Read_SpeedThreshold Rte_Read_RP_CalibPara_SpeedThreshold

#endif /* RTE_CALIBPARA_H */
