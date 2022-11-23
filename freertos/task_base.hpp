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
            deleteTask();
        }

        void createTask(){
            xTaskCreate(taskEntryPoint,name,stack_size,this,priority,&handle);
        }

        void deleteTask(){
            vTaskDelete(handle);
        }

    protected:
        TaskHandle_t handle = 0;
        const char *name;
        int priority;
        uint32_t stack_size;

        virtual void task() = 0;

        static void taskEntryPoint(void* task_instance){
            static_cast<TaskBase*>(task_instance)->task();
        }
};
#endif