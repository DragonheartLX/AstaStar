cmake_minimum_required(VERSION 3.28)
file(GLOB_RECURSE ASTASTAR_Src LIST_DIRECTORIES false 
    src/*.cpp
    src/**/*.cpp)

project(AstaStarLib)

add_library(AstaStarLib ${ASTASTAR_Src})

target_include_directories(AstaStarLib PUBLIC .)

find_package(spdlog CONFIG REQUIRED)
    target_link_libraries(AstaStarLib PUBLIC spdlog::spdlog)