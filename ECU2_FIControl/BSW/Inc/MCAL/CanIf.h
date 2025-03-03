#ifndef CANIF_H
#define CANIF_H

#include "Std_ReturnType.h"

extern Std_ReturnType CanIf_Transmit(uint16 pduId, const uint8* data, uint8 length);
extern Std_ReturnType CanIf_Receive(uint16 pduId, uint8* data, uint8* length);

#endif /* CANIF_H */