#include "../Inc/Rte_NvM.h"
#include "../../BSW/Inc/Services/NvM.h"
#include <stdio.h>

/*----------------------------------------------------------------------------*/
/* Static Variables                                                           */
/*----------------------------------------------------------------------------*/
#define NVM_BLOCK_ID_SPEED    0x200U /* NvM Block ID for Speed Storage */

static VAR(uint16, AUTOMATIC) NvM_StoredSpeed = 0;

/*----------------------------------------------------------------------------*/
/* NvM Speed Storage Implementation                                          */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, NVM_CODE) NvM_WriteSpeed(VAR(uint16, AUTOMATIC) speed)
{
    /* Validate speed range before saving */
    if (speed > 3000) /* 300.0 km/h max (converted to uint16 format) */
    {
        printf("Error: Attempted to save invalid speed %d to NvM\n", speed);
        return E_NOT_OK;
    }
    
    NvM_StoredSpeed = speed;
    printf("NvM: Saving Speed %d km/h to NvM\n", speed);
    return NvM_WriteBlock(NVM_BLOCK_ID_SPEED, &NvM_StoredSpeed);
}

FUNC(Std_ReturnType, NVM_CODE) NvM_ReadSpeed(P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) speed)
{
    if (NvM_ReadBlock(NVM_BLOCK_ID_SPEED, speed) != E_OK)
    {
        printf("Warning: Failed to read speed from NvM. Returning default value.\n");
        *speed = 0; /* Default value if read fails */
        return E_NOT_OK;
    }
    
    printf("NvM: Retrieved Speed %d km/h from NvM\n", *speed);
    return E_OK;
}
