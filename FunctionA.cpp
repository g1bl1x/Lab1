#include <io.h>
#include <fcntl.h>
#include <iostream>
#include <cmath>
#include <Functions.hpp>


void rectangle() {
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);
	int a;
	int b;
	std::wcout << L"Введите длину: ";
	std::wcin >> a;
	std::wcout << L"Введите ширину: ";
	std::wcin >> b;
	std::wcout << L"Какой параметр прямоугольника нужно найти?\n 1. Периметр\n 2. Площадь\n 3. Длина диагонали\n" << std::endl;
	int i;
	std::wcin >> i;
	switch (i) {
		case 1: {
			size_t perimeter = 2 * (a + b);
			std::wcout << L"Периметр: " << perimeter << std::endl;
			break;
		}
		case 2: {
			size_t square = a * b;
			std::wcout << L"Площадь: " << square << std::endl;
			break;
		}
		case 3: {
			size_t diagonal = sqrt(a * a + b * b);
			std::wcout << L"Длина диагонали: " << diagonal << std::endl;
			break;
		}
		default: {
			std::wcout << L"Неверный выбор" << std::endl;
			break;
		}
	}
}