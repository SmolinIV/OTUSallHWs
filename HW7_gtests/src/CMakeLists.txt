
add_library(Containers Containers.cpp)

target_include_directories(Containers PUBLIC include)

add_executable(Containers_WORK
Containers.cpp)

target_link_libraries(Containers_WORK PRIVATE Containers)