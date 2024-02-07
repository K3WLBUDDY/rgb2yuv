cmake_minimum_required(VERSION 3.10)

project(rgb2yuv)

add_executable(rgb2yuv rgb2yuv.cpp rgb2yuv_converter.cpp rgb2yuv_decoder.cpp rgb2yuv_encoder.cpp rgb2yuv_utils.cpp)
