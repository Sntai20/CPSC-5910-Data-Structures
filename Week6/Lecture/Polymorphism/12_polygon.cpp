#include <iostream>
using namespace std;

class Polygon {
public:
    Polygon (int a, int b) : width(a), height(b) {}
    virtual ~Polygon() { cout << "Destructor of polygon\n"; }
    virtual int area (void) = 0;
    void printarea() { cout << this->area() << '\n'; }
protected:
    int width, height;
};

class Rectangle: public Polygon {
public:
    Rectangle(int a, int b) : Polygon(a, b) {}
    ~Rectangle() { cout << "Destructor of rectangle\n"; }
    int area() { return width * height; }
};

class Triangle: public Polygon {
public:
    Triangle(int a, int b) : Polygon(a, b) {}
    ~Triangle() { cout << "Destructor of triangle\n"; }
    int area() { return width * height / 2; }
};

int main() {
    Polygon * ppoly1 = new Rectangle (4, 5);
    Polygon * ppoly2 = new Triangle (4, 5);
    ppoly1->printarea(); 	// can we call ppoly1->area(); ?
    ppoly2->printarea();
    delete ppoly1;
    delete ppoly2;
    return 0;
}

// OUTPUT
// 20
// 10
