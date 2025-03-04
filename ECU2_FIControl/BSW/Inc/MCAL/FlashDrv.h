#ifndef FLASHDRV_H
#define FLASHDRV_H

#include "../../../Common/Std_ReturnType.h"
#include "../../../Common/Compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------------------------------------------------*/
/* Macro Definitions                                                          */
/*----------------------------------------------------------------------------*/
#define FLASHDRV_CODE
#define FLASH_MEMORY_SIZE 1024 /* Simulated Flash Memory Size */

/*----------------------------------------------------------------------------*/
/* Function Prototypes                                                        */
/*----------------------------------------------------------------------------*/
/**
 * @brief Writes data to Flash memory
 * @param address The address to write to
 * @param data Pointer to the data to be written
 * @param length Length of data in bytes
 * @return Std_ReturnType - E_OK if successful, E_NOT_OK if failed
 */
FUNC(Std_ReturnType, FLASHDRV_CODE) FlashDrv_Write(
    VAR(uint32, AUTOMATIC) address,
    P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    VAR(uint16, AUTOMATIC) length);

/**
 * @brief Reads data from Flash memory
 * @param address The address to read from
 * @param data Pointer to buffer for storing read data
 * @param length Length of data in bytes
 * @return Std_ReturnType - E_OK if successful, E_NOT_OK if failed
 */
FUNC(Std_ReturnType, FLASHDRV_CODE) FlashDrv_Read(
    VAR(uint32, AUTOMATIC) address,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    VAR(uint16, AUTOMATIC) length);

/**
 * @brief Erases a section of Flash memory
 * @param address The start address of the erase operation
 * @param length Number of bytes to erase
 * @return Std_ReturnType - E_OK if successful, E_NOT_OK if failed
 */
FUNC(Std_ReturnType, FLASHDRV_CODE) FlashDrv_Erase(
    VAR(uint32, AUTOMATIC) address,
    VAR(uint16, AUTOMATIC) length);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* FLASHDRV_H */
