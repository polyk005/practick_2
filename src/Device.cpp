#include "Device.h"
#include <iostream>

Device::Device() : modelName("Unknown"), manufacturer("Unknown"), yearOfProduction(0), isActive(false) {}

Device::Device(const std::string& name, const std::string& maker, int year) 
    : modelName(name), manufacturer(maker), yearOfProduction(year), isActive(false) {}

Device::Device(const Device& other) 
    : modelName(other.modelName), manufacturer(other.manufacturer), 
      yearOfProduction(other.yearOfProduction), isActive(other.isActive) {}

Device::~Device() {}

void Device::setModelName(const std::string& name) { modelName = name; }
std::string Device::getModelName() const { return modelName; }

void Device::setManufacturer(const std::string& maker) { manufacturer = maker; }
std::string Device::getManufacturer() const { return manufacturer; }

void Device::setYearOfProduction(int year) { yearOfProduction = year; }
int Device::getYearOfProduction() const { return yearOfProduction; }

void Device::activate() { isActive = true; }
void Device::deactivate() { isActive = false; }
bool Device::getStatus() const { return isActive; }

void Device::displayInfo() const {
    std::cout << "Устройство: " << modelName << "\n"
              << "Производитель: " << manufacturer << "\n"
              << "Год выпуска: " << yearOfProduction << "\n"
              << "Статус: " << (isActive ? "Активен" : "Неактивен") << "\n";
}

Device& Device::operator=(const Device& other) {
    if (this != &other) {
        modelName = other.modelName;
        manufacturer = other.manufacturer;
        yearOfProduction = other.yearOfProduction;
        isActive = other.isActive;
    }
    return *this;
}
