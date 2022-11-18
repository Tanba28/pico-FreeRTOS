#ifndef __TASK_BASE_HPP__
#define __TASK_BASE_HPP__

#include "FreeRTOS.h"
#include "task.h"

class TaskBase {
    public:
        TaskBase() = delete;
        TaskBase(const char *_name, int _priority, uint32_t _stack_size=configMINIMAL_STACK_SIZE)
        :name(_name),priority(_priority),stack_size(_stack_size){

        }
        virtual ~TaskBase(){
            delete_task();
        }

        void create_task(){
            xTaskCreate(task_entry_point,name,stack_size,this,priority,&handle);
        }

        void delete_task(){
            vTaskDelete(handle);
        }

    protected:
        TaskHandle_t handle = 0;
        const char *name;
        int priority;
        uint32_t stack_size;

        virtual void task() = 0;

        static void task_entry_point(void* task_instance){
            static_cast<TaskBase*>(task_instance)->task();
        }
};
#endif