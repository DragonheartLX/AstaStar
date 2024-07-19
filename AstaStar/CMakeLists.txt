cmake_minimum_required(VERSION 3.28)
file(GLOB_RECURSE ASTASTAR_Src LIST_DIRECTORIES false 
    Source/*.cpp
    Source/**/*.cpp)

project(AstaStarLib)

add_library(AstaStarLib ${ASTASTAR_Src})

target_include_directories(AstaStarLib PUBLIC Header)
target_precompile_headers(AstaStarLib PUBLIC Header/pch.hpp)

find_package(spdlog CONFIG REQUIRED)
    target_link_libraries(AstaStarLib PUBLIC spdlog::spdlog)

find_package(glfw3 CONFIG REQUIRED)
    target_link_libraries(AstaStarLib PRIVATE glfw)