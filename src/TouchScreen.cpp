#include "TouchScreen.h"
#include <iostream>
#include <stdexcept>

TouchScreen::TouchScreen() : Device(), diagonal(0.0), resolutionX(0), resolutionY(0),
                            technology(TouchTechnology::CAPACITIVE), 
                            multiTouch(MultiTouchSupport::NONE) {}

TouchScreen::TouchScreen(const std::string& name, const std::string& maker, int year,
                        float diag, int resX, int resY, TouchTechnology tech, MultiTouchSupport mt)
    : Device(name, maker, year), diagonal(diag), resolutionX(resX), resolutionY(resY),
      technology(tech), multiTouch(mt) {}

TouchScreen::TouchScreen(const TouchScreen& other) : Device(other) {
    diagonal = other.diagonal;
    resolutionX = other.resolutionX;
    resolutionY = other.resolutionY;
    technology = other.technology;
    multiTouch = other.multiTouch;
    touchPoints = other.touchPoints;
}

TouchScreen::~TouchScreen() {}

void TouchScreen::setDiagonal(float diag) {
    if (diag <= 0) throw std::invalid_argument("Диагональ должна быть положительной");
    diagonal = diag;
}

float TouchScreen::getDiagonal() const { return diagonal; }

void TouchScreen::setResolution(int x, int y) {
    if (x <= 0 || y <= 0) throw std::invalid_argument("Разрешение должно быть положительным");
    resolutionX = x;
    resolutionY = y;
}

std::pair<int, int> TouchScreen::getResolution() const { 
    return {resolutionX, resolutionY}; 
}

void TouchScreen::setTechnology(TouchTechnology tech) { technology = tech; }
TouchTechnology TouchScreen::getTechnology() const { return technology; }

void TouchScreen::setMultiTouchSupport(MultiTouchSupport mt) { multiTouch = mt; }
MultiTouchSupport TouchScreen::getMultiTouchSupport() const { return multiTouch; }

void TouchScreen::addTouchPoint(int x, int y) {
    if (x < 0 || x >= resolutionX || y < 0 || y >= resolutionY) {
        throw std::out_of_range("Координаты касания вне диапазона разрешения");
    }
    touchPoints.emplace_back(x, y);
}

void TouchScreen::clearTouchPoints() { touchPoints.clear(); }

void TouchScreen::processTouchInput() {
    if (!getStatus()) {
        std::cout << "Сенсорный экран неактивен!\n";
        return;
    }

    std::cout << "Обработка " << touchPoints.size() << " точек касания:\n";
    for (const auto& point : touchPoints) {
        std::cout << "Касание в точке (" << point.first << ", " << point.second << ")\n";
    }
    clearTouchPoints();
}

void TouchScreen::displayInfo() const {
    Device::displayInfo();
    std::cout << "Диагональ: " << diagonal << " дюймов\n"
              << "Разрешение: " << resolutionX << "x" << resolutionY << "\n"
              << "Технология: " << technologyToString(technology) << "\n"
              << "Поддержка мультитач: " << multiTouchToString(multiTouch) << "\n"
              << "Активные точки касания: " << touchPoints.size() << "\n";
}

TouchScreen& TouchScreen::operator=(const TouchScreen& other) {
    if (this != &other) {
        Device::operator=(other);
        diagonal = other.diagonal;
        resolutionX = other.resolutionX;
        resolutionY = other.resolutionY;
        technology = other.technology;
        multiTouch = other.multiTouch;
        touchPoints = other.touchPoints;
    }
    return *this;
}

std::string TouchScreen::technologyToString(TouchTechnology tech) {
    switch (tech) {
        case TouchTechnology::RESISTIVE: return "Резистивная";
        case TouchTechnology::CAPACITIVE: return "Ёмкостная";
        case TouchTechnology::INFRARED: return "Инфракрасная";
        case TouchTechnology::SAW: return "ПАВ (поверхностные акустические волны)";
        case TouchTechnology::OPTICAL: return "Оптическая";
        default: return "Неизвестная";
    }
}

std::string TouchScreen::multiTouchToString(MultiTouchSupport mt) {
    switch (mt) {
        case MultiTouchSupport::NONE: return "Нет поддержки";
        case MultiTouchSupport::SINGLE_TOUCH: return "Одно касание";
        case MultiTouchSupport::MULTI_TOUCH_2: return "Два касания";
        case MultiTouchSupport::MULTI_TOUCH_5: return "Пять касаний";
        case MultiTouchSupport::MULTI_TOUCH_10: return "Десять касаний";
        default: return "Неизвестная";
    }
}
