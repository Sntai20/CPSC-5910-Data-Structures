#include "Rectangle.h"
#include <string>

Rectangle::Rectangle(std::string name, int width, int height) {
    this->name = name;
    this->width = width;
    this->height = height;
}

int Rectangle::GetArea() const {
    return width * height;
}

std::string Rectangle::ToString() const {
    return name + ":" + std::to_string(width) + ":" + std::to_string(height);
}
