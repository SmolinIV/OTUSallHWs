cmake_minimum_required(VERSION 3.8)

project(Containers CXX)

add_executable(Containers 
src/Containers.cpp
src/Row.inl
src/bidirectional_list.inl
src/unidirectional_list.inl
)

target_include_directories(Containers PRIVATE include)

set_target_properties(Containers PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
target_compile_options(Containers PRIVATE
-g
-Wall
-Werror
-pedantic
)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
target_compile_options(Containers PRIVATE
/EHsc
/W4
)
endif()