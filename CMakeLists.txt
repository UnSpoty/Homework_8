cmake_minimum_required(VERSION 3.0)
project(Dyn_lib_Homework)

add_library(${PROJECT_NAME} SHARED func_add.c func_div.c func_mul.c func_sub.c)

add_executable(Test_dyn main.c)

target_link_libraries(Test_dyn PRIVATE ${PROJECT_NAME})