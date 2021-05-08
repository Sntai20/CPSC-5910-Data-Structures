// pointers to base class
#include <iostream>
using namespace std;

class Polygon {
public:
    void set_values (int a, int b) { width = a; height = b; }
protected:
    int width, height;
};

class Rectangle: public Polygon {
public:
    int area() { return width * height; }
};

class Triangle: public Polygon {
public:
    int area() { return width * height / 2; }
};

int main() {
    Rectangle rect;
    Triangle trgl;
    Polygon * ppoly1 = &rect;
    Polygon * ppoly2 = &trgl;
    ppoly1->set_values (4, 5);
    ppoly2->set_values (4, 5);
    cout << "Rectangle area: " << rect.area() << '\n';
    cout << "Triangle area: " << trgl.area() << '\n';

    // can you call ppoly1->area()?

    return 0;
}

// OUTPUT
// Rectangle area: 20
// Triangle area: 10
