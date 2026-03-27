#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void startOutput()
{
    cout << "В этой программе вы можете узнать длину окружности, площадь круга и площадь сектора, " << endl;
    cout << "задав радиус круга и угол интересуемого сектора." << endl << endl;
}

float getSafeInputRadius(string message)
{
    string line;
    float value;
    while (true) {
        cout << message;
        getline(cin, line); // Проверяю всю строку целиком
        
        stringstream ss(line);
        // Считаю число и проверяю, что после него ничего нет
        if (ss >> value && ss.eof()) {
            if (value >= 0) return value;
        }
        
        cout << "Ошибка! Введите только натуральное число!" << endl;
    }
}


float getSafeInputAngle(string message)
{
    string line;
    float value;
    while (true) {
        cout << message;
        getline(cin, line); // Проверяю всю строку целиком
        
        stringstream ss(line);
        // Считаю число и проверяю, что после него ничего нет
        if (ss >> value && ss.eof()) {
            if (value >= 0 && value <= 360) return value;
        }
        
        cout << "Ошибка! Введите значение угла от 0 до 360!" << endl;
    }
}

float circleLength(float radius)
{
    float circleLength = 2 * 3.14 * radius;
    return circleLength;
}

float circleSquare(float radius)
{
    float circleSquare = 3.14 * (radius * radius);
    return circleSquare;
}

float sectorSquare(float circleSquare, float angle)
{
    float sectorSquare = circleSquare * (angle / 360);
    return sectorSquare;
}


int circle()
{
    startOutput();  

    float radius  = getSafeInputRadius("Введите радиус: ");
    float angle = getSafeInputAngle("Введите угол сектора: ");

    float square = circleSquare(radius);

    cout << endl << "Параметры заданного круга:" << endl;
    cout << "Длина окружности: " << circleLength(radius) << endl;
    cout << "Площадь круга: " << square << endl;
    cout << "Площадь сектора: " << sectorSquare(square, angle) << endl;

    return 0;
}
