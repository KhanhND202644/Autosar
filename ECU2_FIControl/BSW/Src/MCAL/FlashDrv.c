#include "../../Inc/MCAL/FlashDrv.h"
#include "../../Inc/Services/MemIf.h"
#include <stdio.h>
#include <string.h> 

/* Simulated Flash Memory (for testing) */
#define FLASH_MEMORY_SIZE 1024
static VAR(uint8, AUTOMATIC) FlashMemory[FLASH_MEMORY_SIZE];

/*----------------------------------------------------------------------------*/
/* Flash Write Implementation                                                */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, FLASHDRV_CODE) FlashDrv_Write(
    VAR(uint32, AUTOMATIC) address,
    P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    VAR(uint16, AUTOMATIC) length)
{
    if (address + length > FLASH_MEMORY_SIZE)
    {
        printf("FlashDrv: Write out of bounds!\n");
        return E_NOT_OK;
    }
    
    memcpy(&FlashMemory[address], data, length);
    printf("FlashDrv: Data written to Flash at address %lu\n", address);
    return E_OK;
}

/*----------------------------------------------------------------------------*/
/* Flash Read Implementation                                                 */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, FLASHDRV_CODE) FlashDrv_Read(
    VAR(uint32, AUTOMATIC) address,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    VAR(uint16, AUTOMATIC) length)
{
    if (address + length > FLASH_MEMORY_SIZE)
    {
        printf("FlashDrv: Read out of bounds!\n");
        return E_NOT_OK;
    }
    
    memcpy(data, &FlashMemory[address], length);
    printf("FlashDrv: Data read from Flash at address %lu\n", address);
    return E_OK;
}

/*----------------------------------------------------------------------------*/
/* Flash Erase Implementation                                                */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, FLASHDRV_CODE) FlashDrv_Erase(VAR(uint32, AUTOMATIC) address, VAR(uint16, AUTOMATIC) length)
{
    if (address + length > FLASH_MEMORY_SIZE)
    {
        printf("FlashDrv: Erase out of bounds!\n");
        return E_NOT_OK;
    }
    
    memset(&FlashMemory[address], 0xFF, length);
    printf("FlashDrv: Erased Flash from address %lu, length %u\n", address, length);
    return E_OK;
}

/*----------------------------------------------------------------------------*/
/* Integration with MemIf                                                    */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, FLASHDRV_CODE) MemIf_Write(
    VAR(uint16, AUTOMATIC) blockId,
    P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    VAR(uint16, AUTOMATIC) length)
{
    printf("MemIf: Writing to Flash Block ID %u\n", blockId);
    return FlashDrv_Write(blockId * 16, data, length);
}

FUNC(Std_ReturnType, FLASHDRV_CODE) MemIf_Read(
    VAR(uint16, AUTOMATIC) blockId,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    VAR(uint16, AUTOMATIC) length)
{
    printf("MemIf: Reading from Flash Block ID %u\n", blockId);
    return FlashDrv_Read(blockId * 16, data, length);
}