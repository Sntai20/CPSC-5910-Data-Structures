#include <iostream>
#include <string>       // new include here
#include "Rectangle.h"

int main() {
    Rectangle square("Square", 3, 3);
    std::cout << square.ToString() << std::endl;

    Rectangle* notSquare = new Rectangle("Rect", 3, 10);
    std::cout << notSquare->ToString() << std::endl;
    //std::cout << (*notSquare).ToString() << std::endl;   // same as
    delete notSquare;

    return 0;
}
