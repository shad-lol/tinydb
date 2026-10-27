cmake_minimum_required(VERSION 3.5.0...4.3.1)

set(CMAKE_CXX_MODULE_STD ON)

project("tinydb" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/dist/tinydb")

add_subdirectory("tinydb")