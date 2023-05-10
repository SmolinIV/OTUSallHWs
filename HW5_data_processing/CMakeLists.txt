cmake_minimum_required(VERSION 3.5)

project(05.Homework LANGUAGES CXX)

add_executable(statistics main.cpp)
set_target_properties(statistics PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
target_compile_options(statistics PRIVATE
-g
-Wall
-Werror
-pedantic
)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
target_compile_options(statistics PRIVATE
/EHsc
/W4
)
endif()