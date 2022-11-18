#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>
#include "pico/stdlib.h"

#include "task_base.hpp"

const uint LED_PIN = PICO_DEFAULT_LED_PIN;

class LedOnTask : public TaskBase{
    public:
        LedOnTask():
            TaskBase("LED_ON_TASK",1,256){
        }
    private:
        virtual void task(){
            
            while (true) {
                gpio_put(LED_PIN, 1);
                vTaskDelay(200);
            }
        }
};

class LedOffTask : public TaskBase{
    public:
        LedOffTask():
            TaskBase("LED_OFF_TASK",1,256){
        }
    private:
        virtual void task(){
            vTaskDelay(100);
            while (true) {
                gpio_put(LED_PIN, 0);
                vTaskDelay(200);
            }
        }
};

int main()
{
    stdio_init_all();

    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    LedOnTask led_on_task = LedOnTask();
    LedOffTask led_off_task = LedOffTask();

    led_on_task.create_task();
    led_off_task.create_task();

    vTaskStartScheduler();

    while(true){

    };
}