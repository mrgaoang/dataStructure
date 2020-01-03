# cmake_minimum_required(VERSION <specify CMake version here>)
project(ClionWorkSpace)

set(CMAKE_CXX_STANDARD 14)

add_library(ClionWorkSpace p35-1/shortListMerge.c basic/shortListMerge.h p40/answer_p40.cpp Str串/KMP.cpp)