#ifndef NVM_H
#define NVM_H

#include "../../../Common/Std_ReturnType.h"
#include "../../../Common/Compiler.h"
#include "MemIf.h"

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------------------------------------------------*/
/* Macro Definitions                                                          */
/*----------------------------------------------------------------------------*/
#define NVM_CODE
#define NVM_BLOCK_ID_SPEED    0x200U /* NvM Block ID for Speed Storage */
#define NVM_BLOCK_ID_ERRORS   0x201U /* NvM Block ID for DEM Error Storage */
#define NVM_BLOCK_ID_CALIB    0x202U /* NvM Block ID for Calibration Parameters */

/*----------------------------------------------------------------------------*/
/* Function Prototypes                                                        */
/*----------------------------------------------------------------------------*/
typedef struct {
    uint16 BlockID;
    uint16 BlockSize;
    uint8  NvRamAttributes;
} NvM_BlockDescriptorType;


FUNC(Std_ReturnType, NVM_CODE) NvM_WriteSpeed(VAR(uint16, AUTOMATIC) speed);
FUNC(Std_ReturnType, NVM_CODE) NvM_ReadSpeed(P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) speed);
FUNC(Std_ReturnType, NVM_CODE) NvM_WriteCalibration(VAR(uint16, AUTOMATIC) calibrationValue);
FUNC(Std_ReturnType, NVM_CODE) NvM_ReadCalibration(P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) calibrationValue);

/* Ensure consistency with NvM.c */
extern VAR(uint16, AUTOMATIC) NvM_StoredSpeed;
extern VAR(uint16, AUTOMATIC) NvM_StoredErrorID;
extern VAR(uint8, AUTOMATIC) NvM_StoredErrorStatus;
extern VAR(uint16, AUTOMATIC) NvM_StoredCalibration;


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* NVM_H */



