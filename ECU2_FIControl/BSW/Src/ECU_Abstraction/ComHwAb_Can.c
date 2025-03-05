#include "../../Inc/ECU_Abstraction/ComHwAb_Can.h"
#include "../../../Common/Std_ReturnType.h"
#include "../../../Common/Compiler.h"

/*----------------------------------------------------------------------------*/
/* CAN Reception Implementation                                               */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, COMHWAB_CAN_CODE) ComHwAb_Can_Receive(VAR(uint16, AUTOMATIC) signalID, VAR(uint8*, AUTOMATIC) data)
{
    (void)signalID;
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_OK;
    VAR(CanIf_RxPduIdType, AUTOMATIC) pduId;
    
    /* Map signalID to CAN PDU ID */
    pduId = CAN_ID_SPEED_DATA;  
    
    /* Receive CAN data from CanIf */
    ret_val = CanDrv_Receive(pduId, data); 


    return ret_val;
}