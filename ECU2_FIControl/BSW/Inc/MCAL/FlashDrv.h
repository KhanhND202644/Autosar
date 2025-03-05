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
 * @brief Erases data from Flash memory
 * @param address The address to erase
 * @param length Length of data to erase in bytes
 * @return Std_ReturnType - E_OK if successful, E_NOT_OK if failed
 */
FUNC(Std_ReturnType, FLASHDRV_CODE) FlashDrv_Erase(uint32 address, uint32 length);

/**
 * @brief Writes data to Flash memory
 * @param address The address to write to
 * @param data Pointer to the data to be written
 * @param length Length of data in bytes
 * @return Std_ReturnType - E_OK if successful, E_NOT_OK if failed
 */
FUNC(Std_ReturnType, FLASHDRV_CODE) FlashDrv_Write(uint32 address, const uint8* data, uint32 length);

/**
 * @brief Reads data from Flash memory
 * @param address The address to read from
 * @param data Pointer to the buffer where data will be stored
 * @param length Length of data to read in bytes
 * @return Std_ReturnType - E_OK if successful, E_NOT_OK if failed
 */
FUNC(Std_ReturnType, FLASHDRV_CODE) FlashDrv_Read(uint32 address, uint8* data, uint32 length);

#ifdef __cplusplus
}
#endif

#endif /* FLASHDRV_H */