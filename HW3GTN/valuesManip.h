#pragma once

// �������� ���������� � ������� ��������� ������ �������, ������� �������� � ��� ����� � ������� ��������� �������. ��� � ���������� � caller
COORD GetConsoleCursorPosition();

// ������ ������ ��� ������� � ������������ � �������� �������
void clearLine(COORD& lineToClear, COORD& lineToContinue);

// �������� �������� �� ������������ 
void getValue(int& number, int minLimit = INT_MIN, int maxLimit = INT_MAX);


