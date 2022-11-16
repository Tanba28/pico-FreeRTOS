#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>
#include "pico/stdlib.h"

void led_on_task(void *)
{   
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    while (true) {
        gpio_put(LED_PIN, 1);
        vTaskDelay(200);
    }
}

void led_off_task(void *)
{   
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    vTaskDelay(100);
    while (true) {
        gpio_put(LED_PIN, 0);
        vTaskDelay(200);
    }
}

int main()
{
    stdio_init_all();

    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    xTaskCreate(led_on_task, "LED_ON_Task", 256, NULL, 1, NULL);
    xTaskCreate(led_off_task, "LED_OFF_Task", 256, NULL, 1, NULL);

    vTaskStartScheduler();

    while(true){

    };
}