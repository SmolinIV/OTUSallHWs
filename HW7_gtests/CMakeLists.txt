cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(PROJECT_NAME "Containers")
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
project(${PROJECT_NAME} CXX)

add_executable(${PROJECT_NAME} 
src/Containers.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include)

enable_testing()

add_subdirectory(gtests)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)


if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
target_compile_options(${PROJECT_NAME} PRIVATE
-g
-Wall
-Werror
-pedantic
)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
target_compile_options(${PROJECT_NAME} PRIVATE
/EHsc
/W4
)
endif()