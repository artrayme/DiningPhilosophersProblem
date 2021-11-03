cmake_minimum_required(VERSION 3.20)
project(OS_lr2 C)

set(CMAKE_C_STANDARD 11)

add_executable(OS_lr2 main.c)

find_package (Threads REQUIRED)

target_link_libraries(OS_lr2
        ${CMAKE_THREAD_LIBS_INIT}
        )
