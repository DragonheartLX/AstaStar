cmake_minimum_required(VERSION 3.28)
file(GLOB_RECURSE ASTASTAR_Src LIST_DIRECTORIES false 
    Source/*.cpp
    src/**/*.cpp)

project(AstaStarEditor)

add_executable(AstaStarEditor ${ASTASTAR_Src})

target_include_directories(AstaStarEditor PRIVATE Header)

target_link_libraries(AstaStarEditor PRIVATE AstaStarLib)