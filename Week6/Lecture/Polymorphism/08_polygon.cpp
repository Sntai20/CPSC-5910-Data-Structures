#include <iostream>
using namespace std;
 
// Base class
class Polygon {
public:
    // pure virtual function providing interface framework.
    virtual int getArea() = 0;
    void setWidth(int w) { width = w; }   
    void setHeight(int h) { height = h; }   
protected:
    int width;
    int height;
};
 
// Derived classes
class Rectangle: public Polygon {
public:
    int getArea() override { return (width * height); }
};

class Triangle: public Polygon {
public:
    int getArea() override { return (width * height) / 2; }
};
 
int main() {
    Rectangle Rect;
    Triangle  Tri;
 
    Rect.setWidth(4);
    Rect.setHeight(5);
   
    // Print the area of the object.
    cout << "Rectangle area: " << Rect.getArea() << endl;

    Tri.setWidth(4);
    Tri.setHeight(5);
   
    // Print the area of the object.
    cout << "Triangle area: " << Tri.getArea() << endl; 

    return 0;
}

// OUTPUT
// Rectangle area: 20
// Triangle area: 10
