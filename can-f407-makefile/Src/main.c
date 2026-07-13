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
        TxHeader.StdId = 0x102;          // Set the ID
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
        TxHeader.StdId = 0x203;
        TxHeader.DLC = 1;

        // Open bonnet
        TxData[0] = 0x11;
        if (HAL_CAN_AddTxMessage(&hcan1, &TxHeader, TxData, &TxMailbox) != HAL_OK) {}
        HAL_Delay(1000);

        // Close bonnet
        TxData[0] = 0x22;
        if (HAL_CAN_AddTxMessage(&hcan1, &TxHeader, TxData, &TxMailbox) != HAL_OK) {}
        HAL_Delay(1000);

        // ==========================================
        // Section 3: Wheels
        // ==========================================
        TxHeader.StdId = 0x304;
        TxHeader.DLC = 1;

        // Spin wheels
        TxData[0] = 0x11;
        if (HAL_CAN_AddTxMessage(&hcan1, &TxHeader, TxData, &TxMailbox) != HAL_OK) {}
        HAL_Delay(1000);

        // Stop wheels
        TxData[0] = 0x22;
        if (HAL_CAN_AddTxMessage(&hcan1, &TxHeader, TxData, &TxMailbox) != HAL_OK) {}
        HAL_Delay(1000);
       }
     }
}
