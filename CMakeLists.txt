cmake_minimum_required(VERSION 3.22)
project(RenderHelp)

set (CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DSPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_DEBUG)

include_directories(3rd/spdlog-1.10.0/include)
include_directories(include)



set(SRC 
    demo/main.cpp
)

add_executable(${PROJECT_NAME} ${SRC})
target_compile_options(${PROJECT_NAME} PRIVATE "-O3")