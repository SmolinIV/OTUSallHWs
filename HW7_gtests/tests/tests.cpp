#include <gtest/gtest.h>
#include "include/Row.hpp"

TEST(Row_tests, main_tests_with_row) {
    //Тесты на:
    // Создание массива и проверка функции size
    int r_last_size;
    Row<int> arr{1, 2, 3};
    r_last_size = arr.size();
    EXPECT_TRUE(arr.size() == 3);
    //Добавление в конец
    arr.push_back(4);
    EXPECT_TRUE(arr[arr.size() - 1] == 4);
    // Добавление в начало
    arr.insert(0, 0);
    EXPECT_TRUE(arr[0] == 0);
    // Добавление в середину
    arr.insert(arr.size() / 2, 100);
    EXPECT_TRUE(arr[arr.size() / 2] == 100);

    arr.erase(arr.size() - 1);
    EXPECT_FALSE(arr[arr.size()-1] == 100);

    arr.erase(1);
    EXPECT_FALSE(arr[1] == )
}