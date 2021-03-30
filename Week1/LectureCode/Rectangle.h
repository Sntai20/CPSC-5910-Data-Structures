#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>

class Rectangle {
private:
    int width;
    int height;
    std::string name;
public:
    Rectangle(std::string name, int width, int height);
    std::string ToString() const;
    int GetArea() const;
};


#endif //LECTURECODE_RECTANGLE_H
