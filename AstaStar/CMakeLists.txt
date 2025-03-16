cmake_minimum_required(VERSION 3.28)
file(GLOB_RECURSE ASTASTAR_SRC LIST_DIRECTORIES false 
    Source/*.cpp
    Source/**/*.cpp)

project(AstaStarLib)

add_library(AstaStarLib ${ASTASTAR_SRC})

target_include_directories(AstaStarLib PUBLIC Header)
target_precompile_headers(AstaStarLib PUBLIC Header/pch.h)   