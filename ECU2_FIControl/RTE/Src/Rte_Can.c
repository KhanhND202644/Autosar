#include "../Inc/Rte_Can.h"
#include "Com.h"
#include "Std_ReturnType.h"
#include <stdio.h>

/* Biến lưu trữ dữ liệu tốc độ tạm thời */
static uint16 lastSpeedData = 0;

/****************************************************************************/
/* Transmit Speed Data via CAN (Rte_Write) */
/****************************************************************************/
FUNC(Std_ReturnType, RTE_CODE_ECU2) Rte_Write_RP_CanCom_TransmitSpeedData(VAR(uint16, AUTOMATIC) speed)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_OK;
    VAR(uint16, AUTOMATIC) tmp_data = speed;

    /* Gửi dữ liệu tốc độ qua CAN */
    ret_val = Com_SendSignal(ComConf_ComSignal_SpeedData, &tmp_data);

    switch (ret_val)
    {
    case COM_SERVICE_NOT_AVAILABLE:
        ret_val = RTE_E_COM_STOPPED;
        break;
    case COM_BUSY:
        ret_val = RTE_E_COM_BUSY;
        break;
    default:
        /* Thành công */
        break;
    }

    return ret_val;
}

/****************************************************************************/
/* Receive Speed Data via CAN (Rte_Read) */
/****************************************************************************/
FUNC(Std_ReturnType, RTE_CODE_ECU2) Rte_Read_RP_CanCom_ReceiveSpeedData(P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) speed)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_OK;

    if (speed == NULL)
    {
        printf("Error: Rte_Read_ReceiveSpeedData - Null pointer!\n");
        return RTE_E_INVALID;
    }

    /* Nhận dữ liệu từ CAN */
    ret_val = Com_ReceiveSignal(ComConf_ComSignal_SpeedData, speed);

    if (ret_val == E_OK)
    {
        lastSpeedData = *speed;
    }
    else
    {
        *speed = lastSpeedData; /* Giữ giá trị trước đó nếu lỗi xảy ra */
        printf("Warning: Using last speed value due to CAN receive error.\n");
    }

    return ret_val;
}

/****************************************************************************/
/* Process CAN Communication (Rte_Call) */
/****************************************************************************/
FUNC(Std_ReturnType, RTE_CODE_ECU2) Rte_Call_RP_CanCom_Process(VAR(void, AUTOMATIC))
{
    /* Thực hiện xử lý giao tiếp CAN */
    Com_MainFunctionRx();
    Com_MainFunctionTx();
    return E_OK;
}
