#include "function.h"

#include "cmsis_os.h"
#include "gpio.h"
#include "main.h"
#include "stm32l4xx_hal.h"

void StartDefaultTask(void const* argument)
{
    for (;;)
    {
        toggle_led();
        osDelay(800);
    }
}

void toggle_led()
{
    HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
}
