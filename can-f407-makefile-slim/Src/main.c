#include "main.h"

int main(void)
{
  init();
  while (1)
  {
    MX_USB_HOST_Process();
    // Showcase Loop
   
    if (0)
    {
        // ==========================================
        // Section 1: Headlights
        // ==========================================
        TxHeader.StdId = 0x240;          // Set the ID
        TxHeader.DLC = 1;                // 1 byte of data

        // Activate Headlights
        TxData[0] = 0x11;

        // Push Message 1 into a free hardware mailbox
        if (HAL_CAN_AddTxMessage(&hcan1, &TxHeader, TxData, &TxMailbox) != HAL_OK)
        {
            // Handle transmission error
        }
        HAL_Delay(1000);

        // Deactivate Headlights
        TxData[0] = 0x22;
        if (HAL_CAN_AddTxMessage(&hcan1, &TxHeader, TxData, &TxMailbox) != HAL_OK) {}
        HAL_Delay(1000);

        // ==========================================
        // Section 2: Bonnet
        // ==========================================
        TxHeader.StdId = 0x250;
        TxHeader.DLC = 1;

        // Open bonnet
        TxData[0] = 0x11;
        if (HAL_CAN_AddTxMessage(&hcan1, &TxHeader, TxData, &TxMailbox) != HAL_OK) {}
        HAL_Delay(1000);

        // Close bonnet
        TxData[0] = 0x22;
        if (HAL_CAN_AddTxMessage(&hcan1, &TxHeader, TxData, &TxMailbox) != HAL_OK) {}
        HAL_Delay(1000);
       }
     }
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
  // Retrieve the message from the FIFO buffer
  if (HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &RxHeader, RxData) == HAL_OK)
  {    
    uint8_t msg[] = "Hello testing :)";

    HAL_UART_Transmit(&huart2, msg, sizeof(msg)-1, HAL_MAX_DELAY);
    HAL_UART_Transmit(&huart2, RxData, sizeof(RxData)-1, HAL_MAX_DELAY);
  }
}