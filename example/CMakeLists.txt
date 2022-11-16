add_executable(example main.cpp)

target_link_libraries(example pico_stdlib freertos)

pico_add_extra_outputs(example)