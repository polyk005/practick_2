#include <iostream>
#include <locale>
#include "TouchScreen.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    // Создание сенсорного экрана
    TouchScreen screen("SuperTouch X10", "TouchTech", 2023, 10.1, 1920, 1080, 
                      TouchTechnology::CAPACITIVE, MultiTouchSupport::MULTI_TOUCH_10);

    // Демонстрация работы
    cout << "=== Информация о сенсорном экране ===\n";
    screen.displayInfo();
    cout << endl;

    // Активация и обработка касаний
    screen.activate();
    screen.addTouchPoint(100, 200);
    screen.addTouchPoint(300, 400);
    screen.addTouchPoint(500, 600);

    cout << "=== Обработка касаний ===\n";
    screen.processTouchInput();
    cout << endl;

    // Тестирование копирования
    TouchScreen screen2 = screen;
    cout << "=== Скопированный сенсорный экран ===\n";
    screen2.displayInfo();
    cout << endl;

    // Тестирование присваивания
    TouchScreen screen3;
    screen3 = screen;
    cout << "=== Присвоенный сенсорный экран ===\n";
    screen3.displayInfo();

    return 0;
}
