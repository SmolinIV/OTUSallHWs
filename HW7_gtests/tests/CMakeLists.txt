cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_TOOLCHAIN_FILE "C:\\vcpkg\\scripts\\buildsystems\\vcpkg.cmake")
set(PROJECT_NAME "Tests_containers")

set(COMMON_SRCS
"../src/Containers.cpp"
)

add_executable(${PROJECT_NAME} tests.cpp ${COMMON_SRCS})

find_package(GTest CONFIG REQUIRED)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE
gtest
gtest_main
)