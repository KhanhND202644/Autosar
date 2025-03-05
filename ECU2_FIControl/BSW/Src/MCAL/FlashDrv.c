#include "../../Inc/MCAL/FlashDrv.h"
#include <stdio.h>



FUNC(Std_ReturnType, FLASHDRV_CODE) FlashDrv_Erase(uint32 address, uint32 length) {
    printf("[SIM] Flash Erased at Address: 0x%X, Length: %d bytes\n", address, length);
    return E_OK;
}


FUNC(Std_ReturnType, FLASHDRV_CODE) FlashDrv_Write(uint32 address, const uint8* data, uint32 length) {
    (void)data; 
    printf("[SIM] Flash Write at Address: 0x%X, Length: %d bytes\n", address, length);
    return E_OK;
}


FUNC(Std_ReturnType, FLASHDRV_CODE) FlashDrv_Read(uint32 address, uint8* data, uint32 length) {
    (void)data;
    printf("[SIM] Flash Read at Address: 0x%X, Length: %d bytes\n", address, length);
    return E_OK;
}