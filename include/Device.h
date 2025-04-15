#ifndef DEVICE_H
#define DEVICE_H

#include <string>
#include <iostream>

class Device {
protected:
    std::string modelName;
    std::string manufacturer;
    int yearOfProduction;
    bool isActive;

public:
    // Конструкторы
    Device();
    Device(const std::string& name, const std::string& maker, int year);
    Device(const Device& other);
    virtual ~Device();

    // Геттеры и сеттеры
    void setModelName(const std::string& name);
    std::string getModelName() const;

    void setManufacturer(const std::string& maker);
    std::string getManufacturer() const;

    void setYearOfProduction(int year);
    int getYearOfProduction() const;

    void activate();
    void deactivate();
    bool getStatus() const;

    // Виртуальные методы
    virtual void displayInfo() const;
    virtual Device& operator=(const Device& other);
};

#endif // DEVICE_H
