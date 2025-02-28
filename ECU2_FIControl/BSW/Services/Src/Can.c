/******************************************************************************/
/* System Name : AUTOSAR Communication Services (ComServices)                 */
/* File Name   : ComServices_Can.c                                            */
/* Version     : v1.0.0                                                        */
/* Contents    : CAN Communication Services for ECU2_FIControl                 */
/* Author      : Generated                                                     */
/* Note        : Provides an interface between RTE and IoHwAb_Can              */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* Include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "../Inc/Can.h"
#include "../../ECU_Abstraction/ComHwAb/Inc/ComHwAb_Can.h"
#include "Rte_Can.h"
#include "Std_ReturnType.h"
#include "Std_Types.h"
#include <stdio.h>

/*----------------------------------------------------------------------------*/
/* CAN Transmission Handling                                                  */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, COMSERVICES_CODE) ComServices_CanTransmit(
    VAR(uint16, AUTOMATIC) signalID,
    P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    VAR(uint8, AUTOMATIC) length)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_OK;

    /* Validate data pointer */
    if (data == NULL)
    {
        printf("Error: ComServices_CanTransmit - Null data pointer!\n");
        return E_NOT_OK;
    }

    /* Forward data to IoHwAb for transmission */
    ret_val = IoHwAb_CanTransmit(signalID, data, length);

    if (ret_val != E_OK)
    {
        printf("Error: CAN Transmission Failed for SignalID %d\n", signalID);
    }
    return ret_val;
}

/*----------------------------------------------------------------------------*/
/* CAN Reception Handling                                                     */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, COMSERVICES_CODE) ComServices_CanReceive(
    VAR(uint16, AUTOMATIC) signalID,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) length)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_OK;

    /* Validate data pointer */
    if ((data == NULL) || (length == NULL))
    {
        printf("Error: ComServices_CanReceive - Null pointer!\n");
        return E_NOT_OK;
    }

    /* Forward request to IoHwAb for reception */
    ret_val = IoHwAb_CanReceive(signalID, data, length);

    if (ret_val != E_OK)
    {
        printf("Warning: CAN Receive Failed for SignalID %d\n", signalID);
    }
    return ret_val;
}

/*----------------------------------------------------------------------------*/
/* CAN Communication Processing (Main Function)                               */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, COMSERVICES_CODE) ComServices_CanProcess(VAR(void, AUTOMATIC))
{
    /* Execute periodic CAN communication tasks */
    Com_MainFunctionTx();
    Com_MainFunctionRx();
    return E_OK;
}
