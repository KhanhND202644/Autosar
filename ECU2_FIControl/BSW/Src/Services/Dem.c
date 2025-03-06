#include "../../Inc/Services/Dem.h"
#include "../../Inc/Services/NvM.h"
#include <stddef.h>

/*----------------------------------------------------------------------------*/
/* Report Error to NvM                                                        */
/*----------------------------------------------------------------------------*/

void Dem_Init(void)
{   
    /* Initialize NvM Stored Error ID */
    NvM_StoredErrorID = 0;
    NvM_StoredErrorStatus = 0;

}

FUNC(Std_ReturnType, DEM_CODE) Dem_ReportErrorStatus(VAR(uint16, AUTOMATIC) DTC, VAR(Dem_EventStatusType, AUTOMATIC) status)
{
    /* Directly write error to NvM */
    (void) status;
    return NvM_WriteBlock(NVM_BLOCK_ID_ERRORS, &DTC);
}


