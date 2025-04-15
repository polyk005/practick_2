# Компилятор и флаги
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude
LDFLAGS := 

# Директории
SRC_DIR := src
INCLUDE_DIR := include
BUILD_DIR := build
BIN_DIR := bin

# Исходные файлы
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
TARGET := $(BIN_DIR)/touchscreen_app

# Правила
.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

run: $(TARGET)
	./$(TARGET)

# Зависимости
$(BUILD_DIR)/Device.o: $(INCLUDE_DIR)/Device.h
$(BUILD_DIR)/TouchScreen.o: $(INCLUDE_DIR)/TouchScreen.h $(INCLUDE_DIR)/Device.h
$(BUILD_DIR)/main.o: $(INCLUDE_DIR)/TouchScreen.h $(INCLUDE_DIR)/Device.h
