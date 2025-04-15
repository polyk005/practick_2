#ifndef TOUCHSCREEN_H
#define TOUCHSCREEN_H

#include "Device.h"
#include <vector>

enum class TouchTechnology {
    RESISTIVE,
    CAPACITIVE,
    INFRARED,
    SAW,
    OPTICAL
};

enum class MultiTouchSupport {
    NONE,
    SINGLE_TOUCH,
    MULTI_TOUCH_2,
    MULTI_TOUCH_5,
    MULTI_TOUCH_10
};

class TouchScreen : public Device {
private:
    float diagonal;
    int resolutionX;
    int resolutionY;
    TouchTechnology technology;
    MultiTouchSupport multiTouch;
    std::vector<std::pair<int, int>> touchPoints;

public:
    // Конструкторы
    TouchScreen();
    TouchScreen(const std::string& name, const std::string& maker, int year,
                float diag, int resX, int resY, TouchTechnology tech, MultiTouchSupport mt);
    TouchScreen(const TouchScreen& other);
    ~TouchScreen() override;

    // Геттеры и сеттеры
    void setDiagonal(float diag);
    float getDiagonal() const;

    void setResolution(int x, int y);
    std::pair<int, int> getResolution() const;

    void setTechnology(TouchTechnology tech);
    TouchTechnology getTechnology() const;

    void setMultiTouchSupport(MultiTouchSupport mt);
    MultiTouchSupport getMultiTouchSupport() const;

    // Методы работы с сенсором
    void addTouchPoint(int x, int y);
    void clearTouchPoints();
    void processTouchInput();

    // Переопределенные методы
    void displayInfo() const override;
    TouchScreen& operator=(const TouchScreen& other);

    // Статические методы
    static std::string technologyToString(TouchTechnology tech);
    static std::string multiTouchToString(MultiTouchSupport mt);
};

#endif // TOUCHSCREEN_H
