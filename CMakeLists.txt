cmake_minimum_required(VERSION 3.25.0)
project(UtilityDS VERSION 1.0.0 LANGUAGES C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_library(UtilityDS STATIC src/dynamicArray.c)
target_include_directories(UtilityDS PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_compile_options(-std=c11 -Wall -Wextra -Wpedantic -Wshadow)

include(CTest)
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
