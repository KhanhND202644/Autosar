#ifndef WDGIF_H
#define WDGIF_H

#include "../../../Common/Std_ReturnType.h"
#include "../../../Common/Compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------------------------------------------------*/
/* Macro Definitions                                                          */
/*----------------------------------------------------------------------------*/
#define WDGIF_CODE

/* Watchdog Modes */
#define WDGIF_MODE_OFF    0
#define WDGIF_MODE_ON     1
#define WDGIF_MODE_TEST   2

/*----------------------------------------------------------------------------*/
/* Function Prototypes                                                        */
/*----------------------------------------------------------------------------*/
/**
 * @brief Triggers the Watchdog Timer
 * @return Std_ReturnType - E_OK if successful, E_NOT_OK if failed
 */
FUNC(Std_ReturnType, WDGIF_CODE) WdgIf_TriggerWatchdog(void);

/**
 * @brief Sets the Watchdog Mode
 * @param mode Watchdog mode (WDGIF_MODE_OFF, WDGIF_MODE_ON, WDGIF_MODE_TEST)
 * @return Std_ReturnType - E_OK if successful, E_NOT_OK if failed
 */
FUNC(Std_ReturnType, WDGIF_CODE) WdgIf_SetMode(VAR(uint8, AUTOMATIC) mode);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* WDGIF_H */
