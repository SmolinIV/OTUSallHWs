#pragma once

// ѕолучаем информацию о текущем состо€нии буфера консоли, котора€ содержит в том числе и текущее положение курсора. ≈го и возвращаем в caller
COORD GetConsoleCursorPosition();

// „истим нужную нам строчку и возвращаемс€ в исходную позицию
void clearLine(COORD& lineToClear, COORD& lineToContinue);

// ѕолучаем значение от пользовател€ 
void getValue(int& number, int minLimit = INT_MIN, int maxLimit = INT_MAX);


