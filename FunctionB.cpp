#include <iostream>
#include <cmath>
#include "Functions.hpp"

bool TriangleExists(int a, int b, int c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

int perimeter(int a, int b, int c) {
    return a + b + c;
}

double areaByHeron(int a, int b, int c) {
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

bool Isosceles(int a, int b, int c) {
    return (a == b) || (a == c) || (b == c);
}

void triangle() {
    int a, b, c;
    std::cout << "Введите 1 сторону: ";
    std::cin >> a;
    std::cout << "Введите 2 сторону: ";
    std::cin >> b;
    std::cout << "Введите 3 сторону: ";
    std::cin >> c;

    if (!TriangleExists(a, b, c)) {
        std::cout << "Ошибка: треугольник не существует!\n";
        return;
    }

    std::cout << "\nЧто нужно найти?\n";
    std::cout << "1. Периметр\n";
    std::cout << "2. Площадь (формула Герона)\n";
    std::cout << "3. Проверка на равнобедренность\n";
    std::cout << "Ваш выбор: ";

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        std::cout << "Периметр: " << perimeter(a, b, c) << "\n";
        break;
    case 2:
        std::cout << "Площадь: " << areaByHeron(a, b, c) << "\n";
        break;
    case 3:
        if (Isosceles(a, b, c))
            std::cout << "Треугольник равнобедренный\n";
        else
            std::cout << "Треугольник не равнобедренный\n";
        break;
    default:
        std::cout << "Неверный выбор!\n";
    }
}