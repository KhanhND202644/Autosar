#include "../../Inc/MCAL/FlashDrv.h"
#include "../../Inc/Services/MemIf.h"
#include <stdio.h>

void MemIf_Init(void) {
    printf("MemIf: Initialized\n");
}

bool MemIf_Write(MemIf_MemoryType memType, uint32 address, const uint8* data, uint32 length) {
    (void)memType;
    return FlashDrv_Write(address, data, length) == E_OK;
}

bool MemIf_Read(MemIf_MemoryType memType, uint32 address, uint8* data, uint32 length) {
    (void)memType;
    return FlashDrv_Read(address, data, length) == E_OK;
}

void MemIf_Erase(MemIf_MemoryType memType, uint32 address, uint32 length) {
    (void)memType;
    FlashDrv_Erase(address, length);
}