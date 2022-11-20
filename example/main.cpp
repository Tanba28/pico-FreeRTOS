#include "FreeRTOS.h"
#include "task.h"

#include <stdio.h>
#include "pico/stdlib.h"

#include "task_base.hpp"

const uint LED_PIN = PICO_DEFAULT_LED_PIN;

/* Prototypes for the standard FreeRTOS callback/hook functions implemented
within this file. */

class LedOnTask : public TaskBase{
    public:
        LedOnTask():
            TaskBase("LED_ON_TASK",1,1024){
        }
    private:
        virtual void task(){
            
            while (true) {
                gpio_put(LED_PIN, 1);
                vTaskDelay(2000);
            }
        }
};

class LedOffTask : public TaskBase{
    public:
        LedOffTask():
            TaskBase("LED_OFF_TASK",1,1024){
        }
    private:
        virtual void task(){
            vTaskDelay(1000);
            while (true) {
                gpio_put(LED_PIN, 0);
                vTaskDelay(2000);
            }
        }
};

class PrintTask : public TaskBase{
    public:
        PrintTask():
            TaskBase("PRINT_TASK",1,1024){
        }
    private:
        virtual void task(){
            
            while (true) {
                printf("Hello World!\n");
                vTaskDelay(1000);
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
    PrintTask print_task = PrintTask();

    led_on_task.create_task();
    led_off_task.create_task();
    print_task.create_task();

    vTaskStartScheduler();

    while(true){

    };
}