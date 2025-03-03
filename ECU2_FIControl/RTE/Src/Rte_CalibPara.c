#include "../Inc/Rte_CalibPara.h"

/* Static Variables */
static uint16 speedThreshold = 120;

/****************************************************************************/
/* Provide Calibration Data (Rte_Write) */
/****************************************************************************/
FUNC(Std_ReturnType, RTE_CODE_ECU2) Rte_Write_RP_CalibPara_SpeedThreshold(VAR(uint16, AUTOMATIC) threshold)
{
    speedThreshold = threshold;
    return RTE_E_OK;
}
