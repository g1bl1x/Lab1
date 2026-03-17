#pragma once
#include <string>

/*
2.	Строки. Реализовать функции, связанные со строками (по одной функции на студента):
a.	Подсчет количества гласных букв в строке;
b.	Привидение всех букв к верхнему и нижнему регистру;
c.	Удаление всех знаков препинания и служебных символов (кроме пробела) из строки;
d.	Проверка, является ли строка палиндромом.
*/

void rectangle(); // a

enum class Case
{
	Upper,
	Lower
};

void ConvertCase(std::wstring& str, Case reg); // b

void StripSpecialCharacters(std::wstring& str); // c

bool IsPalindrome(const std::wstring& str); // d