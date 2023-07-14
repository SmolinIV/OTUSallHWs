#include <gtest/gtest.h>
#include "../src/include/Row.hpp"             

    // 1 2 3
    Row<int> arr{1, 2, 3}; 

TEST(Row_tests, create_and_check_size) {
    EXPECT_TRUE(arr.size() == 3);
}

TEST(Row_tests, push_back_and_change_size) {
    arr.push_back(4);                   // 1 2 3 4
    EXPECT_TRUE(arr[arr.size() - 1] == 4);
}
TEST(Row_tests, insert_in_the_beginning) {
     arr.insert(0, 0);                   // 0 1 2 3 4
     EXPECT_TRUE(arr[0] == 0);
}
 TEST(Row_tests, insert_in_the_middle) {
     arr.insert(2, 100);                 // 0 1 100 2 3 4
     EXPECT_TRUE(arr[2] == 100);
}
 TEST(Row_tests, delete_from_the_end) {
     arr.erase(arr.size() - 1);          // 0 1 100 2 3
     EXPECT_FALSE(arr[arr.size()-1] == 100);
}
 TEST(Row_tests, delete_from_the_middle) {
     arr.erase(2);                       // 0 1 2 3
     EXPECT_TRUE(arr[2] == 2);
}

TEST(Row_tests, delete_from_the_beginning) {
    arr.erase(0);                       // 1 2 3
    EXPECT_TRUE(arr[0] == 1);
}

TEST(Row_tests, check_the_content) {
    for (int i = 0; i < arr.size(); i++) {
        EXPECT_TRUE((arr[i] == (i + 1)));
    }
}

TEST(Row_tests, check_copy) {
    Row<int> arr1{arr};
    for (int i = 0; i < arr.size(); i++) {
        EXPECT_TRUE(arr1[i] == arr[i]);
    }
}