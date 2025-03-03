/******************************************************************************/
/* System Name : AUTOSAR RTE Partition                                        */
/* File Name   : Rte_Partition_ECU2.c                                         */
/* Version     : v1.0.0                                                        */
/* Contents    : RTE Partition Configuration for ECU2_FIControl                */
/* Author      : Generated                                                     */
/* Note        : AUTOSAR-based RTE partitioning                               */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* Include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "../../../ECU1_VehicleSpeed/RTE/Std_Types.h"
// #include "../../BSW/Services/Inc/Os.h"
//#include "Rte_Internal.h"

/*----------------------------------------------------------------------------*/
/* Global Variables                                                           */
/*----------------------------------------------------------------------------*/
extern VAR(uint8, AUTOMATIC) Rte_status;
extern VAR(uint8, AUTOMATIC) SchM_status;
extern VAR(boolean, AUTOMATIC) Rte_periodically_event_activation;
extern VAR(boolean, AUTOMATIC) SchM_periodically_event_activation;
extern VAR(uint8, AUTOMATIC) Rte_partition_status_ECU2;
extern VAR(uint32, AUTOMATIC) Rte_DisableEventList[50];

/*----------------------------------------------------------------------------*/
/* Function Declarations                                                      */
/*----------------------------------------------------------------------------*/
extern FUNC(void, RTE_CODE_ECU2) Rte_App_ComTxRx(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_ECU2) Rte_AppDiag_10ms(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_ECU2) Rte_AppWdgM_10ms(VAR(void, AUTOMATIC));

/******************************************************************************/
/* Task: ASWTask_10ms                                                         */
/* Description: Handles periodic event executions at 10ms interval            */
/******************************************************************************/
#define RTE_START_SEC_CODE_ECU2
#include "Rte_MemMap.h"

TASK (ASWTask_10ms) {
    VAR(EventMaskType, AUTOMATIC) Event;
    while(1) {
        WaitEvent(OsEvent_ASW_10ms);
        GetEvent(OsTask_ASWTask_10ms, &Event);
        
        if ((Rte_status == RTE_STATUS_RUN) && (Rte_partition_status_ECU2 == RTE_PARTITION_STATUS_RUNNING) && (SchM_status == SCHM_STATUS_RUN)) {
            if ((Event & OsEvent_ASW_10ms) > 0U) {
                ClearEvent(OsEvent_ASW_10ms);
                
                if (Rte_periodically_event_activation == TRUE) {
                    if (Rte_DisableEventList[5] == 0U) {
                        Rte_App_ComTxRx();
                    }
                }
                if (Rte_periodically_event_activation == TRUE) {
                    if (Rte_DisableEventList[10] == 0U) {
                        Rte_AppDiag_10ms();
                    }
                }
                if (Rte_periodically_event_activation == TRUE) {
                    if (Rte_DisableEventList[15] == 0U) {
                        Rte_AppWdgM_10ms();
                    }
                }
            }
        } else {
            ClearEvent(Event);
        }
    }
}

#define RTE_STOP_SEC_CODE_ECU2
#include "Rte_MemMap.h"

/* End of Rte_Partition_ECU2.c */
