#include "../../Inc/MCAL/FlashDrv.h"
#include "../../Inc/Services/MemIf.h"
#include <stdio.h>

void MemIf_Init(void) {
    printf("MemIf: Initialized\n");
}

bool MemIf_Write(MemIf_MemoryType memType, uint32_t address, const uint8_t *data, uint32_t length) {
    if (memType == MEMIF_EEPROM) {
        return Eep_Write(address, data, length);
    } else if (memType == MEMIF_FLASH) {
        return Fls_Write(address, data, length);
    }
    return false;
}

bool MemIf_Read(MemIf_MemoryType memType, uint32_t address, uint8_t *data, uint32_t length) {
    if (memType == MEMIF_EEPROM) {
        return Eep_Read(address, data, length);
    } else if (memType == MEMIF_FLASH) {
        return Fls_Read(address, data, length);
    }
    return false;
}

void MemIf_Erase(MemIf_MemoryType memType, uint32_t address, uint32_t length) {
    if (memType == MEMIF_FLASH) {
        Fls_Erase(address, length);
    }
}
