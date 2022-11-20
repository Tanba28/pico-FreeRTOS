add_executable(example main.cpp hook.c)

target_link_libraries(example pico_stdlib freertos)

pico_enable_stdio_usb(example 1)
pico_enable_stdio_uart(example 0)

pico_add_extra_outputs(example)