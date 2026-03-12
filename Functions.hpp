#pragma once
#include <string>

/*
2.	Строки. Реализовать функции, связанные со строками (по одной функции на студента):
a.	Подсчет количества гласных букв в строке;
b.	Привидение всех букв к верхнему и нижнему регистру;
c.	Удаление всех знаков препинания и служебных символов (кроме пробела) из строки;
d.	Проверка, является ли строка палиндромом.
*/

size_t CountVowels(const std::string& str); // a

enum class Case
{
	Upper,
	Lower
};

void ConvertCase(std::string& str, Case reg); // b

void StripSpecialCharacters(std::string& str); // c

bool IsPalindrome(const std::string& str); // d