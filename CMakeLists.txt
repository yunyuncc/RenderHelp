cmake_minimum_required(VERSION 3.22)
project(RenderHelp)

set (CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DSPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_DEBUG)

include_directories(3rd/spdlog-1.10.0/include)
include_directories(include)
include_directories(include/RenderHelp)



set(SRC 
    demo/main.cpp
)

add_executable(${PROJECT_NAME} ${SRC})
target_compile_options(${PROJECT_NAME} PRIVATE "-O3")

add_executable(sample_02_texture sample/sample_02_texture.cpp)
target_compile_options(sample_02_texture PRIVATE "-O3")

add_executable(sample_03_box sample/sample_03_box.cpp)
target_compile_options(sample_03_box PRIVATE "-O3")

add_executable(sample_04_gouraud sample/sample_04_gouraud.cpp)
target_compile_options(sample_04_gouraud PRIVATE "-O3")

add_executable(sample_05_model sample/sample_05_model.cpp)
target_compile_options(sample_05_model PRIVATE "-O3")


add_executable(sample_06_normal sample/sample_06_normal.cpp)
target_compile_options(sample_06_normal PRIVATE "-O3")


add_executable(sample_07_specular sample/sample_07_specular.cpp)
target_compile_options(sample_07_specular PRIVATE "-O3")
