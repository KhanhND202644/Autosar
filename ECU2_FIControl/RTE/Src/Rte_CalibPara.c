#include "../Inc/Rte_CalibPara.h"
#include "../../ASW/Inc/CalibParaSWC.h"
#include "Std_ReturnType.h"
#include <stdio.h>

/* Biến lưu giá trị hiệu chỉnh */
static uint16 speedThreshold = 80U;

/****************************************************************************/
//  **Read calibration parameter (Rte_Read)**
/****************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RP_CalibPara_SpeedThreshold(P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) threshold)
{
    if (threshold == NULL)
    {
        printf("Error: Rte_Read_SpeedThreshold - Null pointer!\n");
        return RTE_E_INVALID;
    }

    *threshold = speedThreshold;
    return RTE_E_OK;
}
