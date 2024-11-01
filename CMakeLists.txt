cmake_minimum_required(VERSION 3.30)


project(KebabBookBuilder)

set(CMAKE_CXX_STANDARD 20)             
set(CMAKE_CXX_STANDARD_REQUIRED ON)     
set(CMAKE_CXX_EXTENSIONS OFF)           

include_directories(${PROJECT_NAME} "./include")

add_executable(${PROJECT_NAME} 
    "./main/main.cpp" 
    "./include/DonnerKebabBuilder.hpp"
    "./include/Kebab.hpp"
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/.."
)