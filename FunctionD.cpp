#include "Functions.hpp"
#include <iostream>
#include <cmath>
using namespace std;

// функция длины окружности
double circumference(double r) {
    return 2 * M_PI * r;
}

// функция площади круга
double circleArea(double r) {
    return M_PI * r * r;
}

// функция площади сектора
double sectorArea(double r, double angle) {
    return M_PI * r * r * (angle / 360);
}

int main() {
    double r, angle;

    cout << "Введите радиус: ";
    cin >> r;

    cout << "Введите угол сектора (в градусах): ";
    cin >> angle;

    cout << "\nРезультаты:\n";

    cout << "Длина окружности: " << circumference(r) << endl;
    cout << "Площадь круга: " << circleArea(r) << endl;
    cout << "Площадь сектора: " << sectorArea(r, angle) << endl;

    return 0;
}
