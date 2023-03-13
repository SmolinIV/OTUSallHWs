cmake_minimum_required(VERSION 3.5)

project(03.homework CXX)

add_executable(Guess_the_Number
	HW2_GTN.cpp
	valuesManip.cpp
)

set_target_properties(Guess_the_Number PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON)
if (false)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
  CMAKE_CXX_COMPILER_ID STREQUAL "GNU")

    target_compile_options(Guess_the_Number PRIVATE -Wall -Wextra -Werror -pedantic)

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")

    target_compile_options(Guess_the_Number PRIVATE /EHsc /W4 /WX)

endif()
endif()