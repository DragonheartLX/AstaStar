cmake_minimum_required(VERSION 3.28)
file(GLOB_RECURSE ASTASTAR_EDITOR__SRC LIST_DIRECTORIES false 
    Source/*.cpp
    Source/**/*.cpp)

project(AstaStarEditor)

add_executable(AstaStarEditor ${ASTASTAR_EDITOR__SRC})

target_include_directories(AstaStarEditor PRIVATE Header)

target_link_libraries(AstaStarEditor PRIVATE AstaStarLib)