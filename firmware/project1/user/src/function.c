#include "function.h"
#include "cmsis_os.h"
#include "gpio.h" 
#include "stm32l4xx_hal.h"
#include "main.h"

void StartDefaultTask(void const * argument)
{
  for(;;)
  {
    // toggle led at some point
    toggle_led();
    osDelay(200);
  }
  /* USER CODE END StartDefaultTask */
}

void toggle_led() {
        HAL_GPIO_TogglePin(LD2_GPIO_Port,
          
          
          LD2_Pin)
          ;
}
