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

/*
# 1. Тест на гласные (Кириллица + Латиница + Пустая строка)
-a "Очередь" "Queue" ""

# 2. Тест на регистр (Смешанный ввод)
-b "Съешь ещё этих МЯГКИХ французских булок" "C++23 Standard"

# 3. Тест на спецсимволы (Знаки препинания, табы, символы)
-c "Привет, мир! (Hello... world?)" "Price: $100 & Exit#1"

# 4. Тест на палиндромы (Успех и Провал)
-d "шалаш" "потоп" "level" "not_a_palindrome" "Racecar"

# 5. Полный охват (Сразу всё)
-all "!аргентинаманитнегра!" "123-ABC-321" "!!!Спец-Тест!!!"
*/