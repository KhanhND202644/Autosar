#ifndef WDGM_H
#define WDGM_H

#include "../../../Common/Std_ReturnType.h"
#include "../../../Common/Compiler.h"

/*----------------------------------------------------------------------------*/
/* Watchdog Driver API Definitions                                           */
/*----------------------------------------------------------------------------*/

#define WDGM_MODE_OFF      0
#define WDGM_MODE_SLOW     1
#define WDGM_MODE_FAST     2

/*----------------------------------------------------------------------------*/
/* Function Prototypes                                                        */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, WDGM_CODE) WdgDrv_Trigger(void);
FUNC(Std_ReturnType, WDGM_CODE) WdgDrv_SetMode(VAR(uint8, AUTOMATIC) mode);
FUNC(Std_ReturnType, WDGM_CODE) Hardware_Watchdog_Trigger(void);
FUNC(Std_ReturnType, WDGM_CODE) Hardware_Watchdog_SetMode(VAR(uint8, AUTOMATIC) mode);


#endif /* WDGM_H */