#include "Functions.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include <locale.h>


int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Выберите фигуру: 1. Прямоугольник\n 2. Треугольник\n 3. Трапеция\n 4. Окружность" << std::endl;
    int i;
    std::cin >> i;
    switch (i) {
        case 1: {
            rectangle();
            break;
        }
        case 2: {
            triangle();
            break;
        }
        case 3: {
            trapezoid();
            break;
        }
        case 4: {
            circle();
            break;
        }
    }
}
