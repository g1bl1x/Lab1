#include <iostream>
#include <cmath>
#include <locale.h>
#include <string>
#include <Functions.hpp>

double inputRectangleSide(std::string text) {
	double num;
	while (true) {
		std::cout << text;
		if (!(std::cin >> num)) {
			std::cout << "Ошибка! Введите число\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (num <= 0) {
			std::cout << "Сторона должна быть положительной!" << std::endl;
			continue;
		}
		return num;
	}
}



void rectangle() {
	double a, b;
	a = inputRectangleSide("Введите длину: ");
	b = inputRectangleSide("Введите ширину: ");
	std::cout << "Какой параметр прямоугольника нужно найти?\n 1. Периметр\n 2. Площадь\n 3. Длина диагонали\n" << std::endl;
	int i;
	std::cin >> i;
	switch (i) {
		case 1: {
			double perimeter = 2 * (a + b);
			std::cout << "Периметр: " << perimeter << std::endl;
			break;
		}
		case 2: {
			double square = a * b;
			std::cout << "Площадь: " << square << std::endl;
			break;
		}
		case 3: {
			double diagonal = sqrt(a * a + b * b);
			std::cout << "Длина диагонали: " << diagonal << std::endl;
			break;
		}
		default: {
			std::cout << "Неверный выбор" << std::endl;
			break;
		}
	}
}