add_library(pico-FreeRTOS
    ${FREERTOS_KERNEL_PATH}/event_groups.c
    ${FREERTOS_KERNEL_PATH}/list.c
    ${FREERTOS_KERNEL_PATH}/queue.c
    ${FREERTOS_KERNEL_PATH}/stream_buffer.c
    ${FREERTOS_KERNEL_PATH}/tasks.c
    ${FREERTOS_KERNEL_PATH}/timers.c
    ${FREERTOS_KERNEL_PATH}/portable/MemMang/heap_4.c
    ${FREERTOS_KERNEL_PATH}/portable/ThirdParty/GCC/RP2040/port.c
    hook.c
    )

target_include_directories(pico-FreeRTOS PUBLIC
    .
    ${FREERTOS_KERNEL_PATH}/include
    ${FREERTOS_KERNEL_PATH}/portable/ThirdParty/GCC/RP2040/include
    )

target_link_libraries(pico-FreeRTOS PUBLIC
    pico_stdlib
    pico_base_headers
    hardware_clocks
    hardware_exception
    pico_multicore
)

target_compile_definitions(pico-FreeRTOS PUBLIC
    LIB_FREERTOS_KERNEL=1
    FREE_RTOS_KERNEL_SMP=1
)