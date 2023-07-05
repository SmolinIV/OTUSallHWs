find_package(GTest REQUIRED)

add_executable(Container_tests 
Row_tests.cpp
unidirectional_list_tests.cpp)

target_link_libraries(Container_tests
 PRIVATE
  GTest::GTest
  Containers)

add_test(all_tests Container_tests)
