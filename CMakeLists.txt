cmake_minimum_required(VERSION 3.10)

project(rgb2yuv)

set(RGB2YUV_SOURCES rgb2yuv.cpp rgb2yuv_converter.cpp rgb2yuv_decoder.cpp rgb2yuv_encoder.cpp
    rgb2yuv_utils.cpp)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    list(APPEND RGB2YUV_SOURCES rgb2yuv_utils_asm_msvc.cpp)
elseif ((CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR (CMAKE_CXX_COMPILER_ID STREQUAL "Clang"))
    list(APPEND RGB2YUV_SOURCES rgb2yuv_utils_asm_gcc.cpp)
else()
    message(FATAL_ERROR "Unsupported compiler detected! Stopping build")
endif()

add_executable(rgb2yuv ${RGB2YUV_SOURCES})
