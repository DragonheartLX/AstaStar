cmake_minimum_required (VERSION 3.19)

set(CMAKE_CXX_STANDARD 20)

project(AstaStar)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY $<1:${CMAKE_BINARY_DIR}/bin>)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY $<1:${CMAKE_BINARY_DIR}/lib>)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY $<1:${CMAKE_BINARY_DIR}/lib>)
set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install")
set(AS_ROOT_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

message("-- [AstaStar] EXECUTABLE_OUTPUT_PATH: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message("-- [AstaStar] LIBRARY_OUTPUT_PATH (Static): ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
message("-- [AstaStar] LIBRARY_OUTPUT_PATH (Shared): ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
message("-- [AstaStar] CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")

# MSVC Setting
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(
        "$<$<CONFIG:>:/MT>" #----------------|
        "$<$<CONFIG:Debug>:/MTd>" #----------|-- Statically link the runtime libraries
        "$<$<CONFIG:Release>:/MT>" #---------|
        "$<$<CONFIG:RelWithDebInfo>:/MT>" #--|
    )
endif()

# Clang-cl Setting
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    if(CMAKE_CXX_SIMULATE_ID STREQUAL "MSVC")
        add_compile_options(
            "$<$<CONFIG:>:-fms-runtime-lib=static>" #-------------------|
            "$<$<CONFIG:Debug>:-fms-runtime-lib=static_dbg>" #----------|-- Statically link the runtime libraries
            "$<$<CONFIG:Release>:-fms-runtime-lib=static>" #------------|
            "$<$<CONFIG:RelWithDebInfo>:-fms-runtime-lib=static>" #-----|
        )
    endif()
endif()

message("-- [AstaStar] C Compiler: ${CMAKE_C_COMPILER_ID}")
message("-- [AstaStar] CXX Compiler: ${CMAKE_CXX_COMPILER_ID}")

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/MP>")
endif()

add_subdirectory(AstaStar)
add_subdirectory(AstaStarEditor)