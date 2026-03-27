#include "Functions.hpp"
#include <iostream>
#include <cmath>

struct CircleResult {
    double circumference;
    double area;
    double sectorArea;
};

// Функция для расчетов. 
// radius - радиус, angleDegree - угол сектора в градусах (по умолчанию 360)
CircleResult calculateCircle(double radius, double angleDegree = 360.0) {
    const double PI = M_PI; // Используем константу из cmath
    
    CircleResult res;
    res.circumference = 2 * PI * radius;
    res.area = PI * std::pow(radius, 2);
    res.sectorArea = (res.area * angleDegree) / 360.0;
    
    return res;
}
