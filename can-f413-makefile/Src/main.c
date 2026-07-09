#include "main.h"


/* Private variables ---------------------------------------------------------*/

int main(void)
{
  init();
  while (1)
  {
    /* USER CODE END WHILE */
    HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_9); // Headlight
    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0); // internal led
    //HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_9); // Motors 1
    //HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_11); // Motors 2
    HAL_Delay(1000);

    // Servo
    //__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 800);
    //HAL_Delay(1000);
    //__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 1200);
    //HAL_Delay(1000);

    /* USER CODE BEGIN 3 */
  }

  /* USER CODE END 3 */
}
