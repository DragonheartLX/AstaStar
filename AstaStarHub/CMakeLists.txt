cmake_minimum_required(VERSION 3.28)
file(GLOB_RECURSE ASTASTAR_HUB_SRC LIST_DIRECTORIES false 
    Source/*.cpp
    Source/**/*.cpp)

project(AstaStarHub)

add_executable(AstaStarHub ${ASTASTAR_HUB_SRC})

target_include_directories(AstaStarHub PRIVATE Header)

target_link_libraries(AstaStarHub PRIVATE AstaStarLib)

find_package(bgfx CONFIG REQUIRED)
    target_link_libraries(AstaStarHub PRIVATE bgfx::bx bgfx::bgfx bgfx::bimg bgfx::bimg_decode)