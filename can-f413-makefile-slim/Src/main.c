#include "main.h"


int main(void)
{
  init();
  while (1)
  {
      // SHOWCASE LOOP
          if (0) {
            // Internal LED
            HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
            HAL_Delay(1000);
            HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
            HAL_Delay(1000);

            // Headlight LEDs
            HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_9);
            HAL_Delay(1000);
            HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_9);
            HAL_Delay(1000);

            // Bonnet servo
            __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 1200);
            HAL_Delay(1000);
            __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 800);
            HAL_Delay(1000);

            // Wheel motors
            //HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_9); // Motors 1
            HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_11); // Motors 2
            HAL_Delay(500);
            HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_11); // Motors 2
            HAL_Delay(1000);
          }
  }

  /* USER CODE END 3 */
}