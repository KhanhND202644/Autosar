#ifndef STD_RETURNTYPE_H
#define STD_RETURNTYPE_H

#include "Std_Types.h" /* Include AUTOSAR data type definition */

/*---------------------------------------------------------------------------------------------*/
/* AUTOSAR Standard Return Type Definition */
/*------------------------------------------------------------------------------------------*/

/**
* @brief AUTOSAR standard return type definition (uint8)
*/
typedef uint8 Std_ReturnType;

/*-----------------------------------------------------------------------------------------*/
/* AUTOSAR Return Values ​​*/
/*-----------------------------------------------------------------------------------------*/

/** @brief Success */
#define RTE_E_OK ((Std_ReturnType)0x00U)

/** @brief Failure / General error */
#define RTE_NOT_OK ((Std_ReturnType)0x01U)

/** @brief No valid data */
#define RTE_E_NO_DATA ((Std_ReturnType)0x02U)

/** @brief Data transmission error */
#define RTE_E_TRANSMIT_FAILED ((Std_ReturnType)0x03U)

/** @brief Invalid input data */
#define RTE_E_INVALID ((Std_ReturnType)0x04U)

/** @brief Timeout error */
#define RTE_E_TIMEOUT ((Std_ReturnType)0x05U)

/** @brief Maximum resource limit reached (Queue, Buffer full) */
#define RTE_E_LIMIT ((Std_ReturnType)0x06U)

/** @brief Unconnected Port */
#define RTE_E_UNCONNECTED ((Std_ReturnType)0x07U)

/** @brief Memory Allocation Failure */
#define RTE_E_NOMEM ((Std_ReturnType)0x08U)

/** @brief System Busy */
#define RTE_E_BUSY ((Std_ReturnType)0x09U)

/** @brief Unknown error */
#define RTE_E_GENERAL_ERROR ((Std_ReturnType)0xFFU)

/** @brief  Run status */
#define RTE_STATUS_RUN ((Std_ReturnType)0x01U)

/** @brief  Stop status */
#define RTE_STATUS_STOP ((Std_ReturnType)0x00U)


#endif /* STD_RETURNTYPE_H */