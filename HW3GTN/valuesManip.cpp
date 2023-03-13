#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "valuesManip.h"

COORD cursorPositionForPrintError = { 40, 0 },		// �����, ��� ����� ���������� ������� �� ������ ������������� �����
currentCursorPosition,								// ������� ��������� ������� (������������ �� �������)
lastCursorPosition;									// �����, � ������� ������ ����� ��������� ������ ����� �����-���� ��������


HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);


void getValue(int& number, int minLimit, int maxLimit)
{
	std::cin.clear();
	std::cin.ignore(32767, '\n');

	lastCursorPosition = GetConsoleCursorPosition();
	while (true)
	{
		clearLine(lastCursorPosition, lastCursorPosition);
		std::cin >> number;
		if (std::cin.fail() || number < minLimit || number > maxLimit)
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');

			SetConsoleCursorPosition(handle, cursorPositionForPrintError);
			std::cout << "\x1b[33m" << "Incorrect input. Please, try again." << "\x1b[0m";
		}
		else
		{
			lastCursorPosition = GetConsoleCursorPosition();
			clearLine(cursorPositionForPrintError, lastCursorPosition);
			return;
		}
	}
}

// �������� ���������� � ������� ��������� ������ �������, ������� �������� � ��� ����� � ������� ��������� �������. ��� � ���������� � caller
COORD GetConsoleCursorPosition()
{
	static CONSOLE_SCREEN_BUFFER_INFO cbsi;
	GetConsoleScreenBufferInfo(handle, &cbsi);
	return cbsi.dwCursorPosition;
}

// ������ ������ ��� ������� � ������������ � �������� �������
void clearLine(COORD& lineToClear, COORD& lineToContinue)
{
	SetConsoleCursorPosition(handle, lineToClear);
	std::cout << "                                                                                 ";
	SetConsoleCursorPosition(handle, lineToContinue);
}